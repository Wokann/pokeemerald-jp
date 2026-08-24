@ RustboroCity_House3 scripts (JP map g11 m16 @ 0x08204117)

RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname.
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	@ JP uses the waitdooranim opcode (0xC5) where US uses waitmoncry.
	waitmoncry_jp
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames: @ 0x0820413D
	.string "じぶんの　ポケモンには\n"
	.string "ぴったりの　ニックネームを　つけるんじゃ\l"
	.string "いわゆる　おりじなりてぃ　じゃ！$"

RustboroCity_House3_Text_NamingPikachuPekachu: @ 0x0820416F
	.string "だからって　ピカチュウに\n"
	.string "‘ペカチュウ’って　つけても\l"
	.string "ほとんど　かわって　ないでしょうに⋯⋯\p"
	.string "まあ　わかりやすいのも\n"
	.string "ニックネームには　だいじ　ですけどねぇ$"

RustboroCity_House3_Text_Pekachu: @ 0x082041BF
	.string "ペカチュウ“ぺかー！$"

	@ Fortree City House1 and later unstructured script owners begin here.
	.incbin "baserom_jp.gba", 0x2041ca, 0x1d4
