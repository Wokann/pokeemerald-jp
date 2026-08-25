@ SootopolisCity_Mart scripts (JP map g15 m4 @ 0x0820F1B7)

SootopolisCity_Mart_MapScripts::
	.byte 0

SootopolisCity_Mart_EventScript_Clerk:: @ 0x0820F1B8
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SootopolisCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SootopolisCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_SHADOW_MAIL
	pokemartlistend

SootopolisCity_Mart_EventScript_FatMan:: @ 0x0820F1E6
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_FatManNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_FatManNoLegendaries
	msgbox SootopolisCity_Mart_Text_TooScaryOutside, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_FatManNoLegendaries:: @ 0x0820F206
	msgbox SootopolisCity_Mart_Text_PPUpIsGreat, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_Gentleman:: @ 0x0820F210
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_Mart_Text_DidSomethingAwaken, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_GentlemanNoLegendaries:: @ 0x0820F230
	msgbox SootopolisCity_Mart_Text_FullRestoreItemOfDreams, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_Text_PPUpIsGreat: @ 0x0820F23A
	.string "ポイントアップは　すごいぞ！\p"
	.string "なんたって　ポケモンの\n"
	.string "パワーポイントを　ふやせるからな！$"

SootopolisCity_Mart_Text_TooScaryOutside: @ 0x0820F267
	.string "いったい　なにが　おこってるんだ！？\p"
	.string "ものすごく　きになる　けど\n"
	.string "こわくて　そとに　でられないよ！$"

SootopolisCity_Mart_Text_FullRestoreItemOfDreams: @ 0x0820F299
	.string "かいふくのくすり　ごぞんじ　ですか？\p"
	.string "ポケモンの　たいりょく　ぜんかい！\n"
	.string "じょうたい　いじょうも　すべて　かいふく！\l"
	.string "まさに　ゆめのような　どうぐ　なのです$"

SootopolisCity_Mart_Text_DidSomethingAwaken: @ 0x0820F2E8
	.string "この　てんき⋯⋯\n"
	.string "なにかが　めざめたのか⋯⋯？$"
