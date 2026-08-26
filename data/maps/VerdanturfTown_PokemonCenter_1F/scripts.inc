@ VerdanturfTown_PokemonCenter_1F scripts (JP map g6 m4 @ 0x081F7021)

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:: @ 0x081F702C
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse:: @ 0x081F7035
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman:: @ 0x081F7043
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM:: @ 0x081F704C
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon: @ 0x081F7055
	.string "ポケモンを　しんじられない　ようでは\n"
	.string "いちにんまえ　とは　いえないね\p"
	.string "たたかう　ポケモンたちを\n"
	.string "さいごまで　しんじる　ものだけが\l"
	.string "かちぬく　ことが　できるんだ$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent: @ 0x081F70A5
	.string "シダケにくる　りゆうと　いえば\n"
	.string "ずばり　バトルテントじゃろ？\p"
	.string "それとも　だれか　あいたい　ひとでも\n"
	.string "いるのかね？$"
