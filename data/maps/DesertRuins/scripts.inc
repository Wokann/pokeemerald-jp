@ DesertRuins scripts (JP map g24 m6 @ 0x08213DDF)

DesertRuins_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_EventScript_00213DEF
	map_script MAP_SCRIPT_ON_LOAD, DesertRuins_EventScript_00213E0D
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_EventScript_00213E4E
	.byte 0

DesertRuins_EventScript_00213DEF::
	checkflag 0x8C1
	call_if 0x1, DesertRuins_EventScript_00213DF9
	end

DesertRuins_EventScript_00213DF9::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

DesertRuins_EventScript_00213E0D::
	checkflag 0x8B0
	call_if 0x0, DesertRuins_EventScript_00213E17
	end

DesertRuins_EventScript_00213E17::
	setmetatile 0x7, 0x13, 0x229, 0x1
	setmetatile 0x8, 0x13, 0x229, 0x1
	setmetatile 0x9, 0x13, 0x229, 0x1
	setmetatile 0x7, 0x14, 0x235, 0x1
	setmetatile 0x8, 0x14, 0x235, 0x1
	setmetatile 0x9, 0x14, 0x235, 0x1
	return

DesertRuins_EventScript_00213E4E::
	setflag 0x8B6
	checkflag 0x1BB
	call_if 0x0, DesertRuins_EventScript_00213E5B
	end

DesertRuins_EventScript_00213E5B::
	clearflag 0x3A7
	return

DesertRuins_EventScript_00213E5F::
	lockall
	checkflag 0x8B0
	goto_if 0x1, DesertRuins_EventScript_00213E72
	braillemessage 0x08263753
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

DesertRuins_EventScript_00213E72::
	loadword 0x0, 0x08243CDA
	callstd 0x4
	releaseall
	end

DesertRuins_EventScript_00213E7C::
	lockall
	braillemessage 0x08263753
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

DesertRuins_EventScript_00213E86::
	lock
	faceplayer
	waitse
	playmoncry 0x191, 0x2
	delay 0x28
	waitdooranim
	setwildbattle 0x191, 0x28, 0x0
	setflag 0x8C1
	special StartRegiBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, DesertRuins_EventScript_00213ECD
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, DesertRuins_EventScript_00213ED6
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, DesertRuins_EventScript_00213ED6
	setflag 0x1BB
	release
	end

DesertRuins_EventScript_00213ECD::
	setflag 0x1BB
	goto 0x08244197
	end

DesertRuins_EventScript_00213ED6::
	setvar 0x8004, 0x191
	goto 0x082441A0
	end
