@ RustboroCity_DevonCorp_1F scripts (JP map g11 m0 @ 0x08201030)

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_EventScript_00201036
	.byte 0

RustboroCity_DevonCorp_1F_EventScript_00201036::
	checkflag 0x90
	call_if 0x0, RustboroCity_DevonCorp_1F_EventScript_00201040
	end

RustboroCity_DevonCorp_1F_EventScript_00201040::
	setobjectxyperm 0x2, 0xE, 0x2
	setobjectmovementtype 0x2, 0x8
	return

RustboroCity_DevonCorp_1F_EventScript_0020104C::
	lock
	faceplayer
	checkflag 0x90
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_00201074
	checkflag 0x8E
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_0020106A
	loadword 0x0, 0x08201162
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_0020106A::
	loadword 0x0, 0x082011A8
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_00201074::
	loadword 0x0, 0x08201208
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_0020107E::
	lock
	faceplayer
	checkflag 0x90
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010A5
	checkflag 0x8F
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010AF
	checkflag 0x8E
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010AF
	loadword 0x0, 0x08201222
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010A5::
	loadword 0x0, 0x0820126B
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010AF::
	loadword 0x0, 0x08201249
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010B9::
	lock
	faceplayer
	checkflag 0x90
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010E0
	checkflag 0x8F
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010EA
	checkflag 0x8E
	goto_if 0x1, RustboroCity_DevonCorp_1F_EventScript_002010EA
	loadword 0x0, 0x08201106
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010E0::
	loadword 0x0, 0x08201106
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010EA::
	loadword 0x0, 0x08201146
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_1F_EventScript_002010F4::
	loadword 0x0, 0x08201284
	callstd 0x3
	end

RustboroCity_DevonCorp_1F_EventScript_002010FD::
	loadword 0x0, 0x08201357
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x201106, 0x323
