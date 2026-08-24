SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM46
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
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

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "うみの　かがく　はくぶつかんへ\n"
	.string "ようこそ　いらっしゃいませ！\p"
	.string "にゅうじょうりょう　50えんに　なります\n"
	.string "けんがく　して　いきますか？$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "ごゆっくり　どうぞ！$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "⋯⋯あら　おかねが　たりませんわ$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "⋯⋯あら　さっきの　だんたいさん？\n"
	.string "あなただけ　おくれちゃって　しかたないわね\l"
	.string "はやく　とおっちゃって！$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "みんなの　ために\n"
	.string "われわれ　アクアだんは　いるのよ！$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "げんちしゅうごう　で\n"
	.string "ここに　あつまったのは　いいけど⋯⋯\p"
	.string "かんじんの　リーダーが　まだ　こないんだ$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "ここに　おいてある　もの\n"
	.string "かっぱらうと　もうかるかな？$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "この　ちしきを　いかして\n"
	.string "わるいこと　してやるか⋯⋯$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "なかまが　カナズミで　ドジらなければ\n"
	.string "ここに　こなくて　すんだのによ！$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "さっき　50えんが　なくて\n"
	.string "うけつけで　すごい　じかん　かかったよ⋯⋯$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "うみのこと　べんきょう　して\n"
	.string "ポケモンしょうぶに　やくだてたいの$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "わたくしッ\n"
	.string "うみを　みると　こうふん　するのですッ！\p"
	.string "そんな　わたくしに　とって\n"
	.string "クスノキかんちょうは\l"
	.string "あこがれの　ひと　ナンバー1　なのですッ！$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "うみは　はてしなく　ひろく\n"
	.string "どこまでも　ふかい⋯⋯\p"
	.string "きっと　われわれが　しらない　ポケモンも\n"
	.string "いっぱい　いるのだろうね$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "あたし　うみの　ポケモンが　ほしいの\p"
	.string "だって　ひんやりと　してて\n"
	.string "だきしめたら　きもちよさそう　だもの$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "ひえー！！\n"
	.string "なんで　おまえ　ここに　いるんだよ！？\p"
	.string "おれ？　おれは　カナシダ　トンネルで\n"
	.string "おまえに　コテンパンに　された\l"
	.string "アクアだん　だよ\p"
	.string "これを　やるから　ゆるしてくれよ！$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "その　わざマシン\n"
	.string "おれより　おまえのほうが　にあうぜ！\p"
	.string "じゃあな　わはははー！$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "たのむから\n"
	.string "なんとかして　うけとってくれよ！$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "ガラスの　なかで　あおい　みずが\n"
	.string "くるくると　まわって　いる！\p"
	.string "‘これは　かぜの　ちからで　じんこうてきに\n"
	.string "　うずしおを　おこす　じっけん　です’$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "ガラスの　なかで　あかい　ボールが\n"
	.string "うかんだり　しずんだり　している！\p"
	.string "‘これは　ボールの　ふりょくを　りようした\n"
	.string "　たきのぼりの　げんりの　じっけん　です’$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "うみの　そこの　つちの　みほんだ！\p"
	.string "‘かいていには　ながい　ねんげつを　かけて\n"
	.string "　せいぶつの　しがいが　ふりつもり\l"
	.string "　ちそうが　かたち　づくられて　いきます’\p"
	.string "‘これらを　ぶんせき　することで\n"
	.string "　とおい　むかしの　ことが　わかるのです’$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "うみべの　すなの　みほんだ！\p"
	.string "‘やまから　かわを　つたって　きた　いしは\n"
	.string "　みずの　なかで　ころがる　うちに\l"
	.string "　くだかれたり　けずれたり　していきます’\p"
	.string "‘それらが　ちいさな　つぶに　なって\n"
	.string "　うみべの　すなが　できて　いくのです’$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "‘うみの　まめちしき　その1\n"
	.string "　なぜ　うみの　みずは　あおいの？’\p"
	.string "‘ひかりには　いくつもの　いろが　あって\n"
	.string "　ほとんどの　ひかりは　みずに　はいると\l"
	.string "　その　いろが　なくなって　いきます’\p"
	.string "‘けれど　あおい　ひかり　だけは\n"
	.string "　そのままの　いろで　のこる　ため\l"
	.string "　うみは　あおく　みえるのです’$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "‘うみの　まめちしき　その2\n"
	.string "　なぜ　うみの　みずは　しょっぱいの？’\p"
	.string "‘かいすい　には　いわから　にじみでた\p"
	.string "　しおの　もとに　なる\n"
	.string "　ナトリウムイオン　と　えんそイオン\l"
	.string "　という　ぶっしつが　おおく　ふくまれ\l"
	.string "　だから　なめると　しょっぱいのです’$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "‘うみの　まめちしき　その3\n"
	.string "　うみと　りくは　どちらが　ひろいの？’\p"
	.string "‘だいたい　うみが　70パーセントで\n"
	.string "　りくが　30パーセント　くらいです\p"
	.string "　りくちに　くらべて　うみは\n"
	.string "　その　2ばい　いじょうも　あるのです’$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "デコボコに　なみうった　かせきが　ある！\p"
	.string "‘うみの　そこに　たまった　つちには\n"
	.string "　かいすいが　ながれる　えいきょうで\l"
	.string "　なみの　ような　もようが　できます’\p"
	.string "‘それが　そのまま　かせきに　なったものを\n"
	.string "　リップルマークと　よんでいます’$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "まるい　ドームの　なかで　なんだか\n"
	.string "よく　わからない　きかいが　まわってる！\p"
	.string "なにかの　ふかさを　しらべるのかな？$"
