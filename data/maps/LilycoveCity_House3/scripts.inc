@ LilycoveCity_House3 scripts (JP map g13 m14 @ 0x0820A065)

LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_EventScript_0020A06B
	.byte 0

LilycoveCity_House3_EventScript_0020A06B::
	random 0x4
	copyvar 0x4001, 0x800D
	end

LilycoveCity_House3_EventScript_0020A074::
	lock
	faceplayer
	loadword 0x0, 0x0820A1C2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A09E
	loadword 0x0, 0x0820A278
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

LilycoveCity_House3_EventScript_0020A09E::
	loadword 0x0, 0x0820A24F
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

LilycoveCity_House3_EventScript_0020A0B3::
	lock
	faceplayer
	loadword 0x0, 0x0820A44F
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

LilycoveCity_House3_EventScript_0020A0CA::
	lock
	faceplayer
	copyvar 0x8000, 0x4001
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A19A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1A4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1AE
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1B8
	end

LilycoveCity_House3_EventScript_0020A0FE::
	lock
	faceplayer
	copyvar 0x8000, 0x4001
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A19A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1A4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1AE
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1B8
	end

LilycoveCity_House3_EventScript_0020A132::
	lock
	faceplayer
	copyvar 0x8000, 0x4001
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A19A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1A4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1AE
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1B8
	end

LilycoveCity_House3_EventScript_0020A166::
	lock
	faceplayer
	copyvar 0x8000, 0x4001
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A19A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1A4
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1AE
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_House3_EventScript_0020A1B8
	end

LilycoveCity_House3_EventScript_0020A19A::
	loadword 0x0, 0x0820A495
	callstd 0x4
	release
	end

LilycoveCity_House3_EventScript_0020A1A4::
	loadword 0x0, 0x0820A4B2
	callstd 0x4
	release
	end

LilycoveCity_House3_EventScript_0020A1AE::
	loadword 0x0, 0x0820A4D3
	callstd 0x4
	release
	end

LilycoveCity_House3_EventScript_0020A1B8::
	loadword 0x0, 0x0820A4F2
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20a1c2, 0x358
