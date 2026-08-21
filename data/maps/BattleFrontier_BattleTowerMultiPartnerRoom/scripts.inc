@ BattleFrontier_BattleTowerMultiPartnerRoom scripts (JP map g26 m15 @ 0x08223475)

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022348A
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223493
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_002234F7
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_00223506
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022348A::
	setvar 0x8004, 0x11
	special CallBattlePyramidFunction
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223493::
	checkflag 0x152
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002234BD
	clearflag 0x2C7
	clearflag 0x2C8
	clearflag 0x2C9
	clearflag 0x2CA
	clearflag 0x2CB
	clearflag 0x2CC
	setflag 0x360
	setflag 0x361
	setvar 0x8004, 0xA
	special sub_08161E88
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002234BD::
	setvar 0x4010, 0x7
	setvar 0x4011, 0x7
	setvar 0x4012, 0x7
	setvar 0x4013, 0x7
	setvar 0x4014, 0x7
	setvar 0x4015, 0x7
	setvar 0x4016, 0x7
	setvar 0x4017, 0x7
	setvar 0x4001, 0x1
	setvar 0x4003, 0x1
	setobjectxyperm 0x1, 0xA, 0x2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_002234F7::
	map_script_2 0x4003, 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223501
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223501::
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_MapScriptTable_00223506::
	map_script_2 0x4001, 0x0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223524
	map_script_2 0x4003, 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223518
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223518::
	lockall
	setvar 0x4003, 0x0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223598
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223524::
	lockall
	applymovement 0xFF, 0x08223558
	waitmovement 0x0
	applymovement 0x1, 0x0822355A
	waitmovement 0x0
	moveobjectoffscreen 0x1
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_00223739
	callstd 0x4
	special HealPlayerParty
	setvar 0x4001, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x223558, 0x5
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022355D::
	lock
	faceplayer
	message 0x0822375E
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223580
	loadword 0x0, 0x08223797
	callstd 0x4
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223580::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x6
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	goto 0x08221CFC
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223598::
	loadword 0x0, gJPText_002237C1
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	opendoor 0xA, 0x1
	waitmoncry
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002235C7
	closedoor 0xA, 0x1
	waitmoncry
	warp 0x1A06, 0xFF, 0x1, 0x6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002235C7::
	applymovement 0x1, 0x08223609
	applymovement 0xFF, 0x082235FD
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x2235d9, 0x33
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022360C::
	lock
	faceplayer
	setvar 0x4002, 0x0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619::
	checkflag 0x152
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6
	setvar 0x8004, 0xB
	setvar 0x8005, 0x0
	special sub_08161E88
	waitmessage
	waitbuttonpress
	setvar 0x8004, 0xB
	setvar 0x8005, 0x1
	special sub_08161E88
	waitmessage
	waitbuttonpress
	setvar 0x8004, 0xB
	setvar 0x8005, 0x2
	special sub_08161E88
	waitmessage
	multichoicedefault 0x14, 0x8, 0x5E, 0x1, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6
	setvar 0x8004, 0xB
	setvar 0x8005, 0x3
	special sub_08161E88
	waitmessage
	waitbuttonpress
	closemessage
	compare_var_to_value 0x800C, 0x1
	call_if 0x5, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236B7
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236C2
	removeobject 0x800F
	setflag 0x152
	warpsilent 0x1A0F, 0xFF, 0xA, 0x3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236A6::
	setvar 0x8004, 0xB
	setvar 0x8005, 0x4
	special sub_08161E88
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236B7::
	applymovement 0x800F, 0x082236CD
	waitmovement 0x0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236C2::
	applymovement 0x800F, 0x082236D5
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x2236cd, 0x11
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236DE::
	lock
	faceplayer
	setvar 0x4002, 0x1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236EB::
	lock
	faceplayer
	setvar 0x4002, 0x2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_002236F8::
	lock
	faceplayer
	setvar 0x4002, 0x3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223705::
	lock
	faceplayer
	setvar 0x4002, 0x4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223712::
	lock
	faceplayer
	setvar 0x4002, 0x5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022371F::
	lock
	faceplayer
	setvar 0x4002, 0x6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_0022372C::
	lock
	faceplayer
	setvar 0x4002, 0x7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_00223619
	end

	.globl gJPText_00223739
gJPText_00223739: @ 0x08223739
	.string "こちらに　いる　トレーナーの　なかから\n"
	.string "パートナーを　おさがしください！$"

	.incbin "baserom_jp.gba", 0x22375e, 0x63
	.globl gJPText_002237C1
gJPText_002237C1: @ 0x082237C1
	.string "パートナーさがし\n"
	.string "おつかれさまでした！\p"
	.string "それでは　マルチ　バトルルームへ\n"
	.string "おつれいたします$"

	.incbin "baserom_jp.gba", 0x2237ef, 0x142

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "ぼくは　{STR_VAR_3}　って　いって\n{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしです\lグスっ⋯⋯\pごめんなさい！\nきんちょう　して　なみだが⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "ぼく　{STR_VAR_3}さんの　アドバイスで\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれているんです\pグスン⋯⋯　ぼ　ぼくと\nタッグを　くんで　ください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "えー　ほんとですか！\nやった！　うれしいよう！　うぉぉーん！\pあ⋯⋯　ごめん　なさい\nうれしくて　なみだが⋯⋯\pさっ　さっそく　うけつけに\nいってきますから　まってて　ください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "そ　そんな⋯⋯\nう　うう　うわーん！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "こんにちはっ　ボクは　{STR_VAR_3}！\n{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしなんだ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3}さんに　すすめて　もらった\n{STR_VAR_1}を　もつ　{STR_VAR_2}とね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}が\nいるんだよ　いいでしょ？\lねーっ　ボクと　いっしょに\lタッグを　くもうよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "わーいっ　やった！\nじゃあねー　ボクが\lうけつけに　いってくるからね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "えーっ　どうして？\n{PLAYER}さんと　くみたかったなー$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "ぼくは　あの　ゆうめいな\n{STR_VAR_1}さんの　{STR_VAR_2}ばんの　でし\l{STR_VAR_3}です！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "{STR_VAR_3}さん　から\nアドバイスを　いただいて\l{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nつれているんです\pおねがいです！\nぼくと　タッグを　くんでください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "ありがとうございます！\nさっそく　うけつけを　すませてきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}さんと\nぜひ　タッグを　くみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "あの⋯⋯　あたし　なんかに\nこえを　かけてくれて　うれしいです\lあたしは　{STR_VAR_3}です\l{STR_VAR_1}さんの　{STR_VAR_2}ばんでしで⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3}さんが　あたし　なんかにも\nアドバイスを　くださったので\l{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれています⋯⋯　おそれ　おおいけど⋯⋯\pムリ　だと　おもいます　けど⋯⋯\nあたしと　タッグを　くんでいただけますか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "ほんとう　ですか？　しんじられない！\nあたし　なんかと　くんでもらえる　なんて！\lが⋯⋯がんばります！\pあのっ　あたしで　よかったら\nいまから　うけつけに　いって　きます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "や　やっぱり⋯⋯\nあたし　なんか　ダメですよね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "わたしは　{STR_VAR_3}\n{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしなの！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3}さんが　いいって　いったから\n{STR_VAR_1}　つかいの　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "{STR_VAR_1}　つかいの　{STR_VAR_2}を\nもって　いるわけ！\lわるくない　でしょ？\lあなたと　タッグを　くんで　あげようか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "うん　じゃあ　よろしくね\nわたしの　あしを　ひっぱらないでよね！\lさっそく　うけつけに　いってくるわ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "え？　なんで　ことわるの？\nみるめ　ないんじゃない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "オレは　トライアスリートの　{STR_VAR_3}！\nジョギング　トレーニング　ラッピングと\lまいにち　いそがしい　なか\l{STR_VAR_1}の　{STR_VAR_2}ばんでし　やってる！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "{STR_VAR_3}の　オススメ！\n{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nいそがしい　なか　がんばって　そだてたぜ！\pオレと　タッグを　くんで　がんばろうぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "サンキュー　そう　こなくっちゃ！\nんじゃ　オレ　うけつけを　すませてくるわ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "おいおい　いそがしい　なか　きたのに\nそりゃ　ないぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "ハーイ！　ちょうしは　どう？\n{STR_VAR_1}さんの　{STR_VAR_2}ばんの\lでしトレーナー　{STR_VAR_3}よ　よろしくぅ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "きいてきいて！　{STR_VAR_3}さんが\nおすすめ　してくれた　ポケモンはね\l{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}なの\nもちろん　バッチリ　そだてたわ！\pというわけで　わたしと　くまない？\nきっと　いいカンジよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "わーい　たのしく　なりそうー！\nじゃ　わたしが　うけつけに　いってくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "もー　いじわる！\nわたし　オススメなのに！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "{STR_VAR_3}と　もうします\nわたくし　{STR_VAR_1}さまの　{STR_VAR_2}ばんの\lでしで　ございますの⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "{STR_VAR_3}さまに　おしえを　こい\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nそだて　あげましたの！\pおねがい　わたくしと　タッグを\nくんで　くださると　おっしゃって！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "うっ　うれしい　ですわ⋯⋯\nわたくし　ぜんりょくで　つとめますわ！\pもちろん　うけつけは　わたくしが！\nすこし　おまちくださいませ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "{PLAYER}さんと\nぜひ　タッグを　くみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "キャー！　はなしかけられたっ！\nかっ　かんげきっ⋯⋯！\pわたし！　{STR_VAR_3}と　いいますっ！\n{STR_VAR_1}　せんせいの\l{STR_VAR_2}ばん　でし　ですっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "{STR_VAR_3}　せんせいの　アドバイスで\n{STR_VAR_1}をもつ　{STR_VAR_2}ちゃんと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "{STR_VAR_1}をもつ　{STR_VAR_2}ちゃんを\nそだてましたーっ！\pあの　おねがいが！\nわたしと　タッグをくんで　ほしいのですっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "キャー！　かっ　かんげきっ⋯⋯！\nおありがとう　ございますう！\lではっ　うけつけを　して　まいりますっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "うっわあああ！\nちも　なみだも　ないですねっ！　でもステキ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "いえーい！　{STR_VAR_1}さんの\n{STR_VAR_2}ばん　でしの　おじさんは\l{STR_VAR_3}です　ハロウ　ハロウ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "{STR_VAR_3}　ティーチャー　おすすめの\n{STR_VAR_1}　マスター　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "{STR_VAR_1}　マスター　{STR_VAR_2}を\nトレイン　したんだよー！\lグッドタイミングだね！\lもちろん　おじさんと　タッグを　くむだろ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "オーケイ　エクセレント！\nじゃ　バーっと　うけつけを　すませてくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "ぐわーっ！\n{PLAYER}さん　ってのは　クールだね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "お　おいっ　たいへんだ！\nバトルタワー　きょうで　おしまいらしいぞ！\p⋯⋯　⋯⋯　⋯⋯\nなんてね　うっそ　うそ！\pおいらは　{STR_VAR_3}　って　いうんだ\n{STR_VAR_1}の　1000ばんめの　でしだ！\lうそ　ほんとは　{STR_VAR_2}ばん！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3}が　アドバイスを　くれてね\n{STR_VAR_1}を　もつ　{STR_VAR_2}とね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}をね\n10ぴきずつ　もって　いまーす！\lうそ　ほんとは　1ぴきずつだよ！\pひとつ　どうだろ？　こんな　おいらと\nタッグバトルを　して　みないかな？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "やったー！\nおれいに　ポケモン　あげちゃおう！\pなんて　じょうだん　だけど⋯⋯\nとりあえず　うけつけを　すませてくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "そんな　つめたい　こと　いうと\nバトルタワーを　こわして　しまうぞ！\pなんてね　うそ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "ご·き·げ·ん·よ·う！\nはーい　ごきげんよう！\pわしは　ノリノリ　ふなのり　{STR_VAR_3}！\n{STR_VAR_1}さんの　{STR_VAR_2}ばんの　でしだよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "{STR_VAR_3}さん　アドバイスの　たまもの\n{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}が\nわしの　じまんの　ポケモン！\pさあ　この　であいを　きねんして\nわしと　タッグバトルを　やってください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "ようよう！　ノリが　いいね\nよろしく　たのみますよ！\lじゃ　うけつけは　わしが　いってくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "そんな　{PLAYER}さん！\nノリが　わるいじゃ　ないか！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "イャァアッホオオォォウウ！\nあ　にげないでェ　かえらないでェ！\pオスっ　オレっ　{STR_VAR_3}！\n{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしなのさ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3}さんったら　オレに！\n{STR_VAR_1}を　もつ　{STR_VAR_2}と！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を！\nつかえって　いうから　そうしたぜエェ！\pって　ことで　どうする　オレ？\nさっそく　たのんでみる？\pおねがいです！\nオレと　タッグを　くんでエェ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "やったラッキー　うれしーよ　オレ！！\nさっそく　うけつけに　いってくる！？\lじゃ　ちょっと　まっててェ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "って　ことわられてる　オレっ！？\n{PLAYER}さん　つれないよォ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "ゴホっ！\pあっ　ゴメン　カゼ　ひいてて⋯⋯\nポケモンは　げんきだから　ダイジョブだよ\pおれは　{STR_VAR_3}\n{STR_VAR_1}さんの　{STR_VAR_2}ばんでしだよ\l⋯⋯ゴホっ　ゴホっ　よろしく！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "{STR_VAR_3}さんの　アドバイスで\n{STR_VAR_1}を　もつ　{STR_VAR_2}とさ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nあめのひも　かぜのひも　そだてあげたよ\l⋯⋯それで　カゼを　ひいたんだ　きっと\pまあ　そういう　わけだからさ\nこんな　おれと　いっしょに　くまないかい？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "ありがとう　わるいね\n⋯⋯ゴホ　ゴホ！\lうけつけを　すませてくるから⋯⋯\lゴホ　まっててね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "えー　なんで！\n{PLAYER}さんと　オレって　いいけどなあ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "あっ　ど　どうも！\nてれるなあ\pあの　{STR_VAR_3}です！　{STR_VAR_1}さんの\n{STR_VAR_2}ばんの　でし　やってます⋯⋯！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3}さんが　よいと　いったので\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nそだててるんだ⋯⋯　はずかしながら\pその　はずかしい　けど　ワシと⋯⋯\nタッグを　くんで　もらえる　かな⋯⋯？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "あ　ありがとう！\nはずかしい　けど　がんばって　みるよ\pじゃ⋯⋯　う　うけつけ　してくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "こ　ことわらないでくれ！\nワシに　はじを　かかせないで　くれ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "わたしは　{STR_VAR_3}だ\nうそじゃない！\l{STR_VAR_1}さんの　{STR_VAR_2}ばんの　でしだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3}さんから　すすめられて\nどうやら　ほんき　みたい　だったから\l{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれているんだ　ほんとうだよ！\pところで　もし　よかったら　わたしを\nキミの　パートナーに　みとめて　ほしい$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "ほんとうに　みとめて　くれるのかね？\nうそだったら　いやすぎる　からな\pいや　ほんとうなら　いいんだ　すまなかった\nさっそく　うけつけを　すませてくる$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "え？　なぜ　ことわるのかね？\nわるい　じょうだん　では　ないのかね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "わたし\nミニスカート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "わたしはね⋯⋯\n{STR_VAR_1}を　つかう　{STR_VAR_2}とね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nつれて　あるいているの！\pどう？\nパートナーに　なってくれない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "ありがとうー！\nいまから　とうろく　してくるわね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "わたしの　パートナーに　ならないなんて\nきっと　こうかい　するから！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "あのね！\pぼくは\nたんパンこぞう　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "ぼくはね⋯⋯\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nもっているよ！\pねぇねぇ\nいっしょに　タッグを　くもうよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "やったー！\nうけつけで　とうろく　してくるねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "ぼくの　ポケモンと　タッグを　くめば\nきっと　つよいのにー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "ヤッホー！\pわし\nやまおとこ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "わし\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれて　あるいています！\pどうですかな？\nいっしょに　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "ヤッホー！\pいまから　うけつけで\nとうろくを　すませてきますよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "きみと　いっしょに\nバトルを　したかったです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "こんにちは！\pわたし\nおとなのおねえさん　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "わたし\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nそだてているのよ！\pどう？\nいっしょに　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "うれしい！\pすぐに　とうろくを　すませるわね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "ざんねんね！\pあなたと　わたしが\nくんだら　さいこう　だったのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "よー！\pわし\nつりびと　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "わしは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nつれているぞ\pどうだね？\nいっしょに　たたかうかね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "よしよし！\nまかせとけー\pいまから　とうろくを　するからな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "きみと　わしの　あいしょうは\nバッチリ　だったのにな⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "わたくし\nおじょうさま　{STR_VAR_1}と\lもうします！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "わたくし\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nつれていますの\pどうですか？\pわたくしと　いっしょに\nタッグを　くんで　いただけませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "ありがとうございます！\pでは　わたくしは　\nとうろくを　すませてきますわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "わたくしの　パートナーに　ならないと\nきっと　こうかい　しますわよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "わたし\nトライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "わたしはね⋯⋯\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nもっているの！\pおねがい！\nいっしょに　タッグを　くんでよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "ありがとうー！\nうけつけで　とうろく　してくるー$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "わたしと　タッグを　くんだら\nきっと　つよいのにー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "やあ！\pぼく\nむしとりしょうねん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "ぼく\n{STR_VAR_1}を　おぼえた　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "{STR_VAR_1}を　おぼえた　{STR_VAR_2}を\nもっているよ！\pねー？\nぼくと　いっしょに　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "やったね！\pじゃ　いまから　うけつけで\nとうろくを　すませてくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "ぼくの　ポケモン　さいこう　なのに！\nこうかい　しないでよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "こんにちは！\pぼくは\nじゅくがえり　{STR_VAR_1}　です$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "ぼくは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nそだてています！\pどうです？\pぼくと\nいっしょに　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "ありがとうございます！\pでは\nうけつけで　とうろくを　すませてきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "ざんねんです⋯⋯\pきみと　いっしょに　タッグを　くんで\nべんきょう　したかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "よう！\pオレ\nおぼっちゃま　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "オレ\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nもっているんだぜ！\pオレ　いっしょに\nタッグを　くんでもいいぜ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "よし！\pじゃあ　いまから\nうけつけで　とうろくを　すませてくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "オレと　タッグを　くまない　なんて\nきっと　こうかい　するぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "オッス！\pカラテおう　{STR_VAR_1}\nと　もうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "いま　わたくし\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれております！\pおねがいします！\pわたくしと\nタッグを　くんで　くれませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "オッス！\pさっそく\nうけつけに　とうろく　してまいります！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "オッス⋯⋯\pつぎの　きかいは\nぜひ　タッグを　くんでください⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "こんにちは！\pわたし\nうきわガール　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "わたし\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれているの！\pねぇ？\pいっしょに\nタッグを　くんでよー？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "ありがとうー！\pじゃあ　いまから\nうけつけで　とうろくを　すませてくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "わたしと　タッグを　くんだら\nとっても　つよかったのにー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "こんにちは⋯⋯\pオカルトマニア　{STR_VAR_1}と\nもうします⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "わたくし⋯⋯\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nもっております⋯⋯\pどうか　わたくしと\nタッグを　くんでいただけませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "ありがとうございます⋯⋯\nうけつけで　とうろくを　してきます⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "あなたと　タッグを\nくみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "やあ！\pぼく\nポケモンブリーダー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "ぼくは　いま\n{STR_VAR_1}を　もつ　{STR_VAR_2}とね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nそだてているんだ！\pどう？\pぼくと\nいっしょに　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "ありがとう！\pでは　さっそく\nうけつけで　とうろくを　すませてきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "きみと　いっしょに　タッグを\nくみたかったよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "こんにちは！\pわたし\nトライアスリート　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "わたしは\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれて　はしっているの！\pどう？\nわたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "やったね！\pじゃ　さっそく　うけつけで\nとうろくを　すませてくるわー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "わたしと　タッグを　くんだら\nさいこうなのに　ざんねんね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "やあ！\pぼく\nトライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "ぼく\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれて　はしっているんだ！\pどうだい？\nぼくと　タッグを　くんでみないかい？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "やったー！\pいま　うけつけで\nとうろくを　すませてくるよー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "きみと　タッグを　くんで\nいっしょに　たたかいたかったよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "わたし\nバトルガール　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "わたし\n{STR_VAR_1}を　もつ　{STR_VAR_2}⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nきたえているの！\pどう？\nわたしと　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "ありがとう！\pいまから　うけつけで\nとうろくを　すませてくるからねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "あなたとなら　さいきょうの　タッグを\nくめると　おもったのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "オレ\nトライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "オレ\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれて　はしっているんだぜ！\pどうだい？\nオレと　いっしょに　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "サンキュー！\pいまから　うけつけで\nとうろくを　すませてくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "きみとなら　さいきょうの　タッグを\nくめたのに　ざんねんだよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "ぼくはね⋯⋯\nうきわボーイ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "ぼくは\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれているんだよ！\pねぇ？\nぼくと　いっしょに　タッグを　くもうよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "やったねー！\pうけつけで　とうろく　してくるよー！\nがんばろうねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "ぼくの　ポケモン　とっても　つよいのに⋯⋯\nタッグに　なれなくて　ざんねん！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "イエーイ！\pオレは\nギタリスト　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "オレは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\nつれているんだぜー！\pイエーイ？\nオレと　いっしょに　タッグを　くもうぜ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "イエーイ！\pいまから\nうけつけで　とうろく　してくるぜー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "オレの　ポケモン　とっても　つよいぜー！\nこうかい　しないように　するんだぜー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "こんにちは\pジェントルマン　{STR_VAR_1}と\nもうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "わたくし\n{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}を\nつれておりますぞ！\pどうですかな？\nわたくしの　パートナーに　なりませんかな？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "よろしく　おねがいしますぞ！\pでは\nうけつけで　とうろく　してきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "ざんねん　ですな⋯⋯\nつぎの　きかいを　きたいして　おりますぞ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "わたくし\nだいすきクラブの　{STR_VAR_1}と\lもうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "わたくしは　いま\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\nつれて　おります！\pどうでしょう？\nわたくしと　タッグを　くみませんかな？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "ありがとう　ございます！\nそれでは　とうろくに　いってまいります！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "わたくしの　ポケモン\nさいこうなのに　ざんねんです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "うむ！\pわしは\nたつじん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "わしの　きたえあげた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}じゃ\pどうじゃ？\nわしと　タッグを　くまぬか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "うむ！\pいまから　とうろくを　すませてくるぞ！\nおたがい　がんばろうぞ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "おぬしの　せんたくが\nただしいことを　いのっておるぞ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "⋯⋯はいはい\pわたしは\nたつじん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "わたしの　きたえあげた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　ですよ\pどうですかね？\nわたしと　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "⋯⋯はいはい\nいまから　とうろくを　してきますよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "つぎに　あったときには\nタッグを　くみたいものですね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "オレは\nドラゴンつかい　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "オレの　きたえあげた　ポケモンは\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　だ！\pどうだ？\nオレと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "⋯⋯よしっ！　がんばるぜー！\pすぐに　とうろくを　すませて　くるからな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "オレより　つよい　パートナーは\nそうそう　いないぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "ぼくは\nとりつかい　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "ぼくの　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だね\pどうだい？\nボクと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "ありがとー！\pいまから　とうろくを　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "ぼくの　ポケモン\nほんとに　つよいのに　ざんねんだよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "ぼく\nにんじゃごっこ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "ぼくの　もっている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だよ\pねー？\nぼくと　タッグを　くもうよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "やったー！\nすぐ　とうろくを　してくるねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "ぼくの　ポケモンの　つよさに\nきっと　こうかい　するよー$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "こんにちは！\pわたし\nパラソルおねえさん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "わたしは　いま\n{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}を\nつれているの！\pどう？\nわたしの　ポケモンと　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "ありがとうねー！\pいま　うけつけで　とうろく　してくるから\nがんばろうねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "あたしの　ポケモン　とっても　つよいのに\nざんねんよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "わたしは\nこんちゅうマニア　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "わたしの　みつけた　ポケモンは\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　ですよ！\pどうですか？\nわたしと　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "はい！\nりょうかい　しました\pいま　とうろくを　してきますからね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "わたしが　みつけた　ポケモンと　くめば\nまけないのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "オッス！\pオレは\nふなのり　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "オレの　じまんの　ポケモンは\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　だ！\pなあ！　\nもちろん　オレと　タッグを　くむだろう？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "とうぜん　だよな！\nいまから　とうろく　してくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "オレと　くんだら　らくしょう　なのに\nざんねん　だぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "やあ\pぼくは\nポケモンコレクター　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "ぼくの　じまんの　ポケモンは\n{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}だよ\pどうだい？\nぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "おおー！\pじゃあ　さっそく　うけつけで\nとうろく　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "ぼくの　ポケモンの　みりょくに\nきが　つかないなんて　ガッカリだよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "ぼくは\nポケモンレンジャー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "ぼくの　つれている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ！\pどうだい？\nぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "よしー！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "つぎに　あったときは\nぼくの　ポケモン　えらんでくれよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "わたしは\nポケモンレンジャー　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "わたしが　つれている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ！\pどう？\nわたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "がんばるわよー！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "つぎこそ\nわたしの　ポケモンを　えらんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "わたくし\nアロマなおねえさん　{STR_VAR_1}と\lもうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "わたくしの　つれている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}です\pどうでしょう？\nわたくしと　タッグを　くんでみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "こうえいです\nすぐ　うけつけで　とうろく　してきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "つぎに　おあいした　ときには\nタッグを　くみたいものですね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "わし\nいせきマニア　{STR_VAR_1}じゃ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "わしの　もっている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}じゃ！\pどうじゃ？\nわしと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "よしよし！\nすぐ　うけつけで　とうろく　してくるぞい！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "うーむ⋯⋯\nわしの　ポケモン　つよいと　おもうぞ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "ぼく\nエリートトレーナー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "ぼくの　つれている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だよ\pどう？\nぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "よしっ！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "きみとなら　さいきょうの　チームに　なると\nおもったんだけどな⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "わたしは\nエリートトレーナー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "わたしの　そだてた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\pどう？\nわたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "やったわ！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "あなたとなら　つよい　タッグチームが\nできると　おもったのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "オレは\nかいじゅうマニア　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "オレの　もっている　ポケモンは\n{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}だ！\pどうだ？\nオレと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "やったぜ！\nすぐ　うけつけで　とうろく　してくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "オレの　ポケモン　つよいぞ！\nこうかい　しても　しらないぞ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "オレ\nキャンプファイヤー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "オレの　そだてあげた　ポケモンは\n{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}　だよ\pどうだい？\nオレと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "やったー！\nいま　うけつけで　とうろく　してくるからな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "つぎに　あったときには\nタッグを　くんでくれよな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "ぼくは\nキャンプボーイ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "ぼくの　そだてた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\pどう？\nぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "やったね！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "つぎに　あったときには\nタッグを　くんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "わたしは\nピクニックガール　{STR_VAR_1}です！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "わたしの　つれている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}です\pどうすか？\nわたしと　タッグを　くんでみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "ありがとうございます！\nすぐ　うけつけで　とうろく　してきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "つぎに　あったときには\nタッグを　くんでくださいね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "ぼくは\nサイキッカー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "ぼくの　そだてた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\pどう？\nぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "やったね！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "つぎに　あったときには\nタッグを　くみたいね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "わたし\nサイキッカー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "わたしが　つれている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ！\pどう？\nわたしと　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "ありがとう！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "つぎに　あったときには\nタッグを　くみたいわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "わたし\nじゅくがえり　{STR_VAR_1}です！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "わたしの　つれている　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}です！\pどうですか？\nわたしと　タッグを　くんでくれませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "ありがとうございます！\nすぐ　うけつけで　とうろく　してきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "つぎに　あったときには\nタッグを　くんでくださいね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "わたし\nポケモンブリーダー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "わたしの　そだてた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　なの\pどう？\nわたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "やったね！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "つぎに　あったときには\nぜったいに　タッグを　くんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "わたくし\nだいすきクラブ　{STR_VAR_1}と\lもうしますのよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "わたくしの　そだてた　ポケモンちゃんは\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　ですの\pどうでしょう？\nわたくしと　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "ありがとうございます！\pわたくし　さっそく\nうけつけで　とうろく　してきますわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "わたくしの　ポケモンちゃん\nさいこうなのに　ざんねんです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "わたし\nビキニのおねえさん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "わたしの　そだてた　ポケモンは\n{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}よっ\pどう？\nわたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "やったねっ！\nすぐ　うけつけで　とうろく　してくるねっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "つぎに　あったときには\nタッグを　くんでよねっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "オレ\nトライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "オレの　そだてた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\pどう？\nオレと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "やったね！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "つぎに　あったときには\nタッグを　くんでくれよな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "わたし\nトライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "わたしの　そだてた　ポケモンは\n{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\pどう？\nわたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "やったね！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "つぎに　あったときには\nタッグを　くんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "オレ\nかいパンやろう　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "オレが　そだてた　ポケモンは\n{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}だよ\pどう？\nオレと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "やったね！\nすぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "つぎに　あったときには\nタッグを　くんでくれよな！$"
