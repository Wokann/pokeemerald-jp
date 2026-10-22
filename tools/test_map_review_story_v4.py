"""Address-aware shop/story review remains explicit and rejects false bounds."""
import copy
import json
from pathlib import Path
import unittest
try:
    import map_review_script_profile as profile
    import test_map_semantic_review as fixtures
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import test_map_semantic_review as fixtures
    from tools import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]


class AddressedStoryProfileTests(unittest.TestCase):
    def parse(self, text, address=0x08000000, version=4):
        return profile.profile_block(ROOT, 'Entry::\n' + text, {}, version=version, address=address)

    def test_address_and_profile_version_are_explicit(self):
        for address in (None, True, -1, 0, 0x09000000):
            with self.assertRaises(ValueError):
                self.parse('end', address)
        for source in ('pokemart Items', 'getplayerxy VAR_0x8004, VAR_0x8005',
                       'msgbox Text, MSGBOX_YESNO', 'giveitem ITEM_POWDER_JAR', 'end\n.align 2'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source, address=None, version=3)

    def test_trailing_alignment_uses_absolute_address_not_relative_owner_offset(self):
        for offset, size in ((0, 4), (1, 3), (2, 2), (3, 1)):
            self.assertEqual(self.parse('end\n.align 2', 0x08000000 + offset).size, size)
        for text in ('.align 2', '.align 2\nend', 'end\n.align 1', 'end\n.align 2\nend',
                     'end\n.align 2\nend\n.align 2'):
            with self.assertRaises(ValueError):
                self.parse(text)

    def test_item_and_decoration_lists_have_distinct_types_and_complete_sentinel_tail(self):
        for namespace, kind in (('ITEM', 'mart_items'), ('DECOR', 'mart_decorations')):
            p = self.parse('.2byte %s_ONE\n.2byte %s_TWO\npokemartlistend' % (namespace, namespace))
            self.assertEqual((p.kind, p.size), (kind, 8))
        for source in ('.2byte ITEM_ONE\n.2byte DECOR_TWO\npokemartlistend',
                       '.2byte ITEM_ONE\n.2byte ITEM_NONE\npokemartlistend',
                       '.2byte ITEM_ONE\npokemartlistend\nend',
                       '.2byte ITEM_ONE', 'pokemartlistend'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)
        with self.assertRaises(ValueError):
            self.parse('.2byte ITEM_ONE\npokemartlistend', 0x08000001)

    def test_shop_pointer_kind_cannot_be_interchanged(self):
        good = 'Entry::\npokemart Stock\nend\n.align 2\nStock:\n.2byte ITEM_ONE\npokemartlistend'
        result = profile.profile_owner(ROOT, good, {}, version=4, address=0x08000000)
        self.assertEqual(result['Entry'].targets, {'Stock': 'mart_items'})
        for source in (good.replace('ITEM_ONE', 'DECOR_ONE'), good.replace('pokemart Stock', 'goto Stock')):
            with self.assertRaises(ValueError):
                profile.profile_owner(ROOT, source, {}, version=4, address=0x08000000)

    def test_new_story_forms_measure_actual_macro_contracts_and_standard_entries(self):
        for source, size in (('setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_FACE_UP', 4),
                             ('getplayerxy VAR_0x8004, VAR_0x8005', 5),
                             ('bufferleadmonspeciesname STR_VAR_1', 2), ('addvar VAR_SCOTT_STATE, 1', 5),
                             ('goto_if_set FLAG_TEST, Done', 9), ('goto_if_unset FLAG_TEST, Done', 9),
                             ('giveitem VAR_0x8008, 2', 12), ('yesnobox 20, 8', 3)):
            self.assertEqual(self.parse(source).size, size, source)
        self.assertEqual(self.parse('giveitem ITEM_POWDER_JAR').standard_scripts, {0: 'Std_ObtainItem'})
        self.assertEqual(self.parse('msgbox Text, MSGBOX_YESNO').standard_scripts, {5: 'Std_MsgboxYesNo'})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_184_city_labels_and_78_text_objects_match_exact_native_boundaries(self):
        review = fixtures.review
        symbols, memory = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        start = next(iter(symbols['SlateportCity_MapScripts']))
        text = (ROOT / 'data/maps/SlateportCity/scripts.inc').read_text()
        profiles = profile.profile_owner(ROOT, text, version=4, address=start)
        blocks = review.label_blocks(text)
        labels = list(profiles)
        self.assertEqual(len(labels), 184)
        self.assertEqual(sum(p.size for p in profiles.values()), 6635)
        self.assertEqual(sum(p.kind in ('mart_items', 'mart_decorations') for p in profiles.values()), 4)
        for i, name in enumerate(labels):
            stop = next(iter(symbols[labels[i + 1] if i + 1 < len(labels) else 'MauvilleCity_MapScripts']))
            address = next(iter(symbols[name]))
            self.assertEqual(profiles[name].size, stop - address, name)
            if profiles[name].kind == 'string':
                data = review.encoded_text(ROOT, blocks[name], 'string')
                self.assertEqual(data, rom[address - 0x08000000:stop - 0x08000000], name)
        self.assertEqual(sum(p.kind == 'string' for p in profiles.values()), 78)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_complete_v4_city_and_shared_macro_forms_match_real_expansion(self):
        review = fixtures.review
        manifest = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())
        batches = [b for b in manifest['batches'] if b['review_type'] == 'direct_map_v4' and 'SlateportCity' in b['maps']]
        self.assertEqual(len(batches), 1, 'the full city closure must be explicitly recorded')
        sources = [(ROOT / 'data/maps/SlateportCity/scripts.inc').read_text()]
        for dep in batches[0]['shared_dependencies']:
            blocks = review.label_blocks((ROOT / dep['path']).read_text())
            sources.extend(blocks[name] for name in dep['labels'])
        samples = {line for text in sources for block in review.label_blocks(text).values()
                   if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(samples), 357)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)
        native_forms.StoryProfileTests().check_native_forms(['giveitem ITEM_POWDER_JAR, 2',
            'giveitem VAR_0x8008', 'pokemart Example', 'pokemartdecoration Example',
            'msgbox Example, MSGBOX_YESNO'], version=4)


class AddressedStoryReviewTests(unittest.TestCase):
    def setUp(self):
        f = self.f = fixtures.MapSemanticReviewTests()
        f.setUp()
        self.addCleanup(f.doCleanups)
        f.add_story_fixture()
        batch = f.manifest['batches'][0]
        batch['review_type'] = 'direct_map_v4'
        f.put('data/maps/First/scripts.inc', 'First_MapScripts::\n'
              '\tmap_script MAP_SCRIPT_ON_LOAD, First_Entry\n\t.byte 0\n'
              'First_Entry::\n\tspecial StartBattle\n\tpokemart First_Mart\n\tplayse SE_PIN\n'
              '\tmsgbox First_Text, MSGBOX_YESNO\n\tend\n\t.align 2\n'
              'First_Mart:\n\t.2byte ITEM_ETHER\n\tpokemartlistend\n'
              'First_Text:\n\t.string "あ$"\n')
        f.put('data/std.inc', (f.root / 'data/std.inc').read_text() + 'Std_MsgboxYesNo::\n'
              '\tmessage NULL\n\twaitmessage\n\tyesnobox 20, 8\n\treturn\n')
        source = (f.root / 'data/event_scripts.s').read_text()
        f.put('data/event_scripts.s', source.replace('gStdScripts_End::',
              '\t.4byte NULL\n\t.4byte Std_MsgboxYesNo\ngStdScripts_End::'))
        batch['standard_scripts'] = [dict(index=3, entry='Std_MsgboxSign'), dict(index=5, entry='Std_MsgboxYesNo')]
        batch['shared_dependencies'] = [d for d in batch['shared_dependencies'] if d['entry'] != 'SharedMove']
        batch['shared_dependencies'].append(dict(entry='Std_MsgboxYesNo', path='data/std.inc', labels=['Std_MsgboxYesNo']))
        batch['sources'] = [c for c in batch['sources'] if c['path'] != 'data/movement.inc']
        batch['sources'].append(f.claim('data/std.inc', selector='asm_labels', labels=['Std_MsgboxYesNo']))
        batch['native_spans'] = [s for s in batch['native_spans'] if s['symbol'] != 'SharedMove']
        batch['native_spans'][0]['size'] = 36
        for span in batch['native_spans']:
            if span['symbol'] == 'gStdScripts':
                span['size'] = 24
        batch['native_spans'].append(dict(map=None, role='shared_script', symbol='Std_MsgboxYesNo',
                                         address=0x080001A0, size=10))
        image = bytearray(f.image)
        image[34:36] = bytes([1, 255])
        image[400:408] = bytes(4) + (0x080001A0).to_bytes(4, 'little')
        f.image = bytes(image)
        f.symbols = [(n, v) for n, v in f.symbols if n not in ('First_Inspect', 'First_Text', 'First_Action', 'SharedMove')]
        f.symbols += [('First_Entry', 0x08000006), ('First_Mart', 0x0800001C),
                      ('First_Text', 0x08000022), ('Std_MsgboxYesNo', 0x080001A0)]
        f.refresh_story_fixture()
        self.assertEqual(f.progress()['reviewed_maps'], 1, f.progress())

    def test_complete_v4_native_addressed_shop_and_yesno_closure(self):
        self.assertEqual(self.f.progress()['reviewed_maps'], 1)

    def test_missing_or_duplicate_address_evidence_is_rejected(self):
        batch = self.f.manifest['batches'][0]
        batch['native_spans'].append(copy.deepcopy(batch['native_spans'][0]))
        self.f.save_manifest()
        self.f.assert_not_approved(self.f.progress())

    def test_source_padding_cannot_be_omitted_with_a_true_native_prefix_hash(self):
        f = self.f
        path = 'data/maps/First/scripts.inc'
        f.put(path, (f.root / path).read_text().replace('\t.align 2\n', ''))
        f.manifest['batches'][0]['native_spans'][0]['size'] -= 1
        f.refresh_story_fixture()
        f.assert_not_approved(f.progress())

    def test_each_internal_label_is_bound_not_just_total_owner_size(self):
        f = self.f
        f.symbols = [(n, v + 1 if n == 'First_Text' else v) for n, v in f.symbols]
        f.refresh_story_fixture()
        result = f.progress()
        f.assert_not_approved(result)
        self.assertIn('native_addressed_label_mismatch:First_Text', result['batches'][0]['errors'])


if __name__ == '__main__':
    unittest.main()
