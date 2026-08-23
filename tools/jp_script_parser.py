#!/usr/bin/env python3
"""Strict JP event-script parser.

Starting from the map-script tables and the gStdScripts table, decode the
script byte stream instruction by instruction, follow call/goto targets
inside the script region, and record text pointers (msgbox etc.).

Usage:
    python3 tools/jp_script_parser.py graph        # build the script graph
    python3 tools/jp_script_parser.py dump <addr>  # dump one script
"""

import json
import re
import sys
from pathlib import Path

from jp_map_script_metadata import build_metadata

ROOT = Path(__file__).resolve().parents[1]
CMD_TABLE = ROOT / 'data' / 'script_cmd_table.inc'
EVENT_INC = ROOT / 'asm' / 'macros' / 'event.inc'
SPECIALS_INC = ROOT / 'data' / 'specials.inc'
ROM = (ROOT / 'baserom_jp.gba').read_bytes()

REGION = (0x081DABAC, 0x0828F000)
GDATA_START = 0x08290000


def build_opcode_table():
    entries = []
    for line in CMD_TABLE.read_text(encoding='utf-8').splitlines():
        m = re.match(r'\s*script_cmd_table_entry\s+(\S+)\s+(\S+)\s*@', line)
        if m:
            entries.append((m.group(1), m.group(2)))
    return {const: i for i, (const, _) in enumerate(entries)}


# --- argument-format inference (same approach as decompile_scripts.py) ---
HELPER_SPECS = {
    'stringvar': [('arg', 1)],
    'map': [('arg_hi',), ('arg_lo',)],
    'formatwarp': [('arg_hi',), ('arg_lo',), ('arg', 1), ('arg', 2), ('arg', 2)],
}


def expand_helper(name, call_args):
    spec = HELPER_SPECS.get(name)
    if spec is None:
        return None
    out = []
    ai = 0
    for item in spec:
        if item[0] == 'arg':
            out.append(('arg', item[1], call_args[ai]))
            ai += 1
        elif item[0] == 'arg_hi':
            out.append(('arg_hi', call_args[ai]))
        elif item[0] == 'arg_lo':
            out.append(('arg_lo', call_args[ai]))
            ai += 1
    return out


def emit_spec(line):
    m = re.match(r'\.(byte|2byte|4byte)\s+(.+)$', line)
    if m:
        size = {'byte': 1, '2byte': 2, '4byte': 4}[m.group(1)]
        val = m.group(2).split('@')[0].strip()
        if val.startswith('\\'):
            return [('arg', size, val.lstrip('\\'))]
        if val.startswith('SCR_OP_'):
            return [('op', val)]
        if val.startswith('SPECIAL_\\'):
            return [('special',)]
        if val == 'WARP_ID_NONE':
            return [('lit', size, 0)]
        try:
            return [('lit', size, int(val, 0))]
        except ValueError:
            return None
    m = re.match(r'(\w+)\s+(.+)$', line)
    if m and m.group(1) in HELPER_SPECS:
        args = [a.strip().lstrip('\\') for a in m.group(2).split(',')]
        return expand_helper(m.group(1), args)
    return None


def parse_macro_paths(body):
    paths = [[]]
    stack = []
    for raw in body:
        line = raw.strip()
        if not line or line.startswith('@'):
            continue
        if line.startswith('.if'):
            stack.append(([p[:] for p in paths], [p[:] for p in paths], None))
            paths = stack[-1][1]
        elif line.startswith('.elseif') or line == '.else':
            if not stack:
                return None
            pre, ifp, _ = stack[-1]
            stack[-1] = (pre, ifp, [p[:] for p in pre])
            paths = stack[-1][2]
        elif line == '.endif':
            if not stack:
                return None
            pre, ifp, elsep = stack.pop()
            merged = ifp + (elsep if elsep is not None else [p[:] for p in pre])
            paths = merged
        elif line.startswith(('.warning', '.set', '.global', '.align',
                              '.string', '.asciz')):
            continue
        else:
            em = emit_spec(line)
            if em is None:
                return None
            for p in paths:
                p.extend(em)
    if stack:
        return None
    return paths


JP_CONST_ALIASES = {
    'SCR_OP_APPLYMOVEMENTAT': ('SCR_OP_50', 'applymovement_at'),
    'SCR_OP_WAITMOVEMENTAT': ('SCR_OP_52', 'waitmovement_at'),
    'SCR_OP_REMOVEOBJECTAT': ('SCR_OP_54', 'removeobject_at'),
    'SCR_OP_ADDOBJECTAT': ('SCR_OP_56', 'addobject_at'),
}


def build_macro_formats(opcode_by_name):
    formats = {}
    lines = EVENT_INC.read_text(encoding='utf-8').splitlines()
    i = 0
    while i < len(lines):
        m = re.match(r'\s*\.macro\s+(\w+)', lines[i])
        if not m:
            i += 1
            continue
        name = m.group(1)
        body = []
        i += 1
        while i < len(lines) and not re.match(r'\s*\.endm', lines[i]):
            body.append(lines[i])
            i += 1
        i += 1
        if name == 'trainerbattle':
            continue
        if name == 'special':
            paths = [[('op', 'SCR_OP_SPECIAL'), ('special',)]]
        elif name == 'specialvar':
            paths = [[('op', 'SCR_OP_SPECIALVAR'), ('arg', 2, 'output'),
                      ('special',)]]
        else:
            paths = parse_macro_paths(body)
        if not paths:
            continue
        for path in paths:
            if not path or path[0][0] != 'op':
                continue
            alias = JP_CONST_ALIASES.get(path[0][1])
            const = alias[0] if alias else path[0][1]
            opcode = opcode_by_name.get(const)
            if opcode is None:
                continue
            format_name = alias[1] if alias else name
            argfmt = []
            ok = True
            for em in path[1:]:
                if em[0] == 'arg':
                    argfmt.append((em[1], 'arg', em[2]))
                elif em[0] == 'lit':
                    argfmt.append((em[1], 'lit', em[2]))
                elif em[0] == 'arg_hi':
                    argfmt.append((1, 'arg_hi', em[1]))
                elif em[0] == 'arg_lo':
                    argfmt.append((1, 'arg_lo', em[1]))
                elif em[0] == 'special':
                    argfmt.append((2, 'special', None))
                else:
                    ok = False
                    break
            if not ok or opcode in formats:
                continue
            formats[opcode] = (format_name, argfmt)
    return formats


def build_specials_map():
    specials = {}
    idx = 0
    for line in SPECIALS_INC.read_text(encoding='utf-8').splitlines():
        m = re.match(r'\s*def_special\s+(\w+)(?:\s*,\s*(?:waitstate=)?(\d+))?', line)
        if m:
            specials[idx] = (m.group(1), int(m.group(2) or 0))
            idx += 1
    return specials


SPECIALS = build_specials_map()
OPCODE_BY_NAME = build_opcode_table()
FORMATS = build_macro_formats(OPCODE_BY_NAME)


def rd8(addr):
    return ROM[addr - 0x08000000]


def rd16(addr):
    return int.from_bytes(ROM[addr - 0x08000000:addr - 0x08000000 + 2], 'little')


def rd32(addr):
    return int.from_bytes(ROM[addr - 0x08000000:addr - 0x08000000 + 4], 'little')


def in_region(addr):
    return REGION[0] <= addr < REGION[1]


TERMINATORS = {0x02, 0x03, 0x0C, 0x0D}
# opcodes whose 4-byte arg is a script pointer (call/goto)
PTR_OPS = {0x04, 0x05, 0x06, 0x07}  # call, goto, goto_if, call_if


def decode_instruction(addr):
    """Return (size, name, args, refs) or None if undecodable."""
    op = rd8(addr)
    fmt = FORMATS.get(op)
    if fmt is None:
        return None
    name, argfmt = fmt
    base = 1 + sum(sz for sz, _, _ in argfmt)
    refs = []
    pos = addr + 1
    vals = []
    extra = 0
    for sz, kind, an in argfmt:
        if kind == 'lit':
            v = int.from_bytes(ROM[pos - 0x08000000:pos - 0x08000000 + sz], 'little')
            if v != an:
                return None
            pos += sz
        elif kind == 'arg':
            v = int.from_bytes(ROM[pos - 0x08000000:pos - 0x08000000 + sz], 'little')
            vals.append(v)
            if op in PTR_OPS and sz == 4:
                refs.append(v)
            pos += sz
        elif kind == 'arg_hi':
            v = (ROM[pos - 0x08000000] << 8) | ROM[pos + 1 - 0x08000000]
            vals.append(v)
            pos += 1  # high byte only; the paired low byte is consumed by arg_lo
        elif kind == 'arg_lo':
            pos += 1
        elif kind == 'special':
            idx = int.from_bytes(ROM[pos - 0x08000000:pos - 0x08000000 + 2], 'little')
            entry = SPECIALS.get(idx)
            if entry is None:
                return None
            vals.append(entry[0])
            if entry[1]:
                extra = 1  # waitstate byte follows the special index
            pos += 2
    # specials with SPECIAL_WAITSTATE have an implicit waitstate byte
    if extra and ROM[pos - 0x08000000] == 0x27:
        pos += 1
    return (pos - addr, name, vals, refs)


def parse_script(addr, maxlen=0x4000):
    """Decode one script starting at addr. Returns list of instr tuples:
    (offset, name, args, refs) or None on undecodable data."""
    out = []
    pos = addr
    end = addr + maxlen
    while pos < end:
        r = decode_instruction(pos)
        if r is None:
            return None
        size, name, args, refs = r
        out.append((pos - addr, name, args, refs))
        op = rd8(pos)
        pos += size
        if op in TERMINATORS:
            break
        if op in (0x05, 0x08):  # goto / gotostd: unconditional jump
            nxt = rd8(pos)
            if nxt in TERMINATORS:
                r2 = decode_instruction(pos)
                if r2 is not None:
                    out.append((pos - addr, r2[1], r2[2], r2[3]))
                    pos += r2[0]
            break
        if pos >= end:
            break
    return out


def decode_script_lines(script, label_map, text_label_map=None):
    """Turn a parsed script into assembly macro lines. 4-byte pointer args
    that match a known script label are rendered as that label."""
    text_label_map = text_label_map or {}
    out = []
    for off, name, args, refs in script:
        parts = []
        for i, a in enumerate(args):
            if name in ('loadword', 'message') and i == (1 if name == 'loadword' else 0) \
                    and isinstance(a, int) and a in text_label_map:
                parts.append(text_label_map[a])
            elif isinstance(a, int) and a in label_map:
                parts.append(label_map[a])
            elif isinstance(a, int) and a >= 0x08000000:
                parts.append('0x%08X' % a)
            else:
                parts.append('0x%X' % a if isinstance(a, int) else str(a))
        out.append((name, ', '.join(parts)))
    return out


def parse_map_tables(path):
    """Return list of (table_addr, [(tag, ptr), ...])."""
    tables = json.loads(Path(path).read_text())
    out = []
    for ts, entries in tables.items():
        def toi(x):
            return int(x, 16) if isinstance(x, str) else int(x)
        out.append((toi(ts), [(toi(t), toi(p)) for t, p in entries]))
    return out


def std_entries():
    """gStdScripts table at 0x81DB7BC, 11 entries."""
    base = 0x81DB7BC
    out = []
    for i in range(11):
        p = rd32(base + i * 4)
        out.append((base, [(0, p)]))
    return out


def build_graph(map_tables=None):
    """Discover scripts reachable from ROM-derived map tables + std table."""
    scripts = {}       # addr -> list of instr
    entry_sources = {}  # addr -> source description
    queue = []
    seen = set()

    if map_tables is None:
        _, map_tables = build_metadata()
    for tb, entries in map_tables.items():
        for tag, ptr in entries:
            if in_region(ptr) and ptr not in seen:
                seen.add(ptr)
                queue.append((ptr, 'map'))
    for tb, entries in std_entries():
        for tag, ptr in entries:
            if in_region(ptr) and ptr not in seen:
                seen.add(ptr)
                queue.append((ptr, 'std'))

    while queue:
        addr, src = queue.pop()
        script = parse_script(addr)
        if script is None:
            continue
        scripts[addr] = script
        entry_sources[addr] = src
        for off, name, args, refs in script:
            for r in refs:
                if in_region(r) and r not in seen:
                    seen.add(r)
                    queue.append((r, 'call'))
    return scripts, entry_sources


def text_ptrs(scripts):
    """Collect candidate text pointers: loadword 0, X where X is a ROM addr."""
    ptrs = set()
    for addr, script in scripts.items():
        for off, name, args, refs in script:
            if name == 'loadword' and len(args) == 2 and args[0] == 0:
                if 0x08000000 <= args[1] < 0x0A000000:
                    ptrs.add(args[1])
    return ptrs


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    cmd = sys.argv[1]
    scripts, sources = build_graph()
    print('scripts:', len(scripts))
    print('sources: map=%d std=%d call=%d' % (
        sum(1 for s in sources.values() if s == 'map'),
        sum(1 for s in sources.values() if s == 'std'),
        sum(1 for s in sources.values() if s == 'call')))
    if cmd == 'graph':
        tptrs = text_ptrs(scripts)
        print('text pointers:', len(tptrs))
        if tptrs:
            print('range:', hex(min(tptrs)), hex(max(tptrs)))
        output = ROOT / 'build' / 'jp_map_script_metadata' / 'jp_script_graph.json'
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(
            json.dumps({hex(a): [[o, n, a2] for o, n, a2, _ in s]
                        for a, s in scripts.items()}, indent=2) + '\n',
            encoding='utf-8',
        )
        print('saved', output)
    elif cmd == 'dump':
        addr = int(sys.argv[2], 16)
        script = parse_script(addr)
        if script is None:
            print('undecodable')
        else:
            for off, name, args, refs in script:
                print('%04X: %s %s' % (off, name, ', '.join(str(a) for a in args)))


if __name__ == '__main__':
    main()
