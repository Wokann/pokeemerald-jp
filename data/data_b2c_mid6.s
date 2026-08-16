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

	.globl gPokenavCondition_Pal
gPokenavCondition_Pal: @ 0x85F4E0C
	.incbin "graphics/pokenav/gPokenavCondition_Pal.bin"

	.globl gConditionGraphData_Pal
gConditionGraphData_Pal: @ 0x85F4E2C
	.incbin "graphics/pokenav_conditions/gConditionGraphData_Pal.bin"

	.globl gConditionText_Pal
gConditionText_Pal: @ 0x85F4E4C
	.incbin "graphics/pokenav_conditions/gConditionText_Pal.bin"

	.globl gPokenavCondition_Gfx
gPokenavCondition_Gfx: @ 0x85F4E6C
	.incbin "graphics/pokenav/gPokenavCondition_Gfx.bin"

	.globl gPokenavCondition_Tilemap
gPokenavCondition_Tilemap: @ 0x85F5600
	.incbin "graphics/pokenav/gPokenavCondition_Tilemap.bin"

	.globl sConditionGraphData_Gfx
sConditionGraphData_Gfx: @ 0x85F57EC
	.incbin "graphics/pokenav_conditions/sConditionGraphData_Gfx.bin"

	.globl sConditionGraphData_Tilemap
sConditionGraphData_Tilemap: @ 0x85F5800
	.incbin "graphics/pokenav_conditions/sConditionGraphData_Tilemap.bin"

	.globl gPokenavOptions_Tilemap
gPokenavOptions_Tilemap: @ 0x85F58FC
	.incbin "graphics/pokenav/gPokenavOptions_Tilemap.bin"

	.globl sPokenavMonMarkings_Pal
sPokenavMonMarkings_Pal: @ 0x85F5944
	.incbin "graphics/pokenav/sPokenavMonMarkings_Pal.bin"

