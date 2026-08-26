@ PacifidlogTown_House4 scripts (JP map g7 m5 @ 0x081F7F3D)

PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl:: @ 0x081F7F3E
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman:: @ 0x081F7F47
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy:: @ 0x081F7F50
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes:: @ 0x081F7F71
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No:: @ 0x081F7F7B
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon: @ 0x081F7F85
	.string "ホウエンの　そらたかくを　とんでいく\n"
	.string "ポケモンを　みた！　って　ひとが　いるけど\p"
	.string "ずっと　とびまわって　いるのかしら？\n"
	.string "どこかで　やすんだり　しそうだけど$"

PacifidlogTown_House4_Text_SkyPokemon: @ 0x081F7FD3
	.string "おそらの　ポケモン！\n"
	.string "おそらの　ポケモン！$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom: @ 0x081F7FE9
	.string "きみ　どこから　きたの？$"

PacifidlogTown_House4_Text_YesTown: @ 0x081F7FF6
	.string "はい⋯⋯？\n"
	.string "ハイ⋯　タウン⋯⋯？\p"
	.string "しらないなぁ　そんな　まち$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere: @ 0x081F8015
	.string "いいえ　って　そんな⋯⋯\n"
	.string "どこからも　きてない　はずが　ないでしょ\p"
	.string "ま　まさか　きみ⋯⋯\n"
	.string "うみの　そこで　うまれた　とか⋯⋯？$"
