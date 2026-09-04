#!/usr/bin/env python3
"""Generate JP-local map header and connection sources from canonical map.json.

The JP project has not yet migrated its complete layouts.json table.  This
small companion to mapjson therefore keeps legacy ``gMapLayout_*`` references
for layouts which still use the centralized JP names, while emitting canonical
map-local ``*_Layout`` symbols for reviewed migrated layouts.  It never
derives data from the US checkout.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any


VALID_DIRECTIONS = {"down", "up", "left", "right", "dive", "emerge"}


# These reviewed layouts have map-local resources and canonical labels in
# data/layouts/layouts.inc. Keep this explicit until the complete JP layout
# table is migrated, so generation never guesses an owner for an unreviewed
# layout.
CANONICAL_LAYOUT_SYMBOLS = {
    "LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY": "BattleFrontier_BattlePikeLobby_Layout",
    "LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR": "BattleFrontier_BattlePikeCorridor_Layout",
    "LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM": "BattleFrontier_BattlePikeThreePathRoom_Layout",
    "LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL": "BattleFrontier_BattlePikeRoomNormal_Layout",
    "LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_FINAL": "BattleFrontier_BattlePikeRoomFinal_Layout",
    "LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS": "BattleFrontier_BattlePikeRoomWildMons_Layout",
    "LAYOUT_BATTLE_FRONTIER_RANKING_HALL": "BattleFrontier_RankingHall_Layout",
    "LAYOUT_BATTLE_FRONTIER_LOUNGE1": "BattleFrontier_Lounge1_Layout",
    "LAYOUT_BATTLE_FRONTIER_EXCHANGE_SERVICE_CORNER": "BattleFrontier_ExchangeServiceCorner_Layout",
    "LAYOUT_BATTLE_FRONTIER_RECEPTION_GATE": "BattleFrontier_ReceptionGate_Layout",
    "LAYOUT_BATTLE_FRONTIER_LOUNGE2": "BattleFrontier_Lounge2_Layout",
    "LAYOUT_BATTLE_FRONTIER_SCOTTS_HOUSE": "BattleFrontier_ScottsHouse_Layout",
    "LAYOUT_UNDERWATER_MARINE_CAVE": "Underwater_MarineCave_Layout",
    "LAYOUT_MARINE_CAVE_ENTRANCE": "MarineCave_Entrance_Layout",
    "LAYOUT_TERRA_CAVE_ENTRANCE": "TerraCave_Entrance_Layout",
    "LAYOUT_TERRA_CAVE_END": "TerraCave_End_Layout",
    "LAYOUT_UNDERWATER_ROUTE105": "Underwater_Route105_Layout",
    "LAYOUT_UNDERWATER_ROUTE124": "Underwater_Route124_Layout",
    "LAYOUT_UNDERWATER_ROUTE125": "Underwater_Route125_Layout",
    "LAYOUT_UNDERWATER_ROUTE126": "Underwater_Route126_Layout",
    "LAYOUT_UNDERWATER_ROUTE127": "Underwater_Route127_Layout",
    "LAYOUT_UNDERWATER_ROUTE128": "Underwater_Route128_Layout",
    "LAYOUT_UNDERWATER_ROUTE129": "Underwater_Route129_Layout",
    "LAYOUT_MARINE_CAVE_END": "MarineCave_End_Layout",
    "LAYOUT_FARAWAY_ISLAND_ENTRANCE": "FarawayIsland_Entrance_Layout",
    "LAYOUT_FARAWAY_ISLAND_INTERIOR": "FarawayIsland_Interior_Layout",
    "LAYOUT_BIRTH_ISLAND_EXTERIOR": "BirthIsland_Exterior_Layout",
    "LAYOUT_ISLAND_HARBOR": "IslandHarbor_Layout",
    "LAYOUT_TRAINER_HILL_ENTRANCE": "TrainerHill_Entrance_Layout",
    "LAYOUT_TRAINER_HILL_1F": "TrainerHill_1F_Layout",
    "LAYOUT_TRAINER_HILL_2F": "TrainerHill_2F_Layout",
    "LAYOUT_TRAINER_HILL_3F": "TrainerHill_3F_Layout",
    "LAYOUT_TRAINER_HILL_4F": "TrainerHill_4F_Layout",
    "LAYOUT_TRAINER_HILL_ROOF": "TrainerHill_Roof_Layout",
    "LAYOUT_NAVEL_ROCK_EXTERIOR": "NavelRock_Exterior_Layout",
    "LAYOUT_NAVEL_ROCK_ENTRANCE": "NavelRock_Entrance_Layout",
    "LAYOUT_NAVEL_ROCK_TOP": "NavelRock_Top_Layout",
    "LAYOUT_NAVEL_ROCK_BOTTOM": "NavelRock_Bottom_Layout",
    "LAYOUT_NAVEL_ROCK_LADDER_ROOM1": "NavelRock_LadderRoom1_Layout",
    "LAYOUT_NAVEL_ROCK_LADDER_ROOM2": "NavelRock_LadderRoom2_Layout",
    "LAYOUT_NAVEL_ROCK_B1F": "NavelRock_B1F_Layout",
    "LAYOUT_NAVEL_ROCK_FORK": "NavelRock_Fork_Layout",
    "LAYOUT_ROUTE104_PROTOTYPE": "Route104_Prototype_Layout",
    "LAYOUT_ROUTE109_SEASHORE_HOUSE": "Route109_SeashoreHouse_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_ENTRANCE": "Route110_TrickHouseEntrance_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_END": "Route110_TrickHouseEnd_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_CORRIDOR": "Route110_TrickHouseCorridor_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE1": "Route110_TrickHousePuzzle1_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE2": "Route110_TrickHousePuzzle2_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE3": "Route110_TrickHousePuzzle3_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE4": "Route110_TrickHousePuzzle4_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE5": "Route110_TrickHousePuzzle5_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE6": "Route110_TrickHousePuzzle6_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE7": "Route110_TrickHousePuzzle7_Layout",
    "LAYOUT_ROUTE110_TRICK_HOUSE_PUZZLE8": "Route110_TrickHousePuzzle8_Layout",
    "LAYOUT_ROUTE110_SEASIDE_CYCLING_ROAD_ENTRANCE": "Route110_SeasideCyclingRoadEntrance_Layout",
    "LAYOUT_ROUTE119_WEATHER_INSTITUTE_1F": "Route119_WeatherInstitute_1F_Layout",
    "LAYOUT_ROUTE119_WEATHER_INSTITUTE_2F": "Route119_WeatherInstitute_2F_Layout",
    "LAYOUT_ROUTE124_DIVING_TREASURE_HUNTERS_HOUSE": "Route124_DivingTreasureHuntersHouse_Layout",
}

# The JP layout table has not yet adopted the US shared-layout labels for these
# five resources.  Each US layout id still has one real, map-specific JP owner
# in data/layouts/layouts.inc.  Keep the mapping explicit so generated headers
# reference that owner directly instead of inventing undefined gMapLayout_* names
# or relying on .set aliases.
JP_LAYOUT_SYMBOL_OVERRIDES = {
    "LAYOUT_HOUSE1": "gMapLayout_OLDALE_TOWN_HOUSE1",
    "LAYOUT_HOUSE2": "gMapLayout_OLDALE_TOWN_HOUSE2",
    "LAYOUT_POKEMON_CENTER_1F": "gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F",
    "LAYOUT_POKEMON_CENTER_2F": "gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F",
    "LAYOUT_MART": "gMapLayout_OLDALE_TOWN_MART",
    "LAYOUT_HOUSE_WITH_BED": "gMapLayout_PETALBURG_CITY_HOUSE2",
    "LAYOUT_HARBOR": "gMapLayout_SLATEPORT_CITY_HARBOR",
    "LAYOUT_RUSTBORO_CITY_HOUSE": "gMapLayout_RUSTBORO_CITY_HOUSE2",
    "LAYOUT_EVER_GRANDE_CITY_SHORT_HALL": "gMapLayout_EVER_GRANDE_CITY_HALL1",
    "LAYOUT_HOUSE3": "gMapLayout_DEWFORD_TOWN_HOUSE1",
    "LAYOUT_HOUSE4": "gMapLayout_DEWFORD_TOWN_HOUSE2",
    "LAYOUT_BATTLE_TENT_LOBBY": "gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY",
    "LAYOUT_BATTLE_TENT_CORRIDOR": "gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR",
    "LAYOUT_BATTLE_TENT_BATTLE_ROOM": "gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM",
    "LAYOUT_CABLE_CAR_STATION": "gMapLayout_ROUTE112_CABLE_CAR_STATION",
}


def require_string(data: dict[str, Any], key: str) -> str:
    value = data.get(key)
    if not isinstance(value, str) or not value:
        raise ValueError(f"{key} must be a non-empty string")
    return value


def bool_token(value: Any, key: str) -> str:
    if value is True:
        return "TRUE"
    if value is False:
        return "FALSE"
    raise ValueError(f"{key} must be a JSON boolean")


def warning(map_name: str) -> str:
    return (
        "@\n"
        f"@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/{map_name}/map.json\n"
        "@\n"
    )


def layout_symbol(layout_id: str) -> str:
    if not layout_id.startswith("LAYOUT_"):
        raise ValueError(f"layout must begin with LAYOUT_: {layout_id}")
    return CANONICAL_LAYOUT_SYMBOLS.get(
        layout_id,
        JP_LAYOUT_SYMBOL_OVERRIDES.get(
            layout_id,
            "gMapLayout_" + layout_id.removeprefix("LAYOUT_"),
        ),
    )


def render_header(data: dict[str, Any]) -> str:
    name = require_string(data, "name")
    layout_id = require_string(data, "layout")
    events_name = data.get("shared_events_map", name)
    if not isinstance(events_name, str) or not events_name:
        raise ValueError("shared_events_map must be a non-empty string")
    scripts_name = data.get("shared_scripts_map", name)
    if not isinstance(scripts_name, str) or not scripts_name:
        raise ValueError("shared_scripts_map must be a non-empty string")
    connections = data.get("connections", [])
    if connections is None:
        connections = []
    if not isinstance(connections, list):
        raise ValueError("connections must be an array")

    connection_label = (
        f"{name}_MapConnections"
        if connections and data.get("connections_no_include") is not True
        else "NULL"
    )
    map_layout_symbol = layout_symbol(layout_id)

    return (
        f"{warning(name)}\n"
        f"{name}:\n"
        f"\t.4byte {map_layout_symbol}\n"
        f"\t.4byte {events_name}_MapEvents\n"
        f"\t.4byte {scripts_name}_MapScripts\n"
        f"\t.4byte {connection_label}\n"
        f"\t.2byte {require_string(data, 'music')}\n"
        f"\t.2byte {layout_id}\n"
        f"\t.byte {require_string(data, 'region_map_section')}\n"
        f"\t.byte {bool_token(data.get('requires_flash'), 'requires_flash')}\n"
        f"\t.byte {require_string(data, 'weather')}\n"
        f"\t.byte {require_string(data, 'map_type')}\n"
        "\t.2byte 0\n"
        "\tmap_header_flags "
        f"allow_cycling={bool_token(data.get('allow_cycling'), 'allow_cycling')}, "
        f"allow_escaping={bool_token(data.get('allow_escaping'), 'allow_escaping')}, "
        f"allow_running={bool_token(data.get('allow_running'), 'allow_running')}, "
        f"show_map_name={bool_token(data.get('show_map_name'), 'show_map_name')}\n"
        f"\t.byte {require_string(data, 'battle_scene')}\n"
    )


def render_connections(data: dict[str, Any]) -> str:
    name = require_string(data, "name")
    connections = data.get("connections", [])
    if connections is None:
        connections = []
    if not isinstance(connections, list):
        raise ValueError("connections must be an array")
    has_unused_connection_table = data.get("has_unused_connection_table", False)
    if not isinstance(has_unused_connection_table, bool):
        raise ValueError("has_unused_connection_table must be a JSON boolean")
    if not connections and not has_unused_connection_table:
        return warning(name)

    lines = [warning(name).rstrip(), "", f"{name}_MapConnectionsList:"]
    for connection in connections:
        if not isinstance(connection, dict):
            raise ValueError("each connection must be an object")
        direction = require_string(connection, "direction")
        if direction not in VALID_DIRECTIONS:
            raise ValueError(f"unsupported connection direction: {direction}")
        offset = connection.get("offset")
        if not isinstance(offset, int):
            raise ValueError("connection offset must be an integer")
        destination = require_string(connection, "map")
        lines.append(f"\tconnection {direction}, {offset}, {destination}")

    lines.extend(
        [
            "",
            f"{name}_MapConnections:",
            f"\t.4byte {len(connections)}",
            f"\t.4byte {name}_MapConnectionsList",
            "",
        ]
    )
    return "\n".join(lines)


def load_map(path: Path) -> dict[str, Any]:
    data = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(data, dict):
        raise ValueError("map JSON root must be an object")
    return data


def write_if_changed(path: Path, text: str) -> bool:
    if path.is_file() and path.read_text(encoding="utf-8") == text:
        return False
    path.write_text(text, encoding="utf-8")
    return True


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("map_json", type=Path)
    parser.add_argument("output_dir", type=Path)
    parser.add_argument("--check", action="store_true", help="fail instead of rewriting stale outputs")
    args = parser.parse_args()

    data = load_map(args.map_json)
    outputs = {
        args.output_dir / "header.inc": render_header(data),
        args.output_dir / "connections.inc": render_connections(data),
    }

    stale = [path for path, text in outputs.items()
             if not path.is_file() or path.read_text(encoding="utf-8") != text]
    if args.check:
        if stale:
            raise SystemExit("stale map metadata: " + ", ".join(str(path) for path in stale))
        return

    args.output_dir.mkdir(parents=True, exist_ok=True)
    changed = [path for path, text in outputs.items() if write_if_changed(path, text)]
    if changed:
        print("updated " + ", ".join(str(path) for path in changed))


if __name__ == "__main__":
    main()
