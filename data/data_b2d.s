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

	.section .rodata.data_b2d_after_battle_palace_likelihood

	.globl gUnknown_82ECE7C
gUnknown_82ECE7C: @ 0x82ECE7C
	.incbin "baserom_jp.gba", 0x2ece7c, 0x20

	.section .rodata.data_b2d_after_battle_moves

	.align 2
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

	.section .rodata.data_b2d_after_tmhm_learnsets

	.section .rodata.data_b2d_after_trainer_class_lookups


	.section .rodata.data_b2d_after_cry_ids
	.incbin "baserom_jp.gba", 0x2f00b2, 0x2


	.section .rodata.data_b2d_after_experience_tables


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

	.section .rodata.mid52

	.globl gUnknown_830F6FD
gUnknown_830F6FD: @ 0x830F6FD
	.incbin "baserom_jp.gba", 0x30f6fd, 0x51

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
