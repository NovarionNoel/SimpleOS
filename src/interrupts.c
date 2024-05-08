#include "plic.h"
#include "interrupts.h"
void plic_init(){
    for (int i =0; i<5; i++){
        for (int j=1; j<32; j++){
            plic_enable(j,i);
        }
    }
    set_priority(110,6);
    set_priority(111,6);
    set_priority(112,7);
}

void set_priority(uint32_t interrupt_source, uint32_t priority) {
    if (priority>7 || priority <0)
        {
            return;
        }
    volatile uint32_t *plic_priority_reg = (volatile uint32_t *)(PLIC_PRIORITY_START + (PLIC_WIDTH * interrupt_source));
    *plic_priority_reg = priority; 
}

uint32_t get_priority(uint32_t interrupt_source){
     volatile uint32_t *plic_priority_reg = (volatile uint32_t *)(PLIC_PRIORITY_START + (PLIC_WIDTH *interrupt_source));

    uint32_t priority = *plic_priority_reg;

    return priority;
}

void plic_enable(uint32_t interrupt_source, uint32_t hart_id){
       volatile uint32_t *plic_enable;
       uint32_t word_index = interrupt_source/32;
       uint32_t bit_position = interrupt_source%32;

       switch (hart_id) {
            case 0:
                plic_enable = (volatile uint32_t *)(PLIC_M_ENABLE_H0 +(word_index * sizeof(uint32_t)));
                plic_enable[0] |= (1 << bit_position);
                break;
            case 1:
                plic_enable = (volatile uint32_t *)(PLIC_M_ENABLE_H1 +(word_index * sizeof(uint32_t)));
                plic_enable[0] |= (1 << bit_position);
                break;
            case 2:
                plic_enable = (volatile uint32_t *)(PLIC_M_ENABLE_H2 +(word_index * sizeof(uint32_t)));
                plic_enable[0] |= (1 << bit_position);
                break;
            case 3:
                plic_enable = (volatile uint32_t *)(PLIC_M_ENABLE_H3 +(word_index * sizeof(uint32_t)));
                plic_enable[0] |= (1 << bit_position);
                break;
            case 4:
                plic_enable = (volatile uint32_t *)(PLIC_M_ENABLE_H4 +(word_index * sizeof(uint32_t)));
                plic_enable[0] |= (1 << bit_position);
                break;
            default:
                break;
        }
}

void claim_interrupt(int hart_id){
   
    uint32_t interrupt_id=0;
    volatile uint32_t *PLIC_CLAIM;
    switch (hart_id) {
            case 0:
                interrupt_id= *((volatile uint32_t *)PLIC_M_CLAIM_H0);
                PLIC_CLAIM=(volatile uint32_t *)PLIC_M_CLAIM_H0;
                break;
            case 1:
                interrupt_id= *((volatile uint32_t *)PLIC_M_CLAIM_H1);
                PLIC_CLAIM=(volatile uint32_t *)PLIC_M_CLAIM_H1;
                break;
            case 2:
                interrupt_id= *((volatile uint32_t *)PLIC_M_CLAIM_H2);
                PLIC_CLAIM=(volatile uint32_t *)PLIC_M_CLAIM_H2;
                break;
            case 3:
                interrupt_id= *((volatile uint32_t *)PLIC_M_CLAIM_H3);
                PLIC_CLAIM=(volatile uint32_t *)PLIC_M_CLAIM_H3;
                break;
            case 4:
                interrupt_id= *((volatile uint32_t *)PLIC_M_CLAIM_H4);
                PLIC_CLAIM=(volatile uint32_t *)PLIC_M_CLAIM_H4;
                break;
            default:
                break;
        }

    if(interrupt_id!=0){
        handle_interrupts(hart_id, interrupt_id);
        *PLIC_CLAIM=interrupt_id;
    }
}


void handle_interrupts(int hart_id, uint32_t interrupt_id){
    switch(hart_id){
        case 0:
    
        case 1:
        case 2:
        case 3:
        case 4:
    }
}

void custom_interrupts(uint32_t interrupt_id){
    switch(interrupt_id){
        case 110:
            //WRITE TO UART
        case 111:
            //ELEVATE PROCESS
        case 112:
            //SIGKILL
    }
}