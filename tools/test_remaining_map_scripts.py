"""Guards for the final contiguous map-script run and its JP differences."""

from collections import Counter
import copy
import hashlib
import json
from pathlib import Path
import re
import unittest

import audit_map_event_generation as events
import jp_emit_maps as emitter
import verify_generated_map_scripts as verifier
from test_dungeon_map_scripts import instruction_lines, parallel_movements, source_lines


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / 'pokeemerald'
START = 0x0821EBA1
END = 0x082423AF
REGION_SHA256 = 'aa889ac525fd6d1be350ca0395a4497e9d9ff3c7522f0b3fbc9b851e0c8abaa8'
TOP = (ROOT / 'data/event_scripts.s').read_text(encoding='utf-8')
INCLUDES = re.findall(r'^\s*\.include "([^"]+)"', TOP, re.M)
FIRST = INCLUDES.index('data/maps/BattleFrontier_OutsideWest/scripts.inc')
LAST = INCLUDES.index('data/scripts/std_msgbox.inc')
MAPS = tuple(Path(path).parent.name for path in INCLUDES[FIRST:LAST])


def serial_keys(source):
    result = Counter()
    label = None
    for line in source_lines(source, include_text=False):
        if line.endswith(':'):
            label = line[:-1]
        elif line.startswith('applywaitmovement '):
            result[label, line.split(None, 1)[1]] += 1
    return result


def control_flow_keys(source):
    result = Counter()
    label = None
    for line in source_lines(source, include_text=False):
        if line.endswith(':'):
            label = line[:-1]
        elif line.startswith(('switch ', 'case ')):
            result[label, tuple(instruction_lines(line))] += 1
    return result


def jp_reference_instructions(name, source):
    """Apply only the explicitly reviewed regional differences to US source."""
    if name in ('BattleFrontier_BattleTowerBattleRoom',
                'BattleFrontier_BattlePalaceBattleRoom',
                'BattleFrontier_BattleArenaBattleRoom'):
        old = '\tclosemessage\n\tsetvar VAR_TEMP_2, 0\n'
        assert source.count(old) == 1
        source = source.replace(old, '\tclosemessage\n')
    elif name == 'BattleFrontier_OutsideEast':
        old = '\tmsgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT\n\tclosemessage\n'
        assert source.count(old) == 1
        source = source.replace(old, '\tmsgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT\n')
    elif name == 'BattleFrontier_BattleFactoryPreBattleRoom':
        assert source.count('\tspecial CalculatePlayerPartyCount\n') == 1
        source = source.replace('\tspecial CalculatePlayerPartyCount\n', '')
    elif name == 'BattleFrontier_Lounge7':
        for value in (0, 1):
            old = '\tsetvar VAR_0x8006, %d\n' % value
            assert source.count(old) == 2
            source = source.replace(old, '')
    lines = instruction_lines(source)
    if name == 'TrainerHill_Entrance':
        excluded_blocks = {name + '_EventScript_' + suffix for suffix in
                           ('Closed', 'ManTrainerHillClosed', 'GirlTrainerHillClosed')}
        excluded_texts = {name + '_Text_' + suffix + ':' for suffix in
                          ('StillGettingReady', 'CantWaitToTestTheWaters', 'DoYouKnowWhenTheyOpen')}
        result = []
        label = None
        mode_commands = {
            'multichoice 13, 2, MULTI_TAG_MATCH_TYPE, 0',
            'copyvar VAR_0x8000, VAR_RESULT',
            'goto_if_eq VAR_0x8000, 4, TrainerHill_Entrance_EventScript_CancelEntry',
            'goto_if_eq VAR_0x8000, MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry',
            'trainerhill_setmode VAR_RESULT',
        }
        for line in lines:
            if line.endswith(':'):
                label = line[:-1]
            if (label in excluded_blocks or line in excluded_texts
                    or line.startswith('goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_')
                    or (label == name + '_EventScript_ChooseChallenge' and line in mode_commands)):
                continue
            result.append(line)
        lines = result
    return lines


@unittest.skipUnless((US / 'data/event_scripts.s').exists(), 'US reference checkout required')
class RemainingMapScriptsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.jp = {name: (ROOT / 'data/maps' / name / 'scripts.inc').read_text(encoding='utf-8')
                  for name in MAPS}
        cls.us = {name: (US / 'data/maps' / name / 'scripts.inc').read_text(encoding='utf-8')
                  for name in MAPS}

    def test_ordered_batch_has_no_hidden_raw_or_temporary_rom_alias(self):
        self.assertEqual(len(MAPS), 107)
        self.assertEqual(MAPS[-1], 'Route124_DivingTreasureHuntersHouse')
        aliases = 0
        strings = 0
        for name in MAPS:
            with self.subTest(map=name):
                source = self.jp[name]
                self.assertNotRegex(source, r'(?m)^\s*\.(?:incbin|globl)\b')
                self.assertNotRegex(source, r'\{(?:STRING|ESCAPE)\s')
                for declaration in re.findall(r'(?m)^\s*(\.set[^\n]+)', source):
                    self.assertIn(declaration, self.us[name])
                    self.assertNotRegex(declaration, r'0x08[0-9A-Fa-f]{6}')
                    aliases += 1
                strings += source.count('.string ')
        self.assertEqual(aliases, 14)
        self.assertEqual(strings, 5731)

    def test_instruction_semantics_match_us_with_only_reviewed_jp_differences(self):
        for name in MAPS:
            with self.subTest(map=name):
                self.assertEqual(instruction_lines(self.jp[name]),
                                 jp_reference_instructions(name, self.us[name]))
                expected = control_flow_keys(self.us[name])
                if name == 'TrainerHill_Entrance':
                    expected = Counter({key: count for key, count in expected.items()
                                        if key[0] != name + '_EventScript_ChooseChallenge'})
                self.assertEqual(control_flow_keys(self.jp[name]), expected)

    def test_all_254_serial_helpers_keep_parallel_scene_groups(self):
        total = 0
        for name in MAPS:
            with self.subTest(map=name):
                actual = serial_keys(self.jp[name])
                expected = serial_keys(self.us[name])
                if name == 'TrainerHill_Entrance':
                    key = (name + '_EventScript_Closed',
                           'LOCALID_PLAYER, ' + name + '_Movement_PushPlayerBackFromCounter')
                    self.assertEqual(expected.pop(key), 1)
                self.assertEqual(actual, expected)
                total += sum(actual.values())
                self.assertEqual(
                    parallel_movements(re.sub(r'\b0x0+\b', '0', self.jp[name])),
                    parallel_movements(re.sub(r'\b0x0+\b', '0', self.us[name])),
                )
        self.assertEqual(total, 254)

    def test_complete_map_run_is_byte_exact_and_stops_before_standard_scripts(self):
        source = '\n'.join(self.jp[name] for name in MAPS)
        expected = emitter.ROM[START - verifier.ROM_BASE:END - verifier.ROM_BASE]
        self.assertEqual(len(expected), 145422)
        self.assertEqual(hashlib.sha256(expected).hexdigest(), REGION_SHA256)
        self.assertEqual(verifier.assemble_candidate(source, START), expected)
        linked = verifier._linked_elf_symbol_addresses()
        self.assertEqual(linked['BattleFrontier_OutsideWest_MapScripts'], frozenset({START}))
        self.assertEqual(linked['Std_MsgboxNPC'], frozenset({END}))

    def test_all_event_files_regenerate_from_json_without_modifying_the_worktree(self):
        pairs = [(ROOT / 'data/maps' / name / 'map.json', ROOT / 'data/maps' / name / 'events.inc')
                 for name in MAPS]
        self.assertEqual(events.verify_generation(ROOT, pairs), [])

    def test_event_json_matches_us_except_two_byte_verified_regional_layouts(self):
        for name in MAPS:
            with self.subTest(map=name):
                current = json.loads((ROOT / 'data/maps' / name / 'map.json').read_text())
                reference = json.loads((US / 'data/maps' / name / 'map.json').read_text())
                if name == 'SafariZone_Southeast':
                    reference['bg_events'][1].update(x=35, y=32, elevation=3)
                elif name == 'Route110_TrickHousePuzzle4':
                    reference['object_events'][5].update(x=1, y=10)
                    extra = copy.deepcopy(reference['object_events'][5])
                    extra.update(x=12, y=5, flag='FLAG_TEMP_1B')
                    reference['object_events'].append(extra)
                self.assertEqual(current, reference)

    def test_two_regional_event_owners_match_rom_not_us_coordinates(self):
        linked = verifier._linked_elf_symbol_addresses()
        for name in ('SafariZone_Southeast', 'Route110_TrickHousePuzzle4'):
            with self.subTest(map=name):
                start_set = linked[name + '_ObjectEvents']
                end_set = linked[name + '_MapEvents']
                self.assertEqual(len(start_set), 1)
                self.assertEqual(len(end_set), 1)
                start = next(iter(start_set))
                end = next(iter(end_set)) + 20
                source = ('#include "constants/trainer_types.h"\n'
                          '#include "constants/event_bg.h"\n' +
                          (ROOT / 'data/maps' / name / 'events.inc').read_text())
                expected = emitter.ROM[start - verifier.ROM_BASE:end - verifier.ROM_BASE]
                self.assertEqual(verifier.assemble_candidate(source, start), expected)

    def test_tutor_menu_uses_real_constants_and_table_waitstate(self):
        source = self.jp['BattleFrontier_Lounge7']
        self.assertEqual(source.count('\tspecial ShowScrollableMultichoice\n'), 4)
        self.assertEqual(source.count('case MULTI_B_PRESSED,'), 4)
        self.assertIn('fadescreen FADE_TO_BLACK', source)
        self.assertNotIn('special_no_wait ShowScrollableMultichoice', source)
        self.assertNotRegex(source, r'(?m)^\s*setvar VAR_0x8006,')
        self.assertRegex((ROOT / 'include/constants/script_menu.h').read_text(),
                         r'#define\s+MULTI_B_PRESSED\s+127\b')
        self.assertRegex((ROOT / 'data/specials.inc').read_text(),
                         r'def_special ShowScrollableMultichoice,\s*waitstate=1')


if __name__ == '__main__':
    unittest.main()
