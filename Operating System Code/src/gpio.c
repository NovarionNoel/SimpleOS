#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"

void set_gpio(uint32_t pin) {
    if (pin > 63) {
        return;
    }

    uint32_t offset = pin / 4;
    uint32_t shift = 8 * (pin % 4);

    uint32_t dout = *(volatile uint32_t*)&(gpio.dout_reg[offset]);
    uint32_t doen = *(volatile uint32_t*)&(gpio.doen_reg[offset]);

    *(volatile uint32_t*)&(gpio.dout_reg[offset]) = (dout & ~(gpio.dout_mask << shift)) | (1 << shift);

    // enable is active low
    *(volatile uint32_t*)&(gpio.doen_reg[offset]) = doen & ~(gpio.doen_mask << shift);
}

void clear_gpio(uint32_t pin) {
    if (pin > 63) {
        return;
    }

    uint32_t offset = pin / 4;
    uint32_t shift = 8 * (pin % 4);

    uint32_t dout = *(volatile uint32_t*)&(gpio.dout_reg[offset]);
    *(volatile uint32_t*)&(gpio.dout_reg[offset]) = dout & ~(gpio.dout_mask << shift);
}

void write_gpio(uint32_t pin, int value) {
    if (value) {
        set_gpio(pin);
    } else {
        clear_gpio(pin);
    }
}

uint32_t read_gpio(uint32_t pin){
    //return 64 for invalid pin
    if (pin > 63) {
        return 64;
    }

    uint32_t offset = pin / 4;
    uint32_t shift = 8 * (pin % 4);

    uint32_t dout = *(volatile uint32_t*)&(gpio.dout_reg[offset]);
    uint32_t doen = *(volatile uint32_t*)&(gpio.doen_reg[offset]);

    //enable is active low
    return ((dout >> shift) & 0x1) & ~((doen >> shift) & 0x1);
}

void toggle_gpio(uint32_t pin){
    if (pin>63){
        return;
    }
    uint32_t state = read_gpio(pin);
    
    if (state==64){
        return;
    }

    if (state){
        clear_gpio(pin);
    }
    else{
        set_gpio(pin);
    }

}