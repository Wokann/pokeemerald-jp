#!/usr/bin/env python3
"""Compare funcmap_us.txt / funcmap_jp.txt names against pokeemerald's
current symbol table (pokeemerald.map) and report mismatches so the
funcmaps stay aligned with pokeemerald's latest names.

Usage:
    python3 tools/sync_funcmap_names.py          # report only
    python3 tools/sync_funcmap_names.py --apply  # rewrite both funcmaps
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
US_MAP = ROOT / "funcmap_us.txt"
JP_MAP = ROOT / "funcmap_jp.txt"
EMERALD_MAP = ROOT.parent / "pokeemerald" / "pokeemerald.map"
EMERALD_SYM = ROOT.parent / "pokeemerald" / "pokeemerald.sym"

MAP_RE = re.compile(r"^([0-9A-Fa-f]{8})\s+\S+\s+(\S+)\s*$")


def load_funcmap(path):
    rows = []
    for line in path.read_text(encoding="utf-8").splitlines():
        m = MAP_RE.match(line)
        if m:
            rows.append((int(m.group(1), 16), m.group(2)))
    return rows


def load_emerald_symbols():
    """Parse pokeemerald.sym (fallback: pokeemerald.map) for ROM code
    symbols.  .sym carries every symbol including statics; the whole ROM
    code area is scanned (main .text plus hand-written asm at higher
    addresses such as libgcnmultiboot / m4a)."""
    rom_end = 0x0A000000
    syms = {}
    if EMERALD_SYM.exists():
        # pokeemerald.sym: "080003a4 t 00000020 AgbMain"
        for line in EMERALD_SYM.read_text(encoding="utf-8").splitlines():
            m = re.match(
                r"^([0-9a-fA-F]{8})\s+[gl]\s+[0-9a-fA-F]+\s+(\w+)\s*$", line
            )
            if m:
                addr = int(m.group(1), 16)
                if 0x08000000 <= addr < rom_end:
                    syms[addr] = m.group(2)
    else:
        for line in EMERALD_MAP.read_text(encoding="utf-8").splitlines():
            m = re.match(r"^\s*0x([0-9a-fA-F]{8})\s+(\w+)\s*$", line)
            if m:
                addr = int(m.group(1), 16)
                if 0x08000000 <= addr < rom_end:
                    syms[addr] = m.group(2)
    return syms


def main():
    apply = "--apply" in sys.argv
    emerald = load_emerald_symbols()
    print(f"pokeemerald text symbols: {len(emerald)} "
          f"(from {'pokeemerald.sym' if EMERALD_SYM.exists() else 'pokeemerald.map'})")

    us_rows = load_funcmap(US_MAP)
    us_new = []  # (addr, name) after sync
    us_mism = []
    us_missing = []
    for addr, name in us_rows:
        new = emerald.get(addr)
        if new is None:
            us_missing.append((addr, name))
            us_new.append((addr, name))
        else:
            us_new.append((addr, new))
            if new != name:
                us_mism.append((addr, name, new))
    print(f"US funcmap: {len(us_rows)} rows, {len(us_mism)} renamed, "
          f"{len(us_missing)} no-emerald-symbol (check source manually)")

    # JP map: JP addresses differ from US, so sync by matching the
    # function name against the US funcmap names.
    jp_rows = load_funcmap(JP_MAP)
    us_name_map = {old: new for addr, old, new in us_mism}
    jp_renamed = []
    jp_new = []
    for addr, name in jp_rows:
        if name in us_name_map and us_name_map[name] != name:
            jp_new.append((addr, us_name_map[name]))
            jp_renamed.append((addr, name, us_name_map[name]))
        else:
            jp_new.append((addr, name))
    print(f"JP funcmap: {len(jp_rows)} rows, {len(jp_renamed)} renamed via "
          f"US-name match, {len(jp_rows) - len(jp_renamed)} kept")

    if not apply:
        print("\nUS sample (address-synced):")
        for addr, old, new in us_mism[:12]:
            print(f"  0x{addr:08X} {old} -> {new}")
        print("\nJP sample (name-matched):")
        for addr, old, new in jp_renamed[:12]:
            print(f"  0x{addr:08X} {old} -> {new}")
        print("\nUS no-emerald-symbol sample (manual check needed):")
        for addr, name in us_missing[:12]:
            print(f"  0x{addr:08X} {name}")
        return

    # Write updated funcmaps.
    def rewrite(path, rows):
        rows_by_addr = {a: n for a, n in rows}
        lines = []
        for line in path.read_text(encoding="utf-8").splitlines():
            m = MAP_RE.match(line)
            if m:
                addr = int(m.group(1), 16)
                if addr in rows_by_addr:
                    lines.append(f"{m.group(1):s} {m.group(2):s} {rows_by_addr[addr]}")
                    continue
            lines.append(line)
        path.write_text("\n".join(lines) + "\n", encoding="utf-8")

    rewrite(US_MAP, us_new)
    rewrite(JP_MAP, jp_new)
    print("\nfuncmap_us.txt and funcmap_jp.txt rewritten.")


if __name__ == "__main__":
    main()
