@ SkyPillar_3F scripts (JP map g24 m81 @ 0x0821BECB)

SkyPillar_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_3F_EventScript_0021BED1
	.byte 0

SkyPillar_3F_EventScript_0021BED1::
	compare_var_to_value 0x40CA, 0x2
	call_if 0x0, SkyPillar_3F_EventScript_0021BEDD
	end

SkyPillar_3F_EventScript_0021BEDD::
	setmaplayoutindex 0x1B3
	return

