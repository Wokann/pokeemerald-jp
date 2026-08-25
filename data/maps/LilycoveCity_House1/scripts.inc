@ LilycoveCity_House1 scripts (JP map g13 m12 @ 0x08209F66)

LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM:: @ 0x08209F67
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon:: @ 0x08209F70
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools: @ 0x08209F83
	.string "ポケモンは　にんげんの　パートナーであって\n"
	.string "けっして　にんげんの　どうぐ　じゃないよ\p"
	.string "そこを　かんちがい　しておる\n"
	.string "にんげんも　たまに　いるんだよ⋯⋯$"

LilycoveCity_House1_Text_Kecleon: @ 0x08209FCF
	.string "カクレオン“るろろ⋯⋯？$"
