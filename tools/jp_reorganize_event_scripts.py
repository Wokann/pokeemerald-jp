#!/usr/bin/env python3
"""Rebuild data/event_scripts.s:

  - keep the header region (< first map-script table @ 0x081DB7E8)
  - replace the map region (0x081DB7E8 .. first non-map label after the
    last map table) with one .include per map file, in address order
  - keep the trailing non-map region (std/trainer/misc scripts) as-is
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_emit_maps as em

EVENT_S = ROOT / 'data' / 'event_scripts.s'
LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)')


def main():
    entries = em.map_entries()
    first_map = entries[0][0]
    all_labels = em.event_script_labels()
    map_starts = {e[0] for e in entries}
    nonmap = sorted(a for a in all_labels if a not in map_starts)
    last_map_end = next((a for a in nonmap if a > entries[-1][0]), 0x0828F000)
    print('first map @ %08X, last map end @ %08X' % (first_map, last_map_end))

    lines = EVENT_S.read_text(encoding='utf-8').splitlines(keepends=True)
    out = []
    inserted = False
    dropping = False
    n_drop = 0
    cur_addr = None
    for line in lines:
        m = LABEL_RE.match(line.rstrip('\r\n'))
        if m:
            cur_addr = int(m.group(2), 16)
            if cur_addr == first_map and not inserted:
                out.append(line)
                prev_ms = None
                for ms, mname, gi, mi, ents, events_addr in entries:
                    if ms == prev_ms:
                        continue
                    prev_ms = ms
                    out.append('\t.include "data/maps/%s/scripts.inc"\n' % mname)
                inserted = True
                dropping = True
                continue
            if dropping and cur_addr < last_map_end:
                n_drop += 1
                continue
            if cur_addr >= last_map_end:
                dropping = False
        if dropping:
            continue
        out.append(line)
    print('dropped %d map-region blocks' % n_drop)
    if '--write' in sys.argv:
        EVENT_S.write_text(''.join(out), encoding='utf-8')
        print('wrote', EVENT_S)


if __name__ == '__main__':
    main()
