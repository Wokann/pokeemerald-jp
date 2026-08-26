@ FallarborTown_BattleTentCorridor scripts (JP map g5 m2 @ 0x081F57D8)

FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:: @ 0x081F57DE
	map_script_2 VAR_TEMP_0, 0x0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor:: @ 0x081F57E8
	lockall
	setvar VAR_TEMP_0, 0x1
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 0x2, 0x1
	waitdooranim_jp
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 0x2, 0x1
	waitdooranim_jp
	setvar VAR_0x8006, 0x0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 0x4, 0x4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

FallarborTown_ContestHall_Text_DoAllRightInPreliminary: @ 0x081F5835
	.string "1じ　しんさでは　いいセン　いくけど\n"
	.string "なぜか　アピールで　かてないんだ⋯⋯\p"
	.string "じぶんの　ポケモンばっかり　みてると\n"
	.string "かてないって　ことかなあ$"

FallarborTown_ContestHall_Text_MonAllTheseRibbons: @ 0x081F587B
	.string "みて！　わたしの　ポケモン\n"
	.string "こんなに　リボンが　いっぱい！\p"
	.string "あなたの　ポケモンは　リボン　もらった？\n"
	.string "もらって　いれば　ポケナビで　みられるわよ！$"

FallarborTown_ContestHall_Text_CantWinEverywhere: @ 0x081F58C5
	.string "ジムリーダーにも　かてない⋯⋯\p"
	.string "コンテストでも　かてない⋯⋯\p"
	.string "あっちのまち　こっちのまちを\n"
	.string "いったり　きたり　だよ⋯⋯$"

FallarborTown_ContestHall_Text_SuperRankStage: @ 0x081F5901
	.string "ポケモン　コンテスト\n"
	.string "スーパーランク　ステージ！$"
