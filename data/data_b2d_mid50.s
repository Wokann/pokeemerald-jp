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

	.globl gUnknown_830D26A
gUnknown_830D26A: @ 0x830D26A
	.incbin "baserom_jp.gba", 0x30d26a, 0x12

	.globl gUnknown_830D27C
gUnknown_830D27C: @ 0x830D27C
	.incbin "baserom_jp.gba", 0x30d27c, 0x10

	.globl gUnknown_830D28C
gUnknown_830D28C: @ 0x830D28C
	.incbin "baserom_jp.gba", 0x30d28c, 0x8

	.globl gUnknown_830D294
gUnknown_830D294: @ 0x830D294
	.incbin "baserom_jp.gba", 0x30d294, 0x10

	.globl gUnknown_830D2A4
gUnknown_830D2A4: @ 0x830D2A4
	.incbin "baserom_jp.gba", 0x30d2a4, 0x6c

	.globl gUnknown_830D310
gUnknown_830D310: @ 0x830D310
	.incbin "baserom_jp.gba", 0x30d310, 0x44

	.globl gUnknown_830D354
gUnknown_830D354: @ 0x830D354
	.incbin "baserom_jp.gba", 0x30d354, 0x20

	.globl gUnknown_830D374
gUnknown_830D374: @ 0x830D374
	.incbin "baserom_jp.gba", 0x30d374, 0x400

	.globl gUnknown_830D774
gUnknown_830D774: @ 0x830D774
	.incbin "baserom_jp.gba", 0x30d774, 0x1f3a
