@ MossdeepCity_House3 scripts (JP map g14 m6 @ 0x0820C6FA)

MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman:: @ 0x0820C6FB
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod:: @ 0x0820C73A
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod:: @ 0x0820C744
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod: @ 0x0820C74E
	.string "おーい！　トレーナーよお！\n"
	.string "すごいつりざおは　ほんとうに　すごいぞお\p"
	.string "なんたって　かいていに　いる\n"
	.string "ポケモンも　つりあげられる　からのお！\p"
	.string "どお？　ほしく　なった？$"

MossdeepCity_House3_Text_SuperRodIsSuper: @ 0x0820C7A1
	.string "そうだろ　そうだろ！　すごいつりざおは\n"
	.string "ほんとうに　すごい　からのお！$"

MossdeepCity_House3_Text_TryDroppingRodInWater: @ 0x0820C7C5
	.string "みずの　ある　ところなら\n"
	.string "どこでも　つりざお　つかうと　いいぞお！$"

MossdeepCity_House3_Text_DontYouLikeToFish: @ 0x0820C7E7
	.string "あら？\n"
	.string "つりは　きらい　なのかね？$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon: @ 0x0820C7F9
	.string "すごいつりざおで\n"
	.string "かいていの　ポケモンも　つりあげろお！$"
