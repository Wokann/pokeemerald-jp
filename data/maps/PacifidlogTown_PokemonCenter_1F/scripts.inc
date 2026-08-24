@ PacifidlogTown_PokemonCenter_1F scripts (JP map g7 m0 @ 0x081F782A)

PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "きみの　トレーナーカードは　なにいろ？\n"
	.string "あたしのは　カッパー　なんだよ！$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "キナギタウンって　サニーゴたちの\n"
	.string "あつまりの　うえに　うかんでいるの\p"
	.string "⋯⋯なんて　いったら\n"
	.string "あなたは　しんじるかしら？$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "キナギで　くらす　ひとびとの　せんぞは\n"
	.string "ふねの　うえで　うまれて\l"
	.string "そして　ふねの　うえで　しんだ　という\p"
	.string "なにかを　さがすために\n"
	.string "そんな　いきかたを　していたそうじゃ$"
