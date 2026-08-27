	removeitem 0x190A, 0x9B00
	gotobeatenscript
	faceplayer
	bufferleadmonspeciesname 0x16
	nop
	setmysteryeventstatus 0x12
	setdivewarp 0x800, 0xC, 0xFE13, 0x312
	returnram
	gettime
	nop
	returnram
	.incbin "baserom_jp.gba", 0x2436E5, 0x22A

	.globl gText_HowMayIServeYou
gText_HowMayIServeYou: @ 0x0824390F
	.string "ようこそ！\p"
	.string "おかいもの　ですね！$"

	.globl gText_PleaseComeAgain
gText_PleaseComeAgain: @ 0x08243920
	.string "またどうぞ！$"

gText_PlayerWhatCanIDoForYou:: @ 0x08243927
	.string "{PLAYER}{KUN}　いらっしゃい！\p"
	.string "おかいものね！$"

gText_ObtainedTheItem:: @ 0x0824393C
	.string "{STR_VAR_2}を　てにいれた！$"

gText_TheBagIsFull:: @ 0x08243947
	.string "バッグが　いっぱいだ！$"

gText_PutItemInPocket:: @ 0x08243953
	.string "{PLAYER}は　{STR_VAR_2}を\n"
	.string "{STR_VAR_3}ポケットに　しまった！$"

gText_PlayerFoundOneItem:: @ 0x08243969
	.string "{PLAYER}は　{STR_VAR_2}を\n"
	.string "みつけた！$"

gText_TooBadBagIsFull:: @ 0x08243977
	.string "ざんねん！\n"
	.string "バッグが　いっぱいだ⋯⋯$"

	.incbin "baserom_jp.gba", 0x24398a, 0x1e
	.globl gText_NoRoomLeftForAnother
gText_NoRoomLeftForAnother: @ 0x082439A8
	.incbin "baserom_jp.gba", 0x2439a8, 0x9f

gText_WhichFloorWouldYouLike:: @ 0x08243A47
	.string "ミナモ　デパートへ　ようこそ！\p"
	.string "なんかいへ　いきますか？$"

gText_SandstormIsVicious:: @ 0x08243A64
	.string "さばくの　すなあらしが　ひどくて\n"
	.string "さきに　すすめない！$"

	.globl gJPText_00243A80
gJPText_00243A80: @ 0x08243A80
	.string "バッグに　いれてある　どうぐを\n"
	.string "べんりボタンに　とうろく　できます$"

	.incbin "baserom_jp.gba", 0x243aa2, 0xdd
	.globl gJPText_00243B7F
gJPText_00243B7F: @ 0x08243B7F
	.string "{B_COPY_VAR_1}の　{B_COPY_VAR_2}を\n"
	.string "ポケナビに　とうろく　した！$"

	.incbin "baserom_jp.gba", 0x243b96, 0xf5
	.globl gJPText_00243C8B
gJPText_00243C8B: @ 0x08243C8B
	.string "みずは　ふかい　あおに　そまっている⋯⋯\n"
	.string "なみのりを　つかいますか？$"

	.globl gJPText_00243CAE
gJPText_00243CAE: @ 0x08243CAE
	.string "{B_COPY_VAR_1}は\n"
	.string "なみのりを　つかった！$"

	.globl gText_DoorOpenedFarAway
gText_DoorOpenedFarAway: @ 0x08243CBE
	.incbin "baserom_jp.gba", 0x243cbe, 0x1c

	.globl gText_BigHoleInTheWall
gText_BigHoleInTheWall: @ 0x08243CDA
	.incbin "baserom_jp.gba", 0x243cda, 0x14
	.incbin "baserom_jp.gba", 0x243cee, 0xd8

gText_Sudowoodo_Attacked::
	.string "おかしな　きは\n"
	.string "ホエルコじょうろを　いやがっている！\p"
	.string "おかしな　きが　おそいかかってきた！$"

gText_LegendaryFlewAway:: @ 0x08243DF4
	.string "{B_COPY_VAR_1}は\n"
	.string "どこかへ　とびさって　いった！$"

	.incbin "baserom_jp.gba", 0x243e08, 0xe6
	.globl gJPText_00243EEE
gJPText_00243EEE: @ 0x08243EEE
	.string "アンケートようの　メモようしが　ある\n"
	.string "アンケートに　なにか　かきますか？$"

	.incbin "baserom_jp.gba", 0x243f13, 0x1a9
	.globl gJPText_002440BC
gJPText_002440BC: @ 0x082440BC
	.string "おおあめは　おさまったようだ⋯⋯$"

	.globl gJPText_002440CD
gJPText_002440CD: @ 0x082440CD
	.string "ひでりは　おさまったようだ⋯⋯$"
