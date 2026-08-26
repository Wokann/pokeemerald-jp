@ LavaridgeTown_Gym_B1F scripts (JP map g4 m2 @ 0x081F4DBA)

LavaridgeTown_Gym_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_B1F_OnTransition
	.byte 0

LavaridgeTown_Gym_B1F_OnTransition: @ 0x081F4DC0
	call LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers
	end

LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars:: @ 0x081F4DCB
	setvar VAR_TEMP_7, 0
	setvar VAR_TEMP_8, 0
	setvar VAR_TEMP_9, 0
	setvar VAR_TEMP_A, 0
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar
	setvar VAR_TEMP_7, 1

LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar:: @ 0x081F4DED
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar
	setvar VAR_TEMP_8, 1

LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar:: @ 0x081F4DFB
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar
	setvar VAR_TEMP_9, 1

LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar:: @ 0x081F4E09
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_A, 1

LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars:: @ 0x081F4E17
	return

LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers:: @ 0x081F4E18
	goto_if_defeated TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace
	setobjectmovementtype LOCALID_KEEGAN, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace:: @ 0x081F4E25
	goto_if_defeated TRAINER_JACE, LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff
	setobjectmovementtype LOCALID_JACE, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff:: @ 0x081F4E32
	goto_if_defeated TRAINER_JEFF, LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli
	setobjectmovementtype LOCALID_JEFF, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli:: @ 0x081F4E3F
	goto_if_defeated TRAINER_ELI, LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_ELI, MOVEMENT_TYPE_BURIED

LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers:: @ 0x081F4E4C
	return
