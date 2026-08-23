@ SkyPillar_4F scripts (JP map g24 m82 @ 0x0821BEE1)

SkyPillar_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x0826432F
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_4F_EventScript_0021BEF1
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_4F_EventScript_0021BF06
	.byte 0

SkyPillar_4F_EventScript_0021BEF1::
	compare_var_to_value 0x40CA, 0x2
	call_if 0x0, SkyPillar_4F_EventScript_0021BF02
	copyvar 0x4022, 0x1
	end

SkyPillar_4F_EventScript_0021BF02::
	setmaplayoutindex 0x1B4
	return

SkyPillar_4F_EventScript_0021BF06::
	setstepcallback 0x7
	setholewarp 0x1851, 0xFF, 0x0, 0x0
	end
