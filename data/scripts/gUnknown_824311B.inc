	lockall
	loadword 0x0, 0x81F0308
	callstd 0x4
	fadescreen 0x1
	special FieldShowRegionMap
	releaseall
	end

Common_EventScript_PlayBrineysBoatMusic:: @ 0x0824312C
	setflag 0x4001
	playbgm 0x1AF, 0x0
	return

Common_EventScript_StopBrineysBoatMusic:: @ 0x08243134
	clearflag 0x4001
	fadedefaultbgm
	return

ProfBirch_EventScript_UpdateLocation:: @ 0x08243139
	compare_var_to_value 0x4085, 0x0
	goto_if 0x1, 0x8244178
	checkflag 0x864
	goto_if 0x1, 0x82431A6
	compare_var_to_value 0x4049, 0x0
	call_if 0x1, 0x82431A6
	compare_var_to_value 0x4049, 0x1
	call_if 0x1, 0x82431A6
	compare_var_to_value 0x4049, 0x2
	call_if 0x1, 0x82431B3
	compare_var_to_value 0x4049, 0x3
	call_if 0x1, 0x82431B3
	compare_var_to_value 0x4049, 0x4
	call_if 0x1, 0x82431C0
	compare_var_to_value 0x4049, 0x5
	call_if 0x1, 0x82431C0
	compare_var_to_value 0x4049, 0x6
	call_if 0x1, 0x82431A6
	compare_var_to_value 0x4049, 0x7
	call_if 0x1, 0x82431A6
	return
	clearflag 0x2D1
	clearflag 0x380
	setflag 0x381
	setflag 0x382
	return
	clearflag 0x381
	setflag 0x2D1
	setflag 0x380
	setflag 0x382
	return
	clearflag 0x382
	setflag 0x381
	setflag 0x2D1
	setflag 0x380
	return
	lock
	faceplayer
	checkflag 0x119
	goto_if 0x0, 0x81F186D
	loadword 0x0, 0x8262DF5
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82431F2
	call 0x8243207
	release
	end
	loadword 0x0, 0x8262E1D
	callstd 0x4
	release
	end
	copyvar 0x8004, 0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return
	setvar 0x8004, 0x0
	specialvar 0x800D, ScriptGetPokedexInfo
	copyvar 0x8008, 0x8005
	copyvar 0x8009, 0x8006
	copyvar 0x800A, 0x800D
	buffernumberstring 0x0, 0x8008
	buffernumberstring 0x1, 0x8009
	loadword 0x0, 0x8262E39
	callstd 0x4
	call 0x82431FC
	compare_var_to_value 0x800A, 0x0
	goto_if 0x1, 0x8244178
	setvar 0x8004, 0x1
	specialvar 0x800D, ScriptGetPokedexInfo
	copyvar 0x8008, 0x8005
	copyvar 0x8009, 0x8006
	buffernumberstring 0x0, 0x8008
	buffernumberstring 0x1, 0x8009
	loadword 0x0, 0x826316A
	callstd 0x4
	return
	delay 0x3C
	applymovement 0x8004, 0x8243273
	waitmovement 0x0
	return
	.incbin "baserom_jp.gba", 0x243273, 0x8

	.globl EventScript_HideMrBriney
EventScript_HideMrBriney:: @ 0x0824327B
	.incbin "baserom_jp.gba", 0x24327b, 0xe3

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
