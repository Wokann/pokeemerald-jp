#!/usr/bin/env python3
"""Emit and byte-verify reviewed contiguous Japanese text blocks.

Map script data and shared text do not always live in the same ROM region.
This tool handles the latter without optimistic decoding: each configured
block has an exact raw owner, a closed ROM range, and a proof-gated label for
every EOS-terminated object.  ``emit`` and ``patch`` are read-only.  ``write``
performs the same byte-exact verification before replacing the unique raw
owner in place.
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import jp_emit_maps as emitter
from jp_script_text import JapaneseScriptTextCodec, TextDecodeError, TextRoundTripError
import verify_generated_map_scripts as map_verifier


ROM_BASE = 0x08000000
INCINBIN_RE = re.compile(
    r'^\s*\.incbin\s+"(?P<file>[^"]+)",\s*'
    r'0x(?P<start>[0-9A-Fa-f]+),\s*0x(?P<size>[0-9A-Fa-f]+)\s*$'
)


class TextBlockError(ValueError):
    """A configured shared-text extraction cannot be proven safe."""


@dataclass(frozen=True)
class TextBlock:
    name: str
    source: Path
    start: int
    end: int
    labels: dict[int, str]
    field_placeholders: dict[int, dict[int, str]]


def get_block(name: str) -> TextBlock:
    config = emitter.VERIFIED_SHARED_TEXT_BLOCKS.get(name)
    if config is None:
        known = ", ".join(sorted(emitter.VERIFIED_SHARED_TEXT_BLOCKS)) or "(none)"
        raise TextBlockError(f"unknown text block {name!r}; known: {known}")
    try:
        source = ROOT / config["source"]
        start = int(config["start"])
        end = int(config["end"])
        labels = dict(config["labels"])
        field_placeholders = {
            int(address): dict(names)
            for address, names in config.get("field_placeholders", {}).items()
        }
    except (KeyError, TypeError, ValueError) as error:
        raise TextBlockError(f"invalid configuration for {name}: {error}") from error
    if not source.is_file():
        raise TextBlockError(f"configured source does not exist: {source}")
    if not ROM_BASE <= start < end:
        raise TextBlockError(f"invalid ROM range for {name}: 0x{start:08X}-0x{end:08X}")
    if not labels:
        raise TextBlockError(f"{name} has no text labels")
    return TextBlock(name, source, start, end, labels, field_placeholders)


def split_strings(source: str) -> list[str]:
    """Keep each line/page break as a separate source directive."""
    parts = [part for part in re.split(r'(?<=\\l|\\p|\\n)', source) if part]
    if not parts or not parts[-1].endswith("$"):
        raise TextBlockError(f"decoded text lacks EOS: {source!r}")
    return parts


def emit_block(block: TextBlock) -> str:
    """Return all source objects in a contiguous block after codec proof."""
    codec = JapaneseScriptTextCodec()
    pos = block.start
    seen: set[int] = set()
    lines: list[str] = []
    while pos < block.end:
        label = block.labels.get(pos)
        if label is None:
            raise TextBlockError(
                f"{block.name}: no reviewed label at 0x{pos:08X}; refusing to guess"
            )
        raw = emitter.ROM[pos - ROM_BASE:block.end - ROM_BASE]
        try:
            decoded = codec.verify_one(raw, block.field_placeholders.get(pos))
        except (TextDecodeError, TextRoundTripError) as error:
            raise TextBlockError(f"{block.name}: text at 0x{pos:08X} is not lossless: {error}") from error
        next_pos = pos + decoded.consumed
        if next_pos > block.end:
            raise TextBlockError(
                f"{block.name}: text at 0x{pos:08X} crosses block end 0x{block.end:08X}"
            )
        lines.append(f"{label}: @ 0x{pos:08X}")
        for part in split_strings(decoded.source):
            lines.append(f'\t.string "{part}"')
        lines.append("")
        seen.add(pos)
        pos = next_pos
    if pos != block.end:
        raise TextBlockError(f"{block.name}: stopped at 0x{pos:08X}, expected 0x{block.end:08X}")
    unexpected = set(block.labels) - seen
    if unexpected:
        rendered = ", ".join(f"0x{value:08X}" for value in sorted(unexpected))
        raise TextBlockError(f"{block.name}: configured labels not reached: {rendered}")
    return "\n".join(lines).rstrip() + "\n"


def verify_block(block: TextBlock) -> str:
    """Assemble the fragment independently and compare its complete ROM span."""
    source = emit_block(block)
    produced = map_verifier.assemble_candidate(source, block.start)
    expected = emitter.ROM[block.start - ROM_BASE:block.end - ROM_BASE]
    if produced != expected:
        mismatch = next(
            (index for index, pair in enumerate(zip(produced, expected)) if pair[0] != pair[1]),
            min(len(produced), len(expected)),
        )
        raise TextBlockError(
            f"{block.name}: byte mismatch at 0x{block.start + mismatch:08X}; "
            f"got {len(produced):#x}, expected {len(expected):#x} bytes"
        )
    print(
        f"PASS {block.name}: 0x{block.start:08X}-0x{block.end:08X} "
        f"({block.end - block.start:#x} bytes, text={len(block.labels)})"
    )
    return source


def raw_owner(block: TextBlock) -> tuple[int, int, int, str]:
    """Locate the unique raw incbin line that completely owns a block."""
    owners = []
    for index, line in enumerate(block.source.read_text(encoding="utf-8").splitlines()):
        match = INCINBIN_RE.match(line)
        if match is None or Path(match.group("file")).name != "baserom_jp.gba":
            continue
        start = ROM_BASE + int(match.group("start"), 16)
        end = start + int(match.group("size"), 16)
        if start <= block.start and block.end <= end:
            owners.append((index, start, end, line))
    if len(owners) != 1:
        raise TextBlockError(
            f"{block.name}: expected one raw owner in {block.source}, found {len(owners)}"
        )
    return owners[0]


def incbin_line(start: int, end: int) -> str:
    return f'\t.incbin "baserom_jp.gba", 0x{start - ROM_BASE:x}, 0x{end - start:x}'


def patch_block(block: TextBlock) -> str:
    """Return a reviewable apply_patch payload after full fragment verification."""
    fragment = verify_block(block)
    line_index, owner_start, owner_end, owner_line = raw_owner(block)
    replacement = []
    if owner_start < block.start:
        replacement.append(incbin_line(owner_start, block.start))
    replacement.extend(fragment.rstrip("\n").splitlines())
    if block.end < owner_end:
        replacement.append(incbin_line(block.end, owner_end))
    patch = [
        "*** Begin Patch",
        f"*** Update File: {block.source}",
        "@@",
        "-" + owner_line,
    ]
    patch.extend("+" + line for line in replacement)
    patch.append("*** End Patch")
    return "\n".join(patch) + "\n"


def write_block(block: TextBlock) -> None:
    """Verify and replace the unique raw owner with one decoded block."""
    fragment = verify_block(block)
    line_index, owner_start, owner_end, _ = raw_owner(block)
    source_lines = block.source.read_text(encoding="utf-8").splitlines()
    replacement = []
    if owner_start < block.start:
        replacement.append(incbin_line(owner_start, block.start))
    replacement.extend(fragment.rstrip("\n").splitlines())
    if block.end < owner_end:
        replacement.append(incbin_line(block.end, owner_end))
    source_lines[line_index : line_index + 1] = replacement
    block.source.write_text("\n".join(source_lines) + "\n", encoding="utf-8")
    print(f"wrote {block.source}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    for command, help_text in (
        ("emit", "print one losslessly decoded text block"),
        ("verify", "assemble and exact-compare one text block"),
        ("patch", "print a verified apply_patch payload for one text block"),
        ("write", "verify and replace the unique raw owner in place"),
    ):
        subparser = commands.add_parser(command, help=help_text)
        subparser.add_argument("block_name")
    args = parser.parse_args()
    block = get_block(args.block_name)
    if args.command == "emit":
        print(emit_block(block), end="")
    elif args.command == "verify":
        verify_block(block)
    elif args.command == "patch":
        print(patch_block(block), end="")
    else:
        write_block(block)


if __name__ == "__main__":
    main()
