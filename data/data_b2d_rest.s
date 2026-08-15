.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.globl gUnknown_85AB057
gUnknown_85AB057: @ 0x85AB057
	.incbin "baserom_jp.gba", 0x5ab057, 0x35

	.globl gUnknown_85AB08C
gUnknown_85AB08C: @ 0x85AB08C
	.string "キ⋯コくス⋯コくナ⋯コくヘ⋯コくメ⋯コくラ⋯コくワ⋯コくャ⋯コくからすぎた！$しぶすぎた！$あますぎた！$にがすぎた！$すっぱすぎた！$"
	.globl gUnknown_85AB0D0
gUnknown_85AB0D0: @ 0x85AB0D0
	.string "？⋯コく‘⋯コく/⋯コくG⋯コくN⋯コく{B_PLAYER_NAME}は　\n"
	.string "{B_LAST_ITEM}を　つかった！$ミツルは　\n"
	.string "{B_LAST_ITEM}を　つかった！${B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
	.string "{B_LAST_ITEM}を　つかった！$トレーナーに　ボールを　はじかれた！$ひとの　ものを　とったら　どろぼう！$よけられた！\n"
	.string "こいつは　つかまりそうにないぞ！$ポケモンに\n"
	.string "うまく　あたらなかった！$だめだ！　ポケモンが\n"
	.string "ボールから　でてしまった！$ああ！\n"
	.string "つかまえたと　おもったのに！$ざんねん！\n"
	.string "もうすこしで　つかまえられたのに！$おしい！\n"
	.string "あと　ちょっとの　ところだったのに！$やったー！\n"
	.string "{B_OPPONENT_MON1_NAME}を　つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"
	.string "$やったー！\n"
	.string "{B_OPPONENT_MON1_NAME}を　つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}$つかまえた　{B_OPPONENT_MON1_NAME}に\n"
	.string "ニックネームを　つけますか？${B_OPPONENT_MON1_NAME}は　{B_PC_CREATOR_NAME}　パソコンに\n"
	.string "てんそうされた！$"
	.globl gUnknown_85AB225
gUnknown_85AB225: @ 0x85AB225
	.string "だれかの$"
	.globl gUnknown_85AB22A
gUnknown_85AB22A: @ 0x85AB22A
	.string "マユミの${B_OPPONENT_MON1_NAME}の　データが　あたらしく\n"
	.string "ポケモンずかんに　セーブされます！\p"
	.string "$あめが　ふっている$すなあらしが　ふきあれている$ボックスが　いっぱいで\n"
	.string "これいじょう　つかまえられない！\p$"
	.globl gUnknown_85AB288
gUnknown_85AB288: @ 0x85AB288
	.string "ナゾのみ$"

	.globl gUnknown_85AB28D
gUnknown_85AB28D: @ 0x85AB28D
	.string "のみ${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "まひが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "どくが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "やけどが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "こおりじょうたいが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "ねむりから　さめた！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "こんらんが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "{SE_RG_BAG_POCKET}じょうたいが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "じょうたいいじょうが　なおった！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "たいりょくを　かいふくした！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "{SE_RG_BAG_POCKET}の　わざポイントを　かいふくした！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "ステータスを　もとに　もどした！${B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "すこし　かいふく${B_LAST_ITEM}の　こうかで\n"
	.string "{B_CURRENT_MOVE}しか　だすことができない！\p"
	.string "${B_DEF_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
	.string "もちこたえた！$"
	.globl gUnknown_85AB3BD
gUnknown_85AB3BD: @ 0x85AB3BD
	.string "　$ここで　ボールを　なげるんだね\n"
	.string "ぼく⋯⋯　やってみるよ！$"
	.globl gUnknown_85AB3DC
gUnknown_85AB3DC: @ 0x85AB3DC
	.incbin "baserom_jp.gba", 0x5ab3dc, 0x5c4

	.globl gMissStringIds
gMissStringIds: @ 0x85AB9A0
	.hword STRINGID_ATTACKMISSED
	.hword STRINGID_PKMNPROTECTEDITSELF
	.hword STRINGID_PKMNAVOIDEDATTACK
	.hword STRINGID_AVOIDEDDAMAGE
	.hword STRINGID_PKMNMAKESGROUNDMISS
	.globl gNoEscapeStringIds
gNoEscapeStringIds: @ 0x85AB9AA
	.hword STRINGID_CANTESCAPE
	.hword STRINGID_DONTLEAVEBIRCH
	.hword STRINGID_PREVENTSESCAPE
	.hword STRINGID_CANTESCAPE2
	.hword STRINGID_ATTACKERCANTESCAPE
	.globl gMoveWeatherChangeStringIds
gMoveWeatherChangeStringIds: @ 0x85AB9B4
	.hword STRINGID_STARTEDTORAIN
	.hword STRINGID_DOWNPOURSTARTED
	.hword STRINGID_BUTITFAILED
	.hword STRINGID_SANDSTORMBREWED
	.hword STRINGID_SUNLIGHTGOTBRIGHT
	.hword STRINGID_STARTEDHAIL
	.globl gSandStormHailContinuesStringIds
gSandStormHailContinuesStringIds: @ 0x85AB9C0
	.hword STRINGID_SANDSTORMRAGES
	.hword STRINGID_HAILCONTINUES
	.globl gSandStormHailDmgStringIds
gSandStormHailDmgStringIds: @ 0x85AB9C4
	.hword STRINGID_PKMNBUFFETEDBYSANDSTORM
	.hword STRINGID_PKMNPELTEDBYHAIL
	.globl gSandStormHailEndStringIds
gSandStormHailEndStringIds: @ 0x85AB9C8
	.hword STRINGID_SANDSTORMSUBSIDED
	.hword STRINGID_HAILSTOPPED
	.globl gRainContinuesStringIds
gRainContinuesStringIds: @ 0x85AB9CC
	.hword STRINGID_RAINCONTINUES
	.hword STRINGID_DOWNPOURCONTINUES
	.hword STRINGID_RAINSTOPPED
	.globl gProtectLikeUsedStringIds
gProtectLikeUsedStringIds: @ 0x85AB9D2
	.hword STRINGID_PKMNPROTECTEDITSELF2
	.hword STRINGID_PKMNBRACEDITSELF
	.hword STRINGID_BUTITFAILED
	.globl gReflectLightScreenSafeguardStringIds
gReflectLightScreenSafeguardStringIds: @ 0x85AB9D8
	.hword STRINGID_BUTITFAILED
	.hword STRINGID_PKMNRAISEDDEF
	.hword STRINGID_PKMNRAISEDDEFALITTLE
	.hword STRINGID_PKMNRAISEDSPDEF
	.hword STRINGID_PKMNRAISEDSPDEFALITTLE
	.hword STRINGID_PKMNCOVEREDBYVEIL
	.globl gLeechSeedStringIds
gLeechSeedStringIds: @ 0x85AB9E4
	.hword STRINGID_PKMNSEEDED
	.hword STRINGID_PKMNEVADEDATTACK
	.hword STRINGID_ITDOESNTAFFECT
	.hword STRINGID_PKMNSAPPEDBYLEECHSEED
	.hword STRINGID_ITSUCKEDLIQUIDOOZE
	.globl gRestUsedStringIds
gRestUsedStringIds: @ 0x85AB9EE
	.hword STRINGID_PKMNWENTTOSLEEP
	.hword STRINGID_PKMNSLEPTHEALTHY
	.globl gUproarOverTurnStringIds
gUproarOverTurnStringIds: @ 0x85AB9F2
	.hword STRINGID_PKMNMAKINGUPROAR
	.hword STRINGID_PKMNCALMEDDOWN
	.globl gStockpileUsedStringIds
gStockpileUsedStringIds: @ 0x85AB9F6
	.hword STRINGID_PKMNSTOCKPILED
	.hword STRINGID_PKMNCANTSTOCKPILE
	.globl gWokeUpStringIds
gWokeUpStringIds: @ 0x85AB9FA
	.hword STRINGID_PKMNWOKEUP
	.hword STRINGID_PKMNWOKEUPINUPROAR
	.globl gSwallowFailStringIds
gSwallowFailStringIds: @ 0x85AB9FE
	.hword STRINGID_FAILEDTOSWALLOW
	.hword STRINGID_PKMNHPFULL
	.globl gUproarAwakeStringIds
gUproarAwakeStringIds: @ 0x85ABA02
	.hword STRINGID_PKMNCANTSLEEPINUPROAR2
	.hword STRINGID_UPROARKEPTPKMNAWAKE
	.hword STRINGID_PKMNSTAYEDAWAKEUSING
	.globl gStatUpStringIds
gStatUpStringIds: @ 0x85ABA08
	.hword STRINGID_ATTACKERSSTATROSE
	.hword STRINGID_DEFENDERSSTATROSE
	.hword STRINGID_STATSWONTINCREASE
	.hword STRINGID_EMPTYSTRING3
	.hword STRINGID_USINGITEMSTATOFPKMNROSE
	.hword STRINGID_PKMNUSEDXTOGETPUMPED
	.globl gStatDownStringIds
gStatDownStringIds: @ 0x85ABA14
	.hword STRINGID_ATTACKERSSTATFELL
	.hword STRINGID_DEFENDERSSTATFELL
	.hword STRINGID_STATSWONTDECREASE
	.hword STRINGID_EMPTYSTRING3
	.globl gFirstTurnOfTwoStringIds
gFirstTurnOfTwoStringIds: @ 0x85ABA1C
	.hword STRINGID_PKMNWHIPPEDWHIRLWIND
	.hword STRINGID_PKMNTOOKSUNLIGHT
	.hword STRINGID_PKMNLOWEREDHEAD
	.hword STRINGID_PKMNISGLOWING
	.hword STRINGID_PKMNFLEWHIGH
	.hword STRINGID_PKMNDUGHOLE
	.hword STRINGID_PKMNHIDUNDERWATER
	.hword STRINGID_PKMNSPRANGUP
	.globl gWrappedStringIds
gWrappedStringIds: @ 0x85ABA2C
	.hword STRINGID_PKMNSQUEEZEDBYBIND
	.hword STRINGID_PKMNWRAPPEDBY
	.hword STRINGID_PKMNTRAPPEDINVORTEX
	.hword STRINGID_PKMNCLAMPED
	.hword STRINGID_PKMNTRAPPEDINVORTEX
	.hword STRINGID_PKMNTRAPPEDBYSANDTOMB
	.globl gMistUsedStringIds
gMistUsedStringIds: @ 0x85ABA38
	.hword STRINGID_PKMNSHROUDEDINMIST
	.hword STRINGID_BUTITFAILED
	.globl gFocusEnergyUsedStringIds
gFocusEnergyUsedStringIds: @ 0x85ABA3C
	.hword STRINGID_PKMNGETTINGPUMPED
	.hword STRINGID_BUTITFAILED
	.globl gTransformUsedStringIds
gTransformUsedStringIds: @ 0x85ABA40
	.hword STRINGID_PKMNTRANSFORMEDINTO
	.hword STRINGID_BUTITFAILED
	.globl gSubstituteUsedStringIds
gSubstituteUsedStringIds: @ 0x85ABA44
	.hword STRINGID_PKMNMADESUBSTITUTE
	.hword STRINGID_TOOWEAKFORSUBSTITUTE
	.globl gGotPoisonedStringIds
gGotPoisonedStringIds: @ 0x85ABA48
	.hword STRINGID_PKMNWASPOISONED
	.hword STRINGID_PKMNPOISONEDBY
	.globl gGotParalyzedStringIds
gGotParalyzedStringIds: @ 0x85ABA4C
	.hword STRINGID_PKMNWASPARALYZED
	.hword STRINGID_PKMNWASPARALYZEDBY
	.globl gFellAsleepStringIds
gFellAsleepStringIds: @ 0x85ABA50
	.hword STRINGID_PKMNFELLASLEEP
	.hword STRINGID_PKMNMADESLEEP
	.globl gGotBurnedStringIds
gGotBurnedStringIds: @ 0x85ABA54
	.hword STRINGID_PKMNWASBURNED
	.hword STRINGID_PKMNBURNEDBY
	.globl gGotFrozenStringIds
gGotFrozenStringIds: @ 0x85ABA58
	.hword STRINGID_PKMNWASFROZEN
	.hword STRINGID_PKMNFROZENBY
	.globl gGotDefrostedStringIds
gGotDefrostedStringIds: @ 0x85ABA5C
	.hword STRINGID_PKMNWASDEFROSTED2
	.hword STRINGID_PKMNWASDEFROSTEDBY
	.globl gKOFailedStringIds
gKOFailedStringIds: @ 0x85ABA60
	.hword STRINGID_ATTACKMISSED
	.hword STRINGID_PKMNUNAFFECTED
	.globl gAttractUsedStringIds
gAttractUsedStringIds: @ 0x85ABA64
	.hword STRINGID_PKMNFELLINLOVE
	.hword STRINGID_PKMNSXINFATUATEDY
	.globl gAbsorbDrainStringIds
gAbsorbDrainStringIds: @ 0x85ABA68
	.hword STRINGID_PKMNENERGYDRAINED
	.hword STRINGID_ITSUCKEDLIQUIDOOZE
	.globl gSportsUsedStringIds
gSportsUsedStringIds: @ 0x85ABA6C
	.hword STRINGID_ELECTRICITYWEAKENED
	.hword STRINGID_FIREWEAKENED
	.globl gPartyStatusHealStringIds
gPartyStatusHealStringIds: @ 0x85ABA70
	.hword STRINGID_BELLCHIMED
	.hword STRINGID_BELLCHIMED
	.hword STRINGID_BELLCHIMED
	.hword STRINGID_BELLCHIMED
	.hword STRINGID_SOOTHINGAROMA
	.globl gFutureMoveUsedStringIds
gFutureMoveUsedStringIds: @ 0x85ABA7A
	.hword STRINGID_PKMNFORESAWATTACK
	.hword STRINGID_PKMNCHOSEXASDESTINY
	.globl gBallEscapeStringIds
gBallEscapeStringIds: @ 0x85ABA7E
	.hword STRINGID_PKMNBROKEFREE
	.hword STRINGID_ITAPPEAREDCAUGHT
	.hword STRINGID_AARGHALMOSTHADIT
	.hword STRINGID_SHOOTSOCLOSE
	.globl gWeatherStartsStringIds
gWeatherStartsStringIds: @ 0x85ABA86
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_SANDSTORMISRAGING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_SUNLIGHTSTRONG
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.hword STRINGID_ITISRAINING
	.globl gInobedientStringIds
gInobedientStringIds: @ 0x85ABAA6
	.hword STRINGID_PKMNLOAFING
	.hword STRINGID_PKMNWONTOBEY
	.hword STRINGID_PKMNTURNEDAWAY
	.hword STRINGID_PKMNPRETENDNOTNOTICE
	.hword STRINGID_PKMNINCAPABLEOFPOWER
	.globl gSafariGetNearStringIds
gSafariGetNearStringIds: @ 0x85ABAB0
	.hword STRINGID_CREPTCLOSER
	.hword STRINGID_CANTGETCLOSER
	.globl gSafariPokeblockResultStringIds
gSafariPokeblockResultStringIds: @ 0x85ABAB4
	.hword STRINGID_PKMNCURIOUSABOUTX
	.hword STRINGID_PKMNENTHRALLEDBYX
	.hword STRINGID_PKMNIGNOREDX
	.globl gTrainerItemCuredStatusStringIds
gTrainerItemCuredStatusStringIds: @ 0x85ABABA
	.hword STRINGID_PKMNSITEMSNAPPEDOUT
	.hword STRINGID_PKMNSITEMCUREDPARALYSIS
	.hword STRINGID_PKMNSITEMDEFROSTEDIT
	.hword STRINGID_PKMNSITEMHEALEDBURN
	.hword STRINGID_PKMNSITEMCUREDPOISON
	.hword STRINGID_PKMNSITEMWOKEIT
	.globl gBerryEffectStringIds
gBerryEffectStringIds: @ 0x85ABAC6
	.hword STRINGID_PKMNSITEMCUREDPROBLEM
	.hword STRINGID_PKMNSITEMNORMALIZEDSTATUS
	.globl gBRNPreventionStringIds
gBRNPreventionStringIds: @ 0x85ABACA
	.hword STRINGID_PKMNSXPREVENTSBURNS
	.hword STRINGID_PKMNSXPREVENTSYSZ
	.hword STRINGID_PKMNSXHADNOEFFECTONY
	.globl gPRLZPreventionStringIds
gPRLZPreventionStringIds: @ 0x85ABAD0
	.hword STRINGID_PKMNPREVENTSPARALYSISWITH
	.hword STRINGID_PKMNSXPREVENTSYSZ
	.hword STRINGID_PKMNSXHADNOEFFECTONY
	.globl gPSNPreventionStringIds
gPSNPreventionStringIds: @ 0x85ABAD6
	.hword STRINGID_PKMNPREVENTSPOISONINGWITH
	.hword STRINGID_PKMNSXPREVENTSYSZ
	.hword STRINGID_PKMNSXHADNOEFFECTONY
	.globl gItemSwapStringIds
gItemSwapStringIds: @ 0x85ABADC
	.hword STRINGID_PKMNOBTAINEDX
	.hword STRINGID_PKMNOBTAINEDX2
	.hword STRINGID_PKMNOBTAINEDXYOBTAINEDZ
	.globl gFlashFireStringIds
gFlashFireStringIds: @ 0x85ABAE2
	.hword STRINGID_PKMNRAISEDFIREPOWERWITH
	.hword STRINGID_PKMNSXMADEYINEFFECTIVE
	.globl gCaughtMonStringIds
gCaughtMonStringIds: @ 0x85ABAE6
	.hword STRINGID_PKMNTRANSFERREDSOMEONESPC
	.hword STRINGID_PKMNTRANSFERREDLANETTESPC
	.hword STRINGID_PKMNBOXSOMEONESPCFULL
	.hword STRINGID_PKMNBOXLANETTESPCFULL
	.globl gUnknown_85ABAEE
gUnknown_85ABAEE: @ 0x85ABAEE
	.string "と　も　ウ　ィ　\l"
	.string "　ぶあ$$"
