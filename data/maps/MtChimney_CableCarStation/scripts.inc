@ MtChimney_CableCarStation scripts (JP map g19 m1 @ 0x0821201F)

MtChimney_CableCarStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_CableCarStation_EventScript_0021202A
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtChimney_CableCarStation_MapScriptTable_00212042
	.byte 0

MtChimney_CableCarStation_EventScript_0021202A::
	compare_var_to_value 0x40A3, 0x1
	call_if 0x1, MtChimney_CableCarStation_EventScript_00212036
	end

MtChimney_CableCarStation_EventScript_00212036::
	setobjectxyperm 0x1, 0x5, 0x4
	setobjectmovementtype 0x1, 0xA
	return

MtChimney_CableCarStation_MapScriptTable_00212042::
	map_script_2 0x40A3, 0x1, MtChimney_CableCarStation_EventScript_0021204C
	.2byte 0

MtChimney_CableCarStation_EventScript_0021204C::
	lockall
	applymovement 0xFF, 0x082120D9
	applymovement 0x1, 0x082120CF
	waitmovement 0x0
	setvar 0x40A3, 0x0
	setobjectxyperm 0x1, 0x6, 0x7
	setobjectmovementtype 0x1, 0x8
	releaseall
	end

MtChimney_CableCarStation_EventScript_00212070::
	lock
	faceplayer
	loadword 0x0, 0x082120DE
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, MtChimney_CableCarStation_EventScript_00212091
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MtChimney_CableCarStation_EventScript_002120C0
	end

MtChimney_CableCarStation_EventScript_00212091::
	loadword 0x0, 0x08212105
	callstd 0x4
	closemessage
	applymovement 0x1, 0x082120CA
	applymovement 0xFF, 0x082120D4
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x40A3, 0x2
	incrementgamestat 0x30
	special CableCarWarp
	special CableCar
	release
	end

MtChimney_CableCarStation_EventScript_002120C0::
	loadword 0x0, 0x08212112
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x2120ca, 0x62
