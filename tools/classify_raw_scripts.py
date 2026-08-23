#!/usr/bin/env python3
"""Reclassify raw .incbin chunks as real scripts vs data.

A chunk is a strong script candidate when most decoded instructions are
named macros and its control-flow targets (goto/call/goto_if/call_if)
land inside the JP script region or on known labels.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import decompile_scripts as d

SCRIPT_START = 0x081DABAC
SCRIPT_END = 0x0828D2F8

def main():
    if not d.BASEROM.is_file():
        sys.exit(f"missing {d.BASEROM}; obtain the matching Japanese baserom first")
    data = d.BASEROM.read_bytes()
    opcode_table = d.build_opcode_table()
    by_name = {const: op for const, op in opcode_table.items()}
    formats, formats_by_name = d.build_macro_formats(by_name)
    specials = d.build_specials_map()

    ctrl_re = re.compile(
        r"^\s*(goto|goto_if|call|call_if|gotostd|callstd|goto_if_set|"
        r"goto_if_unset|goto_if_equal|goto_if_not_equal|"
        r"goto_if_ge|goto_if_gt|goto_if_le|goto_if_lt)\b")
    addr_re = re.compile(r"0x([0-9A-Fa-f]{7,8})\b")

    script_like = []
    data_like = []
    for path in sorted((d.SCRIPTS_DIR).glob("gUnknown_*.inc")):
        text = path.read_text(encoding="utf-8")
        if ".incbin" not in text:
            continue  # already decoded or mixed
        m = re.search(r'\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)', text)
        if not m:
            continue
        rel = int(m.group(1), 16)
        size = int(m.group(2), 16)
        # .incbin offsets are offsets in baserom_jp.gba, not offsets relative
        # to the event-script region.  The old subtraction silently examined
        # unrelated bytes even when the expected build/data.bin was present.
        raw = data[rel: rel + size]
        dec = d.decode_chunk(raw, formats, specials)
        lines = [l for l in dec.splitlines() if l.strip()]
        if not lines:
            data_like.append((path.stem, 0, 0, size))
            continue
        raw_bytes = sum(1 for l in lines if l.strip().startswith(".byte"))
        ratio = 1 - raw_bytes / len(lines)
        ctrl = 0
        in_script_targets = 0
        total_targets = 0
        bad = 0
        for l in lines:
            if ctrl_re.match(l):
                ctrl += 1
                for am in addr_re.finditer(l):
                    a = int(am.group(1), 16)
                    total_targets += 1
                    if SCRIPT_START <= a <= SCRIPT_END:
                        in_script_targets += 1
            else:
                for am in addr_re.finditer(l):
                    a = int(am.group(1), 16)
                    if a > 0x04000000 and not (0x08000000 <= a <= 0x09FFFFFF):
                        bad += 1
        if (ctrl > 0 and in_script_targets > 0 and ratio >= 0.7
                and bad <= 1):
            script_like.append((path.stem, size, ratio, ctrl, in_script_targets, total_targets))
        else:
            data_like.append((path.stem, size, ratio, ctrl, in_script_targets, total_targets))

    print(f"script-like: {len(script_like)}, data-like: {len(data_like)}")
    print("\n=== SCRIPT-LIKE (candidates to decode) ===")
    for name, size, ratio, ctrl, ins, tot in sorted(script_like, key=lambda x: -x[2]):
        print(f"{name}: 0x{size:X}B ratio={ratio:.2f} ctrl={ctrl} inScript={ins}/{tot}")

if __name__ == "__main__":
    main()
