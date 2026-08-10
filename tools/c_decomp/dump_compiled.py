#!/usr/bin/env python3
"""Dump a function's compiled bytes from the current C file to /tmp/<func>.bin."""
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import convert_c


def main():
    func = sys.argv[1]
    c_file = Path(__file__).resolve().parents[2] / "src" / sys.argv[2]
    res = convert_c.verify_function(func, str(c_file))
    if not res:
        print("no result")
        return
    out = Path(f"/tmp/{func}.bin")
    out.write_bytes(res["compiled"])
    print(f"{func}: ok={res['ok']} bytes={len(res['compiled'])} -> {out}")


if __name__ == "__main__":
    main()
