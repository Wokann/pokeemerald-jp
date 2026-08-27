	@ Battle Arena EventScript helpers.

	@ Initialize the Battle Arena challenge.
	.macro arena_init
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_INIT
	special CallBattleArenaFunction
	.endm

	@ Get an ARENA_DATA_* value into VAR_RESULT.
	.macro arena_get data:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleArenaFunction
	.endm

	@ Save the game and set the challenge status.
	.macro arena_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleArenaFunction
	.endm

	@ Set an ARENA_DATA_* value. Variables are copied into VAR_0x8006.
	.macro arena_set data:req, val:req
	setvar VAR_0x8004, BATTLE_ARENA_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallBattleArenaFunction
	.endm
