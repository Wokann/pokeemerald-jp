@ CaveOfOrigin_1F scripts (JP map g24 m38 @ 0x082190BE)

CaveOfOrigin_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_1F_EventScript_002190C4
	.byte 0

CaveOfOrigin_1F_EventScript_002190C4::
	checkflag 0x71
	call_if 0x1, 0x08243344
	end

