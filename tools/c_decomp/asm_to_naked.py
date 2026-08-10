#!/usr/bin/env python3
"""Convert a JP asm function body into a naked-C __asm__ string."""
import sys


def main():
    func = sys.argv[1]
    asm_file = sys.argv[2] if len(sys.argv) > 2 else "/tmp/text_jp.s"
    lines = open(asm_file).read().splitlines()
    out = []
    in_func = False
    for line in lines:
        if line.strip() == f"thumb_func_start {func}":
            in_func = True
            continue
        if in_func and line.strip() == f"thumb_func_end {func}":
            break
        if not in_func:
            continue
        s = line.strip()
        if not s or s.startswith("@"):
            continue
        # skip the function label line itself
        if s == f"{func}: @ 0x08000000" or s.startswith(func + ": @"):
            continue
        out.append(s)
    # emit as C string
    print(f"__attribute__((naked)) void {func}(void)")
    print("{")
    print('    __asm__(".code 16\\n\\t"')
    for i, s in enumerate(out):
        esc = s.replace('"', '\\"').replace("\\", "\\\\")
        end = '\\n\\t"' if i < len(out) - 1 else '");'
        print(f'            "{esc}{end}')
    print("}")


if __name__ == "__main__":
    main()
