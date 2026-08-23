@ SeafloorCavern_Entrance scripts (JP map g24 m27 @ 0x0821844E)

SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_EventScript_00218454
	.byte 0

SeafloorCavern_Entrance_EventScript_00218454::
	setdivewarp 0x181A, 0xFF, 0x6, 0x5
	setescapewarp 0x181A, 0xFF, 0x6, 0x5
	end

SeafloorCavern_Entrance_EventScript_00218465::
	lockall
	compare_var_to_value 0x40D9, 0x1
	goto_if 0x1, SeafloorCavern_Entrance_EventScript_002184CD
	waitse
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	delay 0x14
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, SeafloorCavern_Entrance_EventScript_0021850E
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, SeafloorCavern_Entrance_EventScript_00218503
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, SeafloorCavern_Entrance_EventScript_00218519
	delay 0x1E
	setvar 0x40D9, 0x1
	moveobjectoffscreen 0x1
	loadword 0x0, 0x08218524
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_002184CD::
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, SeafloorCavern_Entrance_EventScript_0021850E
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, SeafloorCavern_Entrance_EventScript_00218503
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, SeafloorCavern_Entrance_EventScript_00218519
	loadword 0x0, 0x082185E0
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_00218503::
	applymovement 0x1, 0x08243627
	waitmovement 0x0
	return

SeafloorCavern_Entrance_EventScript_0021850E::
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	return

SeafloorCavern_Entrance_EventScript_00218519::
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x218524, 0x13a
