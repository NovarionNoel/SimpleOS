/*
    CONFIGURE INTERRUPT

    1. Set integer in priority table for H1. 
    2. Enable IRQ for H1
    3. Set interrupt threshold 
    4. Store ISR address in IVT

*/
#include <stdint.h>
#include "interrupts.h"
#include "plic.h"

void configure_ISR(uint32_t interrupt_id, uint32_t priority, uint32_t threshold, isr_t isr){
    //restrict id, priority, and threshold to only valid values
    if (interrupt_id < 1 || interrupt_id > 136){
        return;
    }

    if (priority > 7 || priority < 0){
        return;
    }

    if (threshold > 7 || threshold < 0){
        return;
    }

    //1 Set Priority for IRQ in H1
    volatile uint32_t *INTERRUPT_PRIORITY_LOC=(PLIC_PRIORITY_START +(4*interrupt_id));
    *INTERRUPT_PRIORITY_LOC = priority;
    
    //2 Enable IRQ for H1
    volatile uint32_t *PLIC_ENABLE_REG = (PLIC_M_ENABLE_H1+(interrupt_id/32 * 0x20));
    *PLIC_ENABLE_REG |= (0x1 << interrupt_id); 

    //3 Set interrupt threshold
    volatile uint32_t *H1_THRESHOLD=(PLIC_M_THRESHOLD_H1 +(4*interrupt_id));
    *H1_THRESHOLD = threshold;

    //4 Store the ISR address 
    volatile uint32_t *vector_entry= (volatile uint32_t*)(MTVEC_BASE + (interrupt_id * 4));  
    *vector_entry = (uint32_t)isr;

}

void enable_global_interrupts(){
    //enable machine external interrupts and global interrupts
    write_memory(MIE, 0x800);
    write_memory(MSTATUS, 0x8);
}



//claim the interrupt
uint32_t claim_interrupt(){
   return  *((volatile uint32_t *)PLIC_M_CLAIM_H1);
   
}

//complete the interrupt
void complete_interrupt(uint32_t interrupt_id){
    *((volatile uint32_t *)PLIC_M_CLAIM_H1)= interrupt_id;
}

//helper functions for checking address values
void write_memory(uint32_t address, uint32_t value) {
    volatile uint32_t* reg = (volatile uint32_t*)address;
    *reg = value;
}

uint32_t read_memory(uint32_t address) {
    volatile uint32_t* reg = (volatile uint32_t*)address;
    return *reg;
}