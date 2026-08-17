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

	.globl gUnknown_8300AB1
gUnknown_8300AB1: @ 0x8300AB1
	.incbin "baserom_jp.gba", 0x300ab1, 0x4b

	.globl gUnknown_8300AFC
gUnknown_8300AFC: @ 0x8300AFC
	.incbin "baserom_jp.gba", 0x300afc, 0x2c

	.globl sActionTexts
	.set sActionTexts, gUnknown_8300AFC

	.globl gUnknown_8300B28
gUnknown_8300B28: @ 0x8300B28
	.incbin "baserom_jp.gba", 0x300b28, 0xb4

	.globl sSelectTradeMonActions
	.set sSelectTradeMonActions, gUnknown_8300B28

	.globl gUnknown_8300BDC
gUnknown_8300BDC: @ 0x8300BDC
	.incbin "baserom_jp.gba", 0x300bdc, 0x24

	.globl gUnknown_8300C00
gUnknown_8300C00: @ 0x8300C00
	.incbin "baserom_jp.gba", 0x300c00, 0x4

	.globl gUnknown_8300C04
gUnknown_8300C04: @ 0x8300C04
	.incbin "baserom_jp.gba", 0x300c04, 0x10

	.globl gUnknown_8300C14
gUnknown_8300C14: @ 0x8300C14
	.incbin "baserom_jp.gba", 0x300c14, 0x98

	.globl gUnknown_8300CAC
gUnknown_8300CAC: @ 0x8300CAC

	.globl sTradeYesNoWindowTemplate
	.set sTradeYesNoWindowTemplate, gUnknown_8300CAC
	.incbin "baserom_jp.gba", 0x300CAC, 0x94
	.globl gUnknown_8300D40
gUnknown_8300D40: @ 0x8300D40
	.incbin "baserom_jp.gba", 0x300d40, 0x2024

	.globl gUnknown_8302D64
gUnknown_8302D64: @ 0x8302D64
	.incbin "baserom_jp.gba", 0x302d64, 0x1fa0

	.globl gUnknown_8304D04
gUnknown_8304D04: @ 0x8304D04
	.incbin "baserom_jp.gba", 0x304d04, 0x1020

	.globl gUnknown_8305D24
gUnknown_8305D24: @ 0x8305D24
	.incbin "baserom_jp.gba", 0x305d24, 0x60

	.globl gUnknown_8305D84
gUnknown_8305D84: @ 0x8305D84
	.incbin "baserom_jp.gba", 0x305d84, 0x1420

	.globl gUnknown_83071A4
gUnknown_83071A4: @ 0x83071A4
	.incbin "baserom_jp.gba", 0x3071a4, 0x2840

	.globl gUnknown_83099E4
gUnknown_83099E4: @ 0x83099E4
	.incbin "baserom_jp.gba", 0x3099e4, 0x100

	.globl gUnknown_8309AE4
gUnknown_8309AE4: @ 0x8309AE4
	.incbin "baserom_jp.gba", 0x309ae4, 0x100

	.globl gUnknown_8309BE4
gUnknown_8309BE4: @ 0x8309BE4
	.incbin "baserom_jp.gba", 0x309be4, 0x1000

	.globl gUnknown_830ABE4
gUnknown_830ABE4: @ 0x830ABE4
	.incbin "baserom_jp.gba", 0x30abe4, 0x1000

	.globl gUnknown_830BBE4
gUnknown_830BBE4: @ 0x830BBE4
	.incbin "baserom_jp.gba", 0x30bbe4, 0x100

	.globl gUnknown_830BCE4
gUnknown_830BCE4: @ 0x830BCE4
	.incbin "baserom_jp.gba", 0x30bce4, 0x200

	.globl gUnknown_830BEE4
gUnknown_830BEE4: @ 0x830BEE4
	.incbin "baserom_jp.gba", 0x30bee4, 0x200

	.globl gUnknown_830C0E4
gUnknown_830C0E4: @ 0x830C0E4
	.incbin "baserom_jp.gba", 0x30c0e4, 0x20

	.globl gUnknown_830C104
gUnknown_830C104: @ 0x830C104
	.incbin "baserom_jp.gba", 0x30c104, 0x690

	.globl gUnknown_830C794
gUnknown_830C794: @ 0x830C794
	.incbin "baserom_jp.gba", 0x30c794, 0x7c8

	.globl gUnknown_830CF5C
gUnknown_830CF5C: @ 0x830CF5C
	.incbin "baserom_jp.gba", 0x30cf5c, 0x8

	.globl gUnknown_830CF64
gUnknown_830CF64: @ 0x830CF64
	.incbin "baserom_jp.gba", 0x30cf64, 0x8

	.globl gUnknown_830CF6C
gUnknown_830CF6C: @ 0x830CF6C
	.incbin "baserom_jp.gba", 0x30cf6c, 0x48

	.globl gUnknown_830CFB4
gUnknown_830CFB4: @ 0x830CFB4
	.incbin "baserom_jp.gba", 0x30cfb4, 0x8

	.globl gUnknown_830CFBC
gUnknown_830CFBC: @ 0x830CFBC
	.incbin "baserom_jp.gba", 0x30cfbc, 0x8

	.globl gUnknown_830CFC4
gUnknown_830CFC4: @ 0x830CFC4
	.incbin "baserom_jp.gba", 0x30cfc4, 0x8

	.globl gUnknown_830CFCC
gUnknown_830CFCC: @ 0x830CFCC
	.incbin "baserom_jp.gba", 0x30cfcc, 0x38

	.globl gUnknown_830D004
gUnknown_830D004: @ 0x830D004
	.incbin "baserom_jp.gba", 0x30d004, 0x8

	.globl gUnknown_830D00C
gUnknown_830D00C: @ 0x830D00C
	.incbin "baserom_jp.gba", 0x30d00c, 0x2c

	.globl gUnknown_830D038
gUnknown_830D038: @ 0x830D038
	.incbin "baserom_jp.gba", 0x30d038, 0x8

	.globl gUnknown_830D040
gUnknown_830D040: @ 0x830D040
	.incbin "baserom_jp.gba", 0x30d040, 0x70

	.globl gUnknown_830D0B0
gUnknown_830D0B0: @ 0x830D0B0
	.incbin "baserom_jp.gba", 0x30d0b0, 0x8

	.globl gUnknown_830D0B8
gUnknown_830D0B8: @ 0x830D0B8
	.incbin "baserom_jp.gba", 0x30d0b8, 0x18

	.globl gUnknown_830D0D0
gUnknown_830D0D0: @ 0x830D0D0
	.incbin "baserom_jp.gba", 0x30d0d0, 0x18

	.globl gUnknown_830D0E8
gUnknown_830D0E8: @ 0x830D0E8
	.incbin "baserom_jp.gba", 0x30d0e8, 0x28

	.globl gUnknown_830D110
gUnknown_830D110: @ 0x830D110
	.incbin "baserom_jp.gba", 0x30d110, 0x4

	.globl gUnknown_830D114
gUnknown_830D114: @ 0x830D114
	.incbin "baserom_jp.gba", 0x30d114, 0xf0

	.globl gUnknown_830D204
gUnknown_830D204: @ 0x830D204
	.incbin "baserom_jp.gba", 0x30d204, 0x3c
