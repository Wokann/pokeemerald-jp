#include "global.h"

__attribute__((naked)) void CallBattlePalaceFunction(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _08195578\n\t"
        "	ldr r0, _0819557C\n\t"
        "	ldrh r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        "	pop {r0}\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08195574(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08195578: .4byte sBattlePalaceFunctions\n\t"
        "_0819557C: .4byte 0x02037280\n\t"
        ".syntax divided\n\t"
    );
}

