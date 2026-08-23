@ Route131 scripts (JP map g0 m46 @ 0x081EF434)

Route131_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route131_EventScript_001EF43A
	.byte 0

Route131_EventScript_001EF43A::
	compare_var_to_value 0x405E, 0x4
	call_if 0x4, Route131_EventScript_001EF44F
	call Route131_EventScript_001EF44B
	end

Route131_EventScript_001EF44B::
	setmaplayoutindex 0x13F
	return

Route131_EventScript_001EF44F::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	return

	.incbin "baserom_jp.gba", 0x1ef459, 0xc0
