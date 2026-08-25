@ Route104_MrBrineysHouse scripts (JP map g17 m0 @ 0x082115F0)

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:: @ 0x082115F6
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival:: @ 0x0821160E
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos:: @ 0x08211612
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 0x9, 0x3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 0x9, 0x6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney:: @ 0x08211629
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro:: @ 0x0821164C
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound:: @ 0x08211670
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 0x14, 0x8, MULTI_BRINEY_OFF_DEWFORD, 0x1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries:: @ 0x082116A3
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage:: @ 0x082116BC
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing:: @ 0x082116D5
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing:: @ 0x082116DF
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford:: @ 0x082116E9
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 0xD, 0x33
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko:: @ 0x0821171F
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko: @ 0x08211732
	.string "ハギ“こらこら！\n"
	.string "まて　まて　ピーコちゃん！$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford: @ 0x08211749
	.string "おや？　きみは　たしか　ピーコちゃんを\n"
	.string "たすけて　くれた　{PLAYER}{KUN}！\l"
	.string "そのせつは　せわに　なったのう！\p"
	.string "⋯⋯なぬ？　ふねに　のりたい　とな？\p"
	.string "ふむふむ？\n"
	.string "ムロに　てがみを　とどけて\l"
	.string "カイナへ　にもつを　とどける⋯⋯\l"
	.string "なんだか　いそがしいのう　きみは\p"
	.string "じゃが　それくらい　おやすい　ごようだ！\n"
	.string "わしに　まかせて　おきなさい！\l"
	.string "では　まず　ムロに　むかうとするか！$"

Route104_MrBrineysHouse_Text_SetSailForDewford: @ 0x082117FE
	.string "ハギ“ムロタウン　か\p"
	.string "よっしゃ！　いくぞ　ピーコちゃん！$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail: @ 0x0821181B
	.string "ハギ“そうかね\n"
	.string "たのまれごとは　いいのかね？\p"
	.string "まあ　ふねに　のる　ひつようが　あるときは\n"
	.string "いつでも　えんりょなく　いっておくれ！$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford: @ 0x0821185C
	.string "ハギ“きみの　いいたいことは　わかっとる！\p"
	.string "ムロに　てがみを　とどけて\n"
	.string "カイナへ　にもつを　とどけるんだろう\p"
	.string "それくらい　おやすい　ごようだ！\n"
	.string "わしに　まかせて　おきなさい！\l"
	.string "では　まず　ムロに　むかうとするか！$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford: @ 0x082118C7
	.string "ハギ“きみの　いいたいことは　わかっとる！\p"
	.string "カイナの　クスノキさんに\n"
	.string "にもつを　とどけるんだろう\p"
	.string "それくらい　おやすい　ごようだ！\n"
	.string "わしに　まかせて　おきなさい！\l"
	.string "では　まず　ムロに　むかうとするか！$"

Route104_MrBrineysHouse_Text_WhereAreWeBound: @ 0x0821192C
	.string "ハギ“やあ！　きみのため　なら\n"
	.string "いつでも　ふねを　だそう！\p"
	.string "きみが　いきたいのは　どこ　かな？$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail: @ 0x0821195C
	.string "ハギ“そうか⋯⋯　きみは\n"
	.string "ピーコちゃんの　いのちの　おんじんだ\p"
	.string "ふねに　のる　ひつようが　あるときは\n"
	.string "いつでも　えんりょなく　いっておくれ！$"

Route104_MrBrineysHouse_Text_Peeko: @ 0x082119A3
	.string "ピーコちゃん“ピー　ピひょろー！$"
