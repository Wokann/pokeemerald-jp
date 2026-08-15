#include "global.h"

__attribute__((naked)) void AnimTask_SpiteTargetShadow(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081126C0\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r2, #0\n\t"
        "	strh r2, [r1, #0x26]\n\t"
        "	ldr r2, _081126C4\n\t"
        "	str r2, [r1]\n\t"
        "	bl _call_via_r2\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081126BC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081126C0: .4byte 0x03005B60\n\t"
        "_081126C4: .4byte 0x081126C9\n\t"
        ".syntax divided\n\t"
    );
}

