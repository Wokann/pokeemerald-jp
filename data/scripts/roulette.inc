Roulette_EventScript_Table1:: @ 0x08262C92
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2:: @ 0x08262CC0
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play:: @ 0x08262CEE
	special PlayRoulette
	end

Roulette_Text_PlayMinimumWagerIsX:: @ 0x08262CF3
	.string "ここは　レート{STR_VAR_1}の　ルーレットだい　です\n"
	.string "ルーレットで　あそびますか？$"

Roulette_Text_NotEnoughCoins:: @ 0x08262D18
	.string "コインが　たりません$"

Roulette_Text_SpecialRateTable:: @ 0x08262D23
	.string "ほんじつ　このだいでは\n"
	.string "レート　アップ　じっしちゅう！$"

Roulette_Text_ControlsInstruction:: @ 0x08262D3F
	.string "ベットする　わくを　じゅうじボタンで　えらんで\n"
	.string "Aボタンで　けってい　します$"

Roulette_Text_ItsAHit:: @ 0x08262D66
	.string "あたりー！$"

Roulette_Text_Jackpot:: @ 0x08262D6C
	.string "おおあたり！！$"

Roulette_Text_NothingDoing:: @ 0x08262D74
	.string "はずれー$"

Roulette_Text_YouveWonXCoins:: @ 0x08262D79
	.string "おめでとう　ございます！\n"
	.string "コイン　{STR_VAR_1}まい　はいります！$"

Roulette_Text_NoCoinsLeft:: @ 0x08262D96
	.string "コインが　なくなりました$"

Roulette_Text_KeepPlaying:: @ 0x08262DA3
	.string "つづけて　あそびますか？$"

Roulette_Text_BoardWillBeCleared:: @ 0x08262DB0
	.string "だいの　うえの　たまを\n"
	.string "クリア　します$"

@ Unused
Roulette_Text_YouDontHaveACoinCase:: @ 0x08262DC4
	.string "コインケースを　もっていません！$"

Roulette_Text_CoinCaseIsFull:: @ 0x08262DD5
	.string "コインが　いっぱいです！\n"
	.string "けいひんと　こうかん　して　ください$"
