	lock 
	faceplayer 
	applymovement 0x800F, 0x82424D4
	waitmovement 0x0
	specialvar 0x800D, GetTrainerFlag
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, 0x8242423
	special SetUpTrainerEncounterMusic
	special SetUpTrainerMovement
	goto 0x82424D6
	gotobeatenscript 
