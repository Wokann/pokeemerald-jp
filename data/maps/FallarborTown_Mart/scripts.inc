@ FallarborTown_Mart scripts (JP map g5 m0 @ 0x081F5098)

FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk:: @ 0x081F5099
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	pokemartlistend

FallarborTown_Mart_EventScript_Woman:: @ 0x081F50CC
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM:: @ 0x081F50D5
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty:: @ 0x081F50DE
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve: @ 0x081F50F1
	.string "あたしの　エネコにね\n"
	.string "つきのいしを　つかってね⋯⋯\p"
	.string "しんか　させるか　どうか\n"
	.string "すっごい　まよってるのよぉ\p"
	.string "しんか　させると　つよくなるけど\n"
	.string "すがたかたち　かわっちゃうし⋯⋯$"

FallarborTown_Mart_Text_Skitty: @ 0x081F5148
	.string "エネコ“みゃおう？$"

FallarborTown_Mart_Text_SellNuggetIFound: @ 0x081F5152
	.string "ひろった　きんのたま⋯⋯\n"
	.string "やっぱり　うるしか　ないのかなあ？\l"
	.string "ほかに　つかいみちも　ないからなあ⋯⋯$"
