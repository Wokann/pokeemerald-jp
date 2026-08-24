@ VictoryRoad_1F scripts (JP map g24 m43 @ 0x0821949C)

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_EventScript_002194A2
	.byte 0

VictoryRoad_1F_EventScript_002194A2::
	compare_var_to_value 0x40C3, 0x1
	call_if 0x1, VictoryRoad_1F_EventScript_002194B9
	compare_var_to_value 0x40C3, 0x2
	call_if 0x1, VictoryRoad_1F_EventScript_002194C5
	end

VictoryRoad_1F_EventScript_002194B9::
	setobjectxyperm 0x4, 0x2, 0x18
	setobjectmovementtype 0x4, 0x8
	return

VictoryRoad_1F_EventScript_002194C5::
	setobjectxyperm 0x4, 0x3, 0x18
	setobjectmovementtype 0x4, 0x8
	return

VictoryRoad_1F_EventScript_002194D1::
	lockall
	setvar 0x8008, 0x1
	addobject 0x4
	applymovement 0x4, 0x08219537
	waitmovement 0x0
	goto 0x08219503
	end

VictoryRoad_1F_EventScript_002194EA::
	lockall
	setvar 0x8008, 0x2
	addobject 0x4
	applymovement 0x4, 0x08219543
	waitmovement 0x0
	goto 0x08219503
	end

	.incbin "baserom_jp.gba", 0x219503, 0x4b
VictoryRoad_1F_EventScript_0021954E::
	loadword 0x0, 0x082196CA
	callstd 0x2
	end
