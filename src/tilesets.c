#include "global.h"
#include "tilesets.h"
#include "tileset_anims.h"

// Preserve JP physical order and the halfword-aligned metatile stream.
#define TILESET_GRAPHICS_DATA __attribute__((section(".rodata.tileset_graphics"), aligned(4)))
#define TILESET_METATILES_DATA __attribute__((section(".rodata.tileset_metatiles"), aligned(2)))
#define TILESET_HEADER_DATA __attribute__((section(".rodata.tileset_headers"), aligned(4)))

#include "data/tilesets/graphics.h"
#include "data/tilesets/metatiles.h"
#include "data/tilesets/headers.h"

#undef TILESET_GRAPHICS_DATA
#undef TILESET_METATILES_DATA
#undef TILESET_HEADER_DATA
