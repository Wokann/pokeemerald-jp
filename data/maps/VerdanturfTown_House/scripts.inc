@ VerdanturfTown_House scripts (JP map g6 m8 @ 0x081F777F)

VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1:: @ 0x081F7780
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2:: @ 0x081F7789
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague: @ 0x081F7792
	.string "とおく　はなれた\n"
	.string "サイユウの　おくちに　ある　という\l"
	.string "ポケモン　リーグ\p"
	.string "そこに　あつまるのは\n"
	.string "すごうでの　トレーナー　ばかり　ですって！$"

VerdanturfTown_House_Text_DefeatEliteFourInARow: @ 0x081F77D7
	.string "ポケモン　リーグは\n"
	.string "してんのう　4にん　つづけて\l"
	.string "しょうぶする　という　ルールらしいの！\p"
	.string "とちゅうで　まけたら　ひとりめ　から\n"
	.string "やりなおし　だなんて　きびしいのね！$"
