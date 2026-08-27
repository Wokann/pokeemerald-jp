@ AbandonedShip_Underwater1 scripts (JP map g24 m60 @ 0x0821AE0A)

AbandonedShip_Underwater1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater1_OnResume
	.byte 0

AbandonedShip_Underwater1_OnResume:: @ 0x0821AE10
	setdivewarp MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, 0, 10
	end
