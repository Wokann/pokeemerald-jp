@ Route112 scripts (JP map g0 m27 @ 0x081EAE8C)

Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_OnTransition
	.byte 0

Route112_OnTransition::
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0x0
	end

Route112_EventScript_MagmaGrunts::
	lockall
	delay 0x28
	applymovement LOCALID_ROUTE112_GRUNT_1, 0x0824362B
	waitmovement 0x0
	delay 0x14
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, 0x08243625
	waitmovement 0x0
	delay 0x28
	applymovement LOCALID_ROUTE112_GRUNT_2, 0x08243627
	waitmovement 0x0
	delay 0x14
	msgbox Route112_Text_YeahWeNeedMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, 0x08243625
	waitmovement 0x0
	delay 0x28
	applymovement LOCALID_ROUTE112_GRUNT_1, 0x0824362B
	waitmovement 0x0
	delay 0x14
	msgbox Route112_Text_OhThatsWhyCrewWentToFallarbor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_1, 0x08243625
	waitmovement 0x0
	delay 0x28
	applymovement LOCALID_ROUTE112_GRUNT_2, 0x08243627
	waitmovement 0x0
	delay 0x14
	msgbox Route112_Text_CantLetAnyonePassUntilTheyreBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE112_GRUNT_2, 0x08243625
	waitmovement 0x0
	releaseall
	end

Route112_EventScript_MtChimneyCableCarSign::
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end

Route112_EventScript_MtChimneySign::
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end

Route112_EventScript_RouteSignLavaridge::
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end

Route112_EventScript_Hiker::
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end

Route112_EventScript_Brice::
	trainerbattle_single TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat
	msgbox Route112_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Trent::
	trainerbattle_single TRAINER_TRENT_1, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Route112_EventScript_RegisterTrent
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route112_EventScript_RematchTrent
	msgbox Route112_Text_TrentPostBattle, MSGBOX_DEFAULT
	release
	end

Route112_EventScript_RegisterTrent::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route112_Text_TrentRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRENT_1
	release
	end

Route112_EventScript_RematchTrent::
	trainerbattle_rematch TRAINER_TRENT_1, Route112_Text_TrentRematchIntro, Route112_Text_TrentRematchDefeat
	msgbox Route112_Text_TrentRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Larry::
	trainerbattle_single TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat
	msgbox Route112_Text_LarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Carol::
	trainerbattle_single TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat
	msgbox Route112_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Bryant::
	trainerbattle_single TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat
	msgbox Route112_Text_BryantPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_EventScript_Shayla::
	trainerbattle_single TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat
	msgbox Route112_Text_ShaylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route112_Text_LeaderGoingToAwakenThing: @ 0x081EB023
	.string "なあ　おい　リーダーは　ほんとうに\n"
	.string "アイツを　めざめさせる　つもりか？$"

Route112_Text_YeahWeNeedMeteorite: @ 0x081EB047
	.string "そうらしいな⋯⋯　だが　そのためには\n"
	.string "いんせきが　ひつよう　なんだってよ$"

Route112_Text_OhThatsWhyCrewWentToFallarbor: @ 0x081EB06C
	.string "ははーん　それで　さっき\n"
	.string "なかまが　ハジツゲに　むかったのか$"

Route112_Text_CantLetAnyonePassUntilTheyreBack: @ 0x081EB08B
	.string "ああ　かれらが　もどってくる　までは\n"
	.string "だれも　ここを　とおすな！　ってよ$"

Route112_Text_NotEasyToGetBackToLavaridge: @ 0x081EB0B0
	.string "うーむ⋯⋯　キンセツに　いきたいのだが⋯⋯\n"
	.string "この　だんさを　おりてしまうと\l"
	.string "フエンに　もどるのは　たいへん　だよな⋯⋯$"

Route112_Text_MtChimneyCableCarSign: @ 0x081EB0EC
	.string "‘えんとつやま　ロープウェイ　のりば’\n"
	.string "{UP_ARROW}　このさき　すぐ！$"

Route112_Text_MtChimneySign: @ 0x081EB10D
	.string "‘えんとつやま’\p"
	.string "フエンタウンや　ちょうじょう　へは\n"
	.string "ロープウェイを　ごりよう　ください$"

Route112_Text_RouteSignLavaridge: @ 0x081EB13A
	.string "ここは　112ばん　どうろ\n"
	.string "{LEFT_ARROW}　フエンタウン$"
