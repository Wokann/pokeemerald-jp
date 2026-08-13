#!/usr/bin/env python3
"""Add gJPText_<addr> labels to retained script blocks for text pointers
that map scripts reference but no label exists for yet.

Uses the preproc-expanded output to map ROM offsets back to source lines.
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_emit_maps as em
import jp_script_parser as sp

REGION_BASE = 0x081DABAC


def preproc_output():
    preproc = ROOT / 'tools' / 'preproc' / 'preproc'
    r = subprocess.run([str(preproc), str(ROOT / 'data' / 'event_scripts.s'),
                        str(ROOT / 'charmap.txt')], capture_output=True)
    return r.stdout.decode('utf-8', 'replace').splitlines()


def collect_missing():
    """Text pointers referenced by scripts but not yet labeled."""
    entries = em.map_entries()
    all_ptrs = em.collect_all_text_ptrs(entries)
    # add retained-block script references
    labels = em.event_script_labels()
    blocks = sorted(a for a in labels if a >= 0x82423AF)
    for b in blocks:
        sc = sp.parse_script(b)
        if not sc:
            continue
        for off, name, args, refs in sc:
            if name in ('loadword', 'message') and args:
                idx = 1 if name == 'loadword' else 0
                if len(args) > idx and 0x08000000 <= args[idx] < 0x0A000000:
                    all_ptrs.add(args[idx])
    # labeled text addresses (gJPText_ labels in data/)
    labeled = set()
    for p in (ROOT / 'data').rglob('*.inc'):
        for m in re.finditer(r'gJPText_([0-9A-Fa-f]{7,8}):', p.read_text(
                encoding='utf-8', errors='ignore')):
            labeled.add(0x08000000 + int(m.group(1), 16))
    return sorted(all_ptrs - labeled)


def byte_offsets(lines):
    """Yield (rom_addr, file, src_line) for each byte position."""
    out = []
    addr = REGION_BASE
    cur_file = None
    cur_line = None
    for line in lines:
        m = re.match(r'# (\d+) "(.*)"', line)
        if m:
            cur_line = int(m.group(1))
            cur_file = m.group(2)
            continue
        if cur_file is None:
            continue
        s = line.strip()
        if s.startswith('.byte'):
            n = len(re.findall(r'0x[0-9A-Fa-f]{2}', s))
            out.append((addr, cur_file, cur_line))
            addr += n
            cur_line += 1
        elif s.startswith('.incbin'):
            m2 = re.search(r'0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)', s)
            if m2:
                addr += int(m2.group(2), 16)
            cur_line += 1
        else:
            cur_line += 1
    return out


def main():
    missing = collect_missing()
    print('missing text ptrs:', len(missing))
    if not missing:
        return
    lines = preproc_output()
    offsets = byte_offsets(lines)
    # map addr -> (file, line)
    ptr_to_src = {}
    for addr, f, ln in offsets:
        for miss in missing:
            if miss not in ptr_to_src and addr <= miss < addr + 64:
                ptr_to_src[miss] = (f, ln)
    # group by file, insert labels at source lines
    from collections import defaultdict
    by_file = defaultdict(list)
    for miss, (f, ln) in sorted(ptr_to_src.items()):
        if 'data/scripts/' in f:
            by_file[f].append((miss, ln))
    print('located:', sum(len(v) for v in by_file.values()))
    for f, items in by_file.items():
        path = ROOT / f
        src = path.read_text(encoding='utf-8').splitlines(keepends=True)
        # insert from last to first
        for miss, ln in sorted(items, key=lambda x: -x[1]):
            label = 'gJPText_%08X' % (miss & 0xFFFFFF)
            src.insert(ln - 1, '\t.globl %s\n%s: @ 0x%08X\n' % (label, label, miss))
        path.write_text(''.join(src), encoding='utf-8')
        print('%s: inserted %d labels' % (f, len(items)))


if __name__ == '__main__':
    main()
