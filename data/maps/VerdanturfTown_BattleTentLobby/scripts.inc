@ VerdanturfTown_BattleTentLobby scripts (JP map g6 m0 @ 0x081F6365)

VerdanturfTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentLobby_OnWarp
	.byte 0

VerdanturfTown_BattleTentLobby_OnWarp:: @ 0x081F6370
	map_script_2 VAR_TEMP_1, 0x0, VerdanturfTown_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_TurnPlayerNorth:: @ 0x081F637A
	setvar VAR_TEMP_1, 0x1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

VerdanturfTown_BattleTentLobby_OnFrame:: @ 0x081F6384
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x0, VerdanturfTown_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x1, VerdanturfTown_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x2, VerdanturfTown_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x3, VerdanturfTown_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0x4, VerdanturfTown_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_GetChallengeStatus:: @ 0x081F63AE
	frontier_getstatus
	end

VerdanturfTown_BattleTentLobby_EventScript_QuitWithoutSaving:: @ 0x081F63B7
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_WonChallenge:: @ 0x081F63EC
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_AchievedThreeWinStreak, MSGBOX_DEFAULT
	message VerdanturfTown_BattleTentLobby_Text_FeatWillBeRecorded
	waitmessage
	verdanturftent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	verdanturftent_save 0
	playse SE_SAVE
	waitse

VerdanturfTown_BattleTentLobby_EventScript_GivePrize:: @ 0x081F6426
	msgbox VerdanturfTown_BattleTentLobby_Text_PresentYouWithPrize, MSGBOX_DEFAULT
	verdanturftent_giveprize
	switch VAR_RESULT
	case FALSE, VerdanturfTown_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleDomeLobby_Text_ReceivedPrize
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_NoRoomForPrize:: @ 0x081F6472
	msgbox BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_PrizeWaiting:: @ 0x081F6483
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_AchievedThreeWinStreak, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_GivePrize
	end

VerdanturfTown_BattleTentLobby_EventScript_LostChallenge:: @ 0x081F6492
	lockall
	message VerdanturfTown_BattleTentLobby_Text_ResultsWillBeRecorded
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	verdanturftent_save 0
	playse SE_SAVE
	waitse
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_ResumeChallenge:: @ 0x081F64CC
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	verdanturftent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	goto VerdanturfTown_BattleTentLobby_EventScript_EnterChallenge

VerdanturfTown_BattleTentLobby_EventScript_Attendant:: @ 0x081F6508
	lock
	faceplayer
	verdanturftent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, VerdanturfTown_BattleTentLobby_EventScript_PrizeWaiting
	special SavePlayerParty
	msgbox VerdanturfTown_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT

VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge:: @ 0x081F6528
	message VerdanturfTown_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 0x11, 0x6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, VerdanturfTown_BattleTentLobby_EventScript_ExplainChallenge
	case 2, VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge:: @ 0x081F6564
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 0x2
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox VerdanturfTown_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0x1
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0x0, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	msgbox VerdanturfTown_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge:: @ 0x081F65E9
	setvar VAR_TEMP_CHALLENGE_STATUS, 0x0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	verdanturftent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 0x2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 0xFF
	goto_if_eq VAR_RESULT, 0x0, VerdanturfTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed

VerdanturfTown_BattleTentLobby_EventScript_EnterChallenge:: @ 0x081F6643
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox VerdanturfTown_BattleTentLobby_Text_NowFollowMe, MSGBOX_DEFAULT
	closemessage
	call VerdanturfTown_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR, 0x2, 0x7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0x0
	waitstate
	end

VerdanturfTown_BattleTentLobby_EventScript_ExplainChallenge:: @ 0x081F6670
	msgbox VerdanturfTown_BattleTentLobby_Text_ExplainVerdanturfTent, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons:: @ 0x081F667D
	switch VAR_RESULT
	case FRONTIER_LVL_50, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50:: @ 0x081F6698
	msgbox VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen:: @ 0x081F66A5
	msgbox VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed:: @ 0x081F66B2
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge:: @ 0x081F66C9
	special LoadPlayerParty

VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge:: @ 0x081F66CC
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT

VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge:: @ 0x081F66D4
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_WalkToDoor:: @ 0x081F66D6
	applymovement LOCALID_VERDANTURF_TENT_ATTENDANT, VerdanturfTown_BattleTentLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_WalkToDoor
	waitmovement 0
	opendoor 0x6, 0x1
	waitdooranim_jp
	applymovement LOCALID_VERDANTURF_TENT_ATTENDANT, VerdanturfTown_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 0x6, 0x1
	waitdooranim_jp
	return

VerdanturfTown_BattleTentLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_EventScript_AttractGiver:: @ 0x081F6710
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ATTRACT, VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep, MSGBOX_DEFAULT
	giveitem ITEM_TM_ATTRACT
	goto_if_eq VAR_RESULT, 0x0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ATTRACT
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract:: @ 0x081F6747
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy1:: @ 0x081F6751
	msgbox VerdanturfTown_BattleTentLobby_Text_TaughtWhatKindsOfMoves, MSGBOX_NPC
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy2:: @ 0x081F675A
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_Scott:: @ 0x081F6765
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_VERDANTURF, VerdanturfTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo
	msgbox VerdanturfTown_BattleTentLobby_Text_ScottCanMeetToughTrainers, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 0x1
	setflag FLAG_MET_SCOTT_IN_VERDANTURF
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo:: @ 0x081F6782
	msgbox VerdanturfTown_BattleTentLobby_Text_ScottVisitRegularly, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_LittleBoy:: @ 0x081F678C
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_GentleMonsScaryIfAngry, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesBoard:: @ 0x081F6797
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard:: @ 0x081F67A6
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BATTLE_TENT_RULES
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_RulesLevel
	case 1, VerdanturfTown_BattleTentLobby_EventScript_RulesBasics
	case 2, VerdanturfTown_BattleTentLobby_EventScript_RulesNature
	case 3, VerdanturfTown_BattleTentLobby_EventScript_RulesMoves
	case 4, VerdanturfTown_BattleTentLobby_EventScript_RulesUnderpowered
	case 5, VerdanturfTown_BattleTentLobby_EventScript_RulesWhenInDanger
	case 6, VerdanturfTown_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_ExitRules
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesLevel:: @ 0x081F6813
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesBasics:: @ 0x081F6821
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesNature:: @ 0x081F682F
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesMoves:: @ 0x081F683D
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesUnderpowered:: @ 0x081F684B
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesWhenInDanger:: @ 0x081F6859
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_ExitRules:: @ 0x081F6867
	releaseall
	end

VerdanturfTown_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves: @ 0x081F6869
	.string "どんなに　つよい　ポケモンも\n"
	.string "きらいな　わざは　できるだけ\l"
	.string "つかいたく　ない　みたい\p"
	.string "たとえば　おとなしい　せいかくの\n"
	.string "ポケモンは　あいてを　いため　つけたり\l"
	.string "するのは　すきじゃ　ない　だろうね\p"
	.string "きっと　じぶんの　ちからを　はっき　できない\n"
	.string "とき　って　きらいな　わざを　むりに\l"
	.string "だそう　として　しっぱい　してるんだよ$"

VerdanturfTown_BattleTentLobby_Text_GentleMonsScaryIfAngry: @ 0x081F6909
	.string "でもでも　ぼくの　おねえちゃん　って\n"
	.string "ふだんは　とっても　おとなしい　けど\l"
	.string "おこると　すっごーーーく　こわーーーいよ！\p"
	.string "だから　おとなしい　ポケモン　だって\n"
	.string "おこったら　きっと　こわーーーいよ！！$"

VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep: @ 0x081F696C
	.string "あたしの　ポケモンへの　きもち⋯⋯\n"
	.string "それは　まさに　メロメロなのよ⋯⋯\p"
	.string "あら　へんなところ　みられちゃった\p"
	.string "まあ　いいわ\n"
	.string "あなたの　ポケモンに\l"
	.string "この　わざマシンは　いかが？$"

VerdanturfTown_BattleTentLobby_Text_AttractionMutual: @ 0x081F69C3
	.string "ポケモンの　あたしへの　きもちも⋯⋯\n"
	.string "やっぱり　メロメロに　ちがいないわ！\p"
	.string "だって　あたしの　おもう　とおりに\n"
	.string "たたかって　くれるもの！$"

VerdanturfTown_BattleTentLobby_Text_TaughtWhatKindsOfMoves: @ 0x081F6A08
	.string "きみの　ポケモンには\n"
	.string "どんなわざを　もたせて　いるんだい？\p"
	.string "やっぱり　じぶんを　かいふくしたり\n"
	.string "ぼうぎょを　あげたり　するわざが　あると\l"
	.string "ゆうり　だと　おもうんだよ$"

VerdanturfTown_BattleTentLobby_Text_ScottCanMeetToughTrainers: @ 0x081F6A5B
	.string "エニシダ“これは　これは\n"
	.string "{PLAYER}{KUN}　あえると　おもってたよ！\p"
	.string "バトルテント　って　いうのはさ！\n"
	.string "どんな　ルール　だって\l"
	.string "どんな　たたかいかた　だって\l"
	.string "かんけいなく　つよい　トレーナーと\l"
	.string "であえる　ばしょだと　おもうよ！\p"
	.string "{PLAYER}{KUN}も　めいっぱい\n"
	.string "がんばってよ！$"

VerdanturfTown_BattleTentLobby_Text_ScottVisitRegularly: @ 0x081F6ADD
	.string "エニシダ“どんな　ときにも　つよい\n"
	.string "トレーナーに　あいたくって\l"
	.string "わたしは　ここに　かよって　いるんだよね$"
