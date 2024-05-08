TARGET = minikernel

# Compiler and flags
CC = riscv64-unknown-elf-gcc
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
OBJCOPY = riscv64-unknown-elf-objcopy
OBJDUMP = riscv64-unknown-elf-objdump
CFLAGS = -Oz -std=c11 -nostdlib -MMD -march=rv64imafd -mcmodel=medany
ASFLAGS =
LDFLAGS = -T ld/link.ld

# Directories
SRCDIR = src
INCDIR = inc
ASMDIR = asm
OBJDIR = obj

# Source files
SRCS_C = $(wildcard $(SRCDIR)/*.c)
SRCS_ASM = $(wildcard $(ASMDIR)/*.S)
OBJS_C = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS_C))
OBJS_ASM = $(patsubst $(ASMDIR)/%.S,$(OBJDIR)/%.o,$(SRCS_ASM))
OBJS = $(OBJS_C) $(OBJS_ASM)

all: $(TARGET).bin $(TARGET).dump

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).dump: $(TARGET).elf
	$(OBJDUMP) -D $< > $@

$(TARGET).elf: $(OBJS) ld/link.ld
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(ASMDIR)/%.S
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin $(TARGET).dump

.PHONY: all clean