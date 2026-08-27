Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{STRING 0x01}は　あいことばを\n"
	.string "とびらに　かきつけた！\p"
	.string "‘カラクリだいおう　さま　かっこいい’\p"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "かぎの　はずれる　おとがした！$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "こういうの　かんがえるのって　めんどう！\n"
	.string "わたしは　しょうぶだけ　したいのにー！$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "まけちゃった　けど　やっぱり\n"
	.string "しょうぶが　いちばん　たのしい！$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "トレーナーが　いそうな　ところは\n"
	.string "どこにでも　いきたく　なるわよね！$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "このくらいの　いわは\n"
	.string "ゆび　いっぽんで　らくしょう　だぜ！$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "いわが　おせても\n"
	.string "パズルが　とけない⋯⋯$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "ちからが　つよいだけじゃ　ダメだね⋯⋯\n"
	.string "アタマ　つかわないと$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "カラクリやしきも　だんだん\n"
	.string "むずかしく　なってきたわね！$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "ああっ！$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "さいごまで　いった\n"
	.string "ひとって　いるのかしらね？$"
