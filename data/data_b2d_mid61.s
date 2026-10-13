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
