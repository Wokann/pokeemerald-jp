#!/usr/bin/env python3
"""Generate JP-local map header and connection sources from canonical map.json.

Layout owner symbols come from the checked-in local ``data/layouts/layouts.json``
source of truth.  This keeps the JP header generator independent of a sibling
US checkout while emitting the same ``*_Layout`` symbols as the final project
structure.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any


VALID_DIRECTIONS = {"down", "up", "left", "right", "dive", "emerge"}
ROOT = Path(__file__).resolve().parents[1]
LAYOUTS_JSON = ROOT / "data/layouts/layouts.json"


def load_layout_symbols() -> dict[str, str]:
    data = json.loads(LAYOUTS_JSON.read_text(encoding="utf-8"))
    layouts = data.get("layouts")
    if not isinstance(layouts, list):
        raise ValueError(f"{LAYOUTS_JSON} must contain a layouts array")

    symbols = {}
    for entry in layouts:
        if not isinstance(entry, dict):
            raise ValueError("each layout metadata entry must be an object")
        layout_id = entry.get("id")
        symbol = entry.get("name")
        if not isinstance(layout_id, str) or not layout_id.startswith("LAYOUT_"):
            raise ValueError(f"invalid layout id in {LAYOUTS_JSON}: {layout_id!r}")
        if not isinstance(symbol, str) or not symbol.endswith("_Layout"):
            raise ValueError(f"invalid layout symbol in {LAYOUTS_JSON}: {symbol!r}")
        if layout_id in symbols:
            raise ValueError(f"duplicate layout id in {LAYOUTS_JSON}: {layout_id}")
        symbols[layout_id] = symbol
    return symbols


LAYOUT_SYMBOLS = load_layout_symbols()


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
    try:
        return LAYOUT_SYMBOLS[layout_id]
    except KeyError as error:
        raise ValueError(f"unknown layout id in {LAYOUTS_JSON}: {layout_id}") from error


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
