	specialvar 0x800D, IsTrainerReadyForRematch
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82424C1
	special HasEnoughMonsForDoubleBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, 0x82424C2
	special SetUpTrainerEncounterMusic
	special SetUpTrainerMovement
	special ShowTrainerIntroSpeech
	waitmessage 
	waitbuttonpress 
	special BattleSetup_StartRematchBattle
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x2424c1, 0x6d
