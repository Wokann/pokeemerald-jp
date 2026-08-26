@ CaveOfOrigin_Entrance scripts (JP map g24 m37 @ 0x082190AF)

CaveOfOrigin_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_Entrance_OnResume
	.byte 0

CaveOfOrigin_Entrance_OnResume:
	setescapewarp MAP_SOOTOPOLIS_CITY, 31, 17
	end
