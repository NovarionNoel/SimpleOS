#include "rtc_isr.h"
#include "interrupts.h"
#include "gpio.h"

/*
    INTERRUPT PATTERN
    1. Interrupt claim triggers RTC_ISR
    2. Increment Counter
    3. Check if Counter%1000 = 0
        3a. TRUE: Change state of light
        3b. FALSE: Do Nothing
    4. Write to Claim to signal end of ISR
*/

void RTC_ISR(void){
    rtc_isr_counter++;
    if(rtc_isr_counter%1000==0){
        toggle_gpio(61);
    }
    complete_interrupt(10);

}

