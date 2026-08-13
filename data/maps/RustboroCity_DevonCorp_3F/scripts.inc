@ RustboroCity_DevonCorp_3F scripts (JP map g11 m2 @ 0x08201C29)

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_EventScript_00201C39
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_MapScriptTable_00201C51
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_MapScriptTable_00201C60
	.byte 0

RustboroCity_DevonCorp_3F_EventScript_00201C39::
	compare_var_to_value 0x408F, 0x0
	call_if 0x1, RustboroCity_DevonCorp_3F_EventScript_00201C45
	end

RustboroCity_DevonCorp_3F_EventScript_00201C45::
	setobjectxyperm 0x2, 0x3, 0x2
	setobjectmovementtype 0x2, 0x9
	return

RustboroCity_DevonCorp_3F_MapScriptTable_00201C51::
	map_script_2 0x408F, 0x0, RustboroCity_DevonCorp_3F_EventScript_00201C5B
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_00201C5B::
	turnobject 0xFF, 0x4
	end

RustboroCity_DevonCorp_3F_MapScriptTable_00201C60::
	map_script_2 0x408F, 0x0, RustboroCity_DevonCorp_3F_EventScript_00201C6A
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_00201C6A::
	lockall
	loadword 0x0, gJPText_0020213E
	callstd 0x4
	closemessage
	applymovement 0x2, 0x08201D42
	waitmovement 0x0
	delay 0x50
	applymovement 0x2, 0x08201D4B
	waitmovement 0x0
	loadword 0x0, gJPText_00202212
	callstd 0x4
	closemessage
	playbgm 0x1A4, 0x0
	applymovement 0x2, 0x08201D30
	applymovement 0xFF, 0x08201D54
	waitmovement 0x0
	loadword 0x0, gJPText_00202239
	callstd 0x4
	closemessage
	fadedefaultbgm
	applymovement 0x2, 0x08201D3F
	applymovement 0xFF, 0x08201D62
	waitmovement 0x0
	loadword 0x0, gJPText_00201E05
	callstd 0x4
	setorcopyvar 0x8000, 0x112
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	loadword 0x0, gJPText_00201EE9
	callstd 0x4
	playfanfare 0x172
	message gJPText_00201F3E
	waitfanfare
	setflag 0x862
	setflag 0xBC
	setflag 0x3E7
	loadword 0x0, gJPText_00201F4F
	callstd 0x4
	closemessage
	call 0x0824310F
	loadword 0x0, gJPText_00202015
	callstd 0x4
	setflag 0x37E
	clearflag 0x327
	clearflag 0x3D7
	clearflag 0x2E3
	clearflag 0x371
	setvar 0x4096, 0x1
	clearflag 0x32E
	setvar 0x408F, 0x1
	setvar 0x405A, 0x6
	releaseall
	end

	.incbin "baserom_jp.gba", 0x201d2b, 0x3d
RustboroCity_DevonCorp_3F_EventScript_00201D68::
	lock
	faceplayer
	checkflag 0x110
	goto_if 0x1, RustboroCity_DevonCorp_3F_EventScript_00201DC8
	checkflag 0xBD
	goto_if 0x1, RustboroCity_DevonCorp_3F_EventScript_00201D91
	loadword 0x0, 0x08202037
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_00201D91::
	loadword 0x0, 0x08202047
	callstd 0x4
	setorcopyvar 0x8000, 0xB6
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x110
	loadword 0x0, 0x0820208A
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_00201DC8::
	loadword 0x0, 0x082020E6
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_00201DDD::
	lock
	faceplayer
	checkflag 0x100
	goto_if 0x1, RustboroCity_DevonCorp_3F_EventScript_00201DF2
	loadword 0x0, 0x08202241
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_3F_EventScript_00201DF2::
	loadword 0x0, 0x08202277
	callstd 0x4
	release
	end

RustboroCity_DevonCorp_3F_EventScript_00201DFC::
	loadword 0x0, 0x082022A7
	callstd 0x3
	end

	.globl gJPText_00201E05
gJPText_00201E05: @ 0x08201E05
	.string "わしが　デボン　コーポレーション\n"
	.string "しゃちょうの　ツワブキ　だ！\p"
	.string "きみの　ことは　さっき　きいたよ！\p"
	.string "なんでも　うちの　けんきゅういんを\n"
	.string "2ども　たすけてくれた　とか\p"
	.string "⋯⋯で　そんな　すごい　きみに\n"
	.string "たのみごとを　したいのだ！\p"
	.string "きみは　にもつを　とどけに\n"
	.string "カイナの　ぞうせんじょに　いくんだろう？\p"
	.string "その　とちゅうに\n"
	.string "ムロタウンにも　よって　ほしいのだよ！\p"
	.string "いやー　ムロタウンに\n"
	.string "ダイゴという　おとこが　いるはずでね\l"
	.string "ちょいと　てがみを　とどけてほしいのだ！$"

	.globl gJPText_00201EE9
gJPText_00201EE9: @ 0x08201EE9
	.string "ツワブキ“もちろん　わしは\n"
	.string "すごーい　しゃちょうで　あるからな！\p"
	.string "ただで　おねがいすると　いうような\n"
	.string "ケチな　まねは　しないのだ！\p"
	.string "きみに　こいつを　プレゼントしよう！$"

	.globl gJPText_00201F3E
gJPText_00201F3E: @ 0x08201F3E
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "ポケナビを　てにいれた！$"

	.globl gJPText_00201F4F
gJPText_00201F4F: @ 0x08201F4F
	.string "ツワブキ“そいつは⋯⋯\p"
	.string "ポケモン　ナビゲーター！\n"
	.string "りゃくして　ポケナビ　といってな\p"
	.string "ぼうけんを　する　トレーナーの\n"
	.string "ひつじゅひん　なのだよ！\p"
	.string "そいつで　ホウエンマップを　みれば\n"
	.string "ムロや　カイナの　ばしょ　だって\l"
	.string "ばっちり　わかると　いうものだ！\p"
	.string "⋯⋯さいきんは　アクアだの　マグマだの\n"
	.string "といった　あやしげな　れんちゅうが\l"
	.string "あちこちで　わるさを　してるらしい\p"
	.string "まずは　ひとやすみ　していきなさい！$"

	.globl gJPText_00202015
gJPText_00202015: @ 0x08202015
	.string "ツワブキ“それでは　{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}\n"
	.string "じゅうぶん　きをつけて　いくのだよ！$"

	.incbin "baserom_jp.gba", 0x202037, 0x107
	.globl gJPText_0020213E
gJPText_0020213E: @ 0x0820213E
	.string "ここが　デボン　コーポレーション　3かい\n"
	.string "しゃちょうの　おへや　なのよね！\p"
	.string "いやー！　きみには\n"
	.string "かんしゃ　かんげき　あめ　あられ　なのです\p"
	.string "ところで⋯⋯　きみが\n"
	.string "とりもどしてくれた　にもつ\p"
	.string "そいつを　カイナシティの　ぞうせんじょ\n"
	.string "つまり　ふねの　こうじょうへ\l"
	.string "とどけて　ほしいのです！\p"
	.string "また　おかしな　やつらに\n"
	.string "うばわれては　たまりません　からね\p"
	.string "えへへ⋯⋯\n"
	.string "よろしく　おねがい　しますよ\p"
	.string "ちょっと　まっていて　くださいね$"

	.globl gJPText_00202212
gJPText_00202212: @ 0x08202212
	.string "しゃちょうが　ぜひ\n"
	.string "おはなし　したいそうです\p"
	.string "わたしに　ついて　きてください$"

	.globl gJPText_00202239
gJPText_00202239: @ 0x08202239
	.string "ささ　どうぞ！$"

	.incbin "baserom_jp.gba", 0x202241, 0x1272
