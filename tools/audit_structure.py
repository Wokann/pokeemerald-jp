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

try:
    from jp_map_metadata import layout_symbol
except ModuleNotFoundError:
    from tools.jp_map_metadata import layout_symbol


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
MAP_EVENTS_RE = re.compile(r'^\s*\.include\s+"data/maps/([^/]+)/events\.inc"\s*$')
MAP_HEADER_RE = re.compile(r'^\s*@ (MAP_[A-Z0-9_]+) \(g(\d+) m(\d+)\)\s*$')
MAP_HEADER_FIELD_RE = re.compile(
    r'^\s*\.4byte\s+([^,\s]+).*@\s+(mapLayout|events|mapScripts|connections)\s*$')
MAP_HEADER_VALUE_RE = re.compile(r'^\s*\.4byte\s+([^,\s]+)\s*$')
ASM_INCLUDE_RE = re.compile(r'^\s*\.include\s+"([^"]+)"\s*$')
MAP_EVENT_ALIAS_RE = re.compile(
    r'^\s*\.set\s+(gMapEvents_[A-Z0-9_]+)\s*,\s*([A-Za-z_]\w*_MapEvents)\s*$')
ASM_LABEL_RE = re.compile(r'^\s*([A-Za-z_]\w*)::?\s*(?:@.*)?$')
POINTER_COMMENT_RE = re.compile(r'^\s*\.4byte\s+([^,\s]+).*@\s+([A-Za-z]+)\s*$', re.MULTILINE)
BASEROM_INCBIN_RE = re.compile(r'^\s*\.incbin\s+"baserom_jp\.gba"[^\n]*$', re.MULTILINE)
SCRIPT_DATA_LINKER_RE = re.compile(
    r'^\s*([A-Za-z0-9_./-]+\.o)\(script_data\);\s*$')
SCRIPT_DATA_SECTION_RE = re.compile(r'^\s*script_data\s*:\s*$')
SCRIPT_DATA_MAP_HEADER_RE = re.compile(
    r'^script_data\s+0x([0-9A-Fa-f]+)\s+0x([0-9A-Fa-f]+)\s*$')
SCRIPT_DATA_MAP_OBJECT_RE = re.compile(
    r'^\s*script_data\s+0x([0-9A-Fa-f]+)\s+0x([0-9A-Fa-f]+)\s+([^\s]+\.o)\s*$')
MAP_SYMBOL_RE = re.compile(r'^\s*0x([0-9A-Fa-f]+)\s+([A-Za-z_]\w*)\s*$')
BASEROM_INCBIN_RANGE_RE = re.compile(
    r'^\s*\.incbin\s+"baserom_jp\.gba"\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*,\s*'
    r'(0x[0-9A-Fa-f]+|\d+)\s*(?:@.*)?$')
US_SYMBOL_RE = re.compile(r"^[0-9A-Fa-f]{8}\s+[A-Za-z]\s+[0-9A-Fa-f]+\s+(\w+)\s*$")
NAKED_MACRO_RE = re.compile(r"^\s*NAKED\s*$")
MARKDOWN_SUFFIXES = {".md", ".markdown", ".mdown"}

# The US linker defines source ownership and link order.  JP address ranges
# remain evidence-driven: each partition must be anchored in the JP link map
# and matching ROM, not inferred from US numeric offsets.
SCRIPT_DATA_OWNER_ANCHORS = (
    ("data/event_scripts.o", "gScriptCmdTable"),
    ("data/event_scripts.o", "gStdScripts_End"),
    ("data/battle_anim_scripts.o", "gBattleAnims_StatusConditions"),
    ("data/battle_scripts_1.o", "gBattleScriptsForMoveEffects"),
    ("data/field_effect_scripts.o", "gFieldEffectScriptPointers"),
    ("data/battle_scripts_2.o", "gBattlescriptsForBallThrow"),
    ("data/battle_ai_scripts.o", "gBattleAI_ScriptsTable"),
    ("data/contest_ai_scripts.o", "gContestAI_ScriptsTable"),
    ("data/mystery_event_script_cmd_table.o", "gMysteryEventScriptCmdTable"),
    ("data/mystery_event_script_cmd_table.o", "gMysteryEventScriptCmdTableEnd"),
)


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


def map_metadata(root: Path) -> dict[str, dict[str, object]]:
    """Read the map.json fields relevant to structural ownership.

    In particular, ``shared_events_map`` and ``shared_scripts_map`` describe
    intentional reuse of another map (or a shared non-map script file).  The
    declarations are evidence, not proof on their own: callers also check the
    corresponding header pointer and source definition.
    """
    metadata: dict[str, dict[str, object]] = {}
    for path in sorted((root / "data/maps").glob("*/map.json")):
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            payload = {}
        metadata[path.parent.name] = payload if isinstance(payload, dict) else {}
    return metadata


def assembly_label_names(root: Path, names: set[str]) -> set[str]:
    """Return requested assembly labels that are physically defined in data/.

    Shared script owners need not have a map directory (``SecretBase`` is
    defined in a shared script include), so checking only ``data/maps`` would
    recreate the false missing-file diagnosis this audit is meant to prevent.
    """
    if not names:
        return set()
    pattern = re.compile(r"^\s*(%s)::?\s*(?:@.*)?$" %
                         "|".join(re.escape(name) for name in sorted(names)))
    found = set()
    for path in sorted((root / "data").glob("**/*")):
        if path.suffix not in {".s", ".inc"} or not path.is_file():
            continue
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            if match := pattern.match(line):
                found.add(match.group(1))
    return found


def shared_map_target(metadata: dict[str, object], field: str) -> str | None:
    """Return a declared shared map name, rejecting empty/non-string values."""
    value = metadata.get(field)
    return value if isinstance(value, str) and value else None


def map_artifact_progress(root: Path, convergence_records: list[dict[str, object]] | None = None) -> dict[str, object]:
    """Count map artifacts without treating their presence as semantic review.

    ``map.json`` and the two generated includes demonstrate that the map has
    been structurally split.  They do not demonstrate that its scripts,
    text, constants, or shared ROM boundaries have received a semantic audit.
    No versioned semantic-review manifest exists yet, so this function keeps
    that status explicitly unrecorded instead of deriving it from file names.
    """
    map_root = root / "data/maps"
    jp_json = {path.parent.name for path in map_root.glob("*/map.json")}
    jp_scripts = {path.parent.name for path in map_root.glob("*/scripts.inc")}
    jp_events = {path.parent.name for path in map_root.glob("*/events.inc")}
    upper_event_includes = set()
    for path in sorted((root / "data").glob("*.s")):
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            if match := MAP_EVENTS_RE.match(line):
                upper_event_includes.add(match.group(1))
    direct_structure_complete = jp_json & jp_scripts & jp_events & upper_event_includes
    if convergence_records is None:
        structure_complete = direct_structure_complete
        shared_scripts = shared_events = set()
    else:
        structure_complete = {
            record["name"] for record in convergence_records
            if record["structure"]["complete"]
        }
        shared_scripts = {
            record["name"] for record in convergence_records
            if record["scripts"]["status"] == "shared"
        }
        shared_events = {
            record["name"] for record in convergence_records
            if record["events"]["status"] == "shared"
        }
    return {
        "jp_map_json": len(jp_json),
        "jp_scripts_inc": len(jp_scripts),
        "jp_events_inc": len(jp_events),
        "upper_event_includes": len(upper_event_includes),
        "structure_complete_maps": len(structure_complete),
        "structure_complete_map_names": sorted(structure_complete),
        "direct_structure_complete_maps": len(direct_structure_complete),
        "shared_scripts_maps": len(shared_scripts),
        "shared_scripts_map_names": sorted(shared_scripts),
        "shared_events_maps": len(shared_events),
        "shared_events_map_names": sorted(shared_events),
        "semantic_review": {
            "status": "not_recorded",
            "reviewed_map_names": [],
            "note": "No versioned semantic-review manifest exists; structural artifacts are not semantic-review evidence.",
        },
    }


def map_includes(path: Path, pattern: re.Pattern[str]) -> list[str]:
    """Return map include names in source order, or an empty list if absent."""
    if not path.is_file():
        return []
    return [match.group(1) for line in path.read_text(encoding="utf-8", errors="replace").splitlines()
            if (match := pattern.match(line))]


def inline_asm_includes(text: str, root: Path, included: frozenset[Path] = frozenset(),
                        inside_header: bool = False) -> list[str]:
    """Return assembly lines with repository-local ``.include`` files inlined.

    Map headers may be written directly in ``data/maps.s`` or delegated
    to a map's ``header.inc``.  The audit needs the same pointer view in both
    cases.  Includes outside ``root``, missing files, and recursive includes
    are ignored deterministically: they cannot contribute a header field.
    """
    resolved_root = root.resolve()
    lines: list[str] = []
    for line in text.splitlines():
        match = ASM_INCLUDE_RE.match(line)
        if not match:
            lines.append(line)
            continue
        candidate = (resolved_root / match.group(1)).resolve()
        if not inside_header and candidate.name not in {"header.inc", "headers.inc"}:
            lines.append(line)
            continue
        if candidate in included or not candidate.is_file():
            continue
        try:
            candidate.relative_to(resolved_root)
        except ValueError:
            continue
        included_text = candidate.read_text(encoding="utf-8", errors="replace")
        lines.extend(inline_asm_includes(included_text, resolved_root, included | {candidate}, True))
    return lines


def map_headers(text: str, root: Path | None = None,
                header_labels: dict[str, str] | None = None) -> dict[str, dict[str, object]]:
    """Read annotated map-header fields, including repository-local headers.

    ``root`` is optional so callers with directly expanded assembly retain the
    original text-only behavior.  When supplied, map ``header.inc`` files are
    inlined recursively before their fields are associated with the preceding
    ``@ MAP_*`` annotation.  Generated ``header.inc`` files use their map-name
    label and a fixed MapHeader pointer order without field comments, while
    older direct headers retain annotations and comments; accept both forms.
    """
    records: dict[str, dict[str, object]] = {}
    current: dict[str, object] | None = None
    lines = inline_asm_includes(text, root) if root is not None else text.splitlines()
    for line in lines:
        if match := MAP_HEADER_RE.match(line):
            current = {
                "id": match.group(1),
                "group": int(match.group(2)),
                "number": int(match.group(3)),
            }
            records[match.group(1)] = current
            continue
        if header_labels and (match := ASM_LABEL_RE.match(line)):
            map_id = header_labels.get(match.group(1))
            if map_id is not None:
                current = {"id": map_id}
                records[map_id] = current
                continue
        if current and (match := MAP_HEADER_FIELD_RE.match(line)):
            current[match.group(2)] = match.group(1)
            continue
        if current and (match := MAP_HEADER_VALUE_RE.match(line)):
            for field in ("mapLayout", "events", "mapScripts", "connections"):
                if field not in current:
                    current[field] = match.group(1)
                    break
    return records


def map_event_aliases(text: str) -> dict[str, str]:
    """Return retained gMapEvents aliases and their real generated targets."""
    return {match.group(1): match.group(2)
            for line in text.splitlines()
            if (match := MAP_EVENT_ALIAS_RE.match(line))}


def asm_label_blocks(text: str) -> dict[str, str]:
    """Index top-level assembly labels into small source blocks.

    This is intentionally a structural parser: it only follows labels and
    annotated pointers, never interprets opaque ROM bytes as source data.
    """
    lines = text.splitlines()
    starts = [(match.group(1), index) for index, line in enumerate(lines)
              if (match := ASM_LABEL_RE.match(line))]
    blocks: dict[str, str] = {}
    for position, (label, start) in enumerate(starts):
        end = starts[position + 1][1] if position + 1 < len(starts) else len(lines)
        blocks.setdefault(label, "\n".join(lines[start:end]))
    return blocks


def annotated_pointer(block: str, field: str) -> str | None:
    """Return one .4byte target carrying the requested assembly field comment."""
    for match in POINTER_COMMENT_RE.finditer(block):
        if match.group(2) == field:
            return match.group(1)
    return None


def named_asset_progress(blocks: dict[str, str], symbol: str | None) -> dict[str, object]:
    """Classify one tileset/layout source label without claiming semantic review."""
    if not symbol:
        return {"symbol": None, "defined": False, "source_count": 0,
                "raw_baserom_source_count": 0, "status": "missing_pointer"}
    block = blocks.get(symbol)
    if block is None:
        return {"symbol": symbol, "defined": False, "source_count": 0,
                "raw_baserom_source_count": 0, "status": "missing_label"}
    sources = INCBIN_RE.findall(block)
    raw_sources = [source for source in sources if Path(source).name == "baserom_jp.gba"]
    return {
        "symbol": symbol,
        "defined": True,
        "source_count": len(sources),
        "raw_baserom_source_count": len(raw_sources),
        "status": "contains_raw_baserom" if raw_sources else "named_source_or_no_incbin",
    }


def tileset_resource_chain(blocks: dict[str, str], symbol: str | None) -> dict[str, object]:
    """Follow one tileset's named tiles/palette/metatile input labels."""
    if not symbol:
        return {"symbol": None, "defined": False, "fields": {}, "raw_baserom_source_count": 0}
    block = blocks.get(symbol)
    if block is None:
        return {"symbol": symbol, "defined": False, "fields": {}, "raw_baserom_source_count": 0}
    fields = {}
    for field in ("tiles", "palettes", "metatiles", "metatileAttributes"):
        fields[field] = named_asset_progress(blocks, annotated_pointer(block, field))
    return {
        "symbol": symbol,
        "defined": True,
        "fields": fields,
        "raw_baserom_source_count": sum(item["raw_baserom_source_count"]
                                          for item in fields.values()),
    }


def raw_baserom_directives(text: str) -> list[str]:
    return [match.group(0).strip() for match in BASEROM_INCBIN_RE.finditer(text)]


def parse_script_data_linker_objects(path: Path) -> list[str]:
    """Return explicit ``script_data`` objects in linker order.

    This follows only the braced linker block.  Object order is the upstream
    structural contract; it says nothing by itself about JP address equality.
    """
    if not path.is_file():
        return []
    in_section = False
    opened = False
    objects = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if not in_section:
            if SCRIPT_DATA_SECTION_RE.match(line):
                in_section = True
            continue
        if "{" in line:
            opened = True
        if match := SCRIPT_DATA_LINKER_RE.match(line):
            objects.append(match.group(1))
        if opened and "}" in line:
            break
    return objects


def parse_script_data_map(path: Path) -> dict[str, object]:
    """Read one linker-map section and its explicit object contributions."""
    result: dict[str, object] = {"section": None, "objects": []}
    if not path.is_file():
        return result
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if match := SCRIPT_DATA_MAP_HEADER_RE.match(line):
            start, size = int(match.group(1), 16), int(match.group(2), 16)
            if result["section"] is None:
                result["section"] = {
                    "start": "0x%08X" % start,
                    "size": "0x%X" % size,
                    "end": "0x%08X" % (start + size),
                }
            continue
        if match := SCRIPT_DATA_MAP_OBJECT_RE.match(line):
            start, size = int(match.group(1), 16), int(match.group(2), 16)
            result["objects"].append({
                "owner": match.group(3),
                "start": "0x%08X" % start,
                "size": "0x%X" % size,
                "end": "0x%08X" % (start + size),
            })
    return result


def map_symbol_addresses(path: Path, names: set[str]) -> dict[str, str]:
    """Return exact addresses for selected bare symbol rows in a linker map."""
    if not path.is_file():
        return {}
    addresses = {}
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if match := MAP_SYMBOL_RE.match(line):
            address, name = int(match.group(1), 16), match.group(2)
            if name in names:
                addresses.setdefault(name, "0x%08X" % address)
    return addresses


def parse_baserom_incbin_ranges(text: str) -> list[dict[str, object]]:
    """Record visible JP ROM ranges without interpreting their byte payloads."""
    ranges = []
    for line_number, line in enumerate(text.splitlines(), 1):
        if not (match := BASEROM_INCBIN_RANGE_RE.match(line)):
            continue
        offset, size = int(match.group(1), 0), int(match.group(2), 0)
        ranges.append({
            "line": line_number,
            "file_offset": "0x%X" % offset,
            "size": "0x%X" % size,
            "rom_start": "0x%08X" % (0x08000000 + offset),
            "rom_end": "0x%08X" % (0x08000000 + offset + size),
            "directive": line.strip(),
        })
    return ranges


def event_script_include_context(text: str) -> list[dict[str, object]]:
    """Record every top-level include with a separate map-owner interpretation.

    A map ``scripts.inc`` include identifies a structural map boundary.  Other
    includes remain visible as physical context, but never become map owners.
    """
    includes = []
    for line_number, line in enumerate(text.splitlines(), 1):
        if not (match := ASM_INCLUDE_RE.match(line)):
            continue
        path = match.group(1)
        map_match = MAP_NAME_RE.match(line)
        includes.append({
            "line": line_number,
            "path": path,
            "map_owner": map_match.group(1) if map_match else None,
        })
    return includes


def map_artifact_state(root: Path, name: str) -> dict[str, bool]:
    """Return structural artifacts without treating them as semantic review."""
    directory = root / "data" / "maps" / name
    return {
        "map_json": (directory / "map.json").is_file(),
        "scripts_inc": (directory / "scripts.inc").is_file(),
        "events_inc": (directory / "events.inc").is_file(),
        "header_inc": (directory / "header.inc").is_file(),
    }


def us_map_candidates_between(
        before: str | None, after: str | None, us_map_order: list[str]) -> tuple[list[str], str]:
    """Use US map order only as a candidate list between JP map anchors."""
    positions = {name: index for index, name in enumerate(us_map_order)}
    if before is None or after is None:
        return [], "missing_jp_map_anchor"
    if before not in positions or after not in positions:
        return [], "jp_anchor_missing_from_us_order"
    start, end = positions[before] + 1, positions[after]
    if start > end:
        return [], "us_anchor_order_conflict"
    candidates = us_map_order[start:end]
    return candidates, ("single_us_map_owner_candidate" if len(candidates) == 1 else
                        "no_us_map_owner_between_anchors" if not candidates else
                        "multiple_us_map_owner_candidates")


def top_level_event_script_raw_manifest(
        root: Path, us_root: Path, text: str, us_text: str,
        us_script_data_objects: list[str]) -> dict[str, object]:
    """Describe raw top-level EventScript spans without inventing byte owners.

    The direct JP facts are the raw range and nearest includes.  The optional
    US candidate list is an order-only comparison; it cannot determine which
    bytes belong to a map, shared script, or map text in the JP ROM.
    """
    ranges = parse_baserom_incbin_ranges(text)
    jp_includes = event_script_include_context(text)
    us_map_order = [item["map_owner"] for item in event_script_include_context(us_text)
                    if item["map_owner"]]
    raw_records = []
    for raw in ranges:
        previous = next((item for item in reversed(jp_includes)
                         if item["line"] < raw["line"]), None)
        following = next((item for item in jp_includes if item["line"] > raw["line"]), None)
        previous_map = next((item["map_owner"] for item in reversed(jp_includes)
                             if item["line"] < raw["line"] and item["map_owner"]), None)
        following_map = next((item["map_owner"] for item in jp_includes
                              if item["line"] > raw["line"] and item["map_owner"]), None)
        candidates, classification = us_map_candidates_between(
            previous_map, following_map, us_map_order)
        raw_records.append({
            **raw,
            "owner_status": "top_level_raw_unstructured",
            "previous_include": previous,
            "next_include": following,
            "previous_map_owner": previous_map,
            "next_map_owner": following_map,
            "us_map_owner_candidates": [{
                "name": name,
                "jp_artifacts": map_artifact_state(root, name),
                "us_artifacts": map_artifact_state(us_root, name),
                "semantic_review": "not_recorded",
            } for name in candidates],
            "map_owner_classification": classification,
            "us_script_data_owner": (
                "data/event_scripts.o" if "data/event_scripts.o" in us_script_data_objects else None),
            "us_script_data_owner_evidence": (
                "US linker object only; it does not attribute JP raw bytes to a map or text owner."),
        })

    runs = []
    for record in raw_records:
        start, end = int(record["rom_start"], 16), int(record["rom_end"], 16)
        if runs and runs[-1]["end"] == start and not any(
                item["line"] > runs[-1]["last_line"] and item["line"] < record["line"]
                for item in jp_includes):
            runs[-1]["ranges"].append(record["line"])
            runs[-1]["end"] = end
            runs[-1]["last_line"] = record["line"]
            continue
        runs.append({
            "start": start,
            "end": end,
            "ranges": [record["line"]],
            "last_line": record["line"],
        })
    raw_runs = [{
        "rom_start": "0x%08X" % run["start"],
        "rom_end": "0x%08X" % run["end"],
        "size": "0x%X" % (run["end"] - run["start"]),
        "raw_range_lines": run["ranges"],
        "owner_status": "top_level_raw_unstructured",
    } for run in runs]
    return {
        "method": {
            "jp_role": "ROM ranges and physical include neighbors",
            "us_role": "script_data source ownership and map-order candidates only",
            "rule": "Existing scripts.inc artifacts never establish raw-byte or semantic ownership.",
        },
        "raw_ranges": raw_records,
        "raw_runs": raw_runs,
        "first_unstructured_raw_run": raw_runs[0] if raw_runs else None,
    }


def script_data_progress(root: Path, us_root: Path) -> dict[str, object]:
    """Join US owner order with JP's actual linked ``script_data`` evidence.

    The report is deliberately conservative.  It exposes owner gaps, named
    JP anchors, and raw ranges, but marks every non-terminal partition as
    requiring a separate semantic/byte-boundary review.
    """
    jp_linker = root / "ld_script_jp.txt"
    us_linker = us_root / "ld_script.ld"
    jp_map = root / "pokeemerald_jp.map"
    us_map = us_root / "pokeemerald.map"
    event_scripts = root / "data/event_scripts.s"
    event_scripts_text = event_scripts.read_text(encoding="utf-8", errors="replace") \
        if event_scripts.is_file() else ""
    jp_linker_objects = parse_script_data_linker_objects(jp_linker)
    us_linker_objects = parse_script_data_linker_objects(us_linker)
    jp_map_data = parse_script_data_map(jp_map)
    us_map_data = parse_script_data_map(us_map)
    anchor_owners = {symbol: owner for owner, symbol in SCRIPT_DATA_OWNER_ANCHORS}
    jp_anchors = map_symbol_addresses(jp_map, set(anchor_owners))
    us_anchors = map_symbol_addresses(us_map, set(anchor_owners))
    anchors = [{
        "symbol": symbol,
        "us_owner": owner,
        "jp_address": jp_anchors.get(symbol),
        "us_address": us_anchors.get(symbol),
        "jp_status": "present" if symbol in jp_anchors else "missing",
    } for owner, symbol in SCRIPT_DATA_OWNER_ANCHORS]

    jp_section = jp_map_data["section"]
    mystery_start = jp_anchors.get("gMysteryEventScriptCmdTable")
    mystery_end = jp_anchors.get("gMysteryEventScriptCmdTableEnd")
    candidate_splits = []
    if mystery_start and mystery_end and jp_section:
        start, end = int(mystery_start, 16), int(mystery_end, 16)
        if start < end:
            mystery_owner = "data/mystery_event_script_cmd_table.o"
            linked_object = next((item for item in jp_map_data["objects"]
                                  if item["owner"] == mystery_owner), None)
            linked_exactly = bool(linked_object and linked_object["start"] == mystery_start
                                  and linked_object["end"] == mystery_end)
            candidate_splits.append({
                "owner": mystery_owner,
                "source": "data/mystery_event_script_cmd_table.s",
                "start": mystery_start,
                "end": mystery_end,
                "size": "0x%X" % (end - start),
                "terminal_section_range": end == int(jp_section["end"], 16),
                "linked_object": linked_object,
                "status": ("linked_as_named_owner" if linked_exactly else
                           "ready_for_zero_displacement_owner_split"
                           if end == int(jp_section["end"], 16)
                           else "requires_boundary_review"),
                "evidence": [
                    "JP linker-map labels define the table interval.",
                    "The interval reaches the current JP script_data end.",
                    "US linker order places the named table last.",
                ],
            })

    jp_only_owners = [owner for owner in jp_linker_objects if owner not in us_linker_objects]
    missing_jp_owners = [owner for owner in us_linker_objects if owner not in jp_linker_objects]
    return {
        "method": {
            "us_role": "owner_order_and_source_structure_only",
            "jp_role": "actual_addresses_and_partition_evidence",
            "rule": "US numeric addresses are never used as JP partition boundaries.",
        },
        "linker": {
            "jp_objects": jp_linker_objects,
            "us_objects": us_linker_objects,
            "missing_jp_owners": missing_jp_owners,
            "jp_only_owners": jp_only_owners,
            "jp_matches_us_owner_order": jp_linker_objects == us_linker_objects,
        },
        "linked_sections": {
            "jp": jp_map_data,
            "us": us_map_data,
        },
        "anchors": anchors,
        "event_scripts_raw_baserom_ranges": parse_baserom_incbin_ranges(event_scripts_text),
        "top_level_event_script_raw_owners": top_level_event_script_raw_manifest(
            root, us_root, event_scripts_text,
            (us_root / "data/event_scripts.s").read_text(encoding="utf-8", errors="replace")
            if (us_root / "data/event_scripts.s").is_file() else "",
            us_linker_objects),
        "candidate_splits": candidate_splits,
        "semantic_review": {
            "status": "not_recorded",
            "note": "Only explicitly verified terminal ranges are candidates; all other owner partitions require JP byte-boundary review.",
        },
    }


def map_convergence_progress(root: Path) -> dict[str, object]:
    """Audit map records across the three JP source streams.

    The check starts with the first map in data/event_scripts.s and joins it
    to data/data_b2d_mid26.s (events) and data/maps.s (headers,
    layouts, and tilesets).  It records aliases and raw ranges as work items;
    a present include or generated file is deliberately never a semantic pass.
    """
    event_scripts_path = root / "data/event_scripts.s"
    events_path = root / "data/data_b2d_mid26.s"
    map_data_path = root / "data/maps.s"
    layouts_path = root / "data/layouts/layouts.inc"
    event_scripts_text = event_scripts_path.read_text(encoding="utf-8", errors="replace") \
        if event_scripts_path.is_file() else ""
    events_text = events_path.read_text(encoding="utf-8", errors="replace") if events_path.is_file() else ""
    map_data_text = map_data_path.read_text(encoding="utf-8", errors="replace") \
        if map_data_path.is_file() else ""
    layouts_text = layouts_path.read_text(encoding="utf-8", errors="replace") \
        if layouts_path.is_file() else ""
    map_root = root / "data/maps"
    metadata = map_metadata(root)
    header_labels: dict[str, str] = {}
    for name, payload in metadata.items():
        map_id = payload.get("id")
        header_name = payload.get("name")
        if isinstance(map_id, str):
            header_labels[name] = map_id
            if isinstance(header_name, str):
                header_labels[header_name] = map_id

    script_order = map_includes(event_scripts_path, MAP_NAME_RE)
    event_order = map_includes(events_path, MAP_EVENTS_RE)
    headers = map_headers(map_data_text, root, header_labels)
    aliases = map_event_aliases(events_text)
    shared_symbols = set()
    for payload in metadata.values():
        for field, suffix in (("shared_events_map", "MapEvents"),
                              ("shared_scripts_map", "MapScripts")):
            if owner := shared_map_target(payload, field):
                shared_symbols.add(f"{owner}_{suffix}")
    defined_shared_symbols = assembly_label_names(root, shared_symbols)
    # Headers remain in the map-data stream, while migrated layout owners
    # live in data/layouts/layouts.inc. Combine their label blocks so a direct
    # canonical header reference is not reported as an undefined layout.
    blocks = asm_label_blocks(map_data_text + "\n" + layouts_text)

    ordered_names = list(dict.fromkeys(script_order + event_order + sorted(metadata)))
    records = []
    for name in ordered_names:
        meta = metadata.get(name, {})
        map_id = meta.get("id")
        layout = meta.get("layout")
        header = headers.get(map_id, {}) if isinstance(map_id, str) else {}
        expected_events = f"{name}_MapEvents"
        expected_scripts = f"{name}_MapScripts"
        expected_layout = layout_symbol(layout) if isinstance(layout, str) else None
        shared_events_owner = shared_map_target(meta, "shared_events_map")
        shared_scripts_owner = shared_map_target(meta, "shared_scripts_map")
        shared_events_target = (f"{shared_events_owner}_MapEvents"
                                if shared_events_owner else None)
        shared_scripts_target = (f"{shared_scripts_owner}_MapScripts"
                                 if shared_scripts_owner else None)
        event_alias = ("gMapEvents_" + map_id.removeprefix("MAP_")) \
            if isinstance(map_id, str) else None
        actual_events = header.get("events")
        events_shared = bool(shared_events_target
                             and actual_events == shared_events_target
                             and shared_events_target in defined_shared_symbols)
        scripts_shared = bool(shared_scripts_target
                              and header.get("mapScripts") == shared_scripts_target
                              and shared_scripts_target in defined_shared_symbols)
        if actual_events == expected_events:
            event_pointer_status = "direct"
        elif events_shared:
            event_pointer_status = "shared"
        elif event_alias and actual_events == event_alias and aliases.get(event_alias) == expected_events:
            event_pointer_status = "legacy_alias"
        elif actual_events is None:
            event_pointer_status = "missing_header"
        else:
            event_pointer_status = "other"
        actual_scripts = header.get("mapScripts")
        script_pointer_status = ("direct" if actual_scripts == expected_scripts else
                                 "shared" if scripts_shared else
                                 "missing_header" if actual_scripts is None else "shared_or_other")
        actual_layout = header.get("mapLayout")
        layout_pointer_status = ("direct" if expected_layout and actual_layout == expected_layout else
                                 "missing_header" if actual_layout is None else "other")

        layout_block = blocks.get(expected_layout, "") if expected_layout else ""
        primary_tileset = annotated_pointer(layout_block, "primaryTileset") if layout_block else None
        secondary_tileset = annotated_pointer(layout_block, "secondaryTileset") if layout_block else None
        resource_chain = {
            "layout_symbol": expected_layout,
            "layout_defined": bool(layout_block),
            "primary_tileset": tileset_resource_chain(blocks, primary_tileset),
            "secondary_tileset": tileset_resource_chain(blocks, secondary_tileset),
        }
        resource_chain["raw_baserom_source_count"] = (
            resource_chain["primary_tileset"]["raw_baserom_source_count"]
            + resource_chain["secondary_tileset"]["raw_baserom_source_count"])

        scripts_file = map_root / name / "scripts.inc"
        events_file = map_root / name / "events.inc"
        scripts_text = scripts_file.read_text(encoding="utf-8", errors="replace") \
            if scripts_file.is_file() else ""
        events_file_text = events_file.read_text(encoding="utf-8", errors="replace") \
            if events_file.is_file() else ""
        actions = ["semantic_review_required"]
        if not scripts_file.is_file() and not scripts_shared:
            actions.append("create_or_recover_scripts_inc")
        if not events_file.is_file() and not events_shared:
            actions.append("generate_or_recover_events_inc_from_map_json")
        if name not in script_order and not scripts_shared:
            actions.append("restore_upper_scripts_include")
        if name not in event_order and not events_shared:
            actions.append("restore_upper_events_include")
        if event_pointer_status == "legacy_alias":
            actions.append("replace_event_header_alias_with_real_label")
        if event_pointer_status == "other":
            actions.append("audit_event_header_target")
        if script_pointer_status == "shared_or_other":
            actions.append("audit_map_script_header_target")
        if layout_pointer_status == "other":
            actions.append("audit_map_layout_header_target")
        script_raw = raw_baserom_directives(scripts_text)
        event_raw = raw_baserom_directives(events_file_text)
        if script_raw:
            actions.append("split_map_owned_script_baserom_range")
        if event_raw:
            actions.append("split_map_owned_event_baserom_range")
        if resource_chain["raw_baserom_source_count"]:
            actions.append("split_map_resource_baserom_range")
        structure = {
            "scripts": scripts_file.is_file() or scripts_shared,
            "events": (events_file.is_file() and name in event_order) or events_shared,
        }
        structure["complete"] = bool(name in metadata and structure["scripts"] and structure["events"])
        records.append({
            "name": name,
            "map_id": map_id,
            "script_stream_index": script_order.index(name) + 1 if name in script_order else None,
            "event_stream_index": event_order.index(name) + 1 if name in event_order else None,
            "artifacts": {
                "map_json": name in metadata,
                "scripts_inc": scripts_file.is_file(),
                "events_inc": events_file.is_file(),
                "upper_scripts_include": name in script_order,
                "upper_events_include": name in event_order,
            },
            "header": header,
            "events": {
                "expected": expected_events,
                "legacy_alias": event_alias,
                "actual": actual_events,
                "status": event_pointer_status,
                "shared_owner": shared_events_owner if events_shared else None,
                "shared_target": shared_events_target if events_shared else None,
            },
            "scripts": {
                "expected": expected_scripts,
                "actual": actual_scripts,
                "status": script_pointer_status,
                "shared_owner": shared_scripts_owner if scripts_shared else None,
                "shared_target": shared_scripts_target if scripts_shared else None,
                "raw_baserom_directives": script_raw,
            },
            "layout": {
                "expected": expected_layout,
                "actual": actual_layout,
                "status": layout_pointer_status,
                "resource_chain": resource_chain,
            },
            "events_raw_baserom_directives": event_raw,
            "structure": structure,
            "semantic_review": "not_recorded",
            "required_actions": actions,
        })

    event_statuses = Counter(record["events"]["status"] for record in records)
    script_statuses = Counter(record["scripts"]["status"] for record in records)
    resource_raw_maps = sum(bool(record["layout"]["resource_chain"]["raw_baserom_source_count"])
                            for record in records)
    return {
        "stream_files": {
            "scripts": "data/event_scripts.s",
            "events": "data/data_b2d_mid26.s",
            "map_data": "data/maps.s",
            "layouts": "data/layouts/layouts.inc",
        },
        "script_stream_maps": len(script_order),
        "event_stream_maps": len(event_order),
        "maps_in_both_streams": len(set(script_order) & set(event_order)),
        "header_records": len(headers),
        "event_pointer_statuses": dict(sorted(event_statuses.items())),
        "script_pointer_statuses": dict(sorted(script_statuses.items())),
        "valid_shared_events_maps": sum(record["events"]["status"] == "shared" for record in records),
        "valid_shared_scripts_maps": sum(record["scripts"]["status"] == "shared" for record in records),
        "maps_with_raw_script_ranges": sum(bool(record["scripts"]["raw_baserom_directives"])
                                           for record in records),
        "maps_with_raw_event_ranges": sum(bool(record["events_raw_baserom_directives"])
                                          for record in records),
        "maps_with_raw_resource_ranges": resource_raw_maps,
        "top_level_raw_baserom_directives": {
            "data/event_scripts.s": raw_baserom_directives(event_scripts_text),
            "data/data_b2d_mid26.s": raw_baserom_directives(events_text),
            "data/maps.s": raw_baserom_directives(map_data_text),
        },
        "semantic_review": {
            "status": "not_recorded",
            "note": "Map files and direct pointers are structural evidence only; every record still requires semantic review.",
        },
        "records": records,
    }


def classify_incbin_resource(resource: str) -> tuple[str, str]:
    """Classify an INCBIN path without treating named encoded assets as raw.

    A ``.bin`` container or an encoded stream outside an asset tree still
    needs a source-owner audit.  Conversely, a named LZ/RL/Huff resource in
    ``graphics/`` or ``sound/`` is already a final, structured asset owner:
    it must be validated against the ROM, but it is not an anonymous raw span
    waiting to be split.  Keeping those cases separate makes the progress
    report useful after byte-exact asset migrations.
    """
    path = Path(resource)
    suffix = path.suffix or "[no suffix]"
    asset_root = path.parts and path.parts[0] in {"graphics", "sound"}
    encoded_asset = asset_root and suffix in {".lz", ".rl", ".huff"}
    anonymous_asset = path.name.lower().startswith(("gunknown", "unknown", "unk"))
    raw = suffix in {".bin", ".gba", ".lz", ".rl", ".huff"} and (
        not encoded_asset or anonymous_asset
    )
    if encoded_asset:
        if anonymous_asset:
            return "raw_binary", "anonymous_encoded_asset"
        return "structured_or_encoded", "named_encoded_asset"
    if raw:
        return "raw_binary", "raw_suffix_or_container"
    return "structured_or_encoded", "structured_suffix"


def incbin_progress(root: Path) -> dict[str, object]:
    references = []
    for relpath in sorted(source_files(root)):
        path = root / relpath
        if path.suffix not in {".s", ".inc", ".c", ".h"}:
            continue
        for resource in INCBIN_RE.findall(path.read_text(encoding="utf-8", errors="replace")):
            suffix = Path(resource).suffix or "[no suffix]"
            classification, classification_reason = classify_incbin_resource(resource)
            references.append({
                "owner": relpath,
                "resource": resource,
                "suffix": suffix,
                "classification": classification,
                "classification_reason": classification_reason,
                "exists": (root / resource).is_file(),
                "suggested_action": (
                    "decode_or_split_into_named_asset" if classification == "raw_binary"
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


def map_progress(root: Path, us_root: Path, convergence: dict[str, object]) -> dict[str, object]:
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
    artifacts = map_artifact_progress(root, convergence["records"])
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
        **artifacts,
        "structure_complete_owner_maps": len(set(artifacts["structure_complete_map_names"]) & owner_names),
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
    convergence = map_convergence_progress(root)
    maps = map_progress(root, us_root, convergence)
    script_data = script_data_progress(root, us_root)

    return {
        "schema": 3,
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
        "maps": maps,
        "map_convergence": convergence,
        "script_data": script_data,
        "jp_only_c_manifest": manifest,
    }


def print_report(report: dict[str, object]) -> None:
    files = report["files"]
    modules = report["c_modules"]
    functions = report["functions"]
    maps = report["maps"]
    convergence = report["map_convergence"]
    script_data = report["script_data"]
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
    print("JP-only C migration records (dynamic, not legacy fixed count): %d" %
          len(report["jp_only_c_manifest"]))
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
    print("map structure: owners=%d owner-scripts=%d (%.2f%%) non-owner=%d included=%d; "
          "map.json=%d events.inc=%d upper-events=%d structure-complete=%d "
          "(direct=%d owner=%d shared-scripts/events=%d/%d); semantic-review=%s" % (
        maps["map_table_owners"], maps["first_owner_scripts_inc"], maps["jp_scripts_owner_rate"] * 100,
        maps["non_owner_scripts_inc"],
        maps["event_script_included_owners"], maps["jp_map_json"], maps["jp_events_inc"],
        maps["upper_event_includes"], maps["structure_complete_maps"],
        maps["direct_structure_complete_maps"], maps["structure_complete_owner_maps"],
        maps["shared_scripts_maps"], maps["shared_events_maps"], maps["semantic_review"]["status"]))
    raw_streams = convergence["top_level_raw_baserom_directives"]
    print("map convergence: script-stream=%d event-stream=%d shared=%d headers=%d; "
          "event-pointers=%s; map raw scripts/events/resources=%d/%d/%d; "
          "top-level raw scripts/mid26/maps=%d/%d/%d; semantic-review=%s" % (
              convergence["script_stream_maps"], convergence["event_stream_maps"],
              convergence["maps_in_both_streams"], convergence["header_records"],
              ",".join("%s=%d" % item for item in convergence["event_pointer_statuses"].items()),
              convergence["maps_with_raw_script_ranges"], convergence["maps_with_raw_event_ranges"],
              convergence["maps_with_raw_resource_ranges"],
              len(raw_streams["data/event_scripts.s"]),
              len(raw_streams["data/data_b2d_mid26.s"]),
              len(raw_streams["data/maps.s"]),
              convergence["semantic_review"]["status"]))
    jp_section = script_data["linked_sections"]["jp"]["section"]
    print("script_data: JP owners=%d/%d US; JP section=%s; missing owners=%d; "
          "visible event-script raw ranges=%d; safe terminal candidates=%d" % (
              len(script_data["linker"]["jp_objects"]), len(script_data["linker"]["us_objects"]),
              ("%s..%s" % (jp_section["start"], jp_section["end"])) if jp_section else "unavailable",
              len(script_data["linker"]["missing_jp_owners"]),
              len(script_data["event_scripts_raw_baserom_ranges"]),
              sum(candidate["status"] == "ready_for_zero_displacement_owner_split"
                  for candidate in script_data["candidate_splits"])))


def render_markdown_report(report: dict[str, object]) -> str:
    """Render the reproducible human-facing progress report without a timestamp."""
    functions = report["functions"]
    incbin = report["incbin"]
    assets = report["asset_naming"]
    maps = report["maps"]
    convergence = report["map_convergence"]
    script_data = report["script_data"]
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
        f"- JP 独有 C 迁移记录：{len(report['jp_only_c_manifest'])}（动态清单，不沿用旧固定数）；同名多地址 C 定义："
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
        f"非 owner scripts.inc：{maps['non_owner_scripts_inc']}；结构完整地图："
        f"{maps['structure_complete_maps']}（直接物理文件满足者 "
        f"{maps['direct_structure_complete_maps']}；合法共享 scripts/events owner "
        f"{maps['shared_scripts_maps']}/{maps['shared_events_maps']}；其中首 owner "
        f"{maps['structure_complete_owner_maps']}）；map.json 总数：{maps['jp_map_json']}。",
        f"- 地图语义复核：{maps['semantic_review']['status']}。没有版本化复核清单前，"
        "任何 scripts.inc、map.json 或 events.inc 都不计入语义已审计。",
        f"- 三流地图会合：scripts 流 {convergence['script_stream_maps']}、events 流 "
        f"{convergence['event_stream_maps']}、共有 {convergence['maps_in_both_streams']}、"
        f"地图头 {convergence['header_records']}；事件指针状态 "
        + "、".join(f"{name}={count}" for name, count in convergence['event_pointer_statuses'].items())
        + f"；地图内裸 baserom 范围（脚本/事件/资源）={convergence['maps_with_raw_script_ranges']}/"
        f"{convergence['maps_with_raw_event_ranges']}/{convergence['maps_with_raw_resource_ranges']}。",
        f"- script_data 顶层边界：JP linker 明确 owner {len(script_data['linker']['jp_objects'])}/"
        f"US {len(script_data['linker']['us_objects'])}；待补 JP owner "
        f"{len(script_data['linker']['missing_jp_owners'])}；可见 event_scripts 原始 baserom 范围 "
        f"{len(script_data['event_scripts_raw_baserom_ranges'])}。US 只定义 owner 顺序，JP 范围必须由"
        " JP map/ROM 锚点确认。",
        "",
        "## 指标定义",
        "",
        "| 指标 | 口径 |",
        "| --- | --- |",
        "| 严格 C 转换率 | 默认预处理分支中有 C 函数体、非 `naked` 且不与 selected naked 定义重叠的唯一 funcmap ROM 地址 / funcmap 唯一地址；同名 static 按 source owner 和地址保留，不建立名称→地址覆盖表。 |",
        "| 模块归位率 | 严格 C 地址中能按 US 标准名在 US 源树找到定义的地址 / 严格 C 地址。 |",
        "| 路径对齐率 | 上述地址中 JP 相对 `src/` 路径也属于 US owner 的地址 / 严格 C 地址。 |",
        "| 过渡文件 | 文件名包含 tail、rest、mid、stub 或地址式片段；分类可重叠。 |",
        "| incbin | `.incbin` 与 `INCBIN_*` 的引用数。裸 `.bin/.gba`、asset 根目录外的压缩流，以及 `gUnknown`/`unknown`/`unk` 命名的压缩资产记为原始；`graphics/`、`sound/` 内其余具名 `.lz/.rl/.huff` 记为已结构化编码资产。不是字节转换率。 |",
        "| 资产命名 | 被引用的 `graphics/`、`sound/` 路径与 US 同名文件比较；仅生成候选，不自动改名。 |",
        "| 地图脚本 owner | `scripts.inc` 与 map-table 实际首 owner 名的交集 / 去重首 owner；共享表只属于首次出现地图。 |",
        "| 地图结构完整 | 同一地图具 `map.json`，且其 scripts/events 为本地图的物理文件与上层 include，或为 map.json 明示、header 精确指向且在 JP `data/` 有真实标签定义的共享 owner；只说明结构已拆分。 |",
        "| 地图语义复核 | 仅接受未来版本化复核清单的显式记录；当前为 `not_recorded`，绝不从目录或 include 推断。 |",
        "| 三流地图会合 | 以 `data/event_scripts.s`、`data/data_b2d_mid26.s`、`data/maps.s` 的同图记录连接 scripts、events、地图头/布局/tileset。别名和 baserom 范围均为待办，不构成完成。 |",
        "| script_data 顶层分区 | US linker 提供 8 个对象的目标 owner 顺序；JP linker map 提供实际范围和锚点。只在 JP 起止标签、末尾位置与 ROM 比对均成立时，才允许拆出一个 owner。 |",
        "| JP 独有 C 迁移清单 | 已映射、非裸汇编、但无 US 标准 C owner 的函数模块；动态分类，不沿用失效的固定“38 个”计数。 |",
        "",
        "## 复现与输入",
        "",
        "```sh",
        "python3 tools/audit_structure.py",
        "python3 tools/audit_structure.py --json --output build/audit-structure.json \\",
        "    --manifest build/jp-only-c-manifest.json",
        "python3 tools/audit_structure.py --transition-manifest build/transition-file-manifest.json",
        "python3 tools/audit_structure.py --map-convergence-manifest build/map-convergence-manifest.json",
        "python3 tools/audit_structure.py --script-data-manifest build/script-data-manifest.json",
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
    parser.add_argument("--transition-manifest", type=Path,
                        help="write only the transition-file manifest JSON")
    parser.add_argument("--map-convergence-manifest", type=Path,
                        help="write only the three-stream map convergence manifest JSON")
    parser.add_argument("--script-data-manifest", type=Path,
                        help="write only the script_data owner and boundary manifest JSON")
    parser.add_argument("--markdown-output", type=Path,
                        help="atomically write the human-readable Markdown progress report")
    args = parser.parse_args()
    if args.output:
        require_destination_kind(args.output, "json")
    if args.manifest:
        require_destination_kind(args.manifest, "json")
    if args.transition_manifest:
        require_destination_kind(args.transition_manifest, "json")
    if args.map_convergence_manifest:
        require_destination_kind(args.map_convergence_manifest, "json")
    if args.script_data_manifest:
        require_destination_kind(args.script_data_manifest, "json")
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
    if args.transition_manifest:
        write_output(args.transition_manifest, json.dumps(report["transition_manifest"], ensure_ascii=False,
                                                           indent=2, sort_keys=True) + "\n")
    if args.map_convergence_manifest:
        write_output(args.map_convergence_manifest, json.dumps(report["map_convergence"], ensure_ascii=False,
                                                                indent=2, sort_keys=True) + "\n")
    if args.script_data_manifest:
        write_output(args.script_data_manifest, json.dumps(report["script_data"], ensure_ascii=False,
                                                            indent=2, sort_keys=True) + "\n")
    if args.markdown_output:
        write_output(args.markdown_output, render_markdown_report(report))
    if args.json:
        print(encoded, end="")
    else:
        print_report(report)


if __name__ == "__main__":
    main()
