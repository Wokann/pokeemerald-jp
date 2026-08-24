@ BirthIsland_Exterior scripts (JP map g26 m58 @ 0x0823B5CE)

BirthIsland_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_EventScript_0023B5E2
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_EventScript_0023B61E
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_EventScript_0023B5DE
	.byte 0

BirthIsland_Exterior_EventScript_0023B5DE::
	special sub_0813B208
	end

BirthIsland_Exterior_EventScript_0023B5E2::
	setflag 0x8D3
	setvar 0x4010, 0x64
	setvar 0x4034, 0x0
	setvar 0x4035, 0x0
	checkflag 0x1AD
	call_if 0x1, BirthIsland_Exterior_EventScript_0023B607
	checkflag 0x1AD
	call_if 0x0, BirthIsland_Exterior_EventScript_0023B60E
	end

BirthIsland_Exterior_EventScript_0023B607::
	setflag 0x2FB
	setflag 0x2FC
	return

BirthIsland_Exterior_EventScript_0023B60E::
	checkflag 0x1AC
	goto_if 0x1, 0x08244178
	clearflag 0x2FC
	clearflag 0x8D4
	return

BirthIsland_Exterior_EventScript_0023B61E::
	checkflag 0x8C1
	call_if 0x1, BirthIsland_Exterior_EventScript_0023B628
	end

BirthIsland_Exterior_EventScript_0023B628::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x2
	return

BirthIsland_Exterior_EventScript_0023B63C::
	lock
	faceplayer
	special DoDeoxysRockInteraction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BirthIsland_Exterior_EventScript_0023B674
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BirthIsland_Exterior_EventScript_0023B676
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BirthIsland_Exterior_EventScript_0023B67A
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BirthIsland_Exterior_EventScript_0023B678
	end

BirthIsland_Exterior_EventScript_0023B674::
	release
	end

BirthIsland_Exterior_EventScript_0023B676::
	release
	end

BirthIsland_Exterior_EventScript_0023B678::
	release
	end

BirthIsland_Exterior_EventScript_0023B67A::
	waitse
	setfieldeffectarg 0x0, 0x1
	setfieldeffectarg 0x1, 0x3A
	setfieldeffectarg 0x2, 0x1A
	dofieldeffect 0x41
	playbgm 0x22B, 0x0
	waitfieldeffect 0x41
	addobject 0x2
	applymovement 0x2, 0x0823B70D
	waitmovement 0x0
	waitse
	playmoncry 0x19A, 0x2
	delay 0x28
	waitdooranim
	setvar 0x800F, 0x2
	setvar 0x8004, 0x19A
	setvar 0x8005, 0x1E
	setvar 0x8006, 0x0
	special CreateObedientEnemyMon
	setflag 0x8C1
	special BattleSetup_StartLegendaryBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BirthIsland_Exterior_EventScript_0023B6F4
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, BirthIsland_Exterior_EventScript_0023B702
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, BirthIsland_Exterior_EventScript_0023B702
	setflag 0x1AD
	release
	end

BirthIsland_Exterior_EventScript_0023B6F4::
	setflag 0x1AC
	setvar 0x8004, 0x19A
	goto 0x082441A0
	end

BirthIsland_Exterior_EventScript_0023B702::
	setvar 0x8004, 0x19A
	goto 0x082441A0
	end
