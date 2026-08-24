@ OldaleTown_House2 scripts (JP map g2 m1 @ 0x081F2949)

OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "ポケモンって　たたかうと\n"
	.string "レベルアップして　つよくなるのよ！$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "つれて　あるく　ポケモンが　つよかったら\n"
	.string "とおくまで　いけるように　なるね！$"
