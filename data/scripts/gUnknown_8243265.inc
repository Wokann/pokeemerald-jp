Common_EventScript_FerryDepart:: @ 0x08243265
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EventScript_HideMrBriney:: @ 0x0824327B
	.incbin "baserom_jp.gba", 0x24327b, 0x58

Common_EventScript_FerryDepartIsland:: @ 0x082432D3
	call_if_eq VAR_FACING, DIR_SOUTH, Ferry_EventScript_DepartIslandSouth
	call_if_eq VAR_FACING, DIR_WEST, Ferry_EventScript_DepartIslandWest
	delay 30
	hideplayer
	call Common_EventScript_FerryDepart
	return

	.incbin "baserom_jp.gba", 0x2432f7, 0x67

Route120_EventScript_Kecleon1:: @ 0x0824335E
	.incbin "baserom_jp.gba", 0x24335e, 0xd

Route120_EventScript_Kecleon2:: @ 0x0824336B
	.incbin "baserom_jp.gba", 0x24336b, 0xd

Route120_EventScript_Kecleon3:: @ 0x08243378
	.incbin "baserom_jp.gba", 0x243378, 0xd

Route120_EventScript_Kecleon4:: @ 0x08243385
	.incbin "baserom_jp.gba", 0x243385, 0xd

Route120_EventScript_Kecleon5:: @ 0x08243392
	.incbin "baserom_jp.gba", 0x243392, 0xd

Route119_EventScript_Kecleon1:: @ 0x0824339F
	.incbin "baserom_jp.gba", 0x24339f, 0xd

Route119_EventScript_Kecleon2:: @ 0x082433AC
	.incbin "baserom_jp.gba", 0x2433ac, 0xd

EventScript_Kecleon:: @ 0x082433B9
	.incbin "baserom_jp.gba", 0x2433b9, 0x91

Movement_KecleonAppears: @ 0x0824344A
	.incbin "baserom_jp.gba", 0x24344a, 0x1d1

Common_Movement_ExclamationMark: @ 0x0824361B
	emote_exclamation_mark
	step_end

Common_Movement_Delay48: @ 0x0824361D
	delay_16
	delay_16
	delay_16
	step_end

Common_Movement_FacePlayer: @ 0x08243621
	face_player
	step_end

Common_Movement_FaceAwayPlayer: @ 0x08243623
	face_away_player
	step_end

Common_Movement_FaceOriginalDirection: @ 0x08243625
	face_original_direction
	step_end

Common_Movement_WalkInPlaceFasterLeft: @ 0x08243627
	walk_in_place_faster_left
	step_end

Common_Movement_WalkInPlaceFasterUp: @ 0x08243629
	walk_in_place_faster_up
	step_end

Common_Movement_WalkInPlaceFasterRight: @ 0x0824362B
	walk_in_place_faster_right
	step_end

Common_Movement_WalkInPlaceFasterDown: @ 0x0824362D
	walk_in_place_faster_down
	step_end

Common_Movement_FaceRight:: @ 0x0824362F
	face_right
	step_end

Common_Movement_FaceLeft:: @ 0x08243631
	face_left
	step_end

Common_Movement_FaceDown:: @ 0x08243633
	face_down
	step_end

Common_Movement_FaceUp:: @ 0x08243635
	face_up
	step_end

Common_Movement_WalkInPlaceDown:: @ 0x08243637
	walk_in_place_down
	step_end

Common_Movement_WalkInPlaceLeft:: @ 0x08243639
	walk_in_place_left
	step_end

Common_Movement_WalkInPlaceRight:: @ 0x0824363B
	walk_in_place_right
	step_end

Common_Movement_WalkUp6:: @ 0x0824363D
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Common_Movement_WalkUp4:: @ 0x08243644
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Common_Movement_Delay32:: @ 0x08243649
	delay_16
	delay_16
	step_end

Common_Movement_WalkUp:: @ 0x0824364C
	walk_up
	step_end

@ Unused
Common_Movement_WalkUp2:: @ 0x0824364E
	walk_up
	walk_up
	step_end
