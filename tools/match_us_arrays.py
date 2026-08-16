#!/usr/bin/env python3
"""Find JP gUnknown tables by matching pokeemerald const u8/u16 arrays.

Scans pokeemerald's const u8/u16 arrays (values may be plain numbers,
object-like macros, function-like macros or designated initializers),
expands them using JP/US constants, and searches the byte sequence in
baserom_jp.gba. Reported matches identify what a JP gUnknown table is.

Usage:
  python3 tools/match_us_arrays.py [--min 4] [--addr 0x...]
"""

import argparse
import glob
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
US = Path("/home/kenny/pokeemerald")

FUNC_MACRO_RE = re.compile(r"#define\s+(\w+)\(([^)]*)\)\s+(.+)")
OBJ_MACRO_RE = re.compile(r"#define\s+(\w+)\s+(.+)")
ENUM_RE = re.compile(r"(?:typedef\s+)?enum\s+\w*\s*\{(.*?)\}\s*\w*\s*;?", re.S)
DESIGN_RE = re.compile(r"\[(.+?)\]\s*=\s*(.+)")


def strip_comments(text):
    """Remove // and /* */ comments while preserving structure."""
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    text = re.sub(r"//[^\n]*", "", text)
    return text


def src_files():
    return (list(glob.glob(str(US / "src" / "*.c")))
            + list(glob.glob(str(US / "src" / "data" / "*.c")))
            + list(glob.glob(str(US / "src" / "data" / "*" / "*.c"))))


def collect_macros():
    """Collect object-like and function-like #defines from JP/US headers and US src."""
    vals, funcs = {}, {}
    files = []
    for base in (ROOT / "include", US / "include"):
        files += glob.glob(str(base / "constants" / "*.h"))
        files += glob.glob(str(base / "*.h"))
    files += src_files()
    for f in files:
        for line in open(f, errors="ignore"):
            m = FUNC_MACRO_RE.match(line)
            if m:
                name, params, body = m.groups()
                funcs[name] = (params, body)
                continue
            m = OBJ_MACRO_RE.match(line)
            if m:
                expr = m.group(2).split("//")[0].split("/*")[0].strip()
                if expr:
                    vals[m.group(1)] = expr
    # expand numeric expressions
    for _ in range(6):
        for name, expr in list(vals.items()):
            if isinstance(expr, int):
                continue
            try:
                vals[name] = eval(expr, {"__builtins__": {}}, vals)
            except Exception:
                pass
    return vals, funcs


def collect_enums(vals):
    """Collect enum and scalar const values from US headers and src files."""
    files = glob.glob(str(US / "include" / "**" / "*.h"), recursive=True)
    files += src_files()
    for f in files:
        text = strip_comments(open(f, errors="ignore").read())
        for m in ENUM_RE.finditer(text):
            val = 0
            for item in m.group(1).split(","):
                item = item.strip()
                if not item:
                    continue
                mm = re.match(r"(\w+)\s*=\s*(.+)", item)
                if mm:
                    name, expr = mm.group(1), mm.group(2)
                    try:
                        val = eval(expr, {"__builtins__": {}}, vals)
                    except Exception:
                        pass
                else:
                    name = item
                vals[name] = val
                val += 1
        for m in re.finditer(
            r"const\s+(?:u8|u16|u32|s8|s16|s32)\s+(\w+)\s*=\s*([^;]+);", text
        ):
            name, expr = m.group(1), m.group(2).strip()
            try:
                vals[name] = eval(expr, {"__builtins__": {}}, vals)
            except Exception:
                pass
    return vals


def split_args(s):
    """Split macro argument list, honoring nested parens."""
    parts, depth, cur = [], 0, []
    for ch in s:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    if cur:
        parts.append("".join(cur).strip())
    return parts


def expand_func_macros(expr, funcs, depth=0):
    """Expand function-like macros in expr until stable (or depth cap)."""
    if depth > 12:
        return expr
    # fast path: skip the whole macro table when no macro name is present
    if not any(name in expr for name in funcs):
        return expr
    changed = False
    for name, (params, body) in funcs.items():
        if name not in expr:
            continue
        pat = re.compile(r"\b" + re.escape(name) + r"\s*\(")
        last, out = 0, []
        for m in pat.finditer(expr):
            i = m.end()
            start, pdepth = i, 1
            while pdepth > 0 and i < len(expr):
                if expr[i] == "(":
                    pdepth += 1
                elif expr[i] == ")":
                    pdepth -= 1
                i += 1
            if pdepth != 0:
                continue
            arg_str = expr[start:i - 1]
            args = split_args(arg_str)
            plist = [p.strip() for p in params.split(",") if p.strip()]
            if len(args) != len(plist):
                continue
            subst = body
            for p, a in zip(plist, args):
                subst = re.sub(r"\b" + re.escape(p) + r"\b", a, subst)
            subst = re.sub(r"\s*##\s*", "", subst)
            out.append(expr[last:m.start()])
            out.append("(" + subst + ")")
            last = i
            changed = True
        if changed:
            expr = "".join(out) + expr[last:]
            break
    if changed:
        return expand_func_macros(expr, funcs, depth + 1)
    return expr


def try_eval(expr, ns):
    expr = re.sub(r"\((?:u8|u16|u32|s8|s16|s32)\)", "", expr)
    return eval(expr, {"__builtins__": {}}, ns)


def expand_arrays(vals, funcs):
    """Parse US const u8/u16 arrays -> list of (file, type, name, bytes)."""
    ns = dict(vals)
    results = []
    for f in src_files():
        text = open(f, errors="ignore").read()
        for m in re.finditer(
            r"const\s+(u8|u16)\s+(\w+)\[([^\]]+)\]\s*=\s*\{(.*?)\};", text, re.S
        ):
            typ, name, size, body = m.groups()
            body = strip_comments(body)
            if "[" in body or "*" in body or "{" in body:
                continue
            entries = []  # (index, value)
            pos = 0
            designated = False
            ok = True
            for tok in body.split(","):
                tok = tok.strip()
                if not tok:
                    continue
                ex = expand_func_macros(tok, funcs)
                dm = DESIGN_RE.match(ex)
                if dm:
                    designated = True
                    idx_s, val_s = dm.groups()
                    try:
                        idx = int(try_eval(idx_s, ns))
                        val = try_eval(val_s, ns)
                        entries.append((idx, val))
                    except Exception:
                        ok = False
                        break
                else:
                    for sub in ex.split(","):
                        sub = sub.strip()
                        if not sub:
                            continue
                        try:
                            entries.append((pos, try_eval(sub, ns)))
                            pos += 1
                        except Exception:
                            ok = False
                            break
                    if not ok:
                        break
            if not ok:
                continue
            try:
                size_n = int(try_eval(size, ns))
            except Exception:
                size_n = None
            if designated:
                arr = [0] * (max(i for i, _ in entries) + 1)
                for i, v in entries:
                    arr[i] = v
            else:
                arr = [v for _, v in entries]
            if size_n is not None:
                if len(arr) < size_n:
                    arr += [0] * (size_n - len(arr))
                elif len(arr) > size_n:
                    arr = arr[:size_n]
            if typ == "u8":
                data = bytes(int(v) & 0xFF for v in arr)
            elif typ == "u16":
                try:
                    data = b"".join(struct.pack("<H", int(v) & 0xFFFF) for v in arr)
                except (ValueError, TypeError):
                    print(f"SKIP {name}: non-numeric element {[v for v in arr if not isinstance(v, int)][:5]}")
                    continue
            else:
                continue
            if len(data) >= 4:
                results.append((Path(f).name, typ, name, data))
    return results


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=int, default=16, help="minimum byte length")
    ap.add_argument("--addr", help="only report matches at this JP address")
    ap.add_argument("--tag-only", action="store_true",
                    help="only report matches that land exactly on a JP gUnknown label")
    ap.add_argument("--max-repeats", type=int, default=8,
                    help="stop scanning a candidate after this many matches")
    args = ap.parse_args()

    rom = (ROOT / "baserom_jp.gba").read_bytes()
    tag_addrs = set()
    if args.tag_only:
        pat = re.compile(r"\.globl\s+(gUnknown_[0-9A-Fa-f]+)")
        for f in glob.glob(str(ROOT / "data" / "*.s")) + glob.glob(str(ROOT / "asm" / "*.s")):
            for line in open(f, errors="ignore"):
                mm = pat.search(line)
                if mm:
                    tag_addrs.add(int(mm.group(1).split("_", 1)[1], 16))
        print(f"JP gUnknown labels: {len(tag_addrs)}")
    vals, funcs = collect_macros()
    vals = collect_enums(vals)
    arrays = expand_arrays(vals, funcs)
    print(f"US arrays expanded: {len(arrays)}")

    found = 0
    common = 0
    for f, typ, name, data in arrays:
        if len(data) < args.min:
            continue
        addrs = []
        idx = 0
        while len(addrs) < args.max_repeats:
            idx = rom.find(data, idx)
            if idx < 0:
                break
            addr = 0x08000000 + idx
            if (args.addr is None or addr == int(args.addr, 16)) and (not args.tag_only or addr in tag_addrs):
                addrs.append(addr)
            idx += 1
        if args.addr is not None and not addrs:
            continue
        if not addrs:
            continue
        found += 1
        if len(addrs) >= args.max_repeats:
            common += 1
            print(f"COMMON {name} ({typ}, {len(data)}B) first 0x{addrs[0]:X} [{f}]")
        else:
            addr_str = " ".join(f"0x{a:X}" for a in addrs)
            print(f"MATCH {name} ({typ}, {len(data)}B) at {addr_str} [{f}]")
    print(f"arrays with matches: {found} (common/repeating: {common})")


if __name__ == "__main__":
    main()
