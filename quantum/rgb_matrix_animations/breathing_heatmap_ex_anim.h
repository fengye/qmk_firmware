#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && !defined(DISABLE_RGB_MATRIX_BREATHING_HEATMAP_EX)
RGB_MATRIX_EFFECT(BREATHING_HEATMAP_EX)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint32_t highest_key_count = 0;
static uint32_t key_count[MATRIX_ROWS][MATRIX_COLS] = {{0}};
static uint8_t last_keys[MATRIX_ROWS][MATRIX_COLS] = {{0}};
static uint8_t init_timer = 0;

// keep 30 frames and also makes generating fading color easier
#define KEEP_TIME          32
#define DROP_TIME          31
#define HEAT_PRESS_INC      4
#define HEAT_FRAME_INC      1


void process_rgb_matrix_breathing_heatmap_ex(keyrecord_t *record) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    if (record->event.pressed)
    {
      last_keys[row][col] = KEEP_TIME;

      uint32_t heat = key_count[row][col] + HEAT_PRESS_INC;

      key_count[row][col] = heat;
      if (highest_key_count < heat)
      {
        highest_key_count = heat;
      }

      if (highest_key_count <= 0xff)
      {
        rgb_frame_buffer[row][col] = (uint8_t)heat;
      }
      else 
      {
        float dividend = (float) 1.0f / highest_key_count;
        for (uint8_t i = 0; i < MATRIX_ROWS; ++i)
        {
          for(uint8_t j = 0; j < MATRIX_COLS; ++j)
          {
            rgb_frame_buffer[i][j] = (uint8_t)(key_count[i][j] * 255 * dividend);
          }
        }
      }
    }
    else
    {
      last_keys[row][col] = DROP_TIME;
    }
#ifdef CONSOLE_ENABLE
    for (uint8_t i = 0; i < MATRIX_ROWS; ++i)
    {
      for (uint8_t j = 0; j < MATRIX_COLS; ++j)
      {
        printf("%u\t", rgb_frame_buffer[i][j]);
      }
      print("\n");
    }
#endif
}

static void refresh_frame_buffer(void)
{
  if (highest_key_count <= 0xff)
  {
    for (uint8_t i = 0; i < MATRIX_ROWS; ++i)
    {
      for(uint8_t j = 0; j < MATRIX_COLS; ++j)
      {
        rgb_frame_buffer[i][j] = (uint8_t)key_count[i][j];
      }
    }
  }
  else 
  {
    float dividend = (float) 1.0f / highest_key_count;
    for (uint8_t i = 0; i < MATRIX_ROWS; ++i)
    {
      for(uint8_t j = 0; j < MATRIX_COLS; ++j)
      {
        rgb_frame_buffer[i][j] = (uint8_t)(key_count[i][j] * 255 * dividend);
      }
    }
  }
}


static HSV CYCLE_UP_DOWN_callback(HSV hsv,  uint8_t i, uint8_t time) {
    hsv.h = g_led_config.point[i].y - time;
    hsv.v = init_timer;
    return hsv;
}

bool BREATHING_HEATMAP_EX(effect_params_t* params) {
  // Modified version of RGB_MATRIX_USE_LIMITS to work off of matrix row / col size
  uint8_t led_min = RGB_MATRIX_LED_PROCESS_LIMIT * params->iter;
  uint8_t led_max = led_min + RGB_MATRIX_LED_PROCESS_LIMIT;
  if (led_max > sizeof(rgb_frame_buffer))
    led_max = sizeof(rgb_frame_buffer);

  if (params->init) {
    init_timer = 0xff;
    
    memset(rgb_frame_buffer, 0, sizeof rgb_frame_buffer);
    // do not clear previous saved state but refresh it
    refresh_frame_buffer();
  }

  if (init_timer)
  {
    init_timer--;

    effect_runner_i(params, &CYCLE_UP_DOWN_callback);
    // rgb_matrix_set_color_all(init_timer, init_timer, init_timer);
  }
  else
  {

    uint16_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 8);
    uint8_t breath = (sin8(time) >> 1) + 127;
    

    // Render heatmap
    for (int i = led_min; i < led_max; i++) {
      uint8_t row = i % MATRIX_ROWS;
      uint8_t col = i / MATRIX_ROWS;
      uint8_t val = rgb_frame_buffer[row][col];

      uint8_t lasting_timer = last_keys[row][col];

      // set the pixel colour
      uint8_t led[LED_HITS_TO_REMEMBER];
      uint8_t led_count = rgb_matrix_map_row_column_to_led(row, col, led);

      // check if key color is lasting
      if (lasting_timer == KEEP_TIME)
      {
        for (uint8_t j = 0; j < led_count; ++j)
        {
          if (!HAS_ANY_FLAGS(g_led_config.flags[led[j]], params->flags))
            continue;

          rgb_matrix_set_color(led[j], 0xff, 0xff, 0xff);


        }

        uint32_t heat = key_count[row][col];
        heat += HEAT_FRAME_INC;
        key_count[row][col] = heat;
        if (highest_key_count < heat)
        {
          highest_key_count = heat;
        }
      }
      else if (lasting_timer < KEEP_TIME)
      {
        last_keys[row][col] = lasting_timer - 1;

        uint8_t lasting_color = lasting_timer << 3;
        fract8 interpolate = lasting_color;
        
        for (uint8_t j = 0; j < led_count; ++j)
        {
          if (!HAS_ANY_FLAGS(g_led_config.flags[led[j]], params->flags))
            continue;

          HSV hsv = { 170 - qsub8(val, 85), rgb_matrix_config.hsv.s, scale8((qadd8(170, val) - 170) * 3, rgb_matrix_config.hsv.v) };
          hsv.v = scale8(breath, hsv.v);
          RGB rgb = hsv_to_rgb(hsv);

          uint8_t base_color = scale8(lasting_color, interpolate); 
          rgb.r = qadd8(base_color, scale8(rgb.r, qsub8(0xff, interpolate)));
          rgb.g = qadd8(base_color, scale8(rgb.g, qsub8(0xff, interpolate)));
          rgb.b = qadd8(base_color, scale8(rgb.b, qsub8(0xff, interpolate))); 

          rgb_matrix_set_color(led[j], rgb.r, rgb.g, rgb.b);
        }
      }
      else 
      {

        for (uint8_t j = 0; j < led_count; ++j)
        {
          if (!HAS_ANY_FLAGS(g_led_config.flags[led[j]], params->flags))
            continue;

          HSV hsv = { 170 - qsub8(val, 85), rgb_matrix_config.hsv.s, scale8((qadd8(170, val) - 170) * 3, rgb_matrix_config.hsv.v) };
          hsv.v = scale8(breath, hsv.v);
          RGB rgb = hsv_to_rgb(hsv);
          rgb_matrix_set_color(led[j], rgb.r, rgb.g, rgb.b);
        }
      }
    }
  }

  return led_max < sizeof(rgb_frame_buffer);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && !defined(DISABLE_RGB_MATRIX_BREATHING_HEATMAP_EX)
