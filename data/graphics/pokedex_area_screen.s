	.section .rodata.pokedex_area_screen_graphics_prefix, "a", %progbits

	.globl sAreaGlow_Pal
sAreaGlow_Pal: @ 0x0859381C
	.incbin "baserom_jp.gba", 0x59381c, 0x20

	.globl sAreaGlow_Gfx
sAreaGlow_Gfx: @ 0x0859383C
	.incbin "baserom_jp.gba", 0x59383c, 0x134

	.section .rodata.pokedex_area_screen_graphics_suffix, "a", %progbits

	.globl sAreaMarkerSpriteSheet
sAreaMarkerSpriteSheet: @ 0x085939A4
	.incbin "baserom_jp.gba", 0x5939a4, 0x8

	.globl sAreaMarkerSpritePalette
sAreaMarkerSpritePalette: @ 0x085939AC
	.incbin "baserom_jp.gba", 0x5939ac, 0x8

	.globl sAreaMarkerOamData
sAreaMarkerOamData: @ 0x085939B4
	.incbin "baserom_jp.gba", 0x5939b4, 0x8

	.globl sAreaMarkerSpriteTemplate
sAreaMarkerSpriteTemplate: @ 0x085939BC
	.incbin "baserom_jp.gba", 0x5939bc, 0x18

	.globl sAreaMarkerPalette
sAreaMarkerPalette: @ 0x085939D4
	.incbin "baserom_jp.gba", 0x5939d4, 0x20

	.globl sAreaMarkerTiles
sAreaMarkerTiles: @ 0x085939F4
	.incbin "baserom_jp.gba", 0x5939f4, 0x80

	.globl sAreaUnknownSpritePalette
sAreaUnknownSpritePalette: @ 0x08593A74
	.incbin "baserom_jp.gba", 0x593a74, 0x8

	.globl sAreaUnknownOamData
sAreaUnknownOamData: @ 0x08593A7C
	.incbin "baserom_jp.gba", 0x593a7c, 0x8

	.globl sAreaUnknownSpriteTemplate
sAreaUnknownSpriteTemplate: @ 0x08593A84
	.incbin "baserom_jp.gba", 0x593a84, 0x18

	.globl gPokedexAreaScreenAreaUnknown_Pal
gPokedexAreaScreenAreaUnknown_Pal: @ 0x08593A9C
	.incbin "baserom_jp.gba", 0x593a9c, 0x20

	.globl gPokedexAreaScreenAreaUnknown_Gfx
gPokedexAreaScreenAreaUnknown_Gfx: @ 0x08593ABC
	.incbin "baserom_jp.gba", 0x593abc, 0x1e4
