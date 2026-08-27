@ AlteringCave scripts (JP map g24 m106 @ 0x0821D19C)

AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition::
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end
