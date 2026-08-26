@ PetalburgCity_WallysHouse scripts (JP map g8 m0 @ 0x081F810B)

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:: @ 0x081F8116
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther:: @ 0x081F8120
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:: @ 0x081F8129
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf:: @ 0x081F8133
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad:: @ 0x081F815A
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf:: @ 0x081F8184
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad:: @ 0x081F818E
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally:: @ 0x081F8198
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom:: @ 0x081F81A2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf:: @ 0x081F81B7
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally: @ 0x081F81C1
	.string "きみは⋯⋯\n"
	.string "そうか　{PLAYER}{KUN}　だね？\p"
	.string "さっきは　ミツルの　あいてを　してくれて\n"
	.string "ありがとう⋯⋯\p"
	.string "あのこは　うまれた　ときから\n"
	.string "からだが　じょうぶでは　なくてね\p"
	.string "それで　すこしの　あいだ　シダケタウンの\n"
	.string "わたしの　しんせきの　うちで\l"
	.string "あずかってもらう　ことに　したんだよ\p"
	.string "あそこは　ここよりも　ずっと\n"
	.string "くうきが　きれいな　ところ　だからね！\p"
	.string "⋯⋯で　ミツルかい？　ミツルなら\n"
	.string "もう　しゅっぱつ　していったよ\p"
	.string "いまごろは　どの　あたりかなあ⋯⋯$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing: @ 0x081F829E
	.string "ミツルは　どうしてるかなあ⋯⋯$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs: @ 0x081F82AE
	.string "{PLAYER}{KUN}！\n"
	.string "むりに　よびだして　すまなかったね！\p"
	.string "ミツルは　シダケタウンに　いってから\n"
	.string "すっかり　げんきを　とりもどしたよ！\p"
	.string "それも　みんな　きみの　おかげさ！\p"
	.string "なにしろ　このまちを　でるときに\n"
	.string "ミツルが　ポケモンを　つかまえるのを\l"
	.string "てつだって　くれただろう？\p"
	.string "あのときの　ことが　ミツルは　とっても\n"
	.string "うれしかった　らしいんだ！\p"
	.string "いや　ミツル　だけじゃない\n"
	.string "ちちおやの　わたしも　うれしいよ！\p"
	.string "あのこに　きみの　ような\n"
	.string "やさしい　ともだちが　できたことが　ね！\p"
	.string "そのおれい　という　わけでは　ないけど\n"
	.string "これを　うけとって　くれないか！$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces: @ 0x081F83BA
	.string "なみのりを　つかえるように　なれば\n"
	.string "いろんな　ばしょに　いけるように　なるよ！$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon: @ 0x081F83E2
	.string "もうすぐ　ミツルが　かえってくるぞ！\n"
	.string "たのしみだなあ⋯⋯！$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity: @ 0x081F8400
	.string "ええっ！？　サイユウシティで\n"
	.string "ミツルと　であった　だって⋯⋯？\p"
	.string "んもう　{PLAYER}{KUN}ってばー\p"
	.string "いくら　あのこが　げんきに　なったからって\n"
	.string "そんな　とおくの　まち　まで\l"
	.string "ひとりで　いけるわけ　ないよねえ⋯⋯$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy: @ 0x081F8465
	.string "ミツルが　ポケモンを　つかまえた　って\n"
	.string "すごく　うれしそうに　はなしていたの\p"
	.string "あのこの　あんな　えがお　ひさしぶり$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling: @ 0x081F849F
	.string "うちの　しゅじんには　ないしょ　だけど\p"
	.string "じつは　ミツルったら　シダケタウンを\n"
	.string "かってに　でて　いっちゃった　らしいの⋯⋯\p"
	.string "あのこ　からだは　よわかったけど\n"
	.string "あんがい　しっかりした　せいかく　だから\l"
	.string "かならず　ぶじで　かえってくると\l"
	.string "わたしは　しんじてるわ！$"
