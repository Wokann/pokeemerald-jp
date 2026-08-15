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
                out.append(multi[data[i:i + L]])
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
