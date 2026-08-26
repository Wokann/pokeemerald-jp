@ RustboroCity_PokemonCenter_1F scripts (JP map g11 m5 @ 0x082034B3)

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition: @ 0x082034BE
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x082034C7
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man:: @ 0x082034D5
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy:: @ 0x082034DE
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl:: @ 0x082034E7
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities: @ 0x082034F0
	.string "わしの　ポケモンは　むじゃき　で\n"
	.string "ともだちの　ポケモンは　ようき　なんだよ\p"
	.string "ポケモンにも　せいかくが　ある　というのは\n"
	.string "なかなか　おもしろい　もんだねー！$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon: @ 0x0820353E
	.string "にんげんと　おなじで\n"
	.string "ポケモンにも　オスと　メスが　いるんだけど\l"
	.string "だから　なにが　ちがうのかは\l"
	.string "さっぱり　わかっていない　らしいよ$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor: @ 0x08203580
	.string "となりの　いえの　おじさんが　くれた\n"
	.string "ひでんマシンで　あたしの　ポケモン\l"
	.string "ほそい　きを　きることが　できるんだ！$"
