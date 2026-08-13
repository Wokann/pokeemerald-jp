@ SkyPillar_2F scripts (JP map g24 m80 @ 0x0821BE9B)

SkyPillar_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x0826432F
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_2F_EventScript_0021BEAB
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_2F_EventScript_0021BEC0
	.byte 0

SkyPillar_2F_EventScript_0021BEAB::
	compare_var_to_value 0x40CA, 0x2
	call_if 0x0, SkyPillar_2F_EventScript_0021BEBC
	copyvar 0x4022, 0x1
	end

SkyPillar_2F_EventScript_0021BEBC::
	setmaplayoutindex 0x1B2
	return

SkyPillar_2F_EventScript_0021BEC0::
	setstepcallback 0x7
	setholewarp 0x184F, 0xFF, 0x0, 0x0
	end

