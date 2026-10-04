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


gUnknown_82EC5FE: @ 0x82EC5FE
	.incbin "baserom_jp.gba", 0x2ec5fe, 0x2


	.section .rodata.data_b2d_after_battle_palace_likelihood

	.incbin "baserom_jp.gba", 0x2ece95, 0x7

	.section .rodata.data_b2d_after_tmhm_learnsets

	.section .rodata.data_b2d_after_trainer_class_lookups


	.section .rodata.data_b2d_after_cry_ids
	.incbin "baserom_jp.gba", 0x2f00b2, 0x2


	.section .rodata.data_b2d_after_experience_tables


	.section .rodata.mid48

	.globl gUnknown_8300A99
gUnknown_8300A99: @ 0x8300A99
	.incbin "baserom_jp.gba", 0x300A99, 0x2

	.section .rodata.mid53

	.globl gUnknown_830F760
gUnknown_830F760: @ 0x830F760
	.incbin "baserom_jp.gba", 0x30f760, 0x6

	.globl gUnknown_830F766

	.section .rodata.mid35

	.globl gUnknown_8566D64
gUnknown_8566D64: @ 0x8566D64
	.incbin "baserom_jp.gba", 0x566d64, 0x10

	.section .rodata.mid27

	.globl sFishingReelTimeouts
sFishingReelTimeouts: @ 0x846F9D6
	.2byte 36, 33, 30

	.globl sFishingMoreDotsChance
sFishingMoreDotsChance: @ 0x846F9DC
	.2byte 0, 0, 40, 10, 70, 30

	.section .rodata.mid52

	.globl gUnknown_830F6FD
gUnknown_830F6FD: @ 0x830F6FD
	.incbin "baserom_jp.gba", 0x30f6fd, 0x51

	.section .rodata.mid34_suffix

	.globl gUnknown_8566D08
gUnknown_8566D08: @ 0x8566D08
	.incbin "baserom_jp.gba", 0x566d08, 0x4

	.globl gUnknown_8566D0C
gUnknown_8566D0C: @ 0x8566D0C
	.incbin "baserom_jp.gba", 0x566d0c, 0x20

	.section .rodata.mid36

	.globl gUnknown_8566DF5
gUnknown_8566DF5: @ 0x8566DF5
	.incbin "baserom_jp.gba", 0x566df5, 0xb

	.globl gUnknown_8566E00
gUnknown_8566E00: @ 0x8566E00
	.incbin "baserom_jp.gba", 0x566e00, 0x40

	.globl gUnknown_8566E40
gUnknown_8566E40: @ 0x8566E40
	.incbin "baserom_jp.gba", 0x566e40, 0x18

	.globl gUnknown_8566E58
gUnknown_8566E58: @ 0x8566E58
	.incbin "baserom_jp.gba", 0x566e58, 0x5

	.section .rodata.mid97_prefix

	.globl gJPText_WriteErrorUnableToSaveData
gJPText_WriteErrorUnableToSaveData: @ 0x85CD043
	.string "かきこみ　エラー　です\n"
	.string "データが　ほぞん　できませんでした$"
	.globl gText_Red
gText_Red: @ 0x85CD061
	.string "あか$"
	.globl gText_Blue
gText_Blue: @ 0x85CD064
	.string "あお$　"

	.section .rodata.mid93

	.globl gUnknown_85CC663
gUnknown_85CC663: @ 0x85CC663
	.string "{DYNAMIC 0}さんが　さんかしました！$"
	.globl gUnknown_85CC672
gUnknown_85CC672: @ 0x85CC672
	.string "{DYNAMIC 0}さんが　ぬけました${DYNAMIC 0}の{DYNAMIC 1}ひきめ:${DYNAMIC 0}の{DYNAMIC 1}ひきめは　いません$さんかしゃが　いなくなったので\n"
	.string "しゅうりょうします！$リーダーの　{DYNAMIC 0}さんが\n"
	.string "ぬけたので　かいさんします！$とうろくが　かわりました\n"
	.string "ポケモンレポートに　かきこみますか？$まえに　かかれた　レポートに\n"
	.string "うえから　かいても　いいですか？$ポケモンレポートに　かきこんでいます\n"
	.string "でんげんを　きらないで　ください${DYNAMIC 0}　は\n"
	.string "レポートに　しっかり　かきのこした！$リーダーが　やめると　かいさん\n"
	.string "になりますが　よろしいですか？$"
	.globl gUnknown_85CC769

	.section .rodata.mid94

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

	.section .rodata.mid76_pokeblock_name_text_prefix

	.globl gUnknown_85C97B5
gUnknown_85C97B5: @ 0x85C97B5
	.string "{NO}{B_COPY_VAR_1}　{B_COPY_VAR_2}$"

	.globl gUnknown_85C97BD
gUnknown_85C97BD: @ 0x85C97BD
	.string "きのみのタグ$"
