@ LavaridgeTown_Mart scripts (JP map g4 m4 @ 0x081F4ECC)

LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk:: @ 0x081F4ECD
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM:: @ 0x081F4EFA
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman:: @ 0x081F4F03
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike: @ 0x081F4F0C
	.string "スピーダー　つかって\n"
	.string "ポケモンの　すばやさ　あげるんじゃ！\p"
	.string "そうすりゃ　せんせいこうげき　できて\n"
	.string "たたかいが　ゆうりに　なるからのう！$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney: @ 0x081F4F50
	.string "えんとつやまの　ちょうじょう　だけで\n"
	.string "かうことが　できる　おみやげは\l"
	.string "ポケモンに　あげると　よろこぶよ！$"
