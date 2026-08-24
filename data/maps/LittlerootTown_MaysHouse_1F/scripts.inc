@ LittlerootTown_MaysHouse_1F scripts (JP map g1 m2 @ 0x081F0358)

LittlerootTown_MaysHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_1F_OnLoad::
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 0x6, LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 0x5, 0x4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 0x5, 0x2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 0x6, 0x7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_MaysHouse_1F_OnTransition::
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 0x3, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 0x5, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 0x6, LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 0x2, 0x4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 0x6, 0x5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 0x1, 0x8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_OnFrame::
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0x3, LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0x5, LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0x6, LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 0x1, LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 0x3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
	waitmovement 0x0
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 0x1, 0x1
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, FEMALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, FEMALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	end

LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0x0
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	waitmovement 0x0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
	waitmovement 0x0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 0x2
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RivalsHouse_1F_EventScript_RivalMom::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 0x3, RivalsHouse_1F_EventScript_RivalTooBusy
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalTooBusy::
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalIsOnRoute103::
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_GoHomeEverySoOften::
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalSibling::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, FEMALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0x0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0x0
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 0x1
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 0x2
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 0xA
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 0x1E
	playse SE_PIN
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0x0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	waitmovement 0x0
	call_if_ne VAR_0x8008, 0x1, LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_eq VAR_0x8008, 0x0, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0
	call_if_eq VAR_0x8008, 0x1, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1
	call_if_eq VAR_0x8008, 0x2, LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0x0, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0
	call_if_eq VAR_0x8008, 0x1, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1
	call_if_eq VAR_0x8008, 0x2, LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	delay 0x1E
	setvar VAR_LITTLEROOT_RIVAL_STATE, 0x3
	setvar VAR_LITTLEROOT_TOWN_STATE, 0x1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2::
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
	waitmovement 0x0
	return

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

RivalsHouse_1F_Text_OhYoureTheNewNeighbor: @ 0x081F0678
	.string "えーと　どなた　かしら？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "そうか　あなたが　おとなりに\n"
	.string "ひっこしてきた　{PLAYER}{KUN}　ね！\p"
	.string "うちにも　あなたと　おなじ　としごろの\n"
	.string "{STR_VAR_1}が　いるのよ！\p"
	.string "‘あたらしい　おともだちが　できる！’\n"
	.string "なんて　いって\l"
	.string "とっても　たのしみに　してたの！$"

RivalsHouse_1F_Text_LikeChildLikeFather: @ 0x081F0701
	.string "おとうさんも　あのこに　まけず\n"
	.string "ポケモンに　むちゅう　なのよ\p"
	.string "けんきゅうじょに　いなければ\n"
	.string "きっと　どこかの　くさむらにでも\l"
	.string "もぐりに　いってるんじゃ　ないかしら⋯⋯$"

RivalsHouse_1F_Text_TooBusyToNoticeVisit: @ 0x081F0755
	.string "{RIVAL}ったら　せっかく　{PLAYER}{KUN}が\n"
	.string "ごあいさつに　きてくれたって　いうのに\l"
	.string "ポケモンに　むちゅう　みたいね$"

RivalsHouse_1F_Text_WentOutToRoute103: @ 0x081F078A
	.string "あら　{RIVAL}　だったら\n"
	.string "ついさっき　103ばんどうろの　ほうへ\l"
	.string "でかけて　いったわよ！\p"
	.string "まったく　おとうさんに　にて\n"
	.string "おうちで　じっとして　いられないのよね$"

RivalsHouse_1F_Text_ShouldGoHomeEverySoOften: @ 0x081F07D8
	.string "ポケモンと　いっしょに\n"
	.string "ぼうけん　するのも　いいけど\p"
	.string "たまには　おうちに　かえって　おかあさんに\n"
	.string "げんきな　かおを　みせてあげてね！\p"
	.string "こころの　なかでは　きっと\n"
	.string "{PLAYER}{KUN}の　こと\l"
	.string "しんぱい　してる　はずだから⋯⋯$"

RivalsHouse_1F_Text_MayWhoAreYou: @ 0x081F0843
	.string "あら？　あなた⋯⋯だれ？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "あなたが　{PLAYER}{KUN}⋯⋯\n"
	.string "そうか　きょう　ひっこし　だったんだ⋯⋯\p"
	.string "あ　あたし　ハルカ！\n"
	.string "よ　よろしくね\p"
	.string "あたし⋯⋯\n"
	.string "せかいじゅうの　ポケモンと\l"
	.string "ともだちに　なるのが　ゆめ　なの⋯⋯\p"
	.string "で　でね\n"
	.string "おとうさん⋯⋯　オダマキはかせ　から\l"
	.string "{PLAYER}{KUN}の　おはなし　きいて\p"
	.string "あたし　{PLAYER}{KUN}　とも\n"
	.string "おともだちに　なれたらなあ⋯⋯\l"
	.string "なんて　おもってたの⋯⋯\p"
	.string "あっ　あたしったら　{PLAYER}{KUN}と\n"
	.string "はじめて　おはなし　してるのに\l"
	.string "なに　いってんだろ⋯⋯\p"
	.string "てへへ⋯⋯\p"
	.string "あっ　いけない！\p"
	.string "あたし　おとうさんの　おてつだいで\n"
	.string "やせいの　ポケモン\l"
	.string "つかまえに　いくところ　だったんだ！\p"
	.string "でかける　したくを　するから\n"
	.string "{PLAYER}{KUN}　また　あとでね！$"

RivalsHouse_1F_Text_BrendanWhoAreYou: @ 0x081F0994
	.string "おまえ⋯⋯\p"
	.string "だれ？\p"
	.string "あっ　おまえが　となりに\n"
	.string "ひっこして　きた　{PLAYER}か⋯⋯\p"
	.string "ふうん\n"
	.string "おんなのこ　だったんだ⋯⋯\p"
	.string "とうさん⋯⋯　オダマキはかせ　から\n"
	.string "となりに　ひっこして　くるのは\l"
	.string "ジムリーダーの　こども　って　きいてたから\l"
	.string "かってに　おとこ　だと　おもってたよ\p"
	.string "オレは　ユウキ\n"
	.string "まあ　おとなりさんに　なったことだし\l"
	.string "これから　よろしくな\p"
	.string "おや？　{PLAYER}は\n"
	.string "ポケモン　もってないのか？\p"
	.string "よかったら　オレが\n"
	.string "つかまえてきて　やろうか？\p"
	.string "って　わすれてた⋯⋯\p"
	.string "オレ　とうさんの　てつだいで\n"
	.string "やせいの　ポケモン\l"
	.string "つかまえに　いく　ところ　だったんだ\p"
	.string "でかける　したくを　するから\n"
	.string "{PLAYER}　また　こんどな！$"

RivalsHouse_1F_Text_DoYouHavePokemon: @ 0x081F0ABD
	.string "わーい　おとなりさんだ！\p"
	.string "{STR_VAR_1}は　もう\n"
	.string "じぶんの　ポケモン　もってるの？$"
