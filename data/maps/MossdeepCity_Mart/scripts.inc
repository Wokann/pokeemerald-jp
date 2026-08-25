@ MossdeepCity_Mart scripts (JP map g14 m5 @ 0x0820C5B2)

MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk:: @ 0x0820C5B3
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman:: @ 0x0820C5E2
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy:: @ 0x0820C5EB
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor:: @ 0x0820C5F4
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic: @ 0x0820C5FD
	.string "げんきのかけら　って　すごい！\p"
	.string "これを　あたえると\n"
	.string "ひんしの　ポケモンも　めざめるの！\p"
	.string "でも　パワーポイントは\n"
	.string "かいふく　しないから　きをつけて！$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest: @ 0x0820C647
	.string "ゴールドスプレーは\n"
	.string "よわい　ポケモンを　よせつけない\p"
	.string "かずある　スプレーの　なかで\n"
	.string "いちばん　ながもち　するんだ！$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare: @ 0x0820C681
	.string "ネットボールと　ダイブボールは\n"
	.string "ここ　トクサネでしか　つくっていない\l"
	.string "めずらしい　モンスターボール！\p"
	.string "ネットボールは　むしタイプや\n"
	.string "みずタイプの　ポケモンに　こうかてき！\p"
	.string "ダイブボールは　かいていに　いる\n"
	.string "ポケモンを　つかまえ　やすいんだ！$"
