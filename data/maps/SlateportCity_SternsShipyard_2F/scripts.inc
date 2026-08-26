@ SlateportCity_SternsShipyard_2F scripts (JP map g9 m1 @ 0x081FAFA2)

SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1:: @ 0x081FAFA3
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2:: @ 0x081FAFAC
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding: @ 0x081FAFB5
	.string "おおきな　ふねを　つくる　というのは\n"
	.string "のりものを　つくる　というよりも\l"
	.string "たてものを　つくるのに　にているんだよ$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy: @ 0x081FAFED
	.string "おもたい　てつで　できている　ふねが\n"
	.string "うみに　うくなんて　ふしぎ　だろう？\p"
	.string "あれは　‘ふりょく’　という　げんりを\n"
	.string "おうよう　しているんだ$"
