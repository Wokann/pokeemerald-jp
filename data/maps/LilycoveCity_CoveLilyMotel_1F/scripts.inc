@ LilycoveCity_CoveLilyMotel_1F scripts (JP map g13 m0 @ 0x082054FC)

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner:: @ 0x082054FD
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted:: @ 0x08205537
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear:: @ 0x0820555E
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV:: @ 0x08205585
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot: @ 0x082055D8
	.string "ほほう　ポケモンの　みりょくで\n"
	.string "おきゃくさまが　ばいぞう　したって！？\p"
	.string "そうかあ　うちも　かわいい　ポケモンを\n"
	.string "りょかんの　マスコットに　すれば\p"
	.string "もっと　たくさんの　おきゃくさまが\n"
	.string "とまりに　きてくれるように　なるかな？$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua: @ 0x08205647
	.string "あ　ごめん　ごめん！\n"
	.string "テレビに　むちゅう　だったもんで！\p"
	.string "アクアだん　とかいう　れんちゅうが\n"
	.string "まちに　やってきた　おかげで\l"
	.string "かんこうきゃくも　さっぱり　なんだよね$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV: @ 0x08205699
	.string "あー　ちょっと　じゃま　しないで！\n"
	.string "テレビが　みえない　じゃないか！$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem: @ 0x082056BC
	.string "なんと！　なくした　どうぐを\n"
	.string "ポケモンが　ひろって　きたって！？\p"
	.string "そうかあ　うちも　そんな\n"
	.string "かしこい　ポケモンが　いてくれれば\p"
	.string "おきゃくさまの　なくした　ものも\n"
	.string "すぐに　みつかるのになぁ⋯⋯$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted: @ 0x0820571C
	.string "あ　ごめん　ごめん！\n"
	.string "テレビに　むちゅう　だったもんで！\p"
	.string "そういえば　だれかが　アクアだんの\n"
	.string "アジトを　かいめつ　させた　らしいね！\p"
	.string "おかげで　さっき　だんたいさん　からの\n"
	.string "しゅくはく　よやくが　はいったよ！\p"
	.string "たしか⋯⋯　ゲームなんとか　っていう\n"
	.string "かいしゃ　だったかな⋯⋯$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar: @ 0x082057A5
	.string "なんと！　しのびこんだ　どろぼうを\n"
	.string "るすばんの　ポケモンが　つかまえたって！？\p"
	.string "そうかあ　うちも　ガードマンの　かわりに\n"
	.string "つよい　ポケモンが　いてくれれば\p"
	.string "おきゃくさまの　あんぜんを\n"
	.string "まもることが　できそうだなぁ⋯⋯$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner: @ 0x08205812
	.string "あ　ごめん　ごめん！\n"
	.string "テレビに　むちゅう　だったもんで！\p"
	.string "そういえば　さっき\n"
	.string "だんたいさん　が　とうちゃく　したよ！\p"
	.string "ゲームフリークって　いうから\n"
	.string "ゲームの　かいしゃの　ひとたち　かなぁ？\l"
	.string "ああ　ごはんの　じゅんびを　しなくちゃ⋯⋯$"
