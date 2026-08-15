#include "global.h"
#include "gba/syscall.h"

__attribute__((naked)) u16 ArcTan2(s16 x, s16 y)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xa\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BgAffineSet(struct BgAffineSrcData *src, struct BgAffineDstData *dest, s32 count)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xe\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CpuFastSet(const void *src, void *dest, u32 control)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xc\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CpuSet(const void *src, void *dest, u32 control)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xb\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) s32 Div(s32 num, s32 denom)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #6\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LZ77UnCompVram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x12\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LZ77UnCompWram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x11\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) int MultiBoot(struct MultiBootParam *mp)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	movs r1, #1\n\t"
        "	svc #0x25\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xf\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void RLUnCompVram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x15\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void RLUnCompWram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x14\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void RegisterRamReset(u32 resetFlags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #1\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SoftReset(u32 resetFlags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r3, _082959F4\n\t"
        "	movs r2, #0\n\t"
        "	strb r2, [r3]\n\t"
        "	ldr r1, _082959F8\n\t"
        "	mov sp, r1\n\t"
        "	svc #1\n\t"
        "	svc #0\n\t"
        "	movs r0, r0\n\t"
        "	.align 2, 0\n\t"
        "_082959F4: .4byte 0x04000208\n\t"
        "_082959F8: .4byte 0x03007F00\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u16 Sqrt(u32 num)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #8\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void VBlankIntrWait()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	movs r2, #0\n\t"
        "	svc #5\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

