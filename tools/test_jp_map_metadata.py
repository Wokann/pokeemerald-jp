#!/usr/bin/env python3
"""Regression checks for JP map.json header/connection generation."""

import unittest
from pathlib import Path

import jp_map_metadata


ROOT = Path(__file__).resolve().parents[1]
MAPS = (
    "CaveOfOrigin_B1F",
    "VictoryRoad_1F",
    "VictoryRoad_B1F",
    "VictoryRoad_B2F",
    "Underwater_Route124",
    "Underwater_Route126",
    "Underwater_Route127",
    "Underwater_Route128",
    "Underwater_Route129",
    "OldaleTown_House1",
    "OldaleTown_House2",
    "OldaleTown_PokemonCenter_1F",
    "OldaleTown_PokemonCenter_2F",
    "OldaleTown_Mart",
    "DewfordTown_House1",
    "DewfordTown_PokemonCenter_1F",
    "DewfordTown_PokemonCenter_2F",
    "DewfordTown_Gym",
    "DewfordTown_Hall",
    "DewfordTown_House2",
    "LavaridgeTown_HerbShop",
    "LavaridgeTown_Gym_1F",
    "LavaridgeTown_Gym_B1F",
    "LavaridgeTown_House",
    "LavaridgeTown_Mart",
    "LavaridgeTown_PokemonCenter_1F",
    "LavaridgeTown_PokemonCenter_2F",
    "FallarborTown_Mart",
    "FallarborTown_BattleTentLobby",
    "FallarborTown_BattleTentCorridor",
    "FallarborTown_BattleTentBattleRoom",
    "FallarborTown_PokemonCenter_1F",
    "FallarborTown_PokemonCenter_2F",
    "FallarborTown_CozmosHouse",
    "FallarborTown_MoveRelearnersHouse",
    "VerdanturfTown_BattleTentLobby",
    "VerdanturfTown_BattleTentCorridor",
    "VerdanturfTown_BattleTentBattleRoom",
    "VerdanturfTown_Mart",
    "VerdanturfTown_PokemonCenter_1F",
    "VerdanturfTown_PokemonCenter_2F",
    "VerdanturfTown_WandasHouse",
    "VerdanturfTown_FriendshipRatersHouse",
    "VerdanturfTown_House",
    "PacifidlogTown_PokemonCenter_1F",
    "PacifidlogTown_PokemonCenter_2F",
    "PacifidlogTown_House1",
    "PacifidlogTown_House2",
    "PacifidlogTown_House3",
    "PacifidlogTown_House4",
    "PacifidlogTown_House5",
    "PetalburgCity_WallysHouse",
    "PetalburgCity_Gym",
    "PetalburgCity_House1",
    "PetalburgCity_House2",
    "PetalburgCity_PokemonCenter_1F",
    "PetalburgCity_PokemonCenter_2F",
    "PetalburgCity_Mart",
    "SlateportCity_SternsShipyard_1F",
    "SlateportCity_SternsShipyard_2F",
    "SlateportCity_BattleTentLobby",
    "SlateportCity_BattleTentCorridor",
    "SlateportCity_BattleTentBattleRoom",
    "SlateportCity_NameRatersHouse",
    "SlateportCity_PokemonFanClub",
    "SlateportCity_OceanicMuseum_1F",
    "SlateportCity_OceanicMuseum_2F",
    "SlateportCity_Harbor",
    "SlateportCity_House",
    "SlateportCity_PokemonCenter_1F",
    "SlateportCity_PokemonCenter_2F",
    "SlateportCity_Mart",
    "MauvilleCity_Gym",
    "MauvilleCity_BikeShop",
    "MauvilleCity_House1",
    "MauvilleCity_GameCorner",
    "MauvilleCity_House2",
    "MauvilleCity_PokemonCenter_1F",
    "MauvilleCity_PokemonCenter_2F",
    "MauvilleCity_Mart",
    "RustboroCity_DevonCorp_1F",
    "RustboroCity_DevonCorp_2F",
    "RustboroCity_DevonCorp_3F",
    "RustboroCity_Gym",
    "RustboroCity_PokemonSchool",
    "RustboroCity_PokemonCenter_1F",
    "RustboroCity_PokemonCenter_2F",
    "RustboroCity_Mart",
    "RustboroCity_Flat1_1F",
    "RustboroCity_Flat1_2F",
    "RustboroCity_House1",
    "RustboroCity_CuttersHouse",
    "RustboroCity_House2",
    "RustboroCity_Flat2_1F",
    "RustboroCity_Flat2_2F",
    "RustboroCity_Flat2_3F",
    "RustboroCity_House3",
    "FortreeCity_House1",
    "FortreeCity_Gym",
    "FortreeCity_PokemonCenter_1F",
    "FortreeCity_PokemonCenter_2F",
    "FortreeCity_Mart",
    "FortreeCity_House2",
    "FortreeCity_House3",
    "FortreeCity_House4",
    "FortreeCity_House5",
    "FortreeCity_DecorationShop",
)

CONNECTED_MAPS = (
    "Underwater_Route124",
    "Underwater_Route126",
    "Underwater_Route127",
    "Underwater_Route128",
    "Underwater_Route129",
)

NULL_CONNECTION_MAPS = (
    "CaveOfOrigin_B1F",
    "VictoryRoad_1F",
    "VictoryRoad_B1F",
    "VictoryRoad_B2F",
    "OldaleTown_House1",
    "OldaleTown_House2",
    "OldaleTown_PokemonCenter_1F",
    "OldaleTown_PokemonCenter_2F",
    "OldaleTown_Mart",
    "DewfordTown_House1",
    "DewfordTown_PokemonCenter_1F",
    "DewfordTown_PokemonCenter_2F",
    "DewfordTown_Gym",
    "DewfordTown_Hall",
    "DewfordTown_House2",
    "LavaridgeTown_HerbShop",
    "LavaridgeTown_Gym_1F",
    "LavaridgeTown_Gym_B1F",
    "LavaridgeTown_House",
    "LavaridgeTown_Mart",
    "LavaridgeTown_PokemonCenter_1F",
    "LavaridgeTown_PokemonCenter_2F",
    "FallarborTown_Mart",
    "FallarborTown_BattleTentLobby",
    "FallarborTown_BattleTentCorridor",
    "FallarborTown_BattleTentBattleRoom",
    "FallarborTown_PokemonCenter_1F",
    "FallarborTown_PokemonCenter_2F",
    "FallarborTown_CozmosHouse",
    "FallarborTown_MoveRelearnersHouse",
    "VerdanturfTown_BattleTentLobby",
    "VerdanturfTown_BattleTentCorridor",
    "VerdanturfTown_BattleTentBattleRoom",
    "VerdanturfTown_Mart",
    "VerdanturfTown_PokemonCenter_1F",
    "VerdanturfTown_PokemonCenter_2F",
    "VerdanturfTown_WandasHouse",
    "VerdanturfTown_FriendshipRatersHouse",
    "VerdanturfTown_House",
    "PacifidlogTown_PokemonCenter_1F",
    "PacifidlogTown_PokemonCenter_2F",
    "PacifidlogTown_House1",
    "PacifidlogTown_House2",
    "PacifidlogTown_House3",
    "PacifidlogTown_House4",
    "PacifidlogTown_House5",
    "PetalburgCity_WallysHouse",
    "PetalburgCity_Gym",
    "PetalburgCity_House1",
    "PetalburgCity_House2",
    "PetalburgCity_PokemonCenter_1F",
    "PetalburgCity_PokemonCenter_2F",
    "PetalburgCity_Mart",
    "SlateportCity_SternsShipyard_1F",
    "SlateportCity_SternsShipyard_2F",
    "SlateportCity_BattleTentLobby",
    "SlateportCity_BattleTentCorridor",
    "SlateportCity_BattleTentBattleRoom",
    "SlateportCity_NameRatersHouse",
    "SlateportCity_PokemonFanClub",
    "SlateportCity_OceanicMuseum_1F",
    "SlateportCity_OceanicMuseum_2F",
    "SlateportCity_Harbor",
    "SlateportCity_House",
    "SlateportCity_PokemonCenter_1F",
    "SlateportCity_PokemonCenter_2F",
    "SlateportCity_Mart",
    "MauvilleCity_Gym",
    "MauvilleCity_BikeShop",
    "MauvilleCity_House1",
    "MauvilleCity_GameCorner",
    "MauvilleCity_House2",
    "MauvilleCity_PokemonCenter_1F",
    "MauvilleCity_PokemonCenter_2F",
    "MauvilleCity_Mart",
    "RustboroCity_DevonCorp_1F",
    "RustboroCity_DevonCorp_2F",
    "RustboroCity_DevonCorp_3F",
    "RustboroCity_Gym",
    "RustboroCity_PokemonSchool",
    "RustboroCity_PokemonCenter_1F",
    "RustboroCity_PokemonCenter_2F",
    "RustboroCity_Mart",
    "RustboroCity_Flat1_1F",
    "RustboroCity_Flat1_2F",
    "RustboroCity_House1",
    "RustboroCity_CuttersHouse",
    "RustboroCity_House2",
    "RustboroCity_Flat2_1F",
    "RustboroCity_Flat2_2F",
    "RustboroCity_Flat2_3F",
    "RustboroCity_House3",
    "FortreeCity_House1",
    "FortreeCity_Gym",
    "FortreeCity_PokemonCenter_1F",
    "FortreeCity_PokemonCenter_2F",
    "FortreeCity_Mart",
    "FortreeCity_House2",
    "FortreeCity_House3",
    "FortreeCity_House4",
    "FortreeCity_House5",
    "FortreeCity_DecorationShop",
)

CANONICAL_LAYOUT_MAPS = (
    "Underwater_Route124",
    "Underwater_Route126",
    "Underwater_Route127",
    "Underwater_Route128",
    "Underwater_Route129",
)


class MapMetadataTests(unittest.TestCase):
    def test_checked_metadata_matches_canonical_json(self):
        for map_name in MAPS:
            map_dir = ROOT / "data" / "maps" / map_name
            data = jp_map_metadata.load_map(map_dir / "map.json")
            self.assertEqual(
                (map_dir / "header.inc").read_text(encoding="utf-8"),
                jp_map_metadata.render_header(data),
            )
            self.assertEqual(
                (map_dir / "connections.inc").read_text(encoding="utf-8"),
                jp_map_metadata.render_connections(data),
            )

    def test_headers_use_real_map_and_layout_labels(self):
        for map_name in MAPS:
            text = (ROOT / "data" / "maps" / map_name / "header.inc").read_text(encoding="utf-8")
            self.assertIn(f"{map_name}:", text)
            if map_name in CANONICAL_LAYOUT_MAPS:
                self.assertIn(f".4byte {map_name}_Layout\n", text)
                self.assertNotIn("gMapLayout_", text)
            else:
                self.assertIn("gMapLayout_", text)
            self.assertIn("map_header_flags allow_cycling=", text)
            self.assertNotIn(".set ", text)

    def test_layout_symbol_keeps_legacy_names_outside_reviewed_family(self):
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_UNDERWATER_ROUTE124"),
            "Underwater_Route124_Layout",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_CAVE_OF_ORIGIN_B1F"),
            "gMapLayout_CAVE_OF_ORIGIN_B1F",
        )

    def test_shared_layouts_use_their_real_jp_owners(self):
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_HOUSE1"),
            "gMapLayout_OLDALE_TOWN_HOUSE1",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_HOUSE2"),
            "gMapLayout_OLDALE_TOWN_HOUSE2",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_POKEMON_CENTER_1F"),
            "gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_POKEMON_CENTER_2F"),
            "gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_MART"),
            "gMapLayout_OLDALE_TOWN_MART",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_HOUSE3"),
            "gMapLayout_DEWFORD_TOWN_HOUSE1",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_HOUSE4"),
            "gMapLayout_DEWFORD_TOWN_HOUSE2",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_BATTLE_TENT_LOBBY"),
            "gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_BATTLE_TENT_CORRIDOR"),
            "gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR",
        )
        self.assertEqual(
            jp_map_metadata.layout_symbol("LAYOUT_BATTLE_TENT_BATTLE_ROOM"),
            "gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM",
        )

    def test_connections_use_real_map_labels(self):
        for map_name in CONNECTED_MAPS:
            text = (ROOT / "data" / "maps" / map_name / "connections.inc").read_text(encoding="utf-8")
            self.assertIn(f"{map_name}_MapConnections:", text)
            self.assertNotIn(".set ", text)

    def test_null_connections_match_us_map_json_style(self):
        for map_name in NULL_CONNECTION_MAPS:
            data = jp_map_metadata.load_map(ROOT / "data" / "maps" / map_name / "map.json")
            self.assertIsNone(data["connections"])
            self.assertIn("\t.4byte NULL\n", jp_map_metadata.render_header(data))
            self.assertEqual(
                jp_map_metadata.render_connections(data),
                jp_map_metadata.warning(map_name),
            )


if __name__ == "__main__":
    unittest.main()
