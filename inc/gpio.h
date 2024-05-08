#ifndef GPIO_H
#define GPIO_H
#define GPIO_BASE_ADDRESS 0x13040000

typedef struct {
    uint32_t *doen_reg;
    uint32_t *dout_reg;
    uint32_t dout_mask;
    uint32_t doen_mask;
} GPIO;

static GPIO gpio = {
    .doen_reg = (uint32_t*)(GPIO_BASE_ADDRESS + 0x0),
    .dout_reg = (uint32_t*)(GPIO_BASE_ADDRESS + 0x40),
    .dout_mask = 0x7f,
    .doen_mask = 0x3f
};

void set_gpio(uint32_t pin);
void clear_gpio(uint32_t pin);
void write_gpio(uint32_t pin, int value);

#endif