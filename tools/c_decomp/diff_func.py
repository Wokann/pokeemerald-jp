#!/usr/bin/env python3
"""Disassemble a function's compiled bytes vs JP bytes side by side."""
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import convert_c


def disasm(label, data):
    path = f"/tmp/{label}.bin"
    Path(path).write_bytes(data)
    r = subprocess.run(
        ["arm-none-eabi-objdump", "-D", "-b", "binary", "-m", "arm", "-M", "force-thumb", path],
        capture_output=True,
        text=True,
    )
    return r.stdout


def main():
    func = sys.argv[1]
    c_file = Path(__file__).resolve().parents[2] / "src" / sys.argv[2]
    res = convert_c.verify_function(func, str(c_file))
    if not res:
        print("no result")
        return
    print(f"=== {func} JP 0x{res['addr']:08X} ok={res['ok']}")
    # Align both dumps to instructions by index.
    lines_c = [l for l in disasm("compiled", res["compiled"]).splitlines() if l.strip() and not l.startswith("0:")]
    lines_j = [l for l in disasm("jp", res["jp"]).splitlines() if l.strip() and not l.startswith("0:")]
    n = max(len(lines_c), len(lines_j))
    for i in range(n):
        c = lines_c[i] if i < len(lines_c) else ""
        j = lines_j[i] if i < len(lines_j) else ""
        mark = "  " if c == j else "**"
        print(f"{mark} C: {c:70s} JP: {j}")


if __name__ == "__main__":
    main()
