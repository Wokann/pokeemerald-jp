@ MossdeepCity_GameCorner_1F scripts (JP map g14 m11 @ 0x0820E01E)

MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_MapScriptTable_0020E038
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_MapScriptTable_0020E02E
	map_script MAP_SCRIPT_ON_LOAD, 0x082468BC
	.byte 0

MossdeepCity_GameCorner_1F_MapScriptTable_0020E02E::
	map_script_2 0x4087, 0x8, 0x082468AC
	.2byte 0

MossdeepCity_GameCorner_1F_MapScriptTable_0020E038::
	map_script_2 0x4087, 0x8, 0x0824699B
	.2byte 0

MossdeepCity_GameCorner_1F_EventScript_0020E042::
	lock
	faceplayer
	goto 0x08247913

	.incbin "baserom_jp.gba", 0x20e049, 0x2
MossdeepCity_GameCorner_1F_EventScript_0020E04B::
	lock
	faceplayer
	goto 0x08247970

	.incbin "baserom_jp.gba", 0x20e052, 0x2
MossdeepCity_GameCorner_1F_EventScript_0020E054::
	loadword 0x0, 0x0820E0BA
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x20e05d, 0x1c6
