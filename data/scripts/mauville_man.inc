MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "わし　グッズこうかんオヤジ\n"
	.string "わしと　グッズの　こうかん　する？$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "そう⋯⋯\n"
	.string "わし　ざんねん⋯⋯$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "でも　きみとは　このまえ\n"
	.string "グッズの　こうかん　したよね$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "これ　わしが　もってる　グッズ\n"
	.string "なにか　ほしいの　あったら　いってね$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "ほしい　グッズ　ないの？\n"
	.string "わし　ざんねん⋯⋯$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "それは　{STR_VAR_1}さんが\n"
	.string "つかってた　グッズ　だよ\p"
	.string "これに　するかい？$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "⋯⋯って　きみ　グッズ\n"
	.string "ひとつも　もってない　じゃん！$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "じゃあ　こうかんに　だしてくれる\n"
	.string "グッズを　えらんで！$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "こうかん　して　くれないの？\n"
	.string "わし　ざんねん⋯⋯$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "きみ　{STR_VAR_2}が　いっぱいで\n"
	.string "もう　もてないよ$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "じゃあ　わしの　{STR_VAR_3}と\n"
	.string "きみの　{STR_VAR_2}を　こうかんするよ？$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "きみ　いま　そのグッズ　かざってるね\n"
	.string "かざってる　グッズは　こうかん　できないよ$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "じゃあ　こうかん！\l"
	.string "きみの　パソコンに\n"
	.string "グッズを　おくっておくよ$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "ああ！　ごめん！\n"
	.string "それ　とっても　レアな　グッズ　だから\l"
	.string "こうかん　できないんだ！\p"
	.string "ほかに　ほしい　グッズ　ある？$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "わし　でんせつおやじ\n"
	.string "でんせつの　トレーナーの　はなし　するよ\p"
	.string "わしの　ハナシ　ききたい？$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "そう⋯⋯\n"
	.string "わし　ざんねん⋯⋯$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "わしが　しってる　でんせつは　これだけ\n"
	.string "どの　でんせつが　ききたい？$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "でも　わし⋯⋯\n"
	.string "でんせつの　トレーナーの　はなし\l"
	.string "なにも　しらない\p"
	.string "どこかに　でんせつに　のこる\n"
	.string "トレーナーは　いないかなあ$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "⋯⋯え！！！\p"
	.string "きみ　{STR_VAR_1}かい　も\n"
	.string "{STR_VAR_2}　の！？\p"
	.string "⋯⋯ううむ　それは　すごい！\n"
	.string "あたらしい　でんせつの　はじまりだ！$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "これより　もっとすごい\n"
	.string "でんせつを　もってる　トレーナー\l"
	.string "どこかに　いない　かなあ⋯$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "⋯⋯きみ　トレーナー？\p"
	.string "だったら　なにか　でんせつっぽい　はなし\n"
	.string "きかせてよ$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "ところで⋯\n"
	.string "まだ　でんせつ　ききたい？$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "⋯⋯うーん　ものたりない　なあ\p"
	.string "もっと　すごい　はなしを\n"
	.string "きかせて　ほしいなあ$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "もっと　たくさんの　ひとに\n"
	.string "でんせつの　トレーナーの　はなし\l"
	.string "きいて　ほしいなあ$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "レポートを　かきまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "レポートを　かいた$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "{STR_VAR_1}かいも\n"
	.string "レポートを　かいた　らしい！\p"
	.string "{STR_VAR_3}ほど　ようじん　ぶかい\n"
	.string "トレーナーは　いない　だろう！$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "りゅうこう　はっしん　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "りゅうこうを　つくった$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "{STR_VAR_1}かいも\n"
	.string "りゅうこうを　うみだした　らしい！\p"
	.string "{STR_VAR_3}こそが　つぎつぎと\n"
	.string "ホウエンの　りゅうこうを　うみだしている！$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "きのみを　うえまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "きのみを　うえた$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "{STR_VAR_1}かいも\n"
	.string "きのみを　うめた　そうだ！\p"
	.string "{STR_VAR_3}は　でんせつの\n"
	.string "きのみ　ずき　だな！$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "じてんしゃ　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "じてんしゃを　こうかんした$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "じてんしゃを　こうかんした　そうだ！\p"
	.string "{STR_VAR_3}は　よほどの\n"
	.string "じてんしゃ　だいすき　トレーナー　だな！$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "インタビューに　こたえまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "インタビューに　こたえた$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "インタビューを　うけた　そうだ！\p"
	.string "{STR_VAR_3}は　とても\n"
	.string "ちゅうもく　される　トレーナー　だろう！$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "しょうぶ　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "しょうぶ　した$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ポケモン　しょうぶを　した　そうだ！\p"
	.string "{STR_VAR_3}は　トレーナーを　みると\n"
	.string "しょうぶ　せずに　おれない　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "つかまえまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "ポケモンを　つかまえた$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}ひき　もの\n"
	.string "ポケモンを　つかまえた　そうだ！\p"
	.string "{STR_VAR_3}こそ　でんせつの\n"
	.string "ポケモン　つかまえ　じょうず　だ！$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "つりまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "ポケモンを　つった$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}ひき　もの\n"
	.string "ポケモンを　つった　そうだ！\p"
	.string "{STR_VAR_3}こそ　でんせつの\n"
	.string "つり　めいじん　だ！$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "タマゴを　あたため　つづけた　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "タマゴを　かえした$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "{STR_VAR_1}こ　もの　タマゴを\n"
	.string "かえした　そうだ！\p"
	.string "{STR_VAR_3}こそ　でんせつの\n"
	.string "タマゴ　あたため　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "しんか　させまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "ポケモンを　しんか　させた$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}ひきもの\n"
	.string "ポケモンを　しんか　させたそうだ！\p"
	.string "{STR_VAR_3}こそ　さいこうの\n"
	.string "ポケモン　しんか　マスターだ！$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "ポケモンセンター　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "ポケモンセンターで　かいふくした$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ポケモンセンターで　かいふく　したのだ！\p"
	.string "{STR_VAR_3}ほど　ポケモンセンターが\n"
	.string "すきな　トレーナーも　いない　だろう！$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "さとがえり　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "じぶんの　いえで　かいふくした$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "じぶんの　いえで　かいふく　したのだ！\p"
	.string "{STR_VAR_3}ほど　さとがえりが\n"
	.string "すきな　トレーナーも　いないだろう！$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "サファリゾーンに　いりびたった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "サファリゾーンに　はいった$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "サファリゾーンに　はいった　そうだ！\p"
	.string "{STR_VAR_3}は　サファリゾーンでは\n"
	.string "やせいの　ちが　さわぐ　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "いあいぎりを　しまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "いあいぎり　した$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "いあいぎりを　つかった　そうだ！\p"
	.string "{STR_VAR_3}は　いあいぎりが\n"
	.string "すきで　しょうがない　トレーナー　なのだ！$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "いわを　くだかずに　おれない　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "いわくだき　した$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "いわくだきを　つかった　そうだ！\p"
	.string "{STR_VAR_3}は　いわを　みたら\n"
	.string "くだかずに　おれない　トレーナー　なのだ！$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "ひっこし　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "ひっこし　した$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ひみつきちを　ひっこし　したそうだ！\p"
	.string "{STR_VAR_3}は　ひっこしが\n"
	.string "とっても　すきな　トレーナー　なのだ！$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "はねまくり　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "はねるを　つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "はねるを　つかった　らしい！\p"
	.string "{STR_VAR_3}は　はねる　のが\n"
	.string "とっても　すきな　トレーナー　なのだ！$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "あきらめない　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "わるあがき　した$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "わるあがきを　した　らしい！\p"
	.string "{STR_VAR_3}は　どんな　じょうきょう　でも\n"
	.string "けっして　あきらめない　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "スロットの　めいじん$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "スロットで　おおあたり　した$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "スロットで　おおあたり　した　らしい！\p"
	.string "{STR_VAR_3}は　スロットマシンを\n"
	.string "しりつくして　いる　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "ルーレットの　めいじん$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "ルーレットを　れんぞくで　あてた$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ルーレットを　れんぞくで　あてた　らしい！\p"
	.string "{STR_VAR_3}は　はっきり　いって\n"
	.string "ルーレットを　みきっている　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "バトルタワーの　ちょうせんしゃ$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "バトルタワーに　ちょうせん　した$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "バトルタワーに　いどんだ　そうだ！\p"
	.string "{STR_VAR_3}は　バトルタワーに\n"
	.string "こだわりを　もっている　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "ブレンド　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "ポロックを　つくった$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "{STR_VAR_1}かいも\n"
	.string "ポロックを　つくった　そうだ！\p"
	.string "{STR_VAR_3}に　きのみブレンダーを\n"
	.string "つかわせたら　みぎに　でるものは　ないな！$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "コンテスト　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "コンテストに　さんか　した$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "{STR_VAR_1}かいも\n"
	.string "コンテストに　さんか　した　そうだ！\p"
	.string "{STR_VAR_3}は　じぶんの　ポケモンを\n"
	.string "ひとに　みせるのが　だいすき　なんだろう！$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "コンテストの　たつじん$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "コンテストで　ゆうしょう　した$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "コンテストで　ゆうしょう　した　そうだ！\p"
	.string "{STR_VAR_3}は　とてつも　ない\n"
	.string "コンテスト　マスター　だろう！$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "かいもの　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "かいものを　した$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "おみせで　かいものを　した　らしい！\p"
	.string "{STR_VAR_3}は　おみせに　はいると\n"
	.string "ついつい　かいもの　する　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "ダウジング　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "ダウジングマシンを　つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ダウジングマシンを　つかった　らしい！\p"
	.string "{STR_VAR_3}は\n"
	.string "さがしものが　だいすきな　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "あめに　ふられた　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "あめに　ふられた$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "あめで　ずぶぬれに　なった　らしい！\p"
	.string "{STR_VAR_3}は　みずも　したたる\n"
	.string "いい　トレーナーっていう　かんじ　だな！$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "ずかんで　しらべまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "ずかんを　みた$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ずかんを　みた　そうだ！\p"
	.string "{STR_VAR_3}は　ずかんで　ポケモンを\n"
	.string "しらべるのが　だいすきな　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "リボンを　たくさん　あつめた　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "リボンを　もらった$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "リボンを　もらった　らしい！\p"
	.string "{STR_VAR_3}は　リボンを　あつめるのが\n"
	.string "とても　だいすきな　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "だんさを　とびおりまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "だんさを　とびおりた$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "だんさを　とびおりた　らしい！\p"
	.string "{STR_VAR_3}は　だんさを　みると\n"
	.string "とびおりずに　おれない　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "でんせつの　テレビ　ウォッチャー$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "テレビを　みた$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "テレビを　みた　らしい！\p"
	.string "{STR_VAR_3}は\n"
	.string "テレビ　だいすき　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "じかんを　きに　する　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "とけいを　みた$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "とけいを　みた　らしい！\p"
	.string "{STR_VAR_3}は　じかんを　きに　する\n"
	.string "きちょうめんな　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "ポケモンくじに　あたりまくった　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "ポケモンくじで　あたった$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ポケモンくじで　あたった　らしい！\p"
	.string "{STR_VAR_3}は　ポケモンを　こうかん　する\n"
	.string "ともだちが　とても　おおい　トレーナーだ！$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "そだてやを　つかいこなす　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "そだてやに　ポケモンを　あずけた$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "そだてやに　あずけた　らしい！\p"
	.string "{STR_VAR_3}は　とにかく　そだてまくる\n"
	.string "モーレツな　トレーナーに　ちがいない！$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "ロープウェイ　だいすき　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "ロープウェイに　のった$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "ロープウェイに　のった　らしい！\p"
	.string "{STR_VAR_3}は　うえに　したにと\n"
	.string "おおいそがしの　トレーナーだな！$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "おんせんに　かよいづめの　トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "おんせんに　はいった$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "{STR_VAR_3}という\n"
	.string "トレーナーの　はなし　だが⋯⋯\p"
	.string "なんと　{STR_VAR_1}かいも\n"
	.string "おんせんに　はいった　らしい！\p"
	.string "{STR_VAR_3}は　きっと\n"
	.string "おはだが　ツルツルの　トレーナー　だろう！$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "わし　メルヘンおやじ\n"
	.string "とても　いい　はなし　するよ\p"
	.string "わしの　ハナシ　ききたい？$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "そう⋯\n"
	.string "わし　ざんねん⋯$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "あと　おもったんだけどさ⋯$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "そのぐらい　かな···\p"
	.string "また　はなし　しようね！\n"
	.string "ばいばい！$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "わし　シンガーソングおやじ\n"
	.string "わしの　うた　きいてくれる？$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "そう⋯⋯\n"
	.string "わし　ざんねん⋯⋯$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "あぁ　いい　うた　だなぁ\n"
	.string "ほかの　ひとにも　きかせて　みたいなあ$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "どう？　わしの　うた？\p"
	.string "でも　ちょっと　かしが　きにいらない\p"
	.string "だから　きみ　ちょっと　かえてくれる？$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "そう⋯⋯\n"
	.string "わし　ざんねん⋯⋯$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "ありがとう！\n"
	.string "じゃあ　うたって　みるぞ！$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "こんな　かんじで　いいの？$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "よし　わかった！\n"
	.string "しばらく　このうたを　うたって　みるよ！$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "わし　ナウイおやじ\n"
	.string "いまどきの　ナウイことば　おしえるよ$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "でも　きみには　このまえ　おしえたよね\p"
	.string "こんどは　ほかの　ひとに　おしえたいなぁ$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "でも　きみ　ことば　たくさん　しってるね\n"
	.string "おしえること　ぜんぜん　ないよ$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "きみ　{STR_VAR_1}って\n"
	.string "ことば　しってる？\p"
	.string "いみ？　それはね⋯⋯\n"
	.string "おとうさんか　おかあさんに　きいてみて$"
