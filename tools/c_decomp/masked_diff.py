#!/usr/bin/env python3
"""Show byte-level differences between compiled and JP after masking."""
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
    c = convert_c.mask(res["compiled"])
    j = convert_c.mask(res["jp"])
    print(f"{func}: compiled {len(res['compiled'])}B jp {len(res['jp'])}B ok={res['ok']}")
    n = min(len(c), len(j))
    diffs = []
    for i in range(n):
        if c[i] != j[i]:
            diffs.append(i)
    if len(c) != len(j):
        print(f"  length differs: {len(c)} vs {len(j)}")
    if not diffs:
        print("  no diffs after mask")
    else:
        # group consecutive
        groups = []
        start = prev = diffs[0]
        for i in diffs[1:]:
            if i == prev + 1:
                prev = i
            else:
                groups.append((start, prev))
                start = prev = i
        groups.append((start, prev))
        for s, e in groups:
            print(f"  diff 0x{s:02x}-0x{e:02x}")
            for i in range(s, e + 1):
                print(f"    0x{i:02x}: C={res['compiled'][i]:02x} JP={res['jp'][i]:02x}")


if __name__ == "__main__":
    main()
