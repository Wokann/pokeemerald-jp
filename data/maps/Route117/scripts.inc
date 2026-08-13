@ Route117 scripts (JP map g0 m32 @ 0x081EC423)

Route117_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_EventScript_001EC429
	.byte 0

Route117_EventScript_001EC429::
	call Route117_EventScript_001EC42F
	end

Route117_EventScript_001EC42F::
	checkflag 0x86
	goto_if 0x0, Route117_EventScript_001EC43F
	setobjectxyperm 0x3, 0x2F, 0x6

Route117_EventScript_001EC43F::
	return

Route117_EventScript_001EC440::
	loadword 0x0, 0x081EC769
	callstd 0x2
	end

Route117_EventScript_001EC449::
	loadword 0x0, 0x081EC78F
	callstd 0x2
	end

Route117_EventScript_001EC452::
	loadword 0x0, 0x081EC722
	callstd 0x2
	end

Route117_EventScript_001EC45B::
	loadword 0x0, 0x081EC79A
	callstd 0x3
	end

Route117_EventScript_001EC464::
	loadword 0x0, 0x081EC7B3
	callstd 0x3
	end

Route117_EventScript_001EC46D::
	loadword 0x0, 0x081EC7CD
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1ec476, 0x373
