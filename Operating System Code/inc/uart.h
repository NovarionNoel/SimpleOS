#ifndef UART_H
#define UART_H
#define UART_BASE_ADDRESS 0x10000000

typedef struct {
    uint32_t base;
} UART;

static UART uart = {
    UART_BASE_ADDRESS,
};

typedef enum {
    thre = 5, 
} lsr;

static void tx_uart(uint8_t b);
static void thr_uart(uint8_t b);
static uint32_t lsr_uart();


void printElem_char(char c);
void printElem_str(const char *s);

void print();
void print_args(int arg, ...);

void println();
void println_args(int arg, ...);
#endif