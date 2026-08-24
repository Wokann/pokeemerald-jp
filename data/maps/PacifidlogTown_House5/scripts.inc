@ PacifidlogTown_House5 scripts (JP map g7 m6 @ 0x081F8055)

PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "きょうは　マボロシじま　みえんのう⋯⋯$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "なっ　なんと！\n"
	.string "きょうは　マボロシじま　みえるのじゃ！$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "マボロシじま⋯⋯\n"
	.string "おそらく　しんきろうの　かんけいで\l"
	.string "みえたり　みえなかったり　するんだろう\p"
	.string "いや　ひょっとしたら　ほんとうに\n"
	.string "あらわれたり　きえたり　しているのか⋯⋯？$"
