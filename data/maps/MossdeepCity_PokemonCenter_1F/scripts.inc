@ MossdeepCity_PokemonCenter_1F scripts (JP map g14 m3 @ 0x0820C4B2)

MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:: @ 0x0820C4BD
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x0820C4C1
	setvar VAR_0x800B, LOCALID_MOSSDEEP_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman:: @ 0x0820C4CF
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl:: @ 0x0820C4D8
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable: @ 0x0820C4E1
	.string "この　まちの　ジムリーダー\n"
	.string "なんといっても　あの　コンビネーションは\l"
	.string "さいこう！　さすが！　って　かんじよ$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves: @ 0x0820C517
	.string "ポケモンの　とくせいに　よっては\n"
	.string "わざの　いりょくが　かわったり\l"
	.string "まったく　きかなかったり　するよ！$"
