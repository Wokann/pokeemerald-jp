#!/usr/bin/env python3
"""Extract JP map layout border/blockdata resources from baserom_jp.gba.

In the JP ROM each layout's border (8 bytes) + blockdata (width*height*2
bytes) sits immediately before its layout struct. In data/layouts/layouts.inc
that data was originally mis-attributed to the *previous* entry's incbin:
  - PetalburgCity's border/blockdata is inside the tail incbin of
    gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY
    (0x3B821C, 0x728 -> 0x18 lead + 8 border + 0x708 blockdata)
  - every gMapLayout_<X> incbin is actually the *next* layout's
    border + blockdata

This script:
  - writes data/layouts/<Area>/border.bin and map.bin for every layout
    (Area naming follows pokeemerald's data/layouts/<Area>/ layout)
  - replaces the hardcoded border/map pointers in the layout structs with
    gMapLayout_<NAME>_Border / gMapLayout_<NAME>_Blockdata labels
  - splits the mis-attributed incbins so the ROM byte order is unchanged

Usage:
  python3 tools/extract_map_layouts.py            # extract + rewrite .s
  python3 tools/extract_map_layouts.py --check    # verify only
"""

import argparse
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
S_PATH = ROOT / "data" / "layouts" / "layouts.inc"
OUT_BASE = ROOT / "data" / "layouts"
US_LAYOUTS_JSON = Path("/home/kenny/pokeemerald/data/layouts/layouts.json")

PAT_LAYOUT = re.compile(r"^gMapLayout_(\w+):\s*@\s*0x([0-9A-Fa-f]+)$")
PAT_INC = re.compile(
    r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
)
PAT_PTR = re.compile(r'(\s*\.4byte\s+)0x([0-9A-Fa-f]+)(\s+@\s+(?:border|map))')
PAT_LABEL = re.compile(r"^(\w+)::?$")
PAT_LAYOUT_RESOURCE = re.compile(
    r'\s*\.incbin\s+"(data/layouts/[^"/]+/(?:border|map)\.bin)"\s*$'
)


def to_camel(name):
    return "".join(p.capitalize() for p in name.split("_"))


def load_us_area_names():
    """JP layout suffix -> US area directory name (e.g. PETALBURG_CITY -> PetalburgCity)."""
    names = {}
    if US_LAYOUTS_JSON.exists():
        us = json.loads(US_LAYOUTS_JSON.read_text(encoding="utf-8"))
        for entry in us["layouts"]:
            jp_id = entry["id"].replace("LAYOUT_", "")
            area = entry["name"].replace("_Layout", "")
            names[jp_id] = area
    return names


def parse_layout_resource_labels(lines):
    """Return resource incbins immediately owned by their source labels."""
    resources = {}
    for i, line in enumerate(lines[:-1]):
        label = PAT_LABEL.match(line)
        incbin = PAT_LAYOUT_RESOURCE.match(lines[i + 1])
        if label and incbin:
            resources[label.group(1)] = incbin.group(1)
    return resources


def parse_layouts(lines):
    entries = []
    raw_layouts = []
    for i, line in enumerate(lines):
        m = PAT_LAYOUT.match(line)
        if not m:
            continue
        name = m.group(1)
        addr = int(m.group(2), 16)
        defs = {}
        for j in range(1, 7):
            mm = re.match(r"\s*\.4byte\s+(\S+)\s+@\s+(\w+)", lines[i + j])
            if mm:
                defs[mm.group(2)] = mm.group(1)
        required = {"width", "height", "border", "map"}
        if not required.issubset(defs):
            # This label still owns a raw 0x18-byte MapLayout struct rather than
            # a decomposed layout definition. It is deliberately not treated as
            # an extracted resource pair.
            raw_layouts.append({"name": name, "addr": addr, "idx": i})
            continue

        inc = PAT_INC.match(lines[i + 7] if i + 7 < len(lines) else "")
        border_value = defs["border"]
        map_value = defs["map"]
        expected_border = f"gMapLayout_{name}_Border"
        expected_map = f"gMapLayout_{name}_Blockdata"
        if border_value == expected_border and map_value == expected_map:
            pointer_mode = "named"
            map_size = int(defs["width"]) * int(defs["height"]) * 2
            gap = (-map_size) % 4
            map_ = addr - 0x08000000 - gap - map_size
            border = map_ - 8
        elif border_value.startswith("0x") and map_value.startswith("0x"):
            pointer_mode = "raw"
            border = int(border_value, 16) - 0x08000000
            map_ = int(map_value, 16) - 0x08000000
        else:
            pointer_mode = "invalid"
            border = map_ = None
        entries.append(
            {
                "name": name,
                "addr": addr,
                "w": int(defs["width"]),
                "h": int(defs["height"]),
                "border_off": border,
                "map_off": map_,
                "inc_off": int(inc.group(1), 16) if inc else None,
                "inc_size": int(inc.group(2), 16) if inc else None,
                "idx": i,
                "pointer_mode": pointer_mode,
                "expected_border": expected_border,
                "expected_map": expected_map,
            }
        )
    return entries, raw_layouts


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()
    raw = S_PATH.read_bytes()
    crlf = b"\r\n" in raw
    text = raw.decode("utf-8")
    lines = text.split("\r\n") if crlf else text.split("\n")

    area_names = load_us_area_names()
    entries, raw_layouts = parse_layouts(lines)
    resources = parse_layout_resource_labels(lines)
    print(
        f"layouts: {len(entries) + len(raw_layouts)} "
        f"({len(entries)} structured, {len(raw_layouts)} raw structs)"
    )

    problems = []
    for e in entries:
        if e["pointer_mode"] == "invalid":
            problems.append(
                f"{e['name']}: expected {e['expected_border']} / "
                f"{e['expected_map']} or two raw ROM pointers"
            )
            continue
        if e["map_off"] != e["border_off"] + 8:
            problems.append(f"{e['name']}: border/map gap {e['map_off'] - e['border_off']}")
        exp = e["w"] * e["h"] * 2
        gap = e["addr"] - 0x08000000 - (e["map_off"] + exp)
        if gap not in (0, 2):
            problems.append(
                f"{e['name']}: map end 0x{e['map_off'] + exp:X} != struct "
                f"0x{e['addr'] - 0x08000000:X} (gap {gap})"
            )
        if gap == 2 and rom[e["map_off"] + exp : e["map_off"] + exp + 2] != b"\x00\x00":
            problems.append(f"{e['name']}: non-zero 2-byte gap")
        e["gap"] = gap
        if e["inc_off"] is not None and e["inc_off"] + e["inc_size"] != e["addr"] + 0x18:
            # The layout's own incbin ends at the next struct (addr+0x18 == next layout).
            pass
        if e["pointer_mode"] == "named":
            area = area_names.get(e["name"], to_camel(e["name"]))
            expected_resources = {
                e["expected_border"]: f"data/layouts/{area}/border.bin",
                e["expected_map"]: f"data/layouts/{area}/map.bin",
            }
            for label, expected_path in expected_resources.items():
                actual_path = resources.get(label)
                if actual_path != expected_path:
                    problems.append(
                        f"{e['name']}: {label} owns {actual_path!r}, "
                        f"expected {expected_path!r}"
                    )
                    continue
                path = ROOT / actual_path
                expected_data = (
                    rom[e["border_off"] : e["border_off"] + 8]
                    if label == e["expected_border"]
                    else rom[e["map_off"] : e["map_off"] + e["w"] * e["h"] * 2]
                )
                if not path.is_file():
                    problems.append(f"{e['name']}: missing {actual_path}")
                elif path.read_bytes() != expected_data:
                    problems.append(f"{e['name']}: {actual_path} differs from baserom")
    if problems:
        print("PROBLEMS:")
        for p in problems[:20]:
            print("  ", p)
        sys.exit(1)

    # Map each layout's border_off to the incbin line that contains it.
    inc_lines = []  # (line_idx, off, size)
    for i, line in enumerate(lines):
        m = PAT_INC.match(line)
        if m:
            inc_lines.append((i, int(m.group(1), 16), int(m.group(2), 16)))

    new_lines = list(lines)
    extracted = 0
    verified = 0
    for e in entries:
        if e["pointer_mode"] == "named":
            verified += 1
            continue
        area = area_names.get(e["name"], to_camel(e["name"]))
        out_dir = OUT_BASE / area
        border_data = rom[e["border_off"] : e["border_off"] + 8]
        map_data = rom[e["map_off"] : e["map_off"] + e["w"] * e["h"] * 2]
        if len(border_data) != 8 or len(map_data) != e["w"] * e["h"] * 2:
            problems.append(f"{e['name']}: short ROM read")
            continue
        if not args.check:
            out_dir.mkdir(parents=True, exist_ok=True)
            (out_dir / "border.bin").write_bytes(border_data)
            (out_dir / "map.bin").write_bytes(map_data)
        extracted += 1

        # Replace the hardcoded border/map pointers in the layout struct.
        for j in range(1, 5):
            mm = PAT_PTR.match(new_lines[e["idx"] + j])
            if mm:
                ptr = int(mm.group(2), 16)
                if ptr == e["border_off"] + 0x08000000:
                    new_lines[e["idx"] + j] = (
                        f"{mm.group(1)}gMapLayout_{e['name']}_Border{mm.group(3)}"
                    )
                elif ptr == e["map_off"] + 0x08000000:
                    new_lines[e["idx"] + j] = (
                        f"{mm.group(1)}gMapLayout_{e['name']}_Blockdata{mm.group(3)}"
                    )

        # Split the incbin that contains this layout's border/blockdata.
        for il_idx, (inc_line_idx, inc_off, inc_size) in enumerate(inc_lines):
            if inc_off <= e["border_off"] < inc_off + inc_size:
                lead = e["border_off"] - inc_off
                pad = (
                    "\n\t.byte 0x00, 0x00"
                    if e.get("gap") == 2
                    else ""
                )
                block = (
                    f'\t.incbin "data/layouts/{area}/border.bin"'
                    f"\n"
                    f"gMapLayout_{e['name']}_Blockdata:"
                    f"\n"
                    f'\t.incbin "data/layouts/{area}/map.bin"'
                    f"{pad}"
                )
                if lead > 0:
                    replacement = (
                        f'\t.incbin "baserom_jp.gba", 0x{inc_off:X}, 0x{lead:X}'
                        f"\n"
                        f"gMapLayout_{e['name']}_Border:"
                        f"\n"
                        f"{block}"
                    )
                else:
                    replacement = (
                        f"gMapLayout_{e['name']}_Border:"
                        f"\n"
                        f"{block}"
                    )
                new_lines[inc_line_idx] = replacement
                # Mark this incbin as consumed so two layouts don't reuse it.
                inc_lines[il_idx] = (inc_line_idx, -1, -1)
                break
        else:
            problems.append(f"{e['name']}: border 0x{e['border_off']:X} not covered by any incbin")

    if problems:
        print("PROBLEMS:")
        for p in problems[:20]:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        out = "\r\n".join(new_lines) if crlf else "\n".join(new_lines)
        S_PATH.write_bytes(out.encode("utf-8"))
    if args.check:
        print(
            f"Check: {verified} named resource layouts, {extracted} raw-pointer layouts, "
            f"{len(raw_layouts)} raw layout structs"
        )
    else:
        print(
            f"Extracted: {extracted} raw-pointer layouts; "
            f"verified {verified} named resource layouts -> {OUT_BASE}"
        )


if __name__ == "__main__":
    main()
