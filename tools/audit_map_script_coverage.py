#!/usr/bin/env python3
"""Report JP map-script ownership coverage against the US map hierarchy."""

from __future__ import annotations

import argparse
import json
import re
from dataclasses import asdict, dataclass
from pathlib import Path

import jp_emit_maps as emitter


ROOT = Path(__file__).resolve().parents[1]
US_ROOT = Path("/home/kenny/pokeemerald")
EVENT_SCRIPTS = ROOT / "data" / "event_scripts.s"
INCLUDE_RE = re.compile(r'^\s*\.include\s+"data/maps/([^/]+)/scripts\.inc"\s*$')


@dataclass(frozen=True)
class MapScriptOwner:
    name: str
    start: int
    end: int
    entries: int
    jp_file_exists: bool
    jp_include_exists: bool
    us_file_exists: bool


def map_file_names(root: Path) -> set[str]:
    return {path.parent.name for path in root.glob("data/maps/*/scripts.inc")}


def included_map_file_names() -> set[str]:
    names = set()
    for line in EVENT_SCRIPTS.read_text(encoding="utf-8").splitlines():
        match = INCLUDE_RE.match(line)
        if match:
            names.add(match.group(1))
    return names


def owners(include_empty: bool) -> list[MapScriptOwner]:
    entries = emitter.map_entries(include_empty=include_empty)
    labels = emitter.event_script_labels()
    starts = {entry[0] for entry in entries}
    nonmap = sorted(address for address in labels if address not in starts)
    last_map_end = next((address for address in nonmap if address > entries[-1][0]), 0x0828F000)
    jp_files = map_file_names(ROOT)
    jp_includes = included_map_file_names()
    us_files = map_file_names(US_ROOT)

    output = []
    for index, (start, name, _group, _map_num, table_entries, _events) in enumerate(entries):
        if index and entries[index - 1][0] == start:
            continue  # a shared table is owned by its first upstream map
        next_index = index + 1
        while next_index < len(entries) and entries[next_index][0] == start:
            next_index += 1
        end = entries[next_index][0] if next_index < len(entries) else last_map_end
        output.append(
            MapScriptOwner(
                name=name,
                start=start,
                end=end,
                entries=len(table_entries),
                jp_file_exists=name in jp_files,
                jp_include_exists=name in jp_includes,
                us_file_exists=name in us_files,
            )
        )
    return output


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--json",
        type=Path,
        help="write the complete owner manifest to this path",
    )
    args = parser.parse_args()

    active_records = owners(include_empty=False)
    records = owners(include_empty=True)
    missing_files = [record for record in records if not record.jp_file_exists]
    missing_includes = [record for record in records if record.jp_file_exists and not record.jp_include_exists]
    upstream_missing = [record for record in records if not record.us_file_exists]
    ready = [record for record in missing_files if record.us_file_exists]
    empty_ready = [record for record in ready if record.entries == 0]

    print(f"non-empty JP map-script owners: {len(active_records)}")
    print(f"all JP map-table owners:         {len(records)}")
    print(f"JP data/maps scripts.inc owners: {len(records) - len(missing_files)}")
    print(f"missing JP map owners:           {len(missing_files)}")
    print(f"missing empty-table owners:      {len(empty_ready)}")
    print(f"existing but not event_scripts include: {len(missing_includes)}")
    print(f"owners lacking US scripts.inc counterpart: {len(upstream_missing)}")
    print(f"US-aligned missing-owner candidates: {len(ready)}")
    print("\nMissing US-aligned owners (smallest ROM region first):")
    for record in sorted(ready, key=lambda item: (item.end - item.start, item.start)):
        print(
            f"  {record.name:<48} 0x{record.start:08X}-0x{record.end:08X} "
            f"size=0x{record.end - record.start:X} map_entries={record.entries}"
        )

    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(
            json.dumps([asdict(record) for record in records], indent=2) + "\n",
            encoding="utf-8",
        )
        print(f"wrote {args.json}")


if __name__ == "__main__":
    main()
