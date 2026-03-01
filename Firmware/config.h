#pragma once

/* Encoder pinnen (D0 en D1) */
#define ENCODERS_PAD_A { GP26 }
#define ENCODERS_PAD_B { GP27 }
#define ENCODER_RESOLUTION 4

/* RGB instellingen (D6) */
#define RGB_DI_PIN GP4 
#define RGBLED_NUM 15
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_SNAKE