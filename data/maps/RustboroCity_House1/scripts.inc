@ RustboroCity_House1 scripts (JP map g11 m10 @ 0x08203BC8)

RustboroCity_House1_MapScripts::
	.byte 0

@ JP only: ChoosePartyMon requires explicit waitstate; the special table differs from US.

RustboroCity_House1_EventScript_Trader:: @ 0x08203BC9
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade:: @ 0x08203C47
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon:: @ 0x08203C51
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted:: @ 0x08203C5F
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker:: @ 0x08203C69
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant: @ 0x08203C72
	.string "え？\n"
	.string "ぼくの　ポケモンが　かわいい？\l"
	.string "ウン　しってるよー\p"
	.string "あっ　どうしても　って　いうなら\n"
	.string "こうかん　して　あげても　いいよ\p"
	.string "じゃあ　ぼくの　{STR_VAR_2}\n"
	.string "{STR_VAR_1}　となら　こうかん　するよ$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon: @ 0x08203CCC
	.string "えへへ⋯⋯\n"
	.string "ちゃんと　かわいがってね$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe: @ 0x08203CDF
	.string "えー　どうみても　{STR_VAR_1}に\n"
	.string "みえないんだけど⋯⋯$"

RustboroCity_House1_Text_YouDontWantToThatsOkay: @ 0x08203CF7
	.string "あ　いやなら　いいけど⋯⋯\n"
	.string "せっかく　かわいい　ポケモンなのに$"

RustboroCity_House1_Text_AnyPokemonCanBeCute: @ 0x08203D17
	.string "だいじに　そだてると\n"
	.string "どんな　ポケモンも　すごく　かわいいよねー$"

RustboroCity_House1_Text_AllSortsOfPlaces: @ 0x08203D38
	.string "いろんな　ばしょに\n"
	.string "いろんな　ポケモンが　いる\l"
	.string "いろんな　ひとも　いる\p"
	.string "それが　たのしみで　わしも\n"
	.string "いろんな　ところに　でかけるのさ！$"
