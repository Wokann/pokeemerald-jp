@ AbandonedShip_Corridors_B1F scripts (JP map g24 m57 @ 0x0821ABF0)

AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_EventScript_0021ABFB
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_EventScript_0021AC04
	.byte 0

AbandonedShip_Corridors_B1F_EventScript_0021ABFB::
	setdivewarp 0x183C, 0xFF, 0x5, 0x4
	end

AbandonedShip_Corridors_B1F_EventScript_0021AC04::
	checkflag 0xEF
	call_if 0x0, AbandonedShip_Corridors_B1F_EventScript_0021AC17
	checkflag 0xEF
	call_if 0x1, AbandonedShip_Corridors_B1F_EventScript_0021AC21
	end

AbandonedShip_Corridors_B1F_EventScript_0021AC17::
	setmetatile 0xB, 0x4, 0x233, 0x1
	return

AbandonedShip_Corridors_B1F_EventScript_0021AC21::
	setmetatile 0xB, 0x4, 0x22B, 0x1
	return

AbandonedShip_Corridors_B1F_EventScript_0021AC2B::
	loadword 0x0, 0x0821AD11
	callstd 0x2
	end

AbandonedShip_Corridors_B1F_EventScript_0021AC34::
	lockall
	checkflag 0xEF
	goto_if 0x1, AbandonedShip_Corridors_B1F_EventScript_0021AC75
	checkitem 0x11D, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, AbandonedShip_Corridors_B1F_EventScript_0021AC6B
	loadword 0x0, 0x0821AD3C
	callstd 0x4
	playse 0x15
	removeitem 0x11D, 0x1
	setflag 0xEF
	call AbandonedShip_Corridors_B1F_EventScript_0021AC21
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_0021AC6B::
	loadword 0x0, 0x0821AD1E
	callstd 0x4
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_0021AC75::
	loadword 0x0, 0x0821AD6C
	callstd 0x4
	releaseall
	end
