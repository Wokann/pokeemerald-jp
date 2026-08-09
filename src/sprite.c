#include "global.h"
#include "sprite.h"

extern void FreeSpritePaletteByTag(u16 tag);

void FreeSpritePalette(struct Sprite *sprite)
{
    FreeSpritePaletteByTag(sprite->template->paletteTag);
}
