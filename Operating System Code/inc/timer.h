#ifndef TIMER_H
#define TIMER_H
//fixed values
#define MTIME_FREQUENCY  (uint64_t)4000000
//macros
#define MTIME_LOCATION (0x2000000 + 0xBFF8)
void delay_us(uint64_t us);
void delay_time(uint64_t t);
uint64_t mtime();
#endif