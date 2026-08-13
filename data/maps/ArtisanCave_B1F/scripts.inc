@ ArtisanCave_B1F scripts (JP map g24 m99 @ 0x0821CFD2)

ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_EventScript_0021CFD8
	.byte 0

ArtisanCave_B1F_EventScript_0021CFD8::
	setflag 0x8DF
	end

	.incbin "baserom_jp.gba", 0x21cfdc, 0x1
