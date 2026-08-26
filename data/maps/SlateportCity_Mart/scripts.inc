@ SlateportCity_Mart scripts (JP map g9 m13 @ 0x081FE8F9)

SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk:: @ 0x081FE8FA
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_HARBOR_MAIL
	pokemartlistend

SlateportCity_Mart_EventScript_BlackBelt:: @ 0x081FE92A
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man:: @ 0x081FE933
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart: @ 0x081FE93C
	.string "たしかに　いちば　には\n"
	.string "いろんな　ほりだしものが　ある\p"
	.string "だが　フレンドリィショップ　じゃないと\n"
	.string "かえない　ものも　あるからな$"

SlateportCity_Mart_Text_GreatBallIsBetter: @ 0x081FE97B
	.string "スーパーボールは　モンスターボールよりも\n"
	.string "ポケモンを　つかまえやすい！\p"
	.string "これなら　あの　てごわい　ポケモンも⋯⋯$"
