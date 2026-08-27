@ AbandonedShip_Underwater2 scripts (JP map g24 m64 @ 0x0821B331)

AbandonedShip_Underwater2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater2_OnResume
	.byte 0

AbandonedShip_Underwater2_OnResume:: @ 0x0821B337
	setdivewarp MAP_ABANDONED_SHIP_ROOMS_B1F, 13, 7
	end
