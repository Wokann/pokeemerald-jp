#!/usr/bin/env python3
"""Audit the canonical EventScript Special-table ownership.

``data/specials.inc`` is the one authoritative table: it defines the order
and waitstate metadata consumed by EventScript macros.  This audit reports
legacy generated constants files and build references, rather than generating
another copy of those values.
"""

from __future__ import annotations

import argparse
import json
import re
from collections import Counter, defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
US_ROOT_CANDIDATES = (ROOT.parent / "pokeemerald", ROOT.parent.parent / "pokeemerald")
DEFAULT_US_ROOT = next((path for path in US_ROOT_CANDIDATES if (path / "src").is_dir()),
                       US_ROOT_CANDIDATES[0])
CANONICAL_TABLE = Path("data/specials.inc")
LEGACY_CONSTANTS = Path("constants/specials_constants.inc")
LEGACY_GENERATORS = (Path("tools/gen_special_constants.py"),)
SPECIAL_RE = re.compile(r"^\s*def_special\s+([A-Za-z_]\w*)\b")
SUB_SPECIAL_RE = re.compile(r"^sub_(08[0-9A-Fa-f]{6})$")
SPECIAL_ALIAS_RE = re.compile(
    r"^\s*\.set\s+(SPECIAL(?:_WAITSTATE)?_[A-Za-z_]\w*)\s*,\s*"
    r"SPECIAL(?:_WAITSTATE)?_(sub_08[0-9A-Fa-f]{6})\s*$")
FUNCMAP_ADDRESS_RE = re.compile(r"^[0-9A-Fa-f]{8}$")
SPECIAL_CALL_RE = re.compile(r"^\s*(?:special|specialvar)\b(.*)$")
IDENTIFIER_RE = re.compile(r"\b([A-Za-z_]\w*)\b")
ASM_LABEL_RE = re.compile(r"^\s*([A-Za-z_]\w*)::?\s*(?:@.*)?$", re.MULTILINE)
SOURCE_SUFFIXES = {".c", ".h", ".inc", ".py", ".s", ".txt"}


def tracked_source_paths(root: Path) -> list[Path]:
    """Return deterministic build/tool source candidates, never generated output."""
    paths = []
    for directory in ("asm", "constants", "data", "src", "tools"):
        base = root / directory
        if base.is_dir():
            paths.extend(path for path in base.glob("**/*")
                         if path.is_file() and path.suffix in SOURCE_SUFFIXES)
    makefile = root / "Makefile"
    if makefile.is_file():
        paths.append(makefile)
    return sorted(set(paths))


def reference_sites(root: Path, needle: str) -> list[str]:
    """Return file:line sites that mention one table path."""
    sites = []
    for path in tracked_source_paths(root):
        relative = path.relative_to(root).as_posix()
        if relative in {"tools/audit_special_table.py", "tools/test_audit_special_table.py"}:
            continue
        for line_number, line in enumerate(path.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
            if needle in line:
                sites.append(f"{relative}:{line_number}")
    return sites


def special_names(root: Path) -> list[str]:
    path = root / CANONICAL_TABLE
    if not path.is_file():
        return []
    return [match.group(1) for line in path.read_text(encoding="utf-8", errors="replace").splitlines()
            if (match := SPECIAL_RE.match(line))]


def special_aliases(root: Path) -> dict[str, list[str]]:
    """Return named SPECIAL aliases while retaining their raw table targets."""
    aliases: dict[str, list[str]] = defaultdict(list)
    path = root / CANONICAL_TABLE
    if not path.is_file():
        return aliases
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if match := SPECIAL_ALIAS_RE.match(line):
            aliases[match.group(2)].append(match.group(1))
    return {name: sorted(names) for name, names in aliases.items()}


def parse_funcmap(root: Path) -> dict[int, list[dict[str, str | None]]]:
    """Return address-keyed funcmap rows without conflating same-name symbols.

    ``funcmap_jp.txt`` accepts both ``addr symbol standard`` and
    ``addr source.s symbol [standard]`` rows.  Special placeholders encode
    their JP address, so address is the reproducible join key.
    """
    path = root / "funcmap_jp.txt"
    entries: dict[int, list[dict[str, str | None]]] = defaultdict(list)
    if not path.is_file():
        return entries
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        fields = line.split()
        if len(fields) < 2 or not FUNCMAP_ADDRESS_RE.fullmatch(fields[0]):
            continue
        address = int(fields[0], 16)
        source = None
        if len(fields) >= 3 and Path(fields[1]).suffix in SOURCE_SUFFIXES:
            source, current = fields[1], fields[2]
            standard = fields[3] if len(fields) >= 4 else current
        else:
            current = fields[1]
            standard = fields[2] if len(fields) >= 3 else current
        entries[address].append({"source_owner": source, "current": current,
                                 "standard": standard})
    return entries


def explicit_special_calls(root: Path, names: set[str]) -> dict[str, list[str]]:
    """Find explicit EventScript Special invocations, excluding table entries."""
    calls: dict[str, list[str]] = {name: [] for name in names}
    for path in tracked_source_paths(root):
        if path.suffix not in {".s", ".inc"}:
            continue
        relative = path.relative_to(root).as_posix()
        for line_number, line in enumerate(path.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
            match = SPECIAL_CALL_RE.match(line.split("@", 1)[0])
            if not match:
                continue
            identifiers = IDENTIFIER_RE.findall(match.group(1))
            if identifiers and identifiers[-1] in calls:
                calls[identifiers[-1]].append(f"{relative}:{line_number}")
    return calls


def function_definition_owners(root: Path, names: set[str]) -> dict[str, list[str]]:
    """Find source-file owners for already named C or assembly definitions."""
    owners: dict[str, list[str]] = {name: [] for name in names}
    if not names:
        return owners
    alternatives = "|".join(re.escape(name) for name in sorted(names, key=len, reverse=True))
    c_definition = re.compile(r"\b(" + alternatives + r")\s*\([^;{}]*\)\s*\{", re.MULTILINE)
    for directory, suffix in ((root / "src", ".c"), (root / "asm", ".s")):
        if not directory.is_dir():
            continue
        for path in sorted(directory.rglob("*" + suffix)):
            relative = path.relative_to(root).as_posix()
            text = path.read_text(encoding="utf-8", errors="replace")
            matches = c_definition.findall(text) if suffix == ".c" else ASM_LABEL_RE.findall(text)
            for name in matches:
                if name in owners:
                    owners[name].append(relative)
    return {name: sorted(set(paths)) for name, paths in owners.items()}


def safe_rename_batches(records: list[dict[str, object]]) -> list[dict[str, object]]:
    """Group only adjacent, same-family direct renames into safe batches."""
    batches = []
    for record in sorted((item for item in records if item["category"] == "safe_rename"),
                         key=lambda item: item["table_index"]):
        family = record["recommended_batch"].split(":", 1)[1]
        if (batches and batches[-1]["family"] == family
                and batches[-1]["table_index_end"] + 1 == record["table_index"]):
            batches[-1]["specials"].append(record["jp_name"])
            batches[-1]["table_index_end"] = record["table_index"]
            continue
        batches.append({
            "batch": f"safe_rename:{family}",
            "family": family,
            "source_owner": record["source_owner"],
            "table_index_start": record["table_index"],
            "table_index_end": record["table_index"],
            "specials": [record["jp_name"]],
        })
    for batch in batches:
        batch["count"] = len(batch["specials"])
    return batches


def special_naming_report(jp_root: Path, us_root: Path) -> dict[str, object]:
    """Classify address-named JP Specials without assigning speculative names."""
    jp_names = special_names(jp_root)
    us_names = special_names(us_root)
    placeholders = [name for name in jp_names if SUB_SPECIAL_RE.fullmatch(name)]
    mappings = parse_funcmap(jp_root)
    calls = explicit_special_calls(jp_root, set(placeholders))
    aliases = special_aliases(jp_root)
    mapped_names = {
        item["standard"] for name in placeholders
        for item in mappings.get(int(SUB_SPECIAL_RE.fullmatch(name).group(1), 16), [])
        if item["standard"] and item["current"] == name
        and not SUB_SPECIAL_RE.fullmatch(item["standard"].removesuffix("_jp"))
    }
    jp_definitions = function_definition_owners(jp_root, mapped_names)
    us_definitions = function_definition_owners(us_root, mapped_names)
    records = []
    for index, name in enumerate(jp_names):
        match = SUB_SPECIAL_RE.fullmatch(name)
        if not match:
            continue
        address = int(match.group(1), 16)
        evidence = mappings.get(address, [])
        source_owners = sorted({item["source_owner"] for item in evidence if item["source_owner"]})
        address_candidates = sorted({item["standard"] for item in evidence
                                     if item["standard"]
                                     and not SUB_SPECIAL_RE.fullmatch(item["standard"].removesuffix("_jp"))})
        standard_names = sorted({item["standard"] for item in evidence
                                 if item["standard"] and item["current"] == name
                                 and not SUB_SPECIAL_RE.fullmatch(item["standard"].removesuffix("_jp"))})
        jp_definition_owners = sorted(set().union(
            *(jp_definitions.get(standard, []) for standard in standard_names)))
        us_definition_owners = sorted(set().union(
            *(us_definitions.get(standard, []) for standard in standard_names)))
        if source_owners:
            source_owner_provenance = "funcmap"
        elif len(jp_definition_owners) == 1:
            source_owners = jp_definition_owners
            source_owner_provenance = "jp_definition"
        elif len(us_definition_owners) == 1:
            source_owners = us_definition_owners
            source_owner_provenance = "us_definition"
        else:
            source_owner_provenance = "unresolved"
        direct_name = standard_names[0] if len(standard_names) == 1 else None
        call_sites = calls[name]
        if direct_name and len(source_owners) == 1:
            category = "safe_rename"
            reason = "exact_funcmap_current_with_source_owner"
        elif address_candidates:
            category = "address_candidate_requires_semantic_review"
            reason = "funcmap_address_candidate_not_exact_safe_mapping"
        elif source_owners or call_sites or evidence:
            category = "manual_semantic_review"
            reason = "owner_or_call_evidence_without_unique_standard_name"
        else:
            category = "insufficient_evidence"
            reason = "no_funcmap_owner_or_explicit_call"
        family = Path(source_owners[0]).stem if len(source_owners) == 1 else "unowned"
        records.append({
            "table_index": index,
            "jp_name": name,
            "jp_address": f"0x{address:08X}",
            "source_owner": source_owners[0] if len(source_owners) == 1 else None,
            "source_owner_candidates": source_owners,
            "source_owner_provenance": source_owner_provenance,
            "jp_definition_owners": jp_definition_owners,
            "us_definition_owners": us_definition_owners,
            "funcmap_entries": evidence,
            "funcmap_address_candidates": address_candidates,
            "has_funcmap_address_candidate": bool(address_candidates),
            "funcmap_standard_candidates": standard_names,
            "us_same_index_name": us_names[index] if index < len(us_names) else None,
            "special_aliases": aliases.get(name, []),
            "has_named_special_alias": bool(aliases.get(name)),
            "master_def_is_raw": True,
            "explicit_call_count": len(call_sites),
            "explicit_call_sites": call_sites,
            "category": category,
            "reason": reason,
            "recommended_name": direct_name if category == "safe_rename" else None,
            "recommended_batch": f"{category}:{family}",
        })
    records.sort(key=lambda record: (record["jp_address"], record["table_index"]))
    batches: dict[str, list[str]] = defaultdict(list)
    for record in records:
        batches[record["recommended_batch"]].append(record["jp_name"])
    categories = Counter(record["category"] for record in records)
    return {
        "schema": 1,
        "method": {
            "funcmap_address_candidate_rule": "Any non-placeholder funcmap standard at the address encoded by the raw Special; candidates are never safe names on their own.",
            "safe_rename_rule": "An exact raw current symbol, unique non-placeholder standard, and one resolved source owner.",
            "manual_review_rule": "Source/owner/call evidence exists but no safe exact mapping exists.",
            "insufficient_rule": "No funcmap address row, source owner, or explicit EventScript call exists.",
            "us_same_index_rule": "Context only: JP and US table lengths differ, so same-index US names never name a JP Special automatically.",
        },
        "table_counts": {"jp": len(jp_names), "us": len(us_names)},
        "summary": {
            "funcmap_address_candidates": sum(record["has_funcmap_address_candidate"] for record in records),
            "without_funcmap_address_candidate": sum(not record["has_funcmap_address_candidate"] for record in records),
            "safe_rename": categories["safe_rename"],
            "address_candidate_requires_semantic_review": categories["address_candidate_requires_semantic_review"],
            "manual_semantic_review": categories["manual_semantic_review"],
            "insufficient_evidence": categories["insufficient_evidence"],
        },
        "recommended_batches": [
            {"batch": batch, "specials": names, "count": len(names)}
            for batch, names in sorted(batches.items())
        ],
        "safe_rename_batches": safe_rename_batches(records),
        "records": records,
    }


def table_report(root: Path) -> dict[str, object]:
    """Describe canonical ownership and legacy duplication for one source tree."""
    canonical = root / CANONICAL_TABLE
    legacy = root / LEGACY_CONSTANTS
    names = special_names(root)
    canonical_sites = reference_sites(root, CANONICAL_TABLE.as_posix())
    legacy_sites = reference_sites(root, LEGACY_CONSTANTS.as_posix())
    generators = [path.as_posix() for path in LEGACY_GENERATORS if (root / path).is_file()]
    return {
        "root": str(root),
        "canonical_table": CANONICAL_TABLE.as_posix(),
        "canonical_table_exists": canonical.is_file(),
        "special_count": len(names),
        "duplicate_special_names": sorted({name for name in names if names.count(name) > 1}),
        "canonical_reference_sites": canonical_sites,
        "legacy_constants_path": LEGACY_CONSTANTS.as_posix(),
        "legacy_constants_exists": legacy.is_file(),
        "legacy_reference_sites": legacy_sites,
        "legacy_generator_paths": generators,
        "single_owner": bool(canonical.is_file() and not legacy.is_file() and not legacy_sites and not generators),
    }


def build_report(jp_root: Path, us_root: Path) -> dict[str, object]:
    return {
        "schema": 2,
        "purpose": "detect duplicate generated Special constants; never generate them",
        "jp": table_report(jp_root),
        "us": table_report(us_root),
        "special_naming": special_naming_report(jp_root, us_root),
    }


def print_report(report: dict[str, object]) -> None:
    for label in ("jp", "us"):
        table = report[label]
        print("%s Special table: canonical=%s specials=%d refs=%d legacy-file=%s legacy-refs=%d generators=%d single-owner=%s" % (
            label.upper(), table["canonical_table_exists"], table["special_count"],
            len(table["canonical_reference_sites"]), table["legacy_constants_exists"],
            len(table["legacy_reference_sites"]), len(table["legacy_generator_paths"]),
            table["single_owner"]))
    naming = report["special_naming"]
    print("JP address-named Specials: candidates=%d no-candidate=%d safe=%d candidate-review=%d manual=%d insufficient=%d" % (
        naming["summary"]["funcmap_address_candidates"],
        naming["summary"]["without_funcmap_address_candidate"],
        naming["summary"]["safe_rename"],
        naming["summary"]["address_candidate_requires_semantic_review"],
        naming["summary"]["manual_semantic_review"],
        naming["summary"]["insufficient_evidence"]))


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--jp-root", type=Path, default=ROOT)
    parser.add_argument("--us-root", type=Path, default=DEFAULT_US_ROOT)
    parser.add_argument("--json", action="store_true", help="print stable JSON instead of the summary")
    parser.add_argument("--output", type=Path, help="write stable JSON to this path")
    parser.add_argument("--naming-manifest", type=Path,
                        help="write the address-named Special classification JSON")
    args = parser.parse_args()
    for label, root in (("JP", args.jp_root), ("US", args.us_root)):
        if not (root / CANONICAL_TABLE).is_file():
            raise SystemExit(f"{label} canonical Special table is missing: {root / CANONICAL_TABLE}")
    for destination in (args.output, args.naming_manifest):
        if destination and destination.suffix.lower() in {".md", ".markdown", ".mdown"}:
            raise SystemExit("--output and --naming-manifest are JSON only; use DECOMP_PROGRESS.md as a human-readable report")
    report = build_report(args.jp_root, args.us_root)
    rendered = json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(rendered, encoding="utf-8")
    if args.naming_manifest:
        args.naming_manifest.parent.mkdir(parents=True, exist_ok=True)
        args.naming_manifest.write_text(
            json.dumps(report["special_naming"], ensure_ascii=False, indent=2, sort_keys=True) + "\n",
            encoding="utf-8")
    if args.json:
        print(rendered, end="")
    else:
        print_report(report)


if __name__ == "__main__":
    main()
