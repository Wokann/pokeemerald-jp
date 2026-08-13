@ Route134 scripts (JP map g0 m49 @ 0x081EF674)

Route134_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route134_EventScript_001EF67A
	.byte 0

Route134_EventScript_001EF67A::
	setdivewarp 0x1845, 0xFF, 0x8, 0x6
	end

	.incbin "baserom_jp.gba", 0x1ef683, 0xd1
