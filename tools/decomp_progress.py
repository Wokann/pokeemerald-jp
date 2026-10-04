#!/usr/bin/env python3
"""Inventory C source definitions and standalone asm in pokeemerald-jp.

Compares the src/ function-definition inventory of pokeemerald-jp against
pokeemerald's src/ per relative module path, and reports the remaining JP
functions still stored in standalone asm files.

The historical regex inventory is retained for compatibility, explicitly as
``legacy_source_inventory`` with unit ``source-name``.  It omits most naked
bodies but can include separate NAKED macro lines/inactive branches and miss
other C signatures; its ratio is NOT a ROM completion percentage.  The new
default-branch inventory uses the shared structural-audit parser.

Source-only mode does not read ELF/map/objects or require baserom.  Optional
``--linked`` address metrics use actual JP ELF/map/object evidence, keeping
inline non-emission and unresolved definitions separate.  Sample these build
artifacts under the shared build lock, after a byte-exact compare.

Usage:
    python3 tools/decomp_progress.py --us-root /home/kenny/pokeemerald
    flock /tmp/pokeemerald-jp-build.lock python3 tools/decomp_progress.py --linked --json
"""

import argparse
import json
import re
from pathlib import Path

try:
    import audit_structure as audit
except ModuleNotFoundError:
    from tools import audit_structure as audit

ROOT = Path(__file__).resolve().parents[1]
US_SRC = audit.DEFAULT_US_ROOT / "src"
JP_ASM = ROOT / "asm"
JP_SRC = ROOT / "src"

FUNC_DEF_RE = re.compile(
    r"^(?:static\s+)?(?:const\s+)?"
    r"(?:u8|u16|u32|s8|s16|s32|bool8|bool16|void|int|\w+)\s+"
    r"(?:UNUSED\s+)?\*?\s*"
    r"([A-Za-z_]\w*)\s*\(",
    re.MULTILINE,
)
ASM_FUNC_RE = re.compile(r"^\s*thumb_func_start\s+(\w+)\s*$")


def _find_closing_paren(text, start):
    """Return the position after the parenthesis opened at start, if balanced."""
    depth = 0
    for pos in range(start, len(text)):
        if text[pos] == "(":
            depth += 1
        elif text[pos] == ")":
            depth -= 1
            if depth == 0:
                return pos + 1
    return None


def _skip_trailing_attributes(text, pos):
    """Skip GNU attributes placed between a function parameter list and body."""
    while True:
        while pos < len(text) and text[pos].isspace():
            pos += 1
        if not text.startswith("__attribute__", pos):
            return pos
        open_paren = text.find("(", pos + len("__attribute__"))
        if open_paren == -1:
            return len(text)
        pos = _find_closing_paren(text, open_paren)
        if pos is None:
            return len(text)


def c_functions(path):
    funcs = set()
    text = path.read_text(encoding="utf-8")
    for m in FUNC_DEF_RE.finditer(text):
        name = m.group(1)
        end = _find_closing_paren(text, m.end() - 1)
        if end is None:
            continue
        end = _skip_trailing_attributes(text, end)
        # The former name-only regex also counted forward declarations.  A
        # function contributes to this legacy inventory only when this source
        # file supplies a body; this also prevents a naked-function prototype
        # from inflating the C count.
        if (end < len(text)
                and text[end] == "{"
                and name not in ("if", "for", "while", "switch", "sizeof")):
            funcs.add(name)
    return funcs


def c_modules(root):
    """Return definitions keyed by full path below src/, not basename alone."""
    return {
        path.relative_to(root).with_suffix("").as_posix(): c_functions(path)
        for path in sorted(root.glob("**/*.c"))
    }


def jp_asm_functions():
    funcs = set()
    for path in JP_ASM.glob("*.s"):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = ASM_FUNC_RE.match(line)
            if m:
                funcs.add(m.group(1))
    return funcs


def inventory_report(root, us_root, *, linked=False):
    """Return deterministic, separate source-name and JP-address inventories."""
    if not (us_root / "src").is_dir():
        raise ValueError("US source root is missing src/: %s" % us_root)
    jp_c = c_modules(root / "src")
    us_c = c_modules(us_root / "src")
    # Preserve the old shallow thumb-only, globally name-deduplicated count.
    old_asm = set()
    for path in sorted((root / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            match = ASM_FUNC_RE.match(line)
            if match:
                old_asm.add(match.group(1))
    total_jp = sum(len(values) for values in jp_c.values())
    total_us = sum(len(values) for values in us_c.values())
    denominator = total_jp + len(old_asm)
    definitions = audit.c_inventory(root)
    standalone = audit.standalone_asm_inventory(root)
    source = {
        "unit": "default-branch source definition; not ROM addresses",
        "non_naked": sum(not item.naked for item in definitions),
        "naked": sum(item.naked for item in definitions),
        "inline": sum(item.inline for item in definitions),
        "standalone_asm": len(standalone),
        "standalone_asm_unit": "(source owner, name, instruction set)",
        "name_macro_headers": dict(sorted(dict(item for definition in definitions for item in definition.name_inputs).items())),
        "unverified_function_macros": sorted({f"{item.path}:{item.declared_name}"
                                               for item in definitions if not item.macro_verified}),
        "bound": None, "inline_not_emitted": None, "unresolved_emitted_or_unknown": None,
    }
    address = {"metric_status": "not_requested", "strict_c_rate": None}
    if linked:
        entries, _total = audit.parse_funcmap(root / "funcmap_jp.txt") if (root / "funcmap_jp.txt").is_file() else ([], 0)
        evidence, metadata = audit.linked_function_evidence(root, definitions)
        resolved, multiple = audit.resolve_funcmap_entries(definitions, entries, evidence)
        address = audit.function_binding_inventory(definitions, entries, evidence, metadata, resolved, multiple)
        source.update({"bound": address["bound_c_definitions"],
                       "inline_not_emitted": len(address["inline_not_emitted_definitions"]),
                       "unresolved_emitted_or_unknown": len(address["unresolved_emitted_or_unknown_bindings"])})
    return {
        "schema": 1, "roots": {"jp": str(root), "us": str(us_root)},
        "legacy_source_inventory": {
            "unit": "source-name", "status": "legacy_regex_inventory_not_rom_completion",
            "jp_c_definitions": total_jp, "us_c_definitions": total_us,
            "standalone_jp_asm_functions": len(old_asm), "numerator": total_jp,
            "denominator": denominator, "rate": total_jp / max(denominator, 1),
        },
        "default_source_inventory": source,
        "standalone_asm_definitions": standalone,
        "jp_address_metrics": address,
        "modules": [{"module": name, "jp": len(jp_c.get(name, set())), "us": len(us_c.get(name, set()))}
                    for name in sorted(set(jp_c) | set(us_c))],
    }


def main():
    # Relative paths keep src/foo.c distinct from src/data/foo.c and
    # src/libc/foo.c, which basename-only accounting previously merged.
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--us-root", type=Path, default=US_SRC.parent)
    parser.add_argument("--json", action="store_true", help="print deterministic inventories with explicit units")
    parser.add_argument("--linked", action="store_true", help="read optional JP ELF/map/objects under the shared build lock")
    args = parser.parse_args()
    if not (args.us_root / "src").is_dir():
        parser.error("US source root is missing src/: %s" % args.us_root)
    report = inventory_report(ROOT, args.us_root.resolve(), linked=args.linked)
    if args.json:
        print(json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True))
        return

    print("Legacy regex inventory below: source-name units, NOT ROM completion.")
    print(f"{'module':<36} {'JP C':>5} {'US C':>6}")
    for row in report["modules"]:
        if row["jp"]:
            print(f"{row['module']:<36} {row['jp']:>5} {row['us']:>6}")
    legacy = report["legacy_source_inventory"]
    total_jp, total_us = legacy["jp_c_definitions"], legacy["us_c_definitions"]
    print(f"{'TOTAL':<36} {total_jp:>5} {total_us:>6}")
    source = report["default_source_inventory"]
    print(f"\nDefault-branch source definitions: non-naked={source['non_naked']}, naked={source['naked']}, inline={source['inline']}")
    print(f"Standalone asm owner/name definitions: {source['standalone_asm']} (not ROM addresses)")
    print(f"Linked definitions: {source['bound']}; inline_not_emitted: {source['inline_not_emitted']}; other unresolved: {source['unresolved_emitted_or_unknown']}")
    address = report["jp_address_metrics"]
    print(f"Strict JP ROM C rate: {audit.percentage(address['strict_c_rate'])}; evidence={address['metric_status']}")
    print(f"\nStandalone JP asm functions: {legacy['standalone_jp_asm_functions']}")
    print(f"C source definitions:         {total_jp}")
    print(f"C source inventory:           {total_jp}/{legacy['denominator']} = {legacy['rate']:.2%} [legacy_source_inventory; source-name; NOT ROM completion]")


if __name__ == "__main__":
    main()
