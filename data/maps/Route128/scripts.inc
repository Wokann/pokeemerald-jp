@ Route128 scripts (JP map g0 m43 @ 0x081EED6C)

Route128_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route128_OnFrame
	.byte 0

Route128_OnTransition::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route128_OnFrame::
	map_script_2 VAR_ROUTE128_STATE, 0x1, Route128_EventScript_KyogreAwakenedScene
	.2byte 0

Route128_EventScript_KyogreAwakenedScene::
	lockall
	delay 0x14
	applymovement LOCALID_ROUTE128_ARCHIE, Route128_Movement_ArchieLookAround
	waitmovement 0x0
	msgbox Route128_Text_ArchieWhatHappened, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE128_ARCHIE, Route128_Movement_ArchieBackUp
	waitmovement 0x0
	msgbox Route128_Text_ArchieIOnlyWanted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE128_MAXIE, Route128_Movement_MaxieApproachArchie
	waitmovement 0x0
	applymovement LOCALID_ROUTE128_ARCHIE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	msgbox Route128_Text_MaxieDoYouUnderstandNow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE128_MAXIE, Route128_Movement_MaxieApproachPlayer
	waitmovement 0x0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	msgbox Route128_Text_MaxieResposibilityFallsToArchieAndMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE128_ARCHIE, Route128_Movement_ArchieRunLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_ROUTE128_MAXIE, Route128_Movement_MaxieWalkLeft
	waitmovement 0x0
	msgbox Route128_Text_MaxieThisDefiesBelief, MSGBOX_DEFAULT
	closemessage
	delay 0x28
	applymovement LOCALID_ROUTE128_MAXIE, Route128_Movement_MaxieExit
	applymovement LOCALID_ROUTE128_ARCHIE, Route128_Movement_ArchieExit
	waitmovement 0x0
	removeobject LOCALID_ROUTE128_MAXIE
	removeobject LOCALID_ROUTE128_ARCHIE
	delay 0x64
	setfieldeffectarg 0x0, 0x1
	dofieldeffect FLDEFF_NPCFLY_OUT
	waitfieldeffect FLDEFF_NPCFLY_OUT
	addobject LOCALID_ROUTE128_STEVEN
	applymovement LOCALID_ROUTE128_STEVEN, Route128_Movement_StevenApproachPlayer
	waitmovement 0x0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0x0
	msgbox Route128_Text_StevenWhatIsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE128_STEVEN, Route128_Movement_StevenWalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	msgbox Route128_Text_StevenWholeWorldWillDrown, MSGBOX_DEFAULT
	applymovement LOCALID_ROUTE128_STEVEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0x0
	msgbox Route128_Text_StevenImGoingToSootopolis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE128_STEVEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0x0
	delay 0x32
	setfieldeffectarg 0x0, 0x1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 0xF
	removeobject LOCALID_ROUTE128_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE128_STATE, 0x2
	releaseall
	end

Route128_Movement_Unused1:
	walk_fast_left
	step_end

Route128_Movement_Unused2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route128_Movement_StevenWalkUp:
	walk_up
	step_end

Route128_Movement_StevenApproachPlayer:
	walk_fast_left
	step_end

Route128_Movement_ArchieLookAround:
	walk_fast_down
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

Route128_Movement_ArchieBackUp:
	lock_facing_direction
	walk_slow_up
	delay_16
	unlock_facing_direction
	step_end

Route128_Movement_ArchieRunLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_faster_right
	step_end

Route128_Movement_ArchieExit:
	delay_16
	delay_16
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieWalkLeft:
	walk_left
	walk_left
	delay_8
	delay_4
	step_end

Route128_Movement_MaxieApproachArchie:
	walk_left
	walk_in_place_faster_down
	step_end

Route128_Movement_MaxieExit:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieApproachPlayer:
	walk_right
	walk_in_place_faster_down
	step_end

Route128_EventScript_Isaiah::
	trainerbattle_single TRAINER_ISAIAH_1, Route128_Text_IsaiahIntro, Route128_Text_IsaiahDefeat, Route128_EventScript_RegisterIsaiah
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route128_EventScript_RematchIsaiah
	msgbox Route128_Text_IsaiahPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_RegisterIsaiah::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route128_Text_IsaiahRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAIAH_1
	release
	end

Route128_EventScript_RematchIsaiah::
	trainerbattle_rematch TRAINER_ISAIAH_1, Route128_Text_IsaiahRematchIntro, Route128_Text_IsaiahRematchDefeat
	msgbox Route128_Text_IsaiahPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Katelyn::
	trainerbattle_single TRAINER_KATELYN_1, Route128_Text_KatelynIntro, Route128_Text_KatelynDefeat, Route128_EventScript_RegisterKatelyn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route128_EventScript_RematchKatelyn
	msgbox Route128_Text_KatelynPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_RegisterKatelyn::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox Route128_Text_KatelynRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KATELYN_1
	release
	end

Route128_EventScript_RematchKatelyn::
	trainerbattle_rematch TRAINER_KATELYN_1, Route128_Text_KatelynRematchIntro, Route128_Text_KatelynRematchDefeat
	msgbox Route128_Text_KatelynPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Alexa::
	trainerbattle_single TRAINER_ALEXA, Route128_Text_AlexaIntro, Route128_Text_AlexaDefeat
	msgbox Route128_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Ruben::
	trainerbattle_single TRAINER_RUBEN, Route128_Text_RubenIntro, Route128_Text_RubenDefeat
	msgbox Route128_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Wayne::
	trainerbattle_single TRAINER_WAYNE, Route128_Text_WayneIntro, Route128_Text_WayneDefeat
	msgbox Route128_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Harrison::
	trainerbattle_single TRAINER_HARRISON, Route128_Text_HarrisonIntro, Route128_Text_HarrisonDefeat
	msgbox Route128_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Carlee::
	trainerbattle_single TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat
	msgbox Route128_Text_CarleePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_Text_ArchieWhatHappened: @ 0x081EF029
	.string "アオギリ“なんだ⋯⋯\n"
	.string "この　ひどい　ありさまは⋯⋯？\p"
	.string "おれは⋯⋯\n"
	.string "とんでもない　まちがいを⋯⋯$"

Route128_Text_ArchieIOnlyWanted: @ 0x081EF059
	.string "おれは⋯⋯\n"
	.string "ただ⋯⋯$"

Route128_Text_MaxieDoYouUnderstandNow: @ 0x081EF064
	.string "マツブサ“わかったか　アオギリ！\p"
	.string "おまえの⋯⋯\n"
	.string "いや　われわれの　したことが\l"
	.string "どれほど　おろか　だったのか⋯⋯\p"
	.string "とにかく　いそぐんだ！\n"
	.string "これいじょう　ひどく　ならぬうちに\l"
	.string "なんとか　しないとな！$"

Route128_Text_MaxieResposibilityFallsToArchieAndMe: @ 0x081EF0C6
	.string "マツブサ“{PLAYER}　なにも　いうな\p"
	.string "わたしに　アオギリを　せめる\n"
	.string "しかくが　ないことは　わかっている⋯⋯\p"
	.string "こんな　ことに　なった　いじょう\n"
	.string "もう　にんげんの　ちからでは\l"
	.string "どうする　ことも　できない　だろう\p"
	.string "しかし　だから　といって\n"
	.string "だまって　みている　わけにも　いかない\p"
	.string "この　あとしまつを　つけるのは\n"
	.string "わたしと　アオギリの　やくめ⋯⋯　か⋯⋯$"

Route128_Text_MaxieThisDefiesBelief: @ 0x081EF171
	.string "マツブサ“それにしても⋯⋯\p"
	.string "ちょう　こだいポケモン⋯⋯\n"
	.string "なんという　パワーだ\l"
	.string "すべての　バランスが　くずれたぞ⋯⋯$"

Route128_Text_StevenWhatIsHappening: @ 0x081EF1AB
	.string "ダイゴ“{PLAYER}{KUN}！\n"
	.string "これは　いったい⋯⋯？$"

Route128_Text_StevenWholeWorldWillDrown: @ 0x081EF1C1
	.string "⋯⋯ひどいな\p"
	.string "さっきは　はげしい　ひでり　だったのに\n"
	.string "また　おおあめが　ふりはじめている\p"
	.string "このまま　では　ホウエンちほう⋯⋯\n"
	.string "いや　せかいじゅうが　しずむ！\p"
	.string "この　あめを　ふらせている　くもは\n"
	.string "ルネの　じょうくうを　ちゅうしんに\l"
	.string "ひろがって　いるのか⋯⋯\p"
	.string "いったい　あそこで\n"
	.string "なにが　おきている！？\p"
	.string "ここで　あれこれ　かんがえるより\n"
	.string "ルネに　いけば　わかるか⋯⋯$"

Route128_Text_StevenImGoingToSootopolis: @ 0x081EF277
	.string "{PLAYER}{KUN}⋯⋯\n"
	.string "きみが　なにを　する　つもりか\l"
	.string "わからないけど　ムリだけは　するなよ\p"
	.string "⋯⋯じゃあ\n"
	.string "ボクは　ルネに　いくから$"
