@ CaveOfOrigin_UnusedRubySapphireMap2 scripts (JP map g24 m40 @ 0x082190DE)

CaveOfOrigin_UnusedRubySapphireMap2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_UnusedRubySapphireMap2_EventScript_002190E4
	.byte 0

CaveOfOrigin_UnusedRubySapphireMap2_EventScript_002190E4::
	checkflag 0x71
	call_if 0x1, 0x08243344
	end

