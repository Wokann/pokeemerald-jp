@ Route120 scripts (JP map g0 m35 @ 0x081ED864)

Route120_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
	.byte 0

Route120_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
	end

Route120_EventScript_RemoveKecleonObject::
	call_if_eq VAR_0x8009, 0x0, Route120_EventScript_RemoveBridgeKecleon
	call_if_eq VAR_0x8009, 0x1, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 0x2, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 0x3, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 0x4, Route120_EventScript_RemoveKecleon
	call_if_eq VAR_0x8009, 0x5, Route120_EventScript_RemoveKecleon
	return

Route120_EventScript_RemoveBridgeKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, 0x08244178
	removeobject LOCALID_BRIDGE_KECLEON
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
	return

Route120_EventScript_RemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, 0x08244178
	removeobject VAR_LAST_TALKED
	return

Route120_OnLoad::
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
	end

Route120_EventScript_CloseAncientTomb::
	setmetatile 0x7, 0x36, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 0x7, 0x37, METATILE_General_RockWall_SandBase, TRUE
	return

Route120_EventScript_SetBridgeClearMetatiles::
	setmetatile 0xD, 0xF, METATILE_Fortree_WoodBridge1_Top, FALSE
	setmetatile 0xC, 0x10, METATILE_Fortree_WoodBridge1_Bottom, FALSE
	setmetatile 0xC, 0x11, METATILE_General_ReflectiveWater, FALSE
	setmetatile 0xD, 0x11, METATILE_General_ReflectiveWater, FALSE
	return

Route120_EventScript_SetBridgeKecleonMovement::
	setobjectmovementtype LOCALID_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
	return

Route120_OnTransition::
	call 0x082540DF
	call Route120_EventScript_SetWeather
	end

Route120_EventScript_SetWeather::
	getplayerxy 0x4000, 0x4001
	goto_if_le VAR_TEMP_1, 0xE, Route120_EventScript_SetSunnyWeather
	goto_if_le VAR_TEMP_1, 0x3C, Route120_EventScript_TrySetRainyWeather
	goto_if_ge VAR_TEMP_1, 0x3D, Route120_EventScript_SetCloudyWeather
	return

Route120_EventScript_SetCloudyWeather::
	setweather WEATHER_SUNNY_CLOUDS
	return

Route120_EventScript_SetSunnyWeather::
	setweather WEATHER_SUNNY
	return

Route120_EventScript_TrySetRainyWeather::
	goto_if_le VAR_TEMP_0, 0x7, Route120_EventScript_SetRainyWeather
	goto_if_le VAR_TEMP_0, 0x13, Route120_EventScript_SetSunnyWeather
	goto Route120_EventScript_SetRainyWeather
	end

Route120_EventScript_SetRainyWeather::
	setweather WEATHER_RAIN
	return

Route120_EventScript_BerryBeauty::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
	msgbox 0x0826398A, MSGBOX_YESNO
	call_if_eq VAR_RESULT, 0x1, Route120_EventScript_BerryLove
	call_if_eq VAR_RESULT, 0x0, Route120_EventScript_BerryNotLove
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, Route120_EventScript_GiveFigyBerry
	goto_if_eq VAR_0x8000, 0x5, Route120_EventScript_GiveFigyBerry
	goto_if_eq VAR_0x8000, 0x1, Route120_EventScript_GiveWikiBerry
	goto_if_eq VAR_0x8000, 0x6, Route120_EventScript_GiveWikiBerry
	goto_if_eq VAR_0x8000, 0x2, Route120_EventScript_GiveMagoBerry
	goto_if_eq VAR_0x8000, 0x7, Route120_EventScript_GiveMagoBerry
	goto_if_eq VAR_0x8000, 0x3, Route120_EventScript_GiveAguavBerry
	goto_if_eq VAR_0x8000, 0x8, Route120_EventScript_GiveAguavBerry
	goto_if_eq VAR_0x8000, 0x4, Route120_EventScript_GiveIapapaBerry
	goto_if_eq VAR_0x8000, 0x9, Route120_EventScript_GiveIapapaBerry
	end

Route120_EventScript_GiveFigyBerry::
	setvar VAR_0x8004, ITEM_FIGY_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveWikiBerry::
	setvar VAR_0x8004, ITEM_WIKI_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveMagoBerry::
	setvar VAR_0x8004, ITEM_MAGO_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveAguavBerry::
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveIapapaBerry::
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveBerry::
	setorcopyvar VAR_0x8000, 0x8004
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	goto_if_eq VAR_RESULT, 0x0, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
	msgbox 0x08263A1E, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_ReceivedBerry::
	msgbox 0x08263A41, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_BerryLove::
	msgbox 0x082639DA, MSGBOX_DEFAULT
	return

Route120_EventScript_BerryNotLove::
	msgbox 0x082639FA, MSGBOX_DEFAULT
	return

Route120_EventScript_Steven::
	lock
	faceplayer
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0x0, Route120_EventScript_StevenNotReady
	goto Route120_EventScript_StevenBattleKecleon
	end

Route120_EventScript_StevenNotReady::
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
	release
	end

Route120_EventScript_StevenAskReadyForBattle::
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, 0x0, Route120_EventScript_StevenNotReady
	goto Route120_EventScript_StevenBattleKecleon
	end

Route120_EventScript_StevenBattleKecleon::
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Route120_EventScript_PlayerApproachKecleonNorth
	call_if_eq VAR_FACING, DIR_WEST, Route120_EventScript_PlayerApproachKecleonWest
	applymovement LOCALID_ROUTE120_STEVEN, 0x08243627
	waitmovement 0x0
	delay 0x14
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRIDGE_KECLEON, 0x0824362B
	waitmovement 0x0
	applymovement LOCALID_BRIDGE_KECLEON, 0x0824344A
	waitmovement 0x0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 0x28
	waitdooranim
	setwildbattle SPECIES_KECLEON, 0x1E, 0x0
	setvar VAR_0x8009, 0x0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, 0x1, Route120_EventScript_RemoveBridgeKecleonPostBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route120_EventScript_RemoveBridgeKecleonPostBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route120_EventScript_RemoveBridgeKecleonPostBattle
	goto Route120_EventScript_StevenGiveDeconScope
	end

Route120_EventScript_RemoveBridgeKecleonPostBattle::
	fadescreenswapbuffers 0x1
	removeobject LOCALID_BRIDGE_KECLEON
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
	fadescreenswapbuffers 0x0
	goto Route120_EventScript_StevenGiveDeconScope
	end

Route120_EventScript_StevenGiveDeconScope::
	applymovement LOCALID_ROUTE120_STEVEN, 0x0824362D
	applymovement LOCALID_PLAYER, 0x08243629
	waitmovement 0x0
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
	setorcopyvar VAR_0x8000, ITEM_DEVON_SCOPE
	setorcopyvar VAR_0x8001, 0x1
	callstd 0x0
	setflag FLAG_RECEIVED_DEVON_SCOPE
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE120_STEVEN, 0x0824362D
	waitmovement 0x0
	delay 0x32
	setfieldeffectarg 0x0, 0x1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 0xF
	removeobject LOCALID_ROUTE120_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setmetatile 0xD, 0xF, METATILE_Fortree_WoodBridge1_Top, FALSE
	setmetatile 0xC, 0x10, METATILE_Fortree_WoodBridge1_Bottom, FALSE
	setmetatile 0xC, 0x11, METATILE_General_ReflectiveWater, FALSE
	setmetatile 0xD, 0x11, METATILE_General_ReflectiveWater, FALSE
	special DrawWholeMapView
	release
	end

Route120_EventScript_PlayerApproachKecleonNorth::
	applymovement LOCALID_PLAYER, 0x08243627
	waitmovement 0x0
	return

Route120_EventScript_PlayerApproachKecleonWest::
	applymovement LOCALID_PLAYER, Route120_Movement_ApproachKecleonWest
	waitmovement 0x0
	return

Route120_Movement_ApproachKecleonWest:
	walk_down
	walk_left
	step_end

Route120_EventScript_BridgeKecleon::
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
	end

Route120_EventScript_RouteSignFortree::
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route120_EventScript_RouteSign121::
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
	end

Route120_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Route120_EventScript_RegisterRobert
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchRobert
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RegisterRobert::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROBERT_1
	release
	end

Route120_EventScript_RematchRobert::
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Lorenzo::
	trainerbattle_single TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jenna::
	trainerbattle_single TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Route120_EventScript_RegisterJeffrey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchJeffrey
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RegisterJeffrey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JEFFREY_1
	release
	end

Route120_EventScript_RematchJeffrey::
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jennifer::
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Chip::
	trainerbattle_single TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Angelica::
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Keigo::
	trainerbattle_single TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Leonel::
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Callie::
	trainerbattle_single TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
	end

Route120_Text_StevenGreeting: @ 0x081EDE10
	.string "ダイゴ“ん？　{PLAYER}{KUN}か\n"
	.string "ひさしぶり　だね\p"
	.string "ここに　みえない　なにかが　いるよね？\p"
	.string "で　みえない　なにかに　むかって\n"
	.string "この　どうぐを　つかうと⋯⋯\p"
	.string "ちがうな⋯⋯　せつめい　するよりも\n"
	.string "じっさいに　つかった　ほうが　たのしそうだ\p"
	.string "{PLAYER}{KUN}　きみの　ポケモン\n"
	.string "たたかう　じゅんびは　できて　いるのかい？$"

Route120_Text_StevenIllWaitHere: @ 0x081EDEA6
	.string "ダイゴ“そう？\p"
	.string "ボクは　ここで　まっているから\n"
	.string "じゅんびを　すると　いいよ$"

Route120_Text_StevenReadyForBattle: @ 0x081EDECC
	.string "ダイゴ“{PLAYER}{KUN}　きみの　ポケモン\n"
	.string "たたかう　じゅんびは　できて　いるのかい？$"

Route120_Text_StevenShowMeYourPower: @ 0x081EDEF4
	.string "ダイゴ“{PLAYER}{KUN}\n"
	.string "きみの　トレーナー　としての\l"
	.string "じつりょく　みせてもらうよ！$"

Route120_Text_StevenUsedDevonScope: @ 0x081EDF1B
	.string "ダイゴは\n"
	.string "デボンスコープを　つかった！\p"
	.string "とうめいに　なっていた\n"
	.string "ポケモンの　すがたが　まるわかりだ！\p"
	.string "ポケモンは\n"
	.string "おどろいて　おそいかかってきた！$"

Route120_Text_StevenGiveDevonScope: @ 0x081EDF65
	.string "ダイゴ“なるほど\n"
	.string "きみの　たたかいかた　おもしろいね\p"
	.string "はじめて　ムロで　であった　ときよりも\n"
	.string "ポケモンも　そだっているし⋯⋯\p"
	.string "そうだね\n"
	.string "この　デボンスコープは　きみに　あげよう\p"
	.string "ほかにも　すがたを　かくしている\n"
	.string "ポケモンは　いるかも　しれないから$"

Route120_Text_StevenGoodbye: @ 0x081EDFE1
	.string "ダイゴ“{PLAYER}{KUN}\p"
	.string "ボクは　がんばっている\n"
	.string "トレーナーと　ポケモンが　すきだから\p"
	.string "きみのこと　いいと　おもうよ\p"
	.string "じゃあ\n"
	.string "また　どこかで　あおう！$"

Kecleon_Text_SomethingUnseeable: @ 0x081EE029
	.string "みえない　なにかが　いるようだ$"

Kecleon_Text_WantToUseDevonScope: @ 0x081EE039
	.string "みえない　なにかが　いるようだ\p"
	.string "デボンスコープを　つかいますか？$"

Kecleon_Text_UseDevonScopeMonAttacked: @ 0x081EE05A
	.string "{PLAYER}は\n"
	.string "デボンスコープを　つかった！\p"
	.string "とうめいに　なっていた\n"
	.string "ポケモンの　すがたが　まるわかりだ！\p"
	.string "ポケモンは\n"
	.string "おどろいて　おそいかかってきた！$"

Route120_Text_RouteSignFortree: @ 0x081EE0A3
	.string "ここは　120ばん　どうろ\n"
	.string "{LEFT_ARROW}　ヒワマキシティ$"

Route120_Text_RouteSign121: @ 0x081EE0BD
	.string "{RIGHT_ARROW}　121ばん　どうろ\n"
	.string "{LEFT_ARROW}　120ばん　どうろ$"
