#!/usr/bin/env python3
"""Audit map-script owners in the physical ``event_scripts.s`` order.

The map-script source is intentionally a mixture of fully structured maps,
partially structured maps, and raw ROM owners.  A directory merely existing
on disk is not evidence that it was reviewed or committed.  This tool makes
that distinction explicit so an untracked or half-generated map owner cannot
silently be skipped while later physical owners are converted.

The report is read-only.  ``--strict`` returns non-zero only for conditions
that make an owner unsafe to advance past: a missing included script or an
entirely untracked map directory that participates in the ordered sequence.
Raw and event-unstructured maps remain visible as pending work rather than
being reported as build errors.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MAP_SCRIPT_INCLUDE_RE = re.compile(
    r'^\s*\.include\s+"data/maps/([^/]+)/scripts\.inc"\s*$')
RAW_MAP_HEADER_RE = re.compile(
    r'^@\s+([A-Za-z0-9_]+)\s+scripts\s+\(JP map\b')
INCBIN_RE = re.compile(r'^\s*\.incbin\s+"baserom_jp\.gba"')
EVENT_INCLUDE_RE = re.compile(
    r'^\s*\.include\s+"data/maps/([^/]+)/events\.inc"\s*$')


def git_bytes(root: Path, *args: str) -> bytes:
    result = subprocess.run(
        ("git", "-C", str(root), *args),
        check=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    return result.stdout


def tracked_paths(root: Path) -> set[Path]:
    output = git_bytes(root, "ls-files", "-z", "--", "data/maps")
    return {Path(item.decode("utf-8")) for item in output.split(b"\0") if item}


def untracked_paths(root: Path) -> set[Path]:
    output = git_bytes(root, "status", "--porcelain=v1", "-z", "--untracked-files=all")
    result: set[Path] = set()
    for item in output.split(b"\0"):
        if item.startswith(b"?? "):
            result.add(Path(item[3:].decode("utf-8")))
    return result


def event_include_paths(root: Path) -> set[str]:
    names: set[str] = set()
    for path in sorted(root.joinpath("data").rglob("*")):
        if not path.is_file() or path.suffix not in {".s", ".inc"}:
            continue
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            match = EVENT_INCLUDE_RE.match(line)
            if match:
                names.add(match.group(1))
    return names


def ordered_owners(root: Path) -> list[dict[str, object]]:
    event_scripts = root / "data/event_scripts.s"
    owners: list[dict[str, object]] = []
    raw_header: tuple[str, int] | None = None

    for line_number, line in enumerate(
            event_scripts.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
        include_match = MAP_SCRIPT_INCLUDE_RE.match(line)
        if include_match:
            owners.append({
                "kind": "included",
                "name": include_match.group(1),
                "line": line_number,
            })
            raw_header = None
            continue

        header_match = RAW_MAP_HEADER_RE.match(line)
        if header_match:
            raw_header = (header_match.group(1), line_number)
            continue

        if raw_header is not None and INCBIN_RE.match(line):
            owners.append({
                "kind": "raw",
                "name": raw_header[0],
                "line": raw_header[1],
                "raw_incbin_line": line_number,
            })
            raw_header = None

    return owners


def map_directory_untracked(
        name: str, tracked: set[Path], untracked: set[Path]) -> bool:
    prefix = Path("data/maps") / name
    has_tracked = any(path.is_relative_to(prefix) for path in tracked)
    has_untracked = any(path.is_relative_to(prefix) for path in untracked)
    return has_untracked and not has_tracked


def audit(root: Path) -> dict[str, object]:
    tracked = tracked_paths(root)
    untracked = untracked_paths(root)
    event_includes = event_include_paths(root)
    ordered = ordered_owners(root)
    raw_owners = [owner for owner in ordered if owner["kind"] == "raw"]
    owner_rows: list[dict[str, object]] = []
    untracked_dirs: set[str] = set()

    for ordinal, owner in enumerate(ordered, 1):
        name = str(owner["name"])
        kind = str(owner["kind"])
        map_dir = root / "data/maps" / name
        scripts = map_dir / "scripts.inc"
        map_json = map_dir / "map.json"
        events = map_dir / "events.inc"
        scripts_rel = scripts.relative_to(root)
        json_rel = map_json.relative_to(root)
        events_rel = events.relative_to(root)
        script_text = scripts.read_text(encoding="utf-8", errors="replace") if scripts.exists() else ""
        has_raw_script = kind == "included" and bool(INCBIN_RE.search(script_text))
        completely_untracked = map_directory_untracked(name, tracked, untracked)
        if completely_untracked:
            untracked_dirs.add(name)

        row = {
            "ordinal": ordinal,
            "name": name,
            "owner_kind": kind,
            "event_scripts_line": owner["line"],
            "raw_incbin_line": owner.get("raw_incbin_line"),
            "scripts_exists": scripts.exists(),
            "scripts_tracked": scripts_rel in tracked,
            "scripts_contains_raw_incbin": has_raw_script,
            "map_json_exists": map_json.exists(),
            "map_json_tracked": json_rel in tracked,
            "events_exists": events.exists(),
            "events_tracked": events_rel in tracked,
            "events_linked_from_data": name in event_includes,
            "entire_map_directory_untracked": completely_untracked,
        }
        owner_rows.append(row)

    map_root = root / "data/maps"
    for directory in sorted(path for path in map_root.iterdir() if path.is_dir()):
        name = directory.name
        if map_directory_untracked(name, tracked, untracked):
            untracked_dirs.add(name)

    included_rows = [row for row in owner_rows if row["owner_kind"] == "included"]
    missing_includes = [row["name"] for row in included_rows if not row["scripts_exists"]]
    untracked_included_scripts = [
        row["name"] for row in included_rows
        if row["scripts_exists"] and not row["scripts_tracked"]
    ]
    untracked_ordered = [
        row["name"] for row in included_rows
        if row["entire_map_directory_untracked"] or not row["scripts_tracked"]
    ]
    raw_scripts = [row["name"] for row in owner_rows if row["scripts_contains_raw_incbin"]]
    fully_event_structured = [
        row["name"] for row in owner_rows
        if row["owner_kind"] == "included"
        and row["map_json_tracked"] and row["events_tracked"] and row["events_linked_from_data"]
    ]
    partial_events = [
        row["name"] for row in owner_rows
        if row["owner_kind"] == "included"
        and (row["map_json_exists"] or row["events_exists"] or row["events_linked_from_data"])
        and row["name"] not in fully_event_structured
    ]

    summary = {
        "ordered_map_script_owners": len(owner_rows),
        "included_map_script_owners": len(included_rows),
        "raw_map_script_owners": len(raw_owners),
        "raw_scripts_inside_included_maps": len(raw_scripts),
        "fully_event_structured": len(fully_event_structured),
        "partially_event_structured": len(partial_events),
        "missing_included_scripts": len(missing_includes),
        "untracked_included_scripts": len(untracked_included_scripts),
        "untracked_map_directories": len(untracked_dirs),
        "untracked_ordered_owners": len(untracked_ordered),
    }
    return {
        "summary": summary,
        "owners": owner_rows,
        "raw_owners": raw_owners,
        "missing_included_scripts": missing_includes,
        "untracked_included_scripts": untracked_included_scripts,
        "untracked_map_directories": sorted(untracked_dirs),
        "untracked_ordered_owners": untracked_ordered,
        "raw_scripts_inside_included_maps": raw_scripts,
        "partially_event_structured": partial_events,
    }


def print_text(report: dict[str, object], max_list: int) -> None:
    summary = report["summary"]
    assert isinstance(summary, dict)
    print("Map script owner coverage")
    for key in (
            "ordered_map_script_owners", "raw_map_script_owners",
            "included_map_script_owners",
            "raw_scripts_inside_included_maps", "fully_event_structured",
            "partially_event_structured", "missing_included_scripts",
            "untracked_included_scripts", "untracked_map_directories",
            "untracked_ordered_owners"):
        print(f"{key}: {summary[key]}")

    for title, key in (
            ("Missing included scripts", "missing_included_scripts"),
            ("Untracked included scripts", "untracked_included_scripts"),
            ("Untracked ordered owners", "untracked_ordered_owners"),
            ("Untracked map directories", "untracked_map_directories"),
            ("Raw scripts inside included maps", "raw_scripts_inside_included_maps"),
            ("Partially event-structured owners", "partially_event_structured")):
        values = report[key]
        assert isinstance(values, list)
        if values:
            shown = ", ".join(str(value) for value in values[:max_list])
            suffix = " …" if len(values) > max_list else ""
            print(f"{title}: {shown}{suffix}")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT,
                        help="pokeemerald-jp root (default: script parent)")
    parser.add_argument("--json", action="store_true", help="emit stable JSON")
    parser.add_argument("--strict", action="store_true",
                        help="fail for missing included scripts or untracked ordered owners")
    parser.add_argument("--max-list", type=int, default=25,
                        help="maximum text entries per category")
    parser.add_argument("--show-owners", action="store_true",
                        help="print every physical owner with its structural state")
    args = parser.parse_args()

    report = audit(args.root.resolve())
    if args.json:
        print(json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True))
    else:
        print_text(report, args.max_list)
        if args.show_owners:
            owners = report["owners"]
            assert isinstance(owners, list)
            print("Physical owner ledger (layout state only; not a semantic-review claim)")
            for row in owners:
                assert isinstance(row, dict)
                if row["owner_kind"] == "raw":
                    state = "raw-map-script"
                elif not row["scripts_tracked"]:
                    state = "included-script-untracked"
                elif row["map_json_tracked"] and row["events_tracked"] and row["events_linked_from_data"]:
                    state = "scripts-and-events-structured"
                else:
                    state = "scripts-structured-events-pending"
                print(f"{row['ordinal']:03d} {row['name']} {state}")

    if args.strict:
        missing = report["missing_included_scripts"]
        untracked = report["untracked_ordered_owners"]
        assert isinstance(missing, list) and isinstance(untracked, list)
        if missing or untracked:
            return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
