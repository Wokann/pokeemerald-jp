#!/usr/bin/env python3
"""Decompile the 20 raw M4A song parts (songs 269/350/455) to MPlayDef macros.

The parts live as raw bytes in data/data_b2c_mid8_tail.s under
sSong269_Part0 / sSong350_Part0..8 / sSong455_Part0..9. This script:
  - parses each part's byte stream into MPlayDef macro lines
    (.byte KEYSH, 0 / TEMPO, 66 / N02, Cn3, 112 / W04 / FINE ...)
  - replaces the part's incbin with the macro lines
  - roundtrip-verifies that the macros encode back to the identical bytes

Usage:
  python3 tools/decompile_m4a_tracks.py            # decompile + rewrite .s
  python3 tools/decompile_m4a_tracks.py --check    # verify only
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
S_PATH = ROOT / "data" / "data_b2c_mid8_tail.s"
MPLAY = ROOT / "sound" / "MPlayDef.s"


def load_equ():
    """Read .equ definitions from MPlayDef.s, expanding simple expressions."""
    raw = {}
    for line in MPLAY.read_text(encoding="utf-8").splitlines():
        m = re.match(r"^\s*\.equ\s+(\w+),\s*(.+)", line)
        if m:
            raw[m.group(1)] = m.group(2).split("@")[0].strip()
    # Expand in dependency order (W01 = W00+1 etc.)
    vals = {}
    for _ in range(10):
        for name, expr in raw.items():
            if name in vals:
                continue
            try:
                vals[name] = eval(expr, {}, vals)
            except Exception:
                pass
    return vals


def build_tables(equ):
    # Byte value -> macro name (Wxx, Nxx, FINE, ...)
    by_val = {}
    for name, v in equ.items():
        if isinstance(v, int) and 0x80 <= v <= 0xFF:
            by_val.setdefault(v, name)
    # Note value -> note name (Cn3=60 etc.)
    note_by_val = {}
    for name, v in equ.items():
        if re.match(r"^[A-G][ns][-0-9]", name) and isinstance(v, int):
            note_by_val[v] = name
    return by_val, note_by_val


def parse_track(data, by_val, note_by_val):
    """Return list of macro lines for a raw M4A track byte stream."""
    lines = []
    i = 0
    n = len(data)
    single = {0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4,
              0xC5, 0xC8}
    no_param = {0xB1, 0xB4, 0xCE, 0xCF}
    two_param = {0xB2, 0xB3, 0xB5, 0xB9}
    while i < n:
        b = data[i]
        if 0x80 <= b <= 0xB0:
            lines.append(f".byte\t{by_val.get(b, hex(b))}")
            i += 1
        elif b in no_param:
            lines.append(f".byte\t{by_val.get(b, hex(b))}")
            i += 1
        elif b in two_param:
            a1 = data[i + 1] if i + 1 < n else 0
            a2 = data[i + 2] if i + 2 < n else 0
            lines.append(f".byte\t{by_val.get(b, hex(b))} , {a1}, {a2}")
            i += 3
        elif b in single:
            a1 = data[i + 1] if i + 1 < n else 0
            lines.append(f".byte\t{by_val.get(b, hex(b))} , {a1}")
            i += 2
        elif b == 0xCD:  # XCMD: 2 params + possibly trailing data bytes
            a1 = data[i + 1] if i + 1 < n else 0
            a2 = data[i + 2] if i + 2 < n else 0
            lines.append(f".byte\tXCMD , {a1}, {a2}")
            i += 3
            naked = []
            while i < n and data[i] < 0x80:
                naked.append(str(data[i]))
                i += 1
            if naked:
                lines.append(f".byte\t{', '.join(naked)}")
        elif 0xD0 <= b <= 0xFF:  # note
            note_name = by_val.get(b, hex(b))
            i += 1
            args = []
            if i < n and data[i] < 0x80:
                args.append(note_by_val.get(data[i], str(data[i])))
                i += 1
                if i < n and data[i] < 0x80:
                    args.append(str(data[i]))
                    i += 1
            suffix = f", {', '.join(args)}" if args else ""
            lines.append(f".byte\t{note_name}{suffix}")
        else:
            # Unexpected raw parameter bytes; emit verbatim.
            naked = []
            while i < n and data[i] < 0x80:
                naked.append(str(data[i]))
                i += 1
            if naked:
                lines.append(f".byte\t{', '.join(naked)}")
            else:
                i += 1
    return lines


def encode_lines(lines, equ):
    """Encode macro lines back to bytes for roundtrip verification."""
    name_val = {name: v for name, v in equ.items() if isinstance(v, int)}
    out = bytearray()
    for line in lines:
        m = re.match(r"\.byte\t(.+)", line)
        if not m:
            continue
        for tok in m.group(1).split(","):
            tok = tok.strip()
            if not tok:
                continue
            if tok in name_val:
                out.append(name_val[tok])
            else:
                out.append(int(tok))
    return bytes(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    equ = load_equ()
    by_val, note_by_val = build_tables(equ)
    rom = ROM_PATH.read_bytes()
    raw = S_PATH.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")

    # Locate the 20 target parts and their incbin lines.
    pat_part = re.compile(r"^(sSong(?:269|350|455)_Part\d+):\s*@\s*0x([0-9A-Fa-f]+)$")
    pat_inc = re.compile(
        r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
    )

    all_labels = []
    for l in lines:
        m = re.match(r"^(\w+):\s*@\s*0x([0-9A-Fa-f]+)$", l)
        if m:
            all_labels.append(int(m.group(2), 16))

    targets = []
    for i, line in enumerate(lines):
        m = pat_part.match(line)
        if m:
            addr = int(m.group(2), 16)
            nxt = min((a for a in all_labels if a > addr), default=None)
            end = nxt - 0x08000000 if nxt else len(rom)
            targets.append((m.group(1), addr, i, end))
    targets.sort(key=lambda t: t[1])

    problems = []
    edits = {}  # label line idx -> [label + macro lines]
    for name, addr, idx, end in targets:
        data = rom[addr - 0x08000000 : end]
        if not data:
            problems.append(f"{name}: empty track")
            continue
        macro_lines = parse_track(data, by_val, note_by_val)
        encoded = encode_lines(macro_lines, equ)
        if encoded != data:
            problems.append(f"{name}: roundtrip mismatch ({len(encoded)} vs {len(data)})")
            continue
        block = [f"{name}: @ 0x{addr:X}"] + macro_lines
        edits[idx] = block

    if problems:
        print("PROBLEMS:")
        for p in problems[:20]:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        new_lines = list(lines)
        for idx in sorted(edits, reverse=True):
            # Replace the label line and its following incbin line.
            new_lines[idx : idx + 2] = edits[idx]
        S_PATH.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))
    print(f"{'Check' if args.check else 'Decompiled'}: {len(targets)} tracks to M4A macros")


if __name__ == "__main__":
    main()
