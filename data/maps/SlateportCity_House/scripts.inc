SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "わたしの　ポケモン　せっかちでね\n"
	.string "ほかの　ポケモンと　くらべると\l"
	.string "すばやさが　たかいんだわ\p"
	.string "せいかくで　そだちやすい　のうりょくに\n"
	.string "ちがいが　あるのかもな？$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "あなた　ポケモントレーナーね\n"
	.string "カイナシティに　きた　っていうことは\l"
	.string "とうぜん　バトルテントに　いくのね！$"
