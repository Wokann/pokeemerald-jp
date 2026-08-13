@ AbandonedShip_Rooms_B1F scripts (JP map g24 m58 @ 0x0821AD78)

AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_EventScript_0021AD7E
	.byte 0

AbandonedShip_Rooms_B1F_EventScript_0021AD7E::
	setdivewarp 0x1840, 0xFF, 0x11, 0x4
	end

AbandonedShip_Rooms_B1F_EventScript_0021AD87::
	loadword 0x0, 0x0821AD90
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x21ad90, 0x7a
