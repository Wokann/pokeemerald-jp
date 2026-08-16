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

.globl gUnknown_8539C0E
gUnknown_8539C0E: @ 0x8539C0E
	.incbin "baserom_jp.gba", 0x539c0e, 0x42

	.globl gUnknown_8539C50
gUnknown_8539C50: @ 0x8539C50
	.incbin "baserom_jp.gba", 0x539c50, 0x6a4c

	.globl gUnknown_854069C
gUnknown_854069C: @ 0x854069C
	.incbin "baserom_jp.gba", 0x54069c, 0x2a54

	.globl gUnknown_85430F0
gUnknown_85430F0: @ 0x85430F0
	.incbin "baserom_jp.gba", 0x5430f0, 0x20

	.globl gUnknown_8543110
gUnknown_8543110: @ 0x8543110
	.incbin "baserom_jp.gba", 0x543110, 0x10

	.globl gUnknown_8543120
gUnknown_8543120: @ 0x8543120
	.incbin "baserom_jp.gba", 0x543120, 0x28

	.globl gUnknown_8543148
gUnknown_8543148: @ 0x8543148
	.incbin "baserom_jp.gba", 0x543148, 0x8

	.globl gUnknown_8543150
gUnknown_8543150: @ 0x8543150
	.incbin "baserom_jp.gba", 0x543150, 0x18

	.globl gUnknown_8543168
gUnknown_8543168: @ 0x8543168
	.incbin "baserom_jp.gba", 0x543168, 0x676

	.globl gUnknown_85437DE
gUnknown_85437DE: @ 0x85437DE
	.incbin "baserom_jp.gba", 0x5437de, 0x7e

	.globl gUnknown_854385C
gUnknown_854385C: @ 0x854385C
	.incbin "baserom_jp.gba", 0x54385c, 0x58c

	.globl gUnknown_8543DE8
gUnknown_8543DE8: @ 0x8543DE8
	.incbin "baserom_jp.gba", 0x543de8, 0x19c

	.globl gUnknown_8543F84
gUnknown_8543F84: @ 0x8543F84
	.incbin "baserom_jp.gba", 0x543f84, 0x188

	.globl gUnknown_854410C
gUnknown_854410C: @ 0x854410C
	.incbin "baserom_jp.gba", 0x54410c, 0x28

	.globl gUnknown_8544134
gUnknown_8544134: @ 0x8544134
	.incbin "baserom_jp.gba", 0x544134, 0x18

	.globl gUnknown_854414C
gUnknown_854414C: @ 0x854414C
	.incbin "baserom_jp.gba", 0x54414c, 0x54
