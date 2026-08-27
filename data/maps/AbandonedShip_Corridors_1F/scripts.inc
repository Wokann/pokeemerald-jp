@ AbandonedShip_Corridors_1F scripts (JP map g24 m55 @ 0x0821A97C)

AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster:: @ 0x0821A97D
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie:: @ 0x0821A986
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro: @ 0x0821A99D
	.string "ふねの　なかでも\n"
	.string "うきわ　もっていたら　おかしい？$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat: @ 0x0821A9B7
	.string "うわぁ　つよーい！$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle: @ 0x0821A9C1
	.string "うきわを　もったままだと\n"
	.string "モンスターボール　なげにくいよ$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere: @ 0x0821A9DE
	.string "ここって　おもしろいね！\n"
	.string "いるだけで　ワクワク　してくるよ！$"
