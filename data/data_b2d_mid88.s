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
	.globl gText_AllTextBeingEditedWill
	.set gText_AllTextBeingEditedWill, gUnknown_85CBAA7
	.globl gUnknown_85CBAB6
gUnknown_85CBAB6: @ 0x85CBAB6
	.string "ぜんぶ　けしても　いいですか？$へんしゅうを　やめますか？$へんしゅうした　ことばは　ほぞん$されませんが　いいですか？$なにか　ことばを　いれてください！$ことばを　ぜんぶ　けすことは　できません！$"
	.globl gText_BeDeletedThatOkay
	.set gText_BeDeletedThatOkay, gUnknown_85CBAB6
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
