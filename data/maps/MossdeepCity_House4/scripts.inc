@ MossdeepCity_House4 scripts (JP map g14 m8 @ 0x0820CC5B)

MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman:: @ 0x0820CC5C
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases:: @ 0x0820CC71
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy:: @ 0x0820CC7B
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase:: @ 0x0820CC98
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty:: @ 0x0820CCA2
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases: @ 0x0820CCB5
	.string "おとうと　ったら\n"
	.string "ひとの　ひみつきちを　さがすのが\l"
	.string "たのしみ　なんだって！$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle: @ 0x0820CCDB
	.string "おとうと　ったら\n"
	.string "ともだちの　ひみつきちに　いって\l"
	.string "ポケモンしょうぶを　するのが\l"
	.string "たのしみ　なんだって！$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX: @ 0x0820CD10
	.string "ひょっとして　{STR_VAR_1}　に\n"
	.string "ひみつきち　つくったの　きみ？$"

MossdeepCity_House4_Text_MakeSecretBase: @ 0x0820CD2C
	.string "きみ　どこかに　ひみつきち　つくりなよ！\n"
	.string "ぼくが　さがしだして　みせるからさ$"

MossdeepCity_House4_Text_Skitty: @ 0x0820CD53
	.string "エネコ“みゃあん？$"
