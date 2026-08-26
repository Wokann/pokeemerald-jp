@ MtPyre_5F scripts (JP map g24 m19 @ 0x082168FA)

MtPyre_5F_MapScripts::
	.byte 0

MtPyre_4F_EventScript_Tasha:: @ 0x082168FB
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro: @ 0x08216912
	.string "こわいものが　すきで⋯⋯\n"
	.string "すきで　すきで　たまらない⋯⋯\p"
	.string "あたし　ここに　いると\n"
	.string "こわくて　ふるえるの⋯⋯$"

MtPyre_4F_Text_TashaDefeat: @ 0x08216948
	.string "まけるのは　きらい⋯⋯$"

MtPyre_4F_Text_TashaPostBattle: @ 0x08216954
	.string "こわいもの　みたさで\n"
	.string "ここから　はなれられないの⋯⋯\p"
	.string "ねえ⋯⋯\n"
	.string "あなたも　いっしょに　いない⋯⋯？$"
