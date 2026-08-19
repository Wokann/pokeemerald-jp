#include "global.h"

// JP byte-exact berry glitch fix graphics loader (naked asm).

#define BERRY_FIX_GRAPHICS_DATA __attribute__((section(".rodata.berry_fix_graphics_data")))

BERRY_FIX_GRAPHICS_DATA
static const struct
{
    const u32 *gfx;
    const u32 *tilemap;
    const u16 *pltt;
} sBerryFixGraphics[] =
{
    {(const u32 *)0x085E2A20, (const u32 *)0x085E3610, (const u16 *)0x085E29E0},
    {(const u32 *)0x085E3990, (const u32 *)0x085E4494, (const u16 *)0x085E3930},
    {(const u32 *)0x085E47D0, (const u32 *)0x085E50D8, (const u16 *)0x085E4790},
    {(const u32 *)0x085E539C, (const u32 *)0x085E5BCC, (const u16 *)0x085E535C},
    {(const u32 *)0x085E5E68, (const u32 *)0x085E674C, (const u16 *)0x085E5E28},
    {(const u32 *)0x085E69E8, (const u32 *)0x085E707C, (const u16 *)0x085E69A8},
};

__attribute__((naked)) void LoadBerryFixGraphics(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	movs r6, #0x80\n\t"
        "	lsls r6, r6, #0x13\n\t"
        "	movs r2, #0\n\t"
        "	strh r2, [r6]\n\t"
        "	ldr r1, _081BAA7C\n\t"
        "	strh r2, [r1]\n\t"
        "	adds r1, #2\n\t"
        "	strh r2, [r1]\n\t"
        "	adds r1, #0x3e\n\t"
        "	strh r2, [r1]\n\t"
        "	ldr r5, _081BAA80\n\t"
        "	lsls r4, r0, #1\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r0, r4, r5\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #0x13\n\t"
        "	bl LZ77UnCompVram\n\t"
        "	adds r0, r5, #4\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _081BAA84\n\t"
        "	bl LZ77UnCompVram\n\t"
        "	adds r5, #8\n\t"
        "	adds r4, r4, r5\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #0xa0\n\t"
        "	lsls r1, r1, #0x13\n\t"
        "	movs r4, #0x80\n\t"
        "	lsls r4, r4, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl CpuSet\n\t"
        "	ldr r1, _081BAA88\n\t"
        "	movs r2, #0xf8\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	strh r4, [r6]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081BAA7C: .4byte 0x04000010\n\t"
        "_081BAA80: .4byte sBerryFixGraphics\n\t"
        "_081BAA84: .4byte 0x0600F800\n\t"
        "_081BAA88: .4byte 0x04000008\n\t"
        ".syntax divided\n\t"
    );
}
