#include "constants/global.h"
#include "constants/event_bg.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/secret_bases.h"
#include "constants/trainer_types.h"
#include "constants/berry.h"
#include "constants/vars.h"
#include "constants/weather.h"

#define NULL 0

.include "sound/MPlayDef.s"
	.section .rodata.data_b2d_mid26_before_tileset_anims_data
	.include "asm/macros.inc"

#include "constants/tms_hms.inc"

	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.section .rodata.data_b2d_mid26_after_tileset_anims_data_before_palette_static_data

	.section .rodata.data_b2d_mid26_after_palette_static_data_before_sound_fanfare_data

	.section .rodata.data_b2d_mid26_after_sound_fanfare_data_before_battle_anim_oam_data

	.section .rodata.data_b2d_mid26_after_battle_anim_background_data_before_battle_anim_script_cmd_data

	.section .rodata.data_b2d_mid26_after_battle_anim_script_cmd_data_before_battle_anim_mons_static_data

	.section .rodata.data_b2d_mid26_after_battle_anim_mons_static_data_before_battle_anim_status_effects

	.include "data/maps/PetalburgCity/events.inc"
	.include "data/maps/SlateportCity/events.inc"
	.include "data/maps/MauvilleCity/events.inc"
	.include "data/maps/RustboroCity/events.inc"
	.include "data/maps/FortreeCity/events.inc"
	.include "data/maps/LilycoveCity/events.inc"
	.include "data/maps/MossdeepCity/events.inc"
	.include "data/maps/SootopolisCity/events.inc"
	.include "data/maps/EverGrandeCity/events.inc"
	.include "data/maps/LittlerootTown/events.inc"
	.include "data/maps/OldaleTown/events.inc"
	.include "data/maps/DewfordTown/events.inc"
	.include "data/maps/LavaridgeTown/events.inc"
	.include "data/maps/FallarborTown/events.inc"
	.include "data/maps/VerdanturfTown/events.inc"
	.include "data/maps/PacifidlogTown/events.inc"
	.include "data/maps/Route101/events.inc"
	.include "data/maps/Route102/events.inc"
	.include "data/maps/Route103/events.inc"
	.include "data/maps/Route104/events.inc"
	.include "data/maps/Route105/events.inc"
	.include "data/maps/Route106/events.inc"
	.include "data/maps/Route107/events.inc"
	.include "data/maps/Route108/events.inc"
	.include "data/maps/Route109/events.inc"
	.include "data/maps/Route110/events.inc"
	.include "data/maps/Route111/events.inc"
	.include "data/maps/Route112/events.inc"
	.include "data/maps/Route113/events.inc"
	.include "data/maps/Route114/events.inc"
	.include "data/maps/Route115/events.inc"
	.include "data/maps/Route116/events.inc"
	.include "data/maps/Route117/events.inc"
	.include "data/maps/Route118/events.inc"
	.include "data/maps/Route119/events.inc"
	.include "data/maps/Route120/events.inc"
	.include "data/maps/Route121/events.inc"
	.include "data/maps/Route122/events.inc"
	.include "data/maps/Route123/events.inc"

	.include "data/maps/Route124/events.inc"
	.include "data/maps/Route125/events.inc"
	.include "data/maps/Route126/events.inc"
	.include "data/maps/Route127/events.inc"
	.include "data/maps/Route128/events.inc"
	.include "data/maps/Route129/events.inc"
	.include "data/maps/Route130/events.inc"
	.include "data/maps/Route131/events.inc"
	.include "data/maps/Route132/events.inc"
	.include "data/maps/Route133/events.inc"
	.include "data/maps/Route134/events.inc"
	.include "data/maps/Underwater_Route124/events.inc"
	.include "data/maps/Underwater_Route126/events.inc"
	.include "data/maps/Underwater_Route127/events.inc"
	.include "data/maps/Underwater_Route128/events.inc"
	.include "data/maps/Underwater_Route129/events.inc"
	.include "data/maps/Underwater_Route105/events.inc"
	.include "data/maps/Underwater_Route125/events.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_1F/events.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_2F/events.inc"
	.include "data/maps/LittlerootTown_MaysHouse_1F/events.inc"
	.include "data/maps/LittlerootTown_MaysHouse_2F/events.inc"
	.include "data/maps/LittlerootTown_ProfessorBirchsLab/events.inc"
	.include "data/maps/OldaleTown_House1/events.inc"
	.include "data/maps/OldaleTown_House2/events.inc"
	.include "data/maps/OldaleTown_PokemonCenter_1F/events.inc"
	.include "data/maps/OldaleTown_PokemonCenter_2F/events.inc"
	.include "data/maps/OldaleTown_Mart/events.inc"
	.include "data/maps/DewfordTown_House1/events.inc"
	.include "data/maps/DewfordTown_PokemonCenter_1F/events.inc"
	.include "data/maps/DewfordTown_PokemonCenter_2F/events.inc"
	.include "data/maps/DewfordTown_Gym/events.inc"
	.include "data/maps/DewfordTown_Hall/events.inc"
	.include "data/maps/DewfordTown_House2/events.inc"
	.include "data/maps/LavaridgeTown_HerbShop/events.inc"
	.include "data/maps/LavaridgeTown_Gym_1F/events.inc"
	.include "data/maps/LavaridgeTown_Gym_B1F/events.inc"
	.include "data/maps/LavaridgeTown_House/events.inc"
	.include "data/maps/LavaridgeTown_Mart/events.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_1F/events.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_2F/events.inc"
	.include "data/maps/FallarborTown_Mart/events.inc"
	.include "data/maps/FallarborTown_BattleTentLobby/events.inc"
	.include "data/maps/FallarborTown_BattleTentCorridor/events.inc"
	.include "data/maps/FallarborTown_BattleTentBattleRoom/events.inc"
	.include "data/maps/FallarborTown_PokemonCenter_1F/events.inc"
	.include "data/maps/FallarborTown_PokemonCenter_2F/events.inc"
	.include "data/maps/FallarborTown_CozmosHouse/events.inc"
	.include "data/maps/FallarborTown_MoveRelearnersHouse/events.inc"
	.include "data/maps/VerdanturfTown_BattleTentLobby/events.inc"
	.include "data/maps/VerdanturfTown_BattleTentCorridor/events.inc"
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/events.inc"
	.include "data/maps/VerdanturfTown_Mart/events.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_1F/events.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_2F/events.inc"
	.include "data/maps/VerdanturfTown_WandasHouse/events.inc"
	.include "data/maps/VerdanturfTown_FriendshipRatersHouse/events.inc"
	.include "data/maps/VerdanturfTown_House/events.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_1F/events.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_2F/events.inc"
	.include "data/maps/PacifidlogTown_House1/events.inc"
	.include "data/maps/PacifidlogTown_House2/events.inc"
	.include "data/maps/PacifidlogTown_House3/events.inc"
	.include "data/maps/PacifidlogTown_House4/events.inc"
	.include "data/maps/PacifidlogTown_House5/events.inc"
	.include "data/maps/PetalburgCity_WallysHouse/events.inc"
	.include "data/maps/PetalburgCity_Gym/events.inc"
	.include "data/maps/PetalburgCity_House1/events.inc"
	.include "data/maps/PetalburgCity_House2/events.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_1F/events.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_2F/events.inc"
	.include "data/maps/PetalburgCity_Mart/events.inc"
	.include "data/maps/SlateportCity_SternsShipyard_1F/events.inc"
	.include "data/maps/SlateportCity_SternsShipyard_2F/events.inc"
	.include "data/maps/SlateportCity_BattleTentLobby/events.inc"
	.include "data/maps/SlateportCity_BattleTentCorridor/events.inc"
	.include "data/maps/SlateportCity_BattleTentBattleRoom/events.inc"
	.include "data/maps/SlateportCity_NameRatersHouse/events.inc"
	.include "data/maps/SlateportCity_PokemonFanClub/events.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_1F/events.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_2F/events.inc"
	.include "data/maps/SlateportCity_Harbor/events.inc"
	.include "data/maps/SlateportCity_House/events.inc"
	.include "data/maps/SlateportCity_PokemonCenter_1F/events.inc"
	.include "data/maps/SlateportCity_PokemonCenter_2F/events.inc"
	.include "data/maps/SlateportCity_Mart/events.inc"
	.include "data/maps/MauvilleCity_Gym/events.inc"
	.include "data/maps/MauvilleCity_BikeShop/events.inc"
	.include "data/maps/MauvilleCity_House1/events.inc"
	.include "data/maps/MauvilleCity_GameCorner/events.inc"
	.include "data/maps/MauvilleCity_House2/events.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_1F/events.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_2F/events.inc"
	.include "data/maps/MauvilleCity_Mart/events.inc"
	.include "data/maps/RustboroCity_DevonCorp_1F/events.inc"
	.include "data/maps/RustboroCity_DevonCorp_2F/events.inc"
	.include "data/maps/RustboroCity_DevonCorp_3F/events.inc"
	.include "data/maps/RustboroCity_Gym/events.inc"
	.include "data/maps/RustboroCity_PokemonSchool/events.inc"
	.include "data/maps/RustboroCity_PokemonCenter_1F/events.inc"
	.include "data/maps/RustboroCity_PokemonCenter_2F/events.inc"
	.include "data/maps/RustboroCity_Mart/events.inc"
	.include "data/maps/RustboroCity_Flat1_1F/events.inc"
	.include "data/maps/RustboroCity_Flat1_2F/events.inc"
	.include "data/maps/RustboroCity_House1/events.inc"
	.include "data/maps/RustboroCity_CuttersHouse/events.inc"
	.include "data/maps/RustboroCity_House2/events.inc"
	.include "data/maps/RustboroCity_Flat2_1F/events.inc"
	.include "data/maps/RustboroCity_Flat2_2F/events.inc"
	.include "data/maps/RustboroCity_Flat2_3F/events.inc"
	.include "data/maps/RustboroCity_House3/events.inc"
	.include "data/maps/FortreeCity_House1/events.inc"
	.include "data/maps/FortreeCity_Gym/events.inc"
	.include "data/maps/FortreeCity_PokemonCenter_1F/events.inc"
	.include "data/maps/FortreeCity_PokemonCenter_2F/events.inc"
	.include "data/maps/FortreeCity_Mart/events.inc"
	.include "data/maps/FortreeCity_House2/events.inc"
	.include "data/maps/FortreeCity_House3/events.inc"
	.include "data/maps/FortreeCity_House4/events.inc"
	.include "data/maps/FortreeCity_House5/events.inc"
	.include "data/maps/FortreeCity_DecorationShop/events.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_1F/events.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_2F/events.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_1F/events.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_2F/events.inc"
	.include "data/maps/LilycoveCity_ContestLobby/events.inc"
	.include "data/maps/LilycoveCity_ContestHall/events.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_1F/events.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_2F/events.inc"
	.include "data/maps/LilycoveCity_UnusedMart/events.inc"
	.include "data/maps/LilycoveCity_PokemonTrainerFanClub/events.inc"
	.include "data/maps/LilycoveCity_Harbor/events.inc"
	.include "data/maps/LilycoveCity_MoveDeletersHouse/events.inc"
	.include "data/maps/LilycoveCity_House1/events.inc"
	.include "data/maps/LilycoveCity_House2/events.inc"
	.include "data/maps/LilycoveCity_House3/events.inc"
	.include "data/maps/LilycoveCity_House4/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_1F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_2F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_3F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_4F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_5F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreRooftop/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreElevator/events.inc"
	.include "data/maps/MossdeepCity_Gym/events.inc"
	.include "data/maps/MossdeepCity_House1/events.inc"
	.include "data/maps/MossdeepCity_House2/events.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_1F/events.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_2F/events.inc"
	.include "data/maps/MossdeepCity_Mart/events.inc"
	.include "data/maps/MossdeepCity_House3/events.inc"
	.include "data/maps/MossdeepCity_StevensHouse/events.inc"
	.include "data/maps/MossdeepCity_House4/events.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_1F/events.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_2F/events.inc"
	.include "data/maps/MossdeepCity_GameCorner_1F/events.inc"
	.include "data/maps/MossdeepCity_GameCorner_B1F/events.inc"
	.include "data/maps/SootopolisCity_Gym_1F/events.inc"
	.include "data/maps/SootopolisCity_Gym_B1F/events.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_1F/events.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_2F/events.inc"
	.include "data/maps/SootopolisCity_Mart/events.inc"
	.include "data/maps/SootopolisCity_House1/events.inc"
	.include "data/maps/SootopolisCity_House2/events.inc"
	.include "data/maps/SootopolisCity_House3/events.inc"
	.include "data/maps/SootopolisCity_House4/events.inc"
	.include "data/maps/SootopolisCity_House5/events.inc"
	.include "data/maps/SootopolisCity_House6/events.inc"
	.include "data/maps/SootopolisCity_House7/events.inc"
	.include "data/maps/SootopolisCity_LotadAndSeedotHouse/events.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/events.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/events.inc"
	.include "data/maps/EverGrandeCity_SidneysRoom/events.inc"
	.include "data/maps/EverGrandeCity_PhoebesRoom/events.inc"
	.include "data/maps/EverGrandeCity_GlaciasRoom/events.inc"
	.include "data/maps/EverGrandeCity_DrakesRoom/events.inc"
	.include "data/maps/EverGrandeCity_ChampionsRoom/events.inc"
	.include "data/maps/EverGrandeCity_Hall1/events.inc"
	.include "data/maps/EverGrandeCity_Hall2/events.inc"
	.include "data/maps/EverGrandeCity_Hall3/events.inc"
	.include "data/maps/EverGrandeCity_Hall4/events.inc"
	.include "data/maps/EverGrandeCity_Hall5/events.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_1F/events.inc"
	.include "data/maps/EverGrandeCity_HallOfFame/events.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_1F/events.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_2F/events.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_2F/events.inc"
	.include "data/maps/Route104_MrBrineysHouse/events.inc"
	.include "data/maps/Route104_PrettyPetalFlowerShop/events.inc"
	.include "data/maps/Route111_WinstrateFamilysHouse/events.inc"
	.include "data/maps/Route111_OldLadysRestStop/events.inc"
	.include "data/maps/Route112_CableCarStation/events.inc"
	.include "data/maps/MtChimney_CableCarStation/events.inc"
	.include "data/maps/Route114_FossilManiacsHouse/events.inc"
	.include "data/maps/Route114_FossilManiacsTunnel/events.inc"
	.include "data/maps/Route114_LanettesHouse/events.inc"
	.include "data/maps/Route116_TunnelersRestHouse/events.inc"
	.include "data/maps/Route117_PokemonDayCare/events.inc"
	.include "data/maps/Route121_SafariZoneEntrance/events.inc"
	.include "data/maps/MeteorFalls_1F_1R/events.inc"
	.include "data/maps/MeteorFalls_1F_2R/events.inc"
	.include "data/maps/MeteorFalls_B1F_1R/events.inc"
	.include "data/maps/MeteorFalls_B1F_2R/events.inc"
	.include "data/maps/RusturfTunnel/events.inc"
	.include "data/maps/Underwater_SootopolisCity/events.inc"
	.include "data/maps/DesertRuins/events.inc"
	.include "data/maps/GraniteCave_1F/events.inc"
	.include "data/maps/GraniteCave_B1F/events.inc"
	.include "data/maps/GraniteCave_B2F/events.inc"
	.include "data/maps/GraniteCave_StevensRoom/events.inc"
	.include "data/maps/PetalburgWoods/events.inc"
	.include "data/maps/MtChimney/events.inc"
	.include "data/maps/JaggedPass/events.inc"
	.include "data/maps/FieryPath/events.inc"
	.include "data/maps/MtPyre_1F/events.inc"
	.include "data/maps/MtPyre_2F/events.inc"
	.include "data/maps/MtPyre_3F/events.inc"
	.include "data/maps/MtPyre_4F/events.inc"
	.include "data/maps/MtPyre_5F/events.inc"
	.include "data/maps/MtPyre_6F/events.inc"
	.include "data/maps/MtPyre_Exterior/events.inc"
	.include "data/maps/MtPyre_Summit/events.inc"
	.include "data/maps/AquaHideout_1F/events.inc"
	.include "data/maps/AquaHideout_B1F/events.inc"
	.include "data/maps/AquaHideout_B2F/events.inc"
	.include "data/maps/Underwater_SeafloorCavern/events.inc"
	.include "data/maps/SeafloorCavern_Entrance/events.inc"
	.include "data/maps/SeafloorCavern_Room1/events.inc"
	.include "data/maps/SeafloorCavern_Room2/events.inc"
	.include "data/maps/SeafloorCavern_Room3/events.inc"
	.include "data/maps/SeafloorCavern_Room4/events.inc"
	.include "data/maps/SeafloorCavern_Room5/events.inc"
	.include "data/maps/SeafloorCavern_Room6/events.inc"
	.include "data/maps/SeafloorCavern_Room7/events.inc"
	.include "data/maps/SeafloorCavern_Room8/events.inc"
	.include "data/maps/SeafloorCavern_Room9/events.inc"
	.include "data/maps/CaveOfOrigin_Entrance/events.inc"
	.include "data/maps/CaveOfOrigin_1F/events.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/events.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/events.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/events.inc"
	.include "data/maps/CaveOfOrigin_B1F/events.inc"
	.include "data/maps/VictoryRoad_1F/events.inc"
	.include "data/maps/VictoryRoad_B1F/events.inc"
	.include "data/maps/VictoryRoad_B2F/events.inc"
	.include "data/maps/ShoalCave_LowTideEntranceRoom/events.inc"
	.include "data/maps/ShoalCave_LowTideInnerRoom/events.inc"
	.include "data/maps/ShoalCave_LowTideStairsRoom/events.inc"
	.include "data/maps/ShoalCave_LowTideLowerRoom/events.inc"
	.include "data/maps/ShoalCave_HighTideEntranceRoom/events.inc"
	.include "data/maps/ShoalCave_HighTideInnerRoom/events.inc"
	.include "data/maps/NewMauville_Entrance/events.inc"
	.include "data/maps/NewMauville_Inside/events.inc"
	.include "data/maps/AbandonedShip_Deck/events.inc"
	.include "data/maps/AbandonedShip_Corridors_1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms_1F/events.inc"
	.include "data/maps/AbandonedShip_Corridors_B1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms_B1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms2_B1F/events.inc"
	.include "data/maps/AbandonedShip_Underwater1/events.inc"
	.include "data/maps/AbandonedShip_Room_B1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms2_1F/events.inc"
	.include "data/maps/AbandonedShip_CaptainsOffice/events.inc"
	.include "data/maps/AbandonedShip_Underwater2/events.inc"
	.include "data/maps/AbandonedShip_HiddenFloorCorridors/events.inc"
	.include "data/maps/AbandonedShip_HiddenFloorRooms/events.inc"
	.include "data/maps/IslandCave/events.inc"
	.include "data/maps/AncientTomb/events.inc"
	.include "data/maps/Underwater_Route134/events.inc"
	.include "data/maps/Underwater_SealedChamber/events.inc"
	.include "data/maps/SealedChamber_OuterRoom/events.inc"
	.include "data/maps/SealedChamber_InnerRoom/events.inc"
	.include "data/maps/ScorchedSlab/events.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap1/events.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap2/events.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap3/events.inc"
	.include "data/maps/SkyPillar_Entrance/events.inc"
	.include "data/maps/SkyPillar_Outside/events.inc"
	.include "data/maps/SkyPillar_1F/events.inc"
	.include "data/maps/SkyPillar_2F/events.inc"
	.include "data/maps/SkyPillar_3F/events.inc"
	.include "data/maps/SkyPillar_4F/events.inc"
	.include "data/maps/ShoalCave_LowTideIceRoom/events.inc"
	.include "data/maps/SkyPillar_5F/events.inc"
	.include "data/maps/SkyPillar_Top/events.inc"
	.include "data/maps/MagmaHideout_1F/events.inc"
	.include "data/maps/MagmaHideout_2F_1R/events.inc"
	.include "data/maps/MagmaHideout_2F_2R/events.inc"
	.include "data/maps/MagmaHideout_3F_1R/events.inc"
	.include "data/maps/MagmaHideout_3F_2R/events.inc"
	.include "data/maps/MagmaHideout_4F/events.inc"
	.include "data/maps/MagmaHideout_3F_3R/events.inc"
	.include "data/maps/MagmaHideout_2F_3R/events.inc"
	.include "data/maps/MirageTower_1F/events.inc"
	.include "data/maps/MirageTower_2F/events.inc"
	.include "data/maps/MirageTower_3F/events.inc"
	.include "data/maps/MirageTower_4F/events.inc"
	.include "data/maps/DesertUnderpass/events.inc"
	.include "data/maps/ArtisanCave_B1F/events.inc"
	.include "data/maps/ArtisanCave_1F/events.inc"
	.include "data/maps/Underwater_MarineCave/events.inc"
	.include "data/maps/MarineCave_Entrance/events.inc"
	.include "data/maps/MarineCave_End/events.inc"
	.include "data/maps/TerraCave_Entrance/events.inc"
	.include "data/maps/TerraCave_End/events.inc"
	.include "data/maps/AlteringCave/events.inc"
	.include "data/maps/MeteorFalls_StevensCave/events.inc"
	.include "data/maps/SecretBase_RedCave1/events.inc"
	.include "data/maps/SecretBase_BrownCave1/events.inc"
	.include "data/maps/SecretBase_BlueCave1/events.inc"
	.include "data/maps/SecretBase_YellowCave1/events.inc"
	.include "data/maps/SecretBase_Tree1/events.inc"
	.include "data/maps/SecretBase_Shrub1/events.inc"
	.include "data/maps/SecretBase_RedCave2/events.inc"
	.include "data/maps/SecretBase_BrownCave2/events.inc"
	.include "data/maps/SecretBase_BlueCave2/events.inc"
	.include "data/maps/SecretBase_YellowCave2/events.inc"
	.include "data/maps/SecretBase_Tree2/events.inc"
	.include "data/maps/SecretBase_Shrub2/events.inc"
	.include "data/maps/SecretBase_RedCave3/events.inc"
	.include "data/maps/SecretBase_BrownCave3/events.inc"
	.include "data/maps/SecretBase_BlueCave3/events.inc"
	.include "data/maps/SecretBase_YellowCave3/events.inc"
	.include "data/maps/SecretBase_Tree3/events.inc"
	.include "data/maps/SecretBase_Shrub3/events.inc"
	.include "data/maps/SecretBase_RedCave4/events.inc"
	.include "data/maps/SecretBase_BrownCave4/events.inc"
	.include "data/maps/SecretBase_BlueCave4/events.inc"
	.include "data/maps/SecretBase_YellowCave4/events.inc"
	.include "data/maps/SecretBase_Tree4/events.inc"
	.include "data/maps/SecretBase_Shrub4/events.inc"
	.include "data/maps/BattleColosseum_2P/events.inc"
	.include "data/maps/TradeCenter/events.inc"
	.include "data/maps/RecordCorner/events.inc"
	.include "data/maps/BattleColosseum_4P/events.inc"
	.include "data/maps/ContestHall/events.inc"
	.include "data/maps/InsideOfTruck/events.inc"
	.include "data/maps/SSTidalCorridor/events.inc"
	.include "data/maps/SSTidalLowerDeck/events.inc"
	.include "data/maps/SSTidalRooms/events.inc"
	.include "data/maps/BattlePyramidSquare01/events.inc"
	.include "data/maps/BattlePyramidSquare02/events.inc"
	.include "data/maps/BattlePyramidSquare03/events.inc"
	.include "data/maps/BattlePyramidSquare04/events.inc"
	.include "data/maps/BattlePyramidSquare05/events.inc"
	.include "data/maps/BattlePyramidSquare06/events.inc"
	.include "data/maps/BattlePyramidSquare07/events.inc"
	.include "data/maps/BattlePyramidSquare08/events.inc"
	.include "data/maps/BattlePyramidSquare09/events.inc"
	.include "data/maps/BattlePyramidSquare10/events.inc"
	.include "data/maps/BattlePyramidSquare11/events.inc"
	.include "data/maps/BattlePyramidSquare12/events.inc"
	.include "data/maps/BattlePyramidSquare13/events.inc"
	.include "data/maps/BattlePyramidSquare14/events.inc"
	.include "data/maps/BattlePyramidSquare15/events.inc"
	.include "data/maps/BattlePyramidSquare16/events.inc"
	.include "data/maps/UnionRoom/events.inc"
	.include "data/maps/SafariZone_Northwest/events.inc"
	.include "data/maps/SafariZone_North/events.inc"
	.include "data/maps/SafariZone_Southwest/events.inc"
	.include "data/maps/SafariZone_South/events.inc"
	.include "data/maps/BattleFrontier_OutsideWest/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerElevator/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom/events.inc"
	.include "data/maps/SouthernIsland_Exterior/events.inc"
	.include "data/maps/SouthernIsland_Interior/events.inc"
	.include "data/maps/SafariZone_RestHouse/events.inc"
	.include "data/maps/SafariZone_Northeast/events.inc"
	.include "data/maps/SafariZone_Southeast/events.inc"
	.include "data/maps/BattleFrontier_OutsideEast/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/events.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/events.inc"
	.include "data/maps/BattleFrontier_BattlePyramidFloor/events.inc"
	.include "data/maps/BattleFrontier_BattlePyramidTop/events.inc"
	.include "data/maps/BattleFrontier_BattleArenaLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleArenaCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleArenaBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleFactoryLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleFactoryBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattlePikeLobby/events.inc"
	.include "data/maps/BattleFrontier_BattlePikeCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattlePikeThreePathRoom/events.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomNormal/events.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomFinal/events.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomWildMons/events.inc"
	.include "data/maps/BattleFrontier_RankingHall/events.inc"
	.include "data/maps/BattleFrontier_Lounge1/events.inc"
	.include "data/maps/BattleFrontier_ExchangeServiceCorner/events.inc"
	.include "data/maps/BattleFrontier_Lounge2/events.inc"
	.include "data/maps/BattleFrontier_Lounge3/events.inc"
	.include "data/maps/BattleFrontier_Lounge4/events.inc"
	.include "data/maps/BattleFrontier_ScottsHouse/events.inc"
	.include "data/maps/BattleFrontier_Lounge5/events.inc"
	.include "data/maps/BattleFrontier_Lounge6/events.inc"
	.include "data/maps/BattleFrontier_Lounge7/events.inc"
	.include "data/maps/BattleFrontier_ReceptionGate/events.inc"
	.include "data/maps/BattleFrontier_Lounge8/events.inc"
	.include "data/maps/BattleFrontier_Lounge9/events.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_1F/events.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_2F/events.inc"
	.include "data/maps/BattleFrontier_Mart/events.inc"
	@ MAP_FARAWAY_ISLAND_ENTRANCE (g26 m56)
	.include "data/maps/FarawayIsland_Entrance/events.inc"
	@ MAP_FARAWAY_ISLAND_INTERIOR (g26 m57)
	.include "data/maps/FarawayIsland_Interior/events.inc"
	@ MAP_BIRTH_ISLAND_EXTERIOR (g26 m58)
	.include "data/maps/BirthIsland_Exterior/events.inc"
	@ MAP_BIRTH_ISLAND_HARBOR (g26 m59)
	.include "data/maps/BirthIsland_Harbor/events.inc"
	@ MAP_TRAINER_HILL_ENTRANCE (g26 m60)
	.include "data/maps/TrainerHill_Entrance/events.inc"
	@ MAP_TRAINER_HILL_1F (g26 m61)
	.include "data/maps/TrainerHill_1F/events.inc"
	@ MAP_TRAINER_HILL_2F (g26 m62)
	.include "data/maps/TrainerHill_2F/events.inc"
	@ MAP_TRAINER_HILL_3F (g26 m63)
	.include "data/maps/TrainerHill_3F/events.inc"
	@ MAP_TRAINER_HILL_4F (g26 m64)
	.include "data/maps/TrainerHill_4F/events.inc"
	@ MAP_TRAINER_HILL_ROOF (g26 m65)
	.include "data/maps/TrainerHill_Roof/events.inc"
	@ MAP_NAVEL_ROCK_EXTERIOR (g26 m66)
	.include "data/maps/NavelRock_Exterior/events.inc"
	@ MAP_NAVEL_ROCK_HARBOR (g26 m67)
	.include "data/maps/NavelRock_Harbor/events.inc"
	@ MAP_NAVEL_ROCK_ENTRANCE (g26 m68)
	.include "data/maps/NavelRock_Entrance/events.inc"
	@ MAP_NAVEL_ROCK_B1F (g26 m69)
	.include "data/maps/NavelRock_B1F/events.inc"
	@ MAP_NAVEL_ROCK_FORK (g26 m70)
	.include "data/maps/NavelRock_Fork/events.inc"
	@ MAP_NAVEL_ROCK_UP1 (g26 m71)
	.include "data/maps/NavelRock_Up1/events.inc"
	@ MAP_NAVEL_ROCK_UP2 (g26 m72)
	.include "data/maps/NavelRock_Up2/events.inc"
	@ MAP_NAVEL_ROCK_UP3 (g26 m73)
	.include "data/maps/NavelRock_Up3/events.inc"
	@ MAP_NAVEL_ROCK_UP4 (g26 m74)
	.include "data/maps/NavelRock_Up4/events.inc"
	@ MAP_NAVEL_ROCK_TOP (g26 m75)
	.include "data/maps/NavelRock_Top/events.inc"
	@ MAP_NAVEL_ROCK_DOWN01 (g26 m76)
	.include "data/maps/NavelRock_Down01/events.inc"
	@ MAP_NAVEL_ROCK_DOWN02 (g26 m77)
	.include "data/maps/NavelRock_Down02/events.inc"
	@ MAP_NAVEL_ROCK_DOWN03 (g26 m78)
	.include "data/maps/NavelRock_Down03/events.inc"
	@ MAP_NAVEL_ROCK_DOWN04 (g26 m79)
	.include "data/maps/NavelRock_Down04/events.inc"
	@ MAP_NAVEL_ROCK_DOWN05 (g26 m80)
	.include "data/maps/NavelRock_Down05/events.inc"
	@ MAP_NAVEL_ROCK_DOWN06 (g26 m81)
	.include "data/maps/NavelRock_Down06/events.inc"
	@ MAP_NAVEL_ROCK_DOWN07 (g26 m82)
	.include "data/maps/NavelRock_Down07/events.inc"
	@ MAP_NAVEL_ROCK_DOWN08 (g26 m83)
	.include "data/maps/NavelRock_Down08/events.inc"
	@ MAP_NAVEL_ROCK_DOWN09 (g26 m84)
	.include "data/maps/NavelRock_Down09/events.inc"
	@ MAP_NAVEL_ROCK_DOWN10 (g26 m85)
	.include "data/maps/NavelRock_Down10/events.inc"
	@ MAP_NAVEL_ROCK_DOWN11 (g26 m86)
	.include "data/maps/NavelRock_Down11/events.inc"
	@ MAP_NAVEL_ROCK_BOTTOM (g26 m87)
	.include "data/maps/NavelRock_Bottom/events.inc"
	@ MAP_TRAINER_HILL_ELEVATOR (g26 m88)
	.include "data/maps/TrainerHill_Elevator/events.inc"
	@ MAP_ROUTE104_PROTOTYPE (g27 m0)
	.include "data/maps/Route104_Prototype/events.inc"
	@ MAP_ROUTE104_PROTOTYPE_PRETTY_PETAL_FLOWER_SHOP (g27 m1)
	.include "data/maps/Route104_PrototypePrettyPetalFlowerShop/events.inc"
	@ MAP_ROUTE109_SEASHORE_HOUSE (g28 m0)
	.include "data/maps/Route109_SeashoreHouse/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_ENTRANCE (g29 m0)
	.include "data/maps/Route110_TrickHouseEntrance/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_END (g29 m1)
	.include "data/maps/Route110_TrickHouseEnd/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_CORRIDOR (g29 m2)
	.include "data/maps/Route110_TrickHouseCorridor/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE1 (g29 m3)
	.include "data/maps/Route110_TrickHousePuzzle1/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE2 (g29 m4)
	.include "data/maps/Route110_TrickHousePuzzle2/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE3 (g29 m5)
	.include "data/maps/Route110_TrickHousePuzzle3/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE4 (g29 m6)
	.include "data/maps/Route110_TrickHousePuzzle4/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE5 (g29 m7)
	.include "data/maps/Route110_TrickHousePuzzle5/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE6 (g29 m8)
	.include "data/maps/Route110_TrickHousePuzzle6/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE7 (g29 m9)
	.include "data/maps/Route110_TrickHousePuzzle7/events.inc"
	@ MAP_ROUTE110_TRICK_HOUSE_PUZZLE8 (g29 m10)
	.include "data/maps/Route110_TrickHousePuzzle8/events.inc"
	@ MAP_ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE (g29 m11)
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/events.inc"
	@ MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE (g29 m12)
	.include "data/maps/Route110_SeasideCyclingRoadNorthEntrance/events.inc"
	@ MAP_ROUTE113_GLASS_WORKSHOP (g30 m0)
	.include "data/maps/Route113_GlassWorkshop/events.inc"
	@ MAP_ROUTE123_BERRY_MASTERS_HOUSE (g31 m0)
	.include "data/maps/Route123_BerryMastersHouse/events.inc"
	@ MAP_ROUTE119_WEATHER_INSTITUTE_1F (g32 m0)
	.include "data/maps/Route119_WeatherInstitute_1F/events.inc"
	@ MAP_ROUTE119_WEATHER_INSTITUTE_2F (g32 m1)
	.include "data/maps/Route119_WeatherInstitute_2F/events.inc"
	@ MAP_ROUTE119_HOUSE (g32 m2)
	.include "data/maps/Route119_House/events.inc"
	@ MAP_ROUTE124_DIVING_TREASURE_HUNTERS_HOUSE (g33 m0)
	.include "data/maps/Route124_DivingTreasureHuntersHouse/events.inc"
	.section .rodata.data_b2d_mid26_after_field_weather_drought_before_field_weather_static_data

	.globl gWeatherPtr
gWeatherPtr: @ 0x8526DE8
	.4byte gUnknown_20380F4 @ &gWeather

	.section .rodata.data_b2d_mid26_after_field_weather_effect_static_data

	.globl sWeatherCycleRoute119
sWeatherCycleRoute119: @ 0x852AAF8
	.byte 0x02, 0x03, 0x05, 0x03

	.globl sWeatherCycleRoute123
sWeatherCycleRoute123: @ 0x852AAFC
	.byte 0x02, 0x02, 0x03, 0x02

	.globl sFlashLevelToRadius
sFlashLevelToRadius: @ 0x852AB00
	.hword 0x00C8, 0x0048, 0x0040, 0x0038, 0x0030, 0x0028, 0x0020, 0x0018, 0x0000, 0x0000

	.globl gMaxFlashLevel
gMaxFlashLevel: @ 0x852AB14
gMaxFlashLevel: @ 0x852AB14
	.4byte 8

	.globl sFlashEffectParams
sFlashEffectParams: @ 0x852AB18
sFlashEffectParams: @ 0x852AB18
	.4byte 0x04000040  @ dmaDest
	.4byte 0xA2600001  @ dmaControl
	.byte 0x01  @ initState
	.byte 0x00, 0x00, 0x00

	.globl sBattleTransitionTable_Wild
sBattleTransitionTable_Wild: @ 0x852AB24
	.byte 0x08, 0x09, 0x05, 0x0A, 0x00, 0x0A, 0x07, 0x06

	.globl sBattleTransitionTable_Trainer
sBattleTransitionTable_Trainer: @ 0x852AB2C
	.byte 0x04, 0x0B, 0x02, 0x03, 0x00, 0x0A, 0x01, 0x06

	.globl sBattleTransitionTable_BattleFrontier
sBattleTransitionTable_BattleFrontier: @ 0x852AB34
	.byte 0x1D, 0x1E, 0x1F, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29

	.globl sBattleTransitionTable_BattlePyramid
sBattleTransitionTable_BattlePyramid: @ 0x852AB40
	.byte 0x1F, 0x20, 0x21

	.globl sBattleTransitionTable_BattleDome
sBattleTransitionTable_BattleDome: @ 0x852AB43
	.byte 0x1D, 0x1F, 0x20, 0x21, 0x00

	.globl sOrdinaryBattleParams
sOrdinaryBattleParams: @ 0x0052AB48
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sContinueScriptBattleParams
sContinueScriptBattleParams: @ 0x0052AB90
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sDoubleBattleParams
sDoubleBattleParams: @ 0x0052ABD8
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sOrdinaryNoIntroBattleParams
sOrdinaryNoIntroBattleParams: @ 0x0052AC20
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sContinueScriptDoubleBattleParams
sContinueScriptDoubleBattleParams: @ 0x0052AC68
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.globl sTrainerBOrdinaryBattleParams
sTrainerBOrdinaryBattleParams: @ 0x0052ACB0
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886C
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038878
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038880
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038894
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.globl sTrainerBContinueScriptBattleParams
sTrainerBContinueScriptBattleParams: @ 0x0052ACF8
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886C
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038878
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038880
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038894
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.section .rodata.data_b2d_mid26_after_wild_encounter_data
	.globl gBattlePyramid_1_LandMons
gBattlePyramid_1_LandMons: @ 0x852E3B8
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_1_LandMonsInfo
gBattlePyramid_1_LandMonsInfo: @ 0x852E3E8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_1_LandMons
	.globl gBattlePyramid_2_LandMons
gBattlePyramid_2_LandMons: @ 0x852E3F0
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_2_LandMonsInfo
gBattlePyramid_2_LandMonsInfo: @ 0x852E420
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_2_LandMons
	.globl gBattlePyramid_3_LandMons
gBattlePyramid_3_LandMons: @ 0x852E428
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.globl gBattlePyramid_3_LandMonsInfo
gBattlePyramid_3_LandMonsInfo: @ 0x852E458
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_3_LandMons
	.globl gBattlePyramid_4_LandMons
gBattlePyramid_4_LandMons: @ 0x852E460
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.globl gBattlePyramid_4_LandMonsInfo
gBattlePyramid_4_LandMonsInfo: @ 0x852E490
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_4_LandMons
	.globl gBattlePyramid_5_LandMons
gBattlePyramid_5_LandMons: @ 0x852E498
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_5_LandMonsInfo
gBattlePyramid_5_LandMonsInfo: @ 0x852E4C8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_5_LandMons
	.globl gBattlePyramid_6_LandMons
gBattlePyramid_6_LandMons: @ 0x852E4D0
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_6_LandMonsInfo
gBattlePyramid_6_LandMonsInfo: @ 0x852E500
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_6_LandMons
	.globl gBattlePyramid_7_LandMons
gBattlePyramid_7_LandMons: @ 0x852E508
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.globl gBattlePyramid_7_LandMonsInfo
gBattlePyramid_7_LandMonsInfo: @ 0x852E538
	.byte 8
	.byte 0, 0, 0
	.4byte gBattlePyramid_7_LandMons

	.globl gBattlePyramidWildMonHeaders
gBattlePyramidWildMonHeaders: @ 0x852E540
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_1_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_2_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_3_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_4_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 5 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_5_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 6 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_6_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 7 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_7_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.globl gBattlePike_1_LandMons
gBattlePike_1_LandMons: @ 0x852E5E0
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_1_LandMonsInfo
gBattlePike_1_LandMonsInfo: @ 0x852E610
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_1_LandMons
	.globl gBattlePike_2_LandMons
gBattlePike_2_LandMons: @ 0x852E618
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_2_LandMonsInfo
gBattlePike_2_LandMonsInfo: @ 0x852E648
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_2_LandMons
	.globl gBattlePike_3_LandMons
gBattlePike_3_LandMons: @ 0x852E650
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_3_LandMonsInfo
gBattlePike_3_LandMonsInfo: @ 0x852E680
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_3_LandMons
	.globl gBattlePike_4_LandMons
gBattlePike_4_LandMons: @ 0x852E688
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_4_LandMonsInfo
gBattlePike_4_LandMonsInfo: @ 0x852E6B8
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_4_LandMons

	.globl gBattlePikeWildMonHeaders
gBattlePikeWildMonHeaders: @ 0x852E6C0
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_1_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_2_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_3_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_4_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL

	.section .rodata.data_b2d_mid26_after_wild_encounter_route119_data
	.align 2

	.section .rodata.data_b2d_mid26_after_field_effect_graphics_resource_data
	.align 2

	.globl gFieldEffectScriptFuncs
gFieldEffectScriptFuncs: @ 0x8536E9C
	.4byte FieldEffectCmd_loadtiles + 1, FieldEffectCmd_loadfadedpal + 1, FieldEffectCmd_loadpal + 1, FieldEffectCmd_callnative + 1, FieldEffectCmd_end + 1, FieldEffectCmd_loadgfx_callnative + 1, FieldEffectCmd_loadtiles_callnative + 1, FieldEffectCmd_loadfadedpal_callnative + 1

	.section .rodata.data_b2d_mid26_after_field_effect_script_funcs
	.align 2
