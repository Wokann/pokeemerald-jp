@ Route110_TrickHousePuzzle1 scripts (JP map g29 m3 @ 0x0823DED5)

Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_EventScript_0023DEDB
	.byte 0

Route110_TrickHousePuzzle1_EventScript_0023DEDB::
	compare_var_to_value 0x40AB, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle1_EventScript_0023DEE7
	end

Route110_TrickHousePuzzle1_EventScript_0023DEE7::
	setmetatile 0xD, 0x1, 0x20B, 0x0
	end

Route110_TrickHousePuzzle1_EventScript_0023DEF1::
	lockall
	compare_var_to_value 0x40AB, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle1_EventScript_0023DF03
	goto 0x0823D1AC
	end

Route110_TrickHousePuzzle1_EventScript_0023DF03::
	setvar 0x40AB, 0x1
	goto 0x0823D1B6
	end

	.incbin "baserom_jp.gba", 0x23df0e, 0x141
