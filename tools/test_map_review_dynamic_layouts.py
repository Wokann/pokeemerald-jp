"""Explicit runtime layout changes need source assets and real native pointers."""
import json
from pathlib import Path
import struct
import tempfile
import unittest
try:
    import map_semantic_review as review
    import map_review_script_profile as profile
    import test_map_semantic_review as fixtures
except ModuleNotFoundError:
    from tools import map_semantic_review as review
    from tools import map_review_script_profile as profile
    from tools import test_map_semantic_review as fixtures

ROOT = Path(__file__).resolve().parents[1]


class DynamicLayoutTests(unittest.TestCase):
    def setUp(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        temp = tempfile.TemporaryDirectory(prefix='dynamic-layout-', dir=parent)
        self.addCleanup(temp.cleanup)
        self.root = Path(temp.name)
        def put(path, value):
            target = self.root / path
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(value if isinstance(value, bytes) else value.encode())
        self.put = put
        put('include/constants/layouts.h', '#define LAYOUT_ALT 1\n')
        put('src/overworld.c', 'fixture source\n')
        put('src/scrcmd.c', 'fixture source\n')
        put('data/layouts/layouts_table.inc', 'gMapLayouts::\n.4byte Alt_Layout\n')
        self.row = dict(id='LAYOUT_ALT', name='Alt_Layout', width=2, height=2,
                        primary_tileset='Primary', secondary_tileset='Secondary',
                        border_filepath='data/layouts/Alt/border.bin', blockdata_filepath='data/layouts/Alt/map.bin')
        put('data/layouts/layouts.json', json.dumps(dict(layouts=[self.row])))
        put('data/layouts/Alt/border.bin', bytes(8))
        put('data/layouts/Alt/map.bin', bytes(8))
        put('data/layouts/layouts.inc', 'Alt_Layout_Border::\n.incbin "data/layouts/Alt/border.bin"\n'
            'Alt_Layout_Blockdata::\n.incbin "data/layouts/Alt/map.bin"\nAlt_Layout::\n'
            '.4byte 2\n.4byte 2\n.4byte Alt_Layout_Border\n.4byte Alt_Layout_Blockdata\n'
            '.4byte Primary\n.4byte Secondary\n')
        paths = ['include/constants/layouts.h', 'src/overworld.c', 'src/scrcmd.c',
                 'data/layouts/layouts_table.inc', 'data/layouts/Alt/border.bin', 'data/layouts/Alt/map.bin']
        self.batch = dict(review_type='direct_map_v4', dynamic_layouts=['LAYOUT_ALT'],
                          sources=[dict(path=p, selector='file') for p in paths])
        self.batch['sources'] += [dict(path='data/layouts/layouts.json', selector='json_layout', id='LAYOUT_ALT'),
            dict(path='data/layouts/layouts.inc', selector='asm_labels',
                 labels=['Alt_Layout_Border', 'Alt_Layout_Blockdata', 'Alt_Layout'])]
        image = bytearray(512)
        struct.pack_into('<I', image, 0, 0x08000010)
        struct.pack_into('<6I', image, 16, 2, 2, 0x08000030, 0x08000040, 0x08000050, 0x08000060)
        self.native = dict(rom=bytes(image), symbols={
            'gMapLayouts': {0x08000000}, 'Alt_Layout': {0x08000010}, 'Alt_Layout_Border': {0x08000030},
            'Alt_Layout_Blockdata': {0x08000040}, 'Primary': {0x08000050}, 'Secondary': {0x08000060},
            'ScrCmd_setmaplayoutindex': {0x08000101}, 'SetCurrentMapLayout': {0x08000121},
            'GetMapLayout': {0x08000125}},
            owners=[(0x08000100, 16, 'src/scrcmd.o'), (0x08000120, 32, 'src/overworld.o')])

    def check_native(self):
        errors = []
        review._dynamic_layout_native(self.root, self.batch, self.native, errors)
        return errors

    def test_complete_source_and_native_layout_contract(self):
        roles, rows, table = review.dynamic_layout_contracts(self.root, self.batch)
        self.assertEqual(set(roles.values()), {'dynamic_layout_table', 'dynamic_layout', 'dynamic_border', 'dynamic_blockdata'})
        self.assertEqual(rows, {'LAYOUT_ALT': self.row})
        self.assertEqual(table, ['Alt_Layout'])
        self.assertEqual(self.check_native(), [])

    def test_dynamic_layouts_are_named_v4_dependencies_not_untyped_numbers(self):
        p = profile.profile_block(ROOT, 'Owner::\nsetmaplayoutindex LAYOUT_ALT\nend', {},
                                  version=4, address=0x08000000)
        self.assertEqual((p.size, p.layouts), (4, {'LAYOUT_ALT'}))
        for source in ('setmaplayoutindex 1', 'setmaplayoutindex VAR_RESULT', 'setmaplayoutindex LAYOUT_ALT, 1'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x08000000)
        for ids in (['LAYOUT_ALT', 'LAYOUT_ALT'], [{}], ['Unknown'], None):
            with self.assertRaises(ValueError):
                review.dynamic_layout_contracts(self.root, dict(self.batch, dynamic_layouts=ids))

    def test_asset_and_selected_source_bindings_cannot_be_omitted(self):
        original = self.batch['sources']
        for claim in original:
            self.batch['sources'] = [c for c in original if c is not claim]
            with self.subTest(claim=claim), self.assertRaises(ValueError):
                review.dynamic_layout_contracts(self.root, self.batch)
        self.batch['sources'] = original
        self.put('data/layouts/Alt/map.bin', bytes(6))
        with self.assertRaisesRegex(ValueError, 'dynamic_layout_asset'):
            review.dynamic_layout_contracts(self.root, self.batch)

    def test_wrong_source_table_index_or_structure_cannot_pass(self):
        self.put('include/constants/layouts.h', '#define LAYOUT_ALT 2\n')
        with self.assertRaisesRegex(ValueError, 'dynamic_layout_index_mismatch'):
            review.dynamic_layout_contracts(self.root, self.batch)
        self.put('include/constants/layouts.h', '#define LAYOUT_ALT 1\n')
        path = self.root / 'data/layouts/layouts.inc'
        self.put('data/layouts/layouts.inc', path.read_text().replace('.4byte 2', '.4byte 3', 1))
        with self.assertRaisesRegex(ValueError, 'dynamic_layout_structure_mismatch'):
            review.dynamic_layout_contracts(self.root, self.batch)

    def test_true_byte_spans_do_not_replace_actual_table_and_field_checks(self):
        for offset, value, error in ((0, 0x08000030, 'native_dynamic_layout_table_target_mismatch:LAYOUT_ALT'),
                                     (16, 3, 'native_dynamic_layout_structure_mismatch:LAYOUT_ALT'),
                                     (32, 0x08000060, 'native_dynamic_layout_structure_mismatch:LAYOUT_ALT')):
            original = self.native['rom']
            image = bytearray(original)
            struct.pack_into('<I', image, offset, value)
            self.native['rom'] = bytes(image)
            self.assertIn(error, self.check_native())
            self.native['rom'] = original

    def test_engine_symbol_is_bound_to_its_native_input_owner(self):
        self.native['owners'][1] = (0x08000120, 32, 'src/unrelated.o')
        self.assertIn('native_dynamic_layout_engine_owner_mismatch:GetMapLayout', self.check_native())

    def test_script_reference_requires_explicit_dependency_before_native_checks(self):
        f = fixtures.MapSemanticReviewTests()
        f.setUp()
        self.addCleanup(f.doCleanups)
        f.add_story_fixture()
        batch = f.manifest['batches'][0]
        batch['review_type'] = 'direct_map_v4'
        path = 'data/maps/First/scripts.inc'
        f.put(path, (f.root / path).read_text().replace('First_Action::\n',
              'First_Action::\n\tsetmaplayoutindex LAYOUT_ALT\n'))
        with self.assertRaisesRegex(ValueError, 'missing_or_unreachable_dynamic_layout_contract'):
            review.component_contracts(f.root, batch, ['First'])


if __name__ == '__main__':
    unittest.main()
