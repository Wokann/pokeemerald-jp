"""Contiguous Ever Grande/Littleroot review includes the full intro scene."""
import json
from pathlib import Path
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]
MOVEMENTS = ('walk_fast_left', 'jump_right', 'jump_in_place_right',
             'disable_jump_landing_ground_effect')


class LittlerootStoryTests(unittest.TestCase):
    def test_intro_forms_require_v4_and_keep_exact_arity_and_termination(self):
        for source, size, kind in [('hideplayer', 5, 'script')] + [
                (op + '\nstep_end', 2, 'movement') for op in MOVEMENTS]:
            with self.subTest(source=source):
                p = profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E39F5)
                self.assertEqual((p.size, p.kind), (size, kind))
                with self.assertRaises(ValueError):
                    profile.profile_block(ROOT, 'Owner::\n' + source, {})
        for source in ('hideplayer 1', 'hideplayer\nstep_end', 'jump_right',
                       'jump_right 1\nstep_end', 'walk_fast_left\nend',
                       'disable_jump_landing_ground_effect\nstep_end\nstep_end\nstep_end'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E39F5)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_intro_forms_use_real_macro_expansion(self):
        native_forms.StoryProfileTests().check_native_forms(['hideplayer', *MOVEMENTS], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_every_local_label_and_text_closes_its_actual_native_owner(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, next_map, count, size, texts in [('EverGrandeCity', 'LittlerootTown', 9, 124, 3),
                                                  ('LittlerootTown', 'OldaleTown', 130, 3469, 18)]:
            source = (ROOT / f'data/maps/{name}/scripts.inc').read_text()
            blocks = review.label_blocks(source)
            parts = profile.profile_owner(ROOT, source, version=4,
                                          address=next(iter(symbols[name + '_MapScripts'])))
            labels = list(parts)
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertEqual(sum(p.kind == 'string' for p in parts.values()), texts)
            for i, label in enumerate(labels):
                start = next(iter(symbols[label]))
                stop = next(iter(symbols[labels[i + 1] if i + 1 < len(labels) else next_map + '_MapScripts']))
                self.assertEqual(parts[label].size, stop - start, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, blocks[label], 'string'),
                                     rom[start - 0x08000000:stop - 0x08000000], label)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_full_recorded_script_closures_keep_actual_native_macro_sizes(self):
        batches = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())['batches']
        for name, count in [('EverGrandeCity', 17), ('LittlerootTown', 238)]:
            selected = [b for b in batches if name in b['maps'] and b['review_type'] == 'direct_map_v4']
            self.assertEqual(len(selected), 1)
            sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text()]
            for dep in selected[0]['shared_dependencies']:
                blocks = review.label_blocks((ROOT / dep['path']).read_text())
                sources.extend(blocks[label] for label in dep['labels'])
            samples = {line for source in sources for block in review.label_blocks(source).values()
                       if review.text_kind(block) is None for line in review.statements(block)}
            self.assertEqual(len(samples), count)
            native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    def test_running_shoes_keep_all_six_coordinate_entries_and_two_distinct_flags(self):
        metadata = json.loads((ROOT / 'data/maps/LittlerootTown/map.json').read_text())
        roots = [row for row in metadata['coord_events'] if 'GiveRunningShoesTrigger' in row['script']]
        self.assertEqual([(r['x'], r['y'], r['var'], r['var_value'], r['script'].rsplit('Trigger', 1)[1])
                          for r in roots], [(8, 9, 'VAR_LITTLEROOT_TOWN_STATE', '3', '4'),
                                            (9, 9, 'VAR_LITTLEROOT_TOWN_STATE', '3', '5'),
                                            (10, 9, 'VAR_LITTLEROOT_TOWN_STATE', '3', '2'),
                                            (11, 9, 'VAR_LITTLEROOT_TOWN_STATE', '3', '3'),
                                            (10, 2, 'VAR_LITTLEROOT_TOWN_STATE', '3', '0'),
                                            (11, 2, 'VAR_LITTLEROOT_TOWN_STATE', '3', '1')])
        blocks = review.label_blocks((ROOT / 'data/maps/LittlerootTown/scripts.inc').read_text())
        give = review.statements(blocks['LittlerootTown_EventScript_GiveRunningShoes'])
        self.assertLess(give.index('waitfanfare'), give.index('setflag FLAG_RECEIVED_RUNNING_SHOES'))
        self.assertNotIn('setflag FLAG_SYS_B_DASH', give)
        self.assertEqual(review.statements(blocks['LittlerootTown_EventScript_SetReceivedRunningShoes']),
                         ['removeobject LOCALID_LITTLEROOT_MOM', 'setflag FLAG_SYS_B_DASH',
                          'setvar VAR_LITTLEROOT_TOWN_STATE, 4', 'release', 'end'])

    def test_gendered_family_buffer_is_not_a_player_name(self):
        blocks = review.label_blocks((ROOT / 'data/maps/LittlerootTown/scripts.inc').read_text())
        for entry in ('LittlerootTown_EventScript_GoSaveBirch', 'LittlerootTown_EventScript_YouSavedBirch',
                      'LittlerootTown_EventScript_GoSaveBirchTrigger'):
            lines = review.statements(blocks[entry])
            self.assertLess(lines.index('special GetPlayerBigGuyGirlString'),
                            next(i for i, line in enumerate(lines) if line.startswith('msgbox ')))
        for entry in ('LittlerootTown_Text_CanYouGoSeeWhatsHappening', 'LittlerootTown_Text_YouSavedBirch'):
            self.assertIn('{STR_VAR_1}', blocks[entry])
            self.assertNotIn('{PLAYER}', blocks[entry])
        self.assertEqual(profile.special_waits(ROOT)['GetPlayerBigGuyGirlString'], 0)

    def test_evergrande_visit_flag_belongs_to_coordinate_entry_not_transition(self):
        metadata = json.loads((ROOT / 'data/maps/EverGrandeCity/map.json').read_text())
        roots = metadata['coord_events']
        self.assertEqual(len(roots), 11)
        self.assertEqual({(r['var'], r['var_value'], r['script']) for r in roots},
                         {('VAR_TEMP_1', '0', 'EverGrandeCity_EventScript_SetVisitedEverGrande')})
        blocks = review.label_blocks((ROOT / 'data/maps/EverGrandeCity/scripts.inc').read_text())
        self.assertNotIn('FLAG_VISITED_EVER_GRANDE_CITY', blocks['EverGrandeCity_OnTransition'])
        self.assertEqual(review.statements(blocks['EverGrandeCity_EventScript_SetVisitedEverGrande']),
                         ['setflag FLAG_VISITED_EVER_GRANDE_CITY', 'setvar VAR_TEMP_1, 1', 'end'])


if __name__ == '__main__':
    unittest.main()
