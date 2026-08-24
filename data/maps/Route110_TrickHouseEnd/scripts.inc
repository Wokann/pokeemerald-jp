@ Route110_TrickHouseEnd scripts (JP map g29 m1 @ 0x0823D6C0)

Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_EventScript_0023D6D5
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_EventScript_0023D6E1
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_MapScriptTable_0023D706
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_MapScriptTable_0023D6EF
	.byte 0

Route110_TrickHouseEnd_EventScript_0023D6D5::
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023D71E
	end

Route110_TrickHouseEnd_EventScript_0023D6E1::
	setvar 0x4001, 0x0
	setvar 0x4002, 0x0
	special ResetTrickHouseEndRoomFlag
	end

Route110_TrickHouseEnd_MapScriptTable_0023D6EF::
	map_script_2 0x4002, 0x0, Route110_TrickHouseEnd_EventScript_0023D6F9
	.2byte 0

Route110_TrickHouseEnd_EventScript_0023D6F9::
	addobject 0x1
	showobject_at 0x1, 0x1D01
	turnobject 0x1, 0x4
	end

Route110_TrickHouseEnd_MapScriptTable_0023D706::
	map_script_2 0x4001, 0x0, Route110_TrickHouseEnd_EventScript_0023D710
	.2byte 0

Route110_TrickHouseEnd_EventScript_0023D710::
	setvar 0x4001, 0x1
	call Route110_TrickHouseEnd_EventScript_0023D71E
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_0023D71E::
	setmetatile 0xA, 0x1, 0x21B, 0x1
	return

Route110_TrickHouseEnd_EventScript_0023D728::
	lock
	faceplayer
	loadword 0x0, 0x0823DA9E
	callstd 0x4
	setvar 0x4002, 0x1
	copyvar 0x8000, 0x4044
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D795
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D7D1
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D80D
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D849
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D885
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D8C1
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D8FD
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D939
	end

Route110_TrickHouseEnd_EventScript_0023D795::
	loadword 0x0, 0x0823DABE
	callstd 0x4
	loadword 0x0, 0x0823DDE3
	callstd 0x4
	setvar 0x40C1, 0x0
	setorcopyvar 0x8000, 0x44
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA00
	loadword 0x0, 0x0823DE39
	callstd 0x4
	closemessage
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	release
	end

Route110_TrickHouseEnd_EventScript_0023D7D1::
	loadword 0x0, 0x0823DAF5
	callstd 0x4
	loadword 0x0, 0x0823DDE3
	callstd 0x4
	setvar 0x40C1, 0x0
	setorcopyvar 0x8000, 0xA
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA00
	loadword 0x0, 0x0823DE39
	callstd 0x4
	closemessage
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	release
	end

Route110_TrickHouseEnd_EventScript_0023D80D::
	loadword 0x0, 0x0823DB2B
	callstd 0x4
	loadword 0x0, 0x0823DDE3
	callstd 0x4
	setvar 0x40C1, 0x0
	setorcopyvar 0x8000, 0xCC
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA00
	loadword 0x0, 0x0823DE39
	callstd 0x4
	closemessage
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	release
	end

Route110_TrickHouseEnd_EventScript_0023D849::
	loadword 0x0, 0x0823DB5E
	callstd 0x4
	loadword 0x0, 0x0823DDE3
	callstd 0x4
	setvar 0x40C1, 0x0
	setorcopyvar 0x8000, 0xC2
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA00
	loadword 0x0, 0x0823DE39
	callstd 0x4
	closemessage
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	release
	end

Route110_TrickHouseEnd_EventScript_0023D885::
	loadword 0x0, 0x0823DB8D
	callstd 0x4
	loadword 0x0, 0x0823DDE3
	callstd 0x4
	setvar 0x40C1, 0x0
	setorcopyvar 0x8000, 0x12C
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA00
	loadword 0x0, 0x0823DE39
	callstd 0x4
	closemessage
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	release
	end

Route110_TrickHouseEnd_EventScript_0023D8C1::
	loadword 0x0, 0x0823DBC8
	callstd 0x4
	loadword 0x0, 0x0823DDE3
	callstd 0x4
	setvar 0x40C1, 0x0
	setorcopyvar 0x8000, 0xD0
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA00
	loadword 0x0, 0x0823DE39
	callstd 0x4
	closemessage
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	release
	end

Route110_TrickHouseEnd_EventScript_0023D8FD::
	loadword 0x0, 0x0823DBEF
	callstd 0x4
	loadword 0x0, 0x0823DDE3
	callstd 0x4
	setvar 0x40C1, 0x0
	setorcopyvar 0x8000, 0x47
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA00
	loadword 0x0, 0x0823DE39
	callstd 0x4
	closemessage
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	release
	end

Route110_TrickHouseEnd_EventScript_0023D939::
	loadword 0x0, 0x0823DC16
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA26
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA31
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA3C
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA47
	delay 0x1E
	loadword 0x0, 0x0823DC3B
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	delay 0x1E
	loadword 0x0, 0x0823DC85
	callstd 0x4
	setvar 0x40C1, 0x0
	call Route110_TrickHouseEnd_EventScript_0023D9B6
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route110_TrickHouseEnd_EventScript_0023DA13
	loadword 0x0, 0x0823DD87
	callstd 0x4
	call Route110_TrickHouseEnd_EventScript_0023D9E0
	special SetTrickHouseEndRoomFlag
	release
	end

Route110_TrickHouseEnd_EventScript_0023D9B6::
	multichoice 0x0, 0x0, 0x58, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHouseEnd_EventScript_0023D9D0
	goto Route110_TrickHouseEnd_EventScript_0023D9D8

Route110_TrickHouseEnd_EventScript_0023D9D0::
	setorcopyvar 0x8000, 0x1F
	callstd 0x7
	return

Route110_TrickHouseEnd_EventScript_0023D9D8::
	setorcopyvar 0x8000, 0x20
	callstd 0x7
	return

Route110_TrickHouseEnd_EventScript_0023D9E0::
	applymovement 0x1, 0x0823CC07
	waitmovement 0x0
	playse 0xB2
	applymovement 0x1, 0x0823CC10
	waitmovement 0x0
	removeobject 0x1
	addvar 0x4044, 0x1
	return

Route110_TrickHouseEnd_EventScript_0023DA00::
	call 0x082430EA
	loadword 0x0, 0x0823DDF6
	callstd 0x4
	setvar 0x40C1, 0x1
	return

Route110_TrickHouseEnd_EventScript_0023DA13::
	call 0x082430FD
	loadword 0x0, 0x0823DD3F
	callstd 0x4
	setvar 0x40C1, 0x1
	return

Route110_TrickHouseEnd_EventScript_0023DA26::
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	return

Route110_TrickHouseEnd_EventScript_0023DA31::
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	return

Route110_TrickHouseEnd_EventScript_0023DA3C::
	applymovement 0x1, 0x08243627
	waitmovement 0x0
	return

Route110_TrickHouseEnd_EventScript_0023DA47::
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	return

Route110_TrickHouseEnd_EventScript_0023DA52::
	lockall
	turnobject 0x1, 0x3
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	delay 0x14
	applymovement 0x1, 0x0823DA9C
	waitmovement 0x0
	playse 0xB2
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	loadword 0x0, 0x0823DEA4
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x0823DA9A
	waitmovement 0x0
	delay 0x4
	turnobject 0x1, 0x4
	releaseall
	end
