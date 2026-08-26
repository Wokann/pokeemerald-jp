@ SlateportCity_PokemonCenter_1F scripts (JP map g9 m11 @ 0x081FE809)

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:: @ 0x081FE814
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x081FE81D
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor:: @ 0x081FE82B
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman:: @ 0x081FE834
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon: @ 0x081FE83D
	.string "しょうぶの　コツ⋯⋯\p"
	.string "いろんな　ポケモンを\n"
	.string "バランスよく　そだてることじゃ　ないか？\p"
	.string "いっぴきだけ　つよくても\n"
	.string "にがてな　ポケモンに　であってしまうと\l"
	.string "ても　あしも　でなくなりそうだぜ$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend: @ 0x081FE89A
	.string "ともだちと　ポケモンこうかん　するでしょ\p"
	.string "ポケモンが　どうぐを　もっていると\n"
	.string "2ばい　うれしく　なるよねー！！$"
