"""Complete city scenes keep measured warps, state comparisons and layout spans."""
import copy
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


class SootopolisSceneTests(unittest.TestCase):
    def test_warp_and_camera_forms_remain_explicit_v4(self):
        cases = [('setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6', 8),
                 ('warpsilent MAP_SOOTOPOLIS_CITY, 31, 34', 8),
                 ('warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32', 8),
                 ('turnobject LOCALID_PLAYER, DIR_NORTH', 4),
                 ('fadescreenspeed FADE_TO_BLACK, 1', 3), ('fadenewbgm MUS_SOOTOPOLIS', 3), ('doweather', 1)]
        for source, size in cases:
            p = profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E1CF6)
            self.assertEqual(p.size, size)
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {})
        for op in ('goto_if_ge', 'goto_if_le', 'goto_if_ne'):
            p = profile.profile_block(ROOT, 'Owner::\n' + op + ' VAR_SOOTOPOLIS_CITY_STATE, 6, Target', {},
                                      version=4, address=0x081E1CF6)
            self.assertEqual((p.size, p.targets), (11, {'Target': 'script'}))
        for source in ('warpsilent 0x0007, 31, 34', 'setdivewarp MAP_SOOTOPOLIS_CITY',
                       'warpwhitefade MAP_SOOTOPOLIS_CITY, 0, 1, 2',
                       'goto_if_ne VAR_SOOTOPOLIS_CITY_STATE, 6, 0x08123456'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E1CF6)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_local_labels_and_texts_of_both_contiguous_owners(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, next_map, count, size, texts in [('MossdeepCity', 'SootopolisCity', 53, 1937, 19),
                                                  ('SootopolisCity', 'EverGrandeCity', 170, 7299, 49)]:
            blocks = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())
            parts = profile.profile_owner(ROOT, ''.join(blocks.values()), version=4,
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
    def test_both_complete_recorded_macro_closures_use_actual_native_expansion(self):
        batches = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())['batches']
        for name, count in [('MossdeepCity', 151), ('SootopolisCity', 395)]:
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

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_runtime_layout_evidence_cannot_drop_any_resource_or_table_span(self):
        batches = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())['batches']
        selected = [b for b in batches if 'SootopolisCity' in b['maps'] and b['review_type'] == 'direct_map_v4']
        self.assertEqual(len(selected), 1)
        original = selected[0]
        self.assertEqual(original['dynamic_layouts'], ['LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE'])
        roles = {'dynamic_layout_table', 'dynamic_layout', 'dynamic_border', 'dynamic_blockdata'}
        for role in roles:
            batch = copy.deepcopy(original)
            batch['native_spans'] = [s for s in batch['native_spans'] if s['role'] != role]
            with self.subTest(role=role), self.assertRaisesRegex(ValueError, 'incomplete_shared_native_coverage'):
                review._review_batch(ROOT, batch, {'SootopolisCity'}, {})


if __name__ == '__main__':
    unittest.main()
