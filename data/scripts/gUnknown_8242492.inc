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
	gotobeatenscript 
	special ShowTrainerCantBattleSpeech
	waitmessage 
	waitbuttonpress 
	release 
	end 
	applymovement 0x800F, 0x82424D4
	waitmovement 0x0
	return 
	hideobject_at 0x25FE, 0x3400
	waitmessage 
	waitbuttonpress 
	special TryPrepareSecondApproachingTrainer
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x82423F0
	goto 0x82424EE
	dotrainerbattle 
	specialvar 0x800D, GetTrainerBattleMode
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x824252B
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x824252B
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x824252B
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, 0x824252B
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, 0x824252B
	gotopostbattlescript 
	releaseall 
	end 
