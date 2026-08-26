@ FortreeCity_DecorationShop scripts (JP map g12 m9 @ 0x082053F0)

FortreeCity_DecorationShop_MapScripts::
	.byte 0

FortreeCity_DecorationShop_EventScript_PokefanM:: @ 0x082053F1
	msgbox FortreeCity_DecorationShop_Text_MerchandiseSentToPC, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_Girl:: @ 0x082053FA
	msgbox FortreeCity_DecorationShop_Text_BuyingDeskForDolls, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_ClerkDesks:: @ 0x08205403
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Desks
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Desks: @ 0x0820541C
	.2byte DECOR_SMALL_DESK
	.2byte DECOR_POKEMON_DESK
	.2byte DECOR_HEAVY_DESK
	.2byte DECOR_RAGGED_DESK
	.2byte DECOR_COMFORT_DESK
	.2byte DECOR_BRICK_DESK
	.2byte DECOR_CAMP_DESK
	.2byte DECOR_HARD_DESK
	pokemartlistend

FortreeCity_DecorationShop_EventScript_ClerkChairs:: @ 0x08205430
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_Chairs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_Chairs: @ 0x08205448
	.2byte DECOR_SMALL_CHAIR
	.2byte DECOR_POKEMON_CHAIR
	.2byte DECOR_HEAVY_CHAIR
	.2byte DECOR_RAGGED_CHAIR
	.2byte DECOR_COMFORT_CHAIR
	.2byte DECOR_BRICK_CHAIR
	.2byte DECOR_CAMP_CHAIR
	.2byte DECOR_HARD_CHAIR
	pokemartlistend

FortreeCity_DecorationShop_Text_MerchandiseSentToPC: @ 0x0820545C
	.string "ここで　かった　ものは\n"
	.string "パソコンに　とどけられる！\p"
	.string "なんと　すばらしい！　ついでに　わしも\n"
	.string "いえまで　とどけて　くれないものか$"

FortreeCity_DecorationShop_Text_BuyingDeskForDolls: @ 0x0820549C
	.string "すてきな　つくえを　かって　そのうえに\n"
	.string "かわいい　ぬいぐるみを　ならべるんだ！\p"
	.string "そうしないと　ひみつきちに　おくとき\n"
	.string "つちで　よごれたり　トゲが　ささって\l"
	.string "ぬいぐるみが　かわいそう　だもん！$"
