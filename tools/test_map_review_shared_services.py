"""Measure standard item aliases and player visibility against native scripts."""
from pathlib import Path
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
DECLARATIONS = '.set ITEMID, VAR_0x8000\n.set AMOUNT, VAR_0x8001\n'
ITEM_ENTRY = 'Std_ObtainItem::\nadditem ITEMID, AMOUNT\nreturn\n'


class SharedServiceProfileTests(unittest.TestCase):
    def test_showplayer_is_five_bytes_and_does_not_end_control_flow(self):
        result = profile.profile_block(ROOT, 'Entry::\nshowplayer\n', version=4, address=0x08243265)
        self.assertEqual((result.kind, result.size, result.targets), ('script', 5, {}))
        self.assertTrue(result.may_fall_through)
        result = profile.profile_block(ROOT, 'Entry::\nshowplayer\nreleaseall\nend\n', version=4, address=0x08243265)
        self.assertEqual(result.size, 7)
        self.assertFalse(result.may_fall_through)

    def test_showplayer_rejects_operands_and_remains_outside_legacy_grammar(self):
        for command in ('showplayer 0', 'showplayer LOCALID_PLAYER', 'showplayer 0, 0'):
            with self.subTest(command=command), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Entry::\n' + command, version=4, address=0x08243265)
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT, 'Entry::\nshowplayer', version=3)

    def test_exact_item_aliases_emit_no_bytes_and_keep_actual_entry(self):
        result = profile.profile_owner(ROOT, DECLARATIONS + ITEM_ENTRY, version=4, address=0x08242B6D)
        self.assertEqual(list(result), ['Std_ObtainItem'])
        self.assertEqual(result['Std_ObtainItem'].size, 6)

    def test_changed_partial_duplicate_and_other_owner_aliases_fail_closed(self):
        mutations = (
            DECLARATIONS.replace('8000', '8002'),
            DECLARATIONS.replace('8001', '8000'),
            DECLARATIONS.replace('VAR_0x8000', '0x08242B6D'),
            DECLARATIONS.splitlines()[0] + '\n',
            DECLARATIONS + '.set ITEMID, VAR_0x8000\n',
            DECLARATIONS + '.set EXTRA, 0\n',
            '\n'.join(reversed(DECLARATIONS.splitlines())) + '\n',
        )
        for prefix in mutations:
            with self.subTest(prefix=prefix), self.assertRaisesRegex(ValueError, 'unmodeled_owner_prefix'):
                profile.profile_owner(ROOT, prefix + ITEM_ENTRY, version=4, address=0x08242B6D)
        with self.assertRaisesRegex(ValueError, 'unmodeled_owner_prefix'):
            profile.profile_owner(ROOT, DECLARATIONS + ITEM_ENTRY.replace('Std_ObtainItem', 'Other'), version=4, address=0x08242B6D)
        with self.assertRaisesRegex(ValueError, 'unmodeled_owner_prefix'):
            profile.profile_owner(ROOT, DECLARATIONS + ITEM_ENTRY, version=3)

    def test_aliases_cannot_be_shadowed_inside_script_blocks(self):
        for entry in (ITEM_ENTRY.replace('additem', '.set ITEMID, VAR_0x8002\nadditem'),
                      ITEM_ENTRY + 'Other::\n.set AMOUNT, VAR_0x8002\nreturn\n'):
            with self.subTest(entry=entry), self.assertRaises(ValueError):
                profile.profile_owner(ROOT, DECLARATIONS + entry, version=4, address=0x08242B6D)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_visibility_forms_match_fresh_macro_expansion_and_assembler(self):
        native_forms.StoryProfileTests().check_native_forms(['showplayer', 'hideplayer'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native ROM artifacts')
    def test_complete_item_owner_matches_all_native_label_spans_and_rom(self):
        source = (ROOT / 'data/scripts/obtain_item.inc').read_text()
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        start = next(iter(native['Std_ObtainItem']))
        stop = next(iter(native['EventScript_MixRecordsPrompt']))
        parsed = profile.profile_owner(ROOT, source, version=4, address=start)
        names = list(parsed)
        self.assertEqual((len(names), stop - start), (28, 637))
        for index, name in enumerate(names):
            end = next(iter(native[names[index + 1]])) if index + 1 < len(names) else stop
            self.assertEqual(parsed[name].size, end - next(iter(native[name])), name)
        self.assertEqual(sum(block.size for block in parsed.values()), stop - start)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(verifier.assemble_candidate(source, start), rom[start - 0x08000000:stop - 0x08000000])
        self.assertIn('bufferitemname STR_VAR_2, ITEMID', source)
        self.assertNotIn('bufferitemnameplural', source)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native ROM artifacts')
    def test_complete_ferry_briney_region_keeps_actual_visibility_and_movements(self):
        source = (ROOT / 'data/event_scripts.s').read_text()
        begin = source.index('Common_EventScript_FerryDepart::')
        end = source.index('\t.include "data/scripts/cave_of_origin.inc"', begin)
        source = source[begin:end]
        blocks = review.label_blocks(source)
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        start = next(iter(native[next(iter(blocks))]))
        parsed = profile.profile_owner(ROOT, source, version=4, address=start)
        self.assertEqual((len(parsed), sum(block.size for block in parsed.values())), (7, 146))
        self.assertEqual(sum(line == 'showplayer' for line in review.statements(source)), 1)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(verifier.assemble_candidate(source, start), rom[start - 0x08000000:start - 0x08000000 + 146])


if __name__ == '__main__':
    unittest.main()
