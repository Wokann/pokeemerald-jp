@ BattleFrontier_OutsideEast scripts (JP map g26 m14 @ 0x082229A1)

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_EventScript_002229AC
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_EventScript_002229CA
	.byte 0

BattleFrontier_OutsideEast_EventScript_002229AC::
	checkflag 0x8C1
	call_if 0x1, BattleFrontier_OutsideEast_EventScript_002229B6
	end

BattleFrontier_OutsideEast_EventScript_002229B6::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

BattleFrontier_OutsideEast_EventScript_002229CA::
	setvar 0x40BC, 0x0
	setflag 0x396
	checkflag 0x1C6
	call_if 0x0, BattleFrontier_OutsideEast_EventScript_002229DC
	end

BattleFrontier_OutsideEast_EventScript_002229DC::
	clearflag 0x34A
	return

BattleFrontier_OutsideEast_EventScript_002229E0::
	loadword 0x0, 0x08222BAD
	callstd 0x3
	end

BattleFrontier_OutsideEast_EventScript_002229E9::
	loadword 0x0, 0x08222BCC
	callstd 0x3
	end

BattleFrontier_OutsideEast_EventScript_002229F2::
	loadword 0x0, 0x08222BE7
	callstd 0x3
	end

BattleFrontier_OutsideEast_EventScript_002229FB::
	loadword 0x0, 0x08222C04
	callstd 0x3
	end

BattleFrontier_OutsideEast_EventScript_00222A04::
	loadword 0x0, 0x08222C70
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A0D::
	loadword 0x0, 0x08222C98
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A16::
	loadword 0x0, 0x08222D08
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A1F::
	loadword 0x0, 0x08222D54
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A28::
	loadword 0x0, 0x08222DB2
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A31::
	lock
	loadword 0x0, 0x08222E60
	callstd 0x4
	release
	end

BattleFrontier_OutsideEast_EventScript_00222A3C::
	lock
	faceplayer
	waitse
	playmoncry 0x120, 0x0
	loadword 0x0, 0x08222E98
	callstd 0x4
	waitdooranim
	release
	end

BattleFrontier_OutsideEast_EventScript_00222A4F::
	loadword 0x0, 0x08222EAA
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A58::
	loadword 0x0, 0x08222F21
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A61::
	loadword 0x0, 0x08222F59
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A6A::
	loadword 0x0, 0x08222F8E
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A73::
	lock
	loadword 0x0, 0x08222FAB
	callstd 0x4
	release
	end

BattleFrontier_OutsideEast_EventScript_00222A7E::
	loadword 0x0, 0x08222DF5
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222A87::
	lock
	faceplayer
	waitse
	playse 0x10D
	applymovement 0xE, 0x08222B05
	waitmovement 0x0
	release
	end

gUnknown_8222A99:: @ 0x08222A99
	.incbin "baserom_jp.gba", 0x222a99, 0x7c
BattleFrontier_OutsideEast_EventScript_00222B15::
	loadword 0x0, 0x08222FD8
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B1E::
	loadword 0x0, 0x08223031
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B27::
	loadword 0x0, 0x08223080
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B30::
	loadword 0x0, 0x0822312B
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B39::
	loadword 0x0, 0x08223181
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B42::
	loadword 0x0, 0x082231DF
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B4B::
	loadword 0x0, 0x08223210
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B54::
	lock
	loadword 0x0, 0x0822325E
	callstd 0x4
	release
	end

BattleFrontier_OutsideEast_EventScript_00222B5F::
	lock
	loadword 0x0, 0x08223282
	callstd 0x4
	release
	end

BattleFrontier_OutsideEast_EventScript_00222B6A::
	loadword 0x0, 0x08222C23
	callstd 0x3
	end

BattleFrontier_OutsideEast_EventScript_00222B73::
	loadword 0x0, 0x08222C46
	callstd 0x3
	end

BattleFrontier_OutsideEast_EventScript_00222B7C::
	loadword 0x0, 0x08223312
	callstd 0x2
	end

BattleFrontier_OutsideEast_EventScript_00222B85::
	lock
	faceplayer
	checkflag 0x1C6
	goto_if 0x1, BattleFrontier_OutsideEast_EventScript_00222B9A
	loadword 0x0, 0x08223389
	callstd 0x4
	release
	end

BattleFrontier_OutsideEast_EventScript_00222B9A::
	loadword 0x0, 0x082233CD
	callstd 0x4
	release
	end

BattleFrontier_OutsideEast_EventScript_00222BA4::
	loadword 0x0, 0x08223411
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x222bad, 0x8c8
