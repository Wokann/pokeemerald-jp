#!/usr/bin/env python3
"""Unified, byte-safe entry point for JP map event-script migration.

This command deliberately orchestrates the existing metadata, boundary,
emission, text-codec, and verifier modules.  It does not decode unknown bytes
optimistically: ranges that the emitter cannot classify remain ``.incbin`` and
must still pass an exact ROM-slice comparison before they can be written.
"""

from __future__ import annotations

import argparse
import contextlib
import io
import json
import os
import subprocess
from pathlib import Path

import audit_map_component_boundaries as boundaries
import plan_empty_map_script_owners as empty_owner_planner
import verify_generated_map_scripts as verifier


ROOT = Path(__file__).resolve().parents[1]


def scan(map_name: str | None, as_json: bool) -> None:
    records = boundaries.build_records()
    if map_name is not None:
        record = boundaries.find_record(records, map_name)
        if as_json:
            print(json.dumps(record, ensure_ascii=False, indent=2))
        else:
            boundaries.print_record(record)
    elif as_json:
        print(json.dumps(records, ensure_ascii=False, indent=2))
    else:
        boundaries.print_summary(records)


def verified_source(map_name: str) -> str:
    return verifier.verify_map(map_name)


def write_source(map_name: str, source: str, output: Path | None) -> Path:
    destination = output or ROOT / "data" / "maps" / map_name / "scripts.inc"
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(source, encoding="utf-8")
    print(f"wrote {destination}")
    return destination


def source_patch(map_name: str) -> str:
    """Return an apply_patch payload for one verified map source refresh."""
    with contextlib.redirect_stdout(io.StringIO()):
        source = verified_source(map_name)
    destination = ROOT / "data" / "maps" / map_name / "scripts.inc"
    lines = ["*** Begin Patch"]
    if destination.is_file():
        previous = destination.read_text(encoding="utf-8")
        if previous == source:
            lines.append("*** End Patch")
            return "\n".join(lines) + "\n"
        lines.extend((f"*** Update File: {destination}", "@@"))
        lines.extend("-" + line for line in previous.splitlines())
    else:
        lines.append(f"*** Add File: {destination}")
    lines.extend("+" + line for line in source.splitlines())
    lines.append("*** End Patch")
    return "\n".join(lines) + "\n"


def safe_empty_group(map_name: str):
    """Return the complete raw-tail group that safely owns ``map_name``.

    Empty MapScripts tables are often followed by that map's object-event
    scripts and text.  Moving only the one-byte table would mis-own those
    bytes, so a request always expands to the complete group approved by the
    conservative tail planner.
    """
    planned, _unsafe, _blocked = empty_owner_planner.safe_tail_plan(None)
    requested = next((item for item in planned if item.name == map_name), None)
    if requested is None:
        raise ValueError(
            f"{map_name} is not in a safe empty-map migration group; "
            "inspect plan_empty_map_script_owners.py first"
        )
    group = sorted(
        (item for item in planned if item.source == requested.source),
        key=lambda item: item.start,
    )
    if not group:
        raise AssertionError("safe planner returned an empty owner group")
    for left, right in zip(group, group[1:]):
        if left.end != right.start:
            raise ValueError(
                f"non-contiguous planned group: {left.name} ends at "
                f"0x{left.end:08X}, {right.name} starts at 0x{right.start:08X}"
            )
    if group[-1].end != group[0].source.end:
        raise ValueError(
            f"planned group for {map_name} does not reach its raw-span tail"
        )
    return group


def group_sources(group):
    """Verify every map in ``group`` before emitting any project edit."""
    sources = []
    for item in group:
        destination = ROOT / "data" / "maps" / item.name / "scripts.inc"
        if destination.exists():
            raise ValueError(f"refusing to overwrite existing {destination}")
        # ``verify_map`` deliberately prints its PASS line for interactive
        # use.  A generated apply_patch payload must contain only patch text,
        # so retain that diagnostic while suppressing it in this composition
        # step after the verifier has completed successfully.
        with contextlib.redirect_stdout(io.StringIO()):
            source = verified_source(item.name)
        sources.append((item, source))
    return sources


def group_insertion_anchor(group) -> tuple[str, list[str]]:
    """Return the checked US-order anchor and the group's include names."""
    source = group[0].source
    anchor = empty_owner_planner.source_map_name(source)
    jp_names = empty_owner_planner.map_include_names(empty_owner_planner.EVENT_SCRIPTS)
    us_names = empty_owner_planner.map_include_names(empty_owner_planner.US_EVENT_SCRIPTS)
    us_index = {name: index for index, name in enumerate(us_names)}
    if anchor not in us_index or anchor not in jp_names:
        raise ValueError(f"migration anchor is not an existing US-aligned include: {anchor}")
    # A few JP-specific map includes have no US counterpart.  They do not
    # participate in this US-order assertion; the checked common subsequence
    # is the same conservative rule used by the standalone tail planner.
    aligned_jp_names = [name for name in jp_names if name in us_index]
    positions = [us_index[name] for name in aligned_jp_names]
    if positions != sorted(positions):
        raise ValueError("JP map include order is not a US-order subsequence")
    names = [item.name for item in group]
    if any(name in jp_names for name in names):
        raise ValueError("migration group already has an event_scripts.s include")
    names.sort(key=us_index.__getitem__)
    anchor_index = us_index[anchor]
    if any(us_index[name] <= anchor_index for name in names):
        raise ValueError(f"US order places a target before raw-span owner {anchor}")
    intervening = [
        name for name in aligned_jp_names
        if anchor_index < us_index[name] < us_index[names[0]]
    ]
    if intervening:
        raise ValueError(
            "cannot insert after raw-span owner without reordering existing maps: "
            + ", ".join(intervening)
        )
    return anchor, names


def group_patch(map_name: str) -> str:
    """Create an apply_patch payload for one fully verified empty-map group."""
    group = safe_empty_group(map_name)
    sources = group_sources(group)
    source = group[0].source
    anchor, names = group_insertion_anchor(group)
    prefix_size = group[0].start - source.start
    old_raw = empty_owner_planner.raw_line(source)

    source_path = ROOT / source.path
    lines = ["*** Begin Patch", f"*** Update File: {source_path}", "@@", f"-{old_raw}"]
    if prefix_size:
        lines.append(
            f'+\t.incbin "baserom_jp.gba", 0x{source.start - 0x08000000:x}, '
            f"0x{prefix_size:x}"
        )

    anchor_line = f'\t.include "data/maps/{anchor}/scripts.inc"'
    lines.extend((f"*** Update File: {ROOT / 'data/event_scripts.s'}", "@@", f" {anchor_line}"))
    lines.extend(f'+\t.include "data/maps/{name}/scripts.inc"' for name in names)

    source_by_name = {item.name: text for item, text in sources}
    for name in names:
        lines.append(f"*** Add File: {ROOT / 'data/maps' / name / 'scripts.inc'}")
        lines.extend("+" + line for line in source_by_name[name].splitlines())
    lines.append("*** End Patch")
    return "\n".join(lines) + "\n"


def repack(jobs: int) -> None:
    environment = os.environ.copy()
    environment.pop("OS", None)
    commands = (
        ["make", "-s", "clean"],
        ["make", "-s", f"-j{jobs}"],
        ["make", "-s", "compare"],
    )
    for command in commands:
        result = subprocess.run(command, cwd=ROOT, env=environment, check=False)
        if result.returncode:
            raise SystemExit(result.returncode)


def positive_jobs(value: str) -> int:
    jobs = int(value, 0)
    if not 1 <= jobs <= 64:
        raise argparse.ArgumentTypeError("jobs must be between 1 and 64")
    return jobs


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)

    scan_parser = commands.add_parser("scan", help="audit map/component boundaries")
    scan_parser.add_argument("map_name", nargs="?")
    scan_parser.add_argument("--json", action="store_true")

    emit_parser = commands.add_parser(
        "emit", help="generate and byte-verify one map source candidate"
    )
    emit_parser.add_argument("map_name")
    emit_parser.add_argument("--output", type=Path)
    emit_parser.add_argument(
        "--patch",
        action="store_true",
        help="print an apply_patch payload instead of writing the candidate",
    )
    emit_parser.add_argument(
        "--write",
        action="store_true",
        help="write data/maps/<Map>/scripts.inc after verification",
    )

    verify_parser = commands.add_parser("verify", help="verify one generated map range")
    verify_parser.add_argument("map_name")

    repack_parser = commands.add_parser(
        "repack", help="clean-build the project and compare the complete ROM"
    )
    repack_parser.add_argument("--jobs", type=positive_jobs, default=16)

    run_parser = commands.add_parser(
        "run", help="scan, verify, optionally write, and optionally repack one map"
    )
    run_parser.add_argument("map_name")
    run_parser.add_argument("--write", action="store_true")
    run_parser.add_argument("--repack", action="store_true")
    run_parser.add_argument("--jobs", type=positive_jobs, default=16)

    migrate_parser = commands.add_parser(
        "migrate-empty-group",
        help="emit a byte-safe patch for the complete empty-map owner group",
    )
    migrate_parser.add_argument("map_name")
    return parser


def main() -> None:
    args = build_parser().parse_args()
    if args.command == "scan":
        scan(args.map_name, args.json)
    elif args.command == "emit":
        if sum((args.write, args.output is not None, args.patch)) > 1:
            raise SystemExit("--write, --output, and --patch are mutually exclusive")
        if args.patch:
            print(source_patch(args.map_name), end="")
        else:
            source = verified_source(args.map_name)
            if args.write or args.output is not None:
                write_source(args.map_name, source, args.output)
            else:
                print(source, end="")
    elif args.command == "verify":
        verified_source(args.map_name)
    elif args.command == "repack":
        repack(args.jobs)
    elif args.command == "run":
        scan(args.map_name, False)
        source = verified_source(args.map_name)
        if args.write:
            write_source(args.map_name, source, None)
        if args.repack:
            repack(args.jobs)
    elif args.command == "migrate-empty-group":
        print(group_patch(args.map_name), end="")


if __name__ == "__main__":
    main()
