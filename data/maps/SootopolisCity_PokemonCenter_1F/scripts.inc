@ SootopolisCity_PokemonCenter_1F scripts (JP map g15 m2 @ 0x0820EFD5)

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition: @ 0x0820EFE0
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x0820EFE4
	setvar VAR_0x800B, LOCALID_SOOTOPOLIS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman:: @ 0x0820EFF2
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries:: @ 0x0820F012
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman:: @ 0x0820F01C
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries:: @ 0x0820F03C
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn: @ 0x0820F046
	.string "この　まちの　ジムリーダーは\n"
	.string "ホウエンちほう　でも　いちばんと\l"
	.string "うわさの　じつりょくしゃ　ミクリに\p"
	.string "ポケモン　しょうぶの　てほどきを　した\n"
	.string "じんぶつが　やっているのだ\p"
	.string "しかし　そんな　ミクリの　ししょうよりも\n"
	.string "つよいと　いわれる　してんのう⋯⋯\l"
	.string "その　つよさは　どれほどの　ものだろう$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge: @ 0x0820F0D5
	.string "この　まちの　みんなが　みんな\n"
	.string "いえに　とじこもって　でてこないんです！\p"
	.string "そう　いってる　わたしも\n"
	.string "ここから　でたくないんです⋯⋯$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon: @ 0x0820F117
	.string "どんな　ときでも\n"
	.string "どんな　ことが　あっても\l"
	.string "あたし　ポケモンと　ともだちで　いるわ\p"
	.string "だって　ポケモンと　いっしょだと\n"
	.string "すごく　たのしいもの！$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends: @ 0x0820F15E
	.string "ポケモンって\n"
	.string "あたしたちの　ともだちじゃ⋯⋯　ないの？\p"
	.string "どうして\n"
	.string "あんなふうに　あばれて　いるの？$"
