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

	.globl gUnknown_84E8B94
gUnknown_84E8B94: @ 0x84E8B94
	.incbin "baserom_jp.gba", 0x4e8b94, 0x8

	.globl gUnknown_84E8B9C
gUnknown_84E8B9C: @ 0x84E8B9C
	.incbin "baserom_jp.gba", 0x4e8b9c, 0x60

	.globl gUnknown_84E8BFC
gUnknown_84E8BFC: @ 0x84E8BFC
	.incbin "baserom_jp.gba", 0x4e8bfc, 0x20

	.globl gUnknown_84E8C1C
gUnknown_84E8C1C: @ 0x84E8C1C
	.incbin "baserom_jp.gba", 0x4e8c1c, 0x8

	.globl gUnknown_84E8C24
gUnknown_84E8C24: @ 0x84E8C24
	.incbin "baserom_jp.gba", 0x4e8c24, 0x8

	.globl gUnknown_84E8C2C
gUnknown_84E8C2C: @ 0x84E8C2C
	.incbin "baserom_jp.gba", 0x4e8c2c, 0x68

	.globl gUnknown_84E8C94
gUnknown_84E8C94: @ 0x84E8C94
	.incbin "baserom_jp.gba", 0x4e8c94, 0x4

	.globl gUnknown_84E8C98
gUnknown_84E8C98: @ 0x84E8C98
	.incbin "baserom_jp.gba", 0x4e8c98, 0x10

	.globl gUnknown_84E8CA8
gUnknown_84E8CA8: @ 0x84E8CA8
	.incbin "baserom_jp.gba", 0x4e8ca8, 0x8
