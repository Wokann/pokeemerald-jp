@ Route126 scripts (JP map g0 m41 @ 0x081EEAFA)

Route126_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route126_EventScript_001EEB00
	.byte 0

Route126_EventScript_001EEB00::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	end

	.incbin "baserom_jp.gba", 0x1eeb0a, 0x103
