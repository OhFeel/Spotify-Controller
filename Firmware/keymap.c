#include QMK_KEYBOARD_H

// We definiëren de toetsen voor Spotify
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MPRV, KC_MNXT, KC_MSTP, KC_MUTE,  // Vorige, Volgende, Stop, Mute
        KC_MPLY, KC_NO,   KC_NO,   KC_ENT    // Play/Pause, Leeg, Leeg, Encoder Klik (Enter)
    )
};

// --- ROTARY ENCODER LOGICA ---
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Onze enige encoder
        if (clockwise) {
            tap_code(KC_VOLU); // Volume omhoog
        } else {
            tap_code(KC_VOLD); // Volume omlaag
        }
    }
    return false;
}

// --- LED & VOLUME LOGICA ---
// Let op: "Meebewegen op muziek" in QMK is lastig zonder host-software (zoals Vial).
// We simuleren hier een volume-indicator.
void set_volume_leds(uint8_t level) {
    // Stel dat LED 6 t/m 14 om de encoder zitten
    for (int i = 6; i < 15; i++) {
        if ((i - 6) < level) {
            rgblight_setrgb_at(0, 255, 0, i); // Groen voor volume
        } else {
            rgblight_setrgb_at(0, 0, 0, i);   // Uit
        }
    }
}

// --- OLED SCHERM ---
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Spotify Controller\n"), false);
    oled_write_P(PSTR("Hack Club Edition\n"), false);
    
    // Hier kun je later status toevoegen als je extra software gebruikt
    return false;
}
#endif