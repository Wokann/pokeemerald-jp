@ SafariZone_South scripts (JP map g26 m3 @ 0x0821EA39)

SafariZone_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_South_EventScript_0021EA71
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZone_South_MapScriptTable_0021EA44
	.byte 0

SafariZone_South_MapScriptTable_0021EA44::
	map_script_2 0x40A4, 0x2, SafariZone_South_EventScript_0021EA4E
	.2byte 0

SafariZone_South_EventScript_0021EA4E::
	lockall
	applymovement 0xFF, 0x0821EA85
	waitmovement 0x0
	applymovement 0x1, 0x0821EA87
	waitmovement 0x0
	setobjectxyperm 0x1, 0x20, 0x22
	setvar 0x40A4, 0x0
	releaseall
	end

SafariZone_South_EventScript_0021EA71::
	compare_var_to_value 0x40A4, 0x2
	call_if 0x1, SafariZone_South_EventScript_0021EA7D
	end

SafariZone_South_EventScript_0021EA7D::
	setobjectxyperm 0x1, 0x1F, 0x22
	return

	.incbin "baserom_jp.gba", 0x21ea85, 0x5
SafariZone_South_EventScript_0021EA8A::
	loadword 0x0, 0x0826283A
	callstd 0x2
	end

SafariZone_South_EventScript_0021EA93::
	loadword 0x0, 0x08262869
	callstd 0x2
	end

SafariZone_South_EventScript_0021EA9C::
	loadword 0x0, 0x08262987
	callstd 0x2
	end

SafariZone_South_EventScript_0021EAA5::
	lock
	faceplayer
	checkflag 0x5D
	goto_if 0x0, SafariZone_South_EventScript_0021EACD
	loadword 0x0, 0x0826279C
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SafariZone_South_EventScript_0021EADA
	loadword 0x0, 0x082627BD
	callstd 0x4
	release
	end

SafariZone_South_EventScript_0021EACD::
	setflag 0x5D
	loadword 0x0, 0x0826280D
	callstd 0x4
	release
	end

SafariZone_South_EventScript_0021EADA::
	loadword 0x0, 0x082627D2
	callstd 0x4
	closemessage
	copyvar 0x8000, 0x800C
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, SafariZone_South_EventScript_0021EAFF
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, SafariZone_South_EventScript_0021EB19
	end

SafariZone_South_EventScript_0021EAFF::
	applymovement 0x1, 0x0821EB4A
	waitmovement 0x0
	applymovement 0xFF, 0x0821EB45
	waitmovement 0x0
	goto SafariZone_South_EventScript_0021EB33
	end

SafariZone_South_EventScript_0021EB19::
	applymovement 0x1, 0x0821EB4D
	waitmovement 0x0
	applymovement 0xFF, 0x0821EB47
	waitmovement 0x0
	goto SafariZone_South_EventScript_0021EB33
	end

SafariZone_South_EventScript_0021EB33::
	setvar 0x40A4, 0x1
	special ExitSafariMode
	warpdoor 0x1700, 0xFF, 0x2, 0x5
	waitstate
	end

	.incbin "baserom_jp.gba", 0x21eb45, 0xb
SafariZone_South_EventScript_0021EB50::
	loadword 0x0, 0x08262AEF
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x21eb59, 0x9
SafariZone_South_EventScript_0021EB62::
	loadword 0x0, 0x08262B4E
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x21eb6b, 0x36
