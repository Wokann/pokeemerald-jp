@ MtChimney scripts (JP map g24 m12 @ 0x08214B94)

MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_EventScript_00214BA5
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_EventScript_00214B9F
	.byte 0

MtChimney_EventScript_00214B9F::
	setvar 0x40BD, 0x1
	end

MtChimney_EventScript_00214BA5::
	setstepcallback 0x1
	end

MtChimney_EventScript_00214BA8::
	lock
	faceplayer
	checkflag 0xDB
	call_if 0x0, MtChimney_EventScript_00214BCC
	checkflag 0xDB
	call_if 0x1, MtChimney_EventScript_00214BD5
	closemessage
	applymovement 0x1, 0x08243625
	waitmovement 0x0
	setflag 0xDB
	release
	end

MtChimney_EventScript_00214BCC::
	loadword 0x0, 0x08215500
	callstd 0x4
	return

MtChimney_EventScript_00214BD5::
	loadword 0x0, 0x0821558F
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x214bde, 0xe8
MtChimney_EventScript_00214CC6::
	lock
	faceplayer
	showmoneybox 0x0, 0x0, 0x0
	loadword 0x0, 0x082156F6
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MtChimney_EventScript_00214D3C
	checkmoney 0xC8, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MtChimney_EventScript_00214D49
	loadword 0x0, 0x0821571E
	callstd 0x4
	checkitemspace 0x26, 0x1
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, MtChimney_EventScript_00214D31
	setorcopyvar 0x8000, 0x26
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MtChimney_EventScript_00214D24
	hidemoneybox
	release
	end

MtChimney_EventScript_00214D24::
	loadword 0x0, gJPText_00243977
	callstd 0x4
	hidemoneybox
	release
	end

MtChimney_EventScript_00214D31::
	takemoney 0xC8, 0x0
	updatemoneybox 0x0
	return

MtChimney_EventScript_00214D3C::
	loadword 0x0, 0x08215741
	callstd 0x4
	hidemoneybox
	release
	end

MtChimney_EventScript_00214D49::
	loadword 0x0, 0x08215728
	callstd 0x4
	hidemoneybox
	release
	end

	.incbin "baserom_jp.gba", 0x214d56, 0xd0
MtChimney_EventScript_00214E26::
	loadword 0x0, 0x0821566C
	callstd 0x3
	end

MtChimney_EventScript_00214E2F::
	loadword 0x0, 0x0821568C
	callstd 0x3
	end

MtChimney_EventScript_00214E38::
	loadword 0x0, 0x082156B5
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x214e41, 0x2e
MtChimney_EventScript_00214E6F::
	loadword 0x0, 0x08215428
	callstd 0x3
	end

MtChimney_EventScript_00214E78::
	loadword 0x0, 0x0821544D
	callstd 0x3
	end

MtChimney_EventScript_00214E81::
	loadword 0x0, 0x08215463
	callstd 0x3
	end

MtChimney_EventScript_00214E8A::
	loadword 0x0, 0x08215498
	callstd 0x3
	end

MtChimney_EventScript_00214E93::
	loadword 0x0, 0x082154D0
	callstd 0x3
	end

MtChimney_EventScript_00214E9C::
	loadword 0x0, 0x082154E5
	callstd 0x3
	end

MtChimney_EventScript_00214EA5::
	loadword 0x0, 0x082154F9
	callstd 0x3
	end

MtChimney_EventScript_00214EAE::
	loadword 0x0, 0x082156EF
	callstd 0x3
	end

MtChimney_EventScript_00214EB7::
	lockall
	checkflag 0x8B
	goto_if 0x0, MtChimney_EventScript_00214F0A
	checkflag 0x73
	goto_if 0x1, MtChimney_EventScript_00214F00
	loadword 0x0, 0x0821577F
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, MtChimney_EventScript_00214EF6
	loadword 0x0, 0x082157A5
	callstd 0x4
	setorcopyvar 0x8000, 0x118
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x73
	releaseall
	end

MtChimney_EventScript_00214EF6::
	loadword 0x0, 0x082157BD
	callstd 0x4
	releaseall
	end

MtChimney_EventScript_00214F00::
	loadword 0x0, 0x082157D3
	callstd 0x4
	releaseall
	end

MtChimney_EventScript_00214F0A::
	loadword 0x0, 0x08215749
	callstd 0x4
	releaseall
	end

MtChimney_EventScript_00214F14::
	loadword 0x0, 0x082157ED
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x214f1d, 0xbd5
