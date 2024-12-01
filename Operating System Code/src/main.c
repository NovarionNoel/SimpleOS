#include <stdint.h>
#include <stdbool.h>
#include "defs.h"
#include "uart.h"
#include "timer.h"
#include "gpio.h"
#include "plic.h"   
#include "interrupts.h"
#include "rtc_isr.h"

void kmain() {
    println_args(1, "Successfully booted to main.");
    bool val = true;
    int PIN61 = 61;
    println_args(1, "GPIO61 set to turn on and off");
    //println_args(1, "Configuring Interrupts for HART 1");
    //configure_ISR(/* ID */ 10, /* PRIORITY */ 1, /* THRESHOLD */ 0, /* ISR */ rtc_isr);
    //enable_global_interrupts();

    println_args(1, "GPIO61 will blink every second");


    
    while (true) {
        
        println_args(2, "blink: ", val ? "on" : "off");
        write_gpio(PIN61, val);
        val = !val;
        //delay 500 ms
        delay_us(500 * 1000);
        //claim_interrupt();

    }
}