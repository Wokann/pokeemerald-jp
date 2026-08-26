@ MauvilleCity_PokemonCenter_1F scripts (JP map g10 m5 @ 0x08200DD4)

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition: @ 0x08200DDF
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx:: @ 0x08200DED
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse:: @ 0x08200DF1
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1:: @ 0x08200DFF
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2:: @ 0x08200E08
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster:: @ 0x08200E11
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings: @ 0x08200E1A
	.string "あそこに　いる　オヤジ\n"
	.string "へんなこと　いったり　するの！\p"
	.string "なんだか　おもしろくって\n"
	.string "わすれられない　そんざい　だわ！$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner: @ 0x08200E54
	.string "レコードコーナーを　つかったらね\n"
	.string "ムロタウンで　はやっている　ものが\l"
	.string "ともだちと　いっしょに　なったのよ！$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun: @ 0x08200E8A
	.string "ポケモンセンターの　2かいに\n"
	.string "レコードコーナーが　できたんだってさ！\p"
	.string "よく　わからないけど　おもしろそうだろ？\n"
	.string "とにかく　やってみるよ！$"
