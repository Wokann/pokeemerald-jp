BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "わたしの　この　ポケモン\n"
	.string "{STR_VAR_2}って　いうんですよ　しってます？\l"
	.string "なかなか　かわいくて　イイかんじ　ですよー\p"
	.string "このコ　だったら　わたし\n"
	.string "むねをはって　こうかんに　だせます！\p"
	.string "どうです？\n"
	.string "わたしの　この　{STR_VAR_2}\l"
	.string "{STR_VAR_1}と　こうかん　しません？$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "わー　かわいい　ですねー⋯⋯！\n"
	.string "どうも　ありがとう\l"
	.string "たいせつに　しますよ！\p"
	.string "あっ　{STR_VAR_2}も\n"
	.string "よろしく　おねがい　します！$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "あ　ゴメンなさい！\n"
	.string "わたし　{STR_VAR_1}　いがいとは\l"
	.string "こうかん　するつもり　ないんでー$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "あ　やめますか！\n"
	.string "べつに　いいですよ\l"
	.string "また　こんど　きてくださいー$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "うふふ！\n"
	.string "エネコが　おもってたより　ずっと\l"
	.string "かわいくて　ほんと　うれしいですー$"
