#include "global.h"

__attribute__((naked)) void MovePlayerOnAcroBike(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	mov r3, sp\n\t"
        "	strb r0, [r3]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	ldr r4, _08119C4C\n\t"
        "	mov r0, sp\n\t"
        "	bl CheckMovementInputAcroBike\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r0, r0, r4\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1]\n\t"
        "	ldr r2, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl _call_via_r2\n\t"
        "	add sp, #4\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08119C44(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08119C4C: .4byte 0x0857304C\n\t"
        ".syntax divided\n\t"
    );
}

