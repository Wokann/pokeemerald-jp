#!/usr/bin/env python3
"""Look up one or more functions: dump the JP asm block and the
pokeemerald C definition, to speed up C porting.

Usage:
    python3 tools/c_decomp/lookup_func.py Function1 Function2 ...
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ASM = ROOT / "asm"
US_SRC = ROOT.parent / "pokeemerald" / "src"


def jp_asm_block(name):
    for path in sorted(ASM.glob("*.s")):
        text = path.read_text(encoding="utf-8")
        m = re.search(rf"^({re.escape(name)}:.*?thumb_func_end {re.escape(name)})",
                      text, re.M | re.S)
        if m:
            return path.name, "\n".join(m.group(1).splitlines()[:10])
    return None, None


def us_c_def(name):
    for path in sorted(US_SRC.glob("*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        m = re.search(rf"^[^\n]*\b{re.escape(name)}\s*\([^;]*$",
                      text, re.M)
        if m:
            start = text.rfind("\n", 0, m.start()) + 1
            return path.name, text[start : start + 400]
    return None, None


def main():
    for name in sys.argv[1:]:
        print(f"===== {name} =====")
        jp_file, jp_block = jp_asm_block(name)
        if jp_block:
            print(f"JP [{jp_file}]:")
            print(jp_block)
        else:
            print("JP: not found")
        us_file, us_def = us_c_def(name)
        if us_def:
            print(f"US [{us_file}]:")
            print(us_def)
        else:
            print("US: not found")
        print()


if __name__ == "__main__":
    main()
