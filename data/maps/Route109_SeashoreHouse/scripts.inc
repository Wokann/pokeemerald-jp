@ Route109_SeashoreHouse scripts (JP map g28 m0 @ 0x0823C403)

Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_EventScript_0023C409
	.byte 0

Route109_SeashoreHouse_EventScript_0023C409::
	setflag 0x89F
	end

Route109_SeashoreHouse_EventScript_0023C40D::
	lock
	faceplayer
	checkflag 0x8C
	goto_if 0x1, Route109_SeashoreHouse_EventScript_0023C46F
	checkflag 0x8D
	goto_if 0x1, Route109_SeashoreHouse_EventScript_0023C441
	checkflag 0x2
	goto_if 0x1, Route109_SeashoreHouse_EventScript_0023C437
	loadword 0x0, 0x0823C564
	callstd 0x4
	setflag 0x2
	release
	end

Route109_SeashoreHouse_EventScript_0023C437::
	loadword 0x0, 0x0823C5D9
	callstd 0x4
	release
	end

Route109_SeashoreHouse_EventScript_0023C441::
	loadword 0x0, 0x0823C60A
	callstd 0x4
	setorcopyvar 0x8000, 0x1B
	setorcopyvar 0x8001, 0x6
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route109_SeashoreHouse_EventScript_0023C465
	setflag 0x8C
	release
	end

Route109_SeashoreHouse_EventScript_0023C465::
	loadword 0x0, 0x0823C66D
	callstd 0x4
	release
	end

Route109_SeashoreHouse_EventScript_0023C46F::
	showmoneybox 0x0, 0x0, 0x0
	loadword 0x0, 0x0823C68F
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route109_SeashoreHouse_EventScript_0023C493
	loadword 0x0, 0x0823C6CA
	callstd 0x4
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_0023C493::
	checkmoney 0x12C, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route109_SeashoreHouse_EventScript_0023C4D7
	checkitemspace 0x1B, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route109_SeashoreHouse_EventScript_0023C4E4
	loadword 0x0, 0x0823C6BB
	callstd 0x4
	takemoney 0x12C, 0x0
	updatemoneybox 0x0
	setorcopyvar 0x8000, 0x1B
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_0023C4D7::
	loadword 0x0, 0x0823C6C0
	callstd 0x4
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_0023C4E4::
	loadword 0x0, gText_TooBadBagIsFull
	callstd 0x4
	hidemoneybox
	release
	end
