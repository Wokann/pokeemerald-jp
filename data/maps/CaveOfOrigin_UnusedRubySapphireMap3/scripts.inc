@ CaveOfOrigin_UnusedRubySapphireMap3 scripts (JP map g24 m41 @ 0x082190EE)

CaveOfOrigin_UnusedRubySapphireMap3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_UnusedRubySapphireMap3_EventScript_002190F4
	.byte 0

CaveOfOrigin_UnusedRubySapphireMap3_EventScript_002190F4::
	checkflag 0x71
	call_if 0x1, 0x08243344
	end

	.incbin "baserom_jp.gba", 0x2190fe, 0x39e
