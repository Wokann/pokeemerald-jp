"""One contiguous town batch retains per-map scope and deduplicated evidence."""
import copy
import json
from pathlib import Path
import re
import struct
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
MAPS = ['FallarborTown', 'VerdanturfTown', 'PacifidlogTown']


class SmallTownReviewTests(unittest.TestCase):
    def batch(self):
        rows = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())['batches']
        selected = [r for r in rows if set(r['maps']) & set(MAPS)]
        self.assertEqual(len(selected), 1)
        self.assertEqual(selected[0]['maps'], MAPS)
        return selected[0]

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_three_local_owners_and_22_texts_keep_their_exact_native_bounds(self):
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, following, count, size, texts in [('FallarborTown', 'VerdanturfTown', 18, 502, 8),
                                                  ('VerdanturfTown', 'PacifidlogTown', 22, 808, 10),
                                                  ('PacifidlogTown', 'Route101', 11, 309, 4)]:
            blocks = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())
            parts = profile.profile_owner(ROOT, ''.join(blocks.values()), version=4,
                                          address=next(iter(native[name + '_MapScripts'])))
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertEqual(sum(p.kind == 'string' for p in parts.values()), texts)
            labels = list(parts)
            for i, label in enumerate(labels):
                start = next(iter(native[label]))
                stop = next(iter(native[labels[i + 1] if i + 1 < len(labels) else following + '_MapScripts']))
                self.assertEqual(parts[label].size, stop - start, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, blocks[label], 'string'),
                                     rom[start - 0x08000000:stop - 0x08000000], label)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_entire_group_macro_closure_uses_actual_native_expansion(self):
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in self.batch()['shared_dependencies']:
            blocks = review.shared_script_blocks(ROOT, dep)
            sources.extend(blocks[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 94)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)

    def test_group_deduplication_cannot_remove_a_maps_native_component(self):
        batch = self.batch()
        self.assertEqual(set(batch['checks']), set(MAPS))
        identities = [(s['map'], s['role'], s['symbol']) for s in batch['native_spans']]
        self.assertEqual(len(identities), len(set(identities)))
        self.assertEqual(len(identities), 48)
        for name in MAPS:
            missing = copy.deepcopy(batch)
            missing['native_spans'] = [s for s in missing['native_spans'] if s['map'] != name or s['role'] != 'events']
            with self.subTest(map=name), self.assertRaisesRegex(ValueError, 'incomplete_native_component_coverage'):
                review._review_batch(ROOT, missing, set(MAPS), {})

    def test_hidden_nugget_success_and_failure_stay_separate(self):
        metadata = json.loads((ROOT / 'data/maps/FallarborTown/map.json').read_text())
        hidden = [e for e in metadata['bg_events'] if e['type'] == 'hidden_item']
        self.assertEqual([(e['x'], e['y'], e['item'], e['flag']) for e in hidden],
                         [(2, 15, 'ITEM_NUGGET', 'FLAG_HIDDEN_ITEM_FALLARBOR_TOWN_NUGGET')])
        blocks = review.label_blocks((ROOT / 'data/scripts/obtain_item.inc').read_text())
        self.assertIn('goto_if_eq VAR_0x8007, FALSE, EventScript_NoRoomForHiddenItem', blocks['EventScript_HiddenItemScript'])
        self.assertNotIn('special SetHiddenItemFlag', blocks['EventScript_NoRoomForHiddenItem'])
        self.assertIn('special SetHiddenItemFlag', blocks['EventScript_PutHiddenItemInPocket'])

    def test_twin_original_direction_and_distinct_contest_resets_are_preserved(self):
        blocks = review.label_blocks((ROOT / 'data/maps/VerdanturfTown/scripts.inc').read_text())
        movement = 'applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection'
        for label in ('VerdanturfTown_EventScript_Twin', 'VerdanturfTown_EventScript_TwinTunnelOpen'):
            self.assertIn(movement, review.statements(blocks[label]))
        self.assertNotIn('FLAG_CONTEST_SKETCH_CREATED', blocks['VerdanturfTown_OnTransition'])
        fallarbor = review.label_blocks((ROOT / 'data/maps/FallarborTown/scripts.inc').read_text())
        self.assertIn('clearflag FLAG_CONTEST_SKETCH_CREATED', fallarbor['FallarborTown_OnTransition'])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_cry_and_resume_bridge_use_the_actual_native_dispatch_tables(self):
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        def address(label):
            self.assertEqual(len(native[label]), 1)
            return next(iter(native[label]))
        def word(at):
            return struct.unpack_from('<I', rom, at - 0x08000000)[0]
        entries = re.findall(r'^\s*script_cmd_table_entry\s+(\w+)\s+(\w+)',
                             (ROOT / 'data/script_cmd_table.inc').read_text(), re.M)
        indices = {name: i for i, (name, _) in enumerate(entries)}
        for command in ('SCR_OP_WAITMONCRY', 'SCR_OP_SETSTEPCALLBACK'):
            self.assertEqual(word(address('gScriptCmdTable') + indices[command] * 4) & ~1,
                             address(entries[indices[command]][1]) & ~1)
        self.assertEqual(indices['SCR_OP_WAITMONCRY'], 0xC5)
        blocks = review.label_blocks((ROOT / 'data/maps/FallarborTown/scripts.inc').read_text())
        label = 'FallarborTown_EventScript_Azurill'
        prefix = blocks[label].split('\twaitmoncry', 1)[0]
        start = address(label)
        size = profile.profile_block(ROOT, prefix, {}, version=4, address=start).size
        self.assertEqual(rom[start - 0x08000000 + size], 0xC5)
        pacifidlog = review.label_blocks((ROOT / 'data/maps/PacifidlogTown/scripts.inc').read_text())
        self.assertNotIn('setstepcallback', pacifidlog['PacifidlogTown_OnTransition'])
        resume = address('PacifidlogTown_OnResume') - 0x08000000
        self.assertEqual(rom[resume:resume + 3], bytes([indices['SCR_OP_SETSTEPCALLBACK'], 3, 2]))
        self.assertEqual(word(address('sPerStepCallbacks') + 3 * 4) & ~1,
                         address('PacifidlogBridgePerStepCallback') & ~1)


if __name__ == '__main__':
    unittest.main()
