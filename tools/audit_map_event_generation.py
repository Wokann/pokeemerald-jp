#!/usr/bin/env python3
"""Verify that every tracked map events.inc is reproducible from map.json."""

from __future__ import annotations

import subprocess
import sys
import tempfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MAPJSON = ROOT / "tools" / "mapjson" / "mapjson"


def tracked_event_sources(root: Path) -> list[tuple[Path, Path]]:
    """Return every map.json together with its tracked generated events source."""
    sources: list[tuple[Path, Path]] = []
    for map_json in sorted((root / "data" / "maps").glob("*/map.json")):
        events = map_json.with_name("events.inc")
        if not events.is_file():
            raise RuntimeError(f"missing generated source: {events.relative_to(root)}")
        sources.append((map_json, events))
    if not sources:
        raise RuntimeError("no map.json sources found")
    return sources


def make_event_targets(root: Path) -> set[str]:
    """Read the expanded Makefile target set without running a build."""
    result = subprocess.run(
        ["make", "-pn"],
        cwd=root,
        check=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
        text=True,
    )
    prefix = "JP_STRUCTURED_MAP_EVENTS :="
    for line in result.stdout.splitlines():
        if line.startswith(prefix):
            return set(line.removeprefix(prefix).split())
    raise RuntimeError("JP_STRUCTURED_MAP_EVENTS is not defined in Makefile")


def first_difference(expected: bytes, actual: bytes) -> str:
    """Describe the first byte mismatch without dumping copyrighted source data."""
    for offset, (left, right) in enumerate(zip(expected, actual)):
        if left != right:
            return f"offset 0x{offset:X}: tracked 0x{left:02X}, generated 0x{right:02X}"
    return f"length differs: tracked {len(expected)}, generated {len(actual)}"


def verify_makefile_coverage(root: Path, sources: list[tuple[Path, Path]]) -> None:
    tracked = {str(events.relative_to(root)) for _, events in sources}
    generated = make_event_targets(root)
    missing = sorted(tracked - generated)
    stale = sorted(generated - tracked)
    if missing or stale:
        details: list[str] = []
        if missing:
            details.append("missing Makefile targets: " + ", ".join(missing))
        if stale:
            details.append("stale Makefile targets: " + ", ".join(stale))
        raise RuntimeError("; ".join(details))


def verify_generation(root: Path, sources: list[tuple[Path, Path]]) -> list[str]:
    if not MAPJSON.is_file():
        raise RuntimeError(f"missing mapjson tool: {MAPJSON.relative_to(root)}")

    stale_sources: list[str] = []
    with tempfile.TemporaryDirectory(prefix="pokeemerald-jp-map-events-") as temp:
        temp_root = Path(temp)
        for map_json, events in sources:
            output_dir = temp_root / map_json.parent.name
            output_dir.mkdir()
            result = subprocess.run(
                [str(MAPJSON), "events", "emerald", str(map_json), str(output_dir)],
                cwd=root,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
            )
            if result.returncode:
                raise RuntimeError(
                    f"mapjson failed for {map_json.relative_to(root)}:\n"
                    f"{result.stdout}{result.stderr}"
                )

            generated = output_dir / "events.inc"
            if not generated.is_file():
                raise RuntimeError(
                    f"mapjson did not produce {generated.relative_to(temp_root)}"
                )
            expected_bytes = events.read_bytes()
            generated_bytes = generated.read_bytes()
            if expected_bytes != generated_bytes:
                stale_sources.append(
                    f"{events.relative_to(root)}: "
                    f"{first_difference(expected_bytes, generated_bytes)}"
                )
    return stale_sources


def main() -> int:
    try:
        sources = tracked_event_sources(ROOT)
        verify_makefile_coverage(ROOT, sources)
        stale_sources = verify_generation(ROOT, sources)
    except RuntimeError as error:
        print(f"map event generation audit failed: {error}", file=sys.stderr)
        return 1

    if stale_sources:
        print(
            "map event generation audit failed: regenerated output differs for "
            f"{len(stale_sources)} map(s):",
            file=sys.stderr,
        )
        for stale_source in stale_sources:
            print(f"  {stale_source}", file=sys.stderr)
        return 1

    print(
        f"map event generation: {len(sources)} map.json sources, "
        "all events.inc outputs byte-identical"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
