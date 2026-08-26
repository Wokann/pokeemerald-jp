@ RustboroCity_DevonCorp_1F scripts (JP map g11 m0 @ 0x08201030)

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition: @ 0x08201036
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs:: @ 0x08201040
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee:: @ 0x0820104C
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright:: @ 0x0820106A
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered:: @ 0x08201074
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard:: @ 0x0820107E
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome:: @ 0x082010A5
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed:: @ 0x082010AF
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter:: @ 0x082010B9
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp:: @ 0x082010E0
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed:: @ 0x082010EA
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay:: @ 0x082010F4
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay:: @ 0x082010FD
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp: @ 0x08201106
	.string "いらっしゃいませ！\n"
	.string "デボン　コーポレーション　です！\p"
	.string "みなさまの　せいかつに　やくだつ\n"
	.string "どうぐや　くすりを　おつくりしてます！$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed: @ 0x08201146
	.string "ドジな　けんきゅういんが\n"
	.string "にもつを　とられちゃって⋯⋯$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct: @ 0x08201162
	.string "おっ！　ランニングシューズ！\p"
	.string "じぶんたちの　かいしゃの　しょうひんを\n"
	.string "じっさいに　つかっている　ひとを　みると\l"
	.string "すごく　うれしくなるよね！$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright: @ 0x082011A8
	.string "たしかに　あの　にもつは\n"
	.string "だいじな　もの　だけど\l"
	.string "ほかの　ひとが　ぬすんでいっても\l"
	.string "つかえないと　おもうんだよね\p"
	.string "ぼくの　すいりでは　あの　どろぼう⋯⋯\n"
	.string "たんなる　マヌケ　なんじゃないかな？$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered: @ 0x08201208
	.string "どうやら　デボンのにもつは\n"
	.string "もどってきた　らしいね$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter: @ 0x08201222
	.string "おっと　かんけいしゃ　いがいの　かたは\n"
	.string "ここから　さきには　はいれませんよ！$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed: @ 0x08201249
	.string "どろぼうに　にもつを　うばわれるなんて\n"
	.string "なんて　ドジなんだろう⋯⋯$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere: @ 0x0820126B
	.string "やあ！\n"
	.string "きみなら　いつでも　だいかんげい　だよ！$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay: @ 0x08201284
	.string "いしや　きんぞくの　サンプルが\n"
	.string "ガラスケースの　なかに　ならんでいる！\p"
	.string "パネルに　せつめいが　かいてあるから\n"
	.string "よんでみよう⋯⋯\p"
	.string "‘デボン　コーポレーションは　もともと\n"
	.string "　やまから　いしを　きりだしたり\p"
	.string "　さてつから　てつざいを　つくるために\n"
	.string "　せつりつ　された　かいしゃ　です’\p"
	.string "‘やがて　デボン　コーポレーションは\n"
	.string "　ざいりょう　だけに　とどまらず\p"
	.string "　さまざまな　こうぎょう　せいひんも\n"
	.string "　つくるように　なったのです’$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay: @ 0x08201357
	.string "いろんな　どうぐの　しさくひんが\n"
	.string "ガラスケースの　なかに　ならんでいる！\p"
	.string "パネルに　せつめいが　かいてあるから\n"
	.string "よんでみよう⋯⋯\p"
	.string "‘げんざい　デボン　コーポレーションでは\n"
	.string "　こうぎょう　せいひんの　ほかにも\l"
	.string "　にちようひんや　くすりなど\p"
	.string "　ひとびとの　くらしに　やくだつ　ものを\n"
	.string "　かいはつ　しています’\p"
	.string "‘また　げんざいでは　モンスターボールや\n"
	.string "　ポケナビなどの　トレーナーようひんも\l"
	.string "　てがけるように　なりました’$"
