@ MirageTower_2F scripts (JP map g24 m95 @ 0x0821CDD6)

MirageTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x0826432F
	map_script MAP_SCRIPT_ON_TRANSITION, 0x08264339
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_2F_EventScript_0021CDE6
	.byte 0

MirageTower_2F_EventScript_0021CDE6::
	setstepcallback 0x7
	setholewarp 0x185E, 0xFF, 0x0, 0x0
	end

