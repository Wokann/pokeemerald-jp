#include "global.h"

__attribute__((naked)) void ply_xxx(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r2, _0828FA78\n\t"
        "	ldr r2, [r2]\n\t"
        "	bl _call_via_r2\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0828FA78: .4byte 0x030071C0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xwave(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r2, [r1, #0x40]\n\t"
        "	ldr r0, _0828FAB4\n\t"
        "	ands r4, r0\n\t"
        "	ldrb r0, [r2]\n\t"
        "	orrs r4, r0\n\t"
        "	ldrb r0, [r2, #1]\n\t"
        "	lsls r3, r0, #8\n\t"
        "	ldr r0, _0828FAB8\n\t"
        "	ands r4, r0\n\t"
        "	orrs r4, r3\n\t"
        "	ldrb r0, [r2, #2]\n\t"
        "	lsls r3, r0, #0x10\n\t"
        "	ldr r0, _0828FABC\n\t"
        "	ands r4, r0\n\t"
        "	orrs r4, r3\n\t"
        "	ldrb r0, [r2, #3]\n\t"
        "	lsls r3, r0, #0x18\n\t"
        "	ldr r0, _0828FAC0\n\t"
        "	ands r4, r0\n\t"
        "	orrs r4, r3\n\t"
        "	str r4, [r1, #0x28]\n\t"
        "	adds r2, #4\n\t"
        "	str r2, [r1, #0x40]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0828FAB4: .4byte 0xFFFFFF00\n\t"
        "_0828FAB8: .4byte 0xFFFF00FF\n\t"
        "_0828FABC: .4byte 0xFF00FFFF\n\t"
        "_0828FAC0: .4byte 0x00FFFFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xtype(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r2, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x24\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xatta(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r2, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xdeca(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0x2d\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xsust(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0x2e\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xrele(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0x2f\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xiecv(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r2, [r0]\n\t"
        "	strb r2, [r1, #0x1e]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xiecl(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r2, [r0]\n\t"
        "	strb r2, [r1, #0x1f]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xleng(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0x26\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xswee(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0x27\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r0, [r1, #0x40]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r1, #0x40]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xcmd_0C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r3, r1, #0\n\t"
        "	ldr r4, [r3, #0x40]\n\t"
        "	ldr r0, _0828FB98\n\t"
        "	ands r2, r0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	orrs r2, r0\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	lsls r1, r0, #8\n\t"
        "	ldr r0, _0828FB9C\n\t"
        "	ands r2, r0\n\t"
        "	orrs r2, r1\n\t"
        "	ldrh r1, [r3, #0x3a]\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r1, r0\n\t"
        "	bhs _0828FBA0\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r3, #0x3a]\n\t"
        "	subs r0, r4, #2\n\t"
        "	str r0, [r3, #0x40]\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r3, #1]\n\t"
        "	b _0828FBA8\n\t"
        "	.align 2, 0\n\t"
        "_0828FB98: .4byte 0xFFFFFF00\n\t"
        "_0828FB9C: .4byte 0xFFFF00FF\n\t"
        "_0828FBA0:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r3, #0x3a]\n\t"
        "	adds r0, r4, #2\n\t"
        "	str r0, [r3, #0x40]\n\t"
        "_0828FBA8:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ply_xcmd_0D(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r2, [r1, #0x40]\n\t"
        "	ldr r0, _0828FBE8\n\t"
        "	ands r4, r0\n\t"
        "	ldrb r0, [r2]\n\t"
        "	orrs r4, r0\n\t"
        "	ldrb r0, [r2, #1]\n\t"
        "	lsls r3, r0, #8\n\t"
        "	ldr r0, _0828FBEC\n\t"
        "	ands r4, r0\n\t"
        "	orrs r4, r3\n\t"
        "	ldrb r0, [r2, #2]\n\t"
        "	lsls r3, r0, #0x10\n\t"
        "	ldr r0, _0828FBF0\n\t"
        "	ands r4, r0\n\t"
        "	orrs r4, r3\n\t"
        "	ldrb r0, [r2, #3]\n\t"
        "	lsls r3, r0, #0x18\n\t"
        "	ldr r0, _0828FBF4\n\t"
        "	ands r4, r0\n\t"
        "	orrs r4, r3\n\t"
        "	str r4, [r1, #0x3c]\n\t"
        "	adds r2, #4\n\t"
        "	str r2, [r1, #0x40]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0828FBE8: .4byte 0xFFFFFF00\n\t"
        "_0828FBEC: .4byte 0xFFFF00FF\n\t"
        "_0828FBF0: .4byte 0xFF00FFFF\n\t"
        "_0828FBF4: .4byte 0x00FFFFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DummyFunc(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

