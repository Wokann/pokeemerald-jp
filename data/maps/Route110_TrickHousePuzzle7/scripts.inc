@ Route110_TrickHousePuzzle7 scripts (JP map g29 m9 @ 0x0823FEBC)

Route110_TrickHousePuzzle7_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle7_EventScript_0023FED1
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle7_EventScript_0023FFC3
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle7_EventScript_0023FFDF
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHousePuzzle7_MapScriptTable_0023FFEB
	.byte 0

Route110_TrickHousePuzzle7_EventScript_0023FED1::
	call Route110_TrickHousePuzzle7_EventScript_0023FED7
	end

Route110_TrickHousePuzzle7_EventScript_0023FED7::
	checkflag 0xC2
	call_if 0x1, Route110_TrickHousePuzzle7_EventScript_0023FF05
	checkflag 0xC3
	call_if 0x1, Route110_TrickHousePuzzle7_EventScript_0023FF18
	checkflag 0xC4
	call_if 0x1, Route110_TrickHousePuzzle7_EventScript_0023FF2B
	checkflag 0xC5
	call_if 0x1, Route110_TrickHousePuzzle7_EventScript_0023FF3E
	checkflag 0xC6
	call_if 0x1, Route110_TrickHousePuzzle7_EventScript_0023FF51
	return

Route110_TrickHousePuzzle7_EventScript_0023FF05::
	setmetatile 0xD, 0x11, 0x262, 0x0
	setmetatile 0xC, 0x10, 0x23F, 0x1
	return

Route110_TrickHousePuzzle7_EventScript_0023FF18::
	setmetatile 0xC, 0xD, 0x262, 0x0
	setmetatile 0xC, 0xB, 0x23F, 0x1
	return

Route110_TrickHousePuzzle7_EventScript_0023FF2B::
	setmetatile 0x7, 0xC, 0x262, 0x0
	setmetatile 0x5, 0xA, 0x23F, 0x1
	return

Route110_TrickHousePuzzle7_EventScript_0023FF3E::
	setmetatile 0x6, 0x6, 0x27C, 0x0
	setmetatile 0x4, 0x4, 0x23F, 0x1
	return

Route110_TrickHousePuzzle7_EventScript_0023FF51::
	setmetatile 0x8, 0x4, 0x261, 0x0
	setmetatile 0x7, 0x5, 0x23F, 0x1
	return

	.incbin "baserom_jp.gba", 0x23ff64, 0x5f
Route110_TrickHousePuzzle7_EventScript_0023FFC3::
	compare_var_to_value 0x40B6, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle7_EventScript_0023FFDE
	clearflag 0xC2
	clearflag 0xC3
	clearflag 0xC4
	clearflag 0xC5
	clearflag 0xC6
	end

Route110_TrickHousePuzzle7_EventScript_0023FFDE::
	end

Route110_TrickHousePuzzle7_EventScript_0023FFDF::
	compare_var_to_value 0x40B6, 0x1
	call_if 0x1, Route110_TrickHousePuzzle7_EventScript_0023FED7
	end

Route110_TrickHousePuzzle7_MapScriptTable_0023FFEB::
	map_script_2 0x40B6, 0x1, Route110_TrickHousePuzzle7_EventScript_0023FFF5
	.2byte 0

Route110_TrickHousePuzzle7_EventScript_0023FFF5::
	setvar 0x40B6, 0x0
	end

Route110_TrickHousePuzzle7_EventScript_0023FFFB::
	lockall
	compare_var_to_value 0x40B1, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle7_EventScript_0024000D
	goto 0x0823D1AC
	end

Route110_TrickHousePuzzle7_EventScript_0024000D::
	setvar 0x40B1, 0x1
	goto 0x0823D1B6
	end
