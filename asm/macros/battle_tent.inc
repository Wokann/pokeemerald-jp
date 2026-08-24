	@ Battle Tent EventScript helpers.

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
