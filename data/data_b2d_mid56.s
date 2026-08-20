.include "sound/MPlayDef.s"
	.section .rodata.mid56_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

.globl gUnknown_85467C1
gUnknown_85467C1: @ 0x85467C1
	.incbin "baserom_jp.gba", 0x5467c1, 0x3

	.globl gUnknown_85467C4
gUnknown_85467C4: @ 0x85467C4
	.incbin "baserom_jp.gba", 0x5467c4, 0xc

	.globl gUnknown_85467D0
gUnknown_85467D0: @ 0x85467D0
	.incbin "baserom_jp.gba", 0x5467d0, 0x6

	.globl gUnknown_85467D6
gUnknown_85467D6: @ 0x85467D6
	.incbin "baserom_jp.gba", 0x5467d6, 0x6

	.globl gUnknown_85467DC
gUnknown_85467DC: @ 0x85467DC
	.incbin "baserom_jp.gba", 0x5467dc, 0x4

	.globl gUnknown_85467E0
gUnknown_85467E0: @ 0x85467E0
	.incbin "baserom_jp.gba", 0x5467e0, 0x4
