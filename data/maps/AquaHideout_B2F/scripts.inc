@ AquaHideout_B2F scripts (JP map g24 m25 @ 0x08217F9F)

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:: @ 0x08217FA5
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing:: @ 0x08217FAF
	setvar VAR_TEMP_1, 0x1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer:: @ 0x08217FB5
	lockall
	setvar VAR_0x8008, 0x1
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 0x1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt:: @ 0x08217FD9
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape:: @ 0x08217FF5
	setvar VAR_0x8008, 0x1
	setvar VAR_0x8009, 0x4
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4:: @ 0x0821805A
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated:: @ 0x08218075
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6:: @ 0x0821807F
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8:: @ 0x08218096
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro: @ 0x082180AD
	.string "ウヒョヒョ⋯⋯\p"
	.string "もう　ここまで　きたのか！\n"
	.string "おもって　いたより　やるな！\p"
	.string "だが　ここまでだ！\n"
	.string "おれは　これまでの　したっぱども　とは\l"
	.string "ひとあじ　ちがう！\p"
	.string "じかんかせぎ　なんか　しねえで\n"
	.string "おまえを　コテンパンに　してやるぜ！$"

AquaHideout_B2F_Text_MattDefeat: @ 0x0821811D
	.string "ウヒョヒョ⋯⋯\n"
	.string "まけちまったか⋯⋯$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations: @ 0x0821812F
	.string "ウヒョヒョ⋯⋯！\p"
	.string "おれが　おまえと\n"
	.string "あそんで　やっている　あいだに\l"
	.string "リーダーの　じゅんびが　ととのったぜ！$"

AquaHideout_B2F_Text_MattPostBattle: @ 0x08218165
	.string "ウヒョヒョ⋯⋯！\p"
	.string "リーダーは　どこかの　かいていにある\n"
	.string "どうくつへ　しゅっぱつ　したぜ！\p"
	.string "おいかける　つもりなら　ミナモの　さきに\n"
	.string "ひろがる　でっかい　うみを\l"
	.string "さがしまわって　みるが　いいぜ！\p"
	.string "それで　みつかれば　いいけどな⋯⋯\n"
	.string "ウヒョヒョヒョ！$"

AquaHideout_B2F_Text_Grunt4Intro: @ 0x082181E1
	.string "わっはっは　まちくたびれたぞ！\n"
	.string "おいらとも　しょうぶ　してもらおうか！$"

AquaHideout_B2F_Text_Grunt4Defeat: @ 0x08218205
	.string "まちくたびれて\n"
	.string "まけて　やぶれて⋯⋯$"

AquaHideout_B2F_Text_Grunt4PostBattle: @ 0x08218218
	.string "リーダーぁ⋯⋯\n"
	.string "こんなもんで　どうでしょー！$"

AquaHideout_B2F_Text_Grunt6Intro: @ 0x0821822F
	.string "アジト　じまんの　ワープパネル！\p"
	.string "いま　じぶんが　どこに　いるのか\n"
	.string "わかって　ないでしょ！\p"
	.string "そうやって　つかれはてた　あいてを\n"
	.string "たおすのが　さくせん　なのよ！$"

AquaHideout_B2F_Text_Grunt6Defeat: @ 0x0821827F
	.string "なによっ！\n"
	.string "ちっとも　つかれてない　じゃない！$"

AquaHideout_B2F_Text_Grunt6PostBattle: @ 0x08218297
	.string "そういえば⋯⋯　マスターボールを\n"
	.string "どこに　おいたのか　わすれちゃったわ\p"
	.string "あれを　まもっていないと\n"
	.string "リーダーに　おこられるのよ⋯⋯$"

AquaHideout_B2F_Text_Grunt8Intro: @ 0x082182D8
	.string "オレが　アクアだんに　はいって\n"
	.string "まっさきに　おぼえ　させられたのが\l"
	.string "この　ワープパネルの　はいれつだ！$"

AquaHideout_B2F_Text_Grunt8Defeat: @ 0x0821830C
	.string "ワープパネルの　ことで\n"
	.string "あたまが　いっぱい　だったから⋯⋯$"

AquaHideout_B2F_Text_Grunt8PostBattle: @ 0x0821832A
	.string "これからは　ポケモンしょうぶの\n"
	.string "コツも　おぼえて　おかないと　なあ⋯⋯$"
