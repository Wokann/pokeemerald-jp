@ SlateportCity_House scripts (JP map g9 m10 @ 0x081FE772)

SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM:: @ 0x081FE773
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl:: @ 0x081FE77C
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains: @ 0x081FE785
	.string "わたしの　ポケモン　せっかちでね\n"
	.string "ほかの　ポケモンと　くらべると\l"
	.string "すばやさが　たかいんだわ\p"
	.string "せいかくで　そだちやすい　のうりょくに\n"
	.string "ちがいが　あるのかもな？$"

SlateportCity_House_Text_MustBeGoingToBattleTent: @ 0x081FE7D4
	.string "あなた　ポケモントレーナーね\n"
	.string "カイナシティに　きた　っていうことは\l"
	.string "とうぜん　バトルテントに　いくのね！$"
