#!/usr/bin/env python3
"""Regression coverage for source-proven semantic recovery in jp_emit_maps."""
import difflib
import sys
import unittest
from pathlib import Path


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
            'applymovement LOCALID_PLAYER, Route111_Movement_PushUpFromRoute',
        )
        for spelling in required:
            with self.subTest(spelling=spelling):
                self.assertIn(spelling, generated)

    def test_route111_rendering_is_deterministic(self):
        self.assertEqual(render_map('Route111'), render_map('Route111'))


if __name__ == '__main__':
    unittest.main()
