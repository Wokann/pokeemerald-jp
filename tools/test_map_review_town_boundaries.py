"""Shared sibling boundaries and alternate C objects require explicit evidence."""
import copy
import json
from pathlib import Path
import re
import tempfile
import unittest
from unittest.mock import patch
try:
    import audit_structure as audit
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import audit_structure as audit
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]


class SharedBoundaryTests(unittest.TestCase):
    def setUp(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        directory = tempfile.TemporaryDirectory(prefix='shared-include-boundary-', dir=parent)
        self.addCleanup(directory.cleanup)
        self.root = Path(directory.name)
        (self.root / 'data/scripts').mkdir(parents=True)
        (self.root / 'data/scripts/first.inc').write_text('First::\nend\n')
        (self.root / 'data/scripts/second.inc').write_text('Second::\nend\n')
        self.source = ('Helper::\nclearflag FLAG_DONT_TRANSITION_MUSIC\nfadedefaultbgm\nreturn\n'
                       '.include "data/scripts/first.inc"\n.include "data/scripts/second.inc"\n')
        (self.root / 'data/event_scripts.s').write_text(self.source)
        self.dep = dict(path='data/event_scripts.s', entry='Helper', labels=['Helper'],
                        end_before_includes=['data/scripts/first.inc', 'data/scripts/second.inc'])

    def test_only_explicit_shared_context_clips_pure_terminal_sibling_tail(self):
        block = review.shared_script_blocks(self.root, self.dep)['Helper']
        p = profile.profile_block(self.root, block, {}, version=4, address=0x08243134)
        self.assertEqual(p.size, 5)
        self.assertEqual(review.shared_include_entry(self.root, self.dep), 'First')
        claim = dict(path='data/event_scripts.s', selector='asm_labels', labels=['Helper'])
        self.assertIn(b'.include "data/scripts/second.inc"', review.source_payload(self.root, claim))
        self.assertNotIn('.include', block)
        unbounded = dict(self.dep)
        del unbounded['end_before_includes']
        with self.assertRaises(ValueError):
            profile.profile_block(self.root, review.shared_script_blocks(self.root, unbounded)['Helper'], {},
                                  version=4, address=0x08243134)
        with self.assertRaises(ValueError):
            profile.profile_owner(self.root, self.source, {}, version=4, address=0x08243134)

    def test_map_context_unknown_paths_and_incomplete_or_reordered_tails_fail(self):
        for boundaries in ([], 'data/scripts/first.inc', ['../first.inc'], ['/tmp/first.inc'],
                           ['data/maps/First/scripts.inc'], ['data/scripts/first.inc'] * 2,
                           ['data/scripts/first.inc'],
                           ['data/scripts/second.inc', 'data/scripts/first.inc']):
            dep = dict(self.dep, end_before_includes=boundaries)
            with self.subTest(boundaries=boundaries), self.assertRaises(ValueError):
                review.shared_script_blocks(self.root, dep)
        with self.assertRaisesRegex(ValueError, 'invalid_shared_include_boundary'):
            review.shared_script_blocks(self.root, dict(self.dep, path='data/maps/First/scripts.inc'))

    def test_unterminated_body_or_extra_bytes_cannot_be_hidden_at_boundary(self):
        path = self.root / 'data/event_scripts.s'
        for source in (self.source.replace('return\n', 'goto Target\n'),
                       self.source.replace('return\n', 'return\n.byte 0\n'),
                       self.source + '.incbin "baserom_jp.gba", 0, 2\n'):
            path.write_text(source)
            with self.subTest(source=source), self.assertRaises(ValueError):
                review.shared_script_blocks(self.root, self.dep)
        path.write_text(self.source)
        (self.root / 'data/scripts/first.inc').write_text('.byte 0\nFirst::\nend\n')
        with self.assertRaisesRegex(ValueError, 'nonempty_shared_include_prefix'):
            review.shared_script_blocks(self.root, self.dep)


class TownClosureTests(unittest.TestCase):
    def batch(self, name):
        rows = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())['batches']
        selected = [row for row in rows if name in row['maps'] and row['review_type'] == 'direct_map_v4']
        self.assertEqual(len(selected), 1)
        return selected[0]

    def test_measured_town_commands_keep_v4_arity_and_types(self):
        cases = [('multichoice 20, 8, MULTI_HOWS_FISHING, TRUE', 5),
                 ('multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE', 6),
                 ('setobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN, 0', 6),
                 ('resetobjectsubpriority LOCALID_PLAYER, MAP_DEWFORD_TOWN', 5),
                 ('showobjectat LOCALID_PLAYER, MAP_ROUTE104', 5),
                 ('incrementgamestat GAME_STAT_STARTED_TRENDS', 2), ('getpartysize', 1),
                 ('giveegg SPECIES_WYNAUT', 3), ('fadescreen FADE_TO_BLACK', 2),
                 ('call_if_ne VAR_0x8008, 9, Target', 11)]
        for source, size in cases:
            with self.subTest(source=source):
                p = profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E4C57)
                self.assertEqual(p.size, size)
                with self.assertRaises(ValueError):
                    profile.profile_block(ROOT, 'Owner::\n' + source, {})
        for source in ('multichoice 20, 8, MULTI_HOWS_FISHING', 'giveegg', 'getpartysize 1',
                       'call_if_ne 0x8008, 9, Target', 'call_if_ne VAR_0x8008, 9, 0x08123456'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E4C57)
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms(
                [s for s, _ in cases] + ['walk_faster_left', 'walk_fast_down'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_three_physical_owners_and_local_texts_remain_byte_exact(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, following, count, size, texts in [('OldaleTown', 'DewfordTown', 53, 1237, 10),
                                                  ('DewfordTown', 'LavaridgeTown', 61, 2571, 26),
                                                  ('LavaridgeTown', 'FallarborTown', 60, 2049, 19)]:
            blocks = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())
            parts = profile.profile_owner(ROOT, ''.join(blocks.values()), version=4,
                                          address=next(iter(symbols[name + '_MapScripts'])))
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertEqual(sum(p.kind == 'string' for p in parts.values()), texts)
            labels = list(parts)
            for i, label in enumerate(labels):
                start = next(iter(symbols[label]))
                stop = next(iter(symbols[labels[i + 1] if i + 1 < len(labels) else following + '_MapScripts']))
                self.assertEqual(parts[label].size, stop - start, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, blocks[label], 'string'),
                                     rom[start - 0x08000000:stop - 0x08000000], label)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_complete_shared_closures_compile_actual_forms_without_sibling_bytes(self):
        for name, count in [('OldaleTown', 131), ('DewfordTown', 159), ('LavaridgeTown', 177)]:
            sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text()]
            for dep in self.batch(name)['shared_dependencies']:
                blocks = review.shared_script_blocks(ROOT, dep)
                sources.extend(blocks[label] for label in dep['labels'])
            samples = {line for source in sources for block in review.label_blocks(source).values()
                       if review.text_kind(block) is None for line in review.statements(block)}
            self.assertEqual(len(samples), count)
            native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    def test_facing_direction_uses_real_make_variant_not_an_imaginary_tail_source(self):
        batch = self.batch('LavaridgeTown')
        contract = next(c for c in batch['special_contracts'] if c['entry'] == 'GetPlayerFacingDirection')
        self.assertEqual(contract['source_path'], 'src/field_player_avatar.c')
        self.assertEqual(review.special_input_object(ROOT, contract), 'src/field_player_avatar_tail.o')
        for key, value in [('defines', {}), ('input_object', 'src/field_player_avatar.o'),
                           ('source_owner', 'field_player_avatar_tail.c')]:
            broken = copy.deepcopy(contract)
            broken['compile_variant'][key] = value
            with self.subTest(key=key), self.assertRaises(ValueError):
                review.special_input_object(ROOT, broken)
        missing = copy.deepcopy(batch)
        missing['sources'] = [s for s in missing['sources'] if s['path'] != 'Makefile' or s['selector'] != 'file']
        with self.assertRaisesRegex(ValueError, 'missing_special_compile_variant_source'):
            review._review_batch(ROOT, missing, {'LavaridgeTown'}, {})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_declared_include_boundary_must_match_both_real_native_symbol_tables(self):
        batch, native = self.batch('DewfordTown'), {}
        review._review_batch(ROOT, batch, {'DewfordTown'}, native)
        for table in ('symbols', 'map_symbols'):
            broken = copy.deepcopy(native)
            broken[table]['ProfBirch_EventScript_UpdateLocation'] = {0x0824313A}
            result = review._review_batch(ROOT, batch, {'DewfordTown'}, broken)
            self.assertIn('native_shared_include_boundary_mismatch:Common_EventScript_StopBrineysBoatMusic',
                          result['errors'])
        for dep in batch['shared_dependencies']:
            for path in dep.get('end_before_includes', []):
                missing = copy.deepcopy(batch)
                missing['sources'] = [s for s in missing['sources'] if s['path'] != path or s['selector'] != 'file']
                with self.subTest(path=path), self.assertRaisesRegex(ValueError, 'missing_shared_include_boundary_source'):
                    review._review_batch(ROOT, missing, {'DewfordTown'}, {})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_alternate_special_owner_requires_actual_object_function_evidence(self):
        with patch.object(audit, 'elf_object_functions', return_value=[]):
            result = review._review_batch(ROOT, self.batch('LavaridgeTown'), {'LavaridgeTown'}, {})
        self.assertIn('native_special_variant_object_mismatch:GetPlayerFacingDirection', result['errors'])
        real = audit.elf_object_functions
        def wrong_offset(data):
            return [(name, section, offset + (name == 'GetPlayerFacingDirection'), size, section_size)
                    for name, section, offset, size, section_size in real(data)]
        with patch.object(audit, 'elf_object_functions', side_effect=wrong_offset):
            result = review._review_batch(ROOT, self.batch('LavaridgeTown'), {'LavaridgeTown'}, {})
        self.assertIn('native_special_variant_object_mismatch:GetPlayerFacingDirection', result['errors'])

    def test_oldale_temp_gate_and_west_exit_state_are_not_dead_code(self):
        metadata = json.loads((ROOT / 'data/maps/OldaleTown/map.json').read_text())
        self.assertIn(('VAR_OLDALE_TOWN_STATE', '0', 'OldaleTown_EventScript_BlockedPath'),
                      {(e['var'], e['var_value'], e['script']) for e in metadata['coord_events']})
        blocks = review.label_blocks((ROOT / 'data/maps/OldaleTown/scripts.inc').read_text())
        self.assertIn('setvar VAR_OLDALE_TOWN_STATE, 1', blocks['OldaleTown_EventScript_SetOldaleState'])
        entry = review.statements(blocks['OldaleTown_EventScript_MartEmployee'])
        self.assertLess(entry.index('goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion'),
                        entry.index('setflag FLAG_TEMP_1'))
        give = review.statements(blocks['OldaleTown_EventScript_ExplainPokemonMart'])
        self.assertLess(give.index('goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull'),
                        give.index('setflag FLAG_RECEIVED_POTION_OLDALE'))
        self.assertNotIn('clearflag FLAG_TEMP_1', blocks['OldaleTown_EventScript_BagIsFull'])
        self.assertNotIn('setflag FLAG_RECEIVED_POTION_OLDALE', blocks['OldaleTown_EventScript_BagIsFull'])

    def test_dewford_menus_and_modal_trend_handoff_keep_their_original_results(self):
        blocks = review.label_blocks((ROOT / 'data/maps/DewfordTown/scripts.inc').read_text())
        self.assertIn('multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE',
                      blocks['DewfordTown_EventScript_Briney'])
        self.assertIn('case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect',
                      blocks['DewfordTown_EventScript_Briney'])
        self.assertIn('multichoice 20, 8, MULTI_HOWS_FISHING, TRUE', blocks['DewfordTown_EventScript_HowsFishing'])
        menus = (ROOT / 'src/data/script_menu.h').read_text()
        for name, expected in [('BrineyOnDewford', ['gText_Petalburg', 'gText_Slateport', 'gText_Cancel2']),
                               ('HowsFishing', ['gText_Excellent2', 'gText_NotSoGood'])]:
            body = re.search(r'MultichoiceList_' + name + r'\[\]\s*=\s*\{(.*?)\};', menus, re.S)
            self.assertIsNotNone(body)
            self.assertEqual(re.findall(r'\{(gText_\w+)\}', body[1]), expected)
        give = review.statements(blocks['DewfordTown_EventScript_GiveOldRod'])
        self.assertEqual(give[give.index('giveitem ITEM_OLD_ROD') + 1], 'setflag FLAG_RECEIVED_OLD_ROD')
        trend = review.statements(blocks['DewfordTown_EventScript_GiveNewTrendyPhrase'])
        self.assertLess(trend.index('incrementgamestat GAME_STAT_STARTED_TRENDS'),
                        trend.index('goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough'))
        common = review.label_blocks((ROOT / 'data/event_scripts.s').read_text())['Common_ShowEasyChatScreen']
        self.assertEqual(review.statements(common), ['fadescreen FADE_TO_BLACK', 'special ShowEasyChatScreen',
                                                     'fadescreen FADE_FROM_BLACK', 'return'])
        self.assertEqual(profile.special_waits(ROOT)['ShowEasyChatScreen'], 0)

    def test_lavaridge_egg_checks_party_and_hot_spring_checks_facing_not_bag_space(self):
        blocks = review.label_blocks((ROOT / 'data/maps/LavaridgeTown/scripts.inc').read_text())
        egg = review.statements(blocks['LavaridgeTown_EventScript_EggWoman'])
        self.assertLess(egg.index('getpartysize'),
                        egg.index('goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg'))
        self.assertLess(egg.index('setflag FLAG_RECEIVED_LAVARIDGE_EGG'), egg.index('giveegg SPECIES_WYNAUT'))
        self.assertNotIn('checkitemspace', '\n'.join(egg))
        for gender in ('May', 'Brendan'):
            give = review.statements(blocks['LavaridgeTown_EventScript_' + gender + 'GiveGoGoggles'])
            self.assertEqual(give[give.index('giveitem ITEM_GO_GOGGLES') + 1], 'setflag FLAG_RECEIVED_GO_GOGGLES')
        metadata = json.loads((ROOT / 'data/maps/LavaridgeTown/map.json').read_text())
        self.assertEqual([(e['x'], e['y'], e['var']) for e in metadata['coord_events']],
                         [(6, 3, 'TRIGGER_RUN_IMMEDIATELY')])
        self.assertIn('goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings',
                      blocks['LavaridgeTown_EventScript_HotSpringsTrigger'])


if __name__ == '__main__':
    unittest.main()
