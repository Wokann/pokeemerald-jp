@ Underwater_Route134 scripts (JP map g24 m69 @ 0x0821B9FA)

Underwater_Route134_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route134_OnResume
	.byte 0

Underwater_Route134_OnResume::
	setdivewarp MAP_ROUTE134, 0x3C, 0x1F
	end
