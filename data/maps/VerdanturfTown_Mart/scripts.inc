@ VerdanturfTown_Mart scripts (JP map g6 m3 @ 0x081F6F27)

VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "ポケモン　しょうぶに\n"
	.string "スペシャルアップは　かかせない！\p"
	.string "たたかいの　ときだけ　とはいえ\n"
	.string "わざの　いりょくが　あがるんだからな！$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "バトルテント　ひっしょう\n"
	.string "こうりゃくぼん　というのは\l"
	.string "うってない　ですねえ⋯⋯\p"
	.string "やはり　じぶんで\n"
	.string "がんばらないと　ダメなんですねえ$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "シダケでしか　かえない　ネストボール\n"
	.string "よわい　ポケモンほど　つかまえ　やすくなるの$"
