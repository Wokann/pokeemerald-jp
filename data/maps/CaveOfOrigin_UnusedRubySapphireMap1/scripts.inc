@ CaveOfOrigin_UnusedRubySapphireMap1 scripts (JP map g24 m39 @ 0x082190CE)

CaveOfOrigin_UnusedRubySapphireMap1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_UnusedRubySapphireMap1_EventScript_002190D4
	.byte 0

CaveOfOrigin_UnusedRubySapphireMap1_EventScript_002190D4::
	checkflag 0x71
	call_if 0x1, 0x08243344
	end

