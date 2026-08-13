@ TrainerHill_Entrance scripts (JP map g26 m60 @ 0x0823B765)

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_EventScript_0023B789
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_EventScript_0023B7D4
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_EventScript_0023B77F
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_EventScript_0023B7E1
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_MapScriptTable_0023B7F7
	.byte 0

TrainerHill_Entrance_EventScript_0023B77F::
	setflag 0x8E2
	getplayerxy 0x400D, 0x800D
	end

	.incbin "baserom_jp.gba", 0x23b788, 0x1
TrainerHill_Entrance_EventScript_0023B789::
	setvar 0x8004, 0x4
	special CallTrainerHillFunction
	setvar 0x4000, 0x0
	setvar 0x8004, 0x9
	special CallTrainerHillFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B7B8
	setobjectxy 0xFF, 0x9, 0x6
	applymovement 0xFF, 0x0823B9ED
	end

TrainerHill_Entrance_EventScript_0023B7B8::
	setvar 0x8004, 0x10
	special CallTrainerHillFunction
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B7D3
	applymovement 0xFF, 0x0823B9ED
	end

TrainerHill_Entrance_EventScript_0023B7D3::
	end

TrainerHill_Entrance_EventScript_0023B7D4::
	addobject 0x2
	addobject 0x1
	addobject 0x5
	addobject 0x4
	end

TrainerHill_Entrance_EventScript_0023B7E1::
	compare_var_to_value 0x400D, 0x11
	call_if 0x1, TrainerHill_Entrance_EventScript_0023B7ED
	end

TrainerHill_Entrance_EventScript_0023B7ED::
	setmetatile 0x11, 0xA, 0x307, 0x0
	return

TrainerHill_Entrance_MapScriptTable_0023B7F7::
	map_script_2 0x4000, 0x0, TrainerHill_Entrance_EventScript_0023B83B
	map_script_2 0x400D, 0x11, TrainerHill_Entrance_EventScript_0023B819
	map_script_2 0x4005, 0x1, TrainerHill_Entrance_EventScript_0023B8E2
	map_script_2 0x4001, 0x1, 0x08276CFB
	.2byte 0

TrainerHill_Entrance_EventScript_0023B819::
	lockall
	applymovement 0xFF, 0x0823B9F3
	waitmovement 0x0
	setmetatile 0x11, 0xA, 0x334, 0x1
	special DrawWholeMapView
	playse 0x24
	waitse
	setvar 0x400D, 0x0
	releaseall
	end

TrainerHill_Entrance_EventScript_0023B83B::
	setvar 0x4000, 0x1
	setvar 0x8004, 0x6
	special CallTrainerHillFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B86E
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B883
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B8A7

TrainerHill_Entrance_EventScript_0023B86E::
	lockall
	applymovement 0xFF, 0x0823B9ED
	loadword 0x0, gJPText_0023BBAB
	callstd 0x4
	goto TrainerHill_Entrance_EventScript_0023B893

TrainerHill_Entrance_EventScript_0023B883::
	lockall
	applymovement 0xFF, 0x0823B9ED
	loadword 0x0, gJPText_0023BBE6
	callstd 0x4

TrainerHill_Entrance_EventScript_0023B893::
	closemessage
	applymovement 0xFF, 0x0823B9EF
	waitmovement 0x0
	setvar 0x40D6, 0x0
	special HealPlayerParty
	releaseall

TrainerHill_Entrance_EventScript_0023B8A7::
	end

TrainerHill_Entrance_EventScript_0023B8A8::
	setvar 0x800B, 0x2
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_0023B8B6::
	lock
	faceplayer
	setvar 0x8004, 0xA
	special CallTrainerHillFunction
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B8D8
	loadword 0x0, 0x0823BBDA
	callstd 0x4
	goto TrainerHill_Entrance_EventScript_0023B8E0

TrainerHill_Entrance_EventScript_0023B8D8::
	loadword 0x0, 0x0823BC1D
	callstd 0x4

TrainerHill_Entrance_EventScript_0023B8E0::
	release
	end

TrainerHill_Entrance_EventScript_0023B8E2::
	lockall
	applymovement 0xFF, 0x0823B9ED
	loadword 0x0, gJPText_0023BA7C
	callstd 0x4
	setvar 0x8004, 0xD
	special CallTrainerHillFunction
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, TrainerHill_Entrance_EventScript_0023B9B1
	setvar 0x8004, 0x8
	special CallTrainerHillFunction
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B925
	loadword 0x0, gJPText_0023BAEE
	callstd 0x4
	goto TrainerHill_Entrance_EventScript_0023B92D

TrainerHill_Entrance_EventScript_0023B925::
	loadword 0x0, gJPText_0023BB16
	callstd 0x4

TrainerHill_Entrance_EventScript_0023B92D::
	message gJPText_0023BB51
	waitmessage
	multichoice 0xF, 0x6, 0x11, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B978
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B997
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B96A
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B997
	end

TrainerHill_Entrance_EventScript_0023B96A::
	loadword 0x0, gJPText_0023BC28
	callstd 0x4
	goto TrainerHill_Entrance_EventScript_0023B92D
	end

TrainerHill_Entrance_EventScript_0023B978::
	setvar 0x40D6, 0x1
	setvar 0x4005, 0x0
	special HealPlayerParty
	loadword 0x0, gJPText_0023BB67
	callstd 0x4
	setvar 0x8004, 0x0
	special CallTrainerHillFunction
	releaseall
	end

TrainerHill_Entrance_EventScript_0023B997::
	setvar 0x4005, 0x0
	loadword 0x0, gJPText_0023BB9E
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x0823B9EF
	waitmovement 0x0
	releaseall
	end

TrainerHill_Entrance_EventScript_0023B9B1::
	loadword 0x0, gJPText_0023BAB9
	callstd 0x4
	setvar 0x8004, 0xE
	special CallTrainerHillFunction
	setvar 0x4005, 0x1
	call 0x082423E9
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023B9DF
	setvar 0x8004, 0xE
	special CallTrainerHillFunction
	return

TrainerHill_Entrance_EventScript_0023B9DF::
	setvar 0x8004, 0xF
	special CallTrainerHillFunction
	goto TrainerHill_Entrance_EventScript_0023B997
	end

	.incbin "baserom_jp.gba", 0x23b9ed, 0x9
TrainerHill_Entrance_EventScript_0023B9F6::
	lockall
	fadescreen 0x1
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_0023B9FF::
	loadword 0x0, 0x0823BEFA
	callstd 0x2
	end

TrainerHill_Entrance_EventScript_0023BA08::
	loadword 0x0, 0x0823BF2E
	callstd 0x2
	end

TrainerHill_Entrance_EventScript_0023BA11::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	checkflag 0x864
	goto_if 0x1, TrainerHill_Entrance_EventScript_0023BA4E
	pokemart 0x0823BA34
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x23ba31, 0x1d
TrainerHill_Entrance_EventScript_0023BA4E::
	pokemart 0x0823BA60
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x23ba5d, 0x1f
	.globl gJPText_0023BA7C
gJPText_0023BA7C: @ 0x0823BA7C
	.string "ようこそ　いらっしゃいました！\p"
	.string "ここは　さまざまな　トレーナーさんとの\n"
	.string "タッグバトルが　たのしめる\l"
	.string "トレーナーヒルです！$"

	.globl gJPText_0023BAB9
gJPText_0023BAB9: @ 0x0823BAB9
	.string "はじめて　ごりようになる\n"
	.string "トレーナーさん　ですね\p"
	.string "ごりように　なるまえに　レポートを\n"
	.string "おかきくださいませ$"

	.globl gJPText_0023BAEE
gJPText_0023BAEE: @ 0x0823BAEE
	.string "ただいま　あつまっている\n"
	.string "トレーナーさんは　⋯⋯\p"
	.string "{B_COPY_VAR_1}かい　までの　ようですね$"

	.globl gJPText_0023BB16
gJPText_0023BB16: @ 0x0823BB16
	.string "ただいま　あつまっている\n"
	.string "トレーナーさんは　⋯⋯\p"
	.string "すべての　へやに　トレーナーさんが\n"
	.string "あつまっている　みたいですね！$"

	.globl gJPText_0023BB51
gJPText_0023BB51: @ 0x0823BB51
	.string "トレーナーさんたちと\n"
	.string "しょうぶ　しますか？$"

	.globl gJPText_0023BB67
gJPText_0023BB67: @ 0x0823BB67
	.string "それでは　じかんを　はかりますので\n"
	.string "がんばってくださいね！\p"
	.string "いちについて⋯⋯⋯⋯⋯⋯⋯\p"
	.string "ようい⋯⋯\p"
	.string "ドン！！$"

	.globl gJPText_0023BB9E
gJPText_0023BB9E: @ 0x0823BB9E
	.string "また　おこしくださいね！$"

	.globl gJPText_0023BBAB
gJPText_0023BBAB: @ 0x0823BBAB
	.string "ざんねん　でしたね！\p"
	.string "とっても　いい　しょうぶ\n"
	.string "だったと　おもいます\p"
	.string "また　きてくださいね！$"

	.incbin "baserom_jp.gba", 0x23bbda, 0xc
	.globl gJPText_0023BBE6
gJPText_0023BBE6: @ 0x0823BBE6
	.string "トレーナーさんたちが　いれかわって\n"
	.string "あぶないので\p"
	.string "こちらに　いどう　させて\n"
	.string "いただきました！\p"
	.string "ごめんなさい！$"

	.incbin "baserom_jp.gba", 0x23bc1d, 0xb
	.globl gJPText_0023BC28
gJPText_0023BC28: @ 0x0823BC28
	.string "ここ　トレーナーヒルでは\n"
	.string "タイムアタックという　きょうぎが\l"
	.string "おこなわれます\p"
	.string "はやい　じかんは　タイムボードに\n"
	.string "のりますので　ともだちと　じかんを\l"
	.string "くらべて　みてください\p"
	.string "うけつけから　おくじょうにいる\n"
	.string "オーナーに　はなしかけるまでの\l"
	.string "じかんが　はかられます\p"
	.string "また　トレーナーとの　しょうぶで\n"
	.string "かっても　けいけんちや　おかねの\l"
	.string "やりとりは　おこなわれません$"

	.incbin "baserom_jp.gba", 0x23bcda, 0x298
	.globl gJPText_0023BF72
gJPText_0023BF72: @ 0x0823BF72
	.string "うけつけに　もどりますか？$"

