DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "ほら！　りゅうこう　さいせんたんの\n"
	.string "この　シルクのスカーフ　ステキだろ！\p"
	.string "おっ　めが　かがやいてるね！\n"
	.string "オレの　センスが　わかるんだな　きみは！\p"
	.string "うれしいね！\n"
	.string "これは　プレゼント　するよ！$"

DewfordTown_House2_Text_NoRoom:
	.string "え　もてないの？\n"
	.string "きみの　にもつを　ぜんぶ　うってでも\l"
	.string "もつべき　スカーフだぜ　これは！$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "シルクのスカーフは　ノーマルタイプの\n"
	.string "わざの　いりょくを　あげてくれる！\p"
	.string "ほとんどの　ポケモンに　にあう\n"
	.string "すてきな　スカーフ　ってことだぜ！$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "へえ！　きみ　うみを　こえて\n"
	.string "わざわざ　ムロまで　きたの！\p"
	.string "もしかして　トウキさんの　うわさを　きいて\n"
	.string "あいに　きたんじゃない？\p"
	.string "トウキさん　かっこよくて\n"
	.string "みんなが　あこがれるもんな！$"
