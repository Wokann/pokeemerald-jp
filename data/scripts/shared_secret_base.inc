@ Shared Secret Base scripts (JP @ 0x0821D372).
@ The referenced text records remain in their later physical JP owners.

SecretBase_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SecretBase_OnResume
	.byte 0

SecretBase_OnWarp::
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

SecretBase_OnTransition::
	call SecretBase_EventScript_SetDecorationFlags
	special SetSecretBaseOwnerGfxId
	special sub_080EBD4C
	end

SecretBase_OnFrame::
	map_script_2 VAR_INIT_SECRET_BASE, 0, 0x08245C30
	.2byte 0

SecretBase_OnResume::
	setstepcallback STEP_CB_SECRET_BASE
	end

SecretBase_EventScript_PC::
	lockall
	playse SE_PC_LOGIN
	message 0x08246669
	dofieldeffect FLDEFF_PCTURN_ON
	waitstate
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCShowMainMenu::
	message 0x0824667E
	waitmessage
	goto_if_set FLAG_SECRET_BASE_REGISTRY_ENABLED, SecretBase_EventScript_PCMainMenuWithRegister
	goto SecretBase_EventScript_PCMainMenuWithoutRegister
	end

SecretBase_EventScript_PCCancel::
	lockall
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCMainMenuWithRegister::
	multichoice 0, 0, MULTI_BASE_PC_WITH_REGISTRY, FALSE
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0, SecretBase_EventScript_PCDecorationMenu
	goto_if_eq VAR_0x8000, 1, SecretBase_EventScript_PCPackUp
	goto_if_eq VAR_0x8000, 2, SecretBase_EventScript_PCRegistryMenu
	goto_if_eq VAR_0x8000, 3, SecretBase_EventScript_PCTurnOff
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
	end

SecretBase_EventScript_PCMainMenuWithoutRegister::
	multichoice 0, 0, MULTI_BASE_PC_NO_REGISTRY, FALSE
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0, SecretBase_EventScript_PCDecorationMenu
	goto_if_eq VAR_0x8000, 1, SecretBase_EventScript_PCPackUp
	goto_if_eq VAR_0x8000, 2, SecretBase_EventScript_PCTurnOff
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
	end

SecretBase_EventScript_PCPackUp::
	loadword 0, 0x082465BD
	callstd 5
	goto_if_eq VAR_RESULT, FALSE, SecretBase_EventScript_PCShowMainMenu
	closemessage
	special MoveOutOfSecretBase
	releaseall
	end

SecretBase_EventScript_PCDecorationMenu::
	special ShowSecretBaseDecorationMenu
	end

SecretBase_EventScript_PCRegistryMenu::
	special ShowSecretBaseRegistryMenu
	end

SecretBase_EventScript_RecordMixingPC::
	lockall
	message 0x08246669
	playse SE_PC_LOGIN
	dofieldeffect FLDEFF_PCTURN_ON
	waitstate
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	goto SecretBase_EventScript_PCRegisterMenu
	end

SecretBase_EventScript_PCRegisterMenu::
	message 0x0824667E
	waitmessage
	multichoice 0, 0, MULTI_REGISTER_MENU, FALSE
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0, SecretBase_EventScript_PCRegister
	goto_if_eq VAR_0x8000, 1, SecretBase_EventScript_PCRegistryMenu
	goto_if_eq VAR_0x8000, 2, SecretBase_EventScript_PCRegistryInfo
	goto_if_eq VAR_0x8000, 3, SecretBase_EventScript_PCTurnOff
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
	end

SecretBase_EventScript_ShowRegisterMenu::
	lockall
	goto SecretBase_EventScript_PCRegisterMenu
	end

SecretBase_EventScript_PCRegister::
	special GetCurSecretBaseRegistrationValidity
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_AlreadyRegistered
	goto_if_eq VAR_RESULT, 2, SecretBase_EventScript_CantRegisterTooManyBases
	@ JP special-table slot for the US CopyCurSecretBaseOwnerName_StrVar1 behavior.
	special DeleteRegistry_Yes
	loadword 0, 0x082465E7
	callstd 5
	goto_if_eq VAR_RESULT, FALSE, SecretBase_EventScript_PCRegisterMenu
	loadword 0, 0x0824664D
	callstd 3
	special ToggleCurSecretBaseRegistry
	special DoSecretBasePCTurnOffEffect
	releaseall
	end

SecretBase_EventScript_AlreadyRegistered::
	loadword 0, 0x082465FD
	callstd 5
	goto_if_eq VAR_RESULT, FALSE, SecretBase_EventScript_PCRegisterMenu
	loadword 0, 0x08246658
	callstd 3
	special ToggleCurSecretBaseRegistry
	special DoSecretBasePCTurnOffEffect
	releaseall
	end

SecretBase_EventScript_CantRegisterTooManyBases::
	loadword 0, 0x0824661D
	callstd 3
	special DoSecretBasePCTurnOffEffect
	closemessage
	releaseall
	end

SecretBase_EventScript_PCRegistryInfo::
	loadword 0, 0x08246688
	callstd 4
	goto SecretBase_EventScript_PCRegisterMenu
	end

SecretBase_EventScript_PCTurnOff::
	special DoSecretBasePCTurnOffEffect
	closemessage
	releaseall
	end

@ Unused
SecretBase_EventScript_Poster::
	special SetSecretBaseSecretsTvFlags_Poster
	end

@ Unused
SecretBase_EventScript_FurnitureBottom::
	special SetSecretBaseSecretsTvFlags_MiscFurnature
	end

@ Unused
SecretBase_EventScript_FurnitureMiddle::
	special SetSecretBaseSecretsTvFlags_LargeDecorationSpot
	end

@ Unused
SecretBase_EventScript_FurnitureTop::
	special SetSecretBaseSecretsTvFlags_SmallDecorationSpot
	end

SecretBase_EventScript_SandOrnament::
	special SetSecretBaseSecretsTvFlags_SandOrnament
	dofieldeffect FLDEFF_SAND_PILLAR
	waitstate
	end

SecretBase_EventScript_ShieldOrToyTV::
	special GetShieldToyTVDecorationInfo
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_BattleTowerShield
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_ToyTV
	goto_if_eq VAR_RESULT, 2, SecretBase_EventScript_SeedotTV
	goto_if_eq VAR_RESULT, 3, SecretBase_EventScript_SkittyTV
	end

SecretBase_EventScript_BattleTowerShield::
	loadword 0, 0x082466F5
	callstd 3
	end

SecretBase_EventScript_ToyTV::
	loadword 0, 0x08246714
	callstd 3
	end

SecretBase_EventScript_SeedotTV::
	loadword 0, 0x0824673E
	callstd 3
	end

SecretBase_EventScript_SkittyTV::
	loadword 0, 0x08246761
	callstd 3
	end

SecretBase_Text_SmallIndentInWall::
	.string "かべに　ちいさな　くぼみが　ある$"

SecretBase_Text_IndentUseSecretPower::
	.string "かべに　ちいさな　くぼみが　ある\p"
	.string "ひみつのちからを　つかいますか？$"

SecretBase_Text_DiscoveredSmallCavern::
	.string "ちいさな　どうくつを　はっけん！$"

SecretBase_Text_WantToMakeYourSecretBaseHere::
	.string "ここに　ひみつきちを　つくりますか？$"
