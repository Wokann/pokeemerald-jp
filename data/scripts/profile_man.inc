ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "こんにちは\n"
	.string "えがおの　すてきな　トレーナーさん！\p"
	.string "ぼくは　ポケモントレーナーさん　たちの\n"
	.string "プロフィールを　あつめるのが\l"
	.string "しゅみ　なんだけど⋯⋯$"

ProfileMan_Text_MayISeeYourProfile:
	.string "どうかな？　きみの　プロフィール\n"
	.string "ぼくに　おしえて　もらえないかな？$"

ProfileMan_Text_EasyChatExplanation:
	.string "プロフィールは　すきな　ことばを\n"
	.string "4つ　くみあわせて　つくるんだよ！\p"
	.string "これから　ぼくが\n"
	.string "てきとうな　4つの　ことばで　つくった\l"
	.string "プロフィールを　みせるから\p"
	.string "きみは　その　ことばを\n"
	.string "すきなものに　いれかえて\l"
	.string "きみだけの　プロフィールに　してね！\p"
	.string "えらべる　ことばは\n"
	.string "すごく　たくさん　あるから\l"
	.string "グループに　わかれて　いるんだ\l"
	.string "ポケモン　とか　せいかつ　とか　しゅみ⋯\l"
	.string "という　ぐあいにね！\p"
	.string "だから　まずは\n"
	.string "グループを　えらんで⋯⋯\l"
	.string "そのあとに　えらんだ　グループの\l"
	.string "ことばが　いくつも　でてくるから\l"
	.string "そこから　すきな　ことばを\l"
	.string "みつけてね！$"

ProfileMan_Text_LetsSeeItThen:
	.string "やった！　ありがとう！\n"
	.string "じゃ　さっそく　きかせてよ！$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "そんなあ⋯⋯\p"
	.string "きみの　プロフィールは　さぞかし\n"
	.string "すてきだと　おもうんだけど　なぁ⋯⋯$"

ProfileMan_Text_NotIntoItRightNow:
	.string "あれ？　いまは　きが　のらないんだね？\p"
	.string "だったら　いつでも　いいよ！$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "こんにちは\n"
	.string "えがおの　すてきな　トレーナーさん！$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "きみの　あたらしい　プロフィールを\n"
	.string "おしえて　くれるのかな？$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "やった！　ありがとう！\p"
	.string "じゃあ　まえにも　まして\n"
	.string "すてきな　やつを　きたい　してるよ！$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "いまの　ままが　いいんだね？\p"
	.string "そうだよね　とても　すてきな\n"
	.string "プロフィール　だもの！$"

ProfileMan_Text_FantasticProfile:
	.string "すっ　すばらしい！\p"
	.string "まさに　きみ　そのもの　って　かんじの\n"
	.string "すてきな　プロフィール！\p"
	.string "これを　きいた　ひとは\n"
	.string "だれもが　きみの　とりこに　なるだろうね！\p"
	.string "どうも　ありがとう！$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "ややっ！\n"
	.string "その　ことばを　しっている　とは⋯⋯\p"
	.string "という　ことは　きみも\n"
	.string "ふしぎな　できごと　クラブの　なかま　だね！$"
