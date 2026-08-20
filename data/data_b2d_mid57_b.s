.include "sound/MPlayDef.s"
	.section .rodata.mid57b_contest_pre_ui
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_8560CF4
gUnknown_8560CF4: @ 0x8560CF4
	.incbin "baserom_jp.gba", 0x560cf4, 0x80

	.globl gUnknown_8560D74
gUnknown_8560D74: @ 0x8560D74
	.incbin "baserom_jp.gba", 0x560d74, 0xf8

	.globl gUnknown_8560E6C
gUnknown_8560E6C: @ 0x8560E6C
	.incbin "baserom_jp.gba", 0x560e6c, 0x14

	.globl gUnknown_8560E80
gUnknown_8560E80: @ 0x8560E80
	.incbin "baserom_jp.gba", 0x560e80, 0x18
