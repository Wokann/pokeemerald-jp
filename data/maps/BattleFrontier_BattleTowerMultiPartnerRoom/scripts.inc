@ BattleFrontier_BattleTowerMultiPartnerRoom scripts (JP map g26 m15 @ 0x08223475)

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0x0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0x0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	opendoor 10, 1
	waitdooranim_jp
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim_jp
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0x0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "こちらに　いる　トレーナーの　なかから\n"
	.string "パートナーを　おさがしください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}さんは\n"
	.string "まだ　パートナーを　みつけていません！\p"
	.string "パートナーを　さがすのを　やめて\n"
	.string "うけつけへ　もどりますか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "それでは\n"
	.string "こちらに　いる　トレーナーの　なかから\l"
	.string "パートナーを　おさがしください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "パートナーさがし\n"
	.string "おつかれさまでした！\p"
	.string "それでは　マルチ　バトルルームへ\n"
	.string "おつれいたします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "ぼくは\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばん　でし\l"
	.string "そのなも　{STR_VAR_3}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "{STR_VAR_1}から　アドバイスを　うけて\n"
	.string "{STR_VAR_2}を　もつ　{STR_VAR_3}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれているんです\p"
	.string "おねがいです！\n"
	.string "ぼくと　タッグを　くんでください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "ありがとうございます！\n"
	.string "さっそく　うけつけを　すませてきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "{PLAYER}さんと\n"
	.string "ぜひ　タッグを　くみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "わたしは\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばん　でし\l"
	.string "{STR_VAR_3}と　いいます$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "{STR_VAR_1}から　アドバイスを　うけて\n"
	.string "{STR_VAR_2}を　もつ　{STR_VAR_3}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれているんです\p"
	.string "おねがいします！\n"
	.string "わたしと　タッグを　くんでください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "ありがとうございます！\n"
	.string "さっそく　うけつけを　すませてきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}さんと\n"
	.string "ぜひ　タッグを　くみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "ぼくは　{STR_VAR_3}　って　いって\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしです\l"
	.string "グスっ⋯⋯\p"
	.string "ごめんなさい！\n"
	.string "きんちょう　して　なみだが⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "ぼく　{STR_VAR_3}さんの　アドバイスで\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれているんです\p"
	.string "グスン⋯⋯　ぼ　ぼくと\n"
	.string "タッグを　くんで　ください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "えー　ほんとですか！\n"
	.string "やった！　うれしいよう！　うぉぉーん！\p"
	.string "あ⋯⋯　ごめん　なさい\n"
	.string "うれしくて　なみだが⋯⋯\p"
	.string "さっ　さっそく　うけつけに\n"
	.string "いってきますから　まってて　ください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "そ　そんな⋯⋯\n"
	.string "う　うう　うわーん！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "こんにちはっ　ボクは　{STR_VAR_3}！\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしなんだ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3}さんに　すすめて　もらった\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}とね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}が\n"
	.string "いるんだよ　いいでしょ？\l"
	.string "ねーっ　ボクと　いっしょに\l"
	.string "タッグを　くもうよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "わーいっ　やった！\n"
	.string "じゃあねー　ボクが\l"
	.string "うけつけに　いってくるからね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "えーっ　どうして？\n"
	.string "{PLAYER}さんと　くみたかったなー$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "ぼくは　あの　ゆうめいな\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばんの　でし\l"
	.string "{STR_VAR_3}です！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "{STR_VAR_3}さん　から\n"
	.string "アドバイスを　いただいて\l"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "つれているんです\p"
	.string "おねがいです！\n"
	.string "ぼくと　タッグを　くんでください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "ありがとうございます！\n"
	.string "さっそく　うけつけを　すませてきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}さんと\n"
	.string "ぜひ　タッグを　くみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "あの⋯⋯　あたし　なんかに\n"
	.string "こえを　かけてくれて　うれしいです\l"
	.string "あたしは　{STR_VAR_3}です\l"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばんでしで⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3}さんが　あたし　なんかにも\n"
	.string "アドバイスを　くださったので\l"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれています⋯⋯　おそれ　おおいけど⋯⋯\p"
	.string "ムリ　だと　おもいます　けど⋯⋯\n"
	.string "あたしと　タッグを　くんでいただけますか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "ほんとう　ですか？　しんじられない！\n"
	.string "あたし　なんかと　くんでもらえる　なんて！\l"
	.string "が⋯⋯がんばります！\p"
	.string "あのっ　あたしで　よかったら\n"
	.string "いまから　うけつけに　いって　きます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "や　やっぱり⋯⋯\n"
	.string "あたし　なんか　ダメですよね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "わたしは　{STR_VAR_3}\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしなの！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3}さんが　いいって　いったから\n"
	.string "{STR_VAR_1}　つかいの　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "{STR_VAR_1}　つかいの　{STR_VAR_2}を\n"
	.string "もって　いるわけ！\l"
	.string "わるくない　でしょ？\l"
	.string "あなたと　タッグを　くんで　あげようか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "うん　じゃあ　よろしくね\n"
	.string "わたしの　あしを　ひっぱらないでよね！\l"
	.string "さっそく　うけつけに　いってくるわ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "え？　なんで　ことわるの？\n"
	.string "みるめ　ないんじゃない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "オレは　トライアスリートの　{STR_VAR_3}！\n"
	.string "ジョギング　トレーニング　ラッピングと\l"
	.string "まいにち　いそがしい　なか\l"
	.string "{STR_VAR_1}の　{STR_VAR_2}ばんでし　やってる！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "{STR_VAR_3}の　オススメ！\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "いそがしい　なか　がんばって　そだてたぜ！\p"
	.string "オレと　タッグを　くんで　がんばろうぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "サンキュー　そう　こなくっちゃ！\n"
	.string "んじゃ　オレ　うけつけを　すませてくるわ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "おいおい　いそがしい　なか　きたのに\n"
	.string "そりゃ　ないぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "ハーイ！　ちょうしは　どう？\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばんの\l"
	.string "でしトレーナー　{STR_VAR_3}よ　よろしくぅ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "きいてきいて！　{STR_VAR_3}さんが\n"
	.string "おすすめ　してくれた　ポケモンはね\l"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}なの\n"
	.string "もちろん　バッチリ　そだてたわ！\p"
	.string "というわけで　わたしと　くまない？\n"
	.string "きっと　いいカンジよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "わーい　たのしく　なりそうー！\n"
	.string "じゃ　わたしが　うけつけに　いってくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "もー　いじわる！\n"
	.string "わたし　オススメなのに！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "{STR_VAR_3}と　もうします\n"
	.string "わたくし　{STR_VAR_1}さまの　{STR_VAR_2}ばんの\l"
	.string "でしで　ございますの⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "{STR_VAR_3}さまに　おしえを　こい\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "そだて　あげましたの！\p"
	.string "おねがい　わたくしと　タッグを\n"
	.string "くんで　くださると　おっしゃって！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "うっ　うれしい　ですわ⋯⋯\n"
	.string "わたくし　ぜんりょくで　つとめますわ！\p"
	.string "もちろん　うけつけは　わたくしが！\n"
	.string "すこし　おまちくださいませ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "{PLAYER}さんと\n"
	.string "ぜひ　タッグを　くみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "キャー！　はなしかけられたっ！\n"
	.string "かっ　かんげきっ⋯⋯！\p"
	.string "わたし！　{STR_VAR_3}と　いいますっ！\n"
	.string "{STR_VAR_1}　せんせいの\l"
	.string "{STR_VAR_2}ばん　でし　ですっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "{STR_VAR_3}　せんせいの　アドバイスで\n"
	.string "{STR_VAR_1}をもつ　{STR_VAR_2}ちゃんと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "{STR_VAR_1}をもつ　{STR_VAR_2}ちゃんを\n"
	.string "そだてましたーっ！\p"
	.string "あの　おねがいが！\n"
	.string "わたしと　タッグをくんで　ほしいのですっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "キャー！　かっ　かんげきっ⋯⋯！\n"
	.string "おありがとう　ございますう！\l"
	.string "ではっ　うけつけを　して　まいりますっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "うっわあああ！\n"
	.string "ちも　なみだも　ないですねっ！　でもステキ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "いえーい！　{STR_VAR_1}さんの\n"
	.string "{STR_VAR_2}ばん　でしの　おじさんは\l"
	.string "{STR_VAR_3}です　ハロウ　ハロウ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "{STR_VAR_3}　ティーチャー　おすすめの\n"
	.string "{STR_VAR_1}　マスター　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "{STR_VAR_1}　マスター　{STR_VAR_2}を\n"
	.string "トレイン　したんだよー！\l"
	.string "グッドタイミングだね！\l"
	.string "もちろん　おじさんと　タッグを　くむだろ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "オーケイ　エクセレント！\n"
	.string "じゃ　バーっと　うけつけを　すませてくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "ぐわーっ！\n"
	.string "{PLAYER}さん　ってのは　クールだね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "お　おいっ　たいへんだ！\n"
	.string "バトルタワー　きょうで　おしまいらしいぞ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "なんてね　うっそ　うそ！\p"
	.string "おいらは　{STR_VAR_3}　って　いうんだ\n"
	.string "{STR_VAR_1}の　1000ばんめの　でしだ！\l"
	.string "うそ　ほんとは　{STR_VAR_2}ばん！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3}が　アドバイスを　くれてね\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}とね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}をね\n"
	.string "10ぴきずつ　もって　いまーす！\l"
	.string "うそ　ほんとは　1ぴきずつだよ！\p"
	.string "ひとつ　どうだろ？　こんな　おいらと\n"
	.string "タッグバトルを　して　みないかな？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "やったー！\n"
	.string "おれいに　ポケモン　あげちゃおう！\p"
	.string "なんて　じょうだん　だけど⋯⋯\n"
	.string "とりあえず　うけつけを　すませてくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "そんな　つめたい　こと　いうと\n"
	.string "バトルタワーを　こわして　しまうぞ！\p"
	.string "なんてね　うそ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "ご·き·げ·ん·よ·う！\n"
	.string "はーい　ごきげんよう！\p"
	.string "わしは　ノリノリ　ふなのり　{STR_VAR_3}！\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばんの　でしだよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "{STR_VAR_3}さん　アドバイスの　たまもの\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}が\n"
	.string "わしの　じまんの　ポケモン！\p"
	.string "さあ　この　であいを　きねんして\n"
	.string "わしと　タッグバトルを　やってください！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "ようよう！　ノリが　いいね\n"
	.string "よろしく　たのみますよ！\l"
	.string "じゃ　うけつけは　わしが　いってくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "そんな　{PLAYER}さん！\n"
	.string "ノリが　わるいじゃ　ないか！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "イャァアッホオオォォウウ！\n"
	.string "あ　にげないでェ　かえらないでェ！\p"
	.string "オスっ　オレっ　{STR_VAR_3}！\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばん　でしなのさ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3}さんったら　オレに！\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を！\n"
	.string "つかえって　いうから　そうしたぜエェ！\p"
	.string "って　ことで　どうする　オレ？\n"
	.string "さっそく　たのんでみる？\p"
	.string "おねがいです！\n"
	.string "オレと　タッグを　くんでエェ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "やったラッキー　うれしーよ　オレ！！\n"
	.string "さっそく　うけつけに　いってくる！？\l"
	.string "じゃ　ちょっと　まっててェ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "って　ことわられてる　オレっ！？\n"
	.string "{PLAYER}さん　つれないよォ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "ゴホっ！\p"
	.string "あっ　ゴメン　カゼ　ひいてて⋯⋯\n"
	.string "ポケモンは　げんきだから　ダイジョブだよ\p"
	.string "おれは　{STR_VAR_3}\n"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばんでしだよ\l"
	.string "⋯⋯ゴホっ　ゴホっ　よろしく！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "{STR_VAR_3}さんの　アドバイスで\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}とさ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "あめのひも　かぜのひも　そだてあげたよ\l"
	.string "⋯⋯それで　カゼを　ひいたんだ　きっと\p"
	.string "まあ　そういう　わけだからさ\n"
	.string "こんな　おれと　いっしょに　くまないかい？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "ありがとう　わるいね\n"
	.string "⋯⋯ゴホ　ゴホ！\l"
	.string "うけつけを　すませてくるから⋯⋯\l"
	.string "ゴホ　まっててね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "えー　なんで！\n"
	.string "{PLAYER}さんと　オレって　いいけどなあ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "あっ　ど　どうも！\n"
	.string "てれるなあ\p"
	.string "あの　{STR_VAR_3}です！　{STR_VAR_1}さんの\n"
	.string "{STR_VAR_2}ばんの　でし　やってます⋯⋯！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3}さんが　よいと　いったので\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "そだててるんだ⋯⋯　はずかしながら\p"
	.string "その　はずかしい　けど　ワシと⋯⋯\n"
	.string "タッグを　くんで　もらえる　かな⋯⋯？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "あ　ありがとう！\n"
	.string "はずかしい　けど　がんばって　みるよ\p"
	.string "じゃ⋯⋯　う　うけつけ　してくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "こ　ことわらないでくれ！\n"
	.string "ワシに　はじを　かかせないで　くれ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "わたしは　{STR_VAR_3}だ\n"
	.string "うそじゃない！\l"
	.string "{STR_VAR_1}さんの　{STR_VAR_2}ばんの　でしだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3}さんから　すすめられて\n"
	.string "どうやら　ほんき　みたい　だったから\l"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれているんだ　ほんとうだよ！\p"
	.string "ところで　もし　よかったら　わたしを\n"
	.string "キミの　パートナーに　みとめて　ほしい$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "ほんとうに　みとめて　くれるのかね？\n"
	.string "うそだったら　いやすぎる　からな\p"
	.string "いや　ほんとうなら　いいんだ　すまなかった\n"
	.string "さっそく　うけつけを　すませてくる$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "え？　なぜ　ことわるのかね？\n"
	.string "わるい　じょうだん　では　ないのかね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "わたし\n"
	.string "ミニスカート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "わたしはね⋯⋯\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}とね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "つれて　あるいているの！\p"
	.string "どう？\n"
	.string "パートナーに　なってくれない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "ありがとうー！\n"
	.string "いまから　とうろく　してくるわね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "わたしの　パートナーに　ならないなんて\n"
	.string "きっと　こうかい　するから！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "あのね！\p"
	.string "ぼくは\n"
	.string "たんパンこぞう　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "ぼくはね⋯⋯\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "もっているよ！\p"
	.string "ねぇねぇ\n"
	.string "いっしょに　タッグを　くもうよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "やったー！\n"
	.string "うけつけで　とうろく　してくるねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "ぼくの　ポケモンと　タッグを　くめば\n"
	.string "きっと　つよいのにー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "ヤッホー！\p"
	.string "わし\n"
	.string "やまおとこ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "わし\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれて　あるいています！\p"
	.string "どうですかな？\n"
	.string "いっしょに　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "ヤッホー！\p"
	.string "いまから　うけつけで\n"
	.string "とうろくを　すませてきますよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "きみと　いっしょに\n"
	.string "バトルを　したかったです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "こんにちは！\p"
	.string "わたし\n"
	.string "おとなのおねえさん　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "わたし\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "そだてているのよ！\p"
	.string "どう？\n"
	.string "いっしょに　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "うれしい！\p"
	.string "すぐに　とうろくを　すませるわね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "ざんねんね！\p"
	.string "あなたと　わたしが\n"
	.string "くんだら　さいこう　だったのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "よー！\p"
	.string "わし\n"
	.string "つりびと　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "わしは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "つれているぞ\p"
	.string "どうだね？\n"
	.string "いっしょに　たたかうかね？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "よしよし！\n"
	.string "まかせとけー\p"
	.string "いまから　とうろくを　するからな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "きみと　わしの　あいしょうは\n"
	.string "バッチリ　だったのにな⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "わたくし\n"
	.string "おじょうさま　{STR_VAR_1}と\l"
	.string "もうします！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "わたくし\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "つれていますの\p"
	.string "どうですか？\p"
	.string "わたくしと　いっしょに\n"
	.string "タッグを　くんで　いただけませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "ありがとうございます！\p"
	.string "では　わたくしは　\n"
	.string "とうろくを　すませてきますわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "わたくしの　パートナーに　ならないと\n"
	.string "きっと　こうかい　しますわよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "わたし\n"
	.string "トライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "わたしはね⋯⋯\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "もっているの！\p"
	.string "おねがい！\n"
	.string "いっしょに　タッグを　くんでよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "ありがとうー！\n"
	.string "うけつけで　とうろく　してくるー$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "わたしと　タッグを　くんだら\n"
	.string "きっと　つよいのにー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "やあ！\p"
	.string "ぼく\n"
	.string "むしとりしょうねん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "ぼく\n"
	.string "{STR_VAR_1}を　おぼえた　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "{STR_VAR_1}を　おぼえた　{STR_VAR_2}を\n"
	.string "もっているよ！\p"
	.string "ねー？\n"
	.string "ぼくと　いっしょに　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "やったね！\p"
	.string "じゃ　いまから　うけつけで\n"
	.string "とうろくを　すませてくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "ぼくの　ポケモン　さいこう　なのに！\n"
	.string "こうかい　しないでよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "こんにちは！\p"
	.string "ぼくは\n"
	.string "じゅくがえり　{STR_VAR_1}　です$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "ぼくは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "そだてています！\p"
	.string "どうです？\p"
	.string "ぼくと\n"
	.string "いっしょに　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "ありがとうございます！\p"
	.string "では\n"
	.string "うけつけで　とうろくを　すませてきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "ざんねんです⋯⋯\p"
	.string "きみと　いっしょに　タッグを　くんで\n"
	.string "べんきょう　したかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "よう！\p"
	.string "オレ\n"
	.string "おぼっちゃま　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "オレ\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "もっているんだぜ！\p"
	.string "オレ　いっしょに\n"
	.string "タッグを　くんでもいいぜ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "よし！\p"
	.string "じゃあ　いまから\n"
	.string "うけつけで　とうろくを　すませてくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "オレと　タッグを　くまない　なんて\n"
	.string "きっと　こうかい　するぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "オッス！\p"
	.string "カラテおう　{STR_VAR_1}\n"
	.string "と　もうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "いま　わたくし\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれております！\p"
	.string "おねがいします！\p"
	.string "わたくしと\n"
	.string "タッグを　くんで　くれませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "オッス！\p"
	.string "さっそく\n"
	.string "うけつけに　とうろく　してまいります！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "オッス⋯⋯\p"
	.string "つぎの　きかいは\n"
	.string "ぜひ　タッグを　くんでください⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "こんにちは！\p"
	.string "わたし\n"
	.string "うきわガール　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "わたし\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれているの！\p"
	.string "ねぇ？\p"
	.string "いっしょに\n"
	.string "タッグを　くんでよー？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "ありがとうー！\p"
	.string "じゃあ　いまから\n"
	.string "うけつけで　とうろくを　すませてくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "わたしと　タッグを　くんだら\n"
	.string "とっても　つよかったのにー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "こんにちは⋯⋯\p"
	.string "オカルトマニア　{STR_VAR_1}と\n"
	.string "もうします⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "わたくし⋯⋯\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "もっております⋯⋯\p"
	.string "どうか　わたくしと\n"
	.string "タッグを　くんでいただけませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "ありがとうございます⋯⋯\n"
	.string "うけつけで　とうろくを　してきます⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "あなたと　タッグを\n"
	.string "くみたかったです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "やあ！\p"
	.string "ぼく\n"
	.string "ポケモンブリーダー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "ぼくは　いま\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}とね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "そだてているんだ！\p"
	.string "どう？\p"
	.string "ぼくと\n"
	.string "いっしょに　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "ありがとう！\p"
	.string "では　さっそく\n"
	.string "うけつけで　とうろくを　すませてきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "きみと　いっしょに　タッグを\n"
	.string "くみたかったよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "こんにちは！\p"
	.string "わたし\n"
	.string "トライアスリート　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "わたしは\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれて　はしっているの！\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "やったね！\p"
	.string "じゃ　さっそく　うけつけで\n"
	.string "とうろくを　すませてくるわー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "わたしと　タッグを　くんだら\n"
	.string "さいこうなのに　ざんねんね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "やあ！\p"
	.string "ぼく\n"
	.string "トライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "ぼく\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれて　はしっているんだ！\p"
	.string "どうだい？\n"
	.string "ぼくと　タッグを　くんでみないかい？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "やったー！\p"
	.string "いま　うけつけで\n"
	.string "とうろくを　すませてくるよー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "きみと　タッグを　くんで\n"
	.string "いっしょに　たたかいたかったよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "わたし\n"
	.string "バトルガール　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "わたし\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "きたえているの！\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "ありがとう！\p"
	.string "いまから　うけつけで\n"
	.string "とうろくを　すませてくるからねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "あなたとなら　さいきょうの　タッグを\n"
	.string "くめると　おもったのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "オレ\n"
	.string "トライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "オレ\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれて　はしっているんだぜ！\p"
	.string "どうだい？\n"
	.string "オレと　いっしょに　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "サンキュー！\p"
	.string "いまから　うけつけで\n"
	.string "とうろくを　すませてくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "きみとなら　さいきょうの　タッグを\n"
	.string "くめたのに　ざんねんだよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "ぼくはね⋯⋯\n"
	.string "うきわボーイ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "ぼくは\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれているんだよ！\p"
	.string "ねぇ？\n"
	.string "ぼくと　いっしょに　タッグを　くもうよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "やったねー！\p"
	.string "うけつけで　とうろく　してくるよー！\n"
	.string "がんばろうねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "ぼくの　ポケモン　とっても　つよいのに⋯⋯\n"
	.string "タッグに　なれなくて　ざんねん！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "イエーイ！\p"
	.string "オレは\n"
	.string "ギタリスト　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "オレは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}を\n"
	.string "つれているんだぜー！\p"
	.string "イエーイ？\n"
	.string "オレと　いっしょに　タッグを　くもうぜ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "イエーイ！\p"
	.string "いまから\n"
	.string "うけつけで　とうろく　してくるぜー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "オレの　ポケモン　とっても　つよいぜー！\n"
	.string "こうかい　しないように　するんだぜー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "こんにちは\p"
	.string "ジェントルマン　{STR_VAR_1}と\n"
	.string "もうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "わたくし\n"
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}を\n"
	.string "つれておりますぞ！\p"
	.string "どうですかな？\n"
	.string "わたくしの　パートナーに　なりませんかな？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "よろしく　おねがいしますぞ！\p"
	.string "では\n"
	.string "うけつけで　とうろく　してきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "ざんねん　ですな⋯⋯\n"
	.string "つぎの　きかいを　きたいして　おりますぞ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "わたくし\n"
	.string "だいすきクラブの　{STR_VAR_1}と\l"
	.string "もうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "わたくしは　いま\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}を\n"
	.string "つれて　おります！\p"
	.string "どうでしょう？\n"
	.string "わたくしと　タッグを　くみませんかな？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "ありがとう　ございます！\n"
	.string "それでは　とうろくに　いってまいります！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "わたくしの　ポケモン\n"
	.string "さいこうなのに　ざんねんです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "うむ！\p"
	.string "わしは\n"
	.string "たつじん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "わしの　きたえあげた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}じゃ\p"
	.string "どうじゃ？\n"
	.string "わしと　タッグを　くまぬか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "うむ！\p"
	.string "いまから　とうろくを　すませてくるぞ！\n"
	.string "おたがい　がんばろうぞ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "おぬしの　せんたくが\n"
	.string "ただしいことを　いのっておるぞ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "⋯⋯はいはい\p"
	.string "わたしは\n"
	.string "たつじん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "わたしの　きたえあげた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　ですよ\p"
	.string "どうですかね？\n"
	.string "わたしと　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "⋯⋯はいはい\n"
	.string "いまから　とうろくを　してきますよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くみたいものですね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "オレは\n"
	.string "ドラゴンつかい　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "オレの　きたえあげた　ポケモンは\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　だ！\p"
	.string "どうだ？\n"
	.string "オレと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "⋯⋯よしっ！　がんばるぜー！\p"
	.string "すぐに　とうろくを　すませて　くるからな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "オレより　つよい　パートナーは\n"
	.string "そうそう　いないぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "ぼくは\n"
	.string "とりつかい　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "ぼくの　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だね\p"
	.string "どうだい？\n"
	.string "ボクと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "ありがとー！\p"
	.string "いまから　とうろくを　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "ぼくの　ポケモン\n"
	.string "ほんとに　つよいのに　ざんねんだよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "ぼく\n"
	.string "にんじゃごっこ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "ぼくの　もっている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だよ\p"
	.string "ねー？\n"
	.string "ぼくと　タッグを　くもうよ？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "やったー！\n"
	.string "すぐ　とうろくを　してくるねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "ぼくの　ポケモンの　つよさに\n"
	.string "きっと　こうかい　するよー$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "こんにちは！\p"
	.string "わたし\n"
	.string "パラソルおねえさん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "わたしは　いま\n"
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}を\n"
	.string "つれているの！\p"
	.string "どう？\n"
	.string "わたしの　ポケモンと　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "ありがとうねー！\p"
	.string "いま　うけつけで　とうろく　してくるから\n"
	.string "がんばろうねー！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "あたしの　ポケモン　とっても　つよいのに\n"
	.string "ざんねんよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "わたしは\n"
	.string "こんちゅうマニア　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "わたしの　みつけた　ポケモンは\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　ですよ！\p"
	.string "どうですか？\n"
	.string "わたしと　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "はい！\n"
	.string "りょうかい　しました\p"
	.string "いま　とうろくを　してきますからね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "わたしが　みつけた　ポケモンと　くめば\n"
	.string "まけないのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "オッス！\p"
	.string "オレは\n"
	.string "ふなのり　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "オレの　じまんの　ポケモンは\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　だ！\p"
	.string "なあ！　\n"
	.string "もちろん　オレと　タッグを　くむだろう？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "とうぜん　だよな！\n"
	.string "いまから　とうろく　してくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "オレと　くんだら　らくしょう　なのに\n"
	.string "ざんねん　だぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "やあ\p"
	.string "ぼくは\n"
	.string "ポケモンコレクター　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "ぼくの　じまんの　ポケモンは\n"
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}だよ\p"
	.string "どうだい？\n"
	.string "ぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "おおー！\p"
	.string "じゃあ　さっそく　うけつけで\n"
	.string "とうろく　してくるよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "ぼくの　ポケモンの　みりょくに\n"
	.string "きが　つかないなんて　ガッカリだよ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "ぼくは\n"
	.string "ポケモンレンジャー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "ぼくの　つれている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だ！\p"
	.string "どうだい？\n"
	.string "ぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "よしー！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "つぎに　あったときは\n"
	.string "ぼくの　ポケモン　えらんでくれよ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "わたしは\n"
	.string "ポケモンレンジャー　{STR_VAR_1}よ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "わたしが　つれている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ！\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "がんばるわよー！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "つぎこそ\n"
	.string "わたしの　ポケモンを　えらんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "わたくし\n"
	.string "アロマなおねえさん　{STR_VAR_1}と\l"
	.string "もうします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "わたくしの　つれている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}です\p"
	.string "どうでしょう？\n"
	.string "わたくしと　タッグを　くんでみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "こうえいです\n"
	.string "すぐ　うけつけで　とうろく　してきますね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "つぎに　おあいした　ときには\n"
	.string "タッグを　くみたいものですね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "わし\n"
	.string "いせきマニア　{STR_VAR_1}じゃ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "わしの　もっている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}じゃ！\p"
	.string "どうじゃ？\n"
	.string "わしと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "よしよし！\n"
	.string "すぐ　うけつけで　とうろく　してくるぞい！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "うーむ⋯⋯\n"
	.string "わしの　ポケモン　つよいと　おもうぞ⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "ぼく\n"
	.string "エリートトレーナー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "ぼくの　つれている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}だよ\p"
	.string "どう？\n"
	.string "ぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "よしっ！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "きみとなら　さいきょうの　チームに　なると\n"
	.string "おもったんだけどな⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "わたしは\n"
	.string "エリートトレーナー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "わたしの　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "やったわ！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "あなたとなら　つよい　タッグチームが\n"
	.string "できると　おもったのに⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "オレは\n"
	.string "かいじゅうマニア　{STR_VAR_1}だ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "オレの　もっている　ポケモンは\n"
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}だ！\p"
	.string "どうだ？\n"
	.string "オレと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "やったぜ！\n"
	.string "すぐ　うけつけで　とうろく　してくるぜ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "オレの　ポケモン　つよいぞ！\n"
	.string "こうかい　しても　しらないぞ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "オレ\n"
	.string "キャンプファイヤー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "オレの　そだてあげた　ポケモンは\n"
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}　だよ\p"
	.string "どうだい？\n"
	.string "オレと　タッグを　くんでみないか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "やったー！\n"
	.string "いま　うけつけで　とうろく　してくるからな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでくれよな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "ぼくは\n"
	.string "キャンプボーイ　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "ぼくの　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\p"
	.string "どう？\n"
	.string "ぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "やったね！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "わたしは\n"
	.string "ピクニックガール　{STR_VAR_1}です！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "わたしの　つれている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}です\p"
	.string "どうすか？\n"
	.string "わたしと　タッグを　くんでみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "ありがとうございます！\n"
	.string "すぐ　うけつけで　とうろく　してきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでくださいね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "ぼくは\n"
	.string "サイキッカー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "ぼくの　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\p"
	.string "どう？\n"
	.string "ぼくと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "やったね！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くみたいね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "わたし\n"
	.string "サイキッカー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "わたしが　つれている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ！\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くまない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "ありがとう！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くみたいわね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "わたし\n"
	.string "じゅくがえり　{STR_VAR_1}です！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "わたしの　つれている　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}です！\p"
	.string "どうですか？\n"
	.string "わたしと　タッグを　くんでくれませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "ありがとうございます！\n"
	.string "すぐ　うけつけで　とうろく　してきます！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでくださいね⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "わたし\n"
	.string "ポケモンブリーダー　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "わたしの　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　なの\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "やったね！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "つぎに　あったときには\n"
	.string "ぜったいに　タッグを　くんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "わたくし\n"
	.string "だいすきクラブ　{STR_VAR_1}と\l"
	.string "もうしますのよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "わたくしの　そだてた　ポケモンちゃんは\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}　ですの\p"
	.string "どうでしょう？\n"
	.string "わたくしと　タッグを　くみませんか？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "ありがとうございます！\p"
	.string "わたくし　さっそく\n"
	.string "うけつけで　とうろく　してきますわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "わたくしの　ポケモンちゃん\n"
	.string "さいこうなのに　ざんねんです⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "わたし\n"
	.string "ビキニのおねえさん　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "わたしの　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "{STR_VAR_1}を　もった　{STR_VAR_2}よっ\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "やったねっ！\n"
	.string "すぐ　うけつけで　とうろく　してくるねっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでよねっ！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "オレ\n"
	.string "トライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "オレの　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}　だよ\p"
	.string "どう？\n"
	.string "オレと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "やったね！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでくれよな！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "わたし\n"
	.string "トライアスリート　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "わたしの　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "{STR_VAR_1}を　つかう　{STR_VAR_2}よ\p"
	.string "どう？\n"
	.string "わたしと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "やったね！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでよね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "オレ\n"
	.string "かいパンやろう　{STR_VAR_1}！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "オレが　そだてた　ポケモンは\n"
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}と⋯⋯$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "{STR_VAR_1}を　もつ　{STR_VAR_2}だよ\p"
	.string "どう？\n"
	.string "オレと　タッグを　くんでみない？$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "やったね！\n"
	.string "すぐ　うけつけで　とうろく　してくるね！$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "つぎに　あったときには\n"
	.string "タッグを　くんでくれよな！$"
