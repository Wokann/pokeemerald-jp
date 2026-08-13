@ Route130 scripts (JP map g0 m45 @ 0x081EF38F)

Route130_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_EventScript_001EF395
	.byte 0

Route130_EventScript_001EF395::
	compare_var_to_value 0x405E, 0x4
	call_if 0x4, Route130_EventScript_001EF3E5
	specialvar 0x800D, IsMirageIslandPresent
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route130_EventScript_001EF3E1
	setflag 0x11
	setflag 0x12
	setflag 0x13
	setflag 0x14
	setflag 0x15
	setflag 0x16
	setflag 0x17
	setflag 0x18
	setflag 0x19
	setflag 0x1A
	setflag 0x1B
	setflag 0x1C
	setflag 0x1D
	setflag 0x1E
	setflag 0x1F
	setmaplayoutindex 0x107
	end

Route130_EventScript_001EF3E1::
	setmaplayoutindex 0x2E
	end

Route130_EventScript_001EF3E5::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	return

	.incbin "baserom_jp.gba", 0x1ef3ef, 0x45
