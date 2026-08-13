@ Route124_DivingTreasureHuntersHouse scripts (JP map g33 m0 @ 0x08241C4F)

Route124_DivingTreasureHuntersHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_DivingTreasureHuntersHouse_EventScript_00241C55
	.byte 0

Route124_DivingTreasureHuntersHouse_EventScript_00241C55::
	setflag 0x8BB
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241C59::
	lock
	faceplayer
	checkflag 0xD9
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241C75
	loadword 0x0, 0x08242193
	callstd 0x4
	setflag 0xD9
	goto Route124_DivingTreasureHuntersHouse_EventScript_00241C83
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241C75::
	loadword 0x0, 0x082421D8
	callstd 0x4
	goto Route124_DivingTreasureHuntersHouse_EventScript_00241C83
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241C83::
	call Route124_DivingTreasureHuntersHouse_EventScript_00241C99
	compare_var_to_value 0x4001, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_0024217E
	goto Route124_DivingTreasureHuntersHouse_EventScript_00241CF7
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241C99::
	setvar 0x4001, 0x0
	checkitem 0x30, 0x1
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241CDF
	checkitem 0x32, 0x1
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241CE5
	checkitem 0x31, 0x1
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241CEB
	checkitem 0x33, 0x1
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241CF1
	return

Route124_DivingTreasureHuntersHouse_EventScript_00241CDF::
	addvar 0x4001, 0x1
	return

Route124_DivingTreasureHuntersHouse_EventScript_00241CE5::
	addvar 0x4001, 0x2
	return

Route124_DivingTreasureHuntersHouse_EventScript_00241CEB::
	addvar 0x4001, 0x4
	return

Route124_DivingTreasureHuntersHouse_EventScript_00241CF1::
	addvar 0x4001, 0x8
	return

Route124_DivingTreasureHuntersHouse_EventScript_00241CF7::
	loadword 0x0, 0x08242236
	callstd 0x4
	goto Route124_DivingTreasureHuntersHouse_EventScript_00241D05
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241D05::
	message 0x0824227C
	waitmessage
	copyvar 0x8000, 0x4001
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241DB6
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241DDC
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241E02
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241E33
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241E59
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241E8A
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241EBB
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241EF7
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241F1D
	compare_var_to_value 0x8000, 0xA
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241F4E
	compare_var_to_value 0x8000, 0xB
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241F7F
	compare_var_to_value 0x8000, 0xC
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241FBB
	compare_var_to_value 0x8000, 0xD
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241FEC
	compare_var_to_value 0x8000, 0xE
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242028
	compare_var_to_value 0x8000, 0xF
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242064
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241DB6::
	multichoice 0x0, 0x0, 0x3A, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241DDC::
	multichoice 0x0, 0x0, 0x3B, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241E02::
	multichoice 0x0, 0x0, 0x3C, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241E33::
	multichoice 0x0, 0x0, 0x3D, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241E59::
	multichoice 0x0, 0x0, 0x3E, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241E8A::
	multichoice 0x0, 0x0, 0x3F, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241EBB::
	multichoice 0x0, 0x0, 0x40, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241EF7::
	multichoice 0x0, 0x0, 0x41, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241F1D::
	multichoice 0x0, 0x0, 0x42, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241F4E::
	multichoice 0x0, 0x0, 0x43, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241F7F::
	multichoice 0x0, 0x0, 0x44, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241FBB::
	multichoice 0x0, 0x0, 0x45, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00241FEC::
	multichoice 0x0, 0x0, 0x46, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00242028::
	multichoice 0x0, 0x0, 0x47, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_00242064::
	multichoice 0x0, 0x0, 0x48, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420AB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420BA
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420C9
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_002420D8
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_002420AB::
	setvar 0x8008, 0x30
	setvar 0x8009, 0x5F
	goto Route124_DivingTreasureHuntersHouse_EventScript_002420E7

Route124_DivingTreasureHuntersHouse_EventScript_002420BA::
	setvar 0x8008, 0x32
	setvar 0x8009, 0x60
	goto Route124_DivingTreasureHuntersHouse_EventScript_002420E7

Route124_DivingTreasureHuntersHouse_EventScript_002420C9::
	setvar 0x8008, 0x31
	setvar 0x8009, 0x61
	goto Route124_DivingTreasureHuntersHouse_EventScript_002420E7

Route124_DivingTreasureHuntersHouse_EventScript_002420D8::
	setvar 0x8008, 0x33
	setvar 0x8009, 0x62
	goto Route124_DivingTreasureHuntersHouse_EventScript_002420E7

Route124_DivingTreasureHuntersHouse_EventScript_002420E7::
	bufferitemname 0x0, 0x8008
	bufferitemname 0x1, 0x8009
	loadword 0x0, 0x0824228C
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242174
	checkitemspace 0x8009, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242128
	checkitem 0x8008, 0x2
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242128
	goto Route124_DivingTreasureHuntersHouse_EventScript_0024216A
	end

Route124_DivingTreasureHuntersHouse_EventScript_00242128::
	takeitem 0x8008, 0x1
	setorcopyvar 0x8000, 0x8009
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	loadword 0x0, 0x082422A1
	callstd 0x4
	call Route124_DivingTreasureHuntersHouse_EventScript_00241C99
	compare_var_to_value 0x4001, 0x0
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00242188
	loadword 0x0, 0x082422BC
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route124_DivingTreasureHuntersHouse_EventScript_00241D05
	goto Route124_DivingTreasureHuntersHouse_EventScript_00242174
	end

Route124_DivingTreasureHuntersHouse_EventScript_0024216A::
	loadword 0x0, 0x082422CA
	callstd 0x4
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_00242174::
	loadword 0x0, 0x082422E9
	callstd 0x4
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_0024217E::
	loadword 0x0, 0x082421FC
	callstd 0x4
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_00242188::
	release
	end

Route124_DivingTreasureHuntersHouse_EventScript_0024218A::
	loadword 0x0, 0x08242307
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x242193, 0x21c
