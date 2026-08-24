@ NavelRock_Top scripts (JP map g26 m75 @ 0x0823C122)

NavelRock_Top_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Top_EventScript_0023C12D
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Top_EventScript_0023C160
	.byte 0

NavelRock_Top_EventScript_0023C12D::
	checkflag 0x92
	call_if 0x1, NavelRock_Top_EventScript_0023C140
	checkflag 0x92
	call_if 0x0, NavelRock_Top_EventScript_0023C149
	end

NavelRock_Top_EventScript_0023C140::
	setvar 0x4001, 0x1
	setflag 0x321
	return

NavelRock_Top_EventScript_0023C149::
	setvar 0x4001, 0x1
	checkflag 0x1DC
	goto_if 0x1, 0x08244178
	setvar 0x4001, 0x0
	clearflag 0x321
	return

NavelRock_Top_EventScript_0023C160::
	checkflag 0x8C1
	call_if 0x1, NavelRock_Top_EventScript_0023C16A
	end

NavelRock_Top_EventScript_0023C16A::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x1
	return

NavelRock_Top_EventScript_0023C17E::
	lockall
	setvar 0x4001, 0x1
	special SpawnCameraObject
	setvar 0x8004, 0x3
	setvar 0x8005, 0x23
	special sub_0813B844
	applymovement 0x1, 0x0823C252
	applymovement 0x7F, 0x0823C23F
	waitmovement 0x0
	delay 0x32
	setweather 0x0
	resetweather
	waitse
	playmoncry 0xFA, 0x2
	delay 0x1E
	waitdooranim
	delay 0x3C
	setvar 0x8004, 0x3
	setvar 0x8005, 0x23
	special sub_0813B844
	applymovement 0x7F, 0x0823C243
	applymovement 0x1, 0x0823C249
	waitmovement 0x0
	special RemoveCameraObject
	setvar 0x8004, 0xFA
	setvar 0x8005, 0x46
	setvar 0x8006, 0x0
	special CreateObedientEnemyMon
	setflag 0x8C1
	special BattleSetup_StartLegendaryBattle
	clearflag 0x8C1
	setvar 0x800F, 0x1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, NavelRock_Top_EventScript_0023C226
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, NavelRock_Top_EventScript_0023C234
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, NavelRock_Top_EventScript_0023C234
	setflag 0x92
	releaseall
	end

NavelRock_Top_EventScript_0023C226::
	setflag 0x1DC
	setvar 0x8004, 0xFA
	goto 0x082441A0
	end

NavelRock_Top_EventScript_0023C234::
	setvar 0x8004, 0xFA
	goto 0x082441A0
	end
