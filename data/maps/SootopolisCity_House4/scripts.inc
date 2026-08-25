@ SootopolisCity_House4 scripts (JP map g15 m8 @ 0x0820F593)

SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man:: @ 0x0820F594
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman:: @ 0x0820F59D
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill:: @ 0x0820F5A6
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea: @ 0x0820F5B9
	.string "いいことを　おしえてやろう\p"
	.string "この　あたりの　うみの　そこには\n"
	.string "こだいの　いせきが　あるそうだ！\p"
	.string "ひょっとしたら　むかしの　おたからが\n"
	.string "ざくざく　みつかるかも　しれないぜ！$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon: @ 0x0820F60F
	.string "たからもの　かぁ⋯⋯\p"
	.string "あると　いいけど\n"
	.string "そうでなくても　ポケモンと　いっしょに\l"
	.string "かいていを　おさんぽ　なんて　す·て·き！$"

SootopolisCity_House4_Text_Azumarill: @ 0x0820F64D
	.string "マリルリ“まるりー$"
