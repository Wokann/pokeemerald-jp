SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room.

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 2, 2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	@ The JP ROM uses waitmoncry here; US uses waitdooranim for this door sequence.
	waitmoncry
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitmoncry
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S.
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "コンテストの　ナイスな　じょうほう\n"
	.string "おしえて　やるよ！\p"
	.string "ある　わざの　つぎに\n"
	.string "とくていの　わざで　アピールすると\l"
	.string "すごく　めだつ　ときが　あるんだ！\p"
	.string "うまくやれば　かなり\n"
	.string "ゆうりな　アピールが　できるよ！\p"
	.string "ただ　じゃまされちゃう　ときも　あるけどね$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "ぼくの　おとうさん　コンテストの\n"
	.string "しんさいんを　やって　いるんだ！\p"
	.string "ぼくは　おおきく　なったら\n"
	.string "コンテストの　しんさいん　と\l"
	.string "ジムリーダーと　どっちに　なろうかな？$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "どうして　おれの　ポケモンが\n"
	.string "ゆうしょう　できなかったのか\l"
	.string "ちぃっとも　わからねえ　からよぉ\l"
	.string "しんさいんに　もんく　いったけどよぉ\p"
	.string "ちぃっとも　あいて　してくれねぇのさ\n"
	.string "くやしいったら　ありゃ　しねぇぜ！\p"
	.string "おい　おまえ！\n"
	.string "だまって　これを　うけとれよぉ！$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "わざマシン41は　いちゃもん！\p"
	.string "あいてによぉ　おなじ　わざを　つづけて\n"
	.string "ださせねえように　する　わざ　なんだよぉ！\p"
	.string "いっとくけどなぁ\n"
	.string "おれは　いちゃもん　つけてねぇぞ！$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "しかい“あら！　なかなか　すてきな\n"
	.string "ポケモンを　つれて　いますね！\p"
	.string "ぜひ！　コンテストに\n"
	.string "でて　みて　くださーい！\p"
	.string "きっと　いいセン　いきますよ！\n"
	.string "わたしの　みる　めは　たしかですよ！$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "しんさいん“やあ　こんにちは！\n"
	.string "きみも　トレーナーの　ようだね！\p"
	.string "だったら　ポケモンコンテストに\n"
	.string "でない　ては　ないよ！\p"
	.string "コンテストパスを　シダケタウンで　もらって\n"
	.string "いますぐ　エントリーだ！$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "これから　いよいよ　アピールタイム！\n"
	.string "どの　わざから　みせようかな？$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "オレの　ポケモンの　アピール\n"
	.string "あんまり　みて　もらえなかった⋯⋯\p"
	.string "フッ⋯⋯　あの　しんさいん\n"
	.string "みる　めが　ないな！$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "おっ！　こんな　ところまで　あがってきて\n"
	.string "キミ　けんきゅう　ねっしんだね！\l"
	.string "じゃあ　いいこと　おしえて　あげるよ\p"
	.string "だした　わざが　まわりに　うけると\n"
	.string "かいじょうが　エキサイト　してくる！\p"
	.string "いちばん　エキサイト　したとき\n"
	.string "アピールしてた　ポケモンには⋯⋯\p"
	.string "いいことが　あるかもな！$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "だ　だめだぁ！　ポケモンより\n"
	.string "じぶんの　ほうが　きんちょう　してる！\l"
	.string "ブルブル⋯⋯　ドキドキ⋯$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "ポケモンしょうぶも　コンテストも\n"
	.string "ちがう　ようで　にて　いるよね！\p"
	.string "だいじに　そだてた　ポケモンを\n"
	.string "しんらいして　がんばる　ところがさ！$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "あの　ポケモン　ちょうし　よさそうだろ！\p"
	.string "2じしんさで　ちょうしが　よくなった\n"
	.string "ポケモンは　あまり　きんちょうしないで\l"
	.string "アピール　できる　ように　なるみたいだな$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "なんだあー　このぐらい　なら\n"
	.string "おれの　ポケモンの　ほうが\l"
	.string "だんぜん　うえ　だね！$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "げんきな　アピールを　みていると\n"
	.string "いっしょに　からだを\l"
	.string "うごかしたく　なって　こないか？$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "ポケモン　コンテスト\n"
	.string "ハイパーランク　ステージ！$"
