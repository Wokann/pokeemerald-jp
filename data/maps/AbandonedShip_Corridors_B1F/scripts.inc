@ AbandonedShip_Corridors_B1F scripts (JP map g24 m57 @ 0x0821ABF0)

AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:: @ 0x0821ABFB
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_Corridors_B1F_OnLoad:: @ 0x0821AC04
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom:: @ 0x0821AC17
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom:: @ 0x0821AC21
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM:: @ 0x0821AC2B
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor:: @ 0x0821AC34
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked:: @ 0x0821AC6B
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked:: @ 0x0821AC75
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan:: @ 0x0821AC7F
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro: @ 0x0821AC96
	.string "ふなのりは　ふねに　のるとき\n"
	.string "かならず　ポケモンを　もっている！\l"
	.string "ちょいと　しょうぶ　してくれ！$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat: @ 0x0821ACC7
	.string "こりゃ　まいった$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle: @ 0x0821ACD0
	.string "ふなぞこが　みずの　なかに\n"
	.string "しずんで　いるんだよ\p"
	.string "ポケモンが　みずに　もぐれる　わざを\n"
	.string "つかえたら　さきに　すすめるんだがな⋯⋯$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip: @ 0x0821AD11
	.string "わーい！\n"
	.string "ふね　だぞー！$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked: @ 0x0821AD1E
	.string "カギが　かかっている\p"
	.string "とびらには　そうこ　と　かかれている$"

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey: @ 0x0821AD3C
	.string "{PLAYER}は\n"
	.string "そうこのカギを　つかった！\p"
	.string "さしこんだ　カギは　ぬけなくなったが\n"
	.string "とびらは　ひらいた！$"

AbandonedShip_Text_TheDoorIsOpen: @ 0x0821AD6C
	.string "とびらは　あいている！$"
