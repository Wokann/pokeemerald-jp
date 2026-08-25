	compare_local_to_value 0x21, 0x1C
	compare_var_to_value 0x3F00, 0xA2E
	gotostd 0x13
	.incbin "baserom_jp.gba", 0x263174, 0x8e4
LilycoveCity_Text_BerrySuitsYou: @ 0x08263A58
	.string "やっぱり\p"
	.string "わたしに　スーツが　にあうように\n"
	.string "うみには　しおかぜが　にあうな\l"
	.string "そして　きみには　きのみが　にあいそうだ⋯⋯\p"
	.string "なんでだろうね？$"

LilycoveCity_Text_BecauseYoureTrainer: @ 0x08263A9E
	.string "やっぱり　それは⋯⋯⋯⋯\p"
	.string "きみが　トレーナーだからだ！$"

LilycoveCity_Text_PokeblocksSuitPokemon: @ 0x08263ABA
	.string "やっぱり\p"
	.string "わたしに　シンプルさが　にあうように\n"
	.string "ポケモンには　ポロックが　にあうな$"
	.incbin "baserom_jp.gba", 0x263ae4, 0x787
	.globl gJPText_0026426B
gJPText_0026426B: @ 0x0826426B
	.string "ポケモンえほんが　そろってる！$"

	.globl gJPText_0026427B
gJPText_0026427B: @ 0x0826427B
	.string "いろんな　ほんが　いっぱいだ！$"

	.globl gJPText_0026428B
gJPText_0026428B: @ 0x0826428B
	.string "ポケモンざっしが　ならんでる！\p"
	.string "⋯⋯‘ポケモンのとも'\n"
	.string "⋯⋯‘ポケモン　てちょう'\l"
	.string "⋯⋯‘かわいい　ポケモン'$"

	.globl gJPText_002642C3
gJPText_002642C3: @ 0x082642C3
	.string "たかそうな　つぼが　ある！\n"
	.string "のぞきこむと⋯⋯\p"
	.string "なかは　からっぽ　だ！$"

	.globl gJPText_002642E6
gJPText_002642E6: @ 0x082642E6
	.string "なかは　からっぽ　だ！$"

	.globl gJPText_002642F2
gJPText_002642F2: @ 0x082642F2
	.string "たくさんの　ポケモン　グッズが\n"
	.string "ところせましと　ならべられてる！$"

	.globl gJPText_00264313
gJPText_00264313: @ 0x08264313
	.string "なにかの　せっけいず⋯⋯？\n"
	.string "みても　チンプンカンプン！$"

	.incbin "baserom_jp.gba", 0x26432f, 0x10
