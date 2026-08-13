#!/usr/bin/env python3
"""Locate text .string lines inside retained blocks by walking the block's
byte layout (script instructions via the strict parser, .incbin, .string
encodings) and add gJPText_<addr> labels at exact ROM offsets."""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_script_parser as sp
import jp_match_labels as jml
import jp_emit_maps as em

LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*):')
STRING_RE = re.compile(r'^\s*\.string\s+"(.*)"\s*$')
INCINBIN_RE = re.compile(
    r'^\s*\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)')


def walk_block(block_addr, lines):
    """Return list of (rom_addr, line_idx) for each .string start."""
    pos = block_addr
    out = []
    cur_start = None
    for idx, line in enumerate(lines):
        s = line.strip()
        if not s or s.startswith('@') or s.startswith('#'):
            continue
        if LABEL_RE.match(s):
            continue
        m = STRING_RE.match(s)
        if m:
            if cur_start is None:
                cur_start = pos
                out.append((pos, idx))
            if '$' in m.group(1):
                raw = em.ROM[cur_start - 0x08000000: cur_start - 0x08000000 + 0x1000]
                e = raw.find(b'\xff')
                if e < 0:
                    return None
                pos = cur_start + e + 1
                cur_start = None
            continue
        m = INCINBIN_RE.match(s)
        if m:
            pos += int(m.group(2), 16)
            continue
        # script instruction line
        r = sp.decode_instruction(pos)
        if r is None:
            return None
        pos += r[0]
    return out


def process_block(p, block_addr, missing):
    lines = p.read_text(encoding='utf-8').splitlines(keepends=True)
    starts = walk_block(block_addr, lines)
    if starts is None:
        return 0
    pos_map = {a: idx for a, idx in starts}
    new_lines = list(lines)
    changed = 0
    for miss in missing:
        idx = pos_map.get(miss)
        if idx is None:
            continue
        # avoid duplicate insertion
        if any('gJPText_%08X' % (miss & 0xFFFFFF) in l for l in lines[max(0, idx - 3):idx]):
            continue
        label = 'gJPText_%08X' % (miss & 0xFFFFFF)
        new_lines[idx:idx] = ['\t.globl %s\n' % label,
                              '%s: @ 0x%08X\n' % (label, miss)]
        changed += 1
    if changed:
        p.write_text(''.join(new_lines), encoding='utf-8')
    return changed


def process(missing):
    # map to blocks
    blocks = []
    for line in (ROOT / 'data' / 'event_scripts.s').read_text(
            encoding='utf-8').splitlines():
        m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)', line)
        if m:
            blocks.append(int(m.group(2), 16))
    blocks.sort()
    by_block = {}
    for miss in missing:
        prev = None
        for b in blocks:
            if b <= miss:
                prev = b
            if b > miss:
                break
        if prev is not None and prev >= 0x82423AF:
            by_block.setdefault(prev, []).append(miss)
    print('blocks:', len(by_block))
    total = 0
    for baddr, misses in sorted(by_block.items()):
        p = ROOT / 'data' / 'scripts' / ('gUnknown_%07X.inc' % baddr)
        if not p.exists():
            print('missing file for', hex(baddr))
            continue
        n = process_block(p, baddr, misses)
        if n:
            print('%s: +%d' % (p.name, n))
            total += n
    print('total inserted:', total)
    return total


def main():
    missing = [int(a, 16) for a in sys.argv[1:]] if len(sys.argv) > 1 else \
        jml.jl.collect_missing()
    process(missing)


if __name__ == '__main__':
    main()
