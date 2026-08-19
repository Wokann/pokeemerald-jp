.include "sound/MPlayDef.s"
	.section .rodata.mid1_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.globl gUnknown_85ECE88
gUnknown_85ECE88: @ 0x85ECE88
	.incbin "baserom_jp.gba", 0x5ece88, 0x134

	.globl gUnknown_85ECFBC
gUnknown_85ECFBC: @ 0x85ECFBC
	.incbin "baserom_jp.gba", 0x5ecfbc, 0x78

	.globl gUnknown_85ED034
gUnknown_85ED034: @ 0x85ED034
	.incbin "baserom_jp.gba", 0x5ed034, 0xc

	.globl gUnknown_85ED040
gUnknown_85ED040: @ 0x85ED040
	.incbin "baserom_jp.gba", 0x5ed040, 0xc

	.globl gUnknown_85ED04C
gUnknown_85ED04C: @ 0x85ED04C
	.incbin "baserom_jp.gba", 0x5ed04c, 0xc

	.globl gUnknown_85ED058
gUnknown_85ED058: @ 0x85ED058
	.incbin "baserom_jp.gba", 0x5ed058, 0xc

	.globl gUnknown_85ED064
gUnknown_85ED064: @ 0x85ED064
	.incbin "baserom_jp.gba", 0x5ed064, 0x8

	.globl gUnknown_85ED06C
gUnknown_85ED06C: @ 0x85ED06C
	.incbin "baserom_jp.gba", 0x5ed06c, 0xa8

	.globl gUnknown_85ED114
gUnknown_85ED114: @ 0x85ED114
	.incbin "baserom_jp.gba", 0x5ed114, 0x20

	.globl gUnknown_85ED134
gUnknown_85ED134: @ 0x85ED134
	.incbin "baserom_jp.gba", 0x5ed134, 0x28

	.globl gUnknown_85ED15C
gUnknown_85ED15C: @ 0x85ED15C
	.incbin "baserom_jp.gba", 0x5ed15c, 0x20

	.globl gUnknown_85ED17C
gUnknown_85ED17C: @ 0x85ED17C
	.incbin "baserom_jp.gba", 0x5ed17c, 0xa7

	.globl gUnknown_85ED223
gUnknown_85ED223: @ 0x85ED223
	.incbin "baserom_jp.gba", 0x5ed223, 0x81

	.globl sTextPrinterFunctions
sTextPrinterFunctions: @ 0x85ED2A4
	.4byte PrintInfoPageText + 1, PrintSkillsPageText + 1, PrintBattleMoves + 1, PrintContestMoves + 1

	.globl sTextPrinterTasks
sTextPrinterTasks: @ 0x85ED2B4
	.4byte Task_PrintInfoPage + 1, Task_PrintSkillsPage + 1, Task_PrintBattleMoves + 1, Task_PrintContestMoves + 1

	.globl gUnknown_85ED2C4
gUnknown_85ED2C4: @ 0x85ED2C4
	.string "{COLOR 5}{SHADOW 6}$"
	.globl gUnknown_85ED2CB
gUnknown_85ED2CB: @ 0x85ED2CB
	.string "{COLOR 1}{SHADOW 2}$"
	.globl gUnknown_85ED2D2
gUnknown_85ED2D2: @ 0x85ED2D2
	.string "{DYNAMIC 0}/{DYNAMIC 1}\n"
	.string "{DYNAMIC 2}\n"
	.string "{DYNAMIC 3}$"
	.globl gUnknown_85ED2DE
gUnknown_85ED2DE: @ 0x85ED2DE
	.string "{DYNAMIC 0}\n"
	.string "{DYNAMIC 1}\n"
	.string "{DYNAMIC 2}$"
	.globl gUnknown_85ED2E7
gUnknown_85ED2E7: @ 0x85ED2E7
	.incbin "baserom_jp.gba", 0x5ed2e7, 0x125

	.globl gUnknown_85ED40C
gUnknown_85ED40C: @ 0x85ED40C
	.incbin "baserom_jp.gba", 0x5ed40c, 0x8

	.globl gUnknown_85ED414
gUnknown_85ED414: @ 0x85ED414
	.incbin "baserom_jp.gba", 0x5ed414, 0x18

	.globl gUnknown_85ED42C
gUnknown_85ED42C: @ 0x85ED42C
	.incbin "baserom_jp.gba", 0x5ed42c, 0x98

	.globl gUnknown_85ED4C4
gUnknown_85ED4C4: @ 0x85ED4C4
	.incbin "baserom_jp.gba", 0x5ed4c4, 0x8

	.globl gUnknown_85ED4CC
gUnknown_85ED4CC: @ 0x85ED4CC
	.incbin "baserom_jp.gba", 0x5ed4cc, 0x8

	.globl gUnknown_85ED4D4
gUnknown_85ED4D4: @ 0x85ED4D4
	.incbin "baserom_jp.gba", 0x5ed4d4, 0x74

	.globl gUnknown_85ED548
gUnknown_85ED548: @ 0x85ED548
	.incbin "baserom_jp.gba", 0x5ed548, 0x8

	.globl gUnknown_85ED550
gUnknown_85ED550: @ 0x85ED550
	.incbin "baserom_jp.gba", 0x5ed550, 0x8

	.globl gUnknown_85ED558
gUnknown_85ED558: @ 0x85ED558
	.incbin "baserom_jp.gba", 0x5ed558, 0x18

	.globl gUnknown_85ED570
gUnknown_85ED570: @ 0x85ED570
	.incbin "baserom_jp.gba", 0x5ed570, 0x20

