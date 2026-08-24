#!/usr/bin/env python3
"""Audit JP EventScript naming contracts against a pokeemerald US source tree.

This tool is intentionally read-only.  It reports source-level naming and
metadata differences; it does not claim that a renamed command is bytecode
compatible without a ROM comparison.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
from collections import Counter
from dataclasses import asdict, dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_US_ROOT = Path("/home/kenny/pokeemerald")

# These entries occur only in the US special table.  They are intentionally
# modelled as insertions rather than candidates to add to JP: adding them to
# data/specials.inc would shift every following JP special ID.
US_ONLY_SPECIALS = (
    (31, "ValidateMixingGameLanguage"),
    (45, "ObjectEventInteractionGetBerryName"),
    (46, "ObjectEventInteractionGetBerryCountString"),
)

MACRO_RE = re.compile(r"^\s*\.macro\s+(\w+)(.*)$")
SPECIAL_RE = re.compile(r"^\s*def_special\s+(\w+)(?:,\s*waitstate=(\d+))?")
OPCODE_HEADER_RE = re.compile(r"\b(SCR_OP_\w+)\s*=\s*0x([0-9A-Fa-f]+)")
OPCODE_TABLE_RE = re.compile(
    r"script_cmd_table_entry\s+(SCR_OP_\w+)\s+\w+\s+@\s+0x([0-9A-Fa-f]+)"
)
SPECIAL_CALL_RE = re.compile(r"^\s*(?:special\s+|specialvar\s+[^,]+,\s+)(\w+)\b")
RAW_VAR_RE = re.compile(
    r"^\s*(?:setvar|copyvar|addvar|subvar|compare|compare_var_to_value|compare_var_to_var)\s+"
    r"(0x4[0-9A-Fa-f]{3})\b"
)
RAW_FLAG_RE = re.compile(
    r"^\s*(?:setflag|clearflag|checkflag|goto_if_set|goto_if_unset|call_if_set|call_if_unset)\s+"
    r"(0x[0-9A-Fa-f]+)\b"
)


@dataclass(frozen=True)
class Special:
    name: str
    waitstate: bool


def parse_macros(path: Path) -> dict[str, str]:
    """Return macro definitions keyed by name, preserving signature and body."""
    result: dict[str, str] = {}
    name: str | None = None
    lines: list[str] = []
    for line in path.read_text(encoding="utf-8").splitlines():
        match = MACRO_RE.match(line)
        if match:
            name = match.group(1)
            lines = [line.strip()]
            continue
        if name is not None:
            lines.append(line.strip())
            if line.strip() == ".endm":
                result[name] = "\n".join(lines)
                name = None
    if name is not None:
        raise ValueError(f"unterminated macro {name} in {path}")
    return result


def macro_report(jp_root: Path, us_root: Path) -> dict[str, object]:
    jp = parse_macros(jp_root / "asm/macros/event.inc")
    us = parse_macros(us_root / "asm/macros/event.inc")
    shared = sorted(jp.keys() & us.keys())
    changed = [name for name in shared if jp[name] != us[name]]
    return {
        "jp_macros": len(jp),
        "us_macros": len(us),
        "shared_macros": len(shared),
        "shared_body_or_signature_differences": changed,
        "jp_only_macros": sorted(jp.keys() - us.keys()),
        "us_only_macros": sorted(us.keys() - jp.keys()),
    }


def parse_specials(path: Path) -> list[Special]:
    return [
        Special(match.group(1), bool(int(match.group(2) or "0")))
        for line in path.read_text(encoding="utf-8").splitlines()
        if (match := SPECIAL_RE.match(line))
    ]


def special_alignment(
    jp: list[Special], us: list[Special], insertions: tuple[tuple[int, str], ...] = US_ONLY_SPECIALS
) -> list[tuple[int, int]]:
    """Map JP special indices to US indices without shifting JP's ABI."""
    mapped: list[tuple[int, int]] = []
    for jp_index in range(len(jp)):
        shift = 0
        for us_index, _name in insertions:
            if jp_index + shift >= us_index:
                shift += 1
        mapped.append((jp_index, jp_index + shift))
    if mapped and mapped[-1][1] >= len(us):
        raise ValueError("US special insertion model exceeds the US special table")
    return mapped


def special_call_sites(root: Path, names: set[str]) -> dict[str, list[dict[str, object]]]:
    """Find calls and whether the next instruction is an explicit waitstate."""
    output = {name: [] for name in names}
    for path in sorted(root.joinpath("data").rglob("*")):
        if path.suffix not in {".s", ".inc"}:
            continue
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
        for index, line in enumerate(lines):
            match = SPECIAL_CALL_RE.match(line)
            if not match or match.group(1) not in output:
                continue
            next_instruction = next(
                (
                    candidate.strip()
                    for candidate in lines[index + 1 :]
                    if candidate.strip() and not candidate.lstrip().startswith("@")
                ),
                "",
            )
            output[match.group(1)].append(
                {
                    "path": path.relative_to(root).as_posix(),
                    "line": index + 1,
                    "next_instruction": next_instruction,
                    "explicit_waitstate": next_instruction.startswith("waitstate"),
                }
            )
    return output


def special_report(jp_root: Path, us_root: Path) -> dict[str, object]:
    jp = parse_specials(jp_root / "data/specials.inc")
    us = parse_specials(us_root / "data/specials.inc")
    for index, name in US_ONLY_SPECIALS:
        if index >= len(us) or us[index].name != name:
            raise ValueError(f"US special insertion changed at index {index}: expected {name}")

    alignment = special_alignment(jp, us)
    aliases: list[dict[str, object]] = []
    waitstate_differences: list[dict[str, object]] = []
    for jp_index, us_index in alignment:
        current = jp[jp_index]
        standard = us[us_index]
        if current.name != standard.name:
            aliases.append(
                {
                    "jp_index": jp_index,
                    "us_index": us_index,
                    "current": current.name,
                    "standard": standard.name,
                }
            )
        if current.waitstate != standard.waitstate:
            waitstate_differences.append(
                {
                    "jp_index": jp_index,
                    "us_index": us_index,
                    "current": current.name,
                    "standard": standard.name,
                    "jp_waitstate": current.waitstate,
                    "us_waitstate": standard.waitstate,
                }
            )

    sites = special_call_sites(jp_root, {item["current"] for item in waitstate_differences})
    for item in waitstate_differences:
        item["call_sites"] = sites[item["current"]]
        item["all_call_sites_explicit_waitstate"] = all(
            site["explicit_waitstate"] for site in sites[item["current"]]
        )
    return {
        "jp_specials": len(jp),
        "us_specials": len(us),
        "us_only_specials": [
            {"us_index": index, "name": name} for index, name in US_ONLY_SPECIALS
        ],
        "aliases": aliases,
        "waitstate_differences": waitstate_differences,
    }


def opcode_report(jp_root: Path) -> dict[str, object]:
    header = {
        match.group(1): int(match.group(2), 16)
        for match in OPCODE_HEADER_RE.finditer(
            (jp_root / "include/constants/script_commands.h").read_text(encoding="utf-8")
        )
    }
    table = {
        match.group(1): int(match.group(2), 16)
        for match in OPCODE_TABLE_RE.finditer(
            (jp_root / "data/script_cmd_table.inc").read_text(encoding="utf-8")
        )
    }
    shared = sorted(header.keys() & table.keys())
    return {
        "header_opcodes": len(header),
        "table_opcodes": len(table),
        "shared_opcodes": len(shared),
        "divergent_values": [
            {"name": name, "header": header[name], "table": table[name]}
            for name in shared
            if header[name] != table[name]
        ],
    }


def constants_report(jp_root: Path, us_root: Path) -> dict[str, object]:
    result: dict[str, object] = {}
    for name in ("vars.h", "flags.h"):
        jp = (jp_root / "include/constants" / name).read_bytes()
        us = (us_root / "include/constants" / name).read_bytes()
        result[name] = {
            "identical": jp == us,
            "jp_sha256": hashlib.sha256(jp).hexdigest(),
            "us_sha256": hashlib.sha256(us).hexdigest(),
        }
    return result


def map_script_report(jp_root: Path, aliases: list[dict[str, object]]) -> dict[str, object]:
    standard_names = {item["current"]: item["standard"] for item in aliases}
    alias_uses: Counter[tuple[str, str]] = Counter()
    raw_vars = 0
    raw_flags = 0
    files = sorted(jp_root.glob("data/maps/*/scripts.inc"))
    for path in files:
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            match = SPECIAL_CALL_RE.match(line)
            if match and match.group(1) in standard_names:
                alias_uses[(match.group(1), standard_names[match.group(1)])] += 1
            raw_vars += bool(RAW_VAR_RE.match(line))
            raw_flags += bool(RAW_FLAG_RE.match(line))
    return {
        "structured_map_scripts": len(files),
        "special_alias_uses": [
            {"current": current, "standard": standard, "uses": count}
            for (current, standard), count in sorted(alias_uses.items())
        ],
        "raw_variable_first_operands": raw_vars,
        "raw_flag_first_operands": raw_flags,
    }


def build_report(jp_root: Path, us_root: Path) -> dict[str, object]:
    macros = macro_report(jp_root, us_root)
    specials = special_report(jp_root, us_root)
    return {
        "inputs": {"jp_root": str(jp_root), "us_root": str(us_root)},
        "macros": macros,
        "specials": specials,
        "opcodes": opcode_report(jp_root),
        "constants": constants_report(jp_root, us_root),
        "maps": map_script_report(jp_root, specials["aliases"]),
    }


def print_summary(report: dict[str, object]) -> None:
    macros = report["macros"]
    specials = report["specials"]
    opcodes = report["opcodes"]
    constants = report["constants"]
    maps = report["maps"]
    print(f"shared EventScript macros: {macros['shared_macros']}")
    print(f"shared macro differences:  {len(macros['shared_body_or_signature_differences'])}")
    print(f"JP-only macros:            {len(macros['jp_only_macros'])}")
    print(f"special aliases to US:      {len(specials['aliases'])}")
    print(f"waitstate differences:      {len(specials['waitstate_differences'])}")
    print(f"opcode header divergences:  {len(opcodes['divergent_values'])}")
    print(f"vars.h identical to US:     {constants['vars.h']['identical']}")
    print(f"flags.h identical to US:    {constants['flags.h']['identical']}")
    print(f"structured map scripts:     {maps['structured_map_scripts']}")
    print(f"map special alias uses:     {sum(item['uses'] for item in maps['special_alias_uses'])}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--jp-root", type=Path, default=ROOT)
    parser.add_argument("--us-root", type=Path, default=DEFAULT_US_ROOT)
    parser.add_argument("--json", action="store_true", help="print the complete report as JSON")
    parser.add_argument("--output", type=Path, help="write the complete JSON report to this path")
    args = parser.parse_args()
    report = build_report(args.jp_root.resolve(), args.us_root.resolve())
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    if args.json:
        print(json.dumps(report, indent=2, sort_keys=True))
    elif not args.output:
        print_summary(report)


if __name__ == "__main__":
    main()
