@ Route123 scripts (JP map g0 m38 @ 0x081EE3D6)

Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_EventScript_001EE3DC
	.byte 0

Route123_EventScript_001EE3DC::
	special SetRoute123Weather
	end

Route123_EventScript_001EE3E0::
	lock
	faceplayer
	checkflag 0xE8
	goto_if 0x1, Route123_EventScript_001EE42F
	loadword 0x0, 0x081EE6AD
	callstd 0x4
	special IsGrassTypeInParty
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route123_EventScript_001EE42D
	loadword 0x0, 0x081EE6E3
	callstd 0x4
	setorcopyvar 0x8000, 0x133
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0xE8
	loadword 0x0, 0x081EE722
	callstd 0x4
	release
	end

Route123_EventScript_001EE42D::
	release
	end

Route123_EventScript_001EE42F::
	loadword 0x0, 0x081EE722
	callstd 0x4
	release
	end

Route123_EventScript_001EE439::
	loadword 0x0, 0x081EE753
	callstd 0x3
	end

Route123_EventScript_001EE442::
	loadword 0x0, 0x081EE76F
	callstd 0x3
	end

Route123_EventScript_001EE44B::
	loadword 0x0, 0x081EE790
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1ee454, 0x34b
