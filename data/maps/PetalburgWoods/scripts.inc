@ PetalburgWoods scripts (JP map g24 m11 @ 0x08214278)

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_00214279::
	lockall
	call PetalburgWoods_EventScript_002143C6
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0x0
	loadword 0x0, gJPText_002145E0
	callstd 0x4
	closemessage
	playbgm 0x1A3, 0x0
	applymovement 0x3, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0x0
	loadword 0x0, gJPText_00214617
	callstd 0x4
	closemessage
	applymovement 0x3, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0x0
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_0021464B
	callstd 0x4
	closemessage
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0x0
	loadword 0x0, gJPText_00214673
	callstd 0x4
	closemessage
	applymovement 0x3, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0x0
	loadword 0x0, gJPText_00214696
	callstd 0x4
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, 0xA, 0x0, gJPText_002146E2
	applymovement 0x3, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0x0
	call PetalburgWoods_EventScript_002143DA
	applymovement 0xFF, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0x0
	goto PetalburgWoods_EventScript_00214449
	end

PetalburgWoods_EventScript_0021431B::
	lockall
	call PetalburgWoods_EventScript_002143C6
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	loadword 0x0, gJPText_002145E0
	callstd 0x4
	closemessage
	playbgm 0x1A3, 0x0
	applymovement 0x3, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0x0
	loadword 0x0, gJPText_00214617
	callstd 0x4
	closemessage
	applymovement 0x3, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0x0
	applymovement 0x4, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_0021464B
	callstd 0x4
	closemessage
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0x0
	loadword 0x0, gJPText_00214673
	callstd 0x4
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, gJPText_00214696
	callstd 0x4
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, 0xA, 0x0, gJPText_002146E2
	applymovement 0x3, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0x0
	call PetalburgWoods_EventScript_002143DA
	applymovement 0xFF, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0x0
	goto PetalburgWoods_EventScript_00214449
	end

PetalburgWoods_EventScript_002143C6::
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0x0
	loadword 0x0, gJPText_002145D4
	callstd 0x4
	closemessage
	return

PetalburgWoods_EventScript_002143DA::
	loadword 0x0, gJPText_002146F1
	callstd 0x4
	closemessage
	applymovement 0x3, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0x0
	removeobject 0x3
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	loadword 0x0, gJPText_00214780
	callstd 0x4
	setorcopyvar 0x8000, 0x3
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgWoods_EventScript_0021441F
	goto PetalburgWoods_EventScript_0021442D
	end

PetalburgWoods_EventScript_0021441F::
	loadword 0x0, gJPText_0021481D
	callstd 0x4
	goto PetalburgWoods_EventScript_0021442D
	end

PetalburgWoods_EventScript_0021442D::
	loadword 0x0, gJPText_002147D2
	callstd 0x4
	applymovement 0x4, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0x0
	loadword 0x0, gJPText_00214808
	callstd 0x4
	closemessage
	return

PetalburgWoods_EventScript_00214449::
	removeobject 0x4
	setvar 0x4098, 0x1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_002144B2::
	loadword 0x0, gJPText_002149AA
	callstd 0x2
	end

PetalburgWoods_EventScript_002144BB::
	loadword 0x0, gJPText_002149F6
	callstd 0x2
	end

PetalburgWoods_EventScript_002144C4::
	lock
	faceplayer
	checkflag 0x129
	goto_if 0x1, PetalburgWoods_EventScript_002144F3
	loadword 0x0, gJPText_00214A23
	callstd 0x4
	setorcopyvar 0x8000, 0xCD
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x129
	release
	end

PetalburgWoods_EventScript_002144F3::
	loadword 0x0, gJPText_00214A58
	callstd 0x4
	release
	end

PetalburgWoods_EventScript_002144FD::
	loadword 0x0, gJPText_00214AB1
	callstd 0x3
	end

PetalburgWoods_EventScript_00214506::
	loadword 0x0, gJPText_00214B26
	callstd 0x3
	end

PetalburgWoods_EventScript_0021450F::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x268, 0x0, gJPText_00214837, gJPText_0021485F
	loadword 0x0, gJPText_00214879
	callstd 0x6
	end

PetalburgWoods_EventScript_00214526::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, 0x26D, 0x0, gJPText_0021489D, gJPText_002148C3, PetalburgWoods_EventScript_00214567
	specialvar 0x800D, ShouldTryRematchBattle
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgWoods_EventScript_002145BD
	setvar 0x8004, 0x26D
	specialvar 0x800D, IsTrainerRegistered
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgWoods_EventScript_00214591
	loadword 0x0, gJPText_002148D5
	callstd 0x4
	release
	end

PetalburgWoods_EventScript_00214567::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	checkflag 0x12F
	goto_if 0x1, PetalburgWoods_EventScript_00214578
	release
	end

PetalburgWoods_EventScript_00214578::
	loadword 0x0, gJPText_002148F9
	callstd 0x4
	setvar 0x8004, 0x26D
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x26D
	callstd 0x8
	release
	end

PetalburgWoods_EventScript_00214591::
	checkflag 0x12F
	goto_if 0x1, PetalburgWoods_EventScript_002145A4
	loadword 0x0, gJPText_002148D5
	callstd 0x4
	release
	end

PetalburgWoods_EventScript_002145A4::
	loadword 0x0, gJPText_0021491F
	callstd 0x4
	setvar 0x8004, 0x26D
	special SetMatchCallRegisteredFlag
	setorcopyvar 0x8000, 0x26D
	callstd 0x8
	release
	end

PetalburgWoods_EventScript_002145BD::
	trainerbattle TRAINER_BATTLE_REMATCH, 0x26D, 0x0, gJPText_00214945, gJPText_00214968
	loadword 0x0, gJPText_0021497A
	callstd 0x6
	end

	.globl gJPText_002145D4
gJPText_002145D4: @ 0x082145D4
	.string "うーん\n"
	.string "いないなあ⋯⋯$"

	.globl gJPText_002145E0
gJPText_002145E0: @ 0x082145E0
	.string "ねえ　きみきみ　このあたりで\n"
	.string "キノココって　ポケモン　みなかった？\p"
	.string "おじさん　あの　ポケモン　すき　なのよね$"

	.globl gJPText_00214617
gJPText_00214617: @ 0x08214617
	.string "まちぶせ　していたのに\n"
	.string "いつまでも　トウカのもりで　うろうろと⋯⋯\p"
	.string "まちくたびれたから　きてやったぞ！$"

	.globl gJPText_0021464B
gJPText_0021464B: @ 0x0821464B
	.string "やい！　デボンの　けんきゅういん！\p"
	.string "その　しょるいを　こっちに　よこしやがれ！$"

	.globl gJPText_00214673
gJPText_00214673: @ 0x08214673
	.string "ひやー！\p"
	.string "きみ　ポケモントレーナー　だよね\n"
	.string "おじさんを　たすけてよぉ$"

	.globl gJPText_00214696
gJPText_00214696: @ 0x08214696
	.string "⋯⋯ん？　なんだ　おまえ？\n"
	.string "そいつを　かばおう　ってのか？\p"
	.string "アクアだんの　じゃまを　する　やつは\n"
	.string "こどもでも　ようしゃ　しねえ！\l"
	.string "しょうぶ　しやがれ！$"

	.globl gJPText_002146E2
gJPText_002146E2: @ 0x082146E2
	.string "⋯⋯つ　つよい　じゃねーか！$"

	.globl gJPText_002146F1
gJPText_002146F1: @ 0x082146F1
	.string "むむむ⋯⋯　アクアだんの\n"
	.string "じゃまを　するとは　なんて　やつ！\l"
	.string "もう　いっかい　しょうぶ　しろ！\p"
	.string "⋯⋯と　いいたい　ところ　だが\n"
	.string "もう　てもちの　ポケモンは　いない\p"
	.string "それに　カナズミ　シティにも　アクアだんが\n"
	.string "ねらっている　ものが　あるからな！\p"
	.string "きょうは　これぐらいに　しといてやらぁ！$"

	.globl gJPText_00214780
gJPText_00214780: @ 0x08214780
	.string "⋯⋯ふぅ\n"
	.string "あぶない　ところ　だった！\p"
	.string "きみの　おかげで　だいじな　しょるいを\n"
	.string "うばわれないで　すんだよ！\p"
	.string "⋯⋯そうだ！　おれいに\n"
	.string "スーパーボールを　あげちゃおう！$"

	.globl gJPText_002147D2
gJPText_002147D2: @ 0x082147D2
	.string "⋯⋯そういえば　さっき　アクアだんは\n"
	.string "‘カナズミにも　ねらっている　ものがある’\l"
	.string "とか　いってたよね⋯⋯？$"

	.globl gJPText_00214808
gJPText_00214808: @ 0x08214808
	.string "たいへんだ！！\n"
	.string "こうしちゃ　いられない！$"

	.globl gJPText_0021481D
gJPText_0021481D: @ 0x0821481D
	.string "どうぐ　いっぱいで\n"
	.string "スーパーボール　あげられないね$"

	.globl gJPText_00214837
gJPText_00214837: @ 0x08214837
	.string "ポケモン　いっぱい　つかまえた！\p"
	.string "そら　いけ！\n"
	.string "ぼくの　むしポケモン　チーム！$"

	.globl gJPText_0021485F
gJPText_0021485F: @ 0x0821485F
	.string "こんなに　ポケモン　いるのに\n"
	.string "かてなかったのか⋯⋯$"

	.globl gJPText_00214879
gJPText_00214879: @ 0x08214879
	.string "たくさん　ポケモン　つかまえたら\n"
	.string "モンスターボール　なくなっちゃったよ$"

	.globl gJPText_0021489D
gJPText_0021489D: @ 0x0821489D
	.string "むしポケモンを　がっこうに　もっていくと\n"
	.string "それだけで　にんきもの　だろ！？$"

	.globl gJPText_002148C3
gJPText_002148C3: @ 0x082148C3
	.string "まけると　にんきものに　なれないや$"

	.globl gJPText_002148D5
gJPText_002148D5: @ 0x082148D5
	.string "でかい　むしポケモン　もってると\n"
	.string "それだけで　そんけー　されるだろ！？$"

	.globl gJPText_002148F9
gJPText_002148F9: @ 0x082148F9
	.string "むしポケモン　そだったら　また　しょうぶだ！\n"
	.string "ポケナビに　とうろく　するぞ$"

	.globl gJPText_0021491F
gJPText_0021491F: @ 0x0821491F
	.string "むしポケモン　そだったら　また　しょうぶだ！\n"
	.string "ポケナビに　とうろく　するぞ$"

	.globl gJPText_00214945
gJPText_00214945: @ 0x08214945
	.string "ぼくの　むしポケモン　そだったぞ！\n"
	.string "これで　また　にんきもの　だぜ！$"

	.globl gJPText_00214968
gJPText_00214968: @ 0x08214968
	.string "まけると　にんきものに　なれないや$"

	.globl gJPText_0021497A
gJPText_0021497A: @ 0x0821497A
	.string "つよい　ポケモン　もってると\n"
	.string "にんきものに　なれるだろ？\l"
	.string "だから　がんばって　そだててるのさ！$"

	.globl gJPText_002149AA
gJPText_002149AA: @ 0x082149AA
	.string "よお！　おまえの　ポケモン　げんき？\p"
	.string "てもちの　ポケモンが　よわっていて\n"
	.string "たたかわせたく　ないときは　なるべく\l"
	.string "くさむらを　よけて　あるくと　いいよ！$"

	.globl gJPText_002149F6
gJPText_002149F6: @ 0x082149F6
	.string "みえて　いなくても\n"
	.string "どうぐが　おちてることが　あるから\l"
	.string "あしもとを　しらべて　いるんだ！$"

	.globl gJPText_00214A23
gJPText_00214A23: @ 0x08214A23
	.string "それって　カナズミの　ジムバッジ！\p"
	.string "あなた　トレーナーなのね\n"
	.string "この　どうぐ　つかってみたら　どうかしら？$"

	.globl gJPText_00214A58
gJPText_00214A58: @ 0x08214A58
	.string "きせきのタネを\n"
	.string "ポケモンに　もたせてあげると　くさタイプの\l"
	.string "わざの　いりょくが　あがるのよ\p"
	.string "きせきのタネの　ほかにも\n"
	.string "ポケモンに　もたせると　べんりな\l"
	.string "どうぐが　あるらしいわね$"

	.globl gJPText_00214AB1
gJPText_00214AB1: @ 0x08214AB1
	.string "おとくな　けいじばん！！\p"
	.string "しょうぶの　とき\n"
	.string "いちど　でも　かおをだした　ポケモンは\l"
	.string "けいけんちが　もらえます！\p"
	.string "よわい　ポケモンを　リストの　ひだりにして\n"
	.string "しょうぶのとき　すぐに　こうたい！\l"
	.string "これで　よわい　ポケモンも　そだちます！$"

	.globl gJPText_00214B26
gJPText_00214B26: @ 0x08214B26
	.string "おとくな　けいじばん！！\p"
	.string "ポケモンには　ヒットポイントの　ほかに\n"
	.string "わざを　くりだす　ちからの　もと\l"
	.string "パワーポイント　というものが　あります\p"
	.string "わざの　パワーポイントが　なくなったときも\n"
	.string "ポケモンセンターに　いきましょう！$"
