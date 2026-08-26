@ LavaridgeTown_HerbShop scripts (JP map g4 m0 @ 0x081F4185)

LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk:: @ 0x081F4186
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM:: @ 0x081F41AC
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan:: @ 0x081F41B5
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal:: @ 0x081F41E4
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop: @ 0x081F41EE
	.string "どうも！\n"
	.string "やすくて　よく　きく　かんぽうや　です$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine: @ 0x081F4207
	.string "フエンの　かんぽうやくを\n"
	.string "みにくるとは　なかなか　しぶいのう\p"
	.string "きにいった！　これを　もってけ！$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal: @ 0x081F4237
	.string "おまえさんに　あげた　もくたんは\n"
	.string "かんぽうやくを　つくるのに　つかうが\l"
	.string "ポケモンに　もたせても　すごいぞ！\p"
	.string "ほのおタイプの　わざの　いりょくを\n"
	.string "たかめて　くれるのじゃよ！$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike: @ 0x081F428D
	.string "かんぽうやくの　ききめは　すごいが\n"
	.string "ポケモンに　のませると　きらわれるぞよ\l"
	.string "きっと　すっごく　にがいんじゃろうな！$"
