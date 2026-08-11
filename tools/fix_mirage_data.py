#!/usr/bin/env python3
"""Rename/split the mirage_tower data symbols in data/data.s.

- rename the gfx/tilemap/table symbols to their US counterparts
- split gUnknown_85E7E00 (0x120) into sFossil_Gfx (0x80) +
  sMirageTowerCrumbles_Gfx (0x80) + gUnknown_85E7F00 (0x20)
- fix the mis-extracted gUnknown_85E801C text block into
  sSpriteTemplate_CeilingCrumbleLarge (0x18) + gUnknown_85E8034 text
"""

import re


RENAMES = {
    "gUnknown_85E7430": "sMirageTower_Gfx",
    "gUnknown_85E7D50": "sMirageTowerTilemap",
    "gUnknown_85E7F20": "sCeilingCrumblePositions",
    "gUnknown_85E7F50": "sCeilingCrumbleSpriteSheets",
    "gUnknown_85E7F60": "sInvisibleMirageTowerMetatiles",
    "gUnknown_85E7FBC": "sSpriteTemplate_FallingFossil",
    "gUnknown_85E7FD4": "gMirageTowerPulseBlendSettings",
    "gUnknown_85E7FF0": "sSpriteTemplate_CeilingCrumbleSmall",
}


def main():
    with open("data/data.s", encoding="utf-8", errors="replace") as f:
        lines = f.readlines()

    out = []
    i = 0
    while i < len(lines):
        line = lines[i]
        m = re.match(r"\s*\.globl (gUnknown_85E\w+)", line)
        if not m:
            out.append(line)
            i += 1
            continue
        sym = m.group(1)
        if sym == "gUnknown_85E7E00":
            # Split into three blocks.
            out.append("\t.globl sFossil_Gfx\n")
            out.append("sFossil_Gfx: @ 0x85E7E00\n")
            out.append('\t.incbin "build/data/data.bin", 0x34c05c, 0x80\n')
            out.append("\n")
            out.append("\t.globl sMirageTowerCrumbles_Gfx\n")
            out.append("sMirageTowerCrumbles_Gfx: @ 0x85E7E80\n")
            out.append('\t.incbin "build/data/data.bin", 0x34c0dc, 0x80\n')
            out.append("\n")
            out.append("\t.globl gUnknown_85E7F00\n")
            out.append("gUnknown_85E7F00: @ 0x85E7F00\n")
            out.append('\t.incbin "build/data/data.bin", 0x34c15c, 0x20\n')
            out.append("\n")
            i += 2  # skip .globl + label + .incbin lines
            i += 1
            continue
        if sym == "gUnknown_85E801C":
            # Replace the mis-extracted text block: sprite template + text.
            out.append("\t.globl sSpriteTemplate_CeilingCrumbleLarge\n")
            out.append("sSpriteTemplate_CeilingCrumbleLarge: @ 0x85E801C\n")
            out.append('\t.incbin "build/data/data.bin", 0x34c278, 0x18\n')
            out.append("\n")
            out.append("\t.globl gUnknown_85E8034\n")
            out.append("gUnknown_85E8034: @ 0x85E8034\n")
            # Find where the text block ends (next .globl).
            j = i + 2
            while j < len(lines) and not re.match(r"\s*\.globl ", lines[j]):
                j += 1
            if j >= len(lines):
                raise SystemExit("no next .globl after gUnknown_85E801C")
            next_sym = re.match(r"\s*\.globl (\w+)", lines[j]).group(1)
            nxt = re.match(r"(\w+): @ (0x[0-9A-Fa-f]+)", lines[j + 1])
            next_addr = int(nxt.group(2), 16)
            size = next_addr - 0x085E8034
            out.append(f'\t.incbin "build/data/data.bin", 0x34c290, 0x{size:x}\n')
            out.append("\n")
            # Copy the following .globl/label lines unchanged.
            while i < j:
                i += 1
            continue
        if sym in RENAMES:
            new = RENAMES[sym]
            out.append(line.replace(sym, new))
            i += 1
            out.append(lines[i].replace(sym, new))
            i += 1
            out.append(lines[i])
            i += 1
            continue
        out.append(line)
        i += 1

    with open("data/data.s", "w", encoding="utf-8", newline="") as f:
        f.writelines(out)
    print("done")


if __name__ == "__main__":
    main()
