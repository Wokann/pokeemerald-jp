Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{STRING 0x01}は　あいことばを\n"
	.string "とびらに　かきつけた！\p"
	.string "‘カラクリだいおう　さま　あいしてる’\p"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "かぎの　はずれる　おとがした！$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "ここまで　こられる　トレーナーは\n"
	.string "そうは　いないよな！$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "つまり　キミも\n"
	.string "すごいって　ことだよな⋯$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "えっ　ポケモンリーグの　チャンピオンに\n"
	.string "かったって？　す　すごい⋯⋯！$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "わたしと　しょうぶ　できるなんて\n"
	.string "あなた　しあわせよ！$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "そんな　わたしが\n"
	.string "まけるなんて⋯⋯！$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "わたしに　かつなんて　きせきよ！\n"
	.string "じまん　できる　ことだわ！$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "あなたも　カラクリやしきに\n"
	.string "ちょうせん　しつづけて　いるんですね！$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "なるほど⋯⋯\n"
	.string "すばらしい　センスですね！$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "あなた　みたいな　ひとが　きてくれて\n"
	.string "カラクリだいおうも　まんぞく　でしょうね！$"
