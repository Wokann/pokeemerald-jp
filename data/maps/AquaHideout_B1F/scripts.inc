@ AquaHideout_B1F scripts (JP map g24 m24 @ 0x08217CB0)

AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_EventScript_00217CBB
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_EventScript_00217CD9
	.byte 0

AquaHideout_B1F_EventScript_00217CBB::
	checkflag 0x8C1
	call_if 0x1, AquaHideout_B1F_EventScript_00217CC5
	end

AquaHideout_B1F_EventScript_00217CC5::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

AquaHideout_B1F_EventScript_00217CD9::
	checkflag 0x1C4
	call_if 0x0, AquaHideout_B1F_EventScript_00217CEC
	checkflag 0x1C5
	call_if 0x0, AquaHideout_B1F_EventScript_00217CF0
	end

AquaHideout_B1F_EventScript_00217CEC::
	clearflag 0x3D1
	return

AquaHideout_B1F_EventScript_00217CF0::
	clearflag 0x3D2
	return

AquaHideout_B1F_EventScript_00217CF4::
	lock
	faceplayer
	setwildbattle 0x65, 0x1E, 0x0
	waitse
	playmoncry 0x65, 0x2
	delay 0x28
	waitdooranim
	setflag 0x8C1
	dowildbattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, AquaHideout_B1F_EventScript_00217D38
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, AquaHideout_B1F_EventScript_00217D38
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, AquaHideout_B1F_EventScript_00217D38
	setflag 0x1C4
	release
	end

AquaHideout_B1F_EventScript_00217D38::
	setflag 0x1C4
	goto 0x08244197
	end

AquaHideout_B1F_EventScript_00217D41::
	lock
	faceplayer
	setwildbattle 0x65, 0x1E, 0x0
	waitse
	playmoncry 0x65, 0x2
	delay 0x28
	waitdooranim
	setflag 0x8C1
	dowildbattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, AquaHideout_B1F_EventScript_00217D85
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, AquaHideout_B1F_EventScript_00217D85
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, AquaHideout_B1F_EventScript_00217D85
	setflag 0x1C5
	release
	end

AquaHideout_B1F_EventScript_00217D85::
	setflag 0x1C5
	goto 0x08244197
	end

	.incbin "baserom_jp.gba", 0x217d8e, 0x211
