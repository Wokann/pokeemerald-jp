#!/usr/bin/env python3
"""Generate reproducible JP map-header and map-script-table metadata.

Older script-migration helpers expected hand-created files in /tmp.  This
module rebuilds that information directly from the matching Japanese ROM and
the upstream map-group ordering, so the result is reproducible after a clean
checkout and never depends on a stale temporary file.
"""

from __future__ import annotations

import argparse
import json
from dataclasses import asdict, dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
BASEROM = ROOT / "baserom_jp.gba"
US_MAP_GROUPS = Path("/home/kenny/pokeemerald/data/maps/map_groups.json")

ROM_BASE = 0x08000000
MAP_HEADERS_START = 0x0845A8D8
MAP_HEADER_SIZE = 0x1C
MAP_GROUPS_ADDR = 0x0845E998
MAP_GROUP_COUNT = 34
MAP_SCRIPT_TAGS = frozenset(range(1, 8))


class MetadataError(ValueError):
    """The ROM does not match the expected JP map-header layout."""


@dataclass(frozen=True)
class MapHeader:
    group: int
    map_num: int
    name: str
    address: int
    layout: int
    events: int
    map_scripts: int
    connections: int


def _hex(value: int) -> str:
    return f"0x{value:08X}"


def _read_u32(rom: bytes, address: int) -> int:
    offset = address - ROM_BASE
    if offset < 0 or offset + 4 > len(rom):
        raise MetadataError(f"ROM read outside bounds at {_hex(address)}")
    return int.from_bytes(rom[offset : offset + 4], "little")


def _assert_rom_address(address: int, description: str) -> None:
    if not ROM_BASE <= address < ROM_BASE + 0x02000000:
        raise MetadataError(f"{description} is not a ROM pointer: {_hex(address)}")


def map_names() -> list[list[str]]:
    if not US_MAP_GROUPS.is_file():
        raise MetadataError(f"missing upstream map ordering: {US_MAP_GROUPS}")
    data = json.loads(US_MAP_GROUPS.read_text(encoding="utf-8"))
    order = data.get("group_order")
    if not isinstance(order, list) or len(order) < MAP_GROUP_COUNT:
        raise MetadataError("upstream map_groups.json has fewer than 34 map groups")
    groups = []
    for group_key in order[:MAP_GROUP_COUNT]:
        names = data.get(group_key)
        if not isinstance(names, list):
            raise MetadataError(f"upstream map group {group_key!r} is not a list")
        groups.append(names)
    return groups


def parse_map_script_table(rom: bytes, address: int) -> list[tuple[int, int]]:
    """Read ``u8 tag; u32 ptr`` entries through the zero tag terminator."""
    if address == 0:
        return []
    _assert_rom_address(address, "map-script table")
    entries: list[tuple[int, int]] = []
    for _ in range(32):
        offset = address - ROM_BASE
        if offset + 5 > len(rom):
            raise MetadataError(f"truncated map-script table at {_hex(address)}")
        tag = rom[offset]
        if tag == 0:
            return entries
        if tag not in MAP_SCRIPT_TAGS:
            raise MetadataError(
                f"invalid map-script tag {tag} in table at {_hex(address)}"
            )
        pointer = _read_u32(rom, address + 1)
        _assert_rom_address(pointer, f"map-script pointer in table {_hex(address)}")
        entries.append((tag, pointer))
        address += 5
    raise MetadataError("map-script table has no terminator within 32 entries")


def build_metadata(rom_path: Path = BASEROM) -> tuple[list[MapHeader], dict[int, list[tuple[int, int]]]]:
    """Read every JP MapHeader in the upstream group/map order."""
    if not rom_path.is_file():
        raise MetadataError(f"missing matching Japanese baserom: {rom_path}")
    rom = rom_path.read_bytes()
    groups = map_names()
    headers: list[MapHeader] = []
    tables: dict[int, list[tuple[int, int]]] = {}
    seen_headers: set[int] = set()
    group_tables = [
        _read_u32(rom, MAP_GROUPS_ADDR + group_index * 4)
        for group_index in range(MAP_GROUP_COUNT)
    ]
    for group_index, group_table in enumerate(group_tables):
        _assert_rom_address(group_table, f"map group {group_index}")
    # The group-pointer arrays directly follow the final MapHeader.  Their
    # first address is a ROM-derived boundary, avoiding a stale hand-count.
    map_headers_end = min(group_tables)
    if (map_headers_end - MAP_HEADERS_START) % MAP_HEADER_SIZE:
        raise MetadataError("gMapHeaders boundary is not 0x1C-aligned")

    for group_index, group in enumerate(groups):
        group_table = group_tables[group_index]
        for map_index, name in enumerate(group):
            header_addr = _read_u32(rom, group_table + map_index * 4)
            if not (MAP_HEADERS_START <= header_addr < map_headers_end):
                raise MetadataError(
                    f"{name} header {_hex(header_addr)} is outside gMapHeaders"
                )
            if (header_addr - MAP_HEADERS_START) % MAP_HEADER_SIZE:
                raise MetadataError(f"{name} header {_hex(header_addr)} is not 0x1C-aligned")
            if header_addr in seen_headers:
                raise MetadataError(f"duplicate map header {_hex(header_addr)} for {name}")
            seen_headers.add(header_addr)

            layout = _read_u32(rom, header_addr)
            events = _read_u32(rom, header_addr + 4)
            map_scripts = _read_u32(rom, header_addr + 8)
            connections = _read_u32(rom, header_addr + 12)
            header = MapHeader(
                group=group_index,
                map_num=map_index,
                name=name,
                address=header_addr,
                layout=layout,
                events=events,
                map_scripts=map_scripts,
                connections=connections,
            )
            headers.append(header)
            if map_scripts:
                tables.setdefault(map_scripts, parse_map_script_table(rom, map_scripts))

    expected_header_count = (map_headers_end - MAP_HEADERS_START) // MAP_HEADER_SIZE
    if len(headers) != expected_header_count:
        raise MetadataError(
            f"upstream ordering yielded {len(headers)} maps; expected {expected_header_count}"
        )
    if len(seen_headers) != expected_header_count:
        raise MetadataError(
            f"only {len(seen_headers)} unique headers; expected {expected_header_count}"
        )
    return headers, tables


def legacy_map_headers(headers: list[MapHeader]) -> list[list[object]]:
    """Serialize the tuple shape consumed by the pre-existing JP helpers."""
    return [
        [
            header.group,
            header.map_num,
            _hex(header.address),
            _hex(header.layout),
            _hex(header.events),
            _hex(header.map_scripts),
            "0x00000000",  # legacy wild-data slot; unused by script tools
            header.name,
        ]
        for header in headers
    ]


def legacy_map_tables(tables: dict[int, list[tuple[int, int]]]) -> dict[str, list[list[object]]]:
    return {
        hex(address): [[tag, _hex(pointer)] for tag, pointer in entries]
        for address, entries in sorted(tables.items())
    }


def write_metadata(output_dir: Path, headers: list[MapHeader], tables: dict[int, list[tuple[int, int]]]) -> None:
    output_dir.mkdir(parents=True, exist_ok=True)
    (output_dir / "jp_map_headers.json").write_text(
        json.dumps(legacy_map_headers(headers), ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8",
    )
    (output_dir / "map_script_tables.json").write_text(
        json.dumps(legacy_map_tables(tables), ensure_ascii=False, indent=2) + "\n",
        encoding="utf-8",
    )
    summary = {
        "map_group_count": MAP_GROUP_COUNT,
        "map_count": len(headers),
        "headers_with_map_scripts": sum(bool(header.map_scripts) for header in headers),
        "unique_map_script_tables": len(tables),
        "map_script_entries": sum(len(entries) for entries in tables.values()),
        "first_header": asdict(headers[0]),
        "last_header": asdict(headers[-1]),
    }
    (output_dir / "summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=ROOT / "build" / "jp_map_script_metadata",
        help="generated metadata directory (default: build/jp_map_script_metadata)",
    )
    parser.add_argument("--check", action="store_true", help="validate and print counts without writing files")
    args = parser.parse_args()

    headers, tables = build_metadata()
    if not args.check:
        write_metadata(args.output_dir, headers, tables)
        print(f"wrote {args.output_dir}")
    print(f"map groups: {MAP_GROUP_COUNT}")
    print(f"map headers: {len(headers)}")
    print(f"headers with map scripts: {sum(bool(header.map_scripts) for header in headers)}")
    print(f"unique map-script tables: {len(tables)}")
    print(f"map-script entries: {sum(len(entries) for entries in tables.values())}")


if __name__ == "__main__":
    main()
