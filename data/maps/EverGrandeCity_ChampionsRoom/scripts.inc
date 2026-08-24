@ EverGrandeCity_ChampionsRoom scripts (JP map g16 m4 @ 0x082108D0)

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_EventScript_002108E0
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_MapScriptTable_002108E6
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_MapScriptTable_002108F5
	.byte 0

EverGrandeCity_ChampionsRoom_EventScript_002108E0::
	call 0x08242F63
	end

EverGrandeCity_ChampionsRoom_MapScriptTable_002108E6::
	map_script_2 0x4001, 0x0, EverGrandeCity_ChampionsRoom_EventScript_002108F0
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_002108F0::
	turnobject 0xFF, 0x2
	end

EverGrandeCity_ChampionsRoom_MapScriptTable_002108F5::
	map_script_2 0x4001, 0x0, EverGrandeCity_ChampionsRoom_EventScript_002108FF
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_002108FF::
	lockall
	applymovement 0xFF, 0x08243644
	waitmovement 0x0
	delay 0x28
	applymovement 0xFF, 0x08210923
	waitmovement 0x0
	setvar 0x4001, 0x1
	goto 0x08210926
