@ LilycoveCity_DepartmentStore_4F scripts (JP map g13 m19 @ 0x0820AB4E)

LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman:: @ 0x0820AB4F
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman:: @ 0x0820AB58
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster:: @ 0x0820AB61
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft:: @ 0x0820AB6A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	pokemartlistend

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight:: @ 0x0820AB90
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	pokemartlistend

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM: @ 0x0820ABB4
	.string "うむむ⋯⋯\p"
	.string "こうげきの　わざ　か⋯⋯\n"
	.string "まもりの　わざ　か⋯⋯\p"
	.string "どの　わざマシンを\n"
	.string "ポケモンに　おぼえさせるか　なやむ⋯⋯$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs: @ 0x0820ABF1
	.string "わざマシンって　たくさん　あるのね！\p"
	.string "なにかの　カタログには\n"
	.string "ぜんぶで　50しゅるい　って\l"
	.string "かいて　あったわ$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves: @ 0x0820AC28
	.string "わざマシン　ぜんぶ　ほしいけど\n"
	.string "ポケモン　4つしか　わざ　おぼえないもんな$"
