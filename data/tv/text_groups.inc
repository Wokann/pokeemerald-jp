@ TV read-only data kept in its original mid37 physical section.
@ Text payloads remain independently organized in data/text/tv/*.inc.
@ Keep these tables in ROM order until src/tv.c owns the matching rodata.

	.globl sPokeOutbreakSpeciesList
sPokeOutbreakSpeciesList: @ 0x08568B40
	.hword SPECIES_SEEDOT, MOVE_BIDE, MOVE_HARDEN, MOVE_LEECH_SEED, 0
	.byte 3, MAP_ROUTE102
	.hword SPECIES_NUZLEAF, MOVE_HARDEN, MOVE_GROWTH, MOVE_NATURE_POWER, MOVE_LEECH_SEED
	.byte 15, MAP_ROUTE114
	.hword SPECIES_SEEDOT, MOVE_HARDEN, MOVE_GROWTH, MOVE_NATURE_POWER, MOVE_LEECH_SEED
	.byte 13, MAP_ROUTE117
	.hword SPECIES_SEEDOT, MOVE_GIGA_DRAIN, MOVE_FRUSTRATION, MOVE_SOLAR_BEAM, MOVE_LEECH_SEED
	.byte 25, MAP_ROUTE120
	.hword SPECIES_SKITTY, MOVE_GROWL, MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_ATTRACT
	.byte 8, MAP_ROUTE116

	.globl sGoldSymbolFlags
sGoldSymbolFlags: @ 0x08568B7C
	.hword 0x08C5, 0x08C7, 0x08C9, 0x08CB @ FLAG_SYS_TOWER_GOLD through FLAG_SYS_ARENA_GOLD
	.hword 0x08CD, 0x08CF, 0x08D1 @ FLAG_SYS_FACTORY_GOLD through FLAG_SYS_PYRAMID_GOLD

	.globl sSilverSymbolFlags
sSilverSymbolFlags: @ 0x08568B8A
	.hword 0x08C4, 0x08C6, 0x08C8, 0x08CA @ FLAG_SYS_TOWER_SILVER through FLAG_SYS_ARENA_SILVER
	.hword 0x08CC, 0x08CE, 0x08D0 @ FLAG_SYS_FACTORY_SILVER through FLAG_SYS_PYRAMID_SILVER

	.globl sNumberOneVarsAndThresholds
sNumberOneVarsAndThresholds: @ 0x08568B98
	.hword 0x40E6, 100 @ VAR_DAILY_SLOTS
	.hword 0x40EB, 50 @ VAR_DAILY_ROULETTE
	.hword 0x40E7, 100 @ VAR_DAILY_WILDS
	.hword 0x40E8, 20 @ VAR_DAILY_BLENDER
	.hword 0x40E9, 20 @ VAR_DAILY_PLANTED_BERRIES
	.hword 0x40EA, 20 @ VAR_DAILY_PICKED_BERRIES
	.hword 0x40F1, 30 @ VAR_DAILY_BP

	.globl sPokeNewsTextGroup_Upcoming
sPokeNewsTextGroup_Upcoming: @ 0x08568BB4
	.4byte 0
	.4byte gPokeNewsTextSlateport_Upcoming
	.4byte gPokeNewsTextGameCorner_Upcoming
	.4byte gPokeNewsTextLilycove_Upcoming
	.4byte gPokeNewsTextBlendMaster_Upcoming

	.globl sPokeNewsTextGroup_Ongoing
sPokeNewsTextGroup_Ongoing: @ 0x08568BC8
	.4byte 0
	.4byte gPokeNewsTextSlateport_Ongoing
	.4byte gPokeNewsTextGameCorner_Ongoing
	.4byte gPokeNewsTextLilycove_Ongoing
	.4byte gPokeNewsTextBlendMaster_Ongoing

	.globl sPokeNewsTextGroup_Ending
sPokeNewsTextGroup_Ending: @ 0x08568BDC
	.4byte 0
	.4byte gPokeNewsTextSlateport_Ending
	.4byte gPokeNewsTextGameCorner_Ending
	.4byte gPokeNewsTextLilycove_Ending
	.4byte gPokeNewsTextBlendMaster_Ending

	.globl gTVStringVarPtrs
gTVStringVarPtrs: @ 0x08568BF0
	.4byte gStringVar1, gStringVar2, gStringVar3

	.globl sTVFanClubTextGroup
sTVFanClubTextGroup: @ 0x08568BFC
	.4byte gTVFanClubText00
	.4byte gTVFanClubText01
	.4byte gTVFanClubText02
	.4byte gTVFanClubText03
	.4byte gTVFanClubText04
	.4byte gTVFanClubText05
	.4byte gTVFanClubText06
	.4byte gTVFanClubText07

	.globl sTVRecentHappeninssTextGroup
sTVRecentHappeninssTextGroup: @ 0x08568C1C
	.4byte gTVRecentHappeningsText00
	.4byte gTVRecentHappeningsText01
	.4byte gTVRecentHappeningsText02
	.4byte gTVRecentHappeningsText03
	.4byte gTVRecentHappeningsText04
	.4byte gTVRecentHappeningsText05

	.globl sTVFanClubOpinionsTextGroup
sTVFanClubOpinionsTextGroup: @ 0x08568C34
	.4byte gTVFanClubOpinionsText00
	.4byte gTVFanClubOpinionsText01
	.4byte gTVFanClubOpinionsText02
	.4byte gTVFanClubOpinionsText03
	.4byte gTVFanClubOpinionsText04

	.globl sTVMassOutbreakTextGroup
sTVMassOutbreakTextGroup: @ 0x08568C48
	.4byte gTVMassOutbreakText00

	.globl sTVPokemonTodaySuccessfulTextGroup
sTVPokemonTodaySuccessfulTextGroup: @ 0x08568C4C
	.4byte gTVPokemonTodaySuccessfulText00
	.4byte gTVPokemonTodaySuccessfulText01
	.4byte gTVPokemonTodaySuccessfulText02
	.4byte gTVPokemonTodaySuccessfulText03
	.4byte gTVPokemonTodaySuccessfulText04
	.4byte gTVPokemonTodaySuccessfulText05
	.4byte gTVPokemonTodaySuccessfulText06
	.4byte gTVPokemonTodaySuccessfulText07
	.4byte gTVPokemonTodaySuccessfulText08
	.4byte gTVPokemonTodaySuccessfulText09
	.4byte gTVPokemonTodaySuccessfulText10
	.4byte gTVPokemonTodaySuccessfulText11

	.globl sTVTodaysSmartShopperTextGroup
sTVTodaysSmartShopperTextGroup: @ 0x08568C7C
	.4byte SmartShopper_Text_Intro
	.4byte SmartShopper_Text_ClerkNormal
	.4byte SmartShopper_Text_RandomComment1
	.4byte SmartShopper_Text_RandomComment2
	.4byte SmartShopper_Text_RandomComment3
	.4byte SmartShopper_Text_RandomComment4
	.4byte SmartShopper_Text_SecondItem
	.4byte SmartShopper_Text_ThirdItem
	.4byte SmartShopper_Text_DuringSale
	.4byte SmartShopper_Text_OutroNormal
	.4byte SmartShopper_Text_IsVIP
	.4byte SmartShopper_Text_ClerkMax
	.4byte SmartShopper_Text_OutroMax

	.globl sTVBravoTrainerTextGroup
sTVBravoTrainerTextGroup: @ 0x08568CB0
	.4byte gTVBravoTrainerText00
	.4byte gTVBravoTrainerText01
	.4byte gTVBravoTrainerText02
	.4byte gTVBravoTrainerText03
	.4byte gTVBravoTrainerText04
	.4byte gTVBravoTrainerText05
	.4byte gTVBravoTrainerText06
	.4byte gTVBravoTrainerText07
	.4byte gTVBravoTrainerText08

	.globl sTV3CheersForPokeblocksTextGroup
sTV3CheersForPokeblocksTextGroup: @ 0x08568CD4
	.4byte gTV3CheersForPokeblocksText00
	.4byte gTV3CheersForPokeblocksText01
	.4byte gTV3CheersForPokeblocksText02
	.4byte gTV3CheersForPokeblocksText03
	.4byte gTV3CheersForPokeblocksText04
	.4byte gTV3CheersForPokeblocksText05

	.globl sTVBravoTrainerBattleTowerTextGroup
sTVBravoTrainerBattleTowerTextGroup: @ 0x08568CEC
	.4byte BravoTrainerBattleTower_Text_Intro
	.4byte BravoTrainerBattleTower_Text_NewRecord
	.4byte BravoTrainerBattleTower_Text_Lost
	.4byte BravoTrainerBattleTower_Text_Won
	.4byte BravoTrainerBattleTower_Text_LostFinal
	.4byte BravoTrainerBattleTower_Text_Satisfied
	.4byte BravoTrainerBattleTower_Text_Unsatisfied
	.4byte BravoTrainerBattleTower_Text_None1
	.4byte BravoTrainerBattleTower_Text_None2
	.4byte BravoTrainerBattleTower_Text_None3
	.4byte BravoTrainerBattleTower_Text_None4
	.4byte BravoTrainerBattleTower_Text_Response
	.4byte BravoTrainerBattleTower_Text_ResponseSatisfied
	.4byte BravoTrainerBattleTower_Text_ResponseUnsatisfied
	.4byte BravoTrainerBattleTower_Text_Outro

	.globl sTVContestLiveUpdatesTextGroup
sTVContestLiveUpdatesTextGroup: @ 0x08568D28
	.4byte ContestLiveUpdates_Text_Intro
	.4byte ContestLiveUpdates_Text_WonBothRounds
	.4byte ContestLiveUpdates_Text_BetterRound2
	.4byte ContestLiveUpdates_Text_EqualRounds
	.4byte ContestLiveUpdates_Text_BetterRound1
	.4byte ContestLiveUpdates_Text_GotNervous
	.4byte ContestLiveUpdates_Text_StartledFoes
	.4byte ContestLiveUpdates_Text_UsedCombo
	.4byte ContestLiveUpdates_Text_ExcitingAppeal
	.4byte ContestLiveUpdates_Text_WasCool
	.4byte ContestLiveUpdates_Text_WasBeautiful
	.4byte ContestLiveUpdates_Text_WasCute
	.4byte ContestLiveUpdates_Text_WasSmart
	.4byte ContestLiveUpdates_Text_WasTough
	.4byte ContestLiveUpdates_Text_VeryExcitingAppeal
	.4byte ContestLiveUpdates_Text_VeryCool
	.4byte ContestLiveUpdates_Text_VeryBeautiful
	.4byte ContestLiveUpdates_Text_VeryCute
	.4byte ContestLiveUpdates_Text_VerySmart
	.4byte ContestLiveUpdates_Text_VeryTough
	.4byte ContestLiveUpdates_Text_TookBreak
	.4byte ContestLiveUpdates_Text_GotStartled
	.4byte ContestLiveUpdates_Text_MoveWonderful
	.4byte ContestLiveUpdates_Text_TalkAboutAnotherMon
	.4byte ContestLiveUpdates_Text_FailedToAppeal
	.4byte ContestLiveUpdates_Text_LastInBothRounds
	.4byte ContestLiveUpdates_Text_NotExcitingEnough
	.4byte ContestLiveUpdates_Text_LostAfterWinningRound1
	.4byte ContestLiveUpdates_Text_NeverExciting
	.4byte ContestLiveUpdates_Text_LostBySmallMargin
	.4byte ContestLiveUpdates_Text_RepeatedAppeals
	.4byte ContestLiveUpdates_Text_ValiantEffortButLost
	.4byte ContestLiveUpdates_Text_Outro

	.globl sTVPokemonBattleUpdateTextGroup
sTVPokemonBattleUpdateTextGroup: @ 0x08568DAC
	.4byte gTVPokemonBattleUpdateText00
	.4byte gTVPokemonBattleUpdateText01
	.4byte gTVPokemonBattleUpdateText02
	.4byte gTVPokemonBattleUpdateText03
	.4byte gTVPokemonBattleUpdateText04
	.4byte gTVPokemonBattleUpdateText05
	.4byte gTVPokemonBattleUpdateText06
	.4byte gTVPokemonBattleUpdateText07

	.globl sTVTrainerFanClubSpecialTextGroup
sTVTrainerFanClubSpecialTextGroup: @ 0x08568DCC
	.4byte gTVTrainerFanClubSpecialText00
	.4byte gTVTrainerFanClubSpecialText01
	.4byte gTVTrainerFanClubSpecialText02
	.4byte gTVTrainerFanClubSpecialText03
	.4byte gTVTrainerFanClubSpecialText04
	.4byte gTVTrainerFanClubSpecialText05

	.globl sTVNameRaterTextGroup
sTVNameRaterTextGroup: @ 0x08568DE4
	.4byte gTVNameRaterText00
	.4byte gTVNameRaterText01
	.4byte gTVNameRaterText02
	.4byte gTVNameRaterText03
	.4byte gTVNameRaterText04
	.4byte gTVNameRaterText05
	.4byte gTVNameRaterText06
	.4byte gTVNameRaterText07
	.4byte gTVNameRaterText08
	.4byte gTVNameRaterText09
	.4byte gTVNameRaterText10
	.4byte gTVNameRaterText11
	.4byte gTVNameRaterText12
	.4byte gTVNameRaterText13
	.4byte gTVNameRaterText14
	.4byte gTVNameRaterText15
	.4byte gTVNameRaterText16
	.4byte gTVNameRaterText17
	.4byte gTVNameRaterText18

	.globl sTVLilycoveContestLadyTextGroup
sTVLilycoveContestLadyTextGroup: @ 0x08568E30
	.4byte ContestLadyShow_Text_Intro
	.4byte ContestLadyShow_Text_Won
	.4byte ContestLadyShow_Text_Lost
	.4byte ContestLadyShow_Text_LostBadly

	.globl sTVPokemonTodayFailedTextGroup
sTVPokemonTodayFailedTextGroup: @ 0x08568E40
	.4byte gTVPokemonTodayFailedText00
	.4byte gTVPokemonTodayFailedText01
	.4byte gTVPokemonTodayFailedText02
	.4byte gTVPokemonTodayFailedText03
	.4byte gTVPokemonTodayFailedText04
	.4byte gTVPokemonTodayFailedText05
	.4byte gTVPokemonTodayFailedText06

	.globl sTVPokemonAnglerTextGroup
sTVPokemonAnglerTextGroup: @ 0x08568E5C
	.4byte gTVPokemonAnglerText00
	.4byte gTVPokemonAnglerText01

	.globl sTVWorldOfMastersTextGroup
sTVWorldOfMastersTextGroup: @ 0x08568E64
	.4byte gTVWorldOfMastersText00
	.4byte gTVWorldOfMastersText01
	.4byte gTVWorldOfMastersText02

	.globl sTVTodaysRivalTrainerTextGroup
sTVTodaysRivalTrainerTextGroup: @ 0x08568E70
	.4byte gTVTodaysRivalTrainerText00
	.4byte gTVTodaysRivalTrainerText01
	.4byte gTVTodaysRivalTrainerText02
	.4byte gTVTodaysRivalTrainerText03
	.4byte gTVTodaysRivalTrainerText04
	.4byte gTVTodaysRivalTrainerText05
	.4byte gTVTodaysRivalTrainerText06
	.4byte gTVTodaysRivalTrainerText07
	.4byte gTVTodaysRivalTrainerText08
	.4byte gTVTodaysRivalTrainerText09
	.4byte gTVTodaysRivalTrainerText10

	.globl sTVDewfordTrendWatcherNetworkTextGroup
sTVDewfordTrendWatcherNetworkTextGroup: @ 0x08568E9C
	.4byte TrendWatcher_Text_Intro
	.4byte TrendWatcher_Text_MaleTaughtMePhrase
	.4byte TrendWatcher_Text_FemaleTaughtMePhrase
	.4byte TrendWatcher_Text_PhraseWasHopeless
	.4byte TrendWatcher_Text_MaleTellMeBigger
	.4byte TrendWatcher_Text_FemaleTellMeBigger
	.4byte TrendWatcher_Text_Outro

	.globl sTVHoennTreasureInvestisatorsTextGroup
sTVHoennTreasureInvestisatorsTextGroup: @ 0x08568EB8
	.4byte gTVHoennTreasureInvestigatorsText00
	.4byte gTVHoennTreasureInvestigatorsText01
	.4byte gTVHoennTreasureInvestigatorsText02

	.globl sTVFindThatGamerTextGroup
sTVFindThatGamerTextGroup: @ 0x08568EC4
	.4byte gTVFindThatGamerText00
	.4byte gTVFindThatGamerText01
	.4byte gTVFindThatGamerText02
	.4byte gTVFindThatGamerText03

	.globl sTVBreakingNewsTextGroup
sTVBreakingNewsTextGroup: @ 0x08568ED4
	.4byte gTVBreakingNewsText00
	.4byte gTVBreakingNewsText01
	.4byte gTVBreakingNewsText02
	.4byte gTVBreakingNewsText03
	.4byte gTVBreakingNewsText04
	.4byte gTVBreakingNewsText05
	.4byte gTVBreakingNewsText06
	.4byte gTVBreakingNewsText07
	.4byte gTVBreakingNewsText08
	.4byte gTVBreakingNewsText09
	.4byte gTVBreakingNewsText10
	.4byte gTVBreakingNewsText11
	.4byte gTVBreakingNewsText12

	.globl sTVSecretBaseVisitTextGroup
sTVSecretBaseVisitTextGroup: @ 0x08568F08
	.4byte gTVSecretBaseVisitText00
	.4byte gTVSecretBaseVisitText01
	.4byte gTVSecretBaseVisitText02
	.4byte gTVSecretBaseVisitText03
	.4byte gTVSecretBaseVisitText04
	.4byte gTVSecretBaseVisitText05
	.4byte gTVSecretBaseVisitText06
	.4byte gTVSecretBaseVisitText07
	.4byte gTVSecretBaseVisitText08
	.4byte gTVSecretBaseVisitText09
	.4byte gTVSecretBaseVisitText10
	.4byte gTVSecretBaseVisitText11
	.4byte gTVSecretBaseVisitText12
	.4byte gTVSecretBaseVisitText13

	.globl sTVPokemonLotteryWinnerFlashReportTextGroup
sTVPokemonLotteryWinnerFlashReportTextGroup: @ 0x08568F40
	.4byte gTVPokemonLotteryWinnerFlashReportText00

	.globl sTVThePokemonBattleSeminarTextGroup
sTVThePokemonBattleSeminarTextGroup: @ 0x08568F44
	.4byte gTVThePokemonBattleSeminarText00
	.4byte gTVThePokemonBattleSeminarText01
	.4byte gTVThePokemonBattleSeminarText02
	.4byte gTVThePokemonBattleSeminarText03
	.4byte gTVThePokemonBattleSeminarText04
	.4byte gTVThePokemonBattleSeminarText05
	.4byte gTVThePokemonBattleSeminarText06

	.globl sTVTrainerFanClubTextGroup
sTVTrainerFanClubTextGroup: @ 0x08568F60
	.4byte gTVTrainerFanClubText00
	.4byte gTVTrainerFanClubText01
	.4byte gTVTrainerFanClubText02
	.4byte gTVTrainerFanClubText03
	.4byte gTVTrainerFanClubText04
	.4byte gTVTrainerFanClubText05
	.4byte gTVTrainerFanClubText06
	.4byte gTVTrainerFanClubText07
	.4byte gTVTrainerFanClubText08
	.4byte gTVTrainerFanClubText09
	.4byte gTVTrainerFanClubText10
	.4byte gTVTrainerFanClubText11

	.globl sTVCutiesTextGroup
sTVCutiesTextGroup: @ 0x08568F90
	.4byte TVSpotTheCuties_Text_Intro
	.4byte TVSpotTheCuties_Text_RibbonsLow
	.4byte TVSpotTheCuties_Text_RibbonsMid
	.4byte TVSpotTheCuties_Text_RibbonsHigh
	.4byte TVSpotTheCuties_Text_RibbonIntro
	.4byte TVSpotTheCuties_Text_RibbonChampion
	.4byte TVSpotTheCuties_Text_RibbonCool
	.4byte TVSpotTheCuties_Text_RibbonBeauty
	.4byte TVSpotTheCuties_Text_RibbonCute
	.4byte TVSpotTheCuties_Text_RibbonSmart
	.4byte TVSpotTheCuties_Text_RibbonTough
	.4byte TVSpotTheCuties_Text_RibbonWinning
	.4byte TVSpotTheCuties_Text_RibbonVictory
	.4byte TVSpotTheCuties_Text_RibbonArtist
	.4byte TVSpotTheCuties_Text_RibbonEffort
	.4byte TVSpotTheCuties_Text_Outro

	.globl sTVPokemonNewsBattleFrontierTextGroup
sTVPokemonNewsBattleFrontierTextGroup: @ 0x08568FD0
	.4byte gTVPokemonNewsBattleFrontierText00
	.4byte gTVPokemonNewsBattleFrontierText01
	.4byte gTVPokemonNewsBattleFrontierText02
	.4byte gTVPokemonNewsBattleFrontierText03
	.4byte gTVPokemonNewsBattleFrontierText04
	.4byte gTVPokemonNewsBattleFrontierText05
	.4byte gTVPokemonNewsBattleFrontierText06
	.4byte gTVPokemonNewsBattleFrontierText07
	.4byte gTVPokemonNewsBattleFrontierText08
	.4byte gTVPokemonNewsBattleFrontierText09
	.4byte gTVPokemonNewsBattleFrontierText10
	.4byte gTVPokemonNewsBattleFrontierText11
	.4byte gTVPokemonNewsBattleFrontierText12
	.4byte gTVPokemonNewsBattleFrontierText13
	.4byte gTVPokemonNewsBattleFrontierText14
	.4byte gTVPokemonNewsBattleFrontierText15
	.4byte gTVPokemonNewsBattleFrontierText16
	.4byte gTVPokemonNewsBattleFrontierText17
	.4byte gTVPokemonNewsBattleFrontierText18

	.globl sTVWhatsNo1InHoennTodayTextGroup
sTVWhatsNo1InHoennTodayTextGroup: @ 0x0856901C
	.4byte gTVWhatsNo1InHoennTodayText00
	.4byte gTVWhatsNo1InHoennTodayText01
	.4byte gTVWhatsNo1InHoennTodayText02
	.4byte gTVWhatsNo1InHoennTodayText03
	.4byte gTVWhatsNo1InHoennTodayText04
	.4byte gTVWhatsNo1InHoennTodayText05
	.4byte gTVWhatsNo1InHoennTodayText06
	.4byte gTVWhatsNo1InHoennTodayText07
	.4byte gTVWhatsNo1InHoennTodayText08

	.globl sTVSecretBaseSecretsTextGroup
sTVSecretBaseSecretsTextGroup: @ 0x08569040
	.4byte TVSecretBaseSecrets_Text_Intro
	.4byte TVSecretBaseSecrets_Text_WhatWillPlayerDoNext1
	.4byte TVSecretBaseSecrets_Text_WhatWillPlayerDoNext2
	.4byte TVSecretBaseSecrets_Text_TookXStepsBeforeLeaving
	.4byte TVSecretBaseSecrets_Text_BaseFailedToInterestPlayer
	.4byte TVSecretBaseSecrets_Text_PlayerEnjoyedBase
	.4byte TVSecretBaseSecrets_Text_PlayerHugeFanOfBase
	.4byte TVSecretBaseSecrets_Text_Outro
	.4byte TVSecretBaseSecrets_Text_StoppedMoving1
	.4byte TVSecretBaseSecrets_Text_StoppedMoving2
	.4byte TVSecretBaseSecrets_Text_UsedChair
	.4byte TVSecretBaseSecrets_Text_UsedBalloon
	.4byte TVSecretBaseSecrets_Text_UsedTent
	.4byte TVSecretBaseSecrets_Text_UsedPlant
	.4byte TVSecretBaseSecrets_Text_UsedGoldShield
	.4byte TVSecretBaseSecrets_Text_UsedSilverShield
	.4byte TVSecretBaseSecrets_Text_UsedGlassOrnament
	.4byte TVSecretBaseSecrets_Text_UsedTV
	.4byte TVSecretBaseSecrets_Text_UsedMudBall
	.4byte TVSecretBaseSecrets_Text_UsedBag
	.4byte TVSecretBaseSecrets_Text_UsedCushion
	.4byte TVSecretBaseSecrets_Text_HitCushion
	.4byte TVSecretBaseSecrets_Text_HuggedCushion
	.4byte TVSecretBaseSecrets_Text_BattledWon
	.4byte TVSecretBaseSecrets_Text_BattledLost
	.4byte TVSecretBaseSecrets_Text_DeclinedBattle
	.4byte TVSecretBaseSecrets_Text_UsedPoster
	.4byte TVSecretBaseSecrets_Text_UsedNoteMat
	.4byte TVSecretBaseSecrets_Text_BattledDraw
	.4byte TVSecretBaseSecrets_Text_UsedSpinMat
	.4byte TVSecretBaseSecrets_Text_UsedSandOrnament
	.4byte TVSecretBaseSecrets_Text_UsedDesk
	.4byte TVSecretBaseSecrets_Text_UsedBrick
	.4byte TVSecretBaseSecrets_Text_UsedSolidBoard
	.4byte TVSecretBaseSecrets_Text_UsedFence
	.4byte TVSecretBaseSecrets_Text_UsedGlitterMat
	.4byte TVSecretBaseSecrets_Text_UsedTire
	.4byte TVSecretBaseSecrets_Text_UsedStand
	.4byte TVSecretBaseSecrets_Text_BrokeDoor
	.4byte TVSecretBaseSecrets_Text_UsedDoll
	.4byte TVSecretBaseSecrets_Text_UsedSlide
	.4byte TVSecretBaseSecrets_Text_UsedSlideButDidntGoDown
	.4byte TVSecretBaseSecrets_Text_UsedJumpMat

	.globl sTVSafariFanClubTextGroup
sTVSafariFanClubTextGroup: @ 0x085690EC
	.4byte gTVSafariFanClubText00
	.4byte gTVSafariFanClubText01
	.4byte gTVSafariFanClubText02
	.4byte gTVSafariFanClubText03
	.4byte gTVSafariFanClubText04
	.4byte gTVSafariFanClubText05
	.4byte gTVSafariFanClubText06
	.4byte gTVSafariFanClubText07
	.4byte gTVSafariFanClubText08
	.4byte gTVSafariFanClubText09
	.4byte gTVSafariFanClubText10

	.globl sTVInSearchOfTrainersTextGroup
sTVInSearchOfTrainersTextGroup: @ 0x08569118
	.4byte gTVInSearchOfTrainersText00
	.4byte gTVInSearchOfTrainersText01
	.4byte gTVInSearchOfTrainersText02
	.4byte gTVInSearchOfTrainersText03
	.4byte gTVInSearchOfTrainersText04
	.4byte gTVInSearchOfTrainersText05
	.4byte gTVInSearchOfTrainersText06
	.4byte gTVInSearchOfTrainersText07
	.4byte gTVInSearchOfTrainersText08

	.globl sTVSecretBaseSecretsActions
sTVSecretBaseSecretsActions: @ 0x0856913C
	.byte 0x0A @ SBSECRETS_STATE_USED_CHAIR
	.byte 0x0B @ SBSECRETS_STATE_USED_BALLOON
	.byte 0x0C @ SBSECRETS_STATE_USED_TENT
	.byte 0x0D @ SBSECRETS_STATE_USED_PLANT
	.byte 0x0E @ SBSECRETS_STATE_USED_GOLD_SHIELD
	.byte 0x0F @ SBSECRETS_STATE_USED_SILVER_SHIELD
	.byte 0x10 @ SBSECRETS_STATE_USED_GLASS_ORNAMENT
	.byte 0x11 @ SBSECRETS_STATE_USED_TV
	.byte 0x12 @ SBSECRETS_STATE_USED_MUD_BALL
	.byte 0x13 @ SBSECRETS_STATE_USED_BAG
	.byte 0x14 @ SBSECRETS_STATE_USED_CUSHION
	.byte 0x17 @ SBSECRETS_STATE_BATTLED_WON
	.byte 0x18 @ SBSECRETS_STATE_BATTLED_LOST
	.byte 0x19 @ SBSECRETS_STATE_DECLINED_BATTLE
	.byte 0x1A @ SBSECRETS_STATE_USED_POSTER
	.byte 0x1B @ SBSECRETS_STATE_USED_NOTE_MAT
	.byte 0x1C @ SBSECRETS_STATE_BATTLED_DRAW
	.byte 0x1D @ SBSECRETS_STATE_USED_SPIN_MAT
	.byte 0x1E @ SBSECRETS_STATE_USED_SAND_ORNAMENT
	.byte 0x1F @ SBSECRETS_STATE_USED_DESK
	.byte 0x20 @ SBSECRETS_STATE_USED_BRICK
	.byte 0x21 @ SBSECRETS_STATE_USED_SOLID_BOARD
	.byte 0x22 @ SBSECRETS_STATE_USED_FENCE
	.byte 0x23 @ SBSECRETS_STATE_USED_GLITTER_MAT
	.byte 0x24 @ SBSECRETS_STATE_USED_TIRE
	.byte 0x25 @ SBSECRETS_STATE_USED_STAND
	.byte 0x26 @ SBSECRETS_STATE_USED_BREAKABLE_DOOR
	.byte 0x27 @ SBSECRETS_STATE_USED_DOLL
	.byte 0x28 @ SBSECRETS_STATE_USED_SLIDE
	.byte 0x29 @ SBSECRETS_STATE_DECLINED_SLIDE
	.byte 0x2A @ SBSECRETS_STATE_USED_JUMP_MAT
	.byte 0x2B @ SBSECRETS_NUM_STATES
