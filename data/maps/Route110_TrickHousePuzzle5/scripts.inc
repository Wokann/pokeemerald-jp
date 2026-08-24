@ Route110_TrickHousePuzzle5 scripts (JP map g29 m7 @ 0x0823ECE1)

Route110_TrickHousePuzzle5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle5_EventScript_0023ECE7
	.byte 0

Route110_TrickHousePuzzle5_EventScript_0023ECE7::
	setvar 0x4001, 0x0
	setvar 0x4002, 0x0
	setvar 0x4003, 0x0
	setvar 0x4004, 0x0
	setvar 0x4005, 0x0
	setvar 0x4008, 0x0
	end

Route110_TrickHousePuzzle5_EventScript_0023ED06::
	lockall
	compare_var_to_value 0x40AF, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023ED18
	goto 0x0823D1AC
	end

Route110_TrickHousePuzzle5_EventScript_0023ED18::
	setvar 0x40AF, 0x1
	goto 0x0823D1B6
	end

Route110_TrickHousePuzzle5_EventScript_0023ED23::
	lockall
	applymovement 0x1, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x4001, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F39B
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023EEDC
	end

Route110_TrickHousePuzzle5_EventScript_0023ED44::
	lockall
	applymovement 0x2, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x4002, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F39B
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023EF5B
	end

Route110_TrickHousePuzzle5_EventScript_0023ED65::
	lockall
	applymovement 0x3, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x4003, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F39B
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023EFE5
	end

Route110_TrickHousePuzzle5_EventScript_0023ED86::
	lockall
	applymovement 0x4, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x4004, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F39B
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023F064
	end

Route110_TrickHousePuzzle5_EventScript_0023EDA7::
	lockall
	applymovement 0x5, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x4005, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F39B
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023F0E3
	end

Route110_TrickHousePuzzle5_EventScript_0023EDC8::
	lockall
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023EEDC
	end

Route110_TrickHousePuzzle5_EventScript_0023EDD4::
	lockall
	setvar 0x4009, 0x1
	goto Route110_TrickHousePuzzle5_EventScript_0023EEDC
	end

Route110_TrickHousePuzzle5_EventScript_0023EDE0::
	lockall
	setvar 0x4009, 0x2
	goto Route110_TrickHousePuzzle5_EventScript_0023EEDC
	end

Route110_TrickHousePuzzle5_EventScript_0023EDEC::
	lockall
	setvar 0x4009, 0x3
	goto Route110_TrickHousePuzzle5_EventScript_0023EEDC
	end

Route110_TrickHousePuzzle5_EventScript_0023EDF8::
	lockall
	setvar 0x4009, 0x4
	goto Route110_TrickHousePuzzle5_EventScript_0023EEDC
	end

Route110_TrickHousePuzzle5_EventScript_0023EE04::
	lockall
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023EF5B
	end

Route110_TrickHousePuzzle5_EventScript_0023EE10::
	lockall
	setvar 0x4009, 0x1
	goto Route110_TrickHousePuzzle5_EventScript_0023EF5B
	end

Route110_TrickHousePuzzle5_EventScript_0023EE1C::
	lockall
	setvar 0x4009, 0x2
	goto Route110_TrickHousePuzzle5_EventScript_0023EF5B
	end

Route110_TrickHousePuzzle5_EventScript_0023EE28::
	lockall
	setvar 0x4009, 0x3
	goto Route110_TrickHousePuzzle5_EventScript_0023EF5B
	end

Route110_TrickHousePuzzle5_EventScript_0023EE34::
	lockall
	setvar 0x4009, 0x4
	goto Route110_TrickHousePuzzle5_EventScript_0023EF5B
	end

Route110_TrickHousePuzzle5_EventScript_0023EE40::
	lockall
	setvar 0x4009, 0x5
	goto Route110_TrickHousePuzzle5_EventScript_0023EF5B
	end

Route110_TrickHousePuzzle5_EventScript_0023EE4C::
	lockall
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023EFE5
	end

Route110_TrickHousePuzzle5_EventScript_0023EE58::
	lockall
	setvar 0x4009, 0x1
	goto Route110_TrickHousePuzzle5_EventScript_0023EFE5
	end

Route110_TrickHousePuzzle5_EventScript_0023EE64::
	lockall
	setvar 0x4009, 0x2
	goto Route110_TrickHousePuzzle5_EventScript_0023EFE5
	end

Route110_TrickHousePuzzle5_EventScript_0023EE70::
	lockall
	setvar 0x4009, 0x3
	goto Route110_TrickHousePuzzle5_EventScript_0023EFE5
	end

Route110_TrickHousePuzzle5_EventScript_0023EE7C::
	lockall
	setvar 0x4009, 0x4
	goto Route110_TrickHousePuzzle5_EventScript_0023EFE5
	end

Route110_TrickHousePuzzle5_EventScript_0023EE88::
	lockall
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023F064
	end

Route110_TrickHousePuzzle5_EventScript_0023EE94::
	lockall
	setvar 0x4009, 0x1
	goto Route110_TrickHousePuzzle5_EventScript_0023F064
	end

Route110_TrickHousePuzzle5_EventScript_0023EEA0::
	lockall
	setvar 0x4009, 0x2
	goto Route110_TrickHousePuzzle5_EventScript_0023F064
	end

Route110_TrickHousePuzzle5_EventScript_0023EEAC::
	lockall
	setvar 0x4009, 0x3
	goto Route110_TrickHousePuzzle5_EventScript_0023F064
	end

Route110_TrickHousePuzzle5_EventScript_0023EEB8::
	lockall
	setvar 0x4009, 0x4
	goto Route110_TrickHousePuzzle5_EventScript_0023F064
	end

	.incbin "baserom_jp.gba", 0x23eec4, 0xc
Route110_TrickHousePuzzle5_EventScript_0023EED0::
	lockall
	setvar 0x4009, 0x0
	goto Route110_TrickHousePuzzle5_EventScript_0023F0E3
	end

Route110_TrickHousePuzzle5_EventScript_0023EEDC::
	setvar 0x4001, 0x1
	setvar 0x4008, 0x1
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x4009, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F3A5
	compare_var_to_value 0x4009, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F3DD
	compare_var_to_value 0x4009, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F415
	compare_var_to_value 0x4009, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F44D
	loadword 0x0, 0x0823F894
	callstd 0x4
	random 0x3
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F136
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F159
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F17C
	end

Route110_TrickHousePuzzle5_EventScript_0023EF5B::
	setvar 0x4002, 0x1
	setvar 0x4008, 0x2
	playse 0x15
	applymovement 0x2, 0x0824361B
	waitmovement 0x0
	applymovement 0x2, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x4009, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F4BD
	compare_var_to_value 0x4009, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F4F5
	compare_var_to_value 0x4009, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F52D
	compare_var_to_value 0x4009, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F565
	compare_var_to_value 0x4009, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F59D
	loadword 0x0, 0x0823F9CD
	callstd 0x4
	random 0x3
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F19F
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F1C2
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F1E5
	end

Route110_TrickHousePuzzle5_EventScript_0023EFE5::
	setvar 0x4003, 0x1
	setvar 0x4008, 0x3
	playse 0x15
	applymovement 0x3, 0x0824361B
	waitmovement 0x0
	applymovement 0x3, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x4009, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F3A5
	compare_var_to_value 0x4009, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F3DD
	compare_var_to_value 0x4009, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F415
	compare_var_to_value 0x4009, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F44D
	loadword 0x0, 0x0823FA97
	callstd 0x4
	random 0x3
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F208
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F22B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F24E
	end

Route110_TrickHousePuzzle5_EventScript_0023F064::
	setvar 0x4004, 0x1
	setvar 0x4008, 0x4
	playse 0x15
	applymovement 0x4, 0x0824361B
	waitmovement 0x0
	applymovement 0x4, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x4009, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F3A5
	compare_var_to_value 0x4009, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F3DD
	compare_var_to_value 0x4009, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F415
	compare_var_to_value 0x4009, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F44D
	loadword 0x0, 0x0823FB6C
	callstd 0x4
	random 0x3
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F271
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F294
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F2B7
	end

Route110_TrickHousePuzzle5_EventScript_0023F0E3::
	setvar 0x4005, 0x1
	setvar 0x4008, 0x5
	playse 0x15
	applymovement 0x5, 0x0824361B
	waitmovement 0x0
	applymovement 0x5, 0x0824361D
	waitmovement 0x0
	loadword 0x0, 0x0823FC3B
	callstd 0x4
	random 0x3
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F2DA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F2FD
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F320
	end

Route110_TrickHousePuzzle5_EventScript_0023F136::
	loadword 0x0, 0x0823F8E8
	callstd 0x4
	multichoice 0x0, 0x0, 0x19, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F159::
	loadword 0x0, 0x0823F919
	callstd 0x4
	multichoice 0x0, 0x0, 0x1A, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F17C::
	loadword 0x0, 0x0823F94A
	callstd 0x4
	multichoice 0x0, 0x0, 0x1B, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F19F::
	loadword 0x0, 0x0823F9FC
	callstd 0x4
	multichoice 0x0, 0x0, 0x1C, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F1C2::
	loadword 0x0, 0x0823FA30
	callstd 0x4
	multichoice 0x0, 0x0, 0x1D, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F1E5::
	loadword 0x0, 0x0823FA61
	callstd 0x4
	multichoice 0x0, 0x0, 0x1E, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F208::
	loadword 0x0, 0x0823FAC1
	callstd 0x4
	multichoice 0x0, 0x0, 0x1F, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F22B::
	loadword 0x0, 0x0823FAFD
	callstd 0x4
	multichoice 0x0, 0x0, 0x20, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F24E::
	loadword 0x0, 0x0823FB31
	callstd 0x4
	multichoice 0x0, 0x0, 0x21, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F271::
	loadword 0x0, 0x0823FB9A
	callstd 0x4
	multichoice 0x0, 0x0, 0x22, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F294::
	loadword 0x0, 0x0823FBCB
	callstd 0x4
	multichoice 0x0, 0x0, 0x23, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F2B7::
	loadword 0x0, 0x0823FC00
	callstd 0x4
	multichoice 0x0, 0x0, 0x24, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F2DA::
	loadword 0x0, 0x0823FC68
	callstd 0x4
	multichoice 0x0, 0x0, 0x25, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F2FD::
	loadword 0x0, 0x0823FC9B
	callstd 0x4
	multichoice 0x0, 0x0, 0x26, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F320::
	loadword 0x0, 0x0823FCCB
	callstd 0x4
	multichoice 0x0, 0x0, 0x27, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F391
	goto Route110_TrickHousePuzzle5_EventScript_0023F343
	end

Route110_TrickHousePuzzle5_EventScript_0023F343::
	waitse
	playse 0x20
	loadword 0x0, 0x0823F993
	callstd 0x4
	applymovement 0x1, 0x0823F823
	applymovement 0x2, 0x0823F823
	applymovement 0x3, 0x0823F823
	applymovement 0x4, 0x0823F823
	applymovement 0x5, 0x0823F823
	loadword 0x0, 0x0823F9A5
	callstd 0x4
	waitmovement 0x0
	loadword 0x0, 0x0823F9B9
	callstd 0x4
	closemessage
	warp 0x1D07, 0xFF, 0x0, 0x15
	waitstate
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_0023F391::
	waitse
	playse 0x1F
	goto Route110_TrickHousePuzzle5_EventScript_0023F39B
	end

Route110_TrickHousePuzzle5_EventScript_0023F39B::
	loadword 0x0, 0x0823F97A
	callstd 0x4
	releaseall
	end

Route110_TrickHousePuzzle5_EventScript_0023F3A5::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F5D5
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F5E0
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F5EB
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F5F6
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F601
	return

Route110_TrickHousePuzzle5_EventScript_0023F3DD::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F60C
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F617
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F622
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F62D
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F638
	return

Route110_TrickHousePuzzle5_EventScript_0023F415::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F643
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F64E
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F659
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F664
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F66F
	return

Route110_TrickHousePuzzle5_EventScript_0023F44D::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F67A
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F685
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F690
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F69B
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F6A6
	return

	.incbin "baserom_jp.gba", 0x23f485, 0x38
Route110_TrickHousePuzzle5_EventScript_0023F4BD::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F6E8
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F6F3
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F6FE
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F709
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F714
	return

Route110_TrickHousePuzzle5_EventScript_0023F4F5::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F71F
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F72A
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F735
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F740
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F74B
	return

Route110_TrickHousePuzzle5_EventScript_0023F52D::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F756
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F761
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F76C
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F777
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F782
	return

Route110_TrickHousePuzzle5_EventScript_0023F565::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F78D
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F798
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7A3
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7AE
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7B9
	return

Route110_TrickHousePuzzle5_EventScript_0023F59D::
	compare_var_to_value 0x4008, 0x1
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7C4
	compare_var_to_value 0x4008, 0x2
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7CF
	compare_var_to_value 0x4008, 0x3
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7DA
	compare_var_to_value 0x4008, 0x4
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7E5
	compare_var_to_value 0x4008, 0x5
	call_if 0x1, Route110_TrickHousePuzzle5_EventScript_0023F7F0
	return

Route110_TrickHousePuzzle5_EventScript_0023F5D5::
	applymovement 0x1, 0x0823F7FB
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F5E0::
	applymovement 0x2, 0x0823F7FB
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F5EB::
	applymovement 0x3, 0x0823F7FB
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F5F6::
	applymovement 0x4, 0x0823F7FB
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F601::
	applymovement 0x5, 0x0823F7FB
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F60C::
	applymovement 0x1, 0x0823F7FD
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F617::
	applymovement 0x2, 0x0823F7FD
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F622::
	applymovement 0x3, 0x0823F7FD
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F62D::
	applymovement 0x4, 0x0823F7FD
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F638::
	applymovement 0x5, 0x0823F7FD
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F643::
	applymovement 0x1, 0x0823F800
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F64E::
	applymovement 0x2, 0x0823F800
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F659::
	applymovement 0x3, 0x0823F800
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F664::
	applymovement 0x4, 0x0823F800
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F66F::
	applymovement 0x5, 0x0823F800
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F67A::
	applymovement 0x1, 0x0823F804
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F685::
	applymovement 0x2, 0x0823F804
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F690::
	applymovement 0x3, 0x0823F804
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F69B::
	applymovement 0x4, 0x0823F804
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F6A6::
	applymovement 0x5, 0x0823F804
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x23f6b1, 0x37
Route110_TrickHousePuzzle5_EventScript_0023F6E8::
	applymovement 0x1, 0x0823F80F
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F6F3::
	applymovement 0x2, 0x0823F80F
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F6FE::
	applymovement 0x3, 0x0823F80F
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F709::
	applymovement 0x4, 0x0823F80F
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F714::
	applymovement 0x5, 0x0823F80F
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F71F::
	applymovement 0x1, 0x0823F811
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F72A::
	applymovement 0x2, 0x0823F811
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F735::
	applymovement 0x3, 0x0823F811
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F740::
	applymovement 0x4, 0x0823F811
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F74B::
	applymovement 0x5, 0x0823F811
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F756::
	applymovement 0x1, 0x0823F814
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F761::
	applymovement 0x2, 0x0823F814
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F76C::
	applymovement 0x3, 0x0823F814
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F777::
	applymovement 0x4, 0x0823F814
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F782::
	applymovement 0x5, 0x0823F814
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F78D::
	applymovement 0x1, 0x0823F818
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F798::
	applymovement 0x2, 0x0823F818
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7A3::
	applymovement 0x3, 0x0823F818
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7AE::
	applymovement 0x4, 0x0823F818
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7B9::
	applymovement 0x5, 0x0823F818
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7C4::
	applymovement 0x1, 0x0823F81D
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7CF::
	applymovement 0x2, 0x0823F81D
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7DA::
	applymovement 0x3, 0x0823F81D
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7E5::
	applymovement 0x4, 0x0823F81D
	waitmovement 0x0
	return

Route110_TrickHousePuzzle5_EventScript_0023F7F0::
	applymovement 0x5, 0x0823F81D
	waitmovement 0x0
	return
