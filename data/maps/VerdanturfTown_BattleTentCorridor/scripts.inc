@ VerdanturfTown_BattleTentCorridor scripts (JP map g6 m1 @ 0x081F6B12)

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:: @ 0x081F6B18
	map_script_2 VAR_TEMP_0, 0x0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor:: @ 0x081F6B22
	lockall
	setvar VAR_TEMP_0, 0x1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 0x2, 0x1
	waitdooranim_jp
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 0x2, 0x1
	waitdooranim_jp
	setvar VAR_0x8006, 0x0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 0x6, 0x5
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

VerdanturfTown_ContestHall_Text_WhichContestYouEntering: @ 0x081F6B6F
	.string "きみ　なにコンテストに　でるの？\n"
	.string "ひとつ　アドバイス　してあげるよ！\p"
	.string "たとえば　かわいさコンテスト　でも\n"
	.string "1じしんさで　かわいさ　だけが\l"
	.string "みられてる　わけじゃ　ないみたいなんだ\p"
	.string "そだてかたを　くふう　したほうが　いいよ！$"

VerdanturfTown_ContestHall_Text_RaisedMonToBeCute: @ 0x081F6BDE
	.string "ポケモンが　かわいく　なるように\n"
	.string "そだてて　いたんだけど\p"
	.string "コンテストって　かわいらしさも\n"
	.string "きそう　ことが　できるのね！\p"
	.string "だいじに　そだてて　よかった⋯⋯$"

VerdanturfTown_ContestHall_Text_MyMonRules: @ 0x081F6C2B
	.string "おれの　ポケモン⋯⋯\p"
	.string "そりゃあ　もう　かっこよくて\n"
	.string "たくましくて　うつくしくて\l"
	.string "かわいくて　かしこいんだけど　さ\p"
	.string "こうなったら　ぜんぶの　コンテストで\n"
	.string "かたっぱし　から　ゆうしょう　ねらうか！$"

VerdanturfTown_ContestHall_Text_NormalRankStage: @ 0x081F6C8C
	.string "ポケモン　コンテスト\n"
	.string "ノーマルランク　ステージ！$"
