#include <stdint.h>
#include <stdbool.h>
#include "defs.h"
#include "uart.h"
#include "timer.h"
#include "gpio.h"

void kmain() {
    println_args(1, "Successfully booted to main.");
    bool val = true;
    int PIN61 = 61;
    println_args(1, "GPIO61 set to turn on and off");

    println_args(1, "Begin flashing light, and process messages every .5 seconds.");

    while (true) {
        for (int id=0;id<5;id++){
            claim_interrupt(id);
        }
        println_args(2, "blink: ", val ? "on" : "off");
        write_gpio(PIN61, val);
        val = !val;
        // delay 500 ms
        delay_us(500 * 1000);
    }
}