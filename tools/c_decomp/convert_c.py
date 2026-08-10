#!/usr/bin/env python3
"""Compile a C function with the pret agbcc toolchain, compare its code
bytes with the JP ROM, and print the assembly snippet to inline.

Usage:
    python3 tools/c_decomp/convert_c.py <function-name> <c-file>
    python3 tools/c_decomp/convert_c.py -f <function-name> <c-file>

With -f, the C file may contain several functions (matching pokeemerald
src layout); the named function's bytes are extracted from the object
via arm-none-eabi-nm -S and compared against the JP ROM.

The JP function address is read from the asm label comment.  Absolute
address literals (ROM, EWRAM/IWRAM) and Thumb bl immediates are masked
before comparison: they resolve at link time.  On success the tool
prints the .s snippet with the literal replaced by the JP value, ready
to paste into the asm file.
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
AGBCC = ROOT.parent / "pokeemerald" / "tools" / "agbcc" / "bin" / "agbcc"
AS = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-as"
OBJCOPY = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-objcopy"
NM = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-nm"
JP_ROM = ROOT / "baserom_jp.gba"
JP_ROM_BYTES = JP_ROM.read_bytes()
FUNCMAP = ROOT / "funcmap_jp.txt"


def find_jp_addr(name):
    """Return the JP ROM address for an asm function label, or None."""
    # Prefer funcmap_jp.txt: its third column is maintained against the
    # pokeemerald names, so it stays correct even when the JP asm still
    # carries a differently-named label at the same address (e.g. the
    # safari_zone flag helpers whose JP labels and US names are swapped).
    for line in FUNCMAP.read_text(encoding="utf-8").splitlines():
        m = re.match(rf"^([0-9A-Fa-f]{{8}})\s+\S+\s+{re.escape(name)}\s*$", line)
        if m:
            return int(m.group(1), 16)
    # Fall back to asm labels for functions not yet listed in funcmap.
    for path in sorted((ROOT / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = re.match(rf"^{name}:\s*@\s*0x([0-9A-Fa-f]+)\s*$", line)
            if m:
                return int(m.group(1), 16)
    return None


def compile_c(c_file, out_prefix="/tmp/cv"):
    """Preprocess + compile a C file with the pret toolchain.

    Returns (asm_text, obj_path).  Raises SystemExit with the compiler
    stderr when the pipeline fails to produce assembly.
    """
    proc = subprocess.run(
        "cpp -P -nostdinc -undef -iquote include "
        "-I ../pokeemerald/tools/agbcc/include -I ../pokeemerald/tools/agbcc "
        "-Wno-trigraphs -std=gnu89 -x c {c} | {agbcc} -mthumb-interwork -O2 "
        "-fhex-asm -o {out}.s -".format(c=c_file, agbcc=AGBCC, out=out_prefix),
        shell=True,
        cwd=ROOT,
        capture_output=True,
        text=True,
    )
    asm_path = Path(out_prefix + ".s")
    if proc.returncode != 0 and not asm_path.is_file():
        sys.exit(proc.stderr)
    asm_text = asm_path.read_text()
    subprocess.run(
        [str(AS), "-mcpu=arm7tdmi", "-o", out_prefix + ".o", asm_path],
        check=True,
    )
    return asm_text, out_prefix + ".o"


def object_functions(obj_path):
    """Return {name: (offset, size)} for every defined code symbol."""
    nm = subprocess.run(
        [str(NM), "-S", obj_path], capture_output=True, text=True
    ).stdout
    funcs = {}
    for line in nm.splitlines():
        parts = line.split()
        if len(parts) >= 4 and parts[2] in ("T", "t", "W", "w"):
            funcs[parts[3]] = (int(parts[0], 16), int(parts[1], 16))
    return funcs


def extract_function(obj_path, name):
    """Slice a function's bytes out of the object's .text section."""
    funcs = object_functions(obj_path)
    if name not in funcs:
        return None
    off, size = funcs[name]
    subprocess.run(
        [str(OBJCOPY), "-O", "binary", "--only-section=.text",
         obj_path, obj_path + ".bin"],
        check=True,
    )
    whole = Path(obj_path + ".bin").read_bytes()
    return whole[off : off + size]


def mask(b):
    """Zero out link-time-resolved data: Thumb bl immediates and
    absolute-address literal pool words (ROM, EWRAM/IWRAM)."""
    out = bytearray(b)
    for i in range(0, len(out) - 3, 2):
        hw1 = out[i] | (out[i + 1] << 8)
        hw2 = out[i + 2] | (out[i + 3] << 8)
        if (hw1 & 0xF800) == 0xF000 and (hw2 & 0xF800) == 0xF800:
            out[i] = 0xF0
            out[i + 1] = 0x00
            out[i + 2] = 0xF8
            out[i + 3] = 0x00
    for i in range(0, len(out) - 3, 4):
        v = int.from_bytes(out[i : i + 4], "little")
        if 0x02000000 <= v < 0x04000000 or 0x08000000 <= v <= 0x09FFFFFF:
            out[i : i + 4] = b"\x00\x00\x00\x00"
    return bytes(out)


def strip_trailing(b, pool=()):
    """Drop nop/zero padding that differs only in alignment.
    Bytes belonging to literal-pool words are never trimmed."""
    pool = set(pool)
    out = bytearray(b)
    while len(out):
        if len(out) >= 2 and out[-2:] == b"\xc0\x46":
            del out[-2:]
            continue
        if out[-1] == 0x00 and (len(out) - 1) not in pool:
            # Trim a trailing zero only as part of a zero padding run.
            if len(out) >= 2 and out[-2] == 0x00 and (len(out) - 2) not in pool:
                out.pop()
                continue
        break
    return bytes(out)


def bl_positions(b):
    """Offsets (from function start) of Thumb bl instructions."""
    pos = set()
    for i in range(0, len(b) - 3, 2):
        hw1 = b[i] | (b[i + 1] << 8)
        hw2 = b[i + 2] | (b[i + 3] << 8)
        if (hw1 & 0xF800) == 0xF000 and (hw2 & 0xF800) == 0xF800:
            pos.add(i)
    return pos


def literal_pool_offsets(b):
    """Offsets of 4-byte words loaded via ldr rX, [pc, #imm]."""
    offs = set()
    for i in range(0, len(b) - 3, 2):
        hw = b[i] | (b[i + 1] << 8)
        if (hw & 0xF800) == 0x4800:  # ldr r0-r7, [pc, #imm8*4]
            imm = (hw & 0xFF) * 4
            pc = (i + 4) & ~3
            offs.add(pc + imm)
        elif (hw & 0xF9FF) == 0xF8DF:  # Thumb-2 ldr (literal), U=0 or U=1
            hw2 = b[i + 2] | (b[i + 3] << 8)
            imm12 = hw2 & 0xFFF
            pc = (i + 4) & ~3
            offs.add(pc + imm12)
    return offs


def byte_compare(compiled, jp):
    """Strict byte compare that only tolerates literal-pool words and
    bl targets (both resolved at link time, not in a standalone object).
    Bl instruction *positions* must still match exactly."""
    pool = literal_pool_offsets(compiled)
    pool_bytes = set()
    for off in pool:
        pool_bytes.update(range(off, off + 4))
    c = strip_trailing(compiled, pool_bytes)
    j = strip_trailing(jp, pool_bytes)
    if len(c) != len(j):
        return False
    if bl_positions(c) != bl_positions(j):
        return False
    bls = bl_positions(c)
    n = len(c)
    for i in range(0, n, 2):
        # Skip both halfwords of a bl (i is the high halfword start).
        if i in pool_bytes or i in bls or (i - 2) in bls:
            continue
        if c[i : i + 2] != j[i : i + 2]:
            return False
    for off in pool:
        if off + 4 > n:
            continue
        cv = int.from_bytes(c[off : off + 4], "little")
        jv = int.from_bytes(j[off : off + 4], "little")
        if cv == jv:
            continue
        # Standalone object holds only the reloc addend (0 or small);
        # the JP ROM holds the resolved absolute address.
        if not (cv < 0x10000 and 0x02000000 <= jv < 0x0A000000):
            return False
    return True


def verify_function(name, c_file, jp_name=None):
    """Compile c_file and byte-compare one named function against the
    JP ROM.  Returns a dict with ok/addr/compiled/jp/literal."""
    jp_name = jp_name or name
    jp_addr = find_jp_addr(jp_name)
    if jp_addr is None:
        return {"ok": False, "error": f"no asm label for {jp_name}"}
    asm_text, obj_path = compile_c(c_file)
    compiled = extract_function(obj_path, name)
    if compiled is None:
        return {"ok": False, "error": f"{name}: symbol not in compiled object"}
    jp_bytes = JP_ROM_BYTES[(jp_addr & 0xFFFFFF) : (jp_addr & 0xFFFFFF) + len(compiled)]
    ok = byte_compare(compiled, jp_bytes)
    has_literal = bool(re.search(r"\.word\s+\S+\s*$", asm_text, re.M))
    literal = None
    if has_literal and len(jp_bytes) >= 4:
        literal = int.from_bytes(jp_bytes[len(compiled) - 4 : len(compiled)], "little")
    return {
        "ok": ok,
        "addr": jp_addr,
        "compiled": compiled,
        "jp": jp_bytes,
        "literal": literal,
        "asm": asm_text,
        "error": None,
    }


def verify_c_file(c_file):
    """Compile a C file once and byte-compare every defined function."""
    results = []
    asm_text, obj_path = compile_c(c_file)
    for name, (off, size) in sorted(object_functions(obj_path).items()):
        res = verify_function(name, c_file)
        res["name"] = name
        results.append(res)
    return results


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    use_func_extract = False
    args = sys.argv[1:]
    if args and args[0] == "-f":
        use_func_extract = True
        args = args[1:]
    name, c_file = args[0], Path(args[1])
    jp_name = args[2] if len(args) > 2 else name

    res = verify_function(name, c_file, jp_name)
    if res.get("error"):
        sys.exit(res["error"])
    compiled, jp_bytes = res["compiled"], res["jp"]
    print(f"{name}: JP 0x{res['addr']:08X} compiled {len(compiled)} bytes "
          f"{'MATCH' if res['ok'] else 'DIFF'}")
    print("  compiled:", compiled.hex(" "))
    print("  jp:      ", jp_bytes.hex(" "))
    if not res["ok"]:
        print("  (code bytes differ; adjust the C source)")
        sys.exit(1)
    if res["literal"] is not None:
        print(f"  literal: 0x{res['literal']:08X} (resolve via sym file / rename in .s)")
    if not use_func_extract:
        print("--- snippet ---")
        print(res["asm"])


if __name__ == "__main__":
    main()
