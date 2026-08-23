@ GraniteCave_B1F scripts (JP map g24 m8 @ 0x0821400B)

GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x0826432F
	map_script MAP_SCRIPT_ON_TRANSITION, 0x08264339
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_EventScript_0021401B
	.byte 0

GraniteCave_B1F_EventScript_0021401B::
	setstepcallback 0x7
	setholewarp 0x1809, 0xFF, 0x0, 0x0
	end
