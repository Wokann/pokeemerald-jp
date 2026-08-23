@ Route111 scripts (JP map g0 m26 @ 0x081EA14D)

Route111_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
	.byte 0

Route111_OnLoad::
	call_if_unset 0xE4, Route111_EventScript_CloseDesertRuins
	call_if_eq 0x40CB, 0x1, Route111_EventScript_ShowTemporaryMirageTower
	end

Route111_EventScript_CloseDesertRuins::
	setmetatile 0x1D, 0x56, 0x7C, 0x1
	setmetatile 0x1D, 0x57, 0x91, 0x1
	return

Route111_EventScript_ShowTemporaryMirageTower::
	setmetatile 0x12, 0x35, 0x3D8, 0x0
	setmetatile 0x13, 0x35, 0x3D9, 0x0
	setmetatile 0x14, 0x35, 0x3DA, 0x0
	setmetatile 0x12, 0x36, 0x3E0, 0x0
	setmetatile 0x13, 0x36, 0x3E1, 0x0
	setmetatile 0x14, 0x36, 0x3E2, 0x0
	setmetatile 0x12, 0x37, 0x3E8, 0x0
	setmetatile 0x13, 0x37, 0x3E9, 0x0
	setmetatile 0x14, 0x37, 0x3EA, 0x0
	setmetatile 0x12, 0x38, 0x3F0, 0x0
	setmetatile 0x13, 0x38, 0x3F1, 0x0
	setmetatile 0x14, 0x38, 0x3F2, 0x0
	setmetatile 0x12, 0x39, 0x3DB, 0x0
	setmetatile 0x13, 0x39, 0x3DC, 0x0
	setmetatile 0x14, 0x39, 0x3DD, 0x0
	setmetatile 0x12, 0x3A, 0x3E3, 0x0
	setmetatile 0x13, 0x3A, 0x3E4, 0x0
	setmetatile 0x14, 0x3A, 0x3E5, 0x0
	return

Route111_OnTransition::
	setvar 0x40D6, 0x0
	special SetMirageTowerVisibility
	call_if_unset 0x14E, Route111_EventScript_SetLayoutNoMirageTower
	call_if_eq 0x40CB, 0x1, Route111_EventScript_SetFallingPlayerGfx
	call_if_eq 0x40CB, 0x2, Route111_EventScript_SetMirageTowerGone
	call Route111_EventScript_CheckSetSandstorm
	call 0x082540DF
	checktrainerflag 0x138
	goto_if 0x0, Route111_EventScript_SetWinstratesNotDefeated
	end

Route111_EventScript_SetFallingPlayerGfx::
	checkplayergender
	goto_if_eq 0x800D, 0x0, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq 0x800D, 0x1, Route111_EventScript_SetFallingPlayerGfxFemale
	return

Route111_EventScript_SetFallingPlayerGfxMale::
	setvar 0x4010, 0x64
	return

Route111_EventScript_SetFallingPlayerGfxFemale::
	setvar 0x4010, 0x69
	return

Route111_EventScript_CheckSetSandstorm::
	getplayerxy 0x4000, 0x4001
	goto_if_lt 0x4001, 0x22, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt 0x4001, 0x6B, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt 0x4001, 0x48, Route111_EventScript_SetSandstorm
	goto_if_gt 0x4000, 0x7D0, Route111_EventScript_EndCheckSetSandstorm
	goto_if_lt 0x4000, 0x8, Route111_EventScript_EndCheckSetSandstorm

Route111_EventScript_SetSandstorm::
	setweather 0x8

Route111_EventScript_EndCheckSetSandstorm::
	return

Route111_EventScript_SetWinstratesNotDefeated::
	clearflag 0x300
	setflag 0x301
	setflag 0x302
	setflag 0x303
	cleartrainerflag 0x124
	cleartrainerflag 0x12B
	cleartrainerflag 0x25E
	end

Route111_EventScript_SetLayoutNoMirageTower::
	setmaplayoutindex 0x188
	return

Route111_EventScript_SetMirageTowerGone::
	setvar 0x40CB, 0x3
	return

Route111_OnWarp::
	map_script_2 0x40CB, 0x1, Route111_EventScript_HidePlayerForMirageTower
	.2byte 0

Route111_EventScript_HidePlayerForMirageTower::
	hideobject_at 0xFF, 0x9
	end

Route111_OnFrame::
	map_script_2 0x40CB, 0x1, Route111_EventScript_MirageTowerDisappear
	.2byte 0

Route111_EventScript_MirageTowerDisappear::
	lockall
	special StartMirageTowerFossilFallAndSink
	delay 0x18
	playse 0x2B
	addobject 0x2D
	special StartPlayerDescendMirageTower
	showobject_at 0xFF, 0x9
	removeobject 0x2D
	delay 0x10
	turnobject 0xFF, 0x2
	delay 0x10
	special StartMirageTowerDisintegration
	special StartMirageTowerShake
	setvar 0x40CB, 0x2
	clearflag 0x36A
	goto_if_set 0x150, Route111_EventScript_RootFossilDisappeared
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_RootFossilDisappeared::
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_Movement_PlayerFall:
	lock_anim
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route111_EventScript_Girl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set 0x92C, Route111_EventScript_ReceivedBerry
	msgbox 0x0826388C, MSGBOX_DEFAULT
	setorcopyvar 0x8000, 0x94
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	goto_if_eq 0x800D, 0x0, 0x082430E0
	setflag 0x92C
	special GetPlayerBigGuyGirlString
	msgbox 0x082638C8, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ReceivedBerry::
	msgbox 0x082638F0, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ViciousSandstormTriggerUp::
	lockall
	setvar 0x8004, 0x0
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerDown::
	lockall
	setvar 0x8004, 0x1
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerLeft::
	lockall
	setvar 0x8004, 0x2
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerRight::
	lockall
	setvar 0x8004, 0x3
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTrigger::
	checkitem 0x117, 0x1
	goto_if_eq 0x800D, 0x0, Route111_EventScript_PreventRouteAccess
	setvar 0x4003, 0x1
	releaseall
	end

Route111_EventScript_PreventRouteAccess::
	msgbox 0x08243A64, MSGBOX_DEFAULT
	closemessage
	call_if_eq 0x8004, 0x0, Route111_EventScript_PushUpFromRoute
	call_if_eq 0x8004, 0x1, Route111_EventScript_PushDownFromRoute
	call_if_eq 0x8004, 0x2, Route111_EventScript_PushLeftFromRoute
	call_if_eq 0x8004, 0x3, Route111_EventScript_PushRightFromRoute
	releaseall
	end

Route111_EventScript_PushUpFromRoute::
	applymovement 0xFF, Route111_Movement_PushUpFromRoute
	waitmovement 0x0
	return

Route111_EventScript_PushDownFromRoute::
	applymovement 0xFF, Route111_Movement_PushDownFromRoute
	waitmovement 0x0
	return

Route111_EventScript_PushLeftFromRoute::
	applymovement 0xFF, Route111_Movement_PushLeftFromRoute
	waitmovement 0x0
	return

Route111_EventScript_PushRightFromRoute::
	applymovement 0xFF, Route111_Movement_PushRightFromRoute
	waitmovement 0x0
	return

Route111_Movement_PushUpFromRoute:
	walk_up
	step_end

Route111_Movement_PushDownFromRoute:
	walk_down
	step_end

Route111_Movement_PushLeftFromRoute:
	walk_left
	step_end

Route111_Movement_PushRightFromRoute:
	walk_right
	step_end

Route111_EventScript_SunTrigger::
	setweather 0x2
	fadenewbgm 0x168
	resetweather
	setvar 0x4003, 0x0
	end

Route111_EventScript_SandstormTrigger::
	setweather 0x8
	fadenewbgm 0x199
	resetweather
	end

Route111_EventScript_Victor::
	lock
	faceplayer
	setflag 0x8A3
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
	goto_if_eq 0x800D, 0x1, Route111_EventScript_BattleWinstrates
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_BattleWinstrates::
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro 0x124, Route111_Text_VictorDefeat
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 0x1, Route111_Movement_WinstrateEnterHouse
	waitmovement 0x0
	removeobject 0x1
	call Route111_EventScript_CloseWinstrateDoor
	applymovement 0xFF, Route111_Movement_WaitForNextWinstrate
	waitmovement 0x0
	call Route111_EventScript_OpenWinstrateDoor
	addobject 0x2
	applymovement 0x2, Route111_Movement_WinstrateExitHouse
	waitmovement 0x0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro 0x12B, Route111_Text_VictoriaDefeat
	applymovement 0x2, 0x08243629
	waitmovement 0x0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 0x2, Route111_Movement_WinstrateEnterHouse
	waitmovement 0x0
	removeobject 0x2
	call Route111_EventScript_CloseWinstrateDoor
	applymovement 0xFF, Route111_Movement_WaitForNextWinstrate
	waitmovement 0x0
	call Route111_EventScript_OpenWinstrateDoor
	addobject 0x3
	applymovement 0x3, Route111_Movement_WinstrateExitHouse
	waitmovement 0x0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro 0x25E, Route111_Text_ViviDefeat
	applymovement 0x3, 0x08243629
	waitmovement 0x0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 0x3, Route111_Movement_WinstrateEnterHouse
	waitmovement 0x0
	removeobject 0x3
	call Route111_EventScript_CloseWinstrateDoor
	applymovement 0xFF, Route111_Movement_WaitForNextWinstrate
	waitmovement 0x0
	call Route111_EventScript_OpenWinstrateDoor
	addobject 0x4
	applymovement 0x4, Route111_Movement_WinstrateExitHouse
	waitmovement 0x0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro 0x138, Route111_Text_VickyDefeat
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	call Route111_EventScript_OpenWinstrateDoor
	applymovement 0x4, Route111_Movement_WinstrateEnterHouse
	waitmovement 0x0
	removeobject 0x4
	call Route111_EventScript_CloseWinstrateDoor
	release
	end

Route111_EventScript_OpenWinstrateDoor::
	opendoor 0xD, 0x71
	waitmoncry
	return

Route111_EventScript_CloseWinstrateDoor::
	closedoor 0xD, 0x71
	waitmoncry
	return

Route111_Movement_WinstrateEnterHouse:
	walk_in_place_faster_up
	walk_up
	step_end

Route111_Movement_WinstrateExitHouse:
	walk_down
	step_end

Route111_Movement_WaitForNextWinstrate:
	delay_16
	delay_16
	delay_16
	step_end

Route111_EventScript_RouteSignMauville::
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route111_EventScript_WinstrateHouseSign::
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign112::
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign113::
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
	end

Route111_EventScript_OldLadysRestStopSign::
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
	end

Route111_EventScript_TrainerTipsSpAtkSpDef::
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
	end

Route111_EventScript_Man1::
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
	end

Route111_EventScript_Man2::
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
	end

Route111_EventScript_Hiker::
	lock
	faceplayer
	goto_if_eq 0x40CB, 0x3, Route111_EventScript_HikerMirageTowerGone
	goto_if_eq 0x40CB, 0x2, Route111_EventScript_HikerMirageTowerDisintegrated
	goto_if_set 0x14E, Route111_EventScript_HikerMirageTowerVisible
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerGone::
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerDisintegrated::
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerVisible::
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RockSmashTipFatMan::
	lockall
	applymovement 0x2E, 0x08243621
	waitmovement 0x0
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
	closemessage
	applymovement 0x2E, 0x08243625
	waitmovement 0x0
	releaseall
	end

Route111_EventScript_Drew::
	trainerbattle_single 0xD3, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Heidi::
	trainerbattle_single 0x1D5, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Beau::
	trainerbattle_single 0xD4, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Becky::
	trainerbattle_single 0x1D6, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Dusty::
	trainerbattle_single 0x2C, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
	specialvar 0x800D, ShouldTryRematchBattle
	goto_if_eq 0x800D, 0x1, Route111_EventScript_RematchDusty
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterDusty::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
	setvar 0x8004, 0x2C
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x2C
	callstd 0x8
	release
	end

Route111_EventScript_RematchDusty::
	trainerbattle_rematch 0x2C, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Travis::
	trainerbattle_single 0xDA, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Irene::
	trainerbattle_single 0x1DC, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Daisuke::
	trainerbattle_single 0xBD, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Wilton::
	trainerbattle_single 0x4E, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
	specialvar 0x800D, ShouldTryRematchBattle
	goto_if_eq 0x800D, 0x1, Route111_EventScript_RematchWilton
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
	setvar 0x8004, 0x4E
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x4E
	callstd 0x8
	release
	end

Route111_EventScript_RematchWilton::
	trainerbattle_rematch 0x4E, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Brooke::
	trainerbattle_single 0x5E, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
	specialvar 0x800D, ShouldTryRematchBattle
	goto_if_eq 0x800D, 0x1, Route111_EventScript_RematchBrooke
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterBrooke::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
	setvar 0x8004, 0x5E
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x5E
	callstd 0x8
	release
	end

Route111_EventScript_RematchBrooke::
	trainerbattle_rematch 0x5E, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Hayden::
	trainerbattle_single 0x2C3, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bianca::
	trainerbattle_single 0x2C2, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Tyron::
	trainerbattle_single 0x2C0, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celina::
	trainerbattle_single 0x2C1, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celia::
	trainerbattle_single 0x2E7, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bryan::
	trainerbattle_single 0x2E8, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Branden::
	trainerbattle_single 0x2E9, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_TrainerHillSign::
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
	end

Route111_Text_BattleOurFamily: @ 0x081EA91B
	.string "きみ！　たびの　とちゅう　だろうけれど\p"
	.string "どうだ？　ここは　ひとつ\n"
	.string "わたしたち　かぞく　4にんと\l"
	.string "ポケモン　しょうぶを　してみないか？$"

Route111_Text_IsThatSo: @ 0x081EA95E
	.string "あっそ！\n"
	.string "きが　むいたら　また　おいで！$"

Route111_Text_VictorIntro: @ 0x081EA973
	.string "いい　どきょうだ！　きにいったぞ！$"

Route111_Text_VictorDefeat: @ 0x081EA985
	.string "たはーっ！\n"
	.string "おもっていたより　つよいんだね　きみは！$"

Route111_Text_VictorPostBattle: @ 0x081EA9A0
	.string "おーい！\n"
	.string "なかなか　つよい　トレーナーが　いたぞー！$"

Route111_Text_VictoriaIntro: @ 0x081EA9BB
	.string "あれま！　いがいに　わかいのね！\p"
	.string "うちの　しゅじんに　かってしまう　とは\n"
	.string "なんと　すごうでの　トレーナー　なの！\p"
	.string "じゃあ　こんどは　わたしと　しょうぶよ！$"

Route111_Text_VictoriaDefeat: @ 0x081EAA09
	.string "んまーっ！\n"
	.string "あなたって　なんて　つよいのかしら！$"

Route111_Text_VictoriaPostBattle: @ 0x081EAA22
	.string "つよいわよー！\n"
	.string "このひと　すっごく　つよいわよー！$"

Route111_Text_ViviIntro: @ 0x081EAA3C
	.string "ママより　つよいなんて　すごーい！\p"
	.string "でも　あたし　だって　つよいんだから！\n"
	.string "ほんと　なんだってば！$"

Route111_Text_ViviDefeat: @ 0x081EAA6E
	.string "えっ　もしかして　まけちゃった⋯⋯$"

Route111_Text_ViviPostBattle: @ 0x081EAA80
	.string "くやしい⋯⋯\p"
	.string "⋯⋯　ぐっすん！　おばあちゃーん！！$"

Route111_Text_VickyIntro: @ 0x081EAA9A
	.string "こらーっ！\n"
	.string "わしの　かわいい　まごに　なにすんじゃ！\p"
	.string "こうなったら　わしが　おまえさんを\n"
	.string "メタメタに　してやるから　かくごせぇ！$"

Route111_Text_VickyDefeat: @ 0x081EAADB
	.string "フガッ！　つよいのう⋯⋯\n"
	.string "まごの　いうことは　ほんとう　じゃった$"

Route111_Text_VickyPostBattle: @ 0x081EAAFC
	.string "あんた⋯⋯　いそぎのたびで　ないのなら\n"
	.string "うちに　よっていって　おくれ⋯⋯$"

Route111_Text_ToughToKeepWinningUpTheRanks: @ 0x081EAB21
	.string "もっと　ポケモン　きたえないと\n"
	.string "かちぬくのは　きびしそうだ\p"
	.string "いままでの　ジムリーダーより\n"
	.string "はるかに　つよいと　きくからな\l"
	.string "ポケモンリーグにいる　してんのうは！$"

Route111_Text_WinstrateFamilyDestroyedMe: @ 0x081EAB71
	.string "カチヌキいっかに　いどんだけれど\n"
	.string "4にん　つづけての　ポケモンしょうぶは\l"
	.string "きびしいよな⋯⋯　ボロまけ　したよ$"

Route111_Text_RouteSignMauville: @ 0x081EABA8
	.string "ここは　111ばん　どうろ\n"
	.string "{ESCAPE 0x01}　キンセツシティ$"

Route111_Text_WinstrateHouseSign: @ 0x081EABC2
	.string "われら　かぞくの　こころは　ひとつ\n"
	.string "‘カチヌキ　ファミリーの　いえ’$"

Route111_Text_RouteSign112: @ 0x081EABE5
	.string "ここは　111ばん　どうろ\n"
	.string "{ESCAPE 0x02}　112ばん　どうろ$"

Route111_Text_RouteSign113: @ 0x081EAC01
	.string "ここは　111ばん　どうろ\n"
	.string "{ESCAPE 0x02}　113ばん　どうろ$"

Route111_Text_OldLadysRestStopSign: @ 0x081EAC1D
	.string "‘ケンコーばあさんの　いえ’\n"
	.string "つかれたと　おもうなら　よってらっしゃい！$"

Route111_Text_TrainerTipsSpAtkSpDef: @ 0x081EAC42
	.string "おとくな　けいじばん！！\p"
	.string "ポケモンの　つよさを　あらわす　ことばで\n"
	.string "とくこう　とは\l"
	.string "とくしゅ　こうげきりょく　のこと！\p"
	.string "とくぼう　とは\n"
	.string "とくしゅ　ぼうぎょりょく　のこと　です！$"

Route111_Text_ShouldBeMirageTowerAroundHere: @ 0x081EAC9B
	.string "この　あたりに　すなで　できた\n"
	.string "とうが　たっている　はず　なんだが\p"
	.string "どうしたわけか\n"
	.string "みえるときと　みえないときが　あるのだ\p"
	.string "だから　わたしは　それを\n"
	.string "げんえいのとう　と　よんでいる⋯⋯$"

Route111_Text_MirageTowerClearlyVisible: @ 0x081EACF8
	.string "みえるぞ！　すなのとう　が！\n"
	.string "げんえい　と　よばれた　すなのとうが\n"
	.string "はっきりと　みえる！\p"
	.string "しかし　そのすがたは　はかなくて\n"
	.string "いまにも　くずれて　しまいそうだ⋯⋯\p"
	.string "うーん　はいって　みたいが\n"
	.string "こわくて　ゆうきが　でん！$"

Route111_Text_ThatWasShockingSandRainedDown: @ 0x081EAD65
	.string "はー　びっくりした⋯⋯\p"
	.string "いきなり　すなが　そらから\n"
	.string "バラバラと　ふって　きたんじゃ\p"
	.string "で　なかは　どうじゃった？\n"
	.string "やはり　すなの　オバケ　とか　でたか？$"

Route111_Text_MirageTowerHasntBeenSeenSince: @ 0x081EADB1
	.string "あれから\n"
	.string "すなのとう　は　みえなく　なった\p"
	.string "やはり　げんえいのとう　だったのか⋯⋯$"

Route111_Text_ClawFossilDisappeared: @ 0x081EADDB
	.string "ツメのかせきは\n"
	.string "すなに　もぐって　しまった⋯⋯$"

Route111_Text_RootFossilDisappeared: @ 0x081EADF3
	.string "ねっこのかせきは\n"
	.string "すなに　もぐって　しまった⋯⋯$"

Route111_Text_MauvilleUncleToldMeToTakeRockSmash: @ 0x081EAE0C
	.string "しまった！\p"
	.string "111ばんどうろに　いくなら\n"
	.string "いわくだきを　もっていけ　って\l"
	.string "キンセツの　おじさんに　いわれてたんだ！\p"
	.string "おじさん？　サイクルショップの\n"
	.string "むかいがわの　いえに　すんでるよ$"

Route111_Text_TrainerHillSign: @ 0x081EAE67
	.string "{ESCAPE 0x03}　トレーナーヒル　いりぐち\n"
	.string "かけあがれ！　あつき　トレーナーたち！$"
