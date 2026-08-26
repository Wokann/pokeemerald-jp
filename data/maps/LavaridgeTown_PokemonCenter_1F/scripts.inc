@ LavaridgeTown_PokemonCenter_1F scripts (JP map g4 m5 @ 0x081F4F85)

LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:: @ 0x081F4F90
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse:: @ 0x081F4F99
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster:: @ 0x081F4FA7
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman:: @ 0x081F4FB0
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman:: @ 0x081F4FB9
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether: @ 0x081F4FC2
	.string "ポケモンと　いっしょに　あるいていると\n"
	.string "なんだか　ポケモンが　なついてくれるような\l"
	.string "そんな　きが　するのよね$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate: @ 0x081F4FF9
	.string "おんせんに　はいる　だけで\n"
	.string "げんきに　なるなんて　ふしぎだなー！\l"
	.string "ポケモンも　いれて　あげたいなー$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo: @ 0x081F502B
	.string "ほっほっほ！　おわかいの\n"
	.string "ここから　おんせんに　いけますぞ！\p"
	.string "ポケモンが　ここで　やすむのなら\n"
	.string "ひとも　おんせんで　ゆっくり　しませんと！$"
