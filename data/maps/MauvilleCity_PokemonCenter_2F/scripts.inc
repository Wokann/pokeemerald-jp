@ MauvilleCity_PokemonCenter_2F scripts (JP map g10 m6 @ 0x08200ECF)

MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS.
MauvilleCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

MauvilleCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

MauvilleCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_Text_Youngster: @ 0x08200EFF
	.string "ここの　コロシアムで\n"
	.string "つうしんたいせん　できるの　しってる？\p"
	.string "じぶんの　せいせき　って\n"
	.string "かべを　みると　わかるから\l"
	.string "まけてばかりだと　はずかしくなっちゃう⋯⋯$"

	@ Mauville City Mart and later unstructured script owners begin here.
	.incbin "baserom_jp.gba", 0x200f4f, 0xe1
