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
	.incbin "baserom_jp.gba", 0x259cca, 0x86c9
