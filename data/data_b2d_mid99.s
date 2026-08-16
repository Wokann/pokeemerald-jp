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

	.globl gUnknown_85DBC11
gUnknown_85DBC11: @ 0x85DBC11
	.incbin "baserom_jp.gba", 0x5dbc11, 0x13

	.globl sSelect_MenuOptionFuncs
sSelect_MenuOptionFuncs: @ 0x85DBC24
	.4byte Select_OptionSummary + 1, Select_OptionRentDeselect + 1, Select_OptionOthers + 1

	.globl gUnknown_85DBC30
gUnknown_85DBC30: @ 0x85DBC30
	.incbin "baserom_jp.gba", 0x5dbc30, 0xc

	.globl gUnknown_85DBC3C
gUnknown_85DBC3C: @ 0x85DBC3C
	.incbin "baserom_jp.gba", 0x5dbc3c, 0x38

	.globl gUnknown_85DBC74
gUnknown_85DBC74: @ 0x85DBC74
	.incbin "baserom_jp.gba", 0x5dbc74, 0xa

	.globl gUnknown_85DBC7E
gUnknown_85DBC7E: @ 0x85DBC7E
	.incbin "baserom_jp.gba", 0x5dbc7e, 0x3

	.globl gUnknown_85DBC81
gUnknown_85DBC81: @ 0x85DBC81
	.incbin "baserom_jp.gba", 0x5dbc81, 0x15f

	.globl gUnknown_85DBDE0
gUnknown_85DBDE0: @ 0x85DBDE0
	.incbin "baserom_jp.gba", 0x5dbde0, 0x18

	.globl gUnknown_85DBDF8
gUnknown_85DBDF8: @ 0x85DBDF8
	.incbin "baserom_jp.gba", 0x5dbdf8, 0x18

	.globl gUnknown_85DBE10
gUnknown_85DBE10: @ 0x85DBE10
	.incbin "baserom_jp.gba", 0x5dbe10, 0x18

	.globl gUnknown_85DBE28
gUnknown_85DBE28: @ 0x85DBE28
	.incbin "baserom_jp.gba", 0x5dbe28, 0x18

	.globl gUnknown_85DBE40
gUnknown_85DBE40: @ 0x85DBE40
	.incbin "baserom_jp.gba", 0x5dbe40, 0x18

	.globl gUnknown_85DBE58
gUnknown_85DBE58: @ 0x85DBE58
	.incbin "baserom_jp.gba", 0x5dbe58, 0x50

	.globl gUnknown_85DBEA8
gUnknown_85DBEA8: @ 0x85DBEA8
	.incbin "baserom_jp.gba", 0x5dbea8, 0x10

	.globl gUnknown_85DBEB8
gUnknown_85DBEB8: @ 0x85DBEB8
	.incbin "baserom_jp.gba", 0x5dbeb8, 0x184

	.globl gUnknown_85DC03C
gUnknown_85DC03C: @ 0x85DC03C
	.incbin "baserom_jp.gba", 0x5dc03c, 0x18

	.globl gUnknown_85DC054
gUnknown_85DC054: @ 0x85DC054
	.incbin "baserom_jp.gba", 0x5dc054, 0x18

	.globl gUnknown_85DC06C
gUnknown_85DC06C: @ 0x85DC06C
	.incbin "baserom_jp.gba", 0x5dc06c, 0x18

	.globl gUnknown_85DC084
gUnknown_85DC084: @ 0x85DC084
	.incbin "baserom_jp.gba", 0x5dc084, 0x18

	.globl gUnknown_85DC09C
gUnknown_85DC09C: @ 0x85DC09C
	.incbin "baserom_jp.gba", 0x5dc09c, 0x18

	.globl gUnknown_85DC0B4
