#!/usr/bin/env python3
"""Match JP functions to US counterparts by call graph.

Byte-identical matching (sync_jp_names_by_bytes.py) is strong but misses
JP variants whose code differs while the function and its callees are
the same.  This tool first builds the byte-match table, then propagates
matches through the call graph: an unmatched JP function is assigned to
the US function whose callee set (translated through already-known
matches) matches its own.

Usage:
    python3 tools/match_by_callgraph.py          # report candidates
    python3 tools/match_by_callgraph.py --apply  # rename funcmap_jp.txt
"""

import re
import sys
from pathlib import Path

from extract_calls import bl_targets
from sync_jp_names_by_bytes import (
    JP_MAP,
    US_ROM,
    load_jp_funcs,
    load_us_syms,
    normalize,
)

ROOT = Path(__file__).resolve().parents[1]
JP_ROM = (ROOT / "baserom_jp.gba").read_bytes()

MAP_RE = re.compile(r"^([0-9A-Fa-f]{8})\s+\S+\s+(\S+)\s*$")


def load_us_funcmap():
    rows = []
    for line in (ROOT / "funcmap_us.txt").read_text(encoding="utf-8").splitlines():
        m = MAP_RE.match(line)
        if m:
            rows.append((int(m.group(1), 16), m.group(2)))
    rows.sort()
    out = []
    for i, (addr, name) in enumerate(rows):
        nxt = rows[i + 1][0] if i + 1 < len(rows) else 0x09FFFFFF
        out.append((addr, name, nxt - addr))
    return out


def byte_match_table(jp_funcs, us_syms):
    """Return {jp_addr: us_addr} from exact normalized-byte equality."""
    lookup = {}
    for us_addr, (name, size) in us_syms.items():
        if size > 0x2000:
            continue
        data = US_ROM[us_addr & 0xFFFFFF : (us_addr & 0xFFFFFF) + size]
        lookup.setdefault((size, normalize(data)), []).append(us_addr)
    table = {}
    for jp_addr, name, size in jp_funcs:
        if size > 0x2000:
            continue
        data = JP_ROM[jp_addr & 0xFFFFFF : (jp_addr & 0xFFFFFF) + size]
        hits = lookup.get((size, normalize(data)), [])
        if len(hits) == 1:
            table[jp_addr] = hits[0]
    return table


def main():
    apply = "--apply" in sys.argv
    jp_funcs = load_jp_funcs()
    us_funcs = load_us_funcmap()
    us_syms = load_us_syms()

    us_addr_of = {addr: name for addr, name, _ in us_funcs}

    jp_calls = {
        addr: bl_targets(
            JP_ROM[addr & 0xFFFFFF : (addr & 0xFFFFFF) + size], addr
        )
        for addr, name, size in jp_funcs
    }
    us_calls = {
        addr: bl_targets(
            US_ROM[addr & 0xFFFFFF : (addr & 0xFFFFFF) + size], addr
        )
        for addr, name, size in us_funcs
    }

    us_by_size = {}
    for us_addr, us_name, us_size in us_funcs:
        us_by_size.setdefault(us_size, []).append(us_addr)

    mapping = byte_match_table(jp_funcs, us_syms)
    used_us = set(mapping.values())
    us_to_jp = {us: jp for jp, us in mapping.items()}
    for _ in range(8):
        added = 0
        for jp_addr, jp_name, jp_size in jp_funcs:
            if jp_addr in mapping:
                continue
            jp_targets = jp_calls.get(jp_addr, set())
            jp_known = {t for t in jp_targets if t in mapping}
            jp_known_us = {mapping[t] for t in jp_known}
            if not jp_known:
                continue
            best = None
            best_score = -1
            for delta in range(0, 5):
                for us_size in (jp_size + delta, jp_size - delta):
                    if us_size not in us_by_size:
                        continue
                    for us_addr in us_by_size[us_size]:
                        if us_addr in used_us:
                            continue
                        us_targets = us_calls.get(us_addr, set())
                        us_known = {t for t in us_targets if t in us_to_jp}
                        us_known_jp = {us_to_jp[t] for t in us_known}
                        # Bidirectional callee agreement: JP's mapped
                        # callees all appear in US, and US's mapped
                        # callees are exactly JP's mapped callees.
                        if not (jp_known_us <= us_targets):
                            continue
                        if us_known_jp != jp_known:
                            continue
                        # Unmapped callee counts must be close.
                        jp_unknown = len(jp_targets - jp_known)
                        us_unknown = len(us_targets - us_known)
                        if abs(us_unknown - jp_unknown) > 2:
                            continue
                        hit = len(jp_known_us & us_targets)
                        if hit > best_score:
                            best_score = hit
                            best = us_addr
            if best is not None and best_score == len(jp_known_us):
                mapping[jp_addr] = best
                used_us.add(best)
                us_to_jp[best] = jp_addr
                added += 1
        if added == 0:
            break

    print(f"byte matches: {len(byte_match_table(jp_funcs, us_syms))}")
    print(f"total after call-graph propagation: {len(mapping)}")
    if not apply:
        shown = 0
        for jp_addr, us_addr in sorted(mapping.items()):
            jp_name = next(n for a, n, s in jp_funcs if a == jp_addr)
            us_name = us_addr_of.get(us_addr, "?")
            if jp_name != us_name and shown < 25:
                print(f"  0x{jp_addr:08X} {jp_name} -> {us_name}")
                shown += 1
        return

    by_addr = {
        jp_addr: us_addr_of[us_addr]
        for jp_addr, us_addr in mapping.items()
        if us_addr in us_addr_of
    }
    lines = []
    for line in JP_MAP.read_text(encoding="utf-8").splitlines():
        m = MAP_RE.match(line)
        if m:
            addr = int(m.group(1), 16)
            if addr in by_addr:
                lines.append(f"{m.group(1)} {m.group(2)} {by_addr[addr]}")
                continue
        lines.append(line)
    JP_MAP.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("funcmap_jp.txt rewritten.")


if __name__ == "__main__":
    main()
