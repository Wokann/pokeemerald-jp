#!/usr/bin/env python3
"""Remove converted function blocks from the head of asm/load_save_rest.s.

The converted functions now live in src/load_save.c; the remaining asm
functions stay in ROM order after the C object, so layout is preserved.
Also renames the remaining JP symbols to pokeemerald names.
"""

from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ASM = ROOT / "asm" / "load_save_rest.s"

REMOVE = {
    "SaveEventObjects",
    "LoadEventObjects",
    "CopyPartyAndObjectsToSave",
    "CopyPartyAndObjectsFromSave",
}
RENAME = {
    "SaveSerializedGame": "CopyPartyAndObjectsToSave",
    "LoadSerializedGame": "CopyPartyAndObjectsFromSave",
    "SaveEventObjects": "SaveObjectEvents",
    "LoadEventObjects": "LoadObjectEvents",
}

lines = ASM.read_text(encoding="utf-8").splitlines()

# Collect function blocks (thumb_func_start .. thumb_func_end).
blocks = []
current = None
start = 0
for i, line in enumerate(lines):
    if line.strip().startswith("thumb_func_start"):
        current = line.split()[1]
        start = i
    elif line.strip().startswith("thumb_func_end"):
        blocks.append((current, start, i + 1))
        current = None

remove_idx = set()
for name, s, e in blocks:
    if name in REMOVE:
        remove_idx.update(range(s, e))

out = []
for i, line in enumerate(lines):
    if i in remove_idx:
        continue
    for old, new in RENAME.items():
        line = line.replace(old, new)
    out.append(line)

ASM.write_text("\n".join(out) + "\n", encoding="utf-8")
print(f"removed {sum(1 for n, s, e in blocks if n in REMOVE)} blocks, "
      f"{len(out)} lines remain")
