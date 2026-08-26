@ RustboroCity_Flat2_3F scripts (JP map g11 m15 @ 0x082040B5)

RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee:: @ 0x082040B6
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman:: @ 0x082040BF
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones: @ 0x082040C8
	.string "デボンの　しゃちょうは\n"
	.string "めずらしい　いしを　あつめるのが\l"
	.string "しゅみ　なんだよ$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones: @ 0x082040EE
	.string "たしか　むすこさんも\n"
	.string "めずらしい　いしを　あつめるのが\l"
	.string "しゅみ　だったっけ⋯⋯？$"
