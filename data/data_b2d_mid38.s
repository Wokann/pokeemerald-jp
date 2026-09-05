.include "sound/MPlayDef.s"
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.section .rodata.mid38_after_starter_choose_data

	.globl gWallClockMale_Pal
gWallClockMale_Pal: @ 0x8590D68
	.incbin "graphics/wallclock/gWallClockMale_Pal.bin"

	.globl gWallClockFemale_Pal
gWallClockFemale_Pal: @ 0x8590D88
	.incbin "graphics/wallclock/gWallClockFemale_Pal.bin"

	.globl gWallClockStart_Tilemap
gWallClockStart_Tilemap: @ 0x8590DA8
	.incbin "graphics/wallclock/gWallClockStart_Tilemap.bin"

	.globl gWallClockView_Tilemap
gWallClockView_Tilemap: @ 0x8591074
	.incbin "graphics/wallclock/gWallClockView_Tilemap.bin"

	.globl gWallClock_Gfx
gWallClock_Gfx: @ 0x859130C
	.incbin "graphics/wallclock/gWallClock_Gfx.bin"
