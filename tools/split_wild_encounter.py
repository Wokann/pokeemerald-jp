#!/usr/bin/env python3
"""Extract StandardWildEncounter from the original asm into its own file."""

import subprocess


def main():
    out = subprocess.run(
        ["git", "show", "HEAD:asm/wild_encounter.s"],
        capture_output=True,
        text=True,
    ).stdout
    lines = out.splitlines(keepends=True)
    header = [l for l in lines if l.startswith(".include") or l.startswith(".text") or l.startswith(".syntax")]
    start = None
    end = None
    for i, line in enumerate(lines):
        if "thumb_func_start StandardWildEncounter" in line:
            start = i
        if start is not None and i > start and "thumb_func_end StandardWildEncounter" in line:
            end = i + 1
            break
    if start is None or end is None:
        raise SystemExit("StandardWildEncounter not found")
    with open("asm/wild_encounter_std.s", "w", encoding="utf-8", newline="") as f:
        f.writelines(header)
        f.write("\n")
        f.writelines(lines[start:end])
    print(f"extracted {end - start} lines")


if __name__ == "__main__":
    main()
