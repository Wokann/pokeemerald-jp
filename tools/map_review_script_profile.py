"""Fail-closed typed script/movement analysis for reviewed story-map forms.

This does not approve a map. It measures explicitly supported source forms
and distinguishes scripts, map tables, movements and encoded JP text. Review
records, real macro expansion tests and native byte checks remain mandatory.
"""
from dataclasses import dataclass, field
from pathlib import Path
import re
try:
    from map_semantic_review import encoded_text, label_blocks, statements, text_kind
except ModuleNotFoundError:
    from tools.map_semantic_review import encoded_text, label_blocks, statements, text_kind

NAME = re.compile(r'[A-Za-z_]\w*\Z')
ATOM = re.compile(r'(?:[A-Za-z_]\w*|0x[0-9A-Fa-f]+|-?\d+)\Z')
MAP_TYPES = {name: ('condition_table' if name in ('MAP_SCRIPT_ON_FRAME_TABLE',
    'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE') else 'script') for name in (
    'MAP_SCRIPT_ON_LOAD', 'MAP_SCRIPT_ON_FRAME_TABLE', 'MAP_SCRIPT_ON_TRANSITION',
    'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE', 'MAP_SCRIPT_ON_RESUME', 'MAP_SCRIPT_ON_DIVE_WARP',
    'MAP_SCRIPT_ON_RETURN_TO_FIELD')}
MOVEMENTS = frozenset(('walk_up', 'walk_down', 'walk_left', 'walk_right',
    'walk_in_place_faster_up', 'walk_in_place_faster_down', 'walk_in_place_faster_left',
    'walk_in_place_faster_right', 'face_original_direction', 'face_player', 'set_invisible',
    'delay_8', 'delay_16', 'step_end', 'emote_exclamation_mark', 'emote_question_mark'))
STANDARD = {'MSGBOX_NPC': (2, 'Std_MsgboxNPC'), 'MSGBOX_SIGN': (3, 'Std_MsgboxSign'),
            'MSGBOX_DEFAULT': (4, 'Std_MsgboxDefault')}
FIXED = {'lock': (1, 0), 'lockall': (1, 0), 'release': (1, 0), 'releaseall': (1, 0),
    'end': (1, 0), 'return': (1, 0), 'faceplayer': (1, 0), 'closemessage': (1, 0),
    'waitmessage': (1, 0), 'waitbuttonpress': (1, 0), 'waitstate': (1, 0),
    'fadedefaultbgm': (1, 0), 'waitdooranim': (1, 0), 'setflag': (3, 1), 'clearflag': (3, 1),
    'setvar': (5, 2), 'delay': (3, 1), 'savebgm': (3, 1), 'playbgm': (4, 2),
    'playse': (3, 1), 'opendoor': (5, 2), 'closedoor': (5, 2), 'hideobjectat': (5, 2),
    'setobjectxy': (7, 3), 'setobjectxyperm': (7, 3), 'warp': (8, 3),
    'waitse': (1, 0), 'waitfanfare': (1, 0), 'copyvar': (5, 2),
    'checkitemspace': (5, 2), 'checkitemtype': (3, 1), 'bufferitemname': (4, 2),
    'bufferstdstring': (4, 2), 'playfanfare': (3, 1), 'switch': (5, 1)}


@dataclass
class BlockProfile:
    size: int = 0
    kind: str = 'script'
    targets: dict[str, str] = field(default_factory=dict)
    texts: dict[str, str] = field(default_factory=dict)
    specials: dict[str, int] = field(default_factory=dict)
    standard_scripts: dict[int, str] = field(default_factory=dict)


def special_waits(root: Path) -> dict[str, int]:
    result = {}
    for raw in (root / 'data/specials.inc').read_text().splitlines():
        line = raw.split('@', 1)[0].strip()
        if not re.match(r'def_special(?:\s|$)', line):
            continue
        match = re.fullmatch(r'def_special\s+([A-Za-z_]\w*)(?:,\s*waitstate=([01]))?', line)
        if not match:
            raise ValueError('invalid_special_profile:' + line)
        wait = int(match[2] or 0)
        if match[1] in result and result[match[1]] != wait:
            raise ValueError('conflicting_special_wait_profile:' + line)
        # The real table can repeat the same handler at different indices;
        # its single SPECIAL_WAITSTATE_<handler> contract must stay consistent.
        result[match[1]] = wait
    if not result:
        raise ValueError('missing_special_profile')
    return result


def profile_block(root: Path, block: str, waits=None) -> BlockProfile:
    kind = text_kind(block)
    if kind:
        return BlockProfile(size=len(encoded_text(root, block, kind)), kind=kind)
    lines = statements(block)
    if not lines:
        raise ValueError('empty_profile_block')
    if any(';' in line for line in lines):
        raise ValueError('unmodeled_statement_separator')
    operations = [line.split(None, 1)[0] for line in lines]
    if any(op in MOVEMENTS for op in operations):
        if (any(op not in MOVEMENTS for op in operations) or operations[-1] != 'step_end'
                or operations.count('step_end') != 1):
            raise ValueError('mixed_or_unterminated_movement')
        if any(len(line.split()) != 1 for line in lines):
            raise ValueError('unsupported_movement_arguments')
        return BlockProfile(size=len(lines), kind='movement')
    result = BlockProfile()
    if lines == ['.byte 0']:
        return BlockProfile(size=1, kind='map_table')
    table_ops = set(operations) & {'map_script', 'map_script_2'}
    if table_ops:
        if len(table_ops) != 1:
            raise ValueError('mixed_map_table_formats')
        table_op = next(iter(table_ops))
        terminator = '.byte' if table_op == 'map_script' else '.2byte'
        if (set(operations) != {table_op, terminator} or operations[-1] != terminator
                or operations.count(terminator) != 1):
            raise ValueError('invalid_map_table_terminator')
        result.kind = 'map_table' if table_op == 'map_script' else 'condition_table'
    def target(value, expected):
        if not NAME.fullmatch(value):
            raise ValueError('nonsemantic_profile_target:' + value)
        if value in result.targets and result.targets[value] != expected:
            raise ValueError('incompatible_profile_target:' + value)
        result.targets[value] = expected
    for line in lines:
        parts = line.split(None, 1)
        op = parts[0]
        args = [v.strip() for v in parts[1].split(',')] if len(parts) == 2 else []
        if any(not ATOM.fullmatch(arg) for arg in args):
            raise ValueError('unsupported_profile_argument_expression:' + op)
        if op in FIXED:
            size, count = FIXED[op]
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if op == 'warp' and not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_warp')
        elif op in ('call', 'goto', 'call_if_eq', 'goto_if_eq', 'case'):
            count = 2 if op == 'case' else 3 if '_if_' in op else 1
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if count == 3 and not re.fullmatch(r'VAR_\w+', args[0]):
                raise ValueError('unsupported_profile_compare')
            size = 11 if count in (2, 3) else 5
            target(args[-1], 'script')
        elif op in ('applymovement', 'applywaitmovement'):
            if len(args) not in (2, 3) or (len(args) == 3 and not re.fullmatch(r'MAP_\w+', args[2])):
                raise ValueError('unsupported_profile_movement')
            size = (7 if len(args) == 2 else 9) + (3 if op == 'applywaitmovement' else 0)
            target(args[1], 'movement')
        elif op in ('waitmovement', 'addobject', 'removeobject'):
            allowed = (0, 1, 2) if op == 'waitmovement' else (1, 2)
            if len(args) not in allowed or (len(args) == 2 and not re.fullmatch(r'MAP_\w+', args[1])):
                raise ValueError('unsupported_profile_object')
            size = 5 if len(args) == 2 else 3
        elif op in ('special', 'specialvar', 'pyramid_getlocation'):
            if len(args) != {'special': 1, 'specialvar': 2, 'pyramid_getlocation': 0}[op]:
                raise ValueError('unsupported_profile_special')
            function = 'CallBattlePyramidFunction' if op == 'pyramid_getlocation' else args[-1]
            if not NAME.fullmatch(function):
                raise ValueError('unsupported_profile_special')
            waits = special_waits(root) if waits is None else waits
            if function not in waits:
                raise ValueError('unknown_profile_special:' + function)
            if waits[function] not in (0, 1):
                raise ValueError('invalid_profile_special_wait:' + function)
            result.specials[function] = waits[function]
            size = {'special': 3, 'specialvar': 5, 'pyramid_getlocation': 8}[op] + waits[function]
        elif op == 'finditem':
            if len(args) not in (1, 2) or not re.fullmatch(r'ITEM_\w+', args[0]):
                raise ValueError('unsupported_profile_finditem')
            target('Std_FindItem', 'script')
            result.standard_scripts[1] = 'Std_FindItem'
            size = 12
        elif op == 'additem':
            if len(args) not in (1, 2):
                raise ValueError('unsupported_profile_additem')
            size = 5
        elif op == 'msgbox':
            if len(args) != 2 or args[1] not in STANDARD or not NAME.fullmatch(args[0]):
                raise ValueError('unsupported_profile_message')
            index, entry = STANDARD[args[1]]
            target(entry, 'script')
            result.texts[args[0]] = 'string'
            result.standard_scripts[index] = entry
            size = 8
        elif op == 'message':
            if len(args) != 1 or not NAME.fullmatch(args[0]):
                raise ValueError('unsupported_profile_buffered_message')
            if args != ['NULL']:
                result.texts[args[0]] = 'string'
            size = 5
        elif op in ('map_script', 'map_script_2'):
            if len(args) != (2 if op == 'map_script' else 3):
                raise ValueError('unsupported_profile_map_table')
            if op == 'map_script' and args[0] not in MAP_TYPES:
                raise ValueError('unsupported_profile_map_table_type')
            target(args[-1], MAP_TYPES[args[0]] if op == 'map_script' else 'script')
            size = 5 if op == 'map_script' else 8
        elif op in ('.byte', '.2byte') and args == ['0'] and result.kind in ('map_table', 'condition_table'):
            size = 1 if op == '.byte' else 2
        else:
            raise ValueError('unsupported_story_review_statement:' + op)
        result.size += size
    return result


def profile_owner(root: Path, text: str, waits=None) -> dict[str, BlockProfile]:
    waits = special_waits(root) if waits is None else waits
    blocks = label_blocks(text)
    if not blocks:
        raise ValueError('missing_profile_labels')
    first = re.search(r'(?m)^' + re.escape(next(iter(blocks))) + r'::?', text)
    if statements(text[:first.start()]):
        raise ValueError('unmodeled_owner_prefix')
    result = {name: profile_block(root, block, waits) for name, block in blocks.items()}
    expected_kinds = {}
    for profile in result.values():
        for name, expected in list(profile.targets.items()) + list(profile.texts.items()):
            if name in expected_kinds and expected_kinds[name] != expected:
                raise ValueError('incompatible_reference_kinds:' + name)
            expected_kinds[name] = expected
            if name in result and result[name].kind != expected:
                raise ValueError('incompatible_internal_target:' + name)
    return result
