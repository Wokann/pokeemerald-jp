#!/usr/bin/env python3
"""Find JP gUnknown tables by matching pokeemerald const u8/u16 arrays.

Scans pokeemerald's const u8/u16 arrays (values may be plain numbers or
macros), expands macro values using JP/US constants, and searches the byte
sequence in baserom_jp.gba. Reported matches identify what a JP gUnknown
table is.

Usage:
  python3 tools/match_us_arrays.py [--min 4] [--addr 0x...]
"""

import argparse
import glob
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
US = Path("/home/kenny/pokeemerald")


def collect_defines():
    """Collect #define values from JP and US constants headers."""
    vals = {}
    for base in (ROOT / "include", US / "include"):
        for f in glob.glob(str(base / "constants" / "*.h")) + glob.glob(str(base / "*.h")):
            for line in open(f, errors="ignore"):
                m = re.match(r"#define\s+(\w+)\s+(.+)", line)
                if m:
                    vals[m.group(1)] = m.group(2).split("//")[0].split("/*")[0].strip()
    # expand numeric expressions
    for _ in range(6):
        for name, expr in list(vals.items()):
            if isinstance(expr, int):
                continue
            try:
                vals[name] = eval(expr, {"__builtins__": {}}, vals)
            except Exception:
                pass
    return vals


def collect_enums():
    """Collect enum values from US headers."""
    vals = {}
    for f in glob.glob(str(US / "include" / "**" / "*.h"), recursive=True):
        text = open(f, errors="ignore").read()
        for m in re.finditer(r"enum\s*\{(.*?)\}", text, re.S):
            val = 0
            for item in m.group(1).split(","):
                item = item.strip()
                if not item:
                    continue
                mm = re.match(r"(\w+)\s*=\s*(.+)", item)
                if mm:
                    name, expr = mm.group(1), mm.group(2)
                    try:
                        val = eval(expr, {"__builtins__": {}}, vals)
                    except Exception:
                        pass
                else:
                    name = item
                vals[name] = val
                val += 1
    return vals


def expand_arrays():
    """Parse US const u8/u16 arrays, return list of (file, type, name, bytes)."""
    defines = collect_defines()
    enums = collect_enums()
    ns = {**defines, **enums}
    results = []
    for f in (list(glob.glob(str(US / "src" / "*.c"))) +
              list(glob.glob(str(US / "src" / "data" / "*.c"))) +
              list(glob.glob(str(US / "src" / "data" / "*" / "*.c")))):
        text = open(f, errors="ignore").read()
        for m in re.finditer(
            r"const\s+(u8|u16)\s+(\w+)\[([^\]]+)\]\s*=\s*\{(.*?)\};", text, re.S
        ):
            typ, name, size, body = m.groups()
            if "[" in body or "*" in body:
                continue
            items = []
            for tok in body.split(","):
                tok = tok.strip()
                if not tok:
                    continue
                try:
                    v = eval(tok, {"__builtins__": {}}, ns)
                    items.append(int(v))
                except Exception:
                    items = None
                    break
            if items is None:
                continue
            if typ == "u8" and all(0 <= v <= 0xFF for v in items):
                data = bytes(items)
            elif typ == "u16" and all(0 <= v <= 0xFFFF for v in items):
                data = b"".join(struct.pack("<H", v) for v in items)
            else:
                continue
            if len(data) >= 4:
                results.append((Path(f).name, typ, name, data))
    return results


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=int, default=4, help="minimum byte length")
    ap.add_argument("--addr", help="only report matches at this JP address")
    args = ap.parse_args()

    rom = (ROOT / "baserom_jp.gba").read_bytes()
    arrays = expand_arrays()
    print(f"US arrays expanded: {len(arrays)}")

    found = 0
    for f, typ, name, data in arrays:
        if len(data) < args.min:
            continue
        idx = 0
        while True:
            idx = rom.find(data, idx)
            if idx < 0:
                break
            addr = 0x08000000 + idx
            if args.addr is None or addr == int(args.addr, 16):
                print(f"MATCH {name} ({typ}, {len(data)}B) at 0x{addr:X} [{f}]")
                found += 1
            idx += 1
    print(f"total matches: {found}")


if __name__ == "__main__":
    main()
