@ JP trainer text begins at 0x0825941F.  Preserve unreviewed text as raw
@ data while progressively moving verified map families to US-aligned labels.
	.incbin "baserom_jp.gba", 0x25941f, 0xf8

Route102_Text_CalvinIntro: @ 0x08259517
	.string "ポケモン　つれていれば\n"
	.string "キミも　りっぱな　ポケモントレーナー！\l"
	.string "ボクの　ちょうせん　うけるよね！$"

Route102_Text_CalvinDefeated: @ 0x08259548
	.string "ああ　まけた⋯⋯\n"
	.string "もっと　そだてておけば　よかったよ$"

Route102_Text_CalvinPostBattle: @ 0x08259563
	.string "キミ　つよいなら　つよいって\n"
	.string "さいしょから　いって　くれよな！$"

Route102_Text_CalvinRegister: @ 0x08259583
	.string "ボク　あれから　がんばってるよ！\n"
	.string "こんど　たたかいたい　から\l"
	.string "ポケナビ　とうろく　してよ！$"

Route102_Text_CalvinRegisterShort: @ 0x082595B1
	.string "こんど　また　たたかいたい　から\n"
	.string "ポケナビ　とうろく　してよ！$"

Route102_Text_CalvinRematchIntro: @ 0x082595D1
	.string "キミに　まけてから　ひっしに\n"
	.string "ポケモン　そだてたんだ！　もちろん\l"
	.string "ボクの　ちょうせん　うけるよね！$"

Route102_Text_CalvinRematchDefeated: @ 0x08259603
	.string "ああ　まけた⋯⋯\n"
	.string "そだてかた　わるいのかな$"

Route102_Text_CalvinRematchPostBattle: @ 0x08259619
	.string "キミが　つよくなるなら\n"
	.string "ボクも　もっと　つよくなって　みせるよ！$"

Route102_Text_AllenIntro: @ 0x0825963A
	.string "きみ　トレーナーに　なったばかり？\n"
	.string "おたがい　しょしんしゃ　だね！$"

Route102_Text_AllenDefeated: @ 0x0825965C
	.string "かてると　おもったから\n"
	.string "こえを　かけたのに！$"

Route102_Text_AllenPostBattle: @ 0x08259673
	.string "まだ　1かいも　かってない⋯⋯\n"
	.string "はやく　かちたいなあ⋯⋯$"

Route102_Text_RickIntro: @ 0x08259690
	.string "おっと！　めが　あったな！\n"
	.string "むしポケモンで　あいてを　するぜ！$"

Route102_Text_RickDefeated: @ 0x082596B0
	.string "まけてしまった！$"

Route102_Text_RickPostBattle: @ 0x082596B9
	.string "めが　あった　トレーナーには\n"
	.string "しょうぶを　いどむのが　きまりさ！$"

Route102_Text_TianaIntro: @ 0x082596DA
	.string "わたしは　どんどん　かちぬいて\n"
	.string "さいきょうの　トレーナーを　めざすのよ！\p"
	.string "あなたも　きょうりょく　してね！$"

Route102_Text_TianaDefeated: @ 0x08259710
	.string "わたしが　あなたに\n"
	.string "きょうりょく　しちゃった　みたいね⋯⋯$"

Route102_Text_TianaPostBattle: @ 0x0825972E
	.string "どんどん　かちぬくには\n"
	.string "もっと　たくさん　ポケモンを\l"
	.string "つかまえないと　いけない　みたいね！$"

Route103_Text_DaisyIntro: @ 0x0825975C
	.string "こころ　やすらぐ　かおりに\n"
	.string "あなたも　さそわれたのですね⋯⋯$"

Route103_Text_DaisyDefeated: @ 0x0825977B
	.string "わたくしの　かおりに\n"
	.string "まどわされませんでしたね⋯⋯$"

Route103_Text_DaisyPostBattle: @ 0x08259795
	.string "アロマとは　かおりのこと⋯⋯\n"
	.string "かおりは　こころと　からだを　いやすのです$"

Route103_Text_AmyIntro: @ 0x082597BA
	.string "クミ“あたしは　クミ！\n"
	.string "こっちは　いもうとの　ルミ！\l"
	.string "ふたりで　いっしょに　たたかうのよ！$"

Route103_Text_AmyDefeated: @ 0x082597E8
	.string "クミ“まけっちゃったよぉ⋯⋯$"

Route103_Text_AmyPostBattle: @ 0x082597F7
	.string "クミ“ふたりを　あいてに　するのって\n"
	.string "いろんな　ことを　かんがえるよね！$"

Route103_Text_AmyNotEnoughPokemon: @ 0x0825981C
	.string "クミ“あら？\n"
	.string "ポケモン　1ひきしか　つれてないんだね！\l"
	.string "それじゃあ　あたしたちと　たたかえないわ！$"

Route103_Text_LivIntro: @ 0x0825984E
	.string "ルミ“あたしたちは　ふたりで　ひとり\n"
	.string "いっしょに　たたかうんだよ！$"

Route103_Text_LivDefeated: @ 0x08259870
	.string "ルミ“まけちゃったよぉ　おねえちゃぁん⋯⋯$"

Route103_Text_LivPostBattle: @ 0x08259886
	.string "ルミ“おねえちゃんと　あたしは\n"
	.string "いきが　ぴったり　あってるのに⋯⋯\p"
	.string "まけちゃったよぉ⋯⋯$"

Route103_Text_AmyLivRegister: @ 0x082598B3
	.string "ルミ“あたしたち　ほんとは\n"
	.string "もっと　つよいんだもん⋯⋯\l"
	.string "ほんとうだから！　こんど　みせるから！$"

Route103_Text_LivNotEnoughPokemon: @ 0x082598E3
	.string "ルミ“あたしたちと　たたかいたいなら\n"
	.string "ポケモンを　2ひき　つれてないと　ダメよ！\l"
	.string "じゃないと　しょうぶに　ならないんだから！$"

Route103_Text_AmyRematchIntro: @ 0x08259922
	.string "クミ“あたしは　クミ！\n"
	.string "こっちは　いもうとの　ルミ！\l"
	.string "ふたりで　いっしょに　たたかうのよ！$"

Route103_Text_AmyRematchDefeated: @ 0x08259950
	.string "クミ“くやしい⋯⋯\n"
	.string "また　かてなかったよぉ⋯⋯$"

Route103_Text_AmyRematchPostBattle: @ 0x08259968
	.string "クミ“ふたりを　あいてに　するのって\n"
	.string "いろんな　ことを　かんがえるよね！$"

Route103_Text_AmyRematchNotEnoughPokemon: @ 0x0825998D
	.string "クミ“あら？\n"
	.string "ポケモン　1ひきしか　つれてないんだね！\l"
	.string "それじゃあ　あたしたちと　たたかえないわ！$"

Route103_Text_LivRematchIntro: @ 0x082599BF
	.string "ルミ“あたしたちは　ふたりで　ひとり\n"
	.string "いつも　いっしょに　たたかうんだよ！$"

Route103_Text_LivRematchDefeated: @ 0x082599E5
	.string "ルミ“また　まけちゃったよぉ\n"
	.string "おねえちゃぁん⋯⋯$"

Route103_Text_LivRematchPostBattle: @ 0x082599FE
	.string "ルミ“おねえちゃんと　あたしは\n"
	.string "いきが　ぴったり　あってるのに⋯⋯\p"
	.string "どうして　また　まけちゃったの？$"

Route103_Text_LivRematchNotEnoughPokemon: @ 0x08259A31
	.string "ルミ“あたしたちと　たたかいたいなら\n"
	.string "ポケモンを　2ひき　つれてないと　ダメよ！\l"
	.string "じゃないと　しょうぶに　ならないんだから！$"

Route103_Text_AndrewIntro: @ 0x08259A70
	.string "つりいとが　からまって　イライラするーっ！\n"
	.string "ええいっ　しょうぶだっ！$"

Route103_Text_AndrewDefeated: @ 0x08259A93
	.string "まけたっ！\n"
	.string "よけいに　イライラするぞーっ！$"

Route103_Text_AndrewPostBattle: @ 0x08259AA9
	.string "ええい　はらだたしい⋯⋯！\n"
	.string "イライライライラ⋯⋯$"

Route103_Text_MiguelIntro: @ 0x08259AC2
	.string "わたしの　ポケモンちゃん\n"
	.string "すごく　かわいいから　みていきたまえ！$"

Route103_Text_MiguelDefeated: @ 0x08259AE3
	.string "あわわ⋯⋯\n"
	.string "わたしの　ポケモンちゃん！$"

Route103_Text_MiguelPostBattle: @ 0x08259AF7
	.string "かわいい　ポケモンちゃんは\n"
	.string "やられた　すがたも　かわいいな⋯⋯$"

Route103_Text_MiguelRegister: @ 0x08259B17
	.string "なんどでも　かわいい　ポケモンちゃんを\n"
	.string "みにきて　もらうんだからね！$"

Route103_Text_MiguelRematchIntro: @ 0x08259B3A
	.string "きみ！　わたしの　ポケモンちゃん\n"
	.string "さらに　かわいく　なったのだ！$"

Route103_Text_MiguelRematchDefeated: @ 0x08259B5B
	.string "ああ！\n"
	.string "わたしの　ポケモンちゃん！$"

Route103_Text_MiguelRematchPostBattle: @ 0x08259B6D
	.string "いっしょに　いれば　いるほど\n"
	.string "ポケモンが　かわいくなって　たまらん！$"

Route103_Text_PeteIntro: @ 0x08259B90
	.string "この　くらいの　きょり\n"
	.string "およいで　わたれば　いーのにさ！$"

Route103_Text_PeteDefeated: @ 0x08259BAD
	.string "おお　やるじゃん$"

Route103_Text_PetePostBattle: @ 0x08259BB6
	.string "なーるほど\p"
	.string "それ　ほど　たよれる　ポケモンなら\n"
	.string "おもわず　なみのり　したくなる　ってもんだ$"

Route103_Text_IsabelleIntro: @ 0x08259BE4
	.string "きゃあ　ぶつかるわ！\n"
	.string "あぶないっ！$"

Route103_Text_IsabelleDefeated: @ 0x08259BF6
	.string "んん⋯⋯$"

Route103_Text_IsabellePostBattle: @ 0x08259BFB
	.string "わたし　およぎが　へたで\n"
	.string "れんしゅう　してたのよ⋯⋯\l"
	.string "ぶつかりそうに　なって　ゴメンね$"

Route103_Text_RhettIntro: @ 0x08259C27
	.string "うぉっ！\n"
	.string "なぜ　こんな　せまいところに！？$"

Route103_Text_RhettDefeated: @ 0x08259C3D
	.string "うぉっ　できる！$"

Route103_Text_RhettPostBattle: @ 0x08259C46
	.string "せまい　ところが\n"
	.string "すき　なのかい　きみは？$"

Route103_Text_MarcosIntro: @ 0x08259C5C
	.string "おれっちの　ギターに　さそわれて\n"
	.string "やって　きたのかーい？$"

Route103_Text_MarcosDefeated: @ 0x08259C79
	.string "おれっちの　ひとりショーが　だいなしだよ$"

Route103_Text_MarcosPostBattle: @ 0x08259C8E
	.string "ひとの　すくない　ところで\n"
	.string "ギターを　ひいていたのに\l"
	.string "こんなにも　あつまって　きたぜ！\p"
	.string "ぷ　プロを　めざして　みるか！$"
Route104_Text_GinaIntro: @ 0x08259CCA
	.string "ナオ“よーし！\n"
	.string "あたしたちの　ポケモンと　たたかうです！$"

Route104_Text_GinaDefeat: @ 0x08259CE7
	.string "ナオ“まけて　すごく　くやしいです$"

Route104_Text_GinaPostBattle: @ 0x08259CF9
	.string "ナオ“うわー　{STRING 0x02}　つよいです！\n"
	.string "あたしたち　もっと　しゅぎょう　するです$"

Route104_Text_GinaNotEnoughMons: @ 0x08259D1F
	.string "ナオ“あら？　ポケモン　1ひき　だけですか！\n"
	.string "じゃあ　あたしたち　たたかわない　です！\p"
	.string "だって　ポケモン　1ひき　だけだと\n"
	.string "ポケモンが　さびしそうで　かわいそう　です！$"

Route104_Text_MiaIntro: @ 0x08259D74
	.string "ミオ“あたしたち　ふたご　だから\n"
	.string "ポケモンしょうぶも　いっしょに　するです！$"

Route104_Text_MiaDefeat: @ 0x08259D9B
	.string "ミオ“ふたりで　しょうぶ　したのに\n"
	.string "まけちゃったです⋯⋯$"

Route104_Text_MiaPostBattle: @ 0x08259DB8
	.string "ミオ“もっと　ポケモン　そだてて\n"
	.string "{STRING 0x02}　みたいに　つよく　なるです！$"

Route104_Text_MiaNotEnoughMons: @ 0x08259DDB
	.string "ミオ“あたしたちと　たたかうですか？\p"
	.string "じゃあ　ポケモンを\n"
	.string "2ひき　つれてないと　ダメですよ！\l"
	.string "だって　あたしたち　つよいもん！$"

Route104_Text_IvanIntro: @ 0x08259E1B
	.string "みずポケモンの　エキスパートとは\n"
	.string "なにを　かくそう　オレのこと！\p"
	.string "⋯⋯え？\n"
	.string "しらないの？$"

Route104_Text_IvanDefeat: @ 0x08259E48
	.string "けっこう　つよいと　おもってたんだけどな\n"
	.string "じぶんのこと⋯⋯　がっかり⋯⋯$"

Route104_Text_IvanPostBattle: @ 0x08259E6D
	.string "つりに　むちゅうに　なってて\n"
	.string "ポケモン　そだてるのを　わすれてたよ⋯⋯$"

Route104_Text_BillyIntro: @ 0x08259E91
	.string "すなはまに　あしあと　つけるのって\n"
	.string "たのしーよねー！$"

Route104_Text_BillyDefeat: @ 0x08259EAC
	.string "うへーっ！\n"
	.string "クツに　すなが　はいって　ジャリジャリする！$"

Route104_Text_BillyPostBattle: @ 0x08259EC9
	.string "すなはまを　ボクの　あしあとで\n"
	.string "いっぱいに　したいんだけど\l"
	.string "すぐに　きえちゃうんだよなぁ$"

Route104_Text_HaleyIntro: @ 0x08259EF6
	.string "しょうぶ　しようかな⋯⋯\n"
	.string "やめとこうかな⋯⋯\p"
	.string "えーい！　たたかっちゃえ！$"

Route104_Text_HaleyDefeat: @ 0x08259F1B
	.string "たたかわなければ　よかったかな⋯⋯$"

Route104_Text_HaleyPostBattle: @ 0x08259F2D
	.string "どっちに　しようか　まよってる　とき\n"
	.string "じぶんで　きめないで　たにんに　まかせると\l"
	.string "どっちに　なっても　こうかいするね⋯⋯$"

Route104_Text_HaleyRegister1: @ 0x08259F6A
	.string "あなた　つよいけど\n"
	.string "ポケナビに　とうろく　しようかな⋯⋯\l"
	.string "やめとこうかな⋯⋯\p"
	.string "えーい！　とうろくしちゃえ！$"

Route104_Text_HaleyRegister2: @ 0x08259FA0
	.string "あなた　つよいけど\n"
	.string "ポケナビに　とうろく　しようかな⋯⋯\l"
	.string "やめとこうかな⋯⋯\p"
	.string "えーい！　とうろくしちゃえ！$"

Route104_Text_HaleyRematchIntro: @ 0x08259FD6
	.string "あたしと　しょうぶ　してもらうわよ！$"

Route104_Text_HaleyRematchDefeat: @ 0x08259FE9
	.string "うーん⋯⋯\n"
	.string "かてると　おもったのにな$"

Route104_Text_HaleyPostRematch: @ 0x08259FFC
	.string "たたかうって　じぶんで　きめたから\n"
	.string "まけても　すっきり　してるわ！\p"
	.string "⋯⋯もちろん　まけて　くやしいけどね$"

Route104_Text_WinstonIntro: @ 0x0825A031
	.string "ボクが　あいてして　あげるよ\n"
	.string "この　おかねもちの　ボクがね$"

Route104_Text_WinstonDefeat: @ 0x0825A04F
	.string "どうして　かてないんだ⋯⋯！？$"

Route104_Text_WinstonPostBattle: @ 0x0825A05F
	.string "おかねじゃ　かてない　ものが　ある⋯⋯\n"
	.string "それが　ポケモンなんだね⋯⋯$"

Route104_Text_WinstonRegister1: @ 0x0825A082
	.string "ん？　きみ　ポケナビを　てにいれたね！\p"
	.string "ボクが　とうろくして　あげよう\n"
	.string "この　おかねもちの　ボクがね$"

Route104_Text_WinstonRegister2: @ 0x0825A0B5
	.string "ん？　きみ　ポケナビを　てにいれたね！\p"
	.string "ボクが　とうろくして　あげよう\n"
	.string "この　おかねもちの　ボクがね$"

Route104_Text_WinstonRematchIntro: @ 0x0825A0E8
	.string "きみに　まけてから　いろいろ\n"
	.string "ポケモンのこと　べんきょう　したんだ！$"

Route104_Text_WinstonRematchDefeat: @ 0x0825A10B
	.string "また　まけた⋯⋯\n"
	.string "どうして　かてないんだ⋯⋯！？$"

Route104_Text_WinstonPostRematch: @ 0x0825A124
	.string "おかねもちの　ボク　なのに\n"
	.string "なかなか　ポケモンに　かてない⋯⋯\p"
	.string "なんて　おくが　ふかいんだろう\n"
	.string "ポケモンって⋯⋯$"

Route104_Text_CindyIntro: @ 0x0825A15D
	.string "あなたと　であったのも　なにかの　ごえん\n"
	.string "おてあわせを　おねがい　できるかしら$"

Route104_Text_CindyDefeat: @ 0x0825A185
	.string "まあ！$"

Route104_Text_CindyPostBattle: @ 0x0825A189
	.string "であいは　わかれの　はじまり⋯⋯\n"
	.string "また　どこかで　おあいしましょう$"

Route104_Text_CindyRegister1: @ 0x0825A1AB
	.string "あら⋯⋯　また　おあい　しましたわね\p"
	.string "こんなに　ごえんが　あるんですもの\n"
	.string "ポケナビに　とうろく　して　くださいませ$"

Route104_Text_CindyRegister2: @ 0x0825A1E5
	.string "この　ごえんを　きねんして\n"
	.string "ポケナビに　とうろく　して　くださいませ$"

Route104_Text_CindyRematchIntro: @ 0x0825A208
	.string "また　おあい　しましたわね\n"
	.string "おてあわせ　おねがい　できるかしら$"

Route104_Text_CindyRematchDefeat: @ 0x0825A228
	.string "あら⋯⋯\n"
	.string "わたくし　ベストを　つくしましたのに⋯⋯$"

Route104_Text_CindyPostRematch: @ 0x0825A242
	.string "であいは　わかれの　はじまり⋯⋯\n"
	.string "また　どこかで　おあいしましょう$"

Route104_Text_DarianIntro: @ 0x0825A264
	.string "つよそうな　ポケモンが　つれたっ！\n"
	.string "さかなの　おうさま　って　かんじだ！\l"
	.string "これは　つよそうだぞっ！$"

Route104_Text_DarianDefeat: @ 0x0825A296
	.string "なっにい$"

Route104_Text_DarianPostBattle: @ 0x0825A29B
	.string "おい　なまえ　まけ　してるじゃないか\n"
	.string "おれの　コイキングよ！$"
Route105_Text_FosterIntro: @ 0x0825A2BA
	.string "この　あたりに\n"
	.string "ふしぎな　いわが　あるらしいが\l"
	.string "きみ　しらないかい？$"

Route105_Text_FosterDefeated: @ 0x0825A2DD
	.string "いわのこと　ばかり　かんがえて\n"
	.string "ポケモン　よわいまま　だったか⋯⋯$"

Route105_Text_FosterPostBattle: @ 0x0825A2FF
	.string "すてきな　いわ　だったら\n"
	.string "なんじかん　みていても　あきないよ⋯⋯$"

Route105_Text_LuisIntro: @ 0x0825A320
	.string "よかった！　こどもが\n"
	.string "おぼれているのかと　しんぱい　したよ！\p"
	.string "だいじょうぶ　そうだから　しょうぶ　だな！$"

Route105_Text_LuisDefeated: @ 0x0825A355
	.string "ゴボゴボ⋯⋯$"

Route105_Text_LuisPostBattle: @ 0x0825A35C
	.string "すなはまに　むかって　かたてを　ふるのが\n"
	.string "おぼれたときの　サインだぜ！$"

Route105_Text_DominikIntro: @ 0x0825A380
	.string "あおい　うみで　およいでいると\n"
	.string "さいこうの　きぶん　だな！$"

Route105_Text_DominikDefeated: @ 0x0825A39E
	.string "まけた⋯⋯\n"
	.string "ブルーな　きぶん⋯⋯$"

Route105_Text_DominikPostBattle: @ 0x0825A3AF
	.string "うみが　あおい　りゆう！？\p"
	.string "カイナの　はくぶつかんで　きいたけど\n"
	.string "そんなの　わすれちまったよ！$"

Route105_Text_BeverlyIntro: @ 0x0825A3DF
	.string "みずに　はいると　からだが　かるくなるわね\n"
	.string "なんだか　スリムに　なったみたい！$"

Route105_Text_BeverlyDefeated: @ 0x0825A407
	.string "ぷかぷか⋯⋯$"

Route105_Text_PostBattle: @ 0x0825A40E
	.string "みずの　なかでは　たいじゅうが\n"
	.string "10ぶんの1　くらいに　なるのよ\p"
	.string "と　すると　いま　わたしは⋯⋯\n"
	.string "いけない！　たいじゅうが　バレちゃうわ！$"

Route105_Text_ImaniIntro: @ 0x0825A454
	.string "あおい　そら⋯⋯\n"
	.string "ひろい　うみ⋯⋯\l"
	.string "のどか　よねー⋯⋯$"

Route105_Text_ImaniDefeated: @ 0x0825A470
	.string "なごんでいる　うちに\n"
	.string "まけちゃったわーっ！$"

Route105_Text_ImaniPostBattle: @ 0x0825A486
	.string "あたしと　いると　なごむって　いわれたいの\n"
	.string "うふふふふ！$"

Route105_Text_AndresIntro: @ 0x0825A4A3
	.string "うみに　こそ　なにかが　あると\n"
	.string "かくしんが　ある！$"

Route105_Text_AndresDefeated: @ 0x0825A4BD
	.string "うん⋯⋯　わし\n"
	.string "しょうぶは　よわいんだよ$"

Route105_Text_AndresPostBattle: @ 0x0825A4D2
	.string "せかいじゅうの　うみには\n"
	.string "まだまだ　ひみつが　あるはずだ！\l"
	.string "ぜんぶ　さがしまくるぞ！$"

Route105_Text_AndresRegister: @ 0x0825A4FD
	.string "ん？　こんな　よわい　わしでも\n"
	.string "ポケナビ　とうろくして　くれるのか？$"

Route105_Text_AndresRematchIntro: @ 0x0825A520
	.string "しょうぶは　よわいと　いっているのに⋯⋯\n"
	.string "わし　なんかで　いいのか？$"

Route105_Text_AndresRematchDefeated: @ 0x0825A543
	.string "うん⋯⋯　やっぱり　かてないな$"

Route105_Text_AndresRematchPostBattle: @ 0x0825A553
	.string "しょうぶは　よわいが\n"
	.string "たんきゅうしんは　きみにも　まけん！\l"
	.string "せかいじゅうの　うみを　たび　するぞ！$"

Route105_Text_JosueIntro: @ 0x0825A585
	.string "なれない　およぎで　つかれたー\n"
	.string "きばらしに　ポケモンしょうぶ　じゃい！$"

Route105_Text_JosueDefeated: @ 0x0825A5A9
	.string "うみで　たたかった　から　まけたんだ$"

Route105_Text_JosuePostBattle: @ 0x0825A5BC
	.string "やっぱりさ　おれには\n"
	.string "うみより　そらが　にあってるんだよ$"
Route106_Text_ElliotIntro: @ 0x0825A5D9
	.string "うみづりと　かわづり\n"
	.string "キミは　どっちが　すき？$"

Route106_Text_ElliotDefeated: @ 0x0825A5F1
	.string "まるで　うみづりの　ように\n"
	.string "ごうかいに　まけたぞーっ！$"

Route106_Text_ElliotPostBattle: @ 0x0825A60D
	.string "うみでも　かわでも　つりは　サイコーだ！\n"
	.string "キミも　そう　おもうだろ！？$"

Route106_Text_ElliotRegister: @ 0x0825A631
	.string "つりも　いいけど　しょうぶも　いいな！\n"
	.string "キミ　よかったら　また　たのむよ！$"

Route106_Text_ElliotRematchIntro: @ 0x0825A657
	.string "ポケモン　つりまくったからね\n"
	.string "すごい　しょうぶを　してみせるぞー！$"

Route106_Text_ElliotRematchDefeated: @ 0x0825A679
	.string "また　ごうかいに　まけたぞーっ！$"

Route106_Text_ElliotRematchPostBattle: @ 0x0825A68A
	.string "かっても　まけても　ポケモンは　サイコーだ！\n"
	.string "キミも　そう　おもうだろ！？$"

Route106_Text_NedIntro: @ 0x0825A6B0
	.string "トイレに　いきたくなったとき\n"
	.string "みんなは　どうしてるんだろう⋯⋯？\p"
	.string "トイレに　いっている　あいだに\n"
	.string "もし　おおものが　かかったらと　おもうと⋯⋯$"

Route106_Text_NedDefeated: @ 0x0825A6F8
	.string "トイレを　がまん　してたから\n"
	.string "まけたんだよ　きっと⋯⋯$"

Route106_Text_NedPostBattle: @ 0x0825A714
	.string "ああっ！\n"
	.string "おおものが　つれそうな　よかん⋯⋯！$"

Route106_Text_DouglasIntro: @ 0x0825A72C
	.string "はっはっはっ！\n"
	.string "りくでは　はやく　はしれないが\l"
	.string "みずの　なかなら　まけないぞ！$"

Route106_Text_DouglasDefeated: @ 0x0825A754
	.string "まいりましたーっ！$"

Route106_Text_DouglasPostBattle: @ 0x0825A75E
	.string "すいえいの　きょうそうなら　まけないのに⋯⋯$"

Route106_Text_KylaIntro: @ 0x0825A775
	.string "うみは　わたしの　にわ\n"
	.string "こども　だからって　てかげん　しないわよ！$"

Route106_Text_KylaDefeated: @ 0x0825A797
	.string "ひょっとして\n"
	.string "てかげん　してないよね？$"

Route106_Text_KylaPostBattle: @ 0x0825A7AB
	.string "なみに　ゆられて　ただようのが　だいすき\n"
	.string "あなたも　やってみない？$"
Route107_Text_DarrinIntro: @ 0x0825A7CD
	.string "むにゃむにゃ⋯⋯\p"
	.string "なみに　ゆられてたら　きもちよくなって\n"
	.string "うっかり　ねてしまった！$"

Route107_Text_DarrinDefeated: @ 0x0825A7F7
	.string "あはは　まけた⋯⋯\n"
	.string "また　ねますか⋯⋯$"

Route107_Text_DarrinPostBattle: @ 0x0825A80B
	.string "うみに　うかんで　なみに　ゆられてると\n"
	.string "ふかふかの　ベッドで　ねてる　みたいだよ！$"

Route107_Text_TonyIntro: @ 0x0825A835
	.string "うみは　オレの　にわ　みたいな　もの！\n"
	.string "しょうぶ　しようぜ！$"

Route107_Text_TonyDefeated: @ 0x0825A854
	.string "ホームグラウンドで　まけた⋯⋯\n"
	.string "ショック！$"

Route107_Text_TonyPostBattle: @ 0x0825A86A
	.string "おおきな　ユメを　いっぱい　つめてー\n"
	.string "でっかい　うみを　ひとおよぎー\p"
	.string "さぁて　まだまだ　およぐぞー！$"

Route107_Text_TonyRegister: @ 0x0825A89D
	.string "ショックを　うけたオレを\n"
	.string "きみが　わすれない　ために⋯⋯！$"

Route107_Text_TonyRematchIntro: @ 0x0825A8BB
	.string "でっかい　うみを　およいでいたら\n"
	.string "ポケモンが　すっごく　つよくなったぞー！$"

Route107_Text_TonyRematchDefeated: @ 0x0825A8E1
	.string "ショック！！\p"
	.string "ポケモンは　つよくなったが\n"
	.string "トレーナーの　おれが　よわいまま！？$"

Route107_Text_TonyRematchPostBattle: @ 0x0825A909
	.string "たたかいの　なかで　おぼえたことが\n"
	.string "トレーナーとしての　つよさに　つながる！\l"
	.string "でっかい　うみが　そう　いっていたぞー！$"

Route107_Text_DeniseIntro: @ 0x0825A945
	.string "ムロタウン　っていう\n"
	.string "ちいさな　まちを　しってる？$"

Route107_Text_DeniseDefeated: @ 0x0825A95F
	.string "ヤダ　もーっ！$"

Route107_Text_DenisePostBattle: @ 0x0825A967
	.string "ムロタウンの　しゅうかいじょで\n"
	.string "ふしぎな　ことばが　はやって　いるのよ！$"

Route107_Text_BethIntro: @ 0x0825A98C
	.string "わたしと　しょうぶが　したいの？\n"
	.string "いいわ！　あいてに　なって　あげる！$"

Route107_Text_BethDefeated: @ 0x0825A9B0
	.string "わたしじゃ　あいてに　ならなかったわ！$"

Route107_Text_BethPostBattle: @ 0x0825A9C4
	.string "あなた　まだまだ　つよく　なりそうね\n"
	.string "わたしも　がんばろうっと！$"

Route107_Text_LisaIntro: @ 0x0825A9E5
	.string "ユミ“あたしたち　きょうだい　ふたりで\n"
	.string "しょうぶを　させてもらうわ！$"

Route107_Text_LisaDefeated: @ 0x0825AA08
	.string "ユミ“すごいわ\n"
	.string "つよさの　レベルが　ちがうのね$"

Route107_Text_LisaPostBattle: @ 0x0825AA20
	.string "ユミ“あなたは　いっしょに\n"
	.string "うみに　あそびに　いくような\l"
	.string "おともだち　いるのかしら？$"

Route107_Text_LisaNotEnoughPokemon: @ 0x0825AA4B
	.string "ユミ“アタシたちと　たたかうなら\n"
	.string "ポケモン　もっと　つれてきなさいな$"

Route107_Text_RayIntro: @ 0x0825AA6E
	.string "シン“いつも　きょうだいで\n"
	.string "ポケモンしょうぶ　してるんだ！\p"
	.string "⋯⋯いっつも　おれが　まけるけど\n"
	.string "2たい2なら　きみに　かてるよ！$"

Route107_Text_RayDefeated: @ 0x0825AAAE
	.string "シン“ひゃー\n"
	.string "つよさの　レベルが　ちがいすぎるや$"

Route107_Text_RayPostBattle: @ 0x0825AAC7
	.string "シン“おれの　ポケモン\n"
	.string "ねえちゃんから　もらって　そだてた\l"
	.string "だいじな　あいぼう　なんだぜ！$"

Route107_Text_RayNotEnoughPokemon: @ 0x0825AAF5
	.string "シン“オレらと　たたかうなら\n"
	.string "もっと　ポケモン　つれてきてよ！$"

Route107_Text_CamronIntro: @ 0x0825AB15
	.string "トライアスロンの　とちゅう　だが\n"
	.string "ぜんぜん　つかれて　いないぜ！$"

Route107_Text_CamronDefeated: @ 0x0825AB36
	.string "いまので　つかれて　しまった$"

Route107_Text_CamronPostBattle: @ 0x0825AB45
	.string "こ　このあと　まだ\n"
	.string "すいえい　ランニングが　のこっているぜ\l"
	.string "だいじょうぶか　おれ⋯⋯？$"
Route108_Text_JeromeIntro: @ 0x0825AB71
	.string "オレの　ユメは　せかいに　ある\n"
	.string "7つのうみ　すべてで　およぐこと！$"

Route108_Text_JeromeDefeated: @ 0x0825AB93
	.string "これじゃ\n"
	.string "7つのうみ　すべてで　およげない⋯⋯$"

Route108_Text_JeromePostBattle: @ 0x0825ABAB
	.string "うみの　ポケモンと　あそぶことも\n"
	.string "およいでいる　ときの　たのしみだね！$"

Route108_Text_MatthewIntro: @ 0x0825ABCF
	.string "なあ　キミ！\n"
	.string "キミも　すてられた　ふねに　いくのかい？$"

Route108_Text_MatthewDefeated: @ 0x0825ABEB
	.string "ああ　ぼくが　しずむ⋯⋯\n"
	.string "ぶくぶく⋯⋯$"

Route108_Text_MatthewPostBattle: @ 0x0825ABFF
	.string "すてられぶねの　なかに\n"
	.string "はいっていく　やつらが　いるんだよ！$"

Route108_Text_TaraIntro: @ 0x0825AC1E
	.string "ウソつきな　カレに　いわれたのよ\n"
	.string "ビキニが　にあってて　カワイイって⋯⋯$"

Route108_Text_TaraDefeated: @ 0x0825AC43
	.string "いやん　まけたわーっ！$"

Route108_Text_TaraPostBattle: @ 0x0825AC4F
	.string "ウソでも　いいから　カワイイって　いわれたい\n"
	.string "ふくざつな　おんなごころ⋯⋯$"

Route108_Text_MissyIntro: @ 0x0825AC75
	.string "うみって　だいすき！\n"
	.string "およいでいれば　イヤなことも　わすれるわ！$"

Route108_Text_MissyDefeated: @ 0x0825AC96
	.string "しょうぶに　まけると\n"
	.string "ストレスが　たまるーっ！$"

Route108_Text_MissyPostBattle: @ 0x0825ACAE
	.string "ストレスは　およいで　はっさん！\n"
	.string "けんこうてき　よねー！$"

Route108_Text_CoryIntro: @ 0x0825ACCB
	.string "みずポケモンが　だいすきだー！\n"
	.string "ほかの　ポケモンも　だいすきだー！$"

Route108_Text_CoryDefeated: @ 0x0825ACED
	.string "わー　まけたー！\n"
	.string "わーわー！$"

Route108_Text_CoryPostBattle: @ 0x0825ACFC
	.string "おおごえで　さけべば\n"
	.string "スッキリ　するなあーっ！$"

Route108_Text_CoryRegister: @ 0x0825AD14
	.string "つよい　トレーナーも　だいすきだー！\n"
	.string "ポケナビの　とうろくを　してくれー！$"

Route108_Text_CoryRematchIntro: @ 0x0825AD3A
	.string "かっても　まけても\n"
	.string "うみ　での　しょうぶが　だいすきだー！$"

Route108_Text_CoryRematchDefeated: @ 0x0825AD58
	.string "わーっ　また　まけた！\n"
	.string "わー　わー！$"

Route108_Text_CoryRematchPostBattle: @ 0x0825AD6B
	.string "きみも　いきづまった　ときは\n"
	.string "なにかを　うみに　むかって　さけべーっ！$"

Route108_Text_CarolinaIntro: @ 0x0825AD8F
	.string "じまんの　ポケモンたちで\n"
	.string "スピーディに　たたかうわよ！$"

Route108_Text_CarolinaDefeated: @ 0x0825ADAB
	.string "あら　かわいくないわね！$"

Route108_Text_CarolinaPostBattle: @ 0x0825ADB8
	.string "せっかくの　うみ　だし\n"
	.string "ピンクの　フリフリの　ビキニも\l"
	.string "ちょっと　きてみたい⋯⋯$"
	.incbin "baserom_jp.gba", 0x25ade1, 0x75b2
