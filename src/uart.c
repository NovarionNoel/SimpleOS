#include <stdint.h>
#include <stdarg.h>
#include "uart.h"

static uint32_t lsr_uart() {
    uint32_t off = uart.base + 0x14;
    return *(volatile uint32_t*)off;
}

static void thr_uart( uint8_t b) {
    uint32_t off = uart.base + 0x0;
    *(volatile uint32_t*)off = b;
}

static void tx_uart(uint8_t b) {
    // Wait for THR to be empty
    while (((lsr_uart() >> thre) & 1) != 1) {
    }
    thr_uart(b);
}


void printElem_char(char c) {
    tx_uart(c);
}

void printElem_str(const char *s) {
    while (*s != '\0') {
        tx_uart(*s++);
    }
}

void print_args(int arg, ...) {
    va_list args;
    va_start(args, arg);
    for (int i = 0; i < arg; i++) {
        char *str_arg = va_arg(args, char*);
        printElem_str(str_arg);
    }
    va_end(args);
}

void println_args(int arg, ...) {
    va_list args;
    va_start(args, arg);
    for (int i = 0; i < arg; i++) {
        char *str_arg = va_arg(args, char*);
        printElem_str(str_arg);
    }
    va_end(args);
    tx_uart('\n');
}

void print(){}
void println() {
    tx_uart('\n');
}