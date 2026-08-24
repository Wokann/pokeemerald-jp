@ PacifidlogTown_House4 scripts (JP map g7 m5 @ 0x081F7F3D)

PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "ホウエンの　そらたかくを　とんでいく\n"
	.string "ポケモンを　みた！　って　ひとが　いるけど\p"
	.string "ずっと　とびまわって　いるのかしら？\n"
	.string "どこかで　やすんだり　しそうだけど$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "おそらの　ポケモン！\n"
	.string "おそらの　ポケモン！$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "きみ　どこから　きたの？$"

PacifidlogTown_House4_Text_YesTown:
	.string "はい⋯⋯？\n"
	.string "ハイ⋯　タウン⋯⋯？\p"
	.string "しらないなぁ　そんな　まち$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "いいえ　って　そんな⋯⋯\n"
	.string "どこからも　きてない　はずが　ないでしょ\p"
	.string "ま　まさか　きみ⋯⋯\n"
	.string "うみの　そこで　うまれた　とか⋯⋯？$"
