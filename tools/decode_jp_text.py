#!/usr/bin/env python3
"""Decode pokeemerald-jp text bytes into readable Japanese strings.

Uses the hiragana/katakana half of charmap.txt (the JP table) to decode
raw ROM text, so strings referenced by decompiled functions can be
annotated instead of left as bare addresses.

Usage:
  python3 tools/decode_jp_text.py 0x085F7C50            # decode from baserom
  python3 tools/decode_jp_text.py <bytes-file>           # decode a raw byte file
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def build_charmap():
    cm = {}
    for line in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line or line.startswith("@"):
            continue
        m = re.match(r"'((?:[^'\\]|\\.)*)'\s*=\s*([0-9A-Fa-f ]+)", line)
        if not m:
            continue
        vals = [int(x, 16) for x in m.group(2).split()]
        if len(vals) == 1:
            cm[vals[0]] = m.group(1)
    return cm


def decode(data, charmap):
    out = []
    i = 0
    while i < len(data):
        b = data[i]
        if b == 0xFC:  # EXT_CTRL_CODE_BEGIN: next two bytes are the code
            if i + 2 < len(data):
                out.append("[FC:%02X:%02X]" % (data[i + 1], data[i + 2]))
                i += 3
                continue
            out.append("[FC]")
            i += 1
            continue
        if b == 0xFF:  # EOS
            out.append("$")
            i += 1
            continue
        out.append(charmap.get(b, "?%02X" % b))
        i += 1
    return "".join(out)


def main():
    charmap = build_charmap()
    if not sys.argv[1:]:
        sys.exit(__doc__)
    arg = sys.argv[1]
    if arg.lower().startswith("0x"):
        addr = int(arg, 16)
        base = (ROOT / "baserom_jp.gba").read_bytes()
        off = addr & 0xFFFFFF
        data = base[off : off + 0x80]
        end = data.find(0xFF)
        if end >= 0:
            data = data[: end + 1]
    else:
        data = Path(arg).read_bytes()
    print(decode(data, charmap))


if __name__ == "__main__":
    main()
