@ Route110_TrickHousePuzzle2 scripts (JP map g29 m4 @ 0x0823E04F)

Route110_TrickHousePuzzle2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_EventScript_0023E05A
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_EventScript_0023E087
	.byte 0

Route110_TrickHousePuzzle2_EventScript_0023E05A::
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, Route110_TrickHousePuzzle2_EventScript_0023E105
	compare_var_to_value 0x4002, 0x1
	call_if 0x1, Route110_TrickHousePuzzle2_EventScript_0023E118
	compare_var_to_value 0x4003, 0x1
	call_if 0x1, Route110_TrickHousePuzzle2_EventScript_0023E12B
	compare_var_to_value 0x4004, 0x1
	call_if 0x1, Route110_TrickHousePuzzle2_EventScript_0023E13E
	end

Route110_TrickHousePuzzle2_EventScript_0023E087::
	setvar 0x4001, 0x0
	setvar 0x4002, 0x0
	setvar 0x4003, 0x0
	setvar 0x4004, 0x0
	end

Route110_TrickHousePuzzle2_EventScript_0023E09C::
	lockall
	compare_var_to_value 0x40AC, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle2_EventScript_0023E0AE
	goto 0x0823D1AC
	end

Route110_TrickHousePuzzle2_EventScript_0023E0AE::
	setvar 0x40AC, 0x1
	goto 0x0823D1B6
	end

Route110_TrickHousePuzzle2_EventScript_0023E0B9::
	lockall
	setvar 0x4001, 0x1
	playse 0x15
	call Route110_TrickHousePuzzle2_EventScript_0023E105
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_0023E0CC::
	lockall
	setvar 0x4002, 0x1
	playse 0x15
	call Route110_TrickHousePuzzle2_EventScript_0023E118
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_0023E0DF::
	lockall
	setvar 0x4003, 0x1
	playse 0x15
	call Route110_TrickHousePuzzle2_EventScript_0023E12B
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_0023E0F2::
	lockall
	setvar 0x4004, 0x1
	playse 0x15
	call Route110_TrickHousePuzzle2_EventScript_0023E13E
	special DrawWholeMapView
	releaseall
	end

Route110_TrickHousePuzzle2_EventScript_0023E105::
	setmetatile 0xB, 0xC, 0x259, 0x0
	setmetatile 0x1, 0xD, 0x26A, 0x0
	return

Route110_TrickHousePuzzle2_EventScript_0023E118::
	setmetatile 0x0, 0x4, 0x259, 0x0
	setmetatile 0x5, 0x6, 0x26A, 0x0
	return

Route110_TrickHousePuzzle2_EventScript_0023E12B::
	setmetatile 0xE, 0x5, 0x259, 0x0
	setmetatile 0x7, 0xF, 0x26A, 0x0
	return

Route110_TrickHousePuzzle2_EventScript_0023E13E::
	setmetatile 0x7, 0xB, 0x259, 0x0
	setmetatile 0xE, 0xC, 0x26A, 0x0
	return
