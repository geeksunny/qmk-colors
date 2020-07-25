#ifndef DISABLE_GRADIENT_MIRROR_OUT_IN
RGB_MATRIX_EFFECT(GRADIENT_MIRROR_OUT_IN)
#   ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Based on stock rgb_matrix_animations/gradient_left_right_anim.h source.
bool GRADIENT_MIRROR_OUT_IN(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t led_mid = (led_max / 2) + (((led_max % 2) != 0) ? 1 : 0);

    HSV hsv = rgb_matrix_config.hsv;
    uint8_t scale = scale8(64, rgb_matrix_config.speed);
    uint8_t ii = led_max - 1;
    for (uint8_t i = led_min; i < led_mid; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();
        // The x range will be 0..224, map this to 0..7
        // Relies on hue being 8-bit and wrapping
        hsv.h   = rgb_matrix_config.hsv.h + (scale * g_led_config.point[i].x >> 5);
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        if (i < ii) {
            rgb_matrix_set_color(ii, rgb.r, rgb.g, rgb.b);
            // Decrement outer iterator
            --ii;
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}
#   endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif  // DISABLE_GRADIENT_MIRROR_OUT_IN
