@ SkyPillar_Entrance scripts (JP map g24 m77 @ 0x0821BBE3)

SkyPillar_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Entrance_OnTransition
	.byte 0

SkyPillar_Entrance_OnTransition: @ 0x0821BBE9
	setflag FLAG_LANDMARK_SKY_PILLAR
	end
