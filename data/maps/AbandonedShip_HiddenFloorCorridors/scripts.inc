@ AbandonedShip_HiddenFloorCorridors scripts (JP map g24 m65 @ 0x0821B340)

AbandonedShip_HiddenFloorCorridors_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorCorridors_EventScript_0021B34B
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorCorridors_EventScript_0021B354
	.byte 0

AbandonedShip_HiddenFloorCorridors_EventScript_0021B34B::
	setdivewarp 0x183C, 0xFF, 0x5, 0x4
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B354::
	checkflag 0xF0
	call_if 0x0, AbandonedShip_HiddenFloorCorridors_EventScript_0021B3C5
	checkflag 0xF1
	call_if 0x0, AbandonedShip_HiddenFloorCorridors_EventScript_0021B3CF
	checkflag 0xF2
	call_if 0x0, AbandonedShip_HiddenFloorCorridors_EventScript_0021B3D9
	checkflag 0xF3
	call_if 0x0, AbandonedShip_HiddenFloorCorridors_EventScript_0021B3E3
	checkflag 0xF0
	call_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B39D
	checkflag 0xF1
	call_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B3A7
	checkflag 0xF2
	call_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B3B1
	checkflag 0xF3
	call_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B3BB
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B39D::
	setmetatile 0x3, 0x8, 0x22B, 0x1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3A7::
	setmetatile 0x6, 0x8, 0x22B, 0x1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3B1::
	setmetatile 0x3, 0x3, 0x21A, 0x0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3BB::
	setmetatile 0x9, 0x3, 0x21A, 0x0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3C5::
	setmetatile 0x3, 0x8, 0x233, 0x1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3CF::
	setmetatile 0x6, 0x8, 0x233, 0x1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3D9::
	setmetatile 0x3, 0x3, 0x234, 0x0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3E3::
	setmetatile 0x9, 0x3, 0x234, 0x0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_0021B3ED::
	lockall
	checkflag 0xF0
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4F1
	checkitem 0x119, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4C9
	loadword 0x0, 0x0821B577
	callstd 0x4
	playse 0x15
	takeitem 0x119, 0x1
	setflag 0xF0
	call AbandonedShip_HiddenFloorCorridors_EventScript_0021B39D
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B424::
	lockall
	checkflag 0xF1
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4F1
	checkitem 0x11A, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4D3
	loadword 0x0, 0x0821B577
	callstd 0x4
	playse 0x15
	takeitem 0x11A, 0x1
	setflag 0xF1
	call AbandonedShip_HiddenFloorCorridors_EventScript_0021B3A7
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B45B::
	lockall
	checkflag 0xF2
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4F1
	checkitem 0x11B, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4DD
	loadword 0x0, 0x0821B577
	callstd 0x4
	playse 0x15
	takeitem 0x11B, 0x1
	setflag 0xF2
	call AbandonedShip_HiddenFloorCorridors_EventScript_0021B3B1
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B492::
	lockall
	checkflag 0xF3
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4F1
	checkitem 0x11C, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, AbandonedShip_HiddenFloorCorridors_EventScript_0021B4E7
	loadword 0x0, 0x0821B577
	callstd 0x4
	playse 0x15
	takeitem 0x11C, 0x1
	setflag 0xF3
	call AbandonedShip_HiddenFloorCorridors_EventScript_0021B3BB
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B4C9::
	loadword 0x0, 0x0821B4FB
	callstd 0x4
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B4D3::
	loadword 0x0, 0x0821B51A
	callstd 0x4
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B4DD::
	loadword 0x0, 0x0821B539
	callstd 0x4
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B4E7::
	loadword 0x0, 0x0821B558
	callstd 0x4
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_0021B4F1::
	loadword 0x0, 0x0821AD6C
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x21b4fb, 0xa8
