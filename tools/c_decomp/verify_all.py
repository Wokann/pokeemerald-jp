#!/usr/bin/env python3
"""Batch-verify every C function in src/ against the JP ROM.

For each src/*.c the file is compiled once with the pret toolchain and
every defined function's bytes are compared to the JP ROM (absolute
address literals and bl immediates masked).  Any DIFF or missing label
exits non-zero, so `make verify-c` fails whenever a converted function
diverges from the ROM.
"""

import sys
from pathlib import Path

import convert_c

ROOT = Path(__file__).resolve().parents[2]


def main():
    src = ROOT / "src"
    files = sorted(src.glob("*.c"))
    total = matched = 0
    problems = []
    for c_file in files:
        try:
            results = convert_c.verify_c_file(c_file)
        except SystemExit as e:
            problems.append(f"{c_file.name}: compile error: {e}")
            continue
        for res in results:
            total += 1
            if res["ok"]:
                matched += 1
            else:
                problems.append(
                    f"{c_file.name}: {res['name']} "
                    f"JP 0x{res.get('addr', 0):08X} DIFF"
                    + (f" ({res['error']})" if res["error"] else "")
                )
    print(f"src functions verified: {matched}/{total}")
    for p in problems:
        print("  FAIL:", p)
    if problems:
        sys.exit(1)


if __name__ == "__main__":
    main()
