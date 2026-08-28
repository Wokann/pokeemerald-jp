CaveHole_CheckFallDownHole:: @ 0x0826432F
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
	.2byte 0

CaveHole_FixCrackedGround:: @ 0x08264339
#ifdef UBFIX
	setvar VAR_ICE_STEP_COUNT, 1
#else
	copyvar VAR_ICE_STEP_COUNT, 1, warn=FALSE
#endif
	end

EventScript_FallDownHole:: @ 0x0826433F
	lockall
	delay 20
	applymovement LOCALID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_UNDEFINED
	waitstate
	end

EventScript_FallDownHoleMtPyre:: @ 0x08264358
	lockall
	delay 20
	applymovement LOCALID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	special DoFallWarp
	end

Movement_SetInvisible: @ 0x08264371
	set_invisible
	step_end
