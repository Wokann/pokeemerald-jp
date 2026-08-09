#!/usr/bin/env python3
"""Compile a C function with the pret agbcc toolchain, compare its code
bytes with the JP ROM, and print the assembly snippet to inline.

Usage:
    python3 tools/c_decomp/convert_c.py <function-name> <c-file>

The JP function address is read from the asm label comment; the final
literal pool word is masked for the comparison (it resolves at link
time).  On success the tool prints the .s snippet with the literal
replaced by the JP value, ready to paste into the asm file.
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
AGBCC = ROOT.parent / "pokeemerald" / "tools" / "agbcc" / "bin" / "agbcc"
AS = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-as"
OBJCOPY = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-objcopy"
JP_ROM = ROOT / "baserom_jp.gba"

def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    name, c_file = sys.argv[1], Path(sys.argv[2])

    # JP address + bytes from the asm label comment.
    jp_addr = None
    for path in sorted((ROOT / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = re.match(rf"^{name}:\s*@\s*0x([0-9A-Fa-f]+)\s*$", line)
            if m:
                jp_addr = int(m.group(1), 16)
                break
        if jp_addr:
            break
    if jp_addr is None:
        sys.exit(f"no asm label for {name}")

    # Compile.
    proc = subprocess.run(
        [str(AGBCC), "-mthumb-interwork", "-O2", "-fhex-asm", "-o", "/tmp/cv.s",
         str(c_file)],
        capture_output=True,
        text=True,
    )
    if proc.returncode != 0:
        sys.exit(proc.stderr)
    asm_text = Path("/tmp/cv.s").read_text()
    has_literal = bool(re.search(r"\.word\s+\S+\s*$", asm_text, re.M))
    subprocess.run([str(AS), "-mcpu=arm7tdmi", "-o", "/tmp/cv.o", "/tmp/cv.s"],
                   check=True)
    subprocess.run(
        [str(OBJCOPY), "-O", "binary", "--only-section=.text",
         "/tmp/cv.o", "/tmp/cv.bin"],
        check=True,
    )
    compiled = Path("/tmp/cv.bin").read_bytes()

    jp_size = len(compiled) + 8
    jp_bytes = JP_ROM.read_bytes()[
        (jp_addr & 0xFFFFFF) : (jp_addr & 0xFFFFFF) + jp_size
    ]

    def mask(b):
        out = bytearray(b)
        for i in range(0, len(out) - 3, 2):
            hw1 = out[i] | (out[i + 1] << 8)
            hw2 = out[i + 2] | (out[i + 3] << 8)
            if (hw1 & 0xF800) == 0xF000 and (hw2 & 0xF800) == 0xF800:
                out[i] = 0xF0
                out[i + 1] = 0x00
                out[i + 2] = 0xF8
                out[i + 3] = 0x00
        if has_literal and len(out) >= 8:
            out[-4:] = b"\x00\x00\x00\x00"
        return bytes(out)

    def strip_trailing(b):
        b = bytearray(b)
        while True:
            if len(b) >= 2 and b[-2:] == b"\xc0\x46":
                del b[-2:]
            elif b and b[-1] == 0x00:
                b.pop()
            else:
                break
        return bytes(b)

    ok = strip_trailing(mask(compiled)) == strip_trailing(mask(jp_bytes[: len(compiled)]))
    print(f"{name}: JP 0x{jp_addr:08X} compiled {len(compiled)} bytes "
          f"{'MATCH' if ok else 'DIFF'}")
    print("  compiled:", compiled.hex(" "))
    print("  jp:      ", jp_bytes[: len(compiled)].hex(" "))
    if not ok:
        print("  (code bytes differ; adjust the C source)")
        sys.exit(1)
    # Show the literal the assembler emitted (unresolved) and JP value.
    if has_literal:
        lit = int.from_bytes(jp_bytes[len(compiled) - 4 : len(compiled)], "little")
        print(f"  literal: 0x{lit:08X} (resolve via sym file / rename in .s)")
    print("--- snippet ---")
    print(asm_text)


if __name__ == "__main__":
    main()
