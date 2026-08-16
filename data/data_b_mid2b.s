.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.globl sBg_Pal
sBg_Pal: @ 0x82CB67C
	.incbin "graphics/misc/sBg_Pal.bin"

	.globl sDodrioNormalPal
sDodrioNormalPal: @ 0x82CB6BC
	.incbin "graphics/dodrio/sDodrioNormalPal.bin"

	.globl sDodrioShinyPal
sDodrioShinyPal: @ 0x82CB6DC
	.incbin "graphics/dodrio/sDodrioShinyPal.bin"

	.globl gUnknown_82CB6FC
gUnknown_82CB6FC: @ 0x82CB6FC
	.incbin "baserom_jp.gba", 0x2cb6fc, 0x40

	.globl sBerry_Gfx
sBerry_Gfx: @ 0x82CB73C
	.incbin "graphics/misc/sBerry_Gfx.bin"

	.globl sBg_Gfx
sBg_Gfx: @ 0x82CB910
	.incbin "graphics/misc/sBg_Gfx.bin"

	.globl sTreeBorder_Gfx
sTreeBorder_Gfx: @ 0x82CC1A0
	.incbin "graphics/misc/sTreeBorder_Gfx.bin"

	.globl sStatus_Gfx
sStatus_Gfx: @ 0x82CCF6C
	.incbin "graphics/battle_anims/sStatus_Gfx.bin"

	.globl sCloud_Gfx
sCloud_Gfx: @ 0x82CD000
	.incbin "graphics/misc/sCloud_Gfx.bin"

	.globl sDodrio_Gfx
sDodrio_Gfx: @ 0x82CD148
	.incbin "graphics/dodrio/sDodrio_Gfx.bin"

	.globl sDodrioBg_Tilemap
sDodrioBg_Tilemap: @ 0x82CE364
	.incbin "graphics/dodrio/sDodrioBg_Tilemap.bin"

	.globl sTreeBorderRight_Tilemap
sTreeBorderRight_Tilemap: @ 0x82CE5D0
	.incbin "graphics/misc/sTreeBorderRight_Tilemap.bin"

	.globl sTreeBorderLeft_Tilemap
sTreeBorderLeft_Tilemap: @ 0x82CE820
	.incbin "graphics/misc/sTreeBorderLeft_Tilemap.bin"

