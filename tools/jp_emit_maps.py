#!/usr/bin/env python3
"""Emit per-map script files following the US data/maps/<Map>/scripts.inc
layout, decoded with the strict JP script parser."""

import json
import re
import sys
from pathlib import Path
import collections

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_script_parser as sp

ROM = sp.ROM
MAP_HEADERS = json.loads(Path('/tmp/jp_map_headers.json').read_text())
MAP_TABLES = json.loads(Path('/tmp/map_script_tables.json').read_text())
US_JSON = Path('/home/kenny/pokeemerald/data/maps/map_groups.json')

MAP_SCRIPT_NAMES = {
    1: 'MAP_SCRIPT_ON_LOAD',
    2: 'MAP_SCRIPT_ON_FRAME_TABLE',
    3: 'MAP_SCRIPT_ON_TRANSITION',
    4: 'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE',
    5: 'MAP_SCRIPT_ON_RESUME',
    6: 'MAP_SCRIPT_ON_DIVE_WARP',
    7: 'MAP_SCRIPT_ON_RETURN_TO_FIELD',
}


def toi(x):
    return int(x, 16) if isinstance(x, str) else int(x)


def build_map_names():
    us = json.loads(US_JSON.read_text())
    order = us['group_order']
    names = {}
    for gi, gkey in enumerate(order[:34]):
        for mi, name in enumerate(us[gkey]):
            names[(gi, mi)] = name
    return names


MAP_NAMES = build_map_names()

# text decoding support (single-byte kana priority + control codes)
CHARMAP = ROOT / 'charmap.txt'


def build_text_maps():
    single = {}
    multi = {}
    for line in CHARMAP.read_text(encoding='utf-8').splitlines():
        line = line.strip()
        if not line or line.startswith('@'):
            continue
        m = re.match(r"'((?:[^'\\]|\\.)*)'\s*=\s*([0-9A-Fa-f ]+)", line)
        if m:
            key = m.group(1).replace("\\'", "'")
            vals = [int(x, 16) for x in m.group(2).split()]
            if len(vals) == 1:
                single[vals[0]] = key
            continue
        m = re.match(r'([A-Za-z_][A-Za-z0-9_]*)\s*=\s*([0-9A-Fa-f ]+)', line)
        if m:
            vals = [int(x, 16) for x in m.group(2).split()]
            if len(vals) > 1 and vals[0] != 0xFC:
                multi[bytes(vals)] = m.group(1)
    return single, multi


def ctrl_render(code, args):
    """EXT_CTRL_CODE -> preproc-compatible {NAME arg} text."""
    if code in (0x01, 0x02, 0x03):
        return '{%s %d}' % (djt.CTRL_NAMES[code], args[0]) if args else '{%s}' % djt.CTRL_NAMES[code]
    if code == 0x04:
        return '{COLOR_HIGHLIGHT_SHADOW %d %d %d}' % tuple(args)
    if code == 0x05:
        return '{PALETTE %d}' % args[0]
    if code == 0x06:
        return '{FONT %d}' % args[0]
    if code == 0x08:
        return '{PAUSE %d}' % args[0]
    if code in (0x0B, 0x10):
        sid = args[0] | (args[1] << 8)
        name = djt.build_sound_map().get(sid)
        return '{%s %s}' % (djt.CTRL_NAMES[code], name) if name else '{%s 0x%04X}' % (djt.CTRL_NAMES[code], sid)
    if code == 0x0C:
        return '{ESCAPE 0x%02X}' % args[0]
    if code in (0x0D, 0x0E):
        return '{%s %d}' % (djt.CTRL_NAMES[code], args[0])
    if code == 0x13:
        return '{CLEAR_TO %d}' % args[0]
    if code == 0x14:
        return '{MIN_LETTER_SPACING %d}' % args[0]
    name = djt.CTRL_NAMES.get(code)
    return '{%s}' % name if name else '{CTRL_%02X}' % code


import decode_jp_text as djt


SINGLE, MULTI = build_text_maps()
SAFE_MULTI = {seq: n for seq, n in MULTI.items() if seq[0] in (0xFD, 0xF9, 0xF8, 0xF7)}


def decode_text(data):
    out = []
    i = 0
    n = len(data)
    while i < n:
        b = data[i]
        if b == 0xFC:
            if i + 1 < n:
                code = data[i + 1]
                nargs = djt.CTRL_ARGS.get(code, 0)
                args = data[i + 2:i + 2 + nargs]
                if len(args) == nargs:
                    out.append(ctrl_render(code, args))
                else:
                    out.append('[FC]')
                i += 2 + nargs
            else:
                out.append('[FC]')
                i += 1
            continue
        if b == 0xFF:
            out.append('$')
            i += 1
            continue
        if b == 0xFE:
            out.append('\\n')
            i += 1
            continue
        if b == 0xFA:
            out.append('\\l')
            i += 1
            continue
        if b == 0xFB:
            out.append('\\p')
            i += 1
            continue
        matched = False
        for ln in (3, 2):
            seq = bytes(data[i:i + ln])
            if len(seq) == ln and seq in SAFE_MULTI:
                out.append('{%s}' % SAFE_MULTI[seq])
                i += ln
                matched = True
                break
        if matched:
            continue
        if b in SINGLE:
            out.append(SINGLE[b])
            i += 1
            continue
        out.append('[%02X]' % b)
        i += 1
    return ''.join(out)


def map_entries():
    """Return sorted [(table_addr, map_name, gi, mi, entries, events)]. """
    out = []
    for entry in MAP_HEADERS:
        gi, mi, h, layout, events, ms, wild, name_hex = entry
        mname = MAP_NAMES.get((gi, mi))
        if mname is None:
            continue
        ms = toi(ms)
        if ms == 0:
            continue
        tables = MAP_TABLES.get(hex(ms)) or MAP_TABLES.get('%x' % ms)
        if not tables:
            continue
        entries = [(toi(t), toi(p)) for t, p in tables]
        out.append((ms, mname, gi, mi, entries, toi(events)))
    out.sort(key=lambda x: x[0])
    return out


def map_events_scripts(events_addr):
    """Script pointers from a MapEvents structure (obj/coord/bg)."""
    rom = sp.ROM
    obj_count = rom[events_addr - 0x08000000]
    coord_count = rom[events_addr - 0x08000000 + 2]
    bg_count = rom[events_addr - 0x08000000 + 3]
    objs = sp.rd32(events_addr + 4)
    coords = sp.rd32(events_addr + 12)
    bgs = sp.rd32(events_addr + 16)
    scripts = []
    for i in range(obj_count):
        s = sp.rd32(objs + i * 0x18 + 0x10)
        if s and s != 0xFFFFFFFF:
            scripts.append(('obj%d' % i, s))
    for i in range(coord_count):
        s = sp.rd32(coords + i * 0x10 + 0xC)
        if s and s != 0xFFFFFFFF:
            scripts.append(('coord%d' % i, s))
    for i in range(bg_count):
        kind = rom[bgs + i * 0xC - 0x08000000 + 0x5]
        s = sp.rd32(bgs + i * 0xC + 0x8)
        if kind <= 4 and s and s != 0xFFFFFFFF:
            scripts.append(('bg%d' % i, s))
    return scripts


def parse_frame_table(addr):
    """tag 2/4 table: (u16 var, u16 compare, .4byte script) until var==0."""
    items = []
    pos = addr
    while True:
        var = sp.rd16(pos)
        if var == 0:
            break
        cmp = sp.rd16(pos + 2)
        script = sp.rd32(pos + 4)
        items.append((var, cmp, script))
        pos += 8
    return items


def collect_map_scripts(map_addr, map_name, extra_addrs=None, events_addr=None,
                        region_end=None):
    """Parse all scripts reachable from the map-script table."""
    extra_addrs = extra_addrs or []
    tables = MAP_TABLES.get(hex(map_addr)) or MAP_TABLES.get('%x' % map_addr)
    scripts = {}   # addr -> script instr list
    text_ptrs = set()
    queue = []
    for tag, ptr in tables:
        t, p = toi(tag), toi(ptr)
        if t in (2, 4):
            for var, cmp, sptr in parse_frame_table(p):
                if sptr not in scripts and \
                        (region_end is None or map_addr <= sptr < region_end):
                    queue.append(sptr)
        else:
            if p not in scripts and (region_end is None or map_addr <= p < region_end):
                queue.append(p)
    for a in extra_addrs:
        if a not in scripts and (region_end is None or map_addr <= a < region_end):
            queue.append(a)
    if events_addr:
        for name, s in map_events_scripts(events_addr):
            if s not in scripts and (region_end is None or map_addr <= s < region_end):
                queue.append(s)
    while queue:
        addr = queue.pop()
        script = sp.parse_script(addr)
        if script is None:
            continue
        scripts[addr] = script
        for off, name, args, refs in script:
            if name in ('loadword', 'message') and args:
                idx = 1 if name == 'loadword' else 0
                if len(args) > idx and 0x08000000 <= args[idx] < 0x0A000000:
                    text_ptrs.add(args[idx])
            elif name == 'loadword' and len(args) == 2 and args[0] == 0:
                if 0x08000000 <= args[1] < 0x0A000000:
                    text_ptrs.add(args[1])
            for r in refs:
                if r not in scripts and r not in queue and \
                        (region_end is None or map_addr <= r < region_end):
                    queue.append(r)
    # de-overlap: truncate scripts that extend into another script entry
    entries = set(scripts)
    for addr in sorted(scripts):
        inner = [e for e in entries if addr < e]
        if not inner:
            continue
        cut = min(inner)
        new_script = []
        pos = addr
        for instr in scripts[addr]:
            d = sp.decode_instruction(pos)
            if d is None or pos >= cut:
                break
            new_script.append(instr)
            pos += d[0]
        if len(new_script) != len(scripts[addr]):
            scripts[addr] = new_script
    return scripts, text_ptrs


def script_ranges(scripts):
    """Covered byte ranges of script instructions."""
    ranges = []
    for addr, script in scripts.items():
        pos = addr
        for off, name, args, refs in script:
            # size unknown here; recompute via decode at pos
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size = r[0]
            ranges.append((pos, pos + size))
            pos += size
    return ranges


def map_table_bytes(ms, entries):
    """Mark bytes of the map-script table (5-byte entries until tag 0)."""
    covered = set()
    pos = ms
    while True:
        tag = sp.rd8(pos)
        if tag == 0:
            covered.add(pos)
            break
        covered.update(range(pos, pos + 5))
        pos += 5
    return covered


def frame_table_bytes(addr):
    covered = set()
    pos = addr
    while True:
        var = sp.rd16(pos)
        if var == 0:
            covered.update(range(pos, pos + 2))
            break
        covered.update(range(pos, pos + 8))
        pos += 8
    return covered


def text_range(tp, region_end):
    end = tp
    while end < region_end and ROM[end - 0x08000000] != 0xFF:
        end += 1
    if end < region_end:
        end += 1
    return tp, end


def emit_map(ms, mname, gi, mi, entries, region_end, global_text_ptrs,
             text_label_map, region_labels=None, std_addrs=None, events_addr=None):
    std_addrs = std_addrs or set()
    extra = [a for a in std_addrs if ms <= a < region_end]
    scripts, text_ptrs = collect_map_scripts(ms, mname, extra, events_addr, region_end)
    region_labels = region_labels or {}
    label_map = {}
    for addr in sorted(scripts):
        if addr in std_addrs:
            label_map[addr] = region_labels.get(addr, 'gUnknown_%08X' % (addr & 0xFFFFFF))
        else:
            label_map[addr] = '%s_EventScript_%08X' % (mname, addr & 0xFFFFFF)
    # byte coverage
    covered = collections.defaultdict(str)
    for a in range(ms, region_end):
        covered[a] = 'raw'
    for addr, script in scripts.items():
        pos = addr
        for off, name, args, refs in script:
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size = r[0]
            for b in range(pos, pos + size):
                covered[b] = 'script'
            pos += size
    table_addrs = {ms: 'map'}
    for tag, ptr in entries:
        t, p = toi(tag), toi(ptr)
        if t in (2, 4):
            table_addrs[p] = 'frame'
    for ta, kind in table_addrs.items():
        if kind == 'map':
            for b in map_table_bytes(ms, entries):
                covered[b] = 'table'
        else:
            if ms <= ta < region_end:
                for b in frame_table_bytes(ta):
                    covered[b] = 'table'
    text_ranges = []
    for tp in sorted(global_text_ptrs):
        if not (ms <= tp < region_end):
            continue
        a, b = text_range(tp, region_end)
        text_ranges.append((a, b))
        for x in range(a, b):
            covered[x] = 'text'
    # build segments in address order
    segs = []
    segs.append((ms, 'map_table', 0))
    for ta in sorted(table_addrs):
        if table_addrs[ta] == 'frame' and ms <= ta < region_end:
            segs.append((ta, 'frame_table', 0))
    for addr in scripts:
        pos = addr
        size = 0
        for off, name, args, refs in scripts[addr]:
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size += r[0]
            pos += r[0]
        segs.append((addr, 'script', addr))
    for tp, end in text_ranges:
        segs.append((tp, 'text', tp))
    # raw gaps
    raw_start = None
    for a in range(ms, region_end):
        if covered[a] == 'raw' and raw_start is None:
            raw_start = a
        elif covered[a] != 'raw' and raw_start is not None:
            segs.append((raw_start, 'raw', raw_start))
            raw_start = None
    if raw_start is not None:
        segs.append((raw_start, 'raw', raw_start))
    segs.sort(key=lambda x: x[0])
    # emit in address order
    lines = ['@ %s scripts (JP map g%d m%d @ 0x%08X)' % (mname, gi, mi, ms), '']
    nraw = 0
    for start, kind, payload in segs:
        if kind == 'map_table':
            old = region_labels.get(ms)
            if old:
                lines.append('%s:: @ 0x%08X' % (old, ms))
            lines.append('%s_MapScripts::' % mname)
            for tag, ptr in entries:
                t, p = toi(tag), toi(ptr)
                if t in (2, 4):
                    if ms <= p < region_end:
                        tbl = '%s_MapScriptTable_%08X' % (mname, p & 0xFFFFFF)
                        lines.append('\tmap_script %s, %s' % (MAP_SCRIPT_NAMES.get(t, str(t)), tbl))
                    else:
                        lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
                elif p in label_map:
                    lines.append('\tmap_script %s, %s' % (MAP_SCRIPT_NAMES.get(t, str(t)), label_map[p]))
                else:
                    lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
            lines.append('\t.byte 0')
            lines.append('')
        elif kind == 'frame_table':
            lines.append('%s_MapScriptTable_%08X::' % (mname, start & 0xFFFFFF))
            for var, cmp, sptr in parse_frame_table(start):
                if sptr in label_map:
                    lines.append('\tmap_script_2 0x%X, 0x%X, %s' % (var, cmp, label_map[sptr]))
                else:
                    lines.append('\tmap_script_2 0x%X, 0x%X, 0x%08X' % (var, cmp, sptr))
            lines.append('\t.2byte 0')
            lines.append('')
        elif kind == 'script':
            addr = payload
            old = region_labels.get(addr) if addr not in std_addrs else None
            if old:
                lines.append('%s:: @ 0x%08X' % (old, addr))
            lines.append('%s::' % label_map[addr])
            for name, argstr in sp.decode_script_lines(scripts[addr], label_map, text_label_map):
                if argstr:
                    lines.append('\t%s %s' % (name, argstr))
                else:
                    lines.append('\t%s' % name)
            lines.append('')
        elif kind == 'text':
            tp = payload
            end = text_ranges[[x[0] for x in text_ranges].index(tp)][1]
            raw = ROM[tp - 0x08000000:end - 0x08000000]
            dec = decode_text(raw)
            if '[' in dec:
                lines.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                    tp - 0x08000000, end - tp))
                nraw += 1
                continue
            label = 'gJPText_%08X' % (tp & 0xFFFFFF)
            lines.append('\t.globl %s' % label)
            lines.append('%s: @ 0x%08X' % (label, tp))
            old = region_labels.get(tp)
            if old and old != label:
                lines.append('\t.globl %s' % old)
                lines.append('%s:' % old)
            parts = [p for p in re.split(r'(?<=\\l|\\p|\\n)', dec) if p]
            for k, part in enumerate(parts):
                if k == len(parts) - 1 and dec.endswith('$'):
                    lines.append('\t.string "%s$"' % part.rstrip('$'))
                else:
                    lines.append('\t.string "%s"' % part)
            lines.append('')
        elif kind == 'raw':
            a = start
            b = region_end
            for s2, k2, p2 in segs:
                if k2 != 'raw' and s2 > a:
                    b = min(b, s2)
            old = region_labels.get(a)
            if old:
                lines.append('%s:: @ 0x%08X' % (old, a))
            lines.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                a - 0x08000000, b - a))
            nraw += 1
    return '\n'.join(lines) + '\n', len(text_ranges), nraw


def collect_all_text_ptrs(entries):
    """Global set of text pointers reachable from map scripts."""
    all_ptrs = set()
    for ms, mname, gi, mi, ents, events_addr in entries:
        _, tptrs = collect_map_scripts(ms, mname)
        all_ptrs |= tptrs
    return all_ptrs


def event_script_labels():
    """addr -> label name from data/scripts/*.inc file names + event_scripts.s."""
    labels = {}
    for p in (ROOT / 'data' / 'scripts').glob('gUnknown_*.inc'):
        labels[int(p.stem[len('gUnknown_'):], 16)] = p.stem
    for line in (ROOT / 'data' / 'event_scripts.s').read_text(
            encoding='utf-8').splitlines():
        m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)', line)
        if m:
            labels.setdefault(int(m.group(2), 16), m.group(1))
    return labels


def main():
    entries = map_entries()
    print('maps:', len(entries))
    do_write = '--write' in sys.argv
    args = [a for a in sys.argv[1:] if a != '--write']
    m = args[0] if args else None
    global_text_ptrs = collect_all_text_ptrs(entries)
    print('global text ptrs:', len(global_text_ptrs))
    text_label_map = {p: 'gJPText_%08X' % (p & 0xFFFFFF) for p in global_text_ptrs}
    all_labels = event_script_labels()
    map_starts = {e[0] for e in entries}
    nonmap = sorted(a for a in all_labels if a not in map_starts)
    last_map_end = next((a for a in nonmap if a > entries[-1][0]), 0x0828F000)
    print('last map region end:', hex(last_map_end))
    total_raw = 0
    total_text = 0
    for i, (ms, mname, gi, mi, ents, events_addr) in enumerate(entries):
        if m and mname != m:
            continue
        if i > 0 and ms == entries[i - 1][0]:
            if not m:
                continue  # shared map-script table; emitted with the first map
        j = i + 1
        while j < len(entries) and entries[j][0] == ms:
            j += 1
        region_end = entries[j][0] if j < len(entries) else last_map_end
        region_labels = {a: n for a, n in all_labels.items() if ms <= a < region_end}
        if m and mname == m:
            print('region_labels for', mname, ':', len(region_labels),
                  list(region_labels.items())[:8])
        out, ntext, nraw = emit_map(ms, mname, gi, mi, ents, region_end,
                                    global_text_ptrs, text_label_map,
                                    region_labels, set(), events_addr)
        total_raw += nraw
        total_text += ntext
        if m:
            print('=== %s @ %08X region 0x%X texts=%d rawinc=%d ===' % (
                mname, ms, region_end - ms, ntext, nraw))
            print(out[:2500])
            return
        if do_write:
            outdir = ROOT / 'data' / 'maps' / mname
            outdir.mkdir(parents=True, exist_ok=True)
            (outdir / 'scripts.inc').write_text(out, encoding='utf-8')
    print('total raw incbin lines:', total_raw, 'text ranges:', total_text)


if __name__ == '__main__':
    main()
