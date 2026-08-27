	lockall
	dofieldeffect 0x25
	waitstate
	goto 0x82566D1
	end
	applymovement 0x800F, 0x8256701
	waitmovement 0x0
	removeobject 0x800F
	specialvar 0x800D, TryUpdateRusturfTunnelState
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x82566FF
	special RockSmashWildEncounter
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82566FF
	waitstate
	releaseall
	end
	releaseall
	end
	faceplayer
	.byte 0xFE
	loadword 0x0, 0x8256733
	callstd 0x4
	releaseall
	end
	closemessage
	releaseall
	end
	setrespawn 0x7359
	bufferleadmonspeciesname 0x19
	nop
	.incbin "baserom_jp.gba", 0x256716, 0x3e

EventScript_StrengthBoulder:: @ 0x08256754
	.incbin "baserom_jp.gba", 0x256754, 0x43
