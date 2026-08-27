@ ScorchedSlab scripts (JP map g24 m73 @ 0x0821BBD6)

ScorchedSlab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	.byte 0

ScorchedSlab_OnTransition: @ 0x0821BBDC
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	end
