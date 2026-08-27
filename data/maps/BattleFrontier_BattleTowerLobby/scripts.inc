@ BattleFrontier_BattleTowerLobby scripts (JP map g26 m5 @ 0x0821F6BC)

BattleFrontier_BattleTowerLobby_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_EventScript_0021F6D1
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_EventScript_0021F6D5
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_MapScriptTable_0021F71E
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_MapScriptTable_0021F70A
	.byte 0

BattleFrontier_BattleTowerLobby_EventScript_0021F6D1::
	special sub_08165248
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F6D5::
	call 0x0825409C
	setvar 0x8004, 0xA
	special CallApprenticeFunction
	compare_var_to_value 0x8004, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F6F6
	checkflag 0x934
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F702

BattleFrontier_BattleTowerLobby_EventScript_0021F6F6::
	clearflag 0x2BD
	setvar 0x8004, 0x17
	special CallApprenticeFunction

BattleFrontier_BattleTowerLobby_EventScript_0021F701::
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F702::
	setflag 0x2BD
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F701

BattleFrontier_BattleTowerLobby_MapScriptTable_0021F70A::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerLobby_EventScript_0021F714
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_0021F714::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleTowerLobby_MapScriptTable_0021F71E::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleTowerLobby_EventScript_0021F748
	map_script_2 0x4000, 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F751
	map_script_2 0x4000, 0x2, BattleFrontier_BattleTowerLobby_EventScript_0021F92F
	map_script_2 0x4000, 0x3, BattleFrontier_BattleTowerLobby_EventScript_0021F799
	map_script_2 0x4000, 0x4, BattleFrontier_BattleTowerLobby_EventScript_0021F833
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_0021F748::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F751::
	lock
	faceplayer
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F799::
	lock
	faceplayer
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F7B9
	message BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F7C1

BattleFrontier_BattleTowerLobby_EventScript_0021F7B9::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F7C1::
	setvar 0x8004, 0x5
	special sub_08161E88
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F7E6
	message BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons
	waitmessage
	playfanfare 0x172
	waitfanfare
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F7E6::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_Text_ObtainedXBattlePoints
	callstd 0x9
	call BattleFrontier_BattleTowerLobby_EventScript_0021F88E
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special sub_08161E88
	compare_var_to_value 0x800D, 0x31
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_0021F823
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F823::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F833::
	compare_var_to_value 0x40CE, 0x2
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_0021F85F
	checkflag 0x152
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F85F
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special sub_08161E88
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_0021F871

BattleFrontier_BattleTowerLobby_EventScript_0021F85F::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special sub_08161E88

BattleFrontier_BattleTowerLobby_EventScript_0021F871::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying
	waitmessage
	call BattleFrontier_BattleTowerLobby_EventScript_0021F88E
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F88E::
	message BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved
	waitmessage
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar 0x8004, 0x6
	setvar 0x8005, 0x0
	special sub_08161E88
	playse 0x37
	waitse
	call BattleFrontier_BattleTowerLobby_EventScript_0021F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F920
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F920
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F8F5
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F920

BattleFrontier_BattleTowerLobby_EventScript_0021F8F5::
	setvar 0x8004, 0x13
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F918
	playse 0x37
	loadword 0x0, 0x08222412
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F920

BattleFrontier_BattleTowerLobby_EventScript_0021F918::
	loadword 0x0, 0x0822247E
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F920::
	return

BattleFrontier_BattleTowerLobby_EventScript_0021F921::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x6
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerLobby_EventScript_0021F92F::
	lock
	faceplayer
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F971
	message BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021F971::
	setvar 0x40BC, 0x1
	return

BattleFrontier_BattleTowerLobby_EventScript_0021F977::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021F989::
	message BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021F9C5
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FAD2
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021F9C5::
	setvar 0x40CE, 0x0
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_SelectThreeMons
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FA6B
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FA6B::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	setvar 0x40BC, 0x1
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FAD2::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021F989
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FAE0::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021FAF2::
	message BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FB2E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FC3B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021FB2E::
	setvar 0x40CE, 0x1
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x4
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FBD4
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FBD4::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FC3B::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FAF2
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FC49::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	clearflag 0x152
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021FC5E::
	message BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FC9A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FDA7
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021FC9A::
	setvar 0x40CE, 0x2
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x2
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FD40
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FD40::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FDA7::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FC5E
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FDB5::
	lock
	faceplayer
	setvar 0x40CF, 0x0
	special SavePlayerParty
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_0021FDC7::
	message BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FE03
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022041B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127

BattleFrontier_BattleTowerLobby_EventScript_0021FE03::
	setvar 0x40CE, 0x3
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022006C
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2
	callstd 0x4
	fadescreen 0x1
	call BattleFrontier_BattleTowerLobby_EventScript_002202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x2
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FEA9
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220124

BattleFrontier_BattleTowerLobby_EventScript_0021FEA9::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x4000, 0x0
	setvar 0x8004, 0x0
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special sub_08161E88
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	setvar 0x8004, 0x6
	setvar 0x8005, 0x0
	special sub_08161E88
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220111
	incrementgamestat 0x1E
	specialvar 0x800D, IsWirelessAdapterConnected
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220429
	goto BattleFrontier_BattleTowerLobby_EventScript_00220306
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FF28::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower
	waitmessage
	multichoice 0x10, 0x4, 0x6D, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FF73
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FF8D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFA7
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFC1
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFC1
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FF73::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin
	callstd 0x4
	setvar 0x8004, 0x1
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FFCB
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FF8D::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon
	callstd 0x4
	setvar 0x8004, 0x2
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FFCB
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFA7::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost
	callstd 0x4
	setvar 0x8004, 0x3
	call 0x08242F08
	lock
	faceplayer
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FFCB
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFC1::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFCB::
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFE2
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0021FFEC
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFE2::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ChangedYourMind
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFEC::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFF6::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded
	callstd 0x2
	end

BattleFrontier_BattleTowerLobby_EventScript_0021FFFF::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins
	callstd 0x2
	end

BattleFrontier_BattleTowerLobby_EventScript_00220008::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_00220021::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_0022003A::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x2
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_00220053::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_0022006C::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220087
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200CC

BattleFrontier_BattleTowerLobby_EventScript_00220087::
	copyvar 0x8000, 0x40CE
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200B0
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200BE
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200B0::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200BE::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200CC::
	copyvar 0x8000, 0x40CE
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002200F5
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220103
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_002200F5::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_00220103::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_00220132
	end

BattleFrontier_BattleTowerLobby_EventScript_00220111::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerLobby_EventScript_00220127
	end

BattleFrontier_BattleTowerLobby_EventScript_00220124::
	special LoadPlayerParty

BattleFrontier_BattleTowerLobby_EventScript_00220127::
	special CloseLink
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge
	callstd 0x4

BattleFrontier_BattleTowerLobby_EventScript_00220132::
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_00220134::
	special SavePlayerParty
	setvar 0x8004, 0x3
	call BattleFrontier_BattleTowerLobby_EventScript_002202B3
	special CallFrontierUtilFunc
	setvar 0x800D, 0x0

BattleFrontier_BattleTowerLobby_EventScript_00220149::
	setvar 0x8004, 0xC
	special sub_08161E88
	delay 0x1
	compare_var_to_value 0x800D, 0x6
	goto_if 0x5, BattleFrontier_BattleTowerLobby_EventScript_00220149
	call BattleFrontier_BattleTowerLobby_EventScript_00220176
	clearflag 0x77
	warp 0x1A06, 0xFF, 0x1, 0x6
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_00220176::
	call BattleFrontier_BattleTowerLobby_EventScript_002201E8
	compare_var_to_value 0x40CE, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220193
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022019C

BattleFrontier_BattleTowerLobby_EventScript_00220193::
	messageautoscroll BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
	waitmessage
	delay 0x30

BattleFrontier_BattleTowerLobby_EventScript_0022019C::
	closemessage
	call BattleFrontier_BattleTowerLobby_EventScript_00220229
	call BattleFrontier_BattleTowerLobby_EventScript_0022026E
	applymovement 0x800F, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	applymovement 0xFF, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	waitmovement 0x0
	opendoor 0x8004, 0x1
	waitmoncry
	applymovement 0x800F, BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator
	applymovement 0xFF, BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator
	waitmovement 0x0
	closedoor 0x8004, 0x1
	waitmoncry
	return

BattleFrontier_BattleTowerLobby_Movement_WalkToElevator:
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Unused
BattleFrontier_BattleTowerLobby_Movement_UnusedEnterElevator:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end
BattleFrontier_BattleTowerLobby_EventScript_002201E8::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220215
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022021A
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022021F
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220224
	return

BattleFrontier_BattleTowerLobby_EventScript_00220215::
	bufferstdstring 0x0, 0x13
	return

BattleFrontier_BattleTowerLobby_EventScript_0022021A::
	bufferstdstring 0x0, 0x14
	return

BattleFrontier_BattleTowerLobby_EventScript_0022021F::
	bufferstdstring 0x0, 0x15
	return

BattleFrontier_BattleTowerLobby_EventScript_00220224::
	bufferstdstring 0x0, 0x16
	return

BattleFrontier_BattleTowerLobby_EventScript_00220229::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220256
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022025C
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220262
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220268
	return

BattleFrontier_BattleTowerLobby_EventScript_00220256::
	setvar 0x800F, 0x1
	return

BattleFrontier_BattleTowerLobby_EventScript_0022025C::
	setvar 0x800F, 0x7
	return

BattleFrontier_BattleTowerLobby_EventScript_00220262::
	setvar 0x800F, 0x8
	return

BattleFrontier_BattleTowerLobby_EventScript_00220268::
	setvar 0x800F, 0x9
	return

BattleFrontier_BattleTowerLobby_EventScript_0022026E::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022029B
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202A1
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202A7
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202AD
	return

BattleFrontier_BattleTowerLobby_EventScript_0022029B::
	setvar 0x8004, 0x6
	return

BattleFrontier_BattleTowerLobby_EventScript_002202A1::
	setvar 0x8004, 0xA
	return

BattleFrontier_BattleTowerLobby_EventScript_002202A7::
	setvar 0x8004, 0xE
	return

BattleFrontier_BattleTowerLobby_EventScript_002202AD::
	setvar 0x8004, 0x12
	return

BattleFrontier_BattleTowerLobby_EventScript_002202B3::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202E0
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202E6
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202EC
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002202F2
	return

BattleFrontier_BattleTowerLobby_EventScript_002202E0::
	setvar 0x8005, 0x3
	return

BattleFrontier_BattleTowerLobby_EventScript_002202E6::
	setvar 0x8005, 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002202EC::
	setvar 0x8005, 0x2
	return

BattleFrontier_BattleTowerLobby_EventScript_002202F2::
	setvar 0x8005, 0x2
	return

BattleFrontier_BattleTowerLobby_EventScript_002202F8::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	special CallFrontierUtilFunc
	return

BattleFrontier_BattleTowerLobby_EventScript_00220306::
	setvar 0x8004, 0x9
	message 0x08247C79
	waitmessage
	setvar 0x8005, 0x0
	special TryBattleLinkup
	waitstate
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203F0
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x08246FBE
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220368
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220392
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, 0x08246FB1
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203A7
	end

BattleFrontier_BattleTowerLobby_EventScript_00220368::
	special CloseLink
	compare_var_to_value 0x8005, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220380
	loadword 0x0, 0x08247D84
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_00220380::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode
	callstd 0x4
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_00220392::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers
	callstd 0x4
	special CloseLink
	loadword 0x0, 0x08247DAF
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_002203A7::
	special CloseLink
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203D5
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203DE
	compare_var_to_value 0x8005, 0x2
	call_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203E7
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_002203D5::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002203DE::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002203E7::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons
	callstd 0x4
	return

BattleFrontier_BattleTowerLobby_EventScript_002203F0::
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	special sub_080A0194
	waitstate
	playse 0x37
	waitse
	special TrySetBattleTowerLinkType
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_0022041B::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0021FDC7
	end

BattleFrontier_BattleTowerLobby_EventScript_00220429::
	setvar 0x8004, 0x14
	goto BattleFrontier_BattleTowerLobby_EventScript_00220434
	end

BattleFrontier_BattleTowerLobby_EventScript_00220434::
	message 0x082485D7
	waitmessage
	multichoice 0x10, 0x6, 0x51, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204A4
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220471
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220127
	end

BattleFrontier_BattleTowerLobby_EventScript_00220471::
	call 0x0824780F
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204D7
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220434
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220471
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203A7
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_002204A4::
	call 0x08247814
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204D7
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220434
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002204A4
	compare_var_to_value 0x800D, 0xB
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_002203A7
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_002204D7::
	incrementgamestat 0x1E
	setvar 0x40BC, 0x0
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x1
	special sub_08161E88
	special sub_080A0194
	waitstate
	playse 0x37
	waitse
	goto BattleFrontier_BattleTowerLobby_EventScript_00220134
	end

BattleFrontier_BattleTowerLobby_EventScript_002204FF::
	lockall
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_RulesAreListed
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022050E::
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 0x11, 0x2, 0x61, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220561
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022056F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022057D
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_0022058B
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220599
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerLobby_EventScript_00220599
	end

BattleFrontier_BattleTowerLobby_EventScript_00220561::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022056F::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainMonRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022057D::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_0022058B::
	loadword 0x0, BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules
	callstd 0x4
	goto BattleFrontier_BattleTowerLobby_EventScript_0022050E
	end

BattleFrontier_BattleTowerLobby_EventScript_00220599::
	releaseall
	end

BattleFrontier_BattleTowerLobby_Text_DirectYouToBattleRoom: @ 0x0822059B
	.string "それでは　バトルルームへ\n"
	.string "ごあんない　します！$"

BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting: @ 0x082205B3
	.string "おきゃくさま！\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたね？\p"
	.string "もうしわけ　ありませんが　そのばあい\n"
	.string "ちょうせんは　むこうと　なります$"

BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven: @ 0x08220604
	.string "おめでとう　ございます！\n"
	.string "みごと　7にんぬき　されましたね！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_EarnedFabulousPrize: @ 0x08220624
	.string "7にんぬきを　たっせい　されましたので\n"
	.string "この　しょうひんを　さしあげます！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_ReceivedPrize: @ 0x0822064B
	.string "{PLAYER}は\n"
	.string "{STR_VAR_1}を　もらった！$"

BattleFrontier_BattleTowerLobby_Text_BagFullMakeRoom: @ 0x08220659
	.string "⋯あら　どうぐが　いっぱいですね\p"
	.string "どうぐを　せいりしてから\n"
	.string "またおこしください$"

BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying: @ 0x08220681
	.string "おつかれさまでした！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved: @ 0x0822068D
	.string "せいせきを　レポートに　かきますので\n"
	.string "おまちください$"

BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou: @ 0x082206A8
	.string "おまちしておりました！\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved: @ 0x082206B5
	.string "バトルルームに　ごあんないする　まえに\n"
	.string "レポートを　かきますので　おまちください$"

BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer: @ 0x082206DE
	.string "いよいよ　つぎは　50にんめの\n"
	.string "トレーナー　ですね！\p"
	.string "これからは　7にんを　かちぬく　たびに\n"
	.string "あなたの　ポケモンに　きねんリボンが\l"
	.string "おくられますので　がんばって　くださいね！$"

BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons: @ 0x08220736
	.string "つよい　トレーナー　7にんを\n"
	.string "かちぬいた　きねんの　リボンを　どうぞ！\p"
	.string "{PLAYER}は　リボンを　もらった！$"

BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons: @ 0x08220769
	.string "{PLAYER}は　ポケモンに\n"
	.string "リボンを　つけて　あげた！$"

BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower: @ 0x08220781
	.string "ねえねえ！\p"
	.string "バトルタワーで　これから　しょうぶだ！\n"
	.string "⋯⋯ってとき　とか\p"
	.string "かったり　まけたり　したときって\n"
	.string "どんな　きもち　なのか　おしえてよ！$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin: @ 0x082207C9
	.string "じゃあ　さっそく\n"
	.string "しょうぶに　いどむときの　きもちを⋯⋯$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon: @ 0x082207E6
	.string "じゃあ　しょうぶに　かったときの\n"
	.string "きもちを　きかせて　もらおうかなー$"

BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost: @ 0x08220809
	.string "しょうぶに　まけちゃったとき\n"
	.string "どんな　きもちを　なるか　きかせて！$"

BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt: @ 0x0822082B
	.string "とくに　なにも　おもわないって　こと？\n"
	.string "きみって　クールなんだね$"

BattleFrontier_BattleTowerLobby_Text_ChangedYourMind: @ 0x0822084C
	.string "あれ？　やっぱり　やめたの？\n"
	.string "きみって　きまぐれ　なんだね$"

BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel: @ 0x0822086A
	.string "へえ　そんな　きぶんに　なるんだ！\n"
	.string "なかなか　こせいてき　だね⋯⋯\p"
	.string "どうも　ありがと！$"

BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded: @ 0x08220896
	.string "かちぬいた　トレーナーの　にんずうは\n"
	.string "きろく　されて　いるのよ！\p"
	.string "はずかしく　ない　たたかいを\n"
	.string "しなきゃ⋯⋯！$"

BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins: @ 0x082208CE
	.string "いちど　バトルタワーに　はいれば\n"
	.string "とちゅうで　まけちゃうか\l"
	.string "7にん　かちぬくまでは\l"
	.string "でられなく　なっちゃうんだ！\p"
	.string "かくごして　チャレンジ　しないとね！$"

BattleFrontier_BattleTowerLobby_Text_DoubleBattleRoomConstruction: @ 0x0822091A
	.string "バトルタワー　ダブルバトルコーナーへ\n"
	.string "ようこそ！\p"
	.string "げんざい　バトルルームは　こうじちゅうです\n"
	.string "かんせいまで　しばらく　おまちください$"

BattleFrontier_BattleTowerLobby_Text_MultiBattleRoomConstruction: @ 0x0822095D
	.string "バトルタワー　マルチバトルコーナーへ\n"
	.string "ようこそ！\p"
	.string "げんざい　バトルルームは　こうじちゅうです\n"
	.string "かんせいまで　しばらく　おまちください$"

BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge: @ 0x082209A0
	.string "またの　ちょうせんを\n"
	.string "おまちして　おります！$"

BattleFrontier_BattleTowerLobby_Text_WhichLevelMode: @ 0x082209B7
	.string "バトルルームには\n"
	.string "レベル50と　オープンレベルと　ありますが\l"
	.string "どちらに　はいりますか？$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectMons: @ 0x082209E3
	.string "では　さんかする　ポケモンを\n"
	.string "おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering: @ 0x082209FD
	.string "ごあんないする　まえに\n"
	.string "レポートを　かきますが　よろしいですか？$"

BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom: @ 0x08220A1E
	.string "それでは　{STR_VAR_1}　バトルルームに\n"
	.string "ごあんない　いたします！$"

BattleFrontier_BattleTowerLobby_Text_RecordLastMatch: @ 0x08220A3B
	.string "バトルタワーで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　しますか？$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50: @ 0x08220A68
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　{STR_VAR_2}ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "{STR_VAR_2}ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpen: @ 0x08220B16
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　{STR_VAR_2}ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "{STR_VAR_2}ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles: @ 0x08220BB9
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　3ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "3ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles: @ 0x08220C65
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　3ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "3ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles: @ 0x08220D06
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　4ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "4ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles: @ 0x08220DB2
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　4ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "4ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis: @ 0x08220E53
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　2ひき　いません！\p"
	.string "さんかする　ためには　レベルが　50いかで\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "2ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis: @ 0x08220EFF
	.string "おきゃくさま！\p"
	.string "さんかできる　ポケモンが　2ひき　いません！\p"
	.string "さんかする　ためには\n"
	.string "すべて　ちがうしゅるいの　ポケモンを\l"
	.string "2ひき　よういして　ください\p"
	.string "また　もたせる　どうぐも\n"
	.string "すべて　ちがう　どうぐに　してください！\p"
	.string "なお　タマゴ{STR_VAR_1}さんか　させることは　できません！\p"
	.string "じゅんびが　できましたら\n"
	.string "また　おこし　ください$"

BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle: @ 0x08220FA0
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは　シングル　バトルルームの\n"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge: @ 0x08220FE6
	.string "シングル　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge: @ 0x08221000
	.string "バトルタワー　シングル　バトルルームは\n"
	.string "3ひきの　ポケモンで\l"
	.string "シングルバトルを　おこなう　しせつです！\p"
	.string "タワーには　シングル　バトルルーム　という\n"
	.string "たいせんの　ための　へやが\l"
	.string "たくさん　ようい　されています！\p"
	.string "それぞれの　シングル　バトルルームには\n"
	.string "7にんの　トレーナーが　いて\l"
	.string "あなたの　チャレンジを　まっています！\p"
	.string "みごと　その　7にんを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ばあいは　しっかりと\l"
	.string "レポートに　かいて　おわらせないと\l"
	.string "ちょうせんは　むこうに　なってしまうので\l"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_SelectThreeMons: @ 0x08221126
	.string "では　さんかする　ポケモンを\n"
	.string "3ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle: @ 0x08221144
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは　ダブル　バトルルームの\n"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge: @ 0x08221189
	.string "ダブル　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge: @ 0x082211A2
	.string "バトルタワー　ダブル　バトルルームは\n"
	.string "4ひきの　ポケモンで\l"
	.string "ダブルバトルを　おこなう　しせつです！\p"
	.string "タワーには　ダブル　バトルルーム　という\n"
	.string "たいせんの　ための　へやが\l"
	.string "たくさん　ようい　されています！\p"
	.string "それぞれの　ダブル　バトルルームには\n"
	.string "7にんの　トレーナーが　いて\l"
	.string "あなたの　チャレンジを　まっています！\p"
	.string "みごと　その　7にんを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ばあいは　しっかりと\l"
	.string "レポートに　かいて　おわらせないと\l"
	.string "ちょうせんは　むこうに　なってしまうので\l"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons: @ 0x082212C4
	.string "では　さんかする　ポケモンを\n"
	.string "4ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle: @ 0x082212E2
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは　マルチ　バトルルームの\n"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge: @ 0x08221327
	.string "マルチ　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge: @ 0x08221340
	.string "マルチ　バトルルームは　タワーに　いる\n"
	.string "トレーナーと　きょうりょくして\l"
	.string "ポケモンを　2ひきずつ　もちより\l"
	.string "マルチバトルで　たたかう　しせつです！\p"
	.string "タワーないには　バトルサロン　という\n"
	.string "トレーナーの　あつまる　へやが\l"
	.string "ようい　されています！\p"
	.string "ここで　いっしょに　タッグを　くみたい\n"
	.string "トレーナーを　みつけて　ください！\p"
	.string "タッグが　くめたところで\n"
	.string "マルチ　バトルルームへ　おつれします！\p"
	.string "この　マルチ　バトルルームには\n"
	.string "7くみの　タッグ　トレーナーが　いて\l"
	.string "あなたの　チャレンジを　まっています！\p"
	.string "みごと　その　7くみを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　とちゅうで　ちょうせんを\n"
	.string "ちゅうだん　したい　ばあいは　しっかりと\l"
	.string "レポートに　かいて　おわらせないと\l"
	.string "ちょうせんは　むこうに　なってしまうので\l"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons: @ 0x082214BC
	.string "では　さんかする　ポケモンを\n"
	.string "2ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle: @ 0x082214DA
	.string "トレーナーの　さいのうを　はかる　ばしょ！\n"
	.string "バトルタワーへ　ようこそ！\p"
	.string "こちらでは\n"
	.string "つうしんマルチ　バトルルームの\l"
	.string "ごあんないを　しております！$"

BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge: @ 0x08221523
	.string "つうしんマルチ　バトルルームに\n"
	.string "ちょうせん　されますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge: @ 0x08221540
	.string "つうしんマルチ　バトルルームは\n"
	.string "ワイヤレスアダプタや　つうしんケーブルを\l"
	.string "つないだ　ともだちと　ふたりで\l"
	.string "ちがう　しゅるいの　ポケモンを\l"
	.string "2ひきずつ　もちより\l"
	.string "マルチバトルで　たたかう　しせつです！\p"
	.string "タワーないには　マルチ　バトルルームという\n"
	.string "たいせんの　ための　へやが\l"
	.string "たくさん　ようい　されています！\p"
	.string "それぞれ　マルチ　バトルルームには\n"
	.string "7くみの　タッグ　トレーナーが　いて\l"
	.string "あなたと　ともだちの　タッグでの\l"
	.string "チャレンジを　まっています！\p"
	.string "みごと　その　7くみを　たおせたら\n"
	.string "バトルポイントを　しんてい　いたします！\p"
	.string "また　ほかの　しせつと　ちがって\n"
	.string "ここでは　とちゅうで　ちょうせんを\l"
	.string "ちゅうだん　できません！\p"
	.string "7かい　れんぞくで　たたかうことに　なるので\n"
	.string "じゅうぶん　ちゅうい　してください！$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2: @ 0x0822169F
	.string "では　さんかする　ポケモンを\n"
	.string "2ひき　おえらび　ください！$"

BattleFrontier_BattleTowerLobby_Text_ChoseSameMonAsFriend: @ 0x082216BD
	.string "ともだちと\n"
	.string "おなじ　ポケモンを　えらんでいます！\p"
	.string "ともだちの　ポケモンと\n"
	.string "ちがう　しゅるいの　ポケモンを\l"
	.string "2ひき　えらび\l"
	.string "さんかする　レベルを　あわせて\l"
	.string "とうろくを　やりなおして　ください！$"

BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers: @ 0x0822171D
	.string "つうしんマルチ　バトルルームは\n"
	.string "{STR_VAR_1}にん　では　ちょうせん　できません！$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon: @ 0x08221742
	.string "ともだちも\n"
	.string "{STR_VAR_1}を　えらんでいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons: @ 0x08221755
	.string "ともだちも\n"
	.string "{STR_VAR_1}と　{STR_VAR_2}を\l"
	.string "えらんでいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode: @ 0x0822176C
	.string "ともだちと\n"
	.string "えらんだ　レベルが　ちがいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMon: @ 0x08221783
	.string "ともだちと\n"
	.string "えらんだ　レベルが　ちがいます！\p"
	.string "ともだちも\n"
	.string "{STR_VAR_1}を　えらんでいます！$"

BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMons: @ 0x082217AD
	.string "ともだちと\n"
	.string "えらんだ　レベルが　ちがいます！\p"
	.string "ともだちも\n"
	.string "{STR_VAR_1}と　{STR_VAR_2}を\l"
	.string "えらんでいます$"

BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode: @ 0x082217DA
	.string "ともだちの　ポケモンと\n"
	.string "ちがう　しゅるいの　ポケモンを\l"
	.string "2ひき　えらび\l"
	.string "さんかする　レベルを　あわせて\l"
	.string "とうろくを　やりなおして　ください！$"

BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn: @ 0x08221821
	.string "ごあんないする　まえに　レポートを　かきます\n"
	.string "しばらく　おまちください！$"

BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden: @ 0x08221846
	.string "おめでとう　ございます！\n"
	.string "タワータイクーンを　たおし\l"
	.string "みごと　7にんぬき　されましたね！$"

BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints: @ 0x08221873
	.string "おきゃくさまの\n"
	.string "かぎりない　さいのうを　たたえ\l"
	.string "バトルポイントを　しんてい　します！$"

BattleFrontier_Text_ObtainedXBattlePoints: @ 0x0822189E
	.string "{PLAYER}は　バトルポイントを\n"
	.string "{STR_VAR_1}　BP　てにいれた！$"

BattleFrontier_BattleTowerLobby_Text_RulesAreListed: @ 0x082218B8
	.string "バトルタワーの\n"
	.string "ルールが　かかれている！$"

BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading: @ 0x082218CD
	.string "どの　せつめいを　よみますか？$"

BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules: @ 0x082218DD
	.string "バトルタワーは\n"
	.string "シングルバトル　ダブルバトル　マルチバトル\l"
	.string "つうしんマルチバトル　というように\l"
	.string "4つの　たたかいが\l"
	.string "おこなわれる　しせつです\p"
	.string "それぞれの　たたかい　ごとに\n"
	.string "バトルルームと　よばれる\l"
	.string "たいせんの　へやが　ようい　されています\p"
	.string "ちょうせん　したい　たたかいの　うけつけに\n"
	.string "はなしかけて　いどみましょう$"

BattleFrontier_BattleTowerLobby_Text_ExplainMonRules: @ 0x0822197A
	.string "ちょうせんする　バトルルーム　ごとに\n"
	.string "つれていく　ポケモンの　かずが　かわります\p"
	.string "シングルでは　3ひき\n"
	.string "ダブルでは　4ひき\l"
	.string "マルチでは　2ひき　と　なっています$"

BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules: @ 0x082219CB
	.string "バトルサロンは　マルチバトルで\n"
	.string "タッグを　くむ　あいてを　さがす　へやです\p"
	.string "トレーナーの　ポケモンや　わざなどを　みて\n"
	.string "ベストな　あいてを　えらびましょう\p"
	.string "また　タッグを　くむ　あいては\n"
	.string "7れんしょう　ごとに　えらび　なおします$"

BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules: @ 0x08221A3E
	.string "つうしんマルチ　では\n"
	.string "ワイヤレスアダプタや　つうしんケーブルを\l"
	.string "つないだ　ともだちと　ふたりで\l"
	.string "ちょうせん　することが　できます\p"
	.string "うけつけで　2ひきを　えらびますが\n"
	.string "ともだちと　おなじ　ポケモンでは\l"
	.string "さんかする　ことが　できません\p"
	.string "また　ここでは　たたかいの　とちゅうで\n"
	.string "やすむ　ことは　できません$"
