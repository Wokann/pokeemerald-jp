@ Route111 scripts (JP map g0 m26 @ 0x081EA14D)

Route111_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route111_EventScript_001EA162
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_EventScript_001EA22D
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_MapScriptTable_001EA2EC
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_MapScriptTable_001EA2FC
	.byte 0

Route111_EventScript_001EA162::
	checkflag 0xE4
	call_if 0x0, Route111_EventScript_001EA177
	compare_var_to_value 0x40CB, 0x1
	call_if 0x1, Route111_EventScript_001EA18A
	end

Route111_EventScript_001EA177::
	setmetatile 0x1D, 0x56, 0x7C, 0x1
	setmetatile 0x1D, 0x57, 0x91, 0x1
	return

Route111_EventScript_001EA18A::
	setmetatile 0x12, 0x35, 0x3D8, 0x0
	setmetatile 0x13, 0x35, 0x3D9, 0x0
	setmetatile 0x14, 0x35, 0x3DA, 0x0
	setmetatile 0x12, 0x36, 0x3E0, 0x0
	setmetatile 0x13, 0x36, 0x3E1, 0x0
	setmetatile 0x14, 0x36, 0x3E2, 0x0
	setmetatile 0x12, 0x37, 0x3E8, 0x0
	setmetatile 0x13, 0x37, 0x3E9, 0x0
	setmetatile 0x14, 0x37, 0x3EA, 0x0
	setmetatile 0x12, 0x38, 0x3F0, 0x0
	setmetatile 0x13, 0x38, 0x3F1, 0x0
	setmetatile 0x14, 0x38, 0x3F2, 0x0
	setmetatile 0x12, 0x39, 0x3DB, 0x0
	setmetatile 0x13, 0x39, 0x3DC, 0x0
	setmetatile 0x14, 0x39, 0x3DD, 0x0
	setmetatile 0x12, 0x3A, 0x3E3, 0x0
	setmetatile 0x13, 0x3A, 0x3E4, 0x0
	setmetatile 0x14, 0x3A, 0x3E5, 0x0
	return

Route111_EventScript_001EA22D::
	setvar 0x40D6, 0x0
	special SetMirageTowerVisibility
	checkflag 0x14E
	call_if 0x0, Route111_EventScript_001EA2E2
	compare_var_to_value 0x40CB, 0x1
	call_if 0x1, Route111_EventScript_001EA268
	compare_var_to_value 0x40CB, 0x2
	call_if 0x1, Route111_EventScript_001EA2E6
	call Route111_EventScript_001EA28C
	call 0x082540DF
	checktrainerflag 0x138
	goto_if 0x0, Route111_EventScript_001EA2CC
	end

Route111_EventScript_001EA268::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route111_EventScript_001EA280
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route111_EventScript_001EA286
	return

Route111_EventScript_001EA280::
	setvar 0x4010, 0x64
	return

Route111_EventScript_001EA286::
	setvar 0x4010, 0x69
	return

Route111_EventScript_001EA28C::
	getplayerxy 0x4000, 0x4001
	compare_var_to_value 0x4001, 0x22
	goto_if 0x0, Route111_EventScript_001EA2CB
	compare_var_to_value 0x4001, 0x6B
	goto_if 0x2, Route111_EventScript_001EA2CB
	compare_var_to_value 0x4001, 0x48
	goto_if 0x2, Route111_EventScript_001EA2C8
	compare_var_to_value 0x4000, 0x7D0
	goto_if 0x2, Route111_EventScript_001EA2CB
	compare_var_to_value 0x4000, 0x8
	goto_if 0x0, Route111_EventScript_001EA2CB

Route111_EventScript_001EA2C8::
	setweather 0x8

Route111_EventScript_001EA2CB::
	return

Route111_EventScript_001EA2CC::
	clearflag 0x300
	setflag 0x301
	setflag 0x302
	setflag 0x303
	cleartrainerflag 0x124
	cleartrainerflag 0x12B
	cleartrainerflag 0x25E
	end

Route111_EventScript_001EA2E2::
	setmaplayoutindex 0x188
	return

Route111_EventScript_001EA2E6::
	setvar 0x40CB, 0x3
	return

Route111_MapScriptTable_001EA2EC::
	map_script_2 0x40CB, 0x1, Route111_EventScript_001EA2F6
	.2byte 0

Route111_EventScript_001EA2F6::
	hideobject_at 0xFF, 0x9
	end

Route111_MapScriptTable_001EA2FC::
	map_script_2 0x40CB, 0x1, Route111_EventScript_001EA306
	.2byte 0

Route111_EventScript_001EA306::
	lockall
	special StartMirageTowerFossilFallAndSink
	delay 0x18
	playse 0x2B
	addobject 0x2D
	special StartPlayerDescendMirageTower
	showobject_at 0xFF, 0x9
	removeobject 0x2D
	delay 0x10
	turnobject 0xFF, 0x2
	delay 0x10
	special StartMirageTowerDisintegration
	special StartMirageTowerShake
	setvar 0x40CB, 0x2
	clearflag 0x36A
	checkflag 0x150
	goto_if 0x1, Route111_EventScript_001EA34D
	loadword 0x0, gJPText_001EADDB
	callstd 0x4
	releaseall
	end

Route111_EventScript_001EA34D::
	loadword 0x0, gJPText_001EADF3
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1ea357, 0x8
Route111_EventScript_001EA35F::
	lock
	faceplayer
	dotimebasedevents
	checkflag 0x92C
	goto_if 0x1, Route111_EventScript_001EA39A
	loadword 0x0, 0x0826388C
	callstd 0x4
	setorcopyvar 0x8000, 0x94
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x92C
	special GetPlayerBigGuyGirlString
	loadword 0x0, 0x082638C8
	callstd 0x4
	release
	end

Route111_EventScript_001EA39A::
	loadword 0x0, 0x082638F0
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1ea3a4, 0xc
Route111_EventScript_001EA3B0::
	lockall
	setvar 0x8004, 0x1
	goto Route111_EventScript_001EA3D4
	end

Route111_EventScript_001EA3BC::
	lockall
	setvar 0x8004, 0x2
	goto Route111_EventScript_001EA3D4
	end

	.incbin "baserom_jp.gba", 0x1ea3c8, 0xc
Route111_EventScript_001EA3D4::
	checkitem 0x117, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route111_EventScript_001EA3EB
	setvar 0x4003, 0x1
	releaseall
	end

Route111_EventScript_001EA3EB::
	loadword 0x0, 0x08243A64
	callstd 0x4
	closemessage
	compare_var_to_value 0x8004, 0x0
	call_if 0x1, Route111_EventScript_001EA422
	compare_var_to_value 0x8004, 0x1
	call_if 0x1, Route111_EventScript_001EA42D
	compare_var_to_value 0x8004, 0x2
	call_if 0x1, Route111_EventScript_001EA438
	compare_var_to_value 0x8004, 0x3
	call_if 0x1, Route111_EventScript_001EA443
	releaseall
	end

Route111_EventScript_001EA422::
	applymovement 0xFF, 0x081EA44E
	waitmovement 0x0
	return

Route111_EventScript_001EA42D::
	applymovement 0xFF, 0x081EA450
	waitmovement 0x0
	return

Route111_EventScript_001EA438::
	applymovement 0xFF, 0x081EA452
	waitmovement 0x0
	return

Route111_EventScript_001EA443::
	applymovement 0xFF, 0x081EA454
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1ea44e, 0x8
Route111_EventScript_001EA456::
	setweather 0x2
	fadenewbgm 0x168
	resetweather
	setvar 0x4003, 0x0
	end

Route111_EventScript_001EA463::
	setweather 0x8
	fadenewbgm 0x199
	resetweather
	end

Route111_EventScript_001EA46B::
	lock
	faceplayer
	setflag 0x8A3
	loadword 0x0, 0x081EA91B
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x081EA48D
	loadword 0x0, 0x081EA95E
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1ea48d, 0x16c
Route111_EventScript_001EA5F9::
	loadword 0x0, 0x081EABA8
	callstd 0x3
	end

Route111_EventScript_001EA602::
	loadword 0x0, 0x081EABC2
	callstd 0x3
	end

Route111_EventScript_001EA60B::
	loadword 0x0, 0x081EABE5
	callstd 0x3
	end

Route111_EventScript_001EA614::
	loadword 0x0, 0x081EAC01
	callstd 0x3
	end

Route111_EventScript_001EA61D::
	loadword 0x0, 0x081EAC1D
	callstd 0x3
	end

Route111_EventScript_001EA626::
	loadword 0x0, 0x081EAC42
	callstd 0x3
	end

Route111_EventScript_001EA62F::
	loadword 0x0, 0x081EAB21
	callstd 0x2
	end

Route111_EventScript_001EA638::
	loadword 0x0, 0x081EAB71
	callstd 0x2
	end

Route111_EventScript_001EA641::
	lock
	faceplayer
	compare_var_to_value 0x40CB, 0x3
	goto_if 0x1, Route111_EventScript_001EA66C
	compare_var_to_value 0x40CB, 0x2
	goto_if 0x1, Route111_EventScript_001EA676
	checkflag 0x14E
	goto_if 0x1, Route111_EventScript_001EA680
	loadword 0x0, 0x081EAC9B
	callstd 0x4
	release
	end

Route111_EventScript_001EA66C::
	loadword 0x0, 0x081EADB1
	callstd 0x4
	release
	end

Route111_EventScript_001EA676::
	loadword 0x0, 0x081EAD65
	callstd 0x4
	release
	end

Route111_EventScript_001EA680::
	loadword 0x0, 0x081EACF8
	callstd 0x4
	release
	end

Route111_EventScript_001EA68A::
	lockall
	applymovement 0x2E, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x081EAE0C
	callstd 0x4
	closemessage
	applymovement 0x2E, 0x08243625
	waitmovement 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1ea6aa, 0x268
Route111_EventScript_001EA912::
	loadword 0x0, 0x081EAE67
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1ea91b, 0x4c0
	.globl gJPText_001EADDB
gJPText_001EADDB: @ 0x081EADDB
	.string "ツメのかせきは\n"
	.string "すなに　もぐって　しまった⋯⋯$"

	.globl gJPText_001EADF3
gJPText_001EADF3: @ 0x081EADF3
	.string "ねっこのかせきは\n"
	.string "すなに　もぐって　しまった⋯⋯$"

	.incbin "baserom_jp.gba", 0x1eae0c, 0x80
