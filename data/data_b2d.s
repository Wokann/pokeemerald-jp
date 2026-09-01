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

	.section .rodata.data_b2d_after_battle_moves

	.align 2
	.globl gUnknown_82EEC78
gUnknown_82EEC78: @ 0x82EEC78
	.incbin "baserom_jp.gba", 0x2eec78, 0x2

	.globl gUnknown_82EEC7A
gUnknown_82EEC7A: @ 0x82EEC7A
	.incbin "baserom_jp.gba", 0x2eec7a, 0x8e

	.section .rodata.data_b2d_after_item_effects

	.globl gUnknown_82EF1A0
gUnknown_82EF1A0: @ 0x82EF1A0
	.incbin "baserom_jp.gba", 0x2ef1a0, 0x80

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

	.section .rodata.mid79

	.globl gUnknown_85CA3D8
gUnknown_85CA3D8: @ 0x85CA3D8
	.incbin "baserom_jp.gba", 0x5ca3d8, 0x1

	.globl gUnknown_85CA3D9
gUnknown_85CA3D9: @ 0x85CA3D9
	.string "$イベント$"

	.globl gUnknown_85CA3DF

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

	.section .rodata.mid82

	.globl gUnknown_85CA8B5
gUnknown_85CA8B5: @ 0x85CA8B5
	.string "メールボックス$どうぐを　あずける$"
	.globl gUnknown_85CA8C7
gUnknown_85CA8C7: @ 0x85CA8C7
	.string "どうぐを　ひきだす$"
	.globl gUnknown_85CA8D1
gUnknown_85CA8D1: @ 0x85CA8D1
	.string "どうぐを　すてる$パソコン　に\n"
	.string "どうぐを　あずけます$パソコン　から\n"
	.string "どうぐを　ひきだします$パソコン　に　あずけている\n"
	.string "どうぐを　すてます$"
	.globl gUnknown_85CA918

	.section .rodata.mid34

	.globl gUnknown_8566CC7
gUnknown_8566CC7: @ 0x8566CC7
	.incbin "baserom_jp.gba", 0x566cc7, 0x2

	.globl gUnknown_8566CC9
gUnknown_8566CC9: @ 0x8566CC9
	.incbin "baserom_jp.gba", 0x566cc9, 0x6

	.globl gUnknown_8566CCF
gUnknown_8566CCF: @ 0x8566CCF
	.incbin "baserom_jp.gba", 0x566ccf, 0x24

	.globl gUnknown_8566CF3
gUnknown_8566CF3: @ 0x8566CF3
	.incbin "baserom_jp.gba", 0x566cf3, 0x6

	.globl gUnknown_8566CF9
gUnknown_8566CF9: @ 0x8566CF9
	.incbin "baserom_jp.gba", 0x566cf9, 0xf

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

	.section .rodata.mid66

	.globl gUnknown_85ABBC9
gUnknown_85ABBC9: @ 0x85ABBC9
	.string "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}はい\n"
	.string "いいえ$"
	.globl gUnknown_85ABBD8
gUnknown_85ABBD8: @ 0x85ABBD8
	.string "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}いれかえる　わざを\n"
	.string "えらんで　ください${PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}${ESCAPE 3}${ESCAPE 4}$ー$HP　　$こうげき$ぼうぎょ$とくこう$とくぼう$きBコくにBコくしBコくひBコくちBコくヘ⋯コく"

	.globl gText_SafariBalls

	.section .rodata.mid67

	.globl gUnknown_85ABD18
gUnknown_85ABD18: @ 0x85ABD18
	.string "バトルトーナメント$1かい$2かい$じゅんけっしょう$けっしょう$　　　"

	.globl gUnknown_85ABD3C
gUnknown_85ABD3C: @ 0x85ABD3C
	.string "めCコくよCコくれCコくぉCコくきたいの　おおがた　しんじん！\p"
	.string "$ひがんの　はつ　ゆうしょう　なるか！？\p"
	.string "$もと　チャンピオン！\p"
	.string "$ぜんかい　チャンピオン！\p"
	.string "$むてきの　チャンピオン！\p$"
	.globl gUnknown_85ABD9A

	.section .rodata.mid75

.globl gUnknown_85C96F8
gUnknown_85C96F8: @ 0x85C96F8
	.incbin "baserom_jp.gba", 0x5c96f8, 0x30

	.globl gUnknown_85C9728
gUnknown_85C9728: @ 0x85C9728
	.incbin "baserom_jp.gba", 0x5c9728, 0x10

	.globl gUnknown_85C9738
gUnknown_85C9738: @ 0x85C9738
	.string "{B_COPY_VAR_1}へ\n"
	.string "もどります$"
	.globl gUnknown_85C9742
gUnknown_85C9742: @ 0x85C9742
	.string "　ど　う　ぐ　　$モンスターボール$　わざマシン　　$　き　の　み　　$たいせつなもの　$"
	.globl gUnknown_85C976F

	.section .rodata.mid57_gap

	.globl gHorizontalLungeSpriteTemplate
gHorizontalLungeSpriteTemplate: @ 0x855A958
	.incbin "baserom_jp.gba", 0x55a958, 0x18

	.globl gVerticalDipSpriteTemplate
gVerticalDipSpriteTemplate: @ 0x855A970
	.incbin "baserom_jp.gba", 0x55a970, 0x18

	.globl gSlideMonToOriginalPosSpriteTemplate
gSlideMonToOriginalPosSpriteTemplate: @ 0x855A988
	.incbin "baserom_jp.gba", 0x55a988, 0x18

	.globl gSlideMonToOffsetSpriteTemplate
gSlideMonToOffsetSpriteTemplate: @ 0x855A9A0
	.incbin "baserom_jp.gba", 0x55a9a0, 0x18

	.globl gSlideMonToOffsetAndBackSpriteTemplate
gSlideMonToOffsetAndBackSpriteTemplate: @ 0x855A9B8
	.incbin "baserom_jp.gba", 0x55a9b8, 0x18


	.section .rodata.mid97

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
	.globl gUnknown_85CD068
gUnknown_85CD068: @ 0x85CD068
	.incbin "baserom_jp.gba", 0x5cd068, 0x10

	.globl gUnknown_85CD078
gUnknown_85CD078: @ 0x85CD078
	.incbin "baserom_jp.gba", 0x5cd078, 0x20

	.globl gUnknown_85CD098
gUnknown_85CD098: @ 0x85CD098
	.incbin "baserom_jp.gba", 0x5cd098, 0x8

	.globl gUnknown_85CD0A0
gUnknown_85CD0A0: @ 0x85CD0A0
	.incbin "baserom_jp.gba", 0x5cd0a0, 0x28

	.globl gUnknown_85CD0C8
gUnknown_85CD0C8: @ 0x85CD0C8
	.incbin "baserom_jp.gba", 0x5cd0c8, 0x14

	.globl gUnknown_85CD0DC

	.section .rodata.mid81

.globl gUnknown_85CA6A4
gUnknown_85CA6A4: @ 0x85CA6A4
	.string "{B_COPY_VAR_3}{B_COPY_VAR_1}/{B_COPY_VAR_2}$グッズを　おく$グッズを　もどす$グッズを　すてる$"
	.globl gUnknown_85CA6C6
gUnknown_85CA6C6: @ 0x85CA6C6
	.string "{COLOR 161}{SHADOW 161}$えらんだ　グッズを　へやに　おきます！$えらんだ　グッズを　パソコンに　もどします！$いらなくなった　グッズを　すてます！$"
	.globl gUnknown_85CA70B
gUnknown_85CA70B: @ 0x85CA70B
	.string "グッズは　ありません！{PAUSE_UNTIL_PRESS}$つくえ$いす$はちうえ$おきもの$マット$ポスター$ぬいぐるみ$クッション$"
	.globl gUnknown_85CA73F

	.section .rodata.mid73

.globl gUnknown_85C9299
gUnknown_85C9299: @ 0x85C9299
	.string "▶$　$"
	.globl gUnknown_85C929D
gUnknown_85C929D: @ 0x85C929D
	.string "でんどういり　おめでとう！$みつけた　ポケモン　{B_COPY_VAR_1}！\n"
	.string "つかまえた　ポケモン　{B_COPY_VAR_2}！\p"
	.string "オダマキはかせの\n"
	.string "ポケモンずかん　ひょうか！\p"
	.string "オダマキ“どれどれ\p"
	.string "$ここまでの　レポートを　かきしるしています！\n"
	.string "でんげんを　きらないでください$"
	.globl gUnknown_85C9311
gUnknown_85C9311: @ 0x85C9311
	.incbin "baserom_jp.gba", 0x5c9311, 0x17

	.globl gUnknown_85C9328
gUnknown_85C9328: @ 0x85C9328
	.string "だい{B_COPY_VAR_1}かい　でんどういり！$"
	.globl gUnknown_85C9337
gUnknown_85C9337: @ 0x85C9337
	.string "リーグ　チャンピオン！　おめでとう！$$"
	.globl gUnknown_85C934B
gUnknown_85C934B: @ 0x85C934B
	.string "No,$"

	.globl gUnknown_85C934F
gUnknown_85C934F: @ 0x85C934F
	.string "Lv$IDNo,/$"

	.globl gUnknown_85C9359

	.section .rodata.mid78

	.globl gUnknown_85CA276
gUnknown_85CA276: @ 0x85CA276
	.incbin "baserom_jp.gba", 0x5ca276, 0x1e

	.globl gUnknown_85CA294
gUnknown_85CA294: @ 0x85CA294
	.string "そのポケモンを　こうかんすると\n"
	.string "せんとうできなくなっちゃうよ！$"
	.globl gUnknown_85CA2B4
gUnknown_85CA2B4: @ 0x85CA2B4
	.string "その　ポケモンは　いま\n"
	.string "こうかんに　だせません$"
	.globl gUnknown_85CA2CC
gUnknown_85CA2CC: @ 0x85CA2CC
	.string "タマゴは　いま\n"
	.string "こうかんに　だせません$あいての　ポケモンとは\n"
	.string "いまは　こうかん　できません$　いまは　そのポケモンを　\n"
	.string "あいては　うけとることが　できません$その　あいてとは　いまは　\n"
	.string "こうかん　できません$　　　あいての　ほしがっている　タイプの\n"
	.string "ポケモンでは　ありません$　それは　タマゴでは　ありません$"

	.globl gText_Register
gText_Register: @ 0x85CA368
	.string "とうろくする$"

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

	.section .rodata.mid80

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

	.section .rodata.mid83

	.globl gText_Yes
gText_Yes: @ 0x85CAAD8
	.string "はい$"
	.globl gText_No
gText_No: @ 0x85CAADB
	.string "いいえ$せつめい$シングルバトル$ダブルバトル$マルチバトル$ハギ$ちょうせんする$せつめいをきく$"
	.globl gUnknown_85CAB0D
gUnknown_85CAB0D: @ 0x85CAB0D
	.string "レベル50$"

	.globl gUnknown_85CAB13
gUnknown_85CAB13: @ 0x85CAB13
	.string "オープンレベル$おいしいみず　200¥$サイコソーダ　300¥$ミックスオレ　350¥$はしりかた$まがるコツ$すなのさか$ウイリー$ダニエル$ジャンプ$まんぞく$ふまん$しんかいのキバ$しんかいのウロコ$あおいビードロ$きいろビードロ$あかいビードロ$しろいビードロ$くろいビードロ$ガラスのいす$ガラスのつくえ$キモリドール　　　1000まい$アチャモドール　　1000まい$ミズゴロウドール　1000まい$　50まい　　1000¥$500まい　10000¥$ばつぐん$あんまり$あかいかけら$きいろいかけら$あおいかけら$みどりのかけら$"
	.globl gText_BattleFrontier
gText_BattleFrontier: @ 0x85CAC23
	.string "バトルフロンティア$みぎ$ひだり$わざマシン32　　1500まい$わざマシン29　　3500まい$わざマシン35　　4000まい$わざマシン24　　4000まい$わざマシン13　　4000まい$"
	.globl gUnknown_85CAC84

	.section .rodata.mid85

	.globl gUnknown_85CADC6
gUnknown_85CADC6: @ 0x85CADC6
	.string "レポート$"

	.globl gUnknown_85CADCB
gUnknown_85CADCB: @ 0x85CADCB
	.string "せってい$"
	.globl gUnknown_85CADD0
gUnknown_85CADD0: @ 0x85CADD0
	.string "とじる$　5BP$10BP$15BP$あかいテント$あおいテント$"
	.globl gText_SouthernIsland
gText_SouthernIsland: @ 0x85CADF1
	.string "みなみのことう$"
	.globl gText_BirthIsland
gText_BirthIsland: @ 0x85CADF9
	.string "たんじょうのしま$"
	.globl gText_FarawayIsland
gText_FarawayIsland: @ 0x85CAE02
	.string "さいはてのことう$"
	.globl gText_NavelRock
gText_NavelRock: @ 0x85CAE0B
	.string "へそのいわ$ツメのかせき$ねっこのかせき$いいえ　$これからしょうぶだ！$しょうぶにかった！$しょうぶにまけた！$おしえない$トレードセンター$コロシアム$レコードコーナー$きのみクラッシュ$ぐるぐるこうかん$ミニポケモンでジャンプ$ドードリオのきのみどり$リーダーになる$グループにはいる$2つのコース$レベル50$オープンレベル$ポケモンのしゅるいとかず$もたせるどうぐ$シンボル$たいせんのきろく$バトルポイント$タワーについて$つれていくポケモン$バトルサロン$つうしんマルチ$バトルでの　ちゅうい$はんてい‘こころ'$はんてい‘わざ'$はんてい‘からだ'$くみあわせ$トーナメントひょう$ダブルノックアウト$きほんルール$トレード　あいて$トレード　かいすう$トレード　ちゅうい$オープンレベル$たたかいのきほん$ポケモンのせいかく$ポケモンのわざ$ちからをはっきできない$ピンチになったら$ピラミッドの　ポケモン$ピラミッドの　トレーナー$ピラミッドの　めいろ$バトルバッグ$ポケナビと　バッグ$もたせた　どうぐ$ポケモンの　じゅんばん$でてくるポケモン$たたかう　トレーナー$つづける$きろくする$やすむ$リタイア$"
	.globl gUnknown_85CB00E

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
	.globl gUnknown_85C983E

	.section .rodata.mid68

	.globl gUnknown_85ABE2F
gUnknown_85ABE2F: @ 0x85ABE2F
	.incbin "baserom_jp.gba", 0x5abe2f, 0x85

	.globl gBattlePalaceFlavorTextTable
gBattlePalaceFlavorTextTable: @ 0x85ABEB4
	.hword STRINGID_GLINTAPPEARSINEYE
	.hword STRINGID_PKMNGETTINGINTOPOSITION
	.hword STRINGID_PKMNBEGANGROWLINGDEEPLY
	.hword STRINGID_PKMNEAGERFORMORE

	.incbin "baserom_jp.gba", 0x5abebc, 0x190
