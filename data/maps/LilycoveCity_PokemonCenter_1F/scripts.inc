@ LilycoveCity_PokemonCenter_1F scripts (JP map g13 m6 @ 0x0820824A)

LilycoveCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition:: @ 0x08208255
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
	end

LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx:: @ 0x0820825E
	special SetLilycoveLadyGfx
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
	end

LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon:: @ 0x08208278
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon:: @ 0x0820827C
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x08208280
	setvar VAR_0x800B, LOCALID_LILYCOVE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Boy:: @ 0x0820828E
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_Maniac:: @ 0x08208297
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone:: @ 0x082082AC
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon: @ 0x082082B6
	.string "この　せかいには\n"
	.string "どれだけの　ポケモンが　いるのかな？\p"
	.string "いつのひか　うみを　こえて\n"
	.string "とおい　くにの　ひとと\l"
	.string "ポケモン　こうかん　したいなあ！$"

LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels: @ 0x082082FD
	.string "ちかごろ　ひとの　ポケモンを　うばったり\n"
	.string "いんせきを　よこどり　したりする\l"
	.string "ろくでもない　やつらが　いるらしいな！$"

LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels: @ 0x08208337
	.string "ひとの　ポケモンを　うばったり\n"
	.string "いんせきを　よこどり　していた\l"
	.string "ろくでもない　やつら⋯⋯\p"
	.string "ちかごろ　すがたを　みなくなったよ$"
