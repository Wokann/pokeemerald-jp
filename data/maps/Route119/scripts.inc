@ Route119 scripts (JP map g0 m34 @ 0x081ECCE5)

Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_EventScript_001ECCF0
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_EventScript_001ECD0E
	.byte 0

Route119_EventScript_001ECCF0::
	checkflag 0x8C1
	call_if 0x1, Route119_EventScript_001ECCFA
	end

Route119_EventScript_001ECCFA::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

Route119_EventScript_001ECD0E::
	call 0x08242F63
	call 0x08242F87
	compare_var_to_value 0x40B3, 0x1
	call_if 0x1, Route119_EventScript_001ECD27
	special SetRoute119Weather
	end

Route119_EventScript_001ECD27::
	setflag 0x37D
	clearflag 0x37C
	setvar 0x40B3, 0x2
	return

Route119_EventScript_001ECD33::
	setvar 0x4001, 0x1
	goto Route119_EventScript_001ECD49
	end

Route119_EventScript_001ECD3E::
	setvar 0x4001, 0x2
	goto Route119_EventScript_001ECD49
	end

Route119_EventScript_001ECD49::
	lockall
	addobject 0x19
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route119_EventScript_001ECDC2
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route119_EventScript_001ECDC7
	delay 0x41
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, Route119_EventScript_001ECF87
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, Route119_EventScript_001ECF92
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, Route119_EventScript_001ECFC1
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, Route119_EventScript_001ECFD0
	removeobject 0x19
	addobject 0x10
	delay 0x1E
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route119_EventScript_001ECDCC
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route119_EventScript_001ECE46
	releaseall
	end

Route119_EventScript_001ECDC2::
	playbgm 0x19F, 0x1
	return

Route119_EventScript_001ECDC7::
	playbgm 0x1A5, 0x1
	return

Route119_EventScript_001ECDCC::
	loadword 0x0, 0x081ED2BE
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081ECDFB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081ECE0B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081ECE1B
	end

	.incbin "baserom_jp.gba", 0x1ecdfb, 0x4b
Route119_EventScript_001ECE46::
	loadword 0x0, 0x081ED441
	callstd 0x4
	copyvar 0x8000, 0x4023
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x081ECE75
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x081ECE85
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x081ECE95
	end

	.incbin "baserom_jp.gba", 0x1ece75, 0x112
Route119_EventScript_001ECF87::
	applymovement 0x19, 0x081ECFE9
	waitmovement 0x0
	return

Route119_EventScript_001ECF92::
	applymovement 0x19, 0x081ECFF3
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1ecf9d, 0x24
Route119_EventScript_001ECFC1::
	setobjectxyperm 0x10, 0x19, 0x20
	setobjectxyperm 0x19, 0x19, 0x20
	return

Route119_EventScript_001ECFD0::
	setobjectxyperm 0x10, 0x1A, 0x20
	setobjectxyperm 0x19, 0x1A, 0x20
	return

	.incbin "baserom_jp.gba", 0x1ecfdf, 0x4d
Route119_EventScript_001ED02C::
	loadword 0x0, 0x081ED788
	callstd 0x2
	end

Route119_EventScript_001ED035::
	loadword 0x0, 0x081ED7E7
	callstd 0x3
	end

Route119_EventScript_001ED03E::
	loadword 0x0, 0x081ED801
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1ed047, 0x21d
Route119_EventScript_001ED264::
	lock
	faceplayer
	loadword 0x0, 0x081ED6B1
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

Route119_EventScript_001ED27B::
	lock
	faceplayer
	loadword 0x0, 0x081ED6EB
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

Route119_EventScript_001ED292::
	loadword 0x0, 0x081ED724
	callstd 0x2
	end

Route119_EventScript_001ED29B::
	loadword 0x0, 0x081ED7B3
	callstd 0x2
	end

Route119_EventScript_001ED2A4::
	loadword 0x0, 0x081ED80F
	callstd 0x3
	end

gUnknown_81ED2AD:: @ 0x081ED2AD
	.incbin "baserom_jp.gba", 0x1ed2ad, 0x5b7
