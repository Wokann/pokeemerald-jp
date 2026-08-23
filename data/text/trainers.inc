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

	.incbin "baserom_jp.gba", 0x25975c, 0x8c37
