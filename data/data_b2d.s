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


gUnknown_82EC5FE: @ 0x82EC5FE
	.incbin "baserom_jp.gba", 0x2ec5fe, 0x2

	.globl sTurnActionsFuncsTable
sTurnActionsFuncsTable: @ 0x82EC600 @ 14 B_ACTION_* entries; [10]/[11] are JP-specific functions equivalent to US HandleAction_RunBattleScript/HandleAction_TryFinish
	.4byte HandleAction_UseMove @ B_ACTION_USE_MOVE
	.4byte HandleAction_UseItem @ B_ACTION_USE_ITEM
	.4byte HandleAction_Switch @ B_ACTION_SWITCH
	.4byte HandleAction_Run @ B_ACTION_RUN
	.4byte HandleAction_WatchesCarefully @ B_ACTION_SAFARI_WATCH_CAREFULLY
	.4byte HandleAction_SafariZoneBallThrow @ B_ACTION_SAFARI_BALL
	.4byte HandleAction_ThrowPokeblock @ B_ACTION_SAFARI_POKEBLOCK
	.4byte HandleAction_GoNear @ B_ACTION_SAFARI_GO_NEAR
	.4byte HandleAction_SafariZoneRun @ B_ACTION_SAFARI_RUN
	.4byte HandleAction_WallyBallThrow @ B_ACTION_WALLY_THROW
	.4byte sub_080454F4 @ B_ACTION_EXEC_SCRIPT
	.4byte sub_0803EEE4 @ B_ACTION_TRY_FINISH
	.4byte HandleAction_ActionFinished @ B_ACTION_FINISHED
	.4byte HandleAction_NothingIsFainted @ B_ACTION_NOTHING_FAINTED

	.globl sEndTurnFuncsTable
sEndTurnFuncsTable: @ 0x82EC638
	.4byte HandleEndTurn_ContinueBattle
	.4byte HandleEndTurn_BattleWon @ B_OUTCOME_WON
	.4byte HandleEndTurn_BattleLost @ B_OUTCOME_LOST
	.4byte HandleEndTurn_BattleLost @ B_OUTCOME_DREW
	.4byte HandleEndTurn_RanFromBattle @ B_OUTCOME_RAN
	.4byte HandleEndTurn_FinishBattle @ B_OUTCOME_PLAYER_TELEPORTED
	.4byte HandleEndTurn_MonFled @ B_OUTCOME_MON_FLED
	.4byte HandleEndTurn_FinishBattle @ B_OUTCOME_CAUGHT
	.4byte HandleEndTurn_FinishBattle @ B_OUTCOME_NO_SAFARI_BALLS
	.4byte HandleEndTurn_FinishBattle @ B_OUTCOME_FORFEITED
	.4byte HandleEndTurn_FinishBattle @ B_OUTCOME_MON_TELEPORTED

	.globl sPkblToEscapeFactor
sPkblToEscapeFactor: @ 0x82EC664
	.byte 0 @ pokeblock grade 0, B_MSG_MON_CURIOUS
	.byte 0 @ pokeblock grade 0, B_MSG_MON_ENTHRALLED
	.byte 0 @ pokeblock grade 0, B_MSG_MON_IGNORED
	.byte 3 @ pokeblock grade 1, B_MSG_MON_CURIOUS
	.byte 5 @ pokeblock grade 1, B_MSG_MON_ENTHRALLED
	.byte 0 @ pokeblock grade 1, B_MSG_MON_IGNORED
	.byte 2 @ pokeblock grade 2, B_MSG_MON_CURIOUS
	.byte 3 @ pokeblock grade 2, B_MSG_MON_ENTHRALLED
	.byte 0 @ pokeblock grade 2, B_MSG_MON_IGNORED
	.byte 1 @ pokeblock grade 3, B_MSG_MON_CURIOUS
	.byte 2 @ pokeblock grade 3, B_MSG_MON_ENTHRALLED
	.byte 0 @ pokeblock grade 3, B_MSG_MON_IGNORED
	.byte 1 @ pokeblock grade 4, B_MSG_MON_CURIOUS
	.byte 1 @ pokeblock grade 4, B_MSG_MON_ENTHRALLED
	.byte 0 @ pokeblock grade 4, B_MSG_MON_IGNORED

	.globl sGoNearCounterToCatchFactor
sGoNearCounterToCatchFactor: @ 0x82EC673
	.byte 4 @ safariGoNearCounter 0
	.byte 3 @ safariGoNearCounter 1
	.byte 2 @ safariGoNearCounter 2
	.byte 1 @ safariGoNearCounter 3

	.globl sGoNearCounterToEscapeFactor
sGoNearCounterToEscapeFactor: @ 0x82EC677
	.byte 4, 4, 4, 4 @ safariGoNearCounter 0..3
	.byte 0 @ JP trailing entry

	.globl sSoundMovesTable
sSoundMovesTable: @ 0x82EC67C
	.hword MOVE_GROWL
	.hword MOVE_ROAR
	.hword MOVE_SING
	.hword MOVE_SUPERSONIC
	.hword MOVE_SCREECH
	.hword MOVE_SNORE
	.hword MOVE_UPROAR
	.hword MOVE_METAL_SOUND
	.hword MOVE_GRASS_WHISTLE
	.hword MOVE_HYPER_VOICE
	.hword 0xFFFF @ SOUND_MOVES_END
	.hword 0 @ JP trailing entry

	.globl gBattleScriptingCommandsTable
gBattleScriptingCommandsTable: @ 0x82EC694
	.4byte Cmd_attackcanceler @ B_SCR_OP_ATTACKCANCELER
	.4byte Cmd_accuracycheck @ B_SCR_OP_ACCURACYCHECK
	.4byte Cmd_attackstring @ B_SCR_OP_ATTACKSTRING
	.4byte Cmd_ppreduce @ B_SCR_OP_PPREDUCE
	.4byte Cmd_critcalc @ B_SCR_OP_CRITCALC
	.4byte Cmd_damagecalc @ B_SCR_OP_DAMAGECALC
	.4byte Cmd_typecalc @ B_SCR_OP_TYPECALC
	.4byte Cmd_adjustnormaldamage @ B_SCR_OP_ADJUSTNORMALDAMAGE
	.4byte Cmd_adjustnormaldamage2 @ B_SCR_OP_ADJUSTNORMALDAMAGE2
	.4byte Cmd_attackanimation @ B_SCR_OP_ATTACKANIMATION
	.4byte Cmd_waitanimation @ B_SCR_OP_WAITANIMATION
	.4byte Cmd_healthbarupdate @ B_SCR_OP_HEALTHBARUPDATE
	.4byte Cmd_datahpupdate @ B_SCR_OP_DATAHPUPDATE
	.4byte Cmd_critmessage @ B_SCR_OP_CRITMESSAGE
	.4byte Cmd_effectivenesssound @ B_SCR_OP_EFFECTIVENESSSOUND
	.4byte Cmd_resultmessage @ B_SCR_OP_RESULTMESSAGE
	.4byte Cmd_printstring @ B_SCR_OP_PRINTSTRING
	.4byte Cmd_printselectionstring @ B_SCR_OP_PRINTSELECTIONSTRING
	.4byte Cmd_waitmessage @ B_SCR_OP_WAITMESSAGE
	.4byte Cmd_printfromtable @ B_SCR_OP_PRINTFROMTABLE
	.4byte Cmd_printselectionstringfromtable @ B_SCR_OP_PRINTSELECTIONSTRINGFROMTABLE
	.4byte Cmd_seteffectwithchance @ B_SCR_OP_SETEFFECTWITHCHANCE
	.4byte Cmd_seteffectprimary @ B_SCR_OP_SETEFFECTPRIMARY
	.4byte Cmd_seteffectsecondary @ B_SCR_OP_SETEFFECTSECONDARY
	.4byte Cmd_clearstatusfromeffect @ B_SCR_OP_CLEARSTATUSFROMEFFECT
	.4byte Cmd_tryfaintmon @ B_SCR_OP_TRYFAINTMON
	.4byte Cmd_dofaintanimation @ B_SCR_OP_DOFAINTANIMATION
	.4byte Cmd_cleareffectsonfaint @ B_SCR_OP_CLEAREFFECTSONFAINT
	.4byte Cmd_jumpifstatus @ B_SCR_OP_JUMPIFSTATUS
	.4byte Cmd_jumpifstatus2 @ B_SCR_OP_JUMPIFSTATUS2
	.4byte Cmd_jumpifability @ B_SCR_OP_JUMPIFABILITY
	.4byte Cmd_jumpifsideaffecting @ B_SCR_OP_JUMPIFSIDEAFFECTING
	.4byte Cmd_jumpifstat @ B_SCR_OP_JUMPIFSTAT
	.4byte Cmd_jumpifstatus3condition @ B_SCR_OP_JUMPIFSTATUS3CONDITION
	.4byte Cmd_jumpiftype @ B_SCR_OP_JUMPIFTYPE
	.4byte Cmd_getexp @ B_SCR_OP_GETEXP
	.4byte Cmd_checkteamslost @ B_SCR_OP_CHECKTEAMSLOST
	.4byte Cmd_movevaluescleanup @ B_SCR_OP_MOVEVALUESCLEANUP
	.4byte Cmd_setmultihit @ B_SCR_OP_SETMULTIHIT
	.4byte Cmd_decrementmultihit @ B_SCR_OP_DECREMENTMULTIHIT
	.4byte Cmd_goto @ B_SCR_OP_GOTO
	.4byte Cmd_jumpifbyte @ B_SCR_OP_JUMPIFBYTE
	.4byte Cmd_jumpifhalfword @ B_SCR_OP_JUMPIFHALFWORD
	.4byte Cmd_jumpifword @ B_SCR_OP_JUMPIFWORD
	.4byte Cmd_jumpifarrayequal @ B_SCR_OP_JUMPIFARRAYEQUAL
	.4byte Cmd_jumpifarraynotequal @ B_SCR_OP_JUMPIFARRAYNOTEQUAL
	.4byte Cmd_setbyte @ B_SCR_OP_SETBYTE
	.4byte Cmd_addbyte @ B_SCR_OP_ADDBYTE
	.4byte Cmd_subbyte @ B_SCR_OP_SUBBYTE
	.4byte Cmd_copyarray @ B_SCR_OP_COPYARRAY
	.4byte Cmd_copyarraywithindex @ B_SCR_OP_COPYARRAYWITHINDEX
	.4byte Cmd_orbyte @ B_SCR_OP_ORBYTE
	.4byte Cmd_orhalfword @ B_SCR_OP_ORHALFWORD
	.4byte Cmd_orword @ B_SCR_OP_ORWORD
	.4byte Cmd_bicbyte @ B_SCR_OP_BICBYTE
	.4byte Cmd_bichalfword @ B_SCR_OP_BICHALFWORD
	.4byte Cmd_bicword @ B_SCR_OP_BICWORD
	.4byte Cmd_pause @ B_SCR_OP_PAUSE
	.4byte Cmd_waitstate @ B_SCR_OP_WAITSTATE
	.4byte Cmd_healthbar_update @ B_SCR_OP_HEALTHBAR_UPDATE
	.4byte Cmd_return @ B_SCR_OP_RETURN
	.4byte Cmd_end @ B_SCR_OP_END
	.4byte Cmd_end2 @ B_SCR_OP_END2
	.4byte Cmd_end3 @ B_SCR_OP_END3
	.4byte Cmd_jumpifaffectedbyprotect @ B_SCR_OP_JUMPIFAFFECTEDBYPROTECT
	.4byte Cmd_call @ B_SCR_OP_CALL
	.4byte Cmd_jumpiftype2 @ B_SCR_OP_JUMPIFTYPE2
	.4byte Cmd_jumpifabilitypresent @ B_SCR_OP_JUMPIFABILITYPRESENT
	.4byte Cmd_endselectionscript @ B_SCR_OP_ENDSELECTIONSCRIPT
	.4byte Cmd_playanimation @ B_SCR_OP_PLAYANIMATION
	.4byte Cmd_playanimation_var @ B_SCR_OP_PLAYANIMATION_VAR
	.4byte Cmd_setgraphicalstatchangevalues @ B_SCR_OP_SETGRAPHICALSTATCHANGEVALUES
	.4byte Cmd_playstatchangeanimation @ B_SCR_OP_PLAYSTATCHANGEANIMATION
	.4byte Cmd_moveend @ B_SCR_OP_MOVEEND
	.4byte Cmd_typecalc2 @ B_SCR_OP_TYPECALC2
	.4byte Cmd_returnatktoball @ B_SCR_OP_RETURNATKTOBALL
	.4byte Cmd_getswitchedmondata @ B_SCR_OP_GETSWITCHEDMONDATA
	.4byte Cmd_switchindataupdate @ B_SCR_OP_SWITCHINDATAUPDATE
	.4byte Cmd_switchinanim @ B_SCR_OP_SWITCHINANIM
	.4byte Cmd_jumpifcantswitch @ B_SCR_OP_JUMPIFCANTSWITCH
	.4byte Cmd_openpartyscreen @ B_SCR_OP_OPENPARTYSCREEN
	.4byte Cmd_switchhandleorder @ B_SCR_OP_SWITCHHANDLEORDER
	.4byte Cmd_switchineffects @ B_SCR_OP_SWITCHINEFFECTS
	.4byte Cmd_trainerslidein @ B_SCR_OP_TRAINERSLIDEIN
	.4byte Cmd_playse @ B_SCR_OP_PLAYSE
	.4byte Cmd_fanfare @ B_SCR_OP_FANFARE
	.4byte Cmd_playfaintcry @ B_SCR_OP_PLAYFAINTCRY
	.4byte Cmd_endlinkbattle @ B_SCR_OP_ENDLINKBATTLE
	.4byte Cmd_returntoball @ B_SCR_OP_RETURNTOBALL
	.4byte Cmd_handlelearnnewmove @ B_SCR_OP_HANDLELEARNNEWMOVE
	.4byte Cmd_yesnoboxlearnmove @ B_SCR_OP_YESNOBOXLEARNMOVE
	.4byte Cmd_yesnoboxstoplearningmove @ B_SCR_OP_YESNOBOXSTOPLEARNINGMOVE
	.4byte Cmd_hitanimation @ B_SCR_OP_HITANIMATION
	.4byte Cmd_getmoneyreward @ B_SCR_OP_GETMONEYREWARD
	.4byte Cmd_updatebattlermoves @ B_SCR_OP_UPDATEBATTLERMOVES
	.4byte Cmd_swapattackerwithtarget @ B_SCR_OP_SWAPATTACKERWITHTARGET
	.4byte Cmd_incrementgamestat @ B_SCR_OP_INCREMENTGAMESTAT
	.4byte Cmd_drawpartystatussummary @ B_SCR_OP_DRAWPARTYSTATUSSUMMARY
	.4byte Cmd_hidepartystatussummary @ B_SCR_OP_HIDEPARTYSTATUSSUMMARY
	.4byte Cmd_jumptocalledmove @ B_SCR_OP_JUMPTOCALLEDMOVE
	.4byte Cmd_statusanimation @ B_SCR_OP_STATUSANIMATION
	.4byte Cmd_status2animation @ B_SCR_OP_STATUS2ANIMATION
	.4byte Cmd_chosenstatusanimation @ B_SCR_OP_CHOSENSTATUSANIMATION
	.4byte Cmd_yesnobox @ B_SCR_OP_YESNOBOX
	.4byte Cmd_cancelallactions @ B_SCR_OP_CANCELALLACTIONS
	.4byte Cmd_adjustsetdamage @ B_SCR_OP_ADJUSTSETDAMAGE
	.4byte Cmd_removeitem @ B_SCR_OP_REMOVEITEM
	.4byte Cmd_atknameinbuff1 @ B_SCR_OP_ATKNAMEINBUFF1
	.4byte Cmd_drawlvlupbox @ B_SCR_OP_DRAWLVLUPBOX
	.4byte Cmd_resetsentmonsvalue @ B_SCR_OP_RESETSENTMONSVALUE
	.4byte Cmd_setatktoplayer0 @ B_SCR_OP_SETATKTOPLAYER0
	.4byte Cmd_makevisible @ B_SCR_OP_MAKEVISIBLE
	.4byte Cmd_recordlastability @ B_SCR_OP_RECORDLASTABILITY
	.4byte Cmd_buffermovetolearn @ B_SCR_OP_BUFFERMOVETOLEARN
	.4byte Cmd_jumpifplayerran @ B_SCR_OP_JUMPIFPLAYERRAN
	.4byte Cmd_hpthresholds @ B_SCR_OP_HPTHRESHOLDS
	.4byte Cmd_hpthresholds2 @ B_SCR_OP_HPTHRESHOLDS2
	.4byte Cmd_useitemonopponent @ B_SCR_OP_USEITEMONOPPONENT
	.4byte Cmd_various @ B_SCR_OP_VARIOUS
	.4byte Cmd_setprotectlike @ B_SCR_OP_SETPROTECTLIKE
	.4byte Cmd_tryexplosion @ B_SCR_OP_TRYEXPLOSION
	.4byte Cmd_setatkhptozero @ B_SCR_OP_SETATKHPTOZERO
	.4byte Cmd_jumpifnexttargetvalid @ B_SCR_OP_JUMPIFNEXTTARGETVALID
	.4byte Cmd_tryhealhalfhealth @ B_SCR_OP_TRYHEALHALFHEALTH
	.4byte atk7C_trymirrormove @ B_SCR_OP_TRYMIRRORMOVE
	.4byte Cmd_setrain @ B_SCR_OP_SETRAIN
	.4byte Cmd_setreflect @ B_SCR_OP_SETREFLECT
	.4byte Cmd_setseeded @ B_SCR_OP_SETSEEDED
	.4byte Cmd_manipulatedamage @ B_SCR_OP_MANIPULATEDAMAGE
	.4byte Cmd_trysetrest @ B_SCR_OP_TRYSETREST
	.4byte Cmd_jumpifnotfirstturn @ B_SCR_OP_JUMPIFNOTFIRSTTURN
	.4byte Cmd_nop @ B_SCR_OP_NOP
	.4byte Cmd_jumpifcantmakeasleep @ B_SCR_OP_JUMPIFCANTMAKEASLEEP
	.4byte Cmd_stockpile @ B_SCR_OP_STOCKPILE
	.4byte Cmd_stockpiletobasedamage @ B_SCR_OP_STOCKPILETOBASEDAMAGE
	.4byte Cmd_stockpiletohpheal @ B_SCR_OP_STOCKPILETOHPHEAL
	.4byte Cmd_negativedamage @ B_SCR_OP_NEGATIVEDAMAGE
	.4byte Cmd_statbuffchange @ B_SCR_OP_STATBUFFCHANGE
	.4byte Cmd_normalisebuffs @ B_SCR_OP_NORMALISEBUFFS
	.4byte Cmd_setbide @ B_SCR_OP_SETBIDE
	.4byte Cmd_confuseifrepeatingattackends @ B_SCR_OP_CONFUSEIFREPEATINGATTACKENDS
	.4byte Cmd_setmultihitcounter @ B_SCR_OP_SETMULTIHITCOUNTER
	.4byte Cmd_initmultihitstring @ B_SCR_OP_INITMULTIHITSTRING
	.4byte Cmd_forcerandomswitch @ B_SCR_OP_FORCERANDOMSWITCH
	.4byte Cmd_tryconversiontypechange @ B_SCR_OP_TRYCONVERSIONTYPECHANGE
	.4byte Cmd_givepaydaymoney @ B_SCR_OP_GIVEPAYDAYMONEY
	.4byte Cmd_setlightscreen @ B_SCR_OP_SETLIGHTSCREEN
	.4byte Cmd_tryKO @ B_SCR_OP_TRYKO
	.4byte Cmd_damagetohalftargethp @ B_SCR_OP_DAMAGETOHALFTARGETHP
	.4byte Cmd_setsandstorm @ B_SCR_OP_SETSANDSTORM
	.4byte Cmd_weatherdamage @ B_SCR_OP_WEATHERDAMAGE
	.4byte Cmd_tryinfatuating @ B_SCR_OP_TRYINFATUATING
	.4byte Cmd_updatestatusicon @ B_SCR_OP_UPDATESTATUSICON
	.4byte Cmd_setmist @ B_SCR_OP_SETMIST
	.4byte Cmd_setfocusenergy @ B_SCR_OP_SETFOCUSENERGY
	.4byte Cmd_transformdataexecution @ B_SCR_OP_TRANSFORMDATAEXECUTION
	.4byte Cmd_setsubstitute @ B_SCR_OP_SETSUBSTITUTE
	.4byte Cmd_mimicattackcopy @ B_SCR_OP_MIMICATTACKCOPY
	.4byte Cmd_metronome @ B_SCR_OP_METRONOME
	.4byte Cmd_dmgtolevel @ B_SCR_OP_DMGTOLEVEL
	.4byte Cmd_psywavedamageeffect @ B_SCR_OP_PSYWAVEDAMAGEEFFECT
	.4byte Cmd_counterdamagecalculator @ B_SCR_OP_COUNTERDAMAGECALCULATOR
	.4byte Cmd_mirrorcoatdamagecalculator @ B_SCR_OP_MIRRORCOATDAMAGECALCULATOR
	.4byte Cmd_disablelastusedattack @ B_SCR_OP_DISABLELASTUSEDATTACK
	.4byte Cmd_trysetencore @ B_SCR_OP_TRYSETENCORE
	.4byte Cmd_painsplitdmgcalc @ B_SCR_OP_PAINSPLITDMGCALC
	.4byte Cmd_settypetorandomresistance @ B_SCR_OP_SETTYPETORANDOMRESISTANCE
	.4byte Cmd_setalwayshitflag @ B_SCR_OP_SETALWAYSHITFLAG
	.4byte Cmd_copymovepermanently @ B_SCR_OP_COPYMOVEPERMANENTLY
	.4byte Cmd_trychoosesleeptalkmove @ B_SCR_OP_TRYCHOOSESLEEPTALKMOVE
	.4byte Cmd_setdestinybond @ B_SCR_OP_SETDESTINYBOND
	.4byte Cmd_trysetdestinybondtohappen @ B_SCR_OP_TRYSETDESTINYBONDTOHAPPEN
	.4byte Cmd_remaininghptopower @ B_SCR_OP_REMAININGHPTOPOWER
	.4byte Cmd_tryspiteppreduce @ B_SCR_OP_TRYSPITEPPREDUCE
	.4byte Cmd_healpartystatus @ B_SCR_OP_HEALPARTYSTATUS
	.4byte Cmd_cursetarget @ B_SCR_OP_CURSETARGET
	.4byte Cmd_trysetspikes @ B_SCR_OP_TRYSETSPIKES
	.4byte Cmd_setforesight @ B_SCR_OP_SETFORESIGHT
	.4byte Cmd_trysetperishsong @ B_SCR_OP_TRYSETPERISHSONG
	.4byte Cmd_rolloutdamagecalculation @ B_SCR_OP_ROLLOUTDAMAGECALCULATION
	.4byte Cmd_jumpifconfusedandstatmaxed @ B_SCR_OP_JUMPIFCONFUSEDANDSTATMAXED
	.4byte Cmd_furycuttercalc @ B_SCR_OP_FURYCUTTERCALC
	.4byte Cmd_friendshiptodamagecalculation @ B_SCR_OP_FRIENDSHIPTODAMAGECALCULATION
	.4byte Cmd_presentdamagecalculation @ B_SCR_OP_PRESENTDAMAGECALCULATION
	.4byte Cmd_setsafeguard @ B_SCR_OP_SETSAFEGUARD
	.4byte Cmd_magnitudedamagecalculation @ B_SCR_OP_MAGNITUDEDAMAGECALCULATION
	.4byte Cmd_jumpifnopursuitswitchdmg @ B_SCR_OP_JUMPIFNOPURSUITSWITCHDMG
	.4byte Cmd_setsunny @ B_SCR_OP_SETSUNNY
	.4byte Cmd_maxattackhalvehp @ B_SCR_OP_MAXATTACKHALVEHP
	.4byte Cmd_copyfoestats @ B_SCR_OP_COPYFOESTATS
	.4byte Cmd_rapidspinfree @ B_SCR_OP_RAPIDSPINFREE
	.4byte Cmd_setdefensecurlbit @ B_SCR_OP_SETDEFENSECURLBIT
	.4byte Cmd_recoverbasedonsunlight @ B_SCR_OP_RECOVERBASEDONSUNLIGHT
	.4byte Cmd_hiddenpowercalc @ B_SCR_OP_HIDDENPOWERCALC
	.4byte Cmd_selectfirstvalidtarget @ B_SCR_OP_SELECTFIRSTVALIDTARGET
	.4byte Cmd_trysetfutureattack @ B_SCR_OP_TRYSETFUTUREATTACK
	.4byte Cmd_trydobeatup @ B_SCR_OP_TRYDOBEATUP
	.4byte Cmd_setsemiinvulnerablebit @ B_SCR_OP_SETSEMIINVULNERABLEBIT
	.4byte Cmd_clearsemiinvulnerablebit @ B_SCR_OP_CLEARSEMIINVULNERABLEBIT
	.4byte Cmd_setminimize @ B_SCR_OP_SETMINIMIZE
	.4byte Cmd_sethail @ B_SCR_OP_SETHAIL
	.4byte Cmd_jumpifattackandspecialattackcannotfall @ B_SCR_OP_TRYMEMENTO
	.4byte Cmd_setforcedtarget @ B_SCR_OP_SETFORCEDTARGET
	.4byte Cmd_setcharge @ B_SCR_OP_SETCHARGE
	.4byte Cmd_callenvironmentattack @ B_SCR_OP_CALLENVIRONMENTATTACK
	.4byte Cmd_cureifburnedparalyzedorpoisoned @ B_SCR_OP_CUREIFBURNEDPARALYZEDORPOISONED
	.4byte Cmd_settorment @ B_SCR_OP_SETTORMENT
	.4byte Cmd_jumpifnodamage @ B_SCR_OP_JUMPIFNODAMAGE
	.4byte Cmd_settaunt @ B_SCR_OP_SETTAUNT
	.4byte Cmd_trysethelpinghand @ B_SCR_OP_TRYSETHELPINGHAND
	.4byte Cmd_tryswapitems @ B_SCR_OP_TRYSWAPITEMS
	.4byte Cmd_trycopyability @ B_SCR_OP_TRYCOPYABILITY
	.4byte Cmd_trywish @ B_SCR_OP_TRYWISH
	.4byte Cmd_trysetroots @ B_SCR_OP_TRYSETROOTS
	.4byte Cmd_doubledamagedealtifdamaged @ B_SCR_OP_DOUBLEDAMAGEDEALTIFDAMAGED
	.4byte Cmd_setyawn @ B_SCR_OP_SETYAWN
	.4byte Cmd_setdamagetohealthdifference @ B_SCR_OP_SETDAMAGETOHEALTHDIFFERENCE
	.4byte Cmd_scaledamagebyhealthratio @ B_SCR_OP_SCALEDAMAGEBYHEALTHRATIO
	.4byte Cmd_tryswapabilities @ B_SCR_OP_TRYSWAPABILITIES
	.4byte Cmd_tryimprison @ B_SCR_OP_TRYIMPRISON
	.4byte Cmd_trysetgrudge @ B_SCR_OP_TRYSETGRUDGE
	.4byte Cmd_weightdamagecalculation @ B_SCR_OP_WEIGHTDAMAGECALCULATION
	.4byte Cmd_assistattackselect @ B_SCR_OP_ASSISTATTACKSELECT
	.4byte Cmd_trysetmagiccoat @ B_SCR_OP_TRYSETMAGICCOAT
	.4byte Cmd_trysetsnatch @ B_SCR_OP_TRYSETSNATCH
	.4byte Cmd_trygetintimidatetarget @ B_SCR_OP_TRYGETINTIMIDATETARGET
	.4byte Cmd_switchoutabilities @ B_SCR_OP_SWITCHOUTABILITIES
	.4byte Cmd_jumpifhasnohp @ B_SCR_OP_JUMPIFHASNOHP
	.4byte Cmd_getsecretpowereffect @ B_SCR_OP_GETSECRETPOWEREFFECT
	.4byte Cmd_pickup @ B_SCR_OP_PICKUP
	.4byte Cmd_docastformchangeanimation @ B_SCR_OP_DOCASTFORMCHANGEANIMATION
	.4byte Cmd_trycastformdatachange @ B_SCR_OP_TRYCASTFORMDATACHANGE
	.4byte Cmd_settypebasedhalvers @ B_SCR_OP_SETTYPEBASEDHALVERS
	.4byte Cmd_setweatherballtype @ B_SCR_OP_SETWEATHERBALLTYPE
	.4byte Cmd_tryrecycleitem @ B_SCR_OP_TRYRECYCLEITEM
	.4byte Cmd_settypetoenvironment @ B_SCR_OP_SETTYPETOENVIRONMENT
	.4byte Cmd_pursuitdoubles @ B_SCR_OP_PURSUITDOUBLES
	.4byte Cmd_snatchsetbattlers @ B_SCR_OP_SNATCHSETBATTLERS
	.4byte Cmd_removelightscreenreflect @ B_SCR_OP_REMOVELIGHTSCREENREFLECT
	.4byte Cmd_handleballthrow @ B_SCR_OP_HANDLEBALLTHROW
	.4byte Cmd_givecaughtmon @ B_SCR_OP_GIVECAUGHTMON
	.4byte Cmd_trysetcaughtmondexflags @ B_SCR_OP_TRYSETCAUGHTMONDEXFLAGS
	.4byte Cmd_displaydexinfo @ B_SCR_OP_DISPLAYDEXINFO
	.4byte Cmd_trygivecaughtmonnick @ B_SCR_OP_TRYGIVECAUGHTMONNICK
	.4byte Cmd_subattackerhpbydmg @ B_SCR_OP_SUBATTACKERHPBYDMG
	.4byte Cmd_removeattackerstatus1 @ B_SCR_OP_REMOVEATTACKERSTATUS1
	.4byte Cmd_finishaction @ B_SCR_OP_FINISHACTION
	.4byte Cmd_finishturn @ B_SCR_OP_FINISHTURN
	.4byte Cmd_trainerslideout @ B_SCR_OP_TRAINERSLIDEOUT

	.globl sAccuracyStageRatios
sAccuracyStageRatios: @ 0x82ECA78
	.byte 33 @ stage -6 dividend
	.byte 100 @ stage -6 divisor
	.hword 0
	.byte 36 @ stage -5 dividend
	.byte 100 @ stage -5 divisor
	.hword 0
	.byte 43 @ stage -4 dividend
	.byte 100 @ stage -4 divisor
	.hword 0
	.byte 50 @ stage -3 dividend
	.byte 100 @ stage -3 divisor
	.hword 0
	.byte 60 @ stage -2 dividend
	.byte 100 @ stage -2 divisor
	.hword 0
	.byte 75 @ stage -1 dividend
	.byte 100 @ stage -1 divisor
	.hword 0
	.byte 1 @ stage 0 dividend
	.byte 1 @ stage 0 divisor
	.hword 0
	.byte 133 @ stage +1 dividend
	.byte 100 @ stage +1 divisor
	.hword 0
	.byte 166 @ stage +2 dividend
	.byte 100 @ stage +2 divisor
	.hword 0
	.byte 2 @ stage +3 dividend
	.byte 1 @ stage +3 divisor
	.hword 0
	.byte 233 @ stage +4 dividend
	.byte 100 @ stage +4 divisor
	.hword 0
	.byte 133 @ stage +5 dividend
	.byte 50 @ stage +5 divisor
	.hword 0
	.byte 3 @ stage +6 dividend
	.byte 1 @ stage +6 divisor
	.hword 0

	.globl sCriticalHitChance
sCriticalHitChance: @ 0x82ECAAC
	.hword 16 @ 1/16 chance, stage 0
	.hword 8 @ 1/8 chance, stage 1
	.hword 4 @ 1/4 chance, stage 2
	.hword 3 @ 1/3 chance, stage 3
	.hword 2 @ 1/2 chance, stage 4
	.hword 0 @ JP trailing entry

	.globl sStatusFlagsForMoveEffects
sStatusFlagsForMoveEffects: @ 0x82ECAB8
	.4byte 0x00000000
	.4byte 0x00000007  @ STATUS1_SLEEP
	.4byte 0x00000008  @ STATUS1_POISON
	.4byte 0x00000010  @ STATUS1_BURN
	.4byte 0x00000020  @ STATUS1_FREEZE
	.4byte 0x00000040  @ STATUS1_PARALYSIS
	.4byte 0x00000080  @ STATUS1_TOXIC_POISON
	.4byte 0x00000007  @ STATUS1_SLEEP
	.4byte 0x00000008  @ STATUS1_POISON
	.4byte 0x00000000
	.4byte 0x00000070  @ STATUS1_PSN_ANY
	.4byte 0x00000000
	.4byte 0x00001000
	.4byte 0x0000E000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00400000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x04000000
	.4byte 0x08000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000C00
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000
	.4byte 0x00000000

	.globl sMoveEffectBS_Ptrs
sMoveEffectBS_Ptrs: @ 0x82ECBA8
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectPoison  @ BattleScript_MoveEffectPoison
	.4byte BattleScript_MoveEffectBurn  @ BattleScript_MoveEffectBurn
	.4byte BattleScript_MoveEffectFreeze  @ BattleScript_MoveEffectFreeze
	.4byte BattleScript_MoveEffectParalysis  @ BattleScript_MoveEffectParalysis
	.4byte BattleScript_MoveEffectToxic  @ BattleScript_MoveEffectToxic
	.4byte BattleScript_MoveEffectConfusion  @ BattleScript_MoveEffectConfusion
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectUproar  @ BattleScript_MoveEffectUproar
	.4byte BattleScript_MoveEffectPayDay  @ BattleScript_MoveEffectPayDay
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectWrap  @ BattleScript_MoveEffectWrap
	.4byte BattleScript_MoveEffectRecoil  @ BattleScript_MoveEffectRecoil
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectSleep  @ BattleScript_MoveEffectSleep
	.4byte BattleScript_MoveEffectRecoil  @ BattleScript_MoveEffectRecoil
	.4byte 0x07030100
	.4byte 0x003F1F0F

	.globl gUnknown_82ECC4C
gUnknown_82ECC4C: @ 0x82ECC4C
	.hword 0x7FFF, 0x7FFF, 0x396D, 0x0000, 0x7F9A, 0x7737, 0x7FBD, 0x62AD, 0x5A2B, 0x670F, 0x0000, 0x0000
	.hword 0x7F0F, 0x4400, 0x421F, 0x0014

	.globl gUnknown_82ECC6C
gUnknown_82ECC6C: @ 0x82ECC6C
	.byte 0x10, 0x80, 0x04, 0x00, 0x00, 0x30, 0x33, 0x33, 0x33, 0x33, 0x99, 0x99
	.byte 0x99, 0x03, 0x93, 0x79, 0x77, 0x77, 0x93, 0x77, 0xF0, 0x03, 0x40, 0x1E
	.byte 0x7F, 0x99, 0x00, 0x0A, 0xF0, 0x01, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F
	.byte 0xF0, 0x1F, 0xF0, 0x1F, 0xFF, 0xF0, 0x1F, 0xF0, 0x1A, 0xF0, 0x1F, 0xF0
	.byte 0x01, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF5, 0xF0, 0x1F
	.byte 0xF0, 0x1F, 0xF0, 0x01, 0x30, 0x1F, 0x03, 0x00, 0x1E, 0x33, 0x00, 0x0A
	.byte 0x48, 0x38, 0xF0, 0x03, 0x77, 0x38, 0xD1, 0x6F, 0x63, 0x44, 0x44, 0x7F
	.byte 0x44, 0x90, 0x03, 0xD0, 0x4F, 0x00, 0x12, 0xA0, 0x01, 0xF0, 0x1F, 0xF0
	.byte 0x1F, 0xF0, 0x1F, 0xFF, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F
	.byte 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xFE, 0xF0, 0x1F, 0xF0
	.byte 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xD1, 0x6F, 0x00, 0x12, 0x35
	.byte 0xE1, 0x90, 0x03, 0xD1, 0x6F, 0x50, 0x03, 0x33, 0x55, 0x55, 0x55, 0x13
	.byte 0x1B, 0xEF, 0xD0, 0x4F, 0x50, 0x01, 0x00, 0x1E, 0x55, 0x11, 0xFB, 0xF0
	.byte 0x19, 0xF0, 0x1F, 0xF0, 0x01, 0xFF, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F
	.byte 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x01, 0xF0, 0x1F, 0xFE, 0xF0
	.byte 0x01, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xF0, 0x1F, 0xD1, 0x6F, 0x30
	.byte 0x03, 0x54, 0x40, 0x35, 0x40, 0x1E, 0x03, 0x00, 0x3A, 0x3E, 0x3B, 0x3F
	.byte 0x3C, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00

	.globl gUnknown_82ECD44
gUnknown_82ECD44: @ 0x82ECD44
	.incbin "baserom_jp.gba", 0x2ecd44, 0x18

	.globl sProtectSuccessRates
sProtectSuccessRates: @ 0x82ECD5C
	.hword 0xFFFF @ protect use 0
	.hword 0x7FFF @ protect use 1
	.hword 0x3FFF @ protect use 2
	.hword 0x1FFF @ protect use 3

	.globl sMovesForbiddenToCopy
sMovesForbiddenToCopy: @ 0x82ECD64
	.hword MOVE_METRONOME @ 0x0076
	.hword MOVE_STRUGGLE @ 0x00A5
	.hword MOVE_SKETCH @ 0x00A6
	.hword MOVE_MIMIC @ 0x0066
	.hword 0xFFFE @ MIMIC_FORBIDDEN_END
	.hword MOVE_COUNTER @ 0x0044
	.hword MOVE_MIRROR_COAT @ 0x00F3
	.hword MOVE_PROTECT @ 0x00B6
	.hword MOVE_DETECT @ 0x00C5
	.hword MOVE_ENDURE @ 0x00CB
	.hword MOVE_DESTINY_BOND @ 0x00C2
	.hword MOVE_SLEEP_TALK @ 0x00D6
	.hword MOVE_THIEF @ 0x00A8
	.hword MOVE_FOLLOW_ME @ 0x010A
	.hword MOVE_SNATCH @ 0x0121
	.hword MOVE_HELPING_HAND @ 0x010E
	.hword MOVE_COVET @ 0x0157
	.hword MOVE_TRICK @ 0x010F
	.hword MOVE_FOCUS_PUNCH @ 0x0108
	.hword 0xFFFF @ METRONOME_FORBIDDEN_END
	.globl sFlailHpScaleToPowerTable
sFlailHpScaleToPowerTable: @ 0x82ECD8C
	.byte 1, 200 @ hp<= 1% -> power 200
	.byte 4, 150 @ hp<= 4% -> power 150
	.byte 9, 100 @ hp<= 9% -> power 100
	.byte 16, 80 @ hp<= 16% -> power 80
	.byte 32, 40 @ hp<= 32% -> power 40
	.byte 48, 20 @ hp<= 48% -> power 20

	.globl sNaturePowerMoves
sNaturePowerMoves: @ 0x82ECD98
	.hword MOVE_STUN_SPORE @ BATTLE_ENVIRONMENT_GRASS
	.hword MOVE_RAZOR_LEAF @ BATTLE_ENVIRONMENT_LONG_GRASS
	.hword MOVE_EARTHQUAKE @ BATTLE_ENVIRONMENT_SAND
	.hword MOVE_HYDRO_PUMP @ BATTLE_ENVIRONMENT_UNDERWATER
	.hword MOVE_SURF @ BATTLE_ENVIRONMENT_WATER
	.hword MOVE_BUBBLE_BEAM @ BATTLE_ENVIRONMENT_POND
	.hword MOVE_ROCK_SLIDE @ BATTLE_ENVIRONMENT_MOUNTAIN
	.hword MOVE_SHADOW_BALL @ BATTLE_ENVIRONMENT_CAVE
	.hword MOVE_SWIFT @ BATTLE_ENVIRONMENT_BUILDING
	.hword MOVE_SWIFT @ BATTLE_ENVIRONMENT_PLAIN

	.globl gUnknown_82ECDAC
gUnknown_82ECDAC: @ 0x82ECDAC
	.string "ト　と　\l"
	.string "　り　äあざ　tうっ　Vきト　$$$$"
	.globl gUnknown_82ECDC4
gUnknown_82ECDC4: @ 0x82ECDC4
	.incbin "baserom_jp.gba", 0x2ecdc4, 0x24

	.globl gUnknown_82ECDE8
gUnknown_82ECDE8: @ 0x82ECDE8
	.incbin "baserom_jp.gba", 0x2ecde8, 0x16

	.globl sPickupProbabilities
sPickupProbabilities: @ 0x82ECDFE
	.byte 30
	.byte 40
	.byte 50
	.byte 60
	.byte 70
	.byte 80
	.byte 90
	.byte 94
	.byte 98

	.globl sEnvironmentToType
sEnvironmentToType: @ 0x82ECE07
	.byte 12 @ BATTLE_ENVIRONMENT_GRASS -> TYPE_GRASS
	.byte 12 @ BATTLE_ENVIRONMENT_LONG_GRASS -> TYPE_GRASS
	.byte 4 @ BATTLE_ENVIRONMENT_SAND -> TYPE_GROUND
	.byte 11 @ BATTLE_ENVIRONMENT_UNDERWATER -> TYPE_WATER
	.byte 11 @ BATTLE_ENVIRONMENT_WATER -> TYPE_WATER
	.byte 11 @ BATTLE_ENVIRONMENT_POND -> TYPE_WATER
	.byte 5 @ BATTLE_ENVIRONMENT_MOUNTAIN -> TYPE_ROCK
	.byte 5 @ BATTLE_ENVIRONMENT_CAVE -> TYPE_ROCK
	.byte 0 @ BATTLE_ENVIRONMENT_BUILDING -> TYPE_NORMAL
	.byte 0 @ BATTLE_ENVIRONMENT_PLAIN -> TYPE_NORMAL

	.globl sBallCatchBonuses
sBallCatchBonuses: @ 0x82ECE11
	.byte 20 @ ITEM_ULTRA_BALL
	.byte 15 @ ITEM_GREAT_BALL
	.byte 10 @ ITEM_POKE_BALL
	.byte 15 @ ITEM_SAFARI_BALL
	.byte 0 @ JP trailing entry 4
	.byte 0 @ JP trailing entry 5
	.byte 0 @ JP trailing entry 6

	.section .rodata.data_b2d_after_battle_palace_likelihood

	.globl gUnknown_82ECE7C
gUnknown_82ECE7C: @ 0x82ECE7C
	.incbin "baserom_jp.gba", 0x2ece7c, 0x20

	.globl gUnknown_82ECE9C
gUnknown_82ECE9C: @ 0x82ECE9C
	.incbin "baserom_jp.gba", 0x2ece9c, 0xe4

	.globl gUnknown_82ECF80
gUnknown_82ECF80: @ 0x82ECF80
	.incbin "baserom_jp.gba", 0x2ecf80, 0xc

	.section .rodata.data_b2d_after_smokescreen_data

	.globl gUnknown_82ED050
gUnknown_82ED050: @ 0x82ED050
	.incbin "baserom_jp.gba", 0x2ed050, 0xec

	.globl gUnknown_82ED13C
gUnknown_82ED13C: @ 0x82ED13C
	.incbin "baserom_jp.gba", 0x2ed13c, 0xe4

	.globl gBattleMoves
gBattleMoves: @ 0x82ED220
	.byte 0x00, 0x00, 0x00, 0x00

	.globl gUnknown_82ED224
gUnknown_82ED224: @ 0x82ED224
	.incbin "baserom_jp.gba", 0x2ed224, 0x10b0

	.globl gUnknown_82EE2D4
gUnknown_82EE2D4: @ 0x82EE2D4
	.incbin "baserom_jp.gba", 0x2ee2d4, 0x336

	.globl gUnknown_82EE60A
gUnknown_82EE60A: @ 0x82EE60A
	.incbin "baserom_jp.gba", 0x2ee60a, 0x336

	.globl gUnknown_82EE940
gUnknown_82EE940: @ 0x82EE940
	.incbin "baserom_jp.gba", 0x2ee940, 0x338

	.globl gUnknown_82EEC78
gUnknown_82EEC78: @ 0x82EEC78
	.incbin "baserom_jp.gba", 0x2eec78, 0x2

	.globl gUnknown_82EEC7A
gUnknown_82EEC7A: @ 0x82EEC7A
	.incbin "baserom_jp.gba", 0x2eec7a, 0x8e

	.section .rodata.data_b2d_after_item_effects

	.globl gUnknown_82EF1A0
gUnknown_82EF1A0: @ 0x82EF1A0
	.incbin "baserom_jp.gba", 0x2ef1a0, 0x80

	.globl gUnknown_82EF220
gUnknown_82EF220: @ 0x82EF220
	.incbin "baserom_jp.gba", 0x2ef220, 0xce0

	.globl gFacilityClassToPicIndex
gFacilityClassToPicIndex: @ 0x82EFF00
	.byte 0  @ FACILITY_CLASS_HIKER
	.byte 1  @ FACILITY_CLASS_AQUA_GRUNT_M
	.byte 2  @ FACILITY_CLASS_PKMN_BREEDER_F
	.byte 3  @ FACILITY_CLASS_COOLTRAINER_M
	.byte 4  @ FACILITY_CLASS_BIRD_KEEPER
	.byte 5  @ FACILITY_CLASS_COLLECTOR
	.byte 6  @ FACILITY_CLASS_AQUA_GRUNT_F
	.byte 7  @ FACILITY_CLASS_SWIMMER_M
	.byte 8  @ FACILITY_CLASS_MAGMA_GRUNT_M
	.byte 9  @ FACILITY_CLASS_EXPERT_M
	.byte 11  @ FACILITY_CLASS_BLACK_BELT
	.byte 13  @ FACILITY_CLASS_AQUA_LEADER_ARCHIE
	.byte 14  @ FACILITY_CLASS_HEX_MANIAC
	.byte 15  @ FACILITY_CLASS_AROMA_LADY
	.byte 16  @ FACILITY_CLASS_RUIN_MANIAC
	.byte 17  @ FACILITY_CLASS_INTERVIEWER
	.byte 18  @ FACILITY_CLASS_TUBER_F
	.byte 19  @ FACILITY_CLASS_TUBER_M
	.byte 20  @ FACILITY_CLASS_COOLTRAINER_F
	.byte 21  @ FACILITY_CLASS_LADY
	.byte 22  @ FACILITY_CLASS_BEAUTY
	.byte 23  @ FACILITY_CLASS_RICH_BOY
	.byte 24  @ FACILITY_CLASS_EXPERT_F
	.byte 25  @ FACILITY_CLASS_POKEMANIAC
	.byte 26  @ FACILITY_CLASS_MAGMA_GRUNT_F
	.byte 27  @ FACILITY_CLASS_GUITARIST
	.byte 28  @ FACILITY_CLASS_KINDLER
	.byte 29  @ FACILITY_CLASS_CAMPER
	.byte 30  @ FACILITY_CLASS_PICNICKER
	.byte 31  @ FACILITY_CLASS_BUG_MANIAC
	.byte 33  @ FACILITY_CLASS_PSYCHIC_M
	.byte 34  @ FACILITY_CLASS_PSYCHIC_F
	.byte 35  @ FACILITY_CLASS_GENTLEMAN
	.byte 36  @ FACILITY_CLASS_ELITE_FOUR_SIDNEY
	.byte 37  @ FACILITY_CLASS_ELITE_FOUR_PHOEBE
	.byte 40  @ FACILITY_CLASS_LEADER_ROXANNE
	.byte 41  @ FACILITY_CLASS_LEADER_BRAWLY
	.byte 46  @ FACILITY_CLASS_LEADER_TATE_AND_LIZA
	.byte 48  @ FACILITY_CLASS_SCHOOL_KID_M
	.byte 49  @ FACILITY_CLASS_SCHOOL_KID_F
	.byte 50  @ FACILITY_CLASS_SR_AND_JR
	.byte 51  @ FACILITY_CLASS_POKEFAN_M
	.byte 52  @ FACILITY_CLASS_POKEFAN_F
	.byte 53  @ FACILITY_CLASS_YOUNGSTER
	.byte 54  @ FACILITY_CLASS_CHAMPION_WALLACE
	.byte 55  @ FACILITY_CLASS_FISHERMAN
	.byte 56  @ FACILITY_CLASS_CYCLING_TRIATHLETE_M
	.byte 57  @ FACILITY_CLASS_CYCLING_TRIATHLETE_F
	.byte 58  @ FACILITY_CLASS_RUNNING_TRIATHLETE_M
	.byte 59  @ FACILITY_CLASS_RUNNING_TRIATHLETE_F
	.byte 60  @ FACILITY_CLASS_SWIMMING_TRIATHLETE_M
	.byte 61  @ FACILITY_CLASS_SWIMMING_TRIATHLETE_F
	.byte 62  @ FACILITY_CLASS_DRAGON_TAMER
	.byte 63  @ FACILITY_CLASS_NINJA_BOY
	.byte 64  @ FACILITY_CLASS_BATTLE_GIRL
	.byte 65  @ FACILITY_CLASS_PARASOL_LADY
	.byte 66  @ FACILITY_CLASS_SWIMMER_F
	.byte 67  @ FACILITY_CLASS_TWINS
	.byte 68  @ FACILITY_CLASS_SAILOR
	.byte 70  @ FACILITY_CLASS_WALLY
	.byte 71  @ FACILITY_CLASS_BRENDAN
	.byte 71  @ FACILITY_CLASS_BRENDAN_2
	.byte 71  @ FACILITY_CLASS_BRENDAN_3
	.byte 72  @ FACILITY_CLASS_MAY
	.byte 72  @ FACILITY_CLASS_MAY_2
	.byte 72  @ FACILITY_CLASS_MAY_3
	.byte 32  @ FACILITY_CLASS_PKMN_BREEDER_M
	.byte 73  @ FACILITY_CLASS_BUG_CATCHER
	.byte 74  @ FACILITY_CLASS_PKMN_RANGER_M
	.byte 75  @ FACILITY_CLASS_PKMN_RANGER_F
	.byte 76  @ FACILITY_CLASS_MAGMA_LEADER_MAXIE
	.byte 77  @ FACILITY_CLASS_LASS
	.byte 78  @ FACILITY_CLASS_YOUNG_COUPLE
	.byte 79  @ FACILITY_CLASS_OLD_COUPLE
	.byte 80  @ FACILITY_CLASS_SIS_AND_BRO
	.byte 81  @ FACILITY_CLASS_STEVEN
	.byte 82  @ FACILITY_CLASS_SALON_MAIDEN_ANABEL
	.byte 83  @ FACILITY_CLASS_DOME_ACE_TUCKER
	.byte 89  @ FACILITY_CLASS_RED
	.byte 90  @ FACILITY_CLASS_LEAF
	.byte 91  @ FACILITY_CLASS_RS_BRENDAN
	.byte 92  @ FACILITY_CLASS_RS_MAY

	.globl gUnknown_82EFF52
gUnknown_82EFF52: @ 0x82EFF52
	.incbin "baserom_jp.gba", 0x2eff52, 0x52

	.globl gUnknown_82EFFA4
gUnknown_82EFFA4: @ 0x82EFFA4
	.incbin "baserom_jp.gba", 0x2effa4, 0x110

	.globl gExperienceTables
gExperienceTables: @ 0x82F00B4
	.incbin "baserom_jp.gba", 0x2f00b4, 0xca0

	.globl gSpeciesInfo
gSpeciesInfo: @ 0x82F0D54
	.4byte 0, 0, 0

	.globl gUnknown_82F0D60
gUnknown_82F0D60: @ 0x82F0D60
	.incbin "baserom_jp.gba", 0x2f0d60, 0x2

	.globl gUnknown_82F0D62
gUnknown_82F0D62: @ 0x82F0D62
	.incbin "baserom_jp.gba", 0x2f0d62, 0x3

	.globl gUnknown_82F0D65
gUnknown_82F0D65: @ 0x82F0D65
	.incbin "baserom_jp.gba", 0x2f0d65, 0x2cff
	.globl gUnknown_82F3A64

	.section .rodata.mid48

	.globl gUnknown_8300A99
gUnknown_8300A99: @ 0x8300A99
	.incbin "baserom_jp.gba", 0x300A99, 0x2

	.section .rodata.mid53

	.globl gUnknown_830F760
gUnknown_830F760: @ 0x830F760
	.incbin "baserom_jp.gba", 0x30f760, 0x6

	.globl gUnknown_830F766

	.section .rodata.mid79

	.globl gUnknown_85CA3D8
gUnknown_85CA3D8: @ 0x85CA3D8
	.incbin "baserom_jp.gba", 0x5ca3d8, 0x1

	.globl gUnknown_85CA3D9
gUnknown_85CA3D9: @ 0x85CA3D9
	.string "$イベント$"

	.globl gUnknown_85CA3DF

	.section .rodata.mid35

	.globl gUnknown_8566D64
gUnknown_8566D64: @ 0x8566D64
	.incbin "baserom_jp.gba", 0x566d64, 0x10

	.section .rodata.mid27

	.globl gUnknown_846F9D6
gUnknown_846F9D6: @ 0x846F9D6
	.incbin "baserom_jp.gba", 0x46f9d6, 0x6

	.globl gUnknown_846F9DC
gUnknown_846F9DC: @ 0x846F9DC
	.incbin "baserom_jp.gba", 0x46f9dc, 0xc

	.section .rodata.mid10


	.globl gUnknown_82F4AA2
gUnknown_82F4AA2: @ 0x82F4AA2
	.incbin "baserom_jp.gba", 0x2f4aa2, 0x16

	.section .rodata.mid13


	.globl gUnknown_82F51C6
gUnknown_82F51C6: @ 0x82F51C6
	.incbin "baserom_jp.gba", 0x2f51c6, 0x16
	.globl gUnknown_82F51DC

	.section .rodata.mid14


	.globl gUnknown_82F521C
gUnknown_82F521C: @ 0x82F521C
	.incbin "baserom_jp.gba", 0x2f521c, 0x16
	.globl gUnknown_82F5232

	.section .rodata.mid4


	.globl gUnknown_82F5196
gUnknown_82F5196: @ 0x82F5196
	.incbin "baserom_jp.gba", 0x2f5196, 0x16

	.section .rodata.mid42

	.globl gUnknown_82F5684
gUnknown_82F5684: @ 0x82F5684
	.incbin "baserom_jp.gba", 0x2f5684, 0x16

	.section .rodata.mid9


	.globl gUnknown_82F441C
gUnknown_82F441C: @ 0x82F441C
	.incbin "baserom_jp.gba", 0x2f441c, 0x16
	.globl gUnknown_82F4432

	.section .rodata.mid3


	.globl gUnknown_82F4720
gUnknown_82F4720: @ 0x82F4720
	.incbin "baserom_jp.gba", 0x2f4720, 0x18
	.globl gUnknown_82F4738

	.section .rodata.mid46

	.globl gUnknown_82F5C54
gUnknown_82F5C54: @ 0x82F5C54
	.incbin "baserom_jp.gba", 0x2f5c54, 0x1a

	.section .rodata.mid5


	.globl gUnknown_82F495E
gUnknown_82F495E: @ 0x82F495E
	.incbin "baserom_jp.gba", 0x2f495e, 0x12
	.globl gUnknown_82F4970
gUnknown_82F4970: @ 0x82F4970
	.incbin "baserom_jp.gba", 0x2f4970, 0x12
	.globl gUnknown_82F4982

	.section .rodata.mid2


	.globl gUnknown_82F3E80
gUnknown_82F3E80: @ 0x82F3E80
	.incbin "baserom_jp.gba", 0x2f3e80, 0x14
	.globl gUnknown_82F3E94
gUnknown_82F3E94: @ 0x82F3E94
	.incbin "baserom_jp.gba", 0x2f3e94, 0x16
	.globl gUnknown_82F3EAA

	.section .rodata.mid6


	.globl gUnknown_82F414E
gUnknown_82F414E: @ 0x82F414E
	.incbin "baserom_jp.gba", 0x2f414e, 0x14
	.globl gUnknown_82F4162
gUnknown_82F4162: @ 0x82F4162
	.incbin "baserom_jp.gba", 0x2f4162, 0x18

	.section .rodata.mid12


	.globl gUnknown_82F4250
gUnknown_82F4250: @ 0x82F4250
	.incbin "baserom_jp.gba", 0x2f4250, 0x16
	.globl gUnknown_82F4266
gUnknown_82F4266: @ 0x82F4266
	.incbin "baserom_jp.gba", 0x2f4266, 0x1a
	.globl gUnknown_82F4280

	.section .rodata.mid11


	.globl gUnknown_82F3F64
gUnknown_82F3F64: @ 0x82F3F64
	.incbin "baserom_jp.gba", 0x2f3f64, 0x1a
	.globl gUnknown_82F3F7E
gUnknown_82F3F7E: @ 0x82F3F7E
	.incbin "baserom_jp.gba", 0x2f3f7e, 0x1a
	.globl gUnknown_82F3F98

	.section .rodata.mid43

	.globl gUnknown_82F57C2
gUnknown_82F57C2: @ 0x82F57C2
	.incbin "baserom_jp.gba", 0x2f57c2, 0x18
	.globl gUnknown_82F57DA
gUnknown_82F57DA: @ 0x82F57DA
	.incbin "baserom_jp.gba", 0x2f57da, 0x1e

	.section .rodata.mid_base


	.globl gUnknown_82F4F2A
gUnknown_82F4F2A: @ 0x82F4F2A
	.incbin "baserom_jp.gba", 0x2f4f2a, 0x16
	.globl gUnknown_82F4F40
gUnknown_82F4F40: @ 0x82F4F40
	.incbin "baserom_jp.gba", 0x2f4f40, 0x16
	.globl gUnknown_82F4F56
gUnknown_82F4F56: @ 0x82F4F56
	.incbin "baserom_jp.gba", 0x2f4f56, 0x14

	.section .rodata.mid41

	.globl gUnknown_82F551C
gUnknown_82F551C: @ 0x82F551C
	.incbin "baserom_jp.gba", 0x2f551c, 0x1c
	.globl gUnknown_82F5538
gUnknown_82F5538: @ 0x82F5538
	.incbin "baserom_jp.gba", 0x2f5538, 0x20

	.section .rodata.mid44

	.globl gUnknown_82F5934
gUnknown_82F5934: @ 0x82F5934
	.incbin "baserom_jp.gba", 0x2f5934, 0x18
	.globl gUnknown_82F594C
gUnknown_82F594C: @ 0x82F594C
	.incbin "baserom_jp.gba", 0x2f594c, 0x16
	.globl gUnknown_82F5962
gUnknown_82F5962: @ 0x82F5962
	.incbin "baserom_jp.gba", 0x2f5962, 0x1c

	.section .rodata.mid45

	.globl gUnknown_82F5AC0
gUnknown_82F5AC0: @ 0x82F5AC0
	.incbin "baserom_jp.gba", 0x2f5ac0, 0x16
	.globl gUnknown_82F5AD6
gUnknown_82F5AD6: @ 0x82F5AD6
	.incbin "baserom_jp.gba", 0x2f5ad6, 0x1c
	.globl gUnknown_82F5AF2
gUnknown_82F5AF2: @ 0x82F5AF2
	.incbin "baserom_jp.gba", 0x2f5af2, 0x1c

	.section .rodata.mid52

	.globl gUnknown_830F6FD
gUnknown_830F6FD: @ 0x830F6FD
	.incbin "baserom_jp.gba", 0x30f6fd, 0x51

	.section .rodata.mid8


	.globl gUnknown_82F53E6
gUnknown_82F53E6: @ 0x82F53E6
	.incbin "baserom_jp.gba", 0x2f53e6, 0x1c
	.globl gUnknown_82F5402
gUnknown_82F5402: @ 0x82F5402
	.incbin "baserom_jp.gba", 0x2f5402, 0x18
	.globl gUnknown_82F541A
gUnknown_82F541A: @ 0x82F541A
	.incbin "baserom_jp.gba", 0x2f541a, 0x1e

	.section .rodata.mid82

	.globl gUnknown_85CA8B5
gUnknown_85CA8B5: @ 0x85CA8B5
	.string "メールボックス$どうぐを　あずける$"
	.globl gUnknown_85CA8C7
gUnknown_85CA8C7: @ 0x85CA8C7
	.string "どうぐを　ひきだす$"
	.globl gUnknown_85CA8D1
gUnknown_85CA8D1: @ 0x85CA8D1
	.string "どうぐを　すてる$パソコン　に\n"
	.string "どうぐを　あずけます$パソコン　から\n"
	.string "どうぐを　ひきだします$パソコン　に　あずけている\n"
	.string "どうぐを　すてます$"
	.globl gUnknown_85CA918

	.section .rodata.mid34

	.globl gUnknown_8566CC7
gUnknown_8566CC7: @ 0x8566CC7
	.incbin "baserom_jp.gba", 0x566cc7, 0x2

	.globl gUnknown_8566CC9
gUnknown_8566CC9: @ 0x8566CC9
	.incbin "baserom_jp.gba", 0x566cc9, 0x6

	.globl gUnknown_8566CCF
gUnknown_8566CCF: @ 0x8566CCF
	.incbin "baserom_jp.gba", 0x566ccf, 0x24

	.globl gUnknown_8566CF3
gUnknown_8566CF3: @ 0x8566CF3
	.incbin "baserom_jp.gba", 0x566cf3, 0x6

	.globl gUnknown_8566CF9
gUnknown_8566CF9: @ 0x8566CF9
	.incbin "baserom_jp.gba", 0x566cf9, 0xf

	.globl gUnknown_8566D08
gUnknown_8566D08: @ 0x8566D08
	.incbin "baserom_jp.gba", 0x566d08, 0x4

	.globl gUnknown_8566D0C
gUnknown_8566D0C: @ 0x8566D0C
	.incbin "baserom_jp.gba", 0x566d0c, 0x20

	.section .rodata.mid36

	.globl gUnknown_8566DF5
gUnknown_8566DF5: @ 0x8566DF5
	.incbin "baserom_jp.gba", 0x566df5, 0xb

	.globl gUnknown_8566E00
gUnknown_8566E00: @ 0x8566E00
	.incbin "baserom_jp.gba", 0x566e00, 0x40

	.globl gUnknown_8566E40
gUnknown_8566E40: @ 0x8566E40
	.incbin "baserom_jp.gba", 0x566e40, 0x18

	.globl gUnknown_8566E58
gUnknown_8566E58: @ 0x8566E58
	.incbin "baserom_jp.gba", 0x566e58, 0x5

	.section .rodata.mid66

	.globl gUnknown_85ABBC9
gUnknown_85ABBC9: @ 0x85ABBC9
	.string "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}はい\n"
	.string "いいえ$"
	.globl gUnknown_85ABBD8
gUnknown_85ABBD8: @ 0x85ABBD8
	.string "{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}いれかえる　わざを\n"
	.string "えらんで　ください${PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}${ESCAPE 3}${ESCAPE 4}$ー$HP　　$こうげき$ぼうぎょ$とくこう$とくぼう$きBコくにBコくしBコくひBコくちBコくヘ⋯コく"

	.globl gText_SafariBalls

	.section .rodata.mid67

	.globl gUnknown_85ABD18
gUnknown_85ABD18: @ 0x85ABD18
	.string "バトルトーナメント$1かい$2かい$じゅんけっしょう$けっしょう$　　　"

	.globl gUnknown_85ABD3C
gUnknown_85ABD3C: @ 0x85ABD3C
	.string "めCコくよCコくれCコくぉCコくきたいの　おおがた　しんじん！\p"
	.string "$ひがんの　はつ　ゆうしょう　なるか！？\p"
	.string "$もと　チャンピオン！\p"
	.string "$ぜんかい　チャンピオン！\p"
	.string "$むてきの　チャンピオン！\p$"
	.globl gUnknown_85ABD9A

	.section .rodata.mid75

.globl gUnknown_85C96F8
gUnknown_85C96F8: @ 0x85C96F8
	.incbin "baserom_jp.gba", 0x5c96f8, 0x30

	.globl gUnknown_85C9728
gUnknown_85C9728: @ 0x85C9728
	.incbin "baserom_jp.gba", 0x5c9728, 0x10

	.globl gUnknown_85C9738
gUnknown_85C9738: @ 0x85C9738
	.string "{B_COPY_VAR_1}へ\n"
	.string "もどります$"
	.globl gUnknown_85C9742
gUnknown_85C9742: @ 0x85C9742
	.string "　ど　う　ぐ　　$モンスターボール$　わざマシン　　$　き　の　み　　$たいせつなもの　$"
	.globl gUnknown_85C976F

	.section .rodata.mid57_gap

	.incbin "baserom_jp.gba", 0x55a958, 0x78


	.section .rodata.mid97

	.globl gJPText_WriteErrorUnableToSaveData
gJPText_WriteErrorUnableToSaveData: @ 0x85CD043
	.string "かきこみ　エラー　です\n"
	.string "データが　ほぞん　できませんでした$あか$あお$　"
	.globl gText_Red
	.set gText_Red, gJPText_WriteErrorUnableToSaveData + 0x1E
	.globl gText_Blue
	.set gText_Blue, gJPText_WriteErrorUnableToSaveData + 0x21
	.globl gUnknown_85CD068
gUnknown_85CD068: @ 0x85CD068
	.incbin "baserom_jp.gba", 0x5cd068, 0x10

	.globl gUnknown_85CD078
gUnknown_85CD078: @ 0x85CD078
	.incbin "baserom_jp.gba", 0x5cd078, 0x20

	.globl gUnknown_85CD098
gUnknown_85CD098: @ 0x85CD098
	.incbin "baserom_jp.gba", 0x5cd098, 0x8

	.globl gUnknown_85CD0A0
gUnknown_85CD0A0: @ 0x85CD0A0
	.incbin "baserom_jp.gba", 0x5cd0a0, 0x28

	.globl gUnknown_85CD0C8
gUnknown_85CD0C8: @ 0x85CD0C8
	.incbin "baserom_jp.gba", 0x5cd0c8, 0x14

	.globl gUnknown_85CD0DC

	.section .rodata.mid81

.globl gUnknown_85CA6A4
gUnknown_85CA6A4: @ 0x85CA6A4
	.string "{B_COPY_VAR_3}{B_COPY_VAR_1}/{B_COPY_VAR_2}$グッズを　おく$グッズを　もどす$グッズを　すてる$"
	.globl gUnknown_85CA6C6
gUnknown_85CA6C6: @ 0x85CA6C6
	.string "{COLOR 161}{SHADOW 161}$えらんだ　グッズを　へやに　おきます！$えらんだ　グッズを　パソコンに　もどします！$いらなくなった　グッズを　すてます！$"
	.globl gUnknown_85CA70B
gUnknown_85CA70B: @ 0x85CA70B
	.string "グッズは　ありません！{PAUSE_UNTIL_PRESS}$つくえ$いす$はちうえ$おきもの$マット$ポスター$ぬいぐるみ$クッション$"
	.globl gUnknown_85CA73F

	.section .rodata.mid73

.globl gUnknown_85C9299
gUnknown_85C9299: @ 0x85C9299
	.string "▶$　$"
	.globl gUnknown_85C929D
gUnknown_85C929D: @ 0x85C929D
	.string "でんどういり　おめでとう！$みつけた　ポケモン　{B_COPY_VAR_1}！\n"
	.string "つかまえた　ポケモン　{B_COPY_VAR_2}！\p"
	.string "オダマキはかせの\n"
	.string "ポケモンずかん　ひょうか！\p"
	.string "オダマキ“どれどれ\p"
	.string "$ここまでの　レポートを　かきしるしています！\n"
	.string "でんげんを　きらないでください$"
	.globl gUnknown_85C9311
gUnknown_85C9311: @ 0x85C9311
	.incbin "baserom_jp.gba", 0x5c9311, 0x17

	.globl gUnknown_85C9328
gUnknown_85C9328: @ 0x85C9328
	.string "だい{B_COPY_VAR_1}かい　でんどういり！$"
	.globl gUnknown_85C9337
gUnknown_85C9337: @ 0x85C9337
	.string "リーグ　チャンピオン！　おめでとう！$$"
	.globl gUnknown_85C934B
gUnknown_85C934B: @ 0x85C934B
	.string "No,$"

	.globl gUnknown_85C934F
gUnknown_85C934F: @ 0x85C934F
	.string "Lv$IDNo,/$"

	.globl gUnknown_85C9359

	.section .rodata.mid78

	.globl gUnknown_85CA276
gUnknown_85CA276: @ 0x85CA276
	.incbin "baserom_jp.gba", 0x5ca276, 0x1e

	.globl gUnknown_85CA294
gUnknown_85CA294: @ 0x85CA294
	.string "そのポケモンを　こうかんすると\n"
	.string "せんとうできなくなっちゃうよ！$"
	.globl gUnknown_85CA2B4
gUnknown_85CA2B4: @ 0x85CA2B4
	.string "その　ポケモンは　いま\n"
	.string "こうかんに　だせません$"
	.globl gUnknown_85CA2CC
gUnknown_85CA2CC: @ 0x85CA2CC
	.string "タマゴは　いま\n"
	.string "こうかんに　だせません$あいての　ポケモンとは\n"
	.string "いまは　こうかん　できません$　いまは　そのポケモンを　\n"
	.string "あいては　うけとることが　できません$その　あいてとは　いまは　\n"
	.string "こうかん　できません$　　　あいての　ほしがっている　タイプの\n"
	.string "ポケモンでは　ありません$　それは　タマゴでは　ありません$"

	.globl gText_Register
gText_Register: @ 0x85CA368
	.string "とうろくする$"
	.globl gText_Attack3
	.set gText_Attack3, gText_Register + 0x7
	.globl gText_Defense3
	.set gText_Defense3, gText_Register + 0xC
	.globl gText_Speed2
	.set gText_Speed2, gText_Register + 0x1B

	.section .rodata.mid93

	.globl gUnknown_85CC663
gUnknown_85CC663: @ 0x85CC663
	.string "{DYNAMIC 0}さんが　さんかしました！$"
	.globl gUnknown_85CC672
gUnknown_85CC672: @ 0x85CC672
	.string "{DYNAMIC 0}さんが　ぬけました${DYNAMIC 0}の{DYNAMIC 1}ひきめ:${DYNAMIC 0}の{DYNAMIC 1}ひきめは　いません$さんかしゃが　いなくなったので\n"
	.string "しゅうりょうします！$リーダーの　{DYNAMIC 0}さんが\n"
	.string "ぬけたので　かいさんします！$とうろくが　かわりました\n"
	.string "ポケモンレポートに　かきこみますか？$まえに　かかれた　レポートに\n"
	.string "うえから　かいても　いいですか？$ポケモンレポートに　かきこんでいます\n"
	.string "でんげんを　きらないで　ください${DYNAMIC 0}　は\n"
	.string "レポートに　しっかり　かきのこした！$リーダーが　やめると　かいさん\n"
	.string "になりますが　よろしいですか？$"
	.globl gUnknown_85CC769

	.section .rodata.mid80

.globl gUnknown_85CA4A6
gUnknown_85CA4A6: @ 0x85CA4A6
	.incbin "baserom_jp.gba", 0x5ca4a6, 0x26
	.globl gUnknown_85CA4CC
gUnknown_85CA4CC: @ 0x85CA4CC
	.incbin "baserom_jp.gba", 0x5ca4cc, 0x26
	.globl gUnknown_85CA4F2
gUnknown_85CA4F2: @ 0x85CA4F2
	.incbin "baserom_jp.gba", 0x5ca4f2, 0x20
	.globl gUnknown_85CA512
gUnknown_85CA512: @ 0x85CA512
	.incbin "baserom_jp.gba", 0x5ca512, 0x29
	.globl gUnknown_85CA53B
gUnknown_85CA53B: @ 0x85CA53B
	.incbin "baserom_jp.gba", 0x5ca53b, 0x28
	.globl gUnknown_85CA563
gUnknown_85CA563: @ 0x85CA563
	.incbin "baserom_jp.gba", 0x5ca563, 0xd
	.globl gUnknown_85CA570
gUnknown_85CA570: @ 0x85CA570
	.incbin "baserom_jp.gba", 0x5ca570, 0x23
	.globl gUnknown_85CA593
gUnknown_85CA593: @ 0x85CA593
	.incbin "baserom_jp.gba", 0x5ca593, 0x23
	.globl gUnknown_85CA5B6

	.section .rodata.mid83

	.globl gText_Yes
gText_Yes: @ 0x85CAAD8
	.string "はい$"
	.globl gText_No
gText_No: @ 0x85CAADB
	.string "いいえ$せつめい$シングルバトル$ダブルバトル$マルチバトル$ハギ$ちょうせんする$せつめいをきく$"
	.globl gUnknown_85CAB0D
gUnknown_85CAB0D: @ 0x85CAB0D
	.string "レベル50$"

	.globl gUnknown_85CAB13
gUnknown_85CAB13: @ 0x85CAB13
	.string "オープンレベル$おいしいみず　200¥$サイコソーダ　300¥$ミックスオレ　350¥$はしりかた$まがるコツ$すなのさか$ウイリー$ダニエル$ジャンプ$まんぞく$ふまん$しんかいのキバ$しんかいのウロコ$あおいビードロ$きいろビードロ$あかいビードロ$しろいビードロ$くろいビードロ$ガラスのいす$ガラスのつくえ$キモリドール　　　1000まい$アチャモドール　　1000まい$ミズゴロウドール　1000まい$　50まい　　1000¥$500まい　10000¥$ばつぐん$あんまり$あかいかけら$きいろいかけら$あおいかけら$みどりのかけら$バトルフロンティア$みぎ$ひだり$わざマシン32　　1500まい$わざマシン29　　3500まい$わざマシン35　　4000まい$わざマシン24　　4000まい$わざマシン13　　4000まい$"
	.globl gText_BattleFrontier
	.set gText_BattleFrontier, gUnknown_85CAB13 + 0x110
	.globl gUnknown_85CAC84

	.section .rodata.mid85

	.globl gUnknown_85CADC6
gUnknown_85CADC6: @ 0x85CADC6
	.string "レポート$"

	.globl gUnknown_85CADCB
gUnknown_85CADCB: @ 0x85CADCB
	.string "せってい$"
	.globl gUnknown_85CADD0
gUnknown_85CADD0: @ 0x85CADD0
	.string "とじる$　5BP$10BP$15BP$あかいテント$あおいテント$みなみのことう$たんじょうのしま$さいはてのことう$へそのいわ$ツメのかせき$ねっこのかせき$いいえ　$これからしょうぶだ！$しょうぶにかった！$しょうぶにまけた！$おしえない$トレードセンター$コロシアム$レコードコーナー$きのみクラッシュ$ぐるぐるこうかん$ミニポケモンでジャンプ$ドードリオのきのみどり$リーダーになる$グループにはいる$2つのコース$レベル50$オープンレベル$ポケモンのしゅるいとかず$もたせるどうぐ$シンボル$たいせんのきろく$バトルポイント$タワーについて$つれていくポケモン$バトルサロン$つうしんマルチ$バトルでの　ちゅうい$はんてい‘こころ'$はんてい‘わざ'$はんてい‘からだ'$くみあわせ$トーナメントひょう$ダブルノックアウト$きほんルール$トレード　あいて$トレード　かいすう$トレード　ちゅうい$オープンレベル$たたかいのきほん$ポケモンのせいかく$ポケモンのわざ$ちからをはっきできない$ピンチになったら$ピラミッドの　ポケモン$ピラミッドの　トレーナー$ピラミッドの　めいろ$バトルバッグ$ポケナビと　バッグ$もたせた　どうぐ$ポケモンの　じゅんばん$でてくるポケモン$たたかう　トレーナー$つづける$きろくする$やすむ$リタイア$"
	.globl gText_SouthernIsland
	.set gText_SouthernIsland, gUnknown_85CADD0 + 0x21
	.globl gText_BirthIsland
	.set gText_BirthIsland, gUnknown_85CADD0 + 0x29
	.globl gText_FarawayIsland
	.set gText_FarawayIsland, gUnknown_85CADD0 + 0x32
	.globl gText_NavelRock
	.set gText_NavelRock, gUnknown_85CADD0 + 0x3B
	.globl gUnknown_85CB00E

	.section .rodata.mid94

	.globl gUnknown_85CC874
gUnknown_85CC874: @ 0x85CC874
	.string "タマゴが　かえって\n"
	.string "{B_COPY_VAR_1}が　うまれた！$"
	.globl gUnknown_85CC888
gUnknown_85CC888: @ 0x85CC888
	.incbin "baserom_jp.gba", 0x5cc888, 0x140

	.globl gUnknown_85CC9C8
gUnknown_85CC9C8: @ 0x85CC9C8
	.incbin "baserom_jp.gba", 0x5cc9c8, 0xc

	.globl gUnknown_85CC9D4
gUnknown_85CC9D4: @ 0x85CC9D4
	.incbin "baserom_jp.gba", 0x5cc9d4, 0x1c

	.globl gUnknown_85CC9F0
gUnknown_85CC9F0: @ 0x85CC9F0
	.string "じかん$"
	.globl gUnknown_85CC9F4
gUnknown_85CC9F4: @ 0x85CC9F4
	.incbin "baserom_jp.gba", 0x5cc9f4, 0x8

	.globl gUnknown_85CC9FC
gUnknown_85CC9FC: @ 0x85CC9FC
	.string "サラサラぐあい$"
	.globl gUnknown_85CCA04
gUnknown_85CCA04: @ 0x85CCA04
	.string "{B_COPY_VAR_1}$　"

	.globl gUnknown_85CCA08
gUnknown_85CCA08: @ 0x85CCA08
	.string "ふん$　"

	.globl gUnknown_85CCA0C
gUnknown_85CCA0C: @ 0x85CCA0C
	.string "{B_COPY_VAR_1},{B_COPY_VAR_2}$　　"

	.globl gUnknown_85CCA14
gUnknown_85CCA14: @ 0x85CCA14
	.string "びょう$"
	.globl gUnknown_85CCA18
gUnknown_85CCA18: @ 0x85CCA18
	.string "{B_COPY_VAR_1},{B_COPY_VAR_2}$　　"

	.globl gUnknown_85CCA20
gUnknown_85CCA20: @ 0x85CCA20
	.incbin "baserom_jp.gba", 0x5cca20, 0x8

	.globl gUnknown_85CCA28
gUnknown_85CCA28: @ 0x85CCA28
	.string "{B_COPY_VAR_1}パーセント$"

	.globl gText_PressesRankings
gText_PressesRankings: @ 0x85CCA30
	.string "おした　かいすう　ランキング$　"

	.globl gText_CrushingResults
gText_CrushingResults: @ 0x85CCA40
	.string "つぶした　けっか$　　　ていねいさ　ランキング$たすけあい　ランキング$おすつよさ　ランキング$"
	.globl gUnknown_85CCA70
gUnknown_85CCA70: @ 0x85CCA70
	.incbin "baserom_jp.gba", 0x5cca70, 0xc

	.globl gUnknown_85CCA7C
gUnknown_85CCA7C: @ 0x85CCA7C
	.incbin "baserom_jp.gba", 0x5cca7c, 0x10

	.globl gUnknown_85CCA8C

	.section .rodata.mid76_pokeblock_name_text_prefix

	.globl gUnknown_85C97B5
gUnknown_85C97B5: @ 0x85C97B5
	.string "{NO}{B_COPY_VAR_1}　{B_COPY_VAR_2}$"

	.globl gUnknown_85C97BD
gUnknown_85C97BD: @ 0x85C97BD
	.string "きのみのタグ$"
	.globl gText_HP3
	.set gText_HP3, gUnknown_85C97BD + 0x32A
	.globl gText_SpAtk3
	.set gText_SpAtk3, gUnknown_85C97BD + 0x330
	.globl gText_SpDef3
	.set gText_SpDef3, gUnknown_85C97BD + 0x335
	.globl gText_WontHaveEffect
	.set gText_WontHaveEffect, gUnknown_85C97BD + 0x33A
	.globl gText_PkmnLearnedMove3
	.set gText_PkmnLearnedMove3, gUnknown_85C97BD + 0x5AB
	.globl gText_PkmnCantLearnMove
	.set gText_PkmnCantLearnMove, gUnknown_85C97BD + 0x5BF
	.globl gText_PkmnNeedsToReplaceMove
	.set gText_PkmnNeedsToReplaceMove, gUnknown_85C97BD + 0x5E4
	.globl gText_StopLearningMove2
	.set gText_StopLearningMove2, gUnknown_85C97BD + 0x635
	.globl gText_MoveNotLearned
	.set gText_MoveNotLearned, gUnknown_85C97BD + 0x650
	.globl gText_WhichMoveToForget
	.set gText_WhichMoveToForget, gUnknown_85C97BD + 0x666
	.globl gText_12PoofForgotMove
	.set gText_12PoofForgotMove, gUnknown_85C97BD + 0x678
	.globl gText_PkmnAlreadyKnows
	.set gText_PkmnAlreadyKnows, gUnknown_85C97BD + 0x6BC
	.globl gText_PkmnElevatedToLvVar2
	.set gText_PkmnElevatedToLvVar2, gUnknown_85C97BD + 0x791
	.globl gText_RemoveMailBeforeItem
	.set gText_RemoveMailBeforeItem, gUnknown_85C97BD + 0x49F
	.globl gText_PkmnHoldingItemCantHoldMail
	.set gText_PkmnHoldingItemCantHoldMail, gUnknown_85C97BD + 0x54F
	.globl gText_MailTransferredFromMailbox
	.set gText_MailTransferredFromMailbox, gUnknown_85C97BD + 0x575
	.globl gText_CancelBattle
	.set gText_CancelBattle, gUnknown_85C97BD + 0xA5F
	.globl gText_ReturnToWaitingRoom
	.set gText_ReturnToWaitingRoom, gUnknown_85C97BD + 0xA6C
	.globl gText_CancelChallenge
	.set gText_CancelChallenge, gUnknown_85C97BD + 0xA7B
	.globl gText_PkmnCantSwitchOut
	.set gText_PkmnCantSwitchOut, gUnknown_85C97BD + 0x35D
	.globl gText_PkmnAlreadyInBattle
	.set gText_PkmnAlreadyInBattle, gUnknown_85C97BD + 0x370
	.globl gText_PkmnAlreadySelected
	.set gText_PkmnAlreadySelected, gUnknown_85C97BD + 0x386
	.globl gText_PkmnHasNoEnergy
	.set gText_PkmnHasNoEnergy, gUnknown_85C97BD + 0x39C
	.globl gText_CantSwitchWithAlly
	.set gText_CantSwitchWithAlly, gUnknown_85C97BD + 0x3B9
	.globl gText_EggCantBattle
	.set gText_EggCantBattle, gUnknown_85C97BD + 0x3E0
	.globl gText_ShopBuy
	.set gText_ShopBuy, gUnknown_85C97BD + 0x101
	.globl gText_ShopSell
	.set gText_ShopSell, gUnknown_85C97BD + 0x108
	.globl gText_ShopQuit
	.set gText_ShopQuit, gUnknown_85C97BD + 0x10F
	.globl gUnknown_85C983E

	.section .rodata.mid68

	.globl gUnknown_85ABE2F
gUnknown_85ABE2F: @ 0x85ABE2F
	.incbin "baserom_jp.gba", 0x5abe2f, 0x21d
