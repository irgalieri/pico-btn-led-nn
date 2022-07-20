#include <stdio.h>
#include "pico/stdlib.h"

#define PICO_MY_LED_PIN 15
#define PICO_MY_BTN_PIN 14

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    stdio_init_all();
    const uint LED_PIN_EXT = PICO_MY_LED_PIN;
    const uint LED_PIN_IN = PICO_DEFAULT_LED_PIN;
    const uint BTN_PIN = PICO_MY_BTN_PIN;

    gpio_init(LED_PIN_EXT);
    gpio_set_dir(LED_PIN_EXT, GPIO_OUT);

    gpio_init(LED_PIN_IN);
    gpio_set_dir(LED_PIN_IN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);

    printf("Starting Loop....");

    while (1) {
        if (gpio_get(BTN_PIN)) {
            printf("Btn Press....");
            gpio_put(LED_PIN_EXT, 0);
        } else {
            gpio_put(LED_PIN_EXT, 1);
        }
        gpio_put(LED_PIN_IN, 1);
        sleep_ms(1000);
        gpio_put(LED_PIN_IN, 0);
        sleep_ms(250);
    }
#endif
    return 0;
}
