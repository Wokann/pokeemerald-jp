@ MeteorFalls_StevensCave scripts (JP map g24 m107 @ 0x0821D1A6)

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven:: @ 0x0821D1A7
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated:: @ 0x0821D1F2
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:: @ 0x0821D206
	.string "ダイゴ“へぇ　{PLAYER}{KUN}\n"
	.string "ボクが　ここにいるって　よく　わかったね\p"
	.string "もしかして　きみ⋯⋯　ボクを\n"
	.string "ただの　いしマニアだと　おもってる？\p"
	.string "⋯⋯いや　トクサネの　うちゅうセンターで\n"
	.string "いっしょに　たたかったから\p"
	.string "ボクが　どれくらい　つよいのか\n"
	.string "きみだって　しってるはず　だよね\p"
	.string "よし　{PLAYER}{KUN}\p"
	.string "ほんきで　しょうぶ　するなら\n"
	.string "かくごして　くれよな！$"

MeteorFalls_StevensCave_Text_StevenDefeat:: @ 0x0821D2B0
	.string "きみは⋯⋯\n"
	.string "これほどまでに　つよくなって　いたのか$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:: @ 0x0821D2CA
	.string "ダイゴ“そういえば⋯⋯\n"
	.string "ムロ　タウンの　いしのどうくつで\l"
	.string "はじめて　あった　ときから\p"
	.string "いずれ　きみは　チャンピオンに\n"
	.string "なるような　きが　していた\p"
	.string "ボクの　よそうは\n"
	.string "だいたい　いつも　あたるんだよ\p"
	.string "じゃあ⋯⋯\n"
	.string "つぎに　きみが　むかうのは⋯⋯\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "ふふふ　さすがの　ボクも\n"
	.string "そんなこと　までは　わからないな$"
