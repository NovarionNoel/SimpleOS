#include <stdint.h>
#include "timer.h"

    uint64_t mtime() {
        return *(volatile uint64_t*)(0x2000000 + 0xBFF8);
    }
    void delay_time(uint64_t t) {
        uint64_t rb = mtime();
        while (1) {
            uint64_t ra = mtime();
            if ((ra - rb) >= t)
                break;
        }
    }
     void delay_us(uint64_t us) {
        delay_time(us * MTIME_FREQUENCY / 1000000);
    }
