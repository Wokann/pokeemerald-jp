	@ Battle Frontier Apprentice EventScript helpers.

	@ TRUE if the player has talked to the Apprentice and answered their level mode question.
	.macro apprentice_shouldcheckgone
	setvar VAR_0x8004, APPRENTICE_FUNC_CHECK_GONE
	special CallApprenticeFunction
	.endm

	@ Set the Apprentice object-event graphics from the current trainer class.
	.macro apprentice_setgfx
	setvar VAR_0x8004, APPRENTICE_FUNC_SET_GFX
	special CallApprenticeFunction
	.endm
