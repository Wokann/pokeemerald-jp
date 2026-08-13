@ BattleFrontier_BattleTowerMultiBattleRoom scripts (JP map g26 m17 @ 0x0822659E)

BattleFrontier_BattleTowerMultiBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265AE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScriptTable_002265E9
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_MapScriptTable_002265F9
	.byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265AE::
	compare_var_to_value 0x40CE, 0x2
	call_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265C5
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265E5
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265C5::
	setvar 0x8004, 0xE
	special sub_08161E88
	checkplayergender
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265DF
	setvar 0x401F, 0x0
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265DF::
	setvar 0x401F, 0x59
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265E5::
	special sub_0813A774
	return

BattleFrontier_BattleTowerMultiBattleRoom_MapScriptTable_002265E9::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265F3
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002265F3::
	hideobject_at 0xFF, 0x1A11
	end

BattleFrontier_BattleTowerMultiBattleRoom_MapScriptTable_002265F9::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226603
	.2byte 0

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226603::
	setvar 0x4000, 0x1
	applymovement 0x5, 0x08226BCE
	applymovement 0x6, 0x08226BD4
	waitmovement 0x0
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_0022666A
	applymovement 0x2, 0x08226BF4
	applymovement 0x3, 0x08226BF4
	waitmovement 0x0
	applymovement 0x5, 0x08226BDA
	applymovement 0x6, 0x08226BDA
	waitmovement 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_0022666A::
	setvar 0x8004, 0x3
	special sub_08161E88
	addobject 0x1
	addobject 0x4
	applymovement 0x1, 0x08226BDE
	applymovement 0x4, 0x08226BE4
	waitmovement 0x0
	compare_var_to_value 0x40CE, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002266DC
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special sub_08161E88
	delay 0xF
	applymovement 0x1, 0x08226BFB
	waitmovement 0x0
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	setvar 0x8004, 0x7
	setvar 0x8005, 0x1
	special sub_08161E88
	applymovement 0x4, 0x08226BFB
	waitmovement 0x0
	loadword 0x0, 0x2021C7C
	callstd 0x4
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_0022671F

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002266DC::
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special sub_08161E88
	delay 0xF
	applymovement 0x1, 0x08226BFB
	waitmovement 0x0
	messageautoscroll 0x2021C7C
	waitmessage
	delay 0x30
	setvar 0x8004, 0x7
	setvar 0x8005, 0x1
	special sub_08161E88
	applymovement 0x4, 0x08226BFB
	waitmovement 0x0
	messageautoscroll 0x2021C7C
	waitmessage
	delay 0x30

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_0022671F::
	call 0x08222207
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226760

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226734::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special sub_08161E88
	setvar 0x8004, 0x3
	special sub_0813BFA0
	goto 0x082222AC

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226760::
	call 0x08221FB3
	setvar 0x8004, 0x4
	special sub_08161E88
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226965
	applymovement 0x4, 0x08226BEA
	applymovement 0x1, 0x08226BEF
	waitmovement 0x0
	removeobject 0x1
	removeobject 0x4
	applymovement 0x2, 0x08226BF4
	applymovement 0x3, 0x08226BF4
	waitmovement 0x0
	applymovement 0x5, 0x08226BDA
	applymovement 0x6, 0x08226BDA
	waitmovement 0x0
	compare_var_to_value 0x40CE, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267CE
	loadword 0x0, gJPText_0022230B
	callstd 0x4
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267D7

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267CE::
	messageautoscroll 0x0822230B
	waitmessage
	delay 0x30

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267D7::
	special LoadPlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	compare_var_to_value 0x40CE, 0x3
	call_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226BCA
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002269B3
	compare_var_to_value 0x40CE, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226939
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226867
	multichoice 0x13, 0x4, 0x67, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226939
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_0022689D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002268D9
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226907
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226867::
	multichoice 0x14, 0x6, 0x68, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226939
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002268D9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226907
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_0022689D::
	message gJPText_002223F2
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002268CF
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002268CF::
	call 0x0821F8F5
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002268D9::
	loadword 0x0, gJPText_0022242F
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226991
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226907::
	message gJPText_00222464
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226734
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226939::
	closemessage
	clearflag 0x2
	applymovement 0x5, 0x08226BDC
	applymovement 0x6, 0x08226BDC
	waitmovement 0x0
	applymovement 0x2, 0x08226BF7
	applymovement 0x3, 0x08226BF7
	waitmovement 0x0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_0022666A
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226965::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special sub_08161E88
	setvar 0x8004, 0x3
	special sub_0813BFA0
	goto 0x082222AC

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226991::
	message gJPText_00222446
	waitmessage
	setvar 0x8004, 0x6
	setvar 0x8005, 0x2
	special sub_08161E88
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002269B3::
	compare_var_to_value 0x40CE, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A34
	copyvar 0x400F, 0x800D
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A0A
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A11
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A18
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A1F
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A26
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A2D

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A0A::
	message gJPText_00226BFD
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A11::
	message gJPText_00226C1A
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A18::
	message gJPText_00226C37
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A1F::
	message gJPText_00226C54
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A26::
	message gJPText_00226C71
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A2D::
	message gJPText_00226C8E
	waitmessage
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A34::
	copyvar 0x400F, 0x800D
	copyvar 0x8000, 0x400F
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A80
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A8C
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A98
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226AA4
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226AB0
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ABC

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A80::
	message gJPText_00226BFD
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ACD
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A8C::
	message gJPText_00226C1A
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ACD
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226A98::
	message gJPText_00226C37
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ACD
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226AA4::
	message gJPText_00226C54
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ACD
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226AB0::
	message gJPText_00226C71
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ACD
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ABC::
	message gJPText_00226C8E
	waitmessage
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ACD
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226AC8::
	waitmessage
	delay 0x30
	return

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226ACD::
	checkflag 0x2
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B0D
	multichoice 0x13, 0x6, 0x69, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B39
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B5E
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B93
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B93
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B0D::
	multichoice 0x14, 0x8, 0x6A, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B39
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B93
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B93
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B39::
	setvar 0x8004, 0x0
	setvar 0x8005, 0x0
	message gJPText_00226D53
	waitmessage
	special sub_0813B5A0
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226734
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226AC8
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B5E::
	message gJPText_002223F2
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9
	call 0x0821F8F5
	setflag 0x2
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226B93::
	message gJPText_00222464
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226BB0
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_002267F9
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226BB0::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x0
	message gJPText_00226D53
	waitmessage
	special sub_0813B5A0
	waitstate
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226734
	end

BattleFrontier_BattleTowerMultiBattleRoom_EventScript_00226BCA::
	special sub_0813B56C
	return

	.incbin "baserom_jp.gba", 0x226bce, 0x2f
	.globl gJPText_00226BFD
gJPText_00226BFD: @ 0x08226BFD
	.string "つぎは　2くみめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_00226C1A
gJPText_00226C1A: @ 0x08226C1A
	.string "つぎは　3くみめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_00226C37
gJPText_00226C37: @ 0x08226C37
	.string "つぎは　4くみめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_00226C54
gJPText_00226C54: @ 0x08226C54
	.string "つぎは　5くみめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_00226C71
gJPText_00226C71: @ 0x08226C71
	.string "つぎは　6くみめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.globl gJPText_00226C8E
gJPText_00226C8E: @ 0x08226C8E
	.string "つぎは　7くみめの　あいてです\n"
	.string "じゅんびは　いいですか？$"

	.incbin "baserom_jp.gba", 0x226cab, 0xa8
	.globl gJPText_00226D53
gJPText_00226D53: @ 0x08226D53
	.globl gUnknown_8226D53
gUnknown_8226D53:
	.string "つうしん　たいきちゅう⋯⋯$"

gUnknown_8226D61:: @ 0x08226D61
	.incbin "baserom_jp.gba", 0x226d61, 0x2b
