@ Route116 scripts (JP map g0 m31 @ 0x081EBAB5)

Route116_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_EventScript_001EBAC5
	map_script MAP_SCRIPT_ON_LOAD, Route116_EventScript_001EBAF8
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_MapScriptTable_001EBB0F
	.byte 0

Route116_EventScript_001EBAC5::
	checkflag 0x8F
	call_if 0x1, Route116_EventScript_001EBAF0
	compare_var_to_value 0x4039, 0x1
	call_if 0x1, 0x0824473D
	compare_var_to_value 0x4037, 0x5
	call_if 0x1, 0x08244745
	compare_var_to_value 0x4037, 0x6
	call_if 0x1, 0x08244745
	end

Route116_EventScript_001EBAF0::
	setobjectxyperm 0x15, 0x26, 0xA
	return

Route116_EventScript_001EBAF8::
	compare_var_to_value 0x4037, 0x5
	call_if 0x1, 0x08244389
	compare_var_to_value 0x4037, 0x6
	call_if 0x1, 0x0824439C
	end

Route116_MapScriptTable_001EBB0F::
	map_script_2 0x4039, 0x1, 0x08244749
	.2byte 0

Route116_EventScript_001EBB19::
	lock
	faceplayer
	checkflag 0x8F
	goto_if 0x1, Route116_EventScript_001EBB37
	checkflag 0x8E
	goto_if 0x1, Route116_EventScript_001EBB41
	loadword 0x0, gJPText_001EBFAA
	callstd 0x4
	release
	end

Route116_EventScript_001EBB37::
	loadword 0x0, gJPText_001EC06B
	callstd 0x4
	release
	end

Route116_EventScript_001EBB41::
	loadword 0x0, gJPText_001EBFBC
	callstd 0x4
	release
	end

Route116_EventScript_001EBB4B::
	lock
	faceplayer
	checkflag 0x11F
	goto_if 0x1, Route116_EventScript_001EBBD4
	loadword 0x0, gJPText_001EC094
	callstd 0x4
	goto Route116_EventScript_001EBB64
	end

Route116_EventScript_001EBB64::
	setflag 0x11F
	setorcopyvar 0x8000, 0x9
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route116_EventScript_001EBBE2
	loadword 0x0, gJPText_001EC1A8
	callstd 0x4
	closemessage
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, Route116_EventScript_001EBBBE
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, Route116_EventScript_001EBBBE
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, Route116_EventScript_001EBBBE
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, Route116_EventScript_001EBBC9
	removeobject 0x800F
	clearflag 0x3B5
	setflag 0x100
	release
	end

Route116_EventScript_001EBBBE::
	applymovement 0x800F, Route116_Movement_DevonEmployeeExit
	waitmovement 0x0
	return

Route116_EventScript_001EBBC9::
	applymovement 0x800F, Route116_Movement_DevonEmployeeExitEast
	waitmovement 0x0
	return

Route116_EventScript_001EBBD4::
	loadword 0x0, gJPText_001EC206
	callstd 0x4
	goto Route116_EventScript_001EBB64
	end

Route116_EventScript_001EBBE2::
	loadword 0x0, gJPText_001EC1EC
	callstd 0x4
	release
	end

Route116_Movement_DevonEmployeeExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_DevonEmployeeExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_001EBC00::
	loadword 0x0, gJPText_001EC312
	callstd 0x3
	end

Route116_EventScript_001EBC09::
	loadword 0x0, gJPText_001EC32C
	callstd 0x3
	end

Route116_EventScript_001EBC12::
	loadword 0x0, gJPText_001EC35D
	callstd 0x3
	end

Route116_EventScript_001EBC1B::
	loadword 0x0, gJPText_001EC371
	callstd 0x3
	end

Route116_EventScript_001EBC24::
	loadword 0x0, gJPText_001EC3BD
	callstd 0x3
	end

Route116_EventScript_001EBC2D::
	lock
	faceplayer
	loadword 0x0, gJPText_001EBF46
	callstd 0x4
	setvar 0x406F, 0x2
	release
	end

Route116_EventScript_001EBC3E::
	lockall
	applymovement 0xB, 0x0824362B
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, gJPText_001EBF46
	callstd 0x4
	setvar 0x406F, 0x2
	releaseall
	end

Route116_EventScript_001EBC5F::
	lock
	faceplayer
	checkitem 0xCE, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBC9A
	specialvar 0x800D, FoundBlackGlasses
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBC8B
	loadword 0x0, gJPText_001EC24C
	callstd 0x4
	release
	end

Route116_EventScript_001EBC8B::
	loadword 0x0, gJPText_001EC2BC
	callstd 0x4
	closemessage
	goto Route116_EventScript_001EBCD3
	end

Route116_EventScript_001EBC9A::
	loadword 0x0, gJPText_001EC24C
	callstd 0x4
	loadword 0x0, gJPText_001EC26A
	callstd 0x4
	specialvar 0x800D, FoundBlackGlasses
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBCC4
	loadword 0x0, gJPText_001EC2E9
	callstd 0x4
	release
	end

Route116_EventScript_001EBCC4::
	loadword 0x0, gJPText_001EC27F
	callstd 0x4
	closemessage
	goto Route116_EventScript_001EBCD3
	end

Route116_EventScript_001EBCD3::
	delay 0x14
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, Route116_EventScript_001EBD07
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, Route116_EventScript_001EBD07
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, Route116_EventScript_001EBD07
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, Route116_EventScript_001EBD12
	removeobject 0x800F
	release
	end

Route116_EventScript_001EBD07::
	applymovement 0x800F, Route116_Movement_GlassesManExit
	waitmovement 0x0
	return

Route116_EventScript_001EBD12::
	applymovement 0x800F, Route116_Movement_GlassesManExitEast
	waitmovement 0x0
	return

Route116_Movement_GlassesManExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_GlassesManExitEast:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_001EBD32::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x142, 0x0, 0x0825D643, 0x0825D65E
	loadword 0x0, 0x0825D67E
	callstd 0x6
	end

Route116_EventScript_001EBD49::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x269, 0x0, 0x0825D69F, 0x0825D6BC
	loadword 0x0, 0x0825D6D2
	callstd 0x6
	end

Route116_EventScript_001EBD60::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, 0x111, 0x0, 0x0825D753, 0x0825D77F, Route116_EventScript_001EBDA1
	specialvar 0x800D, ShouldTryRematchBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBDF7
	setvar 0x8004, 0x111
	specialvar 0x800D, sub_0813B518
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route116_EventScript_001EBDCB
	loadword 0x0, 0x0825D795
	callstd 0x4
	release
	end

Route116_EventScript_001EBDA1::
	checkflag 0x12F
	goto_if 0x1, Route116_EventScript_001EBDAC
	release
	end

Route116_EventScript_001EBDAC::
	special sub_080B3F60
	waitmovement 0x0
	loadword 0x0, 0x0825D80A
	callstd 0x4
	setvar 0x8004, 0x111
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x111
	callstd 0x8
	release
	end

Route116_EventScript_001EBDCB::
	checkflag 0x12F
	goto_if 0x1, Route116_EventScript_001EBDDE
	loadword 0x0, 0x0825D795
	callstd 0x4
	release
	end

Route116_EventScript_001EBDDE::
	loadword 0x0, 0x0825D7C6
	callstd 0x4
	setvar 0x8004, 0x111
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x111
	callstd 0x8
	release
	end

Route116_EventScript_001EBDF7::
	trainerbattle TRAINER_BATTLE_REMATCH, 0x111, 0x0, 0x0825D84E, 0x0825D885
	loadword 0x0, 0x0825D89A
	callstd 0x6
	end

Route116_EventScript_001EBE0E::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x277, 0x0, 0x0825D5E4, 0x0825D607
	loadword 0x0, 0x0825D61F
	callstd 0x6
	end

Route116_EventScript_001EBE25::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x25D, 0x0, 0x0825D6F3, 0x0825D718
	loadword 0x0, 0x0825D72C
	callstd 0x6
	end

Route116_EventScript_001EBE3C::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, 0x118, 0x0, 0x0825D8CB, 0x0825D8E9, Route116_EventScript_001EBE7D
	specialvar 0x800D, ShouldTryRematchBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route116_EventScript_001EBED3
	setvar 0x8004, 0x118
	specialvar 0x800D, sub_0813B518
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route116_EventScript_001EBEA7
	loadword 0x0, 0x0825D8F6
	callstd 0x4
	release
	end

Route116_EventScript_001EBE7D::
	checkflag 0x12F
	goto_if 0x1, Route116_EventScript_001EBE88
	release
	end

Route116_EventScript_001EBE88::
	special sub_080B3F60
	waitmovement 0x0
	loadword 0x0, 0x0825D941
	callstd 0x4
	setvar 0x8004, 0x118
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x118
	callstd 0x8
	release
	end

Route116_EventScript_001EBEA7::
	checkflag 0x12F
	goto_if 0x1, Route116_EventScript_001EBEBA
	loadword 0x0, 0x0825D8F6
	callstd 0x4
	release
	end

Route116_EventScript_001EBEBA::
	loadword 0x0, 0x0825D91F
	callstd 0x4
	setvar 0x8004, 0x118
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x118
	callstd 0x8
	release
	end

Route116_EventScript_001EBED3::
	trainerbattle TRAINER_BATTLE_REMATCH, 0x118, 0x0, 0x0825D963, 0x0825D98B
	loadword 0x0, 0x0825D99B
	callstd 0x6
	end

Route116_EventScript_001EBEEA::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x2B7, 0x0, 0x0825D9C3, 0x0825D9E7
	loadword 0x0, 0x0825D9F8
	callstd 0x6
	end

Route116_EventScript_001EBF01::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x2B6, 0x0, 0x0825DA28, 0x0825DA50
	loadword 0x0, 0x0825DA5C
	callstd 0x6
	end

Route116_EventScript_001EBF18::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x2F1, 0x0, 0x0825DA89, 0x0825DA98
	loadword 0x0, 0x0825DAAB
	callstd 0x6
	end

Route116_EventScript_001EBF2F::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x2F2, 0x0, 0x0825DACB, 0x0825DAEE
	loadword 0x0, 0x0825DAFF
	callstd 0x6
	end

	.globl gJPText_001EBF46
gJPText_001EBF46: @ 0x081EBF46
	.string "あああ　なんという　ことだ！\p"
	.string "ピーコちゃんと　さんぽを　していたら\n"
	.string "いきなり　おかしな　やつが　やってきて\p"
	.string "わしの　かわいい　ピーコちゃんが\n"
	.string "うばわれて　しまったのじゃ！\p"
	.string "うおー！　ピーコちゃーん！$"

	.globl gJPText_001EBFAA
gJPText_001EBFAA: @ 0x081EBFAA
	.string "ぬぉー！！\p"
	.string "トンネル　ほりてー！！$"

	.globl gJPText_001EBFBC
gJPText_001EBFBC: @ 0x081EBFBC
	.string "ぬぉー！！\n"
	.string "なんて　ことだ！？\p"
	.string "どうぐも　なにも　つかわずに\n"
	.string "トンネルを　ほっていたのに\l"
	.string "へんな　おとこに　おいだされた！\p"
	.string "あの　トンネルには\n"
	.string "おおきな　ものおとに　はんのう　して\l"
	.string "さわぎだす　ポケモンが　いる\p"
	.string "だから　きかいを　つかっての\n"
	.string "かいはつ　こうじを　やめたのに⋯⋯\p"
	.string "へんに　さわぎを　おこされると\n"
	.string "ポケモンが　おびえないか　しんぱいだ！$"

	.globl gJPText_001EC06B
gJPText_001EC06B: @ 0x081EC06B
	.string "ぬぉー！！\p"
	.string "へんな　おとこが　とびだしていった！\n"
	.string "これで　トンネルを　ほれるよ！$"

	.globl gJPText_001EC094
gJPText_001EC094: @ 0x081EC094
	.string "ああっ！\n"
	.string "きみは！！\p"
	.string "トウカのもりで　たすけてくれた　だけでなく\n"
	.string "ぬすまれた　にもつを　とりかえし\l"
	.string "はたまた　カイナへの　とどけものを\l"
	.string "こころよく　ひきうけてくれた　ひと！！\p"
	.string "クスノキかんちょう　から\n"
	.string "‘にもつが　とどいた’と\l"
	.string "れんらくが　ありましたよ！\p"
	.string "どうも　ありがとう　なのです！\n"
	.string "かんしゃ　かんげき　あめ　あられ　なのです\p"
	.string "そんな　すてきな　トレーナーさんに\n"
	.string "グッド　ニュース！\p"
	.string "さいきん　わがしゃ　では\n"
	.string "あたらしい　モンスターボールの\l"
	.string "かいはつに　せいこう　したのです！\p"
	.string "かんしゃの　きもちとして\n"
	.string "トレーナーさんにも　プレゼント　なのよね！$"

	.globl gJPText_001EC1A8
gJPText_001EC1A8: @ 0x081EC1A8
	.string "あたらしい　モンスターボールは\n"
	.string "カナズミの　フレンドリィ　ショップで\l"
	.string "うってますからね！\p"
	.string "ぜひ　つかって　みてください！\n"
	.string "ではでは⋯⋯$"

	.globl gJPText_001EC1EC
gJPText_001EC1EC: @ 0x081EC1EC
	.string "どうぐ　いっぱいで\n"
	.string "リピートボール　あげられないね$"

	.globl gJPText_001EC206
gJPText_001EC206: @ 0x081EC206
	.string "にもつを　とどけてくれた　ことへの\n"
	.string "かんしゃの　きもちとして\l"
	.string "トレーナーさん　にも　あたらしい\l"
	.string "モンスターボールを　プレゼント　なのよね！$"

	.globl gJPText_001EC24C
gJPText_001EC24C: @ 0x081EC24C
	.string "メガネを　おとしたんだ⋯⋯\n"
	.string "きみも　さがすの　てつだってよ$"

	.globl gJPText_001EC26A
gJPText_001EC26A: @ 0x081EC26A
	.string "その　メガネ⋯⋯？\n"
	.string "ちょっと　みせてよ！$"

	.globl gJPText_001EC27F
gJPText_001EC27F: @ 0x081EC27F
	.string "うーむ⋯⋯\n"
	.string "これは　くろいメガネ　だね\l"
	.string "ぼくが　さがしているのと　ちがうなあ⋯⋯\p"
	.string "ここには　ぼくの　メガネ　ないのかなあ$"

	.globl gJPText_001EC2BC
gJPText_001EC2BC: @ 0x081EC2BC
	.string "うーむ⋯⋯\n"
	.string "どうにも　メガネが　みつからないんだ\l"
	.string "ここには　ぼくの　メガネ　ないのかなあ$"

	.globl gJPText_001EC2E9
gJPText_001EC2E9: @ 0x081EC2E9
	.string "うーむ⋯⋯\n"
	.string "これは　くろいメガネ　だね\l"
	.string "ぼくが　さがしているのと　ちがうなあ⋯⋯$"

	.globl gJPText_001EC312
gJPText_001EC312: @ 0x081EC312
	.string "ここは　116ばん　どうろ\n"
	.string "{ESCAPE 0x02}　カナズミシティ$"

	.globl gJPText_001EC32C
gJPText_001EC32C: @ 0x081EC32C
	.string "カナズミと　シダケを　むすぶ\n"
	.string "‘カナシダ　トンネル’\p"
	.string "かいつう　こうじは　ちゅうしに　なりました$"

	.globl gJPText_001EC35D
gJPText_001EC35D: @ 0x081EC35D
	.string "トンネルこうじ　さぎょういん　つめしょ$"

	.globl gJPText_001EC371
gJPText_001EC371: @ 0x081EC371
	.string "おとくな　けいじばん！\p"
	.string "ポケモンが　しんか　しそうなとき\n"
	.string "Bボタンを　おすと\l"
	.string "びっくりして　しんかを　やめます！\p"
	.string "これを　しんかキャンセルと　いいます$"

	.globl gJPText_001EC3BD
gJPText_001EC3BD: @ 0x081EC3BD
	.string "おとくな　けいじばん！！\p"
	.string "バッグには　いくつかの　ポケットが　あり\n"
	.string "いれる　どうぐの　しゅるい　によって\l"
	.string "それぞれの　ポケットに\l"
	.string "オートで　ぶんるい　されます\p"
	.string "まさに　トレーナーの　ひつじゅひん　です！$"
