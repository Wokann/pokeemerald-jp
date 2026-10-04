#!/usr/bin/env python3
"""Regression coverage for source-proven semantic recovery in jp_emit_maps."""
import difflib
import re
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))

import jp_emit_maps as emitter  # noqa: E402


def render_map(name):
    """Render one map exactly as jp_emit_maps.main would, without writing it."""
    entries = emitter.map_entries(include_empty=True)
    global_text_ptrs = emitter.collect_all_text_ptrs(entries)
    text_label_map = {
        pointer: 'gJPText_%08X' % (pointer & 0xFFFFFF)
        for pointer in global_text_ptrs
    }
    all_labels = emitter.event_script_labels()
    map_starts = {entry[0] for entry in entries}
    nonmap = sorted(address for address in all_labels if address not in map_starts)
    last_map_end = next(
        (address for address in nonmap if address > entries[-1][0]),
        0x0828F000)
    for index, (start, map_name, group, number, map_entries, events_addr) in enumerate(entries):
        if map_name != name:
            continue
        next_index = index + 1
        while next_index < len(entries) and entries[next_index][0] == start:
            next_index += 1
        natural_end = (entries[next_index][0]
                       if next_index < len(entries) else last_map_end)
        region_end = emitter.MAP_SOURCE_REGION_ENDS.get(map_name, natural_end)
        region_labels = {
            address: label for address, label in all_labels.items()
            if start <= address < region_end
        }
        return emitter.emit_map(
            start, map_name, group, number, map_entries, region_end,
            global_text_ptrs, text_label_map, region_labels, set(), events_addr)[0]
    raise AssertionError('map not found: %s' % name)


class Route111SemanticRecoveryTest(unittest.TestCase):
    def collapse_movement(self, generated, reviewed):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            owner = root / 'data/maps/Map'
            owner.mkdir(parents=True)
            (owner / 'scripts.inc').write_text(reviewed, encoding='utf-8')
            with patch.object(emitter, 'ROOT', root):
                overrides = emitter.reviewed_operand_overrides('Map', generated)
                named = emitter.apply_reviewed_operand_overrides(generated, overrides)
                return emitter.collapse_reviewed_movement_wait_macros('Map', named)

    def test_movement_helper_retains_address_scoped_operands(self):
        generated = ('Map_First:: @ 0x08100000\n'
                     '\tapplymovement 0x1, 0x08100100\n\twaitmovement 0x0\n'
                     'Map_Second:: @ 0x08100010\n'
                     '\tapplymovement 0x1, 0x08100100\n\twaitmovement 0x0\n')
        reviewed = ('Map_First:: @ 0x08100000\n'
                    '\tapplywaitmovement LOCALID_MAP_NPC, Map_Movement\n'
                    'Map_Second:: @ 0x08100010\n'
                    '\tapplymovement 0x1, 0x08100100\n\twaitmovement 0x0\n')
        self.assertEqual(self.collapse_movement(generated, reviewed), reviewed)

    def test_movement_helper_does_not_collapse_nonzero_wait(self):
        generated = ('Map_First:: @ 0x08100000\n'
                     '\tapplymovement 1, Movement\n\twaitmovement 1\n')
        reviewed = ('Map_First:: @ 0x08100000\n'
                    '\tapplywaitmovement 1, Movement\n')
        self.assertEqual(self.collapse_movement(generated, reviewed), generated)

    def test_movement_helper_does_not_cross_a_label_or_comment(self):
        reviewed = ('Map_First:: @ 0x08100000\n'
                    '\tapplywaitmovement 1, Movement\n')
        for separator in ('Map_Second:: @ 0x08100007\n', '\t@ keep this boundary\n'):
            generated = ('Map_First:: @ 0x08100000\n\tapplymovement 1, Movement\n'
                         + separator + '\twaitmovement 0\n')
            with self.subTest(separator=separator):
                self.assertEqual(self.collapse_movement(generated, reviewed), generated)

    def test_movement_helper_preserves_parallel_and_optional_map_commands(self):
        for generated, reviewed in (
            ('\tapplymovement 1, Movement\n\tapplymovement 2, Other\n\twaitmovement 0\n',
             '\tapplymovement 1, Movement\n\tapplymovement 2, Other\n\twaitmovement 0\n'),
            ('\tapplymovement_at 1, Movement, MAP_OTHER\n\twaitmovement 0\n',
             '\tapplywaitmovement 1, Movement, MAP_OTHER\n'),
        ):
            prefix = 'Map_First:: @ 0x08100000\n'
            with self.subTest(generated=generated):
                self.assertEqual(self.collapse_movement(prefix + generated, prefix + reviewed),
                                 prefix + generated)

    def test_overrides_are_address_and_command_scoped(self):
        generated = (
            'Map_Script:: @ 0x08100000\n'
            '\tcall_if_unset 0xE4, Target\n'
            'Map_Other:: @ 0x08100010\n'
            '\tcall_if_unset 0xE4, Target\n')
        override = {
            (0x08100000, 'call_if_unset', 0, 0xE4): 'FLAG_REGI_DOORS_OPENED',
        }
        expected = generated.replace(
            'call_if_unset 0xE4, Target\nMap_Other',
            'call_if_unset FLAG_REGI_DOORS_OPENED, Target\nMap_Other')
        self.assertEqual(
            emitter.apply_reviewed_operand_overrides(generated, override), expected)

    def test_route111_matches_reviewed_semantic_source(self):
        generated = render_map('Route111')
        checked_in = (ROOT / 'data' / 'maps' / 'Route111' / 'scripts.inc').read_text(
            encoding='utf-8')
        if generated != checked_in:
            self.fail('\n'.join(difflib.unified_diff(
                checked_in.splitlines(), generated.splitlines(),
                fromfile='checked-in', tofile='generated', n=2)))

        # Exercise the semantic categories that formerly regressed to raw
        # operands. These are exact output assertions, not a map snapshot.
        required = (
            'FLAG_REGI_DOORS_OPENED',             # flag
            'VAR_MIRAGE_TOWER_STATE',             # variable
            'TRAINER_VICKY',                       # trainer
            'MAP_LITTLEROOT_TOWN',                 # map
            'LAYOUT_ROUTE111_NO_MIRAGE_TOWER',     # layout
            'LOCALID_ROUTE111_PLAYER_FALLING',     # object id
            'Route111_Text_ClawFossilDisappeared', # local text
            'GabbyAndTy_EventScript_UpdateLocation',  # external script
            'Route111_Movement_PlayerFall',        # movement
            'METATILE_Mauville_MirageTower_Tile0', # metatile
            'special SetMirageTowerVisibility',    # special
            'trainerbattle_single ',               # trainer battle macro
            'giveitem ITEM_RAZZ_BERRY',            # item macro
            'register_matchcall TRAINER_DUSTY_1',  # match-call macro
            'applywaitmovement LOCALID_PLAYER, Route111_Movement_PushUpFromRoute',
        )
        for spelling in required:
            with self.subTest(spelling=spelling):
                self.assertIn(spelling, generated)

    def test_route111_rendering_is_deterministic(self):
        self.assertEqual(render_map('Route111'), render_map('Route111'))


class ReviewedMapShorthandTest(unittest.TestCase):
    def test_hideplayer_accepts_only_exact_player_and_zero_map(self):
        for args in ('LOCALID_PLAYER, MAP_NONE', '0xFF, 0x0',
                     '255, 0', '0xff, MAP_NONE', 'LOCALID_PLAYER, 0'):
            with self.subTest(args=args):
                self.assertEqual(
                    emitter.collapse_player_visibility_macros([('hideobjectat', args)]),
                    [('hideplayer', '')])

    def test_hideplayer_retains_other_objects_maps_and_commands(self):
        for line in (('hideobjectat', '1, 0'),
                     ('hideobjectat', 'LOCALID_PLAYER, MAP_OTHER'),
                     ('hideobjectat', '0xFF, 1'),
                     ('hideobjectat', 'VAR_LAST_TALKED, MAP_NONE'),
                     ('hideobjectat', '0xFF, 0, 1'),
                     ('showobjectat', '0xFF, 0')):
            with self.subTest(line=line):
                self.assertEqual(emitter.collapse_player_visibility_macros([line]), [line])

    def test_tower_opponent_uses_current_and_legacy_special_names(self):
        for special in ('CallBattleTowerFunc', 'sub_08161E88'):
            lines = [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT'),
                     ('special', special)]
            with self.subTest(special=special):
                self.assertEqual(emitter.collapse_battle_tent_macros(lines, enabled=True),
                                 [('tower_setopponent', '')])
                self.assertEqual(emitter.collapse_battle_tent_macros(lines), lines)

    def test_tower_opponent_does_not_match_another_function_or_special(self):
        for lines in (
            [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_INIT'),
             ('special', 'CallBattleTowerFunc')],
            [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT'),
             ('special', 'CallOtherFunction')],
            [('setvar', 'VAR_0x8005, BATTLE_TOWER_FUNC_SET_OPPONENT'),
             ('special', 'CallBattleTowerFunc')],
            [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT'),
             ('waitstate', ''), ('special', 'CallBattleTowerFunc')],
        ):
            with self.subTest(lines=lines):
                self.assertEqual(emitter.collapse_battle_tent_macros(lines, enabled=True),
                                 lines)

    def test_reviewed_shorthand_survives_actual_map_regeneration(self):
        expected = {
            'SlateportCity_OceanicMuseum_1F': ('giveitem ITEM_TM_THIEF', 'giveitem ITEM_TM46'),
            'MauvilleCity_House1': ('giveitem ITEM_HM_ROCK_SMASH', 'giveitem ITEM_HM06'),
            'SlateportCity_Harbor': ('\thideplayer\n', 'hideobjectat 0xFF, 0x0'),
            'VerdanturfTown_BattleTentBattleRoom': ('\ttower_setopponent\n',
                                                 'special CallBattleTowerFunc'),
        }
        for name, (required, forbidden) in expected.items():
            with self.subTest(map=name):
                generated = render_map(name)
                self.assertIn(required, generated)
                self.assertNotIn(forbidden, generated)

    def test_devon_text_placeholders_match_their_calling_context_and_us_labels(self):
        cases = {
            'RustboroCity_DevonCorp_2F': {
                'HandedFossilToResearcher': ['{PLAYER}', '{STR_VAR_1}'],
                'FossilizedMonBroughtBackToLife': ['{STR_VAR_2}'],
                'ReceivedMonFromResearcher': ['{PLAYER}', '{STR_VAR_2}'],
            },
            'RustboroCity_DevonCorp_3F': {
                'ReceivedPokenav': ['{PLAYER}'],
                'MrStoneGoWithCautionAndCare': ['{PLAYER}', '{KUN}'],
            },
        }
        for name, labels in cases.items():
            generated = render_map(name)
            reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
            for suffix, expected in labels.items():
                label = name + '_Text_' + suffix
                pattern = (r'^' + re.escape(label)
                           + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)')
                for tag, source in (('JP generated', generated), ('US reference', reference)):
                    with self.subTest(map=name, label=label, source=tag):
                        block = re.search(pattern, source, re.M | re.S)
                        self.assertIsNotNone(block)
                        strings = '\n'.join(line for line in block.group(1).splitlines()
                                            if line.lstrip().startswith('.string'))
                        self.assertEqual(re.findall(r'\{[^}]+\}', strings), expected)


if __name__ == '__main__':
    unittest.main()
