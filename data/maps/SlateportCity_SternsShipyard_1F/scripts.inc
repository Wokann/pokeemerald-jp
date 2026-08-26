@ SlateportCity_SternsShipyard_1F scripts (JP map g9 m0 @ 0x081FAB28)

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock:: @ 0x081FAB29
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady:: @ 0x081FAB7B
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined:: @ 0x081FAB8F
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern:: @ 0x081FABA3
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran:: @ 0x081FABC2
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1:: @ 0x081FABD6
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2:: @ 0x081FABDF
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney:: @ 0x081FABE8
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails: @ 0x081FABF1
	.string "えーと⋯⋯　これが　こーなって\n"
	.string "そいでもって　あれが　あーなって\l"
	.string "と　いうことは　それと　これは　どれ？\p"
	.string "ああ　もう　わけが　わからん！$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern: @ 0x081FAC36
	.string "⋯⋯ん？\p"
	.string "ぼくは　クスノキかんちょう　から\n"
	.string "れんらくせんの　せっけいを　まかされた\l"
	.string "ツガという　ものだけど⋯⋯\p"
	.string "あっ！？\n"
	.string "それは　デボンのにもつ！\p"
	.string "うーん⋯⋯\n"
	.string "こまったな⋯⋯\p"
	.string "クスノキかんちょう\n"
	.string "ほかにも　しごとが　あるからって\l"
	.string "どこかに　いっちゃったんだ\p"
	.string "わるいけど　きみ　クスノキかんちょう\n"
	.string "さがして　にもつを　わたしてあげてよ！$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern: @ 0x081FACDE
	.string "ツガ“クスノキかんちょう\n"
	.string "どこに　いっちゃったのかな？\p"
	.string "わるいけど　きみ　クスノキかんちょう\n"
	.string "さがして　にもつを　わたしてあげてよ！$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran: @ 0x081FAD21
	.string "ツガ“ふねをつくる　っていうのは\n"
	.string "つくえの　うえでの　けいさん　だけでは\l"
	.string "わからないことも　おおくてね\p"
	.string "やっぱり　うみのことを　しりつくした\n"
	.string "ベテランの　ちえが　ほしいところだよ⋯⋯$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs: @ 0x081FAD7D
	.string "ツガ“やあ！　ハギろうじんが　ここで\n"
	.string "てつだって　くれるように　なったよ！\p"
	.string "でんせつの　ふなのりに　てつだってもらえて\n"
	.string "れんらくせんは　ちゃくちゃくと\l"
	.string "かんせいに　むかっているよ！$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady: @ 0x081FADD8
	.string "ツガ“ついに　ふねは　かんせいしたよ！\p"
	.string "できた　れんらくせん　タイドリップごうは\n"
	.string "まさに　さいこう　けっさく！\p"
	.string "だけど　もっと　いいものが　できそうな⋯⋯\n"
	.string "そんな　きも　するんだよ\p"
	.string "そう⋯⋯\n"
	.string "ものづくりに　おわりは　ないのさ！$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock: @ 0x081FAE4A
	.string "ハギ“おお！　{PLAYER}{KUN}！\n"
	.string "ひさしぶり　じゃのう！\p"
	.string "いやあ　きみと　であってから\n"
	.string "ふなのりの　ちが　さわいでな⋯⋯\p"
	.string "ツガくんに　きょうりょく　して\n"
	.string "れんらくせんを　つくりたく　なったんじゃ！\p"
	.string "れんらくせんが　できると　おおくの\n"
	.string "ひとを　はこべるように　なるからのう\p"
	.string "しかし⋯⋯　ふむう⋯⋯\n"
	.string "ツガくんは　すごいのう⋯⋯\p"
	.string "かれの　ぎじゅつと　わしの　けいけんを\n"
	.string "がったい　させれば　かならずや\l"
	.string "すごい　ふねが　できるに　ちがいない！$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing: @ 0x081FAF20
	.string "きせつや　てんきや　つきのいち　など\n"
	.string "さまざまな　じょうけん　によって\l"
	.string "うみは　つねに　すがたを　かえていきます\p"
	.string "そう！　うみ　というのは\n"
	.string "いきもの　のような　もの　なんですよ！$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily: @ 0x081FAF7A
	.string "ぼくは　すぐに　ふなよい　するのよね\n"
	.string "だから　ここで　おてつだい　してるのよね$"
