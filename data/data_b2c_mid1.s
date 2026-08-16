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

	.globl gUnknown_85ED2A4
gUnknown_85ED2A4: @ 0x85ED2A4
	.incbin "baserom_jp.gba", 0x5ed2a4, 0x10

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

	.globl sPokedexAreaMap_Pal
sPokedexAreaMap_Pal: @ 0x85ED590
	.incbin "graphics/misc/sPokedexAreaMap_Pal.bin"

	.globl sPokedexAreaMap_Gfx
sPokedexAreaMap_Gfx: @ 0x85ED5F0
	.incbin "graphics/misc/sPokedexAreaMap_Gfx.bin"

	.globl sPokedexAreaMap_Tilemap
sPokedexAreaMap_Tilemap: @ 0x85EE344
	.incbin "graphics/misc/sPokedexAreaMap_Tilemap.bin"

	.globl sPokedexAreaMapAffine_Gfx
sPokedexAreaMapAffine_Gfx: @ 0x85EE658
	.incbin "graphics/misc/sPokedexAreaMapAffine_Gfx.bin"

	.globl sPokedexAreaMapAffine_Tilemap
sPokedexAreaMapAffine_Tilemap: @ 0x85EF3B4
	.incbin "graphics/misc/sPokedexAreaMapAffine_Tilemap.bin"

	.globl gUnknown_85EF704
gUnknown_85EF704: @ 0x85EF704
	.incbin "baserom_jp.gba", 0x5ef704, 0xc

	.globl gUnknown_85EF710
gUnknown_85EF710: @ 0x85EF710
	.incbin "baserom_jp.gba", 0x5ef710, 0x18

	.globl gUnknown_85EF728
gUnknown_85EF728: @ 0x85EF728
	.incbin "baserom_jp.gba", 0x5ef728, 0x30

	.globl gUnknown_85EF758
gUnknown_85EF758: @ 0x85EF758
	.incbin "baserom_jp.gba", 0x5ef758, 0x4

	.globl gUnknown_85EF75C
gUnknown_85EF75C: @ 0x85EF75C
	.incbin "baserom_jp.gba", 0x5ef75c, 0x2

	.globl gUnknown_85EF75E
gUnknown_85EF75E: @ 0x85EF75E
	.incbin "baserom_jp.gba", 0x5ef75e, 0x2

	.globl gUnknown_85EF760
gUnknown_85EF760: @ 0x85EF760
	.incbin "baserom_jp.gba", 0x5ef760, 0x4

	.globl gUnknown_85EF764
gUnknown_85EF764: @ 0x85EF764
	.incbin "baserom_jp.gba", 0x5ef764, 0x8

	.globl gUnknown_85EF76C
gUnknown_85EF76C: @ 0x85EF76C
	.incbin "baserom_jp.gba", 0x5ef76c, 0xc

	.globl gUnknown_85EF778
gUnknown_85EF778: @ 0x85EF778
	.incbin "baserom_jp.gba", 0x5ef778, 0x28

	.globl gUnknown_85EF7A0
gUnknown_85EF7A0: @ 0x85EF7A0
	.incbin "baserom_jp.gba", 0x5ef7a0, 0x20

	.globl gUnknown_85EF7C0
gUnknown_85EF7C0: @ 0x85EF7C0
	.incbin "baserom_jp.gba", 0x5ef7c0, 0x5c

	.globl gUnknown_85EF81C
gUnknown_85EF81C: @ 0x85EF81C
	.incbin "baserom_jp.gba", 0x5ef81c, 0x8

	.globl gUnknown_85EF824
gUnknown_85EF824: @ 0x85EF824
	.incbin "baserom_jp.gba", 0x5ef824, 0x18

