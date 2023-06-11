#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <stdbool.h>
#include <stdlib.h>

static void gpio_setup(void) {

    // Initialize the GPIOC clock
    rcc_periph_clock_enable(RCC_GPIOC);

    // Set pin GPIO8 in GPIO port C to 'output push-pull' mode
    gpio_set_mode(
        GPIOC,
        GPIO_MODE_OUTPUT_2_MHZ,
        GPIO_CNF_OUTPUT_PUSHPULL,
        GPIO13
    );
}

int main(void) {
    
    gpio_setup();

    while (true) {

        // Turn on LED and pause for a bit
        gpio_clear(GPIOC, GPIO13);
        for (int i = 0; i < 1500000; ++i) {
            __asm__("nop"); // Do nothing
        }

        // Turn off LED and pause for a bit
        gpio_set(GPIOC, GPIO13);
        for (int i = 0; i < 500000; ++i) {
            __asm__("nop"); // Do nothing
        }
    }

    return EXIT_SUCCESS;
}