@ Route114_LanettesHouse scripts (JP map g20 m2 @ 0x082124D1)

Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:: @ 0x082124D7
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette:: @ 0x082124DB
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice:: @ 0x08212508
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook:: @ 0x08212512
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2:: @ 0x08212530
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3:: @ 0x08212545
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC:: @ 0x0821254E
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis: @ 0x08212557
	.string "マユミ“あっ！　{PLAYER}{KUN}\p"
	.string "ちらかっていて　ごめんなさい⋯⋯\n"
	.string "けんきゅうに　むちゅうに　なると\l"
	.string "つい　こう　なっちゃうんです⋯⋯\p"
	.string "はずかしいから　ヒミツに　してくださいね\n"
	.string "これ　あげますから⋯⋯$"

Route114_LanettesHouse_Text_OrganizeYourBoxes: @ 0x082125B8
	.string "あずかりシステムを　つくった\n"
	.string "あたしからの　アドバイス　です\p"
	.string "どの　ボックスに　どの　ポケモンを\n"
	.string "あずけたか　わかるように\l"
	.string "きちんと　せいり　したほうが　いいですよ！$"

Route114_LanettesHouse_Text_ResearchNotesPage1: @ 0x0821260C
	.string "けんきゅう　ようの　ノートだ\n"
	.string "ボックスに　ついて　かかれている！\p"
	.string "ボックス1つに　30ぴきの\n"
	.string "ポケモンを　あずけられる　ようにする\p"
	.string "パソコンには　ぜんぶで　420ひきの\n"
	.string "ポケモンを　あずけられる　ようにする\p"
	.string "つづきを　よみますか？$"

Route114_LanettesHouse_Text_ResearchNotesPage2: @ 0x08212680
	.string "ポケモンを　マーキングすると　ボックスが\n"
	.string "せいり　しやすくなる　ようにする\p"
	.string "ボックスの　なまえ　かべがみを\n"
	.string "かえられる　ようにして　あずけられた\l"
	.string "ポケモンが　よろこぶ　ようにする\p"
	.string "つづきを　よみますか？$"

Route114_LanettesHouse_Text_ResearchNotesPage3: @ 0x082126E6
	.string "ポケモンが　てんそう　される　ボックスは\n"
	.string "さいごに　みた　ボックスにする\p"
	.string "その　ボックスが　いっぱいの　ときは\n"
	.string "つぎの　ボックスに　てんそう　する\p"
	.string "つまり　ボックスを　みることで\n"
	.string "ポケモンを　てんそう　したい　ボックスに\l"
	.string "きりかえられる　ようにする$"

Route114_LanettesHouse_Text_ClosedTheNotebook: @ 0x08212763
	.string "{PLAYER}は　ノートを　とじた$"

Route114_LanettesHouse_Text_EmailFromBill: @ 0x08212770
	.string "パソコンを　みると\n"
	.string "なんと　でんしメールが　きていた！\p"
	.string "‘⋯⋯　⋯⋯　⋯⋯\p"
	.string "きみの　あずかり　システム\n"
	.string "なかなか　べんり　やな\p"
	.string "いろんな　ところに\n"
	.string "じょせい　らしい　きくばりが　あって\l"
	.string "つかってて　たのしいし\p"
	.string "いっしょに　かいはつ　した\n"
	.string "なかま　として　うれしいわ！\p"
	.string "ほな　これからも　あずかりシステムの\n"
	.string "けんきゅう　がんばってな\p"
	.string "⋯⋯　⋯⋯　⋯⋯’$"
