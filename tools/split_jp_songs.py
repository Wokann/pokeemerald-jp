#!/usr/bin/env python3
"""Validate and split the structured JP song block into pret-style files.

The JP song table has 559 slots, but slots 270-349 all point at the dummy
header in sound_data and therefore have no song body. The remaining 479 song
bodies are emitted in slot order between 0x088683E0 and 0x0890ED54.

Run without --apply for a read-only audit. With --apply, this writes the song
files plus deterministic Make/LD order manifests and leaves only the following
library rodata in data/data_b2c_mid8_tail.s.
"""

import argparse
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "data/data_b2c_mid8_tail.s"
SOUND_DATA = ROOT / "data/sound_data.s"
SONG_CONSTANTS = ROOT / "include/constants/songs.h"
OUT_DIR = ROOT / "sound/songs/midi"
MAKE_ORDER = ROOT / "sound/song_order.mk"
LD_ORDER = ROOT / "sound/song_order.ld"

FIRST_SONG_ADDR = 0x088683E0
LIB_RODATA_ADDR = 0x0890ED54
DUMMY_IDS = set(range(270, 350))
SONG_IDS = [i for i in range(559) if i not in DUMMY_IDS]

HEADER_RE = re.compile(r"^sSongHeader_(\d+):\s*@\s*0x([0-9A-Fa-f]+)$", re.M)
PART0_RE = re.compile(r"^sSong(\d+)_Part0:\s*@\s*0x([0-9A-Fa-f]+)$", re.M)
CONST_RE = re.compile(r"^#define\s+((?:SE|MUS)_[A-Z0-9_]+)\s+(\d+)\b", re.M)
TABLE_RE = re.compile(r"^\s*\.4byte\s+0x([0-9A-Fa-f]+)\s+@ song (\d+) header$", re.M)


def fail(message):
    raise SystemExit(f"split_jp_songs: {message}")


def song_names():
    text = SONG_CONSTANTS.read_text(encoding="utf-8")
    names = {}
    for name, number in CONST_RE.findall(text):
        names.setdefault(int(number), name.lower())

    # The public constant keeps the contextual name MUS_DESERT, while pret's
    # actual module and SongTable use the more specific mus_route111.
    names[409] = "mus_route111"
    missing = [i for i in SONG_IDS if i not in names]
    if missing:
        fail(f"missing canonical names for IDs: {missing}")
    if len({names[i] for i in SONG_IDS}) != len(SONG_IDS):
        fail("canonical song filenames are not unique")
    return names


def validate_table(header_addrs):
    entries = {int(i): int(addr, 16) for addr, i in TABLE_RE.findall(
        SOUND_DATA.read_text(encoding="utf-8")
    )}
    if sorted(entries) != list(range(559)):
        fail(f"gSongTable slots are not exactly 0..558 ({len(entries)} found)")
    for i in SONG_IDS:
        if entries[i] != header_addrs[i]:
            fail(f"slot {i} points to 0x{entries[i]:08X}, header is 0x{header_addrs[i]:08X}")
    dummy_targets = {entries[i] for i in DUMMY_IDS}
    if len(dummy_targets) != 1 or next(iter(dummy_targets)) != 0x0863D424:
        fail(f"dummy slots have unexpected targets: {sorted(dummy_targets)}")


def audit():
    source = SOURCE.read_text(encoding="utf-8")
    headers = {int(i): int(addr, 16) for i, addr in HEADER_RE.findall(source)}
    parts = {int(i): int(addr, 16) for i, addr in PART0_RE.findall(source)}
    if sorted(headers) != SONG_IDS:
        fail(f"expected 479 headers for non-dummy IDs, found {len(headers)}")
    if sorted(parts) != SONG_IDS[1:]:
        fail(f"expected Part0 for IDs 1..269 and 350..558, found {len(parts)}")
    if headers[0] != FIRST_SONG_ADDR:
        fail(f"first header is 0x{headers[0]:08X}, expected 0x{FIRST_SONG_ADDR:08X}")

    lib_match = re.search(r"^sSetupInfos:\s*@\s*0x([0-9A-Fa-f]+)$", source, re.M)
    if not lib_match or int(lib_match.group(1), 16) != LIB_RODATA_ADDR:
        fail("library rodata boundary sSetupInfos @ 0x0890ED54 not found")
    validate_table(headers)

    def symbol_start(label):
        label_at = source.index(label)
        global_line = f"\t.globl {label[:-1]}\n"
        global_at = source.rfind(global_line, 0, label_at)
        if global_at >= 0 and global_at + len(global_line) == label_at:
            return global_at
        return label_at

    starts = {0: symbol_start("sSongHeader_0:")}
    for i in SONG_IDS[1:]:
        starts[i] = symbol_start(f"sSong{i}_Part0:")
    # This public alias immediately precedes song 456's first track and must
    # stay with the object that defines its target header.
    starts[456] = source.index("\t\t.globl gUnknown_88BA568\n")
    lib_start = symbol_start("sSetupInfos:")
    ordered_starts = [starts[i] for i in SONG_IDS]
    if ordered_starts != sorted(ordered_starts) or ordered_starts[-1] >= lib_start:
        fail("song bodies are not in monotonically increasing slot order")

    names = song_names()
    blocks = {}
    for pos, song_id in enumerate(SONG_IDS):
        start = starts[song_id]
        end = ordered_starts[pos + 1] if pos + 1 < len(SONG_IDS) else lib_start
        block = source[start:end]
        if f"sSongHeader_{song_id}:" not in block:
            fail(f"song {song_id} block does not contain its header")
        blocks[song_id] = block

    covered = sum(len(blocks[i]) for i in SONG_IDS)
    expected = lib_start - starts[0]
    if covered != expected:
        fail(f"coverage mismatch: {covered} != {expected}")
    return source, lib_start, names, blocks, headers


def audit_existing_split():
    names = song_names()
    headers = {}
    paths = []
    for song_id in SONG_IDS:
        path = OUT_DIR / f"{names[song_id]}.s"
        if not path.is_file():
            fail(f"missing split module {path.relative_to(ROOT)}")
        text = path.read_text(encoding="utf-8")
        matches = [(int(i), int(addr, 16)) for i, addr in HEADER_RE.findall(text)]
        if len(matches) != 1 or matches[0][0] != song_id:
            fail(f"{path.relative_to(ROOT)} does not contain exactly header {song_id}")
        headers[song_id] = matches[0][1]
        paths.append(f"sound/songs/midi/{names[song_id]}.s")

    validate_table(headers)
    make_text = MAKE_ORDER.read_text(encoding="utf-8")
    make_paths = re.findall(r"^\s*(sound/songs/midi/[^\s\\]+\.s)", make_text, re.M)
    if make_paths != paths:
        fail("sound/song_order.mk does not match canonical slot order")
    ld_paths = re.findall(r"^(sound/songs/midi/[^()]+)\.o\(\.rodata\);$",
                          LD_ORDER.read_text(encoding="utf-8"), re.M)
    if [p[:-2] for p in paths] != ld_paths:
        fail("sound/song_order.ld does not match canonical slot order")
    return names, headers


def apply_split(source, lib_start, names, blocks):
    existing = [OUT_DIR / f"{names[i]}.s" for i in SONG_IDS if (OUT_DIR / f"{names[i]}.s").exists()]
    if existing:
        fail(f"refusing to overwrite {len(existing)} existing song files")

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    prefix = (
        '.include "sound/MPlayDef.s"\n'
        '\t.section .rodata\n'
        '\t.include "asm/macros.inc"\n\n'
    )
    for song_id in SONG_IDS:
        (OUT_DIR / f"{names[song_id]}.s").write_text(
            prefix + blocks[song_id].strip("\n") + "\n", encoding="utf-8"
        )

    paths = [f"sound/songs/midi/{names[i]}.s" for i in SONG_IDS]
    make_lines = ["SONG_SRCS := \\\n"]
    for pos, path in enumerate(paths):
        suffix = " \\\n" if pos + 1 < len(paths) else "\n"
        make_lines.append(f"\t{path}{suffix}")
    MAKE_ORDER.write_text("".join(make_lines), encoding="utf-8")

    ld_lines = [f"sound/songs/midi/{names[i]}.o(.rodata);\n" for i in SONG_IDS]
    LD_ORDER.write_text("".join(ld_lines), encoding="utf-8")

    remainder = source[lib_start:]
    SOURCE.write_text("\t.section .rodata\n\n" + remainder, encoding="utf-8")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--apply", action="store_true", help="write split song files and order manifests")
    args = parser.parse_args()

    current = SOURCE.read_text(encoding="utf-8")
    if "sSongHeader_0:" not in current:
        names, headers = audit_existing_split()
        total_bytes = LIB_RODATA_ADDR - FIRST_SONG_ADDR
        print(f"validated existing split: {len(headers)} song modules for 559 slots")
        print(f"song ROM range: 0x{FIRST_SONG_ADDR:08X}-0x{LIB_RODATA_ADDR:08X} ({total_bytes:#x} bytes)")
        print(f"first: {names[0]} @ 0x{headers[0]:08X}")
        print(f"last:  {names[558]} @ 0x{headers[558]:08X}")
        if args.apply:
            fail("songs are already split; --apply is not applicable")
        return

    source, lib_start, names, blocks, headers = audit()
    total_bytes = LIB_RODATA_ADDR - FIRST_SONG_ADDR
    print(f"validated {len(blocks)} song bodies for 559 slots")
    print(f"song ROM range: 0x{FIRST_SONG_ADDR:08X}-0x{LIB_RODATA_ADDR:08X} ({total_bytes:#x} bytes)")
    print(f"first: {names[0]} @ 0x{headers[0]:08X}")
    print(f"last:  {names[558]} @ 0x{headers[558]:08X}")
    if args.apply:
        apply_split(source, lib_start, names, blocks)
        print(f"wrote {len(blocks)} files under {OUT_DIR.relative_to(ROOT)}")
        print(f"wrote {MAKE_ORDER.relative_to(ROOT)} and {LD_ORDER.relative_to(ROOT)}")
    else:
        print("audit only; pass --apply to split")


if __name__ == "__main__":
    main()
