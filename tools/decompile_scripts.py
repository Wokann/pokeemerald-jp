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


def build_macro_formats(opcode_by_name):
    formats = {}  # opcode -> (macro_name, [(size, arg_name)])
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

        emissions = []
        simple = True
        for line in body:
            s = line.strip()
            em = re.match(r"\.(byte|2byte|4byte)\s+(\S+)", s)
            if em:
                operand = em.group(2)
                if not emissions:
                    # First emission must be the opcode (.byte SCR_OP_X).
                    emissions.append((em.group(1), operand))
                elif operand.startswith("\\"):
                    emissions.append((em.group(1), operand))
                else:
                    # Literal bytes (e.g. givemon's hardcoded zero fields):
                    # the JP ROM stores real values there, so the US macro
                    # cannot reproduce them.  Keep the macro non-simple.
                    simple = False
                continue
            if s.startswith((".if", ".else", ".endif", ".ifb", ".ifc", ".ifnc")):
                simple = False
                continue
            if s.startswith((".warning", ".set", "@", ".align", ".string", ".asciz")):
                continue
            if s == "":
                continue
            simple = False
        if not simple or not emissions:
            continue
        first_dir, first_arg = emissions[0]
        if first_dir != "byte" or not first_arg.startswith("SCR_OP_"):
            continue
        opcode = opcode_by_name.get(first_arg)
        if opcode is None:
            continue
        argfmt = []
        for d, arg in emissions[1:]:
            size = {"byte": 1, "2byte": 2, "4byte": 4}[d]
            argfmt.append((size, arg.lstrip("\\")))
        formats[opcode] = (name, argfmt)
    return formats


def decode_chunk(raw, opcode_table, formats):
    lines = []
    i = 0
    while i < len(raw):
        op = raw[i]
        fmt = formats.get(op)
        if fmt is None:
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        name, argfmt = fmt
        total = 1 + sum(sz for sz, _ in argfmt)
        if i + total > len(raw):
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        args = []
        pos = i + 1
        for sz, _ in argfmt:
            val = int.from_bytes(raw[pos : pos + sz], "little")
            args.append(f"0x{val:X}")
            pos += sz
        lines.append(f"\t{name} {', '.join(args)}")
        i = pos
    return "\n".join(lines) + "\n"


def encode_lines(text, opcode_table, formats):
    """Re-encode decoded lines back to bytes (pure-Python round-trip)."""
    name_to_opcode = {name: op for op, (name, _) in formats.items()}
    out = bytearray()
    for line in text.splitlines():
        s = line.strip()
        m = re.match(r"\.byte\s+0x([0-9A-Fa-f]{2})", s)
        if m:
            out.append(int(m.group(1), 16))
            continue
        m = re.match(r"(\w+)\s*(?:0x[0-9A-Fa-f]+(?:\s*,\s*0x[0-9A-Fa-f]+)*)?$", s)
        if not m:
            raise ValueError(f"cannot re-encode line: {line!r}")
        name = m.group(1)
        op = name_to_opcode.get(name)
        if op is None:
            raise ValueError(f"unknown command {name}")
        _, argfmt = formats[op]
        args = [int(a, 16) for a in re.findall(r"0x[0-9A-Fa-f]+", s)]
        if len(args) != len(argfmt):
            raise ValueError(f"arg count mismatch for {name}")
        out.append(op)
        for (sz, _), val in zip(argfmt, args):
            out.extend(val.to_bytes(sz, "little"))
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


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    if not BIN.is_file():
        sys.exit(f"missing {BIN}; run make first")
    cmd, target = sys.argv[1], sys.argv[2]
    data = BIN.read_bytes()
    opcode_table = build_opcode_table()
    by_name = {const: op for op, (const, _) in opcode_table.items()}
    formats = build_macro_formats(by_name)
    print(f"opcodes: {len(opcode_table)}, simple macros: {len(formats)}")

    for label, addr, rel, size in parse_chunks():
        if label != target:
            continue
        raw = data[rel : rel + size]
        text = decode_chunk(raw, opcode_table, formats)
        if cmd == "dump":
            print(text)
        elif cmd == "check":
            ok = encode_lines(text, opcode_table, formats) == raw
            print(f"{label}: round-trip {'OK' if ok else 'FAIL'} ({size} bytes)")
        elif cmd == "convert":
            if encode_lines(text, opcode_table, formats) != raw:
                sys.exit(f"{label}: round-trip FAIL, refusing")
            SCRIPTS_DIR.mkdir(exist_ok=True)
            out_path = SCRIPTS_DIR / f"{label}.inc"
            out_path.write_text(text, encoding="utf-8")
            print(f"wrote {out_path}")
        return
    sys.exit(f"no chunk named {target}")


if __name__ == "__main__":
    main()
