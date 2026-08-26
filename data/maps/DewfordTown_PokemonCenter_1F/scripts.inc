@ DewfordTown_PokemonCenter_1F scripts (JP map g3 m1 @ 0x081F2CCF)

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:: @ 0x081F2CDA
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse:: @ 0x081F2CE3
	setvar VAR_0x800B, LOCALID_DEWFORD_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF:: @ 0x081F2CF1
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man:: @ 0x081F2CFA
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern: @ 0x081F2D03
	.string "まちの　はずれの　いしのどうくつ　には\n"
	.string "めずらしい　いしが　あるって　きいたわ$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM: @ 0x081F2D2B
	.string "つかれて　たたかうことの　できない\n"
	.string "ポケモンだって　ひでんと　いわれる\l"
	.string "わざは　つかうことが　できるよ！$"
