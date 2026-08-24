@ PacifidlogTown_House2 scripts (JP map g7 m3 @ 0x081F79FF)

PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
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

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	@ JP opcode 0xC5 is waitdooranim; US uses waitmoncry at this point.
	waitdooranim
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	@ JP opcode 0xC5 is waitdooranim; US uses waitmoncry at this point.
	waitdooranim
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "ウォッホン！！\p"
	.string "わしが　ポケモン　だいすきクラブで\n"
	.string "いちばーん　えらい　かいちょうの⋯⋯\p"
	.string "おとうと　ですぞ！\p"
	.string "まあ　ここで　ポケモンと　いっしょに\n"
	.string "バカンスを　たのしんで　おるのですな！$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "ほう！\n"
	.string "きみの　ポケモン⋯⋯$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "とっても　なついて　いますなあ\p"
	.string "そんな　かわいらしい　ポケモンには\n"
	.string "この　わざマシン　どうですかな？$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "ふむう⋯⋯\n"
	.string "わるくは　ないんだが　よくもない⋯⋯\p"
	.string "おやの　トレーナーである　きみの\n"
	.string "どりょくが　ひつよう　ですな！$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "なんだか　めつきが　わるいですのう\p"
	.string "そんな　こわそうな　ポケモンには\n"
	.string "この　わざマシン　どうですかな？$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "ポケモンの　なつきぐあいが　たかいと\n"
	.string "おんがえしの　いりょくも　たかくなる\p"
	.string "なつきぐあいが　ひくいと\n"
	.string "やつあたりの　いりょくが　つよまるんだよ！$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "そうそう　あと{STR_VAR_1}にち　たてば\n"
	.string "いい　わざマシンが　てに　はいるんだよ！\p"
	.string "そのとき　また　あそびに　きたまえ！\n"
	.string "きみの　ポケモンに　あった\l"
	.string "すてきな　わざマシンを　あげるから$"

PacifidlogTown_House2_Text_Rurii:
	.string "ルリリ“るりー$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "とっても　なついて　いるようだ$"

PacifidlogTown_House2_Text_Rururi:
	.string "ルリリ“ルルリッ！！$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "あんまり　なついて　いないようだ⋯⋯$"
