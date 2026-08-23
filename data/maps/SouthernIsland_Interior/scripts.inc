@ SouthernIsland_Interior scripts (JP map g26 m10 @ 0x082227E2)

SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_EventScript_002227ED
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_EventScript_0022280B
	.byte 0

SouthernIsland_Interior_EventScript_002227ED::
	checkflag 0x8C1
	call_if 0x1, SouthernIsland_Interior_EventScript_002227F7
	end

SouthernIsland_Interior_EventScript_002227F7::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x2
	return

SouthernIsland_Interior_EventScript_0022280B::
	compare_var_to_value 0x40D5, 0x0
	call_if 0x1, SouthernIsland_Interior_EventScript_00222827
	compare_var_to_value 0x40D5, 0x0
	call_if 0x5, SouthernIsland_Interior_EventScript_00222832
	call SouthernIsland_Interior_EventScript_0022283D
	end

SouthernIsland_Interior_EventScript_00222827::
	setvar 0x4011, 0xBC
	setvar 0x4004, 0x198
	return

SouthernIsland_Interior_EventScript_00222832::
	setvar 0x4011, 0xBB
	setvar 0x4004, 0x197
	return

SouthernIsland_Interior_EventScript_0022283D::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SouthernIsland_Interior_EventScript_00222855
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SouthernIsland_Interior_EventScript_0022285B
	end

SouthernIsland_Interior_EventScript_00222855::
	setvar 0x4010, 0x64
	return

SouthernIsland_Interior_EventScript_0022285B::
	setvar 0x4010, 0x69
	return

SouthernIsland_Interior_EventScript_00222861::
	lockall
	setvar 0x8008, 0xC
	goto SouthernIsland_Interior_EventScript_0022286D
	end

SouthernIsland_Interior_EventScript_0022286D::
	checkflag 0x2
	goto_if 0x1, SouthernIsland_Interior_EventScript_00222937
	checkflag 0x1C8
	goto_if 0x1, SouthernIsland_Interior_EventScript_00222937
	checkflag 0x1C9
	goto_if 0x1, SouthernIsland_Interior_EventScript_00222937
	checkflag 0x8B3
	goto_if 0x0, SouthernIsland_Interior_EventScript_00222937
	setflag 0xCE
	setflag 0x2
	special SpawnCameraObject
	applymovement 0x7F, 0x08222967
	waitmovement 0x0
	delay 0x32
	waitse
	playmoncry 0x4004, 0x0
	delay 0x1E
	waitdooranim
	addobject 0x2
	delay 0x1E
	applymovement 0x7F, 0x0822296B
	applymovement 0x2, 0x08222977
	waitmovement 0x0
	delay 0x32
	special RemoveCameraObject
	setvar 0x800F, 0x2
	compare_var_to_value 0x40D5, 0x0
	call_if 0x1, SouthernIsland_Interior_EventScript_00222941
	compare_var_to_value 0x40D5, 0x0
	call_if 0x5, SouthernIsland_Interior_EventScript_00222954
	setflag 0x8C1
	special BattleSetup_StartLatiBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SouthernIsland_Interior_EventScript_0022291E
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, SouthernIsland_Interior_EventScript_0022292C
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, SouthernIsland_Interior_EventScript_0022292C
	setflag 0x1C9
	releaseall
	end

SouthernIsland_Interior_EventScript_0022291E::
	setflag 0x1C8
	copyvar 0x8004, 0x4004
	goto 0x082441A0
	end

SouthernIsland_Interior_EventScript_0022292C::
	copyvar 0x8004, 0x4004
	goto 0x082441A0
	end

SouthernIsland_Interior_EventScript_00222937::
	loadword 0x0, 0x0826358B
	callstd 0x4
	releaseall
	end

SouthernIsland_Interior_EventScript_00222941::
	setvar 0x8004, 0x198
	setvar 0x8005, 0x32
	setvar 0x8006, 0xBF
	special CreateObedientEnemyMon
	return

SouthernIsland_Interior_EventScript_00222954::
	setvar 0x8004, 0x197
	setvar 0x8005, 0x32
	setvar 0x8006, 0xBF
	special CreateObedientEnemyMon
	return

	.incbin "baserom_jp.gba", 0x222967, 0x1c
