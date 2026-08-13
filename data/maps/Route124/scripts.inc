@ Route124 scripts (JP map g0 m39 @ 0x081EE79F)

Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_EventScript_001EE7A5
	.byte 0

Route124_EventScript_001EE7A5::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	end

Route124_EventScript_001EE7AF::
	loadword 0x0, 0x081EE96C
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1ee7b8, 0x1c4
