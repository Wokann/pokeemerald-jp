@ PacifidlogTown_House5 scripts (JP map g7 m6 @ 0x081F8055)

PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher:: @ 0x081F8056
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent:: @ 0x081F8072
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman:: @ 0x081F807C
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday: @ 0x081F8085
	.string "きょうは　マボロシじま　みえんのう⋯⋯$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday: @ 0x081F8099
	.string "なっ　なんと！\n"
	.string "きょうは　マボロシじま　みえるのじゃ！$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather: @ 0x081F80B5
	.string "マボロシじま⋯⋯\n"
	.string "おそらく　しんきろうの　かんけいで\l"
	.string "みえたり　みえなかったり　するんだろう\p"
	.string "いや　ひょっとしたら　ほんとうに\n"
	.string "あらわれたり　きえたり　しているのか⋯⋯？$"
