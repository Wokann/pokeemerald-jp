@ MossdeepCity_StevensHouse scripts (JP map g14 m7 @ 0x0820C816)

MossdeepCity_StevensHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_StevensHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_StevensHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_StevensHouse_OnFrame
	.byte 0

MossdeepCity_StevensHouse_OnLoad:: @ 0x0820C826
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_StevensHouse_EventScript_HideStevensNote
	end

MossdeepCity_StevensHouse_EventScript_HideStevensNote:: @ 0x0820C830
	setmetatile 0x6, 0x4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_StevensHouse_OnTransition:: @ 0x0820C83A
	call_if_eq VAR_STEVENS_HOUSE_STATE, 0x2, MossdeepCity_StevensHouse_EventScript_SetStevenPos
	end

MossdeepCity_StevensHouse_EventScript_SetStevenPos:: @ 0x0820C846
	setobjectxyperm LOCALID_STEVENS_HOUSE_STEVEN, 0x6, 0x5
	setobjectmovementtype LOCALID_STEVENS_HOUSE_STEVEN, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_StevensHouse_OnFrame:: @ 0x0820C852
	map_script_2 VAR_STEVENS_HOUSE_STATE, 0x1, MossdeepCity_StevensHouse_EventScript_StevenGivesDive
	.2byte 0

MossdeepCity_StevensHouse_EventScript_StevenGivesDive:: @ 0x0820C85C
	lockall
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_StevensHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER
	msgbox MossdeepCity_StevensHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 0x14
	applymovement LOCALID_STEVENS_HOUSE_STEVEN, MossdeepCity_StevensHouse_Movement_StevenReturn
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_STEVENS_HOUSE_STATE, 0x2
	releaseall
	end

MossdeepCity_StevensHouse_Movement_StevenApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_StevensHouse_Movement_StevenReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_StevensHouse_EventScript_BeldumPokeball:: @ 0x0820C8D3
	lockall
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_LeaveBeldum
	goto MossdeepCity_StevensHouse_EventScript_GiveBeldum
	end

MossdeepCity_StevensHouse_EventScript_LeaveBeldum:: @ 0x0820C8ED
	msgbox MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_GiveBeldum:: @ 0x0820C8F7
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 0x5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_StevensHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_StevensHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumParty:: @ 0x0820C927
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_SendBeldumPC:: @ 0x0820C94F
	call MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_StevensHouse_EventScript_BeldumTransferredToPC:: @ 0x0820C972
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_StevensHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_StevensHouse_EventScript_ReceivedBeldumFanfare:: @ 0x0820C97D
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_STEVENS_HOUSE_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_StevensHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_StevensHouse_EventScript_ReceivedBeldum:: @ 0x0820C993
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_RockDisplay:: @ 0x0820C99B
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_StevensHouse_EventScript_Steven:: @ 0x0820C9A4
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_StevensHouse_EventScript_Letter:: @ 0x0820C9AD
	lockall
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_StevensHouse_EventScript_DiveItemBall:: @ 0x0820C9B8
	finditem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_StevensHouse_Text_YouveEarnedHMDive: @ 0x0820C9C8
	.string "ダイゴ“{PLAYER}{KUN}⋯⋯\p"
	.string "みてのとおり　なにも　ないけど\n"
	.string "ここが　ボクの　いえなんだ\p"
	.string "⋯⋯そうだ　さっきは　ありがとう\n"
	.string "これは　ボクからの　おれいの　きもち\l"
	.string "ひでんマシンの　ダイビングだ\p"
	.string "えんりょ　しないで　もっていきなよ$"

MossdeepCity_StevensHouse_Text_ExplainDive: @ 0x0820CA36
	.string "ダイゴ“なみのりを　していると\n"
	.string "みずの　いろが　こい　ばしょが　ある\p"
	.string "そこで　ダイビングを　つかうと\n"
	.string "うみの　そこに　もぐれるから\p"
	.string "うかびたい　ときは\n"
	.string "もういちど　ダイビングを　つかうんだ\p"
	.string "ばしょに　よっては\n"
	.string "うかべない　ばあいも　あるけど$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis: @ 0x0820CAAF
	.string "ダイゴ“トクサネと　ルネの　あいだには\n"
	.string "かいていどうくつが　あるらしい\p"
	.string "ほら　たしか⋯⋯　クスノキかんちょうが\n"
	.string "はっけんした　という　あれだよ$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum: @ 0x0820CAF7
	.string "{PLAYER}は\n"
	.string "モンスターボールを　しらべた！\p"
	.string "なかには　ポケモンの\n"
	.string "ダンバルが　はいっている！\p"
	.string "モンスターボールを　もって　いきますか？$"

MossdeepCity_StevensHouse_Text_ObtainedBeldum: @ 0x0820CB39
	.string "{PLAYER}は\n"
	.string "ダンバルを　てにいれた！$"

MossdeepCity_StevensHouse_Text_NoSpaceForAnotherMon: @ 0x0820CB4A
	.string "これいじょう　ポケモンを　もてない！$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas: @ 0x0820CB5D
	.string "{PLAYER}は　モンスターボールを\n"
	.string "そのままに　しておいた$"

MossdeepCity_StevensHouse_Text_LetterFromSteven: @ 0x0820CB77
	.string "てがみが　ある！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "{PLAYER}{KUN}へ\p"
	.string "ボクは　おもうことが　あって\n"
	.string "しばらく　しゅぎょうを　つづける\l"
	.string "とうぶん　いえに　かえらない\p"
	.string "そこで　おねがいだ\p"
	.string "つくえの　うえにある\n"
	.string "モンスターボールを　うけとって　ほしい\p"
	.string "なかに　いるのは　ダンバルといって\n"
	.string "ボクの　おきにいりの　ポケモンだから\p"
	.string "よろしく　たのむよ\p"
	.string "では　また　いつか　あおう！\n"
	.string "　　　　　　ツワブキ　ダイゴより$"

MossdeepCity_StevensHouse_Text_CollectionOfRareRocks: @ 0x0820CC3F
	.string "ダイゴの　あつめた\n"
	.string "めずらしい　いしが　かざってある！$"
