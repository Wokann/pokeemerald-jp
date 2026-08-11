#include "gba/gba.h"

// I/O register alias for use inside inline asm strings (see libisagbprn_a.c).
__asm__(".equ REG_ADDR_WAITCNT, 0x04000204");

void AGBPutcInternal(const char cChr);

// JP 0x08295774: kept as asm (same -O0 register allocation mismatch; this
// file is built with -O2 so agbcc does not emit the naked-asm parameter
// spill that -O0 produces).
__attribute__((naked)) void AGBPutc(const char cChr)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r7, lr}\n\t"
            "sub sp, #0x10\n\t"
            "mov r7, sp\n\t"
            "adds r1, r7, #0\n\t"
            "strb r0, [r1]\n\t"
            "ldr r0, _082957CC\n\t"
            "str r0, [r7, #4]\n\t"
            "adds r0, r7, #0\n\t"
            "adds r0, #8\n\t"
            "ldr r1, [r7, #4]\n\t"
            "ldrh r2, [r1]\n\t"
            "strh r2, [r0]\n\t"
            "ldr r0, [r7, #4]\n\t"
            "movs r2, #0xc0\n\t"
            "lsls r2, r2, #5\n\t"
            "adds r1, r2, #0\n\t"
            "strh r1, [r0]\n\t"
            "adds r0, r7, #0\n\t"
            "ldrb r1, [r0]\n\t"
            "adds r0, r1, #0\n\t"
            "bl AGBPutcInternal\n\t"
            "ldr r0, [r7, #4]\n\t"
            "adds r1, r7, #0\n\t"
            "adds r1, #8\n\t"
            "ldrh r2, [r1]\n\t"
            "strh r2, [r0]\n\t"
            "ldr r0, _082957D0\n\t"
            "str r0, [r7, #0xc]\n\t"
            "ldr r1, [r7, #0xc]\n\t"
            "ldrh r0, [r1, #6]\n\t"
            "ldr r1, [r7, #0xc]\n\t"
            "ldrh r2, [r1, #4]\n\t"
            "subs r1, r2, #1\n\t"
            "lsls r2, r1, #0x10\n\t"
            "lsrs r1, r2, #0x10\n\t"
            "cmp r0, r1\n\t"
            "bne _082957C4\n\t"
            "bl AGBPrintFlush1Block\n\t"
            "_082957C4:\n\t"
            "add sp, #0x10\n\t"
            "pop {r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_082957CC: .4byte REG_ADDR_WAITCNT\n\t"
            "_082957D0: .4byte 0x09FE20F8\n\t"
            ".syntax divided\n");
}
