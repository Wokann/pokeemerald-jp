@ RustboroCity_House2 scripts (JP map g11 m12 @ 0x08203F15)

RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_PokefanF:: @ 0x08203F16
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_LittleGirl:: @ 0x08203F1F
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

RustboroCity_House2_Text_TrainerSchoolExcellent: @ 0x08203F28
	.string "トレーナーズ　スクールは　いいわよ！\p"
	.string "あそこで　ポケモンの　べんきょう　すれば\n"
	.string "ジムリーダーに　だって　なれますもの！$"

RustboroCity_House2_Text_RoxanneKnowsALot: @ 0x08203F64
	.string "ジムリーダーの　ツツジ　ねーちゃん\n"
	.string "すっごい　ポケモン　くわしくて\l"
	.string "すっごい　ポケモン　つよいんだから！$"
