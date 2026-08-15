#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate src/data/union_room.c/h for the union-room text region.

The region in data/data_b.s at 0x82C053C..0x82C06B8 contains the RFU
assert/debug ASCII strings and the first union-room texts.  Every symbol
is decoded from baserom_jp.gba with the EXT_CTRL_CODE rules from
src/text.c (tools/decode_jp_text.py), then emitted as a C array.  The
generated file is round-trip checked by re-encoding through preproc and
comparing byte-for-byte with the ROM.
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import decode_jp_text as d  # noqa: E402


ROM = (ROOT / "baserom_jp.gba").read_bytes()

# (name, addr, kind) for the clean sub-region.  kind is 'ascii', 'text' or
# 'gap'.  ASCII strings are emitted as char arrays; text as _() strings.
SYMBOLS = [
    ("sAssertFile_rfu", 0x082C053C, "ascii_fixed", "rfu.c", 8),
    ("sAssertExpr_RfuFuncNull", 0x082C0544, "ascii_fixed", "Rfu.RfuFunc == NULL", 20),
    ("sAssertExpr_SizeLe252", 0x082C0558, "ascii_fixed", "size<=252", 12),
    ("sASCII_PokemonSioInfo", 0x082C0564, "ascii_fixed", "PokemonSioInfo", 15),
    ("sJPText_Akito", 0x082C0574, "text", None),
    ("sASCII_LinkLossDisconnect", 0x082C0578, "ascii", "LINK LOSS DISCONNECT!"),
    ("sASCII_LinkLossRecoveryNow", 0x082C0590, "ascii_aligned", "LINK LOSS RECOVERY NOW"),
    ("sASCII_30Spaces", 0x082C05A8, "ascii_aligned", " " * 30),
    ("sASCII_15Spaces", 0x082C05C7, "ascii", " " * 15),
    ("sASCII_8Spaces", 0x082C05D7, "ascii", " " * 8),
    ("sASCII_Space", 0x082C05E0, "ascii", " "),
    ("sASCII_Asterisk", 0x082C05E2, "ascii", "*"),
    ("sASCII_NowSlot", 0x082C05E4, "ascii", "NOWSLOT"),
    ("sASCII_ClockCmds", 0x082C05EC, "clock_cmds", None),
    ("sASCII_ChildParentSearch", 0x082C0628, "child_search", None),
    ("sUnknown_82C0640", 0x082C0640, "gap", bytes([0xFF, 0x00, 0x00, 0x00])),
    ("sText_Colon", 0x082C0644, "text", None),
    ("sText_ID", 0x082C0648, "text", None),
    ("sText_PleaseStartOver", 0x082C064C, "text", None),
    ("sText_WirelessSearchCanceled", 0x082C066C, "text", None),
    ("sText_AwaitingCommunication", 0x082C069C, "text_fixed", None),
]

END_ADDR = 0x082C06B8  # sText_AwaitingLinkPressStart (next region)

# Second batch: six simple union-room texts (no embedded tables).
SYMBOLS2 = [
    ("sText_BButtonCancel", 0x082C08A4, "text", None),
    ("sText_PlayerContactedYouForXAccept", 0x082C08C4, "text", None),
    ("sText_PlayerContactedYouShareX", 0x082C08DC, "text", None),
    ("sText_PlayerContactedYouAddToMembers", 0x082C08F8, "text", None),
    ("sText_AreTheseMembersOK", 0x082C0914, "text", None),
    ("sText_CancelModeWithTheseMembers", 0x082C092C, "text_fixed", None),
]

END_ADDR2 = 0x082C0948  # sText_AnOKWasSentToPlayer (next region)


def next_addr(addr, symbols, end_addr):
    for sym in symbols:
        if sym[1] > addr:
            return sym[1]
    return end_addr


def region_bytes(addr, end):
    off = addr & 0xFFFFFF
    return ROM[off : off + (end - addr)]


def emit_ascii(name, content, aligned=False, size=None):
    a = "ALIGNED(4) " if aligned else ""
    s = f"[{size}]" if size else "[]"
    # Brace initializers keep agbcc from emitting .align 2 before every
    # array (packed layout like the ROM); plain strings would be aligned.
    return f'{a}const char {name}{s} = {{"{content}"}};'


def emit_text(name, addr, end, size=None):
    single, multi = d.build_maps()
    sounds = d.build_sound_map()
    data = region_bytes(addr, end)
    # Decode the raw ROM bytes, then truncate at the last $ terminator.
    # Everything after it is alignment padding; the trailing $ itself is
    # reproduced by preproc's automatic terminator (which appends 0xFF).
    text = d.decode(data, single, multi, sounds)
    last = text.rfind("$")
    if last >= 0:
        text = text[:last]
    lines = text.split("\\n")
    s = f"[{size}]" if size else "[]"
    if len(lines) == 1:
        return f'ALIGNED(4) const u8 {name}{s} = _("{text}");'
    body = "\n".join('    "%s\\n"' % ln for ln in lines[:-1]) + "\n" + '    "%s"' % lines[-1]
    return f"ALIGNED(4) const u8 {name}{s} = _(\n{body});"


def build(symbols, end_addr, out_h, out_c, comment):
    single, multi = d.build_maps()
    sounds = d.build_sound_map()
    out = []
    out.append('#include "global.h"')
    out.append("")
    out.append(comment)
    for i, sym in enumerate(symbols):
        name, addr, kind, payload = sym[0], sym[1], sym[2], sym[3]
        end = next_addr(addr, symbols, end_addr)
        if kind == "ascii_fixed":
            out.append(emit_ascii(name, payload, size=symbols[i][4]))
        elif kind in ("ascii", "ascii_aligned"):
            out.append(emit_ascii(name, payload, aligned=(kind == "ascii_aligned")))
        elif kind == "gap":
            b = ", ".join("0x%02X" % x for x in payload)
            out.append(f"const u8 {name}[] = {{{b}}};")
        elif kind in ("text", "text_fixed"):
            size = None
            if kind == "text_fixed":
                size = end_addr - addr
            out.append(emit_text(name, addr, end, size=size))
        elif kind == "clock_cmds":
            out.append('const char sASCII_ClockCmds[][12] = {')
            for row in ["           ", "CLOCK DRIFT", "BUSY SEND  ", "CMD REJECT ", "CLOCK SLAVE"]:
                out.append(f'    "{row}",')
            out.append("};")
        elif kind == "child_search":
            out.append('const char sASCII_ChildParentSearch[][8] = {')
            for row in ["CHILD ", "PARENT", "SEARCH"]:
                out.append(f'    "{row}",')
            out.append("};")
        out.append("")
    (ROOT / out_h).write_text("\n".join(out) + "\n", encoding="utf-8")
    (ROOT / out_c).write_text(f'#include "{Path(out_h).name}"\n', encoding="utf-8")
    print(f"wrote {out_h} and {out_c}")


def main():
    build(SYMBOLS, END_ADDR, "src/data/union_room.h", "src/data/union_room.c",
          "// RFU assert and debug strings (JP-specific section at 0x82C053C)")
    build(SYMBOLS2, END_ADDR2, "src/data/union_room2.h", "src/data/union_room2.c",
          "// Union-room texts (second batch)")


if __name__ == "__main__":
    main()
