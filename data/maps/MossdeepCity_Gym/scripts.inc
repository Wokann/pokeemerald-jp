@ MossdeepCity_Gym scripts (JP map g14 m0 @ 0x0820B369)

MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

MossdeepCity_Gym_OnLoad:: @ 0x0820B36F
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2:: @ 0x0820B37E
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3:: @ 0x0820B38D
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4:: @ 0x0820B39C
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

MossdeepCity_Gym_EventScript_SetSwitch1Metatiles:: @ 0x0820B3A6
	setmetatile 0x5, 0x5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 0x2, 0x7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles:: @ 0x0820B3BE
	setmetatile 0x8, 0xE, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 0x8, 0xA, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles:: @ 0x0820B3D6
	setmetatile 0xF, 0x11, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 0x11, 0xF, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles:: @ 0x0820B3EE
	setmetatile 0x1, 0x17, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 0x5, 0x18, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza:: @ 0x0820B401
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated:: @ 0x0820B43A
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 0x7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 0x1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 0x1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 0x1E
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 0x1E
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2:: @ 0x0820B4A0
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind:: @ 0x0820B4C4
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch:: @ 0x0820B4E7
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Switch1:: @ 0x0820B502
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0x5, 0x5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 0x2, 0x7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed:: @ 0x0820B531
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1:: @ 0x0820B539
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0x5, 0x5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 0x2, 0x7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2:: @ 0x0820B55E
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0x8, 0xE, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 0x8, 0xA, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2:: @ 0x0820B58D
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0x8, 0xE, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 0x8, 0xA, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3:: @ 0x0820B5B2
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0xF, 0x11, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 0x11, 0xF, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3:: @ 0x0820B5E1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0xF, 0x11, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 0x11, 0xF, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4:: @ 0x0820B606
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0x1, 0x17, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 0x5, 0x18, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4:: @ 0x0820B635
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 0x1, 0x17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 0x5, 0x18, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance:: @ 0x0820B65A
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 0x7, 0x1E
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston:: @ 0x0820B666
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil:: @ 0x0820B67D
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake:: @ 0x0820B694
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah:: @ 0x0820B6AB
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha:: @ 0x0820B6C2
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura:: @ 0x0820B6D9
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia:: @ 0x0820B6F0
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate:: @ 0x0820B707
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey:: @ 0x0820B71E
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford:: @ 0x0820B735
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas:: @ 0x0820B74C
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen:: @ 0x0820B763
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide:: @ 0x0820B77A
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory:: @ 0x0820B78F
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue:: @ 0x0820B79C
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue:: @ 0x0820B7AC
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified:: @ 0x0820B7BC
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue:: @ 0x0820B7C6
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch:: @ 0x0820B7D0
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0x0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch:: @ 0x0820B7E6
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0x1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch:: @ 0x0820B7FC
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0x2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch:: @ 0x0820B812
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0x3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch:: @ 0x0820B828
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0x4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice: @ 0x0820B83E
	.string "げんき　しとぉや！！\n"
	.string "チャンピオンを　めざす　{PLAYER}！！\p"
	.string "このジムの　ジムリーダーは\n"
	.string "エスパータイプの　ポケモンつかい！\p"
	.string "かくとうタイプや　どくタイプの\n"
	.string "ポケモンで　いどむと\l"
	.string "ものすごい　ダメージを　くらうぞ！\p"
	.string "しかも　ばつぐんの\n"
	.string "コンビネーションで　せめてくる！\p"
	.string "だから　きみも　かつために　ポケモンとの\n"
	.string "きずなを　きばって　みせて　やれ！$"

MossdeepCity_Gym_Text_GymGuidePostVictory: @ 0x0820B8E9
	.string "こりゃあ　たまげた！！\n"
	.string "きみは　すごか　トレーナーだ！$"

MossdeepCity_Gym_Text_PrestonIntro: @ 0x0820B905
	.string "しょうぶは　こころの　つよさで　きまる\n"
	.string "こころ　よわき　ものは　かてない！$"

MossdeepCity_Gym_Text_PrestonDefeat: @ 0x0820B92B
	.string "まけたか！\n"
	.string "オレも　きたえ　なおさねばっ！$"

MossdeepCity_Gym_Text_PrestonPostBattle: @ 0x0820B941
	.string "まよった　ほうが　まける\n"
	.string "オレからの　ちゅうこくだ！$"

MossdeepCity_Gym_Text_VirgilIntro: @ 0x0820B95C
	.string "キミの　さいのうを　みせて　もらおうか！$"

MossdeepCity_Gym_Text_VirgilDefeat: @ 0x0820B971
	.string "すばらしい　さいのうの　もちぬしだ！$"

MossdeepCity_Gym_Text_VirgilPostBattle: @ 0x0820B984
	.string "よのなかに　てんさいが　いるならば\n"
	.string "ここの　ジムリーダーが　そうだ⋯⋯\p"
	.string "だが　もしかすると　キミの　ほうが\n"
	.string "さいのうは　うえかも　しれない⋯⋯$"

MossdeepCity_Gym_Text_BlakeIntro: @ 0x0820B9CC
	.string "ふふふ⋯⋯\n"
	.string "ねんりきで　モンスターボールを\l"
	.string "くうちゅうに　うかせて　みせよう⋯⋯\p"
	.string "うおおぉぉぉぉぉ⋯⋯！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "ちょうしの　わるい　ときも　ある⋯⋯$"

MossdeepCity_Gym_Text_BlakeDefeat: @ 0x0820BA26
	.string "ポケモン　しょうぶも\n"
	.string "ちょうし　わりーっ！$"

MossdeepCity_Gym_Text_BlakePostBattle: @ 0x0820BA3C
	.string "モンスターボールは　おおきすぎた\n"
	.string "この　わたぼこり　なら　ぜったいに⋯⋯\p"
	.string "ふううううううっ⋯⋯！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "ちがうぞ！\n"
	.string "はないきで　とばして　なんか　いないぞ！$"

MossdeepCity_Gym_Text_HannahIntro: @ 0x0820BA9A
	.string "あなたが　アタシに　まけた　としても\n"
	.string "おちこまない　ことね！\p"
	.string "あなたが　よわい　わけじゃ　なくて\n"
	.string "アタシが　つよすぎる　からよ！$"

MossdeepCity_Gym_Text_HannahDefeat: @ 0x0820BADB
	.string "あなたは　さらに　つよすぎた！$"

MossdeepCity_Gym_Text_HannahPostBattle: @ 0x0820BAEB
	.string "まけたから　って　クヨクヨ　しないわ\n"
	.string "もっと　しゅぎょう　すれば　いいんだもの！\p"
	.string "まえむきな　ところが　アタシの　とりえ！$"

MossdeepCity_Gym_Text_SamanthaIntro: @ 0x0820BB29
	.string "みえる⋯⋯\n"
	.string "あなたの　みらいが　みえる⋯⋯\p"
	.string "わたくしに　かてたら\n"
	.string "あなたの　みらいを　おしえて　あげる！$"

MossdeepCity_Gym_Text_SamanthaDefeat: @ 0x0820BB5E
	.string "まいりました⋯⋯！$"

MossdeepCity_Gym_Text_SamanthaPostBattle: @ 0x0820BB68
	.string "あなたと　ジムリーダーさまの　しょうぶ⋯⋯\n"
	.string "ものすごく　はげしい　てんかい⋯⋯\p"
	.string "けっかは⋯⋯\n"
	.string "わたくしの　くちからは　いえない⋯⋯！$"

MossdeepCity_Gym_Text_MauraIntro: @ 0x0820BBAB
	.string "あなたが　これまで　あゆんできた　みちのり\n"
	.string "あなたが　けいけん　してきた　ことがら\p"
	.string "すべてを　ぶつけて　きなさい！$"

MossdeepCity_Gym_Text_MauraDefeat: @ 0x0820BBE5
	.string "すばらしい　みちのり　だわ⋯⋯！$"

MossdeepCity_Gym_Text_MauraPostBattle: @ 0x0820BBF6
	.string "がんばった　ものには　あかるい　みらいが\n"
	.string "なまけた　ものには　ぜつぼうの　あしたが\p"
	.string "いんがおうほう⋯⋯\n"
	.string "すべては　じぶんに　はねかえる　ものよ⋯⋯$"

MossdeepCity_Gym_Text_SylviaIntro: @ 0x0820BC40
	.string "いのちを　けずって　でも\n"
	.string "この　しょうぶ　かってみせるわ⋯⋯！$"

MossdeepCity_Gym_Text_SylviaDefeat: @ 0x0820BC60
	.string "あなたは\n"
	.string "おそろしい　ことを⋯⋯$"

MossdeepCity_Gym_Text_SylviaPostBattle: @ 0x0820BC71
	.string "あたしに　かったわね⋯⋯\n"
	.string "なにが　おきても　しらないわよ⋯⋯！$"

MossdeepCity_Gym_Text_NateIntro: @ 0x0820BC91
	.string "ほっほっほ\p"
	.string "エスパータイプの　てごわさを\n"
	.string "あなたに　おしえて　さしあげましょう$"

MossdeepCity_Gym_Text_NateDefeat: @ 0x0820BCB9
	.string "こ　これは　これは！\n"
	.string "すばらしい　たたかいかた　ですな$"

MossdeepCity_Gym_Text_NatePostBattle: @ 0x0820BCD5
	.string "わ　わたくしは　どんなに　まけても\n"
	.string "とりみだしは　しませんから$"

MossdeepCity_Gym_Text_KathleenIntro: @ 0x0820BCF5
	.string "おそろしいめに　あわせて　やろうかーっ！$"

MossdeepCity_Gym_Text_KathleenDefeat: @ 0x0820BD0A
	.string "いやあああーっ！$"

MossdeepCity_Gym_Text_KathleenPostBattle: @ 0x0820BD13
	.string "あなたの　げんきが　うつるわ\n"
	.string "はやく　いっちゃいなさいよ！$"

MossdeepCity_Gym_Text_CliffordIntro: @ 0x0820BD31
	.string "としより　だからと　いって\n"
	.string "あまく　みて　もらっては　こまりますよ$"

MossdeepCity_Gym_Text_CliffordDefeat: @ 0x0820BD53
	.string "あふれる　わかさを　かんじる！$"

MossdeepCity_Gym_Text_CliffordPostBattle: @ 0x0820BD63
	.string "この　ジムの　リーダーも　そりゃもう！\n"
	.string "わかくて　げんき　はつらつ　ですぞ$"

MossdeepCity_Gym_Text_MaceyIntro: @ 0x0820BD89
	.string "まだよ\n"
	.string "まだ　ジムリーダーには　あわせないわよ！$"

MossdeepCity_Gym_Text_MaceyDefeat: @ 0x0820BDA2
	.string "ちょっと！　なんなの　その　つよさ！$"

MossdeepCity_Gym_Text_MaceyPostBattle: @ 0x0820BDB5
	.string "フン　あんたは　つよいけど\n"
	.string "エスパーむき　では　ないわ！\l"
	.string "なんだか　たたかいかたが　がさつ　だもん！$"

MossdeepCity_Gym_Text_NicholasIntro: @ 0x0820BDE8
	.string "うぉーっし！　おれの\n"
	.string "スーパーポケモンしょうぶつよいパワー　を\l"
	.string "うけて　みろーっ！$"

MossdeepCity_Gym_Text_NicholasDefeat: @ 0x0820BE12
	.string "やられたあああ！$"

MossdeepCity_Gym_Text_NicholasPostBattle: @ 0x0820BE1B
	.string "よし！　つぎは\n"
	.string "スペシャルポケモンまけないパワー　でも\l"
	.string "かいはつ　するかな？$"

MossdeepCity_Gym_Text_TateAndLizaIntro: @ 0x0820BE42
	.string "フウ“へへへ⋯⋯　ジムリーダーが\p"
	.string "ラン“ふふふ⋯⋯　ジムリーダーが\p"
	.string "フウ“ふたりも　いるんで　おどろいた？\n"
	.string "ラン“ふたりも　いるんで　おどろいた？\p"
	.string "フウ“ぼくたち　ふたご！\n"
	.string "ラン“あたしたち　ふたご！\p"
	.string "フウ“なにも　ことばに　しなくても\n"
	.string "ラン“おたがいの　かんがえて　いることが\p"
	.string "フウ“あたまの　なかに　うかぶから\n"
	.string "ラン“つうじあうことが　できるのヨ！\p"
	.string "フウ“そんな　ぼくたちの　コンビネーション\n"
	.string "ラン“きみに　やぶることが　できる？$"

MossdeepCity_Gym_Text_TateAndLizaDefeat: @ 0x0820BF1C
	.string "フウ“ぼっ　ぼくたちの\n"
	.string "ラン“コンビネーションが⋯⋯！\p"
	.string "フウ“やぶれた　からには　しかたない\n"
	.string "ラン“まけを　みとめて　これを　あげるヨ！$"

MossdeepCity_Gym_Text_ReceivedMindBadge: @ 0x0820BF61
	.string "{PLAYER}は　フウと　ランから\n"
	.string "マインドバッジを　もらった！$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis: @ 0x0820BF7D
	.string "フウ“マインドバッジには　ポケモンの\n"
	.string "とくこうと　とくぼうを　たかめる\l"
	.string "こうかが　ひめられている！\p"
	.string "ラン“それから　ダイビング　という\n"
	.string "ひでんわざも　つかえるように　なるヨ！\p"
	.string "フウ“あと　これも　もっていきなよ！$"

MossdeepCity_Gym_Text_ExplainCalmMind: @ 0x0820BFE8
	.string "フウ“その　わざマシン04には\n"
	.string "ラン“めいそうが　はいってるヨ！\p"
	.string "フウ“ポケモンの　とくこうと\n"
	.string "ラン“ポケモンの　とくぼうを\p"
	.string "フウ“たかめてくれる　わざ　なんだ！\n"
	.string "ラン“エスパーポケモンに　ぴったりだヨ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza: @ 0x0820C058
	.string "ジムリーダー　フウとランを\n"
	.string "ポケナビに　とうろく　した！$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle: @ 0x0820C075
	.string "フウ“きょうだいの　きずな　より\n"
	.string "きみと　ポケモンとの　きずなの　ほうが\l"
	.string "はるかに　つよかった　みたいだね⋯⋯\p"
	.string "ラン“あなたなら　もっと　つよくなれる！\n"
	.string "たたかった　あたしたちには　わかるわ！$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons: @ 0x0820C0D6
	.string "フウ“へへへ⋯⋯　ジムリーダーが\p"
	.string "ラン“ふたりも　いるんで　おどろいた？\p"
	.string "フウ“あら？　たたかえる　ポケモンが\n"
	.string "ラン“いっぴき　しか　いないヨ！\p"
	.string "フウ“それでは　たたかえないね！\n"
	.string "ラン“しょうぶを　たのしみたいから\l"
	.string "もっと　ポケモン　つれてきてヨ！$"

MossdeepCity_Gym_Text_GymStatue: @ 0x0820C153
	.string "トクサネシティ　ポケモンジム$"

MossdeepCity_Gym_Text_GymStatueCertified: @ 0x0820C162
	.string "トクサネシティ　ポケモンジム\p"
	.string "フウ　ラン　にんてい　トレーナー！\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch: @ 0x0820C186
	.string "フウ“ポケモンは⋯⋯\n"
	.string "ラン“ポケモンは⋯⋯\p"
	.string "フウ“くみあわせを　かえると\n"
	.string "ラン“たたかいかたも　かわるよね\p"
	.string "フウ“でも　ぼくは⋯⋯\n"
	.string "ラン“でも　あたしは⋯⋯\p"
	.string "フウ“いつでも　ランと　いっしょ！\n"
	.string "ラン“いつでも　フウと　いっしょ！\p"
	.string "フウ“ぼくたちの　コンビネーション\n"
	.string "ラン“なんどでも　みせて　あげるわ！$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat: @ 0x0820C21E
	.string "フウ“きみと　ポケモンって\n"
	.string "ラン“まるで　きょうだい　みたい！$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch: @ 0x0820C23E
	.string "フウ“なんど　たおされたって\n"
	.string "また　たちなおって　みせるからね！\p"
	.string "ラン“だって　あたしたち　ふたり\n"
	.string "ちからを　あわせて　がんばれるもの！$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons: @ 0x0820C283
	.string "フウ“また　ぼくたちと⋯⋯\n"
	.string "ラン“また　あたしたちと⋯⋯\p"
	.string "フウ“しょうぶを　しに　きてくれたんだね\n"
	.string "ラン“しょうぶを　しに　きてくれたんだね\p"
	.string "フウ“でも⋯⋯\n"
	.string "ラン“あなた　たたかえる　ポケモンを\p"
	.string "フウ“1ひきしか　もって　いないよ！\n"
	.string "ラン“1ひきしか　もって　いないわ！\p"
	.string "フウ“できれば　2ひき　いじょうの\n"
	.string "ラン“ポケモンを　もって　また　きてね！$"
