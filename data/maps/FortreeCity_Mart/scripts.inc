@ FortreeCity_Mart scripts (JP map g12 m4 @ 0x08204DBD)

FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart: @ 0x08204DD8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_WOOD_MAIL
	pokemartlistend

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter: @ 0x08204E0B
	.string "シルバースプレーは\n"
	.string "ききめ　ながもち！　こうか　ばつぐん！\p"
	.string "つまり　むしよけスプレー　よりも\n"
	.string "すごい　ってことね！$"

FortreeCity_Mart_Text_StockUpOnItems: @ 0x08204E45
	.string "もしも　ってことが　あるかも　しれないし\n"
	.string "どうぐは　おおめに　かうように　してるのよ$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow: @ 0x08204E70
	.string "ふしぎなアメを　あげると\n"
	.string "ポケモン　いっきに　そだって\l"
	.string "レベルが　あがっちゃうんだ！$"
