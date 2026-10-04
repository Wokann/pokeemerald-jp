#!/usr/bin/env python3
"""Contracts for the complete, ROM-ordered Ever Grande League map family."""
import json
import re
import sys
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))

import jp_emit_maps as emitter  # noqa: E402
from test_jp_emit_maps import render_map  # noqa: E402


MAPS = (
    'EverGrandeCity_SidneysRoom', 'EverGrandeCity_PhoebesRoom',
    'EverGrandeCity_GlaciasRoom', 'EverGrandeCity_DrakesRoom',
    'EverGrandeCity_ChampionsRoom',
    *(f'EverGrandeCity_Hall{i}' for i in range(1, 6)),
    'EverGrandeCity_PokemonLeague_1F', 'EverGrandeCity_HallOfFame',
    'EverGrandeCity_PokemonCenter_1F', 'EverGrandeCity_PokemonCenter_2F',
    'EverGrandeCity_PokemonLeague_2F',
)
TEXT_COUNTS = (3, 3, 3, 3, 13, 0, 0, 0, 0, 0, 3, 2, 3, 0, 0)


def normalize(source):
    return re.sub(r'\b0x([0-9A-Fa-f]+)\b',
                  lambda match: str(int(match.group(1), 16)), source)


def code_lines(source):
    lines = []
    for raw in normalize(source).splitlines():
        line = raw.partition('@')[0].strip()
        if not line or line.startswith('.string'):
            continue
        lines.append(re.sub(r':{1,2}$', ':', line))
    return lines


class LeagueMapScriptTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.generated = {name: render_map(name) for name in MAPS}
        cls.reference = {
            name: (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
            for name in MAPS
        }

    def test_complete_family_names_texts_and_json_survive_regeneration(self):
        pattern = r'^(\w+):{1,2}[^\n]*\n((?:\t\.string [^\n]*\n)+)'
        total = 0
        for name, count in zip(MAPS, TEXT_COUNTS):
            with self.subTest(map=name):
                source = self.generated[name]
                checked = (ROOT / 'data/maps' / name / 'scripts.inc').read_text(
                    encoding='utf-8')
                self.assertEqual(re.findall(r'^(\w+):{1,2}', source, re.M),
                                 re.findall(r'^(\w+):{1,2}', self.reference[name], re.M))
                texts = re.findall(pattern, source, re.M)
                self.assertEqual(len(texts), count)
                self.assertEqual(texts, re.findall(pattern, checked, re.M))
                total += len(texts)
                for temporary in ('.incbin', '.set ', 'MapScriptTable_',
                                  'gJPText_', '{STRING ', '{ESCAPE '):
                    self.assertNotIn(temporary, source)
                self.assertEqual(
                    json.loads((ROOT / 'data/maps' / name / 'map.json').read_text(
                        encoding='utf-8')),
                    json.loads((emitter.US_MAPS / name / 'map.json').read_text(
                        encoding='utf-8')))
        self.assertEqual(total, 33)

    def test_whole_family_code_matches_us_except_proven_jp_guard_delay(self):
        for name in MAPS:
            with self.subTest(map=name):
                expected = code_lines(self.reference[name])
                if name == 'EverGrandeCity_PokemonLeague_1F':
                    self.assertEqual(expected.count('delay 120'), 1)
                    expected[expected.index('delay 120')] = 'delay 75'
                self.assertEqual(code_lines(self.generated[name]), expected)

    def test_twenty_local_and_two_shared_sequential_helpers_match_us(self):
        counts = {
            'EverGrandeCity_ChampionsRoom': 14,
            'EverGrandeCity_PokemonLeague_1F': 4,
            'EverGrandeCity_PokemonCenter_1F': 2,
        }
        for name in MAPS:
            with self.subTest(map=name):
                self.assertEqual(self.generated[name].count('\tapplywaitmovement '),
                                 counts.get(name, 0))
        shared = (ROOT / 'data/scripts/elite_four.inc').read_text(encoding='utf-8')
        reference = (emitter.US_MAPS.parent / 'scripts/elite_four.inc').read_text(
            encoding='utf-8')
        self.assertEqual(shared.count('\tapplywaitmovement '), 2)
        self.assertNotIn('\tapplymovement ', shared)
        self.assertEqual(code_lines(shared), code_lines(reference))

    def test_five_hall_names_are_bound_to_actual_jp_tables(self):
        for name, table in emitter.MAP_VERIFIED_LEAGUE_HALL_TABLES.items():
            with self.subTest(map=name):
                start = table - 6
                self.assertEqual(emitter.ROM[start - 0x08000000:table - 0x08000000],
                                 b'\x04' + table.to_bytes(4, 'little') + b'\0')
                self.assertEqual(emitter.parse_frame_table(table),
                                 [(0x4001, 0, table + 10)])
                self.assertIn(name + '_OnWarp: @ 0x%08X\n' % table,
                              self.generated[name])
                self.assertIn('\tmap_script_2 VAR_TEMP_1, 0, ' + name
                              + '_EventScript_TurnPlayerNorth\n\t.2byte 0\n',
                              self.generated[name])
                self.assertIn('\tturnobject LOCALID_PLAYER, DIR_NORTH\n\tend\n',
                              self.generated[name])

    def test_parallel_champion_guard_and_hall_of_fame_movements_are_not_collapsed(self):
        expected = {
            'EverGrandeCity_ChampionsRoom': [4, 2],
            'EverGrandeCity_PokemonLeague_1F': [2],
            'EverGrandeCity_HallOfFame': [2, 2, 2, 2, 2],
        }
        for name in MAPS:
            for tag, source in (('JP generated', self.generated[name]),
                                ('US reference', self.reference[name])):
                with self.subTest(map=name, source=tag):
                    groups = re.findall(
                        r'((?:\tapplymovement [^\n]+\n)+)\twaitmovement 0\n', source)
                    self.assertEqual([group.count('\tapplymovement ') for group in groups],
                                     expected.get(name, []))

    def test_elite_four_state_progression_and_intentionally_unused_entries_survive(self):
        for state, member in enumerate(('Sidney', 'Phoebe', 'Glacia', 'Drake')):
            name = 'EverGrandeCity_' + member + 'sRoom'
            source = normalize(self.generated[name])
            with self.subTest(map=name):
                self.assertIn('\tmap_script_2 VAR_ELITE_4_STATE, ' + str(state)
                              + ', ' + name + '_EventScript_WalkInCloseDoor\n', source)
                self.assertIn('\tcall PokemonLeague_EliteFour_EventScript_WalkInCloseDoor\n'
                              '\tsetvar VAR_ELITE_4_STATE, ' + str(state + 1) + '\n', source)
                self.assertIn('\tcall_if_set FLAG_DEFEATED_ELITE_4_' + member.upper()
                              + ', ' + name + '_EventScript_ResetAdvanceToNextRoom\n', source)
                self.assertIn('\tgoto ' + name + '_EventScript_Defeated\n\tend\n', source)
        drake = self.generated['EverGrandeCity_DrakesRoom']
        self.assertIn('\tmap_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, '
                      'EverGrandeCity_SidneysRoom_OnWarp\n', drake)
        self.assertIn('EverGrandeCity_DrakesRoom_OnWarp::', drake)
        for name in MAPS[-2:]:
            for wrapper in ('Colosseum', 'TradeCenter', 'RecordCorner'):
                self.assertRegex(self.generated[name], name + '_EventScript_' + wrapper
                                 + r':{1,2}[^\n]*\n\tcall CableClub_EventScript_'
                                 + wrapper + '\n\tend\n')

    def test_hall_of_fame_gender_respawns_implicit_wait_and_postgame_flags_survive(self):
        name = 'EverGrandeCity_HallOfFame'
        source = normalize(self.generated[name])
        for gender, house in (('Male', 'BRENDANS'), ('Female', 'MAYS')):
            self.assertRegex(source, name + '_EventScript_GameClear' + gender
                             + r':{1,2}[^\n]*\n\tsetrespawn HEAL_LOCATION_LITTLEROOT_TOWN_'
                             + house + '_HOUSE_2F\n\tfadescreenspeed FADE_TO_BLACK, 24\n'
                             '\tspecial GameClear\n\treleaseall\n\tend\n')
        specials = (ROOT / 'data/specials.inc').read_text(encoding='utf-8')
        self.assertRegex(specials, r'(?m)^\s*def_special GameClear,\s*waitstate=1\s*$')
        shared = (ROOT / 'data/scripts/hall_of_fame.inc').read_text(encoding='utf-8')
        reference = (emitter.US_MAPS.parent / 'scripts/hall_of_fame.inc').read_text(
            encoding='utf-8')
        self.assertEqual(code_lines(shared), code_lines(reference))
        self.assertIn('\tcall ' + name + '_EventScript_ResetEliteFour\n', shared)
        for legendary in ('MEW', 'LATIAS_OR_LATIOS', 'DEOXYS', 'LUGIA', 'HO_OH'):
            self.assertIn('\tclearflag FLAG_DEFEATED_' + legendary + '\n', shared)


if __name__ == '__main__':
    unittest.main()
