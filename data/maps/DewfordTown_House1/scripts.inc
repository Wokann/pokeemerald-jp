@ DewfordTown_House1 scripts (JP map g3 m0 @ 0x081F2C10)

DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man:: @ 0x081F2C11
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman:: @ 0x081F2C1A
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon:: @ 0x081F2C23
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland: @ 0x081F2C36
	.string "こういう　ちいさな　しまで\n"
	.string "ポケモンと　かぞく　なかよく　くらすのも\l"
	.string "なかなか　いい　もんですよ$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland: @ 0x081F2C67
	.string "わたしは　カイナシティ　という\n"
	.string "おおきな　みなとまち　から\l"
	.string "およめさんに　きたのよ\p"
	.string "のんびりとした　しま　だけれど\n"
	.string "きれいな　うみに　かこまれて　いれば\l"
	.string "それだけで　しあわせ　なんだね$"

DewfordTown_House1_Text_Zigzagoon: @ 0x081F2CC4
	.string "ジグザグマ“ぐぐう！$"
