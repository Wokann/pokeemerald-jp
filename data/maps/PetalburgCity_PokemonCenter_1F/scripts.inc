@ PetalburgCity_PokemonCenter_1F scripts (JP map g8 m4 @ 0x081FA7CD)

PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:: @ 0x081FA7D8
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x081FA7E1
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan:: @ 0x081FA7EF
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster:: @ 0x081FA7F8
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman:: @ 0x081FA801
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo:: @ 0x081FA81D
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType:: @ 0x081FA840
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType:: @ 0x081FA849
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType:: @ 0x081FA852
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem: @ 0x081FA85B
	.string "パソコンで　つかえる\n"
	.string "ポケモン　あずかり　システム⋯⋯\p"
	.string "つくった　やつは\n"
	.string "すげー　かがくに　くわしいんだろうな！$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP: @ 0x081FA894
	.string "ポケモンに　オレンのみ　を　たべさせたら\n"
	.string "たいりょくが　かいふく　したんだぜ！$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon: @ 0x081FA8BC
	.string "ポケモンには\n"
	.string "いろいろ　タイプが　あるの！\p"
	.string "で　タイプには　あいしょうが　あるから\n"
	.string "ポケモンしょうぶの　とき\l"
	.string "ゆうり　だったり　ふり　だったりするの$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType: @ 0x081FA907
	.string "たとえば　あなたの　キモリは\n"
	.string "くさタイプ　でしょ\p"
	.string "みずタイプや　じめんタイプに　つよくて\n"
	.string "ほのおタイプが　にがて　なのよね！$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType: @ 0x081FA946
	.string "たとえば　あなたの\n"
	.string "アチャモは　ほのおタイプ　でしょ\p"
	.string "くさタイプや　むしタイプに　つよくて\n"
	.string "みずタイプが　にがて　なんだ！$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType: @ 0x081FA984
	.string "たとえば　あなたの\n"
	.string "ミズゴロウは　みずタイプ　だよね\p"
	.string "ほのおタイプに　つよくて\n"
	.string "くさタイプや　でんきタイプが　にがて　ね！$"
