@ VerdanturfTown_FriendshipRatersHouse scripts (JP map g6 m7 @ 0x081F7556)

VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater:: @ 0x081F7557
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

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou:: @ 0x081F75BA
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary:: @ 0x081F75C4
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou:: @ 0x081F75CE
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou:: @ 0x081F75D8
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot:: @ 0x081F75E2
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy:: @ 0x081F75EC
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou:: @ 0x081F75F6
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu:: @ 0x081F7600
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou: @ 0x081F7613
	.string "あなたの　ポケモンが\n"
	.string "どれくらい　なついているか　みてあげる\p"
	.string "あら⋯⋯\n"
	.string "あなたの　ポケモン$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou: @ 0x081F7641
	.string "これいじょうは　ない　ってぐらい\n"
	.string "あなたに　なついているわね\l"
	.string "みている　こっちも　しあわせに　なるわ！$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy: @ 0x081F7675
	.string "なんだか　しあわせそう\n"
	.string "すごく　あなたに　なついているわね$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot: @ 0x081F7693
	.string "かなり　なついているわね\n"
	.string "あなたに　あまえたそうに　しているわよ$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou: @ 0x081F76B4
	.string "ちょっと　なついてきた　って　かんじ　かな\n"
	.string "あなたのこと　しんじている　みたい$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou: @ 0x081F76DC
	.string "まだ　あなたに　なれていない　ようね\n"
	.string "ふつうの　かんけい　って　かんじが　するわ$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary: @ 0x081F7705
	.string "⋯⋯　なんだか　けいかい　しているみたい\n"
	.string "めつきも　ちょっと　こわいし\l"
	.string "ぜんぜん　あなたに　なついていないわ$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou: @ 0x081F773C
	.string "⋯⋯　ちょっと　いいづらいんだけど\p"
	.string "あなた　じぶんの　ポケモンに\n"
	.string "そんなに　きらわれていて　だいじょうぶ？$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu: @ 0x081F7772
	.string "ピカチュウ“ピカピカッ！$"
