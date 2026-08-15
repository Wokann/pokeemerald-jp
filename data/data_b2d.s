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

	.globl gUnknown_82ECE18
gUnknown_82ECE18: @ 0x82ECE18
	.incbin "baserom_jp.gba", 0x2ece18, 0x64

	.globl gUnknown_82ECE7C
gUnknown_82ECE7C: @ 0x82ECE7C
	.incbin "baserom_jp.gba", 0x2ece7c, 0x20

	.globl gUnknown_82ECE9C
gUnknown_82ECE9C: @ 0x82ECE9C
	.incbin "baserom_jp.gba", 0x2ece9c, 0xe4

	.globl gUnknown_82ECF80
gUnknown_82ECF80: @ 0x82ECF80
	.incbin "baserom_jp.gba", 0x2ecf80, 0xc

	.globl gUnknown_82ECF8C
gUnknown_82ECF8C: @ 0x82ECF8C
	.incbin "baserom_jp.gba", 0x2ecf8c, 0x1c

	.globl sSmokescreenImpactSpriteSheet
sSmokescreenImpactSpriteSheet: @ 0x82ECFA8
	.incbin "baserom_jp.gba", 0x2ecfa8, 0x8

	.globl sSmokescreenImpactSpritePalette
sSmokescreenImpactSpritePalette: @ 0x82ECFB0
	.incbin "baserom_jp.gba", 0x2ecfb0, 0x60

	.globl sSmokescreenImpactSpriteTemplate
sSmokescreenImpactSpriteTemplate: @ 0x82ED010
	.incbin "baserom_jp.gba", 0x2ed010, 0x18

	.globl gUnknown_82ED028
gUnknown_82ED028: @ 0x82ED028
	.incbin "baserom_jp.gba", 0x2ed028, 0x10

	.globl gUnknown_82ED038
gUnknown_82ED038: @ 0x82ED038
	.incbin "baserom_jp.gba", 0x2ed038, 0x18

	.globl gUnknown_82ED050
gUnknown_82ED050: @ 0x82ED050
	.incbin "baserom_jp.gba", 0x2ed050, 0xec

	.globl gUnknown_82ED13C
gUnknown_82ED13C: @ 0x82ED13C
	.incbin "baserom_jp.gba", 0x2ed13c, 0xe4

	.globl gBattleMoves
gBattleMoves: @ 0x82ED220
	.incbin "baserom_jp.gba", 0x2ed220, 0x4

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
	.incbin "baserom_jp.gba", 0x2eec7a, 0x29a

	.globl gUnknown_82EEF14
gUnknown_82EEF14: @ 0x82EEF14
	.incbin "baserom_jp.gba", 0x2eef14, 0x28c

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
	.incbin "baserom_jp.gba", 0x2f0d54, 0xc

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
gUnknown_82F3A64: @ 0x82F3A64
	.string "むいをくべせにとぷほぽほぱりrぇぼぞwぺぴシ$$"
	.globl gUnknown_82F3A7C
gUnknown_82F3A7C: @ 0x82F3A7C
	.string "むいをいべいをくべせにとぷほぽほぱわrげぼぴwセぴミ$$"
	.globl gUnknown_82F3A98
gUnknown_82F3A98: @ 0x82F3A98
	.string "むいをいべいにいをくべせにとぷほぽほぱわrげぼイwハぴェ$$"
	.globl gUnknown_82F3AB6
gUnknown_82F3AB6: @ 0x82F3AB6
	.string "こいをいゃせフはテよ,ぇゅず2ぼイカウツ$$"
	.globl gUnknown_82F3ACC
gUnknown_82F3ACC: @ 0x82F3ACC
	.string "こいをいゃいゃせフはテり,ょゅで2イイタウホ$$"
	.globl gUnknown_82F3AE4
gUnknown_82F3AE4: @ 0x82F3AE4
	.string "こいをいゃいフいゃせフはテり,ょゅでちぶ2クイフウィ$$"
	.globl gUnknown_82F3B00
gUnknown_82F3B00: @ 0x82F3B00
	.string "むいらくダせホとがはわやqん♀ぎ:ぢェっぎセ$$"
	.globl gUnknown_82F3B18
gUnknown_82F3B18: @ 0x82F3B18
	.string "むいらいダいらくダせホとがはわよqぇ♀ず:ぼェコぎハ$$"
	.globl gUnknown_82F3B34
gUnknown_82F3B34: @ 0x82F3B34
	.string "むいらいダいホいらくダせホとがはわよqぇ♀ず:エェホぎギ$$"
	.globl gUnknown_82F3B52
gUnknown_82F3B52: @ 0x82F3B52
	.string "むいアい$$"
	.globl gUnknown_82F3B58
gUnknown_82F3B58: @ 0x82F3B58
	.string "ハいハせ$$"
	.globl gUnknown_82F3B5E
gUnknown_82F3B5E: @ 0x82F3B5E
	.string "スいスとぷはぺふぽほぃやつんたぎざでgっずソ$$"
	.globl gUnknown_82F3B76
gUnknown_82F3B76: @ 0x82F3B76
	.string "りいアい$$"
	.globl gUnknown_82F3B7C
gUnknown_82F3B7C: @ 0x82F3B7C
	.string "ハいハせ$$"
	.globl gUnknown_82F3B82
gUnknown_82F3B82: @ 0x82F3B82
	.string "まいまとヤほるりテぇpざればチっひサ$$"
	.globl gUnknown_82F3B96
gUnknown_82F3B96: @ 0x82F3B96
	.string "むいふこたつツはつよちぇるぜチぺラセ$$"
	.globl gUnknown_82F3BAA
gUnknown_82F3BAA: @ 0x82F3BAA
	.string "むいふいたいふこたつツはつりちょるどチカラネ$$"
	.globl gUnknown_82F3BC2
gUnknown_82F3BC2: @ 0x82F3BC2
	.string "むいふいたいツいふこたつツはつりちょるどチタラワ$$"
	.globl gUnknown_82F3BDC
gUnknown_82F3BDC: @ 0x82F3BDC
	.string "むいらいツせペはヤりpょ1でひウ$$"
	.globl gUnknown_82F3BEE
gUnknown_82F3BEE: @ 0x82F3BEE
	.string "むいらいツいツせペは,りpざ1っひナ$$"
	.globl gUnknown_82F3C02
gUnknown_82F3C02: @ 0x82F3C02
	.string "ぞいをいろせまはpよぴぉラずだぼチカ$$"
	.globl gUnknown_82F3C16
gUnknown_82F3C16: @ 0x82F3C16
	.string "ぞいをいろいまいろせまはpゃラぞだっチセ$$"
	.globl gUnknown_82F3C2C
gUnknown_82F3C2C: @ 0x82F3C2C
	.string "もいろいりたわはグりヌぇぉぞ\n"
	.string "ぼ　ぱ$ぼメク$$"
	.globl gUnknown_82F3C44
gUnknown_82F3C44: @ 0x82F3C44
	.string "もいろいりいわいりたわはグりヌぎぉぴ\n"
	.string "シ　ス$シメミ$$"
	.globl gUnknown_82F3C60
gUnknown_82F3C60: @ 0x82F3C60
	.string "エいをいらしカたツにネほなりオゃチぢキイムト$$"
	.globl gUnknown_82F3C78
gUnknown_82F3C78: @ 0x82F3C78
	.string "エいらいツいオい$$"
	.globl gUnknown_82F3C82
gUnknown_82F3C82: @ 0x82F3C82
	.string "こいマしふにりめ2んゥざボぼぶサOハ$$"
	.globl gUnknown_82F3C96
gUnknown_82F3C96: @ 0x82F3C96
	.string "こいマいふいマしふにりめ2ぃゥぢボエぶノOワ$$"
	.globl gUnknown_82F3CAE
gUnknown_82F3CAE: @ 0x82F3CAE
	.string "をいこいらたねねりめわりせぁボざえぷÖセ$$"
	.globl gUnknown_82F3CC4
gUnknown_82F3CC4: @ 0x82F3CC4
	.string "をいこいらたねねりやわわせゅボでえキÖハ$$"
	.globl gUnknown_82F3CDA
gUnknown_82F3CDA: @ 0x82F3CDA
	.string "こいらいねいりいめん$$"
	.globl gUnknown_82F3CE6
gUnknown_82F3CE6: @ 0x82F3CE6
	.string "ろいぞいヤたねねりめほりせぁまざえぷみセ$$"
	.globl gUnknown_82F3CFC
gUnknown_82F3CFC: @ 0x82F3CFC
	.string "ろいぞいヤたねねりやほわせゅまでえキみハ$$"
	.globl gUnknown_82F3D12
gUnknown_82F3D12: @ 0x82F3D12
	.string "ぞいヤいねいりいゆん$$"
	.globl gUnknown_82F3D1E
gUnknown_82F3D1E: @ 0x82F3D1E
	.string "あいをいoこぁつうはこもヒれマぇヨげぢづxぼムイゅサ$$"
	.globl gUnknown_82F3D3A
gUnknown_82F3D3A: @ 0x82F3D3A
	.string "ぁいういヒいヨい$$"
	.globl gUnknown_82F3D44
gUnknown_82F3D44: @ 0x82F3D44
	.string "ゃいらこんつツはおもヘれほぉゅげgぢみぱウイ$$"
	.globl gUnknown_82F3D5C
gUnknown_82F3D5C: @ 0x82F3D5C
	.string "ゃいツいヘいgいウコ$$"
	.globl gUnknown_82F3D68
gUnknown_82F3D68: @ 0x82F3D68
	.string "ぁいマくあつぇふSようぃピげめでニぺぃケよツ$$"
	.globl gUnknown_82F3D80
gUnknown_82F3D80: @ 0x82F3D80
	.string "ぁいぇいマいうい$$"
	.globl gUnknown_82F3D8A
gUnknown_82F3D8A: @ 0x82F3D8A
	.string "ジいぃしょぬわみちれヘゃげぜZぶぅウメシ$$"
	.globl gUnknown_82F3DA0
gUnknown_82F3DA0: @ 0x82F3DA0
	.string "ヌいジいぃいょうぃしょぬわみちれヘぎげびZエぅテメミ$$"
	.globl gUnknown_82F3DBC
gUnknown_82F3DBC: @ 0x82F3DBC
	.string "びいrせぷふぺみぽやぉんxぞっぺ$$"
	.globl gUnknown_82F3DCE
gUnknown_82F3DCE: @ 0x82F3DCE
	.string "びいrいぷいrせぷふぺみぽやぉぃxばっク$$"
	.globl gUnknown_82F3DE4
gUnknown_82F3DE4: @ 0x82F3DE4
	.string "びいぎうぺいぶいっク$$"
	.globl gUnknown_82F3DF0
gUnknown_82F3DF0: @ 0x82F3DF0
	.string "こいぺせぷはジよヅぇ2ずぼぼPカぎテ$$"
	.globl gUnknown_82F3E04
gUnknown_82F3E04: @ 0x82F3E04
	.string "こいぺいぷいぺせぷはジよヅょ2ばぼカPニぎラ$$"
	.globl gUnknown_82F3E1C
gUnknown_82F3E1C: @ 0x82F3E1C
	.string "むいぇいGいぃつスめぷりジぇぺぎざぢぽぶセイ$$"
	.globl gUnknown_82F3E34
gUnknown_82F3E34: @ 0x82F3E34
	.string "ずうむいぇいGいぃいぃつスめぷりジぇぺぎたずざぶぽエセネ$$"
	.globl gUnknown_82F3E52
gUnknown_82F3E52: @ 0x82F3E52
	.string "こいふいをこjつサめCぇ2ぢケイコツ$$"
	.globl gUnknown_82F3E66
gUnknown_82F3E66: @ 0x82F3E66
	.string "0いこいふいをいをこjつサめCぇぶゅ2ぴケニコィ$$"
	.globl gUnknown_82F3E80
gUnknown_82F3E80: @ 0x82F3E80
	.incbin "baserom_jp.gba", 0x2f3e80, 0x14
	.globl gUnknown_82F3E94
gUnknown_82F3E94: @ 0x82F3E94
	.incbin "baserom_jp.gba", 0x2f3e94, 0x16
	.globl gUnknown_82F3EAA
gUnknown_82F3EAA: @ 0x82F3EAA
	.string "コうこいらこぇとスみヌんäずボっぎト$$"
	.globl gUnknown_82F3EBE
gUnknown_82F3EBE: @ 0x82F3EBE
	.string "コうこいらいぇいらこぇとスみヌんäずボクぎヤ$$"
	.globl gUnknown_82F3ED6
gUnknown_82F3ED6: @ 0x82F3ED6
	.string "こいろいづついほボれヤょどぢzぺヌコゆニ$$"
	.globl gUnknown_82F3EEC
gUnknown_82F3EEC: @ 0x82F3EEC
	.string "こいろいづいテいづついほボれヤょテぎどぶzコヌフゆン$$"
	.globl gUnknown_82F3F08
gUnknown_82F3F08: @ 0x82F3F08
	.string "わいんいゃせろはざらやぇ？ずせぱチカゅツ$$"
	.globl gUnknown_82F3F1E
gUnknown_82F3F1E: @ 0x82F3F1E
	.string "わいんいゃいざうöツ$$"
	.globl gUnknown_82F3F2A
gUnknown_82F3F2A: @ 0x82F3F2A
	.string "ダいソせがはうよ:ぇめずAぼぎカ$$"
	.globl gUnknown_82F3F3C
gUnknown_82F3F3C: @ 0x82F3F3C
	.string "ダいソいがいソせがはうよ:ょめばAカぎニ$$"
	.globl gUnknown_82F3F52
gUnknown_82F3F52: @ 0x82F3F52
	.string "がいソいういぢいぢば9ニ$$"
	.globl gUnknown_82F3F60
gUnknown_82F3F60: @ 0x82F3F60
	.string "トい$$"
	.globl gUnknown_82F3F64
gUnknown_82F3F64: @ 0x82F3F64
	.incbin "baserom_jp.gba", 0x2f3f64, 0x1a
	.globl gUnknown_82F3F7E
gUnknown_82F3F7E: @ 0x82F3F7E
	.incbin "baserom_jp.gba", 0x2f3f7e, 0x1a
	.globl gUnknown_82F3F98
gUnknown_82F3F98: @ 0x82F3F98
	.string "づいろいヤせいはどよGわぬぉuずぢぼzっ,カkツ$$"
	.globl gUnknown_82F3FB2
gUnknown_82F3FB2: @ 0x82F3FB2
	.string "づいろいヤいヤせいはどよGわぬぉuぢぢイzシ,ニkヨ$$"
	.globl gUnknown_82F3FCE
gUnknown_82F3FCE: @ 0x82F3FCE
	.string "づいろいヤいヤせいはどよGわぬぉuぢぢイzシ,ニkヨ$$"
	.globl gUnknown_82F3FEA
gUnknown_82F3FEA: @ 0x82F3FEA
	.string "にいぼしもにぽほぷめぺよぉんrざぱぼなコ$$"
	.globl gUnknown_82F4000
gUnknown_82F4000: @ 0x82F4000
	.string "にいぼいもいぼしもにぽほぷめぺよぉぃrぢぱエなフ$$"
	.globl gUnknown_82F401A
gUnknown_82F401A: @ 0x82F401A
	.string "にいぽいrいぱい$$"
	.globl gUnknown_82F4024
gUnknown_82F4024: @ 0x82F4024
	.string "りいぃしャねぉよじぇもざミぶヌカぎツ$$"
	.globl gUnknown_82F4038
gUnknown_82F4038: @ 0x82F4038
	.string "りいぃいャいぃしャねぉよじぇもざミぴヌセぎホ$$"
	.globl gUnknown_82F4050
gUnknown_82F4050: @ 0x82F4050
	.string "むいマいわすクにjみリれSゃセぜケぶベイよシ$$"
	.globl gUnknown_82F4068
gUnknown_82F4068: @ 0x82F4068
	.string "むいマいわうクいわすクにjみリれSげセぱケコベハよワ$$"
	.globl gUnknown_82F4084
gUnknown_82F4084: @ 0x82F4084
	.string "むいマいわうクいわすクにjみリれSげセぱケコベハよワ$$"
	.globl gUnknown_82F40A0
gUnknown_82F40A0: @ 0x82F40A0
	.string "むいをこらつゃふぬよウぇやずチぴエサンハ$$"
	.globl gUnknown_82F40B6
gUnknown_82F40B6: @ 0x82F40B6
	.string "むいをいらいゃいをこらつゃふぬよウぇやずチぴまっエナンン$$"
	.globl gUnknown_82F40D4
gUnknown_82F40D4: @ 0x82F40D4
	.string "ーいのうむいをしがほスりぇげへでュカセタ$$"
	.globl gUnknown_82F40EA
gUnknown_82F40EA: @ 0x82F40EA
	.string "ーいのうむいをいをしがほスりぇげへでホぼュシセフ$$"
	.globl gUnknown_82F4104
gUnknown_82F4104: @ 0x82F4104
	.string "ぜうむいエしぃにぅみカれWゃMぞゥぴヌクFト$$"
	.globl gUnknown_82F411C
gUnknown_82F411C: @ 0x82F411C
	.string "ぜうむいエいぃいエしぃにぅみカれWゃMば0クヌハFワ$$"
	.globl gUnknown_82F4138
gUnknown_82F4138: @ 0x82F4138
	.string "ぞいふしろにまみはろXゃせずチぶ2イTシ$$"
	.globl gUnknown_82F414E
gUnknown_82F414E: @ 0x82F414E
	.incbin "baserom_jp.gba", 0x2f414e, 0x14
	.globl gUnknown_82F4162
gUnknown_82F4162: @ 0x82F4162
	.incbin "baserom_jp.gba", 0x2f4162, 0x18
	.globl gUnknown_82F417A
gUnknown_82F417A: @ 0x82F417A
	.string "へいをつJめずれピげやぼげイgツ$$"
	.globl gUnknown_82F418C
gUnknown_82F418C: @ 0x82F418C
	.string "へいをいJいずいをつJめずれピげべどやエげニgィ$$"
	.globl gUnknown_82F41A6
gUnknown_82F41A6: @ 0x82F41A6
	.string "ゴいあいハくぇたワはヒよヌゃビでBカかヒ$$"
	.globl gUnknown_82F41BC
gUnknown_82F41BC: @ 0x82F41BC
	.string "ゴいあいハいハくぇたワはヒよヌゃビでBセかロ$$"
	.globl gUnknown_82F41D4
gUnknown_82F41D4: @ 0x82F41D4
	.string "むいホいぃつずめ♀ぇろぢィイげツ$$"
	.globl gUnknown_82F41E6
gUnknown_82F41E6: @ 0x82F41E6
	.string "ホいぃいずい♀いEぢォイ$$"
	.globl gUnknown_82F41F4
gUnknown_82F41F4: @ 0x82F41F4
	.string "ソいレい'たZはーみナれヘぎゲぢHぶ$$"
	.globl gUnknown_82F4208
gUnknown_82F4208: @ 0x82F4208
	.string "ソいレい'い'たZはーみナれどぉヘずゲぺHタ$$"
	.globl gUnknown_82F4220
gUnknown_82F4220: @ 0x82F4220
	.string "ソいレい'い'たZはーみナれどぉヘずゲぺHタ$$"
	.globl gUnknown_82F4238
gUnknown_82F4238: @ 0x82F4238
	.string "むいヌいとつクはハれテぇOぢなぼsコぶテよメ$$"
	.globl gUnknown_82F4250
gUnknown_82F4250: @ 0x82F4250
	.incbin "baserom_jp.gba", 0x2f4250, 0x16
	.globl gUnknown_82F4266
gUnknown_82F4266: @ 0x82F4266
	.incbin "baserom_jp.gba", 0x2f4266, 0x1a
	.globl gUnknown_82F4280
gUnknown_82F4280: @ 0x82F4280
	.string "ダいろこさねハみオぁぬょしで♀イブコ$$"
	.globl gUnknown_82F4294
gUnknown_82F4294: @ 0x82F4294
	.string "ダいろいさいろこさねハみオぁぬょしぴ♀ツブメ$$"
	.globl gUnknown_82F42AC
gUnknown_82F42AC: @ 0x82F42AC
	.string "しうむいヌたぅほWれリょSぞムぼゥエベシÜツ$$"
	.globl gUnknown_82F42C4
gUnknown_82F42C4: @ 0x82F42C4
	.string "しうむいヌいぅいヌたぅほWれリょSでムイゥタベフÜヨ$$"
	.globl gUnknown_82F42E0
gUnknown_82F42E0: @ 0x82F42E0
	.string "ザい{B_COPY_VAR_1}ソいモせべはスよぺぇぷずぽぼぴカ$$"
	.globl gUnknown_82F42F6
gUnknown_82F42F6: @ 0x82F42F6
	.string "ザいソいスいぬよルず$$"
	.globl gUnknown_82F4302
gUnknown_82F4302: @ 0x82F4302
	.string "をいらこヲつへはろめヤれパぇテげTぢゆぼLイよコ$$"
	.globl gUnknown_82F431C
gUnknown_82F431C: @ 0x82F431C
	.string "をいらいヲいへいらこヲつへはろめヤれパぇテぞTぺゆシLハよレ$$"
	.globl gUnknown_82F433C
gUnknown_82F433C: @ 0x82F433C
	.string "ぬうねいタしひにはみねるヤれギゃ9ずGぶQイのシ‘ニ$$"
	.globl gUnknown_82F4358
gUnknown_82F4358: @ 0x82F4358
	.string "ぬうえいチせpは¥りけゃくゃきゃびだおぴKクでト$$"
	.globl gUnknown_82F4372
gUnknown_82F4372: @ 0x82F4372
	.string "レいぃせマねはゆぬんもげぇでなっヌコまヌ$$"
	.globl gUnknown_82F4388
gUnknown_82F4388: @ 0x82F4388
	.string "ゴいむいロつリめワれフぇメぢベイHコかテ$$"
	.globl gUnknown_82F439E
gUnknown_82F439E: @ 0x82F439E
	.string "ゴいむいロいリいロつリめワれフぇメぢベクHニかユ$$"
	.globl gUnknown_82F43B8
gUnknown_82F43B8: @ 0x82F43B8
	.string "ほいらいぬとまほ,ぃセごみぴやカケネlメ$$"
	.globl gUnknown_82F43CE
gUnknown_82F43CE: @ 0x82F43CE
	.string "ほいらいぬいまいぬとまほ,ぃセごみぴやシケヤlャ$$"
	.globl gUnknown_82F43E8
gUnknown_82F43E8: @ 0x82F43E8
	.string "あいをいらこまてガはうめヒんぁげルばマイムツよメ$$"
	.globl gUnknown_82F4402
gUnknown_82F4402: @ 0x82F4402
	.string "てうャいぽくびとぼはぷよにわとぎぶずぺぼなっだス$$"
	.globl gUnknown_82F441C
gUnknown_82F441C: @ 0x82F441C
	.incbin "baserom_jp.gba", 0x2f441c, 0x16
	.globl gUnknown_82F4432
gUnknown_82F4432: @ 0x82F4432
	.string "ダいフたろほがわ▶げチぶぎカスナ$$"
	.globl gUnknown_82F4444
gUnknown_82F4444: @ 0x82F4444
	.string "ダいフいろいがいフたろほがわ▶げチっぎニスヲ$$"
	.globl gUnknown_82F445C
gUnknown_82F445C: @ 0x82F445C
	.string "ぞいらいコうぃとほほ·ぃまげァぴみカチネ$$"
	.globl gUnknown_82F4472
gUnknown_82F4472: @ 0x82F4472
	.string "ぞいらいコうぃいぃとほほ·ぃまげァイみツチレ$$"
	.globl gUnknown_82F448A
gUnknown_82F448A: @ 0x82F448A
	.string "むいハいがしqとノほゆらゥぃじぎヒぢムぼぢオぎシ$$"
	.globl gUnknown_82F44A4
gUnknown_82F44A4: @ 0x82F44A4
	.string "がいqいノいゥいヘぢ$$"
	.globl gUnknown_82F44B0
gUnknown_82F44B0: @ 0x82F44B0
	.string "ミいスこ3つタはうめムれモれoぇざげにづそぱたウセコnツgハ$$"
	.globl gUnknown_82F44D0
gUnknown_82F44D0: @ 0x82F44D0
	.string "ツいろいヤしpにTみチれちゃ2ずせぶネイXシ$$"
	.globl gUnknown_82F44E8
gUnknown_82F44E8: @ 0x82F44E8
	.string "あいレいズい♂いズつ♂はうれくぇZばぐウめニIメごョ$$"
	.globl gUnknown_82F4504
gUnknown_82F4504: @ 0x82F4504
	.string "ツいろいけいけつムめゥぇヌぶオセキヤ$$"
	.globl gUnknown_82F4518
gUnknown_82F4518: @ 0x82F4518
	.string "ゃいろいロいきいろせロはきよフぇÄぢゅイヘツンメ$$"
	.globl gUnknown_82F4532
gUnknown_82F4532: @ 0x82F4532
	.string "さいヤいとせどはハよぬぉねぜしぼぢカせツ$$"
	.globl gUnknown_82F4548
gUnknown_82F4548: @ 0x82F4548
	.string "むいらくテたほは,よpゃピでゆカやハ$$"
	.globl gUnknown_82F455C
gUnknown_82F455C: @ 0x82F455C
	.string "バいむほ·ざ$$"
	.globl gUnknown_82F4564
gUnknown_82F4564: @ 0x82F4564
	.string "ゆいわりイぇろざ▶ばぎっ:コスナぜホ$$"
	.globl gUnknown_82F4578
gUnknown_82F4578: @ 0x82F4578
	.string "がいをいぁいょせめはヘよIぇげず:ぼgカぎツべマ$$"
	.globl gUnknown_82F4592
gUnknown_82F4592: @ 0x82F4592
	.string "ゾい$$"
	.globl gUnknown_82F4596
gUnknown_82F4596: @ 0x82F4596
	.string "むいらいせうふたをみツんわざnぶやエ$$"
	.globl gUnknown_82F45AA
gUnknown_82F45AA: @ 0x82F45AA
	.string "むいらいせうふたがみツんわざずぶメエビセぎネ$$"
	.globl gUnknown_82F45C2
gUnknown_82F45C2: @ 0x82F45C2
	.string "むいらいせうふたエみツんねざれぶカエチセキネ$$"
	.globl gUnknown_82F45DA
gUnknown_82F45DA: @ 0x82F45DA
	.string "むいらいせうふたゃみツんわざウぶロエろセゅネ$$"
	.globl gUnknown_82F45F2
gUnknown_82F45F2: @ 0x82F45F2
	.string "⋯いむいッいチつざねノりポぃMぞ0ぶにケFタ$$"
	.globl gUnknown_82F460A
gUnknown_82F460A: @ 0x82F460A
	.string "ャいホいわはがよオぉろず♀ぼだキüツぎホ$$"
	.globl gUnknown_82F4620
gUnknown_82F4620: @ 0x82F4620
	.string "ャいホいわいわはがよオぉろず♀ぼォっだスüホぎェ$$"
	.globl gUnknown_82F463A
gUnknown_82F463A: @ 0x82F463A
	.string "こいハいびはろよオぉふずQぼぜキぶツüホ$$"
	.globl gUnknown_82F4650
gUnknown_82F4650: @ 0x82F4650
	.string "こいハいびいびはろよオぉふずQぼ2っぜスぶホüェ$$"
	.globl gUnknown_82F466A
gUnknown_82F466A: @ 0x82F466A
	.string "ちいチたわほぃわüげ,ぶやカぜト$$"
	.globl gUnknown_82F467C
gUnknown_82F467C: @ 0x82F467C
	.string "むいュしマとAほへよのぅピぎ。ぎめぢぽぱキオSシぜニ$$"
	.globl gUnknown_82F4698
gUnknown_82F4698: @ 0x82F4698
	.string "たい♂いょはチぇ9ぼげツモレごヂべ！$$"
	.globl gUnknown_82F46AC
gUnknown_82F46AC: @ 0x82F46AC
	.string "ぞいエいカはチぇKぼだツしロムヂキ9$$"
	.globl gUnknown_82F46C0
gUnknown_82F46C0: @ 0x82F46C0
	.string "ちいゃいウはチぇQぼゅツgレあヅゼ9$$"
	.globl gUnknown_82F46D4
gUnknown_82F46D4: @ 0x82F46D4
	.string "もいろいカた▶ほイわなげチぶgカNトぜメ$$"
	.globl gUnknown_82F46EA
gUnknown_82F46EA: @ 0x82F46EA
	.string "もいろいカい▶いカた▶ほイわなげチぴgセNミぜェ$$"
	.globl gUnknown_82F4704
gUnknown_82F4704: @ 0x82F4704
	.string "もいろいカい▶いカた▶ほイわなげチぴgセちホNレぜバ$$"
	.globl gUnknown_82F4720
gUnknown_82F4720: @ 0x82F4720
	.incbin "baserom_jp.gba", 0x2f4720, 0x18
	.globl gUnknown_82F4738
gUnknown_82F4738: @ 0x82F4738
	.string "あいゾとおりヨざセっüト$$"
	.globl gUnknown_82F4746
gUnknown_82F4746: @ 0x82F4746
	.string "むいをいぱたモねぷほwわめげムぶgカぴト$$"
	.globl gUnknown_82F475C
gUnknown_82F475C: @ 0x82F475C
	.string "むいをいぱいモいぱたモねぷほwんめずムぺgセぴホ$$"
	.globl gUnknown_82F4776
gUnknown_82F4776: @ 0x82F4776
	.string "むいをいぱいモいぱたモねぷほwんめずムイgニぴレ$$"
	.globl gUnknown_82F4790
gUnknown_82F4790: @ 0x82F4790
	.string "むいろいフしゃねツよ？ょゥぶゅシ$$"
	.globl gUnknown_82F47A2
gUnknown_82F47A2: @ 0x82F47A2
	.string "むいろいフいフしゃねツれ？ずゥエゅフ$$"
	.globl gUnknown_82F47B6
gUnknown_82F47B6: @ 0x82F47B6
	.string "むいろいフいゃいフしゃねツれ？ずゥコゅリ$$"
	.globl gUnknown_82F47CC
gUnknown_82F47CC: @ 0x82F47CC
	.string "こいろいテせがはわり,ょ2ばヌカぎネ$$"
	.globl gUnknown_82F47E0
gUnknown_82F47E0: @ 0x82F47E0
	.string "こいろいテいテせがはわれ,ぎ2ぼヌコぎホ$$"
	.globl gUnknown_82F47F6
gUnknown_82F47F6: @ 0x82F47F6
	.string "こいろいテいがいテせがはわれ,ぎ2ぴヌセぎヤ$$"
	.globl gUnknown_82F480E
gUnknown_82F480E: @ 0x82F480E
	.string "こいマくツせボねせもなぃこぜピっュツ$$"
	.globl gUnknown_82F4822
gUnknown_82F4822: @ 0x82F4822
	.string "こいマいツいマくツせボねせらなぎこぱピタュヨ$$"
	.globl gUnknown_82F483A
gUnknown_82F483A: @ 0x82F483A
	.string "むいをいGしぞにソみモわやぎスでゲタ$$"
	.globl gUnknown_82F484E
gUnknown_82F484E: @ 0x82F484E
	.string "むいをいGいぞいGしぞにソみモぇやぢスイゲメ$$"
	.globl gUnknown_82F4866
gUnknown_82F4866: @ 0x82F4866
	.string "むいぃたえほムわモわgわnげゥぶチカよト$$"
	.globl gUnknown_82F487C
gUnknown_82F487C: @ 0x82F487C
	.string "むいぃいぃたえほムぃモぃgぃnぢゥエチニよリ$$"
	.globl gUnknown_82F4894
gUnknown_82F4894: @ 0x82F4894
	.string "りいアい,しャにナめジんボざ8ぼチコセハ$$"
	.globl gUnknown_82F48AA
gUnknown_82F48AA: @ 0x82F48AA
	.string "りいアい,いャい,しャにナめジぇボで8カチハセン$$"
	.globl gUnknown_82F48C4
gUnknown_82F48C4: @ 0x82F48C4
	.string "ヌいジいぃいょうぃしょぬわみちれヘぎげびZエぅテメミ$$"
	.globl gUnknown_82F48E0
gUnknown_82F48E0: @ 0x82F48E0
	.string "ダいカいぃこ·はがめWぇヘげやぼぎイしテ$$"
	.globl gUnknown_82F48F6
gUnknown_82F48F6: @ 0x82F48F6
	.string "ダいカいぃいぃこ·はがめWぇヘぞやカぎトしロ$$"
	.globl gUnknown_82F490E
gUnknown_82F490E: @ 0x82F490E
	.string "エいRいらしカた/に$$"
	.globl gUnknown_82F491A
gUnknown_82F491A: @ 0x82F491A
	.string "あいRいoくぁた/は$$"
	.globl gUnknown_82F4926
gUnknown_82F4926: @ 0x82F4926
	.string "ぁいRいマくあつ/ふ$$"
	.globl gUnknown_82F4932
gUnknown_82F4932: @ 0x82F4932
	.string "をいRいヨし/にのむoれこゅちぜgぶよイ$$"
	.globl gUnknown_82F4948
gUnknown_82F4948: @ 0x82F4948
	.string "をいRいヨし/にのむoれこゅちぜgぶよイ$$"
	.globl gUnknown_82F495E
gUnknown_82F495E: @ 0x82F495E
	.incbin "baserom_jp.gba", 0x2f495e, 0x12
	.globl gUnknown_82F4970
gUnknown_82F4970: @ 0x82F4970
	.incbin "baserom_jp.gba", 0x2f4970, 0x12
	.globl gUnknown_82F4982
gUnknown_82F4982: @ 0x82F4982
	.string "むいをいエつカみ”んムざキぼ$$"
	.globl gUnknown_82F4992
gUnknown_82F4992: @ 0x82F4992
	.string "むいをいエいエつカや”ょムぶキコ$$"
	.globl gUnknown_82F49A4
gUnknown_82F49A4: @ 0x82F49A4
	.string "むいをいエいカいエつカや”ょけざムエキメ$$"
	.globl gUnknown_82F49BA
gUnknown_82F49BA: @ 0x82F49BA
	.string "びいrいぺいケうっクぴホ$$"
	.globl gUnknown_82F49C8
gUnknown_82F49C8: @ 0x82F49C8
	.string "むいマからしがとSほじれよぎ:ぶぎコ$$"
	.globl gUnknown_82F49DC
gUnknown_82F49DC: @ 0x82F49DC
	.string "むいマいらいがいマからしがとSほじぃよで:コぎメ$$"
	.globl gUnknown_82F49F6
gUnknown_82F49F6: @ 0x82F49F6
	.string "クいニい·つづめプぇぽづ×イなツよメ$$"
	.globl gUnknown_82F4A0A
gUnknown_82F4A0A: @ 0x82F4A0A
	.string "がいソいういIいIばUニ$$"
	.globl gUnknown_82F4A18
gUnknown_82F4A18: @ 0x82F4A18
	.string "バいwこらこむとぷはぺほぽめべり”ぇぶざ$$"
	.globl gUnknown_82F4A2E
gUnknown_82F4A2E: @ 0x82F4A2E
	.string "バいwいらいむいwこらこむとぷはぺほぽめべわ”げぶぶ$$"
	.globl gUnknown_82F4A4A
gUnknown_82F4A4A: @ 0x82F4A4A
	.string "バいwいらいむいwこらこむとぷはぺほぽめべわ”ぢぶク$$"
	.globl gUnknown_82F4A66
gUnknown_82F4A66: @ 0x82F4A66
	.string "こいらいふしょひnやだぉボずゥぴヌカチト$$"
	.globl gUnknown_82F4A7C
gUnknown_82F4A7C: @ 0x82F4A7C
	.string "びいぼしぶはてゆひぉÄざwぼPエ$$"
	.globl gUnknown_82F4A8E
gUnknown_82F4A8E: @ 0x82F4A8E
	.string "びいあいぼしぱはてゆぱぉÄざっぼぴエ$$"
	.globl gUnknown_82F4AA2
gUnknown_82F4AA2: @ 0x82F4AA2
	.incbin "baserom_jp.gba", 0x2f4aa2, 0x16
