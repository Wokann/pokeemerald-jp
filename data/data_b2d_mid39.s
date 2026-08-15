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

	.globl gUnknown_8592BCC
gUnknown_8592BCC: @ 0x8592BCC
	.incbin "baserom_jp.gba", 0x592bcc, 0x2c

	.globl gUnknown_8592BF8
gUnknown_8592BF8: @ 0x8592BF8
	.incbin "baserom_jp.gba", 0x592bf8, 0x18

	.globl gUnknown_8592C10
gUnknown_8592C10: @ 0x8592C10
	.incbin "baserom_jp.gba", 0x592c10, 0x1c

	.globl gUnknown_8592C2C
gUnknown_8592C2C: @ 0x8592C2C
	.incbin "baserom_jp.gba", 0x592c2c, 0x28

	.globl gUnknown_8592C54
gUnknown_8592C54: @ 0x8592C54
	.incbin "baserom_jp.gba", 0x592c54, 0x14

	.globl gUnknown_8592C68
gUnknown_8592C68: @ 0x8592C68
	.incbin "baserom_jp.gba", 0x592c68, 0x14

	.globl gUnknown_8592C7C
gUnknown_8592C7C: @ 0x8592C7C
	.incbin "baserom_jp.gba", 0x592c7c, 0x8

	.globl gUnknown_8592C84
gUnknown_8592C84: @ 0x8592C84
	.incbin "baserom_jp.gba", 0x592c84, 0x2c

	.globl gUnknown_8592CB0
gUnknown_8592CB0: @ 0x8592CB0
	.incbin "baserom_jp.gba", 0x592cb0, 0x2c

	.globl gUnknown_8592CDC
gUnknown_8592CDC: @ 0x8592CDC
	.incbin "baserom_jp.gba", 0x592cdc, 0x160

	.globl gUnknown_8592E3C
gUnknown_8592E3C: @ 0x8592E3C
	.incbin "baserom_jp.gba", 0x592e3c, 0x16

	.globl gUnknown_8592E52
gUnknown_8592E52: @ 0x8592E52
	.incbin "baserom_jp.gba", 0x592e52, 0xa

	.globl gUnknown_8592E5C
gUnknown_8592E5C: @ 0x8592E5C
	.incbin "baserom_jp.gba", 0x592e5c, 0x10

	.globl gUnknown_8592E6C
gUnknown_8592E6C: @ 0x8592E6C
	.incbin "baserom_jp.gba", 0x592e6c, 0x10

	.globl gUnknown_8592E7C
gUnknown_8592E7C: @ 0x8592E7C
	.incbin "baserom_jp.gba", 0x592e7c, 0x24
