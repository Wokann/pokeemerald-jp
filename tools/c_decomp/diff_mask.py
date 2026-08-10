#!/usr/bin/env python3
"""Show mask()-ed compiled vs JP bytes for a function."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import convert_c


def main():
    func = sys.argv[1]
    c_file = Path(__file__).resolve().parents[2] / "src" / sys.argv[2]
    res = convert_c.verify_function(func, str(c_file))
    mc = convert_c.strip_trailing(convert_c.mask(res["compiled"]))
    mj = convert_c.strip_trailing(convert_c.mask(res["jp"]))
    print(f"compiled len={len(res['compiled'])} jp len={len(res['jp'])}")
    print(f"masked compiled len={len(mc)} masked jp len={len(mj)}")
    n = max(len(mc), len(mj))
    for i in range(0, n, 2):
        c = mc[i : i + 2]
        j = mj[i : i + 2]
        mark = "  " if c == j else "**"
        print(f"{mark} {i:04X}: C={c.hex(' ')} JP={j.hex(' ')}")


if __name__ == "__main__":
    main()
