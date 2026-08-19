.include "sound/MPlayDef.s"
	.section .rodata.mid100_shared_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_85DC21C
gUnknown_85DC21C: @ 0x85DC21C
	.incbin "baserom_jp.gba", 0x5dc21c, 0xc

	.section .rodata.mid100_frontier_rest

	.globl gUnknown_85DCB7C
gUnknown_85DCB7C: @ 0x85DCB7C
	.incbin "baserom_jp.gba", 0x5dcb7c, 0x1c

	.globl gUnknown_85DCB98
gUnknown_85DCB98: @ 0x85DCB98
	.incbin "baserom_jp.gba", 0x5dcb98, 0xc

	.globl gUnknown_85DCBA4
gUnknown_85DCBA4: @ 0x85DCBA4
	.incbin "baserom_jp.gba", 0x5dcba4, 0x33c

	.globl gUnknown_85DCEE0
gUnknown_85DCEE0: @ 0x85DCEE0
	.incbin "baserom_jp.gba", 0x5dcee0, 0x348

	.globl gUnknown_85DD228
gUnknown_85DD228: @ 0x85DD228
	.incbin "baserom_jp.gba", 0x5dd228, 0x1c

	.globl gUnknown_85DD244
gUnknown_85DD244: @ 0x85DD244
	.incbin "baserom_jp.gba", 0x5dd244, 0x5c

	.globl gUnknown_85DD2A0
gUnknown_85DD2A0: @ 0x85DD2A0
	.incbin "baserom_jp.gba", 0x5dd2a0, 0x8

	.globl gUnknown_85DD2A8
gUnknown_85DD2A8: @ 0x85DD2A8
	.incbin "baserom_jp.gba", 0x5dd2a8, 0x8

	.globl gUnknown_85DD2B0
gUnknown_85DD2B0: @ 0x85DD2B0
	.incbin "baserom_jp.gba", 0x5dd2b0, 0x8

	.globl gUnknown_85DD2B8
gUnknown_85DD2B8: @ 0x85DD2B8
	.incbin "baserom_jp.gba", 0x5dd2b8, 0x8

	.globl gUnknown_85DD2C0
gUnknown_85DD2C0: @ 0x85DD2C0
	.incbin "baserom_jp.gba", 0x5dd2c0, 0x8

	.globl gUnknown_85DD2C8
gUnknown_85DD2C8: @ 0x85DD2C8
	.incbin "baserom_jp.gba", 0x5dd2c8, 0x8

	.globl gUnknown_85DD2D0
gUnknown_85DD2D0: @ 0x85DD2D0
	.incbin "baserom_jp.gba", 0x5dd2d0, 0x8

	.globl gUnknown_85DD2D8
gUnknown_85DD2D8: @ 0x85DD2D8
	.incbin "baserom_jp.gba", 0x5dd2d8, 0x8

	.globl gUnknown_85DD2E0
gUnknown_85DD2E0: @ 0x85DD2E0
	.incbin "baserom_jp.gba", 0x5dd2e0, 0x8

	.globl gUnknown_85DD2E8
