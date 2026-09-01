#!/usr/bin/env python3
"""Report map-data ownership after removing the temporary mid30 aggregate.

JP ROM offsets come only from JP ``.incbin "baserom_jp.gba"`` directives.
US paths classify final source ownership, but never supply JP boundaries.
"""

from __future__ import annotations

import argparse
import json
import re
from collections import Counter
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_US_ROOT = ROOT.parent.parent / "pokeemerald"
MAPS = Path("data/maps.s")
LAYOUTS = Path("data/layouts/layouts.inc")
ROM_BASE = 0x08000000

RAW_RE = re.compile(
    r'^\s*\.incbin\s+"baserom_jp\.gba"\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*,\s*'
    r'(0x[0-9A-Fa-f]+|\d+)\s*(?:@.*)?$')
INCLUDE_RE = re.compile(r'^\s*\.include\s+"([^"]+)"\s*$')
LABEL_RE = re.compile(r'^\s*([A-Za-z_]\w*)::?\s*(?:@\s*0x([0-9A-Fa-f]{8}))?\s*$')
MAP_INCLUDE_RE = re.compile(r'^data/maps/([^/]+)/(header|connections)\.inc$')
MAP_AGGREGATES = {
    Path("data/maps/headers.inc"),
    Path("data/maps/connections.inc"),
}
MAP_HEADER_COMMENT_RE = re.compile(r'^\s*@\s*(MAP_[A-Z0-9_]+)\s+\(g\d+ m\d+\)\s*$')
CONNECTION_LABEL_RE = re.compile(r'^\s*gMapConnections_([A-Z0-9_]+):')
LAYOUT_LABEL_RE = re.compile(
    r'^\s*(gMapLayout_[A-Za-z0-9_]+|[A-Za-z_]\w*_Layout)::?\s*(?:@.*)?$', re.MULTILINE)


def hex_address(value: int) -> str:
    return f"0x{value:08X}"


def raw_spans(lines: list[str]) -> list[dict[str, object]]:
    """Return exact, independently checkable JP ROM intervals."""
    previous_label = None
    result = []
    for line_number, line in enumerate(lines, 1):
        if match := LABEL_RE.match(line):
            previous_label = match.group(1)
        if not (match := RAW_RE.match(line)):
            continue
        offset, size = int(match.group(1), 0), int(match.group(2), 0)
        start = ROM_BASE + offset
        result.append({
            "source_line": line_number,
            "label": previous_label,
            "file_offset": f"0x{offset:X}",
            "rom_start": hex_address(start),
            "rom_end": hex_address(start + size),
            "size": f"0x{size:X}",
            "directive": line.strip(),
            "classification": "raw_baserom_requires_boundary_audit",
            "final_us_owner": None,
        })
    return result


def expand_map_aggregates(root: Path, lines: list[str]) -> list[str]:
    """Inline the two map owner aggregates in their source position."""
    result = []
    for line in lines:
        include = INCLUDE_RE.match(line)
        path = Path(include.group(1)) if include else None
        candidate = root / path if path is not None else None
        if path not in MAP_AGGREGATES or candidate is None or not candidate.is_file():
            result.append(line)
            continue
        result.extend(candidate.read_text(encoding="utf-8", errors="replace").splitlines())
    return result


def map_include_records(root: Path, us_root: Path, lines: list[str]) -> list[dict[str, object]]:
    """Classify direct map header/connection includes by their final path."""
    records = []
    for line_number, line in enumerate(lines, 1):
        if not (include := INCLUDE_RE.match(line)):
            continue
        path = include.group(1)
        if not (match := MAP_INCLUDE_RE.match(path)):
            continue
        map_name, component = match.groups()
        records.append({
            "source_line": line_number,
            "rom_start": None,
            "rom_end": None,
            "rom_order_evidence": "maps source order; no numeric JP boundary inferred",
            "classification": f"map_{component}_final_owner",
            "map": map_name,
            "final_us_owner": path,
            "jp_owner_exists": (root / path).is_file(),
            "us_owner_exists": (us_root / path).is_file(),
            "semantic_review": "not_recorded",
        })
    return records


def map_paths_by_id(root: Path) -> dict[str, str]:
    """Return map-id-to-directory mappings only from tracked map metadata."""
    paths = {}
    for path in sorted((root / "data/maps").glob("*/map.json")):
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            continue
        map_id = payload.get("id")
        if isinstance(map_id, str):
            paths.setdefault(map_id, path.parent.relative_to(root).as_posix())
    return paths


def pending_map_component_records(root: Path, us_root: Path, lines: list[str]) -> list[dict[str, object]]:
    """Map direct source components to a verified US path, without extracting them."""
    id_paths = map_paths_by_id(root)
    records = []
    for line_number, line in enumerate(lines, 1):
        component = None
        if match := MAP_HEADER_COMMENT_RE.match(line):
            map_id, component = match.group(1), "header"
        elif match := CONNECTION_LABEL_RE.match(line):
            map_id, component = "MAP_" + match.group(1), "connections"
        else:
            continue
        directory = id_paths.get(map_id)
        if directory is None:
            continue
        path = f"{directory}/{component}.inc"
        records.append({
            "source_line": line_number,
            "rom_start": None,
            "rom_end": None,
            "rom_order_evidence": "maps source order; no numeric JP boundary inferred",
            "classification": f"map_{component}_mapped_pending_extraction",
            "map_id": map_id,
            "final_us_owner": path,
            "jp_owner_exists": (root / path).is_file(),
            "us_owner_exists": (us_root / path).is_file(),
            "semantic_review": "not_recorded",
        })
    return records


def layout_record(root: Path, us_root: Path, lines: list[str], raws: list[dict[str, object]]) -> dict[str, object] | None:
    """Describe the one final-layout include with JP-adjacent boundary proof."""
    include_line = next((number for number, line in enumerate(lines, 1)
                         if INCLUDE_RE.match(line) and INCLUDE_RE.match(line).group(1) == str(LAYOUTS)), None)
    if include_line is None:
        return None
    before = [item for item in raws if item["source_line"] < include_line]
    after = [item for item in raws if item["source_line"] > include_line]
    previous = before[-1] if before else None
    following = after[0] if after else None
    layout_path = root / LAYOUTS
    labels = LAYOUT_LABEL_RE.findall(layout_path.read_text(encoding="utf-8", errors="replace")) \
        if layout_path.is_file() else []
    labels = [name for name in labels if not name.endswith(("_Border", "_Blockdata"))]
    return {
        "source_line": include_line,
        "classification": "layouts_final_owner",
        "final_us_owner": str(LAYOUTS),
        "jp_owner_exists": layout_path.is_file(),
        "us_owner_exists": (us_root / LAYOUTS).is_file(),
        "structured_layouts": len(labels),
        "rom_start": previous["rom_end"] if previous else None,
        "rom_end": following["rom_start"] if following else None,
        "rom_boundary_evidence": (
            "adjacent JP raw spans" if previous and following else "missing adjacent JP raw span"),
        "semantic_review": "not_recorded",
    }


def report(root: Path, us_root: Path) -> dict[str, object]:
    path = root / MAPS
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    map_lines = expand_map_aggregates(root, lines)
    raws = raw_spans(lines)
    maps = map_include_records(root, us_root, map_lines)
    pending_maps = pending_map_component_records(root, us_root, map_lines)
    layouts = layout_record(root, us_root, lines, raws)
    regions = sorted(raws + maps + pending_maps + ([layouts] if layouts else []),
                     key=lambda item: item["source_line"])
    counts = Counter(item["classification"] for item in regions)
    first_pending = next((item for item in regions
                          if item["classification"] == "raw_baserom_requires_boundary_audit"), None)
    return {
        "schema": 2,
        "inputs": {"jp": str(MAPS), "us_root": str(us_root)},
        "method": {
            "jp_rom_rule": "Only JP raw incbin offsets and lengths define numeric JP ranges.",
            "us_rule": "US paths classify final structure only; US numeric addresses are ignored.",
            "maps_rule": "Map include existence is structural evidence, never semantic-review completion.",
        },
        "summary": {
            "raw_baserom_regions": len(raws),
            "map_header_final_owners": sum(item["classification"] == "map_header_final_owner" for item in maps),
            "map_connections_final_owners": sum(item["classification"] == "map_connections_final_owner" for item in maps),
            "map_header_mapped_pending_extraction": sum(
                item["classification"] == "map_header_mapped_pending_extraction" for item in pending_maps),
            "map_connections_mapped_pending_extraction": sum(
                item["classification"] == "map_connections_mapped_pending_extraction" for item in pending_maps),
            "structured_layouts": layouts["structured_layouts"] if layouts else 0,
            "classification_counts": dict(sorted(counts.items())),
        },
        "regions_in_physical_source_order": regions,
        "first_unresolved_boundary": first_pending,
        "protected_from_script_data_sweep": {
            "final_map_owners": [item["final_us_owner"] for item in maps],
            "layouts_final_owner": layouts["final_us_owner"] if layouts else None,
            "first_raw_boundary": first_pending,
        },
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--us-root", type=Path, default=DEFAULT_US_ROOT)
    parser.add_argument("--output", type=Path, help="write deterministic JSON report")
    parser.add_argument("--json", action="store_true", help="print deterministic JSON report")
    args = parser.parse_args()
    if args.output and args.output.suffix.lower() != ".json":
        raise SystemExit("--output must name a JSON file")
    payload = json.dumps(report(ROOT, args.us_root.resolve()), ensure_ascii=False, indent=2,
                         sort_keys=True) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(payload, encoding="utf-8")
    if args.json or not args.output:
        print(payload, end="")


if __name__ == "__main__":
    main()
