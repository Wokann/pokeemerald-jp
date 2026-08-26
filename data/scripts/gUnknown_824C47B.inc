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
	.incbin "baserom_jp.gba", 0x253f43, 0x19c

GabbyAndTy_EventScript_UpdateLocation:: @ 0x082540DF
	.incbin "baserom_jp.gba", 0x2540df, 0x10f

GabbyAndTy_EventScript_GabbyBattle1:: @ 0x082541EE
	.incbin "baserom_jp.gba", 0x2541ee, 0x20

GabbyAndTy_EventScript_TyBattle1:: @ 0x0825420E
	.incbin "baserom_jp.gba", 0x25420e, 0x20

GabbyAndTy_EventScript_GabbyBattle2:: @ 0x0825422E
	.incbin "baserom_jp.gba", 0x25422e, 0x20

GabbyAndTy_EventScript_TyBattle2:: @ 0x0825424E
	.incbin "baserom_jp.gba", 0x25424e, 0x20

GabbyAndTy_EventScript_GabbyBattle3:: @ 0x0825426E
	.incbin "baserom_jp.gba", 0x25426e, 0x20

GabbyAndTy_EventScript_TyBattle3:: @ 0x0825428E
	.incbin "baserom_jp.gba", 0x25428e, 0x20

GabbyAndTy_EventScript_GabbyBattle4:: @ 0x082542AE
	.incbin "baserom_jp.gba", 0x2542ae, 0x20

GabbyAndTy_EventScript_TyBattle4:: @ 0x082542CE
	.incbin "baserom_jp.gba", 0x2542ce, 0x20

GabbyAndTy_EventScript_GabbyBattle5:: @ 0x082542EE
	.incbin "baserom_jp.gba", 0x2542ee, 0x20

GabbyAndTy_EventScript_TyBattle5:: @ 0x0825430E
	.incbin "baserom_jp.gba", 0x25430e, 0x20

GabbyAndTy_EventScript_GabbyBattle6:: @ 0x0825432E
	.incbin "baserom_jp.gba", 0x25432e, 0x20

GabbyAndTy_EventScript_TyBattle6:: @ 0x0825434E
	.incbin "baserom_jp.gba", 0x25434e, 0x20

	.incbin "baserom_jp.gba", 0x25436e, 0x225a

EventScript_CutTree:: @ 0x082565C8
	.incbin "baserom_jp.gba", 0x2565c8, 0x4a
