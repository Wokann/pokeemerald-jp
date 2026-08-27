	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit: @ 0x08262452
	.string "サファリゾーンを\n"
	.string "このまま　しゅうりょう　しますか？$"

SafariZone_Text_TimesUp: @ 0x0826246D
	.string "ピンポーン！　じかん　でーす！\n"
	.string "サファリゲームを　しゅうりょう　します$"

SafariZone_Text_OutOfBalls: @ 0x08262491
	.string "サファリボールを　つかいきったので\n"
	.string "サファリゲームを　しゅうりょう　します$"

SafariZone_Text_PlacePokeblockOnFeeder: @ 0x082624B7
	.string "ポロックおきばに　ポロックを　おきますか？$"

SafariZone_Text_PokeblockStillHere: @ 0x082624CD
	.string "まだ　{STR_VAR_1}が　のこっています$"

SafariZone_Text_PokeblockWasPlaced: @ 0x082624DC
	.string "{STR_VAR_1}を\n"
	.string "おきました！$"

	.incbin "baserom_jp.gba", 0x2624E7, 0x80C
