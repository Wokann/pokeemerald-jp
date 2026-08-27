	lockall
	trainerhill_gettime
	msgbox TrainerHill_Entrance_Text_ChallengeTime, MSGBOX_DEFAULT
	releaseall
	end

TrainerHill_1F_EventScript_DummyWarpToEntranceCounter::
	setvar VAR_TEMP_2, 1
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_1F_EventScript_WarpSilentToEntranceCounter  @ VAR_RESULT always FALSE here
	end

@ Never reached
TrainerHill_1F_EventScript_WarpSilentToEntranceCounter::
	warpsilent MAP_TRAINER_HILL_ENTRANCE, 9, 6
	waitstate
	end

TrainerHill_1F_EventScript_Lost::
	trainerhill_settrainerflags
	trainerhill_lost
	setvar VAR_TEMP_1, 1
	end

TrainerHill_EventScript_WarpToEntranceCounter::
	setvar VAR_TEMP_1, 0
	warp MAP_TRAINER_HILL_ENTRANCE, 9, 6
	waitstate
	end

@ Unused
TrainerHill_1F_Movement_SetInvisible:
	set_invisible
	step_end
