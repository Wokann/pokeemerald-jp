@ VerdanturfTown_BattleTentCorridor scripts (JP map g6 m1 @ 0x081F6B12)

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0x0
	opendoor 2, 1
	@ The JP command table retains waitmoncry (0xAE) at both door waits.
	waitmoncry
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0x0
	closedoor 2, 1
	waitmoncry
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S.
@ Unused.
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "きみ　なにコンテストに　でるの？\n"
	.string "ひとつ　アドバイス　してあげるよ！\p"
	.string "たとえば　かわいさコンテスト　でも\n"
	.string "1じしんさで　かわいさ　だけが\l"
	.string "みられてる　わけじゃ　ないみたいなんだ\p"
	.string "そだてかたを　くふう　したほうが　いいよ！$"

@ Unused.
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "ポケモンが　かわいく　なるように\n"
	.string "そだてて　いたんだけど\p"
	.string "コンテストって　かわいらしさも\n"
	.string "きそう　ことが　できるのね！\p"
	.string "だいじに　そだてて　よかった⋯⋯$"

@ Unused.
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "おれの　ポケモン⋯⋯\p"
	.string "そりゃあ　もう　かっこよくて\n"
	.string "たくましくて　うつくしくて\l"
	.string "かわいくて　かしこいんだけど　さ\p"
	.string "こうなったら　ぜんぶの　コンテストで\n"
	.string "かたっぱし　から　ゆうしょう　ねらうか！$"

@ Unused.
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "ポケモン　コンテスト\n"
	.string "ノーマルランク　ステージ！$"
