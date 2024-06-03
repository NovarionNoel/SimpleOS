
typedef void (*isr_t)(void);
void enable_global_interrupts();
void configure_ISR(uint32_t interrupt_id, uint32_t priority, uint32_t threshold, isr_t isr);
uint32_t claim_interrupt();
void complete_interrupt(uint32_t interrupt_id);