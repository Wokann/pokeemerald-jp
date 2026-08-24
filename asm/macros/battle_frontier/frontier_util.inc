	@ Battle Frontier EventScript helpers used by the structured Battle Tent maps.

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

	@ Perform the Frontier soft reset operation.
	.macro frontier_reset
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SOFT_RESET
	special CallFrontierUtilFunc
	.endm
