@ SkyPillar_1F scripts (JP map g24 m79 @ 0x0821BE85)

SkyPillar_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_1F_EventScript_0021BE8B
	.byte 0

SkyPillar_1F_EventScript_0021BE8B::
	compare_var_to_value 0x40CA, 0x2
	call_if 0x0, SkyPillar_1F_EventScript_0021BE97
	end

SkyPillar_1F_EventScript_0021BE97::
	setmaplayoutindex 0x1B1
	return

