@ TerraCave_End scripts (JP map g24 m105 @ 0x0821D0D5)

TerraCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_EventScript_0021D0E0
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_EventScript_0021D0FE
	.byte 0

TerraCave_End_EventScript_0021D0E0::
	checkflag 0x8C1
	call_if 0x1, TerraCave_End_EventScript_0021D0EA
	end

TerraCave_End_EventScript_0021D0EA::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x1
	return

TerraCave_End_EventScript_0021D0FE::
	checkflag 0x1BF
	call_if 0x0, TerraCave_End_EventScript_0021D108
	end

TerraCave_End_EventScript_0021D108::
	clearflag 0x30F
	setvar 0x4001, 0x1
	return

TerraCave_End_EventScript_0021D111::
	lockall
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	applymovement 0x1, 0x0821D193
	waitmovement 0x0
	waitse
	playmoncry 0x195, 0x2
	delay 0x28
	waitdooranim
	setvar 0x800F, 0x1
	setwildbattle 0x195, 0x46, 0x0
	setflag 0x8C1
	special BattleSetup_StartLegendaryBattle
	clearflag 0x8C1
	setvar 0x4001, 0x0
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, TerraCave_End_EventScript_0021D17A
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, TerraCave_End_EventScript_0021D188
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, TerraCave_End_EventScript_0021D188
	setvar 0x4039, 0x1
	setflag 0x1BF
	releaseall
	end

TerraCave_End_EventScript_0021D17A::
	setvar 0x4039, 0x1
	setflag 0x1BF
	goto 0x08244197
	end

TerraCave_End_EventScript_0021D188::
	setvar 0x8004, 0x195
	goto 0x082441A0
	end
