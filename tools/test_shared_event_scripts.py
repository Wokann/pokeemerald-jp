"""Whole-owner guards for the shared EventScript tail and reviewed JP differences."""

from collections import Counter
import hashlib
from pathlib import Path
import re
import unittest

import verify_generated_map_scripts as verifier
from test_dungeon_map_scripts import instruction_lines, parallel_movements, source_lines
from test_remaining_map_scripts import control_flow_keys, serial_keys


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / 'pokeemerald'
START = 0x082423AF
END = 0x082772F0
REGION_SHA256 = '249735fde24062971345fa30011f7cdd99785f625f9ca51f5438b686adada9d4'
ORDER_SHA256 = 'a0b40bfcc02fcaa56907998f92339bcd54c911a06f2af7c71b6a99c4393b902d'
# ContestPainting's context-verified STR_VAR names encode the same FD 02/03/04 bytes.
# Fan Club's seven reporter texts use STR_VAR_1/2, still the same FD 02/03 bytes.
# The caption regression and whole-tail ROM comparison also guard emitted bytes.
LITERAL_SHA256 = '1117a4c9f8f59c840e0b43b87a046ba89b5950cc36959b14781aef7e99d2b31b'
MARKER = '.include "data/scripts/std_msgbox.inc"'
TOP = (ROOT / 'data/event_scripts.s').read_text(encoding='utf-8')
TAIL = TOP[TOP.index(MARKER):]
PATHS = tuple(re.findall(r'^\s*\.include "([^"]+)"', TAIL, re.M))


def commands(source):
    # Ignore actual C-style comments, not command-like text inside them.
    source = re.sub(r'/\*.*?\*/', '', source, flags=re.S)
    return [re.sub(r'\s+', ' ', re.sub(r',\s*', ', ', line))
            for line in instruction_lines(source)
            if not line.startswith(('.braille ', '.globl '))]


def jp_reference_commands(path, source):
    """Document regional behavior explicitly instead of silently accepting differences."""
    if path == 'data/scripts/obtain_item.inc':
        source, count = re.subn(r'bufferitemnameplural ([^,\n]+), ([^,\n]+), [^\n]+',
                               r'bufferitemname \1, \2', source)
        assert count == 7
    elif path == 'data/scripts/prof_birch.inc':
        old = '\tgoto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex\n'
        assert source.count(old) == 1
        source = source.replace(old, '')
    elif path == 'data/scripts/berry_tree.inc':
        source, count = re.subn(r'^\s*special ObjectEventInteractionGetBerry(?:CountString|Name)\n',
                               '', source, flags=re.M)
        assert count == 8
    elif path == 'data/scripts/cable_club.inc':
        old = '\tplayse SE_PIN\n\tdelay 60\n\tmessage CableClub_Text_HopeToSeeYouAgain\n'
        assert source.count(old) == 1
        source = source.replace(old, '\tplayse SE_PIN\n\tmessage CableClub_Text_HopeToSeeYouAgain\n')
        source, count = re.subn(r'(MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected::?\n)'
                               r'\tdelay 60\n', r'\1', source)
        assert count == 1
        for old in ('\tspecial ValidateMixingGameLanguage\n',
                    '\tgoto_if_eq VAR_RESULT, LINKUP_FOREIGN_GAME, '
                    'CableClub_EventScript_AbortLinkForeignGame\n'):
            assert source.count(old) == 1
            source = source.replace(old, '')
        source, count = re.subn(r'^CableClub_EventScript_AbortLinkForeignGame::?\n.*?'
                               r'(?=^[A-Za-z_]\w*::?\n)', '', source, flags=re.M | re.S)
        assert count == 1
    elif path == 'data/text/cable_club.inc':
        old = 'CableClub_Text_CantMixWithJapaneseGame:\n'
        assert source.count(old) == 1
        source = source.replace(old, '')
    elif path == 'data/scripts/contest_hall.inc':
        old = 'buffercontestname STR_VAR_2, VAR_0x8008'
        assert source.count(old) == 1
        source = source.replace(old, 'bufferstdstring STR_VAR_2, VAR_0x8008')
    elif path == 'data/scripts/players_house.inc':
        old = 'playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL'
        assert source.count(old) == 2
        source = source.replace(old, 'playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL')
    elif path == 'data/scripts/berry_blender.inc':
        old = 'special SpawnLinkPartnerObjectEvent'
        assert source.count(old) == 1
        source = source.replace(old, 'special SpawnLinkPartnerEventObject')
    elif path == 'data/scripts/safari_zone.inc':
        source, count = re.subn(r'^#ifdef BUGFIX\n\treleaseall[^\n]*\n#endif\n',
                               '', source, flags=re.M)
        assert count == 1
    elif path == 'data/scripts/battle_pike.inc':
        for suffix in (0, 1):
            old = '\tsetvar VAR_OBJ_GFX_ID_%d, OBJ_EVENT_GFX_LINK_RECEPTIONIST\n' % suffix
            assert source.count(old) == 1
            source = source.replace(old, '')
    elif path == 'data/text/frontier_brain.inc':
        source += '\n.align 2\n'
    return commands(source)


@unittest.skipUnless((US / 'data/event_scripts.s').exists(), 'US reference checkout required')
class SharedEventScriptsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.sources = {path: (ROOT / path).read_text(encoding='utf-8') for path in PATHS}

    def test_complete_tail_keeps_physical_owner_order_without_hidden_raw(self):
        self.assertEqual(len(PATHS), 112)
        self.assertEqual(PATHS[0], 'data/scripts/std_msgbox.inc')
        self.assertEqual(PATHS[-1], 'data/text/birch_speech.inc')
        self.assertEqual(hashlib.sha256('\n'.join(PATHS).encode()).hexdigest(), ORDER_SHA256)
        for path, source in self.sources.items():
            with self.subTest(owner=path):
                self.assertNotRegex(source, r'(?m)^\s*\.incbin\b')
                self.assertNotRegex(source, r'(?m)^\s*\.set[^\n]*0x08[0-9A-Fa-f]{6}\b')
                self.assertNotRegex(source, r'\{(?:STRING|ESCAPE)\s')
        self.assertNotIn('.incbin', TAIL)

    def test_all_included_jp_literals_keep_original_controls_and_braille_transcription(self):
        literals = '\n'.join('\n'.join(raw.strip() for raw in source.splitlines()
                                      if raw.lstrip().startswith(('.string ', '.braille ')))
                             for source in self.sources.values())
        self.assertEqual(len(literals.splitlines()), 12284)
        self.assertEqual(hashlib.sha256(literals.encode()).hexdigest(), LITERAL_SHA256)

    def test_tv_retains_requested_report_level_owners_not_one_us_monolith(self):
        tv_paths = [path for path in PATHS if path.startswith('data/text/tv/')]
        self.assertEqual(len(tv_paths), 32)
        self.assertNotIn('data/text/tv.inc', PATHS)
        self.assertIn('data/text/tv/contest_interview.inc', tv_paths)
        self.assertIn('data/text/tv/battle_tower_broadcast.inc', tv_paths)
        self.assertEqual(tv_paths[-1], 'data/text/tv/pokemon_news.inc')

    def test_each_us_owner_matches_only_the_explicit_regional_exceptions(self):
        matched = 0
        for path, source in self.sources.items():
            reference = US / path
            if not reference.is_file():
                self.assertTrue(path.startswith('data/text/tv/'))
                continue
            with self.subTest(owner=path):
                self.assertEqual(commands(source), jp_reference_commands(path, reference.read_text()))
            matched += 1
        self.assertEqual(matched, 80)

    def test_all_149_serial_helpers_preserve_parallel_actor_groups(self):
        total = 0
        for path, source in self.sources.items():
            reference = US / path
            if not reference.is_file():
                continue
            expected = reference.read_text()
            with self.subTest(owner=path):
                self.assertEqual(serial_keys(source), serial_keys(expected))
                total += sum(serial_keys(source).values())
                self.assertEqual(parallel_movements(re.sub(r'\b0x0+\b', '0', source)),
                                 parallel_movements(re.sub(r'\b0x0+\b', '0', expected)))
        reference_top = (US / 'data/event_scripts.s').read_text()
        reference_tail = reference_top[reference_top.index(MARKER):]
        self.assertEqual(serial_keys(TAIL), serial_keys(reference_tail))
        total += sum(serial_keys(TAIL).values())
        self.assertEqual(total, 149)

    def test_three_complete_switch_groups_match_us_macro_use(self):
        total = Counter()
        for path in ('data/scripts/obtain_item.inc', 'data/scripts/pc.inc',
                     'data/scripts/set_gym_trainers.inc'):
            source = self.sources[path]
            with self.subTest(owner=path):
                self.assertEqual(control_flow_keys(source), control_flow_keys((US / path).read_text()))
                total.update(line.split()[0] for line in source_lines(source, False)
                             if line.startswith(('switch ', 'case ')))
        self.assertEqual(total, {'switch': 3, 'case': 18})
        self.assertNotIn('ITEM_TYPE', self.sources['data/scripts/obtain_item.inc'])
        self.assertEqual(sum(line.startswith('bufferitemname ') for line in
                             source_lines(self.sources['data/scripts/obtain_item.inc'], False)), 7)

    def test_vigoroth_objects_keep_the_actual_jp_machoke_cry_operand(self):
        source = self.sources['data/scripts/players_house.inc']
        self.assertEqual(source.count('playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL'), 2)
        species = (ROOT / 'include/constants/species.h').read_text()
        self.assertRegex(species, r'#define\s+SPECIES_MACHOKE\s+67\b')
        self.assertRegex(species, r'#define\s+SPECIES_VIGOROTH\s+365\b')
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for offset in (0x2582A7, 0x2582BA):
            self.assertEqual(rom[offset:offset + 5], bytes.fromhex('A1 43 00 00 00'))

    def test_entire_tail_matches_rom_and_stops_at_the_next_script_data_object(self):
        source = re.sub(r'^\s*\.include "([^"]+)"\s*$',
                        lambda match: self.sources[match[1]], TAIL, flags=re.M)
        expected = (ROOT / 'baserom_jp.gba').read_bytes()[START - verifier.ROM_BASE:
                                                       END - verifier.ROM_BASE]
        self.assertEqual(len(expected), 216897)
        self.assertEqual(hashlib.sha256(expected).hexdigest(), REGION_SHA256)
        self.assertEqual(verifier.assemble_candidate(source, START), expected)
        linked = verifier._linked_elf_symbol_addresses()
        self.assertEqual(linked['Std_MsgboxNPC'], frozenset({START}))
        self.assertEqual(linked['gMovesWithQuietBGM'], frozenset({END}))


if __name__ == '__main__':
    unittest.main()
