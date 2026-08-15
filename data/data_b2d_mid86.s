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
