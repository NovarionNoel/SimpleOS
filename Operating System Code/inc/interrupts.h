#ifndef INTERRUPTS_H
#define INTERRUPTS_H


#define MIE         0x304
#define MSTATUS     0x300
#define MTVEC_BASE  0x305
typedef void (*isr_t)(void);
void enable_global_interrupts();
void configure_ISR(uint32_t interrupt_id, uint32_t priority, uint32_t threshold, isr_t isr);
uint32_t claim_interrupt();
void complete_interrupt(uint32_t interrupt_id);
void write_memory(uint32_t address, uint32_t value);
uint32_t read_memory(uint32_t address);

#endif /* INTERRUPTS_H */