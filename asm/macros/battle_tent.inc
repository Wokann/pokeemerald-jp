	@ Battle Tent EventScript helpers.

	@ Initialize the Verdanturf Battle Tent challenge.
	.macro verdanturftent_init
	setvar VAR_0x8004, VERDANTURF_TENT_FUNC_INIT
	special CallVerdanturfTentFunction
	.endm

	@ Get the current Verdanturf Battle Tent prize into VAR_RESULT.
	.macro verdanturftent_getprize
	setvar VAR_0x8004, VERDANTURF_TENT_FUNC_GET_PRIZE
	special CallVerdanturfTentFunction
	.endm

	@ Save the Verdanturf Tent challenge with the supplied status.
	.macro verdanturftent_save challengeStatus:req
	setvar VAR_0x8004, VERDANTURF_TENT_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallVerdanturfTentFunction
	.endm

	@ Select Verdanturf Tent's prize item from its reward table.
	.macro verdanturftent_setrandomprize
	setvar VAR_0x8004, VERDANTURF_TENT_FUNC_SET_RANDOM_PRIZE
	special CallVerdanturfTentFunction
	.endm

	@ Give the current Verdanturf Tent prize; FALSE means the Bag is full.
	.macro verdanturftent_giveprize
	setvar VAR_0x8004, VERDANTURF_TENT_FUNC_GIVE_PRIZE
	special CallVerdanturfTentFunction
	.endm

	@ Buffer the next Battle Tent opponent's intro speech into gStringVar4.
	.macro battletent_getopponentintro
	setvar VAR_0x8004, VERDANTURF_TENT_FUNC_GET_OPPONENT_INTRO
	special CallVerdanturfTentFunction
	.endm

	@ Save the Fallarbor Tent challenge with the supplied status.
	.macro fallarbortent_save challengeStatus:req
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallFallarborTentFunction
	.endm

	@ Buffer the Fallarbor Tent opponent's name into gStringVar1.
	.macro fallarbortent_getopponentname
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_GET_OPPONENT_NAME
	special CallFallarborTentFunction
	.endm
