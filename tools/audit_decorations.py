#!/usr/bin/env python3
"""Verify the byte-level JP decoration manifest without extracting assets.

The decoration data is physically contiguous in the Japanese ROM, even while
its source is still split across temporary ``data_b2d_mid61.s`` labels.  This
tool records the invariant layout and validates it directly from input ROM
bytes.  It never writes extracted data: use its deterministic JSON output as a
reviewable manifest, and optionally compare a linked candidate ROM against the
same baseline slices after a source migration.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROM_BASE = 0x08000000
TILES_START = 0x0857FE04
TEXT_START = 0x08580038
TABLE_START = 0x08580CD0
TABLE_END = 0x08581A0C
RECORD_SIZE = 0x1C
RECORD_COUNT = 121
DESCRIPTION_COUNT = 120
RECORD = struct.Struct("<B11sBBBBIII")
MAP_SYMBOL_RE = re.compile(r"^\s*0x([0-9A-Fa-f]+)\s+gDecorations\s*$", re.MULTILINE)


class AuditError(ValueError):
    """The input does not satisfy the fixed JP decoration layout contract."""


def fail(message: str) -> None:
    raise AuditError(f"audit_decorations: {message}")


def rom_slice(data: bytes, start: int, end: int) -> bytes:
    """Return an absolute-ROM-address slice, rejecting truncated inputs."""
    if start < ROM_BASE or end < start:
        fail(f"invalid ROM range 0x{start:08X}..0x{end:08X}")
    start_offset = start - ROM_BASE
    end_offset = end - ROM_BASE
    if end_offset > len(data):
        fail(f"ROM is too short for 0x{start:08X}..0x{end:08X}")
    return data[start_offset:end_offset]


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def terminated_text_end(data: bytes, start: int, limit: int) -> int:
    """Find a description's inclusive 0xFF terminator before *limit*."""
    raw = rom_slice(data, start, limit)
    try:
        return start + raw.index(0xFF) + 1
    except ValueError:
        fail(f"description at 0x{start:08X} has no 0xFF terminator")


def decode_name_bytes(name: bytes, record_id: int) -> bytes:
    """Validate the fixed 11-byte JP name field and return its payload bytes."""
    try:
        end = name.index(0xFF)
    except ValueError:
        fail(f"record {record_id} name has no 0xFF terminator")
    if end == 0:
        fail(f"record {record_id} has an empty name")
    if any(byte != 0xFF for byte in name[end:]):
        fail(f"record {record_id} name padding is not 0xFF")
    return name[:end]


def audit_bytes(data: bytes) -> dict[str, object]:
    """Return the deterministic manifest after validating every table record."""
    table = rom_slice(data, TABLE_START, TABLE_END)
    if len(table) != RECORD_SIZE * RECORD_COUNT:
        fail("table range does not equal 121 records of 0x1C bytes")

    records = []
    description_pointers = []
    tile_pointers = []
    for index in range(RECORD_COUNT):
        offset = index * RECORD_SIZE
        record_id, name, permission, shape, category, padding, price, description, tiles = RECORD.unpack_from(table, offset)
        if record_id != index:
            fail(f"record {index} has id {record_id}, expected {index}")
        name_payload = decode_name_bytes(name, record_id)
        if permission not in range(5):
            fail(f"record {record_id} has invalid permission {permission}")
        if shape not in {0, 1, 3, 4, 5, 7, 8, 9}:
            fail(f"record {record_id} has invalid shape {shape}")
        if category not in range(8):
            fail(f"record {record_id} has invalid category {category}")
        if padding != 0:
            fail(f"record {record_id} has nonzero padding {padding}")
        if not TEXT_START <= description < TABLE_START:
            fail(f"record {record_id} description pointer 0x{description:08X} is outside the text block")
        if not TILES_START <= tiles < TEXT_START:
            fail(f"record {record_id} tiles pointer 0x{tiles:08X} is outside the tiles block")
        records.append({
            "id": record_id,
            "name_bytes": name_payload.hex(),
            "permission": permission,
            "shape": shape,
            "category": category,
            "price": price,
            "description": f"0x{description:08X}",
            "tiles": f"0x{tiles:08X}",
        })
        description_pointers.append(description)
        tile_pointers.append(tiles)

    unique_descriptions = sorted(set(description_pointers))
    if len(unique_descriptions) != DESCRIPTION_COUNT:
        fail(f"expected {DESCRIPTION_COUNT} unique description pointers, found {len(unique_descriptions)}")
    if unique_descriptions[0] != TEXT_START:
        fail(f"first description is 0x{unique_descriptions[0]:08X}, expected 0x{TEXT_START:08X}")
    description_ranges = []
    for position, start in enumerate(unique_descriptions):
        expected_end = unique_descriptions[position + 1] if position + 1 < len(unique_descriptions) else TABLE_START
        end = terminated_text_end(data, start, expected_end)
        if end != expected_end:
            fail(f"description 0x{start:08X} ends at 0x{end:08X}, expected 0x{expected_end:08X}")
        payload = rom_slice(data, start, end - 1)
        if 0xFC in payload or 0xFD in payload:
            fail(f"description 0x{start:08X} has unsupported extended control bytes")
        description_ranges.append({"start": f"0x{start:08X}", "end": f"0x{end:08X}"})

    unique_tiles = sorted(set(tile_pointers))
    if len(unique_tiles) != DESCRIPTION_COUNT:
        fail(f"expected {DESCRIPTION_COUNT} unique tiles pointers, found {len(unique_tiles)}")
    if unique_tiles[0] != TILES_START or unique_tiles[-1] >= TEXT_START:
        fail("tiles pointers do not stay within the fixed tiles block")

    ranges = (
        ("tiles", TILES_START, TEXT_START),
        ("descriptions", TEXT_START, TABLE_START),
        ("records", TABLE_START, TABLE_END),
        ("module", TILES_START, TABLE_END),
    )
    return {
        "format": 1,
        "rom_base": f"0x{ROM_BASE:08X}",
        "record_size": RECORD_SIZE,
        "record_count": RECORD_COUNT,
        "description_count": len(unique_descriptions),
        "tile_pointer_count": len(unique_tiles),
        "ranges": [
            {
                "name": name,
                "start": f"0x{start:08X}",
                "end": f"0x{end:08X}",
                "size": end - start,
                "sha256": sha256(rom_slice(data, start, end)),
            }
            for name, start, end in ranges
        ],
        "description_ranges": description_ranges,
        "records": records,
    }


def check_link_map(path: Path) -> dict[str, object]:
    """Check the sole stable table anchor needed after source restructuring."""
    matches = [int(value, 16) for value in MAP_SYMBOL_RE.findall(path.read_text(encoding="utf-8", errors="replace"))]
    if matches != [TABLE_START]:
        fail(f"{path} must define gDecorations exactly once at 0x{TABLE_START:08X}; found {matches}")
    return {"path": str(path), "gDecorations": f"0x{TABLE_START:08X}"}


def compare_candidate(baseline: bytes, candidate: bytes) -> list[dict[str, object]]:
    """Prove that every owned physical slice is byte-identical in a candidate."""
    result = []
    for name, start, end in (
        ("tiles", TILES_START, TEXT_START),
        ("descriptions", TEXT_START, TABLE_START),
        ("records", TABLE_START, TABLE_END),
    ):
        expected = rom_slice(baseline, start, end)
        actual = rom_slice(candidate, start, end)
        if actual != expected:
            fail(f"candidate differs from baseline in {name} 0x{start:08X}..0x{end:08X}")
        result.append({"name": name, "sha256": sha256(actual)})
    return result


def render_human(manifest: dict[str, object]) -> str:
    lines = [
        f"Decoration records: {manifest['record_count']} x 0x{manifest['record_size']:X}",
        f"JP descriptions: {manifest['description_count']}; tiles pointers: {manifest['tile_pointer_count']}",
    ]
    for item in manifest["ranges"]:
        lines.append(f"{item['name']}: {item['start']}..{item['end']} ({item['size']:#x}) {item['sha256']}")
    return "\n".join(lines)


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rom", type=Path, default=ROOT / "baserom_jp.gba", help="baseline JP ROM (read only)")
    parser.add_argument("--map", dest="link_map", type=Path, help="optional linked map to verify gDecorations placement")
    parser.add_argument("--candidate-rom", type=Path, help="optional linked ROM to compare against the baseline slices")
    parser.add_argument("--json", action="store_true", help="emit the full stable JSON manifest")
    args = parser.parse_args(argv)

    baseline = args.rom.read_bytes()
    manifest = audit_bytes(baseline)
    if args.link_map is not None:
        manifest["link_map"] = check_link_map(args.link_map)
    if args.candidate_rom is not None:
        manifest["candidate_slices"] = compare_candidate(baseline, args.candidate_rom.read_bytes())
    if args.json:
        print(json.dumps(manifest, ensure_ascii=False, indent=2, sort_keys=True))
    else:
        print(render_human(manifest))
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except AuditError as error:
        print(error, file=sys.stderr)
        raise SystemExit(1)
