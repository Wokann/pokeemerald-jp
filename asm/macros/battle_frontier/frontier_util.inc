	@ Battle Frontier EventScript helpers used by the structured Battle Tent maps.

	@ Get the current challenge status into VAR_TEMP_CHALLENGE_STATUS.
	.macro frontier_getstatus
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_STATUS
	special CallFrontierUtilFunc
	.endm

	@ Get the number of facility symbols the player has.
	.macro frontier_getsymbols
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_FACILITY_SYMBOLS
	special CallFrontierUtilFunc
	.endm

	@ Award the facility symbol for the current Frontier challenge.
	.macro frontier_givesymbol
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GIVE_FACILITY_SYMBOL
	special CallFrontierUtilFunc
	.endm

	@ Restore held items that were present before entering the challenge.
	.macro frontier_restorehelditems
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESTORE_HELD_ITEMS
	special CallFrontierUtilFunc
	.endm

	@ Restore moves changed by Sketch during the challenge.
	.macro frontier_resetsketch
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESET_SKETCH_MOVES
	special CallFrontierUtilFunc
	.endm

	@ Set the current Frontier Brain object graphics.
	.macro frontier_setbrainobj
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_BRAIN_OBJECT
	special CallFrontierUtilFunc
	.endm

	@ Increment the current Frontier win streak.
	.macro frontier_incrementstreak
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_INCREMENT_STREAK
	special CallFrontierUtilFunc
	.endm

	@ Get the current Frontier Brain status into VAR_RESULT.
	.macro frontier_getbrainstatus
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_BRAIN_STATUS
	special CallFrontierUtilFunc
	.endm

	@ Check whether the Battle Frontier TV special should air.
	.macro frontier_checkairshow
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_CHECK_AIR_TV_SHOW
	special CallFrontierUtilFunc
	.endm

	@ TRUE if the current opponent is a Frontier Brain.
	.macro frontier_isbrain
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_IS_BRAIN
	special CallFrontierUtilFunc
	.endm

	@ Award Battle Points for the current Frontier challenge.
	.macro frontier_givepoints
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GIVE_BATTLE_POINTS
	special CallFrontierUtilFunc
	.endm

	@ Save the recorded Frontier battle. VAR_RESULT is TRUE on success.
	.macro frontier_savebattle
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_BATTLE
	special CallFrontierUtilFunc
	.endm

	@ Buffer gTrainerBattleOpponent_A's name to STR_VAR_1 (0) or STR_VAR_2 (1).
	.macro frontier_gettrainername stringVar:req
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_BUFFER_TRAINER_NAME
	.if \stringVar == STR_VAR_1
		setvar VAR_0x8005, 0
	.elseif \stringVar == STR_VAR_2
		setvar VAR_0x8005, 1
	.else
		setvar VAR_0x8005, \stringVar
	.endif
	special CallFrontierUtilFunc
	.endm

	@ Get a FRONTIER_DATA_* value into VAR_RESULT.
	.macro frontier_get data:req
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallFrontierUtilFunc
	.endm

	@ Set a FRONTIER_DATA_* value. Values at or after VARS_START are copied.
	.macro frontier_set data:req, val=0xFFFF
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val == 0xFFFF
	@ no value provided
	.elseif \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallFrontierUtilFunc
	.endm

	@ Load the selected party mons into the Frontier battle party.
	.macro frontier_setpartyorder partySize:req
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	setvar VAR_0x8005, \partySize
	special CallFrontierUtilFunc
	.endm

	@ TRUE if the party lacks eligible mons for the current challenge.
	@ The result is written to VAR_0x8004; VAR_RESULT holds the level mode.
	.macro frontier_checkineligible
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_CHECK_INELIGIBLE
	special CallFrontierUtilFunc
	.endm

	@ Validates the visiting E-Reader trainer. 0 if valid, 1 if not
	.macro frontier_checkvisittrainer
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_CHECK_VISIT_TRAINER
	special CallFrontierUtilFunc
	.endm

	@ Perform the Frontier soft reset operation.
	.macro frontier_reset
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SOFT_RESET
	special CallFrontierUtilFunc
	.endm

	@ Sets the selected party mons in the saveblock.
	.macro frontier_saveparty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY
	special CallFrontierUtilFunc
	.endm

	@ Shows the results window for a Battle Frontier facility.
	.macro frontier_results facility:req, mode=0xFF
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_RESULTS_WINDOW
	setvar VAR_0x8005, \facility
	.if \mode != 0xFF
	setvar VAR_0x8006, \mode
	.endif
	special CallFrontierUtilFunc
	.endm
