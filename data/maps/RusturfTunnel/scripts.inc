@ RusturfTunnel scripts (JP map g24 m4 @ 0x082135F0)

RusturfTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_EventScript_0021360D
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_MapScriptTable_002135FB
	.byte 0

RusturfTunnel_MapScriptTable_002135FB::
	map_script_2 0x409A, 0x4, RusturfTunnel_EventScript_00213677
	map_script_2 0x409A, 0x5, RusturfTunnel_EventScript_00213677
	.2byte 0

RusturfTunnel_EventScript_0021360D::
	compare_var_to_value 0x409A, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213619
	end

RusturfTunnel_EventScript_00213619::
	setobjectxyperm 0x7, 0xD, 0x4
	setobjectxyperm 0x6, 0xD, 0x5
	return

RusturfTunnel_EventScript_00213628::
	lock
	faceplayer
	loadword 0x0, gJPText_00213CF3
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RusturfTunnel_EventScript_0021363F::
	lock
	faceplayer
	checkflag 0x1
	goto_if 0x1, RusturfTunnel_EventScript_00213662
	setflag 0x1
	loadword 0x0, gJPText_00213B76
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RusturfTunnel_EventScript_00213662::
	loadword 0x0, gJPText_00213C05
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

RusturfTunnel_EventScript_00213677::
	lockall
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RusturfTunnel_EventScript_00213770
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213785
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_00213790
	call RusturfTunnel_EventScript_002137C8
	loadword 0x0, gJPText_00213C3E
	callstd 0x4
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213791
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_00213791
	setorcopyvar 0x8000, 0x156
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x6A
	loadword 0x0, gJPText_00213C7B
	callstd 0x4
	closemessage
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RusturfTunnel_EventScript_00213726
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_00213738
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_00213754
	loadword 0x0, gJPText_00213CB3
	callstd 0x4
	closemessage
	compare_var_to_value 0x4001, 0x1
	call_if 0x1, RusturfTunnel_EventScript_0021379D
	compare_var_to_value 0x4001, 0x2
	call_if 0x1, RusturfTunnel_EventScript_002137AF
	compare_var_to_value 0x4001, 0x3
	call_if 0x1, RusturfTunnel_EventScript_002137AF
	call 0x08243299
	releaseall
	end

RusturfTunnel_EventScript_00213726::
	applymovement 0xFF, RusturfTunnel_Movement_PlayerWatchBoyfriend1
	applymovement 0x1, RusturfTunnel_Movement_BoyfriendApproachWanda1
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213738::
	applymovement 0xFF, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement 0x1, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0x0
	applymovement 0xA, 0x0824362D
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213754::
	applymovement 0xFF, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement 0x1, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0x0
	applymovement 0xA, 0x0824362D
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213770::
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213785::
	applymovement 0x1, RusturfTunnel_Movement_BoyfriendFaceRight
	waitmovement 0x0
	return

RusturfTunnel_EventScript_00213790::
	return

RusturfTunnel_EventScript_00213791::
	closemessage
	applymovement 0x1, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
	waitmovement 0x0
	return

RusturfTunnel_EventScript_0021379D::
	applymovement 0xA, RusturfTunnel_Movement_WandaExit1
	applymovement 0x1, RusturfTunnel_Movement_WandasBoyfriendExit1
	waitmovement 0x0
	return

RusturfTunnel_EventScript_002137AF::
	applymovement 0xFF, RusturfTunnel_Movement_PlayerWatchWandaExit
	applymovement 0xA, RusturfTunnel_Movement_WandaExit
	applymovement 0x1, RusturfTunnel_Movement_WandasBoyfriendExit
	waitmovement 0x0
	return

RusturfTunnel_EventScript_002137C8::
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	return

RusturfTunnel_Movement_WandaExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandaExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerWatchWandaExit:
	delay_8
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused2:
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused3:
	walk_up
	walk_in_place_faster_down
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend:
	walk_right
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BoyfriendFaceRight:
	walk_up
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
	walk_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda1:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

RusturfTunnel_EventScript_0021383A::
	setvar 0x4001, 0x1
	end

RusturfTunnel_EventScript_00213840::
	setvar 0x4001, 0x2
	end

RusturfTunnel_EventScript_00213846::
	setvar 0x4001, 0x3
	end

RusturfTunnel_EventScript_0021384C::
	lockall
	loadword 0x0, gJPText_00213991
	callstd 0x4
	closemessage
	applymovement 0x6, RusturfTunnel_Movement_GruntAndPeekoBackUp
	applymovement 0x7, RusturfTunnel_Movement_GruntAndPeekoBackUp
	waitmovement 0x0
	moveobjectoffscreen 0x6
	moveobjectoffscreen 0x7
	setvar 0x409A, 0x3
	releaseall
	end

RusturfTunnel_Movement_GruntAndPeekoBackUp:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_00213878::
	lock
	faceplayer
	waitse
	playmoncry 0x135, 0x0
	loadword 0x0, gJPText_002139A1
	callstd 0x4
	waitdooranim
	release
	end

RusturfTunnel_EventScript_0021388B::
	lock
	faceplayer
	playbgm 0x1A3, 0x0
	loadword 0x0, gJPText_002139B0
	callstd 0x4
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, 0x10, 0x0, gJPText_00213A18
	loadword 0x0, gJPText_00213A32
	callstd 0x4
	setorcopyvar 0x8000, 0x10D
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	closemessage
	applymovement 0xFF, RusturfTunnel_Movement_PushPlayerAsideForGrunt
	applymovement 0x6, RusturfTunnel_Movement_GruntEscape
	waitmovement 0x0
	removeobject 0x6
	delay 0x32
	addobject 0x5
	applymovement 0x5, RusturfTunnel_Movement_BrineyApproachPeeko1
	waitmovement 0x0
	applymovement 0xFF, RusturfTunnel_Movement_PlayerMoveAsideForBriney
	applymovement 0x5, RusturfTunnel_Movement_BrineyApproachPeeko2
	waitmovement 0x0
	loadword 0x0, gJPText_00213A8C
	callstd 0x4
	applymovement 0x5, 0x08243621
	waitmovement 0x0
	message gJPText_00213A9E
	waitmessage
	waitse
	playmoncry 0x135, 0x0
	waitbuttonpress
	waitdooranim
	closemessage
	applymovement 0xFF, RusturfTunnel_Movement_PlayerWatchBrineyExit
	applymovement 0x5, RusturfTunnel_Movement_BrineyExit
	applymovement 0x7, RusturfTunnel_Movement_PeekoExit
	waitmovement 0x0
	removeobject 0x5
	removeobject 0x7
	clearflag 0x8E
	setflag 0x8F
	setvar 0x405A, 0x4
	setvar 0x4090, 0x1
	setflag 0x37B
	release
	end

RusturfTunnel_Movement_PushPlayerAsideForGrunt:
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_PlayerMoveAsideForBriney:
	walk_down
	walk_in_place_faster_up
	step_end

RusturfTunnel_Movement_GruntEscape:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_BrineyExit:
	walk_left
	walk_left
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

RusturfTunnel_Movement_PlayerWatchBrineyExit:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko2:
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_PeekoExit:
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

RusturfTunnel_EventScript_0021397A::
	trainerbattle TRAINER_BATTLE_SINGLE, 0x27B, 0x0, gJPText_00213D51, gJPText_00213D8C
	loadword 0x0, gJPText_00213D9D
	callstd 0x6
	end

	.globl gJPText_00213991
gJPText_00213991: @ 0x08213991
	.string "くるのか？\n"
	.string "くるなら　こいよ！$"

	.globl gJPText_002139A1
gJPText_002139A1: @ 0x082139A1
	.string "ピーコちゃん“ピ　ピひょー！$"

	.globl gJPText_002139B0
gJPText_002139B0: @ 0x082139B0
	.string "えーい　くっそー！\p"
	.string "うばった　ポケモンは\n"
	.string "なんの　やくにも　たたないし\p"
	.string "いいところへ　にげこめたと　おもったのに\n"
	.string "この　トンネル　いきどまり　じゃねーか！\p"
	.string "やい！　おまえ！\n"
	.string "おれと　しょうぶ　するんだな！？$"

	.globl gJPText_00213A18
gJPText_00213A18: @ 0x08213A18
	.string "む　むぐぐー！\n"
	.string "おれの　あくじも　いきどまりかっ！$"

	.globl gJPText_00213A32
gJPText_00213A32: @ 0x08213A32
	.string "おかしいなあ⋯⋯\p"
	.string "リーダーの　はなしでは　なにかの　にもつを\n"
	.string "デボンから　ぬすんでくる　っていう\l"
	.string "らくな　しごと　だった　はずなのに⋯⋯\p"
	.string "ちぇっ！\n"
	.string "こんなもん　かえして　やらあ！$"

	.globl gJPText_00213A8C
gJPText_00213A8C: @ 0x08213A8C
	.string "ピーコちゃん！　ぶじで　よかった！$"

	.globl gJPText_00213A9E
gJPText_00213A9E: @ 0x08213A9E
	.string "あんたは　ピーコちゃんの\n"
	.string "いのちの　おんじん　じゃよ！\p"
	.string "わしは　ハギと　いうのじゃが\n"
	.string "きみは⋯⋯？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "そうか　{STRING 0x01}{STRING 0x05}と　いうのか！\n"
	.string "ほんとうに　ありがとうよ！\p"
	.string "これからさき　こまった　ことが　あったら\n"
	.string "えんりょなく　わしに　いっとくれ！\p"
	.string "いつもは　トウカのもりの　ちかくに　ある\n"
	.string "はまべの　こやに　いるからの！\p"
	.string "さあ　ピーコちゃん\n"
	.string "わしらの　おうちに　かえろうな！\p"
	.string "ピーコちゃん“ピひょーっ！！$"

	.globl gJPText_00213B76
gJPText_00213B76: @ 0x08213B76
	.string "⋯⋯\p"
	.string "どうして　これいじょう　ほれない⋯⋯\n"
	.string "この　いわが　かたすぎるのか？\p"
	.string "このさきの　シダケタウンという　ところに\n"
	.string "あいする　かのじょが　いるのに⋯⋯\p"
	.string "カナズミと　シダケを　トンネルで　むすべば\n"
	.string "まいにち　かのじょに　あいに　いける\p"
	.string "それなのに⋯⋯\n"
	.string "おれは　どうすれば　いいんだ⋯⋯$"

	.globl gJPText_00213C05
gJPText_00213C05: @ 0x08213C05
	.string "カナズミから　シダケに　いこうと　すると\n"
	.string "ムロから　カイナと　キンセツを　とおって\l"
	.string "いかなきゃ　ならないんだ⋯⋯$"

	.globl gJPText_00213C3E
gJPText_00213C3E: @ 0x08213C3E
	.string "なんと！　きみが　この　いわを\n"
	.string "くだいて　くれたんだね\p"
	.string "かんしゃの　しるし　として\n"
	.string "この　ひでんマシンを　うけとってくれ$"

	.globl gJPText_00213C7B
gJPText_00213C7B: @ 0x08213C7B
	.string "そいつには　かいりきが　はいっている\n"
	.string "ちからもちの　ポケモンに　おぼえさせれば\l"
	.string "おおきな　いわを　うごかせるよ$"

	.globl gJPText_00213CB3
gJPText_00213CB3: @ 0x08213CB3
	.string "ミチルさん！\n"
	.string "これから　いつでも　あえます！\p"
	.string "ミチル“よかった⋯⋯　です\p"
	.string "さあ　わたしの　いえで\n"
	.string "ゆっくり　やすんで　ください$"

	.globl gJPText_00213CF3
gJPText_00213CF3: @ 0x08213CF3
	.string "この　いわの　むこうに⋯⋯\n"
	.string "わたしの　かれが　いるの\p"
	.string "かれ⋯⋯　わたしに　あうため　だけに\n"
	.string "トンネルを　ほってるわけ　じゃないわ\p"
	.string "みんなの　ために\n"
	.string "てを　きずつけながらも　がんばってるの$"

	.globl gJPText_00213D51
gJPText_00213D51: @ 0x08213D51
	.string "おとこが　やまに　いるから　やまおとこ！\p"
	.string "なのに　ポケモンが　やまに　いても\n"
	.string "やまポケモンと　いわないのは　なぜだ？$"

	.globl gJPText_00213D8C
gJPText_00213D8C: @ 0x08213D8C
	.string "ポケモン⋯⋯\n"
	.string "ちから　つきた⋯⋯$"

	.globl gJPText_00213D9D
gJPText_00213D9D: @ 0x08213D9D
	.string "ここって　ポケモンを　まもるため\n"
	.string "かいはつ　こうじを　やめたんだろ？\l"
	.string "それって　いい　はなし　だよな$"
