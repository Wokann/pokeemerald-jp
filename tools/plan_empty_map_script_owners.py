#!/usr/bin/env python3
"""Plan byte-safe migration of empty JP MapScripts table owners.

This reports, but never edits, the existing raw ``.incbin`` span that owns
each missing US-aligned map path.  A map is safe for a standalone migration
only when it forms the *tail* of one explicit baserom span and every remaining
map owner through that span's end is selected too.  Callers can then truncate
the old span and insert the new map includes without moving or mis-owning any
later map bytes.  Ranges that cross source directives, or precede a larger
unmigrated map owner, are deliberately left out for manual analysis.
"""

from __future__ import annotations

import argparse
import json
import re
from collections import defaultdict
from dataclasses import asdict, dataclass
from pathlib import Path

from audit_map_script_coverage import MapScriptOwner, owners


ROOT = Path(__file__).resolve().parents[1]
US_ROOT = Path("/home/kenny/pokeemerald")
EVENT_SCRIPTS = ROOT / "data" / "event_scripts.s"
US_EVENT_SCRIPTS = US_ROOT / "data" / "event_scripts.s"
INCBIN_RE = re.compile(
    r'^\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)\s*$'
)
MAP_INCLUDE_RE = re.compile(r'^\s*\.include\s+"data/maps/([^/]+)/scripts\.inc"\s*$')


@dataclass(frozen=True)
class IncbinSpan:
    path: str
    line: int
    start: int
    end: int
    is_tail: bool


@dataclass(frozen=True)
class PlannedOwner:
    name: str
    start: int
    end: int
    source: IncbinSpan


def source_files() -> list[Path]:
    """Return every tracked script include that can explicitly own ROM bytes."""
    return sorted(
        list((ROOT / "data" / "maps").glob("*/scripts.inc"))
        + list((ROOT / "data" / "scripts").rglob("*.inc"))
    )


def raw_spans() -> list[IncbinSpan]:
    spans: list[IncbinSpan] = []
    for path in source_files():
        lines = path.read_text(encoding="utf-8").splitlines()
        for line_number, line in enumerate(lines, 1):
            match = INCBIN_RE.match(line)
            if match is None:
                continue
            start = int(match.group(1), 16) + 0x08000000
            end = start + int(match.group(2), 16)
            is_tail = all(
                not trailing.strip() or trailing.lstrip().startswith("@")
                for trailing in lines[line_number:]
            )
            spans.append(
                IncbinSpan(
                    path=str(path.relative_to(ROOT)),
                    line=line_number,
                    start=start,
                    end=end,
                    is_tail=is_tail,
                )
            )
    return spans


def contained_plan(max_size: int | None) -> tuple[list[PlannedOwner], list[MapScriptOwner]]:
    """Return missing empty owners physically contained in one raw span."""
    spans = raw_spans()
    planned: list[PlannedOwner] = []
    blocked: list[MapScriptOwner] = []
    for record in owners(include_empty=True):
        if record.jp_file_exists or not record.us_file_exists or record.entries:
            continue
        if max_size is not None and record.end - record.start > max_size:
            continue
        containing = [
            span for span in spans if span.start <= record.start and record.end <= span.end
        ]
        if len(containing) != 1:
            blocked.append(record)
            continue
        planned.append(
            PlannedOwner(
                name=record.name,
                start=record.start,
                end=record.end,
                source=containing[0],
            )
        )
    return sorted(planned, key=lambda item: item.start), blocked


def safe_tail_plan(max_size: int | None) -> tuple[list[PlannedOwner], list[PlannedOwner], list[MapScriptOwner]]:
    """Return safe tail groups, contained-but-not-safe items, and blocked items."""
    contained, blocked = contained_plan(max_size)
    all_owners = owners(include_empty=True)
    grouped: dict[IncbinSpan, list[PlannedOwner]] = defaultdict(list)
    for item in contained:
        grouped[item.source].append(item)

    safe: list[PlannedOwner] = []
    unsafe: list[PlannedOwner] = []
    for source, items in grouped.items():
        items.sort(key=lambda item: item.start)
        first_start = items[0].start
        selected = {item.name for item in items}
        trailing = [
            owner
            for owner in all_owners
            if first_start <= owner.start < source.end
        ]
        if (
            source.is_tail
            and trailing
            and all(owner.name in selected for owner in trailing)
            and trailing[-1].end == source.end
        ):
            safe.extend(items)
        else:
            unsafe.extend(items)
    return sorted(safe, key=lambda item: item.start), sorted(unsafe, key=lambda item: item.start), blocked


def map_include_names(path: Path) -> list[str]:
    if not path.is_file():
        raise ValueError(f"missing event script source: {path}")
    names = []
    for line in path.read_text(encoding="utf-8").splitlines():
        match = MAP_INCLUDE_RE.match(line)
        if match is not None:
            names.append(match.group(1))
    if len(names) != len(set(names)):
        raise ValueError(f"duplicate map include in {path}")
    return names


def source_map_name(source: IncbinSpan) -> str:
    path = Path(source.path)
    if path.parts[:2] != ("data", "maps") or path.name != "scripts.inc":
        raise ValueError(f"raw span is not owned by a map scripts.inc: {source.path}")
    return path.parent.name


def raw_line(source: IncbinSpan) -> str:
    path = ROOT / source.path
    line = path.read_text(encoding="utf-8").splitlines()[source.line - 1]
    if INCBIN_RE.match(line) is None:
        raise ValueError(f"raw span changed since planning: {source.path}:{source.line}")
    return line


def emit_patch(planned: list[PlannedOwner]) -> str:
    """Return an apply_patch payload for all tail-safe empty owners."""
    jp_names = map_include_names(EVENT_SCRIPTS)
    us_names = map_include_names(US_EVENT_SCRIPTS)
    us_index = {name: index for index, name in enumerate(us_names)}
    positions = [us_index[name] for name in jp_names if name in us_index]
    if positions != sorted(positions):
        raise ValueError("the common JP/US map include order is not a US-order subsequence")

    by_source: dict[IncbinSpan, list[PlannedOwner]] = defaultdict(list)
    for item in planned:
        by_source[item.source].append(item)
    for items in by_source.values():
        items.sort(key=lambda item: item.start)

    insertion_groups: dict[str, list[PlannedOwner]] = {}
    for source, items in by_source.items():
        anchor = source_map_name(source)
        if anchor not in jp_names:
            raise ValueError(f"source owner is not included by event_scripts.s: {anchor}")
        if any(item.name not in us_index for item in items):
            raise ValueError(f"planned owner has no US path after all: {items}")
        if anchor in us_index and any(us_index[item.name] <= us_index[anchor] for item in items):
            raise ValueError(f"US order would place a planned owner before its source: {anchor}")
        insertion_groups[anchor] = sorted(items, key=lambda item: us_index[item.name])

    lines = ["*** Begin Patch"]
    for source, items in sorted(by_source.items(), key=lambda pair: (pair[0].path, pair[0].line)):
        first = items[0]
        prefix_size = first.start - source.start
        old = raw_line(source)
        lines.extend((f"*** Update File: {source.path}", "@@", f"-{old}"))
        if prefix_size:
            lines.append(
                f'+\t.incbin "baserom_jp.gba", 0x{source.start - 0x08000000:x}, 0x{prefix_size:x}'
            )

    lines.append("*** Update File: data/event_scripts.s")
    jp_index = {name: index for index, name in enumerate(jp_names)}
    for anchor, items in sorted(insertion_groups.items(), key=lambda pair: jp_index[pair[0]]):
        anchor_line = f'\t.include "data/maps/{anchor}/scripts.inc"'
        lines.extend(("@@", f" {anchor_line}"))
        lines.extend(f'+\t.include "data/maps/{item.name}/scripts.inc"' for item in items)

    for item in planned:
        lines.extend(
            (
                f"*** Add File: data/maps/{item.name}/scripts.inc",
                f"+@ {item.name} scripts (JP empty MapScripts @ 0x{item.start:08X})",
                "+",
                f"+{item.name}_MapScripts::",
                "+\t.byte 0",
            )
        )
    lines.append("*** End Patch")
    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--max-size",
        type=lambda value: int(value, 0),
        default=1,
        help="only report owner regions no larger than this many bytes (default: 1)",
    )
    parser.add_argument("--json", type=Path, help="write the direct migration plan as JSON")
    parser.add_argument(
        "--emit-patch",
        action="store_true",
        help="print an apply_patch payload for every safe tail owner and exit",
    )
    args = parser.parse_args()

    planned, unsafe, blocked = safe_tail_plan(args.max_size)
    if args.emit_patch:
        if args.json:
            raise SystemExit("--emit-patch cannot be combined with --json")
        print(emit_patch(planned))
        return
    grouped: dict[IncbinSpan, list[PlannedOwner]] = defaultdict(list)
    for item in planned:
        grouped[item.source].append(item)

    print(f"empty US-aligned owners at or below {args.max_size:#x}: {len(planned) + len(unsafe) + len(blocked)}")
    print(f"safe tail-splittable owners: {len(planned)}")
    print(f"contained but not tail-safe owners: {len(unsafe)}")
    print(f"not contained in one raw span: {len(blocked)}")
    print(f"source raw spans to split: {len(grouped)}")
    for source, items in sorted(grouped.items(), key=lambda pair: (pair[0].start, pair[0].path)):
        names = ", ".join(item.name for item in items)
        print(
            f"{source.path}:{source.line}  0x{source.start:08X}-0x{source.end:08X}"
            f"  -> {names}"
        )
    for item in unsafe:
        print(
            f"UNSAFE {item.name}: 0x{item.start:08X}-0x{item.end:08X} "
            f"inside {item.source.path}:{item.source.line}"
        )
    for record in blocked:
        print(f"UNCONTAINED {record.name}: 0x{record.start:08X}-0x{record.end:08X}")

    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(
            json.dumps([asdict(item) for item in planned], indent=2) + "\n",
            encoding="utf-8",
        )
        print(f"wrote {args.json}")


if __name__ == "__main__":
    main()
