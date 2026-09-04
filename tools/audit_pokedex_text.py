#!/usr/bin/env python3
"""Audit the JP Pokédex-description text block against the US label order.

This is deliberately a verifier, not a blind converter.  It derives names only
from the upstream source order, decodes each JP EOS-terminated object with the
project's conservative codec, and then re-encodes each object through the real
preprocessor.  A name-count mismatch, a boundary mismatch, or an unknown text
control is an error rather than a reason to guess at a source representation.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
from pathlib import Path

from jp_script_text import JapaneseScriptTextCodec, TextDecodeError, TextRoundTripError


ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
US_TEXT_PATH = ROOT.parent / "pokeemerald" / "src" / "data" / "pokemon" / "pokedex_text.h"

# The preceding 0xFF at 0x08539C50 is a separate one-byte raw owner.  The
# first real description, gDummyPokedexText, begins one byte later.
JP_TEXT_START = 0x539C51
JP_TEXT_END = 0x54069C
JP_ENTRIES_START = JP_TEXT_END
JP_ENTRIES_END = 0x5430F0
# JP stores six-byte category names, height/weight, two compiler padding
# regions, a description pointer, then the sprite-scaling fields.  This is a
# real JP layout difference from current US PokedexEntry, not an address-only
# renaming opportunity.
JP_ENTRY = struct.Struct("<6sHH2xIHHhHh2x")

LABEL_RE = re.compile(r"^const u8 (g[A-Za-z0-9_]+PokedexText)\[\] = _\(", re.MULTILINE)


def us_labels(path: Path) -> list[str]:
    labels = LABEL_RE.findall(path.read_text(encoding="utf-8"))
    if not labels:
        raise ValueError(f"no Pokédex text labels found in {path}")
    if len(labels) != len(set(labels)):
        raise ValueError("duplicate Pokédex text labels in upstream source")
    return labels


def jp_objects(rom: bytes, codec: JapaneseScriptTextCodec) -> tuple[list[dict[str, object]], int]:
    objects: list[dict[str, object]] = []
    offset = JP_TEXT_START
    while offset < JP_TEXT_END:
        # The final variable-length string is followed by linker fill before
        # the 4-byte-aligned entry table.  It is not an unterminated string of
        # Japanese full-width spaces, because the remaining physical span is
        # entirely zero fill.
        if all(byte == 0 for byte in rom[offset:JP_TEXT_END]):
            return objects, JP_TEXT_END - offset
        try:
            decoded = codec.decode_one(rom[offset:JP_TEXT_END])
        except TextDecodeError as error:
            raise TextDecodeError(
                f"cannot decode Pokédex text at 0x{offset:06X}: {error}"
            ) from error
        raw = rom[offset : offset + decoded.consumed]
        encoded = codec.preproc_bytes(decoded.source)
        if encoded != raw:
            raise TextRoundTripError(
                f"round-trip mismatch at 0x{offset:06X}: "
                f"expected {raw.hex().upper()}, got {encoded.hex().upper()}"
            )
        objects.append(
            {
                "rom_offset": f"0x{offset:06X}",
                "size": decoded.consumed,
                "source": decoded.source,
            }
        )
        offset += decoded.consumed
    return objects, 0


def jp_entries(
    rom: bytes, codec: JapaneseScriptTextCodec, text_objects: list[dict[str, object]]
) -> list[dict[str, object]]:
    span = rom[JP_ENTRIES_START:JP_ENTRIES_END]
    if len(span) % JP_ENTRY.size:
        raise ValueError("JP Pokédex-entry range is not a whole number of entries")
    if len(span) // JP_ENTRY.size != len(text_objects):
        raise ValueError(
            "JP Pokédex-entry count does not match the description-text count"
        )

    entries: list[dict[str, object]] = []
    for index in range(0, len(span), JP_ENTRY.size):
        (
            category_raw,
            height,
            weight,
            description_address,
            unused,
            pokemon_scale,
            pokemon_offset,
            trainer_scale,
            trainer_offset,
        ) = JP_ENTRY.unpack_from(span, index)
        category_data = category_raw.rstrip(b"\0")
        try:
            category = codec.decode(category_data)
        except TextDecodeError as error:
            raise TextDecodeError(
                f"cannot decode category at 0x{JP_ENTRIES_START + index:06X}: {error}"
            ) from error
        if codec.preproc_bytes(category) != category_data:
            raise TextRoundTripError(
                f"category round-trip mismatch at 0x{JP_ENTRIES_START + index:06X}"
            )
        text_index = index // JP_ENTRY.size
        expected_address = 0x08000000 + int(text_objects[text_index]["rom_offset"], 16)
        if description_address != expected_address:
            raise ValueError(
                f"entry {text_index} at 0x{JP_ENTRIES_START + index:06X} points to "
                f"0x{description_address:08X}, expected 0x{expected_address:08X}"
            )
        entries.append(
            {
                "rom_offset": f"0x{JP_ENTRIES_START + index:06X}",
                "category": category,
                "description_address": f"0x{description_address:08X}",
                "height": height,
                "weight": weight,
                "unused": unused,
                "pokemon_scale": pokemon_scale,
                "pokemon_offset": pokemon_offset,
                "trainer_scale": trainer_scale,
                "trainer_offset": trainer_offset,
            }
        )
    return entries


def report() -> dict[str, object]:
    if not ROM_PATH.is_file():
        raise FileNotFoundError(f"missing JP baserom: {ROM_PATH}")
    if not US_TEXT_PATH.is_file():
        raise FileNotFoundError(f"missing US text source: {US_TEXT_PATH}")

    labels = us_labels(US_TEXT_PATH)
    rom = ROM_PATH.read_bytes()
    codec = JapaneseScriptTextCodec()
    objects, trailing_fill = jp_objects(rom, codec)
    if len(objects) != len(labels):
        raise ValueError(
            f"JP object count {len(objects)} does not match US label count {len(labels)}"
        )

    named_objects = [
        {"label": label, **obj} for label, obj in zip(labels, objects, strict=True)
    ]
    span = rom[JP_TEXT_START:JP_TEXT_END]
    entries = jp_entries(rom, codec, named_objects)
    entry_span = rom[JP_ENTRIES_START:JP_ENTRIES_END]
    return {
        "jp_range": f"[0x{JP_TEXT_START:06X}, 0x{JP_TEXT_END:06X})",
        "jp_size": len(span),
        "jp_sha256": hashlib.sha256(span).hexdigest(),
        "objects": len(named_objects),
        "trailing_zero_fill": trailing_fill,
        "round_trip": "preproc-byte-exact",
        "first": named_objects[0],
        "last": named_objects[-1],
        "entries": named_objects,
        "entry_range": f"[0x{JP_ENTRIES_START:06X}, 0x{JP_ENTRIES_END:06X})",
        "entry_size": JP_ENTRY.size,
        "entry_sha256": hashlib.sha256(entry_span).hexdigest(),
        "entry_records": entries,
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--json", action="store_true", help="emit the full deterministic manifest")
    args = parser.parse_args()
    result = report()
    if args.json:
        print(json.dumps(result, ensure_ascii=False, indent=2, sort_keys=True))
        return
    print(f"JP range: {result['jp_range']} ({result['jp_size']} bytes)")
    print(f"SHA-256: {result['jp_sha256']}")
    print(f"objects: {result['objects']} ({result['round_trip']})")
    print(f"first: {result['first']['label']} @ {result['first']['rom_offset']}")
    print(f"last: {result['last']['label']} @ {result['last']['rom_offset']}")
    print(f"entry range: {result['entry_range']} ({len(result['entry_records'])} x {result['entry_size']})")


if __name__ == "__main__":
    try:
        main()
    except (OSError, TextDecodeError, TextRoundTripError, ValueError) as error:
        raise SystemExit(f"audit_pokedex_text: {error}") from error
