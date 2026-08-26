@ MauvilleCity_House1 scripts (JP map g10 m2 @ 0x081FFD77)

MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude:: @ 0x081FFD78
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM06
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash:: @ 0x081FFDA7
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis: @ 0x081FFDB1
	.string "ほっほう！\p"
	.string "ぼくのことを　いわくだきオヤジ\n"
	.string "なんて　よぶひとが　いるらしいけど\l"
	.string "しつれい　しちゃうね！\p"
	.string "ぼくは　まだ　オヤジ　じゃないよ\n"
	.string "せめて　いわくだきにいさん　と\l"
	.string "よんでほしい　ものだね！\p"
	.string "ほっほう！\p"
	.string "それはそれとして　きみの　ポケモン\n"
	.string "なかなか　つよそうだな！\p"
	.string "よし　きにいった！\n"
	.string "この　ひでんマシンを　あげよう！$"

MauvilleCity_House1_Text_ExplainRockSmash: @ 0x081FFE53
	.string "それは　ひでんマシン‘いわくだき’！\p"
	.string "きみの　いくてを　ふさぐ\n"
	.string "じゃまな　おおいわが　あっても\p"
	.string "その　ひでんを　つかうことで\n"
	.string "くだいて　しまえるのだ！\p"
	.string "がんばって　いわを　くだきたまえ！\n"
	.string "ほっほう！$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock: @ 0x081FFEB7
	.string "そうそう\n"
	.string "いわを　くだくと　かくれていた\l"
	.string "ポケモンが　とびでることも　あるからね！\p"
	.string "ほっほう！$"
