#!/usr/bin/env python3
"""Unified, byte-safe entry point for JP map event-script migration.

This command deliberately orchestrates the existing metadata, boundary,
emission, text-codec, and verifier modules.  It does not decode unknown bytes
optimistically: ranges that the emitter cannot classify remain ``.incbin`` and
must still pass an exact ROM-slice comparison before they can be written.
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
from pathlib import Path

import audit_map_component_boundaries as boundaries
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
    return parser


def main() -> None:
    args = build_parser().parse_args()
    if args.command == "scan":
        scan(args.map_name, args.json)
    elif args.command == "emit":
        if args.write and args.output is not None:
            raise SystemExit("--write and --output are mutually exclusive")
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


if __name__ == "__main__":
    main()
