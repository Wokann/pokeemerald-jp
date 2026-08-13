#!/usr/bin/env python3
"""Locate retained-block .string lines by encoding them with the charmap
and matching against ROM bytes, then add gJPText_<addr> labels."""

import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_emit_maps as em
import jp_add_labels as jl

PREPROC = ROOT / 'tools' / 'preproc' / 'preproc'
CHARMAP = ROOT / 'charmap.txt'
STRING_RE = re.compile(r'^\s*\.string\s+"(.*)"\s*$')
LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*):')


def encode_bytes(text):
    with tempfile.NamedTemporaryFile('w', suffix='.s', delete=False,
                                     encoding='utf-8') as f:
        f.write('\t.string "%s"\n' % text)
        name = f.name
    r = subprocess.run([str(PREPROC), name, str(CHARMAP)], capture_output=True)
    Path(name).unlink(missing_ok=True)
    if r.returncode != 0:
        return None
    out = bytearray()
    for line in r.stdout.splitlines():
        for m in re.finditer(r'0x([0-9A-Fa-f]{2})', line.decode('utf-8', 'replace')):
            out.append(int(m.group(1), 16))
    return bytes(out)


def process_addrs(addr_list):
    missing = set(addr_list)
    print('missing:', len(missing))
    # rom bytes for each missing addr
    rom = em.ROM
    rom_text = {}
    for m in missing:
        raw = rom[m - 0x08000000:m - 0x08000000 + 64]
        e = raw.find(b'\xff')
        if e >= 0:
            raw = raw[:e + 1]
        rom_text[m] = raw
    # map each missing addr to its retained block
    blocks = []
    for line in (ROOT / 'data' / 'event_scripts.s').read_text(
            encoding='utf-8').splitlines():
        m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)', line)
        if m:
            blocks.append(int(m.group(2), 16))
    blocks.sort()
    addr_to_block = {}
    for miss in missing:
        prev = None
        for b in blocks:
            if b <= miss:
                prev = b
            if b > miss:
                break
        if prev is not None and prev >= 0x82423AF:
            addr_to_block[miss] = prev
    print('in retained blocks:', len(addr_to_block))
    found = 0
    for baddr in sorted(set(addr_to_block.values())):
        p = ROOT / 'data' / 'scripts' / ('gUnknown_%07X.inc' % baddr)
        if not p.exists():
            continue
        this_missing = [a for a, b in addr_to_block.items() if b == baddr]
        txt = p.read_text(encoding='utf-8')
        lines = txt.splitlines(keepends=True)
        new_lines = list(lines)
        changed = 0
        for idx, line in enumerate(lines):
            m = STRING_RE.match(line.strip())
            if not m:
                continue
            enc = encode_bytes(m.group(1))
            if enc is None or not enc:
                continue
            for miss in this_missing:
                raw = rom_text[miss]
                if miss in missing and raw.startswith(enc):
                    label = 'gJPText_%08X' % (miss & 0xFFFFFF)
                    new_lines[idx:idx] = ['\t.globl %s\n' % label,
                                          '%s: @ 0x%08X\n' % (label, miss)]
                    missing.discard(miss)
                    found += 1
                    changed += 1
                    break
        if changed:
            p.write_text(''.join(new_lines), encoding='utf-8')
            print('%s: +%d' % (p.name, changed))
    print('located:', found, 'remaining:', sorted(hex(x) for x in missing))
    return found


def main():
    if len(sys.argv) > 1:
        missing = [int(a, 16) for a in sys.argv[1:]]
    else:
        missing = jl.collect_missing()
    process_addrs(missing)


if __name__ == '__main__':
    main()
