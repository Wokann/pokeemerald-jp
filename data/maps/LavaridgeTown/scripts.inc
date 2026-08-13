@ LavaridgeTown scripts (JP map g0 m12 @ 0x081E5662)

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_EventScript_001E566D
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_MapScriptTable_001E56D6
	.byte 0

LavaridgeTown_EventScript_001E566D::
	setflag 0x872
	checkflag 0x6C
	call_if 0x1, LavaridgeTown_EventScript_001E56A3
	checkflag 0x8B
	call_if 0x1, LavaridgeTown_EventScript_001E56CE
	call 0x08242F63
	call 0x08242F87
	compare_var_to_value 0x4053, 0x1
	call_if 0x1, LavaridgeTown_EventScript_001E56A7
	compare_var_to_value 0x4053, 0x1
	call_if 0x1, LavaridgeTown_EventScript_001E56D2
	end

LavaridgeTown_EventScript_001E56A3::
	clearflag 0x6C
	return

LavaridgeTown_EventScript_001E56A7::
	getplayerxy 0x8004, 0x8005
	compare_var_to_value 0x8004, 0x9
	goto_if 0x1, LavaridgeTown_EventScript_001E56B8
	return

LavaridgeTown_EventScript_001E56B8::
	setobjectxyperm 0x8, 0xB, 0x9
	setobjectxyperm 0x7, 0x9, 0x8
	setobjectmovementtype 0x7, 0x7
	clearflag 0x3A1
	return

LavaridgeTown_EventScript_001E56CE::
	clearflag 0x36D
	return

LavaridgeTown_EventScript_001E56D2::
	setflag 0x4000
	return

LavaridgeTown_MapScriptTable_001E56D6::
	map_script_2 0x4053, 0x1, LavaridgeTown_EventScript_001E56E0
	.2byte 0

LavaridgeTown_EventScript_001E56E0::
	lockall
	getplayerxy 0x8008, 0x8009
	compare_var_to_value 0x8008, 0x9
	call_if 0x1, LavaridgeTown_EventScript_001E57C9
	compare_var_to_value 0x8008, 0x9
	call_if 0x5, LavaridgeTown_EventScript_001E57EB
	delay 0x14
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LavaridgeTown_EventScript_001E57BF
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LavaridgeTown_EventScript_001E57C4
	compare_var_to_value 0x8008, 0x9
	call_if 0x1, LavaridgeTown_EventScript_001E5830
	compare_var_to_value 0x8008, 0x9
	call_if 0x5, LavaridgeTown_EventScript_001E583B
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LavaridgeTown_EventScript_001E5744
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LavaridgeTown_EventScript_001E5769
	end

LavaridgeTown_EventScript_001E5744::
	loadword 0x0, gJPText_001E594F
	callstd 0x4
	setorcopyvar 0x8000, 0x117
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0xDD
	loadword 0x0, gJPText_001E59CC
	callstd 0x4
	goto LavaridgeTown_EventScript_001E578E
	end

LavaridgeTown_EventScript_001E5769::
	loadword 0x0, gJPText_001E5A74
	callstd 0x4
	setorcopyvar 0x8000, 0x117
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0xDD
	loadword 0x0, gJPText_001E5AB6
	callstd 0x4
	goto LavaridgeTown_EventScript_001E578E
	end

LavaridgeTown_EventScript_001E578E::
	closemessage
	removeobject 0x8
	addobject 0x7
	delay 0x1E
	compare_var_to_value 0x8008, 0x9
	call_if 0x1, LavaridgeTown_EventScript_001E5846
	compare_var_to_value 0x8008, 0x9
	call_if 0x5, LavaridgeTown_EventScript_001E5858
	removeobject 0x7
	setvar 0x4053, 0x2
	clearflag 0x4000
	savebgm 0x0
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_001E57BF::
	playbgm 0x19F, 0x1
	return

LavaridgeTown_EventScript_001E57C4::
	playbgm 0x1A5, 0x1
	return

LavaridgeTown_EventScript_001E57C9::
	applymovement 0x8, 0x08243629
	waitmovement 0x0
	playse 0x15
	applymovement 0x8, 0x0824361B
	waitmovement 0x0
	applymovement 0x8, 0x0824361D
	waitmovement 0x0
	return

LavaridgeTown_EventScript_001E57EB::
	opendoor 0xC, 0xF
	waitmoncry
	addobject 0x8
	applymovement 0x8, 0x081E5887
	waitmovement 0x0
	closedoor 0xC, 0xF
	waitmoncry
	applymovement 0x8, 0x08243627
	waitmovement 0x0
	playse 0x15
	applymovement 0x8, 0x0824361B
	waitmovement 0x0
	applymovement 0x8, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	return

LavaridgeTown_EventScript_001E5830::
	applymovement 0x8, 0x081E5883
	waitmovement 0x0
	return

LavaridgeTown_EventScript_001E583B::
	applymovement 0x8, 0x081E587C
	waitmovement 0x0
	return

LavaridgeTown_EventScript_001E5846::
	applymovement 0xFF, 0x081E586E
	applymovement 0x7, 0x081E5872
	waitmovement 0x0
	return

LavaridgeTown_EventScript_001E5858::
	applymovement 0x7, 0x081E5863
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1e5863, 0x26
LavaridgeTown_EventScript_001E5889::
	specialvar 0x800D, GetPlayerFacingDirection
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LavaridgeTown_EventScript_001E589A
	end

LavaridgeTown_EventScript_001E589A::
	incrementgamestat 0x31
	end

LavaridgeTown_EventScript_001E589D::
	loadword 0x0, 0x081E5C87
	callstd 0x2
	end

LavaridgeTown_EventScript_001E58A6::
	loadword 0x0, 0x081E5CE8
	callstd 0x3
	end

LavaridgeTown_EventScript_001E58AF::
	loadword 0x0, 0x081E5D53
	callstd 0x2
	end

LavaridgeTown_EventScript_001E58B8::
	loadword 0x0, 0x081E5D8B
	callstd 0x2
	end

LavaridgeTown_EventScript_001E58C1::
	loadword 0x0, 0x081E5DBF
	callstd 0x2
	end

LavaridgeTown_EventScript_001E58CA::
	loadword 0x0, 0x081E5D2A
	callstd 0x2
	end

LavaridgeTown_EventScript_001E58D3::
	lock
	faceplayer
	checkflag 0x10A
	goto_if 0x1, LavaridgeTown_EventScript_001E5916
	loadword 0x0, 0x081E5B4B
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LavaridgeTown_EventScript_001E592A
	getpartysize
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, LavaridgeTown_EventScript_001E5920
	loadword 0x0, 0x081E5BE6
	callstd 0x4
	setflag 0x10A
	playfanfare 0x172
	message 0x081E5C01
	waitfanfare
	giveegg 0x168
	release
	end

LavaridgeTown_EventScript_001E5916::
	loadword 0x0, 0x081E5C5A
	callstd 0x4
	release
	end

LavaridgeTown_EventScript_001E5920::
	loadword 0x0, 0x081E5C10
	callstd 0x4
	release
	end

LavaridgeTown_EventScript_001E592A::
	loadword 0x0, 0x081E5C31
	callstd 0x4
	release
	end

LavaridgeTown_EventScript_001E5934::
	loadword 0x0, 0x081E5DFF
	callstd 0x3
	end

LavaridgeTown_EventScript_001E593D::
	loadword 0x0, 0x081E5E1B
	callstd 0x3
	end

LavaridgeTown_EventScript_001E5946::
	loadword 0x0, 0x081E5E46
	callstd 0x3
	end

	.globl gJPText_001E594F
gJPText_001E594F: @ 0x081E594F
	.string "ハルカ“{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！　ひさしぶり！\p"
	.string "あら？　あたしが　おんせんに\n"
	.string "はいったり　してる　あいだに\l"
	.string "フエンの　ジムバッジ　てに　いれたんだ！\p"
	.string "かなり　ポケモン　あつめてる　っていうか\n"
	.string "そだてて　いるんだね！\p"
	.string "じゃあ　これを　あげても\n"
	.string "だいじょうぶ　だよね$"

	.globl gJPText_001E59CC
gJPText_001E59CC: @ 0x081E59CC
	.string "ハルカ“その　ゴーゴーゴーグルが　あると\n"
	.string "111ばん　どうろの　さばくにも\l"
	.string "はいれるように　なるんだよ！\p"
	.string "それにしても　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}\n"
	.string "ポケモンジムに　ちょうせん　だなんて⋯⋯\p"
	.string "あたしに　まけたくない　からって\n"
	.string "がんばって　いるのね！\p"
	.string "じゃあ　あたし　トウカで　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}の\n"
	.string "おとうさんに　ちょうせん　しようかな？\p"
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}　じゃあ　またね！$"

	.globl gJPText_001E5A74
gJPText_001E5A74: @ 0x081E5A74
	.string "ユウキ“{MUS_RG_VS_TRAINER}　ひさしぶり　だな\n"
	.string "ちょうしは　どう？\p"
	.string "ふうん⋯⋯\n"
	.string "バッジは　けっこう　あつめてるんだな\p"
	.string "じゃ\n"
	.string "こいつを　やろうかな？$"

	.globl gJPText_001E5AB6
gJPText_001E5AB6: @ 0x081E5AB6
	.string "ユウキ“それを　もっていれば\n"
	.string "111ばん　どうろの　さばくに　はいれるよ\p"
	.string "さばくにしか　いない\n"
	.string "ポケモンも　いるはず　だから\l"
	.string "よかったら　いけば⋯⋯？\p"
	.string "オレは⋯⋯\n"
	.string "トウカの　ジムリーダー　センリさんに\l"
	.string "ちょうせん　してみようかな⋯⋯\p"
	.string "{MUS_RG_VS_TRAINER}の　とうさん\n"
	.string "{MUS_RG_VS_TRAINER}と　ちがって　つよそうだからな\p"
	.string "じゃな！$"

	.incbin "baserom_jp.gba", 0x1e5b4b, 0x318
