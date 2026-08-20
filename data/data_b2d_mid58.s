.include "sound/MPlayDef.s"
	.section .rodata.mid58_pre_std_strings
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.globl gUnknown_85636B8
gUnknown_85636B8: @ 0x85636B8
	.incbin "baserom_jp.gba", 0x5636b8, 0xb60

	.globl gUnknown_8564218
gUnknown_8564218: @ 0x8564218
	.incbin "baserom_jp.gba", 0x564218, 0x388

	.section .rodata.mid58_post_link_services

	.globl gUnknown_8564698
gUnknown_8564698: @ 0x8564698
	.incbin "baserom_jp.gba", 0x564698, 0xb80

	.globl gUnknown_8565218
gUnknown_8565218: @ 0x8565218
	.incbin "baserom_jp.gba", 0x565218, 0x40

	.globl gUnknown_8565258
gUnknown_8565258: @ 0x8565258
	.incbin "baserom_jp.gba", 0x565258, 0xc0

	.globl gUnknown_8565318
gUnknown_8565318: @ 0x8565318
	.incbin "baserom_jp.gba", 0x565318, 0x20c

	.globl gUnknown_8565524
gUnknown_8565524: @ 0x8565524
	.incbin "baserom_jp.gba", 0x565524, 0xdc

	.globl gUnknown_8565600
gUnknown_8565600: @ 0x8565600
	.incbin "baserom_jp.gba", 0x565600, 0xc8

	.globl gUnknown_85656C8
gUnknown_85656C8: @ 0x85656C8
	.incbin "baserom_jp.gba", 0x5656c8, 0x190
