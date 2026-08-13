@ BattleFrontier_BattleDomePreBattleRoom scripts (JP map g26 m20 @ 0x08227FC4)

BattleFrontier_BattleDomePreBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomePreBattleRoom_MapScriptTable_00227FE3
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomePreBattleRoom_MapScriptTable_00227FCF
	.byte 0

BattleFrontier_BattleDomePreBattleRoom_MapScriptTable_00227FCF::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleDomePreBattleRoom_EventScript_00227FD9
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_00227FD9::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleDomePreBattleRoom_MapScriptTable_00227FE3::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleDomePreBattleRoom_EventScript_00227FED
	.2byte 0

BattleFrontier_BattleDomePreBattleRoom_EventScript_00227FED::
	compare_var_to_value 0x8006, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228392
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x4000, 0x1
	applymovement 0xFF, 0x0822841D
	waitmovement 0x0
	lockall

BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A::
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_002282C6
	waitmessage
	copyvar 0x8000, 0x800D
	call 0x0821F921
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022808C
	multichoice 0x10, 0x0, 0x49, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_002281A8
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_002281C0
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228238
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_002280D8
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228114
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228142
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_0022808C::
	multichoice 0x10, 0x2, 0x6B, 0x1
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_002281A8
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_002281C0
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228238
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228114
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228142
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_002280D8::
	message gJPText_00228716
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022810A
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_0022810A::
	call 0x0821F8F5
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228114::
	loadword 0x0, gJPText_002286C5
	callstd 0x5
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228186
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228142::
	message gJPText_002286DC
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228174
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228174::
	setvar 0x8004, 0xC
	setvar 0x8005, 0x9
	special sub_0818E608
	goto 0x08228A26

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228186::
	message gJPText_002286F9
	waitmessage
	setvar 0x8004, 0xD
	setvar 0x8005, 0x2
	special sub_0818E608
	playse 0x37
	waitse
	fadescreen 0x1
	setvar 0x8004, 0x4
	special CallFrontierUtilFunc
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_002281A8::
	loadword 0x0, gJPText_0022864D
	callstd 0x4
	fadescreen 0x1
	setvar 0x8004, 0x6
	special sub_0818E608
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_002281C0::
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_002281D5
	fadescreen 0x1
	setvar 0x8004, 0x7
	special sub_0818E608
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_002281D5::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228214
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022821D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228226
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022822F
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228214::
	loadword 0x0, gJPText_00228664
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_0022821D::
	loadword 0x0, gJPText_0022867B
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228226::
	loadword 0x0, gJPText_00228692
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_0022822F::
	loadword 0x0, gJPText_002286AC
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228238::
	message gJPText_002284C0
	waitmessage
	waitbuttonpress
	fadescreen 0x1
	call 0x082202F8
	copyvar 0x8004, 0x800D
	setvar 0x8005, 0x2
	special sub_080F9D20
	waitstate
	setvar 0x8004, 0x15
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A
	setvar 0x8004, 0x2
	setvar 0x8005, 0x8
	special sub_0818E608
	setvar 0x8004, 0x12
	special sub_0818E608
	setvar 0x8004, 0x9
	special sub_0818E608
	loadword 0x0, gJPText_002284E0
	callstd 0x4
	closemessage
	applymovement 0x1, 0x0822841A
	waitmovement 0x0
	applymovement 0xFF, 0x08228422
	waitmovement 0x0
	opendoor 0x5, 0x1
	waitmoncry
	applymovement 0xFF, 0x08228424
	waitmovement 0x0
	closedoor 0x5, 0x1
	waitmoncry
	warp 0x1A15, 0xFF, 0x9, 0x5
	setvar 0x4000, 0x0
	waitstate
	end

BattleFrontier_BattleDomePreBattleRoom_EventScript_002282C6::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228305
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022830B
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228311
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228317
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228305::
	message gJPText_00228427
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_0022830B::
	message gJPText_0022844C
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228311::
	message gJPText_00228471
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228317::
	setvar 0x8004, 0x9
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228356
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022836B
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228356
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_0022836B
	message gJPText_00228499
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228356::
	checkflag 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228380
	loadword 0x0, gJPText_00228736
	callstd 0x4
	setflag 0x1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_0022836B::
	checkflag 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228389
	loadword 0x0, gJPText_00228786
	callstd 0x4
	setflag 0x1
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228380::
	loadword 0x0, gJPText_002287D6
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228389::
	loadword 0x0, gJPText_002287FF
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228392::
	setvar 0x4000, 0x1
	loadword 0x0, gJPText_002284EE
	callstd 0x4
	special LoadPlayerParty
	setvar 0x8004, 0x3
	setvar 0x8005, 0x3
	special CallFrontierUtilFunc
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty
	call BattleFrontier_BattleDomePreBattleRoom_EventScript_002283CB
	fadescreen 0x1
	setvar 0x8004, 0xB
	special sub_0818E608
	waitstate
	goto BattleFrontier_BattleDomePreBattleRoom_EventScript_0022801A

BattleFrontier_BattleDomePreBattleRoom_EventScript_002283CB::
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	special CallFrontierUtilFunc
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_002283FF
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228408
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, BattleFrontier_BattleDomePreBattleRoom_EventScript_00228411
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_002283FF::
	loadword 0x0, gJPText_00228512
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228408::
	loadword 0x0, gJPText_0022853F
	callstd 0x4
	return

BattleFrontier_BattleDomePreBattleRoom_EventScript_00228411::
	loadword 0x0, gJPText_0022856C
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x22841a, 0xd
	.globl gJPText_00228427
gJPText_00228427: @ 0x08228427
	.string "まもなく　1かいせんが　はじまります\n"
	.string "じゅんびの　ほうは　いかがですか？$"

	.globl gJPText_0022844C
gJPText_0022844C: @ 0x0822844C
	.string "まもなく　2かいせんが　はじまります\n"
	.string "じゅんびの　ほうは　いかがですか？$"

	.globl gJPText_00228471
gJPText_00228471: @ 0x08228471
	.string "まもなく　じゅんけっしょうが　はじまります\n"
	.string "じゅんびの　ほうは　いかがですか？$"

	.globl gJPText_00228499
gJPText_00228499: @ 0x08228499
	.string "まもなく　けっしょうせんが　はじまります\n"
	.string "じゅんびの　ほうは　いかがですか？$"

	.globl gJPText_002284C0
gJPText_002284C0: @ 0x082284C0
	.string "それでは　しあいに　だす\n"
	.string "ポケモンを　2ひき　えらんでください$"

	.globl gJPText_002284E0
gJPText_002284E0: @ 0x082284E0
	.string "では　こちらから　どうぞ！$"

	.globl gJPText_002284EE
gJPText_002284EE: @ 0x082284EE
	.string "おつかれさまでした！\p"
	.string "ポケモンの　たいりょくを\n"
	.string "かいふく　いたします！$"

	.globl gJPText_00228512
gJPText_00228512: @ 0x08228512
	.string "これで　1かいせんが\n"
	.string "すべて　しゅうりょう　しました！\p"
	.string "かちあがりを　ごらん　ください！$"

	.globl gJPText_0022853F
gJPText_0022853F: @ 0x0822853F
	.string "これで　2かいせんが\n"
	.string "すべて　しゅうりょう　しました！\p"
	.string "かちあがりを　ごらん　ください！$"

	.globl gJPText_0022856C
gJPText_0022856C: @ 0x0822856C
	.string "これで　じゅんけっしょうが\n"
	.string "すべて　しゅうりょう　しました！\p"
	.string "かちあがりを　ごらん　ください！$"

	.incbin "baserom_jp.gba", 0x22859c, 0xb1
	.globl gJPText_0022864D
gJPText_0022864D: @ 0x0822864D
	.string "{MUS_RG_VS_TRAINER}さんの\n"
	.string "つぎの　あいては　このかた　です$"

	.globl gJPText_00228664
gJPText_00228664: @ 0x08228664
	.string "げんざい　トーナメントは\n"
	.string "1かいせん　です！$"

	.globl gJPText_0022867B
gJPText_0022867B: @ 0x0822867B
	.string "げんざい　トーナメントは\n"
	.string "2かいせん　です！$"

	.globl gJPText_00228692
gJPText_00228692: @ 0x08228692
	.string "げんざい　トーナメントは\n"
	.string "じゅんけっしょう　です！$"

	.globl gJPText_002286AC
gJPText_002286AC: @ 0x082286AC
	.string "げんざい　トーナメントは\n"
	.string "けっしょうせん　です！$"

	.globl gJPText_002286C5
gJPText_002286C5: @ 0x082286C5
	.string "レポートを　かいて　しゅうりょう　しますか？$"

	.globl gJPText_002286DC
gJPText_002286DC: @ 0x082286DC
	.string "バトルトーナメントの　ちょうせんを\n"
	.string "ちゅうし　しますか？$"

	.globl gJPText_002286F9
gJPText_002286F9: @ 0x082286F9
	.string "レポートを　かいています\n"
	.string "しばらく　おまちくださいませ！$"

	.globl gJPText_00228716
gJPText_00228716: @ 0x08228716
	.string "さきほどの　たたかいを\n"
	.string "フロンティアパスに　きろく　しますか？$"

	.globl gJPText_00228736
gJPText_00228736: @ 0x08228736
	.string "けっしょう　しんしゅつ\n"
	.string "おめでとう　ございます\p"
	.string "つぎは　ドームスーパースター　ヒースさまに\n"
	.string "いどむ　けっしょうせん　です！\p"
	.string "じゅんびの　ほうは　いかがですか？$"

	.globl gJPText_00228786
gJPText_00228786: @ 0x08228786
	.string "けっしょう　しんしゅつ\n"
	.string "おめでとう　ございます\p"
	.string "つぎは　ドームスーパースター　ヒースさまに\n"
	.string "いどむ　けっしょうせん　です！\p"
	.string "じゅんびの　ほうは　いかがですか？$"

	.globl gJPText_002287D6
gJPText_002287D6: @ 0x082287D6
	.string "さあ　ヒースさまとの　けっしょうせん　です！\n"
	.string "じゅんびの　ほうは　いかがですか？$"

	.globl gJPText_002287FF
gJPText_002287FF: @ 0x082287FF
	.string "さあ　ヒースさまとの　けっしょうせん　です！\n"
	.string "じゅんびの　ほうは　いかがですか？$"

