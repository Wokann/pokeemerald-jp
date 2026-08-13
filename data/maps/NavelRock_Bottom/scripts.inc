@ NavelRock_Bottom scripts (JP map g26 m87 @ 0x0823C264)

NavelRock_Bottom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_EventScript_0023C26F
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_EventScript_0023C293
	.byte 0

NavelRock_Bottom_EventScript_0023C26F::
	checkflag 0x91
	call_if 0x1, NavelRock_Bottom_EventScript_0023C282
	checkflag 0x91
	call_if 0x0, NavelRock_Bottom_EventScript_0023C286
	end

NavelRock_Bottom_EventScript_0023C282::
	setflag 0x320
	return

NavelRock_Bottom_EventScript_0023C286::
	checkflag 0x1DD
	goto_if 0x1, 0x08244178
	clearflag 0x320
	return

NavelRock_Bottom_EventScript_0023C293::
	checkflag 0x8C1
	call_if 0x1, NavelRock_Bottom_EventScript_0023C29D
	end

NavelRock_Bottom_EventScript_0023C29D::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x1
	return

NavelRock_Bottom_EventScript_0023C2B1::
	lock
	faceplayer
	waitse
	delay 0x14
	playse 0x52
	setvar 0x8004, 0x0
	setvar 0x8005, 0x3
	setvar 0x8006, 0x4
	setvar 0x8007, 0x2
	special sub_081395D0
	delay 0x1E
	playse 0x52
	setvar 0x8004, 0x0
	setvar 0x8005, 0x3
	setvar 0x8006, 0x4
	setvar 0x8007, 0x2
	special sub_081395D0
	delay 0x1E
	delay 0x32
	waitse
	playmoncry 0xF9, 0x2
	waitdooranim
	delay 0x14
	setvar 0x8004, 0xF9
	setvar 0x8005, 0x46
	setvar 0x8006, 0x0
	special CreateObedientEnemyMon
	setflag 0x8C1
	special BattleSetup_StartLegendaryBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, NavelRock_Bottom_EventScript_0023C345
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, NavelRock_Bottom_EventScript_0023C353
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, NavelRock_Bottom_EventScript_0023C353
	setflag 0x91
	release
	end

NavelRock_Bottom_EventScript_0023C345::
	setflag 0x1DD
	setvar 0x8004, 0xF9
	goto 0x082441A0
	end

NavelRock_Bottom_EventScript_0023C353::
	setvar 0x8004, 0xF9
	goto 0x082441A0
	end

