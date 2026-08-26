@ DewfordTown_House1 scripts (JP map g3 m0 @ 0x081F2C10)

DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	@ JP ROM uses SCR_OP_WAITDOORANIM (0xC5) at this US waitmoncry site.
	waitmoncry_jp
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "こういう　ちいさな　しまで\n"
	.string "ポケモンと　かぞく　なかよく　くらすのも\l"
	.string "なかなか　いい　もんですよ$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "わたしは　カイナシティ　という\n"
	.string "おおきな　みなとまち　から\l"
	.string "およめさんに　きたのよ\p"
	.string "のんびりとした　しま　だけれど\n"
	.string "きれいな　うみに　かこまれて　いれば\l"
	.string "それだけで　しあわせ　なんだね$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ジグザグマ“ぐぐう！$"
