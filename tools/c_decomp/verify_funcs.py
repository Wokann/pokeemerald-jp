#!/usr/bin/env python3
"""Verify a list of functions in one C file."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import convert_c


def main():
    c_file = sys.argv[1]
    funcs = sys.argv[2:]
    for f in funcs:
        r = convert_c.verify_function(f, c_file)
        if r is None:
            print(f"{f}: no result")
            continue
        if r.get("error"):
            print(f"{f}: {r['error']}")
            continue
        status = "MATCH" if r["ok"] else "DIFF"
        extra = f" ({r.get('error')})" if not r["ok"] and r.get("error") else ""
        print(f"{f}: JP 0x{r['addr']:08X} {status}{extra}")


if __name__ == "__main__":
    main()
