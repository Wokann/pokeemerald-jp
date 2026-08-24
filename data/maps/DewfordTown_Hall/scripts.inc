DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "いまの　はやりって　いったら　やっぱり\n"
	.string "‘{STR_VAR_1}’よね！\p"
	.string "‘{STR_VAR_1}’の　ない\n"
	.string "せいかつ　なんか　かんがえられない！$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "いまの　はやりって　いったら　やっぱり\n"
	.string "‘{STR_VAR_1}’よね！\p"
	.string "でも　もう　そろそろ\n"
	.string "あきてきたなー\p"
	.string "あたらしい　はやりでも　さがそっかなー$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "わたしは　ポケモンにも\n"
	.string "‘{STR_VAR_1}’を\l"
	.string "おしえてるんだけど\p"
	.string "これが　なかなか\n"
	.string "たいへん　なのよねー$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "いま　はやりの\n"
	.string "‘{STR_VAR_1}’のことを\l"
	.string "しらべてるんだけど\p"
	.string "‘{STR_VAR_1}’と\n"
	.string "‘{STR_VAR_2}’ってのは\p"
	.string "ふかい　かんけいが　あるって　いうのは\n"
	.string "ほんとうの　ことなのかい？$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "お！\n"
	.string "やっぱり　そうなのか\p"
	.string "これで　おじさんも　またいっぽ\n"
	.string "りゅうこうに　ちかづいたぞ！$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "なに！？\n"
	.string "そうなのか！？\p"
	.string "いやー　おじさんが　りゅうこうに\n"
	.string "ついて　いくのは　たいへんだ！$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "‘{STR_VAR_1}’の\n"
	.string "テレビって　いうのは\l"
	.string "やってないのかのう⋯⋯$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "うみの　むこうでは\p"
	.string "もっと　‘{STR_VAR_1}’が\n"
	.string "はやってるのかな？$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "ぼくは　‘{STR_VAR_1}’の\n"
	.string "グッズを　いっぱい　あつめて　いるんだ！\p"
	.string "‘{STR_VAR_1}’にんぎょう\n"
	.string "とか\p"
	.string "‘{STR_VAR_1}’ようふく\p"
	.string "‘{STR_VAR_1}’の　えほん\n"
	.string "なんかも　もってるよ\p"
	.string "いいだろー！\n"
	.string "ほしくても　あげないよー$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "“よい‘{STR_VAR_1}’と\n"
	.string "　わるい‘{STR_VAR_1}’”\p"
	.string "“‘{STR_VAR_1}’と\n"
	.string "　ポケモンの　かんけい”\p"
	.string "“やくにたつ\n"
	.string "　‘{STR_VAR_1}’”\p"
	.string "‘{STR_VAR_1}’に\n"
	.string "ついての　ほんが　ずらっと　ならんでいる！$"

DewfordTown_Hall_Text_TrendsScream:
	.string "“‘{STR_VAR_1}’の\n"
	.string "　さけび”\p"
	.string "という　だいめい　だ！$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "“‘{STR_VAR_1}’の\n"
	.string "　ほほえみ”\p"
	.string "という　だいめい　だ！$"

DewfordTown_Hall_Text_LastTrend:
	.string "“さいごの\n"
	.string "　‘{STR_VAR_1}’”\p"
	.string "という　だいめい　だ！$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "“‘{STR_VAR_1}’の\n"
	.string "　たんじょう”\p"
	.string "という　だいめい　だ！$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "ぼく　さいきん　はやりの\p"
	.string "‘{STR_VAR_1}’を\n"
	.string "みたんだ　いいだろ！\p"
	.string "すごかったよ\n"
	.string "ほんもの　だぜ！$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "いや　きみの　みた\n"
	.string "‘{STR_VAR_1}’は\l"
	.string "ほんもの　じゃないね！\p"
	.string "ほんものは　もっと\n"
	.string "キレが　あるというか\l"
	.string "うつくしい　というか⋯⋯\p"
	.string "まあ　とにかく\n"
	.string "もっと　すごいんだよ！$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "ぼく　さいきん　はやってる\n"
	.string "‘{STR_VAR_1}’の\l"
	.string "テーマ　きょくを　かんがえたんだ\l"
	.string "きいてくれよ！\p"
	.string "⋯⋯\p"
	.string "おー！\n"
	.string "{STR_VAR_1}　ー！\p"
	.string "すばらしい\n"
	.string "{STR_VAR_1}　ーー！！$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "⋯⋯\p"
	.string "きみは\n"
	.string "‘{STR_VAR_1}’　よりも\p"
	.string "うたの　べんきょうを\n"
	.string "したほうが　いいね$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "さっきの　はなし\n"
	.string "なんだけどさ\p"
	.string "こんど　この　しまで\n"
	.string "‘{STR_VAR_1}’\l"
	.string "パーティーを　ひらこうぜ！$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "お　いいね！！\p"
	.string "だれが　いちばん\n"
	.string "‘{STR_VAR_1}’が\l"
	.string "うまいかを　きめるんだね！\p"
	.string "じゃあ　きょうから\p"
	.string "‘{STR_VAR_1}’\n"
	.string "ざんまいだ！$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "⋯⋯そうだなぁ\p"
	.string "‘{STR_VAR_1}’は　もう\n"
	.string "りゅうこう　じゃなくて\p"
	.string "せいかつの　いちぶ\n"
	.string "という　かんじかなぁ？$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "え？\n"
	.string "そんなに！？\p"
	.string "きみは　ねても　さめても\n"
	.string "‘{STR_VAR_1}’　のこと\l"
	.string "ばっかり　かんがえてる　からな\p"
	.string "‘{STR_VAR_1}　はかせ’\n"
	.string "だね　まったく$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "ぼくと　きみが\n"
	.string "コンビを　くめば\p"
	.string "“{STR_VAR_1}”では\n"
	.string "もう　むてきって　ことだな！$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "そのとおり！\p"
	.string "‘{STR_VAR_1}　コンビ’\n"
	.string "っていう　かんじだね！\p"
	.string "ハハハ！！$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "さいきん　ぼくの　なかでは\n"
	.string "‘ヘドロばくだん’が　だいブーム　なのさ！\p"
	.string "えー　きみ\n"
	.string "‘ヘドロばくだん’　しらないの？\p"
	.string "それは　かわいそうだな\n"
	.string "よし！　ぼくが　あげるよ！$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "‘ヘドロばくだん’も　いいけど\n"
	.string "‘{STR_VAR_1}’って\l"
	.string "わざを　つかえる\l"
	.string "ポケモンも　いいよね！$"
