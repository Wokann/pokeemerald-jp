#!/usr/bin/env python3
"""Decode a raw chunk as script up to the first data region.

The JP script region interleaves scripts with raw data/text.  A blanket
decode turns the data into nonsense instructions.  This tool decodes
instruction by instruction and stops at the first instruction whose
pointer-ish arguments (goto/call/message/loadword targets) fall outside
ROM, leaving the remainder as .incbin.

Usage:
    python3 tools/split_decode.py 0x1dddf3 0x903
    python3 tools/split_decode.py gUnknown_826240A
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import decompile_scripts as d

# commands whose first arg (or args) is a ROM/RAM address
ADDR_CMDS = re.compile(
    r"^\s*(goto|goto_if|call|call_if|message|loadword|pokenavcall|"
    r"warpsilent|warp|setdynamicwarp|setholewarp|setwarp|warpteleport|"
    r"warpdoor|goto_if_set|goto_if_unset|goto_if_ge|goto_if_gt|"
    r"goto_if_le|goto_if_lt)\b")
# all hex tokens on a line (any width)
HEXARG = re.compile(r"0x([0-9A-Fa-f]+)\b")

def is_romish(a):
    return 0x08000000 <= a <= 0x09FFFFFF

# commands whose positional args must be small (ids, counts, coords)
SMALL_ARG_CMDS = re.compile(
    r"^\s*(removeobject_at|showobject_at|hideobject_at|moveobjectoffscreen|"
    r"givepcitem|setmonmove|setmonmetlocation|checkmonobedience|"
    r"setdoorclosed|opendoor|setberrytree|initclock|braillemessage|"
    r"yesnobox|multichoice|multichoicedefault|multichoicegrid|"
    r"drawboxtext|warphole|gotonative|callnative)\b")

SCRIPT_OPENERS = re.compile(
    r"^\s*(lockall|lock|faceplayer|special|specialvar|setvar|goto|goto_if|"
    r"call|call_if|checkflag|compare_var_to_value|applymovement|message|"
    r"loadword|end|return|release|releaseall|setflag|clearflag|msgbox|"
    r"dotrainerbattle|gotobeatenscript|warp|fadescreen|playse|delay)\b")

def split(raw, formats, specials):
    """Return (decoded_lines, data_offset) where data_offset is the byte
    offset into raw where plausible-script decoding should stop."""
    lines = []
    i = 0
    n = len(raw)
    opened_ok = False
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
            if kind == "lit" and int.from_bytes(raw[pos:pos+sz], "little") != an:
                ok = False
                break
            pos += sz
        if not ok:
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        # consume args like decode_chunk
        args = []
        pos = i + 1
        extra = 0
        skip_lo = False
        for sz, kind, an in argfmt:
            if skip_lo:
                skip_lo = False
                continue
            if kind == "arg":
                args.append(f"0x{int.from_bytes(raw[pos:pos+sz], 'little'):X}")
            elif kind == "lit":
                pass
            elif kind == "arg_hi":
                args.append(f"0x{(raw[pos] << 8) | raw[pos + 1]:X}")
                pos += 1
                skip_lo = True
            elif kind == "special":
                idx = int.from_bytes(raw[pos:pos+2], "little")
                entry = specials.get(idx)
                if entry is None:
                    ok = False
                    break
                args.append(entry[0])
                if entry[1]:
                    extra = 1
            pos += sz
        if not ok:
            lines.append(f"\t.byte 0x{op:02X}")
            i += 1
            continue
        line = f"\t{name} {', '.join(args)}".rstrip()
        # data heuristic: positional args on small-arg commands are absurd
        if SMALL_ARG_CMDS.match(line):
            for a in args:
                if a.startswith("0x"):
                    v = int(a, 16)
                    if v > 0x1000:
                        return lines, i
        # data heuristic: address-carrying commands pointing outside ROM
        if ADDR_CMDS.match(line):
            addrs = [int(am.group(1), 16) for am in HEXARG.finditer(line)]
            if addrs:
                a = addrs[-1]
                if not (0x08000000 <= a <= 0x09FFFFFF
                        or 0x02000000 <= a < 0x04000000):
                    return lines, i
        # generic absurd args on any command: a word beyond RAM/ROM ranges
        for a in args:
            if a.startswith("0x") and len(a) > 8:
                v = int(a, 16)
                if v > 0x04000000 and not is_romish(v):
                    return lines, i
        lines.append(line)
        i += base + extra
        if not opened_ok and len(lines) >= 4:
            opener_count = sum(1 for l in lines if SCRIPT_OPENERS.match(l))
            noise = sum(1 for l in lines
                        if l.strip().startswith(".byte") or l.strip() == "nop")
            if noise >= 2 and opener_count == 0:
                return [], 0
            opened_ok = True
    return lines, n

def main():
    if len(sys.argv) >= 3 and sys.argv[1].startswith("0x"):
        rel = int(sys.argv[1], 16)
        size = int(sys.argv[2], 16)
        if rel >= 0x08000000:
            rel -= 0x08000000
        label = f"0x{rel:X}"
    else:
        label = sys.argv[1]
        inc = d.SCRIPTS_DIR / f"{label}.inc"
        text = inc.read_text(encoding="utf-8")
        m = re.search(r'\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)', text)
        if not m:
            sys.exit("not a single-incbin file")
        rel = int(m.group(1), 16)
        size = int(m.group(2), 16)
    raw = d.BIN.read_bytes()[rel - 0x1DABAC: rel - 0x1DABAC + size]
    opcode_table = d.build_opcode_table()
    by_name = {const: op for const, op in opcode_table.items()}
    formats, formats_by_name = d.build_macro_formats(by_name)
    specials = d.build_specials_map()
    lines, stop = split(raw, formats, specials)
    print(f"# {label}: decoded {stop:#x} of {size:#x} bytes, "
          f"{len(lines)} lines, remaining {size - stop:#x}")
    print("\n".join(lines))
    if stop < size:
        print(f'\t.incbin "baserom_jp.gba", 0x{rel + stop:X}, 0x{size - stop:X}')

if __name__ == "__main__":
    main()
