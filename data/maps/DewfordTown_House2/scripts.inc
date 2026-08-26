@ DewfordTown_House2 scripts (JP map g3 m5 @ 0x081F4008)

DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man:: @ 0x081F4009
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf:: @ 0x081F4038
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf:: @ 0x081F4042
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy:: @ 0x081F404C
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf: @ 0x081F4055
	.string "ほら！　りゅうこう　さいせんたんの\n"
	.string "この　シルクのスカーフ　ステキだろ！\p"
	.string "おっ　めが　かがやいてるね！\n"
	.string "オレの　センスが　わかるんだな　きみは！\p"
	.string "うれしいね！\n"
	.string "これは　プレゼント　するよ！$"

DewfordTown_House2_Text_NoRoom: @ 0x081F40B4
	.string "え　もてないの？\n"
	.string "きみの　にもつを　ぜんぶ　うってでも\l"
	.string "もつべき　スカーフだぜ　これは！$"

DewfordTown_House2_Text_ExplainSilkScarf: @ 0x081F40E1
	.string "シルクのスカーフは　ノーマルタイプの\n"
	.string "わざの　いりょくを　あげてくれる！\p"
	.string "ほとんどの　ポケモンに　にあう\n"
	.string "すてきな　スカーフ　ってことだぜ！$"

DewfordTown_House2_Text_BrawlySoCool: @ 0x081F4128
	.string "へえ！　きみ　うみを　こえて\n"
	.string "わざわざ　ムロまで　きたの！\p"
	.string "もしかして　トウキさんの　うわさを　きいて\n"
	.string "あいに　きたんじゃない？\p"
	.string "トウキさん　かっこよくて\n"
	.string "みんなが　あこがれるもんな！$"
