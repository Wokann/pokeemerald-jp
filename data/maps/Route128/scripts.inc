@ Route128 scripts (JP map g0 m43 @ 0x081EED6C)

Route128_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_EventScript_001EED77
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route128_MapScriptTable_001EED81
	.byte 0

Route128_EventScript_001EED77::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	end

Route128_MapScriptTable_001EED81::
	map_script_2 0x407B, 0x1, Route128_EventScript_001EED8B
	.2byte 0

Route128_EventScript_001EED8B::
	lockall
	delay 0x14
	applymovement 0x4, 0x081EEEBD
	waitmovement 0x0
	loadword 0x0, gJPText_001EF029
	callstd 0x4
	closemessage
	applymovement 0x4, 0x081EEEC5
	waitmovement 0x0
	loadword 0x0, gJPText_001EF059
	callstd 0x4
	closemessage
	applymovement 0x5, 0x081EEEE1
	waitmovement 0x0
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_001EF064
	callstd 0x4
	closemessage
	applymovement 0x5, 0x081EEEEF
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_001EF0C6
	callstd 0x4
	closemessage
	applymovement 0x4, 0x081EEECA
	applymovement 0xFF, 0x08243627
	applymovement 0x5, 0x081EEEDC
	waitmovement 0x0
	loadword 0x0, gJPText_001EF171
	callstd 0x4
	closemessage
	delay 0x28
	applymovement 0x5, 0x081EEEE4
	applymovement 0x4, 0x081EEECF
	waitmovement 0x0
	removeobject 0x5
	removeobject 0x4
	delay 0x64
	setfieldeffectarg 0x0, 0x1
	dofieldeffect 0x1E
	waitfieldeffect 0x1E
	addobject 0x3
	applymovement 0x3, 0x081EEEBB
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, gJPText_001EF1AB
	callstd 0x4
	closemessage
	applymovement 0x3, 0x081EEEB9
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_001EF1C1
	callstd 0x4
	applymovement 0x3, 0x0824362D
	waitmovement 0x0
	loadword 0x0, gJPText_001EF277
	callstd 0x4
	closemessage
	applymovement 0x3, 0x0824362D
	waitmovement 0x0
	delay 0x32
	setfieldeffectarg 0x0, 0x1
	dofieldeffect 0x1E
	delay 0xF
	removeobject 0x3
	waitfieldeffect 0x1E
	clearflag 0x4000
	setvar 0x407B, 0x2
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1eeeaa, 0x17f
	.globl gJPText_001EF029
gJPText_001EF029: @ 0x081EF029
	.string "アオギリ“なんだ⋯⋯\n"
	.string "この　ひどい　ありさまは⋯⋯？\p"
	.string "おれは⋯⋯\n"
	.string "とんでもない　まちがいを⋯⋯$"

	.globl gJPText_001EF059
gJPText_001EF059: @ 0x081EF059
	.string "おれは⋯⋯\n"
	.string "ただ⋯⋯$"

	.globl gJPText_001EF064
gJPText_001EF064: @ 0x081EF064
	.string "マツブサ“わかったか　アオギリ！\p"
	.string "おまえの⋯⋯\n"
	.string "いや　われわれの　したことが\l"
	.string "どれほど　おろか　だったのか⋯⋯\p"
	.string "とにかく　いそぐんだ！\n"
	.string "これいじょう　ひどく　ならぬうちに\l"
	.string "なんとか　しないとな！$"

	.globl gJPText_001EF0C6
gJPText_001EF0C6: @ 0x081EF0C6
	.string "マツブサ“{MUS_RG_VS_TRAINER}　なにも　いうな\p"
	.string "わたしに　アオギリを　せめる\n"
	.string "しかくが　ないことは　わかっている⋯⋯\p"
	.string "こんな　ことに　なった　いじょう\n"
	.string "もう　にんげんの　ちからでは\l"
	.string "どうする　ことも　できない　だろう\p"
	.string "しかし　だから　といって\n"
	.string "だまって　みている　わけにも　いかない\p"
	.string "この　あとしまつを　つけるのは\n"
	.string "わたしと　アオギリの　やくめ⋯⋯　か⋯⋯$"

	.globl gJPText_001EF171
gJPText_001EF171: @ 0x081EF171
	.string "マツブサ“それにしても⋯⋯\p"
	.string "ちょう　こだいポケモン⋯⋯\n"
	.string "なんという　パワーだ\l"
	.string "すべての　バランスが　くずれたぞ⋯⋯$"

	.globl gJPText_001EF1AB
gJPText_001EF1AB: @ 0x081EF1AB
	.string "ダイゴ“{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！\n"
	.string "これは　いったい⋯⋯？$"

	.globl gJPText_001EF1C1
gJPText_001EF1C1: @ 0x081EF1C1
	.string "⋯⋯ひどいな\p"
	.string "さっきは　はげしい　ひでり　だったのに\n"
	.string "また　おおあめが　ふりはじめている\p"
	.string "このまま　では　ホウエンちほう⋯⋯\n"
	.string "いや　せかいじゅうが　しずむ！\p"
	.string "この　あめを　ふらせている　くもは\n"
	.string "ルネの　じょうくうを　ちゅうしんに\l"
	.string "ひろがって　いるのか⋯⋯\p"
	.string "いったい　あそこで\n"
	.string "なにが　おきている！？\p"
	.string "ここで　あれこれ　かんがえるより\n"
	.string "ルネに　いけば　わかるか⋯⋯$"

	.globl gJPText_001EF277
gJPText_001EF277: @ 0x081EF277
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}⋯⋯\n"
	.string "きみが　なにを　する　つもりか\l"
	.string "わからないけど　ムリだけは　するなよ\p"
	.string "⋯⋯じゃあ\n"
	.string "ボクは　ルネに　いくから$"

