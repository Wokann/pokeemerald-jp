	lock 
	faceplayer 
	call 0x82424C9
	specialvar 0x800D, GetTrainerFlag
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, 0x824245B
	special HasEnoughMonsForDoubleBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, 0x8242454
	special SetUpTrainerEncounterMusic
	special SetUpTrainerMovement
	goto 0x82424D6
	special ShowTrainerCantBattleSpeech
	waitmessage 
	waitbuttonpress 
	release 
	end 
	.incbin "baserom_jp.gba", 0x24245b, 0x1
