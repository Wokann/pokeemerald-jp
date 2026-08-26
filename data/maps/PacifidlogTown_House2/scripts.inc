@ PacifidlogTown_House2 scripts (JP map g7 m3 @ 0x081F79FF)

PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother:: @ 0x081F7A00
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag:: @ 0x081F7A4C
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0x0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment:: @ 0x081F7A66
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment:: @ 0x081F7A6F
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM:: @ 0x081F7A80
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn:: @ 0x081F7A84
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort:: @ 0x081F7AB3
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration:: @ 0x081F7ABD
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays:: @ 0x081F7AEC
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill:: @ 0x081F7AFF
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry_jp
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill:: @ 0x081F7B1A
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry_jp
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation: @ 0x081F7B35
	.string "ウォッホン！！\p"
	.string "わしが　ポケモン　だいすきクラブで\n"
	.string "いちばーん　えらい　かいちょうの⋯⋯\p"
	.string "おとうと　ですぞ！\p"
	.string "まあ　ここで　ポケモンと　いっしょに\n"
	.string "バカンスを　たのしんで　おるのですな！$"

PacifidlogTown_House2_Text_AhYourPokemon: @ 0x081F7B93
	.string "ほう！\n"
	.string "きみの　ポケモン⋯⋯$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis: @ 0x081F7BA2
	.string "とっても　なついて　いますなあ\p"
	.string "そんな　かわいらしい　ポケモンには\n"
	.string "この　わざマシン　どうですかな？$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort: @ 0x081F7BD5
	.string "ふむう⋯⋯\n"
	.string "わるくは　ないんだが　よくもない⋯⋯\p"
	.string "おやの　トレーナーである　きみの\n"
	.string "どりょくが　ひつよう　ですな！$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis: @ 0x081F7C0F
	.string "なんだか　めつきが　わるいですのう\p"
	.string "そんな　こわそうな　ポケモンには\n"
	.string "この　わざマシン　どうですかな？$"

PacifidlogTown_House2_Text_ExplainReturnFrustration: @ 0x081F7C43
	.string "ポケモンの　なつきぐあいが　たかいと\n"
	.string "おんがえしの　いりょくも　たかくなる\p"
	.string "なつきぐあいが　ひくいと\n"
	.string "やつあたりの　いりょくが　つよまるんだよ！$"

PacifidlogTown_House2_Text_GetGoodTMInXDays: @ 0x081F7C8C
	.string "そうそう　あと{STR_VAR_1}にち　たてば\n"
	.string "いい　わざマシンが　てに　はいるんだよ！\p"
	.string "そのとき　また　あそびに　きたまえ！\n"
	.string "きみの　ポケモンに　あった\l"
	.string "すてきな　わざマシンを　あげるから$"

PacifidlogTown_House2_Text_Rurii: @ 0x081F7CE4
	.string "ルリリ“るりー$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer: @ 0x081F7CEC
	.string "とっても　なついて　いるようだ$"

PacifidlogTown_House2_Text_Rururi: @ 0x081F7CFC
	.string "ルリリ“ルルリッ！！$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch: @ 0x081F7D07
	.string "あんまり　なついて　いないようだ⋯⋯$"
