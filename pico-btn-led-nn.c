#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

#define PICO_MY_LED_PIN 15
#define PICO_MY_BTN_PIN 14

void blinking(void);
void init_gpio_led(uint led);
void init_gpio_btn(uint btn);
void toggle_led(uint led);
void init_onboard_led(void);
void init_external_led(void);
void init_external_btn(void);

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    stdio_init_all();

    init_onboard_led();
    init_external_led();
    init_external_btn();

    multicore_launch_core1(blinking);

    while (1) {
        if (gpio_get(PICO_MY_BTN_PIN)) {
            toggle_led(PICO_MY_LED_PIN);
        }
        sleep_ms(100);
    }
#endif
    return 0;
}

void init_onboard_led() {
    bi_decl(bi_1pin_with_name(PICO_DEFAULT_LED_PIN, "On-Board LED"));
    init_gpio_led(PICO_DEFAULT_LED_PIN);
}

void init_external_led() {
    bi_decl(bi_1pin_with_name(PICO_MY_LED_PIN, "External LED"));
    init_gpio_led(PICO_MY_LED_PIN);
}

void init_external_btn() {
    bi_decl(bi_1pin_with_name(PICO_MY_BTN_PIN, "External Button"));
    init_gpio_btn(PICO_MY_BTN_PIN);
}

void init_gpio_led(uint led) {
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
}

void init_gpio_btn(uint btn) {
    gpio_init(btn);
    gpio_set_dir(btn, GPIO_IN);
}

void toggle_led(uint led) {
    gpio_put(led, !gpio_get(led));
}

void blinking() {
    while (1) {
        toggle_led(PICO_DEFAULT_LED_PIN);
        sleep_ms(1000);
    }
}
