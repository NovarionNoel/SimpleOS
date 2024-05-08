#include <stdint.h>
extern uint32_t _bss_start;
extern uint32_t _bss_end;

extern void kmain();

void cstart() {
    uint32_t *bss = &_bss_start;
    uint32_t *bss_end = &_bss_end;
    while (bss < bss_end) {
        *bss++ = 0;
    }

    kmain();
}