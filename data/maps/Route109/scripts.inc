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
	trainerbattle_single TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated
	msgbox Route109_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Alice::
	trainerbattle_single TRAINER_ALICE, Route109_Text_AliceIntro, Route109_Text_AliceDefeated
	msgbox Route109_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated
	msgbox Route109_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Edmond::
	trainerbattle_single TRAINER_EDMOND, Route109_Text_EdmondIntro, Route109_Text_EdmondDefeated
	msgbox Route109_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Route109_EventScript_RickyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_RickyRematch
	msgbox Route109_Text_RickyPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_RickyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route109_Text_RickyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICKY_1
	release
	end

Route109_EventScript_RickyRematch::
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_RickyRematchIntro, Route109_Text_RickyRematchDefeated
	msgbox Route109_Text_RickyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Route109_EventScript_LolaRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route109_EventScript_LolaRematch
	msgbox Route109_Text_LolaPostBattle, MSGBOX_DEFAULT
	release
	end

Route109_EventScript_LolaRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route109_Text_LolaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA_1
	release
	end

Route109_EventScript_LolaRematch::
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_LolaRematchIntro, Route109_Text_LolaRematchDefeated
	msgbox Route109_Text_LolaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Austina::
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated
	msgbox Route109_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Gwen::
	trainerbattle_single TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated
	msgbox Route109_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER, Route109_Text_CarterIntro, Route109_Text_CarterDefeated
	msgbox Route109_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Paul::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_PaulIntro, Route109_Text_PaulDefeated, Route109_Text_PaulNotEnoughPokemon
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Mel::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_MelIntro, Route109_Text_MelDefeated, Route109_Text_MelNotEnoughPokemon
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Chandler::
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated
	msgbox Route109_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Hailey::
	trainerbattle_single TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated
	msgbox Route109_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_EventScript_Elijah::
	trainerbattle_single TRAINER_ELIJAH, Route109_Text_ElijahIntro, Route109_Text_ElijahDefeated
	msgbox Route109_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Text_BrineyLandedInSlateportDeliverGoods: @ 0x081E8B34
	.globl gJPText_001E8B34
	.set gJPText_001E8B34, DewfordTown_Text_BrineyLandedInSlateportDeliverGoods
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
