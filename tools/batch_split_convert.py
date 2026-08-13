#!/usr/bin/env python3
"""split_convert every referenced raw chunk that has a script prefix."""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def main():
    r = subprocess.run([sys.executable, str(ROOT / "tools" / "referenced_candidates.py")],
                       capture_output=True, text=True, cwd=ROOT)
    names = []
    for line in r.stdout.splitlines()[1:]:
        m = re.match(r"^(gUnknown_[0-9A-F]+)\s", line)
        if m:
            names.append(m.group(1))
    ok = 0
    skipped = 0
    for name in names:
        rr = subprocess.run([sys.executable, str(ROOT / "tools" / "split_convert.py"), name],
                            capture_output=True, text=True, cwd=ROOT)
        out = (rr.stdout + rr.stderr).strip()
        if "nothing decodable" in out:
            skipped += 1
            continue
        if rr.returncode == 0 and "wrote" in out:
            ok += 1
        else:
            print("FAIL", name, out[:200])
    print(f"converted {ok}, skipped {skipped}")

if __name__ == "__main__":
    main()
