@ MarineCave_Entrance scripts (JP map g24 m102 @ 0x0821CFF5)

MarineCave_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_Entrance_OnResume
	.byte 0

MarineCave_Entrance_OnResume:: @ 0x0821CFFB
	setdivewarp MAP_UNDERWATER_MARINE_CAVE, 9, 6
	end
