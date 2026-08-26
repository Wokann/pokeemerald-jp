@ LavaridgeTown_House scripts (JP map g4 m3 @ 0x081F4E4D)

LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan:: @ 0x081F4E4E
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon:: @ 0x081F4E57
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings: @ 0x081F4E6A
	.string "おんせんで　タマゴを　あたためている\n"
	.string "ばあさんから　きいたんじゃが⋯⋯\p"
	.string "そだてやに　ポケモンを\n"
	.string "2ひき　いっしょに　あずけたらの\l"
	.string "なんと　タマゴが　みつかったそうじゃ！！$"

LavaridgeTown_House_Text_Zigzagoon: @ 0x081F4EC0
	.string "ジグザグマ“ぷしゅー！$"
