#!/usr/bin/env python3
"""Group JP scripts by map from reproducible ROM-derived metadata."""

import json
from pathlib import Path

from jp_map_script_metadata import build_metadata
from jp_script_parser import build_graph

ROOT = Path(__file__).resolve().parents[1]
MAP_HEADERS, MAP_TABLES = build_metadata()


def group_scripts():
    """Map name -> list of (tag, script_addr) from its mapScripts table."""
    per_map = {}
    for header in MAP_HEADERS:
        if header.map_scripts == 0:
            continue
        entries = MAP_TABLES.get(header.map_scripts)
        if not entries:
            continue
        per_map.setdefault(header.name, []).extend(entries)
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
    graph, _ = build_graph(MAP_TABLES)
    graph_addrs = set(graph)
    covered = set()
    for mname, entries in per_map.items():
        for t, p in entries:
            covered.add(p)
    print('unique map script ptrs:', len(covered))
    in_graph = covered & graph_addrs
    print('in graph:', len(in_graph))
    # save grouped map
    out = {k: [[t, hex(p)] for t, p in v] for k, v in sorted(per_map.items())}
    output = ROOT / 'build' / 'jp_map_script_metadata' / 'jp_scripts_by_map.json'
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(out, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')
    print('saved', output)


if __name__ == '__main__':
    main()
