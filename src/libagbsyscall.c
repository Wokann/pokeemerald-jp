#include "global.h"
#include "gba/syscall.h"

#ifndef NONMATCHING
__attribute__((naked)) u16 ArcTan2(s16 x, s16 y)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xa\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
u16 ArcTan2(s16 x, s16 y)
{
    // Integer approximation of atan2 in 0..0xFFFF (full circle).
    s32 angle;
    if (x == 0 && y == 0)
        return 0;
    if (x > 0)
        angle = (s32)((s32)y * 16384 / x);
    else if (x < 0)
        angle = 32768 + (s32)((s32)y * 16384 / -x);
    else
        angle = (y >= 0) ? 16384 : 49152;
    if (angle < 0)
        angle += 65536;
    return (u16)angle;
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void BgAffineSet(struct BgAffineSrcData *src, struct BgAffineDstData *dest, s32 count)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xe\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void BgAffineSet(struct BgAffineSrcData *src, struct BgAffineDstData *dest, s32 count)
{
    s32 i;
    for (i = 0; i < count; i++)
    {
        s32 cx = src[i].texX, cy = src[i].texY;
        s32 sx = src[i].scrX, sy = src[i].scrY;
        dest[i].pa = (s16)sx;
        dest[i].pb = 0;
        dest[i].pc = 0;
        dest[i].pd = (s16)sy;
        dest[i].dx = (s16)(cx - sx);
        dest[i].dy = (s16)(cy - sy);
    }
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void CpuFastSet(const void *src, void *dest, u32 control)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xc\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void CpuFastSet(const void *src, void *dest, u32 control)
{
    u32 count = control & 0x1FFFFF;
    u32 *d32 = dest;
    const u32 *s32 = src;
    if (control & (1 << 26))
    {
        u32 fill = *(const u32 *)src;
        while (count--)
            *d32++ = fill;
    }
    else
    {
        while (count--)
            *d32++ = *s32++;
    }
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void CpuSet(const void *src, void *dest, u32 control)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xb\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void CpuSet(const void *src, void *dest, u32 control)
{
    u32 count = control & 0x1FFFFF;
    u16 *d16 = dest;
    const u16 *s16 = src;
    if (control & (1 << 26))
    {
        u16 fill = *(const u16 *)src;
        while (count--)
            *d16++ = fill;
    }
    else
    {
        while (count--)
            *d16++ = *s16++;
    }
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) s32 Div(s32 num, s32 denom)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #6\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
s32 Div(s32 num, s32 denom)
{
    return num / denom;
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void LZ77UnCompVram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x12\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void LZ77UnCompVram(const u32 *src, void *dest)
{
    const u8 *s = (const u8 *)src + 4;
    u16 *d = dest;
    u32 remaining = (src[0] & 0xFFFFFF) / 2;
    while (remaining > 0)
    {
        u8 flags = *s++;
        s32 i;
        for (i = 0; i < 8 && remaining > 0; i++)
        {
            if (flags & (0x80 >> i))
            {
                *d++ = s[0] | (s[1] << 8);
                s += 2;
                remaining--;
            }
            else
            {
                u16 t = s[0] | (s[1] << 8);
                u32 cnt;
                s32 disp;
                u16 *p;
                s += 2;
                cnt = (t >> 12) + 3;
                disp = (t & 0xFFF) + 1;
                p = d - disp;
                while (cnt-- && remaining > 0)
                {
                    *d++ = *p++;
                    remaining--;
                }
            }
        }
    }
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void LZ77UnCompWram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x11\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void LZ77UnCompWram(const u32 *src, void *dest)
{
    const u8 *s = (const u8 *)src + 4;
    u8 *d = dest;
    u32 remaining = src[0] & 0xFFFFFF;
    while (remaining > 0)
    {
        u8 flags = *s++;
        s32 i;
        for (i = 0; i < 8 && remaining > 0; i++)
        {
            if (flags & (0x80 >> i))
            {
                *d++ = *s++;
                remaining--;
            }
            else
            {
                u16 t = s[0] | (s[1] << 8);
                u32 cnt;
                s32 disp;
                u8 *p;
                s += 2;
                cnt = (t >> 12) + 3;
                disp = (t & 0xFFF) + 1;
                p = d - disp;
                while (cnt-- && remaining > 0)
                {
                    *d++ = *p++;
                    remaining--;
                }
            }
        }
    }
}
#endif


#ifndef NONMATCHING
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
#else
int MultiBoot(struct MultiBootParam *mp)
{
    (void)mp;
    return 0;
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0xf\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset)
{
    s32 i;
    u16 *d = dest;
    for (i = 0; i < count; i++)
    {
        d[0] = (u16)src[i].xScale;
        d[1] = (u16)src[i].yScale;
        d[2] = (u16)src[i].rotation;
        d += (offset / 2);
    }
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void RLUnCompVram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x15\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void RLUnCompVram(const u32 *src, void *dest)
{
    const u8 *s = (const u8 *)src + 4;
    u16 *d = dest;
    u32 remaining = (src[0] & 0xFFFFFF) / 2;
    while (remaining > 0)
    {
        u8 h = *s++;
        u32 cnt;
        cnt = (h >> 1) + 1;
        if (h & 1)
        {
            u16 v = s[0] | (s[1] << 8);
            s += 2;
            while (cnt-- && remaining > 0)
            {
                *d++ = v;
                remaining--;
            }
        }
        else
        {
            while (cnt-- && remaining > 0)
            {
                *d++ = s[0] | (s[1] << 8);
                s += 2;
                remaining--;
            }
        }
    }
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void RLUnCompWram(const u32 *src, void *dest)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #0x14\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void RLUnCompWram(const u32 *src, void *dest)
{
    const u8 *s = (const u8 *)src + 4;
    u8 *d = dest;
    u32 remaining = src[0] & 0xFFFFFF;
    while (remaining > 0)
    {
        u8 h = *s++;
        u32 cnt;
        cnt = (h >> 1) + 1;
        if (h & 1)
        {
            u8 v = *s++;
            while (cnt-- && remaining > 0)
            {
                *d++ = v;
                remaining--;
            }
        }
        else
        {
            while (cnt-- && remaining > 0)
            {
                *d++ = *s++;
                remaining--;
            }
        }
    }
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) void RegisterRamReset(u32 resetFlags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #1\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
void RegisterRamReset(u32 resetFlags)
{
    register u32 r0 asm("r0") = resetFlags;
    __asm__ volatile("svc #1" :: "r"(r0));
}
#endif


#ifndef NONMATCHING
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
        "_082959F8: .4byte gUnknown_3007F00\n\t"
        ".syntax divided\n\t"
    );
}
#else
void SoftReset(u32 resetFlags)
{
    (void)resetFlags;
    __asm__("svc #0");
    __builtin_unreachable();
}
#endif


#ifndef NONMATCHING
__attribute__((naked)) u16 Sqrt(u32 num)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	svc #8\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}
#else
u16 Sqrt(u32 num)
{
    u32 res = 0;
    u32 bit = 1 << 30;
    while (bit > num)
        bit >>= 2;
    while (bit != 0)
    {
        if (num >= res + bit)
        {
            num -= res + bit;
            res = (res >> 1) + bit;
        }
        else
        {
            res >>= 1;
        }
        bit >>= 2;
    }
    return res;
}
#endif


#ifndef NONMATCHING
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
#else
void VBlankIntrWait(void)
{
    __asm__ volatile("movs r2, #0\n\tsvc #5");
}
#endif


