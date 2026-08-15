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

	.globl gUnknown_85C9F2B
gUnknown_85C9F2B: @ 0x85C9F2B
	.string "{B_COPY_VAR_1}は\n"
	.string "けんこうになった！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85C9F3B
gUnknown_85C9F3B: @ 0x85C9F3B
	.string "{B_COPY_VAR_1}の\n"
	.string "わざポイントが　ふえた！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85C9F4E
gUnknown_85C9F4E: @ 0x85C9F4E
	.string "{B_COPY_VAR_1}の\n"
	.string "レベルが　{B_COPY_VAR_2}になった！$"
	.globl gUnknown_85C9F5F
gUnknown_85C9F5F: @ 0x85C9F5F
	.string "{B_COPY_VAR_1}の　{B_COPY_VAR_2}の\n"
	.string "きそ　ポイントが　あがった！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85C9F78
gUnknown_85C9F78: @ 0x85C9F78
	.string "{B_COPY_VAR_1}が　ちょっと　なついた！\n"
	.string "{B_COPY_VAR_2}の　きそポイントが　さがった！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85C9F9B
gUnknown_85C9F9B: @ 0x85C9F9B
	.string "{B_COPY_VAR_1}は　さいこうに　なついている！\n"
	.string "{B_COPY_VAR_2}の　きそポイントが　さがった！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85C9FC1
gUnknown_85C9FC1: @ 0x85C9FC1
	.string "{B_COPY_VAR_1}は　ちょっと　なついた！\n"
	.string "{B_COPY_VAR_2}の　きそポイントは　もうさがらない！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85C9FE7
gUnknown_85C9FE7: @ 0x85C9FE7
	.string "{B_COPY_VAR_1}の\n"
	.string "こんらんが　とけた{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85C9FF7
gUnknown_85C9FF7: @ 0x85C9FF7
	.string "{B_COPY_VAR_1}の\n"
	.string "メロメロが　とけた{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85CA007
gUnknown_85CA007: @ 0x85CA007
	.string "{B_COPY_VAR_1}を\n"
	.string "すてても　よろしいですか$"
	.globl gUnknown_85CA018
gUnknown_85CA018: @ 0x85CA018
	.string "{B_COPY_VAR_1}を\n"
	.string "すてました{PAUSE_UNTIL_PRESS}$どのポケモンに　おぼえさせますか？$ポケモンを　えらんで　ください$どこに　いどうしますか？$どのポケモンに　おしえますか？$どのポケモンに　つかいますか？$どのポケモンに　もたせますか？${B_COPY_VAR_1}を　どうする？$きれるものが　ありません！$ここでは　のれません$すでに　なみのり　しています$ここでは　つかえません$どれを　かいふくする？$どれを　ふやす？$もちものを　どうしますか？$これでは　たたかえません！$どのポケモンを　あずけますか？$たいりょくが　たりません⋯⋯${B_COPY_VAR_1}ひき　そろっていません$おなじ　ポケモンが　います！$おなじ　どうぐを　もってます$ながれが　はやくて　ダメだ！$メールを　どうしますか？$ポケモンか　もどるを　せんたく$ポケモンを　えらんで　けってい$サイクリングを　たのしもう！$すでに　つかっています！${B_COPY_VAR_1}は\n"
	.string "{B_COPY_VAR_2}を　もっています$つかえません$さんかしない$いちばんめ$にばんめ$さんばんめ$でられます$でられません$おぼえられる！$おぼえられない$もうおぼえてる$もっている$もっていない$よんばんめ$"
	.globl gUnknown_85CA1FB
gUnknown_85CA1FB: @ 0x85CA1FB
	.string "その　ポケモンは　さんか　できません{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85CA210
gUnknown_85CA210: @ 0x85CA210
	.string "さんかを　やめますか？$"
	.globl gUnknown_85CA21C
gUnknown_85CA21C: @ 0x85CA21C
	.string "たいせんを　やめますか？$"
	.globl gUnknown_85CA229
gUnknown_85CA229: @ 0x85CA229
	.string "ひかえしつに　もどりますか？$"
	.globl gUnknown_85CA238
gUnknown_85CA238: @ 0x85CA238
	.string "ちょうせんを　やめますか？$"
	.globl gUnknown_85CA246
gUnknown_85CA246: @ 0x85CA246
	.string "ここを　だっしゅつ　して\n"
	.string "{B_COPY_VAR_1}に　もどる？$"
	.globl gUnknown_85CA25C
gUnknown_85CA25C: @ 0x85CA25C
	.string "さいごに　やすんだ\n"
	.string "{B_COPY_VAR_1}に　テレポートする？$"
	.globl gUnknown_85CA273
gUnknown_85CA273: @ 0x85CA273
	.string "{PAUSE_UNTIL_PRESS}$"

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
	.string "ポケモンでは　ありません$　それは　タマゴでは　ありません$とうろくする$"
	.globl gUnknown_85CA36F
gUnknown_85CA36F: @ 0x85CA36F
	.string "こうげき$"
	.globl gUnknown_85CA374
gUnknown_85CA374: @ 0x85CA374
	.string "ぼうぎょ$"
	.globl gUnknown_85CA379
gUnknown_85CA379: @ 0x85CA379
	.string "とくこう$"
	.globl gUnknown_85CA37E
gUnknown_85CA37E: @ 0x85CA37E
	.string "とくぼう$"
	.globl gUnknown_85CA383
gUnknown_85CA383: @ 0x85CA383
	.string "すばやさ$"
	.globl gUnknown_85CA388
gUnknown_85CA388: @ 0x85CA388
	.string "HP$"

	.globl gUnknown_85CA38B
gUnknown_85CA38B: @ 0x85CA38B
	.string "あと$"
	.globl gUnknown_85CA38E
gUnknown_85CA38E: @ 0x85CA38E
	.string "おや/$"
	.globl gUnknown_85CA392
gUnknown_85CA392: @ 0x85CA392
	.string "レンタルポケモン$"

	.globl gUnknown_85CA39B
gUnknown_85CA39B: @ 0x85CA39B
	.string "タイプ/$"

	.globl gUnknown_85CA3A0
gUnknown_85CA3A0: @ 0x85CA3A0
	.string "いりょく$"
	.globl gUnknown_85CA3A5
gUnknown_85CA3A5: @ 0x85CA3A5
	.string "めいちゅう$"
	.globl gUnknown_85CA3AB
gUnknown_85CA3AB: @ 0x85CA3AB
	.string "アピール$"

	.globl gUnknown_85CA3B0
gUnknown_85CA3B0: @ 0x85CA3B0
	.string "ぼうがい$"
	.globl gUnknown_85CA3B5
gUnknown_85CA3B5: @ 0x85CA3B5
	.string "じょうたい$"
	.globl gUnknown_85CA3BB
gUnknown_85CA3BB: @ 0x85CA3BB
	.string "げんざいのけいけんち$"
	.globl gUnknown_85CA3C6
gUnknown_85CA3C6: @ 0x85CA3C6
	.string "レベルアップまで$"

	.globl gUnknown_85CA3CF
gUnknown_85CA3CF: @ 0x85CA3CF
	.string "げんざい　{B_COPY_VAR_1}こ$"
	.globl gUnknown_85CA3D8
gUnknown_85CA3D8: @ 0x85CA3D8
	.incbin "baserom_jp.gba", 0x5ca3d8, 0x1

	.globl gUnknown_85CA3D9
gUnknown_85CA3D9: @ 0x85CA3D9
	.string "$イベント$"

	.globl gUnknown_85CA3DF
gUnknown_85CA3DF: @ 0x85CA3DF
	.string "いれかえ$"
	.globl gUnknown_85CA3E4
gUnknown_85CA3E4: @ 0x85CA3E4
	.string "ポケモンじょうほう$"
	.globl gUnknown_85CA3EE
gUnknown_85CA3EE: @ 0x85CA3EE
	.string "ポケモンのうりょく$"
	.globl gUnknown_85CA3F8
gUnknown_85CA3F8: @ 0x85CA3F8
	.string "たたかうわざ$"
	.globl gUnknown_85CA3FF
gUnknown_85CA3FF: @ 0x85CA3FF
	.string "コンテストわざ$"

	.globl gUnknown_85CA407
gUnknown_85CA407: @ 0x85CA407
	.string "きりかえ$"
	.globl gUnknown_85CA40C
gUnknown_85CA40C: @ 0x85CA40C
	.string "この　タマゴは\n"
	.string "うまれるまで　かなり　かかりそう$"
	.globl gUnknown_85CA425
gUnknown_85CA425: @ 0x85CA425
	.string "なにが　うまれて　くるのかな？\n"
	.string "うまれる　まで　まだまだ　かかりそう$"
	.globl gUnknown_85CA448
gUnknown_85CA448: @ 0x85CA448
	.string "ときどき　うごいて　いるようだ\n"
	.string "うまれる　まで　もうちょっと　かな？$"
	.globl gUnknown_85CA46B
gUnknown_85CA46B: @ 0x85CA46B
	.string "なかから　おとが　きこえてくる\n"
	.string "もうすぐ　うまれそう！$"
	.globl gUnknown_85CA487
gUnknown_85CA487: @ 0x85CA487
	.string "それは　たいせつなわざです\n"
	.string "わすれさせることは　できません！$"
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
gUnknown_85CA5B6: @ 0x85CA5B6
	.string "そだてや　ふうふ　から　もらった\n"
	.string "ふしぎな　ポケモンのタマゴ$"
	.globl gUnknown_85CA5D5
gUnknown_85CA5D5: @ 0x85CA5D5
	.string "ステキな　ばしょで　てにいれた\n"
	.string "ふしぎな　ふしぎな　ポケモンのタマゴ$"
	.globl gUnknown_85CA5F8
gUnknown_85CA5F8: @ 0x85CA5F8
	.string "つうしんこうかんで　てにいれた\n"
	.string "ふしぎな　ポケモンのタマゴ$"
	.globl gUnknown_85CA616
gUnknown_85CA616: @ 0x85CA616
	.string "おんせんばあさん　から　もらった\n"
	.string "ふしぎな　ポケモンのタマゴ$"
	.globl gUnknown_85CA635
gUnknown_85CA635: @ 0x85CA635
	.string "たびの　おじさん　から　もらった\n"
	.string "ふしぎな　ポケモンのタマゴ$"
	.globl gUnknown_85CA654
gUnknown_85CA654: @ 0x85CA654
	.string "　きち$"
	.globl gUnknown_85CA658
gUnknown_85CA658: @ 0x85CA658
	.string "{B_COPY_VAR_1}　の　とうろくを\n"
	.string "かいじょ　しても　よろしい　ですか？$"
	.globl gUnknown_85CA676
gUnknown_85CA676: @ 0x85CA676
	.string "とうろくを　かいじょ　しました{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85CA688
gUnknown_85CA688: @ 0x85CA688
	.string "とうろく　リストは　ありません{PAUSE_UNTIL_PRESS}$とうろく　かいじょ$"
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
gUnknown_85CA73F: @ 0x85CA73F
	.string "きん$"
	.globl gUnknown_85CA742
gUnknown_85CA742: @ 0x85CA742
	.string "ぎん$"

	.globl gUnknown_85CA745
gUnknown_85CA745: @ 0x85CA745
	.string "ここに　おきますか？$"
	.globl gUnknown_85CA750
gUnknown_85CA750: @ 0x85CA750
	.string "ここには　おけません！$"
	.globl gUnknown_85CA75C
gUnknown_85CA75C: @ 0x85CA75C
	.string "おくのを　やめますか？$"
	.globl gUnknown_85CA768
gUnknown_85CA768: @ 0x85CA768
	.string "すでに　おかれて　います！$"
	.globl gUnknown_85CA776
gUnknown_85CA776: @ 0x85CA776
	.string "これいじょう　おけません\n"
	.string "ひみつきちに　おけるのは　{B_COPY_VAR_1}こ　までです$"
	.globl gUnknown_85CA799
gUnknown_85CA799: @ 0x85CA799
	.string "これいじょう　おけません\n"
	.string "へやに　おけるのは　{B_COPY_VAR_1}こ　までです$ここには　おけません！\n"
	.string "つくえの　うえなどに　おいてください！$"
	.globl gUnknown_85CA7D9
gUnknown_85CA7D9: @ 0x85CA7D9
	.string "この　グッズは\n"
	.string "じぶんの　へやには　おけません！$"
	.globl gUnknown_85CA7F2
gUnknown_85CA7F2: @ 0x85CA7F2
	.string "このグッズは　おかれて　いるので\n"
	.string "すてる　ことが　できません！$"
	.globl gUnknown_85CA812
gUnknown_85CA812: @ 0x85CA812
	.string "{B_COPY_VAR_1}　は　なくなりますが\n"
	.string "よろしい　ですか？$"
	.globl gUnknown_85CA829
gUnknown_85CA829: @ 0x85CA829
	.string "グッズを　すてました！$"
	.globl gUnknown_85CA835
gUnknown_85CA835: @ 0x85CA835
	.string "もどすのを　やめますか？$"
	.globl gUnknown_85CA842
gUnknown_85CA842: @ 0x85CA842
	.string "ここに　グッズは　ありません！$"
	.globl gUnknown_85CA852
gUnknown_85CA852: @ 0x85CA852
	.string "このグッズを　パソコンに　もどしますか？$"
	.globl gUnknown_85CA867
gUnknown_85CA867: @ 0x85CA867
	.string "グッズを　パソコンに　もどしました！$"
	.globl gUnknown_85CA87A
gUnknown_85CA87A: @ 0x85CA87A
	.string "グッズは　おかれて　いません！{PAUSE_UNTIL_PRESS}$ヒロミ$ユウリ$ヨシオ$サダハル$せつぞくを　きる$もようがえ$どうぐ　あずかり$"
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
gUnknown_85CA918: @ 0x85CA918
	.string "なにも　ありません！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85CA925
gUnknown_85CA925: @ 0x85CA925
	.string "これいじょう\n"
	.string "バッグに　はいりません$"
	.globl gUnknown_85CA938
gUnknown_85CA938: @ 0x85CA938
	.string "{B_COPY_VAR_1}を\n"
	.string "いくつ　ひきだしますか？$"
	.globl gUnknown_85CA949
gUnknown_85CA949: @ 0x85CA949
	.string "{B_COPY_VAR_1}を\n"
	.string "{B_COPY_VAR_2}コ　ひきだしました$ないようを　よむ$バッグに　もどす$ポケモンに　もたせる$"
	.globl gUnknown_85CA976
gUnknown_85CA976: @ 0x85CA976
	.string "メールは　1つうも　ありません{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85CA988
gUnknown_85CA988: @ 0x85CA988
	.string "{B_COPY_VAR_1}　の\n"
	.string "メールを　どうしますか？$"
	.globl gUnknown_85CA99A
gUnknown_85CA99A: @ 0x85CA99A
	.string "ないようは　きえてしまいますが\n"
	.string "よろしいですか？$"
	.globl gUnknown_85CA9B3
gUnknown_85CA9B3: @ 0x85CA9B3
	.string "バッグが　いっぱいです！{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85CA9C2
gUnknown_85CA9C2: @ 0x85CA9C2
	.string "ないようを　けした　メールを\n"
	.string "バッグに　いれました{PAUSE_UNTIL_PRESS}$"
	.globl gUnknown_85CA9DE
gUnknown_85CA9DE: @ 0x85CA9DE
	.string "パパ$"

	.globl gUnknown_85CA9E1
gUnknown_85CA9E1: @ 0x85CA9E1
	.string "ママ$"

	.globl gUnknown_85CA9E4
gUnknown_85CA9E4: @ 0x85CA9E4
	.string "ミクリ$"

	.globl gUnknown_85CA9E8
gUnknown_85CA9E8: @ 0x85CA9E8
	.string "ダイゴ$"

	.globl gUnknown_85CA9EC
gUnknown_85CA9EC: @ 0x85CA9EC
	.string "トウキ$"

	.globl gUnknown_85CA9F0
gUnknown_85CA9F0: @ 0x85CA9F0
	.string "ナギ$"

	.globl gUnknown_85CA9F3
gUnknown_85CA9F3: @ 0x85CA9F3
	.string "フヨウ$"

	.globl gUnknown_85CA9F7
gUnknown_85CA9F7: @ 0x85CA9F7
	.string "プリム$トウカ$カイナ$ミシロ$ミナモ$ムロ$さんか　する$せつめいをきく$ポケモンコンテストって？$コンテストの　しゅるい$ランクに　ついて$しんさいんに　ついて$かっこよさコンテスト$うつくしさコンテスト$かわいさコンテスト$かしこさコンテスト$たくましさコンテスト$もようがえ$ひっこし$カウント$とうろく　リスト$とうろく　せつめい$マッハ$ダート$どく$まひ$ねむり$やけど$こおり$どくどく$ふつう$よむのを　やめる$みました$これから$"
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
	.string "オープンレベル$おいしいみず　200¥$サイコソーダ　300¥$ミックスオレ　350¥$はしりかた$まがるコツ$すなのさか$ウイリー$ダニエル$ジャンプ$まんぞく$ふまん$しんかいのキバ$しんかいのウロコ$あおいビードロ$きいろビードロ$あかいビードロ$しろいビードロ$くろいビードロ$ガラスのいす$ガラスのつくえ$キモリドール　　　1000まい$アチャモドール　　1000まい$ミズゴロウドール　1000まい$　50まい　　1000¥$500まい　10000¥$ばつぐん$あんまり$あかいかけら$きいろいかけら$あおいかけら$みどりのかけら$バトルフロンティア$みぎ$ひだり$わざマシン32　　1500まい$わざマシン29　　3500まい$わざマシン35　　4000まい$わざマシン24　　4000まい$わざマシン13　　4000まい$"
	.globl gUnknown_85CAC84
gUnknown_85CAC84: @ 0x85CAC84
	.string "かっこよさ$"
	.globl gUnknown_85CAC8A
gUnknown_85CAC8A: @ 0x85CAC8A
	.string "うつくしさ$"
	.globl gUnknown_85CAC90
gUnknown_85CAC90: @ 0x85CAC90
	.string "かわいさ$"
	.globl gUnknown_85CAC95
gUnknown_85CAC95: @ 0x85CAC95
	.string "かしこさ$"
	.globl gUnknown_85CAC9A
gUnknown_85CAC9A: @ 0x85CAC9A
	.string "たくましさ$ノーマル$スーパー$ハイパー$マスター$かっこいい$うつくしい$かわいい$かしこそうな$たくましい$どうぐ$たいせつなもの$ボール$わざマシン$きのみ$"
	.globl gUnknown_85CACEC
gUnknown_85CACEC: @ 0x85CACEC
	.string "だれかのパソコン$"
	.globl gUnknown_85CACF5
gUnknown_85CACF5: @ 0x85CACF5
	.string "マユミのパソコン$"

	.globl gUnknown_85CACFE
gUnknown_85CACFE: @ 0x85CACFE
	.string "{MUS_RG_VS_TRAINER}のパソコン$"

	.globl gUnknown_85CAD06
gUnknown_85CAD06: @ 0x85CAD06
	.string "でんどういり$"
	.globl gUnknown_85CAD0D
gUnknown_85CAD0D: @ 0x85CAD0D
	.string "スイッチをきる$たいせん　あいて$トーナメントひょう$じゅんび　かんりょう$ノーマルランク$スーパーランク$ハイパーランク$マスターランク$シングル$ダブル$マルチ$つうしん　マルチ$バトルバッグ$もたせたどうぐ$つうしんコンテスト$エメラルドモードについて$グローバルモードについて$エメラルドモード$グローバルモード$"
	.globl gUnknown_85CADAE
gUnknown_85CADAE: @ 0x85CADAE
	.string "ずかん$"
	.globl gUnknown_85CADB2
gUnknown_85CADB2: @ 0x85CADB2
	.string "ポケモン$"

	.globl gUnknown_85CADB7
gUnknown_85CADB7: @ 0x85CADB7
	.string "バッグ$"

	.globl gUnknown_85CADBB
gUnknown_85CADBB: @ 0x85CADBB
	.string "ポケナビ$　　　　　$"
	.globl gUnknown_85CADC6
gUnknown_85CADC6: @ 0x85CADC6
	.string "レポート$"

	.globl gUnknown_85CADCB
gUnknown_85CADCB: @ 0x85CADCB
	.string "せってい$"
	.globl gUnknown_85CADD0
gUnknown_85CADD0: @ 0x85CADD0
	.string "とじる$　5BP$10BP$15BP$あかいテント$あおいテント$みなみのことう$たんじょうのしま$さいはてのことう$へそのいわ$ツメのかせき$ねっこのかせき$いいえ　$これからしょうぶだ！$しょうぶにかった！$しょうぶにまけた！$おしえない$トレードセンター$コロシアム$レコードコーナー$きのみクラッシュ$ぐるぐるこうかん$ミニポケモンでジャンプ$ドードリオのきのみどり$リーダーになる$グループにはいる$2つのコース$レベル50$オープンレベル$ポケモンのしゅるいとかず$もたせるどうぐ$シンボル$たいせんのきろく$バトルポイント$タワーについて$つれていくポケモン$バトルサロン$つうしんマルチ$バトルでの　ちゅうい$はんてい‘こころ'$はんてい‘わざ'$はんてい‘からだ'$くみあわせ$トーナメントひょう$ダブルノックアウト$きほんルール$トレード　あいて$トレード　かいすう$トレード　ちゅうい$オープンレベル$たたかいのきほん$ポケモンのせいかく$ポケモンのわざ$ちからをはっきできない$ピンチになったら$ピラミッドの　ポケモン$ピラミッドの　トレーナー$ピラミッドの　めいろ$バトルバッグ$ポケナビと　バッグ$もたせた　どうぐ$ポケモンの　じゅんばん$でてくるポケモン$たたかう　トレーナー$つづける$きろくする$やすむ$リタイア$"
	.globl gUnknown_85CB00E
gUnknown_85CB00E: @ 0x85CB00E
	.string "99かい　いじょう$"
	.globl gUnknown_85CB018
gUnknown_85CB018: @ 0x85CB018
	.string "1ぷん　いじょう$"
	.globl gUnknown_85CB021
gUnknown_85CB021: @ 0x85CB021
	.string "びょう$"
	.globl gUnknown_85CB025
gUnknown_85CB025: @ 0x85CB025
	.string "かい$,$"
	.globl gUnknown_85CB02A
gUnknown_85CB02A: @ 0x85CB02A
	.string "おにいちゃん$"
	.globl gUnknown_85CB031
gUnknown_85CB031: @ 0x85CB031
	.string "おねえちゃん$"
	.globl gUnknown_85CB038
gUnknown_85CB038: @ 0x85CB038
	.string "むすこ$"
	.globl gUnknown_85CB03C
gUnknown_85CB03C: @ 0x85CB03C
	.string "むすめ$あおいビードロ$きいろビードロ$あかいビードロ$しろいビードロ$くろいビードロ$きれいなイス$きれいなつくえ$1かい$2かい$3かい$4かい$5かい$6かい$7かい$8かい$9かい$10かい$11かい$ビ1かい$ビ2かい$ビ3かい$ビ4かい$おくじょう$"
	.globl gUnknown_85CB0BF
gUnknown_85CB0BF: @ 0x85CB0BF
	.string "げんざいのフロア$"
	.globl gUnknown_85CB0C8
gUnknown_85CB0C8: @ 0x85CB0C8
	.string "BP$ちからのこな　　{FONT 0}　　50$ちからのねっこ　{FONT 0}　　80$ばんのうごな　　{FONT 0}　　50$ふっかつそう　　{FONT 0}　300$タウリン　　　　{FONT 0}1000$ブロムヘキシン　{FONT 0}1000$インドメタシン　{FONT 0}1000$リゾチウム　　　{FONT 0}1000$キトサン　　　　{FONT 0}1000$マックスアップ　{FONT 0}1000$ポイントアップ　{FONT 0}3000$ランキングホール$ひきかえサービス$ミナモシティ$カイナシティ$めざめのほこら$おくりびやま$そらのはしら$おぼえていない$"
	.globl gUnknown_85CB1B9
gUnknown_85CB1B9: @ 0x85CB1B9
	.string "やめる$ボックスを　しゅうりょうしますか？　$このボックスを　どうしますか？$どの　テーマにしますか？$どの　かべがみにしますか？${DYNAMIC 0}を　どうしますか？$どの　ボックスに　ジャンプしますか？$どの　ボックスに　あずけますか？${DYNAMIC 0}を　あずけました$このボックスは　いっぱいだ！$ほんとうに　にがしますか？${DYNAMIC 0}を　そとに　にがしてあげた$ばいばい　{DYNAMIC 0}！$マーキングしてください$たたかうポケモンが　いなくなります！$てもちが　いっぱいです！$ポケモンを　つかんだままですよ！$つれていく　ポケモンを　えらんで！$タマゴを　にがすことは　できません！$ボックスそうさを　つづけますか？${DYNAMIC 0}は　かえってきた！$しんぱい　だったのかな⋯⋯$⋯⋯⋯⋯⋯！$メールを　はずして　ください！$どうぐを　もたせますか？${DYNAMIC 0}を　バッグへいれた！$バッグが　いっぱいです！$どうぐを　バッグに　いれますか？${DYNAMIC 0}を　もたせた！${DYNAMIC 0}と　とりかえた！$メールを　あずかることは　できません！$やめる　　　$あずける　　$つれていく　$いれかえる　$つかむ　　　$ここにおく　$ようすをみる$にがす　　　$マーキング　$なまえ　　　$ジャンプ$かべがみ　　$あずかる$もたせる$とりかえる$バッグへ$せつめい$ふうけい1$ふうけい2$ふうけい3$エトセトラ$だいすき$もり$シティ$さばく$サバンナ$いわやま$かざん$ゆきやま$どうくつ$うみべ$かいてい$かわ$そら$みずたま$ポケセン$きかい$シンプル$なにを　しますか？$ポケモンを　つれていく$ポケモンを　あずける　$ボックスを　せいりする$どうぐせいり$さようなら$ボックスに　あずけている　ポケモンを　\n"
	.string "てもちに　くわえる　ことが　できます　$てもちの　ポケモンを　　　　　　　　　\n"
	.string "ボックスに　あずける　ことが　できます$ボックスに　あずけている　ポケモンや　\n"
	.string "てもちの　ポケモンを　せいり　できます$ポケモンが　もっている　どうぐを\n"
	.string "せいり　できます$ひとつ　まえの　メニューに　もどります\n"
	.string "　　　　　　　　　　　　　　　　　　　$"
	.globl gUnknown_85CB534
gUnknown_85CB534: @ 0x85CB534
	.string "てもちポケモンが　1ひきしかいません！\n"
	.string "　　　　　　　　　　　　　　　　　　　$"
	.globl gUnknown_85CB55C
gUnknown_85CB55C: @ 0x85CB55C
	.string "てもちポケモンが　いっぱいです！　　　\n"
	.string "　　　　　　　　　　　　　　　　　　　$"
	.globl gUnknown_85CB584
gUnknown_85CB584: @ 0x85CB584
	.string "ボックス$ホウエンちほうの　マップを　みます$ポケモンを　くわしく　しらべます$とうろくした　ひとを　よびだします$てにいれた　きねんリボンを　みます$ポケナビを　しまいます$"
	.globl gText_NoRibbonWinners
gText_NoRibbonWinners: @ 0x85CB5DC
	.string "リボンを　もっている　ポケモンが　いません$トレーナーが　とうろく　されていません$てもちポケモンを　くわしく　しらべます$すべてのポケモンを　くわしく　しらべます$ポケナビの　メニューに　もどります$かっこいい　ポケモンを　みつけます$うつくしい　ポケモンを　みつけます$かわいい　ポケモンを　みつけます$かしこい　ポケモンを　みつけます$たくましい　ポケモンを　みつけます$コンディションの　メニューに　もどります$"
	.globl gText_NumberRegistered
gText_NumberRegistered: @ 0x85CB6AE
	.string "とうろく　にんずう$"
	.globl gText_NumberOfBattles
gText_NumberOfBattles: @ 0x85CB6B8
	.string "たいせん　かいすう$しょうさい$よびだす$やめる$ここでは　あいてを　よびだす　ことが\n"
	.string "できないようだ$さくせん$もってる　ポケモン$じこしょうかい$　　　　　　　　　　　　　　　　${A_BUTTON}かくだい　{B_BUTTON}もどる${A_BUTTON}ぜんたい　{B_BUTTON}もどる${A_BUTTON}コンディションをみる　{B_BUTTON}もどる${A_BUTTON}マーキング　{B_BUTTON}もどる${A_BUTTON}マークをえらぶ　{B_BUTTON}やめる${A_BUTTON}メニュー　{B_BUTTON}もどる${A_BUTTON}けってい　{B_BUTTON}もどる${B_BUTTON}もどる${A_BUTTON}リボンをみる　{B_BUTTON}もどる${A_BUTTON}しょうさい　{B_BUTTON}もどる${B_BUTTON}もどる$"
	.globl gUnknown_85CB7A2
gUnknown_85CB7A2: @ 0x85CB7A2
	.string "せいかく/$"
	.globl gText_TrainerCloseBy
gText_TrainerCloseBy: @ 0x85CB7A8
	.string "ちかくに　いるみたいだから\n"
	.string "ちょくせつ　あって　はなそう！$"
	.globl gText_InParty
gText_InParty: @ 0x85CB7C6
	.string "てもちポケモン$"

	.globl gText_Number2
gText_Number2: @ 0x85CB7CE
	.string "ばんめ$リボン$"

	.globl sText_ConditionSearchMonMale
sText_ConditionSearchMonMale: @ 0x85CB7D6
	.string "{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}$"
	.globl sText_ConditionSearchMonFemale
sText_ConditionSearchMonFemale: @ 0x85CB7EA
	.string "{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}$"
	.globl sText_ConditionSearchMonUnknown
sText_ConditionSearchMonUnknown: @ 0x85CB7FE
	.string "{DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}$"

	.globl gText_Unknown
gText_Unknown: @ 0x85CB808
	.string "ふめい$よびだし$しょうさい$もどる$"
	.globl gText_SearchResultRank
gText_SearchResultRank: @ 0x85CB81B
	.string "{DYNAMIC 0}ばんめ$"

	.globl gText_RibbonsF700
gText_RibbonsF700: @ 0x85CB821
	.string "リボン　{DYNAMIC 0}こ${DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ${DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ${DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ$4つの　ことばを　くみあわせて$プロフィールを　つくろう！$6つの　ことばで　メッセージを　つくろう！$7もじの　ことばは　1ぎょうに　2つまで！$いまの　きもちに　ぴったりあう$ことばを　みつけよう！$4つの　ことばで$9つの　ことばを　くみあわせて$メッセージを　つくろう！$ことばを　1つだけ　いれかえて$オヤジのうたを　よくして　あげよう！$プロフィールは$たいせんが　はじまるときの　きもちは$たいせんに　かったときの　あいさつは$たいせんに　まけたときの　あいさつは$こたえは$メールに　のせる　メッセージは$はがきに　のせる　あいさつは$あたらしい　うたは$2つの　ことばを　くみあわせて$はやらせたい　ことばを　つくろう！$はやらせたい　ことばは$これで　いいですか？$2つの　ことばを　くみあわせて$いい　ことばを　おしえてあげよう！$トレーナーの　イメージに$ぴったりの　ことばを　みつけよう！$イメージは$ことばの　なかから$クイズの　こたえを　えらぼう！$クイズを　つくろう！$ことばの　なかから　ひとつを　えらんで$クイズの　こたえを　つくろう！$こたえは$クイズは$でしの　きめゼリフは$"
	.globl gUnknown_85CBA63
gUnknown_85CBA63: @ 0x85CBA63
	.string "へんしゅうを　やめますか？$"
	.globl gUnknown_85CBA71
gUnknown_85CBA71: @ 0x85CBA71
	.string "メールを　もたせるのを　やめますか？$ショップの　アンケートに　こたえよう！$インタビューに　こたえよう！$"
	.globl gUnknown_85CBAA7
gUnknown_85CBAA7: @ 0x85CBAA7
	.string "へんしゅうちゅうの　ことばを$"
	.globl gUnknown_85CBAB6
gUnknown_85CBAB6: @ 0x85CBAB6
	.string "ぜんぶ　けしても　いいですか？$へんしゅうを　やめますか？$へんしゅうした　ことばは　ほぞん$されませんが　いいですか？$なにか　ことばを　いれてください！$ことばを　ぜんぶ　けすことは　できません！$"
	.globl gUnknown_85CBB1B
gUnknown_85CBB1B: @ 0x85CBB1B
	.string "かえられる　ことばは　1つ　までです！$"
	.globl gUnknown_85CBB2F
gUnknown_85CBB2F: @ 0x85CBB2F
	.string "うたを　もとに　もどします！$それは　もう　はやっています！$"
	.globl gUnknown_85CBB4E
gUnknown_85CBB4E: @ 0x85CBB4E
	.string "2つの　ことばを　くみあわせてください！$ことばを　おしえるのを　やめますか？$メールを　もたせるのを　やめますか？$もんだいを　つくってください！$こたえを　えらんでください！$もとにもどして　いいですか？$プロフィール$たいせんが　はじまるとき$たいせんに　かったとき$たいせんに　まけたとき$オヤジのうた$はやっている　ものは？$インタビュー$いい　ことば$ファンのしつもん$クイズの　こたえは？$でしの　きめゼリフ$アンケート$あいうえお　なにぬねの　やゆよ　わ$かきくけこ　はひふへほ　そのた$さしすせそ　まみむめも$たちつてと　らりるれろ$"
	.globl gUnknown_85CBC62
gUnknown_85CBC62: @ 0x85CBC62
	.string "ここでは　とちゅうで$"
	.globl gUnknown_85CBC6D
gUnknown_85CBC6D: @ 0x85CBC6D
	.string "やめることは　できません！$"
	.globl gUnknown_85CBC7B
gUnknown_85CBC7B: @ 0x85CBC7B
	.string "{DYNAMIC 0}さんの　クイズ$"

	.globl gUnknown_85CBC85
gUnknown_85CBC85: @ 0x85CBC85
	.string "おねえ$もんだいを　よんだら$Aボタンを　おしてね！$クイズの　こたえは？$"
	.globl gUnknown_85CBCAB
gUnknown_85CBCAB: @ 0x85CBCAB
	.string "クイズの　チャレンジを$"
	.globl gUnknown_85CBCB7
gUnknown_85CBCB7: @ 0x85CBCB7
	.string "あきらめますか？$クイズは　これで　いいですか？$"
	.globl gUnknown_85CBCD0
gUnknown_85CBCD0: @ 0x85CBCD0
	.string "もんだいを　つくってください！$"
	.globl gUnknown_85CBCE0
gUnknown_85CBCE0: @ 0x85CBCE0
	.string "こたえを　えらんでください！$"
	.globl gUnknown_85CBCEF
gUnknown_85CBCEF: @ 0x85CBCEF
	.string "かしを　けすことは　できません！$ポケモン　リーグ$ポケモンセンター$"
	.globl gUnknown_85CBD12
gUnknown_85CBD12: @ 0x85CBD12
	.string "に　ポロックを　あげますか？$かっこよさ$うつくしさ$かわいさ$かしこさ$たくましさ$"
	.globl gUnknown_85CBD3D
gUnknown_85CBD3D: @ 0x85CBD3D
	.string "に　みがきが　かかった！$"
	.globl gUnknown_85CBD4A
gUnknown_85CBD4A: @ 0x85CBD4A
	.string "なにも　かわらなかった！$"
	.globl gUnknown_85CBD57
gUnknown_85CBD57: @ 0x85CBD57
	.string "もう　これいじょう　たべない　みたい⋯$"
	.globl gText_SaveFailedCheckingBackup
gText_SaveFailedCheckingBackup: @ 0x85CBD6B
	.string "レポートの　かきこみに　しっぱいしました\n"
	.string "バックアップカートリッジの　けんさをします\n"
	.string "しばらくおまちください{COLOR 4}“1ふんほど　かかります”$"
	.globl gText_BackupMemoryDamaged
gText_BackupMemoryDamaged: @ 0x85CBDB2
	.string "バックアップきのうの　こしょう　または　じゅみょうが\n"
	.string "きました。セーブすることは　できませんが　このまま\n"
	.string "ゲームを　あそぶことはできます$"

	.globl gText_GamePlayCannotBeContinued
gText_GamePlayCannotBeContinued: @ 0x85CBDF7
	.string "{COLOR 4}“このまま　ぼうけんをつづけることは　できません\n"
	.string "タイトルに　もどります”$"
	.globl gText_CheckCompleted
gText_CheckCompleted: @ 0x85CBE20
	.string "けんさが　しゅうりょうしました！\n"
	.string "もういちど　レポートを　かきこみます\n"
	.string "しばらくおまちください$"

	.globl gText_SaveCompleteGameCannotContinue
gText_SaveCompleteGameCannotContinue: @ 0x85CBE50
	.string "レポートの　かきこみは　しゅうりょうしました\n"
	.string "{COLOR 4}“このまま　ぼうけんをつづけることは　できません\n"
	.string "タイトルに　もどります”$"
	.globl gText_SaveCompletePressA
gText_SaveCompletePressA: @ 0x85CBE90
	.string "レポートの　かきこみは　しゅうりょうしました\n"
	.string "{COLOR 4}“Aボタンを　おしてください”$"
	.globl gUnknown_85CBEBA
gUnknown_85CBEBA: @ 0x85CBEBA
	.string "れんらくせん$"
	.globl gUnknown_85CBEC1
gUnknown_85CBEC1: @ 0x85CBEC1
	.string "ひみつきち$"
	.globl gUnknown_85CBEC7
gUnknown_85CBEC7: @ 0x85CBEC7
	.string "アジト$"

	.globl gUnknown_85CBECB
gUnknown_85CBECB: @ 0x85CBECB
	.string "RTCを　リセットします\n"
	.string "Aで　けってい　Bで　キャンセル$"
	.globl gUnknown_85CBEE9
gUnknown_85CBEE9: @ 0x85CBEE9
	.string "げんざいの　ゲームない　じかん$"
	.globl gUnknown_85CBEF9
gUnknown_85CBEF9: @ 0x85CBEF9
	.string "ぜんかいの　ゲームない　じかん$"
	.globl gUnknown_85CBF09
gUnknown_85CBF09: @ 0x85CBF09
	.string "じかんを　さいせってい　してください$"
	.globl gUnknown_85CBF1C
gUnknown_85CBF1C: @ 0x85CBF1C
	.string "じかんを　さいせってい　しました！\n"
	.string "レポートを　かいています　おまちください$"
	.globl gUnknown_85CBF43
gUnknown_85CBF43: @ 0x85CBF43
	.string "レポートを　かきこみました！$"
	.globl gUnknown_85CBF52
gUnknown_85CBF52: @ 0x85CBF52
	.string "レポートの　かきこみに\n"
	.string "しっぱい　しました⋯$"
	.globl gUnknown_85CBF69
gUnknown_85CBF69: @ 0x85CBF69
	.string "レポートが　ないので\n"
	.string "じかんの　せっていは　できません！$"
	.globl sMEScrCmdGivenationaldexText
sMEScrCmdGivenationaldexText: @ 0x85CBF86
	.string "ゲームない　じかんの　しゅうせい　システムが\n"
	.string "つかえる　ように　なりました！$"
	.globl gUnknown_85CBFAD
gUnknown_85CBFAD: @ 0x85CBFAD
	.string "スロット$"

	.globl gUnknown_85CBFB2
gUnknown_85CBFB2: @ 0x85CBFB2
	.string "ルーレット$"

	.globl gUnknown_85CBFB8
gUnknown_85CBFB8: @ 0x85CBFB8
	.string "いい$"
	.globl gUnknown_85CBFBB
gUnknown_85CBFBB: @ 0x85CBFBB
	.string "おいしい$"
	.globl gUnknown_85CBFC0
gUnknown_85CBFC0: @ 0x85CBFC0
	.string "さいこう$"
	.globl gUnknown_85CBFC5
gUnknown_85CBFC5: @ 0x85CBFC5
	.string "いまいち$"
	.globl gUnknown_85CBFCA
gUnknown_85CBFCA: @ 0x85CBFCA
	.string "まずい$"
	.globl gUnknown_85CBFCE
gUnknown_85CBFCE: @ 0x85CBFCE
	.string "さいあく$"
	.globl gUnknown_85CBFD3
gUnknown_85CBFD3: @ 0x85CBFD3
	.string "から$"
	.globl gUnknown_85CBFD6
gUnknown_85CBFD6: @ 0x85CBFD6
	.string "しぶ$"
	.globl gUnknown_85CBFD9
gUnknown_85CBFD9: @ 0x85CBFD9
	.string "あま$"
	.globl gUnknown_85CBFDC
gUnknown_85CBFDC: @ 0x85CBFDC
	.string "にが$"

	.globl gUnknown_85CBFDF
gUnknown_85CBFDF: @ 0x85CBFDF
	.string "すっぱ$"
	.globl gUnknown_85CBFE3
gUnknown_85CBFE3: @ 0x85CBFE3
	.string "シングル$"

	.globl gUnknown_85CBFE8
gUnknown_85CBFE8: @ 0x85CBFE8
	.string "ダブル$"

	.globl gUnknown_85CBFEC
gUnknown_85CBFEC: @ 0x85CBFEC
	.string "とく$　　0てん$　10てん$　20てん$　30てん$　40てん$　50てん$　60てん$　70てん$　80てん$　90てん$100てん$　　？$キッスポスター　　　16BP$キッスクッション　　32BP$ムチュールドール　　32BP$トゲピードール　　　48BP$ニャースドール　　　48BP$ピッピドール　　　　48BP$メタモンドール　　　48BP$ヒノアラシドール　　80BP$チコリータドール　　80BP$ワニノコドール　　　80BP$ラプラスドール　　128BP$カビゴンドール　　128BP$フシギバナドール　256BP$リザードンドール　256BP$カメックスドール　256BP$タウリン　　　　　　　1BP$リゾチウム　　　　　　1BP$ブロムヘキシン　　　　1BP$キトサン　　　　　　　1BP$インドメタシン　　　　1BP$マックスアップ　　　　1BP$たべのこし　　　　　48BP$しろいハーブ　　　　48BP$せんせいのツメ　　　48BP$メンタルハーブ　　　48BP$ひかりのこな　　　　64BP$こだわりハチマキ　　64BP$おうじゃのしるし　　64BP$きあいのハチマキ　　64BP$ピントレンズ　　　　64BP$タマゴうみ　　　　16BP$ちきゅうなげ　　　24BP$ゆめくい　　　　　24BP$メガトンパンチ　　24BP$メガトンキック　　48BP$のしかかり　　　　48BP$いわなだれ　　　　48BP$カウンター　　　　48BP$でんじは　　　　　48BP$つるぎのまい　　　48BP$まるくなる　　　　16BP$いびき　　　　　　24BP$どろかけ　　　　　24BP$スピードスター　　24BP$こごえるかぜ　　　24BP$こらえる　　　　　48BP$じこあんじ　　　　48BP$れいとうパンチ　　48BP$かみなりパンチ　　48BP$ほのおのパンチ　　48BP$"
	.globl gText_PkmnFainted_FldPsn
gText_PkmnFainted_FldPsn: @ 0x85CC30F
	.string "{B_COPY_VAR_1}は\n"
	.string "ちからつきた\p$"
	.globl gText_Marco
gText_Marco: @ 0x85CC31B
	.string "コウジ$"

	.globl gUnknown_85CC31F
gUnknown_85CC31F: @ 0x85CC31F
	.string "なまえ$"
	.globl gUnknown_85CC323
gUnknown_85CC323: @ 0x85CC323
	.string "IDNo,$"

	.globl gUnknown_85CC329
gUnknown_85CC329: @ 0x85CC329
	.string "おこづかい$"
	.globl gUnknown_85CC32F
gUnknown_85CC32F: @ 0x85CC32F
	.string "¥$"

	.globl gUnknown_85CC331
gUnknown_85CC331: @ 0x85CC331
	.string "ポケモンずかん$"
	.globl gUnknown_85CC339
gUnknown_85CC339: @ 0x85CC339
	.string "ひき$"
	.globl gUnknown_85CC33C
gUnknown_85CC33C: @ 0x85CC33C
	.string ":$てん$"

	.globl gUnknown_85CC341
gUnknown_85CC341: @ 0x85CC341
	.string "プレイじかん$ゲームポイント$"
	.globl gUnknown_85CC350
gUnknown_85CC350: @ 0x85CC350
	.string "のトレーナーカード$"

	.globl gUnknown_85CC35A
gUnknown_85CC35A: @ 0x85CC35A
	.string "はじめてのでんどういり　$つうしんたいせん$ケーブルたいせん$"
	.globl gUnknown_85CC379
gUnknown_85CC379: @ 0x85CC379
	.string "かち　　　　　まけ$"
	.globl gUnknown_85CC383
gUnknown_85CC383: @ 0x85CC383
	.string "ポケモンつうしんこうかん$"
	.globl gUnknown_85CC390
gUnknown_85CC390: @ 0x85CC390
	.string "ユニオンたいせんとこうかん$"
	.globl gUnknown_85CC39E
gUnknown_85CC39E: @ 0x85CC39E
	.string "きのみクラッシュ$"
	.globl gUnknown_85CC3A7
gUnknown_85CC3A7: @ 0x85CC3A7
	.string "あいてが　カードを　みおわるのを\n"
	.string "まっています$"
	.globl gUnknown_85CC3BF
gUnknown_85CC3BF: @ 0x85CC3BF
	.string "ともだちと　つくった　ポロック$"
	.globl gUnknown_85CC3CF
gUnknown_85CC3CF: @ 0x85CC3CF
	.string "{B_COPY_VAR_1}{COLOR 2}{SHADOW 3}こ$"
	.globl gUnknown_85CC3D9
gUnknown_85CC3D9: @ 0x85CC3D9
	.string "ともだちとコンテスト　ゆうしょう$"
	.globl gUnknown_85CC3EA
gUnknown_85CC3EA: @ 0x85CC3EA
	.string "かちとった　バトルポイント$"
	.globl gUnknown_85CC3F8
gUnknown_85CC3F8: @ 0x85CC3F8
	.string "{B_COPY_VAR_1}{COLOR 2}{SHADOW 3}BP$"
	.globl gUnknown_85CC403
gUnknown_85CC403: @ 0x85CC403
	.string "バトルタワー　　かち　　　　　　かちぬき$"
	.globl gUnknown_85CC418
gUnknown_85CC418: @ 0x85CC418
	.string "{B_COPY_VAR_1}　　　　　　{B_COPY_VAR_2}$バトルタワー$バトルドーム$バトルパレス$バトルファクトリー$バトルアリーナ$バトルチューブ$バトルピラミッド$　{B_COPY_VAR_1}　シングル${B_COPY_VAR_1}　ダブル$　{B_COPY_VAR_1}　マルチ$　{B_COPY_VAR_1}　つうしん${B_COPY_VAR_1}$"
	.globl gUnknown_85CC47F
gUnknown_85CC47F: @ 0x85CC47F
	.string "もたせるべき$"
	.globl gUnknown_85CC486
gUnknown_85CC486: @ 0x85CC486
	.string "もたせない$"
	.globl gUnknown_85CC48C
gUnknown_85CC48C: @ 0x85CC48C
	.string "{COLOR 3}{SHADOW 2}$"
	.globl gUnknown_85CC493
gUnknown_85CC493: @ 0x85CC493
	.string "{COLOR 8}$"
	.globl gUnknown_85CC497
gUnknown_85CC497: @ 0x85CC497
	.string "{HIGHLIGHT 0}{COLOR 255}"
	.globl gUnknown_85CC49D
gUnknown_85CC49D: @ 0x85CC49D
	.string "C,$"

	.globl gUnknown_85CC4A0
gUnknown_85CC4A0: @ 0x85CC4A0
	.string "B,$"

	.globl gUnknown_85CC4A3
gUnknown_85CC4A3: @ 0x85CC4A3
	.string "けっか　はっぴょう！$"
	.globl gUnknown_85CC4AE
gUnknown_85CC4AE: @ 0x85CC4AE
	.string "1じしんさの　けっか！$"
	.globl gUnknown_85CC4BA
gUnknown_85CC4BA: @ 0x85CC4BA
	.string "2じしんさの　けっか！$"
	.globl gUnknown_85CC4C6
gUnknown_85CC4C6: @ 0x85CC4C6
	.string "ゆうしょう！　{B_COPY_VAR_1}の　{B_COPY_VAR_2}！$"
	.globl gUnknown_85CC4D5
gUnknown_85CC4D5: @ 0x85CC4D5
	.string "つうしんたいきちゅう$"
	.globl gUnknown_85CC4E0
gUnknown_85CC4E0: @ 0x85CC4E0
	.string "{COLOR 2}$"
	.globl gUnknown_85CC4E4
gUnknown_85CC4E4: @ 0x85CC4E4
	.string "{COLOR_HIGHLIGHT_SHADOW 15 1 14}$"
	.globl gText_HealthboxNickname
gText_HealthboxNickname: @ 0x85CC4EA
	.string "{HIGHLIGHT 2}$"
	.globl gUnknown_85CC4EE
gUnknown_85CC4EE: @ 0x85CC4EE
	.string "　$"
	.globl gText_HealthboxGender_Male
gText_HealthboxGender_Male: @ 0x85CC4F0
	.string "{COLOR 11}♂$"
	.globl gText_HealthboxGender_Female
gText_HealthboxGender_Female: @ 0x85CC4F5
	.string "{COLOR 10}♀$"
	.globl gText_HealthboxGender_None
gText_HealthboxGender_None: @ 0x85CC4FA
	.string "{COLOR 11}$あいうえお$かきくけこ$さしすせそ$たちつてと$なにぬねの$はひふへほ$まみむめも$やゆよ！？$らりるれろ$わをんー　$アイウエオ$カキクケコ$サシスセソ$タチツテト$ナニヌネノ$ハヒフヘホ$マミムメモ$ヤユヨ！？$ラリルレロ$ワヲンー　$ABCDE$FGHIJ$KLMNO$PQRST$UVWXY$Z·⋯　　$01234$56789${EMOJI_MISCHIEVOUS}{EMOJI_HAPPY}{EMOJI_ANGRY}{EMOJI_SURPRISED}{EMOJI_BIGANGER}${EMOJI_BIGSMILE}{EMOJI_EVIL}{EMOJI_NEUTRAL}{EMOJI_TIRED}{EMOJI_SHOCKED}${EMOJI_LEAF}{EMOJI_FIRE}{EMOJI_WATER}{EMOJI_BOLT}{EMOJI_BALL}$♂♀{EMOJI_LEFT_PAREN}{EMOJI_RIGHT_PAREN}{EMOJI_TILDE}${EMOJI_LEFT_EYE}{EMOJI_RIGHT_EYE}{EMOJI_SMALLWHEEL}{EMOJI_SPHERE}{EMOJI_IRRITATED}${EMOJI_SPIRAL}{EMOJI_BIGWHEEL}{EMOJI_TONGUE}{EMOJI_ACUTE}{EMOJI_GRAVE}${EMOJI_RIGHT_FIST}{EMOJI_LEFT_FIST}{EMOJI_TRIANGLE_OUTLINE}{EMOJI_UNION}{EMOJI_GREATER_THAN}${EMOJI_CIRCLE}{EMOJI_TRIANGLE}{EMOJI_SQUARE}{EMOJI_HEART}{EMOJI_MOON}${EMOJI_NOTE}{EMOJI_PLUS}{EMOJI_MINUS}{EMOJI_EQUALS}{EMOJI_PIPE}${EMOJI_HIGHBAR}{UNDERSCORE}{EMOJI_SEMICOLON}:　$ひらがな$カタカナ$ABC$きごう$とうろく$とじる$チャットを　やめますか？$どこに　とうろくしますか？$ここに　とうろくしますか？$ことばを　いれて　ください！$"
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
gUnknown_85CC769: @ 0x85CC769
	.string "こんにちは$"
	.globl gUnknown_85CC76F
gUnknown_85CC76F: @ 0x85CC76F
	.string "ポケモン$"

	.globl gUnknown_85CC774
gUnknown_85CC774: @ 0x85CC774
	.string "こうかん$"
	.globl gUnknown_85CC779
gUnknown_85CC779: @ 0x85CC779
	.string "たいせん$"
	.globl gUnknown_85CC77E
gUnknown_85CC77E: @ 0x85CC77E
	.string "しよう！$"
	.globl gUnknown_85CC783
gUnknown_85CC783: @ 0x85CC783
	.string "OK！$"

	.globl gUnknown_85CC787
gUnknown_85CC787: @ 0x85CC787
	.string "ごめん⋯$"

	.globl gUnknown_85CC78C
gUnknown_85CC78C: @ 0x85CC78C
	.string "わーい{EMOJI_BIGSMILE}$"
	.globl gUnknown_85CC792
gUnknown_85CC792: @ 0x85CC792
	.string "サンキュー$"

	.globl gUnknown_85CC798
gUnknown_85CC798: @ 0x85CC798
	.string "バイバイ！$あいての　じゃくてんを　つく！$さいきょうの　はがねポケモン$めずらしい　いしの　ためなら$たきだって　のぼって　いくよ$けっきょく　ボクが　いちばん$つよくて　すごいんだよね$ポケモンの　ちしきで　しょうぶ$いろんな　ポケモンを　つかうぜ$とうさんより　すごい　ポケモン$はかせに　なって　みせるさ！$しょうぶは　とくいじゃないかも$どんな　ポケモンでも　つかうわ$ポケモン　つれて　おとうさんの$けんきゅうを　おてつだい！$"
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
gUnknown_85CCA8C: @ 0x85CCA8C
	.string "{B_COPY_VAR_1}にんよう$"
	.globl gUnknown_85CCA93
gUnknown_85CCA93: @ 0x85CCA93
	.string "てにいれた　シンボル$"
	.globl gUnknown_85CCA9E
gUnknown_85CCA9E: @ 0x85CCA9E
	.string "たいせんの　きろく$"
	.globl gUnknown_85CCAA8
gUnknown_85CCAA8: @ 0x85CCAA8
	.string "バトルポイント$とじる$$バトルフロンティアの　マップを　みます$トレーナーカードを　みます$きろくした　たいせんを　みます$フロンティアパスを　とじます$いま　たまっている　バトルポイントです$ここに　シンボルを　あつめます$バトルタワー　アビリティシンボル$バトルドーム　タクティクスシンボル$バトルパレス　スピリットシンボル$バトルアリーナ　ガッツシンボル$バトルファクトリー　ノウレッジシンボル$バトルチューブ　ラックシンボル$バトルピラミッド　ブレイブシンボル$げんざい　たいせんきろくは　ありません$バトルタワー$バトルドーム$バトルパレス$バトルアリーナ$バトルファクトリー$バトルチューブ$バトルピラミッド$かちぬき　ひたすら　うえを　めざす。\n"
	.string "さいのうを　ためされる。$トーナメントを　かちぬく。\n"
	.string "せんじゅつを　ためされる。$しょうぶを　みまもる。\n"
	.string "ポケモンとの　きずなを　ためされる。$つよい　ポケモンの　チームで　しょうりする。\n"
	.string "とうしを　ためされる。$レンタルポケモンで　しょうりする。\n"
	.string "ちしきを　ためされる。$3つの　みちから　1つえらび　かちすすむ。\n"
	.string "うんを　ためされる。$ちょうじょうを　めざし　ぼうけんする。\n"
	.string "ゆうきを　ためされる。$"
	.globl gUnknown_85CCCBD
gUnknown_85CCCBD: @ 0x85CCCBD
	.string "しゅじんこう　{B_COPY_VAR_1}$"
	.globl gUnknown_85CCCC7
gUnknown_85CCCC7: @ 0x85CCCC7
	.string "プレイじかん　{B_COPY_VAR_1}:{B_COPY_VAR_2}$"
	.globl gUnknown_85CCCD4
gUnknown_85CCCD4: @ 0x85CCCD4
	.string "ポケモンずかん　{B_COPY_VAR_1}ひき$"
	.globl gUnknown_85CCCE1
gUnknown_85CCCE1: @ 0x85CCCE1
	.string "もっているバッジ　{B_COPY_VAR_1}こ$"
	.globl gText_Powder
gText_Powder: @ 0x85CCCEE
	.string "きのみのこな$"
	.globl gUnknown_85CCCF5
gUnknown_85CCCF5: @ 0x85CCCF5
	.string "ドードリオのきのみどりの　きろく$きのみをとった　かいすう$さいこう　とくてん$5にんで　きのみを\n"
	.string "つづけてとった　かいすう$"
	.globl gText_BerryPickingResults
gText_BerryPickingResults: @ 0x85CCD34
	.string "きのみの　けっか　はっぴょう！！$"
	.globl gText_10P30P50P50P
gText_10P30P50P50P: @ 0x85CCD45
	.string "10P　　30P　　50P　　{EMOJI_MINUS}50P$"
	.globl gText_AnnouncingRankings
gText_AnnouncingRankings: @ 0x85CCD5A
	.string "じゅんいの　はっぴょう！！$"
	.globl gText_AnnouncingPrizes
gText_AnnouncingPrizes: @ 0x85CCD68
	.string "しょうひんの　はっぴょう！！$1:$2:$3:$4:$5:$"
	.globl gText_FirstPlacePrize
gText_FirstPlacePrize: @ 0x85CCD86
	.string "1ばんに　なった　ひとに\n"
	.string "{DYNAMIC 0}を　プレゼント！！$"
	.globl gText_CantHoldAnyMore
gText_CantHoldAnyMore: @ 0x85CCD9F
	.string "{DYNAMIC 0}は　いっぱいです⋯$"
	.globl gText_FilledStorageSpace
gText_FilledStorageSpace: @ 0x85CCDAB
	.string "{DYNAMIC 0}が　いっぱいになってしまった！$"
	.globl gText_WantToPlayAgain
gText_WantToPlayAgain: @ 0x85CCDBD
	.string "もういちど　あそびますか？$"
	.globl gText_SomeoneDroppedOut
gText_SomeoneDroppedOut: @ 0x85CCDCB
	.string "だれかが　ぬけました\n"
	.string "つうしんを　しゅうりょう　します$"
	.globl gText_SpacePoints
gText_SpacePoints: @ 0x85CCDE7
	.string "てん$"

	.globl gText_CommunicationStandby3
gText_CommunicationStandby3: @ 0x85CCDEA
	.string "つうしん　たいきちゅうです$"
	.globl gUnknown_85CCDF8
gUnknown_85CCDF8: @ 0x85CCDF8
	.string "てん$"

	.globl gUnknown_85CCDFB
gUnknown_85CCDFB: @ 0x85CCDFB
	.string "かい$"
	.globl gUnknown_85CCDFE
gUnknown_85CCDFE: @ 0x85CCDFE
	.string "ミニポケモンでジャンプの　きろく$さいこう　ジャンプかいすう$さいこう　とくてん$れんぞく　EXCELLENT$"
	.globl gUnknown_85CCE36
gUnknown_85CCE36: @ 0x85CCE36
	.string "せいせきが　よかったので\n"
	.string "{DYNAMIC 0}を　{DYNAMIC 1}こ　プレゼント！$"
	.globl gUnknown_85CCE52
gUnknown_85CCE52: @ 0x85CCE52
	.string "{DYNAMIC 0}が　いっぱいに\n"
	.string "なってしまった！$"
	.globl gUnknown_85CCE65
gUnknown_85CCE65: @ 0x85CCE65
	.string "{DYNAMIC 0}は　いっぱいです⋯$"
	.globl gUnknown_85CCE71
gUnknown_85CCE71: @ 0x85CCE71
	.string "もういちど　あそびますか？$"
	.globl gUnknown_85CCE7F
gUnknown_85CCE7F: @ 0x85CCE7F
	.string "だれかがぬけました\n"
	.string "つうしんを　しゅうりょうします$"
	.globl gUnknown_85CCE99
gUnknown_85CCE99: @ 0x85CCE99
	.string "つうしん　たいきちゅう$"
	.globl gUnknown_85CCEA5
gUnknown_85CCEA5: @ 0x85CCEA5
	.string "{MUS_RG_VS_TRAINER}の　つうしん　コンテスト　せいせき$"
	.globl gUnknown_85CCEB9
gUnknown_85CCEB9: @ 0x85CCEB9
	.string "1い$"
	.globl gUnknown_85CCEBC
gUnknown_85CCEBC: @ 0x85CCEBC
	.string "2い$"
	.globl gUnknown_85CCEBF
gUnknown_85CCEBF: @ 0x85CCEBF
	.string "3い$"
	.globl gUnknown_85CCEC2
gUnknown_85CCEC2: @ 0x85CCEC2
	.string "4い$"
	.globl gUnknown_85CCEC5
gUnknown_85CCEC5: @ 0x85CCEC5
	.string "someone$"

	.globl gUnknown_85CCECD
gUnknown_85CCECD: @ 0x85CCECD
	.string "pokemon$"

	.globl gJPText_MysteryGift
gJPText_MysteryGift: @ 0x85CCED5
	.string "ふしぎなもらいもの$"
	.globl gJPText_DecideStop
gJPText_DecideStop: @ 0x85CCEDF
	.string "{A_BUTTON}けってい　{B_BUTTON}やめる$"
	.globl gJPText_ReceiveMysteryGiftWithEReader
gJPText_ReceiveMysteryGiftWithEReader: @ 0x85CCEEC
	.string "カードeリーダー{PLUS}　で\n"
	.string "ふしぎなもらいものを　よみこみます$"
	.globl gJPText_SelectConnectFromEReaderMenu
gJPText_SelectConnectFromEReaderMenu: @ 0x85CCF0B
	.string "カードeリーダー{PLUS}の　メニューから\n"
	.string "‘つうしん'を　えらび$"
	.globl gJPText_SelectConnectWithGBA
gJPText_SelectConnectWithGBA: @ 0x85CCF2A
	.string "‘ゲームボーイアドバンスとつうしん'\n"
	.string "を　せんたく　してください$カードeリーダー{PLUS}の　‘つうしん'を\n"
	.string "えらんで　Aボタンを　おしてください$"
	.globl gJPText_LinkIsIncorrect
gJPText_LinkIsIncorrect: @ 0x85CCF72
	.string "せつぞくが　まちがっています$"

	.globl gJPText_CardReadingHasBeenHalted
gJPText_CardReadingHasBeenHalted: @ 0x85CCF81
	.string "カードの　よみこみを\n"
	.string "ちゅうし　しました$カードeリーダー{PLUS}と\n"
	.string "つうしん　できません$"
	.globl gJPText_Connecting
gJPText_Connecting: @ 0x85CCFAD
	.string "つうしん　ちゅう　です$"

	.globl gJPText_ConnectionErrorCheckLink
gJPText_ConnectionErrorCheckLink: @ 0x85CCFB9
	.string "つうしん　エラーです\n"
	.string "せつぞくを　たしかめて　ください$"

	.globl gJPText_ConnectionErrorTryAgain
gJPText_ConnectionErrorTryAgain: @ 0x85CCFD5
	.string "つうしん　エラーです\n"
	.string "はじめから　やりなおして　ください$"

	.globl gJPText_AllowEReaderToLoadCard
gJPText_AllowEReaderToLoadCard: @ 0x85CCFF2
	.string "カードeリーダー{PLUS}　に\n"
	.string "カードを　よみこませて　ください$"
	.globl gJPText_ConnectionComplete
gJPText_ConnectionComplete: @ 0x85CD010
	.string "つうしん　しゅうりょう！$"

	.globl gJPText_NewTrainerHasComeToHoenn
gJPText_NewTrainerHasComeToHoenn: @ 0x85CD01D
	.string "あらたな　トレーナーが\n"
	.string "ホウエンに　やってきた！$"

	.globl gJPText_PleaseWaitAMoment
gJPText_PleaseWaitAMoment: @ 0x85CD036
	.string "しばらく　おまちください$"

	.globl gJPText_WriteErrorUnableToSaveData
gJPText_WriteErrorUnableToSaveData: @ 0x85CD043
	.string "かきこみ　エラー　です\n"
	.string "データが　ほぞん　できませんでした$あか$あお$　"
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
gUnknown_85CD0DC: @ 0x85CD0DC
	.string "つうしん　たいき　ちゅう　です\n"
	.string "⋯⋯Bボタンで　キャンセル　します$"
	.globl gUnknown_85CD0FE
gUnknown_85CD0FE: @ 0x85CD0FE
	.string "Aボタンで　できごとを　よみこみます\n"
	.string "⋯⋯Bボタンで　キャンセル　します$"
	.globl gUnknown_85CD123
gUnknown_85CD123: @ 0x85CD123
	.string "できごとを　よみこみちゅう！！$"
	.globl gUnknown_85CD133
gUnknown_85CD133: @ 0x85CD133
	.string "つうしんケーブルを　ぬかないで　ください\n"
	.string "でんげんを　きらないで　ください$"
	.globl gUnknown_85CD159
gUnknown_85CD159: @ 0x85CD159
	.string "できごとの　よみこみが\n"
	.string "せいじょうに　しゅうりょう　しました$せつぞく　できない　ききの　ようです\n"
	.string "ただしい　ききと　やりなおしてください$"
	.globl gUnknown_85CD19F
gUnknown_85CD19F: @ 0x85CD19F
	.string "エラーがはっせいしました\n"
	.string "しゅうりょうします$Aボタンを　おしてください$つながりました$データを　じゅしんしました$セーブできませんでした$セーブできました$ロードできませんでした$ロードできました$"
	.globl gUnknown_85CD204
gUnknown_85CD204: @ 0x85CD204
	.incbin "baserom_jp.gba", 0x5cd204, 0x4

	.globl gUnknown_85CD208
gUnknown_85CD208: @ 0x85CD208
	.incbin "baserom_jp.gba", 0x5cd208, 0x18

	.globl sClockOamData
sClockOamData: @ 0x85CD220
	.incbin "baserom_jp.gba", 0x5cd220, 0x8

	.globl sSaveFailedBgTemplates
sSaveFailedBgTemplates: @ 0x85CD228
	.incbin "baserom_jp.gba", 0x5cd228, 0xc

	.globl sDummyWindowTemplate
sDummyWindowTemplate: @ 0x85CD234
	.incbin "baserom_jp.gba", 0x5cd234, 0x8

	.globl sWindowTemplate_Text
sWindowTemplate_Text: @ 0x85CD23C
	.incbin "baserom_jp.gba", 0x5cd23c, 0x8

	.globl sWindowTemplate_Clock
sWindowTemplate_Clock: @ 0x85CD244
	.incbin "baserom_jp.gba", 0x5cd244, 0x8

	.globl sClockFrames
sClockFrames: @ 0x85CD24C
	.byte 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x09, 0x00, 0x00, 0x05, 0x00, 0x01
	.byte 0x01, 0x00, 0x01, 0x05, 0x01, 0x01, 0x09, 0x01, 0x00, 0x05, 0x01, 0x00

	.globl sSaveFailedClockPal
sSaveFailedClockPal: @ 0x85CD264
	.byte 0x2C, 0x2E, 0x00, 0x00, 0xE7, 0x1C, 0xEF, 0x3D, 0xF7, 0x5E, 0xFF, 0x7F
	.byte 0x1F, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sSaveFailedClockGfx
sSaveFailedClockGfx: @ 0x85CD284
	.incbin "baserom_jp.gba", 0x5cd284, 0x90

	.globl sRegicePathCoords
sRegicePathCoords: @ 0x85CD314
	.byte 0x04, 0x15, 0x05, 0x15, 0x06, 0x15, 0x07, 0x15, 0x08, 0x15, 0x09, 0x15
	.byte 0x0A, 0x15, 0x0B, 0x15, 0x0C, 0x15, 0x0C, 0x16, 0x0C, 0x17, 0x0D, 0x17
	.byte 0x0D, 0x18, 0x0D, 0x19, 0x0D, 0x1A, 0x0D, 0x1B, 0x0C, 0x1B, 0x0C, 0x1C
	.byte 0x04, 0x1D, 0x05, 0x1D, 0x06, 0x1D, 0x07, 0x1D, 0x08, 0x1D, 0x09, 0x1D
	.byte 0x0A, 0x1D, 0x0B, 0x1D, 0x0C, 0x1D, 0x04, 0x1C, 0x04, 0x1B, 0x03, 0x1B
	.byte 0x03, 0x1A, 0x03, 0x19, 0x03, 0x18, 0x03, 0x17, 0x04, 0x17, 0x04, 0x16

	.globl gUnknown_85CD35C
gUnknown_85CD35C: @ 0x85CD35C
	.incbin "baserom_jp.gba", 0x5cd35c, 0x32

	.globl gUnknown_85CD38E
gUnknown_85CD38E: @ 0x85CD38E
	.incbin "baserom_jp.gba", 0x5cd38e, 0x12

	.globl gUnknown_85CD3A0
gUnknown_85CD3A0: @ 0x85CD3A0
	.incbin "baserom_jp.gba", 0x5cd3a0, 0x5fc

	.globl gUnknown_85CD99C
gUnknown_85CD99C: @ 0x85CD99C
	.incbin "baserom_jp.gba", 0x5cd99c, 0x54

	.globl gUnknown_85CD9F0
gUnknown_85CD9F0: @ 0x85CD9F0
	.incbin "baserom_jp.gba", 0x5cd9f0, 0x8

	.globl gUnknown_85CD9F8
gUnknown_85CD9F8: @ 0x85CD9F8
	.incbin "baserom_jp.gba", 0x5cd9f8, 0x10

	.globl gUnknown_85CDA08
gUnknown_85CDA08: @ 0x85CDA08
	.incbin "baserom_jp.gba", 0x5cda08, 0x48

	.globl gUnknown_85CDA50
gUnknown_85CDA50: @ 0x85CDA50
	.incbin "baserom_jp.gba", 0x5cda50, 0xb4

	.globl gUnknown_85CDB04
gUnknown_85CDB04: @ 0x85CDB04
	.incbin "baserom_jp.gba", 0x5cdb04, 0x4

	.globl gUnknown_85CDB08
gUnknown_85CDB08: @ 0x85CDB08
	.incbin "baserom_jp.gba", 0x5cdb08, 0x4

	.globl gUnknown_85CDB0C
gUnknown_85CDB0C: @ 0x85CDB0C
	.incbin "baserom_jp.gba", 0x5cdb0c, 0x34

	.globl gUnknown_85CDB40
gUnknown_85CDB40: @ 0x85CDB40
	.incbin "baserom_jp.gba", 0x5cdb40, 0x8

	.globl gUnknown_85CDB48
gUnknown_85CDB48: @ 0x85CDB48
	.incbin "baserom_jp.gba", 0x5cdb48, 0x18

	.globl gText_ClearAllSaveData
gText_ClearAllSaveData: @ 0x85CDB60
	.string "すべての　セーブデータエリアを\n"
	.string "クリア　しますか？$"
	.globl gText_ClearingData
gText_ClearingData: @ 0x85CDB7A
	.string "クリア　しています\n"
	.string "おまち　ください$　　　"

	.globl sClearSaveBgTemplates
sClearSaveBgTemplates: @ 0x85CDB90
	.incbin "baserom_jp.gba", 0x5cdb90, 0x8

	.globl sClearSaveTextWindow
sClearSaveTextWindow: @ 0x85CDB98
	.incbin "baserom_jp.gba", 0x5cdb98, 0x10

	.globl sClearSaveYesNo
sClearSaveYesNo: @ 0x85CDBA8
	.incbin "baserom_jp.gba", 0x5cdba8, 0x8

	.globl gUnknown_85CDBB0
gUnknown_85CDBB0: @ 0x85CDBB0
	.incbin "baserom_jp.gba", 0x5cdbb0, 0x20

	.globl gUnknown_85CDBD0
gUnknown_85CDBD0: @ 0x85CDBD0
	.incbin "baserom_jp.gba", 0x5cdbd0, 0x20

	.globl gUnknown_85CDBF0
gUnknown_85CDBF0: @ 0x85CDBF0
	.incbin "baserom_jp.gba", 0x5cdbf0, 0x20

	.globl gUnknown_85CDC10
gUnknown_85CDC10: @ 0x85CDC10
	.incbin "baserom_jp.gba", 0x5cdc10, 0x480

	.globl gUnknown_85CE090
gUnknown_85CE090: @ 0x85CE090
	.incbin "baserom_jp.gba", 0x5ce090, 0x13c

	.globl gUnknown_85CE1CC
gUnknown_85CE1CC: @ 0x85CE1CC
	.incbin "baserom_jp.gba", 0x5ce1cc, 0x60

	.globl gUnknown_85CE22C
gUnknown_85CE22C: @ 0x85CE22C
	.incbin "baserom_jp.gba", 0x5ce22c, 0x60

	.globl gUnknown_85CE28C
gUnknown_85CE28C: @ 0x85CE28C
	.incbin "baserom_jp.gba", 0x5ce28c, 0x5dc

	.globl gUnknown_85CE868
gUnknown_85CE868: @ 0x85CE868
	.incbin "baserom_jp.gba", 0x5ce868, 0x2d0

	.globl gUnknown_85CEB38
gUnknown_85CEB38: @ 0x85CEB38
	.incbin "baserom_jp.gba", 0x5ceb38, 0x20

	.globl gUnknown_85CEB58
gUnknown_85CEB58: @ 0x85CEB58
	.incbin "baserom_jp.gba", 0x5ceb58, 0x20

	.globl gUnknown_85CEB78
gUnknown_85CEB78: @ 0x85CEB78
	.incbin "baserom_jp.gba", 0x5ceb78, 0x13c

	.globl gUnknown_85CECB4
gUnknown_85CECB4: @ 0x85CECB4
	.incbin "baserom_jp.gba", 0x5cecb4, 0x20

	.globl gUnknown_85CECD4
gUnknown_85CECD4: @ 0x85CECD4
	.incbin "baserom_jp.gba", 0x5cecd4, 0x20

	.globl gUnknown_85CECF4
gUnknown_85CECF4: @ 0x85CECF4
	.incbin "baserom_jp.gba", 0x5cecf4, 0x688

	.globl gUnknown_85CF37C
gUnknown_85CF37C: @ 0x85CF37C
	.incbin "baserom_jp.gba", 0x5cf37c, 0x304

	.globl gUnknown_85CF680
gUnknown_85CF680: @ 0x85CF680
	.incbin "baserom_jp.gba", 0x5cf680, 0x16c

	.globl gUnknown_85CF7EC
gUnknown_85CF7EC: @ 0x85CF7EC
	.incbin "baserom_jp.gba", 0x5cf7ec, 0x40

	.globl gUnknown_85CF82C
gUnknown_85CF82C: @ 0x85CF82C
	.incbin "baserom_jp.gba", 0x5cf82c, 0x1ec

	.globl gUnknown_85CFA18
gUnknown_85CFA18: @ 0x85CFA18
	.incbin "baserom_jp.gba", 0x5cfa18, 0x20

	.globl gUnknown_85CFA38
gUnknown_85CFA38: @ 0x85CFA38
	.incbin "baserom_jp.gba", 0x5cfa38, 0x2ae4

	.globl gUnknown_85D251C
gUnknown_85D251C: @ 0x85D251C
	.incbin "baserom_jp.gba", 0x5d251c, 0x18

	.globl gUnknown_85D2534
gUnknown_85D2534: @ 0x85D2534
	.incbin "baserom_jp.gba", 0x5d2534, 0x30

	.globl gUnknown_85D2564
gUnknown_85D2564: @ 0x85D2564
	.incbin "baserom_jp.gba", 0x5d2564, 0x10

	.globl gUnknown_85D2574
gUnknown_85D2574: @ 0x85D2574
	.incbin "baserom_jp.gba", 0x5d2574, 0x48

	.globl gUnknown_85D25BC
gUnknown_85D25BC: @ 0x85D25BC
	.incbin "baserom_jp.gba", 0x5d25bc, 0x28

	.globl gUnknown_85D25E4
gUnknown_85D25E4: @ 0x85D25E4
	.incbin "baserom_jp.gba", 0x5d25e4, 0xc

	.globl gUnknown_85D25F0
gUnknown_85D25F0: @ 0x85D25F0
	.incbin "baserom_jp.gba", 0x5d25f0, 0x60

	.globl gUnknown_85D2650
gUnknown_85D2650: @ 0x85D2650
	.incbin "baserom_jp.gba", 0x5d2650, 0x18

	.globl gUnknown_85D2668
gUnknown_85D2668: @ 0x85D2668
	.incbin "baserom_jp.gba", 0x5d2668, 0x4

	.globl gUnknown_85D266C
gUnknown_85D266C: @ 0x85D266C
	.incbin "baserom_jp.gba", 0x5d266c, 0x50

	.globl gUnknown_85D26BC
gUnknown_85D26BC: @ 0x85D26BC
	.incbin "baserom_jp.gba", 0x5d26bc, 0x18

	.globl gUnknown_85D26D4
gUnknown_85D26D4: @ 0x85D26D4
	.incbin "baserom_jp.gba", 0x5d26d4, 0x38

	.globl gUnknown_85D270C
gUnknown_85D270C: @ 0x85D270C
	.incbin "baserom_jp.gba", 0x5d270c, 0x18

	.globl gUnknown_85D2724
gUnknown_85D2724: @ 0x85D2724
	.incbin "baserom_jp.gba", 0x5d2724, 0x38

	.globl gUnknown_85D275C
gUnknown_85D275C: @ 0x85D275C
	.incbin "baserom_jp.gba", 0x5d275c, 0x18

	.globl gUnknown_85D2774
gUnknown_85D2774: @ 0x85D2774
	.incbin "baserom_jp.gba", 0x5d2774, 0x18

	.globl gUnknown_85D278C
gUnknown_85D278C: @ 0x85D278C
	.incbin "baserom_jp.gba", 0x5d278c, 0x10

	.globl gUnknown_85D279C
gUnknown_85D279C: @ 0x85D279C
	.incbin "baserom_jp.gba", 0x5d279c, 0x10

	.globl gUnknown_85D27AC
gUnknown_85D27AC: @ 0x85D27AC
	.incbin "baserom_jp.gba", 0x5d27ac, 0x20

	.globl gUnknown_85D27CC
gUnknown_85D27CC: @ 0x85D27CC
	.incbin "baserom_jp.gba", 0x5d27cc, 0x10

	.globl gUnknown_85D27DC
gUnknown_85D27DC: @ 0x85D27DC
	.incbin "baserom_jp.gba", 0x5d27dc, 0x28

	.globl gUnknown_85D2804
gUnknown_85D2804: @ 0x85D2804
	.incbin "baserom_jp.gba", 0x5d2804, 0x10

	.globl gUnknown_85D2814
gUnknown_85D2814: @ 0x85D2814
	.incbin "baserom_jp.gba", 0x5d2814, 0x10

	.globl gUnknown_85D2824
gUnknown_85D2824: @ 0x85D2824
	.incbin "baserom_jp.gba", 0x5d2824, 0x30

	.globl gUnknown_85D2854
gUnknown_85D2854: @ 0x85D2854
	.incbin "baserom_jp.gba", 0x5d2854, 0x28

	.globl gUnknown_85D287C
gUnknown_85D287C: @ 0x85D287C
	.incbin "baserom_jp.gba", 0x5d287c, 0x10

	.globl gUnknown_85D288C
gUnknown_85D288C: @ 0x85D288C
	.incbin "baserom_jp.gba", 0x5d288c, 0x50

	.globl gUnknown_85D28DC
gUnknown_85D28DC: @ 0x85D28DC
	.incbin "baserom_jp.gba", 0x5d28dc, 0x10

	.globl gUnknown_85D28EC
gUnknown_85D28EC: @ 0x85D28EC
	.incbin "baserom_jp.gba", 0x5d28ec, 0x24

	.globl gUnknown_85D2910
gUnknown_85D2910: @ 0x85D2910
	.incbin "baserom_jp.gba", 0x5d2910, 0x18

	.globl gUnknown_85D2928
gUnknown_85D2928: @ 0x85D2928
	.incbin "baserom_jp.gba", 0x5d2928, 0x198

	.globl sWordSounds
sWordSounds: @ 0x85D2AC0
	.incbin "baserom_jp.gba", 0x5d2ac0, 0x8c

	.globl sWordPhonemes
sWordPhonemes: @ 0x85D2B4C
	.incbin "baserom_jp.gba", 0x5d2b4c, 0x3c0

	.globl sVariableDmgMoves
sVariableDmgMoves: @ 0x85D2F0C
	.hword 0x0044, 0x005A, 0x0075, 0x00F3, 0x0020, 0x00AF, 0x00B3, 0x00ED, 0x0149, 0x0108, 0x011C, 0x0143
	.hword 0x008A, 0x0137, 0x00AD, 0x00DC, 0x000C, 0x00DA, 0x00D8, 0x011B, 0x00D9, 0x0117, 0xFFFF, 0x00DE
	.hword 0x0095, 0xFFFF, 0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0001, 0x0000, 0x0005, 0x0001
	.hword 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001
	.hword 0x0001, 0x0001, 0x0001, 0x0005, 0x0005, 0x0004, 0x0005, 0x0001, 0x0003, 0x0001, 0x0003, 0x0005
	.hword 0x0001, 0x0007, 0x0001, 0x0007, 0x0007, 0x0001, 0x0005, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001
	.hword 0x0005, 0x0001, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000
	.hword 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0007, 0x0004, 0x0004, 0x0001, 0x0001
	.hword 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0001, 0x0004, 0x0005, 0x0002
	.hword 0x0004, 0x0001, 0x0004, 0x0001, 0x0007, 0x0002, 0x0001, 0x0005, 0x0007, 0x0003, 0x0003, 0x0004
	.hword 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0002, 0x0004, 0x0001, 0x0005, 0x0001, 0x0001, 0x0004
	.hword 0x0005, 0x0003, 0x0001, 0x0002, 0x0001, 0x0005, 0x0004, 0x0003, 0x0006, 0x0004, 0x0003, 0x0003
	.hword 0x0003, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001, 0x0005, 0x0001, 0x0001, 0x0007, 0x0002, 0x0002
	.hword 0x0001, 0x0001, 0x0004, 0x0004, 0x0004, 0x0001, 0x0004, 0x0004, 0x0001, 0x0001, 0x0001, 0x0001
	.hword 0x0007, 0x0007, 0x0006, 0x0003, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001
	.hword 0x0002, 0x0003, 0x0001, 0x0001, 0x0004, 0x0004, 0x0003, 0x0003, 0x0003, 0x0001, 0x0004, 0x0007
	.hword 0x0007, 0x0005, 0x0007, 0x0001, 0x0007, 0x0001, 0x0005, 0x0000, 0x0004, 0x0004, 0x0004, 0x0004
	.hword 0x0004, 0x0002, 0x0002, 0x0006, 0x0003, 0x0006, 0x0004, 0x0004, 0x0002, 0x0005, 0x0002, 0x0001
	.hword 0x0001, 0x0006, 0x0006, 0x0006, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0006, 0x0001, 0x0004
	.hword 0x0001, 0x0001, 0x0003, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0003
	.hword 0x0004, 0xFFFD, 0xFFFA, 0x0004, 0x0004, 0x0006, 0x0006, 0x0007, 0x0006, 0x0002, 0x0091, 0x0003
	.hword 0x00FA, 0x0003, 0x00BE, 0x0003, 0x0080, 0x0003, 0x006E, 0x0003, 0x0098, 0x0003, 0x0143, 0x0003
	.hword 0x0123, 0x0003, 0x007F, 0x0003, 0x014A, 0x0003, 0x0039, 0x0003, 0x0134, 0x0003, 0x0038, 0x0003
	.hword 0x003D, 0x0003, 0x015A, 0x0000, 0x0037, 0x0003, 0x0160, 0x0003, 0x0137, 0x0003, 0x0057, 0x0003
	.hword 0x004C, 0xFFFC, 0x013B, 0xFFFC, 0x00AC, 0xFFFC, 0x0035, 0xFFFC, 0x00DD, 0xFFFC, 0x007E, 0xFFFC
	.hword 0x0101, 0xFFFC, 0x0034, 0xFFFC, 0x0133, 0xFFFC, 0x012B, 0xFFFC, 0x011C, 0xFFFC, 0x0053, 0xFFFC
	.hword 0x0007, 0xFFFC, 0x004C, 0xFFFC, 0xFFFF, 0x0000, 0x013B, 0x0003, 0x00AC, 0x0003, 0x0035, 0x0003
	.hword 0x00DD, 0x0003, 0x007E, 0x0003, 0x0101, 0x0003, 0x0034, 0x0003, 0x0133, 0x0003, 0x012B, 0x0003
	.hword 0x011C, 0x0003, 0x0053, 0x0003, 0x0007, 0x0003, 0x004C, 0x0005, 0x00EB, 0x0003, 0x00EA, 0x0003
	.hword 0x00EC, 0x0003, 0x0137, 0x0003, 0xFFFF, 0x0000, 0x0137, 0x0003, 0x004C, 0xFFFD, 0xFFFF, 0x0000
	.hword 0x0137, 0x0003, 0x004C, 0xFFFD, 0xFFFF, 0x0000, 0x0055, 0x0003, 0x0009, 0x0003, 0x00D1, 0x0003
	.hword 0x0054, 0x0003, 0x00C0, 0x0003, 0x015F, 0x0003, 0x0056, 0x0000, 0x0057, 0x0003, 0x0158, 0x0003
	.hword 0xFFFF, 0x0000, 0x0005, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0005, 0x0005, 0x0005
	.hword 0x0005, 0x0005, 0x0004, 0x0005, 0x0005, 0x0003, 0x0003, 0x0004, 0x0003, 0x0006, 0x0006, 0x0006
	.hword 0x0004, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0004, 0x0004, 0x0004, 0x0004
	.hword 0x0004, 0x0004, 0x0004, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0002, 0x0002
	.hword 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004
	.hword 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0x0000

	.globl sPointsArray
sPointsArray: @ 0x85D3294
	.incbin "baserom_jp.gba", 0x5d3294, 0x70

	.globl sSpecialBattleStrings
sSpecialBattleStrings: @ 0x85D3304
	.string "ビ　”　B　ザ　'　♂　ヅ　ハ　ダ　セ　ぃ　れ　ド　ふ　へ　ト　タ　$$"
	.globl gUnknown_85D3328
gUnknown_85D3328: @ 0x85D3328
	.incbin "baserom_jp.gba", 0x5d3328, 0x19c

	.globl gUnknown_85D34C4
gUnknown_85D34C4: @ 0x85D34C4
	.string "　おああ　そあえ　いあい　いあい　いあい　いあい　い　$"
	.globl gUnknown_85D34E0
gUnknown_85D34E0: @ 0x85D34E0
	.incbin "baserom_jp.gba", 0x5d34e0, 0x8

	.globl gUnknown_85D34E8
gUnknown_85D34E8: @ 0x85D34E8
	.incbin "baserom_jp.gba", 0x5d34e8, 0x25c

	.globl gUnknown_85D3744
gUnknown_85D3744: @ 0x85D3744
	.incbin "baserom_jp.gba", 0x5d3744, 0x4b

	.globl gUnknown_85D378F
gUnknown_85D378F: @ 0x85D378F
	.incbin "baserom_jp.gba", 0x5d378f, 0x39

	.globl gUnknown_85D37C8
gUnknown_85D37C8: @ 0x85D37C8
	.incbin "baserom_jp.gba", 0x5d37c8, 0x8

	.globl gUnknown_85D37D0
gUnknown_85D37D0: @ 0x85D37D0
	.incbin "baserom_jp.gba", 0x5d37d0, 0x1e

	.globl gUnknown_85D37EE
gUnknown_85D37EE: @ 0x85D37EE
	.incbin "baserom_jp.gba", 0x5d37ee, 0x30

	.globl gUnknown_85D381E
gUnknown_85D381E: @ 0x85D381E
	.incbin "baserom_jp.gba", 0x5d381e, 0xbe

	.globl gUnknown_85D38DC
gUnknown_85D38DC: @ 0x85D38DC
	.incbin "baserom_jp.gba", 0x5d38dc, 0xc

	.globl gUnknown_85D38E8
gUnknown_85D38E8: @ 0x85D38E8
	.incbin "baserom_jp.gba", 0x5d38e8, 0x8

	.globl gUnknown_85D38F0
gUnknown_85D38F0: @ 0x85D38F0
	.incbin "baserom_jp.gba", 0x5d38f0, 0xe4

	.globl gUnknown_85D39D4
gUnknown_85D39D4: @ 0x85D39D4
	.incbin "baserom_jp.gba", 0x5d39d4, 0xe4

	.globl sDummyPicData
sDummyPicData: @ 0x85D3AB8
	.incbin "baserom_jp.gba", 0x5d3ab8, 0xc

	.globl sOamData_Normal
sOamData_Normal: @ 0x85D3AC4
	.incbin "baserom_jp.gba", 0x5d3ac4, 0x8

	.globl sOamData_Affine
sOamData_Affine: @ 0x85D3ACC
	.incbin "baserom_jp.gba", 0x5d3acc, 0x8

	.globl gUnknown_85D3AD4
gUnknown_85D3AD4: @ 0x85D3AD4
	.incbin "baserom_jp.gba", 0x5d3ad4, 0xa

	.globl gUnknown_85D3ADE
gUnknown_85D3ADE: @ 0x85D3ADE
	.incbin "baserom_jp.gba", 0x5d3ade, 0x126

	.globl gUnknown_85D3C04
gUnknown_85D3C04: @ 0x85D3C04
	.incbin "baserom_jp.gba", 0x5d3c04, 0x40

	.globl gUnknown_85D3C44
gUnknown_85D3C44: @ 0x85D3C44
	.incbin "baserom_jp.gba", 0x5d3c44, 0x20

	.globl gUnknown_85D3C64
gUnknown_85D3C64: @ 0x85D3C64
	.incbin "baserom_jp.gba", 0x5d3c64, 0x40

	.globl gUnknown_85D3CA4
gUnknown_85D3CA4: @ 0x85D3CA4
	.incbin "baserom_jp.gba", 0x5d3ca4, 0xc8

	.globl gUnknown_85D3D6C
gUnknown_85D3D6C: @ 0x85D3D6C
	.incbin "baserom_jp.gba", 0x5d3d6c, 0x18

	.globl gUnknown_85D3D84
gUnknown_85D3D84: @ 0x85D3D84
	.incbin "baserom_jp.gba", 0x5d3d84, 0xc

	.globl gUnknown_85D3D90
gUnknown_85D3D90: @ 0x85D3D90
	.string "おねえ$ハンサム$ジョバンニ$もあもあ$てつ$きんにくん$　　　"

	.globl gUnknown_85D3DB0
gUnknown_85D3DB0: @ 0x85D3DB0
	.incbin "baserom_jp.gba", 0x5d3db0, 0x2c

	.globl gUnknown_85D3DDC
gUnknown_85D3DDC: @ 0x85D3DDC
	.incbin "baserom_jp.gba", 0x5d3ddc, 0x14

	.globl gUnknown_85D3DF0
gUnknown_85D3DF0: @ 0x85D3DF0
	.incbin "baserom_jp.gba", 0x5d3df0, 0xc

	.globl gUnknown_85D3DFC
gUnknown_85D3DFC: @ 0x85D3DFC
	.incbin "baserom_jp.gba", 0x5d3dfc, 0x1630

	.globl gUnknown_85D542C
gUnknown_85D542C: @ 0x85D542C
	.incbin "baserom_jp.gba", 0x5d542c, 0x269

	.globl gUnknown_85D5695
gUnknown_85D5695: @ 0x85D5695
	.incbin "baserom_jp.gba", 0x5d5695, 0x283

	.globl gUnknown_85D5918
gUnknown_85D5918: @ 0x85D5918
	.incbin "baserom_jp.gba", 0x5d5918, 0x10

	.globl gUnknown_85D5928
gUnknown_85D5928: @ 0x85D5928
	.incbin "baserom_jp.gba", 0x5d5928, 0x10

	.globl gUnknown_85D5938
gUnknown_85D5938: @ 0x85D5938
	.incbin "baserom_jp.gba", 0x5d5938, 0x20

	.globl gUnknown_85D5958
gUnknown_85D5958: @ 0x85D5958
	.incbin "baserom_jp.gba", 0x5d5958, 0x98

	.globl gUnknown_85D59F0
gUnknown_85D59F0: @ 0x85D59F0
	.incbin "baserom_jp.gba", 0x5d59f0, 0xc

	.globl gUnknown_85D59FC
gUnknown_85D59FC: @ 0x85D59FC
	.incbin "baserom_jp.gba", 0x5d59fc, 0x58

	.globl gUnknown_85D5A54
gUnknown_85D5A54: @ 0x85D5A54
	.incbin "baserom_jp.gba", 0x5d5a54, 0x30

	.globl gUnknown_85D5A84
gUnknown_85D5A84: @ 0x85D5A84
	.incbin "baserom_jp.gba", 0x5d5a84, 0x48

	.globl gUnknown_85D5ACC
gUnknown_85D5ACC: @ 0x85D5ACC
	.incbin "baserom_jp.gba", 0x5d5acc, 0x18

	.globl gUnknown_85D5AE4
gUnknown_85D5AE4: @ 0x85D5AE4
	.incbin "baserom_jp.gba", 0x5d5ae4, 0x18

	.globl gUnknown_85D5AFC
gUnknown_85D5AFC: @ 0x85D5AFC
	.incbin "baserom_jp.gba", 0x5d5afc, 0x10

	.globl gUnknown_85D5B0C
gUnknown_85D5B0C: @ 0x85D5B0C
	.incbin "baserom_jp.gba", 0x5d5b0c, 0x5c

	.globl gUnknown_85D5B68
gUnknown_85D5B68: @ 0x85D5B68
	.incbin "baserom_jp.gba", 0x5d5b68, 0x10

	.globl gUnknown_85D5B78
gUnknown_85D5B78: @ 0x85D5B78
	.incbin "baserom_jp.gba", 0x5d5b78, 0x10
	.globl gUnknown_85D5B88
gUnknown_85D5B88: @ 0x85D5B88
	.incbin "baserom_jp.gba", 0x5d5b88, 0x40

	.globl gUnknown_85D5BC8
gUnknown_85D5BC8: @ 0x85D5BC8
	.incbin "baserom_jp.gba", 0x5d5bc8, 0x10

	.globl gUnknown_85D5BD8
gUnknown_85D5BD8: @ 0x85D5BD8
	.incbin "baserom_jp.gba", 0x5d5bd8, 0x40

	.globl gUnknown_85D5C18
gUnknown_85D5C18: @ 0x85D5C18
	.incbin "baserom_jp.gba", 0x5d5c18, 0x4

	.globl gUnknown_85D5C1C
gUnknown_85D5C1C: @ 0x85D5C1C
	.incbin "baserom_jp.gba", 0x5d5c1c, 0x20

	.globl gUnknown_85D5C3C
gUnknown_85D5C3C: @ 0x85D5C3C
	.incbin "baserom_jp.gba", 0x5d5c3c, 0x10

	.globl gUnknown_85D5C4C
gUnknown_85D5C4C: @ 0x85D5C4C
	.incbin "baserom_jp.gba", 0x5d5c4c, 0x44

	.globl gUnknown_85D5C90
gUnknown_85D5C90: @ 0x85D5C90
	.incbin "baserom_jp.gba", 0x5d5c90, 0x80

	.globl gUnknown_85D5D10
gUnknown_85D5D10: @ 0x85D5D10
	.incbin "baserom_jp.gba", 0x5d5d10, 0xac

	.globl gUnknown_85D5DBC
gUnknown_85D5DBC: @ 0x85D5DBC
	.incbin "baserom_jp.gba", 0x5d5dbc, 0x3

	.globl gUnknown_85D5DBF
gUnknown_85D5DBF: @ 0x85D5DBF
	.incbin "baserom_jp.gba", 0x5d5dbf, 0x3

	.globl gUnknown_85D5DC2
gUnknown_85D5DC2: @ 0x85D5DC2
	.incbin "baserom_jp.gba", 0x5d5dc2, 0x3

	.globl gUnknown_85D5DC5
gUnknown_85D5DC5: @ 0x85D5DC5
	.incbin "baserom_jp.gba", 0x5d5dc5, 0x7

	.globl gUnknown_85D5DCC
gUnknown_85D5DCC: @ 0x85D5DCC
	.incbin "baserom_jp.gba", 0x5d5dcc, 0x3c

	.globl gUnknown_85D5E08
gUnknown_85D5E08: @ 0x85D5E08
	.incbin "baserom_jp.gba", 0x5d5e08, 0x1c

	.globl gUnknown_85D5E24
gUnknown_85D5E24: @ 0x85D5E24
	.incbin "baserom_jp.gba", 0x5d5e24, 0x3

	.globl gUnknown_85D5E27
gUnknown_85D5E27: @ 0x85D5E27
	.incbin "baserom_jp.gba", 0x5d5e27, 0x3

	.globl gUnknown_85D5E2A
gUnknown_85D5E2A: @ 0x85D5E2A
	.incbin "baserom_jp.gba", 0x5d5e2a, 0x3

	.globl gUnknown_85D5E2D
gUnknown_85D5E2D: @ 0x85D5E2D
	.incbin "baserom_jp.gba", 0x5d5e2d, 0x3

	.globl gUnknown_85D5E30
gUnknown_85D5E30: @ 0x85D5E30
	.incbin "baserom_jp.gba", 0x5d5e30, 0x10

	.globl gUnknown_85D5E40
gUnknown_85D5E40: @ 0x85D5E40
	.incbin "baserom_jp.gba", 0x5d5e40, 0x2

	.globl gUnknown_85D5E42
gUnknown_85D5E42: @ 0x85D5E42
	.incbin "baserom_jp.gba", 0x5d5e42, 0x2b

	.globl gUnknown_85D5E6D
gUnknown_85D5E6D: @ 0x85D5E6D
	.incbin "baserom_jp.gba", 0x5d5e6d, 0x1

	.globl gUnknown_85D5E6E
gUnknown_85D5E6E: @ 0x85D5E6E
	.incbin "baserom_jp.gba", 0x5d5e6e, 0x1f

	.globl gUnknown_85D5E8D
gUnknown_85D5E8D: @ 0x85D5E8D
	.incbin "baserom_jp.gba", 0x5d5e8d, 0x8ff

	.globl gUnknown_85D678C
gUnknown_85D678C: @ 0x85D678C
	.incbin "baserom_jp.gba", 0x5d678c, 0x100

	.globl gUnknown_85D688C
gUnknown_85D688C: @ 0x85D688C
	.incbin "baserom_jp.gba", 0x5d688c, 0x40

	.globl sBattlePalaceFunctions
sBattlePalaceFunctions: @ 0x85D68CC
	.incbin "baserom_jp.gba", 0x5d68cc, 0x28

	.globl sBattlePalaceEarlyPrizes
sBattlePalaceEarlyPrizes: @ 0x85D68F4
	.hword 0x003F, 0x0040, 0x0041, 0x0043, 0x0042, 0x0046

	.globl sBattlePalaceLatePrizes
sBattlePalaceLatePrizes: @ 0x85D6900
	.hword 0x00B3, 0x00B4, 0x00B7, 0x00C8, 0x00B9, 0x00BB, 0x00C4, 0x00C6, 0x00BA, 0x0000

	.globl sWinStreakFlags
sWinStreakFlags: @ 0x85D6914
	.incbin "baserom_jp.gba", 0x5d6914, 0x10

	.globl sWinStreakMasks
sWinStreakMasks: @ 0x85D6924
	.4byte 0xFFFFFFEF, 0xFFFFFFDF, 0xFFBFFFFF, 0xFF7FFFFF

	.globl gUnknown_85D6934
gUnknown_85D6934: @ 0x85D6934
	.incbin "baserom_jp.gba", 0x5d6934, 0xb68

	.globl sMatchCallBattleTopics
sMatchCallBattleTopics: @ 0x85D749C
	.4byte 0x085D6E34 @ sMatchCallWildBattleTexts
	.4byte 0x085D6EAC @ sMatchCallNegativeBattleTexts
	.4byte 0x085D6F1C @ sMatchCallPositiveBattleTexts

	.globl sMatchCallBattleRequestTopics
sMatchCallBattleRequestTopics: @ 0x85D74A8
	.4byte 0x085D6F8C @ sMatchCallSameRouteBattleRequestTexts
	.4byte 0x085D6FFC @ sMatchCallDifferentRouteBattleRequestTexts

	.globl sMatchCallGeneralTopics
sMatchCallGeneralTopics: @ 0x85D74B0
	.4byte 0x085D706C @ sMatchCallPersonalizedTexts
	.4byte 0x085D726C @ sMatchCallBattleFrontierStreakTexts
	.4byte 0x085D72DC @ sMatchCallBattleFrontierRecordStreakTexts
	.4byte 0x085D734C @ sMatchCallBattleDomeTexts
	.4byte 0x085D73BC @ sMatchCallBattlePikeTexts
	.4byte 0x085D742C @ sMatchCallBattlePyramidTexts

	.globl sMatchCallWindow_Pal
sMatchCallWindow_Pal: @ 0x85D74C8
	.hword 0x0000 @ color 0
	.hword 0x7FFF @ color 1
	.hword 0x0000 @ color 2
	.hword 0x6718 @ color 3
	.hword 0x4B64 @ color 4
	.hword 0x5BAD @ color 5
	.hword 0x6BF6 @ color 6
	.hword 0x7F1A @ color 7
	.hword 0x7F9D @ color 8
	.hword 0x5AFF @ color 9
	.hword 0x6B7F @ color 10
	.hword 0x0257 @ color 11
	.hword 0x73BD @ color 12
	.hword 0x0000 @ color 13
	.hword 0x0000 @ color 14
	.hword 0x0000 @ color 15

	.globl gUnknown_85D74E8
gUnknown_85D74E8: @ 0x85D74E8
	.incbin "baserom_jp.gba", 0x5d74e8, 0x100

	.globl sPokenavIcon_Pal
sPokenavIcon_Pal: @ 0x85D75E8
	.hword 0x7FFF @ color 0
	.hword 0x1595 @ color 1
	.hword 0x4A55 @ color 2
	.hword 0x56B6 @ color 3
	.hword 0x001F @ color 4
	.hword 0x31FE @ color 5
	.hword 0x6694 @ color 6
	.hword 0x798C @ color 7
	.hword 0x7FFF @ color 8
	.hword 0x7EC1 @ color 9
	.hword 0x0000 @ color 10
	.hword 0x0000 @ color 11
	.hword 0x0000 @ color 12
	.hword 0x3B1F @ color 13
	.hword 0x6B39 @ color 14
	.hword 0x5EB5 @ color 15

	.globl gUnknown_85D7608
gUnknown_85D7608: @ 0x85D7608
	.incbin "baserom_jp.gba", 0x5d7608, 0x3e4

	.globl gUnknown_85D79EC
gUnknown_85D79EC: @ 0x85D79EC
	.string "⋯⋯⋯⋯⋯⋯\p$"

	.globl sMatchCallTaskFuncs
sMatchCallTaskFuncs: @ 0x85D79F4
	.4byte MatchCall_LoadGfx @ 0x08195D2D
	.4byte MatchCall_DrawWindow @ 0x08195DF1
	.4byte MatchCall_ReadyIntro @ 0x08195E75
	.4byte MatchCall_SlideWindowIn @ 0x08195EB1
	.4byte MatchCall_PrintIntro @ 0x08195ED9
	.4byte MatchCall_PrintMessage @ 0x08195F31
	.4byte MatchCall_SlideWindowOut @ 0x08195F91
	.4byte MatchCall_EndCall @ 0x08195FF1

	.globl sMatchCallTextWindow
sMatchCallTextWindow: @ 0x85D7A14
	.byte 0 @ bg
	.byte 1 @ tilemapLeft
	.byte 15 @ tilemapTop
	.byte 28 @ width
	.byte 4 @ height
	.byte 15 @ paletteNum
	.hword 0x0200 @ baseBlock

	.globl sMatchCallTextStringVars
sMatchCallTextStringVars: @ 0x85D7A1C
	.4byte gStringVar1
	.4byte gStringVar2
	.4byte gStringVar3

	.globl gUnknown_85D7A28
gUnknown_85D7A28: @ 0x85D7A28
	.string "どニのくベニのくドヌのくヘネのくuネのくけノのくナツ$クミ$ゲン$コウ$マリ$ミホ$　　"

	.globl sMultiTrainerMatchCallTexts
sMultiTrainerMatchCallTexts: @ 0x85D7A54
	.hword 0x0282 @ trainerId (US TRAINER_KIRA_AND_DAN_1)
	.hword 0
	.4byte 0x085D7A40 @ text (gText_* not yet symbolized)
	.hword 0x01E1 @ trainerId (US TRAINER_AMY_AND_LIV_1)
	.hword 0
	.4byte 0x085D7A43 @ text (gText_* not yet symbolized)
	.hword 0x02A9 @ trainerId (US TRAINER_JOHN_AND_JAY_1)
	.hword 0
	.4byte 0x085D7A46 @ text (gText_* not yet symbolized)
	.hword 0x02AF @ trainerId (US TRAINER_LILA_AND_ROY_1)
	.hword 0
	.4byte 0x085D7A49 @ text (gText_* not yet symbolized)
	.hword 0x0033 @ trainerId (US TRAINER_GABBY_AND_TY_1)
	.hword 0
	.4byte 0x085D7A4C @ text (gText_* not yet symbolized)
	.hword 0x011F @ trainerId (US TRAINER_ANNA_AND_MEG_1)
	.hword 0
	.4byte 0x085D7A4F @ text (gText_* not yet symbolized)

	.globl sBattleFrontierFacilityNames
sBattleFrontierFacilityNames: @ 0x85D7A84
	.4byte 0x085CC423 @ FRONTIER_FACILITY_TOWER (US gText_*)
	.4byte 0x085CC42A @ FRONTIER_FACILITY_DOME (US gText_*)
	.4byte 0x085CC431 @ FRONTIER_FACILITY_PALACE (US gText_*)
	.4byte 0x085CC442 @ FRONTIER_FACILITY_ARENA (US gText_*)
	.4byte 0x085CC44A @ MATCH_CALL_PIKE (US gText_*)
	.4byte 0x085CC438 @ MATCH_CALL_FACTORY (US gText_*)
	.4byte 0x085CC452 @ FRONTIER_FACILITY_PYRAMID (US gText_*)

	.globl sBadgeFlags
sBadgeFlags: @ 0x85D7AA0
	.hword 0x867 @ FLAG_BADGE01_GET
	.hword 0x868 @ FLAG_BADGE02_GET
	.hword 0x869 @ FLAG_BADGE03_GET
	.hword 0x86A @ FLAG_BADGE04_GET
	.hword 0x86B @ FLAG_BADGE05_GET
	.hword 0x86C @ FLAG_BADGE06_GET
	.hword 0x86D @ FLAG_BADGE07_GET
	.hword 0x86E @ FLAG_BADGE08_GET

	.globl sBirchDexRatingTexts
sBirchDexRatingTexts: @ 0x85D7AB0
	.4byte 0x08262E5F @ gBirchDexRatingText_LessThan10
	.4byte 0x08262E81 @ gBirchDexRatingText_LessThan20
	.4byte gBirchDexRatingText_LessThan30 @ gBirchDexRatingText_LessThan30
	.4byte 0x08262ECF @ gBirchDexRatingText_LessThan40
	.4byte 0x08262EF5 @ gBirchDexRatingText_LessThan50
	.4byte gBirchDexRatingText_LessThan60 @ gBirchDexRatingText_LessThan60
	.4byte 0x08262F3F @ gBirchDexRatingText_LessThan70
	.4byte 0x08262F61 @ gBirchDexRatingText_LessThan80
	.4byte gBirchDexRatingText_LessThan90 @ gBirchDexRatingText_LessThan90
	.4byte 0x08262FAD @ gBirchDexRatingText_LessThan100
	.4byte 0x08262FE1 @ gBirchDexRatingText_LessThan110
	.4byte gBirchDexRatingText_LessThan120 @ gBirchDexRatingText_LessThan120
	.4byte gBirchDexRatingText_LessThan130 @ gBirchDexRatingText_LessThan130
	.4byte gBirchDexRatingText_LessThan140 @ gBirchDexRatingText_LessThan140
	.4byte gBirchDexRatingText_LessThan150 @ gBirchDexRatingText_LessThan150
	.4byte 0x08263095 @ gBirchDexRatingText_LessThan160
	.4byte 0x082630C7 @ gBirchDexRatingText_LessThan170
	.4byte gBirchDexRatingText_LessThan180 @ gBirchDexRatingText_LessThan180
	.4byte gBirchDexRatingText_LessThan190 @ gBirchDexRatingText_LessThan190
	.4byte 0x0826312D @ gBirchDexRatingText_LessThan200
	.4byte 0x0826314F @ gBirchDexRatingText_LessThan210

	.globl gStandardMenuPalette
gStandardMenuPalette: @ 0x85D7B04
	.incbin "baserom_jp.gba", 0x5d7b04, 0x20

	.globl gUnknown_85D7B24
gUnknown_85D7B24: @ 0x85D7B24
	.incbin "baserom_jp.gba", 0x5d7b24, 0x4

	.globl gUnknown_85D7B28
gUnknown_85D7B28: @ 0x85D7B28
	.incbin "baserom_jp.gba", 0x5d7b28, 0x10

	.globl gUnknown_85D7B38
gUnknown_85D7B38: @ 0x85D7B38
	.incbin "baserom_jp.gba", 0x5d7b38, 0x8

	.globl gUnknown_85D7B40
gUnknown_85D7B40: @ 0x85D7B40
	.incbin "baserom_jp.gba", 0x5d7b40, 0x8

	.globl gUnknown_85D7B48
gUnknown_85D7B48: @ 0x85D7B48
	.incbin "baserom_jp.gba", 0x5d7b48, 0x20

	.globl gUnknown_85D7B68
gUnknown_85D7B68: @ 0x85D7B68
	.incbin "baserom_jp.gba", 0x5d7b68, 0x4

	.globl gUnknown_85D7B6C
gUnknown_85D7B6C: @ 0x85D7B6C
	.incbin "baserom_jp.gba", 0x5d7b6c, 0x4

	.globl gUnknown_85D7B70
gUnknown_85D7B70: @ 0x85D7B70
	.incbin "baserom_jp.gba", 0x5d7b70, 0x68

	.globl gUnknown_85D7BD8
gUnknown_85D7BD8: @ 0x85D7BD8
	.incbin "baserom_jp.gba", 0x5d7bd8, 0x20

	.globl gUnknown_85D7BF8
gUnknown_85D7BF8: @ 0x85D7BF8
	.incbin "baserom_jp.gba", 0x5d7bf8, 0x20

	.globl gUnknown_85D7C18
gUnknown_85D7C18: @ 0x85D7C18
	.incbin "baserom_jp.gba", 0x5d7c18, 0x20

	.globl gUnknown_85D7C38
gUnknown_85D7C38: @ 0x85D7C38
	.incbin "baserom_jp.gba", 0x5d7c38, 0x2000

	.globl gUnknown_85D9C38
gUnknown_85D9C38: @ 0x85D9C38
	.incbin "baserom_jp.gba", 0x5d9c38, 0x1100

	.globl gUnknown_85DAD38
gUnknown_85DAD38: @ 0x85DAD38
	.incbin "baserom_jp.gba", 0x5dad38, 0x440

	.globl gUnknown_85DB178
gUnknown_85DB178: @ 0x85DB178
	.incbin "baserom_jp.gba", 0x5db178, 0x800

	.globl gUnknown_85DB978
gUnknown_85DB978: @ 0x85DB978
	.incbin "baserom_jp.gba", 0x5db978, 0x100

	.globl gUnknown_85DBA78
gUnknown_85DBA78: @ 0x85DBA78
	.incbin "baserom_jp.gba", 0x5dba78, 0x60

	.globl gUnknown_85DBAD8
gUnknown_85DBAD8: @ 0x85DBAD8
	.incbin "baserom_jp.gba", 0x5dbad8, 0x40

	.globl gUnknown_85DBB18
gUnknown_85DBB18: @ 0x85DBB18
	.incbin "baserom_jp.gba", 0x5dbb18, 0x20

	.globl gUnknown_85DBB38
gUnknown_85DBB38: @ 0x85DBB38
	.incbin "baserom_jp.gba", 0x5dbb38, 0x28

	.globl gUnknown_85DBB60
gUnknown_85DBB60: @ 0x85DBB60
	.incbin "baserom_jp.gba", 0x5dbb60, 0x10

	.globl gUnknown_85DBB70
gUnknown_85DBB70: @ 0x85DBB70
	.incbin "baserom_jp.gba", 0x5dbb70, 0x28

	.globl gUnknown_85DBB98
gUnknown_85DBB98: @ 0x85DBB98
	.string "ポケモンレンタル$"

	.globl gUnknown_85DBBA1
gUnknown_85DBBA1: @ 0x85DBBA1
	.string "1ばんめのポケモンを　えらんでください$"
	.globl gUnknown_85DBBB5
gUnknown_85DBBB5: @ 0x85DBBB5
	.string "2ばんめのポケモンを　えらんでください$"
	.globl gUnknown_85DBBC9
gUnknown_85DBBC9: @ 0x85DBBC9
	.string "3ばんめのポケモンを　えらんでください$"
	.globl gUnknown_85DBBDD
gUnknown_85DBBDD: @ 0x85DBBDD
	.string "レンタルする$"
	.globl gUnknown_85DBBE4
gUnknown_85DBBE4: @ 0x85DBBE4
	.string "つよさをみる$"
	.globl gUnknown_85DBBEB
gUnknown_85DBBEB: @ 0x85DBBEB
	.string "べつのにする$"
	.globl gUnknown_85DBBF2
gUnknown_85DBBF2: @ 0x85DBBF2
	.string "はずす$"
	.globl gUnknown_85DBBF6
gUnknown_85DBBF6: @ 0x85DBBF6
	.string "いじょうの　3ひきで　よろしいですか？$"
	.globl gUnknown_85DBC0A
gUnknown_85DBC0A: @ 0x85DBC0A
	.string "はい$"
	.globl gUnknown_85DBC0D
gUnknown_85DBC0D: @ 0x85DBC0D
	.string "いいえ$"
	.globl gUnknown_85DBC11
gUnknown_85DBC11: @ 0x85DBC11
	.incbin "baserom_jp.gba", 0x5dbc11, 0x13

	.globl gUnknown_85DBC24
gUnknown_85DBC24: @ 0x85DBC24
	.incbin "baserom_jp.gba", 0x5dbc24, 0xc

	.globl gUnknown_85DBC30
gUnknown_85DBC30: @ 0x85DBC30
	.incbin "baserom_jp.gba", 0x5dbc30, 0xc

	.globl gUnknown_85DBC3C
gUnknown_85DBC3C: @ 0x85DBC3C
	.incbin "baserom_jp.gba", 0x5dbc3c, 0x38

	.globl gUnknown_85DBC74
gUnknown_85DBC74: @ 0x85DBC74
	.incbin "baserom_jp.gba", 0x5dbc74, 0xa

	.globl gUnknown_85DBC7E
gUnknown_85DBC7E: @ 0x85DBC7E
	.incbin "baserom_jp.gba", 0x5dbc7e, 0x3

	.globl gUnknown_85DBC81
gUnknown_85DBC81: @ 0x85DBC81
	.incbin "baserom_jp.gba", 0x5dbc81, 0x15f

	.globl gUnknown_85DBDE0
gUnknown_85DBDE0: @ 0x85DBDE0
	.incbin "baserom_jp.gba", 0x5dbde0, 0x18

	.globl gUnknown_85DBDF8
gUnknown_85DBDF8: @ 0x85DBDF8
	.incbin "baserom_jp.gba", 0x5dbdf8, 0x18

	.globl gUnknown_85DBE10
gUnknown_85DBE10: @ 0x85DBE10
	.incbin "baserom_jp.gba", 0x5dbe10, 0x18

	.globl gUnknown_85DBE28
gUnknown_85DBE28: @ 0x85DBE28
	.incbin "baserom_jp.gba", 0x5dbe28, 0x18

	.globl gUnknown_85DBE40
gUnknown_85DBE40: @ 0x85DBE40
	.incbin "baserom_jp.gba", 0x5dbe40, 0x18

	.globl gUnknown_85DBE58
gUnknown_85DBE58: @ 0x85DBE58
	.incbin "baserom_jp.gba", 0x5dbe58, 0x50

	.globl gUnknown_85DBEA8
gUnknown_85DBEA8: @ 0x85DBEA8
	.incbin "baserom_jp.gba", 0x5dbea8, 0x10

	.globl gUnknown_85DBEB8
gUnknown_85DBEB8: @ 0x85DBEB8
	.incbin "baserom_jp.gba", 0x5dbeb8, 0x184

	.globl gUnknown_85DC03C
gUnknown_85DC03C: @ 0x85DC03C
	.incbin "baserom_jp.gba", 0x5dc03c, 0x18

	.globl gUnknown_85DC054
gUnknown_85DC054: @ 0x85DC054
	.incbin "baserom_jp.gba", 0x5dc054, 0x18

	.globl gUnknown_85DC06C
gUnknown_85DC06C: @ 0x85DC06C
	.incbin "baserom_jp.gba", 0x5dc06c, 0x18

	.globl gUnknown_85DC084
gUnknown_85DC084: @ 0x85DC084
	.incbin "baserom_jp.gba", 0x5dc084, 0x18

	.globl gUnknown_85DC09C
gUnknown_85DC09C: @ 0x85DC09C
	.incbin "baserom_jp.gba", 0x5dc09c, 0x18

	.globl gUnknown_85DC0B4
gUnknown_85DC0B4: @ 0x85DC0B4
	.string "ポケモンこうかん　　　　　$"
	.globl gUnknown_85DC0C2
gUnknown_85DC0C2: @ 0x85DC0C2
	.string "てばなすポケモンを　えらんでください$"
	.globl gUnknown_85DC0D5
gUnknown_85DC0D5: @ 0x85DC0D5
	.string "うけとるポケモンを　えらんでください$"
	.globl gUnknown_85DC0E8
gUnknown_85DC0E8: @ 0x85DC0E8
	.string "てばなす$"
	.globl gUnknown_85DC0ED
gUnknown_85DC0ED: @ 0x85DC0ED
	.string "つよさをみる$"
	.globl gUnknown_85DC0F4
gUnknown_85DC0F4: @ 0x85DC0F4
	.string "べつのにする$"
	.globl gUnknown_85DC0FB
gUnknown_85DC0FB: @ 0x85DC0FB
	.string "こうかんを　ちゅうし　しますか？$"
	.globl gUnknown_85DC10C
gUnknown_85DC10C: @ 0x85DC10C
	.string "はい$"
	.globl gUnknown_85DC10F
gUnknown_85DC10F: @ 0x85DC10F
	.string "いいえ$"
	.globl gUnknown_85DC113
gUnknown_85DC113: @ 0x85DC113
	.string "てばなすポケモン$"
	.globl gUnknown_85DC11C
gUnknown_85DC11C: @ 0x85DC11C
	.string "ちゅうし$"
	.globl gUnknown_85DC121
gUnknown_85DC121: @ 0x85DC121
	.string "てばなす$"
	.globl gUnknown_85DC126
gUnknown_85DC126: @ 0x85DC126
	.string "うけとる$"
	.globl gUnknown_85DC12B
gUnknown_85DC12B: @ 0x85DC12B
	.string "このポケモンを　うけとりますか？$"
	.globl gUnknown_85DC13C
gUnknown_85DC13C: @ 0x85DC13C
	.string "　　　　$"
	.globl gUnknown_85DC141
gUnknown_85DC141: @ 0x85DC141
	.incbin "baserom_jp.gba", 0x5dc141, 0x17

	.globl gUnknown_85DC158
gUnknown_85DC158: @ 0x85DC158
	.incbin "baserom_jp.gba", 0x5dc158, 0xc

	.globl gUnknown_85DC164
gUnknown_85DC164: @ 0x85DC164
	.incbin "baserom_jp.gba", 0x5dc164, 0x10

	.globl gUnknown_85DC174
gUnknown_85DC174: @ 0x85DC174
	.incbin "baserom_jp.gba", 0x5dc174, 0x50

	.globl gUnknown_85DC1C4
gUnknown_85DC1C4: @ 0x85DC1C4
	.incbin "baserom_jp.gba", 0x5dc1c4, 0xa

	.globl gUnknown_85DC1CE
gUnknown_85DC1CE: @ 0x85DC1CE
	.incbin "baserom_jp.gba", 0x5dc1ce, 0x3

	.globl gUnknown_85DC1D1
gUnknown_85DC1D1: @ 0x85DC1D1
	.incbin "baserom_jp.gba", 0x5dc1d1, 0x3

	.globl gUnknown_85DC1D4
gUnknown_85DC1D4: @ 0x85DC1D4
	.incbin "baserom_jp.gba", 0x5dc1d4, 0x20

	.globl gUnknown_85DC1F4
gUnknown_85DC1F4: @ 0x85DC1F4
	.incbin "baserom_jp.gba", 0x5dc1f4, 0x28

	.globl gUnknown_85DC21C
gUnknown_85DC21C: @ 0x85DC21C
	.incbin "baserom_jp.gba", 0x5dc21c, 0xc

	.globl gUnknown_85DC228
gUnknown_85DC228: @ 0x85DC228
	.incbin "baserom_jp.gba", 0x5dc228, 0x16

	.globl gUnknown_85DC23E
gUnknown_85DC23E: @ 0x85DC23E
	.incbin "baserom_jp.gba", 0x5dc23e, 0x2de

	.globl gUnknown_85DC51C
gUnknown_85DC51C: @ 0x85DC51C
	.incbin "baserom_jp.gba", 0x5dc51c, 0x100

	.globl gUnknown_85DC61C
gUnknown_85DC61C: @ 0x85DC61C
	.incbin "baserom_jp.gba", 0x5dc61c, 0x80

	.globl gUnknown_85DC69C
gUnknown_85DC69C: @ 0x85DC69C
	.incbin "baserom_jp.gba", 0x5dc69c, 0x140

	.globl gUnknown_85DC7DC
gUnknown_85DC7DC: @ 0x85DC7DC
	.incbin "baserom_jp.gba", 0x5dc7dc, 0x80

	.globl gUnknown_85DC85C
gUnknown_85DC85C: @ 0x85DC85C
	.incbin "baserom_jp.gba", 0x5dc85c, 0x80

	.globl gUnknown_85DC8DC
gUnknown_85DC8DC: @ 0x85DC8DC
	.incbin "baserom_jp.gba", 0x5dc8dc, 0x80

	.globl gUnknown_85DC95C
gUnknown_85DC95C: @ 0x85DC95C
	.incbin "baserom_jp.gba", 0x5dc95c, 0x40

	.globl gUnknown_85DC99C
gUnknown_85DC99C: @ 0x85DC99C
	.incbin "baserom_jp.gba", 0x5dc99c, 0x163

	.globl gUnknown_85DCAFF
gUnknown_85DCAFF: @ 0x85DCAFF
	.incbin "baserom_jp.gba", 0x5dcaff, 0xd

	.globl gUnknown_85DCB0C
gUnknown_85DCB0C: @ 0x85DCB0C
	.incbin "baserom_jp.gba", 0x5dcb0c, 0x68

	.globl gUnknown_85DCB74
gUnknown_85DCB74: @ 0x85DCB74
	.incbin "baserom_jp.gba", 0x5dcb74, 0x8

	.globl gUnknown_85DCB7C
gUnknown_85DCB7C: @ 0x85DCB7C
	.incbin "baserom_jp.gba", 0x5dcb7c, 0x1c

	.globl gUnknown_85DCB98
gUnknown_85DCB98: @ 0x85DCB98
	.incbin "baserom_jp.gba", 0x5dcb98, 0xc

	.globl gUnknown_85DCBA4
gUnknown_85DCBA4: @ 0x85DCBA4
	.incbin "baserom_jp.gba", 0x5dcba4, 0x33c

	.globl gUnknown_85DCEE0
gUnknown_85DCEE0: @ 0x85DCEE0
	.incbin "baserom_jp.gba", 0x5dcee0, 0x348

	.globl gUnknown_85DD228
gUnknown_85DD228: @ 0x85DD228
	.incbin "baserom_jp.gba", 0x5dd228, 0x1c

	.globl gUnknown_85DD244
gUnknown_85DD244: @ 0x85DD244
	.incbin "baserom_jp.gba", 0x5dd244, 0x5c

	.globl gUnknown_85DD2A0
gUnknown_85DD2A0: @ 0x85DD2A0
	.incbin "baserom_jp.gba", 0x5dd2a0, 0x8

	.globl gUnknown_85DD2A8
gUnknown_85DD2A8: @ 0x85DD2A8
	.incbin "baserom_jp.gba", 0x5dd2a8, 0x8

	.globl gUnknown_85DD2B0
gUnknown_85DD2B0: @ 0x85DD2B0
	.incbin "baserom_jp.gba", 0x5dd2b0, 0x8

	.globl gUnknown_85DD2B8
gUnknown_85DD2B8: @ 0x85DD2B8
	.incbin "baserom_jp.gba", 0x5dd2b8, 0x8

	.globl gUnknown_85DD2C0
gUnknown_85DD2C0: @ 0x85DD2C0
	.incbin "baserom_jp.gba", 0x5dd2c0, 0x8

	.globl gUnknown_85DD2C8
gUnknown_85DD2C8: @ 0x85DD2C8
	.incbin "baserom_jp.gba", 0x5dd2c8, 0x8

	.globl gUnknown_85DD2D0
gUnknown_85DD2D0: @ 0x85DD2D0
	.incbin "baserom_jp.gba", 0x5dd2d0, 0x8

	.globl gUnknown_85DD2D8
gUnknown_85DD2D8: @ 0x85DD2D8
	.incbin "baserom_jp.gba", 0x5dd2d8, 0x8

	.globl gUnknown_85DD2E0
gUnknown_85DD2E0: @ 0x85DD2E0
	.incbin "baserom_jp.gba", 0x5dd2e0, 0x8

	.globl gUnknown_85DD2E8
gUnknown_85DD2E8: @ 0x85DD2E8
	.string "ーーー$"

	.globl gUnknown_85DD2EC
gUnknown_85DD2EC: @ 0x85DD2EC
	.string "　{MUS_RG_VS_TRAINER}　の　シングル　バトルルーム　せいせき$"
	.globl gUnknown_85DD303
gUnknown_85DD303: @ 0x85DD303
	.string "　　{MUS_RG_VS_TRAINER}　の　ダブル　バトルルーム　せいせき$"
	.globl gUnknown_85DD31A
gUnknown_85DD31A: @ 0x85DD31A
	.string "　　{MUS_RG_VS_TRAINER}　の　マルチ　バトルルーム　せいせき$"
	.globl gUnknown_85DD331
gUnknown_85DD331: @ 0x85DD331
	.string "{MUS_RG_VS_TRAINER}　の　つうしんマルチ　バトルルーム　せいせき$"
	.globl gUnknown_85DD34A
gUnknown_85DD34A: @ 0x85DD34A
	.string "{MUS_RG_VS_TRAINER}　の　シングル　バトルトーナメント　せいせき$"
	.globl gUnknown_85DD363
gUnknown_85DD363: @ 0x85DD363
	.string "{MUS_RG_VS_TRAINER}　の　ダブル　バトルトーナメント　せいせき$"
	.globl gUnknown_85DD37B
gUnknown_85DD37B: @ 0x85DD37B
	.string "{MUS_RG_VS_TRAINER}　の　シングル　バトルホール　せいせき$"
	.globl gUnknown_85DD391
gUnknown_85DD391: @ 0x85DD391
	.string "{MUS_RG_VS_TRAINER}　の　ダブル　バトルホール　せいせき$"
	.globl gUnknown_85DD3A6
gUnknown_85DD3A6: @ 0x85DD3A6
	.string "{MUS_RG_VS_TRAINER}　の　バトルゲーム　せいせき$"
	.globl gUnknown_85DD3B7
gUnknown_85DD3B7: @ 0x85DD3B7
	.string "{MUS_RG_VS_TRAINER}　の　かちぬきチームバトル　せいせき$"
	.globl gUnknown_85DD3CC
gUnknown_85DD3CC: @ 0x85DD3CC
	.string "{MUS_RG_VS_TRAINER}　の　バトルトレード　シングル　せいせき$"
	.globl gUnknown_85DD3E3
gUnknown_85DD3E3: @ 0x85DD3E3
	.string "{MUS_RG_VS_TRAINER}　の　バトルトレード　ダブル　せいせき$"
	.globl gUnknown_85DD3F9
gUnknown_85DD3F9: @ 0x85DD3F9
	.string "{MUS_RG_VS_TRAINER}　の　バトルアドベンチャー　せいせき$"
	.globl gUnknown_85DD40E
gUnknown_85DD40E: @ 0x85DD40E
	.string "レベル　50$"
	.globl gUnknown_85DD415
gUnknown_85DD415: @ 0x85DD415
	.string "オープンレベル$"

	.globl gUnknown_85DD41D
gUnknown_85DD41D: @ 0x85DD41D
	.string "{B_COPY_VAR_1}れんしょう$"
	.globl gUnknown_85DD425
gUnknown_85DD425: @ 0x85DD425
	.string "げんざい$"
	.globl gUnknown_85DD42A
gUnknown_85DD42A: @ 0x85DD42A
	.string "さいこう$"
	.globl gUnknown_85DD42F
gUnknown_85DD42F: @ 0x85DD42F
	.string "ぜんかい$バトル$"
	.globl gUnknown_85DD438
gUnknown_85DD438: @ 0x85DD438
	.string "レンタル/こうかん$"
	.globl gUnknown_85DD442
gUnknown_85DD442: @ 0x85DD442
	.string "つうさん$"
	.globl gUnknown_85DD447
gUnknown_85DD447: @ 0x85DD447
	.string "{B_COPY_VAR_1}れんぱ$"

	.globl gUnknown_85DD44D
gUnknown_85DD44D: @ 0x85DD44D
	.string "{B_COPY_VAR_1}かい　ゆうしょう$"
	.globl gUnknown_85DD458
gUnknown_85DD458: @ 0x85DD458
	.string "{B_COPY_VAR_1}へや　とっぱ$"
	.globl gUnknown_85DD461
gUnknown_85DD461: @ 0x85DD461
	.string "{B_COPY_VAR_1}かい　クリア$"
	.globl gUnknown_85DD46A
gUnknown_85DD46A: @ 0x85DD46A
	.string "{B_COPY_VAR_1}にんぬき$"
	.globl gUnknown_85DD471
gUnknown_85DD471: @ 0x85DD471
	.string "{B_COPY_VAR_1}かい$"
	.globl gUnknown_85DD476
gUnknown_85DD476: @ 0x85DD476
	.string "{B_COPY_VAR_1}だん　せいは$"
	.globl gUnknown_85DD47F
gUnknown_85DD47F: @ 0x85DD47F
	.incbin "baserom_jp.gba", 0x5dd47f, 0xf

	.globl gUnknown_85DD48E
gUnknown_85DD48E: @ 0x85DD48E
	.string "ビ　バ　\l"
	.string "　{UP_ARROW_2}\p"
	.string "　デあドあバあベあボあ$$"
	.globl gUnknown_85DD4A4
gUnknown_85DD4A4: @ 0x85DD4A4
	.string "もJシくシJシくもJシくトJシくもJシくフJシくれJシくシJシくぅJシくシJシくぢJシくワJシくぎJシくシJシくぼJシくワJシくイJシくワJシくもJシくヤJシく　レベル50$　オープンレベル$"
	.globl gUnknown_85DD504
gUnknown_85DD504: @ 0x85DD504
	.incbin "baserom_jp.gba", 0x5dd504, 0x38

	.globl gUnknown_85DD53C
gUnknown_85DD53C: @ 0x85DD53C
	.incbin "baserom_jp.gba", 0x5dd53c, 0x28

	.globl gUnknown_85DD564
gUnknown_85DD564: @ 0x85DD564
	.string "1$2$3$"

	.globl gUnknown_85DD56A
gUnknown_85DD56A: @ 0x85DD56A
	.incbin "baserom_jp.gba", 0x5dd56a, 0x7e

	.globl gUnknown_85DD5E8
gUnknown_85DD5E8: @ 0x85DD5E8
	.incbin "baserom_jp.gba", 0x5dd5e8, 0x8

	.globl gUnknown_85DD5F0
gUnknown_85DD5F0: @ 0x85DD5F0
	.incbin "baserom_jp.gba", 0x5dd5f0, 0x8

	.globl gUnknown_85DD5F8
gUnknown_85DD5F8: @ 0x85DD5F8
	.incbin "baserom_jp.gba", 0x5dd5f8, 0x19c

	.globl gUnknown_85DD794
gUnknown_85DD794: @ 0x85DD794
	.incbin "baserom_jp.gba", 0x5dd794, 0x18

	.globl gUnknown_85DD7AC
gUnknown_85DD7AC: @ 0x85DD7AC
	.incbin "baserom_jp.gba", 0x5dd7ac, 0x10

	.globl gUnknown_85DD7BC
gUnknown_85DD7BC: @ 0x85DD7BC
	.incbin "baserom_jp.gba", 0x5dd7bc, 0x1c

	.globl gUnknown_85DD7D8
gUnknown_85DD7D8: @ 0x85DD7D8
	.incbin "baserom_jp.gba", 0x5dd7d8, 0xc

	.globl gUnknown_85DD7E4
gUnknown_85DD7E4: @ 0x85DD7E4
	.incbin "baserom_jp.gba", 0x5dd7e4, 0x14

	.globl gUnknown_85DD7F8
gUnknown_85DD7F8: @ 0x85DD7F8
	.incbin "baserom_jp.gba", 0x5dd7f8, 0x144

	.globl gUnknown_85DD93C
gUnknown_85DD93C: @ 0x85DD93C
	.incbin "baserom_jp.gba", 0x5dd93c, 0x1c

	.globl gUnknown_85DD958
gUnknown_85DD958: @ 0x85DD958
	.incbin "baserom_jp.gba", 0x5dd958, 0x44

	.globl gUnknown_85DD99C
gUnknown_85DD99C: @ 0x85DD99C
	.incbin "baserom_jp.gba", 0x5dd99c, 0x10

	.globl gUnknown_85DD9AC
gUnknown_85DD9AC: @ 0x85DD9AC
	.string "$\n$$${STRING}$$$$$\n$$${STRING}"

	.globl gUnknown_85DD9BC
gUnknown_85DD9BC: @ 0x85DD9BC
	.incbin "baserom_jp.gba", 0x5dd9bc, 0x10

	.globl gUnknown_85DD9CC
gUnknown_85DD9CC: @ 0x85DD9CC
	.incbin "baserom_jp.gba", 0x5dd9cc, 0x180

	.globl gUnknown_85DDB4C
gUnknown_85DDB4C: @ 0x85DDB4C
	.incbin "baserom_jp.gba", 0x5ddb4c, 0x8

	.globl gUnknown_85DDB54
gUnknown_85DDB54: @ 0x85DDB54
	.incbin "baserom_jp.gba", 0x5ddb54, 0xc8

	.globl gUnknown_85DDC1C
gUnknown_85DDC1C: @ 0x85DDC1C
	.incbin "baserom_jp.gba", 0x5ddc1c, 0x1f8

	.globl gUnknown_85DDE14
gUnknown_85DDE14: @ 0x85DDE14
	.incbin "baserom_jp.gba", 0x5dde14, 0x1c

	.globl gUnknown_85DDE30
gUnknown_85DDE30: @ 0x85DDE30
	.incbin "baserom_jp.gba", 0x5dde30, 0x74

	.globl gUnknown_85DDEA4
gUnknown_85DDEA4: @ 0x85DDEA4
	.incbin "baserom_jp.gba", 0x5ddea4, 0x9

	.globl gUnknown_85DDEAD
gUnknown_85DDEAD: @ 0x85DDEAD
	.incbin "baserom_jp.gba", 0x5ddead, 0x13

	.globl gUnknown_85DDEC0
gUnknown_85DDEC0: @ 0x85DDEC0
	.incbin "baserom_jp.gba", 0x5ddec0, 0x8

	.globl gUnknown_85DDEC8
gUnknown_85DDEC8: @ 0x85DDEC8
	.incbin "baserom_jp.gba", 0x5ddec8, 0x8

	.globl sMovement_ShiftRight
sMovement_ShiftRight: @ 0x85DDED0
	.byte 0x94, 0x0B, 0x95, 0xFE

	.globl sMovement_ShiftDown
sMovement_ShiftDown: @ 0x85DDED4
	.byte 0x94, 0x08, 0x95, 0xFE

	.globl sMovement_ShiftLeft
sMovement_ShiftLeft: @ 0x85DDED8
	.byte 0x94, 0x0A, 0x95, 0xFE

	.globl sMovement_ShiftUp
sMovement_ShiftUp: @ 0x85DDEDC
	.byte 0x94, 0x09, 0x95, 0xFE

	.globl sMovement_FaceRight
sMovement_FaceRight: @ 0x85DDEE0
	.byte 0x03, 0xFE

	.globl sMovement_FaceDown
sMovement_FaceDown: @ 0x85DDEE2
	.byte 0x00, 0xFE

	.globl sMovement_FaceLeft
sMovement_FaceLeft: @ 0x85DDEE4
	.byte 0x02, 0xFE

	.globl sMovement_FaceUp
sMovement_FaceUp: @ 0x85DDEE6
	.byte 0x01, 0xFE, 0x61, 0x01, 0x23, 0x02, 0x56, 0x00, 0xD1, 0x00, 0xE3, 0x00
	.byte 0x00, 0x00, 0x62, 0x01, 0x23, 0x02, 0x56, 0x00, 0x55, 0x00, 0x62, 0x00
	.byte 0x00, 0x00, 0x19, 0x00, 0x25, 0x02, 0x56, 0x00, 0x55, 0x00, 0x15, 0x00
	.byte 0x00, 0x00, 0x7D, 0x00, 0x25, 0x02, 0x09, 0x00, 0x81, 0x00, 0x67, 0x00
	.byte 0x00, 0x00, 0x2D, 0x00, 0x27, 0x02, 0x4E, 0x00, 0xCA, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x52, 0x01, 0x27, 0x02, 0x56, 0x00, 0x57, 0x00, 0x62, 0x00
	.byte 0x00, 0x00, 0x33, 0x01, 0x28, 0x02, 0x4E, 0x00, 0x08, 0x01, 0xCA, 0x00
	.byte 0xB7, 0x00, 0x87, 0x00, 0x28, 0x02, 0x56, 0x00, 0x57, 0x00, 0x2A, 0x00
	.byte 0x62, 0x00, 0x6F, 0x01, 0x24, 0x02, 0x5C, 0x00, 0x7C, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x6B, 0x01, 0x24, 0x02, 0x5C, 0x00, 0xCA, 0x00, 0x59, 0x01
	.byte 0x50, 0x00, 0x0C, 0x00, 0x26, 0x02, 0x4D, 0x00, 0x10, 0x00, 0x3C, 0x00
	.byte 0x00, 0x00, 0x7B, 0x01, 0x26, 0x02, 0x31, 0x01, 0xCF, 0x00, 0xF2, 0x00
	.byte 0x56, 0x01, 0xE3, 0x00, 0x28, 0x02, 0x5C, 0x00, 0x13, 0x00, 0xD3, 0x00
	.byte 0x00, 0x00, 0x29, 0x01, 0x28, 0x01, 0x5C, 0x00, 0xB6, 0x00, 0x23, 0x01
	.byte 0xF0, 0x00, 0xA9, 0x00, 0x29, 0x02, 0x5C, 0x00, 0x6D, 0x00, 0xD4, 0x00
	.byte 0x2C, 0x00, 0x5E, 0x00, 0x29, 0x02, 0x5C, 0x00, 0x45, 0x01, 0x65, 0x00
	.byte 0x00, 0x00, 0x3A, 0x00, 0x25, 0x02, 0xAC, 0x00, 0x24, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x25, 0x00, 0x25, 0x02, 0x05, 0x01, 0x35, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xDB, 0x00, 0x27, 0x01, 0x35, 0x00, 0x9D, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x26, 0x00, 0x27, 0x02, 0x05, 0x01, 0x62, 0x00, 0x35, 0x00
	.byte 0x00, 0x00, 0x65, 0x01, 0x29, 0x02, 0x07, 0x00, 0x88, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x6E, 0x00, 0x29, 0x02, 0x05, 0x01, 0x35, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x6A, 0x01, 0x2A, 0x02, 0x05, 0x01, 0x6D, 0x00, 0xD4, 0x00
	.byte 0x45, 0x01, 0xE5, 0x00, 0x2A, 0x02, 0x35, 0x00, 0x2C, 0x00, 0x4C, 0x00
	.byte 0x3B, 0x01, 0xCE, 0x00, 0x2A, 0x02, 0xB4, 0x00, 0x5C, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x7A, 0x01, 0x29, 0x02, 0x20, 0x01, 0x05, 0x01, 0x65, 0x00
	.byte 0x00, 0x00, 0xC8, 0x00, 0x2A, 0x02, 0x20, 0x01, 0xB4, 0x00, 0xF7, 0x00
	.byte 0x00, 0x00, 0x26, 0x00, 0x2A, 0x02, 0x20, 0x01, 0x05, 0x01, 0x3B, 0x01
	.byte 0x00, 0x00, 0x78, 0x01, 0x2C, 0x02, 0x2C, 0x00, 0x4C, 0x01, 0xF7, 0x00
	.byte 0xB6, 0x00, 0x6A, 0x01, 0x2C, 0x02, 0x05, 0x01, 0xB6, 0x00, 0x5C, 0x00
	.byte 0xF7, 0x00, 0x2F, 0x01, 0x2D, 0x02, 0x20, 0x01, 0x5C, 0x00, 0xB4, 0x00
	.byte 0x00, 0x00, 0x5E, 0x00, 0x2D, 0x02, 0x20, 0x01, 0xB4, 0x00, 0x65, 0x00
	.byte 0x00, 0x00, 0x5D, 0x00, 0x29, 0x02, 0x65, 0x00, 0x55, 0x00, 0xBC, 0x00
	.byte 0x00, 0x00, 0x9B, 0x01, 0x29, 0x02, 0x26, 0x00, 0x5C, 0x00, 0x5E, 0x00
	.byte 0xB6, 0x00, 0x5D, 0x01, 0x2A, 0x02, 0x59, 0x00, 0x9D, 0x00, 0x7E, 0x00
	.byte 0x5C, 0x00, 0xC8, 0x00, 0x2A, 0x02, 0x5E, 0x00, 0xB4, 0x00, 0xF7, 0x00
	.byte 0xDC, 0x00, 0x3F, 0x01, 0x2C, 0x02, 0x59, 0x00, 0xF6, 0x00, 0x78, 0x00
	.byte 0x5E, 0x00, 0x6E, 0x00, 0x2C, 0x02, 0xBC, 0x00, 0x78, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x4E, 0x01, 0x2D, 0x02, 0x59, 0x00, 0xF2, 0x00, 0x51, 0x01
	.byte 0xE1, 0x00, 0x5E, 0x00, 0x2D, 0x02, 0x55, 0x00, 0x5E, 0x00, 0xCA, 0x00
	.byte 0x65, 0x00, 0x32, 0x00, 0x29, 0x02, 0x9D, 0x00, 0xA3, 0x00, 0x5B, 0x00
	.byte 0x00, 0x00, 0x4C, 0x01, 0x29, 0x02, 0x9D, 0x00, 0x59, 0x00, 0xCA, 0x00
	.byte 0x00, 0x00, 0x68, 0x01, 0x2A, 0x00, 0xC2, 0x00, 0x96, 0x00, 0x44, 0x00
	.byte 0xF3, 0x00, 0x32, 0x00, 0x2A, 0x02, 0x59, 0x00, 0x9D, 0x00, 0xDE, 0x00
	.byte 0x5C, 0x00, 0x4C, 0x01, 0x2C, 0x02, 0x9D, 0x00, 0x59, 0x00, 0xCA, 0x00
	.byte 0xB6, 0x00, 0x68, 0x01, 0x2C, 0x00, 0x44, 0x00, 0xF3, 0x00, 0xC2, 0x00
	.byte 0x00, 0x00, 0xCA, 0x00, 0x2D, 0x00, 0x44, 0x00, 0xF3, 0x00, 0xC2, 0x00
	.byte 0x00, 0x00, 0x33, 0x00, 0x2D, 0x01, 0x9D, 0x00, 0xBC, 0x00, 0x59, 0x00
	.byte 0xB6, 0x00, 0x5B, 0x01, 0x29, 0x02, 0x3A, 0x00, 0xF2, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0xD7, 0x00, 0x29, 0x02, 0x3A, 0x00, 0x32, 0x01, 0xB4, 0x00
	.byte 0x00, 0x00, 0x57, 0x00, 0x2A, 0x02, 0x3B, 0x00, 0x26, 0x00, 0x39, 0x00
	.byte 0x00, 0x00, 0xDD, 0x00, 0x2A, 0x02, 0x3A, 0x00, 0x59, 0x00, 0x5C, 0x00
	.byte 0x00, 0x00, 0x7C, 0x00, 0x2C, 0x02, 0x3B, 0x00, 0x8E, 0x00, 0x5E, 0x00
	.byte 0x00, 0x00, 0x5B, 0x00, 0x2C, 0x02, 0x3A, 0x00, 0x39, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x57, 0x01, 0x2D, 0x02, 0x3B, 0x00, 0x22, 0x00, 0x39, 0x00
	.byte 0x00, 0x00, 0x83, 0x00, 0x2D, 0x02, 0x2F, 0x00, 0x22, 0x00, 0x3A, 0x00
	.byte 0x5E, 0x00, 0x6E, 0x00, 0x29, 0x02, 0x78, 0x00, 0xBC, 0x00, 0x7E, 0x00
	.byte 0x00, 0x00, 0x65, 0x00, 0x29, 0x02, 0x78, 0x00, 0x55, 0x00, 0xCD, 0x00
	.byte 0x00, 0x00, 0x5E, 0x00, 0x2A, 0x02, 0xC2, 0x00, 0x7A, 0x00, 0xF7, 0x00
	.byte 0x00, 0x00, 0x4C, 0x00, 0x2A, 0x02, 0x78, 0x00, 0xB6, 0x00, 0x59, 0x00
	.byte 0x00, 0x00, 0xCC, 0x00, 0x2C, 0x02, 0x99, 0x00, 0x26, 0x00, 0xCA, 0x00
	.byte 0x00, 0x00, 0x5D, 0x01, 0x2C, 0x02, 0x99, 0x00, 0x53, 0x00, 0x95, 0x00
	.byte 0x00, 0x00, 0xCD, 0x00, 0x2D, 0x02, 0x99, 0x00, 0x5C, 0x00, 0x9D, 0x00
	.byte 0x00, 0x00, 0x2C, 0x01, 0x2D, 0x02, 0x99, 0x00, 0xCA, 0x00, 0x4C, 0x00
	.byte 0xB6, 0x00, 0xCA, 0x00, 0x29, 0x02, 0x44, 0x00, 0xF3, 0x00, 0xDB, 0x00
	.byte 0xC2, 0x00, 0x8F, 0x01, 0x29, 0x02, 0x59, 0x00, 0x5C, 0x00, 0xBC, 0x00
	.byte 0x5E, 0x00, 0x67, 0x00, 0x2A, 0x02, 0x79, 0x00, 0x5E, 0x00, 0x5F, 0x00
	.byte 0x00, 0x00, 0xC7, 0x00, 0x2A, 0x02, 0xF7, 0x00, 0x39, 0x00, 0x3A, 0x00
	.byte 0x35, 0x00, 0xB2, 0x00, 0x2C, 0x02, 0x6D, 0x00, 0xF7, 0x00, 0x5E, 0x00
	.byte 0xD3, 0x00, 0x41, 0x00, 0x2C, 0x02, 0x5E, 0x00, 0x07, 0x00, 0x08, 0x00
	.byte 0x5C, 0x00, 0x79, 0x00, 0x2D, 0x02, 0x5E, 0x00, 0x55, 0x00, 0x39, 0x00
	.byte 0x3A, 0x00, 0xC4, 0x00, 0x2D, 0x02, 0x5E, 0x00, 0x5B, 0x00, 0xF7, 0x00
	.byte 0x00, 0x00, 0x4C, 0x00, 0x29, 0x02, 0x78, 0x00, 0x59, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0xD0, 0x00, 0x29, 0x02, 0xE7, 0x00, 0xF2, 0x00, 0x59, 0x00
	.byte 0x00, 0x00, 0x8B, 0x00, 0x2A, 0x02, 0x39, 0x00, 0x55, 0x01, 0xF6, 0x00
	.byte 0x00, 0x00, 0x5C, 0x01, 0x2A, 0x02, 0x5F, 0x00, 0x95, 0x00, 0x99, 0x00
	.byte 0x00, 0x00, 0xD5, 0x00, 0x2C, 0x02, 0x5C, 0x00, 0xB6, 0x00, 0x23, 0x00
	.byte 0x00, 0x00, 0x87, 0x01, 0x2C, 0x02, 0xF6, 0x00, 0xB6, 0x00, 0x4C, 0x01
	.byte 0x00, 0x00, 0x85, 0x01, 0x2D, 0x02, 0xBC, 0x00, 0xCA, 0x00, 0x6D, 0x00
	.byte 0x00, 0x00, 0x8E, 0x00, 0x2D, 0x02, 0x3F, 0x00, 0x9D, 0x00, 0x2C, 0x00
	.byte 0x00, 0x00, 0x3E, 0x00, 0x29, 0x02, 0x42, 0x00, 0x08, 0x01, 0x39, 0x00
	.byte 0x00, 0x00, 0x50, 0x01, 0x29, 0x02, 0xFC, 0x00, 0x39, 0x00, 0x08, 0x01
	.byte 0x00, 0x00, 0x33, 0x01, 0x2A, 0x02, 0x93, 0x00, 0x08, 0x01, 0xB6, 0x00
	.byte 0x00, 0x00, 0x65, 0x01, 0x2A, 0x02, 0x09, 0x00, 0x07, 0x00, 0x08, 0x00
	.byte 0x08, 0x01, 0x6B, 0x00, 0x2C, 0x02, 0x09, 0x00, 0x07, 0x00, 0x08, 0x00
	.byte 0x08, 0x01, 0x6A, 0x00, 0x2C, 0x02, 0x19, 0x00, 0x08, 0x01, 0x00, 0x00
	.byte 0x00, 0x00, 0xD6, 0x00, 0x2D, 0x02, 0xE0, 0x00, 0x59, 0x00, 0x08, 0x01
	.byte 0x9D, 0x00, 0x44, 0x00, 0x32, 0x02, 0x9D, 0x00, 0x59, 0x00, 0x08, 0x01
	.byte 0x45, 0x00, 0xC3, 0x00, 0x29, 0x02, 0xF0, 0x00, 0x39, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x71, 0x01, 0x29, 0x02, 0xF1, 0x00, 0x4C, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xF7, 0x00, 0x2A, 0x02, 0xC9, 0x00, 0x59, 0x00, 0x9D, 0x00
	.byte 0x00, 0x00, 0x83, 0x00, 0x2A, 0x02, 0x02, 0x01, 0x3A, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x59, 0x01, 0x2C, 0x02, 0xC9, 0x00, 0xCA, 0x00, 0x4C, 0x00
	.byte 0x00, 0x00, 0x88, 0x00, 0x2C, 0x02, 0xF1, 0x00, 0x35, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x57, 0x01, 0x2D, 0x02, 0x02, 0x01, 0x3A, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x82, 0x00, 0x32, 0x02, 0xF0, 0x00, 0x57, 0x00, 0x38, 0x00
	.byte 0x00, 0x00, 0xCC, 0x00, 0x2A, 0x02, 0x99, 0x00, 0x24, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xD5, 0x00, 0x2A, 0x02, 0x5C, 0x00, 0x59, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x31, 0x00, 0x2E, 0x02, 0x3E, 0x01, 0x4D, 0x00, 0x4F, 0x00
	.byte 0x5E, 0x00, 0xD4, 0x00, 0x2E, 0x02, 0x62, 0x00, 0xE8, 0x00, 0xD2, 0x00
	.byte 0xE4, 0x00, 0xD6, 0x00, 0x30, 0x02, 0xE0, 0x00, 0x18, 0x01, 0x59, 0x00
	.byte 0x9D, 0x00, 0xCD, 0x00, 0x30, 0x02, 0x99, 0x00, 0x59, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x87, 0x01, 0x32, 0x02, 0x60, 0x01, 0xB6, 0x00, 0x9D, 0x00
	.byte 0x00, 0x00, 0x2F, 0x01, 0x32, 0x02, 0xF7, 0x00, 0x5C, 0x00, 0xB4, 0x00
	.byte 0x20, 0x01, 0x42, 0x01, 0x2A, 0x02, 0x65, 0x00, 0x5E, 0x00, 0x4C, 0x01
	.byte 0x00, 0x00, 0xD7, 0x00, 0x2A, 0x02, 0x3A, 0x00, 0x0D, 0x01, 0xB9, 0x00
	.byte 0x62, 0x00, 0x47, 0x01, 0x2E, 0x02, 0x98, 0x00, 0x3A, 0x00, 0x39, 0x00
	.byte 0x00, 0x00, 0x2C, 0x01, 0x2E, 0x02, 0x99, 0x00, 0xF7, 0x00, 0x4C, 0x01
	.byte 0xCA, 0x00, 0x59, 0x01, 0x30, 0x02, 0x5C, 0x00, 0xCA, 0x00, 0x2E, 0x01
	.byte 0x00, 0x00, 0x78, 0x01, 0x30, 0x02, 0x2C, 0x00, 0xB6, 0x00, 0xA3, 0x00
	.byte 0x00, 0x00, 0xE5, 0x00, 0x32, 0x02, 0x3B, 0x01, 0xF2, 0x00, 0xF7, 0x00
	.byte 0xB6, 0x00, 0xC5, 0x00, 0x32, 0x02, 0x5E, 0x00, 0xF7, 0x00, 0xE7, 0x00
	.byte 0x62, 0x00, 0xE0, 0x00, 0x2A, 0x02, 0xBE, 0x00, 0x3A, 0x00, 0x7E, 0x00
	.byte 0x00, 0x00, 0x57, 0x00, 0x2A, 0x02, 0x60, 0x01, 0x3A, 0x00, 0x1D, 0x00
	.byte 0x00, 0x00, 0x36, 0x01, 0x2E, 0x02, 0xB6, 0x00, 0x30, 0x00, 0x39, 0x00
	.byte 0x00, 0x00, 0xC3, 0x00, 0x2E, 0x02, 0x59, 0x00, 0x3D, 0x01, 0x39, 0x00
	.byte 0x00, 0x00, 0x29, 0x01, 0x30, 0x02, 0xB6, 0x00, 0x4C, 0x00, 0x5C, 0x00
	.byte 0x3A, 0x00, 0xC7, 0x00, 0x30, 0x02, 0x5E, 0x00, 0x1D, 0x00, 0xCF, 0x00
	.byte 0x00, 0x00, 0x79, 0x00, 0x32, 0x02, 0x60, 0x01, 0x55, 0x00, 0x6D, 0x00
	.byte 0x3B, 0x00, 0x09, 0x00, 0x32, 0x02, 0x38, 0x00, 0x2C, 0x00, 0x3A, 0x00
	.byte 0x00, 0x00, 0x69, 0x01, 0x2A, 0x02, 0x65, 0x00, 0x05, 0x01, 0xF7, 0x00
	.byte 0xB6, 0x00, 0x5D, 0x00, 0x2A, 0x02, 0x5C, 0x00, 0xB4, 0x00, 0x5F, 0x00
	.byte 0xF7, 0x00, 0x7A, 0x01, 0x2E, 0x02, 0xF7, 0x00, 0xB4, 0x00, 0x05, 0x01
	.byte 0x00, 0x00, 0xC8, 0x00, 0x2E, 0x02, 0xC3, 0x00, 0xB4, 0x00, 0xD4, 0x00
	.byte 0x00, 0x00, 0x42, 0x01, 0x30, 0x02, 0xF7, 0x00, 0xD4, 0x00, 0x5B, 0x00
	.byte 0x65, 0x00, 0x6A, 0x01, 0x30, 0x02, 0x05, 0x01, 0x5C, 0x00, 0xF7, 0x00
	.byte 0x00, 0x00, 0x2F, 0x01, 0x32, 0x02, 0xF7, 0x00, 0xB4, 0x00, 0x20, 0x01
	.byte 0xB6, 0x00, 0x5E, 0x00, 0x32, 0x02, 0x5E, 0x00, 0xC2, 0x00, 0xB4, 0x00
	.byte 0x65, 0x00, 0x63, 0x01, 0x2A, 0x02, 0xF2, 0x00, 0x5C, 0x00, 0x3A, 0x00
	.byte 0x00, 0x00, 0x52, 0x00, 0x2A, 0x02, 0x55, 0x00, 0x56, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xD0, 0x00, 0x2E, 0x02, 0x58, 0x00, 0x26, 0x00, 0x59, 0x00
	.byte 0x00, 0x00, 0xD4, 0x00, 0x2E, 0x02, 0xE8, 0x00, 0xA3, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xCD, 0x00, 0x30, 0x02, 0x99, 0x00, 0x5C, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xE3, 0x00, 0x30, 0x02, 0xD3, 0x00, 0x5C, 0x00, 0x13, 0x00
	.byte 0xB6, 0x00, 0x80, 0x01, 0x32, 0x02, 0x59, 0x00, 0x24, 0x00, 0x39, 0x00
	.byte 0x3A, 0x00, 0x90, 0x01, 0x32, 0x02, 0x59, 0x00, 0x5E, 0x00, 0xF7, 0x00
	.byte 0x18, 0x01, 0x94, 0x00, 0x2A, 0x02, 0x56, 0x00, 0x5C, 0x00, 0x3A, 0x00
	.byte 0x00, 0x00, 0x4D, 0x01, 0x2A, 0x02, 0x59, 0x00, 0xE1, 0x00, 0xF2, 0x00
	.byte 0xD3, 0x00, 0x67, 0x01, 0x2E, 0x02, 0x59, 0x00, 0x51, 0x01, 0x2F, 0x00
	.byte 0xB6, 0x00, 0x4E, 0x01, 0x2E, 0x02, 0x59, 0x00, 0x51, 0x01, 0x7E, 0x00
	.byte 0x00, 0x00, 0x8E, 0x00, 0x30, 0x02, 0x59, 0x00, 0x9D, 0x00, 0x51, 0x01
	.byte 0x00, 0x00, 0x82, 0x00, 0x30, 0x02, 0x59, 0x00, 0x39, 0x00, 0x25, 0x00
	.byte 0x2C, 0x00, 0xE6, 0x00, 0x32, 0x02, 0x38, 0x00, 0x3A, 0x00, 0xB6, 0x00
	.byte 0x00, 0x00, 0x06, 0x00, 0x32, 0x02, 0x35, 0x00, 0x08, 0x01, 0x7E, 0x00
	.byte 0xE7, 0x00, 0x3B, 0x00, 0x2A, 0x02, 0x7E, 0x00, 0x24, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x3E, 0x00, 0x2A, 0x02, 0x38, 0x00, 0x3A, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x1A, 0x00, 0x2E, 0x02, 0x57, 0x00, 0x56, 0x00, 0x15, 0x00
	.byte 0x00, 0x00, 0x86, 0x00, 0x2E, 0x02, 0x39, 0x00, 0x3A, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x87, 0x00, 0x30, 0x02, 0x55, 0x00, 0x2A, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x88, 0x00, 0x30, 0x02, 0x35, 0x00, 0x2C, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x26, 0x00, 0x32, 0x02, 0x35, 0x00, 0x05, 0x01, 0xB6, 0x00
	.byte 0x00, 0x00, 0x79, 0x00, 0x32, 0x02, 0x3A, 0x00, 0x39, 0x00, 0x55, 0x00
	.byte 0x5E, 0x00, 0x73, 0x00, 0x2A, 0x02, 0x3F, 0x00, 0x35, 0x00, 0x39, 0x00
	.byte 0x92, 0x00, 0x31, 0x01, 0x2A, 0x02, 0x4C, 0x01, 0x3F, 0x00, 0x5C, 0x00
	.byte 0x00, 0x00, 0xD9, 0x00, 0x2E, 0x02, 0x3F, 0x00, 0x59, 0x00, 0x08, 0x01
	.byte 0xB6, 0x00, 0xE9, 0x00, 0x2E, 0x02, 0x3C, 0x00, 0x3F, 0x00, 0xF7, 0x00
	.byte 0x3A, 0x00, 0x80, 0x00, 0x30, 0x02, 0x59, 0x00, 0x3F, 0x00, 0x39, 0x00
	.byte 0x55, 0x00, 0x16, 0x00, 0x30, 0x02, 0x3F, 0x00, 0x13, 0x00, 0x77, 0x00
	.byte 0xB6, 0x00, 0x8F, 0x00, 0x32, 0x02, 0x3F, 0x00, 0x22, 0x00, 0xF7, 0x00
	.byte 0x59, 0x00, 0x6E, 0x01, 0x32, 0x02, 0x3F, 0x00, 0x59, 0x00, 0xF7, 0x00
	.byte 0x3A, 0x00

	.globl gUnknown_85DE668
gUnknown_85DE668: @ 0x85DE668
	.incbin "baserom_jp.gba", 0x5de668, 0x7d0

	.globl gUnknown_85DEE38
gUnknown_85DEE38: @ 0x85DEE38
	.incbin "baserom_jp.gba", 0x5dee38, 0x50

	.globl gUnknown_85DEE88
gUnknown_85DEE88: @ 0x85DEE88
	.incbin "baserom_jp.gba", 0x5dee88, 0x5

	.globl gUnknown_85DEE8D
gUnknown_85DEE8D: @ 0x85DEE8D
	.incbin "baserom_jp.gba", 0x5dee8d, 0xfb

	.globl gUnknown_85DEF88
gUnknown_85DEF88: @ 0x85DEF88
	.incbin "baserom_jp.gba", 0x5def88, 0x44

	.globl gUnknown_85DEFCC
gUnknown_85DEFCC: @ 0x85DEFCC
	.incbin "baserom_jp.gba", 0x5defcc, 0x8

	.globl gUnknown_85DEFD4
gUnknown_85DEFD4: @ 0x85DEFD4
	.incbin "baserom_jp.gba", 0x5defd4, 0x190

	.globl gUnknown_85DF164
gUnknown_85DF164: @ 0x85DF164
	.incbin "baserom_jp.gba", 0x5df164, 0x190

	.globl gUnknown_85DF2F4
gUnknown_85DF2F4: @ 0x85DF2F4
	.incbin "baserom_jp.gba", 0x5df2f4, 0x7e

	.globl gUnknown_85DF372
gUnknown_85DF372: @ 0x85DF372
	.incbin "baserom_jp.gba", 0x5df372, 0xa

	.globl gUnknown_85DF37C
gUnknown_85DF37C: @ 0x85DF37C
	.incbin "baserom_jp.gba", 0x5df37c, 0xd8

	.globl gUnknown_85DF454
gUnknown_85DF454: @ 0x85DF454
	.incbin "baserom_jp.gba", 0x5df454, 0x2a4

	.globl gUnknown_85DF6F8
gUnknown_85DF6F8: @ 0x85DF6F8
	.incbin "baserom_jp.gba", 0x5df6f8, 0x18

	.globl gUnknown_85DF710
gUnknown_85DF710: @ 0x85DF710
	.incbin "baserom_jp.gba", 0x5df710, 0x8

	.globl gUnknown_85DF718
gUnknown_85DF718: @ 0x85DF718
	.incbin "baserom_jp.gba", 0x5df718, 0x48

	.globl gUnknown_85DF760
gUnknown_85DF760: @ 0x85DF760
	.incbin "baserom_jp.gba", 0x5df760, 0xc

	.globl gUnknown_85DF76C
gUnknown_85DF76C: @ 0x85DF76C
	.incbin "baserom_jp.gba", 0x5df76c, 0x12

	.globl gUnknown_85DF77E
gUnknown_85DF77E: @ 0x85DF77E
	.string "あえ$$　いお$あうか$いき$$　おく$あえかけいおきこうかさ$えけし$おくこすかけさせきこそ$くす$$けしせ$こすそ$させ$$"
	.globl gUnknown_85DF7BE
gUnknown_85DF7BE: @ 0x85DF7BE
	.incbin "baserom_jp.gba", 0x5df7be, 0xa

	.globl gUnknown_85DF7C8
gUnknown_85DF7C8: @ 0x85DF7C8
	.incbin "baserom_jp.gba", 0x5df7c8, 0xc

	.globl gUnknown_85DF7D4
gUnknown_85DF7D4: @ 0x85DF7D4
	.incbin "baserom_jp.gba", 0x5df7d4, 0x18

	.globl gUnknown_85DF7EC
gUnknown_85DF7EC: @ 0x85DF7EC
	.incbin "baserom_jp.gba", 0x5df7ec, 0x78

	.globl gUnknown_85DF864
gUnknown_85DF864: @ 0x85DF864
	.incbin "baserom_jp.gba", 0x5df864, 0x4

	.globl gUnknown_85DF868
gUnknown_85DF868: @ 0x85DF868
	.incbin "baserom_jp.gba", 0x5df868, 0x4

	.globl gUnknown_85DF86C
gUnknown_85DF86C: @ 0x85DF86C
	.incbin "baserom_jp.gba", 0x5df86c, 0x4

	.globl gUnknown_85DF870
gUnknown_85DF870: @ 0x85DF870
	.incbin "baserom_jp.gba", 0x5df870, 0x4

	.globl gUnknown_85DF874
gUnknown_85DF874: @ 0x85DF874
	.incbin "baserom_jp.gba", 0x5df874, 0x6

	.globl gUnknown_85DF87A
gUnknown_85DF87A: @ 0x85DF87A
	.incbin "baserom_jp.gba", 0x5df87a, 0x2

	.globl gUnknown_85DF87C
gUnknown_85DF87C: @ 0x85DF87C
	.incbin "baserom_jp.gba", 0x5df87c, 0x2

	.globl gUnknown_85DF87E
gUnknown_85DF87E: @ 0x85DF87E
	.incbin "baserom_jp.gba", 0x5df87e, 0x1

	.globl gUnknown_85DF87F
gUnknown_85DF87F: @ 0x85DF87F
	.incbin "baserom_jp.gba", 0x5df87f, 0x4

	.globl gUnknown_85DF883
gUnknown_85DF883: @ 0x85DF883
	.incbin "baserom_jp.gba", 0x5df883, 0x2

	.globl gUnknown_85DF885
gUnknown_85DF885: @ 0x85DF885
	.incbin "baserom_jp.gba", 0x5df885, 0x2

	.globl gUnknown_85DF887
gUnknown_85DF887: @ 0x85DF887
	.incbin "baserom_jp.gba", 0x5df887, 0x5

	.globl gUnknown_85DF88C
gUnknown_85DF88C: @ 0x85DF88C
	.incbin "baserom_jp.gba", 0x5df88c, 0x30

	.globl gUnknown_85DF8BC
gUnknown_85DF8BC: @ 0x85DF8BC
	.incbin "baserom_jp.gba", 0x5df8bc, 0x8

	.globl gUnknown_85DF8C4
gUnknown_85DF8C4: @ 0x85DF8C4
	.incbin "baserom_jp.gba", 0x5df8c4, 0x8

	.globl gUnknown_85DF8CC
gUnknown_85DF8CC: @ 0x85DF8CC
	.incbin "baserom_jp.gba", 0x5df8cc, 0x10

	.globl gUnknown_85DF8DC
gUnknown_85DF8DC: @ 0x85DF8DC
	.incbin "baserom_jp.gba", 0x5df8dc, 0xc0

	.globl gUnknown_85DF99C
gUnknown_85DF99C: @ 0x85DF99C
	.incbin "baserom_jp.gba", 0x5df99c, 0x80

	.globl gUnknown_85DFA1C
gUnknown_85DFA1C: @ 0x85DFA1C
	.incbin "baserom_jp.gba", 0x5dfa1c, 0x10

	.globl gUnknown_85DFA2C
gUnknown_85DFA2C: @ 0x85DFA2C
	.incbin "baserom_jp.gba", 0x5dfa2c, 0x38

	.globl gUnknown_85DFA64
gUnknown_85DFA64: @ 0x85DFA64
	.incbin "baserom_jp.gba", 0x5dfa64, 0x50

	.globl gUnknown_85DFAB4
gUnknown_85DFAB4: @ 0x85DFAB4
	.incbin "baserom_jp.gba", 0x5dfab4, 0x48

	.globl gUnknown_85DFAFC
gUnknown_85DFAFC: @ 0x85DFAFC
	.incbin "baserom_jp.gba", 0x5dfafc, 0x18

	.globl gUnknown_85DFB14
gUnknown_85DFB14: @ 0x85DFB14
	.incbin "baserom_jp.gba", 0x5dfb14, 0x4

	.globl gUnknown_85DFB18
gUnknown_85DFB18: @ 0x85DFB18
	.incbin "baserom_jp.gba", 0x5dfb18, 0x4

	.globl gUnknown_85DFB1C
gUnknown_85DFB1C: @ 0x85DFB1C
	.incbin "baserom_jp.gba", 0x5dfb1c, 0x4

	.globl gUnknown_85DFB20
gUnknown_85DFB20: @ 0x85DFB20
	.incbin "baserom_jp.gba", 0x5dfb20, 0x4

	.globl gUnknown_85DFB24
gUnknown_85DFB24: @ 0x85DFB24
	.incbin "baserom_jp.gba", 0x5dfb24, 0x4

	.globl gUnknown_85DFB28
gUnknown_85DFB28: @ 0x85DFB28
	.incbin "baserom_jp.gba", 0x5dfb28, 0x4

	.globl gUnknown_85DFB2C
gUnknown_85DFB2C: @ 0x85DFB2C
	.incbin "baserom_jp.gba", 0x5dfb2c, 0x4

	.globl gUnknown_85DFB30
gUnknown_85DFB30: @ 0x85DFB30
	.incbin "baserom_jp.gba", 0x5dfb30, 0x18

	.globl gUnknown_85DFB48
gUnknown_85DFB48: @ 0x85DFB48
	.incbin "baserom_jp.gba", 0x5dfb48, 0x18

	.globl gUnknown_85DFB60
gUnknown_85DFB60: @ 0x85DFB60
	.incbin "baserom_jp.gba", 0x5dfb60, 0x20

	.globl gUnknown_85DFB80
gUnknown_85DFB80: @ 0x85DFB80
	.incbin "baserom_jp.gba", 0x5dfb80, 0x70

	.globl gUnknown_85DFBF0
gUnknown_85DFBF0: @ 0x85DFBF0
	.incbin "baserom_jp.gba", 0x5dfbf0, 0x40

	.globl gUnknown_85DFC30
gUnknown_85DFC30: @ 0x85DFC30
	.incbin "baserom_jp.gba", 0x5dfc30, 0x44

	.globl sSaveLocationPokeCenterList
sSaveLocationPokeCenterList: @ 0x85DFC74
	.string "いいういあういうおえかええおおおえかおか　きあきえくおくさけしけおこかこおさかさいしうしかすきすうせえせいそうそしたすたこたせたゅはょはねのののはのひの$$"
	.globl sSaveLocationReloadLocList
sSaveLocationReloadLocList: @ 0x85DFCC2
	.string "おは$$"
	.globl sEmptyMapList
sEmptyMapList: @ 0x85DFCC6
	.hword 0xFFFF

	.globl gItemIconTable
gItemIconTable: @ 0x85DFCC8
	.incbin "baserom_jp.gba", 0x5dfcc8, 0xbe4

	.globl gItemIconSpriteTemplate
gItemIconSpriteTemplate: @ 0x85E08AC
	.incbin "baserom_jp.gba", 0x5e08ac, 0x18

	.globl gUnknown_85E08C4
gUnknown_85E08C4: @ 0x85E08C4
	.incbin "baserom_jp.gba", 0x5e08c4, 0x3c

	.globl gUnknown_85E0900
gUnknown_85E0900: @ 0x85E0900
	.incbin "baserom_jp.gba", 0x5e0900, 0x670

	.globl gUnknown_85E0F70
gUnknown_85E0F70: @ 0x85E0F70
	.incbin "baserom_jp.gba", 0x5e0f70, 0x2c

	.globl gUnknown_85E0F9C
gUnknown_85E0F9C: @ 0x85E0F9C
	.incbin "baserom_jp.gba", 0x5e0f9c, 0x20

	.globl gUnknown_85E0FBC
gUnknown_85E0FBC: @ 0x85E0FBC
	.incbin "baserom_jp.gba", 0x5e0fbc, 0xc0

	.globl gUnknown_85E107C
gUnknown_85E107C: @ 0x85E107C
	.incbin "baserom_jp.gba", 0x5e107c, 0x1c

	.globl gUnknown_85E1098
gUnknown_85E1098: @ 0x85E1098
	.incbin "baserom_jp.gba", 0x5e1098, 0x1c

	.globl gUnknown_85E10B4
gUnknown_85E10B4: @ 0x85E10B4
	.incbin "baserom_jp.gba", 0x5e10b4, 0x14

	.globl gUnknown_85E10C8
gUnknown_85E10C8: @ 0x85E10C8
	.incbin "baserom_jp.gba", 0x5e10c8, 0x40

	.globl gUnknown_85E1108
gUnknown_85E1108: @ 0x85E1108
	.incbin "baserom_jp.gba", 0x5e1108, 0x40

	.globl gUnknown_85E1148
gUnknown_85E1148: @ 0x85E1148
	.incbin "baserom_jp.gba", 0x5e1148, 0x40

	.globl gUnknown_85E1188
gUnknown_85E1188: @ 0x85E1188
	.incbin "baserom_jp.gba", 0x5e1188, 0x38

	.globl gUnknown_85E11C0
gUnknown_85E11C0: @ 0x85E11C0
	.incbin "baserom_jp.gba", 0x5e11c0, 0x8

	.globl gUnknown_85E11C8
gUnknown_85E11C8: @ 0x85E11C8
	.incbin "baserom_jp.gba", 0x5e11c8, 0x8

	.globl gUnknown_85E11D0
gUnknown_85E11D0: @ 0x85E11D0
	.incbin "baserom_jp.gba", 0x5e11d0, 0x8

	.globl gUnknown_85E11D8
gUnknown_85E11D8: @ 0x85E11D8
	.incbin "baserom_jp.gba", 0x5e11d8, 0x8

	.globl gUnknown_85E11E0
gUnknown_85E11E0: @ 0x85E11E0
	.incbin "baserom_jp.gba", 0x5e11e0, 0x8

	.globl gUnknown_85E11E8
gUnknown_85E11E8: @ 0x85E11E8
	.incbin "baserom_jp.gba", 0x5e11e8, 0x8

	.globl gUnknown_85E11F0
gUnknown_85E11F0: @ 0x85E11F0
	.incbin "baserom_jp.gba", 0x5e11f0, 0x8

	.globl gUnknown_85E11F8
gUnknown_85E11F8: @ 0x85E11F8
	.incbin "baserom_jp.gba", 0x5e11f8, 0x8

	.globl gUnknown_85E1200
gUnknown_85E1200: @ 0x85E1200
	.incbin "baserom_jp.gba", 0x5e1200, 0x8

	.globl gUnknown_85E1208
gUnknown_85E1208: @ 0x85E1208
	.incbin "baserom_jp.gba", 0x5e1208, 0x8

	.globl gUnknown_85E1210
gUnknown_85E1210: @ 0x85E1210
	.incbin "baserom_jp.gba", 0x5e1210, 0x8

	.globl gUnknown_85E1218
gUnknown_85E1218: @ 0x85E1218
	.incbin "baserom_jp.gba", 0x5e1218, 0x8

	.globl gUnknown_85E1220
gUnknown_85E1220: @ 0x85E1220
	.incbin "baserom_jp.gba", 0x5e1220, 0x8

	.globl gUnknown_85E1228
gUnknown_85E1228: @ 0x85E1228
	.incbin "baserom_jp.gba", 0x5e1228, 0x18

	.globl gUnknown_85E1240
gUnknown_85E1240: @ 0x85E1240
	.incbin "baserom_jp.gba", 0x5e1240, 0x46

	.globl gUnknown_85E1286
gUnknown_85E1286: @ 0x85E1286
	.incbin "baserom_jp.gba", 0x5e1286, 0x46

	.globl gUnknown_85E12CC
gUnknown_85E12CC: @ 0x85E12CC
	.incbin "baserom_jp.gba", 0x5e12cc, 0x36

	.globl gUnknown_85E1302
gUnknown_85E1302: @ 0x85E1302
	.incbin "baserom_jp.gba", 0x5e1302, 0x36

	.globl gUnknown_85E1338
gUnknown_85E1338: @ 0x85E1338
	.incbin "baserom_jp.gba", 0x5e1338, 0x36

	.globl gUnknown_85E136E
gUnknown_85E136E: @ 0x85E136E
	.incbin "baserom_jp.gba", 0x5e136e, 0x2

	.globl gUnknown_85E1370
gUnknown_85E1370: @ 0x85E1370
	.incbin "baserom_jp.gba", 0x5e1370, 0x2

	.globl gUnknown_85E1372
gUnknown_85E1372: @ 0x85E1372
	.incbin "baserom_jp.gba", 0x5e1372, 0x3

	.globl gUnknown_85E1375
gUnknown_85E1375: @ 0x85E1375
	.incbin "baserom_jp.gba", 0x5e1375, 0x3

	.globl gUnknown_85E1378
gUnknown_85E1378: @ 0x85E1378
	.incbin "baserom_jp.gba", 0x5e1378, 0x3

	.globl gUnknown_85E137B
gUnknown_85E137B: @ 0x85E137B
	.incbin "baserom_jp.gba", 0x5e137b, 0x2

	.globl gUnknown_85E137D
gUnknown_85E137D: @ 0x85E137D
	.incbin "baserom_jp.gba", 0x5e137d, 0x2

	.globl gUnknown_85E137F
gUnknown_85E137F: @ 0x85E137F
	.incbin "baserom_jp.gba", 0x5e137f, 0x2

	.globl gUnknown_85E1381
gUnknown_85E1381: @ 0x85E1381
	.incbin "baserom_jp.gba", 0x5e1381, 0x2

	.globl gUnknown_85E1383
gUnknown_85E1383: @ 0x85E1383
	.incbin "baserom_jp.gba", 0x5e1383, 0x2

	.globl gUnknown_85E1385
gUnknown_85E1385: @ 0x85E1385
	.incbin "baserom_jp.gba", 0x5e1385, 0x3

	.globl gUnknown_85E1388
gUnknown_85E1388: @ 0x85E1388
	.incbin "baserom_jp.gba", 0x5e1388, 0x3

	.globl gUnknown_85E138B
gUnknown_85E138B: @ 0x85E138B
	.incbin "baserom_jp.gba", 0x5e138b, 0x3

	.globl gUnknown_85E138E
gUnknown_85E138E: @ 0x85E138E
	.incbin "baserom_jp.gba", 0x5e138e, 0x3

	.globl gUnknown_85E1391
gUnknown_85E1391: @ 0x85E1391
	.incbin "baserom_jp.gba", 0x5e1391, 0x3

	.globl gUnknown_85E1394
gUnknown_85E1394: @ 0x85E1394
	.incbin "baserom_jp.gba", 0x5e1394, 0x3

	.globl gUnknown_85E1397
gUnknown_85E1397: @ 0x85E1397
	.incbin "baserom_jp.gba", 0x5e1397, 0x3

	.globl gUnknown_85E139A
gUnknown_85E139A: @ 0x85E139A
	.incbin "baserom_jp.gba", 0x5e139a, 0x3

	.globl gUnknown_85E139D
gUnknown_85E139D: @ 0x85E139D
	.incbin "baserom_jp.gba", 0x5e139d, 0x3

	.globl gUnknown_85E13A0
gUnknown_85E13A0: @ 0x85E13A0
	.incbin "baserom_jp.gba", 0x5e13a0, 0x3

	.globl gUnknown_85E13A3
gUnknown_85E13A3: @ 0x85E13A3
	.incbin "baserom_jp.gba", 0x5e13a3, 0x3

	.globl gUnknown_85E13A6
gUnknown_85E13A6: @ 0x85E13A6
	.incbin "baserom_jp.gba", 0x5e13a6, 0x3

	.globl gUnknown_85E13A9
gUnknown_85E13A9: @ 0x85E13A9
	.incbin "baserom_jp.gba", 0x5e13a9, 0x3

	.globl gUnknown_85E13AC
gUnknown_85E13AC: @ 0x85E13AC
	.incbin "baserom_jp.gba", 0x5e13ac, 0x6c

	.globl gUnknown_85E1418
gUnknown_85E1418: @ 0x85E1418
	.incbin "baserom_jp.gba", 0x5e1418, 0xa8

	.globl gUnknown_85E14C0
gUnknown_85E14C0: @ 0x85E14C0
	.incbin "baserom_jp.gba", 0x5e14c0, 0x130

	.globl gUnknown_85E15F0
gUnknown_85E15F0: @ 0x85E15F0
	.incbin "baserom_jp.gba", 0x5e15f0, 0x38

	.globl gUnknown_85E1628
gUnknown_85E1628: @ 0x85E1628
	.incbin "baserom_jp.gba", 0x5e1628, 0xe

	.globl gUnknown_85E1636
gUnknown_85E1636: @ 0x85E1636
	.incbin "baserom_jp.gba", 0x5e1636, 0x1e

	.globl gUnknown_85E1654
gUnknown_85E1654: @ 0x85E1654
	.incbin "baserom_jp.gba", 0x5e1654, 0x70

	.globl gUnknown_85E16C4
gUnknown_85E16C4: @ 0x85E16C4
	.incbin "baserom_jp.gba", 0x5e16c4, 0xa4

	.globl gUnknown_85E1768
gUnknown_85E1768: @ 0x85E1768
	.incbin "baserom_jp.gba", 0x5e1768, 0x8

	.globl gUnknown_85E1770
gUnknown_85E1770: @ 0x85E1770
	.incbin "baserom_jp.gba", 0x5e1770, 0x8

	.globl gUnknown_85E1778
gUnknown_85E1778: @ 0x85E1778
	.incbin "baserom_jp.gba", 0x5e1778, 0x38

	.globl gUnknown_85E17B0
gUnknown_85E17B0: @ 0x85E17B0
	.incbin "baserom_jp.gba", 0x5e17b0, 0x8

	.globl gUnknown_85E17B8
gUnknown_85E17B8: @ 0x85E17B8
	.incbin "baserom_jp.gba", 0x5e17b8, 0x8

	.globl gUnknown_85E17C0
gUnknown_85E17C0: @ 0x85E17C0
	.incbin "baserom_jp.gba", 0x5e17c0, 0x68

	.globl gUnknown_85E1828
gUnknown_85E1828: @ 0x85E1828
	.incbin "baserom_jp.gba", 0x5e1828, 0x8

	.globl gUnknown_85E1830
gUnknown_85E1830: @ 0x85E1830
	.incbin "baserom_jp.gba", 0x5e1830, 0x80

	.globl gUnknown_85E18B0
gUnknown_85E18B0: @ 0x85E18B0
	.incbin "baserom_jp.gba", 0x5e18b0, 0x8

	.globl gUnknown_85E18B8
gUnknown_85E18B8: @ 0x85E18B8
	.incbin "baserom_jp.gba", 0x5e18b8, 0x8

	.globl gUnknown_85E18C0
gUnknown_85E18C0: @ 0x85E18C0
	.incbin "baserom_jp.gba", 0x5e18c0, 0x18

	.globl gUnknown_85E18D8
gUnknown_85E18D8: @ 0x85E18D8
	.incbin "baserom_jp.gba", 0x5e18d8, 0x20

	.globl gUnknown_85E18F8
gUnknown_85E18F8: @ 0x85E18F8
	.incbin "baserom_jp.gba", 0x5e18f8, 0x74

	.globl sVerdanturfTentFuncs
sVerdanturfTentFuncs: @ 0x85E196C
	.incbin "baserom_jp.gba", 0x5e196c, 0x20

	.globl sVerdanturfTentRewards
sVerdanturfTentRewards: @ 0x85E198C
	.hword 0x0008, 0x0000

	.globl sFallarborTentFuncs
sFallarborTentFuncs: @ 0x85E1990
	.incbin "baserom_jp.gba", 0x5e1990, 0x1c

	.globl sFallarborTentRewards
sFallarborTentRewards: @ 0x85E19AC
	.hword 0x0015, 0x0000

	.globl sSlateportTentFuncs
sSlateportTentFuncs: @ 0x85E19B0
	.incbin "baserom_jp.gba", 0x5e19b0, 0x28

	.globl sSlateportTentRewards
sSlateportTentRewards: @ 0x85E19D8
	.hword 0x0017, 0x0000

	.globl sScrollDistances
sScrollDistances: @ 0x85E19DC
	.byte 0x01, 0x02, 0x04, 0x00

	.globl sFont_Braille
sFont_Braille: @ 0x85E19E0
	.incbin "baserom_jp.gba", 0x5e19e0, 0x5904

	.globl gUnknown_85E72E4
gUnknown_85E72E4: @ 0x85E72E4
	.incbin "baserom_jp.gba", 0x5e72e4, 0x48

	.globl gUnknown_85E732C
gUnknown_85E732C: @ 0x85E732C
	.incbin "baserom_jp.gba", 0x5e732c, 0x104

	.globl sMirageTower_Gfx
sMirageTower_Gfx: @ 0x85E7430
	.incbin "baserom_jp.gba", 0x5e7430, 0x920

	.globl sMirageTowerTilemap
sMirageTowerTilemap: @ 0x85E7D50
	.incbin "baserom_jp.gba", 0x5e7d50, 0xb0

	.globl sFossil_Gfx
sFossil_Gfx: @ 0x85E7E00
	.incbin "baserom_jp.gba", 0x5e7e00, 0x80

	.globl sMirageTowerCrumbles_Gfx
sMirageTowerCrumbles_Gfx: @ 0x85E7E80
	.incbin "baserom_jp.gba", 0x5e7e80, 0x80

	.globl gUnknown_85E7F00
gUnknown_85E7F00: @ 0x85E7F00
	.incbin "baserom_jp.gba", 0x5e7f00, 0x20


	.globl sCeilingCrumblePositions
sCeilingCrumblePositions: @ 0x85E7F20
	.hword 0x0000, 0x000A, 0x0041, 0x0011, 0x0003, 0x0032, 0xFFF4, 0x0000, 0x004B, 0x000A, 0x000F, 0x005A
	.hword 0x0007, 0x0008, 0x0041, 0xFFEE, 0x0005, 0x004B, 0x0016, 0xFFF6, 0x0037, 0xFFE8, 0xFFFC, 0x0041

	.globl sCeilingCrumbleSpriteSheets
sCeilingCrumbleSpriteSheets: @ 0x85E7F50
	.incbin "baserom_jp.gba", 0x5e7f50, 0x10

	.globl sInvisibleMirageTowerMetatiles
sInvisibleMirageTowerMetatiles: @ 0x85E7F60
	.incbin "baserom_jp.gba", 0x5e7f60, 0x5c

	.globl sSpriteTemplate_FallingFossil
sSpriteTemplate_FallingFossil: @ 0x85E7FBC
	.incbin "baserom_jp.gba", 0x5e7fbc, 0x18

	.globl gMirageTowerPulseBlendSettings
gMirageTowerPulseBlendSettings: @ 0x85E7FD4
	.incbin "baserom_jp.gba", 0x5e7fd4, 0x1c

	.globl sSpriteTemplate_CeilingCrumbleSmall
sSpriteTemplate_CeilingCrumbleSmall: @ 0x85E7FF0
	.incbin "baserom_jp.gba", 0x5e7ff0, 0xc

	.globl gUnknown_85E7FFC
gUnknown_85E7FFC: @ 0x85E7FFC
	.byte 0x00, 0x00, 0x00, 0x00, 0x10, 0xF3, 0x2B, 0x08, 0x75, 0xE7, 0x1B, 0x08
	.byte 0x00, 0x00, 0x0C, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0x08, 0x80, 0x5E, 0x08
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

	.globl sSpriteTemplate_CeilingCrumbleLarge
sSpriteTemplate_CeilingCrumbleLarge: @ 0x85E801C
	.incbin "baserom_jp.gba", 0x5e801c, 0x18

	.globl gUnknown_85E8034
gUnknown_85E8034: @ 0x85E8034
	.incbin "baserom_jp.gba", 0x5e8034, 0x4d70
