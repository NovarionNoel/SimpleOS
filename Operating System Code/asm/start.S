.section ".text.boot"

.globl _start
_start:
    csrr t0, mhartid
    li t1, 1
    bne t0, t1, _hlt # branch to _hlt if mhartid != 1
    la sp, _stack_start
    call cstart
_hlt:
    wfi
    j _hlt
