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


	.globl gUnknown_82F5196
gUnknown_82F5196: @ 0x82F5196
	.incbin "baserom_jp.gba", 0x2f5196, 0x16
	.globl gUnknown_82F51AC
gUnknown_82F51AC: @ 0x82F51AC
	.string "ょうをいびいさう$$"
	.globl gUnknown_82F51B6
gUnknown_82F51B6: @ 0x82F51B6
	.string "ユいハかぼせさひwれÄずベカ$$"
	.globl gUnknown_82F51C6
gUnknown_82F51C6: @ 0x82F51C6
	.incbin "baserom_jp.gba", 0x2f51c6, 0x16
	.globl gUnknown_82F51DC
gUnknown_82F51DC: @ 0x82F51DC
	.string "あいハいぼいさう$$"
	.globl gUnknown_82F51E6
gUnknown_82F51E6: @ 0x82F51E6
	.string "こいハいジこふつボふ9よTぇCずtぴサコ$$"
	.globl gUnknown_82F51FC
gUnknown_82F51FC: @ 0x82F51FC
	.string "こいハいジいふいジこふつボふ9よネりXりヌりせぇ2ずチぴnコ$$"
	.globl gUnknown_82F521C
gUnknown_82F521C: @ 0x82F521C
	.incbin "baserom_jp.gba", 0x2f521c, 0x16
