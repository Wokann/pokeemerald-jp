@ LilycoveCity_ContestHall scripts (JP map g13 m5 @ 0x082077B9)

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1:: @ 0x082077BA
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2:: @ 0x082077C3
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl:: @ 0x082077CC
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor:: @ 0x082077D5
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC:: @ 0x082077DE
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge:: @ 0x082077F5
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1:: @ 0x0820780C
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2:: @ 0x08207823
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3:: @ 0x0820783A
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4:: @ 0x08207851
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1:: @ 0x08207868
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2:: @ 0x08207871
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3:: @ 0x08207888
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4:: @ 0x0820789F
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC:: @ 0x082078B6
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge:: @ 0x082078CD
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1:: @ 0x082078E4
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2:: @ 0x082078FB
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3:: @ 0x08207912
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4:: @ 0x08207929
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1:: @ 0x08207940
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2:: @ 0x08207957
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3:: @ 0x0820796E
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC:: @ 0x08207985
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge:: @ 0x0820799C
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1:: @ 0x082079B3
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2:: @ 0x082079CA
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3:: @ 0x082079E1
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4:: @ 0x082079F8
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1:: @ 0x08207A0F
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2:: @ 0x08207A3A
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3:: @ 0x08207A51
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign:: @ 0x08207A68
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign:: @ 0x08207A71
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign:: @ 0x08207A7A
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest: @ 0x08207A83
	.string "うつくしさ　コンテストで\n"
	.string "ゆうしょうした　この　ポケモンを\l"
	.string "きょうは　かしこさ　コンテストで\l"
	.string "ゆうしょう　させたんだぜ！\p"
	.string "ああ　じぶんの　さいのうが　こわい⋯⋯$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests: @ 0x08207AD4
	.string "なんども　コンテストに　でていて\n"
	.string "なんとなく　わかって　きたんだけど\p"
	.string "たとえば　かっこいいコンテストで\n"
	.string "かっこいいわざを　だすと　うけるけど\l"
	.string "かしこいアピールや　かわいいアピールは\l"
	.string "なぜか　うけが　わるいんだよな⋯⋯$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks: @ 0x08207B41
	.string "さっき　ゆうしょう　した　おにいさん\n"
	.string "すっごい　たくさんの　しゅるいの\l"
	.string "ポロックを　もってた！\p"
	.string "あれだけ　もってれば\n"
	.string "ゆうしょう　できるのかな？$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous: @ 0x08207B8A
	.string "かーっ　ひろいね　ここは！\n"
	.string "いなかの　コンテスト　かいじょう　とは\l"
	.string "きんちょうかんが　ちがうね！$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal: @ 0x08207BBB
	.string "しかい“はあい　かしこい　ポケモンと\n"
	.string "そして　トレーナーの　みなさーん！\l"
	.string "がんばってくださーーい！\l"
	.string "レッツ！　アピール！！$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest: @ 0x08207BF9
	.string "しんさいん“コンテスト　たのしんでますか？\p"
	.string "おともだちを　3にん　つれてくれば\n"
	.string "4にん　いっしょに　さんか　できますよ！$"

LilycoveCity_ContestHall_Text_EnteredWrongContest: @ 0x08207C36
	.string "あわわわ⋯⋯\n"
	.string "でる　コンテスト　まちがえた⋯⋯\p"
	.string "たくましい　ポケモンを\n"
	.string "かしこさ　コンテストに⋯⋯\p"
	.string "よ　よしっ\n"
	.string "かしこそうな　いわくだき　たのむぞ！$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart: @ 0x08207C81
	.string "わしが　ながねん\n"
	.string "ちしきの　すべてを　かけて\l"
	.string "かしこく　そだてた　ポケモン！\p"
	.string "わかい　やつらの　ポケモン　なんぞに\n"
	.string "そう　やすやすと　まけたりは　せんぞ！\p"
	.string "ばあさん　みとるかー！？$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext: @ 0x08207CDC
	.string "よし！　おれの　ポケモンが\n"
	.string "このつぎに　かしこい　わざをだせば\l"
	.string "いっきに　かいじょうが　エキサイトするぞ！$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife: @ 0x08207D12
	.string "やだあ！\p"
	.string "わたしの　ズバットちゃんの\n"
	.string "きゅうけつが　あんまり　すてきで\l"
	.string "つづけて　なんども　だしてたら\l"
	.string "なんか　がっかり　されちゃってるー！$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa: @ 0x08207D59
	.string "キャー！　おじいさん　すてきー！$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves: @ 0x08207D6A
	.string "おなじ　ポケモンを　つかっていても\n"
	.string "トレーナーに　よって\l"
	.string "ぜんぜん　ちがう　わざで\l"
	.string "アピールして　くるんだよね\p"
	.string "それは　しょうぶと　いっしょだね！$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers: @ 0x08207DB4
	.string "トレーナーより　ポケモンの　ほうが\n"
	.string "あたま　よさそうに　みえるなあ$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests: @ 0x08207DD6
	.string "やっぱり　かしこさ　コンテストよ！\p"
	.string "ちせいてきな　みどりいろが\n"
	.string "うーん　クールだわー！$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest: @ 0x08207E02
	.string "しかい“あら？　あなたも\n"
	.string "うつくしさ　コンテストに　でるの？\l"
	.string "がんばってね！$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty: @ 0x08207E29
	.string "しんさいん“どの　ポケモンも\n"
	.string "じつに　うつくしい　ですなぁ！\p"
	.string "おもわず　さいてんを　わすれますよ！$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty: @ 0x08207E5B
	.string "こんなに　うつくしい　ポケモン\n"
	.string "ほかに　いないわよ　ねえ\p"
	.string "みんなの　めを　くぎづけに　しちゃうわ！$"

LilycoveCity_ContestHall_Text_OverdidGrooming: @ 0x08207E8D
	.string "うわーん！\p"
	.string "この　コンテストの　ために\n"
	.string "いっしょけんめい　けづくろい　したら\p"
	.string "やりすぎて　あたしの　ポケモン\n"
	.string "ボサボサに　なっちゃった！\p"
	.string "どうしよう⋯⋯$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam: @ 0x08207EDA
	.string "この　まぶしすぎる　オーロラビームに\n"
	.string "しんさいんも　めを　あけられない！\p"
	.string "⋯⋯あれ？\n"
	.string "それじゃ　いみが　ないのか？$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe: @ 0x08207F14
	.string "この　きれいな　ポケモン\n"
	.string "あたしの　わかい　ころに　そっくり！\p"
	.string "って　いったら⋯⋯　とうちゃんが\n"
	.string "のんでた　おちゃを　ふきだしたよ\p"
	.string "あたし　なんか　へんなこと　いったかね？$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy: @ 0x08207F6B
	.string "やっぱり　じょせいと　しては\p"
	.string "うつくしさコンテストで　かてると\n"
	.string "いつもより　ちょっぴり　うれしいのよねー！$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon: @ 0x08207FA1
	.string "うわっはっは！\p"
	.string "べっぴんな　ポケモンちゃん　が\n"
	.string "いっぱいだ⋯⋯\l"
	.string "こりゃ　はなやかで　ええのう！$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone: @ 0x08207FD1
	.string "ただ　うつくしい　だけじゃ\n"
	.string "なかなか　かてないわよ！\p"
	.string "あたしの　ポケモンみたいに\n"
	.string "おていれして　ツヤツヤ　じゃなきゃ！$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest: @ 0x0820800D
	.string "しかい“あら　あらー！\n"
	.string "いまは　コンテスト　ちゅう　ですよー！\p"
	.string "うけつけで　エントリー　してから\n"
	.string "でて　くださーい！　ねっ！$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals: @ 0x0820804C
	.string "しんさいん“おお\n"
	.string "みんな　かわいい　アピールだなあ！\p"
	.string "おおっ　なんて　かわいい\n"
	.string "みずあそびの　アピールなんだろう！$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted: @ 0x08208086
	.string "ああ　ぼくの　ルリリちゃんが\n"
	.string "ほかの　ポケモンに　きを　とられちゃった！$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest: @ 0x082080AB
	.string "わたしの　ポケモンって　しょうぶだと\n"
	.string "1ども　かった　こと　ないけど\l"
	.string "コンテストは　おとくい　なのよ！$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel: @ 0x082080DF
	.string "ぼくの　ポケモンの　かれいな\n"
	.string "はなびらのまい⋯⋯\l"
	.string "だれにも　じゃまは　させないぞ！$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter: @ 0x08208109
	.string "どなたの　ポケモンも\n"
	.string "ほんとうに　かわいいわねえ\p"
	.string "でも　わたしの　ポケモンが\n"
	.string "かわいく　アピール　すれば⋯⋯\p"
	.string "きっと　もっと　かわいい　はずよ$"

LilycoveCity_ContestHall_Text_MyChildIsInContest: @ 0x08208151
	.string "うちのこが　コンテストに　でてるんですよ$"

LilycoveCity_ContestHall_Text_ComeOnDear: @ 0x08208166
	.string "ほらっ　がんばって！\n"
	.string "あなたの　ポケモンが　いちばんよっ！$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest: @ 0x08208184
	.string "ワシは　あの　おんなのこが\n"
	.string "いちばん　かわいいと　おもうな⋯⋯\p"
	.string "えっ？　ポケモンの　みためを\n"
	.string "くらべてるんか！？$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn: @ 0x082081BD
	.string "ああん　みてたら\n"
	.string "あの　ポケモン　ほしく　なっちゃった\l"
	.string "つかまえに　いこっと！$"

LilycoveCity_ContestHall_Text_BeautyContestStage: @ 0x082081E5
	.string "うつくしさコンテスト　ステージ\n"
	.string "ビューティフル　ポケモンに　クラクラ！$"

LilycoveCity_ContestHall_Text_CuteContestStage: @ 0x08208209
	.string "かわいさコンテスト　ステージ\n"
	.string "キュートな　ポケモンに　ウキウキ！$"

LilycoveCity_ContestHall_Text_SmartContestStage: @ 0x0820822A
	.string "かしこさコンテスト　ステージ\n"
	.string "インテリ　ポケモンに　トロトロ！$"
