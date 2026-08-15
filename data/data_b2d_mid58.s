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

gUnknown_8563150: @ 0x8563150
	.incbin "baserom_jp.gba", 0x563150, 0x4b4

	.globl gBerryCrush_BerryData
gBerryCrush_BerryData: @ 0x8563604
	.incbin "baserom_jp.gba", 0x563604, 0xac

	.globl gUnknown_85636B0
gUnknown_85636B0: @ 0x85636B0
	.incbin "baserom_jp.gba", 0x5636b0, 0xb68

	.globl gUnknown_8564218
gUnknown_8564218: @ 0x8564218
	.incbin "baserom_jp.gba", 0x564218, 0x388

	.globl gStdStrings
gStdStrings: @ 0x85645A0
	.incbin "baserom_jp.gba", 0x5645a0, 0x78

	.globl gUnknown_8564618
gUnknown_8564618: @ 0x8564618
	.incbin "baserom_jp.gba", 0x564618, 0x8

	.globl gUnknown_8564620
gUnknown_8564620: @ 0x8564620
	.incbin "baserom_jp.gba", 0x564620, 0x1c

	.globl gUnknown_856463C
gUnknown_856463C: @ 0x856463C
	.incbin "baserom_jp.gba", 0x56463c, 0x10

	.globl gUnknown_856464C
gUnknown_856464C: @ 0x856464C
	.incbin "baserom_jp.gba", 0x56464c, 0x10

	.globl gUnknown_856465C
gUnknown_856465C: @ 0x856465C
	.incbin "baserom_jp.gba", 0x56465c, 0x10

	.globl gUnknown_856466C
gUnknown_856466C: @ 0x856466C
	.incbin "baserom_jp.gba", 0x56466c, 0x14

	.globl gUnknown_8564680
gUnknown_8564680: @ 0x8564680
	.incbin "baserom_jp.gba", 0x564680, 0xc

	.globl gUnknown_856468C
gUnknown_856468C: @ 0x856468C
	.incbin "baserom_jp.gba", 0x56468c, 0xb8c

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
