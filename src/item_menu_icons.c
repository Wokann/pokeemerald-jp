#include "global.h"

#define TAG_BERRY_PIC_PAL 30020

extern void FreeSpritePaletteByTag(u16 tag);

void FreeBerryTagSpritePalette(void)
{
    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL);
}
