#include "global.h"

// agbcc cannot parse these large INCBIN initializers in title_screen.c's
// -ffunction-sections build. Keep the US resource names and JP ROM order in
// this data-only translation unit.
#define TITLE_SCREEN_STATIC_GRAPHICS __attribute__((section(".rodata.title_screen_static_graphics"), aligned(1)))

TITLE_SCREEN_STATIC_GRAPHICS const u32 sTitleScreenRayquazaGfx[] = INCBIN_U32("graphics/title_screen/rayquaza.4bpp.lz");
TITLE_SCREEN_STATIC_GRAPHICS const u32 sTitleScreenRayquazaTilemap[] = INCBIN_U32("graphics/title_screen/rayquaza.bin.lz");
TITLE_SCREEN_STATIC_GRAPHICS const u32 sTitleScreenLogoShineGfx[] = INCBIN_U32("graphics/title_screen/logo_shine.4bpp.lz");
TITLE_SCREEN_STATIC_GRAPHICS const u32 sTitleScreenCloudsGfx[] = INCBIN_U32("graphics/title_screen/clouds.4bpp.lz");

#undef TITLE_SCREEN_STATIC_GRAPHICS
