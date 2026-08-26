@ LilycoveCity_DepartmentStore_2F scripts (JP map g13 m17 @ 0x0820A920)

LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook:: @ 0x0820A921
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF:: @ 0x0820A92A
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor:: @ 0x0820A933
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft:: @ 0x0820A93C
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart1: @ 0x0820A954
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight:: @ 0x0820A96E
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart2: @ 0x0820A988
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_MECH_MAIL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly: @ 0x0820A9A0
	.string "どうぐの　きほんは　うまく　つかいこなすこと\n"
	.string "これ　いちばん　だいじ　なのヨ$"

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband: @ 0x0820A9C7
	.string "いえで　まってる　ダンナの\n"
	.string "おみやげ　なんだけど　どれが　いいかしら？$"

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems: @ 0x0820A9EB
	.string "これから　とおい　ところへ\n"
	.string "たびに　いくからな\l"
	.string "ここで　どっさり　どうぐを　かっておくのさ$"
