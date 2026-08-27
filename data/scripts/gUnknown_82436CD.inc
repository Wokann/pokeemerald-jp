	removeitem 0x190A, 0x9B00
	gotopostbattlescript
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

	.incbin "baserom_jp.gba", 0x243927, 0x50
	.globl gText_PlayerWhatCanIDoForYou
	.set gText_PlayerWhatCanIDoForYou, 0x08243927
	.globl gJPText_00243977
gJPText_00243977: @ 0x08243977
	.string "ざんねん！\n"
	.string "バッグが　いっぱいだ⋯⋯$"

	.globl gText_TooBadBagIsFull
	.set gText_TooBadBagIsFull, gJPText_00243977

	.incbin "baserom_jp.gba", 0x24398a, 0x1e
	.globl gText_NoRoomLeftForAnother
gText_NoRoomLeftForAnother: @ 0x082439A8
	.incbin "baserom_jp.gba", 0x2439a8, 0xbc

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
	.incbin "baserom_jp.gba", 0x243cee, 0x200
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
