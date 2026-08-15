#!/usr/bin/env python3
"""Group JP scripts by map using the map-script tables and US map names."""

import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
US_JSON = Path('/home/kenny/pokeemerald/data/maps/map_groups.json')
MAP_HEADERS = json.loads(Path('/tmp/jp_map_headers.json').read_text())
MAP_TABLES = json.loads(Path('/tmp/map_script_tables.json').read_text())
GRAPH = json.loads(Path('/tmp/jp_script_graph.json').read_text())


def toi(x):
    return int(x, 16) if isinstance(x, str) else int(x)


def build_map_names():
    """Return {(group, map): name} for the first 34 groups."""
    us = json.loads(US_JSON.read_text())
    order = us['group_order']
    names = {}
    for gi, gkey in enumerate(order[:34]):
        for mi, name in enumerate(us[gkey]):
            names[(gi, mi)] = name
    return names


MAP_NAMES = build_map_names()


def group_scripts():
    """Map name -> list of (tag, script_addr) from its mapScripts table."""
    per_map = {}
    for entry in MAP_HEADERS:
        gi, mi, h, layout, events, ms, wild, name_hex = entry
        key = (gi, mi)
        mname = MAP_NAMES.get(key)
        if mname is None:
            continue
        ms = toi(ms)
        if ms == 0:
            continue
        tables = MAP_TABLES.get(hex(ms)) or MAP_TABLES.get('%x' % ms)
        if not tables:
            continue
        entries = []
        for t, p in tables:
            entries.append((toi(t), toi(p)))
        per_map.setdefault(mname, []).extend(entries)
    return per_map


def main():
    per_map = group_scripts()
    print('maps with scripts:', len(per_map))
    total = 0
    # distribution
    sizes = sorted((len(v), k) for k, v in per_map.items())
    print('smallest:', sizes[:5])
    print('largest:', sizes[-5:])
    total_entries = sum(len(v) for v in per_map.values())
    print('total map script entries:', total_entries)
    # check coverage against graph
    graph_addrs = {int(a, 16) for a in GRAPH}
    covered = set()
    for mname, entries in per_map.items():
        for t, p in entries:
            covered.add(p)
    print('unique map script ptrs:', len(covered))
    in_graph = covered & graph_addrs
    print('in graph:', len(in_graph))
    # save grouped map
    out = {k: [[t, hex(p)] for t, p in v] for k, v in sorted(per_map.items())}
    Path('/tmp/jp_scripts_by_map.json').write_text(
        json.dumps(out, indent=0, ensure_ascii=False))
    print('saved /tmp/jp_scripts_by_map.json')


if __name__ == '__main__':
    main()
