#!/usr/bin/env python3
"""Symbolize and re-encode text inside retained (non-map) script blocks.

Each retained block starts with script instructions (decoded by the strict
parser) followed by text .string lines.  We compute each .string's ROM
address, re-encode it with the fixed charmap, and add a gJPText_<addr>
label so map scripts can reference shared text.
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_script_parser as sp
import jp_emit_maps as em
import jp_match_labels as jml

LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)')
INCINBIN_RE = re.compile(
    r'^\s*\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)')
STRING_RE = re.compile(r'^\s*\.string\s+"(.*)"\s*$')


def encode_len(text):
    """charmap-encoded byte length of a .string body (via preproc output)."""
    import subprocess, tempfile
    preproc = ROOT / 'tools' / 'preproc' / 'preproc'
    with tempfile.NamedTemporaryFile('w', suffix='.s', delete=False,
                                     encoding='utf-8') as f:
        f.write('\t.string "%s"\n' % text)
        name = f.name
    r = subprocess.run([str(preproc), name, str(ROOT / 'charmap.txt')],
                       capture_output=True)
    Path(name).unlink(missing_ok=True)
    if r.returncode != 0:
        return None
    n = 0
    for line in r.stdout.splitlines():
        n += sum(1 for _ in re.finditer(r'0x[0-9A-Fa-f]{2}', line.decode('utf-8', 'replace')))
    return n


def split_strings(text):
    has_end = text.endswith('$')
    body = text[:-1] if has_end else text
    parts = [p for p in re.split(r'(?<=\\l|\\p|\\n)', body) if p]
    out = []
    for k, part in enumerate(parts):
        if k == len(parts) - 1 and has_end:
            out.append(part + '$')
        else:
            out.append(part)
    return out


def process_block(path, block_addr, known_ptrs, write=False):
    """Walk the block: re-encode garbled .string lines from ROM bytes,
    track each text's ROM address, and label texts in known_ptrs."""
    lines = path.read_text(encoding='utf-8').splitlines(keepends=True)
    pos = block_addr
    new_lines = list(lines)
    changed = 0
    cur_start = None
    cur_line = None
    for idx, line in enumerate(lines):
        s = line.strip()
        if LABEL_RE.match(s):
            continue
        m = STRING_RE.match(s)
        if m:
            if cur_start is None:
                cur_start = pos
                cur_line = idx
            if '$' in m.group(1):
                raw = em.ROM[cur_start - 0x08000000: cur_start - 0x08000000 + 0x1000]
                e = raw.find(b'\xff')
                if e < 0:
                    return 0
                raw = raw[:e + 1]
                dec = em.decode_text(raw)
                if '[' in dec:
                    return 0
                parts = split_strings(dec)
                repl = ['\t.string "%s"\n' % p for p in parts]
                new_lines[cur_line:idx + 1] = repl
                changed += 1
                pos = cur_start + len(raw)
                if cur_start in known_ptrs:
                    label = 'gJPText_%08X' % (cur_start & 0xFFFFFF)
                    if not any(label in l for l in new_lines[max(0, cur_line - 3):cur_line]):
                        new_lines[cur_line:cur_line] = [
                            '\t.globl %s\n' % label,
                            '%s: @ 0x%08X\n' % (label, cur_start)]
                        changed += 1
                cur_start = None
                cur_line = None
            continue
        if INCINBIN_RE.match(s):
            pos += int(INCINBIN_RE.match(s).group(2), 16)
            continue
        # script instruction line (or unknown): advance by decoding
        r = sp.decode_instruction(pos)
        if r is None:
            break
        pos += r[0]
    if changed and write:
        path.write_text(''.join(new_lines), encoding='utf-8')
    return changed


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        '--write',
        action='store_true',
        help='write verified replacements; default is a read-only audit',
    )
    options = parser.parse_args()

    entries = em.map_entries()
    map_starts = {e[0] for e in entries}
    blocks = []
    for line in (ROOT / 'data' / 'event_scripts.s').read_text(
            encoding='utf-8').splitlines():
        m = LABEL_RE.match(line)
        if m:
            blocks.append(int(m.group(2), 16))
    total = 0
    # known text pointers: from map scripts + retained block scripts
    known = set(em.collect_all_text_ptrs(entries))
    for line in (ROOT / 'data' / 'event_scripts.s').read_text(
            encoding='utf-8').splitlines():
        m = LABEL_RE.match(line)
        if m:
            b = int(m.group(2), 16)
            if b >= 0x82423AF:
                sc = sp.parse_script(b)
                if sc:
                    for off, name, args, refs in sc:
                        if name in ('loadword', 'message') and args:
                            idx = 1 if name == 'loadword' else 0
                            if len(args) > idx and 0x08000000 <= args[idx] < 0x0A000000:
                                known.add(args[idx])
    for b in sorted(blocks):
        if b < 0x82423AF:
            continue
        p = ROOT / 'data' / 'scripts' / ('gUnknown_%07X.inc' % b)
        if not p.exists():
            p = ROOT / 'data' / 'scripts' / ('gUnknown_%08X.inc' % b)
        if not p.exists():
            continue
        n = process_block(p, b, known, write=options.write)
        if n:
            action = 'updated' if options.write else 'would update'
            print('%s: %d text lines %s' % (p.name, n, action))
            total += n
    print('total:', total)
    if not options.write:
        print('read-only audit; pass --write to modify files')


if __name__ == '__main__':
    main()
