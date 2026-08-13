@ Route113_GlassWorkshop scripts (JP map g30 m0 @ 0x082407B7)

Route113_GlassWorkshop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_EventScript_002407BD
	.byte 0

Route113_GlassWorkshop_EventScript_002407BD::
	setflag 0x8A4
	compare_var_to_value 0x40BE, 0x1
	call_if 0x1, Route113_GlassWorkshop_EventScript_002407CC
	end

Route113_GlassWorkshop_EventScript_002407CC::
	setvar 0x40BE, 0x2
	return

Route113_GlassWorkshop_EventScript_002407D2::
	lock
	faceplayer
	compare_var_to_value 0x40BE, 0xA
	goto_if 0x4, Route113_GlassWorkshop_EventScript_00240B44
	compare_var_to_value 0x40BE, 0x2
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240822
	compare_var_to_value 0x40BE, 0x1
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240818
	loadword 0x0, 0x08240C51
	callstd 0x4
	setorcopyvar 0x8000, 0x10E
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setvar 0x40BE, 0x1
	loadword 0x0, 0x08240CB6
	callstd 0x4
	release
	end

Route113_GlassWorkshop_EventScript_00240818::
	loadword 0x0, 0x08240CB6
	callstd 0x4
	release
	end

Route113_GlassWorkshop_EventScript_00240822::
	checkitem 0x10E, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240851
	loadword 0x0, 0x08240D28
	callstd 0x4
	compare_var_to_value 0x4048, 0xFA
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240A8A
	message 0x08240D99
	waitmessage
	goto Route113_GlassWorkshop_EventScript_0024085B
	end

Route113_GlassWorkshop_EventScript_00240851::
	loadword 0x0, 0x08240F39
	callstd 0x4
	release
	end

Route113_GlassWorkshop_EventScript_0024085B::
	setvar 0x8009, 0x0
	setvar 0x8004, 0x1
	special sub_0813A164
	waitstate
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_002408D2
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, Route113_GlassWorkshop_EventScript_0024090E
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, Route113_GlassWorkshop_EventScript_0024094A
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240986
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, Route113_GlassWorkshop_EventScript_002409C2
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, Route113_GlassWorkshop_EventScript_002409FE
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240A3F
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240A80
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240A80
	end

Route113_GlassWorkshop_EventScript_002408D2::
	setvar 0x8008, 0x27
	bufferitemname 0x0, 0x8008
	setvar 0x800A, 0xFA
	compare_var_to_value 0x4048, 0xFA
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240AA2
	loadword 0x0, 0x08240DD2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240AB7
	setvar 0x40BE, 0xA
	subvar 0x4048, 0xFA
	goto Route113_GlassWorkshop_EventScript_00240AC3
	end

Route113_GlassWorkshop_EventScript_0024090E::
	setvar 0x8008, 0x28
	bufferitemname 0x0, 0x8008
	setvar 0x800A, 0x1F4
	compare_var_to_value 0x4048, 0x1F4
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240AA2
	loadword 0x0, 0x08240DD2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240AB7
	setvar 0x40BE, 0xB
	subvar 0x4048, 0x1F4
	goto Route113_GlassWorkshop_EventScript_00240AC3
	end

Route113_GlassWorkshop_EventScript_0024094A::
	setvar 0x8008, 0x29
	bufferitemname 0x0, 0x8008
	setvar 0x800A, 0x1F4
	compare_var_to_value 0x4048, 0x1F4
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240AA2
	loadword 0x0, 0x08240DD2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240AB7
	setvar 0x40BE, 0xC
	subvar 0x4048, 0x1F4
	goto Route113_GlassWorkshop_EventScript_00240AC3
	end

Route113_GlassWorkshop_EventScript_00240986::
	setvar 0x8008, 0x2B
	bufferitemname 0x0, 0x8008
	setvar 0x800A, 0x3E8
	compare_var_to_value 0x4048, 0x3E8
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240AA2
	loadword 0x0, 0x08240DD2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240AB7
	setvar 0x40BE, 0xD
	subvar 0x4048, 0x3E8
	goto Route113_GlassWorkshop_EventScript_00240AC3
	end

Route113_GlassWorkshop_EventScript_002409C2::
	setvar 0x8008, 0x2A
	bufferitemname 0x0, 0x8008
	setvar 0x800A, 0x3E8
	compare_var_to_value 0x4048, 0x3E8
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240AA2
	loadword 0x0, 0x08240DD2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240AB7
	setvar 0x40BE, 0xE
	subvar 0x4048, 0x3E8
	goto Route113_GlassWorkshop_EventScript_00240AC3
	end

Route113_GlassWorkshop_EventScript_002409FE::
	setvar 0x8009, 0x1
	setvar 0x8008, 0xD
	bufferspeciesname 0x0, 0x8008
	setvar 0x800A, 0x1770
	compare_var_to_value 0x4048, 0x1770
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240AA2
	loadword 0x0, 0x08240DD2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240AB7
	setvar 0x40BE, 0xF
	subvar 0x4048, 0x1770
	goto Route113_GlassWorkshop_EventScript_00240AC3
	end

Route113_GlassWorkshop_EventScript_00240A3F::
	setvar 0x8009, 0x1
	setvar 0x8008, 0x6
	bufferspeciesname 0x0, 0x8008
	setvar 0x800A, 0x1F40
	compare_var_to_value 0x4048, 0x1F40
	goto_if 0x0, Route113_GlassWorkshop_EventScript_00240AA2
	loadword 0x0, 0x08240DD2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240AB7
	setvar 0x40BE, 0x10
	subvar 0x4048, 0x1F40
	goto Route113_GlassWorkshop_EventScript_00240AC3
	end

Route113_GlassWorkshop_EventScript_00240A80::
	loadword 0x0, 0x08240E97
	callstd 0x4
	release
	end

Route113_GlassWorkshop_EventScript_00240A8A::
	setvar 0x800A, 0xFA
	subvar 0x800A, 0x4048
	buffernumberstring 0x0, 0x800A
	loadword 0x0, 0x08240D4C
	callstd 0x4
	release
	end

Route113_GlassWorkshop_EventScript_00240AA2::
	subvar 0x800A, 0x4048
	buffernumberstring 0x1, 0x800A
	message 0x08240E35
	waitmessage
	goto Route113_GlassWorkshop_EventScript_0024085B
	end

Route113_GlassWorkshop_EventScript_00240AB7::
	message 0x08240DF4
	waitmessage
	goto Route113_GlassWorkshop_EventScript_0024085B
	end

Route113_GlassWorkshop_EventScript_00240AC3::
	loadword 0x0, 0x08240E02
	callstd 0x4
	closemessage
	fadescreen 0x1
	playse 0x5
	delay 0x1E
	fadescreen 0x0
	loadword 0x0, 0x08240EBF
	callstd 0x4
	compare_var_to_value 0x8009, 0x0
	call_if 0x1, Route113_GlassWorkshop_EventScript_00240AFB
	compare_var_to_value 0x8009, 0x1
	call_if 0x1, Route113_GlassWorkshop_EventScript_00240B13
	setvar 0x40BE, 0x2
	release
	end

Route113_GlassWorkshop_EventScript_00240AFB::
	setorcopyvar 0x8000, 0x8008
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240B26
	return

Route113_GlassWorkshop_EventScript_00240B13::
	setorcopyvar 0x8000, 0x8008
	callstd 0x7
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240B35
	return

Route113_GlassWorkshop_EventScript_00240B26::
	call 0x082430EA
	loadword 0x0, 0x08240EDA
	callstd 0x4
	release
	end

Route113_GlassWorkshop_EventScript_00240B35::
	call 0x082430FD
	loadword 0x0, 0x08240F09
	callstd 0x4
	release
	end

Route113_GlassWorkshop_EventScript_00240B44::
	copyvar 0x8000, 0x40BE
	compare_var_to_value 0x8000, 0xA
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240B97
	compare_var_to_value 0x8000, 0xB
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240BAB
	compare_var_to_value 0x8000, 0xC
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240BBF
	compare_var_to_value 0x8000, 0xD
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240BD3
	compare_var_to_value 0x8000, 0xE
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240BE7
	compare_var_to_value 0x8000, 0xF
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240BFB
	compare_var_to_value 0x8000, 0x10
	goto_if 0x1, Route113_GlassWorkshop_EventScript_00240C0F
	end

Route113_GlassWorkshop_EventScript_00240B97::
	setvar 0x8009, 0x0
	setvar 0x8008, 0x27
	bufferitemname 0x0, 0x8008
	goto Route113_GlassWorkshop_EventScript_00240C23
	end

Route113_GlassWorkshop_EventScript_00240BAB::
	setvar 0x8009, 0x0
	setvar 0x8008, 0x28
	bufferitemname 0x0, 0x8008
	goto Route113_GlassWorkshop_EventScript_00240C23
	end

Route113_GlassWorkshop_EventScript_00240BBF::
	setvar 0x8009, 0x0
	setvar 0x8008, 0x29
	bufferitemname 0x0, 0x8008
	goto Route113_GlassWorkshop_EventScript_00240C23
	end

Route113_GlassWorkshop_EventScript_00240BD3::
	setvar 0x8009, 0x0
	setvar 0x8008, 0x2B
	bufferitemname 0x0, 0x8008
	goto Route113_GlassWorkshop_EventScript_00240C23
	end

Route113_GlassWorkshop_EventScript_00240BE7::
	setvar 0x8009, 0x0
	setvar 0x8008, 0x2A
	bufferitemname 0x0, 0x8008
	goto Route113_GlassWorkshop_EventScript_00240C23
	end

Route113_GlassWorkshop_EventScript_00240BFB::
	setvar 0x8009, 0x1
	setvar 0x8008, 0xD
	bufferspeciesname 0x0, 0xD
	goto Route113_GlassWorkshop_EventScript_00240C23
	end

Route113_GlassWorkshop_EventScript_00240C0F::
	setvar 0x8009, 0x1
	setvar 0x8008, 0x6
	bufferspeciesname 0x0, 0x6
	goto Route113_GlassWorkshop_EventScript_00240C23
	end

Route113_GlassWorkshop_EventScript_00240C23::
	loadword 0x0, 0x08240EBF
	callstd 0x4
	compare_var_to_value 0x8009, 0x0
	call_if 0x1, Route113_GlassWorkshop_EventScript_00240AFB
	compare_var_to_value 0x8009, 0x1
	call_if 0x1, Route113_GlassWorkshop_EventScript_00240B13
	setvar 0x40BE, 0x2
	release
	end

Route113_GlassWorkshop_EventScript_00240C48::
	loadword 0x0, 0x08240F6C
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x240c51, 0x347
