Route117_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry_jp
	special StoreSelectedPokemonInDaycare
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCostAndPrepareString
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry_jp
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Day-Care text is physically placed after the Egg Hatching script in the
@ Japanese ROM. Keep the semantic owner together while retaining this order.
EventScript_EggHatch:: @ 0x08257A89
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	releaseall
	end

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon: @ 0x08257A98
	.string "わしは　そだてや　じいさんじゃ\p"
	.string "ここで　みんなの　だいじな　ポケモンの\n"
	.string "めんどうを　みて　おるのじゃよ\p"
	.string "なにか　そだてて　ほしければ\n"
	.string "ばあさんに　たのんで　おくれ$"

Route117_Text_DoYouWantEgg: @ 0x08257AEA
	.string "おお！　あんたか\p"
	.string "あずかっていた　ポケモンを\n"
	.string "そだてていたら⋯⋯なんと！\p"
	.string "ポケモンが　タマゴを\n"
	.string "もっておったんじゃ！\p"
	.string "どこから　もってきたか　わからんが\n"
	.string "あんたの　ポケモンが　もってたんじゃ\p"
	.string "やっぱり　ほしいじゃろ？$"

Route117_Text_YourMonIsDoingFine: @ 0x08257B57
	.string "おお　あんたか！　よくきたな\n"
	.string "{STR_VAR_1}は　げんきじゃぞ$"

Route117_Text_IllKeepIt: @ 0x08257B71
	.string "それじゃ　わしが　もらおう\n"
	.string "ありがとよ$"

Route117_Text_YouHaveNoRoomForIt: @ 0x08257B85
	.string "てもちが　いっぱいの　ようじゃな⋯\n"
	.string "てもちを　せいりしてから　またきなさい$"

Route117_Text_ReceivedEgg: @ 0x08257BAB
	.string "{PLAYER}は　そだてや　じいさんから\n"
	.string "タマゴを　もらった！$"

Route117_Text_TakeGoodCareOfIt: @ 0x08257BC6
	.string "だいじにそだてなさいよ！$"

Route117_Text_FriendlyWithOtherTrainersMon: @ 0x08257BD3
	.string "ところで　あんたの　{STR_VAR_1}じゃが\p"
	.string "なんか　{STR_VAR_2}とこの　{STR_VAR_3}と\n"
	.string "なかよく　あそんで　おったぞ\p"
	.string "しかも　なにやら　メールを\n"
	.string "もらっておった　ようじゃ$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon: @ 0x08257C1B
	.string "ポケモンを　ひきとりたい　ときは\n"
	.string "ばさんに　いって　おくれ$"

Route117_Text_YourMonsAreDoingFine: @ 0x08257C39
	.string "おお　あんたか！　よくきたな\n"
	.string "{STR_VAR_1}と　{STR_VAR_2}は　げんきじゃぞ$"

Route117_Text_IWillKeepDoYouWantIt: @ 0x08257C57
	.string "わしが　もらってしまうぞ\n"
	.string "ほんとうは　ほしいんじゃろ？$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon: @ 0x08257C73
	.string "わしは　そだてや　ばあさんじゃ\p"
	.string "おまえさんの　かわりに　ポケモンを\n"
	.string "そだてて　あげるよ\p"
	.string "なにか　そだてて　ほしいのかい？$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise: @ 0x08257CB0
	.string "どのこを　そだてて　みるかね？$"

Route117_PokemonDayCare_Text_WellRaiseYourMon: @ 0x08257CC0
	.string "それでは　{STR_VAR_1}を\n"
	.string "しばらく　あずかるぞ\p"
	.string "てきとうに　じかんが\n"
	.string "たったら　またきなさい$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore: @ 0x08257CEB
	.string "2ひき　までなら　あずかれるけど\n"
	.string "もう　1ぴき　そだててみるかい？$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou: @ 0x08257D0D
	.string "じいさんが　あんたを　さがして　おったぞ$"

Route117_PokemonDayCare_Text_FineThenComeAgain: @ 0x08257D22
	.string "そうかい　それじゃ　また　きておくれ$"

Route117_PokemonDayCare_Text_NotEnoughMoney: @ 0x08257D35
	.string "おかねが　たりない　ようじゃのう⋯$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo: @ 0x08257D47
	.string "もう　1ぴきも　ひきとるかい？$"

Route117_PokemonDayCare_Text_ComeAgain: @ 0x08257D57
	.string "それじゃ　また　きておくれ$"

Route117_PokemonDayCare_Text_GoodToSeeYou: @ 0x08257D65
	.string "おお　あんたか！　よくきたな\n"
	.string "おまえさんの　ポケモンは　ゲンキじゃぞ$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels: @ 0x08257D88
	.string "{STR_VAR_1}は　レベルで　いうと\n"
	.string "{STR_VAR_2}くらい　そだって　おるぞ$"

Route117_PokemonDayCare_Text_YourTeamIsFull: @ 0x08257DA4
	.string "てもちの　ポケモンがいっぱいじゃよ！\n"
	.string "ポケモンを　せいりしてから　きなさい$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon: @ 0x08257DCA
	.string "どっちの　ポケモンを　ひきとるかい？$"

Route117_PokemonDayCare_Text_ItWillCostX: @ 0x08257DDD
	.string "{STR_VAR_1}を　ひきとるなら\n"
	.string "りょうきんは　{STR_VAR_2}¥　だよ$"

Route117_PokemonDayCare_Text_HeresYourMon: @ 0x08257DF6
	.string "はいよ　たしかに！\n"
	.string "じゃあ　ポケモンを　つれていきなさい！$"

Route117_PokemonDayCare_Text_TookBackMon: @ 0x08257E14
	.string "{PLAYER}は　そだてや　ばあさんから\n"
	.string "{STR_VAR_1}を　ひきとった！$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon: @ 0x08257E2F
	.string "おや？　ポケモンが\n"
	.string "1ぴき　しか　いないようだな\p"
	.string "また　きなさいよ$"

Route117_PokemonDayCare_Text_TakeYourMonBack: @ 0x08257E51
	.string "ポケモンを　ひきとるかい？$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith: @ 0x08257E5F
	.string "その　ポケモンを　あずけると\n"
	.string "たたかえなく　なるぞ\p"
	.string "また　きなさいよ$"

Text_EggHatchHuh: @ 0x08257E82
	.string "おや⋯？$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne: @ 0x08257E87
	.string "おや？　おまえさん\n"
	.string "その　ポケモンを　あずけると\l"
	.string "ぜんぶで　ポケモンが　1ぴき　だけに\l"
	.string "なって　しまう　みたいじゃな\p"
	.string "もうちょっと　たくさん　つかまえてから\n"
	.string "きてみては　どうじゃ？$"
