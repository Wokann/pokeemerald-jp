@ RustboroCity_Flat1_1F scripts (JP map g11 m8 @ 0x08203714)

RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man:: @ 0x08203715
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman:: @ 0x0820371E
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility: @ 0x08203727
	.string "ポケモンには　それぞれ\n"
	.string "とくせい　とよばれる　ふしぎな　ちからが\l"
	.string "そなわって　いるんだよな$"

RustboroCity_Flat1_1F_Text_PokemonStrange: @ 0x08203755
	.string "ほんとうに　ポケモンって\n"
	.string "ふしぎな　いきもの　なのね$"
