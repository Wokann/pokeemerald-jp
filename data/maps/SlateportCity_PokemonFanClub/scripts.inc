SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "ウォッホン！！\p"
	.string "わしが　ポケモン　だいすきクラブで\n"
	.string "いちばーん　えらい　かいちょう　ですぞ！\p"
	.string "なんたって　かいちょう　ですからな\n"
	.string "ポケモンを　そだてさせたら\l"
	.string "みぎに　でるもの　なし！\p"
	.string "そんな　ポケモンを　じまんできる\n"
	.string "ポケモンコンテストという\l"
	.string "もよおしが　あるの　ですが⋯\p"
	.string "なにしろ　とおくの　まちで　やっているので\n"
	.string "あまり　さんか　できんのですよ\p"
	.string "ですから　いまは　ここで\n"
	.string "じぶんの　ポケモンを　じまんしたり\l"
	.string "みなさんの　ポケモンを\l"
	.string "みせて　いただくだけに　しておるのです$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "ポケモンコンテストに　でた　ことが\n"
	.string "ある　トレーナーの　ポケモン⋯\l"
	.string "ぜひとも　みて　みたい　ものですな$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "ウォッホン！！\n"
	.string "おっ　コンテストに　でられましたな！\p"
	.string "どれ　あなたは　ポケモンを\n"
	.string "どんな　ふうに　そだてられて　いるのかな？\p"
	.string "いやー　ひとの　そだてた　ポケモンを\n"
	.string "はいけん　するのは　たのしい　ですぞ！\p"
	.string "きちんと　そだてられた　ポケモンの\n"
	.string "しあわせそうな　かお⋯⋯\p"
	.string "それを　みつめる　トレーナーの\n"
	.string "やさしげな　ひとみ⋯⋯\p"
	.string "いやー　しあわせで\n"
	.string "むねが　いっぱいに　なりますな⋯⋯\p"
	.string "おっと　しつれい！　ついつい\n"
	.string "はなしが　ながくなって　しまいましたな\p"
	.string "では　さっそく　きみの　ポケモンが\n"
	.string "どれほど　そだっているのか\l"
	.string "はいけん　させて　もらいますかな！$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "きみの　ポケモン　そだって　ますかな？\n"
	.string "ちょっと　はいけん　させて　もらいますぞ！$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "ふむふむ⋯⋯\n"
	.string "なるほど⋯⋯$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "ふむう⋯⋯\n"
	.string "わるくは　ないんだが　よくもない⋯⋯\p"
	.string "おやの　トレーナーである　きみの\n"
	.string "どりょくが　ひつよう　ですな！\p"
	.string "たとえば　もっと　たくさん\n"
	.string "ポロックを　あげるのは　どうですかな？$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "あらら⋯⋯\p"
	.string "けっこう　ポケモンが　そだっているので\n"
	.string "いいものを　あげようと　おもったのですが\l"
	.string "もちものが　いっぱい　ですな$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "きみの　{STR_VAR_1}　ですが\n"
	.string "なかなか　みごとに　そだって　おりますな！\l"
	.string "いやー　たいした　ものです！\p"
	.string "だが　この　どうぐを　つかって　あげたなら\n"
	.string "もっと　そだつこと　まちがいなし！　ですぞ！$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "その　あかいバンダナを　もたせると\n"
	.string "ポケモンの　かっこよさを\l"
	.string "みんなに　みとめさせることが　できますぞ！$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "その　あおいバンダナを　もたせると\n"
	.string "ポケモンの　うつくしさを\l"
	.string "いまより　きわだたせることが　できますぞ！$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "その　ピンクのバンダナを　もたせると\n"
	.string "ポケモンの　かわいさを\l"
	.string "もっと　ひきだすことが　できますぞ！$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "その　みどりのバンダナを　もたせると\n"
	.string "ポケモンの　かしこさを\l"
	.string "さらに　みがくことが　できますぞ！$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "その　きいろのバンダナを　もたせると\n"
	.string "ポケモンの　たくましさを\l"
	.string "いっそう　アピール　できますぞ！$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "きみに　あげる　どうぐは\n"
	.string "もう　なにも　ないですぞ！\p"
	.string "なにしろ　どうぐに　たよらんでも\n"
	.string "きみの　ポケモンを　そだてる\l"
	.string "さいのうは　バツグン　ですからな！$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "わたし　ポケモンが　なついている\n"
	.string "すがたを　みるのが　すき\p"
	.string "ポケモンって　いっしょに　いる\n"
	.string "ひとの　きもちに　すごく　びんかん！\p"
	.string "あなたが　ポケモンを　だいじに　すれば\n"
	.string "ポケモンも　あなたに　なついてくれるわ！\p"
	.string "あなたの　ポケモンが　あなたに　なついたら\n"
	.string "わたしにも　みせてね$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "あなたの　ポケモン\n"
	.string "あなたに　なついているのね\p"
	.string "ポケモンに　やさしい　トレーナーさんに\n"
	.string "だいすきクラブからの　おくりもの　よ$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "ポケモンって　いっしょに　いる\n"
	.string "ひとの　きもちに　すごく　びんかん！\p"
	.string "あなたが　ポケモンを　だいじに　すれば\n"
	.string "ポケモンも　あなたに　なついてくれるわ！$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "ポケモンしょうぶに　まけて\n"
	.string "ひんしに　させて　ばかりだと\l"
	.string "ポケモンが　どんどん　すさんで\l"
	.string "トレーナーのこと　うたがう　ようになる\p"
	.string "つまり　なついて　くれなくなるよ$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "ポケモンって　どうぐ\n"
	.string "つかってもらうのが　すきなのかな？\p"
	.string "だって　タウリンとか　あげると\n"
	.string "すごく　うれしそうに　するのよ！$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "エネコ“ふにゃあーあ$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ジグザグマ“キュウウ⋯⋯$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "マリルリ“マリ　マリ！？$"
