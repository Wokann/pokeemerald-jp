@ RustboroCity_Mart scripts (JP map g11 m7 @ 0x082035E0)

RustboroCity_Mart_MapScripts::
	.byte 0

RustboroCity_Mart_EventScript_Clerk:: @ 0x082035E1
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartBasic
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_PokemartExpanded
	end

RustboroCity_Mart_EventScript_PokemartBasic:: @ 0x082035FC
	pokemart RustboroCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Basic: @ 0x0820360C
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

RustboroCity_Mart_EventScript_PokemartExpanded:: @ 0x08203624
	pokemart RustboroCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_Expanded: @ 0x08203634
	.2byte ITEM_POKE_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

RustboroCity_Mart_EventScript_PokefanF:: @ 0x08203650
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_Boy:: @ 0x08203659
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_BugCatcher:: @ 0x08203662
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
	end

RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish: @ 0x0820366B
	.string "トウカのもりで　キノココが\n"
	.string "とびだして　きたときの　ため\l"
	.string "まひなおしや　どくけしを　かっておくの！$"

RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead: @ 0x0820369D
	.string "ポケモン　しんかして　たいりょくが\n"
	.string "ふえたから　キズぐすり　じゃなくて\l"
	.string "いいキズぐすりを　かってあげようかな$"

RustboroCity_Mart_Text_GettingEscapeRopeJustInCase: @ 0x082036D4
	.string "どうくつで　まよった　ときのため\n"
	.string "あなぬけのヒモを　かっておこう　っと！\p"
	.string "つかうと　いっしゅんで\n"
	.string "いりぐちに　もどれるもんね！$"
