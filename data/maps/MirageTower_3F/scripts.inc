@ MirageTower_3F scripts (JP map g24 m96 @ 0x0821CDF1)

MirageTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x0826432F
	map_script MAP_SCRIPT_ON_TRANSITION, 0x08264339
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_3F_EventScript_0021CE01
	.byte 0

MirageTower_3F_EventScript_0021CE01::
	setstepcallback 0x7
	setholewarp 0x185F, 0xFF, 0x0, 0x0
	end
