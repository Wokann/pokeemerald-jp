@ OldaleTown scripts (JP map g0 m10 @ 0x081E4782)

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_EventScript_001E4788
	.byte 0

OldaleTown_EventScript_001E4788::
	call 0x08242F63
	setflag 0x870
	checkflag 0x74
	call_if 0x0, OldaleTown_EventScript_001E47B2
	checkflag 0x84
	call_if 0x0, OldaleTown_EventScript_001E47BE
	checkflag 0x74
	call_if 0x1, OldaleTown_EventScript_001E47AC
	end

OldaleTown_EventScript_001E47AC::
	setvar 0x4051, 0x1
	return

OldaleTown_EventScript_001E47B2::
	setobjectxyperm 0x3, 0x1, 0xB
	setobjectmovementtype 0x3, 0x9
	return

OldaleTown_EventScript_001E47BE::
	setobjectxyperm 0x2, 0xD, 0xE
	setobjectmovementtype 0x2, 0x8
	return

OldaleTown_EventScript_001E47CA::
	loadword 0x0, 0x081E4C38
	callstd 0x3
	end

OldaleTown_EventScript_001E47D3::
	loadword 0x0, 0x081E4A6E
	callstd 0x2
	end

OldaleTown_EventScript_001E47DC::
	lock
	faceplayer
	checkflag 0x84
	goto_if 0x1, OldaleTown_EventScript_001E4899
	checkflag 0x1
	goto_if 0x1, OldaleTown_EventScript_001E4899
	setflag 0x1
	playbgm 0x1A4, 0x0
	loadword 0x0, 0x081E4A8A
	callstd 0x4
	closemessage
	copyvar 0x8000, 0x800C
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, OldaleTown_EventScript_001E4827
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, OldaleTown_EventScript_001E483E
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, OldaleTown_EventScript_001E4855
	end

OldaleTown_EventScript_001E4827::
	applymovement 0x2, 0x081E48B7
	applymovement 0xFF, 0x081E48E1
	waitmovement 0x0
	goto OldaleTown_EventScript_001E486C
	end

OldaleTown_EventScript_001E483E::
	applymovement 0x2, 0x081E48C2
	applymovement 0xFF, 0x081E48EB
	waitmovement 0x0
	goto OldaleTown_EventScript_001E486C
	end

OldaleTown_EventScript_001E4855::
	applymovement 0xFF, 0x081E48D9
	applymovement 0x2, 0x081E48AE
	waitmovement 0x0
	goto OldaleTown_EventScript_001E486C
	end

OldaleTown_EventScript_001E486C::
	loadword 0x0, 0x081E4AB3
	callstd 0x4
	setorcopyvar 0x8000, 0xD
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, OldaleTown_EventScript_001E48A3
	loadword 0x0, 0x081E4B0F
	callstd 0x4
	setflag 0x84
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_001E4899::
	loadword 0x0, 0x081E4B0F
	callstd 0x4
	release
	end

OldaleTown_EventScript_001E48A3::
	loadword 0x0, gJPText_00243977
	callstd 0x4
	fadedefaultbgm
	release
	end

	.incbin "baserom_jp.gba", 0x1e48ae, 0x51
OldaleTown_EventScript_001E48FF::
	lock
	faceplayer
	checkflag 0x74
	goto_if 0x1, OldaleTown_EventScript_001E4946
	loadword 0x0, 0x081E4B8B
	callstd 0x4
	closemessage
	applymovement 0x3, 0x08243625
	waitmovement 0x0
	release
	end

OldaleTown_EventScript_001E491F::
	lockall
	applymovement 0xFF, 0x081E4A62
	applymovement 0x3, 0x081E4A65
	waitmovement 0x0
	loadword 0x0, 0x081E4B44
	callstd 0x4
	closemessage
	applymovement 0x3, 0x081E4A6B
	waitmovement 0x0
	releaseall
	end

OldaleTown_EventScript_001E4946::
	loadword 0x0, 0x081E4BBC
	callstd 0x4
	release
	end

OldaleTown_EventScript_001E4950::
	lockall
	applymovement 0x4, 0x08243621
	waitmovement 0x0
	setvar 0x8009, 0x0
	goto OldaleTown_EventScript_001E49C6
	end

OldaleTown_EventScript_001E4966::
	lockall
	applymovement 0x4, 0x081E4A50
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	setvar 0x8009, 0x1
	goto OldaleTown_EventScript_001E49C6
	end

OldaleTown_EventScript_001E4986::
	lockall
	applymovement 0x4, 0x081E4A53
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	setvar 0x8009, 0x1
	goto OldaleTown_EventScript_001E49C6
	end

OldaleTown_EventScript_001E49A6::
	lockall
	applymovement 0x4, 0x081E4A55
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	setvar 0x8009, 0x1
	goto OldaleTown_EventScript_001E49C6
	end

OldaleTown_EventScript_001E49C6::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, OldaleTown_EventScript_001E49DE
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, OldaleTown_EventScript_001E49EC
	end

OldaleTown_EventScript_001E49DE::
	loadword 0x0, 0x081E4BF3
	callstd 0x4
	goto OldaleTown_EventScript_001E49FA
	end

OldaleTown_EventScript_001E49EC::
	loadword 0x0, 0x081E4C11
	callstd 0x4
	goto OldaleTown_EventScript_001E49FA
	end

OldaleTown_EventScript_001E49FA::
	closemessage
	compare_var_to_value 0x8009, 0x0
	call_if 0x1, OldaleTown_EventScript_001E4A28
	compare_var_to_value 0x8009, 0x1
	call_if 0x1, OldaleTown_EventScript_001E4A3E
	applymovement 0x4, 0x081E4A57
	waitmovement 0x0
	removeobject 0x4
	setvar 0x40C7, 0x2
	setflag 0x3D3
	releaseall
	end

OldaleTown_EventScript_001E4A28::
	compare_var_to_value 0x800C, 0x1
	goto_if 0x5, OldaleTown_EventScript_001E4A3E
	applymovement 0x4, 0x081E4A57
	waitmovement 0x0
	return

OldaleTown_EventScript_001E4A3E::
	applymovement 0xFF, 0x081E4A5E
	applymovement 0x4, 0x081E4A57
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1e4a50, 0x207
