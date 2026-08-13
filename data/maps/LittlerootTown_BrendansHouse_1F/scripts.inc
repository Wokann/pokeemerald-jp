@ LittlerootTown_BrendansHouse_1F scripts (JP map g1 m0 @ 0x081EF785)

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_EventScript_001EF795
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_EventScript_001EF7D4
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_MapScriptTable_001EF81A
	.byte 0

LittlerootTown_BrendansHouse_1F_EventScript_001EF795::
	compare_var_to_value 0x4092, 0x6
	call_if 0x0, LittlerootTown_BrendansHouse_1F_EventScript_001EF7AA
	checkflag 0x112
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF7BD
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF7AA::
	setmetatile 0x5, 0x4, 0x270, 0x1
	setmetatile 0x5, 0x2, 0x268, 0x1
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF7BD::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF7CA
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF7CA::
	setmetatile 0x3, 0x7, 0x293, 0x1
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF7D4::
	compare_var_to_value 0x4092, 0x3
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF80E
	compare_var_to_value 0x4092, 0x5
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF7F6
	compare_var_to_value 0x4092, 0x6
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF802
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF7F6::
	setobjectxyperm 0x1, 0x8, 0x4
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF802::
	setobjectxyperm 0x1, 0x4, 0x5
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF80E::
	setobjectxyperm 0x1, 0x9, 0x8
	setobjectmovementtype 0x1, 0x7
	return

LittlerootTown_BrendansHouse_1F_MapScriptTable_001EF81A::
	map_script_2 0x4092, 0x3, LittlerootTown_BrendansHouse_1F_EventScript_001EF86C
	map_script_2 0x4092, 0x5, LittlerootTown_BrendansHouse_1F_EventScript_001EF844
	map_script_2 0x4092, 0x6, LittlerootTown_BrendansHouse_1F_EventScript_001EF87D
	map_script_2 0x4082, 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF88E
	map_script_2 0x4082, 0x3, 0x082582DC
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_001EF844::
	lockall
	loadword 0x0, gJPText_001EFAFC
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x081EF86A
	applymovement 0x1, 0x081EF86A
	waitmovement 0x0
	warp 0x101, 0xFF, 0x7, 0x1
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1ef86a, 0x2
LittlerootTown_BrendansHouse_1F_EventScript_001EF86C::
	lockall
	setvar 0x8004, 0x1
	setvar 0x8005, 0x0
	goto 0x08257EEE
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF87D::
	lockall
	setvar 0x8004, 0x0
	setvar 0x8005, 0x1
	goto 0x08258057
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF88E::
	lockall
	playse 0x15
	applymovement 0x4, 0x0824361B
	waitmovement 0x0
	applymovement 0x4, 0x0824361D
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	applymovement 0x4, 0x081EF8CC
	waitmovement 0x0
	special GetRivalSonDaughterString
	loadword 0x0, gJPText_001F0678
	callstd 0x4
	setflag 0x57
	setvar 0x4082, 0x2
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1ef8cc, 0x7
LittlerootTown_BrendansHouse_1F_EventScript_001EF8D3::
	lockall
	setvar 0x8004, 0x1
	setvar 0x8005, 0x0
	applymovement 0x8004, 0x08243627
	waitmovement 0x0
	goto 0x08257F4F
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF8EE::
	lockall
	setvar 0x8008, 0x0
	goto LittlerootTown_BrendansHouse_1F_EventScript_001EF912
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF8FA::
	lockall
	setvar 0x8008, 0x1
	goto LittlerootTown_BrendansHouse_1F_EventScript_001EF912
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF906::
	lockall
	setvar 0x8008, 0x2
	goto LittlerootTown_BrendansHouse_1F_EventScript_001EF912
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF912::
	playse 0x9
	delay 0xA
	addobject 0x7
	delay 0x1E
	playse 0x15
	applymovement 0x7, 0x0824361B
	waitmovement 0x0
	applymovement 0x7, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x8008, 0x1
	call_if 0x5, LittlerootTown_BrendansHouse_1F_EventScript_001EF9B1
	playbgm 0x1A5, 0x1
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF9BC
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF9C7
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF9D2
	loadword 0x0, 0x081F0994
	callstd 0x4
	closemessage
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EF9F1
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EFA03
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, LittlerootTown_BrendansHouse_1F_EventScript_001EFA15
	playse 0x9
	removeobject 0x7
	setflag 0x2E9
	setflag 0x331
	clearflag 0x2F8
	delay 0x1E
	setvar 0x408D, 0x3
	setvar 0x4050, 0x1
	savebgm 0x0
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_001EF9B1::
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF9BC::
	applymovement 0x7, 0x081EF9DD
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF9C7::
	applymovement 0x7, 0x081EF9E5
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EF9D2::
	applymovement 0x7, 0x081EF9E9
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1ef9dd, 0x14
LittlerootTown_BrendansHouse_1F_EventScript_001EF9F1::
	applymovement 0xFF, 0x081EFA27
	applymovement 0x7, 0x081EFA36
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EFA03::
	applymovement 0xFF, 0x081EFA2B
	applymovement 0x7, 0x081EFA3C
	waitmovement 0x0
	return

LittlerootTown_BrendansHouse_1F_EventScript_001EFA15::
	applymovement 0xFF, 0x081EFA32
	applymovement 0x7, 0x081EFA46
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1efa27, 0x25
	.globl gJPText_001EFA4C
gJPText_001EFA4C: @ 0x081EFA4C
	.string "ママ“ほら　{MUS_RG_VS_TRAINER}！\n"
	.string "おうちの　なかも　すてき　でしょ！$"

	.globl gJPText_001EFA68
gJPText_001EFA68: @ 0x081EFA68
	.string "おうちの　かたづけは\n"
	.string "ひっこしやさんの　ポケモンが\l"
	.string "てつだって　くれるから　らくちんね！\p"
	.string "{MUS_RG_VS_TRAINER}も　2かいに　ある\n"
	.string "じぶんの　おへやに　いってごらん！\p"
	.string "パパが　ひっこしの　おいわいに\n"
	.string "かってくれた　とけいが　あるから\l"
	.string "じかんを　あわせて　おきなさいよ$"

	.incbin "baserom_jp.gba", 0x1efae5, 0x17
	.globl gJPText_001EFAFC
gJPText_001EFAFC: @ 0x081EFAFC
	.string "ママ“{MUS_RG_VS_TRAINER}\p"
	.string "おへやの　とけい　あわせてきて$"

	.globl gJPText_001EFB12
gJPText_001EFB12: @ 0x081EFB12
	.string "ママ“⋯⋯あ！　{MUS_RG_VS_TRAINER}！　{MUS_RG_VS_TRAINER}！\n"
	.string "はやく　こっちに　いらっしゃい！$"

	.globl gJPText_001EFB33
gJPText_001EFB33: @ 0x081EFB33
	.string "ママ“トウカの　ジムが　うつってるわ\n"
	.string "パパが　でるかもよ！！$"

	.globl gJPText_001EFB52
gJPText_001EFB52: @ 0x081EFB52
	.string "ママ“あらら⋯⋯　おわっちゃった\p"
	.string "パパが　でてたみたい　だったのに　ざんねんね$"

	.globl gJPText_001EFB7A
gJPText_001EFB7A: @ 0x081EFB7A
	.string "⋯⋯あ　そうそう！　このまち　には\n"
	.string "オダマキはかせ　っていう\l"
	.string "パパの　おともだちが　いるの\p"
	.string "はかせの　いえは　おとなり　だから\n"
	.string "きちんと　あいさつ　してくると　いいわ！$"

	.incbin "baserom_jp.gba", 0x1efbcf, 0x128
	.globl gJPText_001EFCF7
gJPText_001EFCF7: @ 0x081EFCF7
	.string "インタビュアー“⋯⋯　いじょう\n"
	.string "トウカジムの　まえ　からでした！$"

	.incbin "baserom_jp.gba", 0x1efd18, 0xb0
	.globl gJPText_001EFDC8
gJPText_001EFDC8: @ 0x081EFDC8
	.string "パパ“ん？\n"
	.string "{MUS_RG_VS_TRAINER}じゃ　ないか！\p"
	.string "ひさしぶりに　かおを　みたが\n"
	.string "どこか　たくましくなった⋯⋯\l"
	.string "そんな　かんじ　だな\p"
	.string "⋯⋯おっと　そうだった\n"
	.string "ハギさん　という　ひとから\l"
	.string "おまえあてに　なにか　とどいていたぞ！$"

	.globl gJPText_001EFE2F
gJPText_001EFE2F: @ 0x081EFE2F
	.string "パパ“ふねのチケットか⋯⋯\p"
	.string "ふねに　のるなら　カイナか　ミナモに\n"
	.string "ふねのりばが　あったよな$"

	.globl gJPText_001EFE5D
gJPText_001EFE5D: @ 0x081EFE5D
	.string "では　わたしは\n"
	.string "トウカの　ジムに　もどるよ\p"
	.string "ママ\n"
	.string "いえのこと　たのんだよ$"

	.globl gJPText_001EFE82
gJPText_001EFE82: @ 0x081EFE82
	.string "ママ“パパったら\n"
	.string "ひさしぶりに　かえって　きたのに\l"
	.string "ポケモンの　はなし　ばっかり！\p"
	.string "もっと　ゆっくり　すれば　いいのにね！$"

	.globl gJPText_001EFEC0
gJPText_001EFEC0: @ 0x081EFEC0
	.string "ママ“なにかの　ニュース　かしら？$"

	.globl gJPText_001EFED2
gJPText_001EFED2: @ 0x081EFED2
	.string "りんじ　ニュース　です\p"
	.string "ホウエンちほうの　かくちで\n"
	.string "⋯⋯いろの　ポケモンが　とんでいた\l"
	.string "という　じょうほうが　よせられています\p"
	.string "いまのところ　しょうたいは\n"
	.string "わかって　いない　ようです⋯⋯\p"
	.string "では　ひきつづき\n"
	.string "えいがを　おたのしみ　ください$"

	.globl gJPText_001EFF49
gJPText_001EFF49: @ 0x081EFF49
	.string "ママ“ねえ　ねえ　{MUS_RG_VS_TRAINER}\n"
	.string "いまの　ニュース\l"
	.string "なにいろの　ポケモンって　いってたの？$"

	.globl gJPText_001EFF72
gJPText_001EFF72: @ 0x081EFF72
	.string "ママ“へえー　まだまだ\n"
	.string "しられていない　ポケモンは　いるのねえ$"

