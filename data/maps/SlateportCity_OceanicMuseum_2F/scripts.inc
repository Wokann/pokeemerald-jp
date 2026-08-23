@ SlateportCity_OceanicMuseum_2F scripts (JP map g9 m8 @ 0x081FD309)

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_001FD30A::
	lock
	faceplayer
	loadword 0x0, gJPText_001FD597
	callstd 0x4
	closemessage
	playbgm 0x1A3, 0x1
	addobject 0x3
	applymovement 0x3, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0x0
	addobject 0x4
	applymovement 0x4, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0x0
	applymovement 0x3, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement 0x4, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0x0
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, SlateportCity_OceanicMuseum_2F_EventScript_001FD49C
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, SlateportCity_OceanicMuseum_2F_EventScript_001FD49C
	loadword 0x0, gJPText_001FD5F3
	callstd 0x4
	compare_var_to_value 0x800C, 0x4
	call_if 0x5, SlateportCity_OceanicMuseum_2F_EventScript_001FD4A7
	loadword 0x0, gJPText_001FD60B
	callstd 0x4
	loadword 0x0, gJPText_001FD61D
	callstd 0x4
	closemessage
	applymovement 0x4, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0x0
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, SlateportCity_OceanicMuseum_2F_EventScript_001FD4B2
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, SlateportCity_OceanicMuseum_2F_EventScript_001FD4BD
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, 0x14, 0x0, gJPText_001FD64E
	loadword 0x0, gJPText_001FD661
	callstd 0x4
	closemessage
	applymovement 0x4, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0x0
	applymovement 0x3, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0x0
	loadword 0x0, gJPText_001FD678
	callstd 0x4
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, 0x15, 0x0, gJPText_001FD699
	applymovement 0x3, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0x0
	applymovement 0x3, 0x0824362D
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_001FD6AC
	callstd 0x4
	closemessage
	delay 0x23
	addobject 0x2
	applymovement 0x2, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement 0x4, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0x0
	loadword 0x0, gJPText_001FD6F5
	callstd 0x4
	closemessage
	applymovement 0x2, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0x0
	loadword 0x0, gJPText_001FD72A
	callstd 0x4
	closemessage
	savebgm 0x0
	fadedefaultbgm
	fadescreen 0x1
	removeobject 0x2
	removeobject 0x3
	removeobject 0x4
	fadescreen 0x0
	delay 0x1E
	setflag 0x373
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, gJPText_001FD871
	callstd 0x4
	setvar 0x8004, 0x10D
	call 0x08243467
	loadword 0x0, gJPText_001FD8E0
	callstd 0x4
	closemessage
	fadescreen 0x1
	playfanfare 0x170
	waitfanfare
	special HealPlayerParty
	removeobject 0x1
	setflag 0x384
	compare_var_to_value 0x40DA, 0x0
	call_if 0x1, SlateportCity_OceanicMuseum_2F_EventScript_001FD496
	setflag 0x95
	clearflag 0x3B3
	setflag 0x3B5
	setvar 0x40D2, 0x1
	fadescreen 0x0
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD496::
	setvar 0x40DA, 0x1
	return

SlateportCity_OceanicMuseum_2F_EventScript_001FD49C::
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	return

SlateportCity_OceanicMuseum_2F_EventScript_001FD4A7::
	applymovement 0x1, 0x08243627
	waitmovement 0x0
	return

SlateportCity_OceanicMuseum_2F_EventScript_001FD4B2::
	applymovement 0xFF, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0x0
	return

SlateportCity_OceanicMuseum_2F_EventScript_001FD4BD::
	applymovement 0xFF, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0x0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_001FD514::
	loadword 0x0, gJPText_001FD9B0
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD51D::
	loadword 0x0, gJPText_001FD9F8
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD526::
	loadword 0x0, gJPText_001FDA3F
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD52F::
	loadword 0x0, gJPText_001FDAC0
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD538::
	loadword 0x0, gJPText_001FDAF8
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD541::
	loadword 0x0, gJPText_001FDB4B
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD54A::
	loadword 0x0, gJPText_001FDB95
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD553::
	loadword 0x0, gJPText_001FDBD1
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD55C::
	loadword 0x0, gJPText_001FDC0D
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD565::
	loadword 0x0, gJPText_001FDC3E
	callstd 0x3
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD56E::
	loadword 0x0, gJPText_001FD94A
	callstd 0x2
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD577::
	loadword 0x0, gJPText_001FD977
	callstd 0x2
	end

SlateportCity_OceanicMuseum_2F_EventScript_001FD580::
	lock
	faceplayer
	loadword 0x0, gJPText_001FD997
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

	.globl gJPText_001FD597
gJPText_001FD597: @ 0x081FD597
	.string "はい？　クスノキは　わたし　だが⋯⋯？\p"
	.string "おお！　それは　デボンの　ツワブキさんに\n"
	.string "たのんで　おいた　パーツだね！\p"
	.string "いやー　どうも　ごくろうさま！\n"
	.string "おかげで　しゅっぱつ　できそうだ⋯⋯$"

	.globl gJPText_001FD5F3
gJPText_001FD5F3: @ 0x081FD5F3
	.string "へへへ　その　パーツ\n"
	.string "おれたちが　いただくぜ！$"

	.globl gJPText_001FD60B
gJPText_001FD60B: @ 0x081FD60B
	.string "クスノキ“だ　だれだ　きみたちは！$"

	.globl gJPText_001FD61D
gJPText_001FD61D: @ 0x081FD61D
	.string "おれたち　アクアだん！\p"
	.string "リーダーが　そのパーツを　ほしがってるんだ！\n"
	.string "なにも　いわずに　よこせ！$"

	.globl gJPText_001FD64E
gJPText_001FD64E: @ 0x081FD64E
	.string "うわー！\n"
	.string "こどもに　やられちまった！$"

	.globl gJPText_001FD661
gJPText_001FD661: @ 0x081FD661
	.string "やばい⋯⋯\n"
	.string "リーダーに　おこられちまうぞ⋯⋯$"

	.globl gJPText_001FD678
gJPText_001FD678: @ 0x081FD678
	.string "ふん！　だらしない　やつめ！\n"
	.string "ここは　おれに　まかせてもらうぜ！$"

	.globl gJPText_001FD699
gJPText_001FD699: @ 0x081FD699
	.string "なんだと！\n"
	.string "おれも　まけてしまった！$"

	.globl gJPText_001FD6AC
gJPText_001FD6AC: @ 0x081FD6AC
	.string "ど　どうしよう⋯⋯\n"
	.string "パーツを　うばえないと　まずくないか？\p"
	.string "うむ⋯⋯\n"
	.string "まさか　こどもに　じゃま　されるなんて\l"
	.string "これっぽっちも　おもってなかったぜ$"

	.globl gJPText_001FD6F5
gJPText_001FD6F5: @ 0x081FD6F5
	.string "パーツを　うばうのに\n"
	.string "いつまで　かかっているのかと　おもえば\l"
	.string "こんな　こどもに　じゃま　されていたのか？$"

	.globl gJPText_001FD72A
gJPText_001FD72A: @ 0x081FD72A
	.string "われわれは\n"
	.string "うみを　あいする　アクアだん！\p"
	.string "そして　おれは\n"
	.string "アクアだんの　リーダー　アオギリだ\p"
	.string "われわれの　じゃまをする　おまえは⋯⋯\n"
	.string "ま　まさか！\l"
	.string "マグマだんの　なかま　なのか！？\p"
	.string "いや　それにしては\n"
	.string "みにつけている　ふくが　ちがうな\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "ポケモンも　ひとも　すべての　いのちは\n"
	.string "うみから　うまれた⋯⋯\p"
	.string "だから　アクアだんは\n"
	.string "うみを　ふやそうと　しているのだよ\p"
	.string "どうだい？\n"
	.string "とても　すばらしい　ことだろう？\p"
	.string "まあ　いい⋯⋯\n"
	.string "まだ　わかい　おまえに\l"
	.string "われわれの　りそうなど　わかるまい⋯⋯\p"
	.string "だが　このさきも　われわれの\n"
	.string "かつどうを　じゃまする　つもりなら\l"
	.string "ただでは　すまさない　からな！\p"
	.string "それだけは　おぼえて　おくのだ！$"

	.globl gJPText_001FD871
gJPText_001FD871: @ 0x081FD871
	.string "クスノキ“きみは⋯⋯\n"
	.string "そうか　{STRING 0x01}{STRING 0x05}　というのか⋯⋯\p"
	.string "いやあ　あぶない　ところ　だった！\n"
	.string "たすけてくれて　ありがとうよ！\p"
	.string "おっと　そうだった！\n"
	.string "デボンに　たのんでおいた　パーツを\l"
	.string "もってきて　くれたの　わすれていたよ！$"

	.globl gJPText_001FD8E0
gJPText_001FD8E0: @ 0x081FD8E0
	.string "クスノキ“おっと！\n"
	.string "こうしちゃ　いられない！\p"
	.string "そろそろ　かいてい　ちょうさに\n"
	.string "しゅっぱつ　する　じかんだ！\p"
	.string "わたしは　これで　しつれい　するけど\n"
	.string "きみは　ゆっくり　かんないを\l"
	.string "けんぶつ　していって　くれたまえ！$"

	.globl gJPText_001FD94A
gJPText_001FD94A: @ 0x081FD94A
	.string "ふねの　もけいを　みておると\n"
	.string "ムロの　ちかくに　ある\l"
	.string "すてられぶねを　おもいだすのう⋯⋯$"

	.globl gJPText_001FD977
gJPText_001FD977: @ 0x081FD977
	.string "はくぶつかんの　なかを\n"
	.string "はしり　まわるんじゃ　ありませんよッ！$"

	.globl gJPText_001FD997
gJPText_001FD997: @ 0x081FD997
	.string "せんすいてい　かっこいー！\n"
	.string "おれも　のりてーよ！$"

	.globl gJPText_001FD9B0
gJPText_001FD9B0: @ 0x081FD9B0
	.string "‘すいしつ　サンプル　1’\n"
	.string "と　かかれた　ラベルが　はってある！\p"
	.string "うみは　みんな　つながって　いるのに\n"
	.string "ちいきに　よって　すこし　ちがうらしい$"

	.globl gJPText_001FD9F8
gJPText_001FD9F8: @ 0x081FD9F8
	.string "‘すいしつ　サンプル　2’\n"
	.string "と　かかれた　ラベルが　はってある！\p"
	.string "ちいきが　ちがえば　うみの　みずの\n"
	.string "しょっぱさも　ちがったり　するのかな？$"

	.globl gJPText_001FDA3F
gJPText_001FDA3F: @ 0x081FDA3F
	.string "ゴムで　できた　ボールが\n"
	.string "ふくらんだり　しぼんだり　している！\p"
	.string "‘うみの　そこには　すいあつ　といって\n"
	.string "　みずじたいの　おもさが　かかります’\p"
	.string "‘あさい　ところでは　すいあつも　かるく\n"
	.string "　ふかい　ところでは　なんまんトン　もの\l"
	.string "　すいあつが　かかるのです’$"

	.globl gJPText_001FDAC0
gJPText_001FDAC0: @ 0x081FDAC0
	.string "‘ホウエン　ちほうの　もけい’\p"
	.string "ホウエンちほう　ぜんたいの　ミニチュアだ！\n"
	.string "ミシロタウンは　どのへん　だろう？$"

	.globl gJPText_001FDAF8
gJPText_001FDAF8: @ 0x081FDAF8
	.string "かいすいの　ながれに　ついての　てんじだ！\p"
	.string "‘うみの　そこに　ちかい　ところ　では\n"
	.string "　みずの　おんどや　えんぶんの　ちがいで\l"
	.string "　うみの　みずが　ながれて　いきます’$"

	.globl gJPText_001FDB4B
gJPText_001FDB4B: @ 0x081FDB4B
	.string "かいすいの　ながれに　ついての　てんじだ！\p"
	.string "‘うみの　ひょうめん　あたり　では\n"
	.string "　かぜの　ちからに　よって\l"
	.string "　うみの　みずが　ながれて　いきます’$"

	.globl gJPText_001FDB95
gJPText_001FDB95: @ 0x081FDB95
	.string "‘れんらくせん　タイドリップごう’\p"
	.string "これは　げんざい　クスノキ　ぞうせんじょで\n"
	.string "つくられている　ふねの　もけい　です！$"

	.globl gJPText_001FDBD1
gJPText_001FDBD1: @ 0x081FDBD1
	.string "‘せんすいてい　かいえん　1ごう’\p"
	.string "うみの　そこを　ちょうさ　するための\n"
	.string "こうせいのう　せんすいていの　もけい　です！$"

	.globl gJPText_001FDC0D
gJPText_001FDC0D: @ 0x081FDC0D
	.string "‘せんすい　ポッド’\p"
	.string "かいていで　さぎょうを　するための\n"
	.string "むじん　こがたポッドの　もけい　です！$"

	.globl gJPText_001FDC3E
gJPText_001FDC3E: @ 0x081FDC3E
	.string "‘サント·アンヌ　ごう’\p"
	.string "せかいを　いっしゅう　している\n"
	.string "ごうか　きゃくせんの　もけい　です！$"
