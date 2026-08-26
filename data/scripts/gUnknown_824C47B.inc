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
	specialvar 0x8004, special_0x44
	compare_var_to_value 0x8004, 0xFF
	goto_if 0x1, 0x824C548
	specialvar 0x800D, special_0x4a
	compare_var_to_value 0x800D, 0xFF
	goto_if 0x1, 0x824C548
	copyvar 0x8004, 0x800D
	specialvar 0x800D, special_0x45
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, 0x824C52A
	end
	special GetMomOrDadStringForTVMessage
	loadword 0x0, 0x8243A12
	callstd 0x4
	special TurnOffTVScreen
	releaseall
	end
	loadword 0x0, 0x81EFD18
	callstd 0x4
	releaseall
	end
	loadword 0x0, 0x81EFED2
	callstd 0x4
	special InitRoamer
	clearflag 0x8BD
	setflag 0xFF
	special TurnOffTVScreen
	releaseall
	end
	special DoTVShow
	waitmessage
	waitbuttonpress
	compare_var_to_value 0x800D, 0x1
	goto_if 0x5, 0x824C52A
	goto 0x824C540
	end
	special TurnOffTVScreen
	setflag 0x891
	releaseall
	end
	special GetMomOrDadStringForTVMessage
	loadword 0x0, 0x8243A12
	callstd 0x4
	goto 0x824C540
	end
	special DoPokeNews
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x824C4C4
	waitmessage
	waitbuttonpress
	goto 0x824C540
	end
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x824C56F
	goto 0x824C540
	end
	.incbin "baserom_jp.gba", 0x24c585, 0x78ec
	.globl LilycoveCity_ContestLobby_EventScript_Reporter
LilycoveCity_ContestLobby_EventScript_Reporter: @ 0x08253E71
	.incbin "baserom_jp.gba", 0x253e71, 0xd2
LilycoveCity_ContestLobby_EventScript_TryShowContestReporter: @ 0x08253F43
	.incbin "baserom_jp.gba", 0x253f43, 0x26cf
