#!/usr/bin/env python3
"""Trim asm/match_call.s to the functions still in asm (sub_08196294+)."""


def main():
    with open("asm/match_call.s", encoding="utf-8", errors="replace") as f:
        lines = f.readlines()
    # Keep the header (includes) and the remainder starting at sub_08196294.
    start = None
    for i, line in enumerate(lines):
        if line.startswith(".include"):
            start = i
        if "thumb_func_start sub_08196294" in line:
            split = i
            break
    out = lines[:start + 1] + [".text\n", ".syntax unified\n", "\n"] + lines[split:]
    with open("asm/match_call.s", "w", encoding="utf-8", newline="") as f:
        f.writelines(out)
    print(f"trimmed to {len(out)} lines (was {len(lines)})")


if __name__ == "__main__":
    main()
