@ SkyPillar_5F scripts (JP map g24 m84 @ 0x0821BF12)

SkyPillar_5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_5F_EventScript_0021BF18
	.byte 0

SkyPillar_5F_EventScript_0021BF18::
	compare_var_to_value 0x40CA, 0x2
	call_if 0x0, SkyPillar_5F_EventScript_0021BF24
	return

SkyPillar_5F_EventScript_0021BF24::
	setmaplayoutindex 0x1B5
	return

