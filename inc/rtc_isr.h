#ifndef RTC_ISR_H
#define RTC_ISR_H

extern volatile uint32_t rtc_isr_counter; 

void rtc_isr(void);
#endif /* RTC_ISR_H */