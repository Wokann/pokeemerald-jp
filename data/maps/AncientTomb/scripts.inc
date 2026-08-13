@ AncientTomb scripts (JP map g24 m68 @ 0x0821B8F8)

AncientTomb_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AncientTomb_EventScript_0021B908
	map_script MAP_SCRIPT_ON_LOAD, AncientTomb_EventScript_0021B937
	map_script MAP_SCRIPT_ON_TRANSITION, AncientTomb_EventScript_0021B926
	.byte 0

AncientTomb_EventScript_0021B908::
	checkflag 0x8C1
	call_if 0x1, AncientTomb_EventScript_0021B912
	end

AncientTomb_EventScript_0021B912::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

AncientTomb_EventScript_0021B926::
	setflag 0x8B9
	checkflag 0x1BD
	call_if 0x0, AncientTomb_EventScript_0021B933
	end

AncientTomb_EventScript_0021B933::
	clearflag 0x3A9
	return

AncientTomb_EventScript_0021B937::
	checkflag 0x8B2
	call_if 0x0, AncientTomb_EventScript_0021B941
	end

AncientTomb_EventScript_0021B941::
	setmetatile 0x7, 0x13, 0x229, 0x1
	setmetatile 0x8, 0x13, 0x229, 0x1
	setmetatile 0x9, 0x13, 0x229, 0x1
	setmetatile 0x7, 0x14, 0x235, 0x1
	setmetatile 0x8, 0x14, 0x235, 0x1
	setmetatile 0x9, 0x14, 0x235, 0x1
	return

AncientTomb_EventScript_0021B978::
	lockall
	checkflag 0x8B2
	goto_if 0x1, AncientTomb_EventScript_0021B98B
	braillemessage 0x08263799
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

AncientTomb_EventScript_0021B98B::
	loadword 0x0, 0x08243CDA
	callstd 0x4
	releaseall
	end

AncientTomb_EventScript_0021B995::
	lockall
	braillemessage 0x08263799
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

AncientTomb_EventScript_0021B99F::
	lock
	faceplayer
	waitse
	playmoncry 0x193, 0x2
	delay 0x28
	waitdooranim
	setwildbattle 0x193, 0x28, 0x0
	setflag 0x8C1
	special StartRegiBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, AncientTomb_EventScript_0021B9E6
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, AncientTomb_EventScript_0021B9EF
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, AncientTomb_EventScript_0021B9EF
	setflag 0x1BD
	release
	end

AncientTomb_EventScript_0021B9E6::
	setflag 0x1BD
	goto 0x08244197
	end

AncientTomb_EventScript_0021B9EF::
	setvar 0x8004, 0x193
	goto 0x082441A0
	end

