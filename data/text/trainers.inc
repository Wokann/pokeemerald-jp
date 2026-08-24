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
Route114_Text_LennyIntro: @ 0x0825CAE3
	.string "やっほーっ！\p"
	.string "⋯⋯\p"
	.string "こだまの　かわりに\n"
	.string "やっほー！　って　いってくれよ！$"

Route114_Text_LennyDefeat: @ 0x0825CB08
	.string "やっほーっ！$"

Route114_Text_LennyPostBattle: @ 0x0825CB0F
	.string "こどものころ　こだま　って\n"
	.string "むこうの　やまにいる　モノマネさんが\l"
	.string "やっほー！　って　いってると　おもってた$"

Route114_Text_LucasIntro: @ 0x0825CB45
	.string "じゅんびを　おこたる　もの\n"
	.string "やまに　のぼるべからず！$"

Route114_Text_LucasDefeat: @ 0x0825CB60
	.string "やまは　こわい　ところだ⋯⋯$"

Route114_Text_LucasPostBattle: @ 0x0825CB6F
	.string "ふゆの　やまは　なだれや　ふぶきで\n"
	.string "そうなんする　きけんが　おおいぞ！$"

Route114_Text_ShaneIntro: @ 0x0825CB93
	.string "キャンプの　たのしみと　いえば\n"
	.string "つりに　はなびに　きもだめし！\p"
	.string "だけど　いちばんは\n"
	.string "ポケモンしょうぶ　だね！$"

Route114_Text_ShaneDefeat: @ 0x0825CBCA
	.string "つよすぎるーっ！$"

Route114_Text_ShanePostBattle: @ 0x0825CBD3
	.string "ぼくね　ポケモンと　いっしょに\n"
	.string "キャンプ　できるだけで　しあわせ　だよ$"

Route114_Text_NancyIntro: @ 0x0825CBF7
	.string "しょくごの　うんどう！\n"
	.string "わたしと　しょうぶ　しましょうよ！$"

Route114_Text_NancyDefeat: @ 0x0825CC15
	.string "まけちゃったー！$"

Route114_Text_NancyPostBattle: @ 0x0825CC1E
	.string "おいしい　ごはんも　たべたし\n"
	.string "なんだか　ねむくなって　きたわ⋯⋯$"

Route114_Text_SteveIntro: @ 0x0825CC3F
	.string "うふふふふふ⋯⋯\n"
	.string "ボクの　ポケモンと　しょうぶしない？$"

Route114_Text_SteveDefeat: @ 0x0825CC5B
	.string "ボ　ボクの　ポケモン⋯⋯$"

Route114_Text_StevePostBattle: @ 0x0825CC68
	.string "からだが　おおきくて　ゴツゴツ　かたくて\n"
	.string "おおきな　ツノと　するどい　キバ⋯⋯\l"
	.string "うふふふふ⋯⋯\l"
	.string "そんな　ポケモンが　ほしいなぁ⋯⋯$"

Route114_Text_SteveRegister: @ 0x0825CCAA
	.string "お　おぼえてろっ！　⋯⋯いや\n"
	.string "わすれられない　ように　こうしてやる！$"

Route114_Text_SteveRematchIntro: @ 0x0825CCCD
	.string "うふふふふふ⋯⋯\n"
	.string "ボクの　ポケモンと　しょうぶ　しようよ$"

Route114_Text_SteveRematchDefeat: @ 0x0825CCEA
	.string "ああ　ポケモン　みることが　できて\n"
	.string "しあわせ　だ⋯⋯$"

Route114_Text_StevePostRematch: @ 0x0825CD05
	.string "うふふふふふ⋯⋯\p"
	.string "ポケモンの　たたかっている　すがたに\n"
	.string "ぞくぞく　するんだ　ボク$"

Route114_Text_BernieIntro: @ 0x0825CD2E
	.string "キャンプファイヤー　するとき\n"
	.string "はなびを　するとき\l"
	.string "みずを　ようい　しておけよ！$"

Route114_Text_BernieDefeat: @ 0x0825CD56
	.string "しょうか　かつどう\n"
	.string "ありがとう！　ってか$"

Route114_Text_BerniePostBattle: @ 0x0825CD6B
	.string "ほんと　ひのようじん　だけは　おこたるな！\n"
	.string "ひを　あまく　みるんじゃないぜ！$"

Route114_Text_BernieRegister: @ 0x0825CD92
	.string "もえあがった　きもちの　まま\n"
	.string "ポケナビに　とうろく　しあおう！$"

Route114_Text_BernieRematchIntro: @ 0x0825CDB2
	.string "キャンプファイヤー　するとき\n"
	.string "はなびを　するとき\l"
	.string "みずを　ようい　するように　なったか！？$"

Route114_Text_BernieRematchDefeat: @ 0x0825CDE0
	.string "もえあがる　まえに\n"
	.string "けされた！　ってか$"

Route114_Text_BerniePostRematch: @ 0x0825CDF4
	.string "ほんと　ひのようじん　だけは　おこたるな！\n"
	.string "ひを　あまく　みるんじゃないぜ！$"

Route114_Text_ClaudeIntro: @ 0x0825CE1B
	.string "つりで　しょうぶ　すると\n"
	.string "きみには　かちめが　ないだろう\l"
	.string "ポケモンで　かかってきなさい！$"

Route114_Text_ClaudeDefeat: @ 0x0825CE48
	.string "つりの　しょうぶなら　かってた⋯⋯$"

Route114_Text_ClaudePostBattle: @ 0x0825CE5A
	.string "りゅうせいのたきで\n"
	.string "おおものでも　つると　しようかな\l"
	.string "あそこの　たきには　なにか　いそうだからね$"

Route114_Text_NolanIntro: @ 0x0825CE8B
	.string "つりも　すき　だが\n"
	.string "しょうぶも　すき！\p"
	.string "しょうぶを　いどまれたら\n"
	.string "つりの　さいちゅうでも　ことわらないよ！$"

Route114_Text_NolanDefeat: @ 0x0825CEC1
	.string "しょうぶは　すき　だが\n"
	.string "つよい　わけじゃ　ないんだ⋯⋯$"

Route114_Text_NolanPostBattle: @ 0x0825CEDD
	.string "こんどこそ！\p"
	.string "と　おもっちゃうから\n"
	.string "つりも　しょうぶも　やめられない$"

Route114_Text_TyraIntro: @ 0x0825CF00
	.string "カヨ“そうね\n"
	.string "なんとなく　そんな　きぶん　だから\l"
	.string "あなたにも　ポケモン　おしえたげよっか$"

Route114_Text_TyraDefeat: @ 0x0825CF2D
	.string "カヨ“すごい　たたかいかた！$"

Route114_Text_TyraPostBattle: @ 0x0825CF3C
	.string "カヨ“コウハイの　イヨに　あたしが\n"
	.string "ポケモンを　おしえて　あげたの！$"

Route114_Text_TyraNotEnoughMons: @ 0x0825CF5F
	.string "カヨ“うふふ！\n"
	.string "あたしたちと　しょうぶ　するなら\l"
	.string "ポケモン　いっぴきじゃ　ダメなのよ！$"

Route114_Text_IvyIntro: @ 0x0825CF8B
	.string "イヨ“あなた\n"
	.string "だれに　ポケモン　おそわったの？$"

Route114_Text_IvyDefeat: @ 0x0825CFA3
	.string "イヨ“すごい　たたかいかた！$"

Route114_Text_IvyPostBattle: @ 0x0825CFB2
	.string "イヨ“あたしが\n"
	.string "ポケモン　はじめた　きっかけは\l"
	.string "センパイが　おしえてくれた　からなの！$"

Route114_Text_IvyNotEnoughMons: @ 0x0825CFDE
	.string "イヨ“ポケモン　いっぴき　だけなの？\n"
	.string "なんだか　さみしい　かんじ　しちゃうね$"

Route114_Text_KaiIntro: @ 0x0825D005
	.string "でっかいの　つれたっ　でっかいの！$"

Route114_Text_KaiDefeat: @ 0x0825D017
	.string "あれー\n"
	.string "おおきさで　まけたんかな$"

Route114_Text_KaiPostBattle: @ 0x0825D028
	.string "よっしゃー！\n"
	.string "もっと　おおきいの　つるもんね！$"

Route114_Text_CharlotteIntro: @ 0x0825D040
	.string "あたし！\n"
	.string "かわいい　だけじゃ　ないんだから！$"

Route114_Text_CharlotteDefeat: @ 0x0825D057
	.string "かわいく　なーいっ！$"

Route114_Text_CharlottePostBattle: @ 0x0825D062
	.string "かわいい　だけの　ポケモンなんて　いや！\n"
	.string "かわいくて　ひとクセ　あるコが　すき！$"

Route114_Text_AngelinaIntro: @ 0x0825D08B
	.string "あなたの　ポケモンって\n"
	.string "どの　くらい　しんか　させてる？$"

Route114_Text_AngelinaDefeat: @ 0x0825D0A8
	.string "ふーん\n"
	.string "なるほどね$"

Route114_Text_AngelinaPostBattle: @ 0x0825D0B2
	.string "しんか　させると\n"
	.string "みためが　ものすごく　かわって\l"
	.string "ビックリする　ポケモンが　いるよね！$"
Route115_Text_TimothyIntro: @ 0x0825D0DE
	.string "ふむ⋯⋯\n"
	.string "なかなか　できそうだな⋯⋯\l"
	.string "わたしが　あいてを　してあげよう！$"

Route115_Text_TimothyDefeat: @ 0x0825D103
	.string "そうぞう　いじょうの　つよさだ⋯⋯！$"

Route115_Text_TimothyPostBattle: @ 0x0825D116
	.string "てんさい　など　いない\n"
	.string "すべては　どりょく！\l"
	.string "わたしは　そう　しんじている⋯⋯$"

Route115_Text_TimothyRegister: @ 0x0825D13E
	.string "ふむ⋯⋯\n"
	.string "こんな　まけかたも　ひさかたぶりだ\l"
	.string "できれば　また　あいてを　してほしい$"

Route115_Text_TimothyRematchIntro: @ 0x0825D168
	.string "ふむ⋯⋯\n"
	.string "あいかわらずの　みのこなし\l"
	.string "わたしの　あいてを　してもらおう！$"

Route115_Text_TimothyRematchDefeat: @ 0x0825D18D
	.string "あいかわらずの　つよさだ⋯⋯！$"

Route115_Text_TimothyPostRematch: @ 0x0825D19D
	.string "どりょく　あるのみ！\p"
	.string "まけたのは　まだまだ\n"
	.string "どりょくが　たりないからだ！$"

Route115_Text_KoichiIntro: @ 0x0825D1C2
	.string "おれのッ！\p"
	.string "ワンリキーがッ！\p"
	.string "たたかいを　のぞんでいるッ！$"

Route115_Text_KoichiDefeat: @ 0x0825D1E0
	.string "いててててっ！$"

Route115_Text_KoichiPostBattle: @ 0x0825D1E8
	.string "おれの　ワンリキー　たちがッ！\p"
	.string "つよさを　のぞむかぎり\p"
	.string "おれたちは　どこまでも　つよくなるぜッ！$"

Route115_Text_NobIntro: @ 0x0825D219
	.string "オレの　とくいわざは\n"
	.string "ずつきで　レンガを　くだく　ことだ！$"

Route115_Text_NobDefeat: @ 0x0825D237
	.string "うがーっ！\n"
	.string "あたまが　くだけたーっ！$"

Route115_Text_NobPostBattle: @ 0x0825D24A
	.string "ポケモンに　カラテを　おしえてるんだが\n"
	.string "オレより　つよく　なりそうで\l"
	.string "ちょっと　たのしみ　なんだ！$"

Route115_Text_NobRegister: @ 0x0825D27C
	.string "きみは　すげえな！\n"
	.string "きたえなおして　もういちど　しょうぶだ！$"

Route115_Text_NobRematchIntro: @ 0x0825D29B
	.string "きみに　まけてから　がんばって\n"
	.string "ポケモンと　おのれを　きたえなおしたぞ！\l"
	.string "さあ　もういちど　しょうぶ！$"

Route115_Text_NobRematchDefeat: @ 0x0825D2CF
	.string "うがーっ！\n"
	.string "また　まけたーっ！$"

Route115_Text_NobPostRematch: @ 0x0825D2DF
	.string "おれの　ポケモンは　まだまだ　つよくなる！\n"
	.string "がんばって　きたえるぞ！$"

Route115_Text_CyndyIntro: @ 0x0825D302
	.string "この　すなはまは　わたしの\n"
	.string "ヒミツの　しゅぎょう　ばしょ！\l"
	.string "かってに　はいって　こないでよ！$"

Route115_Text_CyndyDefeat: @ 0x0825D331
	.string "しゅぎょうが　たりないわ⋯⋯！$"

Route115_Text_CyndyPostBattle: @ 0x0825D341
	.string "すなが　クッションに　なるから\n"
	.string "からだを　いためないの\l"
	.string "さいこうの　しゅぎょう　ばしょね！$"

Route115_Text_CyndyRegister: @ 0x0825D36F
	.string "いいわ　あなたが　ここに　はいるの\n"
	.string "みとめてあげる！\l"
	.string "そのかわり　また　あいてを　たのむわよ！$"

Route115_Text_CyndyRematchIntro: @ 0x0825D39F
	.string "さあ　ポケモンしょうぶ　いくわよ！$"

Route115_Text_CyndyRematchDefeat: @ 0x0825D3B1
	.string "わたしは　たたかえるけど\n"
	.string "ポケモンが⋯⋯$"

Route115_Text_CyndyPostRematch: @ 0x0825D3C6
	.string "まけても　ちょっと　たのしいのは\n"
	.string "ほんとうに　ポケモンが　すき　だからかな？$"

Route115_Text_HectorIntro: @ 0x0825D3ED
	.string "ぼく　めずらしい　ポケモン　もってるんだ！\n"
	.string "よかったら　みせて　あげようか$"

Route115_Text_HectorDefeat: @ 0x0825D413
	.string "きみ⋯⋯\n"
	.string "ぼくの　ポケモン　ほしいでしょ？$"

Route115_Text_HectorPostBattle: @ 0x0825D429
	.string "こんなに　めずらしい　ポケモン　もってるんだ\n"
	.string "それだけで　ぼくは　まんぞく　なのさ！$"

Route115_Text_KyraIntro: @ 0x0825D454
	.string "はしりながら　しょうぶを　するわよッ！\n"
	.string "あなたも　ついて　きなさーい！$"

Route115_Text_KyraDefeat: @ 0x0825D478
	.string "はぁ　はぁ⋯⋯$"

Route115_Text_KyraPostBattle: @ 0x0825D480
	.string "はしりながら　たたかおうと　したのが\n"
	.string "まちがい　だったわよ！\l"
	.string "ひとっぱしり　して　アタマ　ひやすかな$"

Route115_Text_JaidenIntro: @ 0x0825D4B3
	.string "くらえーっ\n"
	.string "にんぽう　すごポケモンの　じゅつ！$"

Route115_Text_JaidenDefeat: @ 0x0825D4CB
	.string "わーん　しっぱいだ！$"

Route115_Text_JaidenPostBattle: @ 0x0825D4D6
	.string "でも　ぼくの　ポケモン\n"
	.string "すごポケモン　だった　でしょ？$"

Route115_Text_HeleneIntro: @ 0x0825D4F2
	.string "ふふっ　あたしの　ポケモンたちは\n"
	.string "くろおび　クラスの　つよさよ！$"

Route115_Text_HeleneDefeat: @ 0x0825D513
	.string "くやしすぎるわ！$"

Route115_Text_HelenePostBattle: @ 0x0825D51C
	.string "あたしより　つよい　ひとなんて\n"
	.string "めったに　あわないのに⋯⋯\p"
	.string "わかった！\n"
	.string "あなた　ジムリーダー　でしょ！$"

Route115_Text_AlixIntro: @ 0x0825D550
	.string "めが　あったからには　にがさないわよ！$"

Route115_Text_AlixDefeat: @ 0x0825D564
	.string "くっ⋯⋯　なかなか！$"

Route115_Text_AlixPostBattle: @ 0x0825D56F
	.string "あーあ！\n"
	.string "テレポートで　おうちに　かえろうかしら$"

Route115_Text_MarleneIntro: @ 0x0825D588
	.string "めいそうの　じゃまを　したわね⋯⋯\n"
	.string "おしおき　させて　もらうわ！$"

Route115_Text_MarleneDefeat: @ 0x0825D5A9
	.string "こころが　みだれて　しまう！$"

Route115_Text_MarlenePostBattle: @ 0x0825D5B8
	.string "ここで　ポケモンたちと\n"
	.string "めいそうを　していたの！\l"
	.string "でも　あまり　おちつかない　ところね$"
Route116_Text_ClarkIntro: @ 0x0825D5E4
	.string "トンネルが　つうじて　いないなら\n"
	.string "やまを　こえて　いけば　いいのだ！$"

Route116_Text_ClarkDefeat: @ 0x0825D607
	.string "ぜえ⋯⋯　ぜえ⋯⋯\n"
	.string "まけて　つかれて　しまった$"

Route116_Text_ClarkPostBattle: @ 0x0825D61F
	.string "トンネルなど　なくても　かまわん\n"
	.string "やまおとこは　やまが　みち　なのだ！$"

Route116_Text_JoeyIntro: @ 0x0825D643
	.string "おれの　ポケモン　つえーぞ！\n"
	.string "ちょっと　みてみろよ！$"

Route116_Text_JoeyDefeat: @ 0x0825D65E
	.string "あいたたたたっ！　キズが　できた！\n"
	.string "バンソーコー　はらなきゃ！$"

Route116_Text_JoeyPostBattle: @ 0x0825D67E
	.string "バンソーコーは　おとこの　くんしょう！\n"
	.string "また　ひとつ　ふえたぜ！$"

Route116_Text_JoseIntro: @ 0x0825D69F
	.string "ぼくの　むしポケモンは　つよいよ！\n"
	.string "しょうぶ　しようよ！$"

Route116_Text_JoseDefeat: @ 0x0825D6BC
	.string "まけた⋯⋯！\n"
	.string "かてると　おもったのに⋯⋯！$"

Route116_Text_JosePostBattle: @ 0x0825D6D2
	.string "むしポケモンは　しんかが　はやいから\n"
	.string "つよく　なるのも　はやい！$"

Route116_Text_JaniceIntro: @ 0x0825D6F3
	.string "わたしの　かわいい　ポケモンの　つよさ\n"
	.string "じっくりと　おしえて　あげるわ！$"

Route116_Text_JaniceDefeat: @ 0x0825D718
	.string "キミの　ほうが　いちまい　うわてね⋯⋯$"

Route116_Text_JanicePostBattle: @ 0x0825D72C
	.string "かわいさと　つよさを　かねそなえた　ポケモン\n"
	.string "それが　わたしの　りそうなの！$"

Route116_Text_JerryIntro: @ 0x0825D753
	.string "トレーナーズ　スクールで\n"
	.string "いろいろ　べんきょう　したからね\l"
	.string "じっせんで　たしかめるよ！$"

Route116_Text_JerryDefeat: @ 0x0825D77F
	.string "べんきょう　さぼってたから\n"
	.string "まけちゃったよ$"

Route116_Text_JerryPostBattle: @ 0x0825D795
	.string "トレーナーズ　スクールで\n"
	.string "もういちど　べんきょう　しなおさなきゃ\l"
	.string "ツツジさんに　おこられちゃうよ$"

Route116_Text_JerryRegister1: @ 0x0825D7C6
	.string "ポケナビには　トレーナーが\n"
	.string "とうろく　できるん　だって\l"
	.string "トレーナーズ　スクールで　ならったんだ！\p"
	.string "よく　わからないから　やってみてよ！$"

Route116_Text_JerryRegister2: @ 0x0825D80A
	.string "ポケナビには　トレーナーが\n"
	.string "とうろく　できるん　だって\l"
	.string "トレーナーズ　スクールで　ならったんだ！\p"
	.string "よく　わからないから　やってみてよ！$"

Route116_Text_JerryRematchIntro: @ 0x0825D84E
	.string "あれから　トレーナーズ　スクールで\n"
	.string "まじめに　べんきょう　したからね\l"
	.string "このまえ　みたいに　まけたりしないよ！$"

Route116_Text_JerryRematchDefeat: @ 0x0825D885
	.string "あれー？\n"
	.string "きちんと　べんきょう　したのに$"

Route116_Text_JerryPostRematch: @ 0x0825D89A
	.string "トレーナーズ　スクールで\n"
	.string "もういちど　べんきょう　しなおさなきゃ\l"
	.string "ツツジさんに　おこられちゃうよ$"

Route116_Text_KarenIntro: @ 0x0825D8CB
	.string "スクールでも　べんきょう\n"
	.string "かえりみち　でも　べんきょうよ！$"

Route116_Text_KarenDefeat: @ 0x0825D8E9
	.string "ショック\n"
	.string "まけちゃったよ$"

Route116_Text_KarenPostBattle: @ 0x0825D8F6
	.string "ああん！　これじゃ　ツツジさまのように\n"
	.string "エレガントな　トレーナーに　なれないわ！$"

Route116_Text_KarenRegister1: @ 0x0825D91F
	.string "あーっ　それ　ポケナビね！\n"
	.string "あたしも　もってるから　とうろくして！$"

Route116_Text_KarenRegister2: @ 0x0825D941
	.string "あーっ　それ　ポケナビね！\n"
	.string "あたしも　もってるから　とうろくして！$"

Route116_Text_KarenRematchIntro: @ 0x0825D963
	.string "あれから　ものすっごく　べんきょう　したの！\n"
	.string "その　せいか　みてもらうからね！$"

Route116_Text_KarenRematchDefeat: @ 0x0825D98B
	.string "ショック\n"
	.string "また　まけちゃったよ$"

Route116_Text_KarenPostRematch: @ 0x0825D99B
	.string "ツツジさまに　かったことが　あるの？\n"
	.string "それじゃ　いまの　あたしには　かてないわ$"

Route116_Text_SarahIntro: @ 0x0825D9C3
	.string "わたくし　いままで\n"
	.string "ひとに　なにかで　まけた　ことって\l"
	.string "ありませんの！$"

Route116_Text_SarahDefeat: @ 0x0825D9E7
	.string "まあ\n"
	.string "こんなの　はじめてですわ！$"

Route116_Text_SarahPostBattle: @ 0x0825D9F8
	.string "なにふじゆう　ない　くらし　ですけど\n"
	.string "ポケモンの　ことだけは\l"
	.string "おもいどおりに　なりません　のね$"

Route116_Text_DawsonIntro: @ 0x0825DA28
	.string "ぼくの　ポケモンの\n"
	.string "うつくしい　けなみに　みとれて\l"
	.string "キミは　なにも　できない！$"

Route116_Text_DawsonDefeat: @ 0x0825DA50
	.string "そりゃないぜ　ベイビー$"

Route116_Text_DawsonPostBattle: @ 0x0825DA5C
	.string "ああっ\n"
	.string "ポケモンの　けなみと\l"
	.string "ぼくの　ヘアーが　みだれた！\l"
	.string "びよういん　よやく　しなきゃ$"

Route116_Text_DevanIntro: @ 0x0825DA89
	.string "ガツンと　いってみようかあ！$"

Route116_Text_DevanDefeat: @ 0x0825DA98
	.string "あああ\n"
	.string "しょうぶに　ならんな　こりゃ$"

Route116_Text_DevanPostBattle: @ 0x0825DAAB
	.string "たまには　ほかの　タイプの\n"
	.string "ポケモンも　つかって　みるかなあ？$"

Route116_Text_JohnsonIntro: @ 0x0825DACB
	.string "この　さきって　いきどまりなんだ\n"
	.string "つまんない　から　しょうぶ　してね$"

Route116_Text_JohnsonDefeat: @ 0x0825DAEE
	.string "まけた　けど　おもしろかったよ！$"

Route116_Text_JohnsonPostBattle: @ 0x0825DAFF
	.string "まけちゃった　から\n"
	.string "ぼくの　たんパン　かしてあげても　いーよ！$"
Route117_Text_IsaacIntro: @ 0x0825DB1F
	.string "オレが　そだてている　ポケモンと\n"
	.string "しょうぶ　してくれないか？$"

Route117_Text_IsaacDefeat: @ 0x0825DB3E
	.string "みごとに　そだててるね⋯⋯$"

Route117_Text_IsaacPostBattle: @ 0x0825DB4C
	.string "つよさ　だけが　ポケモンじゃないよ！\n"
	.string "ポケモンの　こせいを　みがきあげるのも\l"
	.string "たのしみかたの　ひとつ　だね！$"

Route117_Text_IsaacRegister: @ 0x0825DB83
	.string "よーし　ますます　がんばって　そだてるぞ！\n"
	.string "きみ　そしたら　みにきて　くれるだろ？$"

Route117_Text_IsaacRematchIntro: @ 0x0825DBAD
	.string "オレが　そだてている　ポケモン\n"
	.string "あいかわらず　いい　かんじ　だよ！$"

Route117_Text_IsaacRematchDefeat: @ 0x0825DBCF
	.string "いい　そだてかた　してるね⋯⋯\n"
	.string "きみには　そだてやの　さいのう　あるかも$"

Route117_Text_IsaacPostRematch: @ 0x0825DBF4
	.string "いい　ぐあいに　そだってるね！\n"
	.string "ミナモシティの　ポケモンコンテストに\l"
	.string "でることを　おすすめ　するよ！$"

Route117_Text_LydiaIntro: @ 0x0825DC27
	.string "ポケモンを　ちゃんと　そだててるか\n"
	.string "わたしが　たしかめて　あげますね$"

Route117_Text_LydiaDefeat: @ 0x0825DC4A
	.string "ちゃんと　そだってますね$"

Route117_Text_LydiaPostBattle: @ 0x0825DC57
	.string "ポケモンの　こせいにも　きをくばって\n"
	.string "そだてて　みて　くださいね$"

Route117_Text_LydiaRegister: @ 0x0825DC78
	.string "よい　トレーナーさんに　あえて　よかった！\n"
	.string "これからも　よろしく　おねがいしますね$"

Route117_Text_LydiaRematchIntro: @ 0x0825DCA2
	.string "ポケモンを　ちゃんと　そだててるか\n"
	.string "また　わたしが　たしかめて　あげますね$"

Route117_Text_LydiaRematchDefeat: @ 0x0825DCC8
	.string "みごとに　そだってますね$"

Route117_Text_LydiaPostRematch: @ 0x0825DCD5
	.string "ポケモンの　せいかくに　よって\n"
	.string "すきな　ポロックが　あるみたいなの$"

Route117_Text_DylanIntro: @ 0x0825DCF7
	.string "トライアスロンの　まっさいちゅう　だけど\n"
	.string "さくっと　しょうぶ　しようじゃ　ないか！$"

Route117_Text_DylanDefeat: @ 0x0825DD21
	.string "たいりょく　なくなった！$"

Route117_Text_DylanPostBattle: @ 0x0825DD2E
	.string "まいったな⋯⋯\p"
	.string "いまの　しょうぶの　あいだに\n"
	.string "ビリに　なっちゃったかも⋯⋯？$"

Route117_Text_DylanRegister: @ 0x0825DD55
	.string "ポケモンも　つよく　なくちゃ　ダメか？\n"
	.string "きみさ　たまに　ぼくを　きたえてよ！$"

Route117_Text_DylanRematchIntro: @ 0x0825DD7C
	.string "トライアスロンの　まっさいちゅう　だけど\n"
	.string "ぼくには　よゆうが　あるからね\l"
	.string "さくっと　しょうぶ　しようじゃ　ないか！$"

Route117_Text_DylanRematchDefeat: @ 0x0825DDB6
	.string "また　たいりょく　なくなった！$"

Route117_Text_DylanPostRematch: @ 0x0825DDC6
	.string "およぎと　じてんしゃでは　トップだったけど\n"
	.string "ポケモンは　いまいち　じしんが　ないよ$"

Route117_Text_MariaIntro: @ 0x0825DDF0
	.string "トライアスロンの　れんしゅう\n"
	.string "ポケモンと　いっしょに　してるからさ\l"
	.string "スピードに　じしん　あるよ！$"

Route117_Text_MariaDefeat: @ 0x0825DE21
	.string "れんしゅうが　たりなかったかな？$"

Route117_Text_MariaPostBattle: @ 0x0825DE32
	.string "れんしゅうは　つづけてこそ\n"
	.string "いみが　あるのよね\p"
	.string "よーし！　また　れんしゅうよ\n"
	.string "あしたから！$"

Route117_Text_MariaRegister: @ 0x0825DE60
	.string "あなたは　れんしゅう　してる？\n"
	.string "よかったら　わたしが　あいてになるわ！$"

Route117_Text_MariaRematchIntro: @ 0x0825DE84
	.string "どう　れんしゅう　つづけてる？\n"
	.string "あたしは　もちろん　つづけてるわ\l"
	.string "その　しょうこ　みせちゃうから！$"

Route117_Text_MariaRematchDefeat: @ 0x0825DEB6
	.string "れんしゅうが　たりなかったかな？$"

Route117_Text_MariaPostRematch: @ 0x0825DEC7
	.string "あしたから　また　れんしゅう　するから\n"
	.string "よかったら　また　しょうぶ　してね！$"

Route117_Text_DerekIntro: @ 0x0825DEEE
	.string "むかしは　むしとりしょうねん！\n"
	.string "いまは　こんちゅうマニア！\p"
	.string "でも　ポケモンを　あいする　きもちは\n"
	.string "ずっと　かわらないぜ！$"

Route117_Text_DerekDefeat: @ 0x0825DF2B
	.string "ポケモンの　よわさも　かわらない⋯⋯$"

Route117_Text_DerekPostBattle: @ 0x0825DF3E
	.string "すきな　ことばかり　していたら\n"
	.string "いつのまにか　マニアって　よばれてるよ！\p"
	.string "まあ　むしポケモンに　くわしいからね\n"
	.string "マニアと　よばれて　とうぜん　なのさっ！$"

Route117_Text_AnnaIntro: @ 0x0825DF8B
	.string "ミホ“かわいい　コウハイの　まえ　だもん\n"
	.string "いいところ　みせちゃうんだから！$"

Route117_Text_AnnaDefeat: @ 0x0825DFB1
	.string "ミホ“もう！\n"
	.string "コウハイの　まえ　だから　かたせてよ！$"

Route117_Text_AnnaPostBattle: @ 0x0825DFCC
	.string "ミホ“あなたの　ポケモン\n"
	.string "なかなかの　コンビネーション　してる！\p"
	.string "そうね　あたしたちの\n"
	.string "つぎ　ぐらいに　すごいんじゃない？$"

Route117_Text_AnnaAndMegRegister: @ 0x0825E00A
	.string "ミホ“まけっぱなしでは\n"
	.string "ひきさがれない　わたしたち！\l"
	.string "また　きて　くれるわよね？$"

Route117_Text_AnnaNotEnoughMons: @ 0x0825E033
	.string "ミホ“あたしたちと　しょうぶ　したいなら\n"
	.string "ポケモンを　2ひきは　もってきてね！$"

Route117_Text_MegIntro: @ 0x0825E05B
	.string "リコ“すてきな　センパイとの　タッグで\n"
	.string "あなたを　まかしちゃうから！$"

Route117_Text_MegDefeat: @ 0x0825E07E
	.string "リコ“やーん\n"
	.string "センパイ　ごめんなさい！$"

Route117_Text_MegPostBattle: @ 0x0825E092
	.string "リコ“あたしが　センパイの\n"
	.string "あしを　ひっぱっちゃったの⋯⋯\p"
	.string "そうでなきゃ　あんた　かってないわよ！$"

Route117_Text_MegNotEnoughMons: @ 0x0825E0C4
	.string "リコ“ポケモン　1ぴき　しか　いないの？\n"
	.string "じゃあ　しょうぶは　できないわね\p"
	.string "あたしたち　2たい2の\n"
	.string "しょうぶを　たのしみたいの！$"

Route117_Text_AnnaRematchIntro: @ 0x0825E105
	.string "ミホ“コウハイの　まえで\n"
	.string "なんども　まけてられないのよね$"

Route117_Text_AnnaRematchDefeat: @ 0x0825E122
	.string "ミホ“ちょうしが　でなかったのよ$"

Route117_Text_AnnaPostRematch: @ 0x0825E133
	.string "ミホ“あなたの　ポケモン\n"
	.string "なかなかの　コンビネーションしてる！\p"
	.string "そうね　あたしたちの\n"
	.string "つぎ　ぐらいに　すごいんじゃない？$"

Route117_Text_AnnaRematchNotEnoughMons: @ 0x0825E170
	.string "ミホ“あたしたちと　しょうぶ　したいなら\n"
	.string "ポケモンを　2ひきは　もってきてね！$"

Route117_Text_MegRematchIntro: @ 0x0825E198
	.string "リコ“センパイとの　タッグで\n"
	.string "こんどこそ　あなたを　まかしちゃうから！$"

Route117_Text_MegRematchDefeat: @ 0x0825E1BC
	.string "リコ“つよすぎるわ$"

Route117_Text_MegPostRematch: @ 0x0825E1C6
	.string "リコ“センパイと　いっしょに　たたかったのに\n"
	.string "まけるだなんて⋯⋯　おちこんじゃう！$"

Route117_Text_MegRematchNotEnoughMons: @ 0x0825E1F0
	.string "リコ“ポケモン　1ぴき　しか　いないの？\n"
	.string "じゃあ　しょうぶは　できないわね\p"
	.string "あたしたち　2たい2の\n"
	.string "しょうぶを　たのしみたいの！$"

Route117_Text_MelinaIntro: @ 0x0825E231
	.string "すてきな　おはなを　みながら\n"
	.string "しょうぶする　なんて　すてきよね！$"

Route117_Text_MelinaDefeat: @ 0x0825E252
	.string "へーえ　いいカンジね　あんた！$"

Route117_Text_MelinaPostBattle: @ 0x0825E262
	.string "おはなを　みながら　はしると\n"
	.string "きもちいいわよ！$"

Route117_Text_BrandiIntro: @ 0x0825E27A
	.string "エスパーポケモンに\n"
	.string "ひめられた　ちからを　おみせするわ！$"

Route117_Text_BrandiDefeat: @ 0x0825E297
	.string "おどろいたわ$"

Route117_Text_BrandiPostBattle: @ 0x0825E29E
	.string "エスパーポケモンは　おくが　ふかいの\n"
	.string "あなたも　つかまえて　ごらんなさい$"

Route117_Text_AishaIntro: @ 0x0825E2C3
	.string "かつこと　だけを　かんがえて　たたかうわ！$"

Route117_Text_AishaDefeat: @ 0x0825E2D9
	.string "まけても　くやしがったり　しない！\n"
	.string "そんなひまが　あったら　とっくんよ$"

Route117_Text_AishaPostBattle: @ 0x0825E2FD
	.string "まけるかな？と　しんぱい　すると\n"
	.string "よけいに　まけちゃうと　おもうのよね$"
Route118_Text_RoseIntro: @ 0x0825E321
	.string "はなの　かおりは　ふしぎな　ちから\n"
	.string "からだも　こころも　きれいに　なるわ$"

Route118_Text_RoseDefeat: @ 0x0825E346
	.string "あらら\n"
	.string "まけちゃったわね$"

Route118_Text_RosePostBattle: @ 0x0825E353
	.string "はなも　ポケモンも\n"
	.string "いい　かおりの　ものが　だいすき！\l"
	.string "クサイにおいは⋯⋯　かんべんね$"

Route118_Text_RoseRegister: @ 0x0825E37F
	.string "あら　その　においは　ポケナビね\n"
	.string "ぜひとも　とうろく　しあいましょう！$"

Route118_Text_RoseRematchIntro: @ 0x0825E3A3
	.string "いい　かおりに　さそわれて\n"
	.string "いらしたのかしら？$"

Route118_Text_RoseRematchDefeat: @ 0x0825E3BB
	.string "においの　こうか⋯⋯\n"
	.string "あんまり　きかなかったわね$"

Route118_Text_RosePostRematch: @ 0x0825E3D4
	.string "あまいかおりを　うまく　つかうと\n"
	.string "ポケモンが　さそわれて　やってくるわね$"

Route118_Text_PerryIntro: @ 0x0825E3F9
	.string "かれいに　おおぞらを　まう\n"
	.string "とりポケモンが　さいこう　だぜ！$"

Route118_Text_PerryDefeat: @ 0x0825E418
	.string "うう⋯⋯　まけた⋯⋯$"

Route118_Text_PerryPostBattle: @ 0x0825E423
	.string "きみも　いい　ポケモンを　もってるね！\n"
	.string "ぼくも　まけずに　そだてよっと！$"

Route118_Text_ChesterIntro: @ 0x0825E448
	.string "はばたけ！\n"
	.string "おいらの　とりポケモン！$"

Route118_Text_ChesterDefeat: @ 0x0825E45B
	.string "はばたいたけど⋯⋯$"

Route118_Text_ChesterPostBattle: @ 0x0825E465
	.string "もっと　つよくなると\n"
	.string "じゆうに　とべるように　なるのにな！$"

Route118_Text_BarnyIntro: @ 0x0825E483
	.string "あたしゃ　つりびとだが　トレーナーでもある\n"
	.string "つった　ポケモン　ちゃんと　そだててるよ！$"

Route118_Text_BarnyDefeat: @ 0x0825E4AF
	.string "そだてたはず　なんだが⋯⋯？$"

Route118_Text_BarnyPostBattle: @ 0x0825E4BE
	.string "つりを　しながら\n"
	.string "ポケモン　そだてても　かてなかった⋯⋯\l"
	.string "どっちも　はんぱ　だったのか！？$"

Route118_Text_WadeIntro: @ 0x0825E4EC
	.string "つりびとに　だいじ　なのは　どうぐ！\n"
	.string "トレーナーに　だいじ　なのは\l"
	.string "もちろん　ポケモンと　ハートだな！$"

Route118_Text_WadeDefeat: @ 0x0825E520
	.string "ハートの　しょうぶで　まけたのか？$"

Route118_Text_WadePostBattle: @ 0x0825E532
	.string "つり　というのも\n"
	.string "ひとと　ポケモンとの\l"
	.string "しんけん　しょうぶ　だな！$"

Route118_Text_DaltonIntro: @ 0x0825E554
	.string "ぼくの　メロディ\n"
	.string "あなたの　こころに　とどけるよ$"

Route118_Text_DaltonDefeat: @ 0x0825E56D
	.string "ルー　ルルルー$"

Route118_Text_DaltonPostBattle: @ 0x0825E575
	.string "エレキギターって\n"
	.string "ただ　うるさい　だけじゃ　ないんだ⋯⋯\p"
	.string "こうして　こころに　しみる\n"
	.string "メロディも　かなでられるのさ⋯⋯$"

Route118_Text_DaltonRegister: @ 0x0825E5B1
	.string "もっと　いい　メロディが　できたら\n"
	.string "ききにおいでよ！$"

Route118_Text_DaltonRematchIntro: @ 0x0825E5CC
	.string "ぼくと　ポケモンの　メロディ\n"
	.string "あなたの　こころに　とどけるよ$"

Route118_Text_DaltonRematchDefeat: @ 0x0825E5EB
	.string "ルー　ルルルー$"

Route118_Text_DaltonPostRematch: @ 0x0825E5F3
	.string "ひいてるときの　ぼくの　きもちが\n"
	.string "エレキギターを　とおして\l"
	.string "あなたに　とどく　はずなのさ⋯⋯$"

Route118_Text_DeandreIntro: @ 0x0825E622
	.string "いけいけー！\n"
	.string "ボクの　ポケモン　1ごう　2ごう　3ごう！$"

Route118_Text_DeandreDefeat: @ 0x0825E63F
	.string "ああ　だいじょうぶか！？\n"
	.string "ボクの　ポケモン　1ごう　2ごう　3ごう！$"

Route118_Text_DeandrePostBattle: @ 0x0825E662
	.string "ボクの　ポケモン　せんたい\n"
	.string "カッコいい　だろー！\l"
	.string "まね　しても　いーぜー！$"
Route119_Text_BrentIntro: @ 0x0825E688
	.string "ボクらは　モノマネサークル！\n"
	.string "キミの　うごきを　マネするよ！$"

Route119_Text_BrentDefeat: @ 0x0825E6A7
	.string "うわあ　まけたーっ！$"

Route119_Text_BrentPostBattle: @ 0x0825E6B2
	.string "マネを　して　なにが　たのしいか⋯⋯\p"
	.string "ふふふ⋯⋯\n"
	.string "キミには　わからない　だろうよ$"

Route119_Text_DonaldIntro: @ 0x0825E6DB
	.string "ようやく　であえたね！\n"
	.string "ぼくの　むしポケモンが　あいて　するよ！$"

Route119_Text_DonaldDefeat: @ 0x0825E6FC
	.string "であわなければ　よかった⋯⋯$"

Route119_Text_DonaldPostBattle: @ 0x0825E70B
	.string "もっと　キミの　マネを　したい！\n"
	.string "ほら　はやく　うごいてよ！$"

Route119_Text_TaylorIntro: @ 0x0825E72A
	.string "きみが　まえに　すすんだら\n"
	.string "ぼくらも　すすむ\p"
	.string "きみが　みぎへ　まがれば\n"
	.string "ぼくらも　まがる⋯⋯$"

Route119_Text_TaylorDefeat: @ 0x0825E759
	.string "キミが　かっても\n"
	.string "ぼくは　まける⋯⋯$"

Route119_Text_TaylorPostBattle: @ 0x0825E76C
	.string "うーん　しょうぶの　しょうはい　だけは\n"
	.string "マネ　できないよなあ⋯⋯\l"
	.string "なんか　くやしい⋯⋯$"

Route119_Text_DougIntro: @ 0x0825E798
	.string "やっと　ボクを　つかまえられたね！\n"
	.string "それとも　にげようと　していたのかな？$"

Route119_Text_DougDefeat: @ 0x0825E7BE
	.string "すばらしい　たたかい　だったな！$"

Route119_Text_DougPostBattle: @ 0x0825E7CF
	.string "ボクらは　モノマネサークル！\n"
	.string "たのしんで　もらえたかな？$"

Route119_Text_GregIntro: @ 0x0825E7EC
	.string "ボクが　だれなのか　わからないだろう？\p"
	.string "⋯⋯まあ　ボクも　キミのこと　しらないから\n"
	.string "こうして　たたかうんだけどね！$"

Route119_Text_GregDefeat: @ 0x0825E826
	.string "けっこう　つよい　じゃんか！$"

Route119_Text_GregPostBattle: @ 0x0825E835
	.string "キミが　どこかに　いくまで\n"
	.string "ボクらは　マネを　つづけるよ！$"

Route119_Text_KentIntro: @ 0x0825E853
	.string "モノマネ　だいすきな　ひとが\n"
	.string "あつまって　つくった　モノマネサークル！\p"
	.string "であった　そのとき\n"
	.string "しょうぶが　はじまる！$"

Route119_Text_KentDefeat: @ 0x0825E88D
	.string "まいりましたーっ！$"

Route119_Text_KentPostBattle: @ 0x0825E897
	.string "キミも　モノマネサークルに　はいらない？$"

Route119_Text_JacksonIntro: @ 0x0825E8AC
	.string "サバイバルに　ひつような\n"
	.string "ちしきと　ぎじゅつを　もつ　もの！\l"
	.string "それが　ポケモンレンジャーさ！$"

Route119_Text_JacksonDefeat: @ 0x0825E8DB
	.string "ポケモンの　ちしきは　たらなかった⋯⋯$"

Route119_Text_JacksonPostBattle: @ 0x0825E8EF
	.string "ぶんめい　から　はなれて\n"
	.string "にんげんの　やせいを　めざめさせる！\l"
	.string "それが　オレたちの　テーマさ！$"

Route119_Text_JacksonRegister: @ 0x0825E91F
	.string "ちしきぶそくと　わらわずに\n"
	.string "こんど　また　あいてを　してやってくれよな$"

Route119_Text_JacksonRematchIntro: @ 0x0825E943
	.string "ポケモンと　いることで\n"
	.string "やせいを　とりもどすのさ！$"

Route119_Text_JacksonRematchDefeat: @ 0x0825E95D
	.string "あいかわらず　つよいな！$"

Route119_Text_JacksonPostRematch: @ 0x0825E96A
	.string "とにかく　ポケモンを　しんじろ！\n"
	.string "じぶんを　しんじろ！\l"
	.string "そうすれば　みちは　ひらける！$"

Route119_Text_CatherineIntro: @ 0x0825E996
	.string "あら　あなた⋯⋯\n"
	.string "ぼうけんを　している　わりには\l"
	.string "ずいぶん　みがるな　かっこうね！$"

Route119_Text_CatherineDefeat: @ 0x0825E9C0
	.string "じゅんび　ぶそくは　じこの　もと⋯⋯$"

Route119_Text_CatherinePostBattle: @ 0x0825E9D3
	.string "ずいぶん　みがるな　かっこう　だけど\n"
	.string "ひつような　どうぐは　もってるし\l"
	.string "きりょく　たいりょく　じゅうぶんね！$"

Route119_Text_CatherineRegister: @ 0x0825EA0A
	.string "トレーナーの　ひつじゅひん　ポケナビは\n"
	.string "ちゃんと　もってる？\p"
	.string "あっ　もってるわね！　とうろくしましょ$"

Route119_Text_CatherineRematchIntro: @ 0x0825EA3D
	.string "ポケモンと　いっしょの　ぼうけんは\n"
	.string "うまく　いってるかしら？$"

Route119_Text_CatherineRematchDefeat: @ 0x0825EA5C
	.string "まだ　なにかが\n"
	.string "たりなかったわね⋯⋯$"

Route119_Text_CatherinePostRematch: @ 0x0825EA6F
	.string "トレーナーの　あなたが\n"
	.string "ポケモンを　たよって　いるように\l"
	.string "ポケモンも　あなたを　たよっているのよ！$"

Route119_Text_HughIntro: @ 0x0825EAA1
	.string "おおぞらは　おとこの　ロマン！\p"
	.string "じゆうに　そらを　とぶ　きもちよさは\n"
	.string "なにごとにも　かえがたい！$"

Route119_Text_HughDefeat: @ 0x0825EAD2
	.string "まけたーっ！$"

Route119_Text_HughPostBattle: @ 0x0825EAD9
	.string "そらを　とびまわる　ユメは\n"
	.string "とりポケモンの　おかげで　かなえられたよ！$"

Route119_Text_PhilIntro: @ 0x0825EAFD
	.string "ぼくの　とりポケモンの　じつりょくを\n"
	.string "みせて　あげるよ！$"

Route119_Text_PhilDefeat: @ 0x0825EB1A
	.string "じつりょく　ぶそく　だった⋯⋯$"

Route119_Text_PhilPostBattle: @ 0x0825EB2A
	.string "ぼくは　ちいさい　ころから\n"
	.string "とりポケモンに　あこがれて　いたんだ！$"

Route119_Text_YasuIntro: @ 0x0825EB4C
	.string "かげに　ひそみ　やみに　いきる\n"
	.string "それが　オレの　さだめ⋯⋯！\l"
	.string "いざ　ポケモンしょうぶ！$"

Route119_Text_YasuDefeat: @ 0x0825EB78
	.string "まいった⋯⋯！$"

Route119_Text_YasuPostBattle: @ 0x0825EB80
	.string "しょうぶに　やぶれた　ものは\n"
	.string "いさぎよく　かげに　もどる⋯⋯\l"
	.string "それも　さだめ⋯⋯$"

Route119_Text_TakashiIntro: @ 0x0825EBA9
	.string "ゆだん　してると\n"
	.string "いたい　めに　あうぜ！$"

Route119_Text_TakashiDefeat: @ 0x0825EBBE
	.string "つよいな　きみーっ！$"

Route119_Text_TakashiPostBattle: @ 0x0825EBC9
	.string "きしゅう　さくせんは　シッパイだった⋯⋯$"

Route119_Text_HideoIntro: @ 0x0825EBDE
	.string "きを　かくすなら　もりのなか！$"

Route119_Text_HideoDefeat: @ 0x0825EBEE
	.string "つわもので　ござるな$"

Route119_Text_HideoPostBattle: @ 0x0825EBF9
	.string "きを　かくすなら　もりのなか！\n"
	.string "ポケモンを　かくすなら　ポケモンのなか！\p"
	.string "とくに　いみは　ないでござる$"

Route119_Text_ChrisIntro: @ 0x0825EC2D
	.string "わたしに　はなしかけた⋯⋯\n"
	.string "つまり　しょうぶを　いどむ　つもりだな！\p"
	.string "よーし！　なみのり　しながら\n"
	.string "つりあげた　ポケモンで　たたかうぞ！$"

Route119_Text_ChrisDefeat: @ 0x0825EC72
	.string "かつための　ポイントが\n"
	.string "ちっとも　わからん！$"

Route119_Text_ChrisPostBattle: @ 0x0825EC89
	.string "なみのりを　つかう！\p"
	.string "ポケモンの　せなかに　のって\n"
	.string "つりを　たのしむ！\p"
	.string "なんて　ゆうがな　ひととき　だろう！$"

Route119_Text_FabianIntro: @ 0x0825ECC0
	.string "デケデケデケデケ\n"
	.string "かつぜーヘ　おれたちーヒ　かつぜーヘ$"

Route119_Text_FabianDefeat: @ 0x0825ECDC
	.string "まけたぜーヘ　あっさりーヒ　まけたぜーヘ$"

Route119_Text_FabianPostBattle: @ 0x0825ECF1
	.string "デケデケデケデケ\n"
	.string "にどとーホ　おれにーヒ　かまうなよーホ$"

Route119_Text_DaytonIntro: @ 0x0825ED0E
	.string "ホッホッホー！\n"
	.string "こども　トレーナーは　だいすきだぞ！\l"
	.string "おじちゃんと　たたかおうっ！$"

Route119_Text_DaytonDefeat: @ 0x0825ED38
	.string "やるなー　ホッホッホ！$"

Route119_Text_DaytonPostBattle: @ 0x0825ED44
	.string "ホッホッホー！\n"
	.string "こども　トレーナーの　げんきを\l"
	.string "みならって　おじちゃん　がんばるぞ！$"

Route119_Text_RachelIntro: @ 0x0825ED6F
	.string "いつでも　どこでも\n"
	.string "パラソルを　てばなさないの！$"

Route119_Text_RachelDefeat: @ 0x0825ED88
	.string "いやん　そんなあ$"

Route119_Text_RachelPostBattle: @ 0x0825ED91
	.string "パラソルが　おもく　ないかって？\n"
	.string "キミの　バッグの　ほうが\l"
	.string "いっぱい　はいってるじゃない$"
Route120_Text_ColinIntro: @ 0x0825EDBE
	.string "そらを　とんでいる　ポケモンに\n"
	.string "ダメージを　あたえる　ワザを　もってる？$"

Route120_Text_ColinDefeat: @ 0x0825EDE3
	.string "キミの　ほうが\n"
	.string "いちまい　うわて　だった！$"

Route120_Text_ColinPostBattle: @ 0x0825EDF9
	.string "そらをとぶ　って　ワザは　べんりだな！\p"
	.string "そらを　とんでいる　あいだは\n"
	.string "ほとんどの　ワザが　あたらないだろ？$"

Route120_Text_RobertIntro: @ 0x0825EE2F
	.string "ボクの　ポケモンは　つよいぜ！\n"
	.string "キミの　ポケモンは　どうかな？$"

Route120_Text_RobertDefeat: @ 0x0825EE4F
	.string "キミの　ポケモンの　ほうが\n"
	.string "つよかった⋯⋯！$"

Route120_Text_RobertPostBattle: @ 0x0825EE66
	.string "どんどん　つよくなる　ポケモンは\n"
	.string "ほんと　たよりに　なるよなー！$"

Route120_Text_RobertRegister: @ 0x0825EE87
	.string "キミって　きたい　できそうだなー！\n"
	.string "ポケナビに　とうろく　しておきたい！$"

Route120_Text_RobertRematchIntro: @ 0x0825EEAC
	.string "どんどん　つよくなる　ポケモンは\n"
	.string "ほんと　たよりに　なるよなー！$"

Route120_Text_RobertRematchDefeat: @ 0x0825EECD
	.string "キミの　ポケモン\n"
	.string "ほんとうに　つよいんだな⋯⋯$"

Route120_Text_RobertPostRematch: @ 0x0825EEE5
	.string "ポケモンが　つよくなるのと　いっしょに\n"
	.string "おれも　つよくならないとなー！$"

Route120_Text_LorenzoIntro: @ 0x0825EF09
	.string "きみの　ポケモン\n"
	.string "そうなん　しないか　みてあげよう！$"

Route120_Text_LorenzoDefeat: @ 0x0825EF24
	.string "そんなに　つよい　ポケモンと　いっしょなら\n"
	.string "そうなんの　おそれは　ないな！$"

Route120_Text_LorenzoPostBattle: @ 0x0825EF4A
	.string "ポケモンと　いっしょに　どこまでもいく\n"
	.string "トレーナーの　よろこびと　いえるだろう！$"

Route120_Text_JennaIntro: @ 0x0825EF73
	.string "あなたの　たいりょく　どう？\n"
	.string "たいりょく　ぶそくだと\l"
	.string "いざと　いうとき　こまるわよ！$"

Route120_Text_JennaDefeat: @ 0x0825EF9E
	.string "たいりょく　だけは　あったのに⋯⋯$"

Route120_Text_JennaPostBattle: @ 0x0825EFB0
	.string "たいりょく　づくりが　わたしの　にっか\n"
	.string "まいにち　ポケモンと　ランニングよ！$"

Route120_Text_JeffreyIntro: @ 0x0825EFD7
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\l"
	.string "しょうぶ　する⋯⋯？$"

Route120_Text_JeffreyDefeat: @ 0x0825EFF4
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "まけた⋯⋯$"

Route120_Text_JeffreyPostBattle: @ 0x0825F003
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\l"
	.string "がんばろう⋯⋯$"

Route120_Text_JeffreyRegister: @ 0x0825F01D
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\l"
	.string "ポケナビ　もってる⋯⋯？$"

Route120_Text_JeffreyRematchIntro: @ 0x0825F03C
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\l"
	.string "また　しょうぶ　する⋯⋯？$"

Route120_Text_JeffreyRematchDefeat: @ 0x0825F05C
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "また　まけた⋯⋯$"

Route120_Text_JeffreyPostRematch: @ 0x0825F06E
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\l"
	.string "また　がんばろう⋯⋯\l"
	.string "だいじな　むしポケモンの　ために⋯⋯$"

Route120_Text_JenniferIntro: @ 0x0825F09E
	.string "ポケモンには　いろんな　とくせいが　ある\n"
	.string "それを　かんがえてこそ\l"
	.string "いちりゅうの　トレーナーに　なれるのよ！$"

Route120_Text_JenniferDefeat: @ 0x0825F0D4
	.string "なかなか　かんがえてるのね$"

Route120_Text_JenniferPostBattle: @ 0x0825F0E2
	.string "そう　ポケモンの　とくせいに　よって\n"
	.string "たたかいかたも　いろいろ　かわってくるわ！$"

Route120_Text_ChipIntro: @ 0x0825F10B
	.string "なんだね　きみは？\p"
	.string "もしかして　ひょっとすると\n"
	.string "あるかもしれない　といわれる\l"
	.string "こだいの　いせきを　さがしに　きたのかね！？$"

Route120_Text_ChipDefeat: @ 0x0825F149
	.string "まいったね　こりゃ$"

Route120_Text_ChipPostBattle: @ 0x0825F153
	.string "あの　おおきな　いわ\n"
	.string "わたしは　いせき　だと　おもいたいが\l"
	.string "それにしては　いりぐちが　ないね⋯⋯$"

Route120_Text_ClarissaIntro: @ 0x0825F184
	.string "あたしが　パラソルを　もってる　りゆう？\p"
	.string "うふふ　あたしに　かてたら\n"
	.string "おしえて　あげても　いいかな？$"

Route120_Text_ClarissaDefeat: @ 0x0825F1B7
	.string "パラソルで　ポケモンの　こうげきは\n"
	.string "しのげないのね⋯⋯$"

Route120_Text_ClarissaPostBattle: @ 0x0825F1D3
	.string "あたしの　ポケモンたちも\n"
	.string "あつい　ひざしは　にがてだと　おもうの\l"
	.string "だから　こうして　パラソルを　もってるのよ$"

Route120_Text_AngelicaIntro: @ 0x0825F20A
	.string "あたしと　ポケモンと　パラソル\n"
	.string "どれか　ひとつ　かけていても\l"
	.string "うつくしさが　そこなわれるんだわ$"

Route120_Text_AngelicaDefeat: @ 0x0825F23A
	.string "うつくしさが\n"
	.string "だいなしに　なっちゃったわ$"

Route120_Text_AngelicaPostBattle: @ 0x0825F24F
	.string "あなたに　パラソルは　にあわないわ！\p"
	.string "だって　こんなの　もっていたら\n"
	.string "すっごく　ジャマに　なりそう　なんだもの$"

Route120_Text_KeigoIntro: @ 0x0825F287
	.string "ポケモンの　うごきを　とりいれて\n"
	.string "あたらしい　にんぽうを　あみだすんだ！$"

Route120_Text_KeigoDefeat: @ 0x0825F2AC
	.string "あたらしい　にんぽう\n"
	.string "かんせいまで　まだまだ　かかりそうだ$"

Route120_Text_KeigoPostBattle: @ 0x0825F2CA
	.string "ニンジャの　せんせいを　さがして\n"
	.string "でしいり　しようかな？$"

Route120_Text_RileyIntro: @ 0x0825F2E7
	.string "ぼくたち　ニンジャごっこの　かくれぬの！\n"
	.string "どこに　いるのか　わからなかっただろ！$"

Route120_Text_RileyDefeat: @ 0x0825F310
	.string "まけた！\n"
	.string "かくれぬので　かくれるか？$"

Route120_Text_RileyPostBattle: @ 0x0825F323
	.string "ぼくたち　ニンジャごっこの　かくれぬの！\n"
	.string "これって　てづくり　なんだぜ！$"

Route120_Text_CallieIntro: @ 0x0825F348
	.string "よそみ　してると　ケガするよ！$"

Route120_Text_CallieDefeat: @ 0x0825F358
	.string "いたいめに　あったのは　あたしのほうか$"

Route120_Text_CalliePostBattle: @ 0x0825F36C
	.string "やっぱり　しんか　させようかな？\n"
	.string "このままでも　かわいい　けど$"

Route120_Text_LeonelIntro: @ 0x0825F38C
	.string "きみの　てもち　ポケモン\n"
	.string "いろんな　タイプが　そろって　いるか？$"

Route120_Text_LeonelDefeat: @ 0x0825F3AD
	.string "きみの　こだわり　みせてもらったよ！$"

Route120_Text_LeonelPostBattle: @ 0x0825F3C0
	.string "すきな　ポケモン　だけで\n"
	.string "つよいって　いうのが　さいこうだね$"
Route121_Text_VanessaIntro: @ 0x0825F3DF
	.string "あたしの　とっても　プリティな\n"
	.string "ポケモンを　かわいがってよ！$"

Route121_Text_VanessaDefeat: @ 0x0825F3FE
	.string "かわいがるの　いみが　ちがうわ！$"

Route121_Text_VanessaPostBattle: @ 0x0825F40F
	.string "ミナモの　コンテストに　いくのよ\n"
	.string "あたしの　ポケモンなら\l"
	.string "マスター　ランクでも　らくしょうよ！$"

Route121_Text_WalterIntro: @ 0x0825F43F
	.string "せかい　かっこくを\n"
	.string "ポケモンと　いっしょに　まわってきた\p"
	.string "すこしは　うでに　じしんが　ありますよ！$"

Route121_Text_WalterDefeat: @ 0x0825F471
	.string "おみごと　ですな$"

Route121_Text_WalterPostBattle: @ 0x0825F47A
	.string "また　ポケモンと　いっしょに\n"
	.string "せかいを　まわってみたい　ものです$"

Route121_Text_WalterRegister: @ 0x0825F49B
	.string "あなたの　うでまえは　たいしたものだ\n"
	.string "ぜひ　きねんに　とうろくを⋯⋯$"

Route121_Text_WalterRematchIntro: @ 0x0825F4BE
	.string "せかい　かっこくを\n"
	.string "ポケモンと　いっしょに　まわってきた\p"
	.string "すこしは　うでに　じしんが　ありますよ！$"

Route121_Text_WalterRematchDefeat: @ 0x0825F4F0
	.string "おみごと　ですな！$"

Route121_Text_WalterPostRematch: @ 0x0825F4FA
	.string "あなたと　その　ポケモンなら\n"
	.string "がいこくでも　つよいと　いわれるでしょう！$"

Route121_Text_TammyIntro: @ 0x0825F51F
	.string "よの　なかには　ふしぎな　ちからが\n"
	.string "いっぱい　あるの⋯⋯$"

Route121_Text_TammyDefeat: @ 0x0825F53C
	.string "あたし　まけたのね⋯⋯$"

Route121_Text_TammyPostBattle: @ 0x0825F548
	.string "おくりびやま⋯⋯\n"
	.string "あそこに　ふしぎな　ちからが　あるの⋯⋯$"

Route121_Text_KateIntro: @ 0x0825F566
	.string "マナ“ふたり　そろえば　こわいもの　なし！\n"
	.string "あたしたちの　つよさ　みせつけちゃうから！$"

Route121_Text_KateDefeat: @ 0x0825F592
	.string "マナ“コウハイの　まえで　かっこわるいわ⋯⋯$"

Route121_Text_KatePostBattle: @ 0x0825F5A9
	.string "マナ“あたしって　たよられちゃうと\n"
	.string "つい　かっこいい　ところ\l"
	.string "みせたく　なっちゃうのよね⋯⋯$"

Route121_Text_KateNotEnoughMons: @ 0x0825F5D8
	.string "マナ“ポケモン　1ぴき　しか　いないのね\n"
	.string "じゃあ　しょうぶは　できないわ！\p"
	.string "だって　よわいもの　いじめに　なるもの$"

Route121_Text_JoyIntro: @ 0x0825F612
	.string "ユイ“ふたり　そろえば　こわいもの　なし！\n"
	.string "あたしたちの　つよさ　みせつけちゃうから！$"

Route121_Text_JoyDefeat: @ 0x0825F63E
	.string "ユイ“センパイ　ごめんなさーい$"

Route121_Text_JoyPostBattle: @ 0x0825F64E
	.string "ユイ“えへっ！\n"
	.string "また　センパイと　いっしょに　とっくんね！$"

Route121_Text_JoyNotEnoughMons: @ 0x0825F66C
	.string "ユイ“あたしたちに　しょうぶを　いどむなら\n"
	.string "ポケモン　2ひきは　ひつよう　だからね！$"

Route121_Text_JessicaIntro: @ 0x0825F697
	.string "あたくしの　だいじな　ポケモン\n"
	.string "ちょっと　みなさいよ！$"

Route121_Text_JessicaDefeat: @ 0x0825F6B3
	.string "ぷんぷん！\n"
	.string "なによ　ほんき　だしちゃって！$"

Route121_Text_JessicaPostBattle: @ 0x0825F6C9
	.string "サファリで　あたらしい　ポケモン\n"
	.string "つかまえようかな？$"

Route121_Text_JessicaRegister: @ 0x0825F6E4
	.string "きょうは　てかげん　してあげたのよ\n"
	.string "つぎは　こうは　いかないからね！$"

Route121_Text_JessicaRematchIntro: @ 0x0825F707
	.string "だいじな　ポケモン　そだったのよ！\n"
	.string "ちょっと　みていきなさいよ！$"

Route121_Text_JessicaRematchDefeat: @ 0x0825F728
	.string "ぷんぷん！\n"
	.string "また　てかげん　してくれないのね！$"

Route121_Text_JessicaPostRematch: @ 0x0825F740
	.string "サファリで　あたらしい　ポケモン\n"
	.string "つかまえようかな？$"

Route121_Text_CristinIntro: @ 0x0825F75B
	.string "1にちに　5にんずつ\n"
	.string "たおす　ことが　にっかよ！\l"
	.string "あなたが　その　5にんめ！$"

Route121_Text_CristinDefeat: @ 0x0825F782
	.string "いやっ　ひどいわ！$"

Route121_Text_CristinPostBattle: @ 0x0825F78C
	.string "こんなに　あっさり　まけるなんて⋯⋯\n"
	.string "つぎは　わたしが　かつから！$"

Route121_Text_CristinRegister: @ 0x0825F7AE
	.string "くつじょく　てき　だわ！\n"
	.string "あなたの　こと　わすれないんだから⋯⋯\l"
	.string "ポケナビを　かしなさい！$"

Route121_Text_CristinRematchIntro: @ 0x0825F7DC
	.string "1にちに　10にんずつ\n"
	.string "たおす　ことが　にっかよ！\l"
	.string "あなたが　その　10にんめ！$"

Route121_Text_CristinRematchDefeat: @ 0x0825F805
	.string "ちょっ⋯⋯\n"
	.string "ひどい　やりなおしてよ！$"

Route121_Text_CristinPostRematch: @ 0x0825F818
	.string "こんなに　かてない　あいてが　いるなんて⋯⋯\n"
	.string "グスっ　しんじられない$"

Route121_Text_CaleIntro: @ 0x0825F83B
	.string "いま　にもつが　いっぱい　なんですけど！\n"
	.string "こんな　じょうたいで　たたかえと？$"

Route121_Text_CaleDefeat: @ 0x0825F862
	.string "そりゃ　まけますよ\n"
	.string "りょうてが　ふさがってるんだもん$"

Route121_Text_CalePostBattle: @ 0x0825F87D
	.string "この　さきの　ミナモデパートで\n"
	.string "かいもの　しすぎたんだ！\l"
	.string "きみの　みたいな　バッグが　ほしいな$"

Route121_Text_MylesIntro: @ 0x0825F8AD
	.string "みんなの　そだてた　ポケモンが\n"
	.string "みてみたーーい！$"

Route121_Text_MylesDefeat: @ 0x0825F8C6
	.string "すごーーい！$"

Route121_Text_MylesPostBattle: @ 0x0825F8CD
	.string "いいなーー！　きみの　ポケモン！\n"
	.string "どうやって　そだてているの？$"

Route121_Text_PatIntro: @ 0x0825F8ED
	.string "わたしの　そだてた　ポケモンたち\n"
	.string "みんなに　みてほしいの！$"

Route121_Text_PatDefeat: @ 0x0825F90B
	.string "すごいなァ！$"

Route121_Text_PatPostBattle: @ 0x0825F912
	.string "どんな　ポケモンでも　おなじように\n"
	.string "かわいがって　そだてているの！$"

Route121_Text_MarcelIntro: @ 0x0825F934
	.string "わたしの　ポケモンは　まけしらず！\n"
	.string "こんど　かったら　つぎは　コンテストだ！$"

Route121_Text_MarcelDefeat: @ 0x0825F95B
	.string "あっと　どうしたことだ？$"

Route121_Text_MarcelPostBattle: @ 0x0825F968
	.string "コンテストの　まえに\n"
	.string "もうすこし　きたえないと　ダメかな$"
Route123_Text_WendyIntro: @ 0x0825F985
	.string "あなたの　じつりょくが\n"
	.string "どれほどの　ものか⋯⋯\l"
	.string "わたしが　たしかめて　あげる！$"

Route123_Text_WendyDefeat: @ 0x0825F9AD
	.string "すばらしいわ⋯⋯！$"

Route123_Text_WendyPostBattle: @ 0x0825F9B7
	.string "わたしに　かつなんて⋯⋯\n"
	.string "あなたの　じつりょくも　そうとうな　もの！$"

Route123_Text_BraxtonIntro: @ 0x0825F9DA
	.string "たくさん　ジムの　バッジを\n"
	.string "もっている　みたいだね！\p"
	.string "ほんとうに　それだけの　ちからが　あるか\n"
	.string "たしかめさせて　もらうよ！$"

Route123_Text_BraxtonDefeat: @ 0x0825FA18
	.string "たしかに　ちからは　ある！$"

Route123_Text_BraxtonPostBattle: @ 0x0825FA26
	.string "ジムバッジに　はじない\n"
	.string "たたかい　だったよ！$"

Route123_Text_VioletIntro: @ 0x0825FA3D
	.string "たのしい　ことが　あるとき　って\n"
	.string "いい　においで　いっぱいに　なってるのね$"

Route123_Text_VioletDefeat: @ 0x0825FA63
	.string "あぁ\n"
	.string "かなしみの　におい　だわ⋯⋯$"

Route123_Text_VioletPostBattle: @ 0x0825FA75
	.string "きのみ　めいじんの　はなばたけ\n"
	.string "すっごく　いいかんじの　においで　いっぱい！$"

Route123_Text_CameronIntro: @ 0x0825FA9C
	.string "サイキックとは　きもちの　つよさ⋯⋯\p"
	.string "そう　ぼくは　だれにも　まけないと\n"
	.string "おもっているから　つよいよ！$"

Route123_Text_CameronDefeat: @ 0x0825FAD0
	.string "しょんぼり⋯⋯$"

Route123_Text_CameronPostBattle: @ 0x0825FAD8
	.string "サイキックとは　きもちの　つよさ\n"
	.string "きみには　まけないと　おもっていたのに⋯⋯$"

Route123_Text_CameronRegister: @ 0x0825FAFF
	.string "ぼくには　わかる！\n"
	.string "ぼくと　きみとは　また　しょうぶする！\l"
	.string "かてるか　わかんない　けど⋯⋯\p"
	.string "ポケナビを　だして！$"

Route123_Text_CameronRematchIntro: @ 0x0825FB38
	.string "ぼくは　もう　だれにも　まけないと\n"
	.string "おもっているから　つよいよ！！$"

Route123_Text_CameronRematchDefeat: @ 0x0825FB5A
	.string "しょんぼり⋯⋯$"

Route123_Text_CameronPostRematch: @ 0x0825FB62
	.string "おくりびやまで　しゅぎょうでも　しようかな\n"
	.string "このままじゃ　ずっと　きみに　かてないよ$"

Route123_Text_JackiIntro: @ 0x0825FB8D
	.string "ポケモンも　ちょうのうりょくも\n"
	.string "つかえるだけじゃ　いみ　ないわ\l"
	.string "きたえてこそ　ほんものに　なるのよ$"

Route123_Text_JackiDefeat: @ 0x0825FBBF
	.string "すごい！$"

Route123_Text_JackiPostBattle: @ 0x0825FBC4
	.string "だれでも　ちょうのうりょくを　もっているの\n"
	.string "ただ　つかいかたを　わすれている　だけよ$"

Route123_Text_JackiRegister: @ 0x0825FBEF
	.string "もういちど　しょうぶして　みたいわ！\n"
	.string "いいでしょう？$"

Route123_Text_JackiRematchIntro: @ 0x0825FC0A
	.string "どう？　あなたの　なかの\n"
	.string "ちょうのうりょく　めばえたり　した？$"

Route123_Text_JackiRematchDefeat: @ 0x0825FC2A
	.string "すごいわ！$"

Route123_Text_JackiPostRematch: @ 0x0825FC30
	.string "あなたの　つよさ\n"
	.string "それも　ちょうのうりょく　かもね$"

Route123_Text_MiuIntro: @ 0x0825FC4A
	.string "ミウ“トレーナーさんの　ポケモン\n"
	.string "まけても　なかないで　くださいね！$"

Route123_Text_MiuDefeat: @ 0x0825FC6D
	.string "ミウ“まけちゃったね⋯⋯$"

Route123_Text_MiuPostBattle: @ 0x0825FC7A
	.string "ミウ“トレーナーさんの　ポケモン\n"
	.string "なかが　いいから　つよいんですね！$"

Route123_Text_MiuNotEnoughMons: @ 0x0825FC9D
	.string "ミウ“ポケモンさん　2ひきは　いないと\n"
	.string "たたかっても　つまらないもん！$"

Route123_Text_YukiIntro: @ 0x0825FCC1
	.string "ユキ“よーし！\n"
	.string "トレーナーさんの　ポケモン　やっつけます！$"

Route123_Text_YukiDefeat: @ 0x0825FCDF
	.string "ユキ“まけちゃったね⋯⋯$"

Route123_Text_YukiPostBattle: @ 0x0825FCEC
	.string "ユキ“どーして　そんなに　つよいの？\n"
	.string "あたちたち　たたかって　まけたの　はじめて！$"

Route123_Text_YukiNotEnoughMons: @ 0x0825FD16
	.string "ユキ“ポケモンさん　2ひきは　いないと\n"
	.string "たたかっても　つまらないもん！$"

Route123_Text_KindraIntro: @ 0x0825FD3A
	.string "おくりびやまは⋯⋯\n"
	.string "ポケモンの　たましいが　ねむるところ⋯⋯\l"
	.string "あなたの　ポケモンも　ねむる⋯⋯？$"

Route123_Text_KindraDefeat: @ 0x0825FD6B
	.string "げんき　いっぱいね⋯⋯$"

Route123_Text_KindraPostBattle: @ 0x0825FD77
	.string "おくりびやまは⋯⋯\n"
	.string "ポケモンの　たましいが　ねむるところ⋯⋯\p"
	.string "きっと　たましいを　なぐさめる\n"
	.string "ちからに　あふれてるのよ⋯⋯$"

Route123_Text_FernandoIntro: @ 0x0825FDB5
	.string "いっきょく　かなでる　あいだに\n"
	.string "パッと　たおしちゃうゼ！$"

Route123_Text_FernandoDefeat: @ 0x0825FDD2
	.string "おいおい　まだ　イントロだゼ！$"

Route123_Text_FernandoPostBattle: @ 0x0825FDE2
	.string "きみ　やるじゃん\n"
	.string "きみの　きょくを　つくって　みたいよ$"

Route123_Text_FernandoRegister: @ 0x0825FDFE
	.string "こんど　あった　ときには\n"
	.string "フルコーラス　きいて　くれヨ！$"

Route123_Text_FernandoRematchIntro: @ 0x0825FE1B
	.string "よし　きょうこそ！\n"
	.string "1ばんを　うたっている　あいだに\l"
	.string "サッと　たおしちゃうゼ！$"

Route123_Text_FernandoRematchDefeat: @ 0x0825FE43
	.string "おいおい　まだ　サビまで　いってないゼ！$"

Route123_Text_FernandoPostRematch: @ 0x0825FE58
	.string "オレの　うたに　ききほれて\n"
	.string "まけちゃう　って　おもってたんだけど$"

Route123_Text_DavisIntro: @ 0x0825FE79
	.string "ぼくの　おにいちゃんに　とってもらった\n"
	.string "じまんの　むしポケモンだよ！$"

Route123_Text_DavisDefeat: @ 0x0825FE9C
	.string "わーん　バカーっ！$"

Route123_Text_DavisPostBattle: @ 0x0825FEA6
	.string "まけちゃった　こと\n"
	.string "ぼくの　おにいちゃんには　ひみつ　だよ！$"

Route123_Text_JazmynIntro: @ 0x0825FEC5
	.string "みるからに　つよそうな　あなたを\n"
	.string "たおせば　じしんが　つくわね！$"

Route123_Text_JazmynDefeat: @ 0x0825FEE6
	.string "じしん　なくしました⋯⋯$"

Route123_Text_JazmynPostBattle: @ 0x0825FEF3
	.string "ヒトは　みためには　よらないと　いうけど\n"
	.string "けっこう　みためどおりの　ことも　あるわね$"

Route123_Text_FrederickIntro: @ 0x0825FF1E
	.string "おい　きみきみ\n"
	.string "じいちゃんと　ちょっと　あそぼうか$"

Route123_Text_FrederickDefeat: @ 0x0825FF38
	.string "つよいこ　じゃな\n"
	.string "こづかいを　やるか$"

Route123_Text_FrederickPostBattle: @ 0x0825FF4B
	.string "え　こづかい？\n"
	.string "しょうきんを　もらったから　いいじゃろ！$"

Route123_Text_AlbertoIntro: @ 0x0825FF68
	.string "オレ　マジ　とりポケモンが　すき！\n"
	.string "とりイカス！　とりサイコー！$"

Route123_Text_AlbertoDefeat: @ 0x0825FF89
	.string "まけた　とりポケモンも　イカス！$"

Route123_Text_AlbertoPostBattle: @ 0x0825FF9A
	.string "しょうぶの　あいだに　ちらばった\n"
	.string "とりポケモンの　ハネを　あつめて\l"
	.string "ぼうしを　つくる　つもりなんだ！$"

Route123_Text_EdIntro: @ 0x0825FFCD
	.string "トレーナーが　いない　ときは\n"
	.string "じぶんの　ポケモンどうしを\l"
	.string "たたかわせて　ながめて　いるぞぅ$"

Route123_Text_EdDefeat: @ 0x0825FFFB
	.string "きみの　ポケモンも　いいねぃ$"

Route123_Text_EdPostBattle: @ 0x0826000A
	.string "へへへ　きみの　たたかいかたの\n"
	.string "アイディア　いただき！\l"
	.string "つよく　なれそう　だよぅ$"

Route123_Text_JonasIntro: @ 0x08260033
	.string "まちぶせ　していたら\n"
	.string "トレーナーが　かかったで　ござる！$"

Route123_Text_JonasDefeat: @ 0x08260050
	.string "まけて　くれなきゃ\n"
	.string "ニンジャごっこ　できないよ$"

Route123_Text_JonasPostBattle: @ 0x08260068
	.string "つぎは　もっと　よわそうな　トレーナーを\n"
	.string "まちぶせ　してみるで　ござるよ$"

Route123_Text_KayleyIntro: @ 0x0826008D
	.string "かった　ばかりの　パラソルで\n"
	.string "わたしも　3わりましで　かわいい　はず！$"

Route123_Text_KayleyDefeat: @ 0x082600B1
	.string "わたしの　5ばい　くらい　つよいわね$"

Route123_Text_KayleyPostBattle: @ 0x082600C4
	.string "こもの　づかいも　おしゃれの　ひけつよ！$"
Route124_Text_SpencerIntro: @ 0x082600D9
	.string "おっと　みちに　まよったのか？\p"
	.string "わたしの　ポケモンに　かてたら\n"
	.string "みずさき　あんないにんに　なってあげようか？$"

Route124_Text_SpencerDefeat: @ 0x08260110
	.string "たたかいかたを　まよってしまった⋯⋯$"

Route124_Text_SpencerPostBattle: @ 0x08260123
	.string "うみで　まよってしまう　ひとは　おおい！\p"
	.string "そんな　ひとは　ポケナビで\n"
	.string "マップを　たしかめながら　すすむと　いい！$"

Route124_Text_RolandIntro: @ 0x0826015C
	.string "むっ！　じぶんで　およがずに\n"
	.string "ポケモンに　のっている⋯⋯\p"
	.string "なんて　うらやましいんだ！$"

Route124_Text_RolandDefeat: @ 0x08260187
	.string "ああ！\n"
	.string "ダメだ⋯⋯！$"

Route124_Text_RolandPostBattle: @ 0x08260192
	.string "からだが　ひえてきた⋯⋯\n"
	.string "ながいこと　みずの　なかに　いるからだ\p"
	.string "きみのように　ポケモンに　のりたいよ$"

Route124_Text_JennyIntro: @ 0x082601C6
	.string "こうして　うみに　うかんでいると\n"
	.string "ポケモンたちが　あそびに　くるのよ！$"

Route124_Text_JennyDefeat: @ 0x082601EA
	.string "あーあ\n"
	.string "まけちゃった⋯⋯$"

Route124_Text_JennyPostBattle: @ 0x082601F7
	.string "うみを　およいでいると\n"
	.string "おそってくる　ポケモンと\l"
	.string "ただ　みているだけの　ポケモンが　いるの\p"
	.string "ポケモンにも　こせいが　あるのね！$"

Route124_Text_JennyRegister: @ 0x08260237
	.string "なんとなく　だけど\n"
	.string "ポケナビ　とうろく　してもらおうかな⋯⋯$"

Route124_Text_JennyRematchIntro: @ 0x08260256
	.string "こうして　うみに　うかんでいると\n"
	.string "トレーナーが　いどんで　くるのよね！$"

Route124_Text_JennyRematchDefeat: @ 0x0826027A
	.string "おかしいなあ\n"
	.string "また　まけちゃった⋯⋯$"

Route124_Text_JennyPostRematch: @ 0x0826028D
	.string "なんとなく　だけど\n"
	.string "カラクリやしきに　いってみようかな⋯⋯$"

Route124_Text_GraceIntro: @ 0x082602AB
	.string "およぐのにも　あきた　ところだし⋯⋯\n"
	.string "わたしと　しょうぶ　しようよ！$"

Route124_Text_GraceDefeat: @ 0x082602CE
	.string "こんなに　つよいなんて\n"
	.string "おもいも　しなかったわ！$"

Route124_Text_GracePostBattle: @ 0x082602E7
	.string "ずっと　がんばって　きたことが\n"
	.string "あなたの　つよさなのね⋯⋯！$"

Route124_Text_ChadIntro: @ 0x08260306
	.string "うふふふふ\n"
	.string "オレは　モグリの　スイマー\l"
	.string "もぐりは　とくいちゅうの　とくいだぜ！$"

Route124_Text_ChadDefeat: @ 0x0826032E
	.string "ゴボゴボゴボ⋯⋯\n"
	.string "しずんでいく⋯⋯$"

Route124_Text_ChadPostBattle: @ 0x08260340
	.string "うみの　そこに　もぐれる　ポイントが\n"
	.string "この　あたりには　あるらしいぜ！\l"
	.string "モグリの　ちが　さわぐなあ⋯⋯$"

Route124_Text_LilaIntro: @ 0x08260374
	.string "カコ“はーあ\p"
	.string "せっかくの　うみ　なのに\n"
	.string "いっしょに　いるのが　おとうと　なんて⋯⋯\p"
	.string "あなた　きばらしに　ポケモン　しようか！？$"

Route124_Text_LilaDefeat: @ 0x082603B4
	.string "カコ“コウの　せいで　まけたのよ！\n"
	.string "あとで　おしおき　だかんね！！$"

Route124_Text_LilaPostBattle: @ 0x082603D6
	.string "カコ“はーあ\p"
	.string "となりに　いるのが　おとうと　じゃなくて\n"
	.string "すてきな　かれし　だったら　いいのに⋯⋯$"

Route124_Text_LilaNotEnoughMons: @ 0x08260407
	.string "カコ“あたしたちと　たたかう　つもり？\n"
	.string "ポケモン　2ひき　いないと　ダメよ$"

Route124_Text_RoyIntro: @ 0x0826042D
	.string "コウ“オレの　ねえちゃん\n"
	.string "ポケモン　つよいぞ！\l"
	.string "まけて　ないたり　するなよ！$"

Route124_Text_RoyDefeat: @ 0x08260454
	.string "コウ“うわぁ⋯⋯\n"
	.string "あとで　ねえちゃんに　おこられる⋯⋯$"

Route124_Text_RoyPostBattle: @ 0x08260470
	.string "コウ“オレの　ねえちゃん\n"
	.string "おこると　むちゃくちゃ　こわいんだ⋯⋯\p"
	.string "だから　こいびと　いないんだぜ⋯⋯$"

Route124_Text_LilaRoyRegister: @ 0x082604A3
	.string "コウ“また　こんど　しょうぶしてよ\n"
	.string "⋯⋯そのときは　てかげんして　くれよ！$"

Route124_Text_RoyNotEnoughMons: @ 0x082604C9
	.string "コウ“オレらと　たたかう　つもり？\n"
	.string "ポケモン　2ひき　つれてきなよ！$"

Route124_Text_LilaRematchIntro: @ 0x082604EC
	.string "カコ“はーあ\p"
	.string "せっかくの　うみ　なのに\n"
	.string "いっしょに　いるのが　おとうと　なんて⋯⋯\p"
	.string "あら　あなた　ひさしぶりね\n"
	.string "きばらしに　ポケモン　しようか！？$"

Route124_Text_LilaRematchDefeat: @ 0x08260536
	.string "カコ“コウったら！\n"
	.string "あんたの　せいで　また　まけたでしょ！\l"
	.string "あとで　とっくん　だかんね！！$"

Route124_Text_LilaPostRematch: @ 0x08260564
	.string "カコ“はーあ\p"
	.string "あたしに　すてきな　かれしが　いたらなぁ\n"
	.string "すてきな　コンビネーションで\l"
	.string "どんな　あいてにでも　かっちゃうのに$"

Route124_Text_LilaRematchNotEnoughMons: @ 0x082605A2
	.string "カコ“あたしたちと　たたかう　つもり？\n"
	.string "ポケモン　2ひき　いないと　ダメよ$"

Route124_Text_RoyRematchIntro: @ 0x082605C8
	.string "コウ“まけたら　オレが　おこられるから\n"
	.string "むちゃくちゃ　ほんきで　がんばるぞ！$"

Route124_Text_RoyRematchDefeat: @ 0x082605EF
	.string "コウ“うわぁ⋯⋯\n"
	.string "また　ねえちゃんに　おこられる⋯⋯$"

Route124_Text_RoyPostRematch: @ 0x0826060A
	.string "コウ“オレの　ねえちゃん\n"
	.string "おこると　むちゃくちゃ　こわいんだ⋯⋯\p"
	.string "あとで　オレと　ポケモン\n"
	.string "もうとっくん　だよ⋯⋯$"

Route124_Text_RoyRematchNotEnoughMons: @ 0x08260644
	.string "コウ“オレらと　たたかう　つもり？\n"
	.string "ポケモン　2ひき　つれてきなよ！$"

Route124_Text_DeclanIntro: @ 0x08260667
	.string "こんな　きれいな　うみで\n"
	.string "ひとりで　およいでいる　オレ！\l"
	.string "はっきりいって　かなしすぎます！$"

Route124_Text_DeclanDefeat: @ 0x08260695
	.string "かなしい\n"
	.string "そらの　あおさが　かなしい$"

Route124_Text_DeclanPostBattle: @ 0x082606A8
	.string "ビキニのおねえさんを　さそって\n"
	.string "えんえいと　しゃれこんで　みようかな？$"

Route124_Text_IsabellaIntro: @ 0x082606CC
	.string "なみのりトレーナー　なんかに　まけないわ！$"

Route124_Text_IsabellaDefeat: @ 0x082606E2
	.string "ううっ　ポタポタ\n"
	.string "こ　これは　すいてきよ！　ないてないわよ！$"

Route124_Text_IsabellaPostBattle: @ 0x08260701
	.string "きれいな　いろの　カケラが\n"
	.string "この　あたりで　みつかることが　あるわよ$"
Route125_Text_NolenIntro: @ 0x08260724
	.string "キミが　やってくる　おとが\n"
	.string "きこえて　いたから　まってたよ！$"

Route125_Text_NolenDefeat: @ 0x08260743
	.string "まいりました⋯⋯！$"

Route125_Text_NolenPostBattle: @ 0x0826074D
	.string "くうきちゅう　よりも\n"
	.string "すいちゅうの　ほうが　おとの　つたわる\l"
	.string "スピードが　はやいんだよ！$"

Route125_Text_StanIntro: @ 0x0826077A
	.string "おらーっ！！\n"
	.string "おれの　かわいい　ポケモンだー！！$"

Route125_Text_StanDefeat: @ 0x08260793
	.string "まいったぜ⋯⋯！$"

Route125_Text_StanPostBattle: @ 0x0826079C
	.string "タッツーの　みりょくに　まいって\n"
	.string "おれも　およぐように　なったんだー！$"

Route125_Text_TanyaIntro: @ 0x082607C0
	.string "およぎ　つかれちゃった！\n"
	.string "わたしと　ひとしょうぶ　どう？$"

Route125_Text_TanyaDefeat: @ 0x082607DD
	.string "あんた　つよすぎ！$"

Route125_Text_TanyaPostBattle: @ 0x082607E7
	.string "ふう　ふう⋯⋯\n"
	.string "トクサネシティは　どっち　だったっけ？$"

Route125_Text_SharonIntro: @ 0x08260803
	.string "わたしの　そだてた　みずポケモンと\n"
	.string "たたかって　みない？$"

Route125_Text_SharonDefeat: @ 0x08260820
	.string "まけた⋯⋯$"

Route125_Text_SharonPostBattle: @ 0x08260826
	.string "あなたの　つよさは　ホンモノね！\n"
	.string "おどろいたわ！$"

Route125_Text_ErnestIntro: @ 0x0826083F
	.string "オレさまは　たくましい　ふなのり！\n"
	.string "せかいの　うみを　わたりあるく　おとこ！$"

Route125_Text_ErnestDefeat: @ 0x08260866
	.string "ぐおおおーっ！\n"
	.string "かてねえ⋯⋯！$"

Route125_Text_ErnestPostBattle: @ 0x08260876
	.string "あさせのほらあな　は　じかんによって\n"
	.string "しおが　みちたり　ひいたり　するんだ！\p"
	.string "ちなみに　みちしお　から　ひきしお　まで\n"
	.string "およそ　6じかんだぞ！　しっていたか？$"

Route125_Text_ErnestRegister: @ 0x082608C6
	.string "ポケナビ　とうろく　して　くれたら\n"
	.string "いいことを　おしえて　やるよ！$"

Route125_Text_ErnestRematchIntro: @ 0x082608E8
	.string "おっと　ここで　あったが　100ねんめ！\n"
	.string "とにかく　ポケモンしょうぶ　だっ！$"

Route125_Text_ErnestRematchDefeat: @ 0x0826090F
	.string "かてねえ\n"
	.string "ちっとも　かてねえよ！$"

Route125_Text_ErnestRematchPostBattle: @ 0x08260920
	.string "あさせのほらあな⋯⋯\p"
	.string "しおの　みちひきに　よって\n"
	.string "いけたり　いけなかったり　する\l"
	.string "ばしょが　あるんだよな\p"
	.string "ちなみに　みちしお　から　ひきしお　まで\n"
	.string "およそ　6じかんだぞ！　おぼえておけよ！$"

Route125_Text_KimIntro: @ 0x0826097F
	.string "マホ“あさせのほらあなに\n"
	.string "へんな　じいさんが　いるんだって！\l"
	.string "あなたも　あいにいく　とちゅう？$"

Route125_Text_KimDefeat: @ 0x082609AF
	.string "マホ“かてると　おもったのに$"

Route125_Text_KimPostBattle: @ 0x082609BE
	.string "マホ“あさせのほらあなに\n"
	.string "へんな　じいさんが　いるんでしょ？\p"
	.string "さっ　ナホちゃん　あいに　いくよ！$"

Route125_Text_KimNotEnoughMons: @ 0x082609EF
	.string "マホ“ダメだって！\n"
	.string "ポケモン　2ひき　いないと　ダメだって！$"

Route125_Text_IrisIntro: @ 0x08260A0E
	.string "ナホ“センパイ\n"
	.string "こんな　ところに　なにが　あるんですかぁ？$"

Route125_Text_IrisDefeat: @ 0x08260A2C
	.string "ナホ“とちゅう　おしいところ　あったのに$"

Route125_Text_IrisPostBattle: @ 0x08260A41
	.string "ナホ“センパイ⋯⋯　ほんとに\n"
	.string "あさせのほらあなに　はいりますぅ？\l"
	.string "ぬれちゃいますよぉ？$"

Route125_Text_IrisNotEnoughMons: @ 0x08260A6D
	.string "ナホ“2たい1で　しょうぶ　なんて\n"
	.string "そんな　まね　あたしたちに　できないわ$"

Route125_Text_PresleyIntro: @ 0x08260A93
	.string "とりつかいの　ボクが\n"
	.string "なぜ　うみにまで　きているかと　いうと⋯⋯$"

Route125_Text_PresleyDefeat: @ 0x08260AB4
	.string "わかった\n"
	.string "なんで　ここに　いるか　おしえてやるよ$"

Route125_Text_PresleyPostBattle: @ 0x08260ACD
	.string "あきビンに　メールを　いれて\n"
	.string "さっき　うみに　ながしたんだ！\p"
	.string "きっと　かわいい　ビキニの　おんなのコが\n"
	.string "ひろって　くれるぜ！$"

Route125_Text_AuronIntro: @ 0x08260B0C
	.string "こらーッ！　おぬしかッ\n"
	.string "うみに　ゴミを　すてたのは！$"

Route125_Text_AuronDefeat: @ 0x08260B27
	.string "おぬしでは　なかったか$"

Route125_Text_AuronPostBattle: @ 0x08260B33
	.string "さっき　この　あたりで\n"
	.string "こきたない　ビンを　ひろったんじゃ！\l"
	.string "うみに　ゴミを　すてるとは　なっとらん！$"
Route126_Text_BarryIntro: @ 0x08260B67
	.string "すいえいは　ぜんしん　うんどう！\n"
	.string "たいりょくが　つくぞー！$"

Route126_Text_BarryDefeat: @ 0x08260B85
	.string "まけましたーっ！$"

Route126_Text_BarryPostBattle: @ 0x08260B8E
	.string "まいにち　およいでる　おかげで\n"
	.string "みよ！　この　きんにくっ！！$"

Route126_Text_DeanIntro: @ 0x08260BAD
	.string "この　しろく　そびえる　いわやまが\n"
	.string "ルネシティ　なんだぜー！$"

Route126_Text_DeanDefeat: @ 0x08260BCC
	.string "やられたか！？$"

Route126_Text_DeanPostBattle: @ 0x08260BD4
	.string "ルネシティの　いりぐちが　みつからん！\n"
	.string "どこに　あるんだ？$"

Route126_Text_NikkiIntro: @ 0x08260BF2
	.string "おほほほっ\n"
	.string "わたしは　にんぎょ！$"

Route126_Text_NikkiDefeat: @ 0x08260C03
	.string "アワと　なって　きえていく⋯⋯\n"
	.string "ぶくぶくぶく⋯⋯$"

Route126_Text_NikkiPostBattle: @ 0x08260C1C
	.string "こっぴどく　やられちゃったわ⋯⋯\n"
	.string "アワくって　にげだしたい　きぶん⋯⋯$"

Route126_Text_BrendaIntro: @ 0x08260C40
	.string "ねえ　ねえ\n"
	.string "おねえさんと　しょうぶ　しない？$"

Route126_Text_BrendaDefeat: @ 0x08260C57
	.string "いやーんっ！$"

Route126_Text_BrendaPostBattle: @ 0x08260C5E
	.string "こうして　ポケモンと\n"
	.string "うみで　あそぶのが　だいすきなの！$"

Route126_Text_PabloIntro: @ 0x08260C7B
	.string "からておう　より　たくましい\n"
	.string "この　にくたいびを　みよ！$"

Route126_Text_PabloDefeat: @ 0x08260C98
	.string "おわっ　つよいな\n"
	.string "いいね！　いいね！$"

Route126_Text_PabloPostBattle: @ 0x08260CAB
	.string "まけて　いい　しげきに　なったよ！\n"
	.string "からだも　ポケモンも　もっと　きたえるぜ$"

Route126_Text_PabloRegister: @ 0x08260CD2
	.string "いやー　いいね！\n"
	.string "ぜひとも　おちかづきに　なっておきたいね！$"

Route126_Text_PabloRematchIntro: @ 0x08260CF1
	.string "ビキニのおねえさん　より　うつくしい\n"
	.string "この　にくたいびを　みよ！$"

Route126_Text_PabloRematchDefeat: @ 0x08260D12
	.string "おわっ　ほんと　つよいな\n"
	.string "いいね！　いいね！$"

Route126_Text_PabloPostRematch: @ 0x08260D29
	.string "よし　もっともっと　きたえるぜ！\n"
	.string "きみは　いい　しげきに　なるから\l"
	.string "また　きてくれよ！$"

Route126_Text_LeonardoIntro: @ 0x08260D55
	.string "きょねん　まで　およげなかった　オレも\n"
	.string "かいパンやろうに　なれたんだ\l"
	.string "いまなら　なんでも　できる　きがする！$"

Route126_Text_LeonardoDefeat: @ 0x08260D8C
	.string "てへっ　よくばりすぎちゃ　ダメだよな$"

Route126_Text_LeonardoPostBattle: @ 0x08260D9F
	.string "なんでも　れんしゅう　すれば\n"
	.string "うまく　なるんだ！\p"
	.string "キミも　わかい　うちから\n"
	.string "いろいろ　やっておけよ！$"

Route126_Text_IsobelIntro: @ 0x08260DD2
	.string "はなに　かいすいが　はいると\n"
	.string "すっごく　つらいよね？$"

Route126_Text_IsobelDefeat: @ 0x08260DED
	.string "ああっ！\n"
	.string "く　くやし⋯⋯ごほッ！$"

Route126_Text_IsobelPostBattle: @ 0x08260DFE
	.string "かいすいを　ちょっと　のんじゃった⋯⋯！\n"
	.string "からいーッ　にがいーッ！$"

Route126_Text_SiennaIntro: @ 0x08260E20
	.string "わたしの　ハートを　ぶつけるわ！$"

Route126_Text_SiennaDefeat: @ 0x08260E31
	.string "ハートで　まけたわ！$"

Route126_Text_SiennaPostBattle: @ 0x08260E3C
	.string "あつく　なっちゃった\n"
	.string "ちょっと　もぐって　こようかな$"
Route127_Text_CamdenIntro: @ 0x08260E57
	.string "オレと　しょうぶ　したいって\n"
	.string "かおに　かいてあるぜ！$"

Route127_Text_CamdenDefeat: @ 0x08260E72
	.string "あわわわわ⋯⋯$"

Route127_Text_CamdenPostBattle: @ 0x08260E7A
	.string "いい　しょうぶを　した　あとは\n"
	.string "すがすがしい　きもちに　なるなー$"

Route127_Text_DonnyIntro: @ 0x08260E9B
	.string "あいつには　まけたくない　って\n"
	.string "ライバル　きみには　いるの？$"

Route127_Text_DonnyDefeat: @ 0x08260EBA
	.string "あぁ　すっごく　くやしい！$"

Route127_Text_DonnyPostBattle: @ 0x08260EC8
	.string "ライバルが　いると\n"
	.string "つよくなりたい　って　きもちが\l"
	.string "どんどん　あふれて　くるよね$"

Route127_Text_JonahIntro: @ 0x08260EF1
	.string "つりを　することで　てにいれた\n"
	.string "おだやかな　こころ⋯⋯\l"
	.string "それを　みせて　あげましょう⋯⋯$"

Route127_Text_JonahDefeat: @ 0x08260F1E
	.string "⋯⋯　まけても\n"
	.string "こころは　おだやかです$"

Route127_Text_JonahPostBattle: @ 0x08260F32
	.string "つれなくても　かまいません\n"
	.string "ずっと　いとを　たらしているのです⋯⋯$"

Route127_Text_HenryIntro: @ 0x08260F54
	.string "おっと！？　なみのり　している\n"
	.string "ポケモンを　つりあげて　しまったか？$"

Route127_Text_HenryDefeat: @ 0x08260F77
	.string "かなわん！$"

Route127_Text_HenryPostBattle: @ 0x08260F7D
	.string "きみの　ポケモン　つよそうだから\n"
	.string "つりあげたら　かなりの　てごたえ　だろうな！$"

Route127_Text_RogerIntro: @ 0x08260FA5
	.string "よーし！\n"
	.string "ポケモンずきと　つりずきの　たいけつだ！$"

Route127_Text_RogerDefeat: @ 0x08260FBF
	.string "わあ！　いとが　からまった！\n"
	.string "まさに　あとの　まつり$"

Route127_Text_RogerPostBattle: @ 0x08260FDA
	.string "つりでは　いとが　からまることを\n"
	.string "マツリ　と　いうんだよ$"

Route127_Text_AidanIntro: @ 0x08260FF7
	.string "とりポケモンは　すごく　めが　いい！\n"
	.string "おおぞら　たかくから　えものを　みつけるぜ！$"

Route127_Text_AidanDefeat: @ 0x08261021
	.string "ふぅ⋯⋯　まいったぜ$"

Route127_Text_AidanPostBattle: @ 0x0826102C
	.string "この　ちかくには　いっぱい\n"
	.string "もぐれそうな　ところが　あるな！\p"
	.string "そらから　みてると\n"
	.string "うみの　いろが　ちがうから　よくわかる！$"

Route127_Text_KojiIntro: @ 0x0826106A
	.string "はだしで　かけまわると\n"
	.string "あしの　うらが　きたえられるぞ！$"

Route127_Text_KojiDefeat: @ 0x08261087
	.string "いってェ！\n"
	.string "ツメの　あいだに　こいしが⋯⋯$"

Route127_Text_KojiPostBattle: @ 0x0826109D
	.string "はだし　さいこう！\n"
	.string "だが　おまえの　その　ズックも　いいな！$"

Route127_Text_KojiRegister: @ 0x082610BC
	.string "おれに　かったり　するやつは　こうだーっ！\n"
	.string "また　よろしくおねがいします！$"

Route127_Text_KojiRematchIntro: @ 0x082610E2
	.string "きょうも　はだしで　かけまわって\n"
	.string "あしの　うらを　きたえまくりだ！$"

Route127_Text_KojiRematchDefeat: @ 0x08261104
	.string "いってェ！\n"
	.string "つちふまずに　ジャリが⋯⋯$"

Route127_Text_KojiPostRematch: @ 0x08261118
	.string "しばらく　おまえの　ズックと\n"
	.string "おれの　はだし　こうかん　してみないか？$"

Route127_Text_AthenaIntro: @ 0x0826113C
	.string "じっくり　ゆっくり　しょうぶしましょう\n"
	.string "よろしくね！$"

Route127_Text_AthenaDefeat: @ 0x08261157
	.string "せんりゃくを　ねる　ひまも　なかったわ$"

Route127_Text_AthenaPostBattle: @ 0x0826116B
	.string "あおい　いろに　かこまれていると\n"
	.string "じかんが　すぎるのが\l"
	.string "ゆっくりに　かんじられる　のよ$"
Route128_Text_IsaiahIntro: @ 0x08261197
	.string "サイユウシティは　まだ　とおい⋯⋯$"

Route128_Text_IsaiahDefeat: @ 0x082611A9
	.string "ボクの　はつしょうりも　とおい⋯⋯$"

Route128_Text_IsaiahPostBattle: @ 0x082611BB
	.string "まけつづけている　じんせい　ですが\n"
	.string "けっして　あきらめませんよ⋯⋯！$"

Route128_Text_IsaiahRegister: @ 0x082611DE
	.string "こんな　ボク　ですけど\n"
	.string "いつかは　かてると　おもうんです\l"
	.string "ポケナビの　とうろくを　してください⋯⋯！$"

Route128_Text_IsaiahRematchIntro: @ 0x08261211
	.string "まだまだ　げんき　ですからね\n"
	.string "サイユウシティ　めざして　およぎますよ！$"

Route128_Text_IsaiahRematchDefeat: @ 0x08261235
	.string "また　はつしょうり　ならず⋯⋯$"

Route128_Text_IsaiahPostRematch: @ 0x08261245
	.string "あきらめなきゃ　いつかは　かてる\n"
	.string "サイユウシティにも　たどりつく⋯⋯！$"

Route128_Text_KatelynIntro: @ 0x08261269
	.string "トライアスロンは\n"
	.string "すいえい　じてんしゃ　マラソン\p"
	.string "3つの　しゅもくを　つづけて　こなす\n"
	.string "かこくな　レースなの！$"

Route128_Text_KatelynDefeat: @ 0x082612A1
	.string "ポケモンしょうぶも　かこく　よね⋯⋯$"

Route128_Text_KatelynPostBattle: @ 0x082612B4
	.string "つぎは　じてんしゃ　だけど⋯⋯\n"
	.string "くじけそうだわ⋯⋯$"

Route128_Text_KatelynRegister: @ 0x082612CE
	.string "まあ　せっかく　だし\n"
	.string "またいつか　しょうぶを　しましょうよ！$"

Route128_Text_KatelynRematchIntro: @ 0x082612ED
	.string "トライアスロンも　ながいけど\n"
	.string "ポケモン　チャンピオンを　めざすのも\l"
	.string "ながい　みちのり　なのね！$"

Route128_Text_KatelynRematchDefeat: @ 0x0826131D
	.string "ほんとっ\n"
	.string "ポケモンしょうぶ　って　きびしい⋯⋯$"

Route128_Text_KatelynPostRematch: @ 0x08261335
	.string "そろそろ　チャンピオンロードに\n"
	.string "ちょうせん　してみるのも　あり　かな？$"

Route128_Text_AlexaIntro: @ 0x08261359
	.string "ポケモンリーグに　ちょうせん　するため\n"
	.string "いままで　がんばって　きた⋯⋯\p"
	.string "ここで　まけるわけには　いかないわ！$"

Route128_Text_AlexaDefeat: @ 0x08261390
	.string "ああっ！\n"
	.string "なんてこと$"

Route128_Text_AlexaPostBattle: @ 0x0826139B
	.string "ここまで　きたんですもの\n"
	.string "いちど　まけたからって　あきらめない$"

Route128_Text_RubenIntro: @ 0x082613BB
	.string "わたしの　ように　つよい\n"
	.string "ポケモントレーナーは　ほかに　いない！$"

Route128_Text_RubenDefeat: @ 0x082613DC
	.string "なんて　ことだ⋯⋯！$"

Route128_Text_RubenPostBattle: @ 0x082613E7
	.string "きみの　ように　つよい\n"
	.string "ポケモントレーナーは　ほかに　いないだろう！$"

Route128_Text_WayneIntro: @ 0x0826140A
	.string "サイユウに　いってみたいから\n"
	.string "たきのぼりを　おぼえた\l"
	.string "ポケモンを　つりあげたんだよ！$"

Route128_Text_WayneDefeat: @ 0x08261435
	.string "その　いきおい\n"
	.string "まさに　たきのぼり！$"

Route128_Text_WaynePostBattle: @ 0x08261448
	.string "しまった！\p"
	.string "たきのぼりを　おぼえた　ポケモン　つっても\n"
	.string "ルネの　ジムバッジ　もってない！$"

Route128_Text_HarrisonIntro: @ 0x08261475
	.string "きみが　また　つよそーだもんね！\n"
	.string "オレ　かてっかな？$"

Route128_Text_HarrisonDefeat: @ 0x08261490
	.string "あっひゃ\n"
	.string "やっぱ　かてんわな$"

Route128_Text_HarrisonPostBattle: @ 0x0826149F
	.string "サイユウシティの　まわりは\n"
	.string "つよそーな　トレーナーが　いっぱいだぜ！\l"
	.string "オレ　ばちがいじゃ　ないよな？$"

Route128_Text_CarleeIntro: @ 0x082614D2
	.string "この　へんは　ひざしが\n"
	.string "いちだんと　つよいわねえ！$"

Route128_Text_CarleeDefeat: @ 0x082614EC
	.string "まぶしくて　よく　みえなかったの！$"

Route128_Text_CarleePostBattle: @ 0x082614FE
	.string "そろそろ　もどって\n"
	.string "ひやけどめ　ぬりなおさなきゃ$"
Route129_Text_ChaseIntro: @ 0x08261517
	.string "オレは　しょしんしゃ　トライアスリート\n"
	.string "はじめての　レースで　きんちょう！$"

Route129_Text_ChaseDefeat: @ 0x0826153D
	.string "うおー！\n"
	.string "まけてしまったーっ！$"

Route129_Text_ChasePostBattle: @ 0x0826154D
	.string "きんちょう　していたら\n"
	.string "じつりょくが　だせないよな！$"

Route129_Text_AllisonIntro: @ 0x08261568
	.string "トライアスロンの　とちゅう　だけど⋯⋯\n"
	.string "ポケモンしょうぶを　しようよ！$"

Route129_Text_AllisonDefeat: @ 0x0826158C
	.string "かてると　おもったのにーっ！$"

Route129_Text_AllisonPostBattle: @ 0x0826159B
	.string "だいしぜんを　あいてに\n"
	.string "じぶんの　ちからを　ためす　ことも\l"
	.string "トライアスロンの　だいごみ！$"

Route129_Text_ReedIntro: @ 0x082615C8
	.string "ホラホラ！\n"
	.string "とっとと　しょうぶ　しようぜ！$"

Route129_Text_ReedDefeat: @ 0x082615DE
	.string "まけた　まけたよ\n"
	.string "とっとと　おわろうぜ！$"

Route129_Text_ReedPostBattle: @ 0x082615F3
	.string "まけたら　なにも　ないさ\n"
	.string "とっとと　かえると　するか！$"

Route129_Text_TishaIntro: @ 0x0826160F
	.string "のーんびり　のーんびり　やりましょうか？$"

Route129_Text_TishaDefeat: @ 0x08261624
	.string "あらら\n"
	.string "もっと　のんびり　したかったなあ$"

Route129_Text_TishaPostBattle: @ 0x08261639
	.string "あせって　ミスを　するのって　イヤでしょ？\n"
	.string "のんびり　やることに　してるのよ$"

Route129_Text_ClarenceIntro: @ 0x08261660
	.string "なみのりも　けっこう　たいへんだろ？$"

Route129_Text_ClarenceDefeat: @ 0x08261673
	.string "かつのって　むずかしいなあ$"

Route129_Text_ClarencePostBattle: @ 0x08261681
	.string "ポケモンリーグを　めざしてるのか？\n"
	.string "がんばれ　がんばれよ！$"
Route130_Text_RodneyIntro: @ 0x0826169F
	.string "うみの　ドまんなかで\n"
	.string "トレーナーに　であうとは　めずらしいな\l"
	.string "イッパツ　しょうぶ　するか！？$"

Route130_Text_RodneyDefeat: @ 0x082616CE
	.string "なんて　つよい　こどもだ⋯⋯$"

Route130_Text_RodneyPostBattle: @ 0x082616DD
	.string "きびしい　たたかいを　くぐりぬけてきた\n"
	.string "いい　めを　しているぜ！$"

Route130_Text_KatieIntro: @ 0x082616FE
	.string "あおい　うみ\n"
	.string "ブルーな　こころ\l"
	.string "いやされる⋯⋯$"

Route130_Text_KatieDefeat: @ 0x08261716
	.string "うみ　ひろく\n"
	.string "ポケモン　せかい\l"
	.string "また　ひろし⋯⋯$"

Route130_Text_KatiePostBattle: @ 0x0826172F
	.string "こどもたち\n"
	.string "ポケモン　チャンプ\l"
	.string "めざしてる⋯⋯$"

Route130_Text_SantiagoIntro: @ 0x08261747
	.string "なにも　ない　うみに　うかんでると⋯⋯\n"
	.string "へいわだなあー⋯⋯$"

Route130_Text_SantiagoDefeat: @ 0x08261765
	.string "へいわボケ　してて　まけました！$"

Route130_Text_SantiagoPostBattle: @ 0x08261776
	.string "こうして　およいだり　しょうぶしたり⋯⋯\n"
	.string "オレ　しあわせだなあー⋯⋯$"
Route131_Text_RichardIntro: @ 0x08261799
	.string "うみには　ポケモンが　たくさん　いるからね\n"
	.string "およいで　わたるのも　くろう　するよ！$"

Route131_Text_RichardDefeat: @ 0x082617C3
	.string "トレーナーの　そだてた　ポケモンは\n"
	.string "ホントに　つよいなぁ⋯⋯$"

Route131_Text_RichardPostBattle: @ 0x082617E2
	.string "ひいひい⋯⋯　つかれた⋯⋯\n"
	.string "いきは　よいよい　かえりは　こわい⋯⋯\l"
	.string "かえりの　たいりょく　のこってるかなあ⋯⋯$"

Route131_Text_HermanIntro: @ 0x0826181A
	.string "うみ　うみ　うみ⋯⋯\n"
	.string "みわたす　かぎり　うみ⋯⋯\l"
	.string "うみは　もう　あきたぞーっ！$"

Route131_Text_HermanDefeat: @ 0x08261842
	.string "ひょえええええっ！$"

Route131_Text_HermanPostBattle: @ 0x0826184C
	.string "うみに　あきても\n"
	.string "およぎ　つづけるしか　ないのか\p"
	.string "そんな　オレは\n"
	.string "ねっからの　スイマー⋯⋯$"

Route131_Text_SusieIntro: @ 0x0826187A
	.string "ちょっと　あんた\n"
	.string "わたしと　しょうぶ　しましょ！$"

Route131_Text_SusieDefeat: @ 0x08261893
	.string "みかけに　よらず\n"
	.string "つよいわねーっ！$"

Route131_Text_SusiePostBattle: @ 0x082618A5
	.string "あっちで　うみは　あきた　とか　いってる\n"
	.string "おとこが　いるでしょ？\p"
	.string "アレ　くちだけ　なのよ\n"
	.string "ホントは　うみが　すきで　しょうがないの！$"

Route131_Text_KaraIntro: @ 0x082618E8
	.string "なんで　オトコって\n"
	.string "ビキニが　すき　なのかしらね！\p"
	.string "みんな　わたしの　こと\n"
	.string "ジロジロ　みるのよ！$"

Route131_Text_KaraDefeat: @ 0x08261919
	.string "じつりょくが　ちがい　すぎるわ⋯⋯！$"

Route131_Text_KaraPostBattle: @ 0x0826192C
	.string "みんな　ビキニを　みてるんじゃなくて\n"
	.string "わたしの　びぼうが　げんいん　かしら⋯⋯？$"

Route131_Text_ReliIntro: @ 0x08261955
	.string "アミ“きょうだい　ちからを　あわせて\n"
	.string "がんばっちゃおうかな！？$"

Route131_Text_ReliDefeat: @ 0x08261975
	.string "アミ“きょうだいで　ちからを　あわせても\n"
	.string "かてなかったわ$"

Route131_Text_ReliPostBattle: @ 0x08261992
	.string "アミ“キナギの　にんげんは\n"
	.string "うまれた　ときから\l"
	.string "うみと　ポケモンと　いっしょ　なんだ$"

Route131_Text_ReliNotEnoughMons: @ 0x082619BD
	.string "アミ“ポケモン　2ひき　いないの？\n"
	.string "ポケモンしょうぶ　たのしめないわね$"

Route131_Text_IanIntro: @ 0x082619E1
	.string "カツ“きょうだい　ちからを　あわせて\n"
	.string "がんばりまーす！！$"

Route131_Text_IanDefeat: @ 0x082619FE
	.string "カツ“あねきと　がんばったのに\n"
	.string "かてなかったよ⋯⋯$"

Route131_Text_IanPostBattle: @ 0x08261A18
	.string "カツ“キナギって　うみの　うえに\n"
	.string "うかんでる　まち　だろ？\p"
	.string "だから　うみが　つづくかぎり\n"
	.string "そこは　キナギ　なんだよ！$"

Route131_Text_IanNotEnoughMons: @ 0x08261A53
	.string "カツ“ポケモン　2ひき　いたら\n"
	.string "ポケモンしょうぶ　してやるよ！$"

Route131_Text_TaliaIntro: @ 0x08261A73
	.string "わたしに　かてたら\n"
	.string "すごい　じょうほう　おしえてあげる！$"

Route131_Text_TaliaDefeat: @ 0x08261A90
	.string "あら　まけちゃったのね$"

Route131_Text_TaliaPostBattle: @ 0x08261A9C
	.string "この　そばに　ふしぎな　ばしょが　あるわよ\n"
	.string "たかい　とうが　そびえているの！\l"
	.string "みてきたら　どうかしら？$"

Route131_Text_KevinIntro: @ 0x08261AD0
	.string "キナギには　おおらかな　やつ　ばかりだぜ！\n"
	.string "ぜったい　おこったり　しないんだ\l"
	.string "もちろん　オレもな$"

Route131_Text_KevinDefeat: @ 0x08261B01
	.string "あ⋯⋯っ$"

Route131_Text_KevinPostBattle: @ 0x08261B06
	.string "ちっ！　⋯⋯じゃ　なかった\n"
	.string "お　おこってない　おこってないよ！\p"
	.string "⋯⋯ハハ　つよいね　きみは！\n"
	.string "はっハッは！$"
Route132_Text_GilbertIntro: @ 0x08261B3C
	.string "ちいさい　ころは　よく　カゼを　ひいたけど\n"
	.string "すいえいを　はじめて　こんなに　じょうぶ！$"

Route132_Text_GilbertDefeat: @ 0x08261B68
	.string "もっと　つよくなりたい⋯⋯！$"

Route132_Text_GilbertPostBattle: @ 0x08261B77
	.string "ポケモン　トレーナーも\n"
	.string "のやまを　あるき　まわるから\l"
	.string "とっても　けんこうてき　だよねー！$"

Route132_Text_DanaIntro: @ 0x08261BA4
	.string "ながれの　つよい　ところでは\n"
	.string "およがないように　しているのよ$"

Route132_Text_DanaDefeat: @ 0x08261BC3
	.string "いやああああんっ！$"

Route132_Text_DanaPostBattle: @ 0x08261BCD
	.string "ながされると　じぶんが　どこに　いるのか\n"
	.string "わからなく　なっちゃうの⋯⋯$"

Route132_Text_RonaldIntro: @ 0x08261BF1
	.string "かつか　まけるか\n"
	.string "やれば　わかることだろ！$"

Route132_Text_RonaldDefeat: @ 0x08261C07
	.string "わーん\n"
	.string "まけて　しまった$"

Route132_Text_RonaldPostBattle: @ 0x08261C14
	.string "かてると　わかる　しょうぶは　しない！\n"
	.string "かつか　まけるか\l"
	.string "その　ギリギリの　かんじが　いいんだ！$"

Route132_Text_KiyoIntro: @ 0x08261C45
	.string "24じかん　ポケモンのこと　かんがえてる\n"
	.string "そんな　おれに　かてると　おもうか！？$"

Route132_Text_KiyoDefeat: @ 0x08261C6E
	.string "まけた\n"
	.string "おまえさんには　まけたわ$"

Route132_Text_KiyoPostBattle: @ 0x08261C7F
	.string "くう⋯⋯\n"
	.string "おまえも　ポケモンばか　だな！\p"
	.string "24じかん　ポケモンのこと　ばかり\n"
	.string "かんがえて　いるんだろ！$"

Route132_Text_MakaylaIntro: @ 0x08261CB3
	.string "いつも　いっしょの　じいさんが\n"
	.string "いなくても　かてるわい！$"

Route132_Text_MakaylaDefeat: @ 0x08261CD0
	.string "あら　やっぱり　ダメかね$"

Route132_Text_MakaylaPostBattle: @ 0x08261CDD
	.string "あの　わかい　おとこのこ\n"
	.string "じいさんの　わかい　ころに　そっくりじゃ\l"
	.string "ポッ⋯⋯$"

Route132_Text_JonathanIntro: @ 0x08261D04
	.string "さっき　から　へんな　しせんを\n"
	.string "かんじると　おもったら　キミか？$"

Route132_Text_JonathanDefeat: @ 0x08261D25
	.string "へえ！　つよいね！$"

Route132_Text_JonathanPostBattle: @ 0x08261D2F
	.string "だれかが　ぼくの　ことを\n"
	.string "みているきが　して　おちつかないっ！$"

Route132_Text_PaxtonIntro: @ 0x08261D4F
	.string "いつも　いっしょの　ばあさんは　どこかな？\n"
	.string "ひとりで　かてるじゃろか$"

Route132_Text_PaxtonDefeat: @ 0x08261D72
	.string "ああ　やっぱり　ダメかね$"

Route132_Text_PaxtonPostBattle: @ 0x08261D7F
	.string "ばあさんも　わしを　さがしてるじゃろ\n"
	.string "はよう　みつけて　やらんと$"

Route132_Text_DarcyIntro: @ 0x08261DA0
	.string "ひとりで　この　ばしょで\n"
	.string "しゅぎょう　するのが　すきだったのに！\l"
	.string "おおぜい　やって　くるんだもの　ひどい！$"

Route132_Text_DarcyDefeat: @ 0x08261DD6
	.string "わかったわよ\n"
	.string "みんなで　つかえば　いいんでしょ$"

Route132_Text_DarcyPostBattle: @ 0x08261DEE
	.string "とりあえず　そこの　おじいさんと　くんで\n"
	.string "むこうの　チームに　いどんで　みようかな？$"
	.incbin "baserom_jp.gba", 0x261e19, 0x57a
