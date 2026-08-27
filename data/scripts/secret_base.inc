SecretBase_Text_TreeCanBeClimbed:
	.string "ツルを　おとせば　うえに　のぼれそう$"

SecretBase_Text_TreeUseSecretPower:
	.string "ツルを　おとせば　うえに　のぼれそう\p"
	.string "ひみつのちからを　つかいますか？$"

SecretBase_Text_VineDroppedDown:
	.string "ふといツルが　おちてきた！$"

SecretBase_Text_ClumpOfGrass:
	.string "くさのかたまりを　どければ\n"
	.string "なかへ　はいれそう$"

SecretBase_Text_ClumpUseSecretPower:
	.string "くさのかたまりを　どければ\n"
	.string "なかへ　はいれそう\p"
	.string "ひみつのちからを　つかいますか？$"

SecretBase_Text_DiscoveredSmallEntrance:
	.string "ちいさな　いりぐちを　はっけん！$"

	.include "data/text/secret_base_trainers.inc"

SecretBase_EventScript_CheckEntrance::
	special GetSecretBaseTypeInFrontOfPlayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, TRUE, SecretBase_EventScript_AlreadyHasSecretBase
	checkpartymove MOVE_SECRET_POWER
	setfieldeffectargument 0, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_SECRET_POWER
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_Tree
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_Shrub
	end

SecretBase_EventScript_Cave::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_CaveNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_IndentUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox 0x0825665C, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
	waitstate
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveNoSecretPower::
	msgbox SecretBase_Text_SmallIndentInWall, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_CaveEnter::
	msgbox SecretBase_Text_DiscoveredSmallCavern, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Tree::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_TreeNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_TreeUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox 0x0825665C, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
	waitstate
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeNoSecretPower::
	msgbox SecretBase_Text_TreeCanBeClimbed, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_TreeEnter::
	msgbox SecretBase_Text_VineDroppedDown, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Shrub::
	lockall
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_ShrubNoSecretPower
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox SecretBase_Text_ClumpUseSecretPower, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox 0x0825665C, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubUseSecretPower::
	lockall
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
	waitstate
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubNoSecretPower::
	msgbox SecretBase_Text_ClumpOfGrass, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_ShrubEnter::
	msgbox SecretBase_Text_DiscoveredSmallEntrance, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_InitSecretBase::
	closemessage
	playse SE_EXIT
	setvar VAR_INIT_SECRET_BASE, 0
	setflag FLAG_HIDE_SECRET_BASE_TRAINER
	special SetPlayerSecretBase
	special EnterSecretBase
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	waitstate
	end

SecretBase_EventScript_FirstEntrance::
	applymovement LOCALID_PLAYER, SecretBase_Movement_EnterBase
	waitmovement 0
	setvar VAR_INIT_SECRET_BASE, 1
	msgbox SecretBase_Text_WantToMakeYourSecretBaseHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SecretBase_EventScript_SetAsBase
	closemessage
	playse SE_EXIT
	special ClearAndLeaveSecretBase
	end

SecretBase_EventScript_SetAsBase::
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	special EnterNewlyCreatedSecretBase
	end

SecretBase_Movement_EnterBase:
	walk_up
	walk_up
	step_end

SecretBase_EventScript_Enter::
	lockall
	setvar VAR_INIT_SECRET_BASE, 1
	playse SE_EXIT
	special IsCurSecretBaseOwnedByAnotherPlayer
	goto_if_eq VAR_RESULT, FALSE, SecretBase_EventScript_EnterPlayersBase
	clearflag FLAG_HIDE_SECRET_BASE_TRAINER
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_EnterPlayersBase::
	setflag FLAG_HIDE_SECRET_BASE_TRAINER
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_AlreadyHasSecretBase::
	checkpartymove MOVE_SECRET_POWER
	goto_if_eq VAR_RESULT, PARTY_SIZE, SecretBase_EventScript_NoSecretPower
	setfieldeffectargument 0, VAR_RESULT
	setorcopyvar VAR_0x8004, VAR_RESULT
	lockall
	special GetSecretBaseNearbyMapName
	msgbox 0x08246782, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox 0x082465BD, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	fadescreenswapbuffers FADE_TO_BLACK
	special MoveOutOfSecretBaseFromOutside
	closemessage
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox 0x082467B0, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	buffermovename STR_VAR_2, MOVE_SECRET_POWER
	msgbox 0x0825665C, MSGBOX_DEFAULT
	closemessage
	closemessage
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_CaveUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_TreeUseSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_ShrubUseSecretPower
	releaseall
	end

SecretBase_EventScript_NoSecretPower::
	lockall
	goto_if_eq VAR_0x8007, SECRET_BASE_RED_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BROWN_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_BLUE_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_YELLOW_CAVE, SecretBase_EventScript_CaveNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_TREE, SecretBase_EventScript_TreeNoSecretPower
	goto_if_eq VAR_0x8007, SECRET_BASE_SHRUB, SecretBase_EventScript_ShrubNoSecretPower
	end

SecretBase_EventScript_CancelOnEntrance::
	closemessage
	releaseall
	end

SecretBase_EventScript_SetDecorationFlags::
	setflag FLAG_DECORATION_1
	setflag FLAG_DECORATION_2
	setflag FLAG_DECORATION_3
	setflag FLAG_DECORATION_4
	setflag FLAG_DECORATION_5
	setflag FLAG_DECORATION_6
	setflag FLAG_DECORATION_7
	setflag FLAG_DECORATION_8
	setflag FLAG_DECORATION_9
	setflag FLAG_DECORATION_10
	setflag FLAG_DECORATION_11
	setflag FLAG_DECORATION_12
	setflag FLAG_DECORATION_13
	setflag FLAG_DECORATION_14
	return

SecretBase_EventScript_InitDecorations::
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	end

SecretBase_EventScript_SetDecoration::
	setvar VAR_0x8005, 0
	goto SecretBase_EventScript_SetDecoration2
	end

SecretBase_EventScript_SetDecoration2::
	special SetDecoration
	end
