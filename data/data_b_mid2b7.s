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
	.globl gUnknown_82DE7DC
gUnknown_82DE7DC: @ 0x82DE7DC
	.incbin "baserom_jp.gba", 0x2de7dc, 0x6e0

	.globl gUnknown_82DEEBC
gUnknown_82DEEBC: @ 0x82DEEBC
	.incbin "baserom_jp.gba", 0x2deebc, 0x46a8



