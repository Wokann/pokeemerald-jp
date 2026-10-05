"""Byte and semantic guards for the contiguous post-dungeon map owners."""

import json
from pathlib import Path
import unittest
from unittest import mock

import jp_emit_maps as emitter
import verify_generated_map_scripts as verifier
from test_dungeon_map_scripts import instruction_lines, parallel_movements, source_lines


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / 'pokeemerald'
MAPS = (
    'BattleColosseum_2P', 'TradeCenter', 'RecordCorner', 'BattleColosseum_4P',
    'ContestHall', 'InsideOfTruck', 'SSTidalCorridor', 'SSTidalLowerDeck',
    'SSTidalRooms', 'BattlePyramidSquare01', 'UnionRoom',
    'SafariZone_Northwest', 'SafariZone_North', 'SafariZone_Southwest',
    'SafariZone_South',
)
START = 0x0821D626
END = 0x0821EBA1
SHARED_START = 0x0821D372


class ReviewedSourceAddressesTests(unittest.TestCase):
    def test_configured_names_are_anchored_without_editing_source(self):
        source = 'Known::\n\tsetvar VAR_RESULT, TRUE\nUnknown::\n\tend\n'
        metadata = {'FixtureMap': {'scripts': {0x0821D644: 'Known'}}}
        with mock.patch.dict(emitter.MAP_VERIFIED_SEMANTIC_LABELS, metadata), \
                mock.patch.object(Path, 'read_text', return_value=source):
            result = emitter.reviewed_map_source('FixtureMap')
        self.assertEqual(result, 'Known:: @ 0x0821D644\n\tsetvar VAR_RESULT, TRUE\nUnknown::\n\tend\n')
        self.assertNotIn('@', source)

    def test_unknown_label_cannot_borrow_a_previous_address(self):
        source = ('Known:: @ 0x0821D644\n\tsetvar VAR_RESULT, TRUE\n'
                  'Unknown::\n\tsetvar VAR_RESULT, FALSE\n')
        commands = emitter._reviewed_commands_by_address(source)
        self.assertEqual(dict(commands), {0x0821D644: [('setvar', 'VAR_RESULT, TRUE')]})

    def test_explicit_source_address_must_match_metadata(self):
        metadata = {'FixtureMap': {'scripts': {0x0821D644: 'Known'}}}
        with mock.patch.dict(emitter.MAP_VERIFIED_SEMANTIC_LABELS, metadata), \
                mock.patch.object(Path, 'read_text', return_value='Known:: @ 0x0821D645\n\tend\n'):
            with self.assertRaisesRegex(RuntimeError, 'source address mismatch'):
                emitter.reviewed_map_source('FixtureMap')

    def test_conflicting_metadata_is_rejected(self):
        for conflicting in ('tables', 'movements'):
            with self.subTest(conflicting=conflicting):
                metadata = {'FixtureMap': {'scripts': {0x0821D644: 'Known'}}}
                if conflicting == 'tables':
                    metadata['FixtureMap']['tables'] = {0x0821D645: 'Known'}
                    movements = {}
                else:
                    movements = {'FixtureMap': {0x0821D645: 'Known'}}
                with mock.patch.dict(emitter.MAP_VERIFIED_SEMANTIC_LABELS, metadata), \
                        mock.patch.dict(emitter.MAP_MOVEMENT_SCRIPT_LABELS, movements), \
                        mock.patch.object(Path, 'read_text', return_value='Known::\n\tend\n'):
                    with self.assertRaisesRegex(RuntimeError, 'conflicting reviewed JP addresses'):
                        emitter.reviewed_map_source('FixtureMap')


@unittest.skipUnless((US / 'data/event_scripts.s').exists(), 'US reference checkout required')
class PostDungeonScriptRegenerationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.sources = {name: (ROOT / 'data/maps' / name / 'scripts.inc').read_text(encoding='utf-8')
                       for name in MAPS}
        cls.contexts = {name: verifier.map_context(name) for name in MAPS}

    def test_all_current_instructions_and_event_json_match_us(self):
        for name in MAPS:
            with self.subTest(map=name):
                directory = Path('data/maps') / name
                reference = (US / directory / 'scripts.inc').read_text(encoding='utf-8')
                self.assertEqual(instruction_lines(self.sources[name]), instruction_lines(reference))
                self.assertEqual(json.loads((ROOT / directory / 'map.json').read_text()),
                                 json.loads((US / directory / 'map.json').read_text()))

    def test_every_owner_regenerates_existing_semantics_and_jp_text(self):
        text_count = 0
        cursor = START
        for name in MAPS:
            with self.subTest(map=name):
                start, end, generated, texts, raw = self.contexts[name]
                self.assertEqual(start, cursor)
                self.assertEqual(raw, 0)
                self.assertEqual(source_lines(generated), source_lines(self.sources[name]))
                self.assertNotRegex(generated, r'(?:gJPText_|EventScript_[0-9A-F]{8}|\.incbin|\.set\s)')
                text_count += texts
                cursor = end
        self.assertEqual(cursor, END)
        self.assertEqual(text_count, 49)

    def test_whole_contiguous_interval_is_byte_exact(self):
        generated = '\n'.join(self.contexts[name][2] for name in MAPS)
        expected = emitter.ROM[START - 0x08000000:END - 0x08000000]
        self.assertEqual(verifier.assemble_candidate(generated, START), expected)
        self.assertEqual(verifier.assemble_candidate('\n'.join(self.sources.values()), START), expected)
        self.assertEqual(len(expected), 0x157B)

    def test_shared_secret_base_remains_a_separate_exact_owner(self):
        shared = (ROOT / 'data/scripts/shared_secret_base.inc').read_text(encoding='utf-8')
        reference = (US / 'data/scripts/shared_secret_base.inc').read_text(encoding='utf-8')
        self.assertEqual(instruction_lines(shared), instruction_lines(reference))
        expected = emitter.ROM[SHARED_START - 0x08000000:START - 0x08000000]
        self.assertEqual(verifier.assemble_candidate(shared, SHARED_START), expected)
        self.assertEqual(len(expected), 0x2B4)
        # Later Secret Base code/text is not absorbed into this physical run.
        later = (ROOT / 'data/scripts/secret_base.inc').read_text(encoding='utf-8')
        self.assertEqual(instruction_lines(later), instruction_lines(
            (US / 'data/scripts/secret_base.inc').read_text(encoding='utf-8')))

    def test_contest_audience_and_cross_owner_calls_are_complete(self):
        generated = self.contexts['ContestHall'][2]
        self.assertEqual(generated.count('createvobject '), 79)
        self.assertEqual(generated.count('\tswitch '), 4)
        self.assertIn('call ContestHall_EventScript_TryWaitForLink', generated)
        self.assertIn('LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay::', generated)
        self.assertNotIn('warn=FALSE', generated)

    def test_union_room_preserves_all_interaction_and_unused_entries(self):
        generated = self.contexts['UnionRoom'][2]
        for player in range(1, 9):
            self.assertIn('UnionRoom_EventScript_Player%d::' % player, generated)
            self.assertIn('UR_INTERACT_PLAYER_%d' % player, generated)
        self.assertIn('UnionRoom_EventScript_Attendant::', generated)
        self.assertIn('UnionRoom_EventScript_Unused::', generated)
        self.assertEqual(generated.count('\twaitstate'), 10)

    def test_ship_scene_keeps_parallel_movement_and_cross_deck_flow(self):
        corridor = self.contexts['SSTidalCorridor'][2]
        rooms = self.contexts['SSTidalRooms'][2]
        self.assertEqual(parallel_movements(corridor), parallel_movements(self.sources['SSTidalCorridor']))
        self.assertEqual(len(parallel_movements(corridor)), 1)
        self.assertEqual(len(parallel_movements(corridor)[0]), 3)
        self.assertIn('SSTidalRooms_EventScript_ProgessCruiseAfterBed::', corridor)
        self.assertIn('call SSTidalRooms_EventScript_ProgessCruiseAfterBed', rooms)
        self.assertIn('giveitem ITEM_TM_SNATCH', rooms)
        self.assertIn('{PLAYER}{KUN}', corridor)
        self.assertNotIn('{STRING ', corridor)

    def test_nine_serial_helpers_match_us_without_collapsing_parallel_scene(self):
        total = 0
        for name, count in (('SSTidalCorridor', 3), ('SafariZone_South', 6)):
            with self.subTest(map=name):
                current = self.sources[name]
                reference = (US / 'data/maps' / name / 'scripts.inc').read_text(encoding='utf-8')
                current_helpers = [line for line in source_lines(current, False)
                                   if line.startswith('applywaitmovement ')]
                reference_helpers = [line for line in source_lines(reference, False)
                                     if line.startswith('applywaitmovement ')]
                self.assertEqual(current_helpers, reference_helpers)
                self.assertEqual(len(current_helpers), count)
                total += count
        self.assertEqual(total, 9)

    def test_safari_keeps_external_texts_and_unused_motion(self):
        generated = self.contexts['SafariZone_South'][2]
        self.assertIn('switch VAR_FACING', generated)
        self.assertIn('case DIR_NORTH, SafariZone_South_EventScript_ExitEarlyNorth', generated)
        self.assertIn('case DIR_EAST, SafariZone_South_EventScript_ExitEarlyEast', generated)
        self.assertEqual(generated.count('_Movement_'), self.sources['SafariZone_South'].count('_Movement_'))
        self.assertNotIn('.string ', generated)
        self.assertIn('SafariZone_South_Text_GoodLuck', generated)

    def test_include_chain_does_not_skip_empty_tables_or_next_frontier_owner(self):
        top = (ROOT / 'data/event_scripts.s').read_text(encoding='utf-8')
        paths = ['data/scripts/shared_secret_base.inc']
        paths.extend('data/maps/%s/scripts.inc' % name for name in MAPS)
        paths.append('data/maps/BattleFrontier_OutsideWest/scripts.inc')
        positions = [top.index('.include "%s"' % path) for path in paths]
        self.assertEqual(positions, sorted(positions))
        for name in ('BattleColosseum_2P', 'TradeCenter', 'RecordCorner',
                     'BattleColosseum_4P', 'BattlePyramidSquare01'):
            self.assertEqual(self.contexts[name][1] - self.contexts[name][0], 1)
            self.assertEqual(source_lines(self.contexts[name][2]), [name + '_MapScripts:', '.byte 0'])


if __name__ == '__main__':
    unittest.main()
