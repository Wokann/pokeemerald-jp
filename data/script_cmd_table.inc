	.ifndef SCRIPT_CMD_TABLE_ENTRY_MACRO
	.set SCRIPT_CMD_TABLE_ENTRY_MACRO, 1
	.macro script_cmd_table_entry constant:req, value:req
	.if ALLOCATE_SCRIPT_CMD_TABLE
	.4byte \value
	.else
	enum \constant
	.endif
	.endm
	.endif


	enum_start
	.if ALLOCATE_SCRIPT_CMD_TABLE
	.align 2
	.globl gScriptCmdTable
gScriptCmdTable:
	.endif
	script_cmd_table_entry SCR_OP_NOP ScrCmd_nop @ 0x00
	script_cmd_table_entry SCR_OP_SETWORLDMAPFLAG ScrCmd_nop1 @ 0x01
	script_cmd_table_entry SCR_OP_END ScrCmd_end @ 0x02
	script_cmd_table_entry SCR_OP_RETURN ScrCmd_return @ 0x03
	script_cmd_table_entry SCR_OP_CALL ScrCmd_call @ 0x04
	script_cmd_table_entry SCR_OP_GOTO ScrCmd_goto @ 0x05
	script_cmd_table_entry SCR_OP_GOTO_IF ScrCmd_goto_if @ 0x06
	script_cmd_table_entry SCR_OP_CALL_IF ScrCmd_call_if @ 0x07
	script_cmd_table_entry SCR_OP_GOTO_STD ScrCmd_gotostd @ 0x08
	script_cmd_table_entry SCR_OP_CALL_STD ScrCmd_callstd @ 0x09
	script_cmd_table_entry SCR_OP_GOTO_STD_IF ScrCmd_gotostd_if @ 0x0A
	script_cmd_table_entry SCR_OP_CALL_STD_IF ScrCmd_callstd_if @ 0x0B
	script_cmd_table_entry SCR_OP_RETURNRAM ScrCmd_returnram @ 0x0C
	script_cmd_table_entry SCR_OP_0D ScrCmd_endram @ 0x0D
	script_cmd_table_entry SCR_OP_SETMYSTERYEVENTSTATUS ScrCmd_setmysteryeventstatus @ 0x0E
	script_cmd_table_entry SCR_OP_LOAD_WORD ScrCmd_loadword @ 0x0F
	script_cmd_table_entry SCR_OP_LOAD_BYTE ScrCmd_loadbyte @ 0x10
	script_cmd_table_entry SCR_OP_11 ScrCmd_setptr @ 0x11
	script_cmd_table_entry SCR_OP_12 ScrCmd_loadbytefromptr @ 0x12
	script_cmd_table_entry SCR_OP_SETPTRBYTE ScrCmd_setptrbyte @ 0x13
	script_cmd_table_entry SCR_OP_COPYLOCAL ScrCmd_copylocal @ 0x14
	script_cmd_table_entry SCR_OP_COPYBYTE ScrCmd_copybyte @ 0x15
	script_cmd_table_entry SCR_OP_SETVAR ScrCmd_setvar @ 0x16
	script_cmd_table_entry SCR_OP_ADDVAR ScrCmd_addvar @ 0x17
	script_cmd_table_entry SCR_OP_SUBVAR ScrCmd_subvar @ 0x18
	script_cmd_table_entry SCR_OP_COPYVAR ScrCmd_copyvar @ 0x19
	script_cmd_table_entry SCR_OP_SETORCOPYVAR ScrCmd_setorcopyvar @ 0x1A
	script_cmd_table_entry SCR_OP_COMPARE_LOCAL_TO_LOCAL ScrCmd_compare_local_to_local @ 0x1B
	script_cmd_table_entry SCR_OP_COMPARE_LOCAL_TO_VALUE ScrCmd_compare_local_to_value @ 0x1C
	script_cmd_table_entry SCR_OP_1D ScrCmd_compare_local_to_ptr @ 0x1D
	script_cmd_table_entry SCR_OP_1E ScrCmd_compare_ptr_to_local @ 0x1E
	script_cmd_table_entry SCR_OP_1F ScrCmd_compare_ptr_to_value @ 0x1F
	script_cmd_table_entry SCR_OP_20 ScrCmd_compare_ptr_to_ptr @ 0x20
	script_cmd_table_entry SCR_OP_COMPARE_VAR_TO_VALUE ScrCmd_compare_var_to_value @ 0x21
	script_cmd_table_entry SCR_OP_COMPARE_VAR_TO_VAR ScrCmd_compare_var_to_var @ 0x22
	script_cmd_table_entry SCR_OP_CALLNATIVE ScrCmd_callnative @ 0x23
	script_cmd_table_entry SCR_OP_GOTONATIVE ScrCmd_gotonative @ 0x24
	script_cmd_table_entry SCR_OP_SPECIAL ScrCmd_special @ 0x25
	script_cmd_table_entry SCR_OP_SPECIALVAR ScrCmd_specialvar @ 0x26
	script_cmd_table_entry SCR_OP_WAITSTATE ScrCmd_waitstate @ 0x27
	script_cmd_table_entry SCR_OP_DELAY ScrCmd_delay @ 0x28
	script_cmd_table_entry SCR_OP_SETFLAG ScrCmd_setflag @ 0x29
	script_cmd_table_entry SCR_OP_CLEARFLAG ScrCmd_clearflag @ 0x2A
	script_cmd_table_entry SCR_OP_CHECKFLAG ScrCmd_checkflag @ 0x2B
	script_cmd_table_entry SCR_OP_INITCLOCK ScrCmd_initclock @ 0x2C
	script_cmd_table_entry SCR_OP_DOTIMEBASEDEVENTS ScrCmd_dotimebasedevents @ 0x2D
	script_cmd_table_entry SCR_OP_GETTIME ScrCmd_gettime @ 0x2E
	script_cmd_table_entry SCR_OP_PLAYSE ScrCmd_playse @ 0x2F
	script_cmd_table_entry SCR_OP_WAITSE ScrCmd_waitse @ 0x30
	script_cmd_table_entry SCR_OP_PLAYFANFARE ScrCmd_playfanfare @ 0x31
	script_cmd_table_entry SCR_OP_WAITFANFARE ScrCmd_waitfanfare @ 0x32
	script_cmd_table_entry SCR_OP_PLAYBGM ScrCmd_playbgm @ 0x33
	script_cmd_table_entry SCR_OP_SAVEBGM ScrCmd_savebgm @ 0x34
	script_cmd_table_entry SCR_OP_FADEDEFAULTBGM ScrCmd_fadedefaultbgm @ 0x35
	script_cmd_table_entry SCR_OP_FADENEWBGM ScrCmd_fadenewbgm @ 0x36
	script_cmd_table_entry SCR_OP_FADEOUTBGM ScrCmd_fadeoutbgm @ 0x37
	script_cmd_table_entry SCR_OP_FADEINBGM ScrCmd_fadeinbgm @ 0x38
	script_cmd_table_entry SCR_OP_WARP ScrCmd_warp @ 0x39
	script_cmd_table_entry SCR_OP_WARPSILENT ScrCmd_warpsilent @ 0x3A
	script_cmd_table_entry SCR_OP_WARPDOOR ScrCmd_warpdoor @ 0x3B
	script_cmd_table_entry SCR_OP_WARPHOLE ScrCmd_warphole @ 0x3C
	script_cmd_table_entry SCR_OP_WARPTELEPORT ScrCmd_warpteleport @ 0x3D
	script_cmd_table_entry SCR_OP_SETWARP ScrCmd_setwarp @ 0x3E
	script_cmd_table_entry SCR_OP_SETDYNAMICWARP ScrCmd_setdynamicwarp @ 0x3F
	script_cmd_table_entry SCR_OP_SETDIVEWARP ScrCmd_setdivewarp @ 0x40
	script_cmd_table_entry SCR_OP_SETHOLEWARP ScrCmd_setholewarp @ 0x41
	script_cmd_table_entry SCR_OP_GETPLAYERXY ScrCmd_getplayerxy @ 0x42
	script_cmd_table_entry SCR_OP_GETPARTYSIZE ScrCmd_getpartysize @ 0x43
	script_cmd_table_entry SCR_OP_ADDITEM ScrCmd_additem @ 0x44
	script_cmd_table_entry SCR_OP_REMOVEITEM ScrCmd_removeitem @ 0x45
	script_cmd_table_entry SCR_OP_CHECKITEMSPACE ScrCmd_checkitemspace @ 0x46
	script_cmd_table_entry SCR_OP_CHECKITEM ScrCmd_checkitem @ 0x47
	script_cmd_table_entry SCR_OP_CHECKITEMTYPE ScrCmd_checkitemtype @ 0x48
	script_cmd_table_entry SCR_OP_ADDPCITEM ScrCmd_addpcitem @ 0x49
	script_cmd_table_entry SCR_OP_CHECKPCITEM ScrCmd_checkpcitem @ 0x4A
	script_cmd_table_entry SCR_OP_ADDDECORATION ScrCmd_adddecoration @ 0x4B
	script_cmd_table_entry SCR_OP_REMOVEDECORATION ScrCmd_removedecoration @ 0x4C
	script_cmd_table_entry SCR_OP_CHECKDECOR ScrCmd_checkdecor @ 0x4D
	script_cmd_table_entry SCR_OP_CHECKDECORSPACE ScrCmd_checkdecorspace @ 0x4E
	script_cmd_table_entry SCR_OP_APPLYMOVEMENT ScrCmd_applymovement @ 0x4F
	script_cmd_table_entry SCR_OP_50 ScrCmd_applymovement_at @ 0x50
	script_cmd_table_entry SCR_OP_WAITMOVEMENT ScrCmd_waitmovement @ 0x51
	script_cmd_table_entry SCR_OP_52 ScrCmd_waitmovement_at @ 0x52
	script_cmd_table_entry SCR_OP_REMOVEOBJECT ScrCmd_removeobject @ 0x53
	script_cmd_table_entry SCR_OP_54 ScrCmd_removeobject_at @ 0x54
	script_cmd_table_entry SCR_OP_ADDOBJECT ScrCmd_addobject @ 0x55
	script_cmd_table_entry SCR_OP_56 ScrCmd_addobject_at @ 0x56
	script_cmd_table_entry SCR_OP_SETOBJECTXY ScrCmd_setobjectxy @ 0x57
	script_cmd_table_entry SCR_OP_58 ScrCmd_showobject_at @ 0x58
	script_cmd_table_entry SCR_OP_59 ScrCmd_hideobject_at @ 0x59
	script_cmd_table_entry SCR_OP_FACEPLAYER ScrCmd_faceplayer @ 0x5A
	script_cmd_table_entry SCR_OP_TURNOBJECT ScrCmd_turnobject @ 0x5B
	script_cmd_table_entry SCR_OP_TRAINERBATTLE ScrCmd_trainerbattle @ 0x5C
	script_cmd_table_entry SCR_OP_DOTRAINERBATTLE ScrCmd_dotrainerbattle @ 0x5D
	script_cmd_table_entry SCR_OP_GOTOBEATENSCRIPT ScrCmd_gotobeatenscript @ 0x5E
	script_cmd_table_entry SCR_OP_GOTOPOSTBATTLESCRIPT ScrCmd_gotopostbattlescript @ 0x5F
	script_cmd_table_entry SCR_OP_CHECKTRAINERFLAG ScrCmd_checktrainerflag @ 0x60
	script_cmd_table_entry SCR_OP_SETTRAINERFLAG ScrCmd_settrainerflag @ 0x61
	script_cmd_table_entry SCR_OP_CLEARTRAINERFLAG ScrCmd_cleartrainerflag @ 0x62
	script_cmd_table_entry SCR_OP_SETOBJECTXYPERM ScrCmd_setobjectxyperm @ 0x63
	script_cmd_table_entry SCR_OP_COPYOBJECTXYTOPERM ScrCmd_moveobjectoffscreen @ 0x64
	script_cmd_table_entry SCR_OP_SETOBJECTMOVEMENTTYPE ScrCmd_setobjectmovementtype @ 0x65
	script_cmd_table_entry SCR_OP_WAITMESSAGE ScrCmd_waitmessage @ 0x66
	script_cmd_table_entry SCR_OP_MESSAGE ScrCmd_message @ 0x67
	script_cmd_table_entry SCR_OP_CLOSEMESSAGE ScrCmd_closemessage @ 0x68
	script_cmd_table_entry SCR_OP_LOCKALL ScrCmd_lockall @ 0x69
	script_cmd_table_entry SCR_OP_LOCK ScrCmd_lock @ 0x6A
	script_cmd_table_entry SCR_OP_RELEASEALL ScrCmd_releaseall @ 0x6B
	script_cmd_table_entry SCR_OP_RELEASE ScrCmd_release @ 0x6C
	script_cmd_table_entry SCR_OP_WAITBUTTONPRESS ScrCmd_waitbuttonpress @ 0x6D
	script_cmd_table_entry SCR_OP_YESNOBOX ScrCmd_yesnobox @ 0x6E
	script_cmd_table_entry SCR_OP_MULTICHOICE ScrCmd_multichoice @ 0x6F
	script_cmd_table_entry SCR_OP_MULTICHOICEDEFAULT ScrCmd_multichoicedefault @ 0x70
	script_cmd_table_entry SCR_OP_MULTICHOICEGRID ScrCmd_multichoicegrid @ 0x71
	script_cmd_table_entry SCR_OP_ERASEBOX ScrCmd_erasebox @ 0x72
	script_cmd_table_entry SCR_OP_DRAWBOXTEXT ScrCmd_drawboxtext @ 0x73
	script_cmd_table_entry SCR_OP_74 ScrCmd_mossdeepgym2 @ 0x74
	script_cmd_table_entry SCR_OP_SHOWMONPIC ScrCmd_showmonpic @ 0x75
	script_cmd_table_entry SCR_OP_HIDEMONPIC ScrCmd_hidemonpic @ 0x76
	script_cmd_table_entry SCR_OP_77 ScrCmd_showcontestwinner @ 0x77
	script_cmd_table_entry SCR_OP_BRAILLEMESSAGE ScrCmd_braillemessage @ 0x78
	script_cmd_table_entry SCR_OP_GIVEMON ScrCmd_givemon @ 0x79
	script_cmd_table_entry SCR_OP_GIVEEGG ScrCmd_giveegg @ 0x7A
	script_cmd_table_entry SCR_OP_SETMONMOVE ScrCmd_setmonmove @ 0x7B
	script_cmd_table_entry SCR_OP_CHECKPARTYMOVE ScrCmd_checkpartymove @ 0x7C
	script_cmd_table_entry SCR_OP_BUFFERSPECIESNAME ScrCmd_bufferspeciesname @ 0x7D
	script_cmd_table_entry SCR_OP_BUFFERLEADMONSPECIESNAME ScrCmd_bufferleadmonspeciesname @ 0x7E
	script_cmd_table_entry SCR_OP_BUFFERPARTYMONNICK ScrCmd_bufferpartymonnick @ 0x7F
	script_cmd_table_entry SCR_OP_BUFFERITEMNAME ScrCmd_bufferitemname @ 0x80
	script_cmd_table_entry SCR_OP_BUFFERDECORATIONNAME ScrCmd_bufferdecorationname @ 0x81
	script_cmd_table_entry SCR_OP_BUFFERMOVENAME ScrCmd_buffermovename @ 0x82
	script_cmd_table_entry SCR_OP_BUFFERNUMBERSTRING ScrCmd_buffernumberstring @ 0x83
	script_cmd_table_entry SCR_OP_BUFFERSTDSTRING ScrCmd_bufferstdstring @ 0x84
	script_cmd_table_entry SCR_OP_BUFFERSTRING ScrCmd_bufferstring @ 0x85
	script_cmd_table_entry SCR_OP_POKEMART ScrCmd_pokemart @ 0x86
	script_cmd_table_entry SCR_OP_POKEMARTDECORATION ScrCmd_pokemartdecoration @ 0x87
	script_cmd_table_entry SCR_OP_POKEMARTDECORATION2 ScrCmd_pokemartdecoration2 @ 0x88
	script_cmd_table_entry SCR_OP_PLAYSLOTMACHINE ScrCmd_playslotmachine @ 0x89
	script_cmd_table_entry SCR_OP_SETBERRYTREE ScrCmd_setberrytree @ 0x8A
	script_cmd_table_entry SCR_OP_SHOWCONTESTRESULTS ScrCmd_showcontestresults @ 0x8B
	script_cmd_table_entry SCR_OP_STARTCONTEST ScrCmd_startcontest @ 0x8C
	script_cmd_table_entry SCR_OP_CHOOSECONTESTMON ScrCmd_choosecontestmon @ 0x8D
	script_cmd_table_entry SCR_OP_CONTESTLINKTRANSFER ScrCmd_contestlinktransfer @ 0x8E
	script_cmd_table_entry SCR_OP_RANDOM ScrCmd_random @ 0x8F
	script_cmd_table_entry SCR_OP_90 ScrCmd_givemoney @ 0x90
	script_cmd_table_entry SCR_OP_REMOVEMONEY ScrCmd_takemoney @ 0x91
	script_cmd_table_entry SCR_OP_CHECKMONEY ScrCmd_checkmoney @ 0x92
	script_cmd_table_entry SCR_OP_SHOWMONEYBOX ScrCmd_showmoneybox @ 0x93
	script_cmd_table_entry SCR_OP_HIDEMONEYBOX ScrCmd_hidemoneybox @ 0x94
	script_cmd_table_entry SCR_OP_UPDATEMONEYBOX ScrCmd_updatemoneybox @ 0x95
	script_cmd_table_entry SCR_OP_96 ScrCmd_getpricereduction @ 0x96
	script_cmd_table_entry SCR_OP_FADESCREEN ScrCmd_fadescreen @ 0x97
	script_cmd_table_entry SCR_OP_FADESCREENSPEED ScrCmd_fadescreenspeed @ 0x98
	script_cmd_table_entry SCR_OP_99 ScrCmd_setflashradius @ 0x99
	script_cmd_table_entry SCR_OP_ANIMATEFLASH ScrCmd_animateflash @ 0x9A
	script_cmd_table_entry SCR_OP_MESSAGEAUTOSCROLL ScrCmd_messageautoscroll @ 0x9B
	script_cmd_table_entry SCR_OP_DOFIELDEFFECT ScrCmd_dofieldeffect @ 0x9C
	script_cmd_table_entry SCR_OP_9D ScrCmd_setfieldeffectarg @ 0x9D
	script_cmd_table_entry SCR_OP_WAITFIELDEFFECT ScrCmd_waitfieldeffect @ 0x9E
	script_cmd_table_entry SCR_OP_SETRESPAWN ScrCmd_setrespawn @ 0x9F
	script_cmd_table_entry SCR_OP_CHECKPLAYERGENDER ScrCmd_checkplayergender @ 0xA0
	script_cmd_table_entry SCR_OP_PLAYMONCRY ScrCmd_playmoncry @ 0xA1
	script_cmd_table_entry SCR_OP_SETMETATILE ScrCmd_setmetatile @ 0xA2
	script_cmd_table_entry SCR_OP_DOWEATHER ScrCmd_doweather @ 0xA3
	script_cmd_table_entry SCR_OP_SETWEATHER ScrCmd_setweather @ 0xA4
	script_cmd_table_entry SCR_OP_RESETWEATHER ScrCmd_resetweather @ 0xA5
	script_cmd_table_entry SCR_OP_SETSTEPCALLBACK ScrCmd_setstepcallback @ 0xA6
	script_cmd_table_entry SCR_OP_SETMAPLAYOUTINDEX ScrCmd_setmaplayoutindex @ 0xA7
	script_cmd_table_entry SCR_OP_SETOBJECTSUBPRIORITY ScrCmd_setobjectsubpriority @ 0xA8
	script_cmd_table_entry SCR_OP_RESETOBJECTSUBPRIORITY ScrCmd_resetobjectsubpriority @ 0xA9
	script_cmd_table_entry SCR_OP_CREATEVOBJECT ScrCmd_createvobject @ 0xAA
	script_cmd_table_entry SCR_OP_TURNVOBJECT ScrCmd_turnvobject @ 0xAB
	script_cmd_table_entry SCR_OP_OPENDOOR ScrCmd_opendoor @ 0xAC
	script_cmd_table_entry SCR_OP_CLOSEDOOR ScrCmd_closedoor @ 0xAD
	script_cmd_table_entry SCR_OP_WAITMONCRY ScrCmd_waitmoncry @ 0xAE
	script_cmd_table_entry SCR_OP_SETDOOROPEN ScrCmd_setdooropen @ 0xAF
	script_cmd_table_entry SCR_OP_SETDOORCLOSED ScrCmd_setdoorclosed @ 0xB0
	script_cmd_table_entry SCR_OP_ADDELEVMENUITEM ScrCmd_addelevmenuitem @ 0xB1
	script_cmd_table_entry SCR_OP_DRAWBOX ScrCmd_drawbox @ 0xB2
	script_cmd_table_entry SCR_OP_CHECKCOINS ScrCmd_checkcoins @ 0xB3
	script_cmd_table_entry SCR_OP_B4 ScrCmd_givecoins @ 0xB4
	script_cmd_table_entry SCR_OP_B5 ScrCmd_takecoins @ 0xB5
	script_cmd_table_entry SCR_OP_SETWILDBATTLE ScrCmd_setwildbattle @ 0xB6
	script_cmd_table_entry SCR_OP_DOWILDBATTLE ScrCmd_dowildbattle @ 0xB7
	script_cmd_table_entry SCR_OP_SETVADDRESS ScrCmd_setvaddress @ 0xB8
	script_cmd_table_entry SCR_OP_VGOTO ScrCmd_vgoto @ 0xB9
	script_cmd_table_entry SCR_OP_VCALL ScrCmd_vcall @ 0xBA
	script_cmd_table_entry SCR_OP_VGOTO_IF ScrCmd_vgoto_if @ 0xBB
	script_cmd_table_entry SCR_OP_VCALL_IF ScrCmd_vcall_if @ 0xBC
	script_cmd_table_entry SCR_OP_VMESSAGE ScrCmd_vmessage @ 0xBD
	script_cmd_table_entry SCR_OP_BE ScrCmd_vloadword @ 0xBE
	script_cmd_table_entry SCR_OP_VBUFFERSTRING ScrCmd_vbufferstring @ 0xBF
	script_cmd_table_entry SCR_OP_SHOWCOINSBOX ScrCmd_showcoinsbox @ 0xC0
	script_cmd_table_entry SCR_OP_HIDECOINSBOX ScrCmd_hidecoinsbox @ 0xC1
	script_cmd_table_entry SCR_OP_UPDATECOINSBOX ScrCmd_updatecoinsbox @ 0xC2
	script_cmd_table_entry SCR_OP_INCREMENTGAMESTAT ScrCmd_incrementgamestat @ 0xC3
	script_cmd_table_entry SCR_OP_SETESCAPEWARP ScrCmd_setescapewarp @ 0xC4
	script_cmd_table_entry SCR_OP_WAITDOORANIM ScrCmd_waitdooranim @ 0xC5
	script_cmd_table_entry SCR_OP_BUFFERBOXNAME ScrCmd_bufferboxname @ 0xC6
	script_cmd_table_entry SCR_OP_C7 ScrCmd_nop1 @ 0xC7
	script_cmd_table_entry SCR_OP_C8 ScrCmd_nop1 @ 0xC8
	script_cmd_table_entry SCR_OP_C9 ScrCmd_nop1 @ 0xC9
	script_cmd_table_entry SCR_OP_CA ScrCmd_nop1 @ 0xCA
	script_cmd_table_entry SCR_OP_CB ScrCmd_nop1 @ 0xCB
	script_cmd_table_entry SCR_OP_CC ScrCmd_nop1 @ 0xCC
	script_cmd_table_entry SCR_OP_CD ScrCmd_setmonobedient @ 0xCD
	script_cmd_table_entry SCR_OP_CE ScrCmd_checkmonobedience @ 0xCE
	script_cmd_table_entry SCR_OP_CF ScrCmd_gotoram @ 0xCF
	script_cmd_table_entry SCR_OP_D0 ScrCmd_nop1 @ 0xD0
	script_cmd_table_entry SCR_OP_D1 ScrCmd_warpD1 @ 0xD1
	script_cmd_table_entry SCR_OP_SETMONMETLOCATION ScrCmd_setmonmetlocation @ 0xD2
	@ These five retained JP handler names implement the canonical Emerald
	@ rotating-tile / Mossdeep Gym commands named in script_commands.h.
	script_cmd_table_entry SCR_OP_MOVEROTATINGTILEOBJECTS ScrCmd_mossdeepgym1 @ 0xD3
	script_cmd_table_entry SCR_OP_TURNROTATINGTILEOBJECTS sub_0809B48C @ 0xD4
	script_cmd_table_entry SCR_OP_INITROTATINGTILEPUZZLE ScrCmd_mossdeepgym3 @ 0xD5
	script_cmd_table_entry SCR_OP_FREEROTATINGTILEPUZZLE ScrCmd_buffercontesttype @ 0xD6
	script_cmd_table_entry SCR_OP_WARPMOSSDEEPGYM ScrCmd_warpD7 @ 0xD7
	script_cmd_table_entry SCR_OP_D8 ScrCmd_cmdD8 @ 0xD8
	script_cmd_table_entry SCR_OP_D9 ScrCmd_lockfortrainer @ 0xD9
	script_cmd_table_entry SCR_OP_CLOSEBRAILLEMESSAGE ScrCmd_mossdeepgym4 @ 0xDA
	script_cmd_table_entry SCR_OP_DB ScrCmd_cmdDB @ 0xDB
	script_cmd_table_entry SCR_OP_FADESCREENSWAPBUFFERS ScrCmd_fadescreenswapbuffers @ 0xDC
	script_cmd_table_entry SCR_OP_BUFFERTRAINERCLASSNAME ScrCmd_buffertrainerclassname @ 0xDD
	script_cmd_table_entry SCR_OP_BUFFERTRAINERNAME ScrCmd_buffertrainername @ 0xDE
	script_cmd_table_entry SCR_OP_POKENAVCALL ScrCmd_pokenavcall @ 0xDF
	script_cmd_table_entry SCR_OP_E0 ScrCmd_warpE0 @ 0xE0

	.if ALLOCATE_SCRIPT_CMD_TABLE
	.globl gScriptCmdTableEnd
gScriptCmdTableEnd:
	.globl gUnknown_81DAF30
gUnknown_81DAF30:
	.4byte ScrCmd_nop
	.endif
