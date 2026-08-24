@ VerdanturfTown_WandasHouse scripts (JP map g6 m6 @ 0x081F7105)

VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "ミツル“{PLAYER}さんに　まけたけど\n"
	.string "もう　おちこんでないよ\p"
	.string "だって　ラルトスと　いっしょに\n"
	.string "あちこちの　ジムで　うでだめし　して\l"
	.string "すごい　トレーナーに　なるって\l"
	.string "もくひょうが　できたから！\p"
	.string "いつか　{PLAYER}さん　よりも\n"
	.string "つよくなって　もういちど\l"
	.string "ポケモンしょうぶを　おねがい　するからね！$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "ミツル“いつか　{PLAYER}さん　よりも\n"
	.string "つよくなって　もういちど\l"
	.string "ポケモンしょうぶを　おねがい　するからね！$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "おじさん“おお！　{PLAYER}{KUN}\n"
	.string "ミツルくんは　となりに　いるよ！\p"
	.string "しかし　たいした　もんだね！\p"
	.string "しぜんに　かこまれた　かんきょうが\n"
	.string "ミツルくんを　げんきに　させている！\p"
	.string "⋯⋯いや　もしかすると\n"
	.string "あのこに　きぼうを　あたえて　いるのは\p"
	.string "ポケモンなのかも　しれないな⋯⋯$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "ミツルくん⋯⋯\n"
	.string "いつのまにか　いなくなっちゃった⋯⋯$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "おじさん“そうですか⋯⋯\n"
	.string "あの　ミツルくんが\l"
	.string "ひとりで　そんな　とおくまで⋯⋯\p"
	.string "さすがは　わたしの　おとうとの　むすこだ！$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "ミチル“あなたは⋯⋯？\n"
	.string "⋯⋯あ　そうか！\p"
	.string "ミツルくんが　いってた\n"
	.string "{PLAYER}さんって　あなたの　ことね！\p"
	.string "わたしは　ミツルくんの　いとこ　なの！\p"
	.string "どう？　あのこ　こっちに　きてから\n"
	.string "ずいぶん　げんきに　なったでしょう？$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "ミチル“ミツルくんの　ことなら\n"
	.string "だいじょうぶ！　しんぱい　ないわよ！\p"
	.string "だって　わたしの　いとこ　だし\n"
	.string "なにより　ポケモンが　いっしょ　ですもの！$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "きみの　おかげで\n"
	.string "まいにち　かのじょに　あえて\l"
	.string "おれは　ハッピーだよ！$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "うちの　むすめの　こいびとは\n"
	.string "ずいぶん　じょうねつてきな　ひとでね\p"
	.string "むすめに　あうため　だけに\n"
	.string "ひたすら　トンネルを　ほってるってよ！\p"
	.string "むすめも　しんぱい　なのか\n"
	.string "いつも　トンネルに　あしを　はこんでるよ$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "なんと！　むすめの　こいびと　ときたら\n"
	.string "すでで　トンネルを　ほっていたって！\p"
	.string "そりゃあ　たまげた　もんだ！$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "ミツルくんに　もしものことが　あったら\n"
	.string "あたしゃ　トウカにいる　ごりょうしんに\l"
	.string "あわせる　かおが　ないよ⋯⋯$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "ミツルくんが　サイユウに　いたって！？\p"
	.string "そりゃ　トウカの　ごりょうしんも\n"
	.string "びっくり　するだろうねぇ$"

@ The next unstructured Verdanturf map starts at 0x081F7556.
	.incbin "baserom_jp.gba", 0x1f7556, 0x2d4
