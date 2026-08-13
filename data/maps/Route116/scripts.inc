@ Route116 scripts (JP map g0 m31 @ 0x081EBAB5)

Route116_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_EventScript_001EBAC5
	map_script MAP_SCRIPT_ON_LOAD, Route116_EventScript_001EBAF8
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_MapScriptTable_001EBB0F
	.byte 0

Route116_EventScript_001EBAC5::
	checkflag 0x8F
	call_if 0x1, Route116_EventScript_001EBAF0
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0x5
	call_if 0x1, 0x08244745
	compare_var_to_value 0x4037, 0x6
	call_if 0x1, 0x08244745
	end

Route116_EventScript_001EBAF0::
	setobjectxyperm 0x15, 0x26, 0xA
	return

Route116_EventScript_001EBAF8::
	compare_var_to_value 0x4037, 0x5
	call_if 0x1, 0x08244389
	compare_var_to_value 0x4037, 0x6
	call_if 0x1, 0x0824439C
	end

Route116_MapScriptTable_001EBB0F::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

Route116_EventScript_001EBB19::
	lock
	faceplayer
	checkflag 0x8F
	goto_if 0x1, Route116_EventScript_001EBB37
	checkflag 0x8E
	goto_if 0x1, Route116_EventScript_001EBB41
	loadword 0x0, 0x081EBFAA
	callstd 0x4
	release
	end

Route116_EventScript_001EBB37::
	loadword 0x0, 0x081EC06B
	callstd 0x4
	release
	end

Route116_EventScript_001EBB41::
	loadword 0x0, 0x081EBFBC
	callstd 0x4
	release
	end

Route116_EventScript_001EBB4B::
	lock
	faceplayer
	checkflag 0x11F
	goto_if 0x1, Route116_EventScript_001EBBD4
	loadword 0x0, 0x081EC094
	callstd 0x4
	goto Route116_EventScript_001EBB64
	end

Route116_EventScript_001EBB64::
	setflag 0x11F
	setorcopyvar 0x8000, 0x9
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route116_EventScript_001EBBE2
	loadword 0x0, 0x081EC1A8
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, Route116_EventScript_001EBBBE
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, Route116_EventScript_001EBBBE
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, Route116_EventScript_001EBBBE
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, Route116_EventScript_001EBBC9
	removeobject 0x800F
	clearflag 0x3B5
	setflag 0x100
	release
	end

Route116_EventScript_001EBBBE::
	applymovement 0x800F, 0x081EBBEC
	waitmovement 0x0
	return

Route116_EventScript_001EBBC9::
	applymovement 0x800F, 0x081EBBF5
	waitmovement 0x0
	return

Route116_EventScript_001EBBD4::
	loadword 0x0, 0x081EC206
	callstd 0x4
	goto Route116_EventScript_001EBB64
	end

Route116_EventScript_001EBBE2::
	loadword 0x0, 0x081EC1EC
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1ebbec, 0x14
Route116_EventScript_001EBC00::
	loadword 0x0, 0x081EC312
	callstd 0x3
	end

Route116_EventScript_001EBC09::
	loadword 0x0, 0x081EC32C
	callstd 0x3
	end

Route116_EventScript_001EBC12::
	loadword 0x0, 0x081EC35D
	callstd 0x3
	end

Route116_EventScript_001EBC1B::
	loadword 0x0, 0x081EC371
	callstd 0x3
	end

Route116_EventScript_001EBC24::
	loadword 0x0, 0x081EC3BD
	callstd 0x3
	end

Route116_EventScript_001EBC2D::
	lock
	faceplayer
	loadword 0x0, 0x081EBF46
	callstd 0x4
	setvar 0x406F, 0x2
	release
	end

Route116_EventScript_001EBC3E::
	lockall
	applymovement 0xB, 0x0824362B
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, 0x081EBF46
	callstd 0x4
	setvar 0x406F, 0x2
	releaseall
	end

Route116_EventScript_001EBC5F::
	lock
	faceplayer
	checkitem 0xCE, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBC9A
	specialvar 0x800D, FoundBlackGlasses
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBC8B
	loadword 0x0, 0x081EC24C
	callstd 0x4
	release
	end

Route116_EventScript_001EBC8B::
	loadword 0x0, 0x081EC2BC
	callstd 0x4
	closemessage
	goto Route116_EventScript_001EBCD3
	end

Route116_EventScript_001EBC9A::
	loadword 0x0, 0x081EC24C
	callstd 0x4
	loadword 0x0, 0x081EC26A
	callstd 0x4
	specialvar 0x800D, FoundBlackGlasses
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBCC4
	loadword 0x0, 0x081EC2E9
	callstd 0x4
	release
	end

Route116_EventScript_001EBCC4::
	loadword 0x0, 0x081EC27F
	callstd 0x4
	closemessage
	goto Route116_EventScript_001EBCD3
	end

Route116_EventScript_001EBCD3::
	delay 0x14
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, Route116_EventScript_001EBD07
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, Route116_EventScript_001EBD07
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, Route116_EventScript_001EBD07
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, Route116_EventScript_001EBD12
	removeobject 0x800F
	release
	end

Route116_EventScript_001EBD07::
	applymovement 0x800F, 0x081EBD1D
	waitmovement 0x0
	return

Route116_EventScript_001EBD12::
	applymovement 0x800F, 0x081EBD27
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1ebd1d, 0x706
