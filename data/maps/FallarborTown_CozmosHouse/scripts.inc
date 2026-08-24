@ FallarborTown_CozmosHouse scripts (JP map g5 m6 @ 0x081F5E78)

FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "ソライシ“ああ⋯⋯\n"
	.string "マグマだんに　だまされたからと　いって\l"
	.string "いんせきが　てに　はいる　ばしょを\l"
	.string "おしえてしまったら　だめ　だなあ⋯⋯\p"
	.string "りゅうせいのたき　の　いんせき\n"
	.string "もう　ぼくの　モノには　ならないよな⋯⋯$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "おお！　ええ？\p"
	.string "それは⋯⋯\p"
	.string "もしかして　もしかすると⋯⋯\p"
	.string "マグマだんが　りゅうせいのたき　から\n"
	.string "もっていった　いんせき　ですか⋯⋯！？\p"
	.string "よかったら　ぼくに　ください！\p"
	.string "ただで　とは　いいません\n"
	.string "かわりに　この　わざマシンを\l"
	.string "あげますから⋯⋯$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "ソライシ“この　わざマシンは\n"
	.string "ぼくの　きもちです\l"
	.string "ぜひ　つかってください！$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "ソライシ“いやー　すごく　うれしいな\n"
	.string "これで　ぼくの　けんきゅうも　はかどります！$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "ソライシ“そんな⋯⋯\n"
	.string "ものすごく　がっかりだよ⋯⋯$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "ソライシ“その　いんせき⋯⋯\n"
	.string "よかったら　ぼくに　ください！\p"
	.string "ただで　とは　いいません\n"
	.string "かわりに　この　わざマシンを\l"
	.string "あげますから⋯⋯$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "ソライシはかせは\n"
	.string "マグマだんの　ひとと　いっしょに\l"
	.string "114ばん　どうろに　ある\l"
	.string "りゅうせいのたきに　いきましたよ$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "ソライシはかせ⋯⋯\n"
	.string "あんなに　おちこんで　かわいそう！$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "ソライシはかせ　ったら\n"
	.string "あんなに　よろこんで　かわいい！$"
