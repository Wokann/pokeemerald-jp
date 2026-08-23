@ DewfordTown scripts (JP map g0 m11 @ 0x081E4C57)

DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_EventScript_001E4C5D
	.byte 0

DewfordTown_EventScript_001E4C5D::
	setflag 0x871
	end

DewfordTown_EventScript_001E4C61::
	lock
	faceplayer
	checkflag 0xBD
	goto_if 0x0, DewfordTown_EventScript_001E4CD5
	message 0x081E5261
	waitmessage
	multichoicedefault 0x15, 0x6, 0x0, 0x2, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, DewfordTown_EventScript_001E4CAA
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, DewfordTown_EventScript_001E4CBA
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, DewfordTown_EventScript_001E4CCA
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, DewfordTown_EventScript_001E4CCA
	end

DewfordTown_EventScript_001E4CAA::
	loadword 0x0, 0x081E5291
	callstd 0x4
	closemessage
	goto DewfordTown_EventScript_001E4DB0

	.incbin "baserom_jp.gba", 0x1e4cb8, 0x2
DewfordTown_EventScript_001E4CBA::
	loadword 0x0, 0x081E52AF
	callstd 0x4
	closemessage
	goto DewfordTown_EventScript_001E4E37

	.incbin "baserom_jp.gba", 0x1e4cc8, 0x2
DewfordTown_EventScript_001E4CCA::
	loadword 0x0, 0x081E52CD
	callstd 0x4
	closemessage
	release
	end

DewfordTown_EventScript_001E4CD5::
	loadword 0x0, 0x081E51BF
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, DewfordTown_EventScript_001E4CF2
	loadword 0x0, 0x081E5209
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E4CF2::
	loadword 0x0, 0x081E51E2
	callstd 0x4
	closemessage
	goto DewfordTown_EventScript_001E4DB0
	end

DewfordTown_EventScript_001E4D01::
	loadword 0x0, 0x081E50F8
	callstd 0x2
	end

DewfordTown_EventScript_001E4D0A::
	loadword 0x0, 0x081E512A
	callstd 0x3
	end

DewfordTown_EventScript_001E4D13::
	loadword 0x0, 0x081E5149
	callstd 0x3
	end

DewfordTown_EventScript_001E4D1C::
	loadword 0x0, 0x081E516E
	callstd 0x3
	end

DewfordTown_EventScript_001E4D25::
	lock
	faceplayer
	checkflag 0x101
	goto_if 0x1, DewfordTown_EventScript_001E4D7A
	loadword 0x0, 0x081E52F3
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, DewfordTown_EventScript_001E4D4F
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, DewfordTown_EventScript_001E4D70
	end

DewfordTown_EventScript_001E4D4F::
	loadword 0x0, 0x081E5316
	callstd 0x4
	setorcopyvar 0x8000, 0x106
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x101
	loadword 0x0, 0x081E5334
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E4D70::
	loadword 0x0, 0x081E53E0
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E4D7A::
	message 0x081E53EF
	waitmessage
	multichoice 0x14, 0x8, 0x32, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, DewfordTown_EventScript_001E4D9C
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, DewfordTown_EventScript_001E4DA6
	end

DewfordTown_EventScript_001E4D9C::
	loadword 0x0, 0x081E5401
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E4DA6::
	loadword 0x0, 0x081E5420
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E4DB0::
	call 0x08242F21
	setobjectsubpriority 0x2, 0xB, 0x0
	setobjectsubpriority 0xFF, 0xB, 0x0
	applymovement 0x2, 0x081E506D
	waitmovement 0x0
	removeobject 0x2
	applymovement 0xFF, 0x081E5061
	waitmovement 0x0
	hideobject_at 0xFF, 0xB
	call 0x0824312C
	applymovement 0x4, 0x081E4EF2
	applymovement 0xFF, 0x081E4EF2
	waitmovement 0x0
	showobject_at 0xFF, 0x13
	call 0x08243134
	applymovement 0xFF, 0x081E5064
	waitmovement 0x0
	showobject_at 0xFF, 0x13
	clearflag 0x2E3
	clearflag 0x371
	clearflag 0x2E6
	setflag 0x2E7
	hideobject_at 0x4, 0xB
	setvar 0x408E, 0x2
	resetobjectsubpriority 0xFF, 0xB
	warp 0x1100, 0xFF, 0x5, 0x4
	copyvar 0x4096, 0x8008
	waitstate
	release
	end

DewfordTown_EventScript_001E4E37::
	call 0x08242F21
	setobjectsubpriority 0x2, 0xB, 0x0
	setobjectsubpriority 0xFF, 0xB, 0x1
	applymovement 0x2, 0x081E506D
	waitmovement 0x0
	removeobject 0x2
	applymovement 0xFF, 0x081E5061
	waitmovement 0x0
	hideobject_at 0xFF, 0xB
	call 0x0824312C
	applymovement 0x4, 0x081E4FB5
	applymovement 0xFF, 0x081E4FB5
	waitmovement 0x0
	call 0x08243134
	showobject_at 0xFF, 0x18
	applymovement 0xFF, 0x081E5068
	waitmovement 0x0
	setobjectxyperm 0x2, 0x15, 0x1A
	addobject 0x2
	setobjectsubpriority 0x2, 0x18, 0x0
	applymovement 0x2, 0x081E506F
	waitmovement 0x0
	clearflag 0x2E5
	addobject 0x1
	clearflag 0x2E8
	setflag 0x2E7
	hideobject_at 0x4, 0xB
	checkflag 0x95
	call_if 0x0, DewfordTown_EventScript_001E4EE0
	checkflag 0x95
	call_if 0x1, DewfordTown_EventScript_001E4EE9
	closemessage
	copyvar 0x4096, 0x8008
	resetobjectsubpriority 0xFF, 0xB
	resetobjectsubpriority 0x2, 0x18
	moveobjectoffscreen 0x2
	release
	end

DewfordTown_EventScript_001E4EE0::
	loadword 0x0, 0x081E8B34
	callstd 0x4
	return

DewfordTown_EventScript_001E4EE9::
	loadword 0x0, 0x081E8BC7
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x1e4ef2, 0x180
DewfordTown_EventScript_001E5072::
	lock
	faceplayer
	call 0x08242F17
	loadword 0x0, 0x081E54D0
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, DewfordTown_EventScript_001E5098
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, DewfordTown_EventScript_001E50A2
	end

DewfordTown_EventScript_001E5098::
	loadword 0x0, 0x081E5649
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E50A2::
	loadword 0x0, 0x081E5546
	callstd 0x4
	setvar 0x8004, 0x9
	call 0x08242F08
	lock
	faceplayer
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, DewfordTown_EventScript_001E50CD
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, DewfordTown_EventScript_001E50E4
	end

DewfordTown_EventScript_001E50CD::
	incrementgamestat 0x2
	compare_var_to_value 0x8004, 0x0
	goto_if 0x1, DewfordTown_EventScript_001E50EE
	loadword 0x0, 0x081E556D
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E50E4::
	loadword 0x0, 0x081E5626
	callstd 0x4
	release
	end

DewfordTown_EventScript_001E50EE::
	loadword 0x0, 0x081E55FE
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1e50f8, 0x99
Route104_Text_LandedInDewfordDeliverLetter:: @ 0x081E5191
	.globl gJPText_001E5191
gJPText_001E5191:
	.string "ハギ“ほい！　ムロに　とうちゃく！\p"
	.string "たしか　ダイゴとやらに\n"
	.string "てがみを　とどけるんだったな！$"

	.incbin "baserom_jp.gba", 0x1e51bf, 0x6d
DewfordTown_Text_BrineyLandedInDewford:: @ 0x081E522C
	.globl gJPText_001E522C
gJPText_001E522C:
	.string "ハギ“ほい！　ムロタウンに　とうちゃく！\p"
	.string "ふねに　のりたくなったら\n"
	.string "また　わしに　こえを　かけておくれ！$"

	.incbin "baserom_jp.gba", 0x1e5261, 0x401
