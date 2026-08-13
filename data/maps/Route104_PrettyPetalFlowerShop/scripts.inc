@ Route104_PrettyPetalFlowerShop scripts (JP map g17 m1 @ 0x082119B4)

Route104_PrettyPetalFlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_EventScript_002119BA
	.byte 0

Route104_PrettyPetalFlowerShop_EventScript_002119BA::
	setflag 0x89C
	checkflag 0x7F
	goto_if 0x0, Route104_PrettyPetalFlowerShop_EventScript_002119D3
	checkflag 0x869
	goto_if 0x0, Route104_PrettyPetalFlowerShop_EventScript_002119D3
	setflag 0x1
	end

Route104_PrettyPetalFlowerShop_EventScript_002119D3::
	setobjectxyperm 0x1, 0x4, 0x6
	end

Route104_PrettyPetalFlowerShop_EventScript_002119DB::
	lock
	faceplayer
	checkflag 0x1
	goto_if 0x1, Route104_PrettyPetalFlowerShop_EventScript_00211A4C
	loadword 0x0, 0x08263C9E
	callstd 0x4
	checkflag 0x7F
	goto_if 0x1, Route104_PrettyPetalFlowerShop_EventScript_00211A1A
	setflag 0x7F
	loadword 0x0, 0x08263CD9
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route104_PrettyPetalFlowerShop_EventScript_00211A3A
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route104_PrettyPetalFlowerShop_EventScript_00211A43
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_00211A1A::
	loadword 0x0, 0x08263CC6
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route104_PrettyPetalFlowerShop_EventScript_00211A3A
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, Route104_PrettyPetalFlowerShop_EventScript_00211A43
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_00211A3A::
	loadword 0x0, 0x08263D0D
	callstd 0x4
	return

Route104_PrettyPetalFlowerShop_EventScript_00211A43::
	loadword 0x0, 0x08263DCA
	callstd 0x4
	return

Route104_PrettyPetalFlowerShop_EventScript_00211A4C::
	message 0x08243927
	waitmessage
	pokemartdecoration2 0x08211A64
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x211a61, 0x13
Route104_PrettyPetalFlowerShop_EventScript_00211A74::
	lock
	faceplayer
	checkflag 0x5E
	goto_if 0x0, Route104_PrettyPetalFlowerShop_EventScript_00211A89
	loadword 0x0, 0x08263E32
	callstd 0x4
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_00211A89::
	loadword 0x0, 0x08263DE8
	callstd 0x4
	setorcopyvar 0x8000, 0x10C
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	loadword 0x0, 0x08263E32
	callstd 0x4
	setflag 0x5E
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_00211AAA::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x930
	goto_if 0x1, Route104_PrettyPetalFlowerShop_EventScript_00211AEA
	loadword 0x0, 0x08263EA4
	callstd 0x4
	random 0x8
	addvar 0x800D, 0x85
	setorcopyvar 0x8000, 0x800D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x930
	loadword 0x0, 0x08263ED1
	callstd 0x4
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_00211AEA::
	loadword 0x0, 0x08263ED1
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x211af4, 0x2f9
