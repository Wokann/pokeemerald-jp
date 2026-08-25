@ FallarborTown_BattleTentLobby scripts (JP map g5 m1 @ 0x081F5185)

FallarborTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentLobby_MapScriptTable_001F51A4
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentLobby_MapScriptTable_001F5190
	.byte 0

FallarborTown_BattleTentLobby_MapScriptTable_001F5190::
	map_script_2 0x4001, 0x0, FallarborTown_BattleTentLobby_EventScript_001F519A
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_001F519A::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

FallarborTown_BattleTentLobby_MapScriptTable_001F51A4::
	map_script_2 0x4000, 0x0, FallarborTown_BattleTentLobby_EventScript_001F51CE
	map_script_2 0x4000, 0x1, FallarborTown_BattleTentLobby_EventScript_001F51D7
	map_script_2 0x4000, 0x2, FallarborTown_BattleTentLobby_EventScript_001F52EC
	map_script_2 0x4000, 0x3, FallarborTown_BattleTentLobby_EventScript_001F520C
	map_script_2 0x4000, 0x4, FallarborTown_BattleTentLobby_EventScript_001F52B2
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_001F51CE::
	setvar 0x8004, 0x0
	special CallFrontierUtilFunc
	end

FallarborTown_BattleTentLobby_EventScript_001F51D7::
	lockall
	loadword 0x0, gJPText_00274DB9
	callstd 0x4
	closemessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_001F520C::
	lockall
	loadword 0x0, gJPText_00274E1B
	callstd 0x4
	message gJPText_00274E34
	waitmessage
	setvar 0x8004, 0x4
	special CallFallarborTentFunction
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallFallarborTentFunction
	playse 0x37
	waitse

FallarborTown_BattleTentLobby_EventScript_001F5246::
	loadword 0x0, gJPText_00274E4A
	callstd 0x4
	setvar 0x8004, 0x5
	special CallFallarborTentFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5292
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	message gJPText_00274E74
	waitmessage
	playfanfare 0x172
	waitfanfare
	loadword 0x0, gJPText_00274ED5
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_001F5292::
	loadword 0x0, gJPText_00274E82
	callstd 0x4
	waitmessage
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_001F52A3::
	lockall
	loadword 0x0, gJPText_00274E1B
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F5246
	end

FallarborTown_BattleTentLobby_EventScript_001F52B2::
	lockall
	message gJPText_00274EB4
	waitmessage
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x8004, 0x3
	setvar 0x8005, 0x0
	special CallFallarborTentFunction
	playse 0x37
	waitse
	loadword 0x0, gJPText_00274ED5
	callstd 0x4
	closemessage
	setvar 0x4000, 0xFF
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_001F52EC::
	lockall
	message gJPText_00274EED
	waitmessage
	setvar 0x8004, 0x3
	setvar 0x8005, 0x1
	special CallFallarborTentFunction
	playse 0x37
	waitse
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	setvar 0x4000, 0xFF
	goto FallarborTown_BattleTentLobby_EventScript_001F545B

FallarborTown_BattleTentLobby_EventScript_001F5320::
	lock
	faceplayer
	setvar 0x8004, 0x1
	special CallFallarborTentFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, FallarborTown_BattleTentLobby_EventScript_001F52A3
	special SavePlayerParty
	loadword 0x0, 0x08274A30
	callstd 0x4

FallarborTown_BattleTentLobby_EventScript_001F5340::
	message 0x08274A71
	waitmessage
	multichoice 0x11, 0x6, 0x17, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F537C
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5488
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54E4
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54E4

FallarborTown_BattleTentLobby_EventScript_001F537C::
	setvar 0x40CF, 0x3
	setvar 0x40CE, 0x0
	setvar 0x800D, 0x2
	setvar 0x8004, 0xF
	special CallFrontierUtilFunc
	compare_var_to_value 0x8004, 0x1
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5495
	setvar 0x8004, 0x2
	setvar 0x8005, 0x1
	setvar 0x8006, 0x2
	special CallFrontierUtilFunc
	loadword 0x0, 0x08274C64
	callstd 0x4
	fadescreen 0x1
	setvar 0x8004, 0x2
	setvar 0x8005, 0x3
	special sub_080F9D20
	waitstate
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54E1
	loadword 0x0, 0x08274C14
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54E1
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5401
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54E1

FallarborTown_BattleTentLobby_EventScript_001F5401::
	setvar 0x4000, 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x0
	special CallFallarborTentFunction
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
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54CA

FallarborTown_BattleTentLobby_EventScript_001F545B::
	special SavePlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	loadword 0x0, gJPText_00274DA3
	callstd 0x4
	closemessage
	call FallarborTown_BattleTentLobby_EventScript_001F54EE
	warp 0x502, 0xFF, 0x2, 0x7
	setvar 0x4000, 0x0
	waitstate
	end

FallarborTown_BattleTentLobby_EventScript_001F5488::
	loadword 0x0, 0x08274AA3
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F5340

FallarborTown_BattleTentLobby_EventScript_001F5495::
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54B0
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F54BD

FallarborTown_BattleTentLobby_EventScript_001F54B0::
	loadword 0x0, 0x08274C84
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F54EC

FallarborTown_BattleTentLobby_EventScript_001F54BD::
	loadword 0x0, 0x08274CFD
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F54EC

FallarborTown_BattleTentLobby_EventScript_001F54CA::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x0
	special CallFrontierUtilFunc
	goto FallarborTown_BattleTentLobby_EventScript_001F54E4

FallarborTown_BattleTentLobby_EventScript_001F54E1::
	special LoadPlayerParty

FallarborTown_BattleTentLobby_EventScript_001F54E4::
	loadword 0x0, 0x08274A8B
	callstd 0x4

FallarborTown_BattleTentLobby_EventScript_001F54EC::
	release
	end

FallarborTown_BattleTentLobby_EventScript_001F54EE::
	applymovement LOCALID_FALLARBOR_TENT_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor
	waitmovement 0x0
	opendoor 0x6, 0x1
	waitmoncry
	applymovement LOCALID_FALLARBOR_TENT_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0x0
	closedoor 0x6, 0x1
	waitmoncry
	return

FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

FallarborTown_BattleTentLobby_EventScript_001F552C::
	msgbox FallarborTown_BattleTentLobby_Text_CameToCampOut, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_001F5535::
	msgbox FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_001F553E::
	msgbox FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite, MSGBOX_NPC
	end

FallarborTown_BattleTentLobby_EventScript_001F5547::
	lock
	faceplayer
	checkflag 0x1CD
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5564
	msgbox FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone, MSGBOX_DEFAULT
	addvar 0x40D1, 0x1
	setflag 0x1CD
	release
	end

FallarborTown_BattleTentLobby_EventScript_001F5564::
	msgbox FallarborTown_BattleTentLobby_Text_ScottMakeChallenge, MSGBOX_DEFAULT
	release
	end

FallarborTown_BattleTentLobby_EventScript_001F556E::
	lockall
	loadword 0x0, 0x0822FD87
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F557D
	end

FallarborTown_BattleTentLobby_EventScript_001F557D::
	message 0x0822FDA0
	waitmessage
	multichoice 0x11, 0x0, 0x70, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F55DB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F55E9
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F55F7
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5605
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5613
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5621
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, FallarborTown_BattleTentLobby_EventScript_001F5621
	end

FallarborTown_BattleTentLobby_EventScript_001F55DB::
	loadword 0x0, 0x08275BCD
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F557D
	end

FallarborTown_BattleTentLobby_EventScript_001F55E9::
	loadword 0x0, 0x0822FDB0
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F557D
	end

FallarborTown_BattleTentLobby_EventScript_001F55F7::
	loadword 0x0, 0x0822FE72
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F557D
	end

FallarborTown_BattleTentLobby_EventScript_001F5605::
	loadword 0x0, 0x0822FECB
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F557D
	end

FallarborTown_BattleTentLobby_EventScript_001F5613::
	loadword 0x0, 0x0822FFB6
	callstd 0x4
	goto FallarborTown_BattleTentLobby_EventScript_001F557D
	end

FallarborTown_BattleTentLobby_EventScript_001F5621::
	releaseall
	end

FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid: @ 0x081F5623
	.string "ふふふふふふ\p"
	.string "ほんの　こどもだと　おもわせて\n"
	.string "みんなを　ゆだん　させて\l"
	.string "ボクは　ゆうしょう　するのだ！$"

FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite: @ 0x081F5657
	.string "バトルテントって　まちに　よって\n"
	.string "ちょうせん　できる　ことが　ちがうでしょ？\l"
	.string "あたしは　だんぜん　ハジツゲの\l"
	.string "バトルテントが　すきなのよね！\p"
	.string "しんじてる　ポケモンたちと　かちぬくって\n"
	.string "すごく　かっこいいじゃない？$"

FallarborTown_BattleTentLobby_Text_CameToCampOut: @ 0x081F56C2
	.string "テントというから　キャンプ　しにきたら⋯\p"
	.string "さいきんの　テント　というのは\n"
	.string "ごうかな　もん　だなあ\l"
	.string "よし　ついでに　ちょうせん　してみるか？$"

FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone: @ 0x081F5708
	.string "エニシダ“やあ　{PLAYER}{KUN}\n"
	.string "きたんだね　バトルテントに！\p"
	.string "どうも　この　ちほうは\n"
	.string "ノンビリ　した　ひとが　おおくてね\l"
	.string "もっと　こう⋯⋯\l"
	.string "かちたい　パワーの　ありまくりな\l"
	.string "ひとを　わたしは　もとめて　いるんだよ！\l"
	.string "そういう　トレーナーが　いれば　すぐにでも\p"
	.string "⋯⋯って　いや　なんでもないよ\n"
	.string "じゃ　がんばってね！$"

FallarborTown_BattleTentLobby_Text_ScottMakeChallenge: @ 0x081F57A2
	.string "エニシダ“わたし　なんかに\n"
	.string "いつまでも　かまって　いないで\l"
	.string "さっそく　チャレンジ\l"
	.string "して　みたら　どうだい？$"
