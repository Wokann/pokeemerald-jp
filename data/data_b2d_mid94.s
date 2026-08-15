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

	.globl gUnknown_85CC874
gUnknown_85CC874: @ 0x85CC874
	.string "タマゴが　かえって\n"
	.string "{B_COPY_VAR_1}が　うまれた！$"
	.globl gUnknown_85CC888
gUnknown_85CC888: @ 0x85CC888
	.incbin "baserom_jp.gba", 0x5cc888, 0x140

	.globl gUnknown_85CC9C8
gUnknown_85CC9C8: @ 0x85CC9C8
	.incbin "baserom_jp.gba", 0x5cc9c8, 0xc

	.globl gUnknown_85CC9D4
gUnknown_85CC9D4: @ 0x85CC9D4
	.incbin "baserom_jp.gba", 0x5cc9d4, 0x1c

	.globl gUnknown_85CC9F0
gUnknown_85CC9F0: @ 0x85CC9F0
	.string "じかん$"
	.globl gUnknown_85CC9F4
gUnknown_85CC9F4: @ 0x85CC9F4
	.incbin "baserom_jp.gba", 0x5cc9f4, 0x8

	.globl gUnknown_85CC9FC
gUnknown_85CC9FC: @ 0x85CC9FC
	.string "サラサラぐあい$"
	.globl gUnknown_85CCA04
gUnknown_85CCA04: @ 0x85CCA04
	.string "{B_COPY_VAR_1}$　"

	.globl gUnknown_85CCA08
gUnknown_85CCA08: @ 0x85CCA08
	.string "ふん$　"

	.globl gUnknown_85CCA0C
gUnknown_85CCA0C: @ 0x85CCA0C
	.string "{B_COPY_VAR_1},{B_COPY_VAR_2}$　　"

	.globl gUnknown_85CCA14
gUnknown_85CCA14: @ 0x85CCA14
	.string "びょう$"
	.globl gUnknown_85CCA18
gUnknown_85CCA18: @ 0x85CCA18
	.string "{B_COPY_VAR_1},{B_COPY_VAR_2}$　　"

	.globl gUnknown_85CCA20
gUnknown_85CCA20: @ 0x85CCA20
	.incbin "baserom_jp.gba", 0x5cca20, 0x8

	.globl gUnknown_85CCA28
gUnknown_85CCA28: @ 0x85CCA28
	.string "{B_COPY_VAR_1}パーセント$"

	.globl gText_PressesRankings
gText_PressesRankings: @ 0x85CCA30
	.string "おした　かいすう　ランキング$　"

	.globl gText_CrushingResults
gText_CrushingResults: @ 0x85CCA40
	.string "つぶした　けっか$　　　ていねいさ　ランキング$たすけあい　ランキング$おすつよさ　ランキング$"
	.globl gUnknown_85CCA70
gUnknown_85CCA70: @ 0x85CCA70
	.incbin "baserom_jp.gba", 0x5cca70, 0xc

	.globl gUnknown_85CCA7C
gUnknown_85CCA7C: @ 0x85CCA7C
	.incbin "baserom_jp.gba", 0x5cca7c, 0x10

	.globl gUnknown_85CCA8C
