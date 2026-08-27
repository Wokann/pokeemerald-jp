EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	@ The JP text data remains in its later physical owner at 0x082436B8.
	msgbox 0x082436B8, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message 0x082436CD
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	@ The JP menu script waits for its PC menu task here.
	waitstate
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	@ The JP byte stream uses an explicit menu-result dispatch.
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0, EventScript_AccessPokemonStorage
	goto_if_eq VAR_0x8000, 1, EventScript_AccessPlayersPC
	goto_if_eq VAR_0x8000, 2, EventScript_AccessHallOfFame
	goto_if_eq VAR_0x8000, 3, EventScript_TurnOffPC
	goto_if_eq VAR_0x8000, MULTI_B_PRESSED, EventScript_TurnOffPC
	end

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox 0x08243716, MSGBOX_DEFAULT
	special PlayerPC
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox 0x082436FE, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox 0x082436EA, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
	msgbox 0x08243728, MSGBOX_DEFAULT
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	goto EventScript_AccessPC
	end
