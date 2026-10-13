.include "sound/MPlayDef.s"
	.section .rodata.data_b2d_mid61_before_mon_markings_data
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_8579F34
gUnknown_8579F34: @ 0x8579F34
	.incbin "baserom_jp.gba", 0x579f34, 0x4

	.globl gMonMarkingsMenu_Pal
gMonMarkingsMenu_Pal: @ 0x8579F38
	.incbin "graphics/mon_markings/gMonMarkingsMenu_Pal.bin"

	.globl gMonMarkingsMenu_Gfx
gMonMarkingsMenu_Gfx: @ 0x8579F58
	.incbin "graphics/mon_markings/gMonMarkingsMenu_Gfx.bin"

	.globl sMonMarkings_Pal
sMonMarkings_Pal: @ 0x857A278
	.incbin "graphics/mon_markings/sMonMarkings_Pal.bin"

	.globl sMonMarkings_Gfx
sMonMarkings_Gfx: @ 0x857A298
	.incbin "graphics/mon_markings/sMonMarkings_Gfx.bin"
