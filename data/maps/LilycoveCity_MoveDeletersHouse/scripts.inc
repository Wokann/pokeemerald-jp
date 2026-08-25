@ LilycoveCity_MoveDeletersHouse scripts (JP map g13 m11 @ 0x08209D70)

LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter:: @ 0x08209D71
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget:: @ 0x08209DA1
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 0x1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove:: @ 0x08209E16
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove:: @ 0x08209E35
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves:: @ 0x08209E42
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain:: @ 0x08209E4C
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf:: @ 0x08209E56
	special BufferMoveDeleterNicknameAndMove
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove: @ 0x08209E63
	.string "えーと⋯⋯\n"
	.string "そうじゃ　わし　わすれじいさん\p"
	.string "ポケモンの　わざを\n"
	.string "わすれさせる　ことが　できるんじゃ！\p"
	.string "わざを　わすれ　させるかね？$"

LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget: @ 0x08209EA5
	.string "どの　ポケモンに　するんじゃ？$"

LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten: @ 0x08209EB5
	.string "どの　わざを\n"
	.string "わすれ　させるんじゃ？$"

LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove: @ 0x08209EC8
	.string "{STR_VAR_1}は　わざを　1つしか\n"
	.string "もってない　ようじゃ⋯⋯$"

LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten: @ 0x08209EE2
	.string "むむ！\n"
	.string "{STR_VAR_1}の　{STR_VAR_2}じゃな？$"

LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove: @ 0x08209EF1
	.string "だいせいこう　じゃ！\p"
	.string "{STR_VAR_1}は　{STR_VAR_2}を\n"
	.string "わすれた　ようじゃ！$"

LilycoveCity_MoveDeletersHouse_Text_ComeAgain: @ 0x08209F0F
	.string "わすれさせたい　わざが　あったら\n"
	.string "また　くるのじゃぞ！$"

LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves: @ 0x08209F2B
	.string "なぬ！？　タマゴは\n"
	.string "わざを　おぼえていない　ようじゃが⋯⋯？$"

LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf: @ 0x08209F4A
	.string "むむ！\p"
	.string "{STR_VAR_1}は　なみのりを\n"
	.string "わすれたくない　ようじゃ！$"
