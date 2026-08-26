@ PetalburgCity_Mart scripts (JP map g8 m6 @ 0x081FA9E9)

PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk:: @ 0x081FA9EA
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart PetalburgCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_ExpandedItems:: @ 0x081FAA26
	pokemart PetalburgCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_Woman:: @ 0x081FAA56
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy:: @ 0x081FAA5F
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man:: @ 0x081FAA68
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_Text_WeakWillGrowStronger: @ 0x081FAA71
	.string "いまは　よわい　ポケモンでも\n"
	.string "そだててあげれば　きっと　つよくなる！\p"
	.string "だいじ　なのは\n"
	.string "ポケモンへの　あいじょうよ！$"

PetalburgCity_Mart_Text_RepelIsUseful: @ 0x081FAAAB
	.string "むしよけスプレー　つかってる？\n"
	.string "つかうと　ポケモンが　よってこないから\l"
	.string "いそぐとき　べんり　なんだぜ！$"

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou: @ 0x081FAADF
	.string "きみ　どくけし　もってるかい？\p"
	.string "ポケモン　どくを　くらったまま\n"
	.string "あるいていると　たいりょく　なくなって\l"
	.string "たおれちゃうから　もっておくと　いいよ！$"
