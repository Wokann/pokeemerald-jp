@ RustboroCity_House3 scripts (JP map g11 m16 @ 0x08204117)

RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan:: @ 0x08204118
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman:: @ 0x08204121
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_Pekachu:: @ 0x0820412A
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
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
