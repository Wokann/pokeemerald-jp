@ Route110_TrickHousePuzzle6 scripts (JP map g29 m8 @ 0x0823FD00)

Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_EventScript_0023FD0B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_MapScriptTable_0023FD0F
	.byte 0

Route110_TrickHousePuzzle6_EventScript_0023FD0B::
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_MapScriptTable_0023FD0F::
	map_script_2 0x4000, 0x4000, Route110_TrickHousePuzzle6_EventScript_0023FD19
	.2byte 0

Route110_TrickHousePuzzle6_EventScript_0023FD19::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_0023FD1D::
	lockall
	compare_var_to_value 0x40B0, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle6_EventScript_0023FD2F
	goto 0x0823D1AC
	end

Route110_TrickHousePuzzle6_EventScript_0023FD2F::
	setvar 0x40B0, 0x1
	goto 0x0823D1B6
	end
