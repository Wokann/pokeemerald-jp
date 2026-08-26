@ LilycoveCity_DepartmentStore_3F scripts (JP map g13 m18 @ 0x0820AA19)

LilycoveCity_DepartmentStore_3F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft:: @ 0x0820AA1A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins: @ 0x0820AA34
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight:: @ 0x0820AA44
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters: @ 0x0820AA5C
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM:: @ 0x0820AA6E
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_PokefanM:: @ 0x0820AA77
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_Woman:: @ 0x0820AA80
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon: @ 0x0820AA89
	.string "てっとりばやく　ポケモンを　つよくするなら\n"
	.string "どうぐを　あたえるのが　いちばん！\p"
	.string "タウリンなら　こうげきりょく　アップ！\n"
	.string "リゾチウムなら　とくこう　アップ　だぜ！$"

LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance: @ 0x0820AADA
	.string "じょうぶな　ポケモンに\n"
	.string "なって　ほしいからね\p"
	.string "ブロムヘキシンで　ぼうぎょりょくを　あげるか\n"
	.string "キトサンで　とくぼうを　あげるか\l"
	.string "いま　かんがえている　ところ　なんだ$"

LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon: @ 0x0820AB2C
	.string "ポケモンにね\n"
	.string "インドメタシンを　あげたら\l"
	.string "すばやさが　あがったの！$"
