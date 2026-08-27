	compare_local_to_value 0x21, 0x1C
	compare_var_to_value 0x3F00, 0xA2E
	gotostd 0x13
	.incbin "baserom_jp.gba", 0x263174, 0x25
	.include "data/text/lottery_corner.inc"
	.include "data/text/event_ticket_1.inc"
	.include "data/text/braille.inc"
PetalburgCity_Gym_Text_GiveEnigmaBerry: @ 0x082637C2
	.string "パパ“やあ　{PLAYER}！\p"
	.string "めずらしい　きのみを　てに　いれたから\n"
	.string "プレゼント　するよ！$"

Route104_Text_PlantBerriesInSoilTakeThis: @ 0x082637EB
	.string "ふかふかの　つちに　はえている　きのみは\n"
	.string "じゆうに　とっても　よいのじゃが⋯\p"
	.string "1つだけ　きのみを　おなじ　ばしょに　うめる\n"
	.string "それが　れいぎと　いうものじゃ\p"
	.string "ほれ　これを　わけてやろう$"

Route104_Text_TrainersOftenMakeMonHoldBerries: @ 0x08263847
	.string "あんた　みたところ　トレーナーじゃろ？\p"
	.string "トレーナーは　よく　きのみを　ポケモンに\n"
	.string "もたせとるわい\p"
	.string "ふやすも　つかうも　あんた　しだいじゃ$"

Route111_Text_WateredPlantsEveryDayTakeBerry:: @ 0x0826388C
	.string "いつも　みずを　あげてたら\n"
	.string "たくさん　はなが　さいたんだ\p"
	.string "そしたら　きのみも　たくさん　できた！\p"
	.string "はい！\n"
	.string "これ　あげる$"

Route111_Text_GoingToTryToMakeDifferentColorBerries:: @ 0x082638C8
	.string "がんばって　いろんな　いろの\n"
	.string "きのみを　そだてるんだ！\l"
	.string "{STRING 0x02}も　がんばってね！$"

Route111_Text_WhatColorBerriesToLookForToday:: @ 0x082638F0
	.string "きょうは　なにいろの　きのみを\n"
	.string "さがそっかなー$"

	.include "data/text/berries.inc"
Route120_Text_BerriesExpressionOfLoveIsntIt: @ 0x0826398A
	.incbin "baserom_jp.gba", 0x26398a, 0x50

Route120_Text_YesYouUnderstand: @ 0x082639DA
	.incbin "baserom_jp.gba", 0x2639da, 0x20

Route120_Text_MakeYourOwnImpressions: @ 0x082639FA
	.incbin "baserom_jp.gba", 0x2639fa, 0x24

Route120_Text_BerryIsRareRaiseItWithCare: @ 0x08263A1E
	.incbin "baserom_jp.gba", 0x263a1e, 0x23

Route120_Text_IllGetMoreBerriesFromBerryMaster: @ 0x08263A41
	.incbin "baserom_jp.gba", 0x263a41, 0x17
LilycoveCity_Text_BerrySuitsYou: @ 0x08263A58
	.string "やっぱり\p"
	.string "わたしに　スーツが　にあうように\n"
	.string "うみには　しおかぜが　にあうな\l"
	.string "そして　きみには　きのみが　にあいそうだ⋯⋯\p"
	.string "なんでだろうね？$"

LilycoveCity_Text_BecauseYoureTrainer: @ 0x08263A9E
	.string "やっぱり　それは⋯⋯⋯⋯\p"
	.string "きみが　トレーナーだからだ！$"

LilycoveCity_Text_PokeblocksSuitPokemon: @ 0x08263ABA
	.string "やっぱり\p"
	.string "わたしに　シンプルさが　にあうように\n"
	.string "ポケモンには　ポロックが　にあうな$"
	.incbin "baserom_jp.gba", 0x263ae4, 0x44f
	@ Pretty Petal Flower Shop's berry dialogue remains physically owned by
	@ this later shared text block until that full data range is structured.
	.globl Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop
	.set Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, 0x08263C9E
	.globl Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries
	.set Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, 0x08263CC6
	.globl Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries
	.set Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, 0x08263CD9
	.globl Route104_PrettyPetalFlowerShop_Text_BerriesExplanation
	.set Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, 0x08263D0D
	.globl Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness
	.set Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, 0x08263DCA
	.globl Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis
	.set Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis, 0x08263DE8
	.globl Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation
	.set Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, 0x08263E32
	.globl Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers
	.set Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, 0x08263EA4
	.globl Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries
	.set Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, 0x08263ED1
SootopolisCity_Text_NameIsKiriHaveOneOfThese: @ 0x08263F33
	.string "{STR_VAR_1}　なまえ　なんていうの？\p"
	.string "⋯⋯⋯　⋯⋯⋯　⋯⋯⋯\n"
	.string "へー　いいねー\p"
	.string "わたしは　キリ　っていう　なまえなの\p"
	.string "パパと　ママが　すくすくと　そだって\n"
	.string "こころの　あたたかい　おんなのこに　なって\l"
	.string "ほしいっていう　ねがいを　こめたんだって！\p"
	.string "{STR_VAR_1}にも　これ　あげる$"

SootopolisCity_Text_GiveYouThisBerryToo: @ 0x08263FB4
	.string "あと　{STR_VAR_1}には　キリの　だいすきな\n"
	.string "この　きのみも　あげちゃう！$"

SootopolisCity_Text_WhatKindOfWishInYourName: @ 0x08263FD5
	.string "{STR_VAR_1}の　なまえには\n"
	.string "どんな　ねがいが　こめられてるの？$"

SootopolisCity_Text_LikeSeasonBornIn: @ 0x08263FF1
	.string "はる　なつ　あき　ふゆ\n"
	.string "はるに　うまれると　はるが　すきで\l"
	.string "なつに　うまれると　なつが　すきなのかな？$"

SootopolisCity_Text_ThenILoveAutumn: @ 0x08264025
	.string "じゃあ　キリは　あきに　うまれたから\n"
	.string "あきが　だいすき！\p"
	.string "{STR_VAR_1}は　いつが　すき？$"

SootopolisCity_Text_OhDoesntMatter: @ 0x0826404E
	.string "そっか⋯\n"
	.string "かんけいないのか⋯\p"
	.string "しりたいことって　たくさんあるなー$"
	.include "data/text/shoal_cave.inc"
	.globl gJPText_0026426B
gJPText_0026426B: @ 0x0826426B
	.string "ポケモンえほんが　そろってる！$"

	.globl gJPText_0026427B
gJPText_0026427B: @ 0x0826427B
	.string "いろんな　ほんが　いっぱいだ！$"

	.globl gJPText_0026428B
gJPText_0026428B: @ 0x0826428B
	.string "ポケモンざっしが　ならんでる！\p"
	.string "⋯⋯‘ポケモンのとも'\n"
	.string "⋯⋯‘ポケモン　てちょう'\l"
	.string "⋯⋯‘かわいい　ポケモン'$"

	.globl gJPText_002642C3
gJPText_002642C3: @ 0x082642C3
	.string "たかそうな　つぼが　ある！\n"
	.string "のぞきこむと⋯⋯\p"
	.string "なかは　からっぽ　だ！$"

	.globl gJPText_002642E6
gJPText_002642E6: @ 0x082642E6
	.string "なかは　からっぽ　だ！$"

	.globl gJPText_002642F2
gJPText_002642F2: @ 0x082642F2
	.string "たくさんの　ポケモン　グッズが\n"
	.string "ところせましと　ならべられてる！$"

	.globl gJPText_00264313
gJPText_00264313: @ 0x08264313
	.string "なにかの　せっけいず⋯⋯？\n"
	.string "みても　チンプンカンプン！$"

	.incbin "baserom_jp.gba", 0x26432f, 0x10
