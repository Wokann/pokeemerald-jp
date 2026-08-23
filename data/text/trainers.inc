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
Route109_Text_DavidIntro: @ 0x0825ADE1
	.string "うりゃーっ！！\n"
	.string "みごとに　われた　ふっきんを　みろーっ！！$"

Route109_Text_DavidDefeated: @ 0x0825ADFF
	.string "うりゃーっ！！\n"
	.string "まけたーっ！！$"

Route109_Text_DavidPostBattle: @ 0x0825AE0F
	.string "うりゃーっ！！\p"
	.string "ふっきんと　ポケモンの　しょうぶは\n"
	.string "かんけい　ないぞーっ！！$"

Route109_Text_AliceIntro: @ 0x0825AE36
	.string "ひやけ　たいさく\n"
	.string "あなたは　してる？$"

Route109_Text_AliceDefeated: @ 0x0825AE49
	.string "あちちちちっ！$"

Route109_Text_AlicePostBattle: @ 0x0825AE51
	.string "ほっぺの　あたりが　いちばん\n"
	.string "ひやけ　しやすい　ばしょ　なのよ！$"

Route109_Text_HueyIntro: @ 0x0825AE72
	.string "せかいじゅうの　みなとを　おとずれたが\n"
	.string "カイナは　さいこーの　みなとまち　だぜ！$"

Route109_Text_HueyDefeated: @ 0x0825AE9B
	.string "あんた　さいこー　だぜ⋯⋯$"

Route109_Text_HueyPostBattle: @ 0x0825AEA9
	.string "さいこーの　みなとまちには\n"
	.string "さいこーの　トレーナーが　いたぜ⋯⋯$"

Route109_Text_EdmondIntro: @ 0x0825AECA
	.string "ううう⋯⋯\n"
	.string "しょうぶ　するの？　オレと？$"

Route109_Text_EdmondDefeated: @ 0x0825AEDF
	.string "げろげろ⋯⋯$"

Route109_Text_EdmondPostBattle: @ 0x0825AEE6
	.string "いつもは　もっと　つよいんだぞ！\n"
	.string "ふなよいで　ちょうしが　わるいだけだ！\p"
	.string "ふなのり　だけど⋯⋯$"

Route109_Text_RickyIntro: @ 0x0825AF16
	.string "のどが　かわいたよ⋯⋯\n"
	.string "うみのいえで　サイコソーダ　のみたいな⋯⋯$"

Route109_Text_RickyDefeated: @ 0x0825AF38
	.string "うーん⋯⋯$"

Route109_Text_RickyPostBattle: @ 0x0825AF3E
	.string "おなかも　へってきた⋯⋯\n"
	.string "うきわが　おっきな　ドーナッツに　みえるよ$"

Route109_Text_RickyRegister: @ 0x0825AF61
	.string "こんど　のどが　かわいて　ないときに\n"
	.string "もういっかい　しょうぶ　してくれる？$"

Route109_Text_RickyRematchIntro: @ 0x0825AF87
	.string "おなか　へってるけど\n"
	.string "しょうぶ　するなら　げんき　だよ！$"

Route109_Text_RickyRematchDefeated: @ 0x0825AFA4
	.string "まけた⋯⋯\n"
	.string "おなかが　へってるからだ$"

Route109_Text_RickyRematchPostBattle: @ 0x0825AFB7
	.string "すなはまで　たべると\n"
	.string "なんでも　おいしく　おもえるよね$"

Route109_Text_LolaIntro: @ 0x0825AFD3
	.string "ビーチパラソルって\n"
	.string "おおきな　おはな　みたいよねー！$"

Route109_Text_LolaDefeated: @ 0x0825AFEE
	.string "ママーっ！$"

Route109_Text_LolaPostBattle: @ 0x0825AFF4
	.string "おそらの　うえから　すなはまを　みたら\n"
	.string "おはなばたけ　みたいに　みえるのよ！$"

Route109_Text_LolaRegister: @ 0x0825B01B
	.string "わたし　だったら\n"
	.string "まいにち　ここに　きているよ！$"

Route109_Text_LolaRematchIntro: @ 0x0825B034
	.string "もう　あなたには　まけません！\n"
	.string "そのために　うきわ　してるんだから！$"

Route109_Text_LolaRematchDefeated: @ 0x0825B057
	.string "ママーっ！$"

Route109_Text_LolaRematchPostBattle: @ 0x0825B05D
	.string "うきわ　もってると　あたしと　ポケモンの\n"
	.string "かわいさが　ぐぐーんと　アップするの！$"

Route109_Text_AustinaIntro: @ 0x0825B086
	.string "うきわが　ないと　およげないけど\n"
	.string "ポケモンなら　だれにも　まけないよ！$"

Route109_Text_AustinaDefeated: @ 0x0825B0AA
	.string "うきわが　あるから　まけちゃったのかな？$"

Route109_Text_AustinaPostBattle: @ 0x0825B0BF
	.string "あたしの　うきわ\n"
	.string "オシャレだから　てばなせないの$"

Route109_Text_GwenIntro: @ 0x0825B0D8
	.string "そこの　トレーナーさん\n"
	.string "あたしと　たたかう　でちゅ！$"

Route109_Text_GwenDefeated: @ 0x0825B0F3
	.string "つよいでちゅね⋯⋯$"

Route109_Text_GwenPostBattle: @ 0x0825B0FD
	.string "どうしたら　そんなに\n"
	.string "つよくなれる　でちゅか⋯⋯？$"

Route109_Text_CarterIntro: @ 0x0825B117
	.string "わはは！\n"
	.string "おじさん　おおもの　つっちゃうぞ！$"

Route109_Text_CarterDefeated: @ 0x0825B12E
	.string "おじさん　まけちゃったな⋯⋯$"

Route109_Text_CarterPostBattle: @ 0x0825B13D
	.string "たしかに　きみは　おおもの　だな！\n"
	.string "いや　きっと　おおものに　なるぞ！$"

Route109_Text_PaulIntro: @ 0x0825B161
	.string "リキ“やあ　こまったなあ\p"
	.string "ふたりっきりの　じかん\n"
	.string "じゃま　して　ほしくないなあ$"

Route109_Text_PaulDefeated: @ 0x0825B189
	.string "リキ“やあ　まいったな⋯⋯$"

Route109_Text_PaulPostBattle: @ 0x0825B197
	.string "リキ“やあ　ぼくたちが　ここに　いること\n"
	.string "だれにも　いわないで　くれよ！\l"
	.string "ふたりっきりの　せかい　なんだからさ！$"

Route109_Text_PaulNotEnoughPokemon: @ 0x0825B1D0
	.string "リキ“ぼくたち　ラブラブ　だからね\n"
	.string "ぼくたちの　ポケモンも\l"
	.string "2ひき　いっしょに　たたかわせるんだ！$"

Route109_Text_MelIntro: @ 0x0825B202
	.string "シキ“あたしたちが　ラブラブだから\n"
	.string "ホウエンは　あっついのよお！$"

Route109_Text_MelDefeated: @ 0x0825B223
	.string "シキ“あたしの　せいで　まけたんだわ⋯⋯\n"
	.string "こんなんじゃ　リキに　きらわれちゃう！$"

Route109_Text_MelPostBattle: @ 0x0825B24C
	.string "シキ“ねえ　リキ\n"
	.string "あたしのこと　おこってない？\l"
	.string "おこっちゃ　いやよ$"

Route109_Text_MelNotEnoughPokemon: @ 0x0825B26E
	.string "シキ“あたしたち　ラブラブ　だからね\n"
	.string "あたしたちの　ポケモンも\l"
	.string "2ひき　いっしょに　たたかわせるんだ！$"

Route109_Text_ChandlerIntro: @ 0x0825B2A2
	.string "じゃーん！\n"
	.string "ボクの　うきわ　まるいでしょーっ！$"

Route109_Text_ChandlerDefeated: @ 0x0825B2BA
	.string "あーあ！　ざんねん$"

Route109_Text_ChandlerPostBattle: @ 0x0825B2C4
	.string "せっかく　まるい　うきわを\n"
	.string "みせて　あげたのにさ$"

Route109_Text_HaileyIntro: @ 0x0825B2DD
	.string "およげない　から\n"
	.string "およぐ　ふりを　してるの！$"

Route109_Text_HaileyDefeated: @ 0x0825B2F4
	.string "やっぱね！\n"
	.string "かてないって　おもってたんだ$"

Route109_Text_HaileyPostBattle: @ 0x0825B309
	.string "およげるように　なったら\n"
	.string "ポケモンも　つよく　なると　おもう！$"

Route109_Text_ElijahIntro: @ 0x0825B329
	.string "こうはの　おれさまには\n"
	.string "こんな　ポケモンが　おにあいだぜ！$"

Route109_Text_ElijahDefeated: @ 0x0825B347
	.string "まけても　カッコ　いいだろ？$"

Route109_Text_ElijahPostBattle: @ 0x0825B356
	.string "こうはの　おれさまには\n"
	.string "みなとまちが　おにあいだぜ！\l"
	.string "カイナシティに　いってくるか$"
Route110_Text_JacobIntro: @ 0x0825B380
	.string "おっと　あぶない！\n"
	.string "バイク　レースに　なれてない　ようだな！$"

Route110_Text_JacobDefeated: @ 0x0825B39F
	.string "キキーッ！\n"
	.string "ブレーキが　こしょうした！$"

Route110_Text_JacobPostBattle: @ 0x0825B3B3
	.string "タイヤの　パンクや\n"
	.string "ブレーキの　こしょうは　ケガのもと\l"
	.string "ちゃんと　てんけん　しないとな$"

Route110_Text_AnthonyIntro: @ 0x0825B3DF
	.string "ヘイ　ユー！\n"
	.string "ワタシの　スピードに　ついてこれるかな！？$"

Route110_Text_AnthonyDefeated: @ 0x0825B3FC
	.string "オー　マイ　ガッ！$"

Route110_Text_AnthonyPostBattle: @ 0x0825B406
	.string "スピードだけじゃ　ポケモンしょうぶ\n"
	.string "かてませーん！　ハンセイしまーす！$"

Route110_Text_BenjaminIntro: @ 0x0825B42A
	.string "じてんしゃの　スピード　でても\n"
	.string "あせっちゃ　いけないよ！$"

Route110_Text_BenjaminDefeated: @ 0x0825B447
	.string "ポケモンしょうぶも\n"
	.string "あせっちゃ　いけないな⋯⋯$"

Route110_Text_BenjaminPostBattle: @ 0x0825B45F
	.string "あせらず　のんびり　いこうよ\n"
	.string "じかんは　たっぷり　あるからね！$"

Route110_Text_BenjaminRegister: @ 0x0825B47F
	.string "あせらずに　また　がんばるか！\n"
	.string "よかったらさ　れんらく　くれよな$"

Route110_Text_BenjaminRematchIntro: @ 0x0825B4A0
	.string "おっ！　スピード　だしすぎ　じゃない？\n"
	.string "ちょっと　のんびり　しょうぶ　しようよ！$"

Route110_Text_BenjaminRematchDefeated: @ 0x0825B4C9
	.string "べつに　あせってないけど\n"
	.string "なぜだか　まけて　しまうな⋯⋯$"

Route110_Text_BenjaminRematchPostBattle: @ 0x0825B4E6
	.string "あせらず　のんびり　いこうよ\n"
	.string "じかんは　たっぷり　あるからね！$"

Route110_Text_AbigailIntro: @ 0x0825B506
	.string "トライアスロンは　ハードな　スポーツ\n"
	.string "すいえい　じてんしゃ　マラソンの\l"
	.string "3しゅもくを　こなすのよ！$"

Route110_Text_AbigailDefeated: @ 0x0825B538
	.string "ポケモン　しょうぶも　ハードだわ！$"

Route110_Text_AbigailPostBattle: @ 0x0825B54A
	.string "つかれたから　ひとやすみ\n"
	.string "きゅうけいは　たいせつ　なのよ$"

Route110_Text_AbigailRegister: @ 0x0825B567
	.string "あなた　きにいったわ！\n"
	.string "また　サイクリングロードで　たたかいましょ$"

Route110_Text_AbigailRematchIntro: @ 0x0825B589
	.string "じてんしゃに　のりながら\n"
	.string "ポケモンしょうぶ　ってのも　いいものよね！$"

Route110_Text_AbigailRematchDefeated: @ 0x0825B5AC
	.string "うわー\n"
	.string "どうして　そんなに　つよいの？$"

Route110_Text_AbigailRematchPostBattle: @ 0x0825B5C0
	.string "ひょっとして　きろくに\n"
	.string "ちょうせん　していたのかしら？\p"
	.string "だったら　ジャマして　ゴメンねー$"

Route110_Text_JasmineIntro: @ 0x0825B5ED
	.string "じてんしゃを　こぎつづけて\n"
	.string "ふとももが　パンパンに　なっちゃった$"

Route110_Text_JasmineDefeated: @ 0x0825B60E
	.string "きんにくつうが　しんぱいだわ⋯⋯$"

Route110_Text_JasminePostBattle: @ 0x0825B61F
	.string "ジムの　バッチを　もってるの？\n"
	.string "どうりで　つよい　はずだわ！$"

Route110_Text_EdwardIntro: @ 0x0825B63E
	.string "おまえの　さくせんは　すべて　みえた！\n"
	.string "わたしが　まけるはず　ない！$"

Route110_Text_EdwardDefeated: @ 0x0825B661
	.string "じぶんの　はいぼくは　みえなかった⋯⋯！$"

Route110_Text_EdwardPostBattle: @ 0x0825B676
	.string "おまえの　みらいが　みえる⋯⋯\p"
	.string "ふうむ⋯⋯\n"
	.string "あかるい　ひかりが　みえるぞ⋯⋯！$"

Route110_Text_JaclynIntro: @ 0x0825B69E
	.string "おほほほほっ！\n"
	.string "わたくしの　ミラクルを　みせてあげるわ！$"

Route110_Text_JaclynDefeated: @ 0x0825B6BB
	.string "ミラクルに　まけたーっ！$"

Route110_Text_JaclynPostBattle: @ 0x0825B6C8
	.string "わたくしに　かったことが　ミラクル⋯⋯\n"
	.string "そう　きせき　なのよ！\l"
	.string "いつでも　かてるなんて　おもわないことね！$"

Route110_Text_EdwinIntro: @ 0x0825B6FE
	.string "キミの　ポケモン　みせてくれない？\n"
	.string "ひとめで　いいから　おねがい！$"

Route110_Text_EdwinDefeated: @ 0x0825B720
	.string "コンプリート　したかった⋯⋯！$"

Route110_Text_EdwinPostBattle: @ 0x0825B730
	.string "みたことのない　ポケモンに　であうと\n"
	.string "ボクの　コレクターだましいが　もえるなぁ！$"

Route110_Text_EdwinRegister: @ 0x0825B759
	.string "ぼく　エントリーコールも\n"
	.string "たくさん　あつめたいんだよねぇ$"

Route110_Text_EdwinRematchIntro: @ 0x0825B776
	.string "ねえ　キミ\n"
	.string "あたらしい　ポケモン　つかまえた？\p"
	.string "よかったら　ポケモン　みせてくれない？\n"
	.string "ひとめで　いいから　おねがい！$"

Route110_Text_EdwinRematchDefeated: @ 0x0825B7B2
	.string "キミの　ポケモン\n"
	.string "うらやましいな⋯⋯$"

Route110_Text_EdwinRematchPostBattle: @ 0x0825B7C5
	.string "ああ！　とにかく　めずらしい　ポケモン\n"
	.string "ぜんぶ　ボクの　ものに　したいよー！$"

Route110_Text_DaleIntro: @ 0x0825B7EC
	.string "ええーい！\n"
	.string "うしろから　はなしかけるなー！$"

Route110_Text_DaleDefeated: @ 0x0825B802
	.string "まけたっ！\n"
	.string "くやしいっ！！$"

Route110_Text_DalePostBattle: @ 0x0825B810
	.string "すいめんに　うかぶ　うきを　じっと　みる⋯⋯\n"
	.string "しゅうちゅうりょくが　たいせつ　なんだ$"

Route110_Text_IsabelIntro: @ 0x0825B83B
	.string "おほほ！　だいじな　ポケモンを\n"
	.string "じまん　するためなら　どこにでも　いきますわ$"

Route110_Text_IsabelDefeated: @ 0x0825B862
	.string "あら　まあ　イヤですわ$"

Route110_Text_IsabelPostBattle: @ 0x0825B86E
	.string "しょうぶ　させるよりも\n"
	.string "だいすきクラブで　じまんして　こようかしら$"

Route110_Text_IsabelRegister: @ 0x0825B890
	.string "わたしの　じまんは　こんなんじゃ\n"
	.string "おわりませんわ！\l"
	.string "なんかいも　つきあって　もらいますわよ！$"

Route110_Text_IsabelRematchIntro: @ 0x0825B8BF
	.string "おほほ！　だいじな　ポケモンなら\n"
	.string "なんどだって　じまん　しますわ！$"

Route110_Text_IsabelRematchDefeated: @ 0x0825B8E1
	.string "あら　まあ　イヤですわ$"

Route110_Text_IsabelRematchPostBattle: @ 0x0825B8ED
	.string "ポケモンじまんも　やめられないけど\n"
	.string "しょうぶ　するのも　すきなのよ！$"

Route110_Text_TimmyIntro: @ 0x0825B910
	.string "この　あたりの　くさむらで\n"
	.string "かっこいい　ポケモン　みつけたんだぜ！$"

Route110_Text_TimmyDefeated: @ 0x0825B932
	.string "かっこいい　だけじゃ　だめかぁ⋯⋯$"

Route110_Text_TimmyPostBattle: @ 0x0825B944
	.string "つかまえた　ばかりの　ポケモンじゃ\n"
	.string "うまく　たたかえないや！$"

Route110_Text_AlyssaIntro: @ 0x0825B963
	.string "サイクリングロード　から　おちちゃった！\n"
	.string "はずかしい⋯⋯　しょうぶで　まぎらわすわ！$"

Route110_Text_AlyssaDefeated: @ 0x0825B98E
	.string "ひぇ　まけて　しまったわ！$"

Route110_Text_AlyssaPostBattle: @ 0x0825B99C
	.string "おっこちるは　まけるはで\n"
	.string "はずかし　すぎます！　わたし！$"

Route110_Text_JosephIntro: @ 0x0825B9B9
	.string "よぉぉし　とばして　いくぜえェ！\n"
	.string "ノリの　わるいやつは　おいてくぜェ！$"

Route110_Text_JosephDefeated: @ 0x0825B9DD
	.string "ノリが　いいね　あんた⋯⋯$"

Route110_Text_JosephPostBattle: @ 0x0825B9EB
	.string "こんなこと　では　へこたれないぜェ！\n"
	.string "おれは　まけて　またひとつ\l"
	.string "いいオトコに　なったぜェ！$"

Route110_Text_KalebIntro: @ 0x0825BA1A
	.string "かわいい　ポケモンたちが\n"
	.string "たすけあう　ところは　かわいいぞーーっ！$"

Route110_Text_KalebDefeated: @ 0x0825BA3C
	.string "きみは　ちも　なみだも　ないんだな$"

Route110_Text_KalebPostBattle: @ 0x0825BA4E
	.string "おう　よしよし\n"
	.string "よくやったよ　かわいい　おまえたち$"
Route111_Text_DrewIntro: @ 0x0825BA68
	.string "おっ！　ゴーゴーゴーグル　にあってるね！\n"
	.string "でも　ぼくの　ほうが　にあってるだろ？\l"
	.string "どっちが　にあうか　しょうぶだよ！$"

Route111_Text_DrewDefeat: @ 0x0825BAA3
	.string "ゴーゴーゴーグルで　まわりが\n"
	.string "よく　わからなかったよ$"

Route111_Text_DrewPostBattle: @ 0x0825BABE
	.string "ゴーゴーゴーグルが　あると\n"
	.string "さばくの　すなあらしも　へいき　だから\l"
	.string "それだけで　うれしくなるよ！$"

Route111_Text_HeidiIntro: @ 0x0825BAEF
	.string "さばくの　なかでも　ピクニック！\p"
	.string "どんな　ところでも　トレーナー　いるから\n"
	.string "しょうぶも　できるもんね！$"

Route111_Text_HeidiDefeat: @ 0x0825BB23
	.string "いやーん　いじわるー！$"

Route111_Text_HeidiPostBattle: @ 0x0825BB2F
	.string "すなあらしの　なかで　たたかうなら\n"
	.string "ポケモンの　たいりょくに　きを　つけないと\l"
	.string "すぐに　きぜつ　しちゃうわよ！$"

Route111_Text_BeauIntro: @ 0x0825BB67
	.string "ゴーゴーゴーグルを　つけてると\n"
	.string "なんとなく　ヒーローきぶん！\l"
	.string "いまの　ぼくなら　だれにだって　かてるさ！$"

Route111_Text_BeauDefeat: @ 0x0825BB9C
	.string "きぶん　だけじゃ　かてないか⋯⋯$"

Route111_Text_BeauPostBattle: @ 0x0825BBAD
	.string "いつかは　ほんものの　ヒーローに　なる！\n"
	.string "そのために　もっと　がんばって\l"
	.string "ポケモンと　じぶんを　きたえてみせるよ$"

Route111_Text_BeckyIntro: @ 0x0825BBE6
	.string "さばくで　カセキが　みつかるって　きいたけど\n"
	.string "どこに　あるのかなあ？$"

Route111_Text_BeckyDefeat: @ 0x0825BC09
	.string "いまいち　だわ⋯⋯$"

Route111_Text_BeckyPostBattle: @ 0x0825BC13
	.string "さばくで　カセキが　みつかると　いうことは\n"
	.string "むかし　ここは　うみ　だったのね！$"

Route111_Text_DustyIntro: @ 0x0825BC3B
	.string "いせきを　さがして　30ねん！\n"
	.string "そんな　わたしと　たたかうのかね？$"

Route111_Text_DustyDefeat: @ 0x0825BC5D
	.string "いせきを　さがしてるけど\n"
	.string "つよい　ポケモンは　さがしてないんだ$"

Route111_Text_DustyPostBattle: @ 0x0825BC7D
	.string "いせきを　さがして　30ねん！\p"
	.string "いや　もう　40ねん　さがしているか？\n"
	.string "あれ　どうだったかな？$"

Route111_Text_DustyRegister: @ 0x0825BCAD
	.string "つよい　ポケモンは　さがしてないけど\n"
	.string "なぜだか　ポケナビは　おきにいり　なんだ！$"

Route111_Text_DustyRematchIntro: @ 0x0825BCD6
	.string "いせきを　さがして　30ねん！\p"
	.string "いや　いせきを　さがして　40ねん！\n"
	.string "そんな　わたしと　たたかうのかね？$"

Route111_Text_DustyRematchDefeat: @ 0x0825BD0B
	.string "いせきは　みつからない\n"
	.string "つよい　ポケモンも　みつからない$"

Route111_Text_DustyPostRematch: @ 0x0825BD28
	.string "いせきを　さがして　30ねん！\p"
	.string "いや　もう　40ねん　さがしているか？\p"
	.string "うーん　50ねん　だった　きもする⋯⋯\n"
	.string "あれ　どうだったかな？$"

Route111_Text_TravisIntro: @ 0x0825BD6C
	.string "ぼくも　げんき　いっぱい！\n"
	.string "ポケモンも　げんき　いっぱい　だよ！$"

Route111_Text_TravisDefeat: @ 0x0825BD8D
	.string "ポケモンの　げんき　なくなったよ$"

Route111_Text_TravisPostBattle: @ 0x0825BD9E
	.string "げんき　いっぱいに　はしりまわる\n"
	.string "トレーナーが　いると\l"
	.string "つい　そっちを　みちゃうよね！$"

Route111_Text_IreneIntro: @ 0x0825BDCA
	.string "どこに　いくのか　しらないけど\n"
	.string "ちょっと　しょうぶ　してみない？$"

Route111_Text_IreneDefeat: @ 0x0825BDEB
	.string "にくらしいほど　つよいのね！$"

Route111_Text_IrenePostBattle: @ 0x0825BDFA
	.string "えんとつやまに　いこうかな？　って\n"
	.string "おもって　いるんだけど\l"
	.string "このあたりの　けしきも　いいのよね！$"

Route111_Text_DaisukeIntro: @ 0x0825BE2B
	.string "おのれを　きたえるため\n"
	.string "であう　にんげん　すべてに\l"
	.string "しょうぶを　もうしこんでるッス！$"

Route111_Text_DaisukeDefeat: @ 0x0825BE56
	.string "まいったッス⋯⋯！$"

Route111_Text_DaisukePostBattle: @ 0x0825BE60
	.string "おぬしの　ように\n"
	.string "つよい　トレーナーに　かてるまで\l"
	.string "しゅぎょう　あるのみッス！$"

Route111_Text_WiltonIntro: @ 0x0825BE88
	.string "きみが　ポケモンを　どこまで\n"
	.string "きたえているか　みせて　もらおう！$"

Route111_Text_WiltonDefeat: @ 0x0825BEA9
	.string "なるほど\n"
	.string "かなり　きたえてるね！$"

Route111_Text_WiltonPostBattle: @ 0x0825BEBA
	.string "ポケモンも　トレーナーも\n"
	.string "たたかうことで　いろんなことを　まなぶ！\p"
	.string "だいじ　なのは\n"
	.string "まけても　あきらめないことさ！$"

Route111_Text_WiltonRegister: @ 0x0825BEF4
	.string "きみの　きたえかた　さんこうに　なるな！\n"
	.string "きが　むいたら　さいど　たたかってほしい$"

Route111_Text_WiltonRematchIntro: @ 0x0825BF1E
	.string "ぼくたちは　さらなる　たかみを　めざして\n"
	.string "ここで　ポケモンを　きたえている\l"
	.string "きみも　いっしょに　しゅぎょう　しよう！$"

Route111_Text_WiltonRematchDefeat: @ 0x0825BF59
	.string "なかなか　やるな！$"

Route111_Text_WiltonPostRematch: @ 0x0825BF63
	.string "そんなに　つよいなら\n"
	.string "ポケモンリーグを　めざすと　いいよ！$"

Route111_Text_BrookeIntro: @ 0x0825BF81
	.string "あら　あなたの　ポケモン\n"
	.string "かなり　つよそうだわ！\l"
	.string "ぜひ　おてあわせ　してくれない？$"

Route111_Text_BrookeDefeat: @ 0x0825BFAB
	.string "つよそう　じゃなくて\n"
	.string "つよいのね！$"

Route111_Text_BrookePostBattle: @ 0x0825BFBD
	.string "あたしも　がんばって\n"
	.string "ポケモン　そだてた　つもりだけど\l"
	.string "まだ　やること　いっぱい　あるわね！$"

Route111_Text_BrookeRegister: @ 0x0825BFEC
	.string "あなた　みたいな　つよいひとと\n"
	.string "おともだちに　なりたいわ！$"

Route111_Text_BrookeRematchIntro: @ 0x0825C00A
	.string "ポケモンは　つかう　わざによって\n"
	.string "つよくなったり　よわくなったりも　するわ！\p"
	.string "あなたの　ポケモン\n"
	.string "どんな　わざを　おぼえているの？$"

Route111_Text_BrookeRematchDefeat: @ 0x0825C04C
	.string "いい　わざを　おぼえているのね！$"

Route111_Text_BrookePostRematch: @ 0x0825C05D
	.string "あたしの　ポケモン　しんか　させずに\n"
	.string "さきに　わざを　おぼえさせてから\l"
	.string "そだてた　ほうが　よかったかな？$"

Route111_Text_CeliaIntro: @ 0x0825C092
	.string "こんな　ところで\n"
	.string "ピクニックを　するんじゃ　なかった！$"

Route111_Text_CeliaDefeat: @ 0x0825C0AE
	.string "もー\n"
	.string "ほんとに　くるんじゃ　なかった！$"

Route111_Text_CeliaPostBattle: @ 0x0825C0C2
	.string "この　すなあらし　じゃ\n"
	.string "ゴーゴーゴーグルを　つけて　いても\l"
	.string "おべんとうが　ひろげられないんだもん⋯⋯$"

Route111_Text_BryanIntro: @ 0x0825C0F5
	.string "きみの　つよさは　どのくらいか？\n"
	.string "その　ナゾを　ときあかそう！$"

Route111_Text_BryanDefeat: @ 0x0825C115
	.string "おお　そのつよさ\n"
	.string "ナゾに　みちておる！$"

Route111_Text_BryanPostBattle: @ 0x0825C129
	.string "この　さばくには\n"
	.string "ナゾが　おおい　ですぞーっ！$"

Route111_Text_BrandenIntro: @ 0x0825C141
	.string "ぼくに　まけて　くれたら\n"
	.string "サンドイッチ　わけて　あげるよ！$"

Route111_Text_BrandenDefeat: @ 0x0825C15F
	.string "ちぇっ！\n"
	.string "サンドイッチに　つられると　おもったのに$"

Route111_Text_BrandenPostBattle: @ 0x0825C179
	.string "ぼくの　サンドも\n"
	.string "サンドイッチ　だいすき　なんだ$"

Route111_Text_TyronIntro: @ 0x0825C192
	.string "ぼくは　こんな　ポケモンが　すきなんだ！$"

Route111_Text_TyronDefeat: @ 0x0825C1A7
	.string "ちょっと！　ぼくの　ポケモン\n"
	.string "ちゃんと　みてくれてた！？$"

Route111_Text_TyronPostBattle: @ 0x0825C1C4
	.string "しょうぶを　する　ときって\n"
	.string "じぶんの　ポケモンを　みせびらかす\l"
	.string "たのしみが　ゼッタイ　あるよねー$"

Route111_Text_CelinaIntro: @ 0x0825C1F5
	.string "うふん⋯⋯\n"
	.string "わたくしを　ドキドキ　させてね！$"

Route111_Text_CelinaDefeat: @ 0x0825C20C
	.string "す　⋯⋯ごい\n"
	.string "なんて　つよいの$"

Route111_Text_CelinaPostBattle: @ 0x0825C21C
	.string "ま　まだ　ドキドキ　しているわ\n"
	.string "あなたって⋯⋯　ステキな　トレーナーね$"

Route111_Text_HaydenIntro: @ 0x0825C240
	.string "おいらは　いま　はらが　へっている\n"
	.string "だから　ようしゃは　しないぞ！$"

Route111_Text_HaydenDefeat: @ 0x0825C262
	.string "ぐうぅ⋯⋯$"

Route111_Text_HaydenPostBattle: @ 0x0825C268
	.string "はらが　なった！\n"
	.string "きのみでも　やいて　たべようかナ？$"

Route111_Text_BiancaIntro: @ 0x0825C283
	.string "あなたは　キンセツの　ほうから　きたの？\n"
	.string "じゃ　たいりょくも　バッチリね！$"

Route111_Text_BiancaDefeat: @ 0x0825C2A9
	.string "あらら　すごいんだー$"

Route111_Text_BiancaPostBattle: @ 0x0825C2B4
	.string "この　さきの　みちのりは\n"
	.string "けっこう　ながいわよ！$"
Route112_Text_BriceIntro: @ 0x0825C2CD
	.string "わっはっはっ！\n"
	.string "どうだ？\l"
	.string "オレと　しょうぶ　しないか？\l"
	.string "わっはっはっ！$"

Route112_Text_BriceDefeat: @ 0x0825C2F1
	.string "まけた⋯⋯\n"
	.string "わっはっはっ！$"

Route112_Text_BricePostBattle: @ 0x0825C2FF
	.string "いろあざやかな　キノコを　たべたら⋯⋯\n"
	.string "わ　わらいが　とまらない！\l"
	.string "わっはっはっ！$"

Route112_Text_TrentIntro: @ 0x0825C329
	.string "やまのぼりで　きたえた　オレの　あしこし\n"
	.string "ちょっとや　そっとじゃ　くじけないぜ！$"

Route112_Text_TrentDefeat: @ 0x0825C352
	.string "あ⋯⋯\n"
	.string "あしが　つった⋯⋯$"

Route112_Text_TrentPostBattle: @ 0x0825C360
	.string "なんじゅっキロも　ある　にもつを　せおって\n"
	.string "やまみちを　あるき　つづけるんだ\l"
	.string "からだが　じょうぶに　なるぞ！$"

Route112_Text_TrentRegister: @ 0x0825C397
	.string "つった　あしが　いたい⋯⋯\n"
	.string "ちょっと　オレの　リュックから\l"
	.string "ほうたいを　だしてくれ\p"
	.string "って　ちがうよ　それは　ポケナビだろ！\n"
	.string "もういいよ　とうろく　するから$"

Route112_Text_TrentRematchIntro: @ 0x0825C3E5
	.string "やまのぼりで　きたえてるからな\n"
	.string "かなり　パワフルだぞ！$"

Route112_Text_TrentRematchDefeat: @ 0x0825C401
	.string "パワーで　まけたか？$"

Route112_Text_TrentRematchPostBattle: @ 0x0825C40C
	.string "えんとつやまの　うえには\n"
	.string "すごい　トレーナーが　いるらしいぞ！\l"
	.string "こんど　しょうぶに　いくつもりだ！$"

Route112_Text_LarryIntro: @ 0x0825C43E
	.string "ぼくは　つよいんだ⋯⋯\n"
	.string "まけても　ないたり　しないぞ⋯⋯！$"

Route112_Text_LarryDefeat: @ 0x0825C45C
	.string "うわーーーん！$"

Route112_Text_LarryPostBattle: @ 0x0825C464
	.string "おかあさんに　あえなくて\n"
	.string "さみしいから　ないてるんじゃ　ないよ！\l"
	.string "ぐすん⋯⋯$"

Route112_Text_CarolIntro: @ 0x0825C48B
	.string "ピクニックと　いえば　うた！\n"
	.string "さあ　いっしょに　うたいましょ！$"

Route112_Text_CarolDefeat: @ 0x0825C4AB
	.string "こんなに　つよいなんて⋯⋯！$"

Route112_Text_CarolPostBattle: @ 0x0825C4BA
	.string "うたも　ポケモンしょうぶも\n"
	.string "うまい　へた　なんて　かんけい　ないよ！\l"
	.string "たのしんだ　ほうが　かち　なのよ！$"

Route112_Text_BryantIntro: @ 0x0825C4EF
	.string "ほのおの　ぬけみちで　つかまえた\n"
	.string "ホカホカの　ポケモン　みせてやろー！$"

Route112_Text_BryantDefeat: @ 0x0825C513
	.string "おお　ボコボコだ$"

Route112_Text_BryantPostBattle: @ 0x0825C51C
	.string "ナカナカ　すてきな\n"
	.string "たたかいかたじゃ　ないか　きみぃ！$"

Route112_Text_ShaylaIntro: @ 0x0825C538
	.string "アラ！　すてきな　トレーナーさん\n"
	.string "ロマンチックな　しょうぶを　おねがいね！\l"
	.string "マアマア　つよいわよ　わたし！$"

Route112_Text_ShaylaDefeat: @ 0x0825C56E
	.string "なんて　つよいのかしら\n"
	.string "おねえさん　おどろいちゃった！$"

Route112_Text_ShaylaPostBattle: @ 0x0825C58A
	.string "ねえ　いま　いそがしいの？\n"
	.string "えっと　もし　よかったら\l"
	.string "さっそく　2かいせん　と　おもって⋯⋯\l"
	.string "ん？　いそがしいなら　いいわ$"
Route113_Text_JaylenIntro: @ 0x0825C5C8
	.string "この　あたりが　わりと　すずしいの\n"
	.string "なんでか　しってるかい？$"

Route113_Text_JaylenDefeat: @ 0x0825C5E7
	.string "ぴゅーっ！\n"
	.string "まけたーっ！$"

Route113_Text_JaylenPostBattle: @ 0x0825C5F4
	.string "かざんばいが　たいようの　ひかりを\n"
	.string "さえぎってるから　ひえるんだね！\l"
	.string "あつがりの　オレには　たすかるよ！$"

Route113_Text_DillonIntro: @ 0x0825C629
	.string "やまの　ふんかは\n"
	.string "ちきゅうが　いきている　しょうこ！$"

Route113_Text_DillonDefeat: @ 0x0825C644
	.string "つよいな　おまえーっ！$"

Route113_Text_DillonPostBattle: @ 0x0825C650
	.string "ごほ　がへっ！\n"
	.string "はいが　はいに　はいった⋯⋯\p"
	.string "うけなかった⋯⋯\n"
	.string "さむい⋯⋯　ブルブル⋯⋯$"

Route113_Text_MadelineIntro: @ 0x0825C67D
	.string "あたしの　ドンメルちゃんに\n"
	.string "かざんばいが　かからないように\l"
	.string "パラソルを　さしているの$"

Route113_Text_MadelineDefeat: @ 0x0825C6A8
	.string "はあ　はあ⋯⋯\n"
	.string "つかれましたわ⋯⋯$"

Route113_Text_MadelinePostBattle: @ 0x0825C6BA
	.string "とても　おつよいのね\n"
	.string "おねえさん　かんしん　しちゃったわ$"

Route113_Text_MadelineRegister: @ 0x0825C6D7
	.string "ね　ちょっと　パラソルに　はいって\n"
	.string "ポケナビを　とうろく　していって！$"

Route113_Text_MadelineRematchIntro: @ 0x0825C6FB
	.string "おひさしぶりね\n"
	.string "よろしかったら　しょうぶ　しません？$"

Route113_Text_MadelineRematchDefeat: @ 0x0825C716
	.string "おみごと　ですわ$"

Route113_Text_MadelinePostRematch: @ 0x0825C71F
	.string "あいかわらず　おつよいのね\n"
	.string "おねえさん　かんしん　しちゃったわ$"

Route113_Text_LaoIntro: @ 0x0825C73F
	.string "はいの　なかから　ドロロンッ！！\n"
	.string "しょうぶで　ござる！$"

Route113_Text_LaoDefeat: @ 0x0825C75B
	.string "まいったで　ござる$"

Route113_Text_LaoPostBattle: @ 0x0825C765
	.string "もっと　かくれかたを　けんきゅう　しよう\n"
	.string "それでは　しつれいするで　ござる$"

Route113_Text_LaoRegister: @ 0x0825C78B
	.string "やあ！　にんぽう\n"
	.string "ポケナビ　とうろくのじゅつで　ござる！$"

Route113_Text_LaoRematchIntro: @ 0x0825C7A8
	.string "はいの　なかから　ドロロロンッ！！\n"
	.string "しょうぶで　ござる！$"

Route113_Text_LaoRematchDefeat: @ 0x0825C7C5
	.string "まいったで　ござる$"

Route113_Text_LaoPostRematch: @ 0x0825C7CF
	.string "かくれかたは　よかったが\n"
	.string "しょうぶが　いまいち　だった⋯⋯\p"
	.string "それでは　しつれいするで　ござる$"

Route113_Text_LungIntro: @ 0x0825C7FE
	.string "みつけてくれて　ありがとう！\n"
	.string "でも　しょうぶは　べつだよ！$"

Route113_Text_LungDefeat: @ 0x0825C81C
	.string "にんぽう　かざんばい　がくれ！\p"
	.string "⋯⋯　って　もう　おわり？$"

Route113_Text_LungPostBattle: @ 0x0825C83A
	.string "かくれていて　なにが　しんぱいって\n"
	.string "だれも　とおらないと　さびしいんだよね$"

Route113_Text_ToriIntro: @ 0x0825C860
	.string "ナナ“ふたりで　かざんばい　あつめてるよ\n"
	.string "でも　ポケモンしょうぶも　するんだよ！$"

Route113_Text_ToriDefeat: @ 0x0825C889
	.string "ナナ“まけちゃった\n"
	.string "つまんないから　かざんばい　あつめよ！$"

Route113_Text_ToriPostBattle: @ 0x0825C8A7
	.string "ナナ“かざんばい　どれくらい　たまったかな？\n"
	.string "しろいビードロ　つくれると　いいのにね！$"

Route113_Text_ToriNotEnoughMons: @ 0x0825C8D3
	.string "ナナ“あたしたち　2たい2で　たたかいたいの\n"
	.string "そうしないと　まけちゃうもん！$"

Route113_Text_TiaIntro: @ 0x0825C8FA
	.string "ネネ“ふたりで　かざんばい　あつめてるよ\n"
	.string "でも　ポケモンしょうぶも　するんだよ！$"

Route113_Text_TiaDefeat: @ 0x0825C923
	.string "ネネ“かてなかった\n"
	.string "つまんないから　かざんばい　あつめよ！$"

Route113_Text_TiaPostBattle: @ 0x0825C941
	.string "ネネ“かざんばい　けっこう　たまったよ！\n"
	.string "もう　しろいビードロ　つくれるよ　きっと！$"

Route113_Text_TiaNotEnoughMons: @ 0x0825C96C
	.string "ネネ“あたしたち　2たい2で　たたかいたいの\n"
	.string "そうしないと　かてないもん！$"

Route113_Text_CobyIntro: @ 0x0825C992
	.string "おまえ　なんか　この　つばさで\n"
	.string "ふきとばして　やるぜっ！$"

Route113_Text_CobyDefeat: @ 0x0825C9AF
	.string "え　あれ？$"

Route113_Text_CobyPostBattle: @ 0x0825C9B5
	.string "そんなに　あっさり　かたれると\n"
	.string "なにを　いって　いいか　わからない⋯⋯$"

Route113_Text_SophieIntro: @ 0x0825C9D9
	.string "あったかくて　ねむく　なっちゃう\n"
	.string "ねむけ　ざましに　あいてを　してよ！$"

Route113_Text_SophieDefeat: @ 0x0825C9FD
	.string "きっと　これは　ユメなのよ⋯⋯$"

Route113_Text_SophiePostBattle: @ 0x0825CA0D
	.string "まけて　くやしい　から\n"
	.string "もう　ここで　フテね　しちゃうわ！\l"
	.string "ぐーぐー$"

Route113_Text_LawrenceIntro: @ 0x0825CA30
	.string "もしかして　かざんばい　あつめの\n"
	.string "とちゅう　だった？$"

Route113_Text_LawrenceDefeat: @ 0x0825CA4B
	.string "えへへ　まけちゃったね$"

Route113_Text_LawrencePostBattle: @ 0x0825CA57
	.string "ぼくも　はいに　もぐっちゃおう　かしら$"

Route113_Text_WyattIntro: @ 0x0825CA6B
	.string "ぼ　ボクと　たたかうって　いうんですか！\n"
	.string "まだ　つかまえた　ばかりなのに！$"

Route113_Text_WyattDefeat: @ 0x0825CA91
	.string "か　かって　うれしい　ですか！\n"
	.string "こんな　ボクに　かって　うれしいですか！$"

Route113_Text_WyattPostBattle: @ 0x0825CAB6
	.string "はいしゃに　こえを　かけて　くれるって\n"
	.string "いうんですか！\l"
	.string "か　カッコいい　ですね！　ふん！$"
	.incbin "baserom_jp.gba", 0x25cae3, 0x58b0
