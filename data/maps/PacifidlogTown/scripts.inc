@ PacifidlogTown scripts (JP map g0 m15 @ 0x081E6381)

PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "キナギから　カイナへは\n"
	.string "しおの　ながれが　とても　はげしいの\p"
	.string "うかつに　なみのり　すると\n"
	.string "おもわぬ　ほうこうに　ながされちゃう$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "ね！　ね！　すごいでしょ！\n"
	.string "みずの　うえに　おうちが　たってるの！\p"
	.string "ぼく　ここで　うまれたんだよ！$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "そらのはしら？\p"
	.string "⋯⋯ああ　このさきに　たっている\n"
	.string "たかーーい　とうの　ことだね\p"
	.string "あんな　たかい　ところ\n"
	.string "おっかなくて　のぼれないなー\p"
	.string "ぼくは　やっぱり　キナギでの\n"
	.string "すいめん　スレスレな　せいかつが\l"
	.string "はだに　あうんだよねえー$"

PacifidlogTown_Text_TownSign:
	.string "ここは　キナギ　タウン\n"
	.string "あさひが　みずべを　てらす　まち$"
