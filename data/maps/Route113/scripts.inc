@ Route113 scripts (JP map g0 m28 @ 0x081EB153)

Route113_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route113_EventScript_001EB15E
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_EventScript_001EB161
	.byte 0

Route113_EventScript_001EB15E::
	setstepcallback 0x1
	end

Route113_EventScript_001EB161::
	clearflag 0x9D
	call Route113_EventScript_001EB16A
	end

Route113_EventScript_001EB16A::
	getplayerxy 0x4000, 0x4001
	compare_var_to_value 0x4000, 0x13
	goto_if 0x0, Route113_EventScript_001EB189
	compare_var_to_value 0x4000, 0x54
	goto_if 0x2, Route113_EventScript_001EB189
	setweather 0x7
	return

Route113_EventScript_001EB189::
	return

Route113_EventScript_001EB18A::
	loadword 0x0, 0x081EB35B
	callstd 0x2
	end

Route113_EventScript_001EB193::
	loadword 0x0, 0x081EB397
	callstd 0x2
	end

Route113_EventScript_001EB19C::
	loadword 0x0, 0x081EB3CC
	callstd 0x3
	end

Route113_EventScript_001EB1A5::
	loadword 0x0, 0x081EB3E8
	callstd 0x3
	end

Route113_EventScript_001EB1AE::
	loadword 0x0, 0x081EB454
	callstd 0x3
	end

Route113_EventScript_001EB1B7::
	loadword 0x0, 0x081EB402
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1eb1c0, 0x2b4
