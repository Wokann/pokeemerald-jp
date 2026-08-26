	.incbin "baserom_jp.gba", 0x247cda, 0x8d
Text_LinkErrorPleaseReset: @ 0x08247D67
	.incbin "baserom_jp.gba", 0x247d67, 0xe4
	.globl gJPText_00247E4B
gJPText_00247E4B: @ 0x08247E4B
	.string "へやからでると　つうしんが\n"
	.string "おわりますが　よろしいですか？$"

	.incbin "baserom_jp.gba", 0x247e69, 0x1e
	.globl gJPText_00247E87
gJPText_00247E87: @ 0x08247E87
	.string "とりこみちゅうの　ようだ⋯$"

	.globl gJPText_00247E95
gJPText_00247E95: @ 0x08247E95
	.string "{B_COPY_VAR_1}の　トレーナーカードを\n"
	.string "みせてもらった！$"

	.globl gJPText_00247EAC
gJPText_00247EAC: @ 0x08247EAC
	.string "{B_COPY_VAR_1}の　トレーナーカードを\n"
	.string "みせてもらった！\p"
	.string "⋯{B_COPY_VAR_2}カードだ！$"

	.incbin "baserom_jp.gba", 0x247ecc, 0x4e
	.globl gJPText_00247F1A
gJPText_00247F1A: @ 0x08247F1A
	.string "トレーナーカードの\n"
	.string "きろくを　かきかえます！$"

	.globl gJPText_00247F31
gJPText_00247F31: @ 0x08247F31
	.string "では　また　どうぞ！$"

	.incbin "baserom_jp.gba", 0x247f3c, 0xa7
	.globl gJPText_00247FE3
gJPText_00247FE3: @ 0x08247FE3
	.string "さんか　したい　ひとは\n"
	.string "カウンターに　おこしください$"

	.incbin "baserom_jp.gba", 0x247ffe, 0x799
	.globl gJPText_00248797
gJPText_00248797: @ 0x08248797
	.string "こんにちは！\p"
	.string "ワイヤレス　つうしんが\n"
	.string "はじめての　かたですね？\p"
	.string "わたくし　あんないやくの\n"
	.string "アオナと　もうします\p"
	.string "ポケモンセンター　2かいの\n"
	.string "ごあんないを　いたしますので\l"
	.string "こちらへ　どうぞ！$"

	.globl gJPText_002487F6
gJPText_002487F6: @ 0x082487F6
	.string "こちら　2かいには\n"
	.string "ふたつの　おへやが　ございます\p"
	.string "ひとつめは　ひだりがわの　おへや\n"
	.string "ユニオン　ルーム！\p"
	.string "あなたの　ちかくで\n"
	.string "ユニオン　ルームに　はいっている\l"
	.string "みしらぬ　おともだちと\l"
	.string "いろいろな　コミュニケーションが\l"
	.string "たのしめます！\p"
	.string "ふたつめは　みぎがわの　おへや\n"
	.string "ダイレクト　コーナー！\p"
	.string "あなたの　しっている　おともだちと\n"
	.string "ポケモンの　こうかんや\l"
	.string "たいせん　などを\l"
	.string "たのしむ　ことが　できます！\p"
	.string "もし　ワイヤレスアダプタが\n"
	.string "つながって　いない　ばあいでも\p"
	.string "みぎがわの　おへやで\n"
	.string "ケーブル　つうしんが　たのしめます\p"
	.string "それでは\p"
	.string "ワイヤレス　つうしんを\n"
	.string "たのしんで　くださいね！$"

	.incbin "baserom_jp.gba", 0x248916, 0x1de
LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist: @ 0x08248AF4
	.incbin "baserom_jp.gba", 0x248af4, 0x10cd
LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer: @ 0x08249BC1
	.incbin "baserom_jp.gba", 0x249bc1, 0x41c
LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank: @ 0x08249FDD
	.incbin "baserom_jp.gba", 0x249fdd, 0x12d
LilycoveCity_ContestLobby_Text_ComeThroughHere: @ 0x0824A10A
	.incbin "baserom_jp.gba", 0x24a10a, 0x75
	.globl gJPText_0024A17F
gJPText_0024A17F: @ 0x0824A17F
	.string "しかい“はい！　これより\n"
	.string "{B_COPY_VAR_3}　ランクの\l"
	.string "ポケモン　{B_COPY_VAR_2}コンテストが\l"
	.string "はじまります！\p"
	.string "しゅつじょう　される　トレーナーと\n"
	.string "ポケモンの　みなさんは　こちら！$"

	.incbin "baserom_jp.gba", 0x24a1cd, 0x56
	.globl gJPText_0024A223
gJPText_0024A223: @ 0x0824A223
	.string "しかい“エントリーナンバー　{B_COPY_VAR_2}ばん！\n"
	.string "{B_COPY_VAR_1}さんの　{B_COPY_VAR_3}　です！$"

	.globl gJPText_0024A244
gJPText_0024A244: @ 0x0824A244
	.string "しかい“さあ\n"
	.string "ポケモンの　しょうかいが　おわりました\l"
	.string "1じ　しんさに　はいりましょう！\p"
	.string "かいじょうの　おきゃくさまに　よる\n"
	.string "ポケモンの　にんき　とうひょうです！\p"
	.string "では　さっそく　はじめましょう！\n"
	.string "とうひょう　おねがいします！$"

	.globl gJPText_0024A2B5
gJPText_0024A2B5: @ 0x0824A2B5
	.string "　　　　とうひょう　ちゅう⋯$"

	.globl gJPText_0024A2C4
gJPText_0024A2C4: @ 0x0824A2C4
	.string "さあ！\n"
	.string "いま　とうひょうが　おわりました！\l"
	.string "しゅうけいを　している　あいだに\l"
	.string "2じ　しんさに　うつりましょう！\p"
	.string "2じ　しんさは　いよいよ\n"
	.string "おまちかねの　アピールタイム！\l"
	.string "わざで　アピール　しまくりましょうー！\p"
	.string "では　はりきって　どうぞ！\n"
	.string "レッツ！　アピール！$"

	.globl gJPText_0024A346
gJPText_0024A346: @ 0x0824A346
	.string "しかい“はあい　そこまでえーー！$"

	.globl gJPText_0024A357
gJPText_0024A357: @ 0x0824A357
	.string "みなさん　すばらしい　アピールでした！\n"
	.string "これで　すべて　しゅうりょう　です！\l"
	.string "おつかれさまでした！$"

	.globl gJPText_0024A389
gJPText_0024A389: @ 0x0824A389
	.string "さて　のこるは\n"
	.string "ドキドキの　けっかはっぴょう　ですね！\l"
	.string "はっぴょうは　しんさいんの　ほうから\l"
	.string "おこなわれます！$"

	.globl gJPText_0024A3C1
gJPText_0024A3C1: @ 0x0824A3C1
	.string "しんさいん“では⋯　はっぴょう　します！$"

	.globl gJPText_0024A3D6
gJPText_0024A3D6: @ 0x0824A3D6
	.string "しかい“エントリーナンバー　{B_COPY_VAR_2}ばん\n"
	.string "{B_COPY_VAR_3}さん！　そして　{B_COPY_VAR_1}！\l"
	.string "おめでとう　ございます！$"

	.globl gJPText_0024A404
gJPText_0024A404: @ 0x0824A404
	.string "しかい“おめでとう　ございます！\n"
	.string "また　さんか　してくださいね！$"

	.globl gJPText_0024A425
gJPText_0024A425: @ 0x0824A425
	.string "しかい“さあ！\n"
	.string "しょうひんを　おうけとり　ください！$"

	.globl gJPText_0024A440
gJPText_0024A440: @ 0x0824A440
	.string "しょうひんと　して\n"
	.string "この　リボンを　おうけとり　ください！$"

	.globl gJPText_0024A45E
gJPText_0024A45E: @ 0x0824A45E
	.string "{MUS_RG_VS_TRAINER}は　リボンを　もらった！$"

	.globl gJPText_0024A46D
gJPText_0024A46D: @ 0x0824A46D
	.string "{MUS_RG_VS_TRAINER}は　リボンを\n"
	.string "{B_COPY_VAR_1}に　つけて　あげた！$"

	.globl gJPText_0024A483
gJPText_0024A483: @ 0x0824A483
	.string "それでは　しょうひんは　あとで\n"
	.string "うけつけで　おうけとり　ください！\l"
	.string "またの　さんかを　おまち　してます！$"

	.incbin "baserom_jp.gba", 0x24a4b8, 0x57
LilycoveCity_ContestLobby_Text_ProgressWillBeSaved: @ 0x0824A50F
	.incbin "baserom_jp.gba", 0x24a50f, 0x1e
LilycoveCity_ContestLobby_Text_ParticipateAnotherTime: @ 0x0824A52D
	.incbin "baserom_jp.gba", 0x24a52d, 0xdf
LilycoveCity_ContestLobby_Text_Transmitting: @ 0x0824A60C
	.incbin "baserom_jp.gba", 0x24a60c, 0xd
LilycoveCity_ContestLobby_Text_TransmissionError: @ 0x0824A619
	.incbin "baserom_jp.gba", 0x24a619, 0x10
LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest: @ 0x0824A629
	.incbin "baserom_jp.gba", 0x24a629, 0x1d
LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice: @ 0x0824A646
	.incbin "baserom_jp.gba", 0x24a646, 0x17
LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel: @ 0x0824A65D
	.incbin "baserom_jp.gba", 0x24a65d, 0x4d
LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX: @ 0x0824A6AA
	.incbin "baserom_jp.gba", 0x24a6aa, 0x3e
LilycoveCity_ContestLobby_Text_ContestBeginShortly: @ 0x0824A6E8
	.incbin "baserom_jp.gba", 0x24a6e8, 0x13
LilycoveCity_ContestLobby_Text_LinkContestReception: @ 0x0824A6FB
	.incbin "baserom_jp.gba", 0x24a6fb, 0x39
LilycoveCity_ContestLobby_Text_WhichTopic2: @ 0x0824A734
	.incbin "baserom_jp.gba", 0x24a734, 0x10
LilycoveCity_ContestLobby_Text_EnterContest3: @ 0x0824A744
	.incbin "baserom_jp.gba", 0x24a744, 0x11
LilycoveCity_ContestLobby_Text_EnterWhichContest3: @ 0x0824A755
	.incbin "baserom_jp.gba", 0x24a755, 0x14
LilycoveCity_ContestLobby_Text_MonInNoCondition2: @ 0x0824A769
	.incbin "baserom_jp.gba", 0x24a769, 0x27
LilycoveCity_ContestLobby_Text_EggCannotTakePart2: @ 0x0824A790
	.incbin "baserom_jp.gba", 0x24a790, 0x1e
LilycoveCity_ContestLobby_Text_EnterWhichPokemon3: @ 0x0824A7AE
	.incbin "baserom_jp.gba", 0x24a7ae, 0x14
LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader: @ 0x0824A7C2
	.incbin "baserom_jp.gba", 0x24a7c2, 0x3f
LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode: @ 0x0824A801
	.incbin "baserom_jp.gba", 0x24a801, 0x6b
LilycoveCity_ContestLobby_Text_ExplainLinkContest: @ 0x0824A86C
	.incbin "baserom_jp.gba", 0x24a86c, 0x149
LilycoveCity_ContestLobby_Text_ExplainEMode: @ 0x0824A9B5
	.incbin "baserom_jp.gba", 0x24a9b5, 0xd5
LilycoveCity_ContestLobby_Text_ExplainGMode: @ 0x0824AA8A
	.incbin "baserom_jp.gba", 0x24aa8a, 0x87
LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode: @ 0x0824AB11
	.incbin "baserom_jp.gba", 0x24ab11, 0x57
LilycoveCity_ContestLobby_Text_WhichContestMode: @ 0x0824AB68
	.incbin "baserom_jp.gba", 0x24ab68, 0x7af
