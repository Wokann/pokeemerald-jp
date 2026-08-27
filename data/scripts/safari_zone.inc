	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "サファリゾーンを\n"
	.string "このまま　しゅうりょう　しますか？$"

SafariZone_Text_TimesUp:
	.string "ピンポーン！　じかん　でーす！\n"
	.string "サファリゲームを　しゅうりょう　します$"

SafariZone_Text_OutOfBalls:
	.string "サファリボールを　つかいきったので\n"
	.string "サファリゲームを　しゅうりょう　します$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "ポロックおきばに　ポロックを　おきますか？$"

SafariZone_Text_PokeblockStillHere:
	.string "まだ　{STR_VAR_1}が　のこっています$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{STR_VAR_1}を\n"
	.string "おきました！$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "サファリゾーンへ　ようこそ！\p"
	.string "ここでは　ホウエンでは　なかなか\n"
	.string "みることの　できない　ポケモンを\p"
	.string "しぜんの　すがたの　まま\n"
	.string "めに　することが　できます\p"
	.string "また　ポケモントレーナーの\n"
	.string "ようぼうに　おこたえ　して\p"
	.string "ポケモンを\n"
	.string "つかまえる　ことも　できます！\p"
	.string "サファリゾーンを　たのしんで　いってね！$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "サファリゾーンへ　ようこそ！\n"
	.string "サファリゾーンは　はじめて　ですか？$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "サファリゾーンを　たのしんで　いってね！$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "サファリゾーンでは\n"
	.string "30この　サファリボールを　つかって\l"
	.string "ポケモンを　つかまえる　ことが　できます\p"
	.string "サファリボールを　つかいきるか\n"
	.string "500ぽ　あるくと\p"
	.string "ゲームは　しゅうりょう　です\p"
	.string "サファリゾーンを　たのしんで　いってね！$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "サファリゾーンへ　ようこそ！\p"
	.string "500えんで　ポケモン　つかまえほうだい！\n"
	.string "サファリゲームに　さんか　しますか？$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "そうですか\n"
	.string "こんど　ぜひ　さんか　してください！$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "おかねが　たりませんよ！$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "それでは　500えん　いただきます$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "では　サファリボールを　どうぞ！$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER}は　サファリボールを\n"
	.string "30こ　うけとった！$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "じかんに　なりましたら\n"
	.string "こちらから　おしらせ　しますので\p"
	.string "ぞんぶんに　おたのしみ　ください！\n"
	.string "では　いってらっしゃい！$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "おきゃくさん！\n"
	.string "ボックスが　いっぱい　ですよ！$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "あ！　おきゃくさん\n"
	.string "ポロックケースを　おもちで　ないですね？\p"
	.string "サファリゾーンは　ポロックを　つかうと\n"
	.string "より　おたのしみ　いただけますので\p"
	.string "ぜひ　ポロックケースを\n"
	.string "おもちに　なって　おこし　ください\p"
	.string "ポロックケースは\n"
	.string "ミナモシティの　コンテストかいじょうで\l"
	.string "うけとることが　できますよ$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "まだ　じかんが　のこっていますが\n"
	.string "サファリゾーンを　やめますか？$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "では　ひきつづき　おたのしみ　ください！$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "わかりました\p"
	.string "それでは　のこりの　サファリボールを\n"
	.string "おあずかり　します\p"
	.string "おつかれさまでした\n"
	.string "また　ごりよう　ください$"

SafariZone_South_Text_GoodLuck:
	.string "それでは　いってらっしゃい！\l"
	.string "なにか　ありましたら\n"
	.string "わたしに　こえを　かけて　くださいね$"

SafariZone_South_Text_Boy:
	.string "しってた？\p"
	.string "あの　しかくい　はこに　ポロックを　おくと\n"
	.string "ポケモンが　あつまって　くるんだよ！$"

SafariZone_South_Text_Man:
	.string "この　さきに　いきたい　けど\n"
	.string "じてんしゃ　もって　くるの　わすれた⋯⋯\p"
	.string "おくに　めずらしい　ポケモンが\n"
	.string "いそうな　きが　するのに！$"

SafariZone_Southwest_Text_Woman:
	.string "ポケモンに　ポロックを　なげても\n"
	.string "しらんぷり　される　ときが　あるのよ\p"
	.string "ポケモンにも　すききらいが　あるのかしら？$"

SafariZone_Northwest_Text_Man:
	.string "ぜぇ⋯⋯　ぜぇ⋯⋯\n"
	.string "やっと　ここまで　きたけど⋯⋯\p"
	.string "つかれちゃって　ポケモン　つかまえる\n"
	.string "げんきも　のこって　ないよ⋯⋯$"

SafariZone_North_Text_Fisherman:
	.string "ホウエンに　いない　みずポケモンを\n"
	.string "さがしに　きたんだけど⋯⋯\p"
	.string "みずうみは　どこにあるのか\n"
	.string "きみ　しってるかい？$"

SafariZone_North_Text_Man:
	.string "ここで　めずらしい　ポケモンを\n"
	.string "たくさん　つかまえて\l"
	.string "ともだちと　こうかん　するんだ！$"

SafariZone_South_Text_Youngster:
	.string "ポロックおきばに　おいた　ポロックが\n"
	.string "いつのまにか　なくなっていた⋯⋯\p"
	.string "しらない　うちに\n"
	.string "ポケモンが　たべちゃったのかな？$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "サファリゾーンの　おとくな　じょうほう！\p"
	.string "であった　ポケモンに\n"
	.string "ポロックを　なげると　にげにくく　なります！$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "あるき　つかれたら　ちょっと　ひといき！\n"
	.string "‘みんなの　きゅうけいじょ'$"

SafariZone_RestHouse_Text_Youngster:
	.string "おれ　ポロック　もってないけど\n"
	.string "ポケモン　たくさん　つかまえたよ\p"
	.string "ちかづいて　ボールを　なげる　だけで\n"
	.string "けっこう　つかまえられる　もんだよ！$"

SafariZone_RestHouse_Text_PsychicM:
	.string "ポロックを　つかうと　いつもより\n"
	.string "ちょっぴり　にげにくく　なるみたい\p"
	.string "だから　にげにくい　ポケモンに　つかっても\n"
	.string "あんまり　いみが　ないかもね$"

SafariZone_RestHouse_Text_FatMan:
	.string "ポロックおきばに　ポロック　おいて\n"
	.string "ポケモンを　つかまえると\p"
	.string "おなじ　ような　せいかくの　ポケモンが\n"
	.string "あつまる　きが　するなあ$"

SafariZone_South_Text_AreaOffLimits1:
	.string "このさきは　ただいま　こうじちゅう　のため\n"
	.string "たちいり　きんしに　なっています$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "サファリゾーンの　かくちょう　こうじが\n"
	.string "しゅうりょう　しました\p"
	.string "あたらしい　エリアも\n"
	.string "たのしんで　くださいね！$"

SafariZone_South_Text_AreaOffLimits2:
	.string "このさきは　ただいま　こうじちゅう　のため\n"
	.string "たちいり　きんしに　なっています$"

SafariZone_Southeast_Text_LittleGirl:
	.string "わーい　わーい！\n"
	.string "はじめて　みる　ポケモンが　いっぱい！$"

SafariZone_Southeast_Text_FatMan:
	.string "このへんに　いる　ポケモンは\n"
	.string "はじめて　みるやつ　ばっかりだ！\p"
	.string "そんな　めずらしい　ポケモンが\n"
	.string "つかまえ　ほうだい　だなんて　すげー！$"

SafariZone_Southeast_Text_RichBoy:
	.string "このへんに　いる　ポケモンは\n"
	.string "ホウエンちほう　いがいの　とちに\l"
	.string "すんでる　ポケモン　らしいぜ$"

SafariZone_Northeast_Text_Boy:
	.string "サファリボールが　あと　すこししか\n"
	.string "のこって　ないんだよ\l"
	.string "なにを　つかまえるか　まよっちゃうなあ$"

SafariZone_Northeast_Text_Woman:
	.string "ピカチュウが　ここで　みられるって\n"
	.string "きいたんだけど　どこに　いるのかしら$"

SafariZone_Northeast_Text_Girl:
	.string "あーん　ポケモンが\n"
	.string "なかなか　つかまらないわっ！\p"
	.string "このままじゃ　にゅうじょうりょうの\n"
	.string "モトが　とれないわっ！$"
