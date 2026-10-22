#!/usr/bin/env python3
"""Reproducible structural audit for pokeemerald-jp and pokeemerald.

The report deliberately keeps several progress measures separate.  A C
object can contain ``__attribute__((naked))`` assembly, and a JP source file
can be split differently from its upstream counterpart.  Neither condition
means that its source is strict C or that its module has reached its upstream
home.  This script reports those facts independently instead of blending them
into a single percentage.

Source inventories do not require a build.  Function-address metrics require
the JP ELF symbol table and linker input-object ranges; absent or ambiguous
evidence remains unresolved, rather than being guessed from US names.
The map-owner metric parses the matching ``baserom_jp.gba`` through the
repository map emitter.  The default is a short human-readable report;
``--json`` is the stable machine-readable form and ``--manifest`` writes the
JP-only code-module inventory used to plan migrations.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import tempfile
from bisect import bisect_right
from collections import Counter, defaultdict
from dataclasses import asdict, dataclass, replace
from pathlib import Path

try:
    from jp_map_metadata import layout_symbol
    from audit_resource_references import collect_resource_references
    from map_semantic_review import map_review_progress
    from audit_us_reference import us_reference
except ModuleNotFoundError:
    from tools.jp_map_metadata import layout_symbol
    from tools.audit_resource_references import collect_resource_references
    from tools.map_semantic_review import map_review_progress
    from tools.audit_us_reference import us_reference


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
    inline: bool = False
    declared_name: str | None = None
    macro: str | None = None
    macro_verified: bool = True
    name_inputs: tuple[tuple[str, str], ...] = ()
    link_name: str | None = None
    link_name_verified: bool = True

    @property
    def emitted_name(self) -> str:
        """The ELF spelling, never a replacement for the C source name."""
        return self.link_name if self.link_name is not None else self.name


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


def active_preprocessor_text(text: str, *, keep_directives: bool = False,
                             defines: dict[str, int] | None = None) -> str:
    """Blank inactive branches while preserving offsets and line positions.

    With no explicit defines, use the default configuration: feature macros such
    as ``NONMATCHING`` are undefined, and the C99-era ``__STDC_VERSION__`` is
    available.  This prevents the mutually exclusive C and NAKED branches
    from being counted together. Literal target-specific build defines select
    additional proven object modes; arbitrary inactive bodies are never added.
    """
    macros = {"__STDC__": 1, "__STDC_VERSION__": 199901, **(defines or {})}
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
            if keep_directives and active and command in {"define", "include", "undef"}:
                result.append(line)
            else:
                result.append("".join("\n" if char == "\n" else " " for char in line))
        elif active:
            result.append(line)
        else:
            result.append("".join("\n" if char == "\n" else " " for char in line))
    return "".join(result)


def libc_function_macros(path: Path, root: Path, text: str) -> tuple[set[str], dict[str, str | None], tuple[tuple[str, str], ...]]:
    """Read supported libc naming macros from actual local build headers.

    These are the include directories used by the repository libc recipes,
    not a guessed US-name table.  Follow actual includes (string.h also
    includes _ansi.h); only identifier-to-identifier aliases are supported.
    Missing/unknown macro
    definitions remain unverified and cannot contribute to address metrics.
    """
    verified, aliases, inputs, visited = set(), {}, [], set()
    def scan(current: Path, selected: str) -> None:
        for line in selected.splitlines():
            include = re.fullmatch(r'\s*#\s*include\s*([<"])([^>"]+)[>"]\s*', line)
            if include:
                kind, header = include.groups()
                if Path(header).is_absolute() or ".." in Path(header).parts:
                    continue
                directories = ((current.parent,) if kind == '"' else ()) + (
                    root / "tools/agbcc-src/libc/include", root / "tools/agbcc-src/ginclude",
                    root / "tools/agbcc-src/libc/stdlib")
                found = next((directory / header for directory in directories if (directory / header).is_file()), None)
                if found is not None and found not in visited:
                    visited.add(found)
                    data = found.read_bytes()
                    inputs.append((found.relative_to(root).as_posix(), hashlib.sha256(data).hexdigest()))
                    scan(found, active_preprocessor_text(data.decode("utf-8", errors="replace"), keep_directives=True))
                continue
            undef = re.fullmatch(r'\s*#\s*undef\s+([A-Za-z_]\w*)\s*', line)
            if undef:
                aliases.pop(undef.group(1), None)
                verified.discard(undef.group(1))
                continue
            function = re.fullmatch(r'\s*#\s*define\s+(_DEFUN|_DEFUN_VOID)\(([^)]*)\)\s+(.+?)\s*', line)
            if function:
                name, args, value = function.groups()
                verified.discard(name)
                args = re.sub(r'\s+', '', args)
                value = re.sub(r'\s+', '', value)
                if ((name == "_DEFUN" and args == "name,arglist,args" and value == "name(args)")
                        or (name == "_DEFUN_VOID" and args == "name" and value in {"name(_NOARGS)", "name()"})):
                    verified.add(name)
                continue
            alias = re.fullmatch(r'\s*#\s*define\s+([A-Za-z_]\w*)\s+([A-Za-z_]\w*)\s*', line)
            if alias:
                aliases[alias.group(1)] = alias.group(2)
                continue
            unknown = re.match(r'\s*#\s*define\s+([A-Za-z_]\w*)', line)
            if unknown:
                # Unsupported redefinitions must not leave an earlier
                # identifier alias looking verified.
                aliases[unknown.group(1)] = None
    scan(path, text)
    return verified, aliases, tuple(sorted(set(inputs)))


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


def function_declaration_suffix(text: str, probe: int) -> tuple[int, list[str | None]]:
    """Skip GNU attributes/asm names after a balanced parameter list.

    Only a literal assembler identifier is supported.  An expression, escaped
    spelling or unknown macro is not expanded or guessed into a link name.
    """
    names = []
    while True:
        while probe < len(text) and text[probe].isspace():
            probe += 1
        if probe < len(text) and text[probe] == "#":
            line_end = text.find("\n", probe)
            probe = len(text) if line_end == -1 else line_end + 1
            continue
        suffix = re.match(r"(?:__attribute__|asm|__asm|__asm__)\s*\(", text[probe:])
        if suffix is None:
            return probe, names
        open_pos = probe + suffix.end() - 1
        if suffix.group().startswith("__attribute__"):
            end = skip_balanced(text, open_pos)
        else:
            depth, end = 0, None
            for token in re.finditer(r'"(?:\\.|[^"\\])*"|[()]', text[open_pos:]):
                if token.group() == "(":
                    depth += 1
                elif token.group() == ")":
                    depth -= 1
                    if depth == 0:
                        end = open_pos + token.end()
                        break
        if end is None:
            return len(text), names + [None]
        if not suffix.group().startswith("__attribute__"):
            literal = re.fullmatch(r'\s*"([A-Za-z_]\w*)"\s*', text[open_pos + 1:end - 1])
            names.append(literal.group(1) if literal else None)
        probe = end


def function_link_names(text: str) -> dict[str, tuple[str | None, bool, int]]:
    """Collect explicit link names from this translation unit's declarations.

    Input is already build-branch selected. Comments, strings and nested
    scopes cannot supply a declaration; variables/function-pointer objects
    with an asm name are not function declarations.  Conflicting/unsupported
    declarations remain unverified instead of falling back to the C name.
    """
    quoted_or_comment = re.compile(
        r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\n]*|/\*[\s\S]*?\*/')
    clean = quoted_or_comment.sub(
        lambda match: "".join("\n" if char == "\n" else " " for char in match.group())
        if match.group().startswith(("//", "/*")) else match.group(), text)
    heads = quoted_or_comment.sub(
        lambda match: "".join("\n" if char == "\n" else " " for char in match.group()), clean)
    positions, depths, depth = [], [], 0
    for match in re.finditer(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|[{}]', clean):
        if match.group() in {"{", "}"}:
            depth += 1 if match.group() == "{" else -1
            positions.append(match.start())
            depths.append(depth)
    declarations, first_declarations = defaultdict(list), {}
    ignored = {"asm", "__asm", "__asm__", "__attribute__", "if", "for", "while", "switch", "sizeof"}
    for match in FUNCTION_HEAD_RE.finditer(heads):
        position = bisect_right(positions, match.start()) - 1
        if (position >= 0 and depths[position] != 0) or match.group("name") in ignored:
            continue
        end = skip_balanced(clean, match.end("head") - 1)
        if end is None:
            continue
        probe, names = function_declaration_suffix(clean, end)
        if names and probe < len(clean) and clean[probe] in ";{":
            declarations[match.group("name")].extend(names)
            first_declarations.setdefault(match.group("name"), match.start("head"))
    result = {}
    for name, values in declarations.items():
        unique = set(values)
        verified = len(unique) == 1 and None not in unique
        result[name] = (values[0] if verified else None, verified, first_declarations[name])
    return result


def function_definitions(path: Path, root: Path, *,
                         defines: dict[str, int] | None = None) -> list[FunctionDef]:
    """Find C definitions without counting prototypes or control statements."""
    original = path.read_text(encoding="utf-8", errors="replace")
    text = active_preprocessor_text(original, defines=defines)
    link_names = function_link_names(text)
    selected_directives = active_preprocessor_text(
        original, keep_directives=True, defines=defines) if "_DEFUN" in text else ""
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
        probe, _suffix_names = function_declaration_suffix(text, end)
        if probe >= len(text) or text[probe] != "{":
            continue
        # The expression consumes leading GNU attributes as part of this
        # declaration, so never scan into an earlier declaration for them.
        header = text[match.start("head"):probe]
        macro = name if name in {"_DEFUN", "_DEFUN_VOID"} else None
        declared_name = None
        macro_verified = True
        name_inputs = ()
        if macro:
            # Macro names are expanded at this definition, not using a
            # redefine/include/undef that appears later in the source.
            macros, aliases, name_inputs = libc_function_macros(
                path, root, selected_directives[:match.start("head")])
            first_argument = text[open_pos + 1:end - 1].split(",", 1)[0].strip()
            if not re.fullmatch(r"[A-Za-z_]\w*", first_argument):
                continue
            declared_name, name = first_argument, first_argument
            macro_verified = macro in macros
            visited = set()
            while name in aliases:
                if name in visited or aliases[name] is None:
                    macro_verified = False
                    break
                visited.add(name)
                name = aliases[name]
        link_name, link_name_verified, first_declaration = link_names.get(name, (None, True, -1))
        # A later asm declaration may be ignored by the compiler.  It cannot
        # retroactively redirect a definition to another function's symbol.
        link_name_verified = link_name_verified and first_declaration <= match.start("head")
        result.append(FunctionDef(
            path=path.relative_to(root / "src").as_posix(),
            name=name,
            naked="naked" in header or has_naked_macro_prefix(text, match.start("head")),
            inline=bool(re.search(r"\binline\b", header)),
            declared_name=declared_name, macro=macro, macro_verified=macro_verified,
            name_inputs=name_inputs if macro else (),
            link_name=link_name, link_name_verified=link_name_verified,
        ))
    counts = Counter(item.emitted_name for item in result if item.link_name_verified)
    collisions = {item.emitted_name for item in result
                  if item.link_name is not None and item.link_name_verified and counts[item.emitted_name] > 1}
    return [replace(item, link_name_verified=False) if item.emitted_name in collisions else item
            for item in result]


def c_compile_variants(root: Path) -> list[dict[str, object]]:
    """Read conservative alternate-object bindings from literal Make rules.

    Only unconditional C_BUILDDIR rules with a unique repository-local C
    first prerequisite, literal target-specific 'CPPFLAGS += -D...' and
    the project's explicit CPP/CC/AS recipe qualify.
    No Make expansion, shell execution, conditional selection, include or
    basename guess is used. Unsupported flags or conflicting rules reject
    that target. Actual ELF/link-map ownership remains separately required.
    """
    makefile = root / "Makefile"
    if not makefile.is_file():
        return []
    data = makefile.read_bytes()
    target_re = re.compile(
        r"^\$\(C_BUILDDIR\)/([A-Za-z0-9_/.-]+\.o):\s*(.*?)\s*$")
    define_re = re.compile(r"-D([A-Za-z_]\w*)(?:=(0[xX][0-9A-Fa-f]+|\d+))?")
    sources, defines, recipes, rejected = (
        defaultdict(set), defaultdict(dict), defaultdict(list), set())
    conditional_depth = 0
    recipe_target = None
    for raw in data.decode("utf-8", errors="replace").splitlines():
        if raw.startswith("\t"):
            if recipe_target:
                recipes[recipe_target].append(raw)
            continue
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        recipe_target = None
        if re.match(r"^(?:ifdef|ifndef|ifeq|ifneq)\b", line):
            conditional_depth += 1
            continue
        if re.match(r"^endif\b", line):
            conditional_depth = max(0, conditional_depth - 1)
            continue
        match = target_re.fullmatch(line)
        if match is None:
            continue
        target, value = match.groups()
        if ".." in Path(target).parts or line.endswith("\\"):
            rejected.add(target)
            continue
        cpp_assignment = re.match(r"CPPFLAGS\s*([:+?]?=)\s*(.*)$", value)
        prerequisites = [item for item in value.split()
                         if re.fullmatch(r"src/[A-Za-z0-9_/.-]+\.c", item)]
        if conditional_depth:
            if cpp_assignment or prerequisites:
                rejected.add(target)
            continue
        if cpp_assignment:
            operation, flags = cpp_assignment.groups()
            tokens = flags.split()
            if operation != "+=" or not tokens:
                rejected.add(target)
                continue
            for token in tokens:
                flag = define_re.fullmatch(token)
                if flag is None:
                    rejected.add(target)
                    continue
                name, number = flag.groups()
                value = (int(number, 16) if number and number.lower().startswith("0x")
                         else int(number, 10) if number else 1)
                if name in defines[target] and defines[target][name] != value:
                    rejected.add(target)
                defines[target][name] = value
        elif "=" not in value:
            if not prerequisites or value.split()[0] != prerequisites[0]:
                rejected.add(target)
                continue
            sources[target].update(prerequisites)
            recipe_target = target
    result = []
    for target in sorted(defines):
        if target in rejected or len(sources[target]) != 1:
            continue
        recipe = "\n".join(recipes[target])
        if not (re.search(r"\$\(CPP\)\s+\$\(CPPFLAGS\)\s+-P\s+-x\s+c\s+\$<\s+\|", recipe)
                and "$(or $(CC1),$(CC)) $(CFLAGS) -o - -" in recipe
                and "$(AS) $(ASFLAGS) -o $@ -" in recipe
                and "$@.gen.s" in recipe):
            continue
        relative = next(iter(sources[target]))
        source = root / relative
        if (".." in Path(relative).parts or not source.is_file()
                or not source.resolve().is_relative_to((root / "src").resolve())):
            continue
        owner = relative.removeprefix("src/")
        if Path(target).with_suffix(".c").as_posix() == owner:
            continue
        result.append({
            "source_owner": owner,
            "input_object": "src/" + target,
            "object_owner": Path(target).with_suffix(".c").as_posix(),
            "defines": dict(sorted(defines[target].items())),
            "makefile_sha256": hashlib.sha256(data).hexdigest(),
        })
    return result


def c_inventory(root: Path) -> list[FunctionDef]:
    """Select default bodies plus proven literal alternate compilation guards.

    Identical source definitions present in multiple compilation modes are
    counted once; different naked/link-name bodies stay distinct and cannot
    be promoted by a union of inactive configurations.
    """
    definitions = [definition for path in sorted((root / "src").glob("**/*.c"))
                   for definition in function_definitions(path, root)]
    by_definition = defaultdict(list)
    for index, definition in enumerate(definitions):
        by_definition[replace(definition, name_inputs=())].append(index)
    for variant in c_compile_variants(root):
        for definition in function_definitions(
                root / "src" / variant["source_owner"], root, defines=variant["defines"]):
            inputs = dict(definition.name_inputs)
            inputs["Makefile"] = variant["makefile_sha256"]
            key = replace(definition, name_inputs=())
            if key in by_definition:
                for index in by_definition[key]:
                    merged_inputs = dict(definitions[index].name_inputs)
                    merged_inputs.update(inputs)
                    definitions[index] = replace(
                        definitions[index], name_inputs=tuple(sorted(merged_inputs.items())))
            else:
                by_definition[key].append(len(definitions))
                definitions.append(replace(definition, name_inputs=tuple(sorted(inputs.items()))))
    return definitions


def standalone_asm_inventory(root: Path) -> list[dict[str, str]]:
    """Source owner/name inventory, not a ROM-address denominator."""
    result = set()
    pattern = re.compile(r'^\s*(thumb|arm)_func_start\s+([A-Za-z_]\w*)\s*$')
    for path in sorted((root / "asm").glob("**/*.s")):
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            match = pattern.match(line)
            if match:
                result.add((path.relative_to(root).as_posix(), match.group(2), match.group(1)))
    return [{"source_owner": owner, "name": name, "instruction_set": mode}
            for owner, name, mode in sorted(result)]


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
        address = int(fields[0], 16) & ~1
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
    path = source.replace("\\", "/")
    for prefix in ("src/", "asm/"):
        if path.startswith(prefix):
            path = path[len(prefix):]
    return Path(path).with_suffix(".c").as_posix() == definition.path


def linker_code_inputs(text: str) -> list[tuple[int, int, str, str, str]]:
    """Keep each input's address range, full C owner, section and object."""
    ranges = set()
    section = ""
    for line in text.splitlines():
        match = re.fullmatch(r"\s+(\.[^\s]+)\s*", line)
        if match:
            section = match.group(1)
        match = re.fullmatch(
            r"\s*(?:(\.[^\s]+)\s+)?(0x[0-9A-Fa-f]+)\s+"
            r"(0x[0-9A-Fa-f]+)\s+(\S+\.o)\s*", line)
        if not match:
            continue
        current, start, size, owner = match.groups()
        current = current or section
        owner = owner.replace("\\", "/")
        if not current.startswith((".text", ".iwram")) or "/src/" not in "/" + owner:
            continue
        source = owner[owner.index("src/") + 4:-2] + ".c"
        start, size = int(start, 16), int(size, 16)
        if start and size:
            ranges.add((start, start + size, source, current, owner))
    return sorted(ranges)


def linker_code_ranges(text: str) -> list[tuple[int, int, str]]:
    """Compatibility view of actual C input-object intervals."""
    return sorted({(start, end, source) for start, end, source, _section, _object
                   in linker_code_inputs(text)})


def elf_tables(data: bytes) -> tuple[tuple, list[tuple], list[tuple]]:
    """Read bounded ELF32 tables, retaining symbol type/section/size."""
    if len(data) < 52 or data[:6] != b"\x7fELF\x01\x01":
        raise ValueError("expected an ELF32 little-endian file")
    header = struct.unpack_from("<16sHHIIIIIHHHHHH", data)
    offset, stride, count = header[6], header[11], header[12]
    if stride < 40 or not count or offset + stride * count > len(data):
        raise ValueError("invalid ELF section headers")
    sections = [struct.unpack_from("<10I", data, offset + index * stride)
                for index in range(count)]
    symbols = []
    for section in sections:
        if section[1] != 2:  # SHT_SYMTAB
            continue
        if section[6] >= count or section[9] != 16 or section[5] % 16:
            raise ValueError("invalid ELF symbol table")
        strings = sections[section[6]]
        if (section[4] + section[5] > len(data)
                or strings[4] + strings[5] > len(data)):
            raise ValueError("truncated ELF symbol/string table")
        table = data[strings[4]:strings[4] + strings[5]]
        local_file = None
        for position in range(section[4], section[4] + section[5], 16):
            name_at, address, size, info, _other, index = struct.unpack_from(
                "<IIIBBH", data, position)
            if name_at >= len(table):
                raise ValueError("invalid ELF symbol name")
            end = table.find(b"\0", name_at)
            if end < 0:
                raise ValueError("unterminated ELF symbol name")
            name = table[name_at:end].decode("utf-8", errors="replace")
            kind, binding = info & 15, info >> 4
            if kind == 4:  # STT_FILE is only a local-symbol context.
                local_file = name
                continue
            symbols.append((name, address, size, info, index, local_file if binding == 0 else None))
    return header, sections, symbols


def elf_code_symbols(data: bytes) -> list[tuple[str, int, str | None]]:
    """Retain executable local/global symbols, never ABS aliases.

    STT_FILE is auxiliary for locals only; Thumb's low bit is not an address.
    """
    _header, sections, rows = elf_tables(data)
    symbols = []
    for name, address, _size, info, index, local_file in rows:
        if (not name or index >= len(sections) or info & 15 not in (0, 2)
                or not sections[index][2] & 4):
            continue
        address &= ~1
        code = sections[index]
        if code[3] <= address < code[3] + code[5]:
            symbols.append((name, address, local_file))
    return sorted(set(symbols), key=lambda item: (item[0], item[1], item[2] or ""))


def elf_object_functions(data: bytes) -> list[tuple[str, str, int, int, int]]:
    """Return ET_REL STT_FUNC names with exact executable section offsets.

    A mapping/data/ABS symbol or a function-like section name alone is not
    evidence.  Section sizes are retained to check the final map interval.
    """
    header, sections, rows = elf_tables(data)
    if header[1] != 1 or not 0 < header[13] < len(sections):
        raise ValueError("expected an ET_REL object with section names")
    if not any(section[1] == 2 for section in sections):
        raise ValueError("missing ELF object symbol table")
    strings = sections[header[13]]
    if strings[1] != 3 or strings[4] + strings[5] > len(data):
        raise ValueError("invalid ELF section-name table")
    names = data[strings[4]:strings[4] + strings[5]]
    result = []
    for name, address, size, info, index, _local_file in rows:
        if not name or info & 15 != 2 or not 0 < index < len(sections):
            continue
        section = sections[index]
        if not section[2] & 4 or section[0] >= len(names):
            continue
        end = names.find(b"\0", section[0])
        if end < 0:
            raise ValueError("unterminated ELF section name")
        offset = (address & ~1) - section[3]
        if not 0 <= offset < section[5] or offset + size > section[5]:
            continue
        result.append((name, names[section[0]:end].decode("utf-8", errors="replace"),
                       offset, size, section[5]))
    return sorted(set(result))


def linked_function_evidence(
    root: Path, definitions: list[FunctionDef],
) -> tuple[dict[tuple[str, int], set[str]], dict[str, object]]:
    """Bind JP names/addresses to exact C owners, exposing absent evidence."""
    elf_path, map_path = root / "pokeemerald_jp.elf", root / "pokeemerald_jp.map"
    metadata = {
        "method": "JP ELF executable symbols + JP linker input-object intervals; exact input-section/object STT_FUNC supplement; local STT_FILE is auxiliary",
        "status": "unavailable",
        "inputs": {},
        "object_ranges": 0,
        "owner_conflicts": 0,
        "stale_source_owners": [],
        "unverified_function_macros": sorted({f"{item.path}:{item.declared_name}"
                                               for item in definitions if not item.macro_verified}),
        "unverified_asm_link_names": sorted({f"{item.path}:{item.name}"
                                            for item in definitions if not item.link_name_verified}),
        "asm_link_name_bindings": [],
        "input_section_bindings": [],
        "input_object_errors": {},
        "inline_not_emitted": [],
        "c_compile_variants": c_compile_variants(root),
        "source_definition_sha256": hashlib.sha256(json.dumps(
            [asdict(definition) for definition in definitions], sort_keys=True,
            separators=(",", ":")).encode("utf-8")).hexdigest(),
    }
    if not elf_path.is_file():
        metadata["reason"] = "missing_jp_elf"
        return {}, metadata
    data = elf_path.read_bytes()
    metadata["inputs"]["elf"] = {
        "path": "pokeemerald_jp.elf", "sha256": hashlib.sha256(data).hexdigest()}
    try:
        symbols = elf_code_symbols(data)
    except ValueError as error:
        metadata["reason"] = str(error)
        return {}, metadata
    ranges, code_inputs = [], []
    if map_path.is_file():
        map_data = map_path.read_bytes()
        code_inputs = linker_code_inputs(map_data.decode("utf-8", errors="replace"))
        alternate_owners = {item["object_owner"]: item["source_owner"]
                            for item in metadata["c_compile_variants"]}
        code_inputs = [
            (start, end, alternate_owners.get(owner, owner), section, object_name)
            for start, end, owner, section, object_name in code_inputs]
        ranges = sorted({(start, end, owner) for start, end, owner, _section, _object in code_inputs})
        metadata["inputs"]["link_map"] = {
            "path": "pokeemerald_jp.map", "sha256": hashlib.sha256(map_data).hexdigest()}
    else:
        metadata["reason"] = "missing_jp_link_map"
    metadata["object_ranges"] = len(ranges)
    source_paths = {definition.path for definition in definitions}
    by_emitted_owner = defaultdict(list)
    for item in definitions:
        if item.macro_verified and item.link_name_verified:
            by_emitted_owner[(item.emitted_name, item.path)].append(item)
    ambiguous_link_names = {key for key, values in by_emitted_owner.items()
                            if len(values) > 1 and any(item.link_name is not None for item in values)}
    metadata["unverified_asm_link_names"] = sorted(set(metadata["unverified_asm_link_names"]) | {
        f"{item.path}:{item.name}" for key in ambiguous_link_names for item in by_emitted_owner[key]})
    wanted_names = {name for name, owner in by_emitted_owner if (name, owner) not in ambiguous_link_names}
    _header, final_sections, final_rows = elf_tables(data)
    typed_symbols = {(name, address & ~1) for name, address, _size, info, index, _file in final_rows
                     if (info & 15 == 2 and 0 < index < len(final_sections)
                         and final_sections[index][2] & 4
                         and final_sections[index][3] <= (address & ~1)
                         < final_sections[index][3] + final_sections[index][5])}
    starts = [start for start, _end, _owner in ranges]
    maximum_ends = []
    for _start, end, _owner in ranges:
        maximum_ends.append(max(end, maximum_ends[-1] if maximum_ends else end))
    by_basename = defaultdict(set)
    for path in source_paths:
        by_basename[Path(path).name].add(path)
    stale = {path for path in source_paths if (root / "src" / path).is_file()
             and (root / "src" / path).stat().st_mtime_ns > elf_path.stat().st_mtime_ns}
    name_dependencies = dict(item for definition in definitions for item in definition.name_inputs)
    metadata["inputs"]["name_macro_headers"] = dict(sorted(name_dependencies.items()))
    for definition in definitions:
        for relative, expected_hash in definition.name_inputs:
            header_path = root / relative
            if (not header_path.is_file()
                    or hashlib.sha256(header_path.read_bytes()).hexdigest() != expected_hash
                    or header_path.stat().st_mtime_ns > elf_path.stat().st_mtime_ns):
                stale.add(definition.path)
    metadata["stale_source_owners"] = sorted(stale)
    object_cache = {}
    object_symbol_names = {}
    metadata["inputs"]["input_objects"] = {}
    executable_ranges = [(item[3], item[3] + item[5]) for item in final_sections if item[2] & 4]

    def object_functions(object_name: str) -> list[tuple] | None:
        if object_name in object_cache:
            return object_cache[object_name]
        candidates = (root / object_name, root / "build/pokeemerald-jp" / object_name)
        target = next((item for item in candidates if item.is_file()), None)
        reason = None
        if target is None:
            reason = "missing_input_object"
        elif not target.resolve().is_relative_to(root.resolve()):
            reason = "input_object_outside_jp_root"
        elif target.stat().st_mtime_ns > elf_path.stat().st_mtime_ns:
            reason = "input_object_newer_than_elf"
        if reason:
            metadata["input_object_errors"][object_name] = reason
            object_cache[object_name] = None
            return None
        object_data = target.read_bytes()
        try:
            functions = elf_object_functions(object_data)
        except ValueError as error:
            metadata["input_object_errors"][object_name] = str(error)
            object_cache[object_name] = None
            return None
        metadata["inputs"]["input_objects"][target.relative_to(root).as_posix()] = hashlib.sha256(object_data).hexdigest()
        object_symbol_names[object_name] = {name for name, _address, _file in elf_code_symbols(object_data)}
        object_cache[object_name] = functions
        return functions

    alternate_object_paths = {item["input_object"] for item in metadata["c_compile_variants"]}
    alternate_inputs = [item for item in code_inputs
                        if any(("/" + item[4]).endswith("/" + path)
                               for path in alternate_object_paths)]
    evidence: dict[tuple[str, int], set[str]] = defaultdict(set)
    conflicts = set()
    def owners_at(address: int) -> set[str]:
        owners = set()
        position = bisect_right(starts, address) - 1
        while position >= 0 and maximum_ends[position] > address:
            start, end, owner = ranges[position]
            if start <= address < end:
                owners.add(owner)
            position -= 1
        return owners

    for name, address, local_file in symbols:
        if name not in wanted_names:
            continue
        owners = owners_at(address)
        local_owners = by_basename.get(Path(local_file).name, set()) if local_file else set()
        if local_file:
            exact_file = local_file.removeprefix("src/")
            if exact_file in source_paths:
                local_owners = {exact_file}
        if len(owners) > 1 or (owners and local_owners and not owners & local_owners):
            conflicts.add((name, address))
            continue
        if len(owners) == 1 and owners <= source_paths and not owners & stale:
            owner = next(iter(owners))
            variant_ranges = [item for item in alternate_inputs if item[0] <= address < item[1]]
            if variant_ranges:
                matches = []
                for start, end, actual_owner, section, object_name in variant_ranges:
                    for symbol, actual_section, offset, _size, section_size in (
                            object_functions(object_name) or []):
                        if (symbol == name and actual_owner == owner and actual_section == section
                                and start + offset == address and section_size == end - start):
                            matches.append((section, object_name))
                if len(set(matches)) != 1:
                    continue
            if (name, owner) in ambiguous_link_names:
                continue
            for definition in by_emitted_owner.get((name, owner), []):
                # A variable/NOTYPE symbol cannot verify an explicit function
                # asm name.  The exact typed object supplement remains below.
                if definition.link_name is not None and (name, address) not in typed_symbols:
                    continue
                evidence[(definition.name, address)].add(owner)
                if definition.link_name is not None:
                    metadata["asm_link_name_bindings"].append({
                        "source_owner": owner, "name": definition.name, "link_name": name,
                        "address": "0x%08X" % address,
                        "evidence": "JP_ELF_STT_FUNC_and_unique_linker_input_owner"})
    for name, address in conflicts:
        for definition in definitions:
            if definition.emitted_name == name:
                evidence.pop((definition.name, address), None)
    metadata["asm_link_name_bindings"] = [item for item in metadata["asm_link_name_bindings"]
                                         if (item["link_name"], int(item["address"], 16)) not in conflicts]

    # GNU ld may replace a source function symbol with an ABS name while
    # retaining its real input section.  Supplement only from the matching
    # built object, never from that ABS name or an address in funcmap.
    by_owner = defaultdict(list)
    for item in code_inputs:
        by_owner[item[2]].append(item)
    bound = {(name, owner) for (name, _address), owners in evidence.items() for owner in owners}
    for definition in definitions:
        if (not definition.macro_verified or not definition.link_name_verified
                or (definition.emitted_name, definition.path) in ambiguous_link_names
                or definition.path in stale
                or (definition.name, definition.path) in bound):
            continue
        inputs = by_owner[definition.path]
        candidates, object_records = set(), {}
        for start, end, owner, section, object_name in inputs:
            records = object_functions(object_name)
            object_records[object_name] = records
            if (records is None or (definition.link_name is None
                                    and section != ".text." + definition.name)):
                continue
            for name, actual_section, offset, _size, section_size in records:
                address = start + offset
                if (name == definition.emitted_name and actual_section == section
                        and section_size == end - start
                        and owners_at(address) == {owner}
                        and any(a <= address < b for a, b in executable_ranges)):
                    candidates.add((address, section, object_name))
        if len(candidates) == 1:
            address, section, object_name = next(iter(candidates))
            if (definition.emitted_name, address) not in conflicts:
                evidence[(definition.name, address)].add(definition.path)
                metadata["input_section_bindings"].append({
                    "source_owner": definition.path, "name": definition.name,
                    "address": "0x%08X" % address, "input_section": section,
                    "input_object": object_name, "evidence": "exact_input_section_and_object_STT_FUNC"})
                if definition.link_name is not None:
                    metadata["asm_link_name_bindings"].append({
                        "source_owner": definition.path, "name": definition.name,
                        "link_name": definition.link_name, "address": "0x%08X" % address,
                        "input_section": section, "input_object": object_name,
                        "evidence": "exact_input_section_and_object_STT_FUNC"})
        elif (not candidates and definition.inline and inputs and object_records
              and all(records is not None for records in object_records.values())
              and all(definition.emitted_name not in object_symbol_names[object_name]
                      and definition.name not in object_symbol_names[object_name]
                      for object_name in object_records)):
            metadata["inline_not_emitted"].append({"source_owner": definition.path, "name": definition.name})
    metadata["input_section_bindings"].sort(key=lambda item: (item["source_owner"], item["name"], item["address"]))
    metadata["inline_not_emitted"].sort(key=lambda item: (item["source_owner"], item["name"]))
    metadata["asm_link_name_bindings"].sort(key=lambda item: (item["source_owner"], item["name"], item["address"]))
    metadata["owner_conflicts"] = len(conflicts)
    metadata["status"] = "available" if evidence else "unavailable"
    if not evidence and "reason" not in metadata:
        metadata["reason"] = "no_verified_jp_source_bindings"
    metadata["bound_name_address_pairs"] = len(evidence)
    metadata["rule"] = "No name-only, US-index, or neighboring-address fallback; unverified definitions remain unresolved."
    return dict(evidence), metadata


def resolve_funcmap_entries(
    definitions: list[FunctionDef], entries: list[FuncmapEntry],
    linked_owners: dict[tuple[str, int], set[str]] | None = None,
) -> tuple[dict[FunctionDef, list[FuncmapEntry]], list[str]]:
    """Resolve one physical definition without cross-owner name fan-out.

    Reports always provide linked evidence, including an empty dictionary
    when it is unavailable.  The legacy direct-call form accepts only an
    explicit, exact funcmap source owner, never an unowned name match.
    An explicit asm link name always requires actual linked evidence.
    """
    by_name: dict[str, list[FuncmapEntry]] = defaultdict(list)
    by_address: dict[int, list[FuncmapEntry]] = defaultdict(list)
    for entry in entries:
        by_address[entry.address & ~1].append(entry)
        by_name[entry.current].append(entry)
        if entry.standard != entry.current:
            by_name[entry.standard].append(entry)
    resolved: dict[FunctionDef, list[FuncmapEntry]] = {}
    multi_address = []
    linked_addresses = defaultdict(set)
    for (name, address), owners in (linked_owners or {}).items():
        if len(owners) == 1:
            linked_addresses[(name, next(iter(owners)))].add(address)
    for definition in definitions:
        if (not definition.macro_verified or not definition.link_name_verified
                or (definition.link_name is not None and linked_owners is None)):
            continue
        candidates = by_name.get(definition.name, [])
        owner_candidates = [entry for entry in candidates if entry.source and
                            source_matches_definition(entry.source, definition)]
        actual_addresses = linked_addresses[(definition.name, definition.path)]
        if linked_owners is not None and len(actual_addresses) > 1:
            multi_address.append(f"{definition.path}:{definition.name}")
            continue
        # The current JP name can have changed since funcmap's alias columns.
        # A proved JP owner/name/address binds the address directly; neither
        # column's US-name spelling is used to invent a JP address.
        selected = owner_candidates if linked_owners is None else [
            entry for address in actual_addresses for entry in by_address.get(address, [])]
        addresses = {entry.address & ~1 for entry in selected}
        if len(addresses) > 1:
            multi_address.append(f"{definition.path}:{definition.name}")
            continue
        if addresses:
            resolved[definition] = sorted(set(selected), key=lambda entry: (
                entry.address, entry.source or "", entry.current, entry.standard))
    return resolved, sorted(multi_address)


def function_binding_inventory(
    definitions: list[FunctionDef], entries: list[FuncmapEntry],
    linked: dict[tuple[str, int], set[str]], metadata: dict[str, object],
    resolved: dict[FunctionDef, list[FuncmapEntry]], multi_address: list[str],
) -> dict[str, object]:
    """Shared source inventory and conservative JP address metric contract.

    Keep the all-unbound legacy list, but separate proved inline non-emission
    from emitted/unknown unresolved definitions.  Neither is guessed into
    the funcmap denominator.
    """
    candidates, actual = defaultdict(set), defaultdict(set)
    for item in entries:
        candidates[item.current].add(item.address)
        candidates[item.standard].add(item.address)
    for (name, address), owners in linked.items():
        if len(owners) == 1:
            actual[(name, next(iter(owners)))].add(address)
    inline_keys = {(item["source_owner"], item["name"])
                   for item in metadata.get("inline_not_emitted", [])}
    unresolved = []
    for definition in definitions:
        if definition in resolved:
            continue
        key = (definition.path, definition.name)
        addresses = actual[(definition.name, definition.path)]
        reason = ("function_macro_unverified" if not definition.macro_verified else
                  "asm_link_name_unverified" if (not definition.link_name_verified
                       or f"{definition.path}:{definition.name}" in metadata.get("unverified_asm_link_names", [])) else
                  "ambiguous_linked_addresses" if f"{definition.path}:{definition.name}" in multi_address else
                  "stale_source_owner" if definition.path in metadata.get("stale_source_owners", []) else
                  "inline_not_emitted" if key in inline_keys else
                  "linked_address_missing_from_funcmap" if addresses else
                  "linked_name_owner_address_not_verified")
        unresolved.append({
            "source_owner": definition.path, "name": definition.name,
            "naked": definition.naked, "inline": definition.inline,
            "declared_name": definition.declared_name, "reason": reason,
            "link_name": definition.link_name, "link_name_verified": definition.link_name_verified,
            "candidate_addresses": ["0x%08X" % value for value in sorted(candidates[definition.name])],
            "verified_source_addresses": ["0x%08X" % value for value in sorted(addresses)],
        })
    naked = {entry.address for definition, values in resolved.items() if definition.naked for entry in values}
    strict = {entry.address for definition, values in resolved.items() if not definition.naked
              for entry in values} - naked
    total = len({entry.address for entry in entries})
    return {
        "funcmap_unique_addresses": total,
        "c_definitions": len(definitions),
        "source_non_naked_definitions": sum(not item.naked for item in definitions),
        "source_naked_definitions": sum(item.naked for item in definitions),
        "source_inline_definitions": sum(item.inline for item in definitions),
        "source_inventory_unit": "build-selected source definition; not ROM addresses",
        "bound_c_definitions": len(resolved), "binding_evidence": metadata,
        "unresolved_bindings": unresolved,
        "inline_not_emitted_definitions": [item for item in unresolved if item["reason"] == "inline_not_emitted"],
        "unresolved_emitted_or_unknown_bindings": [item for item in unresolved if item["reason"] != "inline_not_emitted"],
        "metric_status": "conservative_verified_lower_bound" if linked and total else "unavailable",
        "strict_c_addresses": len(strict), "naked_assembly_addresses": len(naked),
        "strict_c_rate": len(strict) / total if linked and total else None,
        "unmapped_c_definitions": sorted(f"{item['source_owner']}:{item['name']}" for item in unresolved),
        "multi_address_c_definitions": multi_address,
        "strict_naked_address_overlap": len(strict & naked),
    }


def legacy_binding_audit(
    definitions: list[FunctionDef], entries: list[FuncmapEntry],
    linked: dict[tuple[str, int], set[str]],
    resolved: dict[FunctionDef, list[FuncmapEntry]],
) -> dict[str, object]:
    """Diagnose the superseded fan-out model, never use it for progress.

    A rejected assignment is a proved wrong owner/address only when JP linked
    evidence confirms a different binding.  Missing symbols remain evidence
    gaps, not claimed mistakes.  The natural strict/naked intersection is
    shown before exclusion so a disjoint-set guard cannot conceal pollution.
    """
    by_name = defaultdict(list)
    for entry in entries:
        by_name[entry.current].append(entry)
        if entry.standard != entry.current:
            by_name[entry.standard].append(entry)
    legacy = {}
    known_definitions = {(definition.name, definition.path) for definition in definitions}
    by_definition = defaultdict(set)
    for (name, address), owners in linked.items():
        if len(owners) == 1:
            owner = next(iter(owners))
            by_definition[(name, owner)].add(address)
    rejected = []
    for definition in definitions:
        candidates = by_name.get(definition.name, [])
        # Exactly reproduce the old stem-only owner preference for diagnosis.
        preferred = [entry for entry in candidates if entry.source and
                     Path(entry.source).stem == Path(definition.path).stem]
        selected = {entry.address: entry for entry in (preferred or candidates)}
        if selected:
            legacy[definition] = list(selected.values())
        accepted = {entry.address for entry in resolved.get(definition, [])}
        for address in sorted(set(selected) - accepted):
            owners = linked.get((definition.name, address), set())
            own_addresses = by_definition[(definition.name, definition.path)]
            reason = "evidence_gap"
            if owners and definition.path not in owners and any(
                    (definition.name, owner) in known_definitions for owner in owners):
                reason = "confirmed_wrong_owner"
            elif own_addresses and address not in own_addresses:
                reason = "confirmed_wrong_address"
            rejected.append({
                "source_owner": definition.path,
                "name": definition.name,
                "naked": definition.naked,
                "candidate_address": "0x%08X" % address,
                "reason": reason,
                "verified_owners_at_name_address": sorted(owners),
                "verified_addresses_for_source_name": ["0x%08X" % value
                                                        for value in sorted(own_addresses)],
            })

    def counts(bindings):
        naked = {entry.address for definition, values in bindings.items()
                 if definition.naked for entry in values}
        strict = {entry.address for definition, values in bindings.items()
                  if not definition.naked for entry in values}
        return {
            "bound_definitions": len(bindings),
            "strict_before_naked_exclusion": len(strict),
            "naked_addresses": len(naked),
            "natural_strict_naked_overlap": len(strict & naked),
            "strict_after_naked_exclusion": len(strict - naked),
        }

    return {
        "legacy_metrics_invalid": True,
        "interpretation": "A decrease after binding correction is a measurement correction, not decompilation regression.",
        "legacy_name_fanout": counts(legacy),
        "verified_owner_bindings": counts(resolved),
        "rejected_assignment_counts": dict(sorted(Counter(
            item["reason"] for item in rejected).items())),
        "rejected_assignments": rejected,
    }


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
            standard = next(iter(standards)) if len(standards) == 1 else None
            variant = NUMERIC_VARIANT_RE.fullmatch(standard) if standard else None
            if standard is None:
                classification = "ambiguous_us_standard_names"
                action = "review_conflicting_funcmap_aliases"
            elif standard in us_symbols:
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
                "us_standard_names": sorted(standards),
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
        elif classes & {"jp_specific_or_unmapped_us", "ambiguous_us_standard_names"}:
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


def path_only_c_manifest(
    jp_files: set[str], us_files: set[str], definitions: list[FunctionDef],
    resolved: dict[FunctionDef, list[FuncmapEntry]],
) -> list[dict[str, object]]:
    """List every literal JP-exclusive .c path, including data-only wrappers.

    This scope is independent of the semantic-gap migration queue, whose
    modules may already have an identically named US path.
    """
    by_path = defaultdict(list)
    for definition in definitions:
        by_path["src/" + definition.path].append(definition)
    paths = sorted(path for path in jp_files - us_files
                   if path.startswith("src/") and path.endswith(".c"))
    records = []
    for path in paths:
        values = by_path[path]
        strict = {entry.address for definition in values if not definition.naked
                  for entry in resolved.get(definition, [])}
        naked = {entry.address for definition in values if definition.naked
                 for entry in resolved.get(definition, [])}
        unresolved = sorted(definition.name for definition in values if definition not in resolved)
        records.append({
            "path": path,
            "scope": "literal_jp_exclusive_c_path",
            "source_function_definitions": len(values),
            "source_non_naked_definitions": sum(not definition.naked for definition in values),
            "source_naked_definitions": sum(definition.naked for definition in values),
            "verified_strict_addresses": ["0x%08X" % address for address in sorted(strict - naked)],
            "verified_naked_addresses": ["0x%08X" % address for address in sorted(naked)],
            "unresolved_function_names": unresolved,
            "address_binding_status": ("no_function_definitions" if not values else
                                       "partial_or_unresolved" if unresolved else "all_definitions_bound"),
            "semantic_review": "not_recorded",
        })
    return records


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


def map_artifact_progress(root: Path, convergence_records: list[dict[str, object]] | None = None,
                          semantic_review: dict[str, object] | None = None) -> dict[str, object]:
    """Count map artifacts without treating their presence as semantic review.

    ``map.json`` and the two generated includes demonstrate that the map has
    been structurally split.  They do not demonstrate that its scripts,
    text, constants, or shared ROM boundaries have received a semantic audit.
    Only an explicit review with current source/native evidence contributes
    to the separate semantic metric; file names never imply approval.
    """
    map_root = root / "data/maps"
    jp_json = {path.parent.name for path in map_root.glob("*/map.json")}
    jp_scripts = {path.parent.name for path in map_root.glob("*/scripts.inc")}
    jp_events = {path.parent.name for path in map_root.glob("*/events.inc")}
    upper_event_includes = set()
    aggregate_events_path = root / "data/maps/events.inc"
    aggregate_events_included = False
    for path in sorted((root / "data").glob("*.s")):
        source_text = path.read_text(encoding="utf-8", errors="replace")
        for line in source_text.splitlines():
            if match := MAP_EVENTS_RE.match(line):
                upper_event_includes.add(match.group(1))
            if (match := ASM_INCLUDE_RE.match(line)) and match.group(1) == "data/maps/events.inc":
                aggregate_events_included = True
    if aggregate_events_included and aggregate_events_path.is_file():
        upper_event_includes.update(map_includes(aggregate_events_path, MAP_EVENTS_RE))
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
        "semantic_review": (semantic_review if semantic_review is not None
                            else map_review_progress(root, jp_json)),
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
    # Blocks are isolated physical assembly owners, not preprocessed TUs.
    # Use the same literal collector as the whole-source inventory. Unknown
    # templates remain explicit diagnostics rather than "no incbin" success.
    collected = collect_resource_references({"data/<asset-block>.s": block})
    sources = [item["resource"] for item in collected["references"]]
    raw_sources = [source for source in sources if Path(source).name == "baserom_jp.gba"]
    return {
        "symbol": symbol,
        "defined": True,
        "source_count": len(sources),
        "raw_baserom_source_count": len(raw_sources),
        "unresolved_source_count": len(collected["unresolved"]),
        "unresolved_sources": collected["unresolved"],
        "incgfx_source_count": len(collected["incgfx"]),
        "incgfx_sources": collected["incgfx"],
        "incgfx_unresolved_sources": collected["incgfx_unresolved"],
        "status": ("contains_raw_baserom" if raw_sources else
                   "unresolved_source" if collected["unresolved"] or collected["incgfx_unresolved"]
                   else "named_source_or_no_incbin"),
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
    to data/map_events.s (events) and data/maps.s (headers, layouts, and
    tilesets).  Older trees that have not yet moved the event stream use the
    data/data_b2d_mid26.s fallback. It records aliases and raw ranges as work
    items; a present include or generated file is deliberately never a
    semantic pass.
    """
    event_scripts_path = root / "data/event_scripts.s"
    events_path = root / "data/map_events.s"
    if not events_path.is_file():
        events_path = root / "data/data_b2d_mid26.s"
    map_data_path = root / "data/maps.s"
    layouts_path = root / "data/layouts/layouts.inc"
    events_stream_path = events_path.relative_to(root).as_posix()
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
    # The final event owner delegates to the generated aggregate. Preserve
    # the aggregate's source order rather than treating its single include as
    # an empty event stream. Legacy mid26 owners still carry direct includes.
    aggregate_events_path = root / "data/maps/events.inc"
    aggregate_events_included = any(
        (match := ASM_INCLUDE_RE.match(line)) and match.group(1) == "data/maps/events.inc"
        for line in events_text.splitlines())
    if not event_order and aggregate_events_included and aggregate_events_path.is_file():
        event_order = map_includes(aggregate_events_path, MAP_EVENTS_RE)
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

    semantic_review = map_review_progress(root, {path.parent.name for path in
                                               (root / "data/maps").glob("*/map.json")})
    reviewed_names = set(semantic_review["reviewed_map_names"])
    review_states = {name: batch["status"] for batch in semantic_review["batches"]
                     for name in batch["maps"]}
    for record in records:
        record["semantic_review"] = review_states.get(record["name"], "not_recorded")
        if record["name"] in reviewed_names:
            record["required_actions"] = [action for action in record["required_actions"]
                                           if action != "semantic_review_required"]
    event_statuses = Counter(record["events"]["status"] for record in records)
    script_statuses = Counter(record["scripts"]["status"] for record in records)
    resource_raw_maps = sum(bool(record["layout"]["resource_chain"]["raw_baserom_source_count"])
                            for record in records)
    return {
        "stream_files": {
            "scripts": "data/event_scripts.s",
            "events": events_stream_path,
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
            events_stream_path: raw_baserom_directives(events_text),
            "data/maps.s": raw_baserom_directives(map_data_text),
        },
        "semantic_review": semantic_review,
        "records": records,
    }


TILESET_RESOURCE_FILENAMES = {
    "tiles.4bpp.lz",
    "metatiles.bin",
    "metatile_attributes.bin",
}
ANONYMOUS_RESOURCE_PREFIXES = ("gunknown", "unknown", "unk")


def is_anonymous_resource_path(path: Path) -> bool:
    """Return whether any owner or leaf name is intentionally anonymous."""
    return any(part.lower().startswith(ANONYMOUS_RESOURCE_PREFIXES) for part in path.parts)


def declared_layout_resources(root: Path) -> set[str]:
    """Return the exact map and border resource paths owned by layouts.json."""
    path = root / "data" / "layouts" / "layouts.json"
    if not path.is_file():
        return set()
    try:
        layouts = json.loads(path.read_text(encoding="utf-8")).get("layouts", [])
    except (json.JSONDecodeError, OSError):
        return set()
    resources = set()
    for layout in layouts:
        if not isinstance(layout, dict):
            continue
        for field in ("blockdata_filepath", "border_filepath"):
            resource = layout.get(field)
            if isinstance(resource, str):
                resources.add(resource)
    return resources


def classify_incbin_resource(resource: str,
                             layout_resources: set[str] | None = None) -> tuple[str, str]:
    """Classify an INCBIN path without treating named encoded assets as raw.

    A ``.bin`` container or an encoded stream outside a verified asset owner
    still needs a source-owner audit.  Conversely, named encoded assets in
    ``graphics/`` or ``sound/``, the three canonical tileset resources under
    a named primary/secondary owner, and map/border paths declared by
    ``layouts.json`` are final physical owners.  They still need byte and
    semantic validation, but are not anonymous raw spans waiting to be split.
    """
    path = Path(resource)
    suffix = path.suffix or "[no suffix]"
    asset_root = path.parts and path.parts[0] in {"graphics", "sound"}
    encoded_asset = asset_root and suffix in {".lz", ".rl", ".huff"}
    anonymous_asset = is_anonymous_resource_path(path)
    named_tileset_asset = (
        len(path.parts) == 5
        and path.parts[:2] == ("data", "tilesets")
        and path.parts[2] in {"primary", "secondary"}
        and path.name in TILESET_RESOURCE_FILENAMES
        and not anonymous_asset
    )
    named_layout_asset = (
        len(path.parts) == 4
        and path.parts[:2] == ("data", "layouts")
        and path.name in {"map.bin", "border.bin"}
        and not anonymous_asset
    )
    declared_layout_asset = (
        resource in (layout_resources or set()) and named_layout_asset)
    if named_tileset_asset:
        return "structured_or_encoded", "named_tileset_resource"
    if declared_layout_asset:
        return "structured_or_encoded", "declared_layout_resource"
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
    raw_baserom_ranges = []
    raw_baserom_unbounded_references = 0
    layout_resources = declared_layout_resources(root)
    source_texts = {}
    for relpath in sorted(source_files(root)):
        path = root / relpath
        if path.suffix not in {".s", ".inc", ".c", ".h"}:
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        source_texts[relpath] = text
    # Context headers discover possible resource templates but do not add
    # counted occurrences outside the established src/asm/data denominator.
    support = {path.relative_to(root).as_posix(): path.read_text(encoding="utf-8", errors="replace")
               for path in sorted((root / "include").rglob("*.h"))}
    collected = collect_resource_references(source_texts, support_sources=support)
    # Range parsing is still the specialized offset/size parser, but its input
    # occurrences must agree with the collector (no comments/template bodies).
    direct_baserom_lines = defaultdict(set)
    for item in collected["references"]:
        if item["syntax"] == "asm_incbin" and item["resource"] == "baserom_jp.gba":
            direct_baserom_lines[item["owner"]].add(item["line"])
    for relpath, lines in sorted(direct_baserom_lines.items()):
        visible_ranges = [item for item in parse_baserom_incbin_ranges(source_texts[relpath])
                          if item["line"] in lines]
        for item in visible_ranges:
            item["owner"] = relpath
        raw_baserom_ranges.extend(visible_ranges)
        raw_baserom_unbounded_references += len(lines) - len(visible_ranges)
    for item in collected["references"]:
        resource = item["resource"]
        suffix = Path(resource).suffix or "[no suffix]"
        classification, classification_reason = classify_incbin_resource(resource, layout_resources)
        references.append({
            **item,
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
        "raw_baserom_visible_range_references": len(raw_baserom_ranges),
        "raw_baserom_visible_bytes": sum(
            int(item["size"], 0) for item in raw_baserom_ranges),
        "raw_baserom_unbounded_references": raw_baserom_unbounded_references,
        "missing_resource_paths": len(missing),
        "suffixes": dict(sorted(suffixes.items())),
        "raw_by_owner_directory": dict(sorted(raw_owner_dirs.items())),
        "raw_by_resource_directory": dict(sorted(raw_resource_dirs.items())),
        "raw_baserom_manifest": raw_baserom_ranges,
        "manifest": references,
        "collection_mode": collected["mode"],
        "unresolved_resource_references": len(collected["unresolved"]),
        "unresolved_manifest": collected["unresolved"],
        # Source assets and generated conversions are not INCBIN occurrences.
        "incgfx_references": len(collected["incgfx"]),
        "incgfx_unique_source_paths": len({item["source_asset"] for item in collected["incgfx"]}),
        "incgfx_unique_generated_tails": len({item["generated_tail"] for item in collected["incgfx"]}),
        "incgfx_manifest": collected["incgfx"],
        "incgfx_unresolved_references": len(collected["incgfx_unresolved"]),
        "incgfx_unresolved_manifest": collected["incgfx_unresolved"],
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
    artifacts = map_artifact_progress(root, convergence["records"], convergence.get("semantic_review"))
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


def _build_report(root: Path, us_root: Path) -> dict[str, object]:
    if not (us_root / "src").is_dir():
        raise ValueError("US source root is missing src/: %s" % us_root)
    jp_files = source_files(root)
    us_files = source_files(us_root)
    jp_defs = c_inventory(root)
    us_defs = c_inventory(us_root)
    funcmap_entries, total_functions = parse_funcmap(root / "funcmap_jp.txt")
    linked, binding_evidence = linked_function_evidence(root, jp_defs)
    resolved, multi_address_c_definitions = resolve_funcmap_entries(jp_defs, funcmap_entries, linked)
    inventory = function_binding_inventory(jp_defs, funcmap_entries, linked, binding_evidence,
                                          resolved, multi_address_c_definitions)
    binding_audit = legacy_binding_audit(jp_defs, funcmap_entries, linked, resolved)
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
            "jp_binding_evidence": ("exact_input_section_and_object_STT_FUNC" if any(
                item["name"] == definition.name and item["source_owner"] == definition.path
                and item["address"] == "0x%08X" % address
                for item in binding_evidence["input_section_bindings"]) else "elf_symbol_and_linker_source_owner"),
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
        "schema": 6,
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
            **inventory,
            "binding_audit": binding_audit,
            "strict_c_addresses": len(strict_addresses),
            "naked_assembly_addresses": len(naked_addresses),
            "strict_c_rate": inventory["strict_c_rate"],
            "standard_owned_addresses": len(standard_owned_addresses),
            "module_aligned_addresses": len(aligned_addresses),
            "us_binary_only_addresses": len(binary_only_addresses),
            "module_home_rate": len(standard_owned_addresses) / len(strict_addresses) if strict_addresses else None,
            "path_alignment_rate": len(aligned_addresses) / len(strict_addresses) if strict_addresses else None,
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
        "jp_path_only_c_manifest": path_only_c_manifest(jp_files, us_files, jp_defs, resolved),
        "c_manifest_scopes": {
            "jp_path_only_c_manifest": "Every JP .c path absent from the US source tree, including zero-function wrappers.",
            "jp_only_c_manifest": "Legacy field name: verified non-naked function modules lacking US standard C owners; NOT the JP-exclusive path inventory.",
        },
    }


def build_report(root: Path, us_root: Path, *, us_ref: str | None = 'HEAD') -> dict[str, object]:
    """Pin US-derived candidates to one committed tree by default."""
    with us_reference(root, us_root, us_ref) as (reference, provenance):
        report = _build_report(root, reference)
        # Keep JSON deterministic and identify the logical repository, not a
        # random ephemeral directory that has already been cleaned on return.
        report['roots']['us'] = str(us_root.resolve())
        report['us_reference'] = provenance
        if 'functions' in report:
            symbol_input = reference / 'pokeemerald.sym'
            available = symbol_input.is_file()
            report['functions']['us_binary_symbol_evidence'] = {
                'status': 'provided_unvalidated_artifact' if available else 'unavailable',
                'sha256': hashlib.sha256(symbol_input.read_bytes()).hexdigest() if available else None,
                'role': 'symbol_name_candidates_only; no_US_build_or_ROM_equivalence_claim',
            }
            if not available:
                # No supplied US symbols is not evidence of zero binary-only
                # functions, nor a negative lookup for every individual name.
                report['functions']['us_binary_only_addresses'] = None
                for owner in report['functions'].get('ownership', []):
                    owner['us_binary_symbol'] = None
        if 'script_data' in report:
            report['script_data']['linked_sections']['us']['evidence_status'] = (
                'provided_unvalidated_artifact' if (reference / 'pokeemerald.map').is_file() else 'unavailable')
        return report


def percentage(value: float | None) -> str:
    return "unavailable" if value is None else "%.2f%%" % (value * 100)


def print_report(report: dict[str, object]) -> None:
    files = report["files"]
    modules = report["c_modules"]
    functions = report["functions"]
    maps = report["maps"]
    convergence = report["map_convergence"]
    script_data = report["script_data"]
    incbin = report["incbin"]
    assets = report["asset_naming"]
    print("Structural audit (source inventory + evidence-bound JP function addresses)")
    reference = report.get('us_reference', {})
    print('US reference: ' + (reference['commit'] + ' (committed Git blobs only; live WIP excluded)'
                             if reference.get('mode') == 'git_snapshot'
                             else 'unverified live worktree; not a fixed pret source reference'))
    print("file paths: JP=%d US=%d same=%d JP-only=%d US-only=%d" % (
        sum(files["jp"]["directories"].values()), sum(files["us"]["directories"].values()),
        files["same_path"], files["jp_only"], files["us_only"]))
    print("C modules: JP=%d US=%d same-path=%d JP-only=%d US-only=%d" % (
        modules["jp"], modules["us"], modules["same_path"], modules["jp_only"], modules["us_only"]))
    print("source C definitions: non-naked=%d naked=%d; bound=%d unresolved=%d; address-metric=%s" % (
        functions["source_non_naked_definitions"], functions["source_naked_definitions"],
        functions["bound_c_definitions"], len(functions["unresolved_bindings"]), functions["metric_status"]))
    print("strict C (verified lower bound): %d/%d = %s (naked asm addresses: %d)" % (
        functions["strict_c_addresses"], functions["funcmap_unique_addresses"],
        percentage(functions["strict_c_rate"]), functions["naked_assembly_addresses"]))
    print("source inline definitions=%d; proved inline_not_emitted=%d; other unresolved=%d (source units, not ROM addresses)" % (
        functions["source_inline_definitions"], len(functions["inline_not_emitted_definitions"]),
        len(functions["unresolved_emitted_or_unknown_bindings"])))
    print("module home (funcmap US-name candidates): %d strict addresses = %s; path alignment: %d = %s; US binary-only: %s" % (
        functions["standard_owned_addresses"], percentage(functions["module_home_rate"]),
        functions["module_aligned_addresses"], percentage(functions["path_alignment_rate"]),
        'unavailable' if functions["us_binary_only_addresses"] is None else functions["us_binary_only_addresses"]))
    print("JP-exclusive .c paths: %d; non-US-function semantic-gap modules: %d (different scopes)" % (
        len(report["jp_path_only_c_manifest"]), len(report["jp_only_c_manifest"])))
    binding = functions["binding_audit"]
    print("legacy fan-out metrics invalid: natural strict/naked overlap old=%d verified=%d; rejected=%s" % (
        binding["legacy_name_fanout"]["natural_strict_naked_overlap"],
        binding["verified_owner_bindings"]["natural_strict_naked_overlap"],
        binding["rejected_assignment_counts"]))
    print("transition files: " + ", ".join(
        "%s=%d" % (name, value["count"])
        for name, value in report["transition_files"].items()))
    print("incbin: references=%d unique=%d raw=%d non-raw=%d missing=%d visible-baserom-ranges=%d visible-baserom-bytes=0x%X unbounded-baserom=%d" % (
        incbin["references"], incbin["unique_paths"], incbin["raw_binary_references"],
        incbin["non_raw_references"], incbin["missing_resource_paths"],
        incbin["raw_baserom_visible_range_references"],
        incbin["raw_baserom_visible_bytes"],
        incbin["raw_baserom_unbounded_references"]))
    print("resource-collection: physical-source-occurrences/all-branches unresolved=%d; INCGFX-separate=%d sources=%d generated-context-diagnostics=%d" % (
        incbin["unresolved_resource_references"], incbin["incgfx_references"],
        incbin["incgfx_unique_source_paths"], incbin["incgfx_unresolved_references"]))
    print("asset naming: referenced=%d exact-US=%d unique-candidates=%d ambiguous=%d no-match=%d" % (
        assets["referenced_graphics_or_sound_paths"], assets["exact_us_paths"],
        assets["unique_us_basename_candidates"], assets["ambiguous_us_basename_candidates"],
        assets["no_us_basename_match"]))
    print("map structure: owners=%d owner-scripts=%d (%.2f%%) non-owner=%d included=%d; "
          "map.json=%d events.inc=%d upper-events=%d structure-complete=%d "
          "(direct=%d owner=%d shared-scripts/events=%d/%d); semantic-review=%s current=%d/%d" % (
        maps["map_table_owners"], maps["first_owner_scripts_inc"], maps["jp_scripts_owner_rate"] * 100,
        maps["non_owner_scripts_inc"],
        maps["event_script_included_owners"], maps["jp_map_json"], maps["jp_events_inc"],
        maps["upper_event_includes"], maps["structure_complete_maps"],
        maps["direct_structure_complete_maps"], maps["structure_complete_owner_maps"],
        maps["shared_scripts_maps"], maps["shared_events_maps"], maps["semantic_review"]["status"],
        maps["semantic_review"].get("reviewed_maps", 0), maps["jp_map_json"]))
    raw_streams = convergence["top_level_raw_baserom_directives"]
    print("map convergence: script-stream=%d event-stream=%d shared=%d headers=%d; "
          "event-pointers=%s; map raw scripts/events/resources=%d/%d/%d; "
          "top-level raw scripts/events/maps=%d/%d/%d; semantic-review=%s current=%d/%d" % (
              convergence["script_stream_maps"], convergence["event_stream_maps"],
              convergence["maps_in_both_streams"], convergence["header_records"],
              ",".join("%s=%d" % item for item in convergence["event_pointer_statuses"].items()),
              convergence["maps_with_raw_script_ranges"], convergence["maps_with_raw_event_ranges"],
              convergence["maps_with_raw_resource_ranges"],
              len(raw_streams["data/event_scripts.s"]),
              len(raw_streams[convergence["stream_files"]["events"]]),
              len(raw_streams["data/maps.s"]),
              convergence["semantic_review"]["status"],
              convergence["semantic_review"].get("reviewed_maps", 0),
              convergence["semantic_review"].get("total_maps", convergence["header_records"])))
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
    reference = report.get('us_reference', {})
    reference_note = (
        '> US 统计参照：Git `' + reference['commit'] + '`；仅使用该提交的真实文件，不混入工作区或未登记的 US 编译产物。'
        if reference.get('mode') == 'git_snapshot' else
        '> US 统计参照：显式使用未验证的工作区，US 衍生指标不代表固定 pret Git 版本。')
    return "\n".join([
        "# 可复现结构审计进度",
        "",
        "> 此文件由 `python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md` 生成。",
        "> `--output` 只写 JSON，且会拒绝 Markdown 路径，避免误覆盖本报告。",
        reference_note,
        '> US 二进制辅助证据缺失时输出 unavailable/null，而非真实零值；源码归属候选不依赖这些未登记的符号或链接产物。',
        "",
        "## 当前快照",
        "",
        f"- 严格 C：{functions['strict_c_addresses']}/{functions['funcmap_unique_addresses']} "
        f"({percentage(functions['strict_c_rate'])}，保守可证下界)；naked 汇编地址：{functions['naked_assembly_addresses']}；"
        f"strict/naked 交集：{functions['strict_naked_address_overlap']}。",
        f"- 源码函数体库存：非 naked {functions['source_non_naked_definitions']}、naked "
        f"{functions['source_naked_definitions']}；地址已绑定 {functions['bound_c_definitions']}、"
        f"未解析 {len(functions['unresolved_bindings'])}；指标证据状态：{functions['metric_status']}。",
        f"- inline 源码定义：{functions['source_inline_definitions']}；对象证实无独立入口 "
        f"{len(functions['inline_not_emitted_definitions'])}；其他未解析 "
        f"{len(functions['unresolved_emitted_or_unknown_bindings'])}。这些是源码库存单位，不是 ROM 分母。",
        "- 旧名称 fan-out 指标已失效；修正绑定导致计数下降属于测量纠错，不是反编译退步。"
        f"排除 naked 前自然交集：旧 {functions['binding_audit']['legacy_name_fanout']['natural_strict_naked_overlap']}、"
        f"新 {functions['binding_audit']['verified_owner_bindings']['natural_strict_naked_overlap']}。",
        f"- 模块归位：{functions['standard_owned_addresses']}/{functions['strict_c_addresses']} "
        f"({percentage(functions['module_home_rate'])})；路径对齐：{functions['module_aligned_addresses']}/"
        f"{functions['strict_c_addresses']} ({percentage(functions['path_alignment_rate'])})；US 标准名仍为 funcmap 候选，并非语义复核结论。",
        f"- JP 路径独有 C 清单：{len(report['jp_path_only_c_manifest'])}；无 US 标准函数 owner 的语义缺口模块："
        f"{len(report['jp_only_c_manifest'])}（两种口径，不沿用旧固定数）；同一源同名多地址未解析定义："
        f"{len(functions['multi_address_c_definitions'])}。",
        f"- 过渡文件：tail={transitions['tail']['count']}、rest={transitions['rest']['count']}、"
        f"mid={transitions['mid']['count']}、stub={transitions['stub']['count']}、"
        f"address={transitions['address']['count']}。",
        f"- incbin：{incbin['references']} 引用、{incbin['unique_paths']} 条唯一路径、"
        f"原始二进制 {incbin['raw_binary_references']}、非原始 {incbin['non_raw_references']}、"
        f"缺失资源 {incbin['missing_resource_paths']}；可见 baserom 范围 "
        f"{incbin['raw_baserom_visible_range_references']} 条/"
        f"0x{incbin['raw_baserom_visible_bytes']:X} 字节，未限定范围 "
        f"{incbin['raw_baserom_unbounded_references']} 条。",
        f"- 资源采集口径：物理源码引用（含全部源码分支），非默认构建发射量；"
        f"未解决/条件诊断 {incbin['unresolved_resource_references']} 条。"
        f"INCGFX 单列 {incbin['incgfx_references']} 次、{incbin['incgfx_unique_source_paths']} 个源资产，"
        f"生成上下文诊断 {incbin['incgfx_unresolved_references']} 条，不计入 incbin 分母。",
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
        f"- 地图静态语义复核：{maps['semantic_review']['status']}；当前证据有效 "
        f"{maps['semantic_review'].get('reviewed_maps', 0)}/{maps['jp_map_json']}。"
        "仅计显式登记且源码/原生证据仍有效的地图，不代表运行时玩法验证。",
        "- 有效复核证据版本（同一地图仅计一次）："
        + ("、".join(f"{kind}={count}" for kind, count in sorted(
            maps['semantic_review'].get('current_maps_by_review_type', {}).items())) or "未记录")
        + "。v4 包含按实际地址核对的类型化脚本、事件入口与共享调用闭包；版本统计不代表玩法完成度。",
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
        "| 严格 C 转换率 | 默认分支及由明确 Makefile 规则证实的附加编译分支中，非 `naked` C 函数体经 JP ELF 符号与 JP linker 输入对象范围验证 owner 的唯一 funcmap 地址 / funcmap 唯一地址；源码名与显式 `asm`/`__asm__` 链接名分开保留，显式链接名必须有 ELF/object STT_FUNC 证据。同名 static 按 source owner 和地址保留，不建立名称→地址覆盖表。缺证保留 unresolved，因此仅为保守可证下界；没有 ELF 证据时百分比 unavailable，不报 0% 退步。 |",
        "| C 多对象编译 | 同一 C 源码的额外宏编译只接受无条件 Makefile 规则、唯一首 C 输入、字面量整数宏和明确 CPP/CC/AS 配方；每个附加地址仍须通过真实 ET_REL STT_FUNC、输入段、offset/段大小和最终链接 owner 核验。相同定义不按编译次数重复计数；不支持的规则不猜测，不能把所有未选中分支直接并入 C 进度。JSON 保留规则、宏、真实源码 owner、输入对象与 Makefile 哈希；规则或对象晚于 ELF 则不绑定。 |",
        "| 模块归位率 | 已证实 JP owner 的严格 C 地址中，funcmap US 标准名候选在 US 源树有定义的地址 / 严格 C 地址；不代表该候选已逐函数语义复核。 |",
        "| 路径对齐率 | 上述地址中 JP 相对 `src/` 路径也属于 US owner 的地址 / 严格 C 地址。 |",
        "| 过渡文件 | 文件名包含 tail、rest、mid、stub 或地址式片段；分类可重叠。 |",
        "| incbin | 物理源码内 `.incbin`、`INCBIN_U8/U16/U32` 的文件实参引用数，含已证明的直接参数转发模板；宏定义本身不计引用，多文件实参逐个计数，重复路径另算唯一路径。源码分支均可见，条件/作用域/动态或未支持展开显式诊断，不宣称默认构建发射量。INCGFX 的源/生成路径元信息单列，不加入该分母。裸 `.bin/.gba`、asset 根目录外的压缩流及匿名命名压缩资产沿用原 raw 分类；显式 baserom 范围仍另列字节，不是总 ROM 转换率。 |",
        "| 资产命名 | 被引用的 `graphics/`、`sound/` 路径与 US 同名文件比较；仅生成候选，不自动改名。 |",
        "| 地图脚本 owner | `scripts.inc` 与 map-table 实际首 owner 名的交集 / 去重首 owner；共享表只属于首次出现地图。 |",
        "| 地图结构完整 | 同一地图具 `map.json`，且其 scripts/events 为本地图的物理文件与上层 include，或为 map.json 明示、header 精确指向且在 JP `data/` 有真实标签定义的共享 owner；只说明结构已拆分。 |",
        "| 地图静态语义复核 | 只接受 tools/map_semantic_reviews.json 中显式复核决定；校验地图源码、生成规则、宏/常量、布局资源、共享调用和 JP ELF/map/ROM 区间。缺证或失效不计当前有效数；无登记仍为 not_recorded。只覆盖条目声明的静态字段/控制流范围，不代表运行时玩法或共享系统全生命周期已验证。 |",
        "| 三流地图会合 | 以 `data/event_scripts.s`、`data/map_events.s`（旧树回退 `data/data_b2d_mid26.s`）和 `data/maps.s` 的同图记录连接 scripts、events、地图头/布局/tileset。别名和 baserom 范围均为待办，不构成完成。 |",
        "| script_data 顶层分区 | US linker 提供 8 个对象的目标 owner 顺序；JP linker map 提供实际范围和锚点。只在 JP 起止标签、末尾位置与 ROM 比对均成立时，才允许拆出一个 owner。 |",
        "| JP 路径独有 C 清单 | JP src/**/*.c 路径与 US 的差集；包含零函数的文本/数据包装文件。独立于无 US 标准函数 owner 的语义缺口模块清单。 |",
        "| 无 US 函数 owner 语义缺口清单 | 已证实 JP 地址绑定、非裸汇编、但无 US 标准 C owner 的函数模块；旧 jp_only_c_manifest 字段和 --manifest 保留此兼容口径，不是完整路径独有模块清单。 |",
        "",
        "## 复现与输入",
        "",
        "```sh",
        "python3 tools/audit_structure.py",
        "python3 tools/audit_structure.py --json --output build/audit-structure.json \\",
        "    --manifest build/jp-only-c-manifest.json",
        "python3 tools/audit_structure.py --transition-manifest build/transition-file-manifest.json",
        "python3 tools/audit_structure.py --jp-path-manifest build/jp-exclusive-c-paths.json",
        "python3 tools/audit_structure.py --map-convergence-manifest build/map-convergence-manifest.json",
        "python3 tools/audit_structure.py --script-data-manifest build/script-data-manifest.json",
        "python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md",
        "# 固定 US 提交重放（默认 HEAD 会在 JSON 中记录解析后的完整 commit/tree）",
        "python3 tools/audit_structure.py --us-ref " + reference.get('commit', 'COMMIT') + " --markdown-output DECOMP_PROGRESS.md",
        "# 比较另一份 US 工程时显式指定其根目录",
        "python3 tools/audit_structure.py --us-root /path/to/pokeemerald --markdown-output DECOMP_PROGRESS.md",
        "```",
        "",
        "源码库存、funcmap 和 incbin 清单不需要构建。函数地址指标读取匹配的 "
        "`pokeemerald_jp.elf` 与 `pokeemerald_jp.map`；输入 section 补证还读取对应 JP 对象的 STT_FUNC，"
        "libc 宏名称展开读取真实 include 链。JSON 记录这些输入 SHA-256、未解析原因和旧/新绑定诊断；"
        "缺失证据不按名字猜测。采样这些生成文件时须持有共享构建锁，避免 make clean 窗口。完整报告仍需要匹配的 "
        "`baserom_jp.gba` 来解析地图 owner。US 默认从指定 Git 提交的真实 blob 读取，"
        "不读取该目录的移植 WIP 或未跟踪生成物；资产命名候选只比较该提交实际包含的路径，"
        "缺少生成输出不等于 JP 命名错误。未登记的 US `.sym/.map` 不混入快照；"
        "缺少辅助证据明确标记 unavailable/null。只有显式 `--us-worktree` 才使用未验证的活目录。",
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
    reference_group = parser.add_mutually_exclusive_group()
    reference_group.add_argument('--us-ref', default='HEAD', help='US Git commit/ref (default HEAD; ignores worktree WIP)')
    reference_group.add_argument('--us-worktree', action='store_true', help='explicitly use unverified live US sources/artifacts')
    parser.add_argument("--json", action="store_true", help="print stable JSON")
    parser.add_argument("--output", type=Path, help="write the full JSON report (never Markdown)")
    parser.add_argument("--manifest", type=Path,
                        help="write the legacy non-US-function semantic-gap manifest (not JP-exclusive paths)")
    parser.add_argument("--jp-path-manifest", type=Path,
                        help="write every literal JP-exclusive .c path as JSON")
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
    if args.jp_path_manifest:
        require_destination_kind(args.jp_path_manifest, "json")
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
    try:
        report = build_report(ROOT, args.us_root.resolve(), us_ref=None if args.us_worktree else args.us_ref)
    except ValueError as exc:
        raise SystemExit('US reference error: ' + str(exc)) from exc
    encoded = json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True) + "\n"
    if args.output:
        write_output(args.output, encoded)
    if args.manifest:
        write_output(args.manifest, json.dumps(report["jp_only_c_manifest"], ensure_ascii=False,
                                                indent=2, sort_keys=True) + "\n")
    if args.jp_path_manifest:
        write_output(args.jp_path_manifest, json.dumps(report["jp_path_only_c_manifest"], ensure_ascii=False,
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
