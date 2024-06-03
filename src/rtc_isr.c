#include <stdint.h>
#include "interrupts.h"
#include "rtc_isr.h"
#include "gpio.h"

/*
    INTERRUPT PATTERN
    1. Interrupt claim triggers rtc_isr
    2. Increment Counter
    3. Check if Counter%1000 = 0
        3a. TRUE: Change state of light
        3b. FALSE: Do Nothing
    4. Write to Claim to signal end of ISR
*/

volatile uint32_t rtc_isr_counter = 0;

void rtc_isr(void){
    rtc_isr_counter++;
    if(rtc_isr_counter%1000==0){
        toggle_gpio(61);
    }
    complete_interrupt(10);

}

