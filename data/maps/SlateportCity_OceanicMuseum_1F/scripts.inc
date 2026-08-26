@ SlateportCity_OceanicMuseum_1F scripts (JP map g9 m7 @ 0x081FCA3E)

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant:: @ 0x081FCA3F
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft:: @ 0x081FCA48
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight:: @ 0x081FCA59
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee:: @ 0x081FCA6A
	showmoneybox 0x0, 0x0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee:: @ 0x081FCA91
	checkmoney 0x32
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 0x32
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0x1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney:: @ 0x081FCAC1
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway:: @ 0x081FCAE2
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0x1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1:: @ 0x081FCAF6
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2:: @ 0x081FCAFF
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3:: @ 0x081FCB08
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4:: @ 0x081FCB11
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5:: @ 0x081FCB1A
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6:: @ 0x081FCB23
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment:: @ 0x081FCB2C
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment:: @ 0x081FCB35
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay:: @ 0x081FCB3E
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay:: @ 0x081FCB47
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1:: @ 0x081FCB50
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2:: @ 0x081FCB59
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3:: @ 0x081FCB62
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay:: @ 0x081FCB6B
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine:: @ 0x081FCB74
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1:: @ 0x081FCB7D
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2:: @ 0x081FCB86
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3:: @ 0x081FCB8F
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4:: @ 0x081FCB98
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt:: @ 0x081FCBA1
	lock
	faceplayer
	delay 0x8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM46
	goto_if_eq VAR_RESULT, 0x0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth:: @ 0x081FCC15
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth:: @ 0x081FCC2C
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast:: @ 0x081FCC3C
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited:: @ 0x081FCC53
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief:: @ 0x081FCC5E
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter: @ 0x081FCC7E
	.string "うみの　かがく　はくぶつかんへ\n"
	.string "ようこそ　いらっしゃいませ！\p"
	.string "にゅうじょうりょう　50えんに　なります\n"
	.string "けんがく　して　いきますか？$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself: @ 0x081FCCC1
	.string "ごゆっくり　どうぞ！$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney: @ 0x081FCCCC
	.string "⋯⋯あら　おかねが　たりませんわ$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup: @ 0x081FCCDD
	.string "⋯⋯あら　さっきの　だんたいさん？\n"
	.string "あなただけ　おくれちゃって　しかたないわね\l"
	.string "はやく　とおっちゃって！$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll: @ 0x081FCD12
	.string "みんなの　ために\n"
	.string "われわれ　アクアだんは　いるのよ！$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere: @ 0x081FCD2D
	.string "げんちしゅうごう　で\n"
	.string "ここに　あつまったのは　いいけど⋯⋯\p"
	.string "かんじんの　リーダーが　まだ　こないんだ$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich: @ 0x081FCD60
	.string "ここに　おいてある　もの\n"
	.string "かっぱらうと　もうかるかな？$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds: @ 0x081FCD7C
	.string "この　ちしきを　いかして\n"
	.string "わるいこと　してやるか⋯⋯$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled: @ 0x081FCD97
	.string "なかまが　カナズミで　ドジらなければ\n"
	.string "ここに　こなくて　すんだのによ！$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney: @ 0x081FCDBB
	.string "さっき　50えんが　なくて\n"
	.string "うけつけで　すごい　じかん　かかったよ⋯⋯$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling: @ 0x081FCDDF
	.string "うみのこと　べんきょう　して\n"
	.string "ポケモンしょうぶに　やくだてたいの$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel: @ 0x081FCE00
	.string "わたくしッ\n"
	.string "うみを　みると　こうふん　するのですッ！\p"
	.string "そんな　わたくしに　とって\n"
	.string "クスノキかんちょうは\l"
	.string "あこがれの　ひと　ナンバー1　なのですッ！$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow: @ 0x081FCE4A
	.string "うみは　はてしなく　ひろく\n"
	.string "どこまでも　ふかい⋯⋯\p"
	.string "きっと　われわれが　しらない　ポケモンも\n"
	.string "いっぱい　いるのだろうね$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon: @ 0x081FCE86
	.string "あたし　うみの　ポケモンが　ほしいの\p"
	.string "だって　ひんやりと　してて\n"
	.string "だきしめたら　きもちよさそう　だもの$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis: @ 0x081FCEBA
	.string "ひえー！！\n"
	.string "なんで　おまえ　ここに　いるんだよ！？\p"
	.string "おれ？　おれは　カナシダ　トンネルで\n"
	.string "おまえに　コテンパンに　された\l"
	.string "アクアだん　だよ\p"
	.string "これを　やるから　ゆるしてくれよ！$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain: @ 0x081FCF12
	.string "その　わざマシン\n"
	.string "おれより　おまえのほうが　にあうぜ！\p"
	.string "じゃあな　わはははー！$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis: @ 0x081FCF3A
	.string "たのむから\n"
	.string "なんとかして　うけとってくれよ！$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment: @ 0x081FCF51
	.string "ガラスの　なかで　あおい　みずが\n"
	.string "くるくると　まわって　いる！\p"
	.string "‘これは　かぜの　ちからで　じんこうてきに\n"
	.string "　うずしおを　おこす　じっけん　です’$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment: @ 0x081FCF9B
	.string "ガラスの　なかで　あかい　ボールが\n"
	.string "うかんだり　しずんだり　している！\p"
	.string "‘これは　ボールの　ふりょくを　りようした\n"
	.string "　たきのぼりの　げんりの　じっけん　です’$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay: @ 0x081FCFEB
	.string "うみの　そこの　つちの　みほんだ！\p"
	.string "‘かいていには　ながい　ねんげつを　かけて\n"
	.string "　せいぶつの　しがいが　ふりつもり\l"
	.string "　ちそうが　かたち　づくられて　いきます’\p"
	.string "‘これらを　ぶんせき　することで\n"
	.string "　とおい　むかしの　ことが　わかるのです’$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay: @ 0x081FD062
	.string "うみべの　すなの　みほんだ！\p"
	.string "‘やまから　かわを　つたって　きた　いしは\n"
	.string "　みずの　なかで　ころがる　うちに\l"
	.string "　くだかれたり　けずれたり　していきます’\p"
	.string "‘それらが　ちいさな　つぶに　なって\n"
	.string "　うみべの　すなが　できて　いくのです’$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1: @ 0x081FD0D7
	.string "‘うみの　まめちしき　その1\n"
	.string "　なぜ　うみの　みずは　あおいの？’\p"
	.string "‘ひかりには　いくつもの　いろが　あって\n"
	.string "　ほとんどの　ひかりは　みずに　はいると\l"
	.string "　その　いろが　なくなって　いきます’\p"
	.string "‘けれど　あおい　ひかり　だけは\n"
	.string "　そのままの　いろで　のこる　ため\l"
	.string "　うみは　あおく　みえるのです’$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2: @ 0x081FD16B
	.string "‘うみの　まめちしき　その2\n"
	.string "　なぜ　うみの　みずは　しょっぱいの？’\p"
	.string "‘かいすい　には　いわから　にじみでた\p"
	.string "　しおの　もとに　なる\n"
	.string "　ナトリウムイオン　と　えんそイオン\l"
	.string "　という　ぶっしつが　おおく　ふくまれ\l"
	.string "　だから　なめると　しょっぱいのです’$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3: @ 0x081FD1EA
	.string "‘うみの　まめちしき　その3\n"
	.string "　うみと　りくは　どちらが　ひろいの？’\p"
	.string "‘だいたい　うみが　70パーセントで\n"
	.string "　りくが　30パーセント　くらいです\p"
	.string "　りくちに　くらべて　うみは\n"
	.string "　その　2ばい　いじょうも　あるのです’$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay: @ 0x081FD258
	.string "デコボコに　なみうった　かせきが　ある！\p"
	.string "‘うみの　そこに　たまった　つちには\n"
	.string "　かいすいが　ながれる　えいきょうで\l"
	.string "　なみの　ような　もようが　できます’\p"
	.string "‘それが　そのまま　かせきに　なったものを\n"
	.string "　リップルマークと　よんでいます’$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine: @ 0x081FD2CF
	.string "まるい　ドームの　なかで　なんだか\n"
	.string "よく　わからない　きかいが　まわってる！\p"
	.string "なにかの　ふかさを　しらべるのかな？$"
