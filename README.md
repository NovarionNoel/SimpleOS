# SimpleOS
OS Project for Senior Thesis

## Build tools required:
- CMake and related dependences
- RISCV-Unknown-Elf Toolchain
- Tools for imaging the VisionFive 2 via UART from [Zyedidia](https://github.com/zyedidia/blog-code/tree/master/2-baremetal-visionfive)

## Hardware Required
- VisionFive 2 SoC
- USB to UART Connector
- LEDs
- Dupont Lines M/F, M/M, F/F
- JTAG Probe (In this case, JLink Mini EDU was used)

## References and Resources

Chang, A. (2019, May 27). RISC-V PLIC Specification. GitHub. https://github.com/riscv/riscv-plic-spec/blob/master/riscv-plic.adoc#interrupt-targets-and-hart-contexts 

Kaashoek, F., Morris, R., & Cox, R. (2006, June 12). XV6 for RISC-V. GitHub. https://github.com/mit-pdos/xv6-riscv 

Marz, S. (2019, September 26). The Adventures of OS: Making a RISC-V Operating System using Rust. Stephen Marz: Blog. https://osblog.stephenmarz.com/ 

Microsoft Corporation. (2000, December 6). Designing Hardware for Microsoft® Operating Systems: Microsoft Extensible Firmware Initiative FAT32 File System Specification. https://www.cs.fsu.edu/~cop4610t/assignments/project3/spec/fatspec.pdf 

SiFive. (2019). Sifive U74-MC Core Complex Manual. https://starfivetech.com/uploads/u74mc_core_complex_manual_21G1.pdf 

SiFive. (2019, December 5). SiFive Interrupt Cookbook Version 1.2. https://starfivetech.com/uploads/sifive-interrupt-cookbook-v1p2.pdf 

Starfive Tech Visionfive 2 Documentation and Boot Issues. IPFire Community Forums. (2023, October 1). https://community.ipfire.org/t/starfive-tech-visionfive-2/10510 

StarFive. (2022, December 21). VisionFive 2 Quick Start Guide. RVspace Doc Center. https://doc-en.rvspace.org/VisionFive2/PDF/VisionFive2_QSG.pdf 

StarFive. (2023a, February 2). JH7110 Interrupt Connections. RVspace Doc Center. https://doc-en.rvspace.org/JH7110/TRM/JH7110_TRM/interrupt_connections.html 

StarFive. (2023b, February 2). StarFive JH-7110 Datasheet. RVspace Doc Center. https://doc-en.rvspace.org/JH7110/Datasheet/index.html 

StarFive. (2023c, August 31). VisionFive 2 Errata Sheet. RVspace Doc Center. https://doc-en.rvspace.org/VisionFive2/PDF/VisionFive2_Errata.pdf 

StarFive. (n.d.). Hardware Setup. RVspace Doc Center. https://doc-en.rvspace.org/VisionFive2/40-Pin_GPIO_Header_UG/VisionFive2_40pin_UG/hardware_setup3%20-%20vf2.html 

U-Boot. (n.d.). Starfive VisionFive2. Das U-Boot Board Specific Documentation. https://docs.u-boot.org/en/latest/board/starfive/visionfive2.html 

Yedidia, Z. (2022, November 12). Multiplix: An operating system kernel for RISC-V and Aarch64 SBCS. GitHub. https://github.com/zyedidia/multiplix 

Yedidia, Z. (2023, February 8). Writing a bare-metal RISC-V application in D. Zachary Yedidia’s Blog. https://zyedidia.github.io/blog/posts/1-d-baremetal/ 

Zhang, Y., Renesse, R. van, & Mohamed, Y. (2022, January 12). EGOS-2000. GitHub. https://github.com/yhzhang0128/egos-2000 

