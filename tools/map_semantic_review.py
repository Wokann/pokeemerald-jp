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
import subprocess
from pathlib import Path, PurePosixPath

MANIFEST_PATH = 'tools/map_semantic_reviews.json'
REQUIRED_COMPONENTS = ('map.json', 'scripts.inc', 'events.inc', 'header.inc', 'connections.inc')
REQUIRED_NATIVE_ROLES = {'scripts', 'events', 'header', 'connections', 'layout', 'border', 'blockdata', 'default_layout_table'}
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
TEXT_CONTEXT = {'charmap.txt', 'include/constants/characters.h', 'tools/preproc/Makefile',
                'tools/map_semantic_review.py'} | {
    'tools/preproc/' + name for name in (
        'asm_file.cpp', 'asm_file.h', 'c_file.cpp', 'c_file.h', 'char_util.h',
        'charmap.cpp', 'charmap.h', 'io.cpp', 'io.h', 'preproc.cpp', 'preproc.h',
        'string_parser.cpp', 'string_parser.h', 'utf8.cpp', 'utf8.h')}
STORY_CONTEXT = TEXT_CONTEXT | {'tools/map_review_script_profile.py', 'data/specials.inc',
                               'asm/macros/movement.inc', 'src/field_control_avatar.c'}
TRAINER_ENGINE_CONTEXT = {'src/scrcmd.c', 'src/battle_setup.c', 'src/overworld.c', 'src/field_screen_effect.c'}
WARP_CONTEXT_SYMBOLS = {'ScrCmd_warp': 'src/scrcmd.c', 'DoWarp': 'src/field_screen_effect.c',
    'Task_WarpAndLoadMap': 'src/field_screen_effect.c', 'CB2_LoadMap': 'src/overworld.c',
    'ScriptContext_Init': 'src/script.c', 'InitScriptContext': 'src/script.c'}
CALLBACK_CONTEXT_SYMBOLS = {
    'SetCB2WhiteOut': 'src/post_battle_event_funcs.c', 'SetMainCallback2': 'src/main.c',
    'CB2_WhiteOut': 'src/overworld.c', 'ScriptContext_Init': 'src/script.c',
    'InitScriptContext': 'src/script.c',
}
TRAINER_ENGINE_SYMBOLS = {
    'ScrCmd_trainerbattle': 'src/scrcmd.c', 'ScrCmd_dotrainerbattle': 'src/scrcmd.c',
    'ScrCmd_gotopostbattlescript': 'src/scrcmd.c',
    'BattleSetup_ConfigureTrainerBattle': 'src/battle_setup.c',
    'BattleSetup_StartTrainerBattle': 'src/battle_setup.c',
    'BattleSetup_GetScriptAddrAfterBattle': 'src/battle_setup.c',
}
TRAINER_EXTENDED_SYMBOLS = {
    'ScrCmd_gotobeatenscript': 'src/scrcmd.c',
    'BattleSetup_GetTrainerPostBattleScript': 'src/battle_setup.c',
    'TrainerBattleLoadArgs': 'src/battle_setup.c',
    'BattleSetup_StartRematchBattle': 'src/battle_setup.c',
    'CB2_EndTrainerBattle': 'src/battle_setup.c',
    'CB2_EndRematchBattle': 'src/battle_setup.c',
    'IsPlayerDefeated': 'src/battle_setup.c',
}
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


def statements(text: str) -> list[str]:
    """Ignore comments, but never treat an @ inside a quoted JP string as one."""
    result = []
    for raw in text.splitlines():
        for match in re.finditer(r'"(?:\\.|[^"\\])*"|(@.*$)', raw):
            if match.group(1):
                raw = raw[:match.start()]
                break
        line = raw.strip()
        if line and not re.fullmatch(r'[A-Za-z_]\w*::?', line):
            if re.fullmatch(r'\.globl\s+[A-Za-z_]\w*', line):
                continue
            result.append(line)
    return result


def shared_include_entry(root: Path, dep: dict) -> str | None:
    """An explicitly declared sibling include is not part of a shared script."""
    boundaries = dep.get('end_before_includes')
    if boundaries is None:
        return None
    text_owner = (dep.get('kind') in ('string', 'braille')
                  and isinstance(dep.get('path'), str)
                  and re.fullmatch(r'data/scripts/[A-Za-z0-9_/]+\.inc', dep['path']))
    if ((dep.get('path') != 'data/event_scripts.s' and not text_owner) or not isinstance(boundaries, list)
            or not boundaries or any(not isinstance(p, str) or not re.fullmatch(
                r'data/(?:scripts|text)/[A-Za-z0-9_/]+\.inc', p) for p in boundaries)
            or len(set(boundaries)) != len(boundaries)):
        raise ValueError('invalid_shared_include_boundary')
    source = local_path(root, boundaries[0]).read_text()
    first = LABEL_RE.search(source)
    if first is None or statements(source[:first.start()]):
        raise ValueError('nonempty_shared_include_prefix')
    return first[1]


def shared_script_blocks(root: Path, dep: dict) -> dict[str, str]:
    """Keep local profiles strict; trim only a declared, terminal sibling tail.

    The full untrimmed asm-label source claim is still hashed. The boundary
    file is separately bound and its first native label must immediately
    follow this script; no included bytes are silently treated as reviewed.
    """
    following = shared_include_entry(root, dep)
    blocks = label_blocks(local_path(root, dep.get('path')).read_text())
    if following is None:
        return blocks
    scope = dep.get('labels', [dep.get('entry')])
    if (not isinstance(scope, list) or not scope or any(
            not isinstance(label, str) or not MAP_RE.fullmatch(label) for label in scope)
            or len(set(scope)) != len(scope) or scope[-1] not in blocks):
        raise ValueError('invalid_shared_include_scope')
    label = scope[-1]
    lines = blocks[label].splitlines(True)
    cuts = [i for i, line in enumerate(lines) if re.match(r'^\s*\.include\b', line)]
    if not cuts:
        raise ValueError('missing_shared_include_boundary')
    cut = cuts[0]
    body = ''.join(lines[:cut])
    text_owner = dep.get('kind') in ('string', 'braille')
    terminal = (bool(encoded_text(root, body, dep['kind'])) if text_owner
                else bool(statements(body)) and statements(body)[-1] in ('return', 'end'))
    if (not terminal
            or statements(''.join(lines[cut:])) != ['.include "' + p + '"' for p in dep['end_before_includes']]):
        raise ValueError('nonterminal_or_mixed_shared_include_boundary')
    blocks[label] = body
    return blocks


def text_kind(text: str) -> str | None:
    operations = {line.split(None, 1)[0] for line in statements(text)}
    if '.string' in operations:
        if operations != {'.string'}:
            raise ValueError('mixed_script_text_block')
        return 'string'
    if '.braille' in operations or 'brailleformat' in operations:
        if operations != {'.braille', 'brailleformat'}:
            raise ValueError('mixed_braille_text_block')
        return 'braille'
    return None


def special_input_object(root: Path, contract: dict) -> str:
    """Accept alternate C owners only from the existing conservative Make parser."""
    variant = contract.get('compile_variant')
    if variant is None:
        return contract['source_path'][:-2] + '.o'
    try:
        from audit_structure import c_compile_variants, function_definitions
    except ModuleNotFoundError:
        from tools.audit_structure import c_compile_variants, function_definitions
    if (not isinstance(variant, dict) or variant not in c_compile_variants(root)
            or 'src/' + variant['source_owner'] != contract['source_path']):
        raise ValueError('invalid_special_compile_variant')
    definitions = function_definitions(local_path(root, contract['source_path']), root, defines=variant['defines'])
    if contract['source_symbol'] not in {d.name for d in definitions}:
        raise ValueError('unselected_special_compile_variant_function')
    return variant['input_object']


def encoded_text(root: Path, text: str, kind: str) -> bytes:
    """Use the real JP preprocessor via stdin, with no external temporary files."""
    if kind not in ('string', 'braille') or text_kind(text) != kind:
        raise ValueError('invalid_text_dependency_kind')
    lines = statements(text)
    header = b''
    if kind == 'braille':
        formats = [line for line in lines if line.startswith('brailleformat ')]
        strings = [line for line in lines if line.startswith('.braille ')]
        if len(formats) != 1 or len(strings) != 1 or lines != formats + strings:
            raise ValueError('invalid_braille_object_format')
        values = [v.strip() for v in formats[0].split(None, 1)[1].split(',')]
        if len(values) != 6 or any(not re.fullmatch(r'(?:0x[0-9A-Fa-f]+|[0-9]+)', v) for v in values):
            raise ValueError('invalid_braille_format_fields')
        numbers = [int(v, 16 if v.startswith('0x') else 10) for v in values]
        if any(n > 255 for n in numbers):
            raise ValueError('invalid_braille_format_fields')
        header = bytes(numbers)
        lines = strings
    for line in lines:
        if not re.fullmatch(r'\.(?:string|braille)\s+"(?:\\.|[^"\\])*"', line):
            raise ValueError('invalid_text_source_literal')
    binary = local_path(root, 'tools/preproc/preproc')
    charmap = local_path(root, 'charmap.txt')
    try:
        result = subprocess.run([str(binary), '-i', 'map-review.s', str(charmap)],
                                input='\n'.join(lines) + '\n', text=True, capture_output=True,
                                cwd=root, check=False, timeout=10)
    except (OSError, subprocess.TimeoutExpired) as exc:
        raise ValueError('text_preprocessor_unavailable') from exc
    if result.returncode:
        raise ValueError('text_preprocessor_rejected_source')
    payload = bytearray()
    for line in result.stdout.splitlines():
        if not line.strip() or line.startswith('# '):
            continue
        match = re.fullmatch(r'\s*\.byte\s+(0x[0-9A-Fa-f]{2}(?:\s*,\s*0x[0-9A-Fa-f]{2})*)\s*', line)
        if not match:
            raise ValueError('unexpected_text_preprocessor_output')
        payload.extend(int(v.strip(), 16) for v in match.group(1).split(','))
    if not payload or payload[-1] != 255 or (kind == 'braille' and payload.count(255) != 1):
        raise ValueError('unterminated_review_text')
    return header + payload


def extended_analysis(root: Path, text: str) -> tuple[int, set[str], dict[str, str]]:
    """Explicit v2 grammar for dive hooks, flags, metatiles and JP text.

    Fixed-size forms below correspond to reviewed event.inc expansions. In
    particular goto_if_ne accepts only the three-argument variable/immediate
    form, and msgbox only an explicit MSGBOX_SIGN; no polymorphic defaults or
    table-dependent Special waits are guessed.
    """
    size, scripts, texts = 0, set(), {}
    blocks = label_blocks(text)
    if not blocks:
        raise ValueError('missing_review_script_labels')
    sizes = {'setdivewarp': (8, 3), 'setflag': (3, 1), 'setmetatile': (9, 4),
             'getplayerxy': (5, 2), 'goto_if_set': (9, 2), 'call_if_set': (9, 2),
             'goto_if_ne': (11, 3), 'lockall': (1, 0), 'releaseall': (1, 0),
             'msgbox': (8, 2), 'braillemsgbox': (7, 1), 'message': (5, 1),
             'waitmessage': (1, 0), 'waitbuttonpress': (1, 0)}
    for block in blocks.values():
        kind = text_kind(block)
        if kind:
            size += len(encoded_text(root, block, kind))
            continue
        for line in statements(block):
            tokens = line.split(None, 1)
            op = tokens[0]
            if op not in sizes:
                length, targets = script_analysis(line)
                size += length
                scripts.update(targets)
                continue
            length, count = sizes[op]
            args = [v.strip() for v in tokens[1].split(',')] if len(tokens) == 2 else []
            if len(args) != count or any(not v for v in args):
                raise ValueError('unsupported_direct_review_arguments:' + op)
            if op == 'goto_if_ne' and (not re.fullmatch(r'VAR_[A-Za-z0-9_]+', args[0])
                                       or not re.fullmatch(r'(?:0x[0-9A-Fa-f]+|[0-9]+)', args[1])):
                raise ValueError('unsupported_compare_operand')
            if op == 'msgbox' and args[1] != 'MSGBOX_SIGN':
                raise ValueError('unsupported_message_type')
            if op == 'message' and args != ['NULL']:
                raise ValueError('unsupported_buffered_message_argument')
            if op == 'msgbox':
                scripts.add('Std_MsgboxSign')
            if op in ('goto_if_set', 'call_if_set', 'goto_if_ne', 'msgbox', 'braillemsgbox'):
                target = args[0] if op in ('msgbox', 'braillemsgbox') else args[-1]
                if not MAP_RE.fullmatch(target):
                    raise ValueError('nonsemantic_script_target')
                if op in ('msgbox', 'braillemsgbox'):
                    kind = 'string' if op == 'msgbox' else 'braille'
                    if target in texts and texts[target] != kind:
                        raise ValueError('conflicting_text_usage:' + target)
                    texts[target] = kind
                else:
                    scripts.add(target)
            size += length
    return size, scripts, texts


def default_layout_owner(root: Path, name: str, *, allow_shared=False) -> dict:
    """Resolve the JSON's real default owner, not a map-directory convention."""
    metadata = json.loads(local_path(root, f'data/maps/{name}/map.json').read_text())
    data = json.loads(local_path(root, 'data/layouts/layouts.json').read_text())
    rows = data.get('layouts') if isinstance(data, dict) else None
    if not isinstance(rows, list) or any(not isinstance(row, dict) for row in rows):
        raise ValueError('invalid_default_layout_metadata')
    selected = [row for row in rows if row.get('id') == metadata.get('layout')]
    if not isinstance(metadata.get('layout'), str) or not re.fullmatch(r'LAYOUT_\w+', metadata['layout']):
        raise ValueError('invalid_default_layout_id')
    if len(selected) != 1:
        raise ValueError('missing_or_ambiguous_default_layout')
    row = selected[0].copy()
    owner = row.get('name')
    if not isinstance(owner, str) or not MAP_RE.fullmatch(owner):
        raise ValueError('invalid_default_layout_owner')
    shared = owner != name + '_Layout'
    if shared and not allow_shared:
        raise ValueError('unsupported_shared_default_layout_version')
    for field, filename in (('border_filepath', 'border.bin'), ('blockdata_filepath', 'map.bin')):
        # Preserve older canonical-layout records; a shared owner must always
        # name its actual assets explicitly rather than guessing a directory.
        if field not in row and not shared:
            row[field] = f'data/layouts/{name}/{filename}'
        path = row.get(field)
        if (not isinstance(path, str) or not path.startswith('data/layouts/')
                or not path.endswith('/' + filename) or '..' in Path(path).parts):
            raise ValueError('invalid_default_layout_asset_path')
        local_path(root, path)
    if shared and (any(type(row.get(field)) is not int or row[field] <= 0 for field in ('width', 'height'))
                   or any(not isinstance(row.get(field), str) or not MAP_RE.fullmatch(row[field])
                          for field in ('primary_tileset', 'secondary_tileset'))):
        raise ValueError('invalid_shared_default_layout_shape')
    return row


def _dynamic_blockdata_size(root: Path, row: dict) -> int:
    """Keep an asset's optional zero-filled word-alignment tail in its extent."""
    data = local_path(root, row['blockdata_filepath']).read_bytes()
    logical_size = row['width'] * row['height'] * 2
    if len(data) != logical_size:
        if len(data) != (logical_size + 3) & ~3 or any(data[logical_size:]):
            raise ValueError('missing_or_wrong_dynamic_layout_asset')
    return len(data)


def dynamic_layout_contracts(root: Path, batch: dict) -> tuple[dict, dict, list]:
    """Resolve only explicitly used layout IDs to their real generated owners."""
    ids = batch.get('dynamic_layouts', [])
    if (not isinstance(ids, list)
            or any(not isinstance(v, str) or not re.fullmatch(r'LAYOUT_\w+', v) for v in ids)
            or len(ids) != len(set(ids))):
        raise ValueError('invalid_dynamic_layout_contracts')
    if not ids:
        return {}, {}, []
    if batch.get('review_type') != 'direct_map_v4':
        raise ValueError('unsupported_dynamic_layout_contracts')
    files = {c['path'] for c in batch['sources'] if c.get('selector') == 'file'}
    if not {'include/constants/layouts.h', 'src/overworld.c', 'src/scrcmd.c',
            'data/layouts/layouts_table.inc'} <= files:
        raise ValueError('missing_dynamic_layout_context')
    data = json.loads(local_path(root, 'data/layouts/layouts.json').read_text())
    layouts = data.get('layouts') if isinstance(data, dict) else None
    if not isinstance(layouts, list) or any(not isinstance(row, dict) for row in layouts):
        raise ValueError('invalid_dynamic_layout_metadata')
    blocks = label_blocks(local_path(root, 'data/layouts/layouts.inc').read_text())
    table_blocks = label_blocks(local_path(root, 'data/layouts/layouts_table.inc').read_text())
    if 'gMapLayouts' not in table_blocks:
        raise ValueError('missing_dynamic_layout_table')
    table = []
    for line in statements(table_blocks['gMapLayouts']):
        match = re.fullmatch(r'\.4byte\s+([A-Za-z_]\w*)', line)
        if not match:
            raise ValueError('unsupported_dynamic_layout_table')
        table.append(match[1])
    roles, selected = {'gMapLayouts': 'dynamic_layout_table'}, {}
    for layout_id in ids:
        matches = [row for row in layouts if row.get('id') == layout_id]
        if len(matches) != 1:
            raise ValueError('missing_or_ambiguous_dynamic_layout')
        row = matches[0]
        name = row.get('name')
        width, height = row.get('width'), row.get('height')
        if (not isinstance(name, str) or not MAP_RE.fullmatch(name)
                or type(width) is not int or type(height) is not int or min(width, height) <= 0):
            raise ValueError('invalid_dynamic_layout_shape')
        labels = [name + '_Border', name + '_Blockdata', name]
        if (not any(c.get('path') == 'data/layouts/layouts.json' and c.get('selector') == 'json_layout'
                    and c.get('id') == layout_id for c in batch['sources'])
                or not any(c.get('path') == 'data/layouts/layouts.inc' and c.get('selector') == 'asm_labels'
                           and c.get('labels') == labels for c in batch['sources'])):
            raise ValueError('missing_dynamic_layout_source_binding')
        for key, symbol, size, role in (('border_filepath', labels[0], 8, 'dynamic_border'),
                                       ('blockdata_filepath', labels[1], width * height * 2, 'dynamic_blockdata')):
            path = row.get(key)
            if not isinstance(path, str) or path not in files:
                raise ValueError('missing_or_wrong_dynamic_layout_asset')
            if role == 'dynamic_blockdata':
                _dynamic_blockdata_size(root, row)
            elif local_path(root, path).stat().st_size != size:
                raise ValueError('missing_or_wrong_dynamic_layout_asset')
            owned = statements(blocks[symbol]) if symbol in blocks else []
            if not owned or owned[0] != '.incbin "' + path + '"':
                raise ValueError('dynamic_layout_asset_owner_mismatch')
            roles[symbol] = role
        fields = [str(width), str(height), labels[0], labels[1], row.get('primary_tileset'), row.get('secondary_tileset')]
        if (any(not isinstance(v, str) or not MAP_RE.fullmatch(v) for v in fields[2:])
                or name not in blocks or statements(blocks[name]) != ['.4byte ' + v for v in fields]):
            raise ValueError('dynamic_layout_structure_mismatch')
        index = _literal_define(root, 'include/constants/layouts.h', layout_id)
        if not 1 <= index <= len(table) or table[index - 1] != name:
            raise ValueError('dynamic_layout_index_mismatch')
        roles[name] = 'dynamic_layout'
        selected[layout_id] = row
    return roles, selected, table


def story_event_target(event: dict, field: str, *, version=3):
    """Separate tagged data payloads from actual script pointers, fail closed."""
    if not isinstance(event, dict):
        raise ValueError('invalid_story_event_record')
    target = event.get('script')
    if field == 'bg_events':
        kind = event.get('type')
        if kind == 'hidden_item':
            if 'script' in event or not all(isinstance(event.get(k), str) and MAP_RE.fullmatch(event[k])
                                           for k in ('item', 'flag')):
                raise ValueError('unsupported_story_hidden_item')
            target = 'EventScript_HiddenItemScript'
        elif version == 4 and kind == 'secret_base':
            if ('script' in event or not isinstance(event.get('secret_base_id'), str)
                    or not re.fullmatch(r'SECRET_BASE_[A-Z0-9_]+', event['secret_base_id'])):
                raise ValueError('unsupported_story_secret_base')
            # The BG union stores a base ID, not this pointer. The C dispatcher
            # selects this root only when facing north and TrySetCurSecretBase succeeds.
            target = 'SecretBase_EventScript_CheckEntrance'
        elif kind != 'sign' or target in (None, 'NULL', '0', '0x0', 0):
            raise ValueError('unsupported_story_background_dispatch')
    elif field == 'coord_events':
        if version == 4 and event.get('type') == 'weather':
            if ('script' in event or 'var' in event or 'var_value' in event
                    or not isinstance(event.get('weather'), str)
                    or not re.fullmatch(r'COORD_EVENT_WEATHER_[A-Z0-9_]+', event['weather'])):
                raise ValueError('unsupported_story_weather_coordinate')
            # mapjson emits script=NULL,index=0; C passes trigger to DoCoordEventWeather.
            return None
        if event.get('type') != 'trigger':
            raise ValueError('unsupported_story_coordinate_dispatch')
    elif field != 'object_events':
        raise ValueError('unsupported_story_event_field')
    if target is None or target in ('NULL', '0', '0x0') or type(target) is int and target == 0:
        return None
    if not isinstance(target, str) or not MAP_RE.fullmatch(target):
        raise ValueError('nonsemantic_event_script_target')
    return target


def _external_message_dependencies(texts: dict, local_labels: set, actual_kinds: dict,
                                   explicit_dependencies=()) -> dict:
    """A typed local owner covers its text even when another map references it."""
    external = {}
    for target, kind in texts.items():
        if target in local_labels:
            if actual_kinds.get(target) != kind:
                raise ValueError('incompatible_message_target:' + target)
            if target in explicit_dependencies:
                # Older batches retain a separate, fully bound native text
                # claim even when the enclosing map owner also covers it.
                external[target] = kind
        else:
            external[target] = kind
    return external


def component_contracts(root: Path, batch: dict, maps: list[str]) -> tuple[dict, dict]:
    """Derive component identity/extent and actual shared-call closure from source."""
    contracts, external, external_text = {}, set(), {}
    local_labels = set()
    addressed = batch.get('review_type') == 'direct_map_v4'
    story = batch.get('review_type') in ('direct_map_v3', 'direct_map_v4')
    extended = batch.get('review_type') in ('direct_map_v2', 'direct_map_v3', 'direct_map_v4')
    expected_kinds, actual_kinds, used_standard, used_specials = {}, {}, {}, {}
    used_layouts = set()
    trainer_battles, trainer_run, trainer_post, trainer_beaten = {}, False, False, False
    context_exits = {}
    callback_exits = {}
    if story:
        # Lazy import: the typed profiler reuses this module's text encoder.
        try:
            from map_review_script_profile import profile_owner, special_waits
        except ModuleNotFoundError:
            from tools.map_review_script_profile import profile_owner, special_waits
        waits = special_waits(root)
    def expect(target, kind):
        if target in expected_kinds and expected_kinds[target] != kind:
            raise ValueError('incompatible_reference_kinds:' + target)
        expected_kinds[target] = kind
    def typed_targets(profiles):
        nonlocal trainer_run, trainer_post, trainer_beaten
        texts, targets = {}, set()
        for label, profile in profiles.items():
            if profile.context_warp:
                context_exits[label] = profile.context_warp
            if profile.context_callback:
                callback_exits[label] = profile.context_callback
            if profile.runtime_scripts:
                bound = {c.get('path') for c in batch['sources'] if c.get('selector') == 'file'}
                if (profile.runtime_scripts != {'saved_wonder_card'}
                        or not {'src/script.c', 'src/scrcmd.c', 'src/mystery_gift.c', 'src/util.c'} <= bound):
                    raise ValueError('missing_runtime_script_interface_context')
            if profile.runtime_texts:
                bound = {c.get('path') for c in batch['sources'] if c.get('selector') == 'file'}
                contexts = {
                    'battletent_getopponentintro': {
                        'src/battle_tent.c', 'src/battle_tower.c', 'include/battle_tower.h',
                        'src/frontier_util.c', 'src/scrcmd.c', 'src/string_util.c', 'include/string_util.h'},
                    'CopyEReaderTrainerGreeting': {
                        'src/battle_tower.c', 'include/battle_tower.h', 'src/easy_chat.c',
                        'src/scrcmd.c', 'src/string_util.c', 'include/string_util.h'},
                }
                producer = profile.runtime_texts.get('gStringVar4')
                if (set(profile.runtime_texts) != {'gStringVar4'} or producer not in contexts
                        or not contexts[producer] <= bound):
                    raise ValueError('missing_runtime_text_interface_context')
            if label in actual_kinds and actual_kinds[label] != profile.kind:
                raise ValueError('incompatible_definition_kind:' + label)
            actual_kinds[label] = profile.kind
            if addressed and profile.may_fall_through and not profile.fallthrough:
                raise ValueError('unmodeled_script_fallthrough:' + label)
            for target, kind in list(profile.targets.items()) + list(profile.texts.items()):
                expect(target, kind)
            texts.update(profile.texts)
            targets.update(profile.targets)
            used_standard.update(profile.standard_scripts)
            used_specials.update(profile.specials)
            used_layouts.update(profile.layouts)
            for battle in profile.trainer_battles:
                if battle['address'] in trainer_battles and trainer_battles[battle['address']] != battle:
                    raise ValueError('conflicting_trainer_battle_site')
                trainer_battles[battle['address']] = battle
            trainer_run |= profile.trainer_run
            trainer_post |= profile.trainer_post_return
            trainer_beaten |= profile.trainer_beaten_return
        return sum(p.size for p in profiles.values()), targets, texts
    def source_address(owner, symbol):
        spans = batch.get('native_spans')
        if not isinstance(spans, list):
            raise ValueError('missing_addressed_native_spans')
        matches = [s for s in spans if isinstance(s, dict) and s.get('map') == owner and s.get('symbol') == symbol]
        if len(matches) != 1:
            raise ValueError('missing_or_ambiguous_source_address:' + symbol)
        return _integer(matches[0].get('address'))
    def analyze(text, address=None):
        if story:
            return typed_targets(profile_owner(root, text, waits, version=4 if addressed else 3, address=address))
        if extended:
            return extended_analysis(root, text)
        length, targets = script_analysis(text)
        return length, targets, {}
    def collect_text(texts, blocks):
        for target, kind in texts.items():
            if target in blocks:
                if text_kind(blocks[target]) != kind:
                    raise ValueError('incompatible_message_target:' + target)
            elif target in external_text and external_text[target] != kind:
                raise ValueError('conflicting_text_usage:' + target)
            else:
                external_text[target] = kind
    for name in maps:
        metadata = json.loads(local_path(root, f'data/maps/{name}/map.json').read_text())
        script = local_path(root, f'data/maps/{name}/scripts.inc').read_text()
        blocks = label_blocks(script)
        if not blocks or next(iter(blocks)) != name + '_MapScripts':
            raise ValueError('noncanonical_map_script_owner')
        local_labels.update(blocks)
        length, targets, texts = analyze(script, source_address(name, name + '_MapScripts') if addressed else None)
        if story:
            expect(name + '_MapScripts', 'map_table')
            for field in ('object_events', 'coord_events', 'bg_events'):
                for event in metadata.get(field, []):
                    target = story_event_target(event, field, version=4 if addressed else 3)
                    event_context = set()
                    if addressed and field == 'bg_events' and event.get('type') == 'secret_base':
                        event_context = {'src/field_control_avatar.c', 'src/secret_base.c', 'src/fldeff_misc.c',
                                         'include/constants/secret_bases.h'}
                    elif addressed and field == 'coord_events' and event.get('type') == 'weather':
                        event_context = {'src/field_control_avatar.c', 'src/coord_event_weather.c',
                                         'include/constants/weather.h'}
                    bound = {s.get('path') for s in batch.get('sources', [])
                             if isinstance(s, dict) and s.get('selector') == 'file'}
                    if not event_context <= bound:
                        raise ValueError('missing_story_event_dispatch_context')
                    if target is None:
                        continue
                    expect(target, 'script')
                    targets.add(target)
        if extended:
            for target in targets & blocks.keys():
                if text_kind(blocks[target]):
                    raise ValueError('script_target_is_text:' + target)
        external.update(targets - blocks.keys())
        collect_text(texts, blocks)
        contracts[(name, 'scripts')] = (name + '_MapScripts', length)
        counts = [len(metadata.get(key, [])) for key in
                  ('object_events', 'warp_events', 'coord_events', 'bg_events')]
        suffixes = ('_ObjectEvents', '_MapWarps', '_MapCoordEvents', '_MapBGEvents')
        first = next((name + suffix for count, suffix in zip(counts, suffixes) if count), name + '_MapEvents')
        contracts[(name, 'events')] = (first, 20 + sum(n * stride for n, stride in zip(counts, (24, 8, 16, 12))))
        contracts[(name, 'header')] = (name, 28)
        connections = metadata.get('connections', [])
        unused_connections = metadata.get('has_unused_connection_table', False)
        if type(unused_connections) is not bool or unused_connections and connections != []:
            raise ValueError('invalid_unused_connection_metadata')
        if connections is None:
            if not extended or statements(local_path(root, f'data/maps/{name}/connections.inc').read_text()):
                raise ValueError('unsupported_or_nonempty_null_connections')
        else:
            if not isinstance(connections, list):
                raise ValueError('invalid_connection_metadata')
            contracts[(name, 'connections')] = (name + '_MapConnectionsList', 12 * len(connections) + 8)
        layout = default_layout_owner(root, name, allow_shared=addressed)
        contracts[(name, 'layout')] = (layout['name'], 24)
        for field, role, suffix in (('border_filepath', 'border', '_Border'), ('blockdata_filepath', 'blockdata', '_Blockdata')):
            contracts[(name, role)] = (layout['name'] + suffix, local_path(root, layout[field]).stat().st_size)
        if layout['name'] != name + '_Layout':
            if not {'include/constants/layouts.h', 'data/layouts/layouts_table.inc'} <= {
                    c.get('path') for c in batch['sources'] if c.get('selector') == 'file'}:
                raise ValueError('missing_shared_default_layout_context')
            layout_blocks = label_blocks(local_path(root, 'data/layouts/layouts.inc').read_text())
            expected = [str(layout['width']), str(layout['height']), layout['name'] + '_Border',
                        layout['name'] + '_Blockdata', layout['primary_tileset'], layout['secondary_tileset']]
            if (layout['name'] not in layout_blocks
                    or statements(layout_blocks[layout['name']]) != ['.4byte ' + value for value in expected]):
                raise ValueError('shared_default_layout_structure_mismatch')
            for field, suffix in (('border_filepath', '_Border'), ('blockdata_filepath', '_Blockdata')):
                owned = statements(layout_blocks.get(layout['name'] + suffix, ''))
                if not owned or owned[0] != '.incbin "' + layout[field] + '"':
                    raise ValueError('shared_default_layout_asset_owner_mismatch')
            if local_path(root, layout['border_filepath']).stat().st_size != 8:
                raise ValueError('invalid_shared_default_layout_border')
            _dynamic_blockdata_size(root, layout)
            table = label_blocks(local_path(root, 'data/layouts/layouts_table.inc').read_text()).get('gMapLayouts', '')
            entries = [re.fullmatch(r'\.4byte\s+([A-Za-z_]\w*)', line) for line in statements(table)]
            index = _literal_define(root, 'include/constants/layouts.h', layout['id'])
            if (not entries or not all(entries) or not 1 <= index <= len(entries)
                    or entries[index - 1][1] != layout['name']):
                raise ValueError('shared_default_layout_table_mismatch')
            contracts[(name, 'default_layout_table')] = ('gMapLayouts', 4 * len(entries))
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
        if story and entry in local_labels and entry not in entries:
            # A shared helper may call back into the explicitly profiled map
            # owner. Its source/native extent is already bound there; the
            # final expected/actual kind check must still validate this edge.
            continue
        if entry in visited:
            continue
        visited.add(entry)
        if entry not in entries:
            raise ValueError('missing_shared_call_evidence:' + entry)
        dep = entries[entry]
        if dep.get('end_before_includes') is not None and batch['review_type'] != 'direct_map_v4':
            raise ValueError('unsupported_shared_include_review_version')
        blocks = shared_script_blocks(root, dep)
        if not set(dep.get('end_before_includes', [])) <= {
                c.get('path') for c in batch['sources'] if c.get('selector') == 'file'}:
            raise ValueError('missing_shared_include_boundary_source')
        scope = dep.get('labels') if story else blocks.keys()
        if story and (not isinstance(scope, list) or not scope or len(scope) != len(set(scope))
                      or any(not isinstance(label, str) or not MAP_RE.fullmatch(label) for label in scope)):
            raise ValueError('invalid_shared_typed_scope')
        prepared = None
        if addressed:
            if any(label not in blocks for label in scope):
                raise ValueError('missing_shared_script_label')
            prepared = profile_owner(root, '\n'.join(blocks[label] for label in scope), waits,
                                     version=4, address=source_address(None, entry))
            typed_targets(prepared)
        reachable, todo = set(), [entry]
        while todo:
            label = todo.pop()
            if label in reachable:
                continue
            if label not in blocks:
                raise ValueError('missing_shared_script_label')
            reachable.add(label)
            if prepared is not None:
                targets, texts = set(prepared[label].targets), prepared[label].texts
            else:
                _, targets, texts = analyze(blocks[label])
            # A selected shared-script claim does not cover other text blocks
            # merely because they happen to be in the same aggregate file.
            collect_text(texts, {} if story else blocks)
            todo.extend(targets & set(scope))
            pending.extend(targets - set(scope))
        ordered = [label for label in blocks if label in reachable]
        if not ordered or ordered[0] != entry or dep.get('labels') != ordered:
            raise ValueError('incomplete_or_reordered_shared_closure')
        if not any(c.get('path') == dep['path'] and c.get('selector') == 'asm_labels'
                   and c.get('labels') == ordered for c in batch['sources']):
            raise ValueError('missing_shared_source_binding')
        sizes = [(label, prepared[label].size if prepared is not None else analyze(blocks[label])[0]) for label in ordered]
        shared[entry] = sizes
        contracts[(None, entry)] = (entry, sum(size for label, size in sizes))
    if visited != entries.keys():
        raise ValueError('unreachable_shared_dependency')
    if batch.get('dynamic_layouts', []) != sorted(used_layouts):
        raise ValueError('missing_or_unreachable_dynamic_layout_contract')
    layout_roles, layouts, layout_table = dynamic_layout_contracts(root, batch)
    if layout_roles:
        contracts[(None, 'gMapLayouts')] = ('gMapLayouts', 4 * len(layout_table))
        for row in layouts.values():
            name = row['name']
            for symbol, size in ((name, 24), (name + '_Border', 8),
                                 (name + '_Blockdata', _dynamic_blockdata_size(root, row))):
                if (None, symbol) in contracts:
                    raise ValueError('conflicting_dynamic_layout_contract')
                contracts[(None, symbol)] = (symbol, size)
    dependencies = batch.get('text_dependencies', [])
    if not isinstance(dependencies, list) or (dependencies and not extended):
        raise ValueError('unsupported_text_dependencies')
    text_entries = {}
    for dep in dependencies:
        if not isinstance(dep, dict) or not MAP_RE.fullmatch(str(dep.get('entry', ''))) or dep['entry'] in text_entries:
            raise ValueError('invalid_or_duplicate_text_dependency')
        text_entries[dep['entry']] = dep
    if addressed:
        external_text = _external_message_dependencies(external_text, local_labels, actual_kinds,
                                                       set(text_entries))
    if set(text_entries) != set(external_text):
        raise ValueError('incomplete_or_unreachable_text_dependencies')
    for entry, dep in text_entries.items():
        if dep.get('kind') != external_text[entry]:
            raise ValueError('incompatible_message_dependency:' + entry)
        if dep.get('end_before_includes') is not None:
            if not addressed:
                raise ValueError('unsupported_shared_include_review_version')
            if not set(dep['end_before_includes']) <= {
                    c.get('path') for c in batch['sources'] if c.get('selector') == 'file'}:
                raise ValueError('missing_shared_include_boundary_source')
        blocks = shared_script_blocks(root, dep)
        if entry not in blocks or not any(c.get('path') == dep['path'] and c.get('selector') == 'asm_labels'
                                          and c.get('labels') == [entry] for c in batch['sources']):
            raise ValueError('missing_text_source_binding')
        contracts[(None, entry)] = (entry, len(encoded_text(root, blocks[entry], dep.get('kind'))))
    standard = batch.get('standard_scripts', [])
    expected = ([dict(index=index, entry=entry) for index, entry in sorted(used_standard.items())]
                if story else [dict(index=3, entry='Std_MsgboxSign')] if 'Std_MsgboxSign' in visited else [])
    if standard != expected or (standard and not extended):
        raise ValueError('missing_or_unreachable_standard_script_evidence')
    if standard:
        blocks = label_blocks(local_path(root, 'data/event_scripts.s').read_text())
        if 'gStdScripts' not in blocks or not any(c.get('path') == 'data/event_scripts.s'
                and c.get('selector') == 'asm_labels' and c.get('labels') == ['gStdScripts'] for c in batch['sources']):
            raise ValueError('missing_standard_table_source_binding')
        entries = []
        for line in statements(blocks['gStdScripts']):
            match = re.fullmatch(r'\.4byte\s+([A-Za-z_]\w*)', line)
            if not match:
                raise ValueError('unsupported_standard_table_source')
            entries.append(match.group(1))
        if any(index >= len(entries) or entries[index] != entry
               for index, entry in ((v['index'], v['entry']) for v in standard)):
            raise ValueError('standard_script_index_mismatch')
        contracts[(None, 'gStdScripts')] = ('gStdScripts', 4 * len(entries))
    if story:
        expected_exits = [dict(entry=entry, destination=destination)
                          for entry, destination in sorted(context_exits.items())]
        if batch.get('context_exits', []) != expected_exits:
            raise ValueError('missing_or_changed_context_warp_contract')
        if (expected_exits and not (set(WARP_CONTEXT_SYMBOLS.values()) | {'ld_script_jp.txt'}) <= {
                c['path'] for c in batch['sources'] if c.get('selector') == 'file'}):
            raise ValueError('missing_context_warp_source')
        expected_callbacks = [dict(entry=entry, special=special)
                              for entry, special in sorted(callback_exits.items())]
        if batch.get('callback_exits', []) != expected_callbacks:
            raise ValueError('missing_or_changed_context_callback_contract')
        if (expected_callbacks and not (set(CALLBACK_CONTEXT_SYMBOLS.values()) | {'ld_script_jp.txt'}) <= {
                c['path'] for c in batch['sources'] if c.get('selector') == 'file'}):
            raise ValueError('missing_context_callback_source')
        expected_battles = [trainer_battles[key] for key in sorted(trainer_battles)]
        if batch.get('trainer_battles', []) != expected_battles:
            raise ValueError('missing_or_changed_trainer_battle_contract')
        for battle in expected_battles:
            if 'local_id' in battle:
                _trainer_local_id(root, battle, batch['sources'])
        if (bool(expected_battles), trainer_run, trainer_post) not in ((False, False, False), (True, True, True)):
            raise ValueError('incomplete_trainer_battle_handoff')
        if any('mode' in b for b in expected_battles) and not trainer_beaten:
            raise ValueError('missing_trainer_beaten_script_handoff')
        if expected_battles and not TRAINER_ENGINE_CONTEXT <= {c['path'] for c in batch['sources'] if c.get('selector') == 'file'}:
            raise ValueError('missing_trainer_engine_source')
        special_contracts = batch.get('special_contracts')
        if (not isinstance(special_contracts, list) or any(not isinstance(c, dict) for c in special_contracts)
                or len({c.get('entry') for c in special_contracts}) != len(special_contracts)
                or {c.get('entry'): c.get('waitstate') for c in special_contracts} != used_specials):
            raise ValueError('incomplete_or_changed_special_contracts')
        for contract in special_contracts:
            path = contract.get('source_path')
            if (not isinstance(path, str) or not path.startswith('src/') or not path.endswith('.c')
                    or not MAP_RE.fullmatch(str(contract.get('source_symbol', '')))
                    or not any(c.get('path') == path and c.get('selector') == 'file' for c in batch['sources'])):
                raise ValueError('missing_special_implementation_source')
            if contract.get('compile_variant') is not None:
                if batch['review_type'] != 'direct_map_v4' or not {'Makefile', 'tools/audit_structure.py'} <= {
                        c['path'] for c in batch['sources'] if c.get('selector') == 'file'}:
                    raise ValueError('missing_special_compile_variant_source')
                special_input_object(root, contract)
        for entry, dep in text_entries.items():
            actual_kinds[entry] = dep['kind']
        for target, expected_kind in expected_kinds.items():
            if actual_kinds.get(target) != expected_kind:
                raise ValueError('incompatible_or_missing_typed_target:' + target)
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
            try:
                relative = (root / relative).resolve().relative_to(root.resolve()).as_posix()
            except ValueError as exc:
                raise ValueError('external_compile_include:' + name) from exc
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


def native_elf(data: bytes, *, include_ram=False) -> tuple[dict[str, set[int]], list[tuple[int, bytes]]]:
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
            if not owner or not (0x08000000 <= value < 0x09000000
                                 or include_ram and 0x02000000 <= value < 0x04000000):
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


def _runtime_text_native(root: Path, profile, native: dict, errors: list):
    """A produced message buffer is a unique RAM symbol, never a ROM text span."""
    if not profile.runtime_texts:
        return
    if 'runtime_text_symbols' not in native:
        native['runtime_text_symbols'], _ = native_elf((root / 'pokeemerald_jp.elf').read_bytes(), include_ram=True)
    for symbol in profile.runtime_texts:
        values = native['runtime_text_symbols'].get(symbol, set())
        if len(values) != 1 or not all(0x02000000 <= value < 0x02040000 for value in values):
            errors.append('native_runtime_text_buffer_mismatch:' + symbol)
    if profile.runtime_texts != {'gStringVar4': 'CopyEReaderTrainerGreeting'}:
        return
    addresses = {}
    for symbol, owner in (('CopyEReaderTrainerGreeting', 'src/battle_tower.o'),
                          ('FrontierSpeechToString', 'src/battle_tower.o'),
                          ('ConvertEasyChatWordsToString', 'src/easy_chat.o')):
        values = {value & ~1 for value in native['symbols'].get(symbol, set())}
        if len(values) != 1:
            errors.append('native_runtime_text_producer_symbol_mismatch:' + symbol)
            continue
        address = addresses[symbol] = next(iter(values))
        if not any(start <= address < start + size and (actual == owner or actual.endswith('/' + owner))
                   for start, size, actual in native['owners']):
            errors.append('native_runtime_text_producer_owner_mismatch:' + symbol)
    if len(addresses) != 3:
        return
    def code(symbol, size):
        address = addresses[symbol]
        at = address - 0x08000000
        return address, native['rom'][at:at + size]
    def calls(address, data):
        targets = set()
        for offset in range(0, len(data) - 3, 2):
            high, low = struct.unpack_from('<HH', data, offset)
            if high & 0xF800 == 0xF000 and low & 0xF800 == 0xF800:
                delta = ((high & 0x7FF) << 12) | ((low & 0x7FF) << 1)
                if delta & 0x400000:
                    delta -= 0x800000
                targets.add(address + offset + 4 + delta)
        return targets
    address, greeting = code('CopyEReaderTrainerGreeting', 0x1C)
    if len(greeting) != 0x1C or addresses['FrontierSpeechToString'] not in calls(address, greeting):
        errors.append('native_runtime_text_greeting_call_mismatch')
    address, speech = code('FrontierSpeechToString', 0x70)
    buffers = native['runtime_text_symbols'].get('gStringVar4', set())
    if (len(speech) != 0x70 or addresses['ConvertEasyChatWordsToString'] not in calls(address, speech)
            or len(buffers) != 1 or struct.pack('<I', next(iter(buffers))) not in speech):
        errors.append('native_runtime_text_speech_buffer_mismatch')


def _literal_define(root: Path, path: str, name: str) -> int:
    values = re.findall(r'(?m)^\s*#define\s+' + re.escape(name)
                        + r'\s+(0x[0-9a-fA-F]+|[0-9]+)\s*(?://[^\n]*)?$', local_path(root, path).read_text())
    if len(values) != 1:
        raise ValueError('unsupported_trainer_engine_constant:' + name)
    return int(values[0], 16 if values[0].startswith('0x') else 10)


def _trainer_local_id(root: Path, battle: dict, sources: list) -> int:
    """Resolve an explicit nonzero ID through its generated define and JSON object."""
    label = battle.get('local_id')
    if label is None:
        return _literal_define(root, 'include/constants/event_objects.h', 'LOCALID_NONE')
    if not isinstance(label, str) or not re.fullmatch(r'LOCALID_\w+', label) or label == 'LOCALID_NONE':
        raise ValueError('invalid_explicit_trainer_local_id')
    paths = {claim['path'] for claim in sources if claim.get('selector') == 'file'}
    if 'include/constants/map_event_ids.h' not in paths:
        raise ValueError('missing_trainer_local_id_source')
    value = _literal_define(root, 'include/constants/map_event_ids.h', label)
    matches = []
    for path in sorted(paths):
        if not re.fullmatch(r'data/maps/[A-Za-z_]\w*/map\.json', path):
            continue
        data = json.loads(local_path(root, path).read_text())
        for index, event in enumerate(data.get('object_events', []), 1):
            if event.get('local_id') == label:
                matches.append((index, event.get('script')))
    if (not 1 <= value <= 255 or matches != [(value, battle['owner'])]):
        raise ValueError('trainer_local_id_object_mismatch:' + label)
    return value


def _context_warp_native(batch: dict, native: dict, errors: list[str]) -> None:
    """Bind the native callback/init chain, not an invented movement edge."""
    if not batch.get('context_exits'):
        return
    addresses = {}
    for symbol, path in WARP_CONTEXT_SYMBOLS.items():
        values = {value & ~1 for value in native['symbols'].get(symbol, set())}
        if len(values) != 1:
            errors.append('native_context_warp_symbol_mismatch:' + symbol)
            continue
        address = addresses[symbol] = next(iter(values))
        owner = path[:-2] + '.o'
        if not any(start <= address < start + size and (actual == owner or actual.endswith('/' + owner))
                   for start, size, actual in native['owners']):
            errors.append('native_context_warp_owner_mismatch:' + symbol)
    if len(addresses) != len(WARP_CONTEXT_SYMBOLS):
        return
    aliases = {value & ~1 for value in native['symbols'].get('ScriptContext1_Init', set())}
    # Do not require retaining the old JP spelling during future cleanup.
    if aliases and aliases != {addresses['ScriptContext_Init']}:
        errors.append('native_context_warp_init_alias_mismatch')
    start = addresses['CB2_LoadMap']
    if not 0x08000000 <= start <= 0x08000000 + len(native['rom']) - 16:
        errors.append('native_context_warp_loader_not_in_rom')
        return
    code = native['rom'][start - 0x08000000:start - 0x08000000 + 16]
    calls = set()
    for offset in range(0, len(code) - 3, 2):
        high, low = struct.unpack_from('<HH', code, offset)
        if high & 0xF800 == 0xF000 and low & 0xF800 == 0xF800:
            delta = ((high & 0x7FF) << 12) | ((low & 0x7FF) << 1)
            if delta & 0x400000:
                delta -= 0x800000
            calls.add(start + offset + 4 + delta)
    if addresses['ScriptContext_Init'] not in calls:
        errors.append('native_context_warp_missing_init_call')


def _context_callback_native(batch: dict, native: dict, errors: list[str]) -> None:
    """Verify the measured JP callback setter and its script-context reset."""
    if not batch.get('callback_exits'):
        return
    addresses = {}
    for symbol, path in CALLBACK_CONTEXT_SYMBOLS.items():
        values = {value & ~1 for value in native['symbols'].get(symbol, set())}
        if len(values) != 1:
            errors.append('native_context_callback_symbol_mismatch:' + symbol)
            continue
        address = addresses[symbol] = next(iter(values))
        owner = path[:-2] + '.o'
        if not any(start <= address < start + size and (actual == owner or actual.endswith('/' + owner))
                   for start, size, actual in native['owners']):
            errors.append('native_context_callback_owner_mismatch:' + symbol)
    if len(addresses) != len(CALLBACK_CONTEXT_SYMBOLS):
        return
    aliases = {value & ~1 for value in native['symbols'].get('ScriptContext1_Init', set())}
    if aliases and aliases != {addresses['ScriptContext_Init']}:
        errors.append('native_context_callback_init_alias_mismatch')
    def code(symbol, size):
        start = addresses[symbol]
        at = start - 0x08000000
        return start, native['rom'][at:at + size]
    def calls(start, data):
        targets = set()
        for offset in range(0, len(data) - 3, 2):
            high, low = struct.unpack_from('<HH', data, offset)
            if high & 0xF800 == 0xF000 and low & 0xF800 == 0xF800:
                delta = ((high & 0x7FF) << 12) | ((low & 0x7FF) << 1)
                if delta & 0x400000:
                    delta -= 0x800000
                targets.add(start + offset + 4 + delta)
        return targets
    # Measured function extents, not a search through arbitrary later code.
    start, setter = code('SetCB2WhiteOut', 0x14)
    if (len(setter) != 0x14 or addresses['SetMainCallback2'] not in calls(start, setter)
            or struct.pack('<I', addresses['CB2_WhiteOut'] | 1) not in setter):
        errors.append('native_context_callback_setter_mismatch')
    start, callback = code('CB2_WhiteOut', 0x74)
    if len(callback) != 0x74 or addresses['ScriptContext_Init'] not in calls(start, callback):
        errors.append('native_context_callback_missing_init_call')


def _trainer_native(root: Path, batch: dict, native: dict, errors: list[str], parsed: list) -> None:
    """Bind the supported mode's real JP parameter header and C interface."""
    if not batch.get('trainer_battles'):
        return
    handlers = re.findall(r'(?m)^\s*script_cmd_table_entry\s+\w+\s+(\w+)\s*(?:@[^\n]*)?$',
                          local_path(root, 'data/script_cmd_table.inc').read_text())
    if handlers.count('ScrCmd_trainerbattle') != 1:
        raise ValueError('missing_trainer_command_identity')
    opcode = handlers.index('ScrCmd_trainerbattle')
    try:
        from map_review_script_profile import TRAINER_FORMS
    except ModuleNotFoundError:
        from tools.map_review_script_profile import TRAINER_FORMS
    extended = any('mode' in b for b in batch['trainer_battles'])
    for symbol, path in (TRAINER_ENGINE_SYMBOLS | (TRAINER_EXTENDED_SYMBOLS if extended else {})).items():
        values = {v & ~1 for v in native['symbols'].get(symbol, set())}
        if len(values) != 1:
            errors.append('native_trainer_engine_symbol_mismatch:' + symbol)
            continue
        address = next(iter(values))
        expected_owner = path[:-2] + '.o'
        if (not any(base <= address < base + len(data) for base, data in native['memory'])
                or not any(start <= address < start + length and
                           (owner == expected_owner or owner.endswith('/' + expected_owner))
                           for start, length, owner in native['owners'])):
            errors.append('native_trainer_engine_owner_mismatch:' + symbol)
    for battle in batch['trainer_battles']:
        local_id = _trainer_local_id(root, battle, batch.get('sources', []))
        address, resume = _integer(battle['address']), _integer(battle['resume'])
        trainer = _literal_define(root, 'include/constants/opponents.h', battle['trainer'])
        mode_name = battle.get('mode', 'TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT')
        mode = _literal_define(root, 'include/constants/battle_setup.h', mode_name)
        fields = ['intro_text', 'defeat_text'] if 'mode' in battle else ['defeat_text']
        fields += [key for key in ('cannot_battle_text', 'post_script') if key in battle]
        values = [native['symbols'].get(battle[key], set()) for key in fields]
        size = 6 + 4 * len(fields)
        owner = native['symbols'].get(battle['owner'], set())
        if (any(len(v) != 1 for v in values) or len(owner) != 1
                or next(iter(owner)) > address or resume != address + size
                or not any(role in ('scripts', 'shared_script') and start <= address < resume < start + size
                           for name, role, symbol, start, size, digest in parsed)):
            errors.append('native_trainer_continuation_mismatch:' + battle['owner'])
            continue
        expected = struct.pack('<BBHH', opcode, mode, trainer, local_id)
        expected += b''.join(struct.pack('<I', next(iter(v))) for v in values)
        at = address - 0x08000000
        if native['rom'][at:at + size] != expected:
            errors.append('native_trainer_parameter_header_mismatch:' + battle['owner'])
    if extended:
        tables = {table for mode, _, table in TRAINER_FORMS.values()
                  if mode in {b.get('mode') for b in batch['trainer_battles']}}
        if any('mode' not in b for b in batch['trainer_battles']):
            tables.add('sOrdinaryNoIntroBattleParams')
        tables |= {'sTrainerBOrdinaryBattleParams', 'sTrainerBContinueScriptBattleParams'}
        _trainer_parameter_tables(root, native, tables, errors)


def _trainer_parameter_tables(root: Path, native: dict, tables: set[str], errors: list[str]) -> None:
    """Tie the C argument schema to actual ROM rows, RAM pointers and input owner."""
    source = local_path(root, 'src/battle_setup.c').read_text()
    types = ('TRAINER_PARAM_LOAD_VAL_8BIT', 'TRAINER_PARAM_LOAD_VAL_16BIT',
             'TRAINER_PARAM_LOAD_VAL_32BIT', 'TRAINER_PARAM_CLEAR_VAL_8BIT',
             'TRAINER_PARAM_CLEAR_VAL_16BIT', 'TRAINER_PARAM_CLEAR_VAL_32BIT',
             'TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR')
    enums = re.findall(r'enum\s*\{([^}]*TRAINER_PARAM_LOAD_SCRIPT_RET_ADDR[^}]*)\}', source, re.S)
    if len(enums) != 1 or re.findall(r'TRAINER_PARAM_\w+', enums[0]) != list(types):
        raise ValueError('unsupported_trainer_parameter_enum')
    if 'trainer_data_symbols' not in native:
        native['trainer_data_symbols'], _ = native_elf((root / 'pokeemerald_jp.elf').read_bytes(), include_ram=True)
    symbols = native['trainer_data_symbols']
    for table in sorted(tables):
        has_intro = table != 'sOrdinaryNoIntroBattleParams'
        double = 'Double' in table
        callback = 'ContinueScript' in table
        trainer_b = table.startswith('sTrainerB')
        rows = [('sTrainerBattleMode', 0), ('gTrainerBattleOpponent_A', 1),
                ('sTrainerObjectEventLocalId', 1), ('sTrainerAIntroSpeech', 2 if has_intro else 5),
                ('sTrainerADefeatSpeech', 2), ('sTrainerVictorySpeech', 5),
                ('sTrainerCannotBattleSpeech', 2 if double else 5),
                ('sTrainerABattleScriptRetAddr', 2 if callback else 5), ('sTrainerBattleEndScript', 6)]
        if trainer_b:
            rows = [(symbol.replace('Opponent_A', 'Opponent_B').replace('sTrainerA', 'sTrainerB'), kind)
                    for symbol, kind in rows]
        body = re.findall(r'\b' + re.escape(table) + r'\[\][^=;]*=\s*\{(.*?)\};', source, re.S)
        actual = re.findall(r'\{\s*&([A-Za-z_]\w*)\s*,\s*(TRAINER_PARAM_\w+)\s*\}', body[0]) if len(body) == 1 else []
        if actual != [(symbol, types[kind]) for symbol, kind in rows]:
            raise ValueError('unsupported_trainer_parameter_source:' + table)
        values = [symbols.get(symbol, set()) for symbol in [table] + [s for s, _ in rows]]
        if any(len(v) != 1 for v in values):
            errors.append('native_trainer_parameter_symbol_mismatch:' + table)
            continue
        address = next(iter(values[0]))
        expected = b''.join(struct.pack('<IB3x', next(iter(value)), kind)
                            for value, (_, kind) in zip(values[1:], rows))
        if not any(start <= address and address + len(expected) <= start + size
                   and (path == 'src/battle_setup.o' or path.endswith('/src/battle_setup.o'))
                   for start, size, path in native['owners']):
            errors.append('native_trainer_parameter_owner_mismatch:' + table)
        at = address - 0x08000000
        if native['rom'][at:at + len(expected)] != expected:
            errors.append('native_trainer_parameter_table_mismatch:' + table)


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
    if batch.get('review_type') not in ('direct_map_v1', 'direct_map_v2', 'direct_map_v3', 'direct_map_v4') or batch.get('decision') != 'reviewed':
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
    if batch['review_type'] in ('direct_map_v2', 'direct_map_v3', 'direct_map_v4'):
        required |= TEXT_CONTEXT
    if batch['review_type'] in ('direct_map_v3', 'direct_map_v4'):
        required |= STORY_CONTEXT
    if not required <= file_claims:
        raise ValueError('incomplete_map_or_generator_source_coverage')
    context = compile_context(root, required & (REQUIRED_CONTEXT | STORY_CONTEXT) | {
        f'data/maps/{n}/scripts.inc' for n in reviewed} | {
        c['path'] for c in sources if c.get('selector') == 'asm_labels'} | {
        c['source_path'] for c in batch.get('special_contracts', [])} | (
        TRAINER_ENGINE_CONTEXT if batch.get('trainer_battles') else set()))
    if not context <= file_claims:
        raise ValueError('incomplete_macro_constant_dependency_closure')
    if not {f'data/maps/{n}/map.json' for n in reviewed} <= us_files.keys():
        raise ValueError('incomplete_us_map_reference')
    for n in reviewed:
        layout = default_layout_owner(root, n, allow_shared=batch['review_type'] == 'direct_map_v4')
        layout_sources = {layout['border_filepath'], layout['blockdata_filepath']}
        if not layout_sources <= file_claims:
            raise ValueError('incomplete_layout_resource_coverage')
        expected_labels = {layout['name'] + suffix for suffix in ('_Border', '_Blockdata', '')}
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


def _shared_default_layout_native(root: Path, maps: list[str], native: dict, errors: list[str]) -> None:
    """Check shared defaults through the real header, layout and indexed table."""
    for name in maps:
        row = default_layout_owner(root, name, allow_shared=True)
        if row['name'] == name + '_Layout':
            continue
        wanted = [name, row['name'], row['name'] + '_Border', row['name'] + '_Blockdata',
                  row['primary_tileset'], row['secondary_tileset'], 'gMapLayouts']
        values = [native['symbols'].get(symbol, set()) for symbol in wanted]
        if any(len(value) != 1 for value in values):
            errors.append('native_shared_default_layout_symbol_mismatch:' + name)
            continue
        header, layout, border, blockdata, primary, secondary, table = [next(iter(value)) for value in values]
        index = _literal_define(root, 'include/constants/layouts.h', row['id'])
        at = header - 0x08000000
        if (native['rom'][at:at + 4] != struct.pack('<I', layout)
                or native['rom'][at + 18:at + 20] != struct.pack('<H', index)):
            errors.append('native_shared_default_layout_header_mismatch:' + name)
        at = layout - 0x08000000
        expected = struct.pack('<6I', row['width'], row['height'], border, blockdata, primary, secondary)
        if native['rom'][at:at + 24] != expected:
            errors.append('native_shared_default_layout_structure_mismatch:' + name)
        at = table - 0x08000000 + 4 * (index - 1)
        if native['rom'][at:at + 4] != struct.pack('<I', layout):
            errors.append('native_shared_default_layout_table_mismatch:' + name)


def _dynamic_layout_native(root: Path, batch: dict, native: dict, errors: list[str]) -> None:
    roles, layouts, _ = dynamic_layout_contracts(root, batch)
    if not roles:
        return
    def address(symbol):
        values = native['symbols'].get(symbol, set())
        if len(values) != 1:
            errors.append('native_dynamic_layout_symbol_mismatch:' + symbol)
            return None
        return next(iter(values))
    table = address('gMapLayouts')
    for layout_id, row in layouts.items():
        name = row['name']
        expected_symbols = [name, name + '_Border', name + '_Blockdata',
                            row['primary_tileset'], row['secondary_tileset']]
        values = [address(symbol) for symbol in expected_symbols]
        if table is None or any(value is None for value in values):
            continue
        index = _literal_define(root, 'include/constants/layouts.h', layout_id)
        slot = table - 0x08000000 + 4 * (index - 1)
        if int.from_bytes(native['rom'][slot:slot + 4], 'little') != values[0]:
            errors.append('native_dynamic_layout_table_target_mismatch:' + layout_id)
        start = values[0] - 0x08000000
        expected = [row['width'], row['height']] + values[1:]
        if native['rom'][start:start + 24] != struct.pack('<6I', *expected):
            errors.append('native_dynamic_layout_structure_mismatch:' + layout_id)
    for symbol, source in (('ScrCmd_setmaplayoutindex', 'src/scrcmd.o'),
                           ('SetCurrentMapLayout', 'src/overworld.o'), ('GetMapLayout', 'src/overworld.o')):
        value = address(symbol)
        if value is None:
            continue
        value &= ~1
        if not any(start <= value < start + length and (path == source or path.endswith('/' + source))
                   for start, length, path in native['owners']):
            errors.append('native_dynamic_layout_engine_owner_mismatch:' + symbol)


def _native_batch(root: Path, batch: dict, maps: list[str], errors: list[str], native: dict,
                  latest_source_ns: int) -> dict:
    contracts, shared = component_contracts(root, batch, maps)
    layout_roles, layouts, layout_table = dynamic_layout_contracts(root, batch)
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
        if not isinstance(symbol, str) or not MAP_RE.fullmatch(symbol):
            raise ValueError('invalid_native_symbol')
        if (name not in roles and not (name is None and role in (
                'shared_script', 'shared_text', 'standard_script_table',
                'dynamic_layout_table', 'dynamic_layout', 'dynamic_border', 'dynamic_blockdata'))):
            raise ValueError('unattributed_native_span')
        if name is None:
            expected_role = (layout_roles[symbol] if symbol in layout_roles
                             else 'standard_script_table' if symbol == 'gStdScripts' and batch.get('standard_scripts')
                             else 'shared_text' if any(d['entry'] == symbol for d in batch.get('text_dependencies', []))
                             else 'shared_script' if any(d['entry'] == symbol for d in batch.get('shared_dependencies', [])) else None)
            if role != expected_role:
                raise ValueError('shared_native_role_mismatch')
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
    expected_roles = {name: {role for owner, role in contracts if owner == name} for name in maps}
    if any(value != expected_roles[name] for name, value in roles.items()):
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
            expected_owner = ('data/event_scripts.o' if role in ('scripts', 'shared_script', 'shared_text', 'standard_script_table')
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
        for dep in batch.get('shared_dependencies', []) + batch.get('text_dependencies', []):
            following = shared_include_entry(root, dep)
            if following is not None:
                last = dep.get('labels', [dep['entry']])[-1]
                sizes = (dict(shared[dep['entry']]) if dep['entry'] in shared
                         else {dep['entry']: contracts[(None, dep['entry'])][1]})
                addresses = native['symbols'].get(last, set())
                expected = {a + sizes[last] for a in addresses}
                linker = native['map_symbols'].get(following)
                linker_mismatch = (linker != expected if dep.get('kind') not in ('string', 'braille')
                                   else linker is not None and linker != expected)
                if (len(expected) != 1 or native['symbols'].get(following) != expected
                        or linker_mismatch):
                    errors.append('native_shared_include_boundary_mismatch:' + last)
        if batch['review_type'] == 'direct_map_v4':
            _shared_default_layout_native(root, maps, native, errors)
            try:
                from map_review_script_profile import profile_owner
            except ModuleNotFoundError:
                from tools.map_review_script_profile import profile_owner
            for name in maps:
                address = next(a for n, role, symbol, a, size, digest in parsed if n == name and role == 'scripts')
                profiles = profile_owner(root, local_path(root, f'data/maps/{name}/scripts.inc').read_text(),
                                         version=4, address=address)
                for label, profile in profiles.items():
                    if native['symbols'].get(label) != {address}:
                        errors.append('native_addressed_label_mismatch:' + label)
                    if profile.fallthrough and native['symbols'].get(profile.fallthrough) != {address + profile.size}:
                        errors.append('native_script_fallthrough_mismatch:' + label)
                    _runtime_text_native(root, profile, native, errors)
                    address += profile.size
            for dep in batch.get('shared_dependencies', []):
                block = shared_script_blocks(root, dep)
                address = next(a for n, role, symbol, a, size, digest in parsed
                               if n is None and symbol == dep['entry'])
                profiles = profile_owner(root, '\n'.join(block[label] for label in dep['labels']),
                                         version=4, address=address)
                for label, profile in profiles.items():
                    if profile.fallthrough and native['symbols'].get(profile.fallthrough) != {address + profile.size}:
                        errors.append('native_script_fallthrough_mismatch:' + label)
                    _runtime_text_native(root, profile, native, errors)
                    address += profile.size
            _trainer_native(root, batch, native, errors, parsed)
            _context_warp_native(batch, native, errors)
            _context_callback_native(batch, native, errors)
            _dynamic_layout_native(root, batch, native, errors)
        for entry, pieces in shared.items():
            address = next(a for n, role, symbol, a, size, digest in parsed if n is None and symbol == entry)
            for label, size in pieces:
                if native['symbols'].get(label) != {address}:
                    errors.append('shared_closure_not_contiguous:' + label)
                address += size
        if batch['review_type'] in ('direct_map_v2', 'direct_map_v3', 'direct_map_v4'):
            for contract in batch.get('special_contracts', []):
                entry, source = contract['entry'], contract['source_symbol']
                values = {v & ~1 for v in native['symbols'].get(entry, set())}
                if len(values) != 1 or values != {v & ~1 for v in native['symbols'].get(source, set())}:
                    errors.append('native_special_implementation_mismatch:' + entry)
                    continue
                address = next(iter(values))
                expected_owner = special_input_object(root, contract)
                owners = [path for start, length, path in native['owners'] if start <= address < start + length
                          and (path == expected_owner or path.endswith('/' + expected_owner))]
                if not owners:
                    errors.append('native_special_input_owner_mismatch:' + entry)
                if contract.get('compile_variant') is not None:
                    try:
                        try:
                            from audit_structure import elf_object_functions, linker_code_inputs
                        except ModuleNotFoundError:
                            from tools.audit_structure import elf_object_functions, linker_code_inputs
                        if len(set(owners)) != 1:
                            raise ValueError('ambiguous_special_variant_object')
                        paths = [p for p in (owners[0], 'build/pokeemerald-jp/' + owners[0])
                                 if (root / p).is_file()]
                        if len(paths) != 1:
                            raise ValueError('missing_or_ambiguous_special_variant_artifact')
                        obj = local_path(root, paths[0])
                        if obj.stat().st_mtime_ns > (root / 'pokeemerald_jp.elf').stat().st_mtime_ns:
                            raise ValueError('special_variant_object_newer_than_elf')
                        functions = elf_object_functions(obj.read_bytes())
                        selected = [f for f in functions if f[0] == source and f[3] > 0]
                        if len(selected) != 1:
                            raise ValueError('missing_special_variant_object_function')
                        if 'code_inputs' not in native:
                            native['code_inputs'] = linker_code_inputs((root / 'pokeemerald_jp.map').read_text())
                        _, section, offset, size, section_size = selected[0]
                        tied = [(start, end) for start, end, _, sec, path in native['code_inputs']
                                if sec == section and (path == expected_owner or path.endswith('/' + expected_owner))
                                and end - start == section_size and start + offset == address
                                and address + size <= end]
                        if len(tied) != 1:
                            raise ValueError('special_variant_object_offset_mismatch')
                    except (OSError, ValueError):
                        errors.append('native_special_variant_object_mismatch:' + entry)
            for standard in batch.get('standard_scripts', []):
                table = next(a for n, role, symbol, a, size, digest in parsed if role == 'standard_script_table')
                slot = table - 0x08000000 + 4 * standard['index']
                if native['symbols'].get(standard['entry']) != {int.from_bytes(native['rom'][slot:slot + 4], 'little')}:
                    errors.append('native_standard_script_target_mismatch:' + standard['entry'])
            for name in maps:
                metadata = json.loads(local_path(root, f'data/maps/{name}/map.json').read_text())
                if (name, 'connections') not in contracts or metadata.get('has_unused_connection_table'):
                    address = next(a for n, role, symbol, a, size, digest in parsed if n == name and role == 'header') - 0x08000000
                    if native['rom'][address + 12:address + 16] != bytes(4):
                        errors.append('native_null_connection_pointer_mismatch:' + name)
            text_sources = [(dict(path=f'data/maps/{name}/scripts.inc'), None) for name in maps]
            text_sources += [(dep, dep['entry']) for dep in batch.get('text_dependencies', [])]
            for dep, selected in text_sources:
                for label, block in shared_script_blocks(root, dep).items():
                    if selected is not None and selected != label:
                        continue
                    kind = text_kind(block)
                    if not kind:
                        continue
                    values = native['symbols'].get(label, set())
                    if len(values) != 1:
                        errors.append('native_text_symbol_mismatch:' + label)
                        continue
                    address = next(iter(values)) - 0x08000000
                    encoded = encoded_text(root, block, kind)
                    if native['rom'][address:address + len(encoded)] != encoded:
                        errors.append('native_text_encoding_mismatch:' + label)
    for name in maps:
        for start, part in (('data/event_scripts.s', 'scripts.inc'),
                            ('data/map_events.s', 'events.inc'),
                            ('data/maps.s', 'header.inc'), ('data/maps.s', 'connections.inc')):
            if f'data/maps/{name}/{part}' not in _reachable(root, start, native.setdefault('include_graph', {})):
                errors.append('unreachable_map_component:' + name + '/' + part)
    for dep in batch.get('shared_dependencies', []) + batch.get('text_dependencies', []):
        if dep['path'] not in _reachable(root, 'data/event_scripts.s', native.setdefault('include_graph', {})):
            errors.append('unreachable_shared_owner:' + dep['path'])
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
              'current_maps_by_review_type': {}, 'batches': [], 'errors': []}
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
        names, ids, native, current_types = set(), set(), {}, {}
        for batch in batches:
            if not isinstance(batch, dict):
                raise ValueError('invalid_review_batch')
            record = _review_batch(root, batch, known_maps, native)
            if record['id'] in ids or names & set(record['maps']):
                raise ValueError('duplicate_batch_or_map_review')
            ids.add(record['id']); names.update(record['maps'])
            result['batches'].append(record)
            if record['status'] == 'current':
                kind = batch['review_type']
                current_types[kind] = current_types.get(kind, 0) + len(record['maps'])
        current = sorted(name for b in result['batches'] if b['status'] == 'current' for name in b['maps'])
        result.update(status='recorded', reviewed_map_names=current, reviewed_maps=len(current),
                      current_maps_by_review_type=dict(sorted(current_types.items())))
    except (OSError, UnicodeError, ValueError, TypeError, KeyError) as exc:
        result.update(status='invalid_manifest', reviewed_map_names=[], reviewed_maps=0, current_maps_by_review_type={},
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
