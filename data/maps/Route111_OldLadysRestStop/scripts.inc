@ Route111_OldLadysRestStop scripts (JP map g18 m1 @ 0x08211DED)

Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_EventScript_00211DF3
	.byte 0

Route111_OldLadysRestStop_EventScript_00211DF3::
	setflag 0x8A1
	end

Route111_OldLadysRestStop_EventScript_00211DF7::
	lock
	faceplayer
	loadword 0x0, 0x08211E4F
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route111_OldLadysRestStop_EventScript_00211E18
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route111_OldLadysRestStop_EventScript_00211E45
	end

Route111_OldLadysRestStop_EventScript_00211E18::
	loadword 0x0, 0x08211E90
	callstd 0x4
	closemessage
	call 0x0824310F
	loadword 0x0, 0x08211EA6
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route111_OldLadysRestStop_EventScript_00211E18
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route111_OldLadysRestStop_EventScript_00211E45
	end

Route111_OldLadysRestStop_EventScript_00211E45::
	loadword 0x0, 0x08211EE0
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x211e4f, 0xbb
