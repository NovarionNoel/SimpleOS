void plic_init();
void interrupt_enable(uint32_t interrupt_source);
void set_priority(uint32_t interrupt_source, uint32_t priority);
void handle_interrupts();
uint32_t get_priority(uint32_t interrupt_source);