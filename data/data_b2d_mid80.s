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

.globl gUnknown_85CA4A6
gUnknown_85CA4A6: @ 0x85CA4A6
	.incbin "baserom_jp.gba", 0x5ca4a6, 0x26
	.globl gUnknown_85CA4CC
gUnknown_85CA4CC: @ 0x85CA4CC
	.incbin "baserom_jp.gba", 0x5ca4cc, 0x26
	.globl gUnknown_85CA4F2
gUnknown_85CA4F2: @ 0x85CA4F2
	.incbin "baserom_jp.gba", 0x5ca4f2, 0x20
	.globl gUnknown_85CA512
gUnknown_85CA512: @ 0x85CA512
	.incbin "baserom_jp.gba", 0x5ca512, 0x29
	.globl gUnknown_85CA53B
gUnknown_85CA53B: @ 0x85CA53B
	.incbin "baserom_jp.gba", 0x5ca53b, 0x28
	.globl gUnknown_85CA563
gUnknown_85CA563: @ 0x85CA563
	.incbin "baserom_jp.gba", 0x5ca563, 0xd
	.globl gUnknown_85CA570
gUnknown_85CA570: @ 0x85CA570
	.incbin "baserom_jp.gba", 0x5ca570, 0x23
	.globl gUnknown_85CA593
gUnknown_85CA593: @ 0x85CA593
	.incbin "baserom_jp.gba", 0x5ca593, 0x23
	.globl gUnknown_85CA5B6
