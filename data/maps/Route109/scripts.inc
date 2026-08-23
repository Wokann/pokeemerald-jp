@ Route109 scripts (JP map g0 m24 @ 0x081E8676)

Route109_MapScripts::
	.byte 0

Route109_EventScript_StartDepartForDewford::
	call 0x08242F21
	setobjectsubpriority 0x2, 0x18, 0x0
	setobjectsubpriority 0xFF, 0x18, 0x0
	applymovement 0x2, Route109_Movement_BrineyEnterBoat
	waitmovement 0x0
	removeobject 0x2
	copyvar VAR_0x8000, 0x800C
	goto_if_eq VAR_0x8000, 0x1, Route109_EventScript_EnterBoatSouth
	goto_if_eq VAR_0x8000, 0x3, Route109_EventScript_EnterBoatWest
	goto_if_eq VAR_0x8000, 0x4, Route109_EventScript_EnterBoatEast
	end

Route109_EventScript_EnterBoatSouth::
	applymovement 0xFF, Route109_Movement_PlayerEnterBoatSouth
	waitmovement 0x0
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_EnterBoatEast::
	applymovement 0xFF, Route109_Movement_PlayerEnterBoatEast
	waitmovement 0x0
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_EnterBoatWest::
	applymovement 0xFF, Route109_Movement_PlayerEnterBoatWest
	waitmovement 0x0
	goto Route109_EventScript_DoSailToDewford
	end

Route109_EventScript_DoSailToDewford::
	hideobject_at 0xFF, 0x18
	call 0x0824312C
	applymovement 0x1, Route109_Movement_SailToDewford
	applymovement 0xFF, Route109_Movement_SailToDewford
	waitmovement 0x0
	delay 0x32
	call 0x08243134
	showobject_at 0xFF, 0xB
	applymovement 0xFF, Route109_Movement_PlayerExitBoat
	waitmovement 0x0
	addobject 0x4
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setobjectxyperm 0x2, 0xC, 0x8
	addobject 0x2
	setobjectsubpriority 0x2, 0xB, 0x0
	applymovement 0x2, Route109_Movement_BrineyExitBoat
	waitmovement 0x0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	hideobject_at 0x1, 0x18
	msgbox 0x081E522C, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority 0xFF, 0x18
	resetobjectsubpriority 0x2, 0xB
	moveobjectoffscreen 0x2
	release
	end

Route109_Movement_SailToDewford:
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

Route109_Movement_PlayerEnterBoatSouth:
	walk_down
	walk_down
	step_end

Route109_Movement_PlayerExitBoat:
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_right
	step_end

Route109_Movement_PlayerEnterBoatEast:
	walk_right
	walk_down
	step_end

Route109_Movement_PlayerEnterBoatWest:
	walk_left
	walk_down
	step_end

Route109_Movement_BrineyEnterBoat:
	walk_down
	step_end

Route109_Movement_BrineyExitBoat:
	walk_down
	walk_in_place_faster_left
	step_end

Route109_EventScript_MrBriney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route109_EventScript_HaveNotDeliveredDevonGood
	goto Route109_EventScript_DeliveredDevonGoods
	end

Route109_EventScript_HaveNotDeliveredDevonGood::
	message Route109_Text_BrineySailToDewfordQuestion
	msgbox Route109_Text_BrineySailToDewfordQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0x0, Route109_EventScript_StayHere
	goto Route109_EventScript_SailToDewford
	end

Route109_EventScript_DeliveredDevonGoods::
	message Route109_Text_BrineyWhereAreWeBound
	waitmessage
	multichoicedefault 0x15, 0x8, MULTI_BRINEY_OFF_DEWFORD, 0x1, 0x0
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, Route109_EventScript_SailToDewford
	goto_if_eq VAR_0x8000, 0x1, Route109_EventScript_ChoseNotToSail
	goto_if_eq VAR_0x8000, 0x7F, Route109_EventScript_ChoseNotToSail
	end

Route109_EventScript_SailToDewford::
	msgbox Route109_Text_BrineyDewfordItIs, MSGBOX_DEFAULT
	closemessage
	goto Route109_EventScript_StartDepartForDewford
	end

Route109_EventScript_StayHere::
	msgbox Route109_Text_BrineyDeliverDevonGoods, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_ChoseNotToSail::
	msgbox Route109_Text_BrineyTellMeWhenYouNeedToSail, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_SeashoreHouseGirl::
	msgbox Route109_Text_ChillAtMyPapasSpot, MSGBOX_NPC
	end

Route109_EventScript_SandCastleBoy::
	lock
	faceplayer
	msgbox Route109_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route109_EventScript_SoftSandGirl::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_AlreadyReceivedSoftSand
	msgbox Route109_Text_YouCanHaveThis, MSGBOX_DEFAULT
	setorcopyvar VAR_0x8000, ITEM_SOFT_SAND
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	goto_if_eq VAR_RESULT, 0x0, 0x082430E0
	closemessage
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	setflag FLAG_RECEIVED_SOFT_SAND
	release
	end

Route109_EventScript_AlreadyReceivedSoftSand::
	msgbox Route109_Text_WereGoingToMakeBigCastle, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, 0x08243625
	waitmovement 0x0
	release
	end

Route109_EventScript_Woman::
	msgbox Route109_Text_LittleKidsDartAround, MSGBOX_NPC
	end

Route109_EventScript_OldMan::
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
	end

Route109_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0x0
	msgbox Route109_Text_ZigzagoonCry, MSGBOX_DEFAULT
	waitdooranim
	release
	end

Route109_EventScript_SeashoreHouseSign::
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
	end

Route109_EventScript_TrainerTipsSign::
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
	end

Route109_EventScript_David::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_DAVID, 0x0, 0x0825ADE1, 0x0825ADFF
	msgbox 0x0825AE0F, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Alice::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_ALICE, 0x0, 0x0825AE36, 0x0825AE49
	msgbox 0x0825AE51, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Huey::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_HUEY, 0x0, 0x0825AE72, 0x0825AE9B
	msgbox 0x0825AEA9, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Edmond::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_EDMOND, 0x0, 0x0825AECA, 0x0825AEDF
	msgbox 0x0825AEE6, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Ricky::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_RICKY_1, 0x0, 0x0825AF16, 0x0825AF38, Route109_EventScript_RickyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, 0x1, Route109_EventScript_RickyRematch
	msgbox 0x0825AF3E, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_RickyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox 0x0825AF61, MSGBOX_DEFAULT
	setvar 0x8004, 0x40
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 0x40
	callstd 0x8
	release
	end

Route109_EventScript_RickyRematch::
	trainerbattle TRAINER_BATTLE_REMATCH, TRAINER_RICKY_1, 0x0, 0x0825AF87, 0x0825AFA4
	msgbox 0x0825AFB7, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Lola::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_LOLA_1, 0x0, 0x0825AFD3, 0x0825AFEE, Route109_EventScript_LolaRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, 0x1, Route109_EventScript_LolaRematch
	msgbox 0x0825AFF4, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_LolaRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox 0x0825B01B, MSGBOX_DEFAULT
	setvar 0x8004, 0x39
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 0x39
	callstd 0x8
	release
	end

Route109_EventScript_LolaRematch::
	trainerbattle TRAINER_BATTLE_REMATCH, TRAINER_LOLA_1, 0x0, 0x0825B034, 0x0825B057
	msgbox 0x0825B05D, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Austina::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_AUSTINA, 0x0, 0x0825B086, 0x0825B0AA
	msgbox 0x0825B0BF, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Gwen::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_GWEN, 0x0, 0x0825B0D8, 0x0825B0F3
	msgbox 0x0825B0FD, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Carter::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_CARTER, 0x0, 0x0825B117, 0x0825B12E
	msgbox 0x0825B13D, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Paul::
	trainerbattle TRAINER_BATTLE_DOUBLE, TRAINER_MEL_AND_PAUL, 0x0, 0x0825B161, 0x0825B189, 0x0825B1D0
	msgbox 0x0825B197, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Mel::
	trainerbattle TRAINER_BATTLE_DOUBLE, TRAINER_MEL_AND_PAUL, 0x0, 0x0825B202, 0x0825B223, 0x0825B26E
	msgbox 0x0825B24C, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Chandler::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_CHANDLER, 0x0, 0x0825B2A2, 0x0825B2BA
	msgbox 0x0825B2C4, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Hailey::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_HAILEY, 0x0, 0x0825B2DD, 0x0825B2F4
	msgbox 0x0825B309, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Elijah::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_ELIJAH, 0x0, 0x0825B329, 0x0825B347
	msgbox 0x0825B356, MSGBOX_AUTOCLOSE
	end

	.globl gJPText_001E8B34
gJPText_001E8B34: @ 0x081E8B34
	.string "ハギ“ほい！　カイナに　とうちゃく！\p"
	.string "たしか　クスノキさんに\n"
	.string "デボンのにもつを　とどけるんだったな！$"

Route109_Text_BrineySailToDewfordQuestion: @ 0x081E8B67
	.string "ハギ“にもつを　とどけないのかい？\p"
	.string "それとも　ムロに　もどるのかね？$"

Route109_Text_BrineyDewfordItIs: @ 0x081E8B8A
	.string "ハギ“ムロタウン　か\p"
	.string "よっしゃ！　いくぞ　ピーコちゃん！$"

Route109_Text_BrineyDeliverDevonGoods: @ 0x081E8BA7
	.string "ハギ“では　にもつを　とどけておいで\n"
	.string "わしは　ここに　いるから$"

DewfordTown_Text_BrineyLandedInSlateport: @ 0x081E8BC7
	.string "ハギ“ほい！　カイナに　とうちゃく！\p"
	.string "ふねに　のりたくなったら\n"
	.string "また　わしに　こえを　かけておくれ！$"

Route109_Text_BrineyWhereAreWeBound: @ 0x081E8BFA
	.string "ハギ“やあ！　きみのため　なら\n"
	.string "いつでも　ふねを　だそう！\p"
	.string "きみが　いきたいのは　どこ　かな？$"

Route109_Text_BrineyTellMeWhenYouNeedToSail: @ 0x081E8C2A
	.string "ハギ“ふねに　のる　ひつようが　あるときは\n"
	.string "いつでも　こえを　かけておくれ$"

Route109_Text_ChillAtMyPapasSpot: @ 0x081E8C50
	.string "あつい　トレーナーさんも\n"
	.string "あつくない　トレーナーさんも\l"
	.string "おとうさんの　おみせに　よってってー！$"

Route109_Text_LittleKidsDartAround: @ 0x081E8C80
	.string "こどもって　あちこち　うごきまわるから\n"
	.string "めを　はなせなくて　たいへん！\p"
	.string "ポケモンが　いっしょ　だから\n"
	.string "だいじょうぶ　だと　おもってるけど⋯⋯$"

Route109_Text_SandCastleTakingLongTime: @ 0x081E8CC7
	.string "なかなか　すなの　おしろ　できないね$"

Route109_Text_YouCanHaveThis: @ 0x081E8CDA
	.string "{STRING 0x02}　これ　あげる！$"

Route109_Text_WereGoingToMakeBigCastle: @ 0x081E8CE5
	.string "すなはまの　すなを　ぜーんぶ　あつめて\n"
	.string "おっきな　おしろを　つくるの\p"
	.string "それで　あたしたち\n"
	.string "おうさまと　おうじょさまに　なるの\p"
	.string "{STRING 0x02}は\n"
	.string "けらいに　してあげるね$"

Route109_Text_ZigzagoonPicksUpLitter: @ 0x081E8D34
	.string "この　あたりの　うみは　きれいだがな\p"
	.string "それでも　たまに　こうして　すてられた\n"
	.string "ゴミを　ジグザグマに　あつめてもらうよ\p"
	.string "よごれた　みずは　あめと　なって\n"
	.string "かわに　ながれこみ　のみみずと　なる⋯⋯\p"
	.string "うみを　よごすと\n"
	.string "けっきょく　じぶんらが　こまるからの$"

Route109_Text_ZigzagoonCry: @ 0x081E8DB1
	.string "ジグザグマ“ぐぐ？$"

Route109_Text_SeashoreHouseSign: @ 0x081E8DBB
	.string "‘うみの　いえ’\p"
	.string "すなはま　といえば　ポケモンしょうぶ！\n"
	.string "あつい　トレーナー　ここに　つどえ！$"

Route109_Text_TrainerTipsSign: @ 0x081E8DEB
	.string "おとくな　けいじばん！！\p"
	.string "ポケモンの　レベルが　おなじ　でも\n"
	.string "つよさまで　おなじとは　かぎりません！\p"
	.string "それに　トレーナーが　そだてた\n"
	.string "ポケモンの　ほうが　つよくなると\l"
	.string "いわれて　います！$"
