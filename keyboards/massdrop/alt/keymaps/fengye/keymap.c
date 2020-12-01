#include QMK_KEYBOARD_H

enum alt_layers {
	LAYER0 = 0,
	WIN,
	FN,
	LSFT,
	RSFT,
	NAV,
};


enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    KC_LSFN,               //New left shift
    KC_RSFN,               //New right shift
    KC_GRV_,               //Grave/tilda workaround
    KC_HEAD,               //Go to line start
    KC_TAIL,               //Go to line end
    KC_WINMAC,             //Swap function key style between windows+linux/mac
    KC_DEL_,               //Shift+Backspace = Delete
    KC_BTLD,               //Put keyboard in bootloader mode
};

#define KC_ESCF		LT(NAV, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER0] = LAYOUT_65_ansi_blocker(
        KC_ESCF, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFN, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFN,          KC_UP,   KC_PGDN, \
        KC_CAPS, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(FN),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [WIN] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, KC_LGUI, KC_LALT,                            _______,                            KC_RALT, _______, _______, _______, _______  \
    ),
    [FN] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                           KC_WINMAC,                           _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    [LSFT] = LAYOUT_65_ansi_blocker(
        KC_GRV_, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL_, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            KC_UNDS,                            _______, _______, _______, _______, _______  \
    ),
    [RSFT] = LAYOUT_65_ansi_blocker(
        KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL_, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            KC_UNDS,                            _______, _______, _______, _______, _______  \
    ),
    [NAV] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_HEAD, KC_UP,   KC_TAIL, KC_HOME, KC_PGUP, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, _______, \
        _______, _______, _______,                            KC_BTLD,                            _______, _______, _______, KC_PGDN, _______  \
    ),
    
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

#define SAVE_MODS()            uint8_t __saved_mods = get_mods(); clear_mods()
#define RESTORE_MODS()         set_mods(__saved_mods)

void keyboard_post_init_user(void)
{
    // no eeprom on massdrop/alt, windows/linux style as default
    layer_on(WIN);
    send_keyboard_report();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) 
    {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        case KC_WINMAC:
            if (record->event.pressed)
            {
                if (layer_state_is(WIN))
                {
                    layer_off(WIN);
                }
                else
                {
                    layer_on(WIN);
                }
                send_keyboard_report();
            }
            return false;

        case KC_LSFN:
            if (record->event.pressed) {
                layer_on(LSFT);
                register_code(KC_LSHIFT);
            }
            else {
                unregister_code(KC_LSHIFT);
                layer_off(LSFT);
            }
            return false;
        case KC_RSFN:
            if (record->event.pressed) {
                layer_on(RSFT);
                register_code(KC_RSHIFT);
            }
            else {
                unregister_code(KC_RSHIFT);
                layer_off(RSFT);
            }
            return false;
        case KC_GRV_:
            if (record->event.pressed) {
                SAVE_MODS();
                SEND_STRING("`");
                RESTORE_MODS();
            }
            return false;
        case KC_DEL_:
            if (record->event.pressed) {
                SAVE_MODS();
                SEND_STRING("\x7f");
                RESTORE_MODS();
            }
            return false;
        case KC_HEAD:
        {
            if (layer_state_is(WIN))
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
            return false; 
        }

        case KC_TAIL:
        {
            if (layer_state_is(WIN))
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
            return false;
        }
        case KC_BTLD:
        {
            if(record->event.pressed && MODS_CTRL)
            {
                reset_keyboard();
            }
            return false;
        }
        default:
            return true; //Process all other keycodes normally
    }
}
