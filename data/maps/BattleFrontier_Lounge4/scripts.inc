BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "つよい　トレーナーの　インタビュー\n"
	.string "きょうは　やって　いるかなー？$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "ここで　おいしい　レストランでも\n"
	.string "やったら　もうかりそうやな$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "ふう\p"
	.string "たたかいの　あいまに\n"
	.string "ちょっと　ひとやすみ⋯⋯\p"
	.string "と　いっても\n"
	.string "おれの　あたまの　なかでは\l"
	.string "やすみなく　せんりゃくが　ねられているぜ！$"
