@ VerdanturfTown_FriendshipRatersHouse scripts (JP map g6 m7 @ 0x081F7556)

VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	@ JP opcode 0xC5 is waitdooranim; US uses waitmoncry at this point.
	waitdooranim
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "あなたの　ポケモンが\n"
	.string "どれくらい　なついているか　みてあげる\p"
	.string "あら⋯⋯\n"
	.string "あなたの　ポケモン$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "これいじょうは　ない　ってぐらい\n"
	.string "あなたに　なついているわね\l"
	.string "みている　こっちも　しあわせに　なるわ！$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "なんだか　しあわせそう\n"
	.string "すごく　あなたに　なついているわね$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "かなり　なついているわね\n"
	.string "あなたに　あまえたそうに　しているわよ$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "ちょっと　なついてきた　って　かんじ　かな\n"
	.string "あなたのこと　しんじている　みたい$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "まだ　あなたに　なれていない　ようね\n"
	.string "ふつうの　かんけい　って　かんじが　するわ$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "⋯⋯　なんだか　けいかい　しているみたい\n"
	.string "めつきも　ちょっと　こわいし\l"
	.string "ぜんぜん　あなたに　なついていないわ$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "⋯⋯　ちょっと　いいづらいんだけど\p"
	.string "あなた　じぶんの　ポケモンに\n"
	.string "そんなに　きらわれていて　だいじょうぶ？$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "ピカチュウ“ピカピカッ！$"

@ The next unstructured Verdanturf map starts at 0x081F777F.
	.incbin "baserom_jp.gba", 0x1f777f, 0xab
