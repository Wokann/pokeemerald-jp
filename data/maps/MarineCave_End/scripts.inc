@ MarineCave_End scripts (JP map g24 m103 @ 0x0821D004)

MarineCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_EventScript_0021D00F
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_EventScript_0021D02D
	.byte 0

MarineCave_End_EventScript_0021D00F::
	checkflag 0x8C1
	call_if 0x1, MarineCave_End_EventScript_0021D019
	end

MarineCave_End_EventScript_0021D019::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x1
	return

MarineCave_End_EventScript_0021D02D::
	checkflag 0x1BE
	call_if 0x0, MarineCave_End_EventScript_0021D037
	end

MarineCave_End_EventScript_0021D037::
	clearflag 0x30E
	setvar 0x4001, 0x1
	return

MarineCave_End_EventScript_0021D040::
	lockall
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	applymovement 0x1, 0x0821D0C2
	waitmovement 0x0
	waitse
	playmoncry 0x194, 0x2
	delay 0x28
	waitdooranim
	setvar 0x800F, 0x1
	setwildbattle 0x194, 0x46, 0x0
	setflag 0x8C1
	special BattleSetup_StartLegendaryBattle
	clearflag 0x8C1
	setvar 0x4001, 0x0
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, MarineCave_End_EventScript_0021D0A9
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, MarineCave_End_EventScript_0021D0B7
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, MarineCave_End_EventScript_0021D0B7
	setvar 0x4039, 0x1
	setflag 0x1BE
	releaseall
	end

MarineCave_End_EventScript_0021D0A9::
	setvar 0x4039, 0x1
	setflag 0x1BE
	goto 0x08244197
	end

MarineCave_End_EventScript_0021D0B7::
	setvar 0x8004, 0x194
	goto 0x082441A0
	end
