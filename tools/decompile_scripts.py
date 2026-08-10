#!/usr/bin/env python3
"""Decode JP event-script bytes into readable .inc text.

The command table comes from data/script_cmd_table.inc (JP opcode order);
argument formats are inferred from asm/macros/event.inc macro bodies.
Commands whose macros are simple (one opcode byte plus fixed-size args)
decode to named invocations; anything else is emitted as raw .byte.

Usage:
    python3 tools/decompile_scripts.py dump <chunk-label>
    python3 tools/decompile_scripts.py check <chunk-label>
    python3 tools/decompile_scripts.py convert <chunk-label>
    python3 tools/decompile_scripts.py scan [min-size]
    python3 tools/decompile_scripts.py convert-all [readability-threshold]
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EVENT_S = ROOT / "data" / "event_scripts.s"
BIN = ROOT / "build" / "data" / "event_scripts.bin"
CMD_TABLE = ROOT / "data" / "script_cmd_table.inc"
EVENT_INC = ROOT / "asm" / "macros" / "event.inc"
SCRIPTS_DIR = ROOT / "data" / "scripts"

LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
INCINBIN_RE = re.compile(
    r'^\s*\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)\s*$'
)


def build_opcode_table():
    entries = []
    for line in CMD_TABLE.read_text(encoding="utf-8").splitlines():
        m = re.match(r"\s*script_cmd_table_entry\s+(\S+)\s+(\S+)\s*@", line)
        if m:
            entries.append((m.group(1), m.group(2)))
    return {i: (const, handler) for i, (const, handler) in enumerate(entries)}


# Helper macros used inside command macro bodies.  Emission kinds:
#   ("arg", size)          one \arg, little-endian
#   ("arg_hi"/"arg_lo")    high/low byte of one \arg (the map macro)
HELPER_SPECS = {
    "stringvar": [("arg", 1)],
    "map": [("arg_hi",), ("arg_lo",)],
    "formatwarp": [("arg_hi",), ("arg_lo",), ("arg", 1), ("arg", 2), ("arg", 2)],
}


def expand_helper(name, call_args):
    """Expand a helper-macro call into emission tuples."""
    spec = HELPER_SPECS.get(name)
    if spec is None:
        return None
    out = []
    ai = 0
    for item in spec:
        if item[0] == "arg":
            out.append(("arg", item[1], call_args[ai]))
            ai += 1
        elif item[0] == "arg_hi":
            out.append(("arg_hi", call_args[ai]))
        elif item[0] == "arg_lo":
            out.append(("arg_lo", call_args[ai]))
            ai += 1
    return out


def emit_spec(line):
    """Turn one macro-body line into a list of emission tuples, or None."""
    m = re.match(r"\.(byte|2byte|4byte)\s+(.+)$", line)
    if m:
        size = {"byte": 1, "2byte": 2, "4byte": 4}[m.group(1)]
        val = m.group(2).split("@")[0].strip()
        if val.startswith("\\"):
            return [("arg", size, val.lstrip("\\"))]
        if val.startswith("SCR_OP_"):
            return [("op", val)]
        if val.startswith("SPECIAL_\\"):
            return [("special",)]
        if val == "WARP_ID_NONE":
            return [("lit", size, 0)]
        try:
            return [("lit", size, int(val, 0))]
        except ValueError:
            return None
    m = re.match(r"(\w+)\s+(.+)$", line)
    if m and m.group(1) in HELPER_SPECS:
        args = [a.strip().lstrip("\\") for a in m.group(2).split(",")]
        return expand_helper(m.group(1), args)
    return None


def parse_macro_paths(body):
    """Return the emission paths of a macro body (one path per branch).

    Emission tuples: ("op", const), ("arg", size, name), ("lit", size, value),
    ("arg_hi", name), ("arg_lo", name), ("special",).
    Returns None when the body cannot be represented (kept as raw bytes).
    """
    paths = [[]]
    stack = []
    for raw in body:
        line = raw.strip()
        if not line or line.startswith("@"):
            continue
        if line.startswith(".if"):
            stack.append(([p[:] for p in paths], [p[:] for p in paths], None))
            paths = stack[-1][1]
        elif line.startswith(".elseif") or line == ".else":
            if not stack:
                return None
            pre, ifp, _ = stack[-1]
            stack[-1] = (pre, ifp, [p[:] for p in pre])
            paths = stack[-1][2]
        elif line == ".endif":
            if not stack:
                return None
            pre, ifp, elsep = stack.pop()
            merged = ifp + (elsep if elsep is not None else [p[:] for p in pre])
            paths = merged
        elif line.startswith((".warning", ".set", ".global", ".align",
                              ".string", ".asciz")):
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


def build_specials_map():
    """Return {special index: (name, waitstate)} in specials.inc order."""
    specials = {}
    idx = 0
    for line in (ROOT / "data" / "specials.inc").read_text(encoding="utf-8").splitlines():
        m = re.match(r"\s*def_special\s+(\w+)(?:\s*,\s*(?:waitstate=)?(\d+))?", line)
        if m:
            specials[idx] = (m.group(1), int(m.group(2) or 0))
            idx += 1
    return specials


# The US event.inc names some *_at commands with SCR_OP_*AT constants
# (SCR_OP_APPLYMOVEMENTAT etc.), while the JP command table uses raw hex
# const names for those opcodes (SCR_OP_50 etc.).  Decode them under the
# JP macro names so the .inc output assembles against asm/macros/event.inc.
JP_CONST_ALIASES = {
    "SCR_OP_APPLYMOVEMENTAT": ("SCR_OP_50", "applymovement_at"),
    "SCR_OP_WAITMOVEMENTAT": ("SCR_OP_52", "waitmovement_at"),
    "SCR_OP_REMOVEOBJECTAT": ("SCR_OP_54", "removeobject_at"),
    "SCR_OP_ADDOBJECTAT": ("SCR_OP_56", "addobject_at"),
}


def build_macro_formats(opcode_by_name):
    """Return (formats, formats_by_name).

    formats:          opcode -> (name, argfmt)
    formats_by_name:  (name, nargs) -> (opcode, argfmt)
    argfmt entries: (size, kind, arg) with kind in
    arg / lit / arg_hi / arg_lo / special.
    """
    formats = {}
    formats_by_name = {}
    lines = EVENT_INC.read_text(encoding="utf-8").splitlines()
    i = 0
    while i < len(lines):
        m = re.match(r"\s*\.macro\s+(\w+)", lines[i])
        if not m:
            i += 1
            continue
        name = m.group(1)
        body = []
        i += 1
        while i < len(lines) and not re.match(r"\s*\.endm", lines[i]):
            body.append(lines[i])
            i += 1
        i += 1

        if name == "trainerbattle":
            continue  # variable size per battle type; kept as raw for now
        if name == "special":
            paths = [[("op", "SCR_OP_SPECIAL"), ("special",)]]
        elif name == "specialvar":
            paths = [[("op", "SCR_OP_SPECIALVAR"), ("arg", 2, "output"),
                      ("special",)]]
        else:
            paths = parse_macro_paths(body)
        if not paths:
            continue
        for path in paths:
            if not path or path[0][0] != "op":
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
                if em[0] == "arg":
                    argfmt.append((em[1], "arg", em[2]))
                elif em[0] == "lit":
                    argfmt.append((em[1], "lit", em[2]))
                elif em[0] == "arg_hi":
                    argfmt.append((1, "arg_hi", em[1]))
                elif em[0] == "arg_lo":
                    argfmt.append((1, "arg_lo", em[1]))
                elif em[0] == "special":
                    argfmt.append((2, "special", None))
                else:
                    ok = False
                    break
            if not ok or opcode in formats:
                continue
            formats[opcode] = (format_name, argfmt)
            nargs = sum(
                1
                for sz, kind, an in argfmt
                if kind in ("arg", "special") or kind == "arg_hi"
            )
            formats_by_name[(format_name, nargs)] = (opcode, argfmt)
    return formats, formats_by_name


def decode_chunk(raw, formats, specials):
    lines = []
    i = 0
    n = len(raw)
    while i < n:
        op = raw[i]
        fmt = formats.get(op)
        if fmt is None:
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        name, argfmt = fmt
        base = 1 + sum(sz for sz, _, _ in argfmt)
        if i + base > n:
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        pos = i + 1
        ok = True
        for sz, kind, an in argfmt:
            if kind == "lit" and int.from_bytes(raw[pos : pos + sz], "little") != an:
                ok = False
                break
            pos += sz
        if not ok:
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        args = []
        pos = i + 1
        extra = 0
        skip_lo = False
        for sz, kind, an in argfmt:
            if skip_lo:
                skip_lo = False
                continue
            if kind == "arg":
                args.append(f"0x{int.from_bytes(raw[pos : pos + sz], 'little'):X}")
            elif kind == "lit":
                pass
            elif kind == "arg_hi":
                args.append(f"0x{(raw[pos] << 8) | raw[pos + 1]:X}")
                pos += 1  # consume the paired low byte now
                skip_lo = True
            elif kind == "special":
                idx = int.from_bytes(raw[pos : pos + 2], "little")
                entry = specials.get(idx)
                if entry is None:
                    ok = False
                    break
                sp_name, sp_wait = entry
                args.append(sp_name)
                if sp_wait:
                    extra = 1
            pos += sz
        if not ok:
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        if extra and (i + base + 1 > n or raw[i + base] != 0x27):
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        lines.append(f"\t{name} {', '.join(args)}")
        i += base + extra
    return "\n".join(lines) + "\n"


def encode_lines(text, formats_by_name, specials):
    """Re-encode decoded lines back to bytes (pure-Python round-trip)."""
    out = bytearray()
    for line in text.splitlines():
        s = line.strip()
        m = re.match(r"\.byte\s+0x([0-9A-Fa-f]{2})", s)
        if m:
            out.append(int(m.group(1), 16))
            continue
        m = re.match(r"(\w+)\s*(.*)$", s)
        if not m:
            raise ValueError(f"cannot re-encode line: {line!r}")
        name = m.group(1)
        rest = m.group(2).strip()
        args = []
        if rest:
            for tok in re.split(r"\s*,\s*", rest):
                tok = tok.strip()
                args.append(int(tok, 16) if tok.startswith("0x") else tok)
        key = (name, len(args))
        if key not in formats_by_name:
            raise ValueError(f"unknown command {name} with {len(args)} args")
        opcode, argfmt = formats_by_name[key]
        out.append(opcode)
        ai = 0
        pending_hi = None
        for sz, kind, an in argfmt:
            if kind == "arg":
                v = args[ai]
                ai += 1
                out.extend(v.to_bytes(sz, "little"))
            elif kind == "lit":
                v = an & ((1 << (8 * sz)) - 1)
                out.extend(v.to_bytes(sz, "little"))
            elif kind == "arg_hi":
                pending_hi = args[ai]
                out.append((pending_hi >> 8) & 0xFF)
            elif kind == "arg_lo":
                out.append(pending_hi & 0xFF)
                ai += 1
            elif kind == "special":
                v = args[ai]
                ai += 1
                found = None
                for ix, (nm, ws) in specials.items():
                    if nm == v:
                        found = (ix, ws)
                        # Keep the last match: the JP ROM's special table has
                        # a duplicate ShowMapNamePopup entry (indices 406/407)
                        # and scripts reference the later index.
                if found is None:
                    raise ValueError(f"unknown special {v}")
                idx, ws = found
                out.extend(idx.to_bytes(2, "little"))
                if ws:
                    out.append(0x27)
    return bytes(out)


def parse_chunks():
    chunks = []
    label = None
    for line in EVENT_S.read_text(encoding="utf-8").splitlines():
        lm = LABEL_RE.match(line)
        if lm:
            label = lm.group(1)
            addr = int(lm.group(2), 16)
            continue
        m = INCINBIN_RE.match(line)
        if m:
            if label is None:
                continue
            rel = int(m.group(1), 16)
            size = int(m.group(2), 16)
            chunks.append((label, addr, rel, size))
            label = None
    return chunks


REGION_BASE = 0x081DABAC  # first byte of build/data/event_scripts.bin


def parse_all_chunks():
    """Return (label, addr, rel, size) for every labelled chunk in the
    script region, deriving rel/size from consecutive label addresses.
    Already-converted (.include) chunks are included this way; chunks
    whose data lies beyond the bin are skipped."""
    bin_size = BIN.stat().st_size if BIN.is_file() else 0
    items = []
    for line in EVENT_S.read_text(encoding="utf-8").splitlines():
        lm = LABEL_RE.match(line)
        if lm:
            items.append((lm.group(1), int(lm.group(2), 16)))
    items.sort(key=lambda t: t[1])
    chunks = []
    for i, (label, addr) in enumerate(items):
        size = items[i + 1][1] - addr if i + 1 < len(items) else 0
        rel = addr - REGION_BASE
        if rel < 0 or rel + size > bin_size:
            continue
        chunks.append((label, addr, rel, size))
    return chunks


def readability(text):
    lines = text.splitlines()
    if not lines:
        return 0.0
    macro = sum(1 for l in lines if not l.strip().startswith(".byte"))
    return macro / len(lines)


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    if not BIN.is_file():
        sys.exit(f"missing {BIN}; run make first")
    cmd, target = sys.argv[1], sys.argv[2]
    data = BIN.read_bytes()
    opcode_table = build_opcode_table()
    by_name = {const: op for op, (const, _) in opcode_table.items()}
    formats, formats_by_name = build_macro_formats(by_name)
    specials = build_specials_map()
    print(f"opcodes: {len(opcode_table)}, named formats: {len(formats)}, "
          f"specials: {len(specials)}")

    for label, addr, rel, size in parse_all_chunks():
        if label != target:
            continue
        raw = data[rel : rel + size]
        text = decode_chunk(raw, formats, specials)
        if cmd == "dump":
            print(text)
        elif cmd == "check":
            ok = encode_lines(text, formats_by_name, specials) == raw
            print(f"{label}: round-trip {'OK' if ok else 'FAIL'} ({size} bytes)")
        elif cmd == "convert":
            if encode_lines(text, formats_by_name, specials) != raw:
                sys.exit(f"{label}: round-trip FAIL, refusing")
            SCRIPTS_DIR.mkdir(exist_ok=True)
            out_path = SCRIPTS_DIR / f"{label}.inc"
            out_path.write_text(text, encoding="utf-8")
            print(f"wrote {out_path}")
        return

    if cmd == "scan":
        min_size = int(sys.argv[2]) if len(sys.argv) > 2 else 0
        rows = []
        for label, addr, rel, size in parse_all_chunks():
            if size < min_size:
                continue
            raw = data[rel : rel + size]
            text = decode_chunk(raw, formats, specials)
            rows.append((readability(text), label, size))
        rows.sort(reverse=True)
        for ratio, label, size in rows:
            print(f"{ratio:5.2f} {label:<26} 0x{size:05X}")
        return

    if cmd == "convert-all":
        threshold = float(sys.argv[2]) if len(sys.argv) > 2 else 0.55
        converted = []
        for label, addr, rel, size in parse_all_chunks():
            raw = data[rel : rel + size]
            # Skip pointer tables: most 4-byte words pointing into ROM/RAM
            # means this is data, not script.
            if size % 4 == 0 and size >= 8:
                words = [int.from_bytes(raw[j : j + 4], "little")
                         for j in range(0, size, 4)]
                ptr = sum(
                    1
                    for w in words
                    if 0x08000000 <= w <= 0x09FFFFFF
                    or 0x02000000 <= w < 0x04000000
                )
                if ptr * 10 >= len(words) * 7:
                    continue
            text = decode_chunk(raw, formats, specials)
            if readability(text) < threshold:
                continue
            if encode_lines(text, formats_by_name, specials) != raw:
                continue
            SCRIPTS_DIR.mkdir(exist_ok=True)
            (SCRIPTS_DIR / f"{label}.inc").write_text(text, encoding="utf-8")
            converted.append(label)
        # Replace the incbin lines of converted chunks with .include.
        lines = EVENT_S.read_text(encoding="utf-8").splitlines(keepends=True)
        out = []
        label = None
        for line in lines:
            lm = LABEL_RE.match(line.rstrip("\r\n"))
            if lm:
                label = lm.group(1)
                out.append(line)
                continue
            m = INCINBIN_RE.match(line)
            if m and label in converted:
                out.append(f'\t.include "data/scripts/{label}.inc"\n')
                label = None
                continue
            out.append(line)
        EVENT_S.write_text("".join(out), encoding="utf-8")
        print(f"converted {len(converted)} chunks (threshold {threshold})")
        return
    sys.exit(f"no chunk named {target}")


if __name__ == "__main__":
    main()
