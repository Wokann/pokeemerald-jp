#!/usr/bin/env python3
"""Fix the mis-extracted sprite template at 0x84E8B40 in data/data.s.

The automatic extractor treated the SpriteTemplate bytes at 0x84E8B40 as a
text string.  Replace the three .string lines with:
  sSpriteTemplate_Arrow        (0x18 bytes)
  gUnknown_84E8B58             (0x4 bytes)
  gUnknown_84E8B5C             (0x28 bytes, raw text region)
"""


def main():
    path = "data/data.s"
    with open(path, encoding="utf-8", errors="replace") as f:
        lines = f.readlines()

    # Locate the block.
    start = None
    end = None
    for i, line in enumerate(lines):
        if ".globl gUnknown_84E8B40" in line:
            start = i
        if start is not None and i > start and ".globl gUnknown_84E8B84" in line:
            end = i
            break

    if start is None or end is None:
        raise SystemExit("could not locate gUnknown_84E8B40 block")

    print(f"replacing lines {start + 1}..{end} ({end - start} lines)")
    replacement = [
        "\t.globl sSpriteTemplate_Arrow\n",
        "sSpriteTemplate_Arrow: @ 0x84E8B40\n",
        '\t.incbin "build/data/data.bin", 0x24cd9c, 0x18\n',
        "\n",
        "\t.globl gUnknown_84E8B58\n",
        "gUnknown_84E8B58: @ 0x84E8B58\n",
        '\t.incbin "build/data/data.bin", 0x24cdb4, 0x4\n',
        "\n",
        "\t.globl gUnknown_84E8B5C\n",
        "gUnknown_84E8B5C: @ 0x84E8B5C\n",
        '\t.incbin "build/data/data.bin", 0x24cdb8, 0x28\n',
        "\n",
    ]
    lines[start:end] = replacement

    with open(path, "w", encoding="utf-8", newline="") as f:
        f.writelines(lines)
    print("done")


if __name__ == "__main__":
    main()
