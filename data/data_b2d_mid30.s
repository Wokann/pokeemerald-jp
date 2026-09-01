.include "sound/MPlayDef.s"
	.section .rodata.after_tilesets, "a", %progbits
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/map_header.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.include "data/layouts/layouts.inc"
	.include "data/layouts/layouts_table.inc"
	.globl gMapHeaders
gMapHeaders: @ 0x0845A8D8
	@ struct MapHeader { mapLayout, events, mapScripts, connections, music, mapLayoutId, regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType }
	@ MAP_PETALBURG_CITY (g0 m0)
	.include "data/maps/PetalburgCity/header.inc"
	@ MAP_SLATEPORT_CITY (g0 m1)
	.include "data/maps/SlateportCity/header.inc"
	@ MAP_MAUVILLE_CITY (g0 m2)
	.include "data/maps/MauvilleCity/header.inc"
	@ MAP_RUSTBORO_CITY (g0 m3)
	.include "data/maps/RustboroCity/header.inc"
	@ MAP_FORTREE_CITY (g0 m4)
	.include "data/maps/FortreeCity/header.inc"
	@ MAP_LILYCOVE_CITY (g0 m5)
	.include "data/maps/LilycoveCity/header.inc"
	@ MAP_MOSSDEEP_CITY (g0 m6)
	.include "data/maps/MossdeepCity/header.inc"
	@ MAP_SOOTOPOLIS_CITY (g0 m7)
	.include "data/maps/SootopolisCity/header.inc"
	@ MAP_EVER_GRANDE_CITY (g0 m8)
	.include "data/maps/EverGrandeCity/header.inc"
	@ MAP_LITTLEROOT_TOWN (g0 m9)
	.include "data/maps/LittlerootTown/header.inc"
	@ MAP_OLDALE_TOWN (g0 m10)
	.include "data/maps/OldaleTown/header.inc"
	@ MAP_DEWFORD_TOWN (g0 m11)
	.include "data/maps/DewfordTown/header.inc"
	@ MAP_LAVARIDGE_TOWN (g0 m12)
	.include "data/maps/LavaridgeTown/header.inc"
	@ MAP_FALLARBOR_TOWN (g0 m13)
	.include "data/maps/FallarborTown/header.inc"
	@ MAP_VERDANTURF_TOWN (g0 m14)
	.include "data/maps/VerdanturfTown/header.inc"
	@ MAP_PACIFIDLOG_TOWN (g0 m15)
	.include "data/maps/PacifidlogTown/header.inc"
	@ MAP_ROUTE101 (g0 m16)
	.include "data/maps/Route101/header.inc"
	@ MAP_ROUTE102 (g0 m17)
	.include "data/maps/Route102/header.inc"
	@ MAP_ROUTE103 (g0 m18)
	.include "data/maps/Route103/header.inc"
	@ MAP_ROUTE104 (g0 m19)
	.include "data/maps/Route104/header.inc"
	@ MAP_ROUTE105 (g0 m20)
	.include "data/maps/Route105/header.inc"
	@ MAP_ROUTE106 (g0 m21)
	.include "data/maps/Route106/header.inc"
	@ MAP_ROUTE107 (g0 m22)
	.include "data/maps/Route107/header.inc"
	@ MAP_ROUTE108 (g0 m23)
	.include "data/maps/Route108/header.inc"
	@ MAP_ROUTE109 (g0 m24)
	.include "data/maps/Route109/header.inc"
	@ MAP_ROUTE110 (g0 m25)
	.include "data/maps/Route110/header.inc"
	@ MAP_ROUTE111 (g0 m26)
	.include "data/maps/Route111/header.inc"
	@ MAP_ROUTE112 (g0 m27)
	.include "data/maps/Route112/header.inc"
	@ MAP_ROUTE113 (g0 m28)
	.include "data/maps/Route113/header.inc"
	@ MAP_ROUTE114 (g0 m29)
	.include "data/maps/Route114/header.inc"
	@ MAP_ROUTE115 (g0 m30)
	.include "data/maps/Route115/header.inc"
	@ MAP_ROUTE116 (g0 m31)
	.include "data/maps/Route116/header.inc"
	@ MAP_ROUTE117 (g0 m32)
	.include "data/maps/Route117/header.inc"
	@ MAP_ROUTE118 (g0 m33)
	.include "data/maps/Route118/header.inc"
	@ MAP_ROUTE119 (g0 m34)
	.include "data/maps/Route119/header.inc"
	@ MAP_ROUTE120 (g0 m35)
	.include "data/maps/Route120/header.inc"
	@ MAP_ROUTE121 (g0 m36)
	.include "data/maps/Route121/header.inc"
	@ MAP_ROUTE122 (g0 m37)
	.include "data/maps/Route122/header.inc"
	@ MAP_ROUTE123 (g0 m38)
	.include "data/maps/Route123/header.inc"
	@ MAP_ROUTE124 (g0 m39)
	.include "data/maps/Route124/header.inc"
	@ MAP_ROUTE125 (g0 m40)
	.include "data/maps/Route125/header.inc"
	@ MAP_ROUTE126 (g0 m41)
	.include "data/maps/Route126/header.inc"
	@ MAP_ROUTE127 (g0 m42)
	.include "data/maps/Route127/header.inc"
	@ MAP_ROUTE128 (g0 m43)
	.include "data/maps/Route128/header.inc"
	@ MAP_ROUTE129 (g0 m44)
	.include "data/maps/Route129/header.inc"
	@ MAP_ROUTE130 (g0 m45)
	.include "data/maps/Route130/header.inc"
	@ MAP_ROUTE131 (g0 m46)
	.include "data/maps/Route131/header.inc"
	@ MAP_ROUTE132 (g0 m47)
	.include "data/maps/Route132/header.inc"
	@ MAP_ROUTE133 (g0 m48)
	.include "data/maps/Route133/header.inc"
	@ MAP_ROUTE134 (g0 m49)
	.include "data/maps/Route134/header.inc"
	@ MAP_UNDERWATER_ROUTE124 (g0 m50)
	.include "data/maps/Underwater_Route124/header.inc"
	@ MAP_UNDERWATER_ROUTE126 (g0 m51)
	.include "data/maps/Underwater_Route126/header.inc"
	@ MAP_UNDERWATER_ROUTE127 (g0 m52)
	.include "data/maps/Underwater_Route127/header.inc"
	@ MAP_UNDERWATER_ROUTE128 (g0 m53)
	.include "data/maps/Underwater_Route128/header.inc"
	@ MAP_UNDERWATER_ROUTE129 (g0 m54)
	.include "data/maps/Underwater_Route129/header.inc"
	@ MAP_UNDERWATER_ROUTE105 (g0 m55)
	.include "data/maps/Underwater_Route105/header.inc"
	@ MAP_UNDERWATER_ROUTE125 (g0 m56)
	.include "data/maps/Underwater_Route125/header.inc"
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F (g1 m0)
	.include "data/maps/LittlerootTown_BrendansHouse_1F/header.inc"
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F (g1 m1)
	.include "data/maps/LittlerootTown_BrendansHouse_2F/header.inc"
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F (g1 m2)
	.include "data/maps/LittlerootTown_MaysHouse_1F/header.inc"
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F (g1 m3)
	.include "data/maps/LittlerootTown_MaysHouse_2F/header.inc"
	@ MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB (g1 m4)
	.include "data/maps/LittlerootTown_ProfessorBirchsLab/header.inc"
	@ MAP_OLDALE_TOWN_HOUSE1 (g2 m0)
	.include "data/maps/OldaleTown_House1/header.inc"
	@ MAP_OLDALE_TOWN_HOUSE2 (g2 m1)
	.include "data/maps/OldaleTown_House2/header.inc"
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_1F (g2 m2)
	.include "data/maps/OldaleTown_PokemonCenter_1F/header.inc"
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_2F (g2 m3)
	.include "data/maps/OldaleTown_PokemonCenter_2F/header.inc"
	@ MAP_OLDALE_TOWN_MART (g2 m4)
	.include "data/maps/OldaleTown_Mart/header.inc"
	@ MAP_DEWFORD_TOWN_HOUSE1 (g3 m0)
	.include "data/maps/DewfordTown_House1/header.inc"
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_1F (g3 m1)
	.include "data/maps/DewfordTown_PokemonCenter_1F/header.inc"
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_2F (g3 m2)
	.include "data/maps/DewfordTown_PokemonCenter_2F/header.inc"
	@ MAP_DEWFORD_TOWN_GYM (g3 m3)
	.include "data/maps/DewfordTown_Gym/header.inc"
	@ MAP_DEWFORD_TOWN_HALL (g3 m4)
	.include "data/maps/DewfordTown_Hall/header.inc"
	@ MAP_DEWFORD_TOWN_HOUSE2 (g3 m5)
	.include "data/maps/DewfordTown_House2/header.inc"
	@ MAP_LAVARIDGE_TOWN_HERB_SHOP (g4 m0)
	.include "data/maps/LavaridgeTown_HerbShop/header.inc"
	@ MAP_LAVARIDGE_TOWN_GYM_1F (g4 m1)
	.include "data/maps/LavaridgeTown_Gym_1F/header.inc"
	@ MAP_LAVARIDGE_TOWN_GYM_B1F (g4 m2)
	.include "data/maps/LavaridgeTown_Gym_B1F/header.inc"
	@ MAP_LAVARIDGE_TOWN_HOUSE (g4 m3)
	.include "data/maps/LavaridgeTown_House/header.inc"
	@ MAP_LAVARIDGE_TOWN_MART (g4 m4)
	.include "data/maps/LavaridgeTown_Mart/header.inc"
	@ MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F (g4 m5)
	.include "data/maps/LavaridgeTown_PokemonCenter_1F/header.inc"
	@ MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F (g4 m6)
	.include "data/maps/LavaridgeTown_PokemonCenter_2F/header.inc"
	@ MAP_FALLARBOR_TOWN_MART (g5 m0)
	.include "data/maps/FallarborTown_Mart/header.inc"
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY (g5 m1)
	.include "data/maps/FallarborTown_BattleTentLobby/header.inc"
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR (g5 m2)
	.include "data/maps/FallarborTown_BattleTentCorridor/header.inc"
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM (g5 m3)
	.include "data/maps/FallarborTown_BattleTentBattleRoom/header.inc"
	@ MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F (g5 m4)
	.include "data/maps/FallarborTown_PokemonCenter_1F/header.inc"
	@ MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F (g5 m5)
	.include "data/maps/FallarborTown_PokemonCenter_2F/header.inc"
	@ MAP_FALLARBOR_TOWN_COZMOS_HOUSE (g5 m6)
	.include "data/maps/FallarborTown_CozmosHouse/header.inc"
	@ MAP_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE (g5 m7)
	.include "data/maps/FallarborTown_MoveRelearnersHouse/header.inc"
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY (g6 m0)
	.include "data/maps/VerdanturfTown_BattleTentLobby/header.inc"
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR (g6 m1)
	.include "data/maps/VerdanturfTown_BattleTentCorridor/header.inc"
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM (g6 m2)
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/header.inc"
	@ MAP_VERDANTURF_TOWN_MART (g6 m3)
	.include "data/maps/VerdanturfTown_Mart/header.inc"
	@ MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F (g6 m4)
	.include "data/maps/VerdanturfTown_PokemonCenter_1F/header.inc"
	@ MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F (g6 m5)
	.include "data/maps/VerdanturfTown_PokemonCenter_2F/header.inc"
	@ MAP_VERDANTURF_TOWN_WANDAS_HOUSE (g6 m6)
	.include "data/maps/VerdanturfTown_WandasHouse/header.inc"
	@ MAP_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE (g6 m7)
	.include "data/maps/VerdanturfTown_FriendshipRatersHouse/header.inc"
	@ MAP_VERDANTURF_TOWN_HOUSE (g6 m8)
	.include "data/maps/VerdanturfTown_House/header.inc"
	@ MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F (g7 m0)
	.include "data/maps/PacifidlogTown_PokemonCenter_1F/header.inc"
	@ MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F (g7 m1)
	.include "data/maps/PacifidlogTown_PokemonCenter_2F/header.inc"
	@ MAP_PACIFIDLOG_TOWN_HOUSE1 (g7 m2)
	.include "data/maps/PacifidlogTown_House1/header.inc"
	@ MAP_PACIFIDLOG_TOWN_HOUSE2 (g7 m3)
	.include "data/maps/PacifidlogTown_House2/header.inc"
	@ MAP_PACIFIDLOG_TOWN_HOUSE3 (g7 m4)
	.include "data/maps/PacifidlogTown_House3/header.inc"
	@ MAP_PACIFIDLOG_TOWN_HOUSE4 (g7 m5)
	.include "data/maps/PacifidlogTown_House4/header.inc"
	@ MAP_PACIFIDLOG_TOWN_HOUSE5 (g7 m6)
	.include "data/maps/PacifidlogTown_House5/header.inc"
	@ MAP_PETALBURG_CITY_WALLYS_HOUSE (g8 m0)
	.include "data/maps/PetalburgCity_WallysHouse/header.inc"
	@ MAP_PETALBURG_CITY_GYM (g8 m1)
	.include "data/maps/PetalburgCity_Gym/header.inc"
	@ MAP_PETALBURG_CITY_HOUSE1 (g8 m2)
	.include "data/maps/PetalburgCity_House1/header.inc"
	@ MAP_PETALBURG_CITY_HOUSE2 (g8 m3)
	.include "data/maps/PetalburgCity_House2/header.inc"
	@ MAP_PETALBURG_CITY_POKEMON_CENTER_1F (g8 m4)
	.include "data/maps/PetalburgCity_PokemonCenter_1F/header.inc"
	@ MAP_PETALBURG_CITY_POKEMON_CENTER_2F (g8 m5)
	.include "data/maps/PetalburgCity_PokemonCenter_2F/header.inc"
	@ MAP_PETALBURG_CITY_MART (g8 m6)
	.include "data/maps/PetalburgCity_Mart/header.inc"
	@ MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F (g9 m0)
	.include "data/maps/SlateportCity_SternsShipyard_1F/header.inc"
	@ MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F (g9 m1)
	.include "data/maps/SlateportCity_SternsShipyard_2F/header.inc"
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY (g9 m2)
	.include "data/maps/SlateportCity_BattleTentLobby/header.inc"
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR (g9 m3)
	.include "data/maps/SlateportCity_BattleTentCorridor/header.inc"
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM (g9 m4)
	.include "data/maps/SlateportCity_BattleTentBattleRoom/header.inc"
	@ MAP_SLATEPORT_CITY_NAME_RATERS_HOUSE (g9 m5)
	.include "data/maps/SlateportCity_NameRatersHouse/header.inc"
	@ MAP_SLATEPORT_CITY_POKEMON_FAN_CLUB (g9 m6)
	.include "data/maps/SlateportCity_PokemonFanClub/header.inc"
	@ MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F (g9 m7)
	.include "data/maps/SlateportCity_OceanicMuseum_1F/header.inc"
	@ MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_2F (g9 m8)
	.include "data/maps/SlateportCity_OceanicMuseum_2F/header.inc"
	@ MAP_SLATEPORT_CITY_HARBOR (g9 m9)
	.include "data/maps/SlateportCity_Harbor/header.inc"
	@ MAP_SLATEPORT_CITY_HOUSE (g9 m10)
	.include "data/maps/SlateportCity_House/header.inc"
	@ MAP_SLATEPORT_CITY_POKEMON_CENTER_1F (g9 m11)
	.include "data/maps/SlateportCity_PokemonCenter_1F/header.inc"
	@ MAP_SLATEPORT_CITY_POKEMON_CENTER_2F (g9 m12)
	.include "data/maps/SlateportCity_PokemonCenter_2F/header.inc"
	@ MAP_SLATEPORT_CITY_MART (g9 m13)
	.include "data/maps/SlateportCity_Mart/header.inc"
	@ MAP_MAUVILLE_CITY_GYM (g10 m0)
	.include "data/maps/MauvilleCity_Gym/header.inc"
	@ MAP_MAUVILLE_CITY_BIKE_SHOP (g10 m1)
	.include "data/maps/MauvilleCity_BikeShop/header.inc"
	@ MAP_MAUVILLE_CITY_HOUSE1 (g10 m2)
	.include "data/maps/MauvilleCity_House1/header.inc"
	@ MAP_MAUVILLE_CITY_GAME_CORNER (g10 m3)
	.include "data/maps/MauvilleCity_GameCorner/header.inc"
	@ MAP_MAUVILLE_CITY_HOUSE2 (g10 m4)
	.include "data/maps/MauvilleCity_House2/header.inc"
	@ MAP_MAUVILLE_CITY_POKEMON_CENTER_1F (g10 m5)
	.include "data/maps/MauvilleCity_PokemonCenter_1F/header.inc"
	@ MAP_MAUVILLE_CITY_POKEMON_CENTER_2F (g10 m6)
	.include "data/maps/MauvilleCity_PokemonCenter_2F/header.inc"
	@ MAP_MAUVILLE_CITY_MART (g10 m7)
	.include "data/maps/MauvilleCity_Mart/header.inc"
	@ MAP_RUSTBORO_CITY_DEVON_CORP_1F (g11 m0)
	.include "data/maps/RustboroCity_DevonCorp_1F/header.inc"
	@ MAP_RUSTBORO_CITY_DEVON_CORP_2F (g11 m1)
	.include "data/maps/RustboroCity_DevonCorp_2F/header.inc"
	@ MAP_RUSTBORO_CITY_DEVON_CORP_3F (g11 m2)
	.include "data/maps/RustboroCity_DevonCorp_3F/header.inc"
	@ MAP_RUSTBORO_CITY_GYM (g11 m3)
	.include "data/maps/RustboroCity_Gym/header.inc"
	@ MAP_RUSTBORO_CITY_POKEMON_SCHOOL (g11 m4)
	.include "data/maps/RustboroCity_PokemonSchool/header.inc"
	@ MAP_RUSTBORO_CITY_POKEMON_CENTER_1F (g11 m5)
	.include "data/maps/RustboroCity_PokemonCenter_1F/header.inc"
	@ MAP_RUSTBORO_CITY_POKEMON_CENTER_2F (g11 m6)
	.include "data/maps/RustboroCity_PokemonCenter_2F/header.inc"
	@ MAP_RUSTBORO_CITY_MART (g11 m7)
	.include "data/maps/RustboroCity_Mart/header.inc"
	@ MAP_RUSTBORO_CITY_FLAT1_1F (g11 m8)
	.include "data/maps/RustboroCity_Flat1_1F/header.inc"
	@ MAP_RUSTBORO_CITY_FLAT1_2F (g11 m9)
	.include "data/maps/RustboroCity_Flat1_2F/header.inc"
	@ MAP_RUSTBORO_CITY_HOUSE1 (g11 m10)
	.include "data/maps/RustboroCity_House1/header.inc"
	@ MAP_RUSTBORO_CITY_CUTTERS_HOUSE (g11 m11)
	.include "data/maps/RustboroCity_CuttersHouse/header.inc"
	@ MAP_RUSTBORO_CITY_HOUSE2 (g11 m12)
	.include "data/maps/RustboroCity_House2/header.inc"
	@ MAP_RUSTBORO_CITY_FLAT2_1F (g11 m13)
	.include "data/maps/RustboroCity_Flat2_1F/header.inc"
	@ MAP_RUSTBORO_CITY_FLAT2_2F (g11 m14)
	.include "data/maps/RustboroCity_Flat2_2F/header.inc"
	@ MAP_RUSTBORO_CITY_FLAT2_3F (g11 m15)
	.include "data/maps/RustboroCity_Flat2_3F/header.inc"
	@ MAP_RUSTBORO_CITY_HOUSE3 (g11 m16)
	.include "data/maps/RustboroCity_House3/header.inc"
	@ MAP_FORTREE_CITY_HOUSE1 (g12 m0)
	.include "data/maps/FortreeCity_House1/header.inc"
	@ MAP_FORTREE_CITY_GYM (g12 m1)
	.include "data/maps/FortreeCity_Gym/header.inc"
	@ MAP_FORTREE_CITY_POKEMON_CENTER_1F (g12 m2)
	.include "data/maps/FortreeCity_PokemonCenter_1F/header.inc"
	@ MAP_FORTREE_CITY_POKEMON_CENTER_2F (g12 m3)
	.include "data/maps/FortreeCity_PokemonCenter_2F/header.inc"
	@ MAP_FORTREE_CITY_MART (g12 m4)
	.include "data/maps/FortreeCity_Mart/header.inc"
	@ MAP_FORTREE_CITY_HOUSE2 (g12 m5)
	.include "data/maps/FortreeCity_House2/header.inc"
	@ MAP_FORTREE_CITY_HOUSE3 (g12 m6)
	.include "data/maps/FortreeCity_House3/header.inc"
	@ MAP_FORTREE_CITY_HOUSE4 (g12 m7)
	.include "data/maps/FortreeCity_House4/header.inc"
	@ MAP_FORTREE_CITY_HOUSE5 (g12 m8)
	.include "data/maps/FortreeCity_House5/header.inc"
	@ MAP_FORTREE_CITY_DECORATION_SHOP (g12 m9)
	.include "data/maps/FortreeCity_DecorationShop/header.inc"
	@ MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F (g13 m0)
	.include "data/maps/LilycoveCity_CoveLilyMotel_1F/header.inc"
	@ MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_2F (g13 m1)
	.include "data/maps/LilycoveCity_CoveLilyMotel_2F/header.inc"
	@ MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F (g13 m2)
	.include "data/maps/LilycoveCity_LilycoveMuseum_1F/header.inc"
	@ MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F (g13 m3)
	.include "data/maps/LilycoveCity_LilycoveMuseum_2F/header.inc"
	@ MAP_LILYCOVE_CITY_CONTEST_LOBBY (g13 m4)
	.include "data/maps/LilycoveCity_ContestLobby/header.inc"
	@ MAP_LILYCOVE_CITY_CONTEST_HALL (g13 m5)
	.include "data/maps/LilycoveCity_ContestHall/header.inc"
	@ MAP_LILYCOVE_CITY_POKEMON_CENTER_1F (g13 m6)
	.include "data/maps/LilycoveCity_PokemonCenter_1F/header.inc"
	@ MAP_LILYCOVE_CITY_POKEMON_CENTER_2F (g13 m7)
	.include "data/maps/LilycoveCity_PokemonCenter_2F/header.inc"
	@ MAP_LILYCOVE_CITY_UNUSED_MART (g13 m8)
	.include "data/maps/LilycoveCity_UnusedMart/header.inc"
	@ MAP_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB (g13 m9)
	.include "data/maps/LilycoveCity_PokemonTrainerFanClub/header.inc"
	@ MAP_LILYCOVE_CITY_HARBOR (g13 m10)
	.include "data/maps/LilycoveCity_Harbor/header.inc"
	@ MAP_LILYCOVE_CITY_MOVE_DELETERS_HOUSE (g13 m11)
	.include "data/maps/LilycoveCity_MoveDeletersHouse/header.inc"
	@ MAP_LILYCOVE_CITY_HOUSE1 (g13 m12)
	.include "data/maps/LilycoveCity_House1/header.inc"
	@ MAP_LILYCOVE_CITY_HOUSE2 (g13 m13)
	.include "data/maps/LilycoveCity_House2/header.inc"
	@ MAP_LILYCOVE_CITY_HOUSE3 (g13 m14)
	.include "data/maps/LilycoveCity_House3/header.inc"
	@ MAP_LILYCOVE_CITY_HOUSE4 (g13 m15)
	.include "data/maps/LilycoveCity_House4/header.inc"
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F (g13 m16)
	.include "data/maps/LilycoveCity_DepartmentStore_1F/header.inc"
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F (g13 m17)
	.include "data/maps/LilycoveCity_DepartmentStore_2F/header.inc"
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F (g13 m18)
	.include "data/maps/LilycoveCity_DepartmentStore_3F/header.inc"
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F (g13 m19)
	.include "data/maps/LilycoveCity_DepartmentStore_4F/header.inc"
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F (g13 m20)
	.include "data/maps/LilycoveCity_DepartmentStore_5F/header.inc"
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP (g13 m21)
	.include "data/maps/LilycoveCity_DepartmentStoreRooftop/header.inc"
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR (g13 m22)
	.include "data/maps/LilycoveCity_DepartmentStoreElevator/header.inc"
	@ MAP_MOSSDEEP_CITY_GYM (g14 m0)
	.include "data/maps/MossdeepCity_Gym/header.inc"
	@ MAP_MOSSDEEP_CITY_HOUSE1 (g14 m1)
	.include "data/maps/MossdeepCity_House1/header.inc"
	@ MAP_MOSSDEEP_CITY_HOUSE2 (g14 m2)
	.include "data/maps/MossdeepCity_House2/header.inc"
	@ MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F (g14 m3)
	.include "data/maps/MossdeepCity_PokemonCenter_1F/header.inc"
	@ MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F (g14 m4)
	.include "data/maps/MossdeepCity_PokemonCenter_2F/header.inc"
	@ MAP_MOSSDEEP_CITY_MART (g14 m5)
	.include "data/maps/MossdeepCity_Mart/header.inc"
	@ MAP_MOSSDEEP_CITY_HOUSE3 (g14 m6)
	.include "data/maps/MossdeepCity_House3/header.inc"
	@ MAP_MOSSDEEP_CITY_STEVENS_HOUSE (g14 m7)
	.include "data/maps/MossdeepCity_StevensHouse/header.inc"
	@ MAP_MOSSDEEP_CITY_HOUSE4 (g14 m8)
	.include "data/maps/MossdeepCity_House4/header.inc"
	@ MAP_MOSSDEEP_CITY_SPACE_CENTER_1F (g14 m9)
	.include "data/maps/MossdeepCity_SpaceCenter_1F/header.inc"
	@ MAP_MOSSDEEP_CITY_SPACE_CENTER_2F (g14 m10)
	.include "data/maps/MossdeepCity_SpaceCenter_2F/header.inc"
	@ MAP_MOSSDEEP_CITY_GAME_CORNER_1F (g14 m11)
	.include "data/maps/MossdeepCity_GameCorner_1F/header.inc"
	@ MAP_MOSSDEEP_CITY_GAME_CORNER_B1F (g14 m12)
	.include "data/maps/MossdeepCity_GameCorner_B1F/header.inc"
	@ MAP_SOOTOPOLIS_CITY_GYM_1F (g15 m0)
	.include "data/maps/SootopolisCity_Gym_1F/header.inc"
	@ MAP_SOOTOPOLIS_CITY_GYM_B1F (g15 m1)
	.include "data/maps/SootopolisCity_Gym_B1F/header.inc"
	@ MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F (g15 m2)
	.include "data/maps/SootopolisCity_PokemonCenter_1F/header.inc"
	@ MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F (g15 m3)
	.include "data/maps/SootopolisCity_PokemonCenter_2F/header.inc"
	@ MAP_SOOTOPOLIS_CITY_MART (g15 m4)
	.include "data/maps/SootopolisCity_Mart/header.inc"
	@ MAP_SOOTOPOLIS_CITY_HOUSE1 (g15 m5)
	.include "data/maps/SootopolisCity_House1/header.inc"
	@ MAP_SOOTOPOLIS_CITY_HOUSE2 (g15 m6)
	.include "data/maps/SootopolisCity_House2/header.inc"
	@ MAP_SOOTOPOLIS_CITY_HOUSE3 (g15 m7)
	.include "data/maps/SootopolisCity_House3/header.inc"
	@ MAP_SOOTOPOLIS_CITY_HOUSE4 (g15 m8)
	.include "data/maps/SootopolisCity_House4/header.inc"
	@ MAP_SOOTOPOLIS_CITY_HOUSE5 (g15 m9)
	.include "data/maps/SootopolisCity_House5/header.inc"
	@ MAP_SOOTOPOLIS_CITY_HOUSE6 (g15 m10)
	.include "data/maps/SootopolisCity_House6/header.inc"
	@ MAP_SOOTOPOLIS_CITY_HOUSE7 (g15 m11)
	.include "data/maps/SootopolisCity_House7/header.inc"
	@ MAP_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE (g15 m12)
	.include "data/maps/SootopolisCity_LotadAndSeedotHouse/header.inc"
	@ MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F (g15 m13)
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/header.inc"
	@ MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F (g15 m14)
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/header.inc"
	@ MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM (g16 m0)
	.include "data/maps/EverGrandeCity_SidneysRoom/header.inc"
	@ MAP_EVER_GRANDE_CITY_PHOEBES_ROOM (g16 m1)
	.include "data/maps/EverGrandeCity_PhoebesRoom/header.inc"
	@ MAP_EVER_GRANDE_CITY_GLACIAS_ROOM (g16 m2)
	.include "data/maps/EverGrandeCity_GlaciasRoom/header.inc"
	@ MAP_EVER_GRANDE_CITY_DRAKES_ROOM (g16 m3)
	.include "data/maps/EverGrandeCity_DrakesRoom/header.inc"
	@ MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM (g16 m4)
	.include "data/maps/EverGrandeCity_ChampionsRoom/header.inc"
	@ MAP_EVER_GRANDE_CITY_HALL1 (g16 m5)
	.include "data/maps/EverGrandeCity_Hall1/header.inc"
	@ MAP_EVER_GRANDE_CITY_HALL2 (g16 m6)
	.include "data/maps/EverGrandeCity_Hall2/header.inc"
	@ MAP_EVER_GRANDE_CITY_HALL3 (g16 m7)
	.include "data/maps/EverGrandeCity_Hall3/header.inc"
	@ MAP_EVER_GRANDE_CITY_HALL4 (g16 m8)
	.include "data/maps/EverGrandeCity_Hall4/header.inc"
	@ MAP_EVER_GRANDE_CITY_HALL5 (g16 m9)
	.include "data/maps/EverGrandeCity_Hall5/header.inc"
	@ MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F (g16 m10)
	.include "data/maps/EverGrandeCity_PokemonLeague_1F/header.inc"
	@ MAP_EVER_GRANDE_CITY_HALL_OF_FAME (g16 m11)
	.include "data/maps/EverGrandeCity_HallOfFame/header.inc"
	@ MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F (g16 m12)
	.include "data/maps/EverGrandeCity_PokemonCenter_1F/header.inc"
	@ MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F (g16 m13)
	.include "data/maps/EverGrandeCity_PokemonCenter_2F/header.inc"
	@ MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F (g16 m14)
	.include "data/maps/EverGrandeCity_PokemonLeague_2F/header.inc"
	@ MAP_ROUTE104_MR_BRINEYS_HOUSE (g17 m0)
	.include "data/maps/Route104_MrBrineysHouse/header.inc"
	@ MAP_ROUTE104_PRETTY_PETAL_FLOWER_SHOP (g17 m1)
	.include "data/maps/Route104_PrettyPetalFlowerShop/header.inc"
	@ MAP_ROUTE111_WINSTRATE_FAMILYS_HOUSE (g18 m0)
	.include "data/maps/Route111_WinstrateFamilysHouse/header.inc"
	@ MAP_ROUTE111_OLD_LADYS_REST_STOP (g18 m1)
	.include "data/maps/Route111_OldLadysRestStop/header.inc"
	@ MAP_ROUTE112_CABLE_CAR_STATION (g19 m0)
	.include "data/maps/Route112_CableCarStation/header.inc"
	@ MAP_MT_CHIMNEY_CABLE_CAR_STATION (g19 m1)
	.include "data/maps/MtChimney_CableCarStation/header.inc"
	@ MAP_ROUTE114_FOSSIL_MANIACS_HOUSE (g20 m0)
	.include "data/maps/Route114_FossilManiacsHouse/header.inc"
	@ MAP_ROUTE114_FOSSIL_MANIACS_TUNNEL (g20 m1)
	.include "data/maps/Route114_FossilManiacsTunnel/header.inc"
	@ MAP_ROUTE114_LANETTES_HOUSE (g20 m2)
	.include "data/maps/Route114_LanettesHouse/header.inc"
	@ MAP_ROUTE116_TUNNELERS_REST_HOUSE (g21 m0)
	.include "data/maps/Route116_TunnelersRestHouse/header.inc"
	@ MAP_ROUTE117_POKEMON_DAY_CARE (g22 m0)
	.include "data/maps/Route117_PokemonDayCare/header.inc"
	@ MAP_ROUTE121_SAFARI_ZONE_ENTRANCE (g23 m0)
	.include "data/maps/Route121_SafariZoneEntrance/header.inc"
	@ MAP_METEOR_FALLS_1F_1R (g24 m0)
	.include "data/maps/MeteorFalls_1F_1R/header.inc"
	@ MAP_METEOR_FALLS_1F_2R (g24 m1)
	.include "data/maps/MeteorFalls_1F_2R/header.inc"
	@ MAP_METEOR_FALLS_B1F_1R (g24 m2)
	.include "data/maps/MeteorFalls_B1F_1R/header.inc"
	@ MAP_METEOR_FALLS_B1F_2R (g24 m3)
	.include "data/maps/MeteorFalls_B1F_2R/header.inc"
	@ MAP_RUSTURF_TUNNEL (g24 m4)
	.include "data/maps/RusturfTunnel/header.inc"
	@ MAP_UNDERWATER_SOOTOPOLIS_CITY (g24 m5)
	.include "data/maps/Underwater_SootopolisCity/header.inc"
	@ MAP_DESERT_RUINS (g24 m6)
	.include "data/maps/DesertRuins/header.inc"
	@ MAP_GRANITE_CAVE_1F (g24 m7)
	.include "data/maps/GraniteCave_1F/header.inc"
	@ MAP_GRANITE_CAVE_B1F (g24 m8)
	.include "data/maps/GraniteCave_B1F/header.inc"
	@ MAP_GRANITE_CAVE_B2F (g24 m9)
	.include "data/maps/GraniteCave_B2F/header.inc"
	@ MAP_GRANITE_CAVE_STEVENS_ROOM (g24 m10)
	.include "data/maps/GraniteCave_StevensRoom/header.inc"
	@ MAP_PETALBURG_WOODS (g24 m11)
	.include "data/maps/PetalburgWoods/header.inc"
	@ MAP_MT_CHIMNEY (g24 m12)
	.include "data/maps/MtChimney/header.inc"
	@ MAP_JAGGED_PASS (g24 m13)
	.include "data/maps/JaggedPass/header.inc"
	@ MAP_FIERY_PATH (g24 m14)
	.include "data/maps/FieryPath/header.inc"
	@ MAP_MT_PYRE_1F (g24 m15)
	.include "data/maps/MtPyre_1F/header.inc"
	@ MAP_MT_PYRE_2F (g24 m16)
	.include "data/maps/MtPyre_2F/header.inc"
	@ MAP_MT_PYRE_3F (g24 m17)
	.include "data/maps/MtPyre_3F/header.inc"
	@ MAP_MT_PYRE_4F (g24 m18)
	.include "data/maps/MtPyre_4F/header.inc"
	@ MAP_MT_PYRE_5F (g24 m19)
	.include "data/maps/MtPyre_5F/header.inc"
	@ MAP_MT_PYRE_6F (g24 m20)
	.include "data/maps/MtPyre_6F/header.inc"
	@ MAP_MT_PYRE_EXTERIOR (g24 m21)
	.include "data/maps/MtPyre_Exterior/header.inc"
	@ MAP_MT_PYRE_SUMMIT (g24 m22)
	.include "data/maps/MtPyre_Summit/header.inc"
	@ MAP_AQUA_HIDEOUT_1F (g24 m23)
	.include "data/maps/AquaHideout_1F/header.inc"
	@ MAP_AQUA_HIDEOUT_B1F (g24 m24)
	.include "data/maps/AquaHideout_B1F/header.inc"
	@ MAP_AQUA_HIDEOUT_B2F (g24 m25)
	.include "data/maps/AquaHideout_B2F/header.inc"
	@ MAP_UNDERWATER_SEAFLOOR_CAVERN (g24 m26)
	.include "data/maps/Underwater_SeafloorCavern/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ENTRANCE (g24 m27)
	.include "data/maps/SeafloorCavern_Entrance/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM1 (g24 m28)
	.include "data/maps/SeafloorCavern_Room1/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM2 (g24 m29)
	.include "data/maps/SeafloorCavern_Room2/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM3 (g24 m30)
	.include "data/maps/SeafloorCavern_Room3/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM4 (g24 m31)
	.include "data/maps/SeafloorCavern_Room4/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM5 (g24 m32)
	.include "data/maps/SeafloorCavern_Room5/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM6 (g24 m33)
	.include "data/maps/SeafloorCavern_Room6/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM7 (g24 m34)
	.include "data/maps/SeafloorCavern_Room7/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM8 (g24 m35)
	.include "data/maps/SeafloorCavern_Room8/header.inc"
	@ MAP_SEAFLOOR_CAVERN_ROOM9 (g24 m36)
	.include "data/maps/SeafloorCavern_Room9/header.inc"
	@ MAP_CAVE_OF_ORIGIN_ENTRANCE (g24 m37)
	.include "data/maps/CaveOfOrigin_Entrance/header.inc"
	@ MAP_CAVE_OF_ORIGIN_1F (g24 m38)
	.include "data/maps/CaveOfOrigin_1F/header.inc"
	@ MAP_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1 (g24 m39)
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/header.inc"
	@ MAP_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2 (g24 m40)
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/header.inc"
	@ MAP_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3 (g24 m41)
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/header.inc"
	@ MAP_CAVE_OF_ORIGIN_B1F (g24 m42)
	.include "data/maps/CaveOfOrigin_B1F/header.inc"
	@ MAP_VICTORY_ROAD_1F (g24 m43)
	.include "data/maps/VictoryRoad_1F/header.inc"
	@ MAP_VICTORY_ROAD_B1F (g24 m44)
	.include "data/maps/VictoryRoad_B1F/header.inc"
	@ MAP_VICTORY_ROAD_B2F (g24 m45)
	.include "data/maps/VictoryRoad_B2F/header.inc"
	@ MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM (g24 m46)
	.include "data/maps/ShoalCave_LowTideEntranceRoom/header.inc"
	@ MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM (g24 m47)
	.include "data/maps/ShoalCave_LowTideInnerRoom/header.inc"
	@ MAP_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM (g24 m48)
	.include "data/maps/ShoalCave_LowTideStairsRoom/header.inc"
	@ MAP_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM (g24 m49)
	.include "data/maps/ShoalCave_LowTideLowerRoom/header.inc"
	@ MAP_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM (g24 m50)
	.include "data/maps/ShoalCave_HighTideEntranceRoom/header.inc"
	@ MAP_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM (g24 m51)
	.include "data/maps/ShoalCave_HighTideInnerRoom/header.inc"
	@ MAP_NEW_MAUVILLE_ENTRANCE (g24 m52)
	.include "data/maps/NewMauville_Entrance/header.inc"
	@ MAP_NEW_MAUVILLE_INSIDE (g24 m53)
	.include "data/maps/NewMauville_Inside/header.inc"
	@ MAP_ABANDONED_SHIP_DECK (g24 m54)
	.include "data/maps/AbandonedShip_Deck/header.inc"
	@ MAP_ABANDONED_SHIP_CORRIDORS_1F (g24 m55)
	.include "data/maps/AbandonedShip_Corridors_1F/header.inc"
	@ MAP_ABANDONED_SHIP_ROOMS_1F (g24 m56)
	.include "data/maps/AbandonedShip_Rooms_1F/header.inc"
	@ MAP_ABANDONED_SHIP_CORRIDORS_B1F (g24 m57)
	.include "data/maps/AbandonedShip_Corridors_B1F/header.inc"
	@ MAP_ABANDONED_SHIP_ROOMS_B1F (g24 m58)
	.include "data/maps/AbandonedShip_Rooms_B1F/header.inc"
	@ MAP_ABANDONED_SHIP_ROOMS2_B1F (g24 m59)
	.include "data/maps/AbandonedShip_Rooms2_B1F/header.inc"
	@ MAP_ABANDONED_SHIP_UNDERWATER1 (g24 m60)
	.include "data/maps/AbandonedShip_Underwater1/header.inc"
	@ MAP_ABANDONED_SHIP_ROOM_B1F (g24 m61)
	.include "data/maps/AbandonedShip_Room_B1F/header.inc"
	@ MAP_ABANDONED_SHIP_ROOMS2_1F (g24 m62)
	.include "data/maps/AbandonedShip_Rooms2_1F/header.inc"
	@ MAP_ABANDONED_SHIP_CAPTAINS_OFFICE (g24 m63)
	.include "data/maps/AbandonedShip_CaptainsOffice/header.inc"
	@ MAP_ABANDONED_SHIP_UNDERWATER2 (g24 m64)
	.include "data/maps/AbandonedShip_Underwater2/header.inc"
	@ MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS (g24 m65)
	.include "data/maps/AbandonedShip_HiddenFloorCorridors/header.inc"
	@ MAP_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS (g24 m66)
	.include "data/maps/AbandonedShip_HiddenFloorRooms/header.inc"
	@ MAP_ISLAND_CAVE (g24 m67)
	.include "data/maps/IslandCave/header.inc"
	@ MAP_ANCIENT_TOMB (g24 m68)
	.include "data/maps/AncientTomb/header.inc"
	@ MAP_UNDERWATER_ROUTE134 (g24 m69)
	.include "data/maps/Underwater_Route134/header.inc"
	@ MAP_UNDERWATER_SEALED_CHAMBER (g24 m70)
	.include "data/maps/Underwater_SealedChamber/header.inc"
	@ MAP_SEALED_CHAMBER_OUTER_ROOM (g24 m71)
	.include "data/maps/SealedChamber_OuterRoom/header.inc"
	@ MAP_SEALED_CHAMBER_INNER_ROOM (g24 m72)
	.include "data/maps/SealedChamber_InnerRoom/header.inc"
	@ MAP_SCORCHED_SLAB (g24 m73)
	.include "data/maps/ScorchedSlab/header.inc"
	@ MAP_AQUA_HIDEOUT_UNUSED_RUBY_MAP1 (g24 m74)
	.include "data/maps/AquaHideout_UnusedRubyMap1/header.inc"
	@ MAP_AQUA_HIDEOUT_UNUSED_RUBY_MAP2 (g24 m75)
	.include "data/maps/AquaHideout_UnusedRubyMap2/header.inc"
	@ MAP_AQUA_HIDEOUT_UNUSED_RUBY_MAP3 (g24 m76)
	.include "data/maps/AquaHideout_UnusedRubyMap3/header.inc"
	@ MAP_SKY_PILLAR_ENTRANCE (g24 m77)
	.include "data/maps/SkyPillar_Entrance/header.inc"
	@ MAP_SKY_PILLAR_OUTSIDE (g24 m78)
	.include "data/maps/SkyPillar_Outside/header.inc"
	@ MAP_SKY_PILLAR_1F (g24 m79)
	.include "data/maps/SkyPillar_1F/header.inc"
	@ MAP_SKY_PILLAR_2F (g24 m80)
	.include "data/maps/SkyPillar_2F/header.inc"
	@ MAP_SKY_PILLAR_3F (g24 m81)
	.include "data/maps/SkyPillar_3F/header.inc"
	@ MAP_SKY_PILLAR_4F (g24 m82)
	.include "data/maps/SkyPillar_4F/header.inc"
	@ MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM (g24 m83)
	.include "data/maps/ShoalCave_LowTideIceRoom/header.inc"
	@ MAP_SKY_PILLAR_5F (g24 m84)
	.include "data/maps/SkyPillar_5F/header.inc"
	@ MAP_SKY_PILLAR_TOP (g24 m85)
	.include "data/maps/SkyPillar_Top/header.inc"
	@ MAP_MAGMA_HIDEOUT_1F (g24 m86)
	.include "data/maps/MagmaHideout_1F/header.inc"
	@ MAP_MAGMA_HIDEOUT_2F_1R (g24 m87)
	.include "data/maps/MagmaHideout_2F_1R/header.inc"
	@ MAP_MAGMA_HIDEOUT_2F_2R (g24 m88)
	.include "data/maps/MagmaHideout_2F_2R/header.inc"
	@ MAP_MAGMA_HIDEOUT_3F_1R (g24 m89)
	.include "data/maps/MagmaHideout_3F_1R/header.inc"
	@ MAP_MAGMA_HIDEOUT_3F_2R (g24 m90)
	.include "data/maps/MagmaHideout_3F_2R/header.inc"
	@ MAP_MAGMA_HIDEOUT_4F (g24 m91)
	.include "data/maps/MagmaHideout_4F/header.inc"
	@ MAP_MAGMA_HIDEOUT_3F_3R (g24 m92)
	.include "data/maps/MagmaHideout_3F_3R/header.inc"
	@ MAP_MAGMA_HIDEOUT_2F_3R (g24 m93)
	.include "data/maps/MagmaHideout_2F_3R/header.inc"
	@ MAP_MIRAGE_TOWER_1F (g24 m94)
	.include "data/maps/MirageTower_1F/header.inc"
	@ MAP_MIRAGE_TOWER_2F (g24 m95)
	.include "data/maps/MirageTower_2F/header.inc"
	@ MAP_MIRAGE_TOWER_3F (g24 m96)
	.include "data/maps/MirageTower_3F/header.inc"
	@ MAP_MIRAGE_TOWER_4F (g24 m97)
	.include "data/maps/MirageTower_4F/header.inc"
	@ MAP_DESERT_UNDERPASS (g24 m98)
	.include "data/maps/DesertUnderpass/header.inc"
	@ MAP_ARTISAN_CAVE_B1F (g24 m99)
	.include "data/maps/ArtisanCave_B1F/header.inc"
	@ MAP_ARTISAN_CAVE_1F (g24 m100)
	.include "data/maps/ArtisanCave_1F/header.inc"
	@ MAP_UNDERWATER_MARINE_CAVE (g24 m101)
	.include "data/maps/Underwater_MarineCave/header.inc"
	@ MAP_MARINE_CAVE_ENTRANCE (g24 m102)
	.include "data/maps/MarineCave_Entrance/header.inc"
	@ MAP_MARINE_CAVE_END (g24 m103)
	.include "data/maps/MarineCave_End/header.inc"
	@ MAP_TERRA_CAVE_ENTRANCE (g24 m104)
	.include "data/maps/TerraCave_Entrance/header.inc"
	@ MAP_TERRA_CAVE_END (g24 m105)
	.include "data/maps/TerraCave_End/header.inc"
	@ MAP_ALTERING_CAVE (g24 m106)
	.include "data/maps/AlteringCave/header.inc"
	@ MAP_METEOR_FALLS_STEVENS_CAVE (g24 m107)
	.include "data/maps/MeteorFalls_StevensCave/header.inc"
	@ MAP_SECRET_BASE_RED_CAVE1 (g25 m0)
	.include "data/maps/SecretBase_RedCave1/header.inc"
	@ MAP_SECRET_BASE_BROWN_CAVE1 (g25 m1)
	.include "data/maps/SecretBase_BrownCave1/header.inc"
	@ MAP_SECRET_BASE_BLUE_CAVE1 (g25 m2)
	.include "data/maps/SecretBase_BlueCave1/header.inc"
	@ MAP_SECRET_BASE_YELLOW_CAVE1 (g25 m3)
	.include "data/maps/SecretBase_YellowCave1/header.inc"
	@ MAP_SECRET_BASE_TREE1 (g25 m4)
	.include "data/maps/SecretBase_Tree1/header.inc"
	@ MAP_SECRET_BASE_SHRUB1 (g25 m5)
	.include "data/maps/SecretBase_Shrub1/header.inc"
	@ MAP_SECRET_BASE_RED_CAVE2 (g25 m6)
	.include "data/maps/SecretBase_RedCave2/header.inc"
	@ MAP_SECRET_BASE_BROWN_CAVE2 (g25 m7)
	.include "data/maps/SecretBase_BrownCave2/header.inc"
	@ MAP_SECRET_BASE_BLUE_CAVE2 (g25 m8)
	.include "data/maps/SecretBase_BlueCave2/header.inc"
	@ MAP_SECRET_BASE_YELLOW_CAVE2 (g25 m9)
	.include "data/maps/SecretBase_YellowCave2/header.inc"
	@ MAP_SECRET_BASE_TREE2 (g25 m10)
	.include "data/maps/SecretBase_Tree2/header.inc"
	@ MAP_SECRET_BASE_SHRUB2 (g25 m11)
	.include "data/maps/SecretBase_Shrub2/header.inc"
	@ MAP_SECRET_BASE_RED_CAVE3 (g25 m12)
	.include "data/maps/SecretBase_RedCave3/header.inc"
	@ MAP_SECRET_BASE_BROWN_CAVE3 (g25 m13)
	.include "data/maps/SecretBase_BrownCave3/header.inc"
	@ MAP_SECRET_BASE_BLUE_CAVE3 (g25 m14)
	.include "data/maps/SecretBase_BlueCave3/header.inc"
	@ MAP_SECRET_BASE_YELLOW_CAVE3 (g25 m15)
	.include "data/maps/SecretBase_YellowCave3/header.inc"
	@ MAP_SECRET_BASE_TREE3 (g25 m16)
	.include "data/maps/SecretBase_Tree3/header.inc"
	@ MAP_SECRET_BASE_SHRUB3 (g25 m17)
	.include "data/maps/SecretBase_Shrub3/header.inc"
	@ MAP_SECRET_BASE_RED_CAVE4 (g25 m18)
	.include "data/maps/SecretBase_RedCave4/header.inc"
	@ MAP_SECRET_BASE_BROWN_CAVE4 (g25 m19)
	.include "data/maps/SecretBase_BrownCave4/header.inc"
	@ MAP_SECRET_BASE_BLUE_CAVE4 (g25 m20)
	.include "data/maps/SecretBase_BlueCave4/header.inc"
	@ MAP_SECRET_BASE_YELLOW_CAVE4 (g25 m21)
	.include "data/maps/SecretBase_YellowCave4/header.inc"
	@ MAP_SECRET_BASE_TREE4 (g25 m22)
	.include "data/maps/SecretBase_Tree4/header.inc"
	@ MAP_SECRET_BASE_SHRUB4 (g25 m23)
	.include "data/maps/SecretBase_Shrub4/header.inc"
	@ MAP_BATTLE_COLOSSEUM_2P (g25 m24)
	.include "data/maps/BattleColosseum_2P/header.inc"
	@ MAP_TRADE_CENTER (g25 m25)
	.include "data/maps/TradeCenter/header.inc"
	@ MAP_RECORD_CORNER (g25 m26)
	.include "data/maps/RecordCorner/header.inc"
	@ MAP_BATTLE_COLOSSEUM_4P (g25 m27)
	.include "data/maps/BattleColosseum_4P/header.inc"
	@ MAP_CONTEST_HALL (g25 m28)
	.include "data/maps/ContestHall/header.inc"
	@ MAP_UNUSED_CONTEST_HALL1 (g25 m29)
	.include "data/maps/UnusedContestHall1/header.inc"
	@ MAP_UNUSED_CONTEST_HALL2 (g25 m30)
	.include "data/maps/UnusedContestHall2/header.inc"
	@ MAP_UNUSED_CONTEST_HALL3 (g25 m31)
	.include "data/maps/UnusedContestHall3/header.inc"
	@ MAP_UNUSED_CONTEST_HALL4 (g25 m32)
	.include "data/maps/UnusedContestHall4/header.inc"
	@ MAP_UNUSED_CONTEST_HALL5 (g25 m33)
	.include "data/maps/UnusedContestHall5/header.inc"
	@ MAP_UNUSED_CONTEST_HALL6 (g25 m34)
	.include "data/maps/UnusedContestHall6/header.inc"
	@ MAP_CONTEST_HALL_BEAUTY (g25 m35)
	.include "data/maps/ContestHallBeauty/header.inc"
	@ MAP_CONTEST_HALL_TOUGH (g25 m36)
	.include "data/maps/ContestHallTough/header.inc"
	@ MAP_CONTEST_HALL_COOL (g25 m37)
	.include "data/maps/ContestHallCool/header.inc"
	@ MAP_CONTEST_HALL_SMART (g25 m38)
	.include "data/maps/ContestHallSmart/header.inc"
	@ MAP_CONTEST_HALL_CUTE (g25 m39)
	.include "data/maps/ContestHallCute/header.inc"
	@ MAP_INSIDE_OF_TRUCK through subsequent unstructured map headers
	.include "data/maps/InsideOfTruck/header.inc"
	@ MAP_SS_TIDAL_CORRIDOR (g25 m41)
	.include "data/maps/SSTidalCorridor/header.inc"
	@ MAP_SS_TIDAL_LOWER_DECK (g25 m42)
	.include "data/maps/SSTidalLowerDeck/header.inc"
	@ MAP_SS_TIDAL_ROOMS (g25 m43)
	.include "data/maps/SSTidalRooms/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE01 (g25 m44)
	.include "data/maps/BattlePyramidSquare01/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE02 (g25 m45)
	.include "data/maps/BattlePyramidSquare02/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE03 (g25 m46)
	.include "data/maps/BattlePyramidSquare03/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE04 (g25 m47)
	.include "data/maps/BattlePyramidSquare04/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE05 (g25 m48)
	.include "data/maps/BattlePyramidSquare05/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE06 (g25 m49)
	.include "data/maps/BattlePyramidSquare06/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE07 (g25 m50)
	.include "data/maps/BattlePyramidSquare07/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE08 (g25 m51)
	.include "data/maps/BattlePyramidSquare08/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE09 (g25 m52)
	.include "data/maps/BattlePyramidSquare09/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE10 (g25 m53)
	.include "data/maps/BattlePyramidSquare10/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE11 (g25 m54)
	.include "data/maps/BattlePyramidSquare11/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE12 (g25 m55)
	.include "data/maps/BattlePyramidSquare12/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE13 (g25 m56)
	.include "data/maps/BattlePyramidSquare13/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE14 (g25 m57)
	.include "data/maps/BattlePyramidSquare14/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE15 (g25 m58)
	.include "data/maps/BattlePyramidSquare15/header.inc"
	@ MAP_BATTLE_PYRAMID_SQUARE16 (g25 m59)
	.include "data/maps/BattlePyramidSquare16/header.inc"
	@ MAP_UNION_ROOM (g25 m60)
	.include "data/maps/UnionRoom/header.inc"
	@ MAP_SAFARI_ZONE_NORTHWEST (g26 m0)
	.include "data/maps/SafariZone_Northwest/header.inc"
	@ MAP_SAFARI_ZONE_NORTH (g26 m1)
	.include "data/maps/SafariZone_North/header.inc"
	@ MAP_SAFARI_ZONE_SOUTHWEST (g26 m2)
	.include "data/maps/SafariZone_Southwest/header.inc"
	@ MAP_SAFARI_ZONE_SOUTH (g26 m3)
	.include "data/maps/SafariZone_South/header.inc"
	.include "data/maps/BattleFrontier_OutsideWest/header.inc"
	.include "data/maps/BattleFrontier_BattleTowerLobby/header.inc"
	.include "data/maps/BattleFrontier_BattleTowerElevator/header.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor/header.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom/header.inc"
	.include "data/maps/SouthernIsland_Exterior/header.inc"
	.include "data/maps/SouthernIsland_Interior/header.inc"
	.include "data/maps/SafariZone_RestHouse/header.inc"
	.include "data/maps/SafariZone_Northeast/header.inc"
	.include "data/maps/SafariZone_Southeast/header.inc"
	.include "data/maps/BattleFrontier_OutsideEast/header.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/header.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiCorridor/header.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/header.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/header.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/header.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/header.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/header.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/header.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/header.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/header.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/header.inc"
	.include "data/maps/BattleFrontier_BattlePyramidFloor/header.inc"
	.include "data/maps/BattleFrontier_BattlePyramidTop/header.inc"
	.include "data/maps/BattleFrontier_BattleArenaLobby/header.inc"
	.include "data/maps/BattleFrontier_BattleArenaCorridor/header.inc"
	.include "data/maps/BattleFrontier_BattleArenaBattleRoom/header.inc"
	.include "data/maps/BattleFrontier_BattleFactoryLobby/header.inc"
	.include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/header.inc"
	.include "data/maps/BattleFrontier_BattleFactoryBattleRoom/header.inc"
	@ MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY (g26 m34)
	.include "data/maps/BattleFrontier_BattlePikeLobby/header.inc"
	@ MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR (g26 m35)
	.include "data/maps/BattleFrontier_BattlePikeCorridor/header.inc"
	@ MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM (g26 m36)
	.include "data/maps/BattleFrontier_BattlePikeThreePathRoom/header.inc"
	@ MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL (g26 m37)
	.include "data/maps/BattleFrontier_BattlePikeRoomNormal/header.inc"
	@ MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_FINAL (g26 m38)
	.include "data/maps/BattleFrontier_BattlePikeRoomFinal/header.inc"
	@ MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS (g26 m39)
	.include "data/maps/BattleFrontier_BattlePikeRoomWildMons/header.inc"
	@ MAP_BATTLE_FRONTIER_RANKING_HALL (g26 m40)
	.include "data/maps/BattleFrontier_RankingHall/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE1 (g26 m41)
	.include "data/maps/BattleFrontier_Lounge1/header.inc"
	@ MAP_BATTLE_FRONTIER_EXCHANGE_SERVICE_CORNER (g26 m42)
	.include "data/maps/BattleFrontier_ExchangeServiceCorner/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE2 (g26 m43)
	.include "data/maps/BattleFrontier_Lounge2/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE3 (g26 m44)
	.include "data/maps/BattleFrontier_Lounge3/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE4 (g26 m45)
	.include "data/maps/BattleFrontier_Lounge4/header.inc"
	@ MAP_BATTLE_FRONTIER_SCOTTS_HOUSE (g26 m46)
	.include "data/maps/BattleFrontier_ScottsHouse/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE5 (g26 m47)
	.include "data/maps/BattleFrontier_Lounge5/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE6 (g26 m48)
	.include "data/maps/BattleFrontier_Lounge6/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE7 (g26 m49)
	.include "data/maps/BattleFrontier_Lounge7/header.inc"
	@ MAP_BATTLE_FRONTIER_RECEPTION_GATE (g26 m50)
	.include "data/maps/BattleFrontier_ReceptionGate/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE8 (g26 m51)
	.include "data/maps/BattleFrontier_Lounge8/header.inc"
	@ MAP_BATTLE_FRONTIER_LOUNGE9 (g26 m52)
	.include "data/maps/BattleFrontier_Lounge9/header.inc"
	@ MAP_BATTLE_FRONTIER_POKEMON_CENTER_1F (g26 m53)
	.include "data/maps/BattleFrontier_PokemonCenter_1F/header.inc"
	@ MAP_BATTLE_FRONTIER_POKEMON_CENTER_2F (g26 m54)
	.include "data/maps/BattleFrontier_PokemonCenter_2F/header.inc"
	@ MAP_BATTLE_FRONTIER_MART (g26 m55)
	.include "data/maps/BattleFrontier_Mart/header.inc"
	@ MAP_FARAWAY_ISLAND_ENTRANCE (g26 m56)
	.include "data/maps/FarawayIsland_Entrance/header.inc"
	@ MAP_FARAWAY_ISLAND_INTERIOR (g26 m57)
	.include "data/maps/FarawayIsland_Interior/header.inc"
	@ MAP_BIRTH_ISLAND_EXTERIOR (g26 m58)
	.include "data/maps/BirthIsland_Exterior/header.inc"
	@ MAP_BIRTH_ISLAND_HARBOR (g26 m59)
	.include "data/maps/BirthIsland_Harbor/header.inc"
	@ MAP_TRAINER_HILL_ENTRANCE (g26 m60)
	.include "data/maps/TrainerHill_Entrance/header.inc"
	@ MAP_TRAINER_HILL_1F (g26 m61)
	.include "data/maps/TrainerHill_1F/header.inc"
	@ MAP_TRAINER_HILL_2F (g26 m62)
	.include "data/maps/TrainerHill_2F/header.inc"
	@ MAP_TRAINER_HILL_3F (g26 m63)
	.include "data/maps/TrainerHill_3F/header.inc"
	@ MAP_TRAINER_HILL_4F (g26 m64)
	.include "data/maps/TrainerHill_4F/header.inc"
	@ MAP_TRAINER_HILL_ROOF (g26 m65)
	.include "data/maps/TrainerHill_Roof/header.inc"
	.incbin "baserom_jp.gba", 0x45DC94, 0xBD0
	.4byte BattleFrontier_BattlePikeLobby
	.4byte BattleFrontier_BattlePikeCorridor
	.4byte BattleFrontier_BattlePikeThreePathRoom
	.4byte BattleFrontier_BattlePikeRoomNormal
	.4byte BattleFrontier_BattlePikeRoomFinal
	.4byte BattleFrontier_BattlePikeRoomWildMons
	.4byte BattleFrontier_RankingHall
	.4byte BattleFrontier_Lounge1
	.4byte BattleFrontier_ExchangeServiceCorner
	.4byte BattleFrontier_Lounge2
	.4byte BattleFrontier_Lounge3
	.4byte BattleFrontier_Lounge4
	.4byte BattleFrontier_ScottsHouse
	.4byte BattleFrontier_Lounge5
	.4byte BattleFrontier_Lounge6
	.4byte BattleFrontier_Lounge7
	.4byte BattleFrontier_ReceptionGate
	.4byte BattleFrontier_Lounge8
	.4byte BattleFrontier_Lounge9
	.4byte BattleFrontier_PokemonCenter_1F
	.4byte BattleFrontier_PokemonCenter_2F
	.4byte BattleFrontier_Mart
	.4byte FarawayIsland_Entrance
	.4byte FarawayIsland_Interior
	.4byte BirthIsland_Exterior
	.4byte BirthIsland_Harbor
	.4byte TrainerHill_Entrance
	.4byte TrainerHill_1F
	.4byte TrainerHill_2F
	.4byte TrainerHill_3F
	.4byte TrainerHill_4F
	.4byte TrainerHill_Roof
	.incbin "baserom_jp.gba", 0x45E8E4, 0xB4

	.globl gUnknown_845E998
gUnknown_845E998: @ 0x845E998
	.globl gUnknown_845E998
gUnknown_845E998: @ 0x0845E998
	.incbin "baserom_jp.gba", 0x45E998, 0x88
	.globl gMapGroups
	.set gMapGroups, gUnknown_845E998
	.include "data/maps/LittlerootTown/connections.inc"
	.include "data/maps/OldaleTown/connections.inc"
	.include "data/maps/DewfordTown/connections.inc"
	.include "data/maps/LavaridgeTown/connections.inc"
	.include "data/maps/FallarborTown/connections.inc"
	.include "data/maps/VerdanturfTown/connections.inc"
	.include "data/maps/PacifidlogTown/connections.inc"
	.include "data/maps/PetalburgCity/connections.inc"
	.include "data/maps/SlateportCity/connections.inc"
	.include "data/maps/MauvilleCity/connections.inc"
	.include "data/maps/RustboroCity/connections.inc"
	.include "data/maps/FortreeCity/connections.inc"
	.include "data/maps/LilycoveCity/connections.inc"
	.include "data/maps/MossdeepCity/connections.inc"
	.incbin "baserom_jp.gba", 0x45EC10, 0x8
	.include "data/maps/EverGrandeCity/connections.inc"
	.include "data/maps/Route101/connections.inc"
	.include "data/maps/Route102/connections.inc"
	.include "data/maps/Route103/connections.inc"
	.include "data/maps/Route104/connections.inc"
	.include "data/maps/Route105/connections.inc"
	.include "data/maps/Route106/connections.inc"
	.include "data/maps/Route107/connections.inc"
	.include "data/maps/Route108/connections.inc"
	.include "data/maps/Route109/connections.inc"
	.include "data/maps/Route110/connections.inc"
	.include "data/maps/Route111/connections.inc"
	.include "data/maps/Route112/connections.inc"
	.include "data/maps/Route113/connections.inc"
	.include "data/maps/Route114/connections.inc"
	.include "data/maps/Route115/connections.inc"
	.include "data/maps/Route116/connections.inc"
	.include "data/maps/Route117/connections.inc"
	.include "data/maps/Route118/connections.inc"
	.include "data/maps/Route119/connections.inc"
	.include "data/maps/Route120/connections.inc"
	.include "data/maps/Route121/connections.inc"
	.include "data/maps/Route122/connections.inc"
	.include "data/maps/Route123/connections.inc"
	.include "data/maps/Route124/connections.inc"
	.include "data/maps/Route125/connections.inc"
	.include "data/maps/Route126/connections.inc"
	.include "data/maps/Route127/connections.inc"
	.include "data/maps/Route128/connections.inc"
	.include "data/maps/Route129/connections.inc"
	.include "data/maps/Route130/connections.inc"
	.include "data/maps/Route131/connections.inc"
	.include "data/maps/Route132/connections.inc"
	.include "data/maps/Route133/connections.inc"
	.include "data/maps/Route134/connections.inc"
	@ 0x0845F144: Underwater_Route105 connection list and header.
	.include "data/maps/Underwater_Route105/connections.inc"
	@ 0x0845F158: Underwater_Route124 connection list and header.
	.include "data/maps/Underwater_Route124/connections.inc"
	@ 0x0845F178: Underwater_Route125 connection list and header.
	.include "data/maps/Underwater_Route125/connections.inc"
	@ 0x0845F18C: Underwater_Route126 connection list and header.
	.include "data/maps/Underwater_Route126/connections.inc"
	@ 0x0845F1B8: Underwater_Route127 connection list and header.
	.include "data/maps/Underwater_Route127/connections.inc"
	@ 0x0845F1E4: Underwater_Route128 connection list and header.
	.include "data/maps/Underwater_Route128/connections.inc"
	@ 0x0845F204: Underwater_Route129 connection list and header.
	.include "data/maps/Underwater_Route129/connections.inc"
	@ 0x0845F218: Safari Zone Northwest connection list and header.
	.include "data/maps/SafariZone_Northwest/connections.inc"
	@ 0x0845F238: Safari Zone North connection list and header.
	.include "data/maps/SafariZone_North/connections.inc"
	@ 0x0845F264: Safari Zone Southwest connection list and header.
	.include "data/maps/SafariZone_Southwest/connections.inc"
	@ 0x0845F284: Safari Zone South connection list and header.
	.include "data/maps/SafariZone_South/connections.inc"
	.include "data/maps/SafariZone_Northeast/connections.inc"
	.include "data/maps/SafariZone_Southeast/connections.inc"
	.include "data/maps/BattleFrontier_OutsideWest/connections.inc"
	.include "data/maps/BattleFrontier_OutsideEast/connections.inc"

	.globl sDummyConnectionFlags
sDummyConnectionFlags: @ 0x845F318
	.incbin "baserom_jp.gba", 0x45f318, 0x4

	.globl sTileBitAttributes
sTileBitAttributes: @ 0x845F31C
	.incbin "graphics/misc/sTileBitAttributes.bin"

	.globl sDoorOpenAnimFrames
sDoorOpenAnimFrames: @ 0x846F3AC
	.incbin "graphics/misc/sDoorOpenAnimFrames.bin"

	.globl sDoorCloseAnimFrames
sDoorCloseAnimFrames: @ 0x846F3C0
	.incbin "graphics/misc/sDoorCloseAnimFrames.bin"

	.globl sBigDoorOpenAnimFrames
sBigDoorOpenAnimFrames: @ 0x846F3D4
	.incbin "graphics/misc/sBigDoorOpenAnimFrames.bin"

	.globl sDoorAnimGraphicsTable
sDoorAnimGraphicsTable: @ 0x846F594
	.hword 0x0021
	.byte 0x00, 0x01
	.4byte 0x084603AC, 0x0846F3FC
	.hword 0x0061
	.byte 0x01, 0x01
	.4byte 0x084606CC, 0x0846F404
	.hword 0x01CD
	.byte 0x01, 0x01
	.4byte 0x084609CC, 0x0846F40C
	.hword 0x0041
	.byte 0x01, 0x01
	.4byte 0x08460CCC, 0x0846F414
	.hword 0x0248
	.byte 0x00, 0x01
	.4byte 0x0845F40C, 0x0846F41C
	.hword 0x0249
	.byte 0x00, 0x01
	.4byte 0x0845F72C, 0x0846F424
	.hword 0x022F
	.byte 0x00, 0x01
	.4byte 0x08460FCC, 0x0846F42C
	.hword 0x021F
	.byte 0x00, 0x01
	.4byte 0x084612EC, 0x0846F434
	.hword 0x02A5
	.byte 0x00, 0x01
	.4byte 0x0845FA4C, 0x0846F43C
	.hword 0x0287
	.byte 0x00, 0x01
	.4byte 0x0846160C, 0x0846F44C
	.hword 0x02AC
	.byte 0x00, 0x01
	.4byte 0x084674EC, 0x0846F48C
	.hword 0x03A1
	.byte 0x00, 0x01
	.4byte 0x0846780C, 0x0846F494
	.hword 0x02DC
	.byte 0x00, 0x01
	.4byte 0x08467B2C, 0x0846F484
	.hword 0x0225
	.byte 0x00, 0x01
	.4byte 0x08467E4C, 0x0846F47C
	.hword 0x01DB
	.byte 0x01, 0x01
	.4byte 0x0846816C, 0x0846F4A4
	.hword 0x0246
	.byte 0x00, 0x01
	.4byte 0x0845FD6C, 0x0846F444
	.hword 0x028E
	.byte 0x00, 0x01
	.4byte 0x0846008C, 0x0846F49C
	.hword 0x02A1
	.byte 0x00, 0x01
	.4byte 0x0846848C, 0x0846F454
	.hword 0x021C
	.byte 0x00, 0x01
	.4byte 0x084687AC, 0x0846F46C
	.hword 0x021E
	.byte 0x00, 0x01
	.4byte 0x08468ACC, 0x0846F474
	.hword 0x021D
	.byte 0x01, 0x01
	.4byte 0x08468DEC, 0x0846F45C
	.hword 0x021A
	.byte 0x00, 0x01
	.4byte 0x0846910C, 0x0846F464
	.hword 0x0224
	.byte 0x00, 0x01
	.4byte 0x0846942C, 0x0846F4AC
	.hword 0x0289
	.byte 0x00, 0x01
	.4byte 0x0846974C, 0x0846F4B4
	.hword 0x030C
	.byte 0x01, 0x01
	.4byte 0x08469A6C, 0x0846F4BC
	.hword 0x032D
	.byte 0x01, 0x01
	.4byte 0x08469D8C, 0x0846F4C4
	.hword 0x02ED
	.byte 0x01, 0x01
	.4byte 0x0846A0AC, 0x0846F4CC
	.hword 0x0264
	.byte 0x01, 0x01
	.4byte 0x0846A3CC, 0x0846F4D4
	.hword 0x022B
	.byte 0x00, 0x01
	.4byte 0x0846A6EC, 0x0846F4DC
	.hword 0x02F7
	.byte 0x00, 0x01
	.4byte 0x0846AA0C, 0x0846F4E4
	.hword 0x0297
	.byte 0x00, 0x01
	.4byte 0x0846AD2C, 0x0846F4EC
	.hword 0x0285
	.byte 0x01, 0x01
	.4byte 0x0846B04C, 0x0846F4F4
	.hword 0x025D
	.byte 0x01, 0x01
	.4byte 0x0846B36C, 0x0846F4FC
	.hword 0x020E
	.byte 0x01, 0x01
	.4byte 0x0846B68C, 0x0846F504
	.hword 0x03B0
	.byte 0x01, 0x01
	.4byte 0x0846B9AC, 0x0846F50C
	.hword 0x028A
	.byte 0x01, 0x01
	.4byte 0x0846BCCC, 0x0846F514
	.hword 0x0263
	.byte 0x01, 0x01
	.4byte 0x0846BFEC, 0x0846F51C
	.hword 0x0329
	.byte 0x01, 0x01
	.4byte 0x0846C30C, 0x0846F524
	.hword 0x0291
	.byte 0x00, 0x01
	.4byte 0x0846C62C, 0x0846F52C
	.hword 0x021B
	.byte 0x02, 0x01
	.4byte 0x0846C94C, 0x0846F534
	.hword 0x0209
	.byte 0x01, 0x01
	.4byte 0x0846CC6C, 0x0846F53C
	.hword 0x0219
	.byte 0x00, 0x01
	.4byte 0x0846CF8C, 0x0846F544
	.hword 0x0393
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x03D4
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x036C
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x025E
	.byte 0x01, 0x01
	.4byte 0x0846D6AC, 0x0846F554
	.hword 0x02AD
	.byte 0x01, 0x02
	.4byte 0x0846D9CC, 0x0846F55C
	.hword 0x03FC
	.byte 0x00, 0x01
	.4byte 0x0846DFEC, 0x0846F56C
	.hword 0x0396
	.byte 0x01, 0x01
	.4byte 0x0846E30C, 0x0846F56C
	.hword 0x020A
	.byte 0x01, 0x01
	.4byte 0x0846E62C, 0x0846F574
	.hword 0x026B
	.byte 0x01, 0x01
	.4byte 0x0846E94C, 0x0846F57C
	.hword 0x032C
	.byte 0x01, 0x01
	.4byte 0x0846ED6C, 0x0846F584
	.hword 0x0383
	.byte 0x01, 0x01
	.4byte 0x0846F08C, 0x0846F58C
	.hword 0x0000
	.byte 0x00, 0x00
	.4byte 0x00000000, 0x00000000

	.globl sForcedMovementTestFuncs
sForcedMovementTestFuncs: @ 0x846F81C
	.4byte MetatileBehavior_IsTrickHouseSlipperyFloor + 1, MetatileBehavior_IsIce + 1, MetatileBehavior_IsWalkSouth + 1, MetatileBehavior_IsWalkNorth + 1
	.4byte MetatileBehavior_IsWalkWest + 1, MetatileBehavior_IsWalkEast + 1, MetatileBehavior_IsSouthwardCurrent + 1, MetatileBehavior_IsNorthwardCurrent + 1
	.4byte MetatileBehavior_IsWestwardCurrent + 1, MetatileBehavior_IsEastwardCurrent + 1, MetatileBehavior_IsSlideSouth + 1, MetatileBehavior_IsSlideNorth + 1
	.4byte MetatileBehavior_IsSlideWest + 1, MetatileBehavior_IsSlideEast + 1, MetatileBehavior_IsWaterfall + 1, MetatileBehavior_IsSecretBaseJumpMat + 1
	.4byte MetatileBehavior_IsSecretBaseSpinMat + 1, MetatileBehavior_IsMuddySlope + 1

	.globl sForcedMovementFuncs
sForcedMovementFuncs: @ 0x846F864
	.4byte ForcedMovement_None + 1, ForcedMovement_Slip + 1, ForcedMovement_Slip + 1, ForcedMovement_WalkSouth + 1
	.4byte ForcedMovement_WalkNorth + 1, ForcedMovement_WalkWest + 1, ForcedMovement_WalkEast + 1, ForcedMovement_PushedSouthByCurrent + 1
	.4byte ForcedMovement_PushedNorthByCurrent + 1, ForcedMovement_PushedWestByCurrent + 1, ForcedMovement_PushedEastByCurrent + 1, ForcedMovement_SlideSouth + 1
	.4byte ForcedMovement_SlideNorth + 1, ForcedMovement_SlideWest + 1, ForcedMovement_SlideEast + 1, ForcedMovement_PushedSouthByCurrent + 1
	.4byte ForcedMovement_MatJump + 1, ForcedMovement_MatSpin + 1, ForcedMovement_MuddySlope + 1

	.globl sPlayerNotOnBikeFuncs
sPlayerNotOnBikeFuncs: @ 0x846F8B0
	.4byte PlayerNotOnBikeNotMoving + 1, PlayerNotOnBikeTurningInPlace + 1, PlayerNotOnBikeMoving + 1

	.globl sAcroBikeTrickMetatiles
sAcroBikeTrickMetatiles: @ 0x846F8BC
	.4byte MetatileBehavior_IsBumpySlope + 1, MetatileBehavior_IsIsolatedVerticalRail + 1, MetatileBehavior_IsIsolatedHorizontalRail + 1, MetatileBehavior_IsVerticalRail + 1, MetatileBehavior_IsHorizontalRail + 1

	.globl sAcroBikeTrickCollisionTypes
sAcroBikeTrickCollisionTypes: @ 0x846F8D0
	.byte 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00, 0x00

	.globl sPlayerAvatarTransitionFuncs
sPlayerAvatarTransitionFuncs: @ 0x846F8D8
	.4byte PlayerAvatarTransition_Normal + 1, PlayerAvatarTransition_MachBike + 1, PlayerAvatarTransition_AcroBike + 1, PlayerAvatarTransition_Surfing + 1
	.4byte PlayerAvatarTransition_Underwater + 1, PlayerAvatarTransition_ReturnToField + 1, PlayerAvatarTransition_Dummy + 1, PlayerAvatarTransition_Dummy + 1

	.globl sArrowWarpMetatileBehaviorChecks
sArrowWarpMetatileBehaviorChecks: @ 0x846F8F8
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1, MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

	.globl gUnknown_846F908
gUnknown_846F908: @ 0x846F908
	.incbin "baserom_jp.gba", 0x46f908, 0x10

	.globl gUnknown_846F918
gUnknown_846F918: @ 0x846F918
	.incbin "baserom_jp.gba", 0x46f918, 0x10

	.globl gUnknown_846F928
gUnknown_846F928: @ 0x846F928
	.incbin "baserom_jp.gba", 0x46f928, 0x2

	.globl gUnknown_846F92A
gUnknown_846F92A: @ 0x846F92A
	.incbin "baserom_jp.gba", 0x46f92a, 0x2

	.globl gUnknown_846F92C
gUnknown_846F92C: @ 0x846F92C
	.incbin "baserom_jp.gba", 0x46f92c, 0x14

	.globl sArrowWarpMetatileBehaviorChecks2
sArrowWarpMetatileBehaviorChecks2: @ 0x846F940
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1, MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

	.globl gUnknown_846F950
gUnknown_846F950: @ 0x846F950
	.incbin "baserom_jp.gba", 0x46f950, 0xc

	.globl gUnknown_846F95C
gUnknown_846F95C: @ 0x846F95C
	.incbin "baserom_jp.gba", 0x46f95c, 0x4

	.globl sPlayerAvatarSecretBaseMatSpin
sPlayerAvatarSecretBaseMatSpin: @ 0x846F960
	.4byte PlayerAvatar_SecretBaseMatSpinStep0 + 1, PlayerAvatar_SecretBaseMatSpinStep1 + 1, PlayerAvatar_SecretBaseMatSpinStep2 + 1, PlayerAvatar_SecretBaseMatSpinStep3 + 1

	.globl gUnknown_846F970
gUnknown_846F970: @ 0x846F970
	.incbin "baserom_jp.gba", 0x46f970, 0x4

	.globl gUnknown_846F974
gUnknown_846F974: @ 0x846F974
	.incbin "baserom_jp.gba", 0x46f974, 0x8

	.globl sFishingStateFuncs
sFishingStateFuncs: @ 0x846F97C
	.4byte Fishing_Init + 1, Fishing_GetRodOut + 1, Fishing_WaitBeforeDots + 1, Fishing_InitDots + 1, Fishing_ShowDots + 1, Fishing_CheckForBite + 1, Fishing_GotBite + 1, Fishing_WaitForA + 1
	.4byte Fishing_CheckMoreDots + 1, Fishing_MonOnHook + 1, Fishing_StartEncounter + 1, Fishing_NotEvenNibble + 1, Fishing_GotAway + 1, Fishing_NoMon + 1, Fishing_PutRodAway + 1, Fishing_EndNoMon + 1

	.globl gUnknown_846F9BC
gUnknown_846F9BC: @ 0x846F9BC
	.incbin "baserom_jp.gba", 0x46f9bc, 0x6

	.globl gUnknown_846F9C2
gUnknown_846F9C2: @ 0x846F9C2
	.incbin "baserom_jp.gba", 0x46f9c2, 0x6
