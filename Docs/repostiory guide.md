# Operating System Code Folders and Explanation
This is a brief guide for the file structure and contents of the operating system directory. 
## asm
Assembly code file(s) necessary for project.
- start.S: system entry point, creates program stack and halts all but 1 hart
## build
Build directory contains each stage of the necessary build files for creating a kernel image.
## inc
C header files for each component.
- defs.h: General global definitions
- gpio.h: GPIO driver header 
- interrupts.h: Interrupt handler header
- plic.h: PLIC values for the VF2
- rtc-isr.h: Real time clock interrupt service routine
- timer.h: System Timer driver header
- uart.h UART polled driver header 
## ld
Linker files for compiling code for the VF2.
- link.ld: specifies code loading location, stack directives, data alignment
## src
C code files for each component
- entry.c: Entry point into C code from assembly, starts kmain
- gpio.c: GPIO driver code
- interrupts.c: Interrupt handler code
- main.c: primary operating system entry, currently runs UART, GPIO, and TIMER drivers to blink lights and print messages about it.
- rtc_isr: real time clock interrupt service routine code
- timer.c: system timer code
- uart.c: UART polled driver code
## imaging_tool
Tools created by Z. Ydedia used for imaging the VisionFive 2. Details on his work can be found [here](https://zyedidia.github.io/blog/posts/1-d-baremetal/).
## Unimplemented File System
C code and header files for a FAT32 filesystem.
- fat32.h: FAT32 header with specifications based on the FAT32 standard
- fat32.c: FAT32 code with functions based on the FAT32 standard

## Misc (Main Directory)
- Makefile: build instructions for 'make' to create a kernel image
- Minikernel.img: The created kernel image.
- vf2-build: Files from Z. Ydedia to aid in building the kernel image.
- sx: Files from Z. Ydedia to aid in building the kernel image.
- jh7110-recovery-20221205.bin: Firmware loading program from StarFive used to image the VisionFive 2 with the kernel.