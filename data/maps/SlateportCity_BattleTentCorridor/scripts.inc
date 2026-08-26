@ SlateportCity_BattleTentCorridor scripts (JP map g9 m3 @ 0x081FB594)

SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

SlateportCity_BattleTentCorridor_OnWarp:: @ 0x081FB59F
	map_script_2 VAR_TEMP_1, 0x0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects:: @ 0x081FB5A9
	setvar VAR_TEMP_1, 0x1
	goto_if_ne VAR_0x8006, 0x1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, 0x2, 0x2
	turnobject LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, DIR_SOUTH

SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth:: @ 0x081FB5C4
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:: @ 0x081FB5C9
	map_script_2 VAR_TEMP_0, 0x0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor:: @ 0x081FB5D3
	goto_if_eq VAR_0x8006, 0x1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 0x1
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 0x2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate

SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom:: @ 0x081FB622
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 0x2, 0x1
	waitdooranim_jp
	applymovement LOCALID_SLATEPORT_TENT_CORRIDOR_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 0x2, 0x1
	waitdooranim_jp
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 0x4, 0x4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle:: @ 0x081FB65C
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty

SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent:: @ 0x081FB67B
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 0x1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 0x2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 0x14, 0x6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge:: @ 0x081FB6C9
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge:: @ 0x081FB6F7
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 0x14, 0x8, MULTI_YESNO, 0x1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon:: @ 0x081FB729
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons:: @ 0x081FB75F
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 0x1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent:: @ 0x081FB782
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent:: @ 0x081FB789
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge:: @ 0x081FB790
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge:: @ 0x081FB7B2
	special SavePlayerParty
	factory_setparties 0x0
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

SlateportCity_ContestHall_Text_AdviceForContests: @ 0x081FB7D9
	.string "コンテストの　ナイスな　じょうほう\n"
	.string "おしえて　やるよ！\p"
	.string "ある　わざの　つぎに\n"
	.string "とくていの　わざで　アピールすると\l"
	.string "すごく　めだつ　ときが　あるんだ！\p"
	.string "うまくやれば　かなり\n"
	.string "ゆうりな　アピールが　できるよ！\p"
	.string "ただ　じゃまされちゃう　ときも　あるけどね$"

SlateportCity_ContestHall_Text_MyPapaIsContestJudge: @ 0x081FB856
	.string "ぼくの　おとうさん　コンテストの\n"
	.string "しんさいんを　やって　いるんだ！\p"
	.string "ぼくは　おおきく　なったら\n"
	.string "コンテストの　しんさいん　と\l"
	.string "ジムリーダーと　どっちに　なろうかな？$"

SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed: @ 0x081FB8A9
	.string "どうして　おれの　ポケモンが\n"
	.string "ゆうしょう　できなかったのか\l"
	.string "ちぃっとも　わからねえ　からよぉ\l"
	.string "しんさいんに　もんく　いったけどよぉ\p"
	.string "ちぃっとも　あいて　してくれねぇのさ\n"
	.string "くやしいったら　ありゃ　しねぇぜ！\p"
	.string "おい　おまえ！\n"
	.string "だまって　これを　うけとれよぉ！$"

SlateportCity_ContestHall_Text_ExplainTorment: @ 0x081FB929
	.string "わざマシン41は　いちゃもん！\p"
	.string "あいてによぉ　おなじ　わざを　つづけて\n"
	.string "ださせねえように　する　わざ　なんだよぉ！\p"
	.string "いっとくけどなぁ\n"
	.string "おれは　いちゃもん　つけてねぇぞ！$"

SlateportCity_ContestHall_Text_MCStepUpTakePartInContest: @ 0x081FB97E
	.string "しかい“あら！　なかなか　すてきな\n"
	.string "ポケモンを　つれて　いますね！\p"
	.string "ぜひ！　コンテストに\n"
	.string "でて　みて　くださーい！\p"
	.string "きっと　いいセン　いきますよ！\n"
	.string "わたしの　みる　めは　たしかですよ！$"

SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest: @ 0x081FB9DB
	.string "しんさいん“やあ　こんにちは！\n"
	.string "きみも　トレーナーの　ようだね！\p"
	.string "だったら　ポケモンコンテストに\n"
	.string "でない　ては　ないよ！\p"
	.string "コンテストパスを　シダケタウンで　もらって\n"
	.string "いますぐ　エントリーだ！$"

SlateportCity_ContestHall_Text_ItsAppealTime: @ 0x081FBA3B
	.string "これから　いよいよ　アピールタイム！\n"
	.string "どの　わざから　みせようかな？$"

SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal: @ 0x081FBA5E
	.string "オレの　ポケモンの　アピール\n"
	.string "あんまり　みて　もらえなかった⋯⋯\p"
	.string "フッ⋯⋯　あの　しんさいん\n"
	.string "みる　めが　ないな！$"

SlateportCity_ContestHall_Text_RewardWithSageAdvice: @ 0x081FBA98
	.string "おっ！　こんな　ところまで　あがってきて\n"
	.string "キミ　けんきゅう　ねっしんだね！\l"
	.string "じゃあ　いいこと　おしえて　あげるよ\p"
	.string "だした　わざが　まわりに　うけると\n"
	.string "かいじょうが　エキサイト　してくる！\p"
	.string "いちばん　エキサイト　したとき\n"
	.string "アピールしてた　ポケモンには⋯⋯\p"
	.string "いいことが　あるかもな！$"

SlateportCity_ContestHall_Text_MoreFreakedOutThanMon: @ 0x081FBB24
	.string "だ　だめだぁ！　ポケモンより\n"
	.string "じぶんの　ほうが　きんちょう　してる！\l"
	.string "ブルブル⋯⋯　ドキドキ⋯$"

SlateportCity_ContestHall_Text_BattleAndContestAlike: @ 0x081FBB54
	.string "ポケモンしょうぶも　コンテストも\n"
	.string "ちがう　ようで　にて　いるよね！\p"
	.string "だいじに　そだてた　ポケモンを\n"
	.string "しんらいして　がんばる　ところがさ！$"

SlateportCity_ContestHall_Text_MonLooksOnTopOfGame: @ 0x081FBB99
	.string "あの　ポケモン　ちょうし　よさそうだろ！\p"
	.string "2じしんさで　ちょうしが　よくなった\n"
	.string "ポケモンは　あまり　きんちょうしないで\l"
	.string "アピール　できる　ように　なるみたいだな$"

SlateportCity_ContestHall_Text_MyMonBetterThanThatLot: @ 0x081FBBEA
	.string "なんだあー　このぐらい　なら\n"
	.string "おれの　ポケモンの　ほうが\l"
	.string "だんぜん　うえ　だね！$"

SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon: @ 0x081FBC13
	.string "げんきな　アピールを　みていると\n"
	.string "いっしょに　からだを\l"
	.string "うごかしたく　なって　こないか？$"

SlateportCity_ContestHall_Text_HyperRankStage: @ 0x081FBC40
	.string "ポケモン　コンテスト\n"
	.string "ハイパーランク　ステージ！$"
