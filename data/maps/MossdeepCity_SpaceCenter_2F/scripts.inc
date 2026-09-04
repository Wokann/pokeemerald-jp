@ MossdeepCity_SpaceCenter_2F scripts (JP map g14 m10 @ 0x0820D682)

MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition:: @ 0x0820D68D
	call_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
	call_if_eq VAR_MOSSDEEP_SPACE_CENTER_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
	end

MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians:: @ 0x0820D6A4
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 0x5, 0x3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_RICH_BOY, 0x3, 0x2
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_2F_GENTLEMAN, 0x1, 0x3
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts:: @ 0x0820D6C9
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_6, 0xB, 0x2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_7, 0xF, 0x2
	setobjectxyperm LOCALID_SPACE_CENTER_GRUNT_5, 0xD, 0x4
	return

MossdeepCity_SpaceCenter_2F_OnFrame:: @ 0x0820D6DF
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 0x1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts:: @ 0x0820D6E9
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 0xD, 0x1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_PlayerExit:
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts:: @ 0x0820D733
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
	applymovement LOCALID_SPACE_CENTER_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 0x2
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_6
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_7
	copyobjectxytoperm LOCALID_SPACE_CENTER_GRUNT_5
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_Scientist:: @ 0x0820D7B7
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal:: @ 0x0820D7DE
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma:: @ 0x0820D7E8
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Gentleman:: @ 0x0820D7F2
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal:: @ 0x0820D819
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma:: @ 0x0820D823
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoy:: @ 0x0820D82D
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 0x2, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal:: @ 0x0820D854
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma:: @ 0x0820D85E
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt6:: @ 0x0820D868
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt7:: @ 0x0820D871
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Grunt5:: @ 0x0820D87A
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_Tabitha:: @ 0x0820D883
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_Maxie:: @ 0x0820D899
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_Steven:: @ 0x0820D8A4
	lockall
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
	closemessage
	delay 0x1E
	playse SE_NOT_EFFECTIVE
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
	applymovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth:: @ 0x0820D8E4
	applymovement LOCALID_SPACE_CENTER_2F_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_StevenFight:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth:
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt:: @ 0x0820D904
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle:: @ 0x0820D936
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0x0, MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt

MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle:: @ 0x0820D95C
	special ReducePlayerPartyToSelectedMons
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_STEVEN
	setvar VAR_0x8005, 0x0
	special DoSpecialTrainerBattle
	frontier_saveparty
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut

MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha:: @ 0x0820D99B
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
	closemessage
	delay 0x14
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 0x3C
	applymovement LOCALID_SPACE_CENTER_MAXIE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_SPACE_CENTER_TABITHA, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 0x14
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MOSSDEEP_CITY_STATE, 0x3
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 0x3
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	removeobject LOCALID_SPACE_CENTER_GRUNT_6
	removeobject LOCALID_SPACE_CENTER_GRUNT_7
	removeobject LOCALID_SPACE_CENTER_GRUNT_5
	removeobject LOCALID_SPACE_CENTER_TABITHA
	removeobject LOCALID_SPACE_CENTER_MAXIE
	setobjectxy LOCALID_SPACE_CENTER_2F_SCIENTIST, 0x5, 0x6
	turnobject LOCALID_SPACE_CENTER_2F_SCIENTIST, DIR_SOUTH
	setobjectxy LOCALID_SPACE_CENTER_2F_GENTLEMAN, 0xB, 0x8
	turnobject LOCALID_SPACE_CENTER_2F_GENTLEMAN, DIR_NORTH
	setobjectxy LOCALID_SPACE_CENTER_2F_RICH_BOY, 0x6, 0x2
	turnobject LOCALID_SPACE_CENTER_2F_RICH_BOY, DIR_NORTH
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
	fadescreen FADE_FROM_BLACK
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	removeobject LOCALID_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 0x1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	removeobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	setobjectxyperm LOCALID_SPACE_CENTER_2F_SCIENTIST, 0x5, 0x6
	setobjectmovementtype LOCALID_SPACE_CENTER_2F_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
	addobject LOCALID_SPACE_CENTER_2F_SCIENTIST
	fadescreen FADE_FROM_BLACK
	end

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer:: @ 0x0820DA5B
	switch VAR_FACING
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth:: @ 0x0820DA77
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_NORTH
	return

MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest:: @ 0x0820DA7C
	turnobject LOCALID_SPACE_CENTER_2F_STEVEN, DIR_EAST
	return

MossdeepCity_SpaceCenter_2F_EventScript_MaxieTrainer:: @ 0x0820DA81
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_MAXIE_MOSSDEEP, LOCALID_NONE, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
	end

MossdeepCity_SpaceCenter_2F_EventScript_TabithaTrainer:: @ 0x0820DA90
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_TABITHA_MOSSDEEP, LOCALID_NONE, MossdeepCity_SpaceCenter_Text_TabithaDefeat, MossdeepCity_SpaceCenter_Text_TabithaDefeat
	end

MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall:: @ 0x0820DA9F
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
	call_if_eq VAR_RESULT, FEMALE, MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall:: @ 0x0820DABD
	pokenavcall MatchCall_Text_MayRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall:: @ 0x0820DAC4
	pokenavcall MatchCall_Text_BrendanRayquazaCall
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets: @ 0x0820DACB
	.string "トクサネは　てんきの　よい　ひが　おおい\n"
	.string "かぜの　むきも　あんてい　している\p"
	.string "ロケットを　うちあげる　には\n"
	.string "もってこいの　ばしょ　なんですな$"

MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel: @ 0x0820DB12
	.string "ロケットの　ねんりょうなんか　うばって\n"
	.string "マグマだんは　なにする　つもりだ！？$"

MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut: @ 0x0820DB39
	.string "わしも　もうすこし　わかければ\n"
	.string "うちゅう　ひこうしに　なりたかった⋯⋯\p"
	.string "いや　いまからでも　おそくない！\n"
	.string "よーし　がんばるぞー！！$"

MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis: @ 0x0820DB7B
	.string "マグマだんに　ねんりょうを　うばわれたら\n"
	.string "わしが　うちゅうに　いけなくなる！\p"
	.string "そんなこと　させて　たまるかー！$"

MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace: @ 0x0820DBB3
	.string "いつか　ふつーの　ひとも\n"
	.string "うちゅうに　いけると　いいのにな⋯⋯$"

MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace: @ 0x0820DBD3
	.string "マグマだんも⋯⋯\n"
	.string "うちゅうに　いきたいの　かな？$"

MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn: @ 0x0820DBEC
	.string "なんだ　おまえ！\p"
	.string "おれたち　3にんに　かこまれてるのに\n"
	.string "やろうってのか！？$"

MossdeepCity_SpaceCenter_2F_Text_GoodAnswer: @ 0x0820DC12
	.string "だよな！\n"
	.string "そのほうが　おりこうさん　だぜ！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro: @ 0x0820DC28
	.string "むてっぽうな　やつめ⋯⋯\n"
	.string "まずは　オレからだ！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat: @ 0x0820DC40
	.string "オレは　まけたが　しかし！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro: @ 0x0820DC4E
	.string "あんしん　するのは　まだ　はやい\n"
	.string "つぎは　オレが　あいてだ！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat: @ 0x0820DC6D
	.string "オレも　まけたが　だけど！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro: @ 0x0820DC7B
	.string "ひとやすみ　したいだろう　けど\n"
	.string "そんな　わけには　いきませーん！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat: @ 0x0820DC9C
	.string "オレたちが　ひとやすみ\n"
	.string "しておけば⋯⋯　よかった⋯⋯$"

MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle: @ 0x0820DCB7
	.string "3にんも　いて　このザマか！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle: @ 0x0820DCC6
	.string "3にんがかりで　まけると\n"
	.string "いつもの　3ばい　かっこわるいぜ！$"

MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle: @ 0x0820DCE5
	.string "オレたち　リーダーの\n"
	.string "やくに　たってるのかな⋯⋯？$"

MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou: @ 0x0820DCFF
	.string "ウヒョヒョ！　せっかく\n"
	.string "ねんりょうを　いただきに　きたのに\l"
	.string "ジャマが　はいっちまった！\p"
	.string "おまえも　オレたちの　ジャマを　するなら\n"
	.string "いっしょに　かたづけて　やろうか！$"

MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere: @ 0x0820DD52
	.string "マツブサ“えーい　そこをどけ！\n"
	.string "われわれの　ジャマを　するんじゃない！$"

MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel: @ 0x0820DD76
	.string "ダイゴ“マグマだん⋯⋯\n"
	.string "ロケットの　ねんりょうなんか　ぬすんで\l"
	.string "いったい　なにをする　つもりなんだ！$"

MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano: @ 0x0820DDA9
	.string "マツブサ“ふふふ⋯⋯\n"
	.string "そんなに　しりたけりゃ　おしえてやろう\p"
	.string "えんとつやまの　かこうに\n"
	.string "ぜんぶ　なげこんで　やるのさ！\p"
	.string "グラードンも　きえてしまった　ことだし\n"
	.string "もう　あんなやまに　ようはない\p"
	.string "だから　ねんりょうの　ちからを　りようして\n"
	.string "かざんを　ふんか　させて　やるのさ\l"
	.string "ズドドーン　とな！$"

MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle: @ 0x0820DE3B
	.string "ダイゴ“{PLAYER}{KUN}！\n"
	.string "ちからを　かして　くれるのかい！？\p"
	.string "ボクと　いっしょに　たたかおう！\n"
	.string "じゅんびは　いいね？$"

MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly: @ 0x0820DE73
	.string "ダイゴ“じゃあ　いそいで\n"
	.string "じゅんびを　ととのえて　くるんだ！$"

MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand: @ 0x0820DE92
	.string "わたしは　ただ⋯⋯\n"
	.string "りくちを　ふやしたい　だけなのに⋯⋯$"

MossdeepCity_SpaceCenter_Text_TabithaDefeat: @ 0x0820DEAF
	.string "みぎに　おなじ　だ⋯⋯$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided: @ 0x0820DEBB
	.string "マツブサ“われわれは　かざんを\n"
	.string "ふんか　させられ　なかった⋯⋯\p"
	.string "ねむりから　めざめた　グラードンも\n"
	.string "コントロール　できなかった⋯⋯\p"
	.string "りくちをふやす　という　かんがえは\n"
	.string "まちがって　いるのか？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "もしも⋯⋯　われわれ　マグマだんが\n"
	.string "まちがっていると　いうのなら\l"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "まさか　アクアだんの\n"
	.string "うみをふやす　という　かんがえも⋯⋯$"

MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp: @ 0x0820DF75
	.string "マツブサ“わかった⋯⋯\n"
	.string "ねんりょうは　あきらめよう⋯⋯\p"
	.string "わたしには　ほかに　たしかめ　なければ\n"
	.string "ならない　ことが　あるようだ⋯⋯$"

MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome: @ 0x0820DFB6
	.string "ダイゴ“ふう　あぶない　ところ　だった\n"
	.string "{PLAYER}{KUN}　ありがとう\p"
	.string "ちからを　かしてくれた　おれいに\n"
	.string "いいものを　あげるから\l"
	.string "あとで　いえまで　きておくれ\p"
	.string "ボクのいえは　カナズミ　じゃないよ\n"
	.string "このしまに　あるんだ$"
