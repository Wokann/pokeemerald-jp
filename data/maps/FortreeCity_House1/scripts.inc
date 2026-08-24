@ FortreeCity_House1 scripts (JP map g12 m0 @ 0x082041CA)

FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	@ The JP special table does not mark ChoosePartyMon as waitstate=1.
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	@ JP uses the waitdooranim opcode (0xC5) where US uses waitmoncry.
	waitmoncry_jp
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou: @ 0x0820428B
	.string "うぉー！\n"
	.string "どうしても　{STR_VAR_1}が　ほしーっ！\l"
	.string "⋯⋯と\l"
	.string "こころの　さけびを　きかれて　しまった！\p"
	.string "きいた　からには\n"
	.string "きみの　{STR_VAR_1}と　ボクの　{STR_VAR_2}を\l"
	.string "もちろん　こうかん　するでしょ！$"

FortreeCity_House1_Text_MonYouTakeCare: @ 0x082042E3
	.string "おー　やったー！\p"
	.string "{STR_VAR_1}　よくきたなー！\n"
	.string "{STR_VAR_2}　げんきで　やれよー！$"

FortreeCity_House1_Text_ThisIsntAMon: @ 0x08204305
	.string "いやソレ\n"
	.string "{STR_VAR_1}じゃないでしょ$"

FortreeCity_House1_Text_YouWontTradeMe: @ 0x08204314
	.string "え　こうかん　しないの？\n"
	.string "こころの　さけびを　きいたくせに⋯⋯$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong: @ 0x08204334
	.string "よし　いまから\n"
	.string "バルビートを　つよく　するぞー！\l"
	.string "プラスルも　つよく　してやってよ！$"

FortreeCity_House1_Text_TradingMemoriesWithOthers: @ 0x0820435F
	.string "ひとと　ポケモンを　こうかん　する⋯⋯\p"
	.string "つまりは　それぞれの\n"
	.string "おもいでを　こうかん　しているのじゃな$"

FortreeCity_House1_Text_Zigzagoon: @ 0x08204392
	.string "ジグザグマ“グモモォ？$"
