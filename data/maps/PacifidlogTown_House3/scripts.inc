@ PacifidlogTown_House3 scripts (JP map g7 m4 @ 0x081F7D1A)

PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_001F7D1B::
	lock
	faceplayer
	checkflag 0x9A
	goto_if 0x1, PacifidlogTown_House3_EventScript_001F7DB5
	setvar 0x8008, 0x2
	copyvar 0x8004, 0x8008
	specialvar 0x800D, GetInGameTradeSpeciesInfo
	copyvar 0x8009, 0x800D
	loadword 0x0, gJPText_001F7DC8
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PacifidlogTown_House3_EventScript_001F7D9D
	special ChoosePartyMon
	waitstate
	copyvar 0x800A, 0x8004
	compare_var_to_value 0x8004, 0xFF
	goto_if 0x1, PacifidlogTown_House3_EventScript_001F7D9D
	copyvar 0x8005, 0x800A
	specialvar 0x800D, GetTradeSpecies
	copyvar 0x800B, 0x800D
	compare_var_to_var 0x800D, 0x8009
	goto_if 0x5, PacifidlogTown_House3_EventScript_001F7DA7
	copyvar 0x8004, 0x8008
	copyvar 0x8005, 0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	buffermovename 0x0, 0x8009
	loadword 0x0, gJPText_001F7E3D
	callstd 0x4
	setflag 0x9A
	release
	end

PacifidlogTown_House3_EventScript_001F7D9D::
	loadword 0x0, gJPText_001F7E92
	callstd 0x4
	release
	end

PacifidlogTown_House3_EventScript_001F7DA7::
	buffermovename 0x0, 0x8009
	loadword 0x0, gJPText_001F7E77
	callstd 0x4
	release
	end

PacifidlogTown_House3_EventScript_001F7DB5::
	loadword 0x0, gJPText_001F7EBB
	callstd 0x4
	release
	end

PacifidlogTown_House3_EventScript_001F7DBF::
	loadword 0x0, gJPText_001F7EFD
	callstd 0x2
	end

	.globl gJPText_001F7DC8
gJPText_001F7DC8: @ 0x081F7DC8
	.string "みてくれよ　この　{STRING 0x03}！\n"
	.string "おれが　きのう　じぶんの　たんじょうびに\l"
	.string "きねんに　つかまえた　{STRING 0x03}だ！\p"
	.string "お！　ほしい　って　かおを　したな？\n"
	.string "まっ　きちょうな　{STRING 0x03}だからな！\p"
	.string "よし！　{STRING 0x02}と　だったら\n"
	.string "こうかん　して　やっても　いいぞ！$"

	.globl gJPText_001F7E3D
gJPText_001F7E3D: @ 0x081F7E3D
	.string "おっ　これが　{STRING 0x02}　かあー！\n"
	.string "やっぱ　{STRING 0x03}　とは\l"
	.string "いろいろ　にている　ようで\l"
	.string "びみょうに　ちがうなあ！\p"
	.string "サンキュ！$"

	.globl gJPText_001F7E77
gJPText_001F7E77: @ 0x081F7E77
	.string "だめだめ！　{STRING 0x02}　じゃないと　\n"
	.string "ひきうけられないね！$"

	.globl gJPText_001F7E92
gJPText_001F7E92: @ 0x081F7E92
	.string "ふーん　やめるのか⋯⋯\p"
	.string "まっ　おれのほうも\n"
	.string "どうしても　って　わけじゃ　ないしね$"

	.globl gJPText_001F7EBB
gJPText_001F7EBB: @ 0x081F7EBB
	.string "じぶんで　さがしても　いいんだけど⋯⋯\p"
	.string "ほかの　トレーナーが　つかまえた\n"
	.string "タツベイ　って　いうのが\l"
	.string "どうしても　ほしかったんだよね$"

	.globl gJPText_001F7EFD
gJPText_001F7EFD: @ 0x081F7EFD
	.string "それって　ポケモンずかん？\p"
	.string "それって　あなた　たくさんの\n"
	.string "ポケモンと　であった　ってこと？\p"
	.string "それって　すっごい　うらやましい！$"
