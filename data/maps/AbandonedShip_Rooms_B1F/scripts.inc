@ AbandonedShip_Rooms_B1F scripts (JP map g24 m58 @ 0x0821AD78)

AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_OnResume
	.byte 0

AbandonedShip_Rooms_B1F_OnResume:: @ 0x0821AD7E
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 17, 4
	end

AbandonedShip_Rooms_B1F_EventScript_FatMan:: @ 0x0821AD87
	msgbox AbandonedShip_Rooms_B1F_Text_GettingQueasy, MSGBOX_NPC
	end

AbandonedShip_Rooms_B1F_Text_GettingQueasy: @ 0x0821AD90
	.string "うぅ⋯⋯\p"
	.string "なんだか　ふねの　なかに　いるだけで\n"
	.string "よってきちゃった⋯⋯\p"
	.string "ふねは　ちっとも　うごいてないのに⋯⋯$"
