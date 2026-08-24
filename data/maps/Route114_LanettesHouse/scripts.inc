@ Route114_LanettesHouse scripts (JP map g20 m2 @ 0x082124D1)

Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_EventScript_002124D7
	.byte 0

Route114_LanettesHouse_EventScript_002124D7::
	setflag 0x8A5
	end

Route114_LanettesHouse_EventScript_002124DB::
	lock
	faceplayer
	checkflag 0x83
	goto_if 0x1, Route114_LanettesHouse_EventScript_00212508
	setflag 0x8AB
	loadword 0x0, 0x08212557
	callstd 0x4
	setorcopyvar 0x8000, 0x63
	callstd 0x7
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430F3
	setflag 0x83
	release
	end

Route114_LanettesHouse_EventScript_00212508::
	loadword 0x0, 0x082125B8
	callstd 0x4
	release
	end

Route114_LanettesHouse_EventScript_00212512::
	lockall
	loadword 0x0, 0x0821260C
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route114_LanettesHouse_EventScript_00212530
	loadword 0x0, 0x08212763
	callstd 0x4
	releaseall
	end

Route114_LanettesHouse_EventScript_00212530::
	loadword 0x0, 0x08212680
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, Route114_LanettesHouse_EventScript_00212545
	releaseall
	end

Route114_LanettesHouse_EventScript_00212545::
	loadword 0x0, 0x082126E6
	callstd 0x4
	return

Route114_LanettesHouse_EventScript_0021254E::
	loadword 0x0, 0x08212770
	callstd 0x3
	end
