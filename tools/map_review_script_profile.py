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
STANDARD_V4 = STANDARD | {'MSGBOX_YESNO': (5, 'Std_MsgboxYesNo')}
MOVEMENTS_V4 = MOVEMENTS | {'lock_facing_direction', 'unlock_facing_direction',
                           'face_up', 'face_down', 'face_left', 'face_right', 'delay_4', 'reveal_trainer',
                           'walk_in_place_down', 'walk_faster_right', 'walk_fast_right', 'walk_fast_up',
                           'set_visible', 'walk_faster_up', 'walk_in_place_slow_left',
                           'walk_in_place_slow_right', 'walk_slow_left', 'walk_slow_diag_northeast',
                           'walk_slow_diag_southwest', 'walk_left_affine', 'init_affine_anim',
                           'clear_affine_anim', 'levitate', 'destroy_extra_task',
                           'walk_fast_left', 'jump_right', 'jump_in_place_right',
                           'disable_jump_landing_ground_effect', 'walk_faster_left', 'walk_fast_down'}
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
FIXED_V4 = FIXED | {'setobjectmovementtype': (4, 2), 'getplayerxy': (5, 2),
                   'bufferleadmonspeciesname': (2, 1), 'addvar': (5, 2), 'yesnobox': (3, 2),
                   'copyobjectxytoperm': (3, 1), 'checkplayergender': (1, 0),
                   'playmoncry': (5, 2), 'waitmoncry': (1, 0),
                   'setmetatile': (9, 4), 'dotimebasedevents': (1, 0), 'random': (3, 1),
                   'setfieldeffectargument': (4, 2), 'dofieldeffect': (3, 1), 'waitfieldeffect': (3, 1),
                   'setweather': (3, 1), 'doweather': (1, 0), 'fadenewbgm': (3, 1),
                   'fadescreenspeed': (3, 2), 'turnobject': (4, 2), 'hideplayer': (5, 0),
                   'multichoice': (5, 4), 'multichoicedefault': (6, 5),
                   'setobjectsubpriority': (6, 3), 'resetobjectsubpriority': (5, 2),
                   'showobjectat': (5, 2), 'incrementgamestat': (2, 1),
                   'getpartysize': (1, 0), 'giveegg': (3, 1), 'fadescreen': (2, 1)}


@dataclass
class BlockProfile:
    size: int = 0
    kind: str = 'script'
    targets: dict[str, str] = field(default_factory=dict)
    texts: dict[str, str] = field(default_factory=dict)
    specials: dict[str, int] = field(default_factory=dict)
    standard_scripts: dict[int, str] = field(default_factory=dict)
    layouts: set[str] = field(default_factory=set)
    trainer_battles: list[dict] = field(default_factory=list)
    trainer_run: bool = False
    trainer_post_return: bool = False


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


def profile_block(root: Path, block: str, waits=None, *, version=3, address=None) -> BlockProfile:
    if version not in (3, 4):
        raise ValueError('unsupported_story_profile_version')
    if version == 4 and (type(address) is not int or not 0x08000000 <= address < 0x09000000):
        raise ValueError('missing_or_invalid_story_native_address')
    kind = text_kind(block)
    if kind:
        return BlockProfile(size=len(encoded_text(root, block, kind)), kind=kind)
    lines = statements(block)
    if not lines:
        raise ValueError('empty_profile_block')
    if any(';' in line for line in lines):
        raise ValueError('unmodeled_statement_separator')
    operations = [line.split(None, 1)[0] for line in lines]
    movements = MOVEMENTS_V4 if version == 4 else MOVEMENTS
    fixed = FIXED_V4 if version == 4 else FIXED
    standard = STANDARD_V4 if version == 4 else STANDARD
    if version == 4 and 'pokemartlistend' in operations:
        if (operations[-1] != 'pokemartlistend' or operations.count('pokemartlistend') != 1
                or len(lines) < 2 or address % 4 or lines[-1] != 'pokemartlistend'):
            raise ValueError('invalid_shop_table_termination_or_alignment')
        entries = [re.fullmatch(r'\.2byte\s+((ITEM|DECOR)_\w+)', line) for line in lines[:-1]]
        if (not all(entries) or len({e[2] for e in entries}) != 1
                or any(e[1] in ('ITEM_NONE', 'DECOR_NONE') for e in entries)):
            raise ValueError('mixed_or_unmodeled_shop_table')
        return BlockProfile(size=2 * len(entries) + 4,
                            kind='mart_items' if entries[0][2] == 'ITEM' else 'mart_decorations')
    if any(op in movements for op in operations):
        if (any(op not in movements for op in operations) or operations[-1] != 'step_end'
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
    for position, line in enumerate(lines):
        parts = line.split(None, 1)
        op = parts[0]
        args = [v.strip() for v in parts[1].split(',')] if len(parts) == 2 else []
        if any(not ATOM.fullmatch(arg) for arg in args):
            raise ValueError('unsupported_profile_argument_expression:' + op)
        if op in fixed:
            size, count = fixed[op]
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if op == 'warp' and not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_warp')
        elif (op in ('call', 'goto', 'call_if_eq', 'goto_if_eq', 'case')
              or version == 4 and op in ('goto_if_ge', 'goto_if_le', 'goto_if_ne', 'call_if_ne')):
            count = 2 if op == 'case' else 3 if '_if_' in op else 1
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if count == 3 and not re.fullmatch(r'VAR_\w+', args[0]):
                raise ValueError('unsupported_profile_compare')
            size = 11 if count in (2, 3) else 5
            target(args[-1], 'script')
        elif version == 4 and op in ('goto_if_set', 'goto_if_unset', 'call_if_set', 'call_if_unset'):
            if len(args) != 2 or not re.fullmatch(r'FLAG_\w+', args[0]):
                raise ValueError('unsupported_profile_flag_branch')
            target(args[-1], 'script')
            size = 9
        elif version == 4 and op == 'trainerbattle_no_intro':
            if (len(args) != 2 or not re.fullmatch(r'TRAINER_\w+', args[0])
                    or not NAME.fullmatch(args[1]) or args[1] == 'NULL'):
                raise ValueError('unsupported_no_intro_trainer_battle')
            if position == len(lines) - 1:
                raise ValueError('missing_inline_trainer_battle_continuation')
            owner = re.search(r'(?m)^([A-Za-z_]\w*)::?', block)
            if owner is None:
                raise ValueError('missing_trainer_battle_owner')
            target('EventScript_DoNoIntroTrainerBattle', 'script')
            result.texts[args[1]] = 'string'
            result.trainer_battles.append(dict(owner=owner[1], trainer=args[0], defeat_text=args[1],
                address=f'0x{address + result.size:08X}', resume=f'0x{address + result.size + 10:08X}'))
            size = 10
        elif version == 4 and op in ('dotrainerbattle', 'gotopostbattlescript'):
            if args:
                raise ValueError('unsupported_trainer_battle_primitive')
            result.trainer_run |= op == 'dotrainerbattle'
            result.trainer_post_return |= op == 'gotopostbattlescript'
            size = 1
        elif version == 4 and op == 'pokenavcall':
            if len(args) != 1 or not NAME.fullmatch(args[0]) or args[0] == 'NULL':
                raise ValueError('unsupported_pokenav_call')
            result.texts[args[0]] = 'string'
            size = 5
        elif version == 4 and op == 'checkitem':
            if len(args) not in (1, 2) or not re.fullmatch(r'(?:ITEM|VAR)_\w+', args[0]):
                raise ValueError('unsupported_profile_checkitem')
            size = 5
        elif version == 4 and op == 'setstepcallback':
            if len(args) != 1 or not re.fullmatch(r'STEP_CB_\w+', args[0]):
                raise ValueError('unsupported_profile_step_callback')
            size = 2
        elif version == 4 and op in ('setdivewarp', 'warpsilent', 'warpwhitefade'):
            if len(args) != 3 or not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_coordinate_warp')
            size = 8
        elif version == 4 and op == 'setmaplayoutindex':
            if len(args) != 1 or not re.fullmatch(r'LAYOUT_\w+', args[0]):
                raise ValueError('unsupported_profile_dynamic_layout')
            result.layouts.add(args[0])
            size = 3
        elif version == 4 and op in ('pokemart', 'pokemartdecoration'):
            if len(args) != 1:
                raise ValueError('unsupported_profile_shop')
            target(args[0], 'mart_items' if op == 'pokemart' else 'mart_decorations')
            size = 5
        elif version == 4 and op == '.align':
            if (args != ['2'] or table_ops or position != len(lines) - 1
                    or len(lines) < 2 or lines[-2] not in ('end', 'return')):
                raise ValueError('unsupported_profile_alignment')
            size = -(address + result.size) % 4
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
        elif op == 'finditem' or version == 4 and op == 'giveitem':
            if (len(args) not in (1, 2) or not re.fullmatch(
                    r'ITEM_\w+' if op == 'finditem' else r'(?:ITEM|VAR)_\w+', args[0])):
                raise ValueError('unsupported_profile_finditem')
            index, entry = (1, 'Std_FindItem') if op == 'finditem' else (0, 'Std_ObtainItem')
            target(entry, 'script')
            result.standard_scripts[index] = entry
            size = 12
        elif op == 'additem':
            if len(args) not in (1, 2):
                raise ValueError('unsupported_profile_additem')
            size = 5
        elif op == 'msgbox':
            if len(args) != 2 or args[1] not in standard or not NAME.fullmatch(args[0]):
                raise ValueError('unsupported_profile_message')
            index, entry = standard[args[1]]
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


def profile_owner(root: Path, text: str, waits=None, *, version=3, address=None) -> dict[str, BlockProfile]:
    waits = special_waits(root) if waits is None else waits
    blocks = label_blocks(text)
    if not blocks:
        raise ValueError('missing_profile_labels')
    first = re.search(r'(?m)^' + re.escape(next(iter(blocks))) + r'::?', text)
    if statements(text[:first.start()]):
        raise ValueError('unmodeled_owner_prefix')
    result = {}
    for name, block in blocks.items():
        result[name] = profile_block(root, block, waits, version=version, address=address)
        if address is not None:
            address += result[name].size
    expected_kinds = {}
    for profile in result.values():
        for name, expected in list(profile.targets.items()) + list(profile.texts.items()):
            if name in expected_kinds and expected_kinds[name] != expected:
                raise ValueError('incompatible_reference_kinds:' + name)
            expected_kinds[name] = expected
            if name in result and result[name].kind != expected:
                raise ValueError('incompatible_internal_target:' + name)
    return result
