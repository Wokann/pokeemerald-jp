@ Underwater_MarineCave scripts (JP map g24 m101 @ 0x0821CFDD)

Underwater_MarineCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_MarineCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_MarineCave_OnTransition
	.byte 0

Underwater_MarineCave_OnTransition:: @ 0x0821CFE8
	setflag FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT
	end

Underwater_MarineCave_OnResume:: @ 0x0821CFEC
	setdivewarp MAP_MARINE_CAVE_ENTRANCE, 10, 17
	end
