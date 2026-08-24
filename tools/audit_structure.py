#!/usr/bin/env python3
"""Reproducible structural audit for pokeemerald-jp and pokeemerald.

The report deliberately keeps several progress measures separate.  A C
object can contain ``__attribute__((naked))`` assembly, and a JP source file
can be split differently from its upstream counterpart.  Neither condition
means that its source is strict C or that its module has reached its upstream
home.  This script reports those facts independently instead of blending them
into a single percentage.

The source/file/function metrics do not use build artefacts.  The map-owner
metric intentionally parses the matching ``baserom_jp.gba`` through the
repository map emitter.  The default is a short human-readable report;
``--json`` is the stable machine-readable form and ``--manifest`` writes the
JP-only code-module inventory used to plan migrations.
"""

from __future__ import annotations

import argparse
import json
import re
import tempfile
from collections import Counter, defaultdict
from dataclasses import asdict, dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
US_ROOT_CANDIDATES = (ROOT.parent / "pokeemerald", ROOT.parent.parent / "pokeemerald")
DEFAULT_US_ROOT = next((path for path in US_ROOT_CANDIDATES if (path / "src").is_dir()),
                       US_ROOT_CANDIDATES[0])
SOURCE_DIRS = ("src", "asm", "data")
SOURCE_SUFFIXES = {".c", ".h", ".s", ".inc", ".json"}
FUNCTION_HEAD_RE = re.compile(
    r"(?m)^(?P<head>(?:(?:__attribute__\s*\(\([^\n]*?\)\)\s*)|[^\n{};])*?"
    r"\b(?P<name>(?!__attribute__\b)[A-Za-z_]\w*)\s*\()"
)
ADDRESS_RE = re.compile(r"^[0-9A-Fa-f]{8}$")
TRANSITION_RE = {
    "tail": re.compile(r"(?:^|_)tail\d*(?:_|$)"),
    "rest": re.compile(r"(?:^|_)rest\d*(?:_|$)"),
    "mid": re.compile(r"(?:^|_)mid\d*(?:_|$)"),
    "stub": re.compile(r"(?:^|_)stub\d*(?:_|$)"),
    "address": re.compile(r"(?:^|_)(?:0x)?[0-9A-Fa-f]{6,}(?:_|$)"),
}
PLACEHOLDER_RE = re.compile(r"(?:^nullsub_|Dummy|dummy|Nop|CallbackDummy)")
NUMERIC_VARIANT_RE = re.compile(r"^(.*)_([2-9]\d*)$")
INCBIN_RE = re.compile(r'(?:^|\s)(?:\.incbin\b|INCBIN_[A-Z0-9_]+\b)[^\n]*?"([^"]+)"')
MAP_NAME_RE = re.compile(r'^\s*\.include\s+"data/maps/([^/]+)/scripts\.inc"\s*$')
US_SYMBOL_RE = re.compile(r"^[0-9A-Fa-f]{8}\s+[A-Za-z]\s+[0-9A-Fa-f]+\s+(\w+)\s*$")
NAKED_MACRO_RE = re.compile(r"^\s*NAKED\s*$")
MARKDOWN_SUFFIXES = {".md", ".markdown", ".mdown"}


@dataclass(frozen=True)
class FunctionDef:
    path: str
    name: str
    naked: bool


@dataclass(frozen=True)
class FuncmapEntry:
    """One funcmap row; names intentionally do not identify a row globally."""
    address: int
    source: str | None
    current: str
    standard: str


def eval_preprocessor_condition(expression: str, macros: dict[str, int]) -> bool:
    """Evaluate the small integer-expression subset used by C source guards.

    Unknown identifiers have C preprocessor semantics (zero).  This mirrors
    the default project build closely enough for conditional function bodies
    without requiring an installed host preprocessor or its include paths.
    """
    expression = re.sub(
        r"defined\s*\(\s*([A-Za-z_]\w*)\s*\)",
        lambda match: "1" if match.group(1) in macros else "0", expression)
    expression = re.sub(r"\bdefined\s+([A-Za-z_]\w*)",
                        lambda match: "1" if match.group(1) in macros else "0", expression)
    expression = re.sub(r"\b([A-Za-z_]\w*)\b",
                        lambda match: str(macros.get(match.group(1), 0)), expression)
    expression = re.sub(r"(?<=\d)[uUlL]+\b", "", expression)
    expression = expression.replace("&&", " and ").replace("||", " or ")
    expression = re.sub(r"!(?!=)", " not ", expression)
    if not re.fullmatch(r"[\s0-9xXa-fA-F()+\-*/%<>=!&|~.andor]+", expression):
        return False
    try:
        return bool(eval(expression, {"__builtins__": {}}, {}))
    except (ArithmeticError, SyntaxError, ValueError):
        return False


def active_preprocessor_text(text: str) -> str:
    """Blank inactive branches while preserving offsets and line positions.

    The audit uses the repository's default configuration: feature macros such
    as ``NONMATCHING`` are undefined, and the C99-era ``__STDC_VERSION__`` is
    available.  This prevents the mutually exclusive C and NAKED branches
    from being counted together.
    """
    macros = {"__STDC_VERSION__": 199901}
    active = True
    frames: list[dict[str, bool]] = []
    result = []
    directive_re = re.compile(r"^\s*#\s*(\w+)(?:\s+(.*?))?\s*$")
    for line in text.splitlines(keepends=True):
        match = directive_re.match(line)
        if match:
            command, argument = match.group(1), (match.group(2) or "").strip()
            if command in {"if", "ifdef", "ifndef"}:
                parent = active
                if command == "if":
                    selected = eval_preprocessor_condition(argument, macros)
                elif command == "ifdef":
                    selected = argument in macros
                else:
                    selected = argument not in macros
                frames.append({"parent": parent, "taken": parent and selected})
                active = parent and selected
            elif command == "elif" and frames:
                frame = frames[-1]
                selected = eval_preprocessor_condition(argument, macros)
                active = frame["parent"] and not frame["taken"] and selected
                frame["taken"] = frame["taken"] or active
            elif command == "else" and frames:
                frame = frames[-1]
                active = frame["parent"] and not frame["taken"]
                frame["taken"] = True
            elif command == "endif" and frames:
                active = frames.pop()["parent"]
            elif command == "define" and active:
                fields = argument.split(None, 1)
                if fields and "(" not in fields[0]:
                    macros[fields[0]] = int(fields[1], 0) if len(fields) == 2 and fields[1].isdigit() else 1
            elif command == "undef" and active:
                macros.pop(argument, None)
            result.append("\n" if line.endswith("\n") else "")
        elif active:
            result.append(line)
        else:
            result.append("".join("\n" if char == "\n" else " " for char in line))
    return "".join(result)


def skip_balanced(text: str, open_pos: int) -> int | None:
    """Return the byte after the balanced parenthesis at *open_pos*."""
    depth = 0
    for pos in range(open_pos, len(text)):
        if text[pos] == "(":
            depth += 1
        elif text[pos] == ")":
            depth -= 1
            if depth == 0:
                return pos + 1
    return None


def has_naked_macro_prefix(text: str, before: int) -> bool:
    """Recognize ``NAKED`` on the declaration's own preceding macro line.

    The declaration can be conditional, so preprocessor lines between the
    macro and the selected signature are ignored.  Any ordinary source line
    (including a prior function's closing brace) terminates the search.
    """
    lines = text[:before].splitlines()
    skipped_conditional_depth = 0
    for line in reversed(lines):
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith("#endif") or stripped.startswith("#else") or stripped.startswith("#elif"):
            skipped_conditional_depth += 1
            continue
        if stripped.startswith("#if"):
            if skipped_conditional_depth:
                skipped_conditional_depth -= 1
            continue
        if skipped_conditional_depth:
            continue
        return bool(NAKED_MACRO_RE.fullmatch(line))
    return False


def function_definitions(path: Path, root: Path) -> list[FunctionDef]:
    """Find C definitions without counting prototypes or control statements."""
    text = active_preprocessor_text(path.read_text(encoding="utf-8", errors="replace"))
    result: list[FunctionDef] = []
    ignored = {"if", "for", "while", "switch", "sizeof"}
    for match in FUNCTION_HEAD_RE.finditer(text):
        name = match.group("name")
        if name in ignored:
            continue
        # The captured head ends immediately after the actual function's
        # opening parenthesis.  Looking for the first ``("`` in the header
        # would instead select ``__attribute__((...))`` when present.
        open_pos = match.end("head") - 1
        end = skip_balanced(text, open_pos)
        if end is None:
            continue
        probe = end
        while True:
            while probe < len(text) and text[probe].isspace():
                probe += 1
            # A conditional signature can leave ``#endif`` between the
            # selected parameter list and its common function body.
            if probe < len(text) and text[probe] == "#":
                line_end = text.find("\n", probe)
                probe = len(text) if line_end == -1 else line_end + 1
                continue
            if not text.startswith("__attribute__", probe):
                break
            attr_open = text.find("(", probe + len("__attribute__"))
            if attr_open < 0:
                break
            attr_end = skip_balanced(text, attr_open)
            if attr_end is None:
                break
            probe = attr_end
        if probe >= len(text) or text[probe] != "{":
            continue
        # The expression consumes leading GNU attributes as part of this
        # declaration, so never scan into an earlier declaration for them.
        header = text[match.start("head"):probe]
        result.append(FunctionDef(
            path=path.relative_to(root / "src").as_posix(),
            name=name,
            naked="naked" in header or has_naked_macro_prefix(text, match.start("head")),
        ))
    return result


def c_inventory(root: Path) -> list[FunctionDef]:
    return [definition for path in sorted((root / "src").glob("**/*.c"))
            for definition in function_definitions(path, root)]


def source_files(root: Path) -> set[str]:
    files = set()
    for directory in SOURCE_DIRS:
        base = root / directory
        if not base.is_dir():
            continue
        for path in base.glob("**/*"):
            if path.is_file() and path.suffix in SOURCE_SUFFIXES:
                files.add(path.relative_to(root).as_posix())
    return files


def extension_counts(files: set[str]) -> dict[str, int]:
    return dict(sorted(Counter(Path(path).suffix or "[no suffix]" for path in files).items()))


def directory_counts(files: set[str]) -> dict[str, int]:
    counts = Counter()
    for path in files:
        parts = Path(path).parts
        counts[parts[0]] += 1
    return dict(sorted(counts.items()))


def parse_funcmap(path: Path) -> tuple[list[FuncmapEntry], int]:
    """Return every funcmap row and its unique address count.

    Static functions can legitimately share a name in distinct owner modules,
    so callers must resolve a row by its source owner rather than collapsing
    rows into a name-to-address dictionary.
    """
    entries: list[FuncmapEntry] = []
    unique_addresses = set()
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        fields = line.split()
        if len(fields) < 2 or not ADDRESS_RE.fullmatch(fields[0]):
            continue
        address = int(fields[0], 16)
        # Retained asm rows can have either ``address file.s symbol`` or
        # ``address file.s JP-name US-name``.  Neither source field is a
        # function alias.
        if len(fields) >= 3 and fields[1].endswith(".s"):
            source = fields[1]
            current = fields[2]
            standard = fields[3] if len(fields) >= 4 else current
        else:
            source = None
            current = fields[1]
            standard = fields[2] if len(fields) >= 3 else current
        entries.append(FuncmapEntry(address, source, current, standard))
        unique_addresses.add(address)
    return entries, len(unique_addresses)


def source_matches_definition(source: str, definition: FunctionDef) -> bool:
    """Match a retained ``foo.s`` funcmap owner to ``src/foo.c``."""
    return Path(source).stem == Path(definition.path).stem


def resolve_funcmap_entries(
    definitions: list[FunctionDef], entries: list[FuncmapEntry],
) -> tuple[dict[FunctionDef, list[FuncmapEntry]], list[str]]:
    """Resolve definitions while retaining all legitimate same-name addresses."""
    by_name: dict[str, list[FuncmapEntry]] = defaultdict(list)
    for entry in entries:
        by_name[entry.current].append(entry)
        if entry.standard != entry.current:
            by_name[entry.standard].append(entry)
    resolved: dict[FunctionDef, list[FuncmapEntry]] = {}
    multi_address = []
    for definition in definitions:
        candidates = by_name.get(definition.name, [])
        owner_candidates = [entry for entry in candidates if entry.source and
                            source_matches_definition(entry.source, definition)]
        selected = owner_candidates or candidates
        unique = {entry.address: entry for entry in selected}
        if unique:
            resolved[definition] = list(unique.values())
            if len(unique) > 1:
                multi_address.append(f"{definition.path}:{definition.name}")
    return resolved, sorted(multi_address)


def index_us_functions(definitions: list[FunctionDef]) -> dict[str, set[str]]:
    owners: dict[str, set[str]] = defaultdict(set)
    for definition in definitions:
        owners[definition.name].add(definition.path)
    return owners


def us_binary_symbols(root: Path) -> set[str]:
    """Return named code/data symbols emitted by the reference US build."""
    sym = root / "pokeemerald.sym"
    if not sym.is_file():
        return set()
    return {match.group(1) for line in sym.read_text(encoding="utf-8", errors="replace").splitlines()
            if (match := US_SYMBOL_RE.match(line))}


def module_manifest(
    jp_definitions: list[FunctionDef],
    us_owners: dict[str, set[str]],
    us_symbols: set[str],
    resolved: dict[FunctionDef, list[FuncmapEntry]],
    naked_addresses: set[int],
) -> list[dict[str, object]]:
    """Classify strict, mapped C modules with no US-standard owner.

    Generated data fragments and copied libc sources remain in the report, but
    are explicitly marked as such.  This makes the migration queue useful
    without pretending that every JP-specific data split is gameplay code.
    """
    by_path: dict[str, list[FunctionDef]] = defaultdict(list)
    for definition in jp_definitions:
        if (not definition.naked and definition in resolved and
                all(entry.address not in naked_addresses for entry in resolved[definition])):
            by_path[definition.path].append(definition)
    manifest = []
    for path, definitions in sorted(by_path.items()):
        unmatched = sorted({definition.name for definition in definitions
                            if all(entry.standard not in us_owners
                                   for entry in resolved[definition])})
        if not unmatched:
            continue
        functions = []
        for name in unmatched:
            standards = {entry.standard for definition in definitions if definition.name == name
                         for entry in resolved[definition]}
            standard = sorted(standards)[0]
            variant = NUMERIC_VARIANT_RE.fullmatch(standard)
            if standard in us_symbols:
                classification = "us_binary_only"
                action = "locate_us_non_c_or_symbol_owner"
            elif path.startswith(("libc/", "libagbsyscall")):
                classification = "library_or_runtime"
                action = "keep_as_jp_runtime_split"
            elif PLACEHOLDER_RE.search(standard):
                classification = "placeholder"
                action = "document_or_share_placeholder"
            elif variant and variant.group(1) in us_owners:
                classification = "numbered_variant"
                action = "compare_with_us_base_function"
            else:
                classification = "jp_specific_or_unmapped_us"
                action = "manual_us_counterpart_review"
            functions.append({
                "name": name,
                "us_standard_name": standard,
                "classification": classification,
                "suggested_action": action,
            })
        classes = {item["classification"] for item in functions}
        if classes == {"us_binary_only"}:
            category = "us_binary_only"
        elif classes == {"library_or_runtime"}:
            category = "library_or_runtime"
        elif classes == {"placeholder"}:
            category = "placeholder_only"
        elif classes == {"numbered_variant"}:
            category = "numbered_variant_only"
        elif "jp_specific_or_unmapped_us" in classes:
            category = "needs_counterpart_review"
        else:
            category = "mixed_non_mainline"
        manifest.append({
            "path": path,
            "category": category,
            "functions": len(definitions),
            "unmatched_functions": functions,
        })
    return manifest


def transition_files(files: set[str]) -> dict[str, list[str]]:
    result = {name: [] for name in TRANSITION_RE}
    for path in sorted(files):
        stem = Path(path).stem
        for name, pattern in TRANSITION_RE.items():
            if pattern.search(stem):
                result[name].append(path)
    return result


def transition_manifest(files: set[str]) -> list[dict[str, object]]:
    actions = {
        "tail": "merge_into_semantic_module_after_link_order_is_stable",
        "rest": "split_into_semantic_modules_after_boundary_audit",
        "mid": "split_or_rename_after_link_order_is_stable",
        "stub": "replace_placeholder_with_named_implementation",
        "address": "assign_semantic_owner_before_renaming",
    }
    records = []
    for path in sorted(files):
        categories = [name for name, pattern in TRANSITION_RE.items()
                      if pattern.search(Path(path).stem)]
        if categories:
            records.append({
                "path": path,
                "categories": categories,
                "suggested_actions": [actions[name] for name in categories],
            })
    return records


def incbin_progress(root: Path) -> dict[str, object]:
    references = []
    raw_suffixes = {".bin", ".gba", ".lz", ".rl", ".huff"}
    for relpath in sorted(source_files(root)):
        path = root / relpath
        if path.suffix not in {".s", ".inc", ".c", ".h"}:
            continue
        for resource in INCBIN_RE.findall(path.read_text(encoding="utf-8", errors="replace")):
            suffix = Path(resource).suffix or "[no suffix]"
            raw = suffix in raw_suffixes
            references.append({
                "owner": relpath,
                "resource": resource,
                "suffix": suffix,
                "classification": "raw_binary" if raw else "structured_or_encoded",
                "exists": (root / resource).is_file(),
                "suggested_action": (
                    "decode_or_split_into_named_asset" if raw
                    else "retain_and_validate_source_asset"
                ),
            })
    suffixes = Counter(item["suffix"] for item in references)
    raw_records = [item for item in references if item["classification"] == "raw_binary"]
    missing = [item for item in references if not item["exists"]]
    raw_owner_dirs = Counter(str(Path(item["owner"]).parent) for item in raw_records)
    raw_resource_dirs = Counter(str(Path(item["resource"]).parent) for item in raw_records)
    return {
        "references": len(references),
        "unique_paths": len({item["resource"] for item in references}),
        "raw_binary_references": len(raw_records),
        "non_raw_references": len(references) - len(raw_records),
        "missing_resource_paths": len(missing),
        "suffixes": dict(sorted(suffixes.items())),
        "raw_by_owner_directory": dict(sorted(raw_owner_dirs.items())),
        "raw_by_resource_directory": dict(sorted(raw_resource_dirs.items())),
        "manifest": references,
    }


def asset_naming_progress(incbin: dict[str, object], us_root: Path) -> dict[str, object]:
    """Compare referenced JP graphics/sound names with the requested US tree.

    This is deliberately a candidate audit, not a renamer: a resource path can
    be referenced from assembly, headers, linker inputs, and generated data.
    A unique US basename is useful evidence for a reviewable rename, while an
    exact path is already aligned.
    """
    asset_dirs = ("graphics", "sound")
    us_paths = set()
    by_name: dict[str, list[str]] = defaultdict(list)
    for directory in asset_dirs:
        base = us_root / directory
        if not base.is_dir():
            continue
        for path in base.glob("**/*"):
            if path.is_file():
                relpath = path.relative_to(us_root).as_posix()
                us_paths.add(relpath)
                by_name[path.name].append(relpath)
    resources = sorted({item["resource"] for item in incbin["manifest"]
                        if Path(item["resource"]).parts[:1] in {(name,) for name in asset_dirs}})
    records = []
    for resource in resources:
        candidates = sorted(by_name.get(Path(resource).name, []))
        if resource in us_paths:
            status = "exact_us_path"
        elif len(candidates) == 1:
            status = "unique_us_basename_candidate"
        elif candidates:
            status = "ambiguous_us_basename"
        else:
            status = "no_us_basename_match"
        records.append({"resource": resource, "status": status, "us_candidates": candidates})
    counts = Counter(item["status"] for item in records)
    return {
        "referenced_graphics_or_sound_paths": len(records),
        "exact_us_paths": counts["exact_us_path"],
        "unique_us_basename_candidates": counts["unique_us_basename_candidate"],
        "ambiguous_us_basename_candidates": counts["ambiguous_us_basename"],
        "no_us_basename_match": counts["no_us_basename_match"],
        "manifest": records,
    }


def first_map_owner_names(entries) -> set[str]:
    """Return the first map name for each shared JP map-script table."""
    first = {}
    for start, name, *_rest in entries:
        first.setdefault(start, name)
    return set(first.values())


def map_entries_for_us_root(emitter, us_root: Path):
    """Read map names from the requested US tree, not emitter's hard-coded one."""
    map_groups = us_root / "data/maps/map_groups.json"
    if not map_groups.is_file():
        raise FileNotFoundError("US map groups are missing: %s" % map_groups)
    saved_json, saved_names = emitter.US_JSON, emitter.MAP_NAMES
    emitter.US_JSON = map_groups
    emitter.MAP_NAMES = emitter.build_map_names()
    try:
        return emitter.map_entries(include_empty=True)
    finally:
        emitter.US_JSON, emitter.MAP_NAMES = saved_json, saved_names


def map_progress(root: Path, us_root: Path) -> dict[str, object]:
    # The emitter is the repository's authoritative parser for JP map tables.
    # A shared table belongs to its first map, matching audit_map_script_coverage.
    import jp_emit_maps as emitter

    map_entries = map_entries_for_us_root(emitter, us_root)
    owner_names = first_map_owner_names(map_entries)
    names = set()
    event_scripts = root / "data/event_scripts.s"
    if event_scripts.is_file():
        for line in event_scripts.read_text(encoding="utf-8", errors="replace").splitlines():
            match = MAP_NAME_RE.match(line)
            if match:
                names.add(match.group(1))
    map_root = root / "data/maps"
    jp_json = {path.parent.name for path in map_root.glob("*/map.json")}
    jp_scripts = {path.parent.name for path in map_root.glob("*/scripts.inc")}
    owner_scripts = jp_scripts & owner_names
    non_owner_scripts = jp_scripts - owner_names
    us_maps = us_root / "data/maps"
    us_json = {path.parent.name for path in us_maps.glob("*/map.json")} if us_maps.is_dir() else set()
    return {
        "map_table_owners": len(owner_names),
        "map_table_owner_names": sorted(owner_names),
        "event_script_included_owners": len(names),
        "jp_scripts_inc": len(jp_scripts),
        "first_owner_scripts_inc": len(owner_scripts),
        "first_owner_script_names": sorted(owner_scripts),
        "non_owner_scripts_inc": len(non_owner_scripts),
        "non_owner_script_names": sorted(non_owner_scripts),
        "jp_scripts_owner_rate": len(owner_scripts) / max(len(owner_names), 1),
        "jp_map_json": len(jp_json),
        "jp_map_json_with_scripts": len(jp_json & jp_scripts),
        "us_map_json": len(us_json),
    }


def build_report(root: Path, us_root: Path) -> dict[str, object]:
    jp_files = source_files(root)
    us_files = source_files(us_root)
    jp_defs = c_inventory(root)
    us_defs = c_inventory(us_root)
    funcmap_entries, total_functions = parse_funcmap(root / "funcmap_jp.txt")
    resolved, multi_address_c_definitions = resolve_funcmap_entries(jp_defs, funcmap_entries)
    us_owners = index_us_functions(us_defs)
    us_symbols = us_binary_symbols(us_root)

    strict_addresses = set()
    naked_addresses = set()
    unmapped_c_definitions = []
    standard_owned_addresses = set()
    aligned_addresses = set()
    binary_only_addresses = set()
    function_owners = []
    strict_records = []
    for definition in jp_defs:
        entries = resolved.get(definition)
        if entries is None:
            unmapped_c_definitions.append(f"{definition.path}:{definition.name}")
            continue
        for entry in entries:
            if definition.naked:
                naked_addresses.add(entry.address)
            else:
                strict_records.append((definition, entry))

    # A ROM address containing any selected NAKED definition is assembly, not
    # strict C.  This also makes the sets disjoint if a source alias remains.
    strict_records = [(definition, entry) for definition, entry in strict_records
                      if entry.address not in naked_addresses]
    for definition, entry in strict_records:
        address, standard = entry.address, entry.standard
        strict_addresses.add(address)
        owners = us_owners.get(standard, set())
        function_owners.append({
            "address": "0x%08X" % address,
            "current_name": definition.name,
            "current_owner": definition.path,
            "funcmap_source_owner": entry.source,
            "us_standard_name": standard,
            "us_owners": sorted(owners),
            "us_binary_symbol": standard in us_symbols,
        })
        if owners:
            standard_owned_addresses.add(address)
            if definition.path in owners:
                aligned_addresses.add(address)
        elif standard in us_symbols:
            binary_only_addresses.add(address)

    jp_modules = {path.removeprefix("src/").removesuffix(".c")
                  for path in jp_files if path.startswith("src/") and path.endswith(".c")}
    us_modules = {path.removeprefix("src/").removesuffix(".c")
                  for path in us_files if path.startswith("src/") and path.endswith(".c")}
    common_modules = jp_modules & us_modules
    manifest = module_manifest(jp_defs, us_owners, us_symbols, resolved, naked_addresses)
    transitions = transition_files(jp_files)
    incbin = incbin_progress(root)

    return {
        "schema": 1,
        "roots": {"jp": str(root), "us": str(us_root)},
        "files": {
            "jp": {"directories": directory_counts(jp_files), "suffixes": extension_counts(jp_files)},
            "us": {"directories": directory_counts(us_files), "suffixes": extension_counts(us_files)},
            "same_path": len(jp_files & us_files),
            "jp_only": len(jp_files - us_files),
            "us_only": len(us_files - jp_files),
        },
        "c_modules": {
            "jp": len(jp_modules), "us": len(us_modules), "same_path": len(common_modules),
            "jp_only": len(jp_modules - us_modules), "us_only": len(us_modules - jp_modules),
        },
        "functions": {
            "funcmap_unique_addresses": total_functions,
            "c_definitions": len(jp_defs),
            "strict_c_addresses": len(strict_addresses),
            "naked_assembly_addresses": len(naked_addresses),
            "strict_c_rate": len(strict_addresses) / max(total_functions, 1),
            "standard_owned_addresses": len(standard_owned_addresses),
            "module_aligned_addresses": len(aligned_addresses),
            "us_binary_only_addresses": len(binary_only_addresses),
            "module_home_rate": len(standard_owned_addresses) / max(len(strict_addresses), 1),
            "path_alignment_rate": len(aligned_addresses) / max(len(strict_addresses), 1),
            "unmapped_c_definitions": sorted(unmapped_c_definitions),
            "multi_address_c_definitions": multi_address_c_definitions,
            "strict_naked_address_overlap": len(strict_addresses & naked_addresses),
            "ownership": sorted(function_owners, key=lambda item: (
                item["address"], item["current_owner"], item["current_name"])),
        },
        "transition_files": {name: {"count": len(paths), "paths": paths}
                             for name, paths in transitions.items()},
        "transition_manifest": transition_manifest(jp_files),
        "incbin": incbin,
        "asset_naming": asset_naming_progress(incbin, us_root),
        "maps": map_progress(root, us_root),
        "jp_only_c_manifest": manifest,
    }


def print_report(report: dict[str, object]) -> None:
    files = report["files"]
    modules = report["c_modules"]
    functions = report["functions"]
    maps = report["maps"]
    incbin = report["incbin"]
    assets = report["asset_naming"]
    print("Structural audit (source inventory; no build artefacts)")
    print("file paths: JP=%d US=%d same=%d JP-only=%d US-only=%d" % (
        sum(files["jp"]["directories"].values()), sum(files["us"]["directories"].values()),
        files["same_path"], files["jp_only"], files["us_only"]))
    print("C modules: JP=%d US=%d same-path=%d JP-only=%d US-only=%d" % (
        modules["jp"], modules["us"], modules["same_path"], modules["jp_only"], modules["us_only"]))
    print("strict C: %d/%d = %.2f%% (naked asm addresses: %d)" % (
        functions["strict_c_addresses"], functions["funcmap_unique_addresses"],
        functions["strict_c_rate"] * 100, functions["naked_assembly_addresses"]))
    print("module home: %d strict addresses = %.2f%%; path alignment: %d = %.2f%%; US binary-only: %d" % (
        functions["standard_owned_addresses"], functions["module_home_rate"] * 100,
        functions["module_aligned_addresses"], functions["path_alignment_rate"] * 100,
        functions["us_binary_only_addresses"]))
    print("JP-only C migration records: %d" % len(report["jp_only_c_manifest"]))
    print("transition files: " + ", ".join(
        "%s=%d" % (name, value["count"])
        for name, value in report["transition_files"].items()))
    print("incbin: references=%d unique=%d raw=%d non-raw=%d missing=%d" % (
        incbin["references"], incbin["unique_paths"], incbin["raw_binary_references"],
        incbin["non_raw_references"], incbin["missing_resource_paths"]))
    print("asset naming: referenced=%d exact-US=%d unique-candidates=%d ambiguous=%d no-match=%d" % (
        assets["referenced_graphics_or_sound_paths"], assets["exact_us_paths"],
        assets["unique_us_basename_candidates"], assets["ambiguous_us_basename_candidates"],
        assets["no_us_basename_match"]))
    print("map structure: owners=%d owner-scripts=%d (%.2f%%) non-owner=%d included=%d map.json=%d (with scripts=%d)" % (
        maps["map_table_owners"], maps["first_owner_scripts_inc"], maps["jp_scripts_owner_rate"] * 100,
        maps["non_owner_scripts_inc"],
        maps["event_script_included_owners"], maps["jp_map_json"], maps["jp_map_json_with_scripts"]))


def render_markdown_report(report: dict[str, object]) -> str:
    """Render the reproducible human-facing progress report without a timestamp."""
    functions = report["functions"]
    incbin = report["incbin"]
    assets = report["asset_naming"]
    maps = report["maps"]
    transitions = report["transition_files"]
    return "\n".join([
        "# 可复现结构审计进度",
        "",
        "> 此文件由 `python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md` 生成。",
        "> `--output` 只写 JSON，且会拒绝 Markdown 路径，避免误覆盖本报告。",
        "",
        "## 当前快照",
        "",
        f"- 严格 C：{functions['strict_c_addresses']}/{functions['funcmap_unique_addresses']} "
        f"({functions['strict_c_rate'] * 100:.2f}%)；naked 汇编地址：{functions['naked_assembly_addresses']}；"
        f"strict/naked 交集：{functions['strict_naked_address_overlap']}。",
        f"- 模块归位：{functions['standard_owned_addresses']}/{functions['strict_c_addresses']} "
        f"({functions['module_home_rate'] * 100:.2f}%)；路径对齐：{functions['module_aligned_addresses']}/"
        f"{functions['strict_c_addresses']} ({functions['path_alignment_rate'] * 100:.2f}%)。",
        f"- JP 独有 C 迁移记录：{len(report['jp_only_c_manifest'])}；同名多地址 C 定义："
        f"{len(functions['multi_address_c_definitions'])}。",
        f"- 过渡文件：tail={transitions['tail']['count']}、rest={transitions['rest']['count']}、"
        f"mid={transitions['mid']['count']}、stub={transitions['stub']['count']}、"
        f"address={transitions['address']['count']}。",
        f"- incbin：{incbin['references']} 引用、{incbin['unique_paths']} 条唯一路径、"
        f"原始二进制 {incbin['raw_binary_references']}、非原始 {incbin['non_raw_references']}、"
        f"缺失资源 {incbin['missing_resource_paths']}。",
        f"- 资产命名：{assets['referenced_graphics_or_sound_paths']} 条 graphics/sound 引用中，"
        f"精确 US 路径 {assets['exact_us_paths']}、唯一 basename 候选 "
        f"{assets['unique_us_basename_candidates']}、歧义 "
        f"{assets['ambiguous_us_basename_candidates']}。",
        f"- 地图脚本：{maps['first_owner_scripts_inc']}/{maps['map_table_owners']} "
        f"({maps['jp_scripts_owner_rate'] * 100:.2f}%) 个首 owner 有 scripts.inc；"
        f"非 owner scripts.inc：{maps['non_owner_scripts_inc']}；map.json："
        f"{maps['jp_map_json']}（含 scripts：{maps['jp_map_json_with_scripts']}）。",
        "",
        "## 指标定义",
        "",
        "| 指标 | 口径 |",
        "| --- | --- |",
        "| 严格 C 转换率 | 默认预处理分支中有 C 函数体、非 `naked` 且不与 selected naked 定义重叠的唯一 funcmap ROM 地址 / funcmap 唯一地址；同名 static 按 source owner 和地址保留，不建立名称→地址覆盖表。 |",
        "| 模块归位率 | 严格 C 地址中能按 US 标准名在 US 源树找到定义的地址 / 严格 C 地址。 |",
        "| 路径对齐率 | 上述地址中 JP 相对 `src/` 路径也属于 US owner 的地址 / 严格 C 地址。 |",
        "| 过渡文件 | 文件名包含 tail、rest、mid、stub 或地址式片段；分类可重叠。 |",
        "| incbin | `.incbin` 与 `INCBIN_*` 的引用数，按原始二进制和结构化/编码后缀分组；不是字节转换率。 |",
        "| 资产命名 | 被引用的 `graphics/`、`sound/` 路径与 US 同名文件比较；仅生成候选，不自动改名。 |",
        "| 地图脚本 owner | `scripts.inc` 与 map-table 实际首 owner 名的交集 / 去重首 owner；共享表只属于首次出现地图。 |",
        "",
        "## 复现与输入",
        "",
        "```sh",
        "python3 tools/audit_structure.py",
        "python3 tools/audit_structure.py --json --output build/audit-structure.json \\",
        "    --manifest build/jp-only-c-manifest.json",
        "python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md",
        "# 比较另一份 US 工程时显式指定其根目录",
        "python3 tools/audit_structure.py --us-root /path/to/pokeemerald --markdown-output DECOMP_PROGRESS.md",
        "```",
        "",
        "源文件、funcmap 和 incbin 清单不读取 `build/`。完整报告仍需要匹配的 "
        "`baserom_jp.gba` 来解析地图 owner；US 二进制符号统计使用指定 US 树的 "
        "`pokeemerald.sym`（若存在），资源存在性检查也依赖本地提取资源。",
        "",
        "涉及源码或链接输入的变更须执行：",
        "",
        "```sh",
        "flock /tmp/pokeemerald-jp-build.lock bash -lc 'make clean && make -j16 && make compare'",
        "```",
        "",
        "只有末行 `pokeemerald_jp.gba: OK` 才可提交。",
        "",
    ])


def require_destination_kind(path: Path, expected: str) -> None:
    """Reject the common JSON/Markdown destination mix-up before auditing."""
    suffix = path.suffix.lower()
    if expected == "json" and suffix in MARKDOWN_SUFFIXES:
        raise SystemExit("--output and --manifest write JSON; use --markdown-output for Markdown paths")
    if expected == "markdown" and suffix == ".json":
        raise SystemExit("--markdown-output writes Markdown; use --output for JSON paths")


def write_output(path: Path, content: str) -> None:
    """Atomically replace an output file so a progress report is never partial."""
    path.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile("w", encoding="utf-8", dir=path.parent,
                                     prefix=f".{path.name}.", suffix=".tmp", delete=False) as output:
        temporary = Path(output.name)
        output.write(content)
    try:
        temporary.replace(path)
    finally:
        temporary.unlink(missing_ok=True)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--us-root", type=Path, default=DEFAULT_US_ROOT)
    parser.add_argument("--json", action="store_true", help="print stable JSON")
    parser.add_argument("--output", type=Path, help="write the full JSON report (never Markdown)")
    parser.add_argument("--manifest", type=Path, help="write only the JP-only C manifest JSON")
    parser.add_argument("--markdown-output", type=Path,
                        help="atomically write the human-readable Markdown progress report")
    args = parser.parse_args()
    if args.output:
        require_destination_kind(args.output, "json")
    if args.manifest:
        require_destination_kind(args.manifest, "json")
    if args.markdown_output:
        require_destination_kind(args.markdown_output, "markdown")
    if not (args.us_root / "src").is_dir():
        raise SystemExit("US source root is missing src/: %s" % args.us_root)
    report = build_report(ROOT, args.us_root.resolve())
    encoded = json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True) + "\n"
    if args.output:
        write_output(args.output, encoded)
    if args.manifest:
        write_output(args.manifest, json.dumps(report["jp_only_c_manifest"], ensure_ascii=False,
                                                indent=2, sort_keys=True) + "\n")
    if args.markdown_output:
        write_output(args.markdown_output, render_markdown_report(report))
    if args.json:
        print(encoded, end="")
    else:
        print_report(report)


if __name__ == "__main__":
    main()
