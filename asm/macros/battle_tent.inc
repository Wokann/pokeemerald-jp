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

	@ Initialize the Fallarbor Battle Tent challenge.
	.macro fallarbortent_init
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_INIT
	special CallFallarborTentFunction
	.endm

	@ Get the current Fallarbor Battle Tent prize into VAR_RESULT.
	.macro fallarbortent_getprize
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_GET_PRIZE
	special CallFallarborTentFunction
	.endm

	@ Unused. Set Fallarbor Battle Tent's prize item.
	.macro fallarbortent_setprize unusedArg:req, itemId:req
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_SET_PRIZE
	setvar VAR_0x8005, \unusedArg
	setvar VAR_0x8006, \itemId
	special CallFallarborTentFunction
	.endm

	@ Save the Fallarbor Tent challenge with the supplied status.
	.macro fallarbortent_save challengeStatus:req
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallFallarborTentFunction
	.endm

	@ Select Fallarbor Tent's prize item from its reward table.
	.macro fallarbortent_setrandomprize
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_SET_RANDOM_PRIZE
	special CallFallarborTentFunction
	.endm

	@ Give the current Fallarbor Tent prize; FALSE means the Bag is full.
	.macro fallarbortent_giveprize
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_GIVE_PRIZE
	special CallFallarborTentFunction
	.endm

	@ Buffer the Fallarbor Tent opponent's name into gStringVar1.
	.macro fallarbortent_getopponentname
	setvar VAR_0x8004, FALLARBOR_TENT_FUNC_GET_OPPONENT_NAME
	special CallFallarborTentFunction
	.endm

	@ Initialize the Slateport Battle Tent challenge.
	.macro slateporttent_init
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_INIT
	special CallSlateportTentFunction
	.endm

	@ Get the current Slateport Battle Tent prize into VAR_RESULT.
	.macro slateporttent_getprize
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GET_PRIZE
	special CallSlateportTentFunction
	.endm

	@ Unused. Set Slateport Battle Tent's prize item.
	.macro slateporttent_setprize unusedArg:req, itemId:req
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SET_PRIZE
	setvar VAR_0x8005, \unusedArg
	setvar VAR_0x8006, \itemId
	special CallSlateportTentFunction
	.endm

	@ Save the Slateport Tent challenge with the supplied status.
	.macro slateporttent_save challengeStatus:req
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallSlateportTentFunction
	.endm

	@ Select Slateport Tent's prize item from its reward table.
	.macro slateporttent_setrandomprize
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SET_RANDOM_PRIZE
	special CallSlateportTentFunction
	.endm

	@ Give the current Slateport Tent prize; FALSE means the Bag is full.
	.macro slateporttent_giveprize
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GIVE_PRIZE
	special CallSlateportTentFunction
	.endm

	@ Slateport Tent's version of factory_rentmons.
	.macro slateporttent_rentmons
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SELECT_RENT_MONS
	special CallSlateportTentFunction
	.endm

	@ Slateport Tent's version of factory_swapmons.
	.macro slateporttent_swapmons
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_SWAP_RENT_MONS
	special CallSlateportTentFunction
	.endm

	@ Slateport Tent's version of factory_generateopponentmons.
	.macro slateporttent_generateopponentmons
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GENERATE_OPPONENT_MONS
	special CallSlateportTentFunction
	.endm

	@ Slateport Tent's version of factory_generaterentalmons.
	.macro slateporttent_generaterentalmons
	setvar VAR_0x8004, SLATEPORT_TENT_FUNC_GENERATE_RENTAL_MONS
	special CallSlateportTentFunction
	.endm
