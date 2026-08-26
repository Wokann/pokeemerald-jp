@ CaveOfOrigin_B1F scripts (JP map g24 m42 @ 0x082190FE)

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace:: @ 0x082190FF
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza:: @ 0x08219146
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin:: @ 0x08219182
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre:: @ 0x0821918D
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember:: @ 0x08219198
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar:: @ 0x082191A3
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory: @ 0x082191C4
	.string "そうか　きみが　{PLAYER}{KUN}⋯⋯\n"
	.string "きみの　かつやくは　きいているよ\p"
	.string "わたしの　なまえは　ミクリ\n"
	.string "ルネの　ジムリーダーを　していたけれど\l"
	.string "ちょっと　わけが　あってね\p"
	.string "いまは　ししょうの　アダンさんに\n"
	.string "ジムのことは　おまかせして　いるのさ\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "いま　このまちで　あばれている\n"
	.string "グラードンと　カイオーガは\l"
	.string "ちょうこだい　ポケモンと　いわれている\p"
	.string "けれど　ちょうこだい　ポケモンは\n"
	.string "あの2ひき　だけじゃ　なかった⋯⋯\l"
	.string "どこかに　もう1ひき\p"
	.string "そう⋯⋯　レックウザと　よばれる\n"
	.string "ちょうこだい　ポケモンが　いるんだよ\p"
	.string "とおい　むかしに\n"
	.string "あの2ひきの　たたかいを　しずめたのも\l"
	.string "レックウザ　だと　いわれている\p"
	.string "だが　レックウザが　どこに　いるかは\n"
	.string "わたしにも　わからない⋯⋯$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza: @ 0x0821931C
	.string "ミクリ“{PLAYER}{KUN}　ひょっとして\n"
	.string "きみは　レックウザが　どこに　いるか\l"
	.string "しっているのかい？\p"
	.string "よかったら　おしえて　くれないか⋯⋯$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin: @ 0x0821935C
	.string "ミクリ“めざめのほこらか⋯⋯\p"
	.string "って　それは　ここのこと　じゃないか\n"
	.string "たのむよ　しっかり　してくれ！\p"
	.string "レックウザが　どこに　いるか\n"
	.string "もういちど　かんがえて　みてくれ⋯⋯$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat: @ 0x082193B0
	.string "ミクリ“おくりびやまか⋯⋯\p"
	.string "しかし　このまえ　オババさまに\n"
	.string "あったときは　なにも　いってなかった\p"
	.string "あのひとが　わたしに\n"
	.string "うそを　つくとも　おもえないし⋯⋯\p"
	.string "{PLAYER}{KUN}　もういちど\n"
	.string "よく　かんがえて　くれないか⋯⋯$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow: @ 0x0821941A
	.string "ミクリ“えっ　おぼえてない　って！？\n"
	.string "うーん　それは　こまったな⋯⋯\p"
	.string "なんとか\n"
	.string "おもいだして　もらえない　だろうか⋯⋯$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar: @ 0x08219456
	.string "ミクリ“そらのはしら⋯⋯？\p"
	.string "そうか！　そらのはしら　だったか！\p"
	.string "よし　{PLAYER}{KUN}\n"
	.string "こうしては　いられない\l"
	.string "いますぐ　そらのはしらへ　いくぞ！$"
