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
	.globl gBerryCrush_Crusher_Pal
gBerryCrush_Crusher_Pal: @ 0x82C5F84
	.incbin "graphics/berry_crush/gBerryCrush_Crusher_Pal.bin"

	.globl gBerryCrush_Crusher_Gfx
gBerryCrush_Crusher_Gfx: @ 0x82C6104
	.incbin "graphics/berry_crush/gBerryCrush_Crusher_Gfx.bin"

	.globl sCrusherTop_Tilemap
sCrusherTop_Tilemap: @ 0x82C74D4
	.incbin "graphics/berry_crush/sCrusherTop_Tilemap.bin"

	.globl sContainerCap_Tilemap
sContainerCap_Tilemap: @ 0x82C7604
	.incbin "graphics/misc/sContainerCap_Tilemap.bin"

	.globl sBg_Tilemap
sBg_Tilemap: @ 0x82C779C
	.incbin "graphics/misc/sBg_Tilemap.bin"

	.globl sPlayerNameWindowGfx
sPlayerNameWindowGfx: @ 0x82C79C4
	.incbin "graphics/naming_screen/sPlayerNameWindowGfx.bin"

