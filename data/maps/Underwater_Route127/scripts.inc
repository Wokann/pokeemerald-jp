@ Underwater_Route127 scripts (JP map g0 m52 @ 0x081EF754)

Underwater_Route127_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route127_EventScript_001EF75A
	.byte 0

Underwater_Route127_EventScript_001EF75A::
	call 0x08244C4D
	end

	.incbin "baserom_jp.gba", 0x1ef760, 0x1
