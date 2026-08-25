@ Route117_PokemonDayCare scripts (JP map g22 m0 @ 0x082129DB)

Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:: @ 0x082129E1
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end
