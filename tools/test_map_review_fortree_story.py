"""Fortree's reveal/cry sequence and bridge callback retain JP byte identity."""
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


class FortreeStoryTests(unittest.TestCase):
    def test_new_forms_are_measured_only_in_explicit_v4(self):
        for line, size in (('checkitem ITEM_DEVON_SCOPE', 5), ('checkitem ITEM_DEVON_SCOPE, 1', 5),
                           ('setstepcallback STEP_CB_FORTREE_BRIDGE', 2),
                           ('playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER', 5), ('waitmoncry', 1)):
            result = profile.profile_block(ROOT, 'Owner::\n' + line, {}, version=4, address=0x081DFDEE)
            self.assertEqual(result.size, size)
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + line, {})
        for line in ('checkitem', 'checkitem 0x120', 'checkitem ITEM_DEVON_SCOPE, 1, 2',
                     'setstepcallback 2', 'setstepcallback VAR_RESULT',
                     'playmoncry SPECIES_KECLEON', 'waitmoncry 0', 'set_visible\nend'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + line, {}, version=4, address=0x081DFDEE)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_actual_macro_forms_and_default_quantity(self):
        native_forms.StoryProfileTests().check_native_forms([
            'checkitem ITEM_DEVON_SCOPE', 'checkitem ITEM_DEVON_SCOPE, 1',
            'setstepcallback STEP_CB_FORTREE_BRIDGE',
            'playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER', 'waitmoncry', 'set_visible'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_28_labels_and_the_next_owner_boundary(self):
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        source = (ROOT / 'data/maps/FortreeCity/scripts.inc').read_text()
        parts = profile.profile_owner(ROOT, source, version=4,
                                      address=next(iter(native['FortreeCity_MapScripts'])))
        names = list(parts)
        self.assertEqual(len(parts), 28)
        self.assertEqual(sum(part.size for part in parts.values()), 899)
        for i, name in enumerate(names):
            next_name = names[i + 1] if i + 1 < len(names) else 'LilycoveCity_MapScripts'
            self.assertEqual(parts[name].size,
                             next(iter(native[next_name])) - next(iter(native[name])), name)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_cry_wait_and_bridge_really_dispatch_to_current_jp_handlers(self):
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        def address(name):
            self.assertEqual(len(native[name]), 1, name)
            return next(iter(native[name]))
        def word(at):
            return struct.unpack_from('<I', rom, at - 0x08000000)[0]
        entries = re.findall(r'^\s*script_cmd_table_entry\s+(\w+)\s+(\w+)',
                             (ROOT / 'data/script_cmd_table.inc').read_text(), re.M)
        indices = {name: i for i, (name, _) in enumerate(entries)}
        self.assertEqual(indices['SCR_OP_WAITMONCRY'], 0xC5)
        self.assertEqual(indices['SCR_OP_WAITDOORANIM'], 0xAE)
        for opcode in ('SCR_OP_WAITMONCRY', 'SCR_OP_PLAYMONCRY', 'SCR_OP_SETSTEPCALLBACK', 'SCR_OP_CHECKITEM'):
            i = indices[opcode]
            self.assertEqual(word(address('gScriptCmdTable') + 4 * i) & ~1, address(entries[i][1]) & ~1)
        source = review.label_blocks((ROOT / 'data/maps/FortreeCity/scripts.inc').read_text())
        label = 'FortreeCity_EventScript_UseDevonScope'
        at = address(label)
        prefix = source[label].split('\twaitmoncry', 1)[0]
        size = profile.profile_block(ROOT, prefix, {}, version=4, address=at).size
        self.assertEqual(rom[at - 0x08000000 + size], 0xC5)
        at = address('FortreeCity_OnResume') - 0x08000000
        self.assertEqual(rom[at:at + 2], bytes([indices['SCR_OP_SETSTEPCALLBACK'], 2]))
        self.assertEqual(word(address('sPerStepCallbacks') + 2 * 4) & ~1,
                         address('FortreeBridgePerStepCallback') & ~1)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_recorded_local_and_shared_macro_closure(self):
        batches = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())['batches']
        matches = [b for b in batches if 'FortreeCity' in b['maps'] and b['review_type'] == 'direct_map_v4']
        self.assertEqual(len(matches), 1)
        sources = [(ROOT / 'data/maps/FortreeCity/scripts.inc').read_text()]
        for dep in matches[0]['shared_dependencies']:
            blocks = review.label_blocks((ROOT / dep['path']).read_text())
            sources.extend(blocks[name] for name in dep['labels'])
        samples = {line for source in sources for block in review.label_blocks(source).values()
                   if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(samples), 50)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)


if __name__ == '__main__':
    unittest.main()
