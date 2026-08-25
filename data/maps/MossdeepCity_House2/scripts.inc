@ MossdeepCity_House2 scripts (JP map g14 m2 @ 0x0820C3D2)

MossdeepCity_House2_MapScripts::
	.byte 0

MossdeepCity_House2_EventScript_Man:: @ 0x0820C3D3
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Twin:: @ 0x0820C3DC
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Wingull:: @ 0x0820C3E5
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox MossdeepCity_House2_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry_jp
	closemessage
	setflag FLAG_WINGULL_DELIVERED_MAIL
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_House2_EventScript_WingullExitNorth
	call_if_eq VAR_FACING, DIR_WEST, MossdeepCity_House2_EventScript_WingullExitWest
	removeobject LOCALID_MOSSDEEP_HOUSE_WINGULL
	release
	end

MossdeepCity_House2_EventScript_WingullExitNorth:: @ 0x0820C418
	applymovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitNorth
	waitmovement 0
	return

MossdeepCity_House2_EventScript_WingullExitWest:: @ 0x0820C423
	applymovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitEast
	waitmovement 0
	return

MossdeepCity_House2_Movement_WingullExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_WingullExitEast:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree: @ 0x0820C43A
	.string "おれの　いもうとは　ヒワマキの\n"
	.string "ボーイフレンドと　ぶんつう　してる\p"
	.string "ちっとも　うらやましく　ないぞ！$"

MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth: @ 0x0820C46D
	.string "ヒワマキの　おともだちに　あえなくても\n"
	.string "ポケモンが　おてがみを　はこんでくれるの\l"
	.string "はなれていても　さみしくないわ！$"

MossdeepCity_House2_Text_Wingull: @ 0x0820C4A7
	.string "キャモメ“ぴひょー！$"
