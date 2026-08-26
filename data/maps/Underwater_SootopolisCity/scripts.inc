@ Underwater_SootopolisCity scripts (JP map g24 m5 @ 0x08213DD0)

Underwater_SootopolisCity_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_SootopolisCity_OnResume
	.byte 0

Underwater_SootopolisCity_OnResume:: @ 0x08213DD6
	setdivewarp MAP_SOOTOPOLIS_CITY, 29, 53
	end
