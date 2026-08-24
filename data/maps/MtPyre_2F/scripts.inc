@ MtPyre_2F scripts (JP map g24 m16 @ 0x08216230)

MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x0826432F
	map_script MAP_SCRIPT_ON_TRANSITION, 0x08264339
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_EventScript_00216240
	.byte 0

MtPyre_2F_EventScript_00216240::
	setstepcallback 0x7
	setholewarp 0x180F, 0xFF, 0x0, 0x0
	end

MtPyre_2F_EventScript_0021624B::
	loadword 0x0, 0x082162D8
	callstd 0x2
	end

MtPyre_2F_EventScript_00216254::
	loadword 0x0, 0x08216301
	callstd 0x2
	end
