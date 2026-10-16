#!/usr/bin/env python3
"""Conservative resource-reference collection, without running a preprocessor.

The unit is a physical source occurrence, not an emitted ROM object. Headers
are scanned once, not once per translation unit. All source branches remain
visible; branch-selection uncertainty is reported rather than guessed.

Function-like resource templates are inferred from local #define bodies, never
from macro names. Only direct parameter/literal forwarding to an INCBIN/INCGFX
primitive is expanded. Indirection, cycles, conditional definitions, token
pasting and dynamic paths produce diagnostics. This intentionally does not
pretend to implement arbitrary C or GAS preprocessing.
"""

from __future__ import annotations

import bisect
import json
import re
from dataclasses import dataclass
from pathlib import PurePosixPath
from typing import Mapping

PRIMITIVE_RE = re.compile(r"(?:INCBIN|INCGFX)(?:_[A-Z0-9_]+)?\Z")
INCBIN_TYPES = {"INCBIN_U8", "INCBIN_U16", "INCBIN_U32"}
INCGFX_TYPES = {"INCGFX_U8", "INCGFX_U16", "INCGFX_U32"}
TOKEN_RE = re.compile(
    r'(?P<comment>//[^\n]*|/\*[\s\S]*?\*/)|'
    r'(?P<string>"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\')|'
    r'(?P<word>[A-Za-z_]\w*)|(?P<space>\s+)|(?P<other>.)')


@dataclass(frozen=True)
class Token:
    value: str
    kind: str
    start: int
    end: int


@dataclass(frozen=True)
class Macro:
    name: str
    parameters: tuple[str, ...] | None
    body: str
    owner: str
    line: int
    start: int
    end: int
    conditions: tuple[str, ...]


def _tokens(text: str) -> list[Token]:
    return [Token(m[0], m.lastgroup or "other", m.start(), m.end())
            for m in TOKEN_RE.finditer(text)
            if m.lastgroup not in {"comment", "space"}]


def _blank(text: str) -> str:
    return "".join("\n" if c == "\n" else " " for c in text)


def _without_comments(text: str) -> str:
    return TOKEN_RE.sub(lambda m: _blank(m[0]) if m.lastgroup == "comment" else m[0], text)


def _arguments(tokens: list[Token], opening: int) -> tuple[list[list[Token]], int] | None:
    """Split preprocessing arguments: strings and nested parentheses are atomic."""
    depth = 1
    start = opening + 1
    result = []
    for i in range(start, len(tokens)):
        value = tokens[i].value
        if value == "(":
            depth += 1
        elif value == ")":
            depth -= 1
            if depth == 0:
                if i > start or result:
                    result.append(tokens[start:i])
                return result, i
        elif value == "," and depth == 1:
            result.append(tokens[start:i])
            start = i + 1
    return None


def _literal(tokens: list[Token]) -> str | None:
    # The project's ReadString accepts one string, not arbitrary C expressions
    # or C's later adjacent-literal concatenation. Do not invent escape rules.
    if len(tokens) != 1 or tokens[0].kind != "string":
        return None
    value = tokens[0].value
    if not value.startswith('"') or "\\" in value or "\n" in value or "\r" in value:
        return None
    try:
        result = json.loads(value)
    except ValueError:
        return None
    return result if isinstance(result, str) and result else None


def _expression(tokens: list[Token]) -> str:
    return " ".join(t.value for t in tokens)


def _initializer_prefix(tokens: list[Token]) -> bool:
    """A pure primitive alias or a plain array initializer, not arbitrary code."""
    if not tokens:
        return True
    values = [t.value for t in tokens]
    if values[-1] != "=" or values.count("=") != 1 or values.count("[") != 1 or values.count("]") != 1:
        return False
    left, right = values.index("["), values.index("]")
    return (left >= 2 and left < right
            and all(t.kind == "word" or t.value == "*" for t in tokens[:left])
            and all(t.kind == "word" for t in tokens[right + 1:-1])
            and not any(v in {"(", ")", "{", "}", ";", "#"} for v in values[left + 1:right]))


def _leaf_in_body(tokens: list[Token], parameters: tuple[str, ...] | None = None) -> bool:
    return (any(t.kind == "word" and PRIMITIVE_RE.fullmatch(t.value)
                and t.value not in (parameters or ())
                and (i + 1 < len(tokens) and tokens[i + 1].value == "(" or len(tokens) == 1)
                for i, t in enumerate(tokens))
            or _inline_asm_incbin(tokens))


def _inline_asm_incbin(tokens: list[Token]) -> bool:
    return (any(t.value in {"asm", "__asm__"} for t in tokens)
            and any(t.kind == "string" and re.search(r"\.incbin\b", t.value) for t in tokens))


class Source:
    def __init__(self, owner: str, text: str):
        self.owner = owner
        self.text = text
        self.newlines = [i for i, c in enumerate(text) if c == "\n"]
        cleaned = _without_comments(text)
        self.assembly = PurePosixPath(owner).suffix in {".s", ".inc"}
        if self.assembly:
            # GAS @ comments are not C strings; only strip outside quotes.
            cleaned = re.sub(r'"(?:\\.|[^"\\])*"|@[^\n]*',
                             lambda m: _blank(m[0]) if m[0].startswith("@") else m[0], cleaned)
        self.macros: list[Macro] = []
        self.events: list[tuple[int, str, Macro | None, tuple[str, ...]]] = []
        self.contexts: list[tuple[int, tuple[str, ...]]] = [(0, ())]
        self.gas_macros: list[dict[str, object]] = []
        self.include_context: list[str] = []
        self._parse(cleaned)

    def line(self, position: int) -> int:
        return bisect.bisect_left(self.newlines, position) + 1

    def context(self, position: int) -> tuple[str, ...]:
        index = bisect.bisect_right(self.contexts, (position, (chr(0x10FFFF),))) - 1
        return self.contexts[index][1]

    def _parse(self, cleaned: str) -> None:
        lines = cleaned.splitlines(keepends=True)
        directives = []
        offset = 0
        i = 0
        while i < len(lines):
            start = offset
            part = lines[i]
            offset += len(part)
            i += 1
            while part.rstrip("\r\n").endswith("\\") and i < len(lines):
                part += lines[i]
                offset += len(lines[i])
                i += 1
            logical = re.sub(r"\\\r?\n", " ", part)
            match = re.match(r"^\s*#\s*(\w+)(.*)", logical)
            if match:
                directives.append((start, offset, match[1], match[2].strip()))
        # A conventional whole-header include guard does not select source
        # occurrences. It is not a claim that a TU actually includes the file.
        guard = None
        if PurePosixPath(self.owner).suffix == ".h" and len(directives) >= 3:
            first, second, last = directives[0], directives[1], directives[-1]
            if (first[2] == "ifndef" and second[2] == "define"
                    and second[3] == first[3] and last[2] == "endif"
                    and not cleaned[:first[0]].strip() and not cleaned[last[1]:].strip()):
                depth = 0
                matching = None
                for item in directives:
                    if item[2] in {"if", "ifdef", "ifndef"}:
                        depth += 1
                    elif item[2] == "endif":
                        depth -= 1
                        if depth == 0:
                            matching = item
                            break
                if matching == last:
                    guard = first[0]
        contexts: list[str | None] = []
        masked = list(cleaned)
        for start, end, kind, body in directives:
            conditions = tuple(x for x in contexts if x is not None)
            if kind == "define":
                match = re.match(r"([A-Za-z_]\w*)(\(([^)]*)\))?\s*(.*)", body)
                if match:
                    parameters = (None if match[2] is None else
                                  tuple(p.strip() for p in match[3].split(",") if p.strip()))
                    macro = Macro(match[1], parameters, match[4], self.owner,
                                  self.line(start), start, end, conditions)
                    self.macros.append(macro)
                    self.events.append((end, macro.name, macro, conditions))
            elif kind == "undef":
                name = body.split()[0] if body else ""
                self.events.append((end, name, None, conditions))
            elif kind in {"if", "ifdef", "ifndef"}:
                contexts.append(None if start == guard else f"{kind} {body} (line {self.line(start)})")
            elif kind in {"elif", "else"} and contexts:
                contexts[-1] = f"{kind} {body} (line {self.line(start)})"
            elif kind == "endif" and contexts:
                contexts.pop()
            elif kind == "include":
                self.include_context.append(body)
            self.contexts.append((end, tuple(x for x in contexts if x is not None)))
            masked[start:end] = _blank(cleaned[start:end])
        self.contexts.sort()
        if self.assembly:
            active = None
            cursor = 0
            gas_conditions = []
            gas_contexts = [(0, ())]
            for line in cleaned.splitlines(keepends=True):
                conditional = re.match(r"^\s*\.(if\w*|else|elseif|endif)\b(.*)", line)
                if conditional and active is None:
                    kind, expression = conditional[1], conditional[2].strip()
                    if kind == "endif":
                        if gas_conditions:
                            gas_conditions.pop()
                    elif kind in {"else", "elseif"}:
                        if gas_conditions:
                            gas_conditions[-1] = f"GAS .{kind} {expression} (line {self.line(cursor)})"
                    else:
                        gas_conditions.append(f"GAS .{kind} {expression} (line {self.line(cursor)})")
                    gas_contexts.append((cursor + len(line), tuple(gas_conditions)))
                match = re.match(r"^\s*\.macro\s+(\w+)(.*)", line)
                if match and active is None:
                    active = dict(name=match[1], parameters=match[2].strip(),
                                  owner=self.owner, line=self.line(cursor), start=cursor, body=[])
                elif re.match(r"^\s*\.endm\b", line) and active is not None:
                    active["end"] = cursor + len(line)
                    active["body"] = "".join(active["body"])
                    self.gas_macros.append(active)
                    masked[int(active["start"]):cursor + len(line)] = _blank(cleaned[int(active["start"]):cursor + len(line)])
                    active = None
                elif active is not None:
                    active["body"].append(line)
                cursor += len(line)
            cpp_contexts = sorted(self.contexts)
            positions = sorted({p for p, _ in cpp_contexts} | {p for p, _ in gas_contexts})
            self.contexts = []
            for position in positions:
                bound = (position, (chr(0x10FFFF),))
                cpp = cpp_contexts[bisect.bisect_right(cpp_contexts, bound) - 1][1]
                gas = gas_contexts[bisect.bisect_right(gas_contexts, bound) - 1][1]
                self.contexts.append((position, cpp + gas))
        self.code = "".join(masked)
        self.tokens = _tokens(self.code)
        self.contexts.sort()

    def binding(self, name: str, position: int) -> tuple[Macro | None, str | None]:
        value = None
        uncertain = False
        for end, event_name, macro, conditions in self.events:
            if end > position:
                break
            if event_name != name:
                continue
            if conditions:
                uncertain = True
            else:
                value = macro
                uncertain = False
        if uncertain:
            return None, "conditional_macro_binding"
        return value, None

    def has_local_event(self, name: str, position: int) -> bool:
        return any(end <= position and event_name == name
                   for end, event_name, _, _ in self.events)


def _resource_macros(sources: Mapping[str, Source]) -> set[str]:
    # Union by name is used ONLY to discover possible sinks. Actual resolution
    # always uses the local, ordered binding, never this cross-file graph.
    names = {m.name for source in sources.values() for m in source.macros}
    objects = {m.name for source in sources.values() for m in source.macros if m.parameters is None}
    graph: dict[str, set[str]] = {}
    reached = set()
    for source in sources.values():
        for macro in source.macros:
            body = _tokens(macro.body)
            children = {t.value for i, t in enumerate(body) if t.kind == "word"
                        and (t.value in objects or (i + 1 < len(body) and body[i + 1].value == "("))}
            children.difference_update(macro.parameters or ())
            graph.setdefault(macro.name, set()).update(children & names)
            if _leaf_in_body(body, macro.parameters):
                reached.add(macro.name)
    while True:
        extra = {name for name, children in graph.items() if children & reached}
        if extra <= reached:
            break
        reached.update(extra)
    return {name for name in reached if not PRIMITIVE_RE.fullmatch(name)}


def _dependency_problem(name: str, graph: dict[str, set[str]], candidates: set[str],
                        limit: int) -> tuple[str, list[str]] | None:
    def visit(current: str, trace: list[str]) -> tuple[str, list[str]] | None:
        if current in trace:
            return "macro_cycle", trace + [current]
        if len(trace) >= limit:
            return "macro_depth_limit", trace + [current]
        for child in sorted(graph.get(current, set()) & candidates):
            problem = visit(child, trace + [current])
            if problem:
                return problem
        return None
    return visit(name, [])


def collect_resource_references(
        sources: Mapping[str, str], *, support_sources: Mapping[str, str] | None = None,
        graphics_root: str | None = None, max_macro_depth: int = 16,
        candidate_macros: set[str] | None = None) -> dict[str, object]:
    """Return literal INCBIN occurrences, separate INCGFX metadata and diagnostics.

    support_sources contributes template discovery, not counted occurrences.
    Includes are NOT expanded into each TU; a cross-file macro call whose local
    binding is unknown is unresolved. candidate_macros can explicitly mark a
    known-but-unavailable resource macro without guessing from its spelling.
    graphics_root=None keeps the generated identity symbolic, not guessed.
    """
    if max_macro_depth < 1:
        raise ValueError("max_macro_depth must be positive")
    all_text = dict(support_sources or {})
    all_text.update(sources)
    parsed = {owner: Source(owner, text) for owner, text in sorted(all_text.items())}
    candidates = _resource_macros(parsed)
    candidates.update(candidate_macros or set())
    references: list[dict[str, object]] = []
    incgfx: list[dict[str, object]] = []
    unresolved: list[dict[str, object]] = []
    incgfx_unresolved: list[dict[str, object]] = []

    def diagnostic(source: Source, token: Token, macro: str, reason: str,
                   expression: str = "", trace: list[object] | None = None,
                   target: list[dict[str, object]] | None = None) -> None:
        item = dict(owner=source.owner, line=source.line(token.start), macro=macro,
                    reason=reason, expression=expression, macro_trace=trace or [],
                    conditions=list(source.context(token.start)))
        (unresolved if target is None else target).append(item)

    def emit(source: Source, token: Token, primitive: str, arguments: list[list[Token]],
             trace: list[object], invocation: str) -> None:
        if source.has_local_event(primitive, token.start):
            definition, problem = source.binding(primitive, token.start)
            reason = ("conditional_resource_primitive_binding" if problem else
                      "locally_undefined_resource_primitive" if definition is None else
                      "locally_redefined_resource_primitive")
            target = incgfx_unresolved if primitive.startswith("INCGFX") else unresolved
            diagnostic(source, token, invocation, reason, primitive, trace, target)
            return
        conditions = list(source.context(token.start))
        common = dict(owner=source.owner, line=source.line(token.start),
                      macro=invocation, primitive=primitive, macro_trace=trace,
                      conditions=conditions)
        if primitive.startswith("INCGFX"):
            if primitive not in INCGFX_TYPES or len(arguments) not in {2, 3}:
                diagnostic(source, token, invocation, "unsupported_incgfx_signature",
                           trace=trace, target=incgfx_unresolved)
                return
            values = [_literal(arg) for arg in arguments]
            if any(value is None for value in values):
                diagnostic(source, token, invocation, "nonliteral_incgfx_argument",
                           ", ".join(_expression(arg) for arg in arguments), trace,
                           incgfx_unresolved)
                return
            asset, extensions = values[:2]
            options = values[2] if len(values) == 3 else ""
            assert isinstance(asset, str) and isinstance(extensions, str) and isinstance(options, str)
            if not options.isascii():
                diagnostic(source, token, invocation, "unverified_incgfx_option_encoding",
                           options, trace, incgfx_unresolved)
                return
            encoded = "".join(c if c.isalnum() else "_" for c in options)
            tail = asset + encoded + extensions
            issues = []
            if graphics_root is None:
                issues.append("graphics_root_unspecified")
                diagnostic(source, token, invocation, issues[-1], tail, trace, incgfx_unresolved)
            incgfx.append(dict(**common, source_asset=asset, extensions=extensions,
                               arguments=options, arguments_as_path=encoded,
                               graphics_root=graphics_root, generated_tail=tail,
                               generated_path=None if graphics_root is None else graphics_root + tail,
                               unresolved=issues))
            return
        if primitive not in INCBIN_TYPES:
            diagnostic(source, token, invocation, "unsupported_incbin_type", primitive, trace)
            return
        if not arguments:
            diagnostic(source, token, invocation, "missing_incbin_arguments", trace=trace)
            return
        for index, argument in enumerate(arguments, 1):
            path = _literal(argument)
            if path is None:
                diagnostic(source, token, invocation, "nonliteral_incbin_path", _expression(argument), trace)
                continue
            references.append(dict(**common, resource=path, argument_index=index,
                                   syntax="c_primitive" if not trace else "c_template"))
        if conditions:
            # Count both physical branches, but do not imply default-build selection.
            diagnostic(source, token, invocation, "conditional_emission_not_selected", trace=trace)

    gas_names = set()
    gas_graph: dict[str, set[str]] = {}
    for source in parsed.values():
        for macro in source.gas_macros:
            body = str(macro["body"])
            name = str(macro["name"])
            gas_graph.setdefault(name, set()).update(re.findall(r"^\s*(\w+)\b", body, re.M))
            if re.search(r"^\s*\.incbin\b", body, re.M):
                gas_names.add(name)
    while True:
        extra = {name for name, children in gas_graph.items() if children & gas_names}
        if extra <= gas_names:
            break
        gas_names.update(extra)

    for owner in sorted(sources):
        source = parsed[owner]
        for macro in source.gas_macros:
            if macro["name"] in gas_names:
                diagnostic(source, Token(str(macro["name"]), "word", int(macro["start"]), int(macro["end"])),
                           str(macro["name"]), "unsupported_gas_resource_template", str(macro["body"]))
        tokens = source.tokens
        i = 0
        while i < len(tokens):
            token = tokens[i]
            name = token.value
            if name in {"asm", "__asm__"} and i + 1 < len(tokens) and tokens[i + 1].value == "(":
                assembly = _arguments(tokens, i + 1)
                if assembly is not None and _inline_asm_incbin(tokens[i:assembly[1] + 1]):
                    diagnostic(source, token, name, "unsupported_inline_assembly_resource",
                               _expression(tokens[i:assembly[1] + 1]))
                    i = assembly[1] + 1
                    continue
            if token.kind == "word" and (PRIMITIVE_RE.fullmatch(name) or name in candidates):
                if i + 1 >= len(tokens) or tokens[i + 1].value != "(":
                    if name in candidates:
                        macro, problem = source.binding(name, token.start)
                        if macro is not None and macro.parameters is None:
                            diagnostic(source, token, name, "unsupported_object_resource_macro", macro.body)
                    i += 1
                    continue
                result = _arguments(tokens, i + 1)
                if result is None:
                    diagnostic(source, token, name, "unclosed_resource_invocation")
                    i += 1
                    continue
                args, closing = result
                if PRIMITIVE_RE.fullmatch(name):
                    emit(source, token, name, args, [], name)
                else:
                    macro, binding_problem = source.binding(name, token.start)
                    trace = ([dict(name=name, owner=source.owner, line=source.line(token.start),
                                   binding="unavailable", includes=source.include_context)] if macro is None
                             else [dict(name=macro.name, owner=macro.owner, line=macro.line)])
                    # Discovery graph edges can come from different physical
                    # files. Never use that union to resolve a call or infer a
                    # cycle: each edge below comes from this local binding.
                    local_graph = {}
                    for candidate in candidates:
                        definition, problem = source.binding(candidate, token.start)
                        if definition is None or problem:
                            continue
                        body_tokens = _tokens(definition.body)
                        children = {t.value for n, t in enumerate(body_tokens[:-1])
                                    if t.kind == "word" and body_tokens[n + 1].value == "("}
                        children.difference_update(definition.parameters or ())
                        local_graph[candidate] = children & candidates
                    dependency_problem = _dependency_problem(name, local_graph, candidates, max_macro_depth)
                    if binding_problem:
                        diagnostic(source, token, name, binding_problem, trace=trace)
                    elif macro is None:
                        diagnostic(source, token, name, "resource_macro_binding_unavailable",
                                   "include scope or #undef requires explicit preprocessing", trace)
                    elif dependency_problem:
                        reason, chain = dependency_problem
                        chain_trace = []
                        for item in chain:
                            definition, _ = source.binding(item, token.start)
                            chain_trace.append(dict(name=item, owner=source.owner,
                                                    line=definition.line if definition else None))
                        diagnostic(source, token, name, reason, trace=chain_trace)
                    elif macro.parameters is None:
                        diagnostic(source, token, name, "unsupported_object_resource_macro", macro.body, trace)
                    elif any("..." in p for p in macro.parameters):
                        diagnostic(source, token, name, "unsupported_variadic_resource_template", macro.body, trace)
                    elif len(args) != len(macro.parameters):
                        diagnostic(source, token, name, "resource_macro_arity", macro.body, trace)
                    else:
                        body = _tokens(macro.body)
                        words = {t.value for t in body if t.kind == "word"}
                        calls = [(n, t.value) for n, t in enumerate(body[:-1])
                                 if t.kind == "word" and PRIMITIVE_RE.fullmatch(t.value)
                                 and body[n + 1].value == "("]
                        if not _leaf_in_body(body, macro.parameters) and not local_graph.get(name):
                            # A same-named macro in another source may be a
                            # resource wrapper; this local definition is not.
                            pass
                        elif _inline_asm_incbin(body):
                            diagnostic(source, token, name, "unsupported_inline_assembly_resource", macro.body, trace)
                        elif any(t.value == "#" for t in body):
                            diagnostic(source, token, name, "unsupported_macro_stringification_or_paste", macro.body, trace)
                        elif words & candidates:
                            diagnostic(source, token, name, "unsupported_resource_indirection", macro.body, trace)
                        elif words & {"if", "for", "while", "do", "switch"} or len(calls) != 1:
                            diagnostic(source, token, name, "unsupported_resource_template_shape", macro.body, trace)
                        else:
                            at, primitive = calls[0]
                            leaf = _arguments(body, at + 1)
                            # A direct initializer or a pure primitive alias is
                            # supported, not compound resource expressions.
                            if (leaf is None or not _initializer_prefix(body[:at])
                                    or any(t.value != ";" for t in body[leaf[1] + 1:])):
                                diagnostic(source, token, name, "unsupported_resource_template_shape", macro.body, trace)
                            else:
                                parameters = dict(zip(macro.parameters, args))
                                forwarded = []
                                bad = False
                                for argument in leaf[0]:
                                    if len(argument) == 1 and argument[0].value in parameters:
                                        forwarded.append(parameters[argument[0].value])
                                    elif _literal(argument) is not None:
                                        forwarded.append(argument)
                                    else:
                                        bad = True
                                if bad:
                                    diagnostic(source, token, name, "unsupported_resource_path_template", macro.body, trace)
                                else:
                                    emit(source, token, primitive, forwarded, trace, name)
                i = closing + 1
                continue
            # Direct assembly .incbin: do not mistake C strings or GAS template
            # bodies for actual literal paths. Offset/size parsing stays separate.
            if name == "." and i + 2 < len(tokens) and tokens[i + 1].value == "incbin":
                path_token = tokens[i + 2]
                line_start = source.code.rfind("\n", 0, token.start) + 1
                prefix = source.code[line_start:token.start]
                if (tokens[i + 1].start != token.end
                        or not re.fullmatch(r"\s*(?:[A-Za-z_.$][\w.$]*::?\s*)?", prefix)):
                    i += 1
                    continue
                if source.line(path_token.start) != source.line(token.start):
                    diagnostic(source, token, ".incbin", "missing_assembly_path_on_line")
                    i += 2
                    continue
                path = _literal([path_token])
                conditions = list(source.context(token.start))
                if path is None:
                    diagnostic(source, token, ".incbin", "nonliteral_assembly_incbin_path", path_token.value)
                else:
                    references.append(dict(owner=owner, line=source.line(token.start), resource=path,
                                           syntax="asm_incbin", macro=".incbin", primitive=".incbin",
                                           argument_index=1, macro_trace=[], conditions=conditions))
                    if conditions:
                        diagnostic(source, token, ".incbin", "conditional_emission_not_selected")
                i += 3
                continue
            i += 1
        if gas_names:
            cursor = 0
            for line in source.code.splitlines(keepends=True):
                match = re.match(r"^\s*(\w+)\b", line)
                if match and match[1] in gas_names:
                    diagnostic(source, Token(match[1], "word", cursor, cursor + len(line)),
                               match[1], "unsupported_gas_resource_invocation", line.strip())
                cursor += len(line)
    return dict(mode="physical_source_occurrences_all_branches", references=references,
                incgfx=incgfx, unresolved=unresolved, incgfx_unresolved=incgfx_unresolved)
