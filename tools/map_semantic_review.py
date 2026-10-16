#!/usr/bin/env python3
"""Validate explicit, source/native-bound map reviews, never infer them from files.

A review is a versioned human/semantic assertion backed by immutable native
spans and scoped source fingerprints. This validator checks that its evidence
is still current; it does not automatically review or approve a map.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
from pathlib import Path, PurePosixPath

MANIFEST_PATH = 'tools/map_semantic_reviews.json'
REQUIRED_COMPONENTS = ('map.json', 'scripts.inc', 'events.inc', 'header.inc', 'connections.inc')
REQUIRED_NATIVE_ROLES = {'scripts', 'events', 'header', 'connections', 'layout', 'border', 'blockdata'}
REQUIRED_CONTEXT = {
    'asm/macros/map.inc', 'asm/macros/event.inc',
    'tools/jp_map_metadata.py', 'tools/jp_generate_layouts.py',
    'tools/mapjson/mapjson.cpp', 'tools/mapjson/mapjson.h',
    'tools/mapjson/json11.cpp', 'tools/mapjson/json11.h',
    'constants/map_constants.inc', 'constants/map_header.inc', 'constants/songs.inc',
    'include/constants/items.h', 'include/constants/flags.h', 'include/constants/vars.h',
    'include/constants/weather.h', 'include/constants/map_types.h',
    'data/event_scripts.s', 'data/map_events.s', 'data/maps.s',
    'data/maps/map_groups.json', 'data/maps/events.inc', 'data/maps/headers.inc',
    'data/maps/groups.inc', 'data/maps/connections.inc',
    'data/layouts/layouts.json', 'data/layouts/layouts_table.inc',
    'data/script_cmd_table.inc', 'include/constants/map_scripts.h',
    'include/constants/comparison_operators.h',
}
MAKE_PREFIXES = (
    'JP_STRUCTURED_MAPS', 'JP_STRUCTURED_MAP_METADATA_MAPS',
    '$(JP_STRUCTURED_MAP_EVENTS):', '$(JP_MAP_GROUP_AGGREGATES) &:',
    'data/maps/%/header.inc data/maps/%/connections.inc &:',
    'data/layouts/layouts.inc data/layouts/layouts_table.inc include/constants/layouts.h &:',
    '$(OBJ_DIR)/data/maps.o:', '$(OBJ_DIR)/data/map_events.o:',
)
LINKER_INPUTS = ('data/event_scripts.o', 'data/map_events.o', 'data/maps.o')
LABEL_RE = re.compile(r'(?m)^([A-Za-z_]\w*)::?\s*(?:@[^\n]*)?$')
SYMBOL_RE = re.compile(r'^\s*0x([0-9a-fA-F]{8,16})\s+([A-Za-z_]\w*)\s*$')
SHA256_RE = re.compile(r'^[0-9a-f]{64}$')
SHA1_RE = re.compile(r'^[0-9a-f]{40}$')
MAP_RE = re.compile(r'^[A-Za-z][A-Za-z0-9_]*$')
SCOPE = ('Direct-map script control flow, events, header flags, connections, '
         'layout/resource linkage and explicitly listed shared-script closure; '
         'not a claim that the whole project or all shared game systems are reviewed.')


def script_analysis(text: str) -> tuple[int, set[str]]:
    """Measure the explicit v1 grammar; unknown statements are never guessed.

    The initial schema covers empty/OnResume map tables and the reviewed
    switch/case/escape/return helper. More complex owners need an explicitly
    tested extension before they can be registered under this schema.
    """
    sizes = {'map_script': 5, 'call': 5, 'goto': 5, 'end': 1, 'return': 1,
             'switch': 5, 'case': 11, 'setescapewarp': 8}
    size, targets = 0, set()
    for raw in text.splitlines():
        line = raw.split('@', 1)[0].strip()
        if not line or re.fullmatch(r'[A-Za-z_]\w*::?', line):
            continue
        tokens = line.split(None, 1)
        op, args = tokens[0], tokens[1] if len(tokens) == 2 else ''
        if op == '.byte' and args.strip() == '0':
            size += 1
            continue
        if op not in sizes:
            raise ValueError('unsupported_direct_review_statement:' + op)
        size += sizes[op]
        if op in ('map_script', 'call', 'goto', 'case'):
            target = args.split(',')[-1].strip()
            if not MAP_RE.fullmatch(target):
                raise ValueError('nonsemantic_script_target')
            targets.add(target)
    return size, targets


def label_blocks(text: str) -> dict[str, str]:
    labels = list(LABEL_RE.finditer(text))
    result = {}
    for i, match in enumerate(labels):
        name = match.group(1)
        if name in result:
            raise ValueError('ambiguous_script_label')
        result[name] = text[match.start():labels[i + 1].start() if i + 1 < len(labels) else len(text)]
    return result


def component_contracts(root: Path, batch: dict, maps: list[str]) -> tuple[dict, dict]:
    """Derive component identity/extent and actual shared-call closure from source."""
    contracts, external = {}, set()
    for name in maps:
        metadata = json.loads(local_path(root, f'data/maps/{name}/map.json').read_text())
        script = local_path(root, f'data/maps/{name}/scripts.inc').read_text()
        blocks = label_blocks(script)
        if not blocks or next(iter(blocks)) != name + '_MapScripts':
            raise ValueError('noncanonical_map_script_owner')
        length, targets = script_analysis(script)
        external.update(targets - blocks.keys())
        contracts[(name, 'scripts')] = (name + '_MapScripts', length)
        counts = [len(metadata.get(key, [])) for key in
                  ('object_events', 'warp_events', 'coord_events', 'bg_events')]
        suffixes = ('_MapObjectEvents', '_MapWarps', '_MapCoordEvents', '_MapBGEvents')
        first = next((name + suffix for count, suffix in zip(counts, suffixes) if count), name + '_MapEvents')
        contracts[(name, 'events')] = (first, 20 + sum(n * stride for n, stride in zip(counts, (24, 8, 16, 12))))
        contracts[(name, 'header')] = (name, 28)
        contracts[(name, 'connections')] = (name + '_MapConnectionsList', 12 * len(metadata.get('connections', [])) + 8)
        contracts[(name, 'layout')] = (name + '_Layout', 24)
        for filename, role, suffix in (('border.bin', 'border', '_Layout_Border'), ('map.bin', 'blockdata', '_Layout_Blockdata')):
            contracts[(name, role)] = (name + suffix, local_path(root, f'data/layouts/{name}/{filename}').stat().st_size)
    dependencies = batch.get('shared_dependencies', [])
    if not isinstance(dependencies, list):
        raise ValueError('invalid_shared_dependencies')
    entries = {}
    for dep in dependencies:
        if not isinstance(dep, dict) or not isinstance(dep.get('entry'), str) or dep['entry'] in entries:
            raise ValueError('invalid_or_duplicate_shared_dependency')
        entries[dep['entry']] = dep
    pending, visited, shared = list(external), set(), {}
    while pending:
        entry = pending.pop()
        if entry in visited:
            continue
        visited.add(entry)
        if entry not in entries:
            raise ValueError('missing_shared_call_evidence:' + entry)
        dep = entries[entry]
        blocks = label_blocks(local_path(root, dep.get('path')).read_text())
        reachable, todo = set(), [entry]
        while todo:
            label = todo.pop()
            if label in reachable:
                continue
            if label not in blocks:
                raise ValueError('missing_shared_script_label')
            reachable.add(label)
            _, targets = script_analysis(blocks[label])
            todo.extend(targets & blocks.keys())
            pending.extend(targets - blocks.keys())
        ordered = [label for label in blocks if label in reachable]
        if not ordered or ordered[0] != entry or dep.get('labels') != ordered:
            raise ValueError('incomplete_or_reordered_shared_closure')
        if not any(c.get('path') == dep['path'] and c.get('selector') == 'asm_labels'
                   and c.get('labels') == ordered for c in batch['sources']):
            raise ValueError('missing_shared_source_binding')
        sizes = [(label, script_analysis(blocks[label])[0]) for label in ordered]
        shared[entry] = sizes
        contracts[(None, entry)] = (entry, sum(size for label, size in sizes))
    if visited != entries.keys():
        raise ValueError('unreachable_shared_dependency')
    return contracts, shared


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def compile_context(root: Path, seeds: set[str]) -> set[str]:
    """Resolve repository macro/constant includes without sweeping other maps.

    Runtime map/script/text owners are not recursively swept from the three
    aggregate inputs. Once a compile-time include is selected, however, its
    quoted includes are all dependencies, including data/script_cmd_table.inc.
    """
    pending = [(p, p.startswith(('asm/', 'include/', 'constants/', 'tools/'))
                or p == 'data/script_cmd_table.inc') for p in sorted(seeds)]
    seen, result = set(), set()
    while pending:
        path, context = pending.pop()
        key = (path, context)
        if key in seen:
            continue
        seen.add(key)
        if context:
            result.add(path)
        text = local_path(root, path).read_text(encoding='utf-8')
        for kind, name in re.findall(r'(?m)^\s*(#\s*include|\.include)\s+"([^"]+)"', text):
            candidates = ([str(PurePosixPath(path).parent / name), name, 'include/' + name]
                          if kind.startswith('#') else [name, str(PurePosixPath(path).parent / name)])
            relative = next((p for p in candidates if (root / p).is_file()), None)
            if relative is None:
                raise ValueError('missing_compile_include:' + name)
            selected = (context or relative.startswith(('asm/', 'include/', 'constants/', 'tools/'))
                        or relative == 'data/script_cmd_table.inc')
            if selected:
                # Validate canonical in-repository resolution before traversing.
                local_path(root, relative)
                pending.append((relative, True))
    return result


def local_path(root: Path, relative: object) -> Path:
    """Reject noncanonical paths, symlink escapes and nonfiles."""
    if not isinstance(relative, str) or '\\' in relative:
        raise ValueError('invalid_repository_path')
    path = PurePosixPath(relative)
    if path.is_absolute() or not path.parts or any(p in ('.', '..') for p in path.parts):
        raise ValueError('invalid_repository_path')
    if str(path) != relative or ':' in relative:
        raise ValueError('invalid_repository_path')
    resolved = (root / relative).resolve()
    if not resolved.is_relative_to(root.resolve()) or not resolved.is_file():
        raise ValueError('missing_or_external_source')
    return resolved


def source_payload(root: Path, claim: dict) -> bytes:
    """Hash whole files or explicitly selected native assembly label blocks."""
    path = local_path(root, claim.get('path'))
    selector = claim.get('selector')
    if selector == 'file':
        return path.read_bytes()
    if selector == 'linker_inputs':
        inputs = claim.get('inputs')
        if inputs != list(LINKER_INPUTS):
            raise ValueError('invalid_linker_input_selection')
        selected, found = [], {name: 0 for name in inputs}
        for line in path.read_text(encoding='utf-8').splitlines(True):
            matches = [name for name in inputs if re.search(re.escape(name) + r'\s*\(', line)]
            if matches or re.match(r'^\s*#\s*(?:if|ifdef|ifndef|elif|else|endif)\b', line):
                selected.append(line)
            for name in matches:
                found[name] += 1
        if any(count != 1 for count in found.values()):
            raise ValueError('missing_or_ambiguous_linker_input')
        return ''.join(selected).encode()
    if selector == 'json_layout':
        data = json.loads(path.read_text(encoding='utf-8'))
        if not isinstance(data, dict) or not isinstance(data.get('layouts'), list):
            raise ValueError('invalid_layout_metadata_source')
        if any(not isinstance(v, dict) for v in data['layouts']):
            raise ValueError('invalid_layout_metadata_entry')
        entries = [v for v in data['layouts'] if v.get('id') == claim.get('id')]
        if len(entries) != 1 or not isinstance(claim.get('id'), str):
            raise ValueError('missing_or_ambiguous_layout_metadata')
        return (json.dumps(entries[0], sort_keys=True, separators=(',', ':')) + '\n').encode()
    if selector == 'make_prefixes':
        prefixes = claim.get('prefixes')
        if not isinstance(prefixes, list) or not prefixes or any(not isinstance(v, str) or not v for v in prefixes):
            raise ValueError('invalid_make_selection')
        lines = path.read_text(encoding='utf-8').splitlines(True)
        selected, found = [], set()
        for i, line in enumerate(lines):
            matches = {p for p in prefixes if line.startswith(p)}
            if matches:
                found.update(matches)
                end = i + 1
                while end < len(lines) and (lines[end - 1].rstrip().endswith('\\') or lines[end].startswith('\t')):
                    end += 1
                selected.extend(lines[i:end])
            elif re.match(r'^(?:ifdef|ifndef|ifeq|ifneq|else|endif)\b', line):
                selected.append(line)
        if found != set(prefixes):
            raise ValueError('missing_make_rule_or_membership')
        # Track the variables actually consumed by these rules (including
        # CPP/PREPROC/AS/tool paths), not unrelated graphics asset lists.
        assignments = {}
        for i, line in enumerate(lines):
            match = re.match(r'^(?:override\s+|export\s+)?([A-Za-z_]\w*)\s*(?::=|\+=|\?=|=)', line)
            if match:
                end = i + 1
                while end < len(lines) and lines[end - 1].rstrip().endswith('\\'):
                    end += 1
                assignments.setdefault(match.group(1), []).append(''.join(lines[i:end]))
        consumed = set()
        pending = re.findall(r'\$\(([A-Za-z_]\w*)\)', ''.join(selected))
        variable_source = []
        while pending:
            name = pending.pop()
            if name in consumed:
                continue
            consumed.add(name)
            definitions = assignments.get(name, [])
            variable_source.extend(definitions)
            pending += re.findall(r'\$\(([A-Za-z_]\w*)\)', ''.join(definitions))
        return (''.join(selected) + '\n# consumed Make variables\n' + ''.join(sorted(set(variable_source)))).encode()
    if selector != 'asm_labels':
        raise ValueError('unsupported_source_selector')
    labels = claim.get('labels')
    if not isinstance(labels, list) or not labels or len(set(labels)) != len(labels):
        raise ValueError('invalid_label_selection')
    text = path.read_text(encoding='utf-8')
    matches = list(LABEL_RE.finditer(text))
    blocks = {}
    for i, match in enumerate(matches):
        end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
        blocks.setdefault(match.group(1), []).append(text[match.start():end])
    selected = []
    for label in labels:
        if not isinstance(label, str) or len(blocks.get(label, [])) != 1:
            raise ValueError('missing_or_ambiguous_label')
        selected.append(blocks[label][0])
    return '\n'.join(selected).encode('utf-8')


def _integer(value: object) -> int:
    if isinstance(value, bool):
        raise ValueError('invalid_integer')
    if isinstance(value, int):
        return value
    if isinstance(value, str) and re.fullmatch(r'0x[0-9A-Fa-f]+', value):
        return int(value, 16)
    raise ValueError('invalid_integer')


def native_elf(data: bytes) -> tuple[dict[str, set[int]], list[tuple[int, bytes]]]:
    """Read defined global/local symbols and allocated ROM bytes from ELF32/ARM."""
    if len(data) < 52 or data[:7] != b'\x7fELF\x01\x01\x01':
        raise ValueError('unsupported_native_elf')
    header = struct.unpack_from('<16sHHIIIIIHHHHHH', data)
    if header[1:3] != (2, 40) or header[11] != 40 or not header[12]:
        raise ValueError('unsupported_native_elf')
    offset, count = header[6], header[12]
    if offset + count * 40 > len(data):
        raise ValueError('truncated_native_elf')
    sections = [struct.unpack_from('<10I', data, offset + i * 40) for i in range(count)]
    def payload(section):
        start, size = section[4:6]
        if start + size > len(data):
            raise ValueError('truncated_native_elf')
        return data[start:start + size]
    symbols, memory = {}, []
    for section in sections:
        if section[1] == 1 and section[2] & 2 and 0x08000000 <= section[3] < 0x09000000:
            memory.append((section[3], payload(section)))
        if section[1] != 2:
            continue
        if section[6] >= len(sections) or section[9] != 16 or section[5] % 16:
            raise ValueError('invalid_native_symbol_table')
        strings = payload(sections[section[6]])
        entries = payload(section)
        for at in range(0, len(entries), 16):
            name, value, size, info, other, owner = struct.unpack_from('<IIIBBH', entries, at)
            if not owner or not 0x08000000 <= value < 0x09000000:
                continue
            if name >= len(strings):
                raise ValueError('invalid_native_symbol_name')
            end = strings.find(b'\0', name)
            if end < 0:
                raise ValueError('invalid_native_symbol_name')
            text = strings[name:end].decode('utf-8')
            if text:
                symbols.setdefault(text, set()).add(value)
    if not memory or not symbols:
        raise ValueError('missing_native_elf_evidence')
    return symbols, memory


def _review_batch(root: Path, batch: dict, maps: set[str], native: dict) -> dict:
    """Validate one explicit direct-owner batch; unsupported cases fail closed."""
    name = batch.get('id')
    if not isinstance(name, str) or not MAP_RE.fullmatch(name):
        raise ValueError('invalid_batch_id')
    reviewed = batch.get('maps')
    if (not isinstance(reviewed, list) or not reviewed
            or any(not isinstance(n, str) or not MAP_RE.fullmatch(n) for n in reviewed)
            or len(set(reviewed)) != len(reviewed)):
        raise ValueError('invalid_map_list')
    if not set(reviewed) <= maps:
        raise ValueError('unknown_map')
    if batch.get('review_type') != 'direct_map_v1' or batch.get('decision') != 'reviewed':
        raise ValueError('unsupported_or_unapproved_review')
    if not SHA1_RE.fullmatch(str(batch.get('jp_commit', ''))):
        raise ValueError('missing_jp_baseline')
    reference = batch.get('us_reference')
    if not isinstance(reference, dict) or not SHA1_RE.fullmatch(str(reference.get('commit', ''))):
        raise ValueError('missing_immutable_us_reference')
    us_files = reference.get('files')
    if not isinstance(us_files, dict) or not us_files:
        raise ValueError('missing_us_source_fingerprints')
    for path, digest in us_files.items():
        if not path.startswith('data/') or not SHA256_RE.fullmatch(str(digest)):
            raise ValueError('invalid_us_source_fingerprint')
    sources = batch.get('sources')
    if not isinstance(sources, list) or not sources:
        raise ValueError('missing_source_evidence')
    file_claims = set()
    identities = set()
    errors = []
    latest_source_ns = 0
    for claim in sources:
        if not isinstance(claim, dict) or not SHA256_RE.fullmatch(str(claim.get('sha256', ''))):
            raise ValueError('invalid_source_claim')
        identity = (claim.get('path'), claim.get('selector'), tuple(claim.get('labels', [])),
                    claim.get('id'), tuple(claim.get('prefixes', [])), tuple(claim.get('inputs', [])))
        if identity in identities:
            raise ValueError('duplicate_source_claim')
        identities.add(identity)
        try:
            payload = source_payload(root, claim)
            latest_source_ns = max(latest_source_ns, local_path(root, claim.get('path')).stat().st_mtime_ns)
            if sha256(payload) != claim['sha256']:
                errors.append('source_changed:' + str(claim.get('path')))
        except (OSError, UnicodeError, ValueError) as exc:
            errors.append(str(exc) + ':' + str(claim.get('path')))
        if claim.get('selector') == 'file':
            file_claims.add(claim.get('path'))
    required = {f'data/maps/{n}/{part}' for n in reviewed for part in REQUIRED_COMPONENTS} | REQUIRED_CONTEXT
    if not required <= file_claims:
        raise ValueError('incomplete_map_or_generator_source_coverage')
    context = compile_context(root, REQUIRED_CONTEXT | {
        f'data/maps/{n}/scripts.inc' for n in reviewed} | {
        c['path'] for c in sources if c.get('selector') == 'asm_labels'})
    if not context <= file_claims:
        raise ValueError('incomplete_macro_constant_dependency_closure')
    if not {f'data/maps/{n}/map.json' for n in reviewed} <= us_files.keys():
        raise ValueError('incomplete_us_map_reference')
    for n in reviewed:
        layout_sources = {f'data/layouts/{n}/{part}' for part in ('border.bin', 'map.bin')}
        if not layout_sources <= file_claims:
            raise ValueError('incomplete_layout_resource_coverage')
        expected_labels = {n + suffix for suffix in ('_Layout_Border', '_Layout_Blockdata', '_Layout')}
        labels = {label for c in sources if c.get('path') == 'data/layouts/layouts.inc'
                  and c.get('selector') == 'asm_labels' for label in c.get('labels', [])}
        if not expected_labels <= labels:
            raise ValueError('incomplete_layout_definition_coverage')
    checks = batch.get('checks')
    required_checks = {'script_control_flow', 'event_fields', 'header_flags', 'connections',
                       'layout_resources', 'shared_call_closure', 'localization'}
    if (not isinstance(checks, dict) or set(checks) != set(reviewed)
            or any(not isinstance(v, dict) or set(v) != required_checks
                   or any(not isinstance(note, str) or not note.strip() for note in v.values())
                   for v in checks.values())):
        raise ValueError('incomplete_explicit_semantic_checks')
    for n in reviewed:
        metadata = json.loads(local_path(root, f'data/maps/{n}/map.json').read_text())
        if metadata.get('name') != n or 'shared_scripts_map' in metadata or 'shared_events_map' in metadata:
            raise ValueError('unsupported_shared_or_mismatched_map')
        if not any(c.get('path') == 'data/layouts/layouts.json' and c.get('selector') == 'json_layout'
                   and c.get('id') == metadata.get('layout') for c in sources):
            raise ValueError('missing_layout_metadata_source')
    if not any(c.get('path') == 'Makefile' and c.get('selector') == 'make_prefixes'
               and set(c.get('prefixes', [])) >= set(MAKE_PREFIXES) for c in sources):
        raise ValueError('missing_generation_rule_evidence')
    if not any(c.get('path') == 'ld_script_jp.txt' and c.get('selector') == 'linker_inputs'
               and c.get('inputs') == list(LINKER_INPUTS) for c in sources):
        raise ValueError('missing_linker_input_evidence')
    # The remainder checks native artifact provenance and all explicit spans.
    return _native_batch(root, batch, reviewed, errors, native, latest_source_ns)


def _reachable(root: Path, start: str, cache: dict) -> set[str]:
    if start in cache:
        return cache[start]
    seen = set()
    pending = [start]
    while pending:
        name = pending.pop()
        if name in seen:
            continue
        seen.add(name)
        try:
            source = local_path(root, name).read_text(encoding='utf-8')
        except (OSError, UnicodeError, ValueError):
            continue
        pending += re.findall(r'(?m)^\s*\.include\s+"([^"]+)"\s*(?:@[^\n]*)?$', source)
    cache[start] = seen
    return seen


def _native_batch(root: Path, batch: dict, maps: list[str], errors: list[str], native: dict,
                  latest_source_ns: int) -> dict:
    contracts, shared = component_contracts(root, batch, maps)
    spans = batch.get('native_spans')
    if not isinstance(spans, list) or not spans:
        raise ValueError('missing_native_spans')
    roles = {name: set() for name in maps}
    identities = set()
    parsed = []
    for span in spans:
        if not isinstance(span, dict) or not SHA256_RE.fullmatch(str(span.get('sha256', ''))):
            raise ValueError('invalid_native_span')
        name, role, symbol = span.get('map'), span.get('role'), span.get('symbol')
        if (name not in roles and not (name is None and role == 'shared_script')):
            raise ValueError('unattributed_native_span')
        if not isinstance(symbol, str) or not MAP_RE.fullmatch(symbol):
            raise ValueError('invalid_native_symbol')
        address, size = _integer(span.get('address')), _integer(span.get('size'))
        if size <= 0 or not 0x08000000 <= address < address + size <= 0x09000000:
            raise ValueError('invalid_native_bounds')
        contract_key = (name, symbol if name is None else role)
        if contracts.get(contract_key) != (symbol, size):
            raise ValueError('native_component_identity_or_extent_mismatch')
        identity = (name, role, symbol)
        if identity in identities:
            raise ValueError('duplicate_native_span')
        identities.add(identity)
        if name is not None:
            if role not in REQUIRED_NATIVE_ROLES:
                raise ValueError('unsupported_native_role')
            roles[name].add(role)
        parsed.append((name, role, symbol, address, size, span['sha256']))
    if any(value != REQUIRED_NATIVE_ROLES for value in roles.values()):
        raise ValueError('incomplete_native_component_coverage')
    if {(name, symbol if name is None else role) for name, role, symbol, *rest in parsed} != contracts.keys():
        raise ValueError('incomplete_shared_native_coverage')
    expected_sha1 = batch.get('rom_sha1')
    if not SHA1_RE.fullmatch(str(expected_sha1)):
        raise ValueError('invalid_native_rom_identity')
    available = all((root / p).is_file() for p in ('baserom_jp.gba', 'pokeemerald_jp.gba', 'pokeemerald_jp.elf', 'pokeemerald_jp.map'))
    if available:
        if min((root / p).stat().st_mtime_ns for p in ('pokeemerald_jp.gba', 'pokeemerald_jp.elf', 'pokeemerald_jp.map')) < latest_source_ns:
            errors.append('native_artifacts_older_than_review_inputs')
        if 'rom' not in native:
            native['rom'] = (root / 'baserom_jp.gba').read_bytes()
            native['sha1'] = hashlib.sha1(native['rom']).hexdigest()
            native['build_sha1'] = hashlib.sha1((root / 'pokeemerald_jp.gba').read_bytes()).hexdigest()
            native['symbols'], native['memory'] = native_elf((root / 'pokeemerald_jp.elf').read_bytes())
            symbols, owners = {}, []
            for line in (root / 'pokeemerald_jp.map').read_text().splitlines():
                match = SYMBOL_RE.match(line)
                if match:
                    address, symbol = int(match.group(1), 16), match.group(2)
                    symbols.setdefault(symbol, set()).add(address)
                owner = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
                if owner:
                    owners.append((int(owner[1], 16), int(owner[2], 16), owner[3].replace('\\', '/')))
            native['map_symbols'] = symbols
            native['owners'] = owners
        if native['sha1'] != expected_sha1 or native['build_sha1'] != expected_sha1:
            errors.append('native_rom_identity_mismatch')
        for name, role, symbol, address, size, digest in parsed:
            if native['symbols'].get(symbol) != {address}:
                errors.append('native_symbol_mismatch:' + symbol)
            if symbol in native['map_symbols'] and native['map_symbols'][symbol] != {address}:
                errors.append('linker_symbol_mismatch:' + symbol)
            expected_owner = ('data/event_scripts.o' if role in ('scripts', 'shared_script')
                              else 'data/map_events.o' if role == 'events' else 'data/maps.o')
            if not any(start <= address and address + size <= start + length
                       and (path == expected_owner or path.endswith('/' + expected_owner))
                       for start, length, path in native['owners']):
                errors.append('native_input_owner_mismatch:' + symbol)
            offset = address - 0x08000000
            data = native['rom'][offset:offset + size]
            if len(data) != size or sha256(data) != digest:
                errors.append('native_bytes_mismatch:' + symbol)
            image = [payload[address - base:address - base + size] for base, payload in native['memory']
                     if base <= address and address + size <= base + len(payload)]
            if len(image) != 1 or image[0] != data:
                errors.append('native_elf_bytes_mismatch:' + symbol)
        for entry, pieces in shared.items():
            address = next(a for n, role, symbol, a, size, digest in parsed if n is None and symbol == entry)
            for label, size in pieces:
                if native['symbols'].get(label) != {address}:
                    errors.append('shared_closure_not_contiguous:' + label)
                address += size
    for name in maps:
        for start, part in (('data/event_scripts.s', 'scripts.inc'),
                            ('data/map_events.s', 'events.inc'),
                            ('data/maps.s', 'header.inc'), ('data/maps.s', 'connections.inc')):
            if f'data/maps/{name}/{part}' not in _reachable(root, start, native.setdefault('include_graph', {})):
                errors.append('unreachable_map_component:' + name + '/' + part)
    return {
        'id': batch['id'], 'maps': sorted(maps),
        'status': 'stale' if errors else 'current' if available else 'native_artifacts_unavailable',
        'errors': sorted(set(errors)), 'source_claims': len(batch['sources']),
        'native_spans': len(parsed), 'us_commit': batch['us_reference']['commit'],
        'reference_evidence': 'explicit_review_against_recorded_immutable_git_sources',
    }


def map_review_progress(root: Path, known_maps: set[str]) -> dict:
    """Return deterministic review status; malformed manifests never approve maps."""
    result = {'status': 'not_recorded', 'manifest': MANIFEST_PATH, 'scope': SCOPE,
              'reviewed_map_names': [], 'reviewed_maps': 0, 'total_maps': len(known_maps),
              'batches': [], 'errors': []}
    path = root / MANIFEST_PATH
    if not path.is_file():
        return result
    try:
        manifest = json.loads(local_path(root, MANIFEST_PATH).read_text(encoding='utf-8'))
        if not isinstance(manifest, dict) or manifest.get('schema_version') != 1:
            raise ValueError('unsupported_manifest_schema')
        batches = manifest.get('batches')
        if not isinstance(batches, list) or not batches:
            raise ValueError('empty_or_invalid_review_batches')
        names, ids, native = set(), set(), {}
        for batch in batches:
            if not isinstance(batch, dict):
                raise ValueError('invalid_review_batch')
            record = _review_batch(root, batch, known_maps, native)
            if record['id'] in ids or names & set(record['maps']):
                raise ValueError('duplicate_batch_or_map_review')
            ids.add(record['id']); names.update(record['maps'])
            result['batches'].append(record)
        current = sorted(name for b in result['batches'] if b['status'] == 'current' for name in b['maps'])
        result.update(status='recorded', reviewed_map_names=current, reviewed_maps=len(current))
    except (OSError, UnicodeError, ValueError, TypeError, KeyError) as exc:
        result.update(status='invalid_manifest', reviewed_map_names=[], reviewed_maps=0,
                      batches=[], errors=[str(exc)])
    return result


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    maps = {p.parent.name for p in (args.root / 'data/maps').glob('*/map.json')}
    report = map_review_progress(args.root, maps)
    text = json.dumps(report, ensure_ascii=False, sort_keys=True, indent=2) + '\n'
    if args.output:
        args.output.write_text(text, encoding='utf-8')
    else:
        print(text, end='')


if __name__ == '__main__':
    main()
