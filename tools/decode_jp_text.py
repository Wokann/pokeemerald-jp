#!/usr/bin/env python3
"""Decode pokeemerald-jp text bytes into readable JP strings.

Uses charmap.txt (hiragana/katakana + multi-byte macros) and the
EXT_CTRL_CODE rules from src/text.c so that bytes that only have meaning
after a control code are treated as control parameters, not decoded as
ordinary text.

Usage:
  python3 tools/decode_jp_text.py 0x085F7C50            # decode from baserom
  python3 tools/decode_jp_text.py <bytes-file>           # decode a raw byte file
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# EXT_CTRL_CODE argument byte counts, from src/text.c (RENDER_STATE_HANDLE_CHAR).
CTRL_ARGS = {
    0x00: 0,  # NAME_END
    0x01: 1,  # COLOR
    0x02: 1,  # HIGHLIGHT
    0x03: 1,  # SHADOW
    0x04: 3,  # COLOR_HIGHLIGHT_SHADOW
    0x05: 1,  # PALETTE
    0x06: 1,  # FONT
    0x07: 0,  # RESET_FONT
    0x08: 1,  # PAUSE
    0x09: 0,  # PAUSE_UNTIL_PRESS
    0x0A: 0,  # WAIT_SE
    0x0B: 2,  # PLAY_BGM
    0x0C: 1,  # ESCAPE
    0x0D: 1,  # SHIFT_RIGHT
    0x0E: 1,  # SHIFT_DOWN
    0x0F: 0,  # FILL_WINDOW
    0x10: 2,  # PLAY_SE
    0x11: 0,  # CLEAR
    0x12: 0,  # SKIP
    0x13: 1,  # CLEAR_TO
    0x14: 1,  # MIN_LETTER_SPACING
    0x15: 0,  # JPN
    0x16: 0,  # ENG
    0x17: 0,  # PAUSE_MUSIC
    0x18: 0,  # RESUME_MUSIC
}

CTRL_NAMES = {
    0x00: "NAME_END",
    0x01: "COLOR",
    0x02: "HIGHLIGHT",
    0x03: "SHADOW",
    0x04: "COLOR_HIGHLIGHT_SHADOW",
    0x05: "PALETTE",
    0x06: "FONT",
    0x07: "RESET_FONT",
    0x08: "PAUSE",
    0x09: "PAUSE_UNTIL_PRESS",
    0x0A: "WAIT_SE",
    0x0B: "PLAY_BGM",
    0x0C: "ESCAPE",
    0x0D: "SHIFT_RIGHT",
    0x0E: "SHIFT_DOWN",
    0x0F: "FILL_WINDOW",
    0x10: "PLAY_SE",
    0x11: "CLEAR",
    0x12: "SKIP",
    0x13: "CLEAR_TO",
    0x14: "MIN_LETTER_SPACING",
    0x15: "JPN",
    0x16: "ENG",
    0x17: "PAUSE_MUSIC",
    0x18: "RESUME_MUSIC",
}


def build_sound_map():
    """SE_xxx/MUS_xxx id -> name from include/constants/songs.h."""
    sounds = {}
    for line in (ROOT / "include/constants/songs.h").read_text(encoding="utf-8").splitlines():
        m = re.match(r"#define (SE_[A-Za-z0-9_]+|MUS_[A-Za-z0-9_]+)\s+(\d+)", line)
        if m:
            sounds[int(m.group(2))] = m.group(1)
    return sounds


COLOR_NAMES = {
    0x0: "TEXT_COLOR_TRANSPARENT",
    0x1: "TEXT_COLOR_WHITE",
    0x2: "TEXT_COLOR_DARK_GRAY",
    0x3: "TEXT_COLOR_LIGHT_GRAY",
    0x4: "TEXT_COLOR_RED",
    0x5: "TEXT_COLOR_LIGHT_RED",
    0x6: "TEXT_COLOR_GREEN",
    0x7: "TEXT_COLOR_LIGHT_GREEN",
    0x8: "TEXT_COLOR_BLUE",
    0x9: "TEXT_COLOR_LIGHT_BLUE",
    0xA: "TEXT_DYNAMIC_COLOR_1",
    0xB: "TEXT_DYNAMIC_COLOR_2",
    0xC: "TEXT_DYNAMIC_COLOR_3",
    0xD: "TEXT_DYNAMIC_COLOR_4",
    0xE: "TEXT_DYNAMIC_COLOR_5",
    0xF: "TEXT_DYNAMIC_COLOR_6",
}

FONT_NAMES = {
    0: "FONT_SMALL",
    1: "FONT_NORMAL",
    2: "FONT_SHORT",
    3: "FONT_SHORT_COPY_1",
    4: "FONT_SHORT_COPY_2",
    5: "FONT_SHORT_COPY_3",
    6: "FONT_SHORT_COPY_4",
    7: "FONT_NARROW",
    8: "FONT_SMALL_NARROW",
}


def ctrl_param_text(code, args, sounds):
    """Render control-code arguments using their concrete rules."""
    if not args:
        return ""
    if code in (0x01, 0x02, 0x03):
        name = COLOR_NAMES.get(args[0], "0x%02X" % args[0])
        return ":%s" % name
    if code == 0x04:  # fg/bg/shadow
        parts = [COLOR_NAMES.get(b, "0x%02X" % b) for b in args]
        return ":%s" % ",".join(parts)
    if code == 0x05:
        return ":%02X" % args[0]
    if code == 0x06:
        return ":%s" % FONT_NAMES.get(args[0], "0x%02X" % args[0])
    if code == 0x08:
        return ":%d" % args[0]
    if code in (0x0B, 0x10):  # PLAY_BGM / PLAY_SE: u16 id
        sid = args[0] | (args[1] << 8)
        name = sounds.get(sid, "0x%04X" % sid)
        return ":%s" % name
    if code == 0x0C:  # ESCAPE: single char
        return ":0x%02X" % args[0]
    if code in (0x0D, 0x0E):
        return ":%d" % args[0]
    return ":%s" % args.hex().upper()


def build_maps():
    """Return (single_byte_chars, multi_byte_macros) from charmap.txt."""
    single = {}
    multi = {}
    for line in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line or line.startswith("@"):
            continue
        m = re.match(r"'((?:[^'\\]|\\.)*)'\s*=\s*([0-9A-Fa-f ]+)", line)
        if m:
            vals = [int(x, 16) for x in m.group(2).split()]
            if len(vals) == 1:
                single[vals[0]] = m.group(1)
            continue
        m = re.match(r"([A-Za-z0-9_]+)\s*=\s*([0-9A-Fa-f ]+)", line)
        if m:
            vals = [int(x, 16) for x in m.group(2).split()]
            if len(vals) > 1:
                # Skip FC control-code macros (handled separately below).
                if vals[0] != 0xFC:
                    multi[bytes(vals)] = m.group(1)
    return single, multi


def decode(data, single, multi, sounds):
    max_len = max((len(k) for k in multi), default=1)
    out = []
    i = 0
    while i < len(data):
        b = data[i]
        if b == 0xFC:
            if i + 1 < len(data):
                code = data[i + 1]
                name = CTRL_NAMES.get(code, "CTRL_%02X" % code)
                nargs = CTRL_ARGS.get(code, 0)
                args = data[i + 2 : i + 2 + nargs]
                out.append("{%s%s}" % (name, ctrl_param_text(code, args, sounds)))
                i += 2 + nargs
            else:
                out.append("[FC]")
                i += 1
            continue
        if b == 0xFF:
            out.append("$")
            i += 1
            continue
        if b == 0xFE:
            out.append("\\n")
            i += 1
            continue
        matched = False
        for ln in range(max_len, 0, -1):
            seq = bytes(data[i : i + ln])
            if seq in multi:
                out.append("{%s}" % multi[seq])
                i += ln
                matched = True
                break
        if matched:
            continue
        out.append(single.get(b, "?%02X" % b))
        i += 1
    return "".join(out)


def main():
    single, multi = build_maps()
    sounds = build_sound_map()
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
    print(decode(data, single, multi, sounds))


if __name__ == "__main__":
    main()
