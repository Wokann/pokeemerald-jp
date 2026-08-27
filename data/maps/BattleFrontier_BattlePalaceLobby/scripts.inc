@ BattleFrontier_BattlePalaceLobby scripts (JP map g26 m22 @ 0x08229D56)

BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_MapScriptTable_00229D75
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_MapScriptTable_00229D61
	.byte 0

BattleFrontier_BattlePalaceLobby_MapScriptTable_00229D61::
	map_script_2 0x4001, 0x0, BattleFrontier_BattlePalaceLobby_EventScript_00229D6B
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_00229D6B::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattlePalaceLobby_MapScriptTable_00229D75::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePalaceLobby_EventScript_00229D9F
	map_script_2 0x4000, 0x1, BattleFrontier_BattlePalaceLobby_EventScript_00229DA8
	map_script_2 0x4000, 0x2, BattleFrontier_BattlePalaceLobby_EventScript_00229EE0
	map_script_2 0x4000, 0x3, BattleFrontier_BattlePalaceLobby_EventScript_00229DEF
	map_script_2 0x4000, 0x4, BattleFrontier_BattlePalaceLobby_EventScript_00229E4B
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_00229D9F::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

BattleFrontier_BattlePalaceLobby_EventScript_00229DA8::
	lockall
	loadword 0x0, gJPText_0022A7B5
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallBattlePalaceFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattlePalaceFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_00229DEF::
	lockall
	setvar 0x8004, 0xA
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_00229E10
	loadword 0x0, gJPText_0022A6FB
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_00229E18

BattleFrontier_BattlePalaceLobby_EventScript_00229E10::
	loadword 0x0, gJPText_0022ABCE
	callstd 0x4

BattleFrontier_BattlePalaceLobby_EventScript_00229E18::
	loadword 0x0, gJPText_0022ABEF
	callstd 0x4
	setvar 0x8004, 0xB
	special CallFrontierUtilFunc
	loadword 0x0, BattleFrontier_Text_ObtainedXBattlePoints
	callstd 0x9
	message gJPText_0022A72D
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_00229E79
	loadword 0x0, gJPText_0022A4E9
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_00229E4B::
	lockall
	message gJPText_0022A6CC
	waitmessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallBattlePalaceFunction
	call BattleFrontier_BattlePalaceLobby_EventScript_00229E79
	loadword 0x0, gJPText_0022A4E9
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_00229E79::
	setvar 0x8004, 0x8
	special CallFrontierUtilFunc
	special LoadPlayerParty
	special HealPlayerParty
	setvar 0x8004, 0x7
	setvar 0x8005, 0x0
	special CallBattlePalaceFunction
	playse 0x37
	waitse
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_00229EDF
	message gJPText_0022AC13
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_00229EDF
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_00229EDA
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_00229EDF

BattleFrontier_BattlePalaceLobby_EventScript_00229EDA::
	call 0x0821F8F5

BattleFrontier_BattlePalaceLobby_EventScript_00229EDF::
	return

BattleFrontier_BattlePalaceLobby_EventScript_00229EE0::
	lockall
	loadword 0x0, gJPText_0022A790
	callstd 0x4
	message gJPText_0022A79A
	waitmessage
	setvar 0x8004, 0x7
	setvar 0x8005, 0x1
	special CallBattlePalaceFunction
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A0CB

BattleFrontier_BattlePalaceLobby_EventScript_00229F1C::
	lock
	faceplayer
	setvar 0x40CF, 0x2
	setvar 0x40CE, 0x0
	goto BattleFrontier_BattlePalaceLobby_EventScript_00229F40
	end

BattleFrontier_BattlePalaceLobby_EventScript_00229F2E::
	lock
	faceplayer
	setvar 0x40CF, 0x2
	setvar 0x40CE, 0x1
	goto BattleFrontier_BattlePalaceLobby_EventScript_00229F40
	end

BattleFrontier_BattlePalaceLobby_EventScript_00229F40::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x0
	special CallBattlePalaceFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, BattleFrontier_BattlePalaceLobby_EventScript_00229DEF
	special SavePlayerParty
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A176
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A17F

BattleFrontier_BattlePalaceLobby_EventScript_00229F71::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A188
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A18E
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_00229FBE
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A0F8
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A16C
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A16C

BattleFrontier_BattlePalaceLobby_EventScript_00229FBE::
	message 0x0822A50A
	waitmessage
	multichoice 0x11, 0x6, 0x18, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A16C
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A16C
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A11D
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	copyvar 0x8006, 0x800D
	special CallFrontierUtilFunc
	loadword 0x0, 0x0822A67F
	callstd 0x4
	fadescreen 0x1
	call 0x082202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A169
	loadword 0x0, 0x0822A69B
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A169
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A05F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A169

BattleFrontier_BattlePalaceLobby_EventScript_0022A05F::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x0
	special CallBattlePalaceFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special CallBattlePalaceFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	special LoadPlayerParty
	closemessage
	delay 0x2
	call 0x082423E9
	setvar 0x4000, 0xFF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A152

BattleFrontier_BattlePalaceLobby_EventScript_0022A0CB::
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_0022A6BB
	callstd 0x4
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_0022A194
	warp 0x1A17, 0xFF, 0x8, 0xD
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A0F8::
	compare_var_to_value 0x40CE, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A110
	loadword 0x0, 0x0822A391
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_00229F71

BattleFrontier_BattlePalaceLobby_EventScript_0022A110::
	loadword 0x0, 0x0822AA78
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_00229F71

BattleFrontier_BattlePalaceLobby_EventScript_0022A11D::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A138
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A145

BattleFrontier_BattlePalaceLobby_EventScript_0022A138::
	loadword 0x0, 0x0822A534
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A174

BattleFrontier_BattlePalaceLobby_EventScript_0022A145::
	loadword 0x0, 0x0822A5DF
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A174

BattleFrontier_BattlePalaceLobby_EventScript_0022A152::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A16C

BattleFrontier_BattlePalaceLobby_EventScript_0022A169::
	special LoadPlayerParty

BattleFrontier_BattlePalaceLobby_EventScript_0022A16C::
	loadword 0x0, gJPText_0022A4E9
	callstd 0x4

BattleFrontier_BattlePalaceLobby_EventScript_0022A174::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A176::
	loadword 0x0, 0x0822A333
	callstd 0x4
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A17F::
	loadword 0x0, 0x0822AA1D
	callstd 0x4
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A188::
	message 0x0822A379
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A18E::
	message 0x0822AA61
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A194::
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A1FB
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A201
	applymovement 0x800F, 0x0822A21F
	applymovement 0xFF, 0x0822A21F
	waitmovement 0x0
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A207
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A20D
	waitmoncry
	applymovement 0x800F, 0x0822A221
	applymovement 0xFF, 0x0822A224
	waitmovement 0x0
	compare_var_to_value 0x40CE, 0x0
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A213
	compare_var_to_value 0x40CE, 0x1
	call_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A219
	waitmoncry
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A1FB::
	setvar 0x800F, 0x1
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A201::
	setvar 0x800F, 0x6
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A207::
	opendoor 0x5, 0x4
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A20D::
	opendoor 0x13, 0x4
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A213::
	closedoor 0x5, 0x4
	return

BattleFrontier_BattlePalaceLobby_EventScript_0022A219::
	closedoor 0x13, 0x4
	return

	.incbin "baserom_jp.gba", 0x22a21f, 0x9
BattleFrontier_BattlePalaceLobby_EventScript_0022A228::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x2
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A241::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A25A::
	loadword 0x0, 0x0822A80A
	callstd 0x2
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A263::
	loadword 0x0, 0x0822A8D9
	callstd 0x2
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A26C::
	loadword 0x0, 0x0822A977
	callstd 0x2
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A275::
	loadword 0x0, 0x0822A9D6
	callstd 0x2
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A27E::
	lockall
	loadword 0x0, 0x0822AC3F
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A28D
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A28D::
	message 0x0822AC54
	waitmessage
	multichoice 0x10, 0x0, 0x64, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A2EB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A2F9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A307
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A315
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A323
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A331
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattlePalaceLobby_EventScript_0022A331
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A2EB::
	loadword 0x0, 0x0822AC64
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A28D
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A2F9::
	loadword 0x0, 0x0822ACC9
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A28D
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A307::
	loadword 0x0, 0x0822AD4C
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A28D
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A315::
	loadword 0x0, 0x0822AE0B
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A28D
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A323::
	loadword 0x0, 0x0822AEA7
	callstd 0x4
	goto BattleFrontier_BattlePalaceLobby_EventScript_0022A28D
	end

BattleFrontier_BattlePalaceLobby_EventScript_0022A331::
	releaseall
	end

	.incbin "baserom_jp.gba", 0x22a333, 0x1b6
	.globl gJPText_0022A4E9
gJPText_0022A4E9: @ 0x0822A4E9
	.string "おのれの　こころと　ポケモンを　きたえたら\n"
	.string "また　くるがよい⋯⋯$"

	.incbin "baserom_jp.gba", 0x22a50a, 0x1b1
	.globl gJPText_0022A6BB
gJPText_0022A6BB: @ 0x0822A6BB
	.string "それでは\n"
	.string "わしに　ついてこい⋯⋯$"

	.globl gJPText_0022A6CC
gJPText_0022A6CC: @ 0x0822A6CC
	.string "よいものを　みせて　もらった\p"
	.string "それでは　せいせきを　レポートに　かくぞ\n"
	.string "しばし　またれよ⋯⋯$"

	.globl gJPText_0022A6FB
gJPText_0022A6FB: @ 0x0822A6FB
	.string "7にんぬき　たっせい　とは⋯⋯\p"
	.string "おぬしと　ポケモンの　こころの　きずなは\n"
	.string "まことの　ようじゃな⋯⋯$"

	.globl gJPText_0022A72D
gJPText_0022A72D: @ 0x0822A72D
	.string "せいせきを　レポートに　かくぞ\n"
	.string "しばし　またれよ⋯⋯$"

	.incbin "baserom_jp.gba", 0x22a748, 0x1e
	.globl gJPText_0022A766
gJPText_0022A766: @ 0x0822A766
	.string "どうぐが　いっぱいの　ようだな⋯⋯\p"
	.string "どうぐを　せいりしてから\n"
	.string "また　くるがよい⋯⋯$"

	.globl gJPText_0022A790
gJPText_0022A790: @ 0x0822A790
	.string "まっておったぞ⋯⋯$"

	.globl gJPText_0022A79A
gJPText_0022A79A: @ 0x0822A79A
	.string "バトルホールへ　むかうまえに\n"
	.string "レポートを　かくぞ⋯⋯$"

	.globl gJPText_0022A7B5
gJPText_0022A7B5: @ 0x0822A7B5
	.string "おぬし⋯⋯\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しなかったな？\p"
	.string "ざんねんだが　そのばあい\n"
	.string "ちょうせんは　むこうと　なる⋯⋯$"

	.incbin "baserom_jp.gba", 0x22a7fc, 0x3d2
	.globl gJPText_0022ABCE
gJPText_0022ABCE: @ 0x0822ABCE
	.string "パレスガーディアンを　たおし\n"
	.string "7にんぬきを　たっせいするとは⋯⋯$"

	.globl gJPText_0022ABEF
gJPText_0022ABEF: @ 0x0822ABEF
	.string "おぬしと　ポケモンの　きずなを　たたえ\n"
	.string "バトルポイントを　おくろう⋯⋯$"

	.globl gJPText_0022AC13
gJPText_0022AC13: @ 0x0822AC13
	.string "バトルパレスで\n"
	.string "さいごに　おこなった　たたかいを\l"
	.string "フロンティアパスに　きろく　するか？$"
