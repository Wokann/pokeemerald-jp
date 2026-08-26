@ PacifidlogTown_House3 scripts (JP map g7 m4 @ 0x081F7D1A)

PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader:: @ 0x081F7D1B
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade:: @ 0x081F7D9D
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon:: @ 0x081F7DA7
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted:: @ 0x081F7DB5
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl:: @ 0x081F7DBF
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt: @ 0x081F7DC8
	.string "みてくれよ　この　{STR_VAR_2}！\n"
	.string "おれが　きのう　じぶんの　たんじょうびに\l"
	.string "きねんに　つかまえた　{STR_VAR_2}だ！\p"
	.string "お！　ほしい　って　かおを　したな？\n"
	.string "まっ　きちょうな　{STR_VAR_2}だからな！\p"
	.string "よし！　{STR_VAR_1}と　だったら\n"
	.string "こうかん　して　やっても　いいぞ！$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou: @ 0x081F7E3D
	.string "おっ　これが　{STR_VAR_1}　かあー！\n"
	.string "やっぱ　{STR_VAR_2}　とは\l"
	.string "いろいろ　にている　ようで\l"
	.string "びみょうに　ちがうなあ！\p"
	.string "サンキュ！$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon: @ 0x081F7E77
	.string "だめだめ！　{STR_VAR_1}　じゃないと　\n"
	.string "ひきうけられないね！$"

PacifidlogTown_House3_Text_NotDesperateOrAnything: @ 0x081F7E92
	.string "ふーん　やめるのか⋯⋯\p"
	.string "まっ　おれのほうも\n"
	.string "どうしても　って　わけじゃ　ないしね$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon: @ 0x081F7EBB
	.string "じぶんで　さがしても　いいんだけど⋯⋯\p"
	.string "ほかの　トレーナーが　つかまえた\n"
	.string "タツベイ　って　いうのが\l"
	.string "どうしても　ほしかったんだよね$"

PacifidlogTown_House3_Text_IsThatAPokedex: @ 0x081F7EFD
	.string "それって　ポケモンずかん？\p"
	.string "それって　あなた　たくさんの\n"
	.string "ポケモンと　であった　ってこと？\p"
	.string "それって　すっごい　うらやましい！$"
