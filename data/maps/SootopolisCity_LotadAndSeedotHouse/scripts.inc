@ SootopolisCity_LotadAndSeedotHouse scripts (JP map g15 m12 @ 0x0820F861)

SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother:: @ 0x0820F862
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot:: @ 0x0820F8A9
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot:: @ 0x0820F8B3
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot:: @ 0x0820F8BD
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot:: @ 0x0820F8C7
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1:: @ 0x0820F8E9
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother:: @ 0x0820F8F3
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad:: @ 0x0820F93A
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad:: @ 0x0820F944
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad:: @ 0x0820F94E
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad:: @ 0x0820F958
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2:: @ 0x0820F97A
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord:: @ 0x0820F984
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord:: @ 0x0820F992
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot: @ 0x0820F9A0
	.string "きみ　タネボーって　ポケモン　しってる？\n"
	.string "ルネでは　めったに　みられないん　だけどね\p"
	.string "わし　おおきな　タネボーが\n"
	.string "めちゃめちゃ　だいすき　なのよ！\p"
	.string "おとうとは　ハスボーの　ほうが\n"
	.string "おおきいって　いうんだけど\p"
	.string "タネボーの　ほうが\n"
	.string "おおきいに　きまってる　よね！\p"
	.string "ん？　きみ　タネボー　もってるの？\n"
	.string "ちょ　ちょ　ちょっと⋯⋯\l"
	.string "おじさんに　みせて　おくれ！$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad: @ 0x0820FA50
	.string "{STR_VAR_2}cm！！\n"
	.string "おお！　こいつは　でかい！\p"
	.string "おとうとが　みた　でかい　ハスボーに\n"
	.string "まけない　おおきさ　かも！\p"
	.string "みせて　くれて　ありがとう\n"
	.string "おれいに　これを　あげるよ！$"

SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1: @ 0x0820FAA3
	.string "{PLAYER}は\n"
	.string "きずぐすりを　もらった！$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1: @ 0x0820FAB4
	.string "ありゃ？\n"
	.string "きみ　もちもの　いっぱいだね$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot: @ 0x0820FAC8
	.string "{STR_VAR_2}cmか⋯⋯\p"
	.string "ううむ　わしは　これより　おおきい\n"
	.string "タネボーを　みたこと　あるな⋯⋯$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot: @ 0x0820FAF3
	.string "おお　こいつは　なかなか⋯⋯　って\n"
	.string "これ　タネボーじゃ　ないよ！$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot: @ 0x0820FB14
	.string "おおきい　タネボー　もってないの？\n"
	.string "それは　ざんねん⋯⋯\p"
	.string "こんど　おおきい　タネボー　みせてね$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory: @ 0x0820FB44
	.string "しじょう　さいだいの　タネボー！\n"
	.string "{STR_VAR_2}の　{STR_VAR_3}cmのやつ！\p"
	.string "ハスボーより　おおきい　タネボー\n"
	.string "いつでも　ぼしゅうちゅう！$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad: @ 0x0820FB81
	.string "きみ　ハスボーって　ポケモン　しってる？\n"
	.string "ルネでは　めったに　みられないん　だけどね\p"
	.string "わし　おおきな　ハスボーが\n"
	.string "めちゃめちゃ　だいすき　なのよ！\p"
	.string "アニキは　タネボーの　ほうが\n"
	.string "おおきいって　いうんだけど\p"
	.string "ハスボーの　ほうが\n"
	.string "おおきいに　きまってる　よね！\p"
	.string "ん？　きみ　ハスボー　もってるの？\n"
	.string "ちょ　ちょ　ちょっと⋯⋯\l"
	.string "おじさんに　みせて　おくれ！$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot: @ 0x0820FC30
	.string "{STR_VAR_2}cm！！\n"
	.string "おお！　こいつは　でかい！\p"
	.string "あにきが　みた　でかい　タネボーに\n"
	.string "まけない　おおきさ　かも！\p"
	.string "みせて　くれて　ありがとう\n"
	.string "おれいに　これを　あげるよ！$"

SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2: @ 0x0820FC82
	.string "{PLAYER}は\n"
	.string "きずぐすりを　もらった！$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2: @ 0x0820FC93
	.string "ありゃ？\n"
	.string "きみ　もちもの　いっぱいだね$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad: @ 0x0820FCA7
	.string "{STR_VAR_2}cmか⋯⋯\p"
	.string "ううむ　わしは　これより　おおきい\n"
	.string "ハスボーを　みたこと　あるな⋯⋯$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad: @ 0x0820FCD2
	.string "おお　こいつは　なかなか⋯⋯　って\n"
	.string "これ　ハスボーじゃ　ないよ！$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad: @ 0x0820FCF3
	.string "おおきい　ハスボー　もってないの？\n"
	.string "それは　ざんねん⋯⋯\p"
	.string "こんど　おおきい　ハスボー　みせてね$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory: @ 0x0820FD23
	.string "しじょう　さいだいの　ハスボー！\n"
	.string "{STR_VAR_2}の　{STR_VAR_3}cmのやつ！\p"
	.string "タネボーより　おおきい　ハスボー\n"
	.string "いつでも　ぼしゅうちゅう！$"
