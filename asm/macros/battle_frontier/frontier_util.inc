	@ Battle Frontier EventScript helpers used by the structured Battle Tent maps.

	@ Get the current challenge status into VAR_TEMP_CHALLENGE_STATUS.
	.macro frontier_getstatus
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_GET_STATUS
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
