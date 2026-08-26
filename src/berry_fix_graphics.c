#include "global.h"

// JP byte-exact berry glitch fix graphics loader.

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

void LoadBerryFixGraphics(u32 idx)
{
    REG_DISPCNT = 0;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BLDCNT = 0;
    LZ77UnCompVram(sBerryFixGraphics[idx].gfx, (void *)BG_CHAR_ADDR(0));
    LZ77UnCompVram(sBerryFixGraphics[idx].tilemap, (void *)BG_SCREEN_ADDR(31));
    CpuCopy16(sBerryFixGraphics[idx].pltt, (void *)BG_PLTT, BG_PLTT_SIZE);
    REG_BG0CNT = BGCNT_SCREENBASE(31);
    REG_DISPCNT = DISPCNT_BG0_ON;
}
