@ BattleFrontier_OutsideWest scripts (JP map g26 m4 @ 0x0821EBA1)

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_EventScript_0021EBA7
	.byte 0

BattleFrontier_OutsideWest_EventScript_0021EBA7::
	setvar 0x40BC, 0x0
	setflag 0x396
	end

BattleFrontier_OutsideWest_EventScript_0021EBB0::
	lock
	faceplayer
	loadword 0x0, 0x0821EF43
	callstd 0x4
	checkitem 0x109, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EC0E
	message 0x0821EFA2
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_0021EBD6
	end

BattleFrontier_OutsideWest_EventScript_0021EBD6::
	multichoicedefault 0x12, 0x6, 0x35, 0x2, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EC18
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EC43
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EC98
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EC98
	end

BattleFrontier_OutsideWest_EventScript_0021EC0E::
	loadword 0x0, 0x0821EF66
	callstd 0x4
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EC18::
	loadword 0x0, 0x0821EFD1
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EC6E
	loadword 0x0, 0x0821EFF7
	callstd 0x4
	call BattleFrontier_OutsideWest_EventScript_0021EC7A
	warp 0x909, 0xFF, 0x8, 0xB
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EC43::
	loadword 0x0, 0x0821EFDD
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EC6E
	loadword 0x0, 0x0821EFF7
	callstd 0x4
	call BattleFrontier_OutsideWest_EventScript_0021EC7A
	warp 0xD0A, 0xFF, 0x8, 0xB
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EC6E::
	message 0x0821F00B
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_0021EBD6
	end

BattleFrontier_OutsideWest_EventScript_0021EC7A::
	closemessage
	applymovement 0x800F, 0x0824362D
	waitmovement 0x0
	delay 0x1E
	hideobject_at 0x3, 0x1A04
	setvar 0x8004, 0x2
	call 0x082432D3
	return

BattleFrontier_OutsideWest_EventScript_0021EC98::
	loadword 0x0, 0x0821EFE9
	callstd 0x4
	release
	end

BattleFrontier_OutsideWest_EventScript_0021ECA2::
	loadword 0x0, 0x0821EEB7
	callstd 0x3
	end

BattleFrontier_OutsideWest_EventScript_0021ECAB::
	loadword 0x0, 0x0821EED6
	callstd 0x3
	end

BattleFrontier_OutsideWest_EventScript_0021ECB4::
	loadword 0x0, 0x0821EEF6
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x21ecbd, 0x12
BattleFrontier_OutsideWest_EventScript_0021ECCF::
	loadword 0x0, 0x0821F01B
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021ECD8::
	lock
	faceplayer
	message 0x0821F07B
	waitmessage
	applymovement 0x12, 0x08243623
	waitmovement 0x0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_0021ECED::
	loadword 0x0, 0x0821F0A7
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021ECF6::
	lock
	goto BattleFrontier_OutsideWest_EventScript_0021ED04
	end

BattleFrontier_OutsideWest_EventScript_0021ECFD::
	lock
	goto BattleFrontier_OutsideWest_EventScript_0021ED04
	end

BattleFrontier_OutsideWest_EventScript_0021ED04::
	applymovement 0x9, 0x0824362B
	waitmovement 0x0
	loadword 0x0, 0x0821F110
	callstd 0x4
	applymovement 0xA, 0x08243627
	waitmovement 0x0
	loadword 0x0, 0x0821F146
	callstd 0x4
	closemessage
	delay 0x19
	applymovement 0x9, 0x08243629
	applymovement 0xA, 0x08243629
	waitmovement 0x0
	release
	end

BattleFrontier_OutsideWest_EventScript_0021ED3F::
	lock
	faceplayer
	delay 0x14
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021ED7A
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021ED85
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021ED7A
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021ED7A
	loadword 0x0, 0x0821F18F
	callstd 0x4
	release
	end

BattleFrontier_OutsideWest_EventScript_0021ED7A::
	applymovement 0xE, 0x08243629
	waitmovement 0x0
	return

BattleFrontier_OutsideWest_EventScript_0021ED85::
	return

BattleFrontier_OutsideWest_EventScript_0021ED86::
	lock
	faceplayer
	message 0x0821F1DE
	waitmessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EDBD
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EDC8
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EDD3
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EDDE
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EDBD::
	applymovement 0xC, 0x0821EDE9
	waitmovement 0x0
	return

BattleFrontier_OutsideWest_EventScript_0021EDC8::
	applymovement 0xC, 0x0821EDEC
	waitmovement 0x0
	return

BattleFrontier_OutsideWest_EventScript_0021EDD3::
	applymovement 0xC, 0x0821EDEF
	waitmovement 0x0
	return

BattleFrontier_OutsideWest_EventScript_0021EDDE::
	applymovement 0xC, 0x0821EDF2
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x21ede9, 0xc
BattleFrontier_OutsideWest_EventScript_0021EDF5::
	lock
	faceplayer
	loadword 0x0, 0x0821F223
	callstd 0x4
	random 0x2
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_OutsideWest_EventScript_0021EE13
	goto BattleFrontier_OutsideWest_EventScript_0021EE1D
	end

BattleFrontier_OutsideWest_EventScript_0021EE13::
	loadword 0x0, 0x0821F24A
	callstd 0x4
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EE1D::
	loadword 0x0, 0x0821F26C
	callstd 0x4
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EE27::
	loadword 0x0, 0x0821F29C
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x21ee30, 0x9
BattleFrontier_OutsideWest_EventScript_0021EE39::
	loadword 0x0, 0x0821F30D
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE42::
	loadword 0x0, 0x0821F2E3
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE4B::
	loadword 0x0, 0x0821F371
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE54::
	loadword 0x0, 0x0821F3AB
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE5D::
	loadword 0x0, 0x0821F3F2
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE66::
	loadword 0x0, 0x0821F428
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE6F::
	loadword 0x0, 0x0821F44F
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE78::
	lock
	loadword 0x0, 0x0821F4C2
	callstd 0x4
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EE83::
	lock
	loadword 0x0, 0x0821F509
	callstd 0x4
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EE8E::
	loadword 0x0, 0x0821F550
	callstd 0x2
	end

BattleFrontier_OutsideWest_EventScript_0021EE97::
	lock
	faceplayer
	loadword 0x0, 0x0821F5B0
	callstd 0x4
	closemessage
	applymovement 0x17, 0x08243625
	waitmovement 0x0
	release
	end

BattleFrontier_OutsideWest_EventScript_0021EEAE::
	loadword 0x0, 0x0821F657
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x21eeb7, 0x805
