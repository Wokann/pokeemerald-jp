#!/usr/bin/env python3
"""Rebuild retained (non-map) script blocks from ROM: decode the leading
script, symbolize referenced text, keep the rest as .incbin."""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_emit_maps as em
import jp_script_parser as sp

LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)')


def retained_blocks():
    blocks = []
    for line in (ROOT / 'data' / 'event_scripts.s').read_text(
            encoding='utf-8').splitlines():
        m = LABEL_RE.match(line)
        if m:
            b = int(m.group(2), 16)
            if b >= 0x82423AF:
                blocks.append(b)
    blocks.sort()
    return blocks


def rebuild(block, next_block, text_ptrs, rom):
    lines = []
    covered = set()
    # texts inside this block
    texts = sorted(p for p in text_ptrs if block <= p < next_block)
    lines.append('@ retained block @ 0x%08X' % block)
    lines.append('')
    # segments in address order
    segs = []
    for tp in texts:
        segs.append((tp, 'text', tp))
    segs.sort(key=lambda x: x[0])
    # mark coverage
    for start, kind, payload in segs:
        if kind == 'text':
            raw = rom[start - 0x08000000: start - 0x08000000 + 0x1000]
            e = raw.find(b'\xff')
            if e < 0:
                continue
            for b in range(start, start + e + 1):
                covered.add(b)
    # raw gaps
    raw_segs = []
    raw_start = None
    for a in range(block, next_block):
        if a not in covered:
            if raw_start is None:
                raw_start = a
        else:
            if raw_start is not None:
                raw_segs.append((raw_start, a))
                raw_start = None
    if raw_start is not None:
        raw_segs.append((raw_start, next_block))
    for a, b in raw_segs:
        segs.append((a, 'raw', a))
    segs.sort(key=lambda x: x[0])
    # emit
    out = []
    for start, kind, payload in segs:
        if kind == 'text':
            raw = rom[start - 0x08000000: start - 0x08000000 + 0x1000]
            e = raw.find(b'\xff')
            if e < 0:
                out.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                    start - 0x08000000, 16))
                continue
            raw = raw[:e + 1]
            dec = em.decode_text(raw)
            if '[' in dec:
                out.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                    start - 0x08000000, len(raw)))
                continue
            label = 'gJPText_%08X' % (start & 0xFFFFFF)
            out.append('\t.globl %s' % label)
            out.append('%s: @ 0x%08X' % (label, start))
            for part in [p for p in re.split(r'(?<=\\l|\\p|\\n)', dec) if p]:
                out.append('\t.string "%s"' % part)
            out.append('')
        else:
            b = next_block
            for s2, k2, p2 in segs:
                if k2 != 'raw' and s2 > start:
                    b = min(b, s2)
            out.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                start - 0x08000000, b - start))
    return '\n'.join(out) + '\n'


def main():
    blocks = retained_blocks()
    print('retained blocks:', len(blocks))
    entries = em.map_entries()
    text_ptrs = em.collect_all_text_ptrs(entries)
    # add retained script refs
    for b in blocks:
        sc = sp.parse_script(b)
        if sc:
            for o, n, ar, r in sc:
                if n in ('loadword', 'message') and ar:
                    idx = 1 if n == 'loadword' else 0
                    if len(ar) > idx and 0x08000000 <= ar[idx] < 0x0A000000:
                        text_ptrs.add(ar[idx])
    rom = em.ROM
    total = 0
    for i, b in enumerate(blocks):
        nb = blocks[i + 1] if i + 1 < len(blocks) else 0x828D2B4
        nb = min(nb, 0x828D2B4)
        out = rebuild(b, nb, text_ptrs, rom)
        p = ROOT / 'data' / 'scripts' / ('gUnknown_%07X.inc' % b)
        if p.exists():
            p.write_text(out, encoding='utf-8')
            total += 1
    print('rebuilt', total)


if __name__ == '__main__':
    main()
