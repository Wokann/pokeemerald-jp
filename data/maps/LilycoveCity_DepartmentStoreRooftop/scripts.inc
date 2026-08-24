@ LilycoveCity_DepartmentStoreRooftop scripts (JP map g13 m21 @ 0x0820AE53)

LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE59
	.byte 0

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE59::
	getpricereduction 0x3
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE73
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE77
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE73::
	clearflag 0x3C2
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE77::
	setflag 0x3C2
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE7B::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemartdecoration 0x0820AE94
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20ae92, 0x22
LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEB4::
	lock
	faceplayer
	getpricereduction 0x3
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AECE
	loadword 0x0, 0x0820B0AF
	callstd 0x4
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AECE::
	loadword 0x0, 0x0820B0EA
	callstd 0x4
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AED8::
	loadword 0x0, 0x0820B120
	callstd 0x2
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEE1::
	lockall
	message 0x0820B12E
	waitmessage
	showmoneybox 0x0, 0x0, 0x0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEF2
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEF2::
	multichoice 0x10, 0x0, 0x2A, 0x0
	copyvar 0x4001, 0x800D
	copyvar 0x8000, 0x4001
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF30
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF3B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF46
	loadword 0x0, 0x0820B180
	callstd 0x4
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020B0AA
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF30::
	setvar 0x4000, 0x1A
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF7B
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF3B::
	setvar 0x4000, 0x1B
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF7B
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF46::
	setvar 0x4000, 0x1C
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF7B
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF51::
	checkmoney 0xC8, 0x0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF58::
	checkmoney 0x12C, 0x0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF5F::
	checkmoney 0x15E, 0x0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF66::
	takemoney 0xC8, 0x0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF6D::
	takemoney 0x12C, 0x0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF74::
	takemoney 0x15E, 0x0
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF7B::
	compare_var_to_value 0x4001, 0x0
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF51
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF58
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF5F
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020B08E
	checkitemspace 0x4000, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020B09C
	compare_var_to_value 0x4001, 0x0
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF66
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF6D
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AF74
	updatemoneybox 0x0
	bufferitemname 0x0, 0x4000
	playse 0x6A
	loadword 0x0, 0x0820B14A
	callstd 0x4
	additem 0x4000, 0x1
	bufferitemname 0x1, 0x4000
	bufferstdstring 0x2, 0xE
	loadword 0x0, 0x08243953
	callstd 0x4
	random 0x40
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, LilycoveCity_DepartmentStoreRooftop_EventScript_0020B082
	checkitemspace 0x4000, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020B09C
	playse 0x6A
	loadword 0x0, 0x0820B159
	callstd 0x4
	additem 0x4000, 0x1
	bufferitemname 0x1, 0x4000
	bufferstdstring 0x2, 0xE
	loadword 0x0, 0x08243953
	callstd 0x4
	random 0x40
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, LilycoveCity_DepartmentStoreRooftop_EventScript_0020B082
	checkitemspace 0x4000, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_DepartmentStoreRooftop_EventScript_0020B09C
	playse 0x6A
	loadword 0x0, 0x0820B159
	callstd 0x4
	additem 0x4000, 0x1
	bufferitemname 0x1, 0x4000
	bufferstdstring 0x2, 0xE
	loadword 0x0, 0x08243953
	callstd 0x4
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020B082
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020B082::
	message 0x0820B12E
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEF2
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020B08E::
	loadword 0x0, 0x0820B175
	callstd 0x4
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020B0AA
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020B09C::
	loadword 0x0, 0x08243947
	callstd 0x4
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_0020B0AA
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_0020B0AA::
	hidemoneybox
	releaseall
	end
