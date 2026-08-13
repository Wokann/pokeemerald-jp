	lockall 
	incrementgamestat 0x2C
	special ResetTVShowState
	specialvar 0x800D, CheckForBigMovieOrEmergencyNewsOnTV
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x824C50A
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x824C514
	checkflag 0x892
	goto_if 0x0, 0x824C4FA
	checkflag 0x891
	goto_if 0x1, 0x824C4FA
	specialvar 0x800D, IsTVShowInSearchOfTrainersAiring
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x824C56F
	goto 0x824C559
	end 
	.incbin "baserom_jp.gba", 0x24c4c4, 0xa14e
