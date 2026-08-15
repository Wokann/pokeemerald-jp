#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Decode ROM inner-code bytes back to charmap text (reverse lookup)."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

fwd = {}
single = {}   # single-byte: byte -> char (kana/symbols, no control codes)
multi = {}    # multi-byte: bytes -> text (control codes, constants)
for l in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
    m = re.match(r"^('(.+?)'|(\w+))\s*=\s*([0-9A-Fa-f ]+?)(?:\s+@.*)?$", l)
    if m:
        try:
            b = bytes(int(x, 16) for x in m.group(4).split())
        except ValueError:
            continue
        if m.group(2):
            key = m.group(2).replace("\\'", "'").replace("\\\\", "\\")
            fwd[key] = b
            if len(b) == 1:
                single[b[0]] = key
            else:
                multi.setdefault(b, "{" + key + "}")
        else:
            fwd["{" + m.group(3) + "}"] = b
            multi.setdefault(b, "{" + m.group(3) + "}")

# control-code prefixes (FD xx / FC xx / FE / FA / FB) take priority as multi-byte
multi_len = sorted(set(len(b) for b in multi), reverse=True)

# extended control codes that take argument bytes after the code.
# key: charmap constant name; value: number of argument bytes.
CTRL_ARG_BYTES = {
    "COLOR": 1,
    "HIGHLIGHT": 1,
    "SHADOW": 1,
    "COLOR_HIGHLIGHT_SHADOW": 3,
    "PALETTE": 1,
    "FONT": 1,
    "PAUSE": 1,
    "WAIT_SE": 1,
    "PLAY_BGM": 1,
    "SHIFT_RIGHT": 1,
    "SHIFT_DOWN": 1,
    "FILL_WINDOW": 1,
    "PLAY_SE": 1,
    "CLEAR_TO": 1,
    "MIN_LETTER_SPACING": 1,
}


def decode(data):
    """Decode inner-code bytes to charmap text (kana/symbol first)."""
    out = []
    i = 0
    while i < len(data):
        matched = False
        b0 = data[i]
        # single-byte kana/symbol first
        if b0 in single:
            out.append(single[b0])
            i += 1
            matched = True
            continue
        # multi-byte control codes
        for L in multi_len:
            if i + L <= len(data) and data[i:i + L] in multi:
                token = multi[data[i:i + L]]
                name = token.strip("{}")
                nargs = CTRL_ARG_BYTES.get(name, 0)
                args = data[i + L:i + L + nargs]
                if nargs and len(args) == nargs:
                    out.append("{" + name + " " + " ".join(str(x) for x in args) + "}")
                    i += L + nargs
                else:
                    out.append(token)
                    i += L
                matched = True
                break
        if not matched:
            out.append(f"\\x{data[i]:02X}")
            i += 1
    return "".join(out)


if __name__ == "__main__":
    import sys
    rom = (ROOT / "baserom_jp.gba").read_bytes()
    off = int(sys.argv[1], 16)
    size = int(sys.argv[2], 16)
    data = rom[off:off + size]
    print("hex:", data.hex(" "))
    print("decoded:", decode(data))
