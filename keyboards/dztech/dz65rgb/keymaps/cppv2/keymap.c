#include QMK_KEYBOARD_H


enum custom_keycodes {
  KC_PTR = SAFE_RANGE,
  KC_CMMT,
  KC_HEAD,
  KC_TAIL,
  KC_LSFN,
  KC_RSFN,
  KC_BSLS_,
  KC_GRV_,
  KC_QUOT_,
  KC_LBRC_,
  KC_RBRC_,
  KC_RESET_
};

#define FN_LAYER                 1
#define NAV_LAYER                2
#define SFT_LAYER                3
#define WIN_LAYER                4

#define KC_TABF                  LT(NAV_LAYER, KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_65_ansi( /* macOS */
            KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,    KC_5,   KC_6,    KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,  KC_LPRN,   KC_RPRN,\
            KC_TABF,       KC_Q,     KC_W,     KC_E,  KC_R,    KC_T,   KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,     KC_LCBR,  KC_RCBR, KC_BSPC,   KC_PGUP,\
            KC_LCTL,       KC_A,     KC_S,     KC_D,  KC_F,    KC_G,   KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_COLN,           KC_ENT,    KC_PGDN,\
            KC_LSFN,       KC_Z,     KC_X,     KC_C,  KC_V,    KC_B,   KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFN,           KC_UP,     MO(FN_LAYER),\
            TT(WIN_LAYER), KC_LALT,  KC_LGUI,                  KC_SPC,                    KC_RGUI, KC_RALT, KC_DEL,   KC_LEFT,           KC_DOWN,   KC_RGHT),

        [FN_LAYER] = LAYOUT_65_ansi( /* FN & RGB */
            KC_GRV,        KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  EEP_RST,  KC_VOLU,\
            KC_CAPS,       RGB_TOG,  KC_VOLU, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, KC_PSCR,  KC_SLCK, KC_PAUS, KC_DEL,   KC_VOLD,\
            KC_TRNS,       KC_LEFT,  KC_VOLD, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPI, RGB_SPD, KC_HOME,  KC_PGUP,          KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_MUTE, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,  KC_PGDN,  KC_TRNS,          KC_PGUP,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS, KC_TRNS, KC_MUTE,  KC_HOME,          KC_PGDN,   KC_END),

        [NAV_LAYER] = LAYOUT_65_ansi( /* Navigation */
            KC_RESET_,     KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_HEAD, KC_UP,   KC_TAIL, KC_HOME,  KC_PGUP, KC_TRNS, LSFT(KC_DEL),KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,   KC_PGDN,          KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_LGUI,  KC_LALT,                  KC_TRNS,                   KC_RALT, KC_RGUI, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),

        [SFT_LAYER] = LAYOUT_65_ansi( /* Shift Layer */
            KC_TRNS,       KC_TRNS,  KC_DQT,  KC_GRV_,KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT_,KC_2,     KC_UNDS, KC_PLUS, KC_LBRC_, KC_RBRC_,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_LT,   KC_GT,   KC_DEL,   KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HASH,  KC_DLR,           KC_CMMT,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUES, KC_PTR,  KC_BSLS_, KC_TRNS,          KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_UNDS,                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),

        [WIN_LAYER] = LAYOUT_65_ansi( /* Windows */
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,\
            KC_TRNS,       KC_LGUI,  KC_LALT,                  KC_TRNS,                   KC_RALT, KC_RGUI, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),
};

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_init_user(void)
{
}

void rgb_matrix_indicators_user(void)
{
  // this is where lighting the caps lock
  if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK))
  {
    const uint8_t capslock_led_index = g_led_config.matrix_co[1][0];
    rgb_matrix_set_color(capslock_led_index, 0xFF, 0x00, 0xFF);
  }

  if (layer_state_is(WIN_LAYER))
  {
    const uint8_t winlock_led_index = g_led_config.matrix_co[4][0];
    rgb_matrix_set_color(winlock_led_index, 0x00, 0xFF, 0xFF);
  }
}
#endif


void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

void keyboard_post_init_user(void) 
{
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}


#define SAVE_MODS()            uint8_t __saved_mods = get_mods(); clear_mods()
#define RESTORE_MODS()         set_mods(__saved_mods)


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
#ifdef CONSOLE_ENABLE
    printf("(%u, %u)=%u\n", record->event.key.col, record->event.key.row, record->event.pressed);
#endif
    switch(keycode)
    {
        case KC_RESET_:
        {
            if (record->event.pressed)
            {
                uint8_t mods = get_mods();
                 if (mods & MOD_MASK_SHIFT)
                {
                    reset_keyboard();
                }
            }
        }
        break;

        case KC_PTR:
        {
            if (record->event.pressed)
            {
                SAVE_MODS();
                SEND_STRING("->");
                RESTORE_MODS();
            }
        }
        break;

        case KC_CMMT:
        {
            if (record->event.pressed)
            {
                SAVE_MODS();
                SEND_STRING("// "); 
                RESTORE_MODS();
            }
        }
        break;

        case KC_BSLS_:
        {
            if (record->event.pressed)
            {
                SAVE_MODS();
                SEND_STRING("\\");  
                RESTORE_MODS();
            }
        }
        break;

        case KC_GRV_:
        {
            if (record->event.pressed)
            {
                SAVE_MODS();
                SEND_STRING("`");   
                RESTORE_MODS();
            }
        }
        break;

        case KC_QUOT_:
        {
            if (record->event.pressed)
            {
                SAVE_MODS();
                SEND_STRING("'");   
                RESTORE_MODS();
            }
        }
        break;

        case KC_LSFN:
        {
            if (record->event.pressed) 
            {
                layer_on(SFT_LAYER);
                register_code(KC_LSHIFT);
            }
            else
            {
                unregister_code(KC_LSHIFT);
                layer_off(SFT_LAYER);
            }
        }
        break;

        case KC_RSFN:
        {
            if (record->event.pressed) 
            {
                layer_on(SFT_LAYER);
                register_code(KC_RSHIFT);
            }
            else
            {
                unregister_code(KC_RSHIFT);
                layer_off(SFT_LAYER);
            }
        }
        break;

        case KC_HEAD:
        {
            if (layer_state_is(WIN_LAYER))
            {
                // Windows use HOME/END instead of ctrl+a/ctrl+e
                if (record->event.pressed)
                {
                    register_code(KC_HOME);
                }
                else
                {
                    unregister_code(KC_HOME);
                }
            }
            else 
            {
                if (record->event.pressed)
                {
                    // down mod
                    add_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();
                    // down key
                    register_code(KC_A);
                }
                else
                {
                    // up key
                    unregister_code(KC_A);
                    // up mod
                    del_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();

                }
            }
        }
        break;

        case KC_TAIL:
        {
            if (layer_state_is(WIN_LAYER))
            {
                // Windows use HOME/END instead of ctrl+a/ctrl+e
                if (record->event.pressed)
                {
                    register_code(KC_END);
                }
                else
                {
                    unregister_code(KC_END);
                }
            }
            else
            {
                if (record->event.pressed)
                {
                    // down mod
                    add_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();
                    // down key
                    register_code(KC_E);
                }
                else
                {
                    // up key
                    unregister_code(KC_E);
                    // up mod
                    del_weak_mods(MOD_BIT(KC_LCTL));
                    send_keyboard_report();                    
                }
            }
        }

        break;

        case KC_RBRC_:
        {
            if (record->event.pressed)
            {
                SAVE_MODS();
                SEND_STRING("]");  
                RESTORE_MODS();
            }
        }
        break;

        case KC_LBRC_:
        {
            if (record->event.pressed)
            {
                SAVE_MODS();
                SEND_STRING("[");  
                RESTORE_MODS();
            }
        }
        break;
    }
  return true;
}
