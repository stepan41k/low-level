#include "textflag.h"

TEXT ·hello(SB), NOSPLIT, $0
    MOVQ $1, AX
    MOVQ $1, DI
    LEAQ msg<>(SB), SI 
    MOVQ $13, DX
    SYSCALL
    RET

GLOBL msg<>(SB), RODATA, $8
DATA msg<>+0(SB)/8, $"Hello Wo"
DATA msg<>+8(SB)/5, $"rld!\n"
