@ SlateportCity_Harbor scripts (JP map g9 m9 @ 0x081FDC6E)

SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_EventScript_001FDC74
	.byte 0

SlateportCity_Harbor_EventScript_001FDC74::
	setescapewarp 0x1, 0xFF, 0x1C, 0xD
	setvar 0x4001, 0x0
	compare_var_to_value 0x40A0, 0x1
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDC9A
	checkflag 0x864
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDC96
	end

SlateportCity_Harbor_EventScript_001FDC96::
	clearflag 0x35C
	return

SlateportCity_Harbor_EventScript_001FDC9A::
	savebgm 0x1A3
	setobjectxyperm 0x4, 0xC, 0xD
	setobjectmovementtype 0x4, 0x9
	setflag 0x389
	return

SlateportCity_Harbor_EventScript_001FDCAC::
	lockall
	setvar 0x8008, 0x0
	goto SlateportCity_Harbor_EventScript_001FDCE6
	end

SlateportCity_Harbor_EventScript_001FDCB8::
	lockall
	setvar 0x8008, 0x1
	goto SlateportCity_Harbor_EventScript_001FDCE6
	end

SlateportCity_Harbor_EventScript_001FDCC4::
	lockall
	setvar 0x8008, 0x2
	goto SlateportCity_Harbor_EventScript_001FDCE6
	end

SlateportCity_Harbor_EventScript_001FDCD0::
	lockall
	setvar 0x8008, 0x3
	applymovement 0xFF, 0x081FDDE0
	waitmovement 0x0
	goto SlateportCity_Harbor_EventScript_001FDCE6
	end

SlateportCity_Harbor_EventScript_001FDCE6::
	applymovement 0x7, 0x0824362D
	waitmovement 0x0
	applymovement 0x6, 0x0824362D
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, 0x081FE364
	callstd 0x4
	closemessage
	applymovement 0x6, 0x081FDDB9
	applymovement 0x7, 0x081FDDB9
	applymovement 0x8, 0x081FDDC3
	waitmovement 0x0
	removeobject 0x6
	removeobject 0x7
	removeobject 0x8
	setvar 0x40A0, 0x2
	setflag 0x61
	setflag 0x313
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDD7A
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDD8F
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDDA4
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDDA4
	loadword 0x0, 0x081FE3D4
	callstd 0x4
	closemessage
	setflag 0x335
	setflag 0x336
	moveobjectoffscreen 0x4
	setobjectmovementtype 0x4, 0xA
	releaseall
	end

SlateportCity_Harbor_EventScript_001FDD7A::
	applymovement 0x4, 0x081FDDD1
	waitmovement 0x0
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

SlateportCity_Harbor_EventScript_001FDD8F::
	applymovement 0x4, 0x081FDDD7
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	return

SlateportCity_Harbor_EventScript_001FDDA4::
	applymovement 0x4, 0x081FDDDC
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1fddb9, 0x29
SlateportCity_Harbor_EventScript_001FDDE2::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDDF7
	loadword 0x0, 0x081FE111
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FDDF7::
	loadword 0x0, 0x081FE13F
	callstd 0x4
	message 0x081FE19E
	waitmessage
	goto SlateportCity_Harbor_EventScript_001FDE0B
	end

SlateportCity_Harbor_EventScript_001FDE0B::
	checkflag 0x1D0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDE41
	multichoicedefault 0x12, 0x8, 0x38, 0x2, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDE83
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDF1E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDF1E
	end

SlateportCity_Harbor_EventScript_001FDE41::
	multichoicedefault 0x11, 0x6, 0x34, 0x2, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDE83
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDEAB
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDF1E
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDF1E
	end

	.incbin "baserom_jp.gba", 0x1fde79, 0xa
SlateportCity_Harbor_EventScript_001FDE83::
	loadword 0x0, 0x081FE1DB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDECE
	setvar 0x40B4, 0x1
	call SlateportCity_Harbor_EventScript_001FDEDA
	warp 0x1929, 0xFF, 0x1, 0xA
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_001FDEAB::
	loadword 0x0, 0x081FE1E7
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDECE
	call SlateportCity_Harbor_EventScript_001FDEDA
	warp 0x1A04, 0xFF, 0x13, 0x43
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_001FDECE::
	message 0x081FE20A
	waitmessage
	goto SlateportCity_Harbor_EventScript_001FDE0B
	end

SlateportCity_Harbor_EventScript_001FDEDA::
	loadword 0x0, 0x081FE1F6
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243629
	waitmovement 0x0
	delay 0x1E
	hideobject_at 0x800F, 0x909
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDF33
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDF28
	delay 0x1E
	hideobject_at 0xFF, 0x0
	setvar 0x8004, 0x5
	call 0x08243265
	return

SlateportCity_Harbor_EventScript_001FDF1E::
	loadword 0x0, 0x081FE1CD
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FDF28::
	applymovement 0xFF, 0x081FDF3E
	waitmovement 0x0
	return

SlateportCity_Harbor_EventScript_001FDF33::
	applymovement 0xFF, 0x081FDF41
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1fdf3e, 0x5
SlateportCity_Harbor_EventScript_001FDF43::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x0, SlateportCity_Harbor_EventScript_001FDF7A
	setvar 0x8004, 0x0
	checkflag 0x1BE
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDF84
	checkflag 0x1BF
	call_if 0x1, SlateportCity_Harbor_EventScript_001FDF84
	compare_var_to_value 0x8004, 0x2
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDF7A
	loadword 0x0, 0x081FE249
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FDF7A::
	loadword 0x0, 0x081FE21A
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FDF84::
	addvar 0x8004, 0x1
	return

SlateportCity_Harbor_EventScript_001FDF8A::
	loadword 0x0, 0x081FE2D6
	callstd 0x2
	end

SlateportCity_Harbor_EventScript_001FDF93::
	lock
	faceplayer
	checkflag 0x86D
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDFF1
	checkflag 0x10F
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDFE7
	checkflag 0x70
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDFDA
	compare_var_to_value 0x40A0, 0x2
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FDFD0
	loadword 0x0, 0x081FE335
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_Harbor_EventScript_001FDFD0::
	loadword 0x0, 0x081FE3D4
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FDFDA::
	setflag 0x10F
	loadword 0x0, 0x081FE44D
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FDFE7::
	loadword 0x0, 0x081FE518
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FDFF1::
	compare_var_to_value 0x4001, 0x1
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE102
	checkitem 0x116, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE029
	checkflag 0x864
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE01F
	loadword 0x0, 0x081FE59B
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FE01F::
	loadword 0x0, 0x081FE5E2
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FE029::
	message 0x081FE638
	waitmessage
	goto SlateportCity_Harbor_EventScript_001FE035
	end

SlateportCity_Harbor_EventScript_001FE035::
	multichoice 0x0, 0x0, 0x2E, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE06C
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE0AC
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE0EC
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE0EC
	end

SlateportCity_Harbor_EventScript_001FE06C::
	loadword 0x0, 0x081FE6F9
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE0F6
	setorcopyvar 0x8000, 0xC0
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	removeitem 0x116, 0x1
	loadword 0x0, 0x081FE735
	callstd 0x4
	setflag 0x126
	goto SlateportCity_Harbor_EventScript_001FE102
	end

SlateportCity_Harbor_EventScript_001FE0AC::
	loadword 0x0, 0x081FE70E
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_Harbor_EventScript_001FE0F6
	setorcopyvar 0x8000, 0xC1
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	removeitem 0x116, 0x1
	loadword 0x0, 0x081FE735
	callstd 0x4
	setflag 0x126
	goto SlateportCity_Harbor_EventScript_001FE102
	end

SlateportCity_Harbor_EventScript_001FE0EC::
	loadword 0x0, 0x081FE6A7
	callstd 0x4
	release
	end

SlateportCity_Harbor_EventScript_001FE0F6::
	message 0x081FE724
	waitmessage
	goto SlateportCity_Harbor_EventScript_001FE035
	end

SlateportCity_Harbor_EventScript_001FE102::
	setvar 0x4001, 0x1
	loadword 0x0, 0x081FE750
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1fe111, 0x6f8
