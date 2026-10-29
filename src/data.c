#include "global.h"

const u16 gMinigameDigits_Pal[] __attribute__((section(".rodata.minigame_digits"))) = INCGFX_U16("graphics/link/minigame_digits.png", ".gbapal");
const u32 gMinigameDigits_Gfx[] __attribute__((section(".rodata.minigame_digits"))) = INCGFX_U32("graphics/link/minigame_digits.png", ".4bpp.lz");
static const u32 sMinigameDigitsThin_Gfx[] __attribute__((section(".rodata.minigame_digits"))) = INCGFX_U32("graphics/link/minigame_digits2.png", ".4bpp.lz");
