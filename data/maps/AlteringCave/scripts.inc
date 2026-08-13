@ AlteringCave scripts (JP map g24 m106 @ 0x0821D19C)

AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_EventScript_0021D1A2
	.byte 0

AlteringCave_EventScript_0021D1A2::
	setflag 0x8DD
	end

	.incbin "baserom_jp.gba", 0x21d1a6, 0x1cc
