@ OldaleTown_Mart scripts (JP map g2 m4 @ 0x081F2B0B)

OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk:: @ 0x081F2B0C
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_ExpandedItems:: @ 0x081F2B38
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

OldaleTown_Mart_EventScript_Woman:: @ 0x081F2B56
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock:: @ 0x081F2B6B
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy:: @ 0x081F2B75
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut: @ 0x081F2B7E
	.string "なんでも　うりきれ　らしくて\n"
	.string "モンスターボール　かえないの⋯⋯$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls: @ 0x081F2B9E
	.string "どんどん　モンスターボール　かって\n"
	.string "どんどん　ポケモン　つかまえちゃうわよ！$"

OldaleTown_Mart_Text_RestoreHPWithPotion: @ 0x081F2BC5
	.string "ポケモンは　たいりょくが　なくなると\n"
	.string "たたかう　げんきも　なくなる\p"
	.string "そんな　ときは　キズぐすりを　つかって\n"
	.string "たいりょくを　かいふく　してあげるんだ！$"
