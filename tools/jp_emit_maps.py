#!/usr/bin/env python3
"""Emit per-map script files following the US data/maps/<Map>/scripts.inc
layout, decoded with the strict JP script parser."""

import json
import re
import sys
from pathlib import Path
import collections

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_script_parser as sp
import jp_map_script_metadata as map_metadata
from jp_script_text import JapaneseScriptTextCodec, TextDecodeError, TextRoundTripError

ROM = sp.ROM
_MAP_HEADERS, _MAP_TABLES = map_metadata.build_metadata()
MAP_HEADERS = map_metadata.legacy_map_headers(_MAP_HEADERS)
MAP_TABLES = map_metadata.legacy_map_tables(_MAP_TABLES)
US_JSON = Path('/home/kenny/pokeemerald/data/maps/map_groups.json')

MAP_SCRIPT_NAMES = {
    1: 'MAP_SCRIPT_ON_LOAD',
    2: 'MAP_SCRIPT_ON_FRAME_TABLE',
    3: 'MAP_SCRIPT_ON_TRANSITION',
    4: 'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE',
    5: 'MAP_SCRIPT_ON_RESUME',
    6: 'MAP_SCRIPT_ON_DIVE_WARP',
    7: 'MAP_SCRIPT_ON_RETURN_TO_FIELD',
}

# Confirmed JP script entries which are owned by a map in the US source tree
# but are invoked indirectly rather than through that map's event table.
MAP_AUXILIARY_SCRIPT_ADDRESSES = {
    'RustboroCity_Gym': (0x08202410,),  # EventScript_RegisterRoxanne
}

# Verified map-local text that has no JP script pointer (for example an
# intentionally unused US-source string) and therefore is not discovered by
# the script graph.
MAP_AUXILIARY_TEXT_ADDRESSES = {
    'RustboroCity_DevonCorp_2F': (0x08201B83,),
}

# Map-owned movement scripts confirmed by their JP addresses and the matching
# US map source.  They are referenced by ``applymovement`` rather than being
# event scripts, so the event-script parser deliberately does not follow them.
MAP_MOVEMENT_SCRIPT_LABELS = {
    'Route116': {
        0x081EBBEC: 'Route116_Movement_DevonEmployeeExit',
        0x081EBBF5: 'Route116_Movement_DevonEmployeeExitEast',
        0x081EBD1D: 'Route116_Movement_GlassesManExit',
        0x081EBD27: 'Route116_Movement_GlassesManExitEast',
    },
    'RusturfTunnel': {
        0x082137E0: 'RusturfTunnel_Movement_WandaExit1',
        0x082137EC: 'RusturfTunnel_Movement_WandaExit',
        0x082137F8: 'RusturfTunnel_Movement_PlayerWatchWandaExit',
        0x082137FE: 'RusturfTunnel_Movement_Unused1',
        0x08213801: 'RusturfTunnel_Movement_Unused2',
        0x08213806: 'RusturfTunnel_Movement_Unused3',
        0x0821380B: 'RusturfTunnel_Movement_PlayerWatchBoyfriend1',
        0x0821380E: 'RusturfTunnel_Movement_PlayerWatchBoyfriend',
        0x08213811: 'RusturfTunnel_Movement_BoyfriendFaceRight',
        0x08213814: 'RusturfTunnel_Movement_WandasBoyfriendExit1',
        0x08213821: 'RusturfTunnel_Movement_WandasBoyfriendExit',
        0x0821382E: 'RusturfTunnel_Movement_WandasBoyfriendApproachPlayer',
        0x08213830: 'RusturfTunnel_Movement_BoyfriendApproachWanda1',
        0x08213835: 'RusturfTunnel_Movement_BoyfriendApproachWanda',
        0x08213874: 'RusturfTunnel_Movement_GruntAndPeekoBackUp',
        0x08213941: 'RusturfTunnel_Movement_PushPlayerAsideForGrunt',
        0x08213947: 'RusturfTunnel_Movement_PlayerMoveAsideForBriney',
        0x0821394A: 'RusturfTunnel_Movement_GruntEscape',
        0x08213954: 'RusturfTunnel_Movement_BrineyApproachPeeko1',
        0x0821395C: 'RusturfTunnel_Movement_BrineyExit',
        0x08213968: 'RusturfTunnel_Movement_PlayerWatchBrineyExit',
        0x0821396D: 'RusturfTunnel_Movement_BrineyApproachPeeko2',
        0x08213970: 'RusturfTunnel_Movement_PeekoExit',
    },
    'RustboroCity_DevonCorp_3F': {
        0x08201D2B: 'RustboroCity_DevonCorp_3F_Movement_Unused',
        0x08201D30: 'RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident',
        0x08201D3F: 'RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk',
        0x08201D42: 'RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen',
        0x08201D4B: 'RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer',
        0x08201D54: 'RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident',
        0x08201D62: 'RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk',
    },
    'RustboroCity_PokemonSchool': {
        0x08202D82: 'RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest',
        0x08202D99: 'RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast',
    },
    'SlateportCity_OceanicMuseum_1F': {
        0x081FCAF4: 'SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter',
        0x081FCC68: 'SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth',
        0x081FCC6D: 'SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast',
        0x081FCC70: 'SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit',
        0x081FCC77: 'SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth',
    },
    'SlateportCity_OceanicMuseum_2F': {
        0x081FD4C8: 'SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth',
        0x081FD4CC: 'SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest',
        0x081FD4D2: 'SlateportCity_OceanicMuseum_2F_Movement_Unused',
        0x081FD4E0: 'SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer',
        0x081FD4E2: 'SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter',
        0x081FD4EC: 'SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle',
        0x081FD4EE: 'SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter',
        0x081FD4F2: 'SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach',
        0x081FD4F9: 'SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated',
        0x081FD4FD: 'SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter',
        0x081FD4FF: 'SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach',
        0x081FD508: 'SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie',
    },
    'GraniteCave_StevensRoom': {
        0x082140F2: 'GraniteCave_StevensRoom_Movement_StevenExit',
        0x082140F9: 'GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit',
        0x082140FE: 'GraniteCave_StevensRoom_Movement_StevenExitSouth',
    },
    'PetalburgWoods': {
        0x08214453: 'PetalburgWoods_Movement_DevonResearcherLookAround',
        0x08214464: 'PetalburgWoods_Movement_DevonResearcherExitLeft',
        0x0821446D: 'PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft',
        0x08214472: 'PetalburgWoods_Movement_DevonResearcherApproachPlayerRight',
        0x08214479: 'PetalburgWoods_Movement_DevonResearcherExitRight',
        0x08214482: 'PetalburgWoods_Movement_WatchResearcherLeave',
        0x08214486: 'PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft',
        0x0821448C: 'PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight',
        0x08214490: 'PetalburgWoods_Movement_DevonResearcherStartExit',
        0x08214498: 'PetalburgWoods_Movement_AquaApproachResearcherLeft',
        0x0821449B: 'PetalburgWoods_Movement_AquaBackOff',
        0x0821449F: 'PetalburgWoods_Movement_AquaRunAway',
        0x082144A7: 'PetalburgWoods_Movement_AquaApproachResearcherRight',
        0x082144AB: 'PetalburgWoods_Movement_AquaEntrance',
        0x082144B0: 'PetalburgWoods_Movement_AquaApproachPlayer',
    },
}

# Reviewed JP-to-US names for maps whose event positions, control-flow shape,
# and text/movement ordering have all been checked against the US source.  This
# is intentionally an allowlist: unreviewed addresses keep deterministic
# address labels instead of receiving a plausible-but-unproven semantic name.
MAP_VERIFIED_SEMANTIC_LABELS = {
    'RustboroCity_DevonCorp_3F': {
        'scripts': {
            0x08201C39: 'RustboroCity_DevonCorp_3F_OnTransition',
            0x08201C45: 'RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos',
            0x08201C5B: 'RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast',
            0x08201C6A: 'RustboroCity_DevonCorp_3F_EventScript_MeetPresident',
            0x08201D68: 'RustboroCity_DevonCorp_3F_EventScript_MrStone',
            0x08201D91: 'RustboroCity_DevonCorp_3F_EventScript_GiveExpShare',
            0x08201DC8: 'RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor',
            0x08201DDD: 'RustboroCity_DevonCorp_3F_EventScript_Employee',
            0x08201DF2: 'RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls',
            0x08201DFC: 'RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay',
        },
        'tables': {
            0x08201C51: 'RustboroCity_DevonCorp_3F_OnWarp',
            0x08201C60: 'RustboroCity_DevonCorp_3F_OnFrame',
        },
        'texts': {
            0x08201E05: 'RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor',
            0x08201EE9: 'RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis',
            0x08201F3E: 'RustboroCity_DevonCorp_3F_Text_ReceivedPokenav',
            0x08201F4F: 'RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp',
            0x08202015: 'RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare',
            0x08202037: 'RustboroCity_DevonCorp_3F_Text_CountingOnYou',
            0x08202047: 'RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter',
            0x0820208A: 'RustboroCity_DevonCorp_3F_Text_ExplainExpShare',
            0x082020E6: 'RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends',
            0x0820213E: 'RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere',
            0x08202212: 'RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe',
            0x08202239: 'RustboroCity_DevonCorp_3F_Text_PleaseGoAhead',
            0x08202241: 'RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard',
            0x08202277: 'RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular',
            0x082022A7: 'RustboroCity_DevonCorp_3F_Text_RareRocksDisplay',
        },
        # FD nn is context-sensitive.  These two are field messages whose
        # exact US counterparts establish the intended field placeholders.
        'field_placeholders': {
            0x08201F3E: {0x01: 'PLAYER'},
            0x08202015: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        # These constants are emitted only in argument positions whose US
        # counterpart proves the type (flag, variable, item, song, etc.).
        'symbols': {
            'vars': {
                0x405A: 'VAR_RUSTBORO_CITY_STATE',
                0x408F: 'VAR_DEVON_CORP_3F_STATE',
                0x4096: 'VAR_BRINEY_LOCATION',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'flags': {
                0x00BC: 'FLAG_RECEIVED_POKENAV',
                0x00BD: 'FLAG_DELIVERED_STEVEN_LETTER',
                0x0100: 'FLAG_RECEIVED_REPEAT_BALL',
                0x0110: 'FLAG_RECEIVED_EXP_SHARE',
                0x02E3: 'FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY',
                0x0327: 'FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND',
                0x032E: 'FLAG_HIDE_RUSTBORO_CITY_RIVAL',
                0x0371: 'FLAG_HIDE_BRINEYS_HOUSE_PEEKO',
                0x037E: 'FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND',
                0x03D7: 'FLAG_HIDE_RUSTURF_TUNNEL_WANDA',
                0x03E7: 'FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT',
                0x0862: 'FLAG_SYS_POKENAV_GET',
            },
            'items': {
                0x00B6: 'ITEM_EXP_SHARE',
                0x0112: 'ITEM_LETTER',
            },
            'songs': {
                0x0172: 'MUS_OBTAIN_ITEM',
                0x01A4: 'MUS_FOLLOW_ME',
            },
            'local_ids': {
                0x02: 'LOCALID_DEVON_CORP_3F_EMPLOYEE',
                0xFF: 'LOCALID_PLAYER',
            },
            'directions': {0x04: 'DIR_EAST'},
            'movement_types': {0x09: 'MOVEMENT_TYPE_FACE_LEFT'},
        },
    },
}

MSGBOX_TYPES = {
    2: 'MSGBOX_NPC',
    3: 'MSGBOX_SIGN',
    4: 'MSGBOX_DEFAULT',
    5: 'MSGBOX_YESNO',
    6: 'MSGBOX_AUTOCLOSE',
    9: 'MSGBOX_GETPOINTS',
    10: 'MSGBOX_POKENAV',
}

TEXT_POINTER_ARGUMENTS = {
    'loadword': (1,),
    'message': (0,),
    'pokenavcall': (0,),
}


def toi(x):
    return int(x, 16) if isinstance(x, str) else int(x)


def build_map_names():
    us = json.loads(US_JSON.read_text())
    order = us['group_order']
    names = {}
    for gi, gkey in enumerate(order[:34]):
        for mi, name in enumerate(us[gkey]):
            names[(gi, mi)] = name
    return names


MAP_NAMES = build_map_names()
TEXT_CODEC = JapaneseScriptTextCodec()


def build_movement_action_names():
    """Read the JP movement macro table as its authoritative byte mapping."""
    names = {}
    value = None
    macro_file = ROOT / 'asm' / 'macros' / 'movement.inc'
    for raw_line in macro_file.read_text(encoding='utf-8').splitlines():
        line = raw_line.strip()
        match = re.fullmatch(r'enum_start(?:\s+(0x[0-9A-Fa-f]+))?', line)
        if match:
            value = int(match.group(1), 0) if match.group(1) else 0
            continue
        match = re.fullmatch(
            r'create_movement_action\s+([A-Za-z_][A-Za-z0-9_]*)', line)
        if match and value is not None:
            names[value] = match.group(1)
            value += 1
    return names


MOVEMENT_ACTION_NAMES = build_movement_action_names()
if MOVEMENT_ACTION_NAMES.get(0xFE) != 'step_end':
    raise RuntimeError('movement macro table does not define step_end as 0xFE')


def decode_movement_script(addr, region_end):
    """Decode a proved one-byte movement sequence through its step_end byte."""
    actions = []
    pos = addr
    while pos < region_end:
        action = ROM[pos - 0x08000000]
        name = MOVEMENT_ACTION_NAMES.get(action)
        if name is None:
            return None
        actions.append(name)
        pos += 1
        if action == 0xFE:
            return actions, pos
    return None

def decode_text(data, placeholder_names=None):
    """Return safe source text, or None when a byte sequence is not proved."""
    try:
        return TEXT_CODEC.verify(data, placeholder_names)
    except (TextDecodeError, TextRoundTripError):
        return None


def collapse_msgbox_macros(lines):
    """Restore the source-level ``msgbox`` macro for a proven two-op sequence."""
    out = []
    index = 0
    while index < len(lines):
        name, argstr = lines[index]
        if name == 'loadword' and index + 1 < len(lines):
            next_name, next_argstr = lines[index + 1]
            parts = [part.strip() for part in argstr.split(',', 1)]
            try:
                message_type = int(next_argstr, 0)
            except ValueError:
                message_type = None
            if (next_name == 'callstd' and len(parts) == 2
                    and parts[0] in ('0', '0x0')
                    and message_type in MSGBOX_TYPES):
                out.append(('msgbox', '%s, %s' % (parts[1], MSGBOX_TYPES[message_type])))
                index += 2
                continue
        out.append((name, argstr))
        index += 1
    return out


def collapse_condition_macros(lines):
    """Restore exact two-instruction comparison and flag-test macros."""
    out = []
    index = 0
    while index < len(lines):
        name, argstr = lines[index]
        if index + 1 < len(lines):
            next_name, next_argstr = lines[index + 1]
            parts = [part.strip() for part in argstr.split(',', 1)]
            next_parts = [part.strip() for part in next_argstr.split(',', 1)]
            try:
                condition = int(next_parts[0], 0)
            except (IndexError, ValueError):
                condition = None
            if (name == 'checkflag' and next_name in ('goto_if', 'call_if')
                    and len(next_parts) == 2):
                suffix = {0: 'unset', 1: 'set'}.get(condition)
                if suffix is not None:
                    out.append(('%s_if_%s' % (next_name[:-3], suffix),
                                '%s, %s' % (argstr, next_parts[1])))
                    index += 2
                    continue
            if (name in ('compare_var_to_value', 'compare_var_to_var')
                    and next_name in ('goto_if', 'call_if')
                    and len(parts) == 2 and len(next_parts) == 2):
                suffix = {
                    0: 'lt',
                    1: 'eq',
                    2: 'gt',
                    3: 'le',
                    4: 'ge',
                    5: 'ne',
                }.get(condition)
                if suffix is not None:
                    out.append(('%s_if_%s' % (next_name[:-3], suffix),
                                '%s, %s, %s' % (parts[0], parts[1], next_parts[1])))
                    index += 2
                    continue
        out.append((name, argstr))
        index += 1
    return out


VARIABLE_ARGUMENTS = {
    'compare_var_to_value': {0},
    'compare_var_to_var': {0, 1},
    'setvar': {0},
    'addvar': {0},
    'subvar': {0},
    'copyvar': {0, 1},
    'setorcopyvar': {0},
}
FLAG_ARGUMENTS = {'setflag', 'clearflag', 'checkflag'}
LOCAL_ID_ARGUMENTS = {
    'applymovement': {0},
    'setobjectxyperm': {0},
    'setobjectmovementtype': {0},
    'turnobject': {0},
}


def semantic_symbol_formatter(mname):
    """Return a conservative formatter for reviewed map-script constants."""
    symbols = MAP_VERIFIED_SEMANTIC_LABELS.get(mname, {}).get('symbols', {})
    if not symbols:
        return None

    def format_symbol(name, index, value, args):
        if name in FLAG_ARGUMENTS and index == 0:
            return symbols.get('flags', {}).get(value)
        if index in VARIABLE_ARGUMENTS.get(name, ()):
            return symbols.get('vars', {}).get(value)
        if name == 'setorcopyvar' and index == 1 and args and args[0] == 0x8000:
            return symbols.get('items', {}).get(value)
        if name in ('playbgm', 'playfanfare') and index == 0:
            return symbols.get('songs', {}).get(value)
        if index in LOCAL_ID_ARGUMENTS.get(name, ()):
            local = symbols.get('local_ids', {}).get(value)
            if local is not None:
                return local
            return symbols.get('vars', {}).get(value)
        if name == 'turnobject' and index == 1:
            return symbols.get('directions', {}).get(value)
        if name == 'setobjectmovementtype' and index == 1:
            return symbols.get('movement_types', {}).get(value)
        return None

    return format_symbol


def semantic_map_variable(mname, value):
    """Render a reviewed map-script table variable, if one is available."""
    return (MAP_VERIFIED_SEMANTIC_LABELS.get(mname, {})
            .get('symbols', {}).get('vars', {}).get(value))


def map_entries(include_empty=False):
    """Return sorted [(table_addr, map_name, gi, mi, entries, events)].

    ``include_empty`` retains maps whose table is a single zero terminator.
    Those tables are the missing structural owners behind many US
    ``data/maps/<Map>/scripts.inc`` paths.
    """
    out = []
    for entry in MAP_HEADERS:
        gi, mi, h, layout, events, ms, wild, name_hex = entry
        mname = MAP_NAMES.get((gi, mi))
        if mname is None:
            continue
        ms = toi(ms)
        if ms == 0:
            continue
        tables = MAP_TABLES.get(hex(ms))
        if tables is None:
            tables = MAP_TABLES.get('%x' % ms)
        if tables is None:
            continue
        if not tables and not include_empty:
            continue
        entries = [(toi(t), toi(p)) for t, p in tables]
        out.append((ms, mname, gi, mi, entries, toi(events)))
    out.sort(key=lambda x: x[0])
    return out


def map_events_scripts(events_addr):
    """Script pointers from a MapEvents structure (obj/coord/bg)."""
    rom = sp.ROM
    obj_count = rom[events_addr - 0x08000000]
    coord_count = rom[events_addr - 0x08000000 + 2]
    bg_count = rom[events_addr - 0x08000000 + 3]
    objs = sp.rd32(events_addr + 4)
    coords = sp.rd32(events_addr + 12)
    bgs = sp.rd32(events_addr + 16)
    scripts = []
    for i in range(obj_count):
        s = sp.rd32(objs + i * 0x18 + 0x10)
        if s and s != 0xFFFFFFFF:
            scripts.append(('obj%d' % i, s))
    for i in range(coord_count):
        s = sp.rd32(coords + i * 0x10 + 0xC)
        if s and s != 0xFFFFFFFF:
            scripts.append(('coord%d' % i, s))
    for i in range(bg_count):
        kind = rom[bgs + i * 0xC - 0x08000000 + 0x5]
        s = sp.rd32(bgs + i * 0xC + 0x8)
        if kind <= 4 and s and s != 0xFFFFFFFF:
            scripts.append(('bg%d' % i, s))
    return scripts


def parse_frame_table(addr):
    """tag 2/4 table: (u16 var, u16 compare, .4byte script) until var==0."""
    items = []
    pos = addr
    while True:
        var = sp.rd16(pos)
        if var == 0:
            break
        cmp = sp.rd16(pos + 2)
        script = sp.rd32(pos + 4)
        items.append((var, cmp, script))
        pos += 8
    return items


def collect_map_scripts(map_addr, map_name, extra_addrs=None, events_addr=None,
                        region_end=None):
    """Parse all scripts reachable from the map-script table."""
    extra_addrs = extra_addrs or []
    tables = MAP_TABLES.get(hex(map_addr))
    if tables is None:
        tables = MAP_TABLES.get('%x' % map_addr)
    if tables is None:
        return {}, set()
    scripts = {}   # addr -> script instr list
    text_ptrs = set()
    queue = []
    for tag, ptr in tables:
        t, p = toi(tag), toi(ptr)
        if t in (2, 4):
            for var, cmp, sptr in parse_frame_table(p):
                if sptr not in scripts and \
                        (region_end is None or map_addr <= sptr < region_end):
                    queue.append(sptr)
        else:
            if p not in scripts and (region_end is None or map_addr <= p < region_end):
                queue.append(p)
    for a in extra_addrs:
        if a not in scripts and (region_end is None or map_addr <= a < region_end):
            queue.append(a)
    if events_addr:
        for name, s in map_events_scripts(events_addr):
            if s not in scripts and (region_end is None or map_addr <= s < region_end):
                queue.append(s)
    while queue:
        addr = queue.pop()
        script = sp.parse_script(addr)
        if script is None:
            continue
        scripts[addr] = script
        for off, name, args, refs in script:
            if name in TEXT_POINTER_ARGUMENTS:
                for idx in TEXT_POINTER_ARGUMENTS[name]:
                    if len(args) > idx and 0x08000000 <= args[idx] < 0x0A000000:
                        text_ptrs.add(args[idx])
            elif name == 'trainerbattle':
                for idx in sp.trainerbattle_text_arg_indexes(args):
                    if 0x08000000 <= args[idx] < 0x0A000000:
                        text_ptrs.add(args[idx])
            for r in refs:
                if r not in scripts and r not in queue and \
                        (region_end is None or map_addr <= r < region_end):
                    queue.append(r)
    # de-overlap: truncate scripts that extend into another script entry
    entries = set(scripts)
    for addr in sorted(scripts):
        inner = [e for e in entries if addr < e]
        if not inner:
            continue
        cut = min(inner)
        new_script = []
        pos = addr
        for instr in scripts[addr]:
            d = sp.decode_instruction(pos)
            if d is None or pos >= cut:
                break
            new_script.append(instr)
            pos += d[0]
        if len(new_script) != len(scripts[addr]):
            scripts[addr] = new_script
    return scripts, text_ptrs


def script_ranges(scripts):
    """Covered byte ranges of script instructions."""
    ranges = []
    for addr, script in scripts.items():
        pos = addr
        for off, name, args, refs in script:
            # size unknown here; recompute via decode at pos
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size = r[0]
            ranges.append((pos, pos + size))
            pos += size
    return ranges


def map_table_bytes(ms, entries):
    """Mark bytes of the map-script table (5-byte entries until tag 0)."""
    covered = set()
    pos = ms
    while True:
        tag = sp.rd8(pos)
        if tag == 0:
            covered.add(pos)
            break
        covered.update(range(pos, pos + 5))
        pos += 5
    return covered


def frame_table_bytes(addr):
    covered = set()
    pos = addr
    while True:
        var = sp.rd16(pos)
        if var == 0:
            covered.update(range(pos, pos + 2))
            break
        covered.update(range(pos, pos + 8))
        pos += 8
    return covered


def text_range(tp, region_end):
    """Return one verified EOS-terminated text span, or None if uncertain."""
    raw = ROM[tp - 0x08000000:region_end - 0x08000000]
    try:
        decoded = TEXT_CODEC.verify_one(raw)
    except (TextDecodeError, TextRoundTripError):
        return None
    return tp, tp + decoded.consumed


def emit_map(ms, mname, gi, mi, entries, region_end, global_text_ptrs,
             text_label_map, region_labels=None, std_addrs=None, events_addr=None):
    std_addrs = std_addrs or set()
    semantic = MAP_VERIFIED_SEMANTIC_LABELS.get(mname, {})
    verified_script_labels = semantic.get('scripts', {})
    verified_table_labels = semantic.get('tables', {})
    verified_text_labels = semantic.get('texts', {})
    field_placeholders = semantic.get('field_placeholders', {})
    symbol_formatter = semantic_symbol_formatter(mname)
    extra = [
        a
        for a in (*std_addrs, *MAP_AUXILIARY_SCRIPT_ADDRESSES.get(mname, ()))
        if ms <= a < region_end
    ]
    scripts, text_ptrs = collect_map_scripts(ms, mname, extra, events_addr, region_end)
    missing_scripts = set(verified_script_labels) - set(scripts)
    if missing_scripts:
        raise RuntimeError(
            'verified semantic script labels are not reachable for %s: %s' % (
                mname, ', '.join('0x%08X' % addr for addr in sorted(missing_scripts))))
    text_ptrs.update(
        addr for addr in MAP_AUXILIARY_TEXT_ADDRESSES.get(mname, ())
        if ms <= addr < region_end)
    movement_labels = {
        addr: label
        for addr, label in MAP_MOVEMENT_SCRIPT_LABELS.get(mname, {}).items()
        if ms <= addr < region_end
    }
    movements = {}
    for addr, label in movement_labels.items():
        decoded = decode_movement_script(addr, region_end)
        if decoded is None:
            raise RuntimeError(
                'cannot prove movement script %s at 0x%08X' % (label, addr))
        actions, end = decoded
        movements[addr] = (label, actions, end)
    region_labels = region_labels or {}
    label_map = {}
    for addr in sorted(scripts):
        if addr in std_addrs:
            label_map[addr] = region_labels.get(addr, 'gUnknown_%08X' % (addr & 0xFFFFFF))
        else:
            label_map[addr] = verified_script_labels.get(
                addr, '%s_EventScript_%08X' % (mname, addr & 0xFFFFFF))
    label_map.update(movement_labels)
    # byte coverage
    covered = collections.defaultdict(str)
    for a in range(ms, region_end):
        covered[a] = 'raw'
    for addr, script in scripts.items():
        pos = addr
        for off, name, args, refs in script:
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size = r[0]
            for b in range(pos, pos + size):
                covered[b] = 'script'
            pos += size
    for addr, (_label, _actions, end) in movements.items():
        if any(covered[b] != 'raw' for b in range(addr, end)):
            raise RuntimeError('movement script overlaps decoded data at 0x%08X' % addr)
        for b in range(addr, end):
            covered[b] = 'movement'
    table_addrs = {ms: 'map'}
    for tag, ptr in entries:
        t, p = toi(tag), toi(ptr)
        if t in (2, 4):
            table_addrs[p] = 'frame'
    for ta, kind in table_addrs.items():
        if kind == 'map':
            for b in map_table_bytes(ms, entries):
                covered[b] = 'table'
        else:
            if ms <= ta < region_end:
                for b in frame_table_bytes(ta):
                    covered[b] = 'table'
    missing_tables = set(verified_table_labels) - set(table_addrs)
    if missing_tables:
        raise RuntimeError(
            'verified semantic map-table labels are absent for %s: %s' % (
                mname, ', '.join('0x%08X' % addr for addr in sorted(missing_tables))))
    text_ranges = []
    for tp in sorted(global_text_ptrs | text_ptrs):
        if not (ms <= tp < region_end):
            continue
        result = text_range(tp, region_end)
        if result is None:
            # It remains in the surrounding raw segment.  Do not emit source
            # text unless its terminator and every control byte are proved.
            continue
        a, b = result
        text_ranges.append((a, b))
        for x in range(a, b):
            covered[x] = 'text'
    # A pointer found through another map's script graph is not necessarily
    # defined by a checked-in gJPText_* label yet.  Render only labels emitted
    # by this map; leave external text pointers numeric until their owning
    # source range has been converted and defines the symbol.
    emitted_text_label_map = {}
    for tp, _ in text_ranges:
        emitted_text_label_map[tp] = verified_text_labels.get(
            tp, 'gJPText_%08X' % (tp & 0xFFFFFF))
    missing_texts = set(verified_text_labels) - set(emitted_text_label_map)
    if missing_texts:
        raise RuntimeError(
            'verified semantic text labels are not emitted for %s: %s' % (
                mname, ', '.join('0x%08X' % addr for addr in sorted(missing_texts))))
    missing_placeholder_texts = set(field_placeholders) - set(emitted_text_label_map)
    if missing_placeholder_texts:
        raise RuntimeError(
            'field placeholder metadata has no emitted text for %s: %s' % (
                mname,
                ', '.join('0x%08X' % addr for addr in sorted(missing_placeholder_texts))))
    # build segments in address order
    segs = []
    segs.append((ms, 'map_table', 0))
    for ta in sorted(table_addrs):
        if table_addrs[ta] == 'frame' and ms <= ta < region_end:
            segs.append((ta, 'frame_table', 0))
    for addr in scripts:
        pos = addr
        size = 0
        for off, name, args, refs in scripts[addr]:
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size += r[0]
            pos += r[0]
        segs.append((addr, 'script', addr))
    for addr in movements:
        segs.append((addr, 'movement', addr))
    for tp, end in text_ranges:
        segs.append((tp, 'text', tp))
    # raw gaps
    raw_start = None
    for a in range(ms, region_end):
        if covered[a] == 'raw' and raw_start is None:
            raw_start = a
        elif covered[a] != 'raw' and raw_start is not None:
            segs.append((raw_start, 'raw', raw_start))
            raw_start = None
    if raw_start is not None:
        segs.append((raw_start, 'raw', raw_start))
    segs.sort(key=lambda x: x[0])
    # emit in address order
    lines = ['@ %s scripts (JP map g%d m%d @ 0x%08X)' % (mname, gi, mi, ms), '']
    nraw = 0
    for start, kind, payload in segs:
        if kind == 'map_table':
            old = region_labels.get(ms)
            if old:
                lines.append('%s:: @ 0x%08X' % (old, ms))
            lines.append('%s_MapScripts::' % mname)
            for tag, ptr in entries:
                t, p = toi(tag), toi(ptr)
                if t in (2, 4):
                    if ms <= p < region_end:
                        tbl = verified_table_labels.get(
                            p, '%s_MapScriptTable_%08X' % (mname, p & 0xFFFFFF))
                        lines.append('\tmap_script %s, %s' % (MAP_SCRIPT_NAMES.get(t, str(t)), tbl))
                    else:
                        lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
                elif p in label_map:
                    lines.append('\tmap_script %s, %s' % (MAP_SCRIPT_NAMES.get(t, str(t)), label_map[p]))
                else:
                    lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
            lines.append('\t.byte 0')
            lines.append('')
        elif kind == 'frame_table':
            table_label = verified_table_labels.get(
                start, '%s_MapScriptTable_%08X' % (mname, start & 0xFFFFFF))
            lines.append('%s::' % table_label)
            for var, cmp, sptr in parse_frame_table(start):
                rendered_var = semantic_map_variable(mname, var) or '0x%X' % var
                if sptr in label_map:
                    lines.append('\tmap_script_2 %s, 0x%X, %s' % (
                        rendered_var, cmp, label_map[sptr]))
                else:
                    lines.append('\tmap_script_2 %s, 0x%X, 0x%08X' % (
                        rendered_var, cmp, sptr))
            lines.append('\t.2byte 0')
            lines.append('')
        elif kind == 'script':
            addr = payload
            old = region_labels.get(addr) if addr not in std_addrs else None
            if old:
                lines.append('%s:: @ 0x%08X' % (old, addr))
            lines.append('%s::' % label_map[addr])
            decoded_lines = sp.decode_script_lines(
                scripts[addr], label_map, emitted_text_label_map, symbol_formatter)
            decoded_lines = collapse_msgbox_macros(decoded_lines)
            for name, argstr in collapse_condition_macros(decoded_lines):
                if argstr:
                    lines.append('\t%s %s' % (name, argstr))
                else:
                    lines.append('\t%s' % name)
            lines.append('')
        elif kind == 'movement':
            label, actions, _end = movements[payload]
            lines.append('%s:' % label)
            for action in actions:
                lines.append('\t%s' % action)
            lines.append('')
        elif kind == 'text':
            tp = payload
            end = text_ranges[[x[0] for x in text_ranges].index(tp)][1]
            raw = ROM[tp - 0x08000000:end - 0x08000000]
            dec = decode_text(raw, field_placeholders.get(tp))
            if dec is None:
                lines.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                    tp - 0x08000000, end - tp))
                nraw += 1
                continue
            label = emitted_text_label_map[tp]
            if label.startswith('gJPText_'):
                lines.append('\t.globl %s' % label)
            lines.append('%s: @ 0x%08X' % (label, tp))
            old = region_labels.get(tp)
            if old and old != label:
                lines.append('\t.globl %s' % old)
                lines.append('%s:' % old)
            parts = [p for p in re.split(r'(?<=\\l|\\p|\\n)', dec) if p]
            for k, part in enumerate(parts):
                if k == len(parts) - 1 and dec.endswith('$'):
                    lines.append('\t.string "%s$"' % part.rstrip('$'))
                else:
                    lines.append('\t.string "%s"' % part)
            lines.append('')
        elif kind == 'raw':
            a = start
            b = region_end
            for s2, k2, p2 in segs:
                if k2 != 'raw' and s2 > a:
                    b = min(b, s2)
            old = region_labels.get(a)
            if old:
                lines.append('%s:: @ 0x%08X' % (old, a))
            lines.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                a - 0x08000000, b - a))
            nraw += 1
    return '\n'.join(lines).rstrip() + '\n', len(text_ranges), nraw


def collect_all_text_ptrs(entries):
    """Global set of text pointers reachable from map scripts."""
    all_ptrs = set()
    for ms, mname, gi, mi, ents, events_addr in entries:
        _, tptrs = collect_map_scripts(
            ms,
            mname,
            MAP_AUXILIARY_SCRIPT_ADDRESSES.get(mname, ()),
            events_addr,
        )
        all_ptrs |= tptrs
    return all_ptrs


def event_script_labels():
    """addr -> label name from data/scripts/*.inc file names + event_scripts.s."""
    labels = {}
    for p in (ROOT / 'data' / 'scripts').glob('gUnknown_*.inc'):
        labels[int(p.stem[len('gUnknown_'):], 16)] = p.stem
    for line in (ROOT / 'data' / 'event_scripts.s').read_text(
            encoding='utf-8').splitlines():
        m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)', line)
        if m:
            labels.setdefault(int(m.group(2), 16), m.group(1))
    return labels


def main():
    do_write = '--write' in sys.argv
    include_empty = '--include-empty' in sys.argv
    args = [a for a in sys.argv[1:] if a not in ('--write', '--include-empty')]
    m = args[0] if args else None
    entries = map_entries(include_empty=include_empty or m is not None)
    print('maps:', len(entries))
    global_text_ptrs = collect_all_text_ptrs(entries)
    print('global text ptrs:', len(global_text_ptrs))
    text_label_map = {p: 'gJPText_%08X' % (p & 0xFFFFFF) for p in global_text_ptrs}
    all_labels = event_script_labels()
    map_starts = {e[0] for e in entries}
    nonmap = sorted(a for a in all_labels if a not in map_starts)
    last_map_end = next((a for a in nonmap if a > entries[-1][0]), 0x0828F000)
    print('last map region end:', hex(last_map_end))
    total_raw = 0
    total_text = 0
    for i, (ms, mname, gi, mi, ents, events_addr) in enumerate(entries):
        if m and mname != m:
            continue
        if i > 0 and ms == entries[i - 1][0]:
            if not m:
                continue  # shared map-script table; emitted with the first map
        j = i + 1
        while j < len(entries) and entries[j][0] == ms:
            j += 1
        region_end = entries[j][0] if j < len(entries) else last_map_end
        region_labels = {a: n for a, n in all_labels.items() if ms <= a < region_end}
        if m and mname == m:
            print('region_labels for', mname, ':', len(region_labels),
                  list(region_labels.items())[:8])
        out, ntext, nraw = emit_map(ms, mname, gi, mi, ents, region_end,
                                    global_text_ptrs, text_label_map,
                                    region_labels, set(), events_addr)
        total_raw += nraw
        total_text += ntext
        if do_write:
            outdir = ROOT / 'data' / 'maps' / mname
            outdir.mkdir(parents=True, exist_ok=True)
            (outdir / 'scripts.inc').write_text(out, encoding='utf-8')
        if m:
            print('=== %s @ %08X region 0x%X texts=%d rawinc=%d ===' % (
                mname, ms, region_end - ms, ntext, nraw))
            print(out[:2500])
            return
    print('total raw incbin lines:', total_raw, 'text ranges:', total_text)


if __name__ == '__main__':
    main()
