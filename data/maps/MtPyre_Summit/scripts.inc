@ MtPyre_Summit scripts (JP map g24 m22 @ 0x08216B74)

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:: @ 0x08216B7A
	call_if_eq VAR_MT_PYRE_STATE, 0x2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions:: @ 0x08216B86
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 0x17, 0x6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 0x16, 0x6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0:: @ 0x08216B95
	lockall
	setvar VAR_0x8008, 0x0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1:: @ 0x08216BA1
	lockall
	setvar VAR_0x8008, 0x1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2:: @ 0x08216BAD
	lockall
	setvar VAR_0x8008, 0x2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits:: @ 0x08216BB9
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 0x32
	call_if_eq VAR_0x8008, 0x0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 0x1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 0x2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 0x14
	setvar VAR_MT_PYRE_STATE, 0x1
	call_if_eq VAR_0x8008, 0x0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 0x1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 0x2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0:: @ 0x08216C5D
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieFacePlayer1:: @ 0x08216C68
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2:: @ 0x08216C69
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0:: @ 0x08216C74
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1:: @ 0x08216C89
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2:: @ 0x08216C94
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan:: @ 0x08216CB9
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza:: @ 0x08216CE4
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale:: @ 0x08216D04
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale:: @ 0x08216D0D
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale:: @ 0x08216D16
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady:: @ 0x08216D1F
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 0x3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned:: @ 0x08216D48
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake:: @ 0x08216D55
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned:: @ 0x08216D5F
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0:: @ 0x08216D69
	lockall
	setvar VAR_0x8008, 0x0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1:: @ 0x08216D75
	lockall
	setvar VAR_0x8008, 0x1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2:: @ 0x08216D81
	lockall
	setvar VAR_0x8008, 0x2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs:: @ 0x08216D8D
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 0x3C
	call_if_eq VAR_0x8008, 0x0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 0x1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 0x2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 0x1E
	call_if_eq VAR_0x8008, 0x0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 0x1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 0x2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0x0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 0x1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 0x2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 0x1E
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 0x3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0:: @ 0x08216E41
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1:: @ 0x08216E5A
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2:: @ 0x08216E73
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0:: @ 0x08216E8C
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1:: @ 0x08216EA5
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2:: @ 0x08216EBE
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0:: @ 0x08216ED7
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1:: @ 0x08216EF3
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2:: @ 0x08216F0F
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1:: @ 0x08216F7A
	trainerbattle_single 0x17, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2:: @ 0x08216F91
	trainerbattle_single 0x18, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3:: @ 0x08216FA8
	trainerbattle_single 0x19, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4:: @ 0x08216FBF
	trainerbattle_single 0x239, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro: @ 0x08216FD6
	.string "くっそー！　マグマだんの　れんちゅうに\n"
	.string "さきを　こされて　しまったが\p"
	.string "オレたちだって　まけちゃ　いないぜ！$"

MtPyre_Summit_Text_Grunt1Defeat: @ 0x0821700C
	.string "おまえ⋯⋯　にげていった　マグマだんが\n"
	.string "もどって　きたのかと　おもったんだよ$"

MtPyre_Summit_Text_Grunt1PostBattle: @ 0x08217033
	.string "たしかに　おまえは　つよいな⋯⋯\n"
	.string "だけど　おれたちは　たくさん　いるんだぞ！$"

MtPyre_Summit_Text_Grunt2Intro: @ 0x0821705A
	.string "おっ　ざんねん　だったな！\p"
	.string "もうすこし　はやく　ここにくれば\n"
	.string "あの　よわっちょろい　マグマだんとの\l"
	.string "しょうぶで　すんだ　はずなのに\p"
	.string "いまごろ　きた　おかげで\n"
	.string "つよい　オレたちが　あいてだぜ！$"

MtPyre_Summit_Text_Grunt2Defeat: @ 0x082170BA
	.string "うーむ⋯⋯　マグマだんに\n"
	.string "あいてを　させれば　よかった⋯⋯$"

MtPyre_Summit_Text_Grunt2PostBattle: @ 0x082170D8
	.string "なにも　しらないくせに\n"
	.string "オレたちの　じゃまを　するんじゃないぜ！$"

MtPyre_Summit_Text_Grunt3Intro: @ 0x082170F9
	.string "おまえ⋯⋯　えんとつやまで　あったな！\p"
	.string "どっちの　だんいん　でもないのに\n"
	.string "なぜ　こんな　ところに　いるんだ！？$"

MtPyre_Summit_Text_Grunt3Defeat: @ 0x08217131
	.string "ぐぐぐ⋯⋯\n"
	.string "じゃまを　するなら　マグマだんに　しろ⋯⋯$"

MtPyre_Summit_Text_Grunt3PostBattle: @ 0x0821714D
	.string "まあいいさ　じかんは　かせげた！\p"
	.string "リーダーの　もくてきの　もの\n"
	.string "うばえた　はずだぜ！$"

MtPyre_Summit_Text_Grunt4Intro: @ 0x08217178
	.string "あっ　わかった！\n"
	.string "あんた　マグマだんに　はいろうと　したけど\l"
	.string "いれて　もらえなかったんでしょ！\p"
	.string "はん！　うちら　アクアだんに　だって\n"
	.string "いれてやんないよ！$"

MtPyre_Summit_Text_Grunt4Defeat: @ 0x082171C5
	.string "そうしたら　アクアだんに　いれて\n"
	.string "やらない　ことも　ないよ⋯⋯$"

MtPyre_Summit_Text_Grunt4PostBattle: @ 0x082171E5
	.string "リーダーと　あたしたち　だんいんとの\n"
	.string "みごとな　コンビネーション　ってわけさ！$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo: @ 0x0821720D
	.string "アオギリ“マグマだんの　マツブサに\n"
	.string "さきを　こされて　しまったが\l"
	.string "われわれも　ようじは　すませたぜ！\p"
	.string "おくりびやまに　まつられて　いた\n"
	.string "べにいろのたま⋯⋯\l"
	.string "たしかに　アオギリが　いただいた！\p"
	.string "ふふふ⋯⋯\n"
	.string "これで　われわれの　もくてきも\l"
	.string "はたせると　いうものだ⋯⋯\p"
	.string "さあ！\n"
	.string "ここは　ひきあげるぞ！$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis: @ 0x082172A1
	.string "ああ　なんという　ことだ⋯⋯！\p"
	.string "あいいろのたま　だけではなく\n"
	.string "べにいろのたま　までもが\l"
	.string "うばわれて　しまうとは⋯⋯\p"
	.string "あいいろのたまと　べにいろのたまが\n"
	.string "はなればなれに　なって　しまうなど\l"
	.string "けっして　あっては　ならないこと⋯⋯\p"
	.string "あの　おとこたちは　ふたつのたまで\n"
	.string "いったい　なにを　するきなのか⋯⋯\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "そういえば　さいしょに　あらわれて\n"
	.string "あいいろのたまを　うばって　いった\l"
	.string "マグマだん　とやらが\l"
	.string "こんなものを　おとしていった⋯⋯\p"
	.string "これが　なんなのか　わたしには　わからん\p"
	.string "おまえさん　よかったら　こいつを\n"
	.string "もらって　おくれ⋯⋯\p"
	.string "もしかすると　なにかの　やくに\n"
	.string "たつのでは　ないだろうか⋯⋯！$"

MtPyre_Summit_Text_OrbsHaveBeenTaken: @ 0x082173D9
	.string "あやしげな　ふたりの　おとこに　うばわれた\n"
	.string "あいいろのたまと　べにいろのたま⋯⋯\p"
	.string "ふたつが　はなればなれ　では\n"
	.string "きっと　よくないことが　おこる⋯⋯$"

MtPyre_Summit_Text_GroudonKyogreAwakened: @ 0x08217423
	.string "なんと⋯⋯\n"
	.string "グラードンと　カイオーガが\l"
	.string "めざめて　しまったと　いうのか⋯⋯\p"
	.string "かつて　2ひきの　ポケモンの\n"
	.string "いかりを　しずめたのが\l"
	.string "あいいろのたまと　べにいろのたまだと\l"
	.string "そう　いわれておる⋯⋯\p"
	.string "そして　そのたまの　しんの　もちぬしが\n"
	.string "どこかに　いると　いうのだが⋯⋯\p"
	.string "それが　ひと　なのか\n"
	.string "あるいは　ポケモン　なのか\p"
	.string "こればっかりは\n"
	.string "だれにも　わからんのだよ⋯⋯$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs: @ 0x082174D8
	.string "ふたつのたまを　うばった　おとこたちが\n"
	.string "みずから　かえしに　くるとは⋯⋯\p"
	.string "あの　ふたり⋯⋯\n"
	.string "あんがい　わるいやつでは　ないのかもな$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs: @ 0x0821751A
	.string "だいちと　うみと　おおぞらの　けしん⋯⋯\p"
	.string "それが　ちょうこだいポケモンの\n"
	.string "しょうたい　とも　いわれておる⋯⋯\p"
	.string "わしら　にんげんや　ポケモンに\n"
	.string "いのちが　あるように\l"
	.string "この　せかいだって　いきている⋯⋯\p"
	.string "ちょうこだいポケモンは　わしたちに\n"
	.string "そのことを　おしえて　くれたのさ⋯⋯$"

MtPyre_Summit_Text_WillYouHearOutMyTale: @ 0x082175A3
	.string "おくりびやまは　ポケモンの　たましいを\n"
	.string "なぐさめる　ための　ところ⋯⋯\p"
	.string "ここは　たかい　ばしょに　あって\n"
	.string "ホウエンを　みわたす　ことが　できるから\l"
	.string "ポケモンたちの　たましいも\l"
	.string "やすらぎを　おぼえるの　じゃろう⋯⋯\p"
	.string "おまえさんが　ここに　きたのも\n"
	.string "なにかの　えん⋯⋯\p"
	.string "ホウエンちほうに　つたわる　はなしを\n"
	.string "きいて　いきなされ⋯⋯$"

MtPyre_Summit_Text_GroudonKyogreTale: @ 0x08217647
	.string "とおい　とおい　おおむかしの　こと⋯⋯\p"
	.string "せかいでは　りくと　うみの　ポケモンが\n"
	.string "はげしい　たたかいを　くりひろげていた\p"
	.string "りくの　ポケモンは\n"
	.string "だいちを　もりあげ　じめんを　ひろげ\p"
	.string "うみの　ポケモンは\n"
	.string "あらなみを　おこして　うみを　ひろげた\p"
	.string "2ひきの　たたかいは　おわることなく\n"
	.string "この　せかいは　もえさかる　ほのおと\l"
	.string "ふきあれる　あらしで　うめつくされた\p"
	.string "それを　しずめたのが\n"
	.string "あいいろのたま　と　べにいろのたま⋯⋯\p"
	.string "ふたつの　たまから　ひろがる　ひかりが\n"
	.string "2ひきの　いかりを　しずめた\p"
	.string "そして　おとなしくなった　2ひきは\n"
	.string "かいてい　ふかく　もぐっていき\l"
	.string "やがて　そのすがたを　けしたのじゃ⋯⋯$"

MtPyre_Summit_Text_WellThatTooIsFine: @ 0x0821776F
	.string "そうかね⋯⋯\n"
	.string "まあ　それも　よいじゃろう⋯⋯$"

MtPyre_Summit_Text_MaxieSilence: @ 0x08217786
	.string "マツブサ“{PLAYER}⋯⋯\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn: @ 0x082177A2
	.string "ホウエンに　のこされた　いいつたえを\n"
	.string "かたりつぐのが　わたしの　やくめ\p"
	.string "そして　いま\n"
	.string "ルネで　おこった　じけんは　まくを　とじ\l"
	.string "いいつたえは　また　ぬりかえられた⋯⋯\p"
	.string "あらたな　ホウエンの　いいつたえを\n"
	.string "きいて　いきなされ⋯⋯$"

MtPyre_Summit_Text_HoennTrioTale: @ 0x08217814
	.string "とおい　とおい　おおむかしの　こと⋯⋯\p"
	.string "せかいでは　りくと　うみの　ポケモンが\n"
	.string "はげしい　たたかいを　くりひろげていた\p"
	.string "りくの　ポケモンは\n"
	.string "だいちを　もりあげ　じめんを　ひろげ\p"
	.string "うみの　ポケモンは\n"
	.string "あらなみを　おこして　うみを　ひろげた\p"
	.string "2ひきの　たたかいは　おわることなく\n"
	.string "この　せかいは　もえさかる　ほのおと\l"
	.string "ふきあれる　あらしで　うめつくされた\p"
	.string "そのとき！\n"
	.string "あらしの　なかから　まいおりて　きたのが\l"
	.string "おおぞらの　ポケモン⋯⋯\p"
	.string "その　みどりに　かがやく　ポケモンは\n"
	.string "2ひきの　いかりを　しずめると\l"
	.string "また　どこかへと　とびさって　いった\p"
	.string "どこか　とおい\n"
	.string "そらの　かなたへ⋯⋯$"
