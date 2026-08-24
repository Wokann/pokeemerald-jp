LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	@ JP's cry-wait byte is emitted through the historical waitdooranim macro slot.
	waitdooranim
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "おんせんで　タマゴを　あたためている\n"
	.string "ばあさんから　きいたんじゃが⋯⋯\p"
	.string "そだてやに　ポケモンを\n"
	.string "2ひき　いっしょに　あずけたらの\l"
	.string "なんと　タマゴが　みつかったそうじゃ！！$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ジグザグマ“ぷしゅー！$"
