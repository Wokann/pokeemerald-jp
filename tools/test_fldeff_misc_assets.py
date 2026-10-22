#!/usr/bin/env python3
"""Native field-effect graphics and typed-owner rebuild contracts."""
import re
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
RESOURCES = [
    ('pics/secret_power_cave.png', 0x56955c, 640, '-mwidth 2 -mheight 2'),
    ('palettes/secret_power_cave.pal', 0x5697fc, 32, ''),
    ('pics/secret_power_shrub.png', 0x56981c, 640, '-mwidth 2 -mheight 2'),
    ('pics/secret_power_tree.png', 0x569a9c, 768, '-mwidth 2 -mheight 2'),
    ('palettes/secret_power_plant.pal', 0x569d9c, 32, ''),
    ('pics/sand_pillar/0.png', 0x569dbc, 256, ''),
    ('pics/sand_pillar/1.png', 0x569ebc, 256, ''),
    ('pics/sand_pillar/2.png', 0x569fbc, 256, ''),
    ('pics/record_mix_lights.png', 0x56a290, 384, '-mwidth 4 -mheight 1'),
    ('palettes/record_mix_lights.pal', 0x56a410, 32, ''),
]


class FldeffMiscAssetTests(unittest.TestCase):
    def test_final_inputs_are_editable_upstream_style_sources(self):
        for relative, start, size, flags in RESOURCES:
            source = ROOT / 'graphics/field_effects' / relative
            if source.suffix == '.png':
                self.assertEqual(source.read_bytes()[:8], b'\x89PNG\r\n\x1a\n')
            else:
                lines = source.read_text().splitlines()
                self.assertEqual(lines[:3], ['JASC-PAL', '0100', '16'])
                self.assertEqual(len(lines[3:]), 16)

    def test_complete_family_uses_real_c_owners(self):
        source = (ROOT / 'src/fldeff_misc.c').read_text()
        data = source.split('#define FLDEFF_MISC_DATA ', 1)[1].split('#undef FLDEFF_MISC_DATA', 1)[0]
        self.assertEqual(len(re.findall(r'^(?:static )?const ', data, re.M)), 40)
        self.assertNotIn('asm(', data)
        self.assertNotIn('extern ', data)
        self.assertIn('sSecretPowerCave_Filler[32] FLDEFF_MISC_DATA = {0}', data)
        self.assertEqual(data.count('overworld_frame(sSecretPowerTree_Gfx,'), 5)
        self.assertIn('{gTilesetPalettes_SecretBase[5], FLDEFF_PAL_TAG_SAND_PILLAR}', data)
        tilesets = (ROOT / 'data/tilesets/graphics.inc').read_text()
        self.assertEqual(tilesets.count('gTilesetPalettes_SecretBase::'), 1)
        self.assertNotIn('.set gTilesetPalettes_SecretBase', tilesets)
        assembly = (ROOT / 'data/data_b2d_mid60.s').read_text()
        for name in ('secret_power.inc', 'secret_power_descriptors.inc', 'record_mix_lights.inc'):
            self.assertFalse((ROOT / 'data/field_effects' / name).exists())
            self.assertNotIn(name, assembly)

    def test_build_chain_explicitly_generates_and_preprocesses_resources(self):
        make = (ROOT / 'Makefile').read_text()
        rule = re.search(r'(?m)^\$\(C_BUILDDIR\)/fldeff_misc\.o: src/fldeff_misc\.c charmap\.txt[^\n]*\n((?:\t[^\n]*\n)+)', make)
        self.assertIsNotNone(rule)
        self.assertIn('$(PREPROC) -i $< charmap.txt', rule.group(1))
        self.assertIn('$(JP_FLDEFF_MISC_ASSETS)', rule.group(0))
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('rm -f $(JP_FLDEFF_MISC_ASSETS)', clean)
        for relative, start, size, flags in RESOURCES:
            source = 'graphics/field_effects/' + relative
            encoded = ''.join(c if c.isalnum() else '_' for c in flags)
            suffix = '.4bpp' if relative.endswith('.png') else '.gbapal'
            self.assertIn(source + encoded + suffix + ': ' + source + ' | tools', make)

    def test_linker_preserves_the_native_owner_order(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        owners = ['src/give_gift_ribbon_to_party.o(.rodata.gift_ribbon_data)',
                  'src/fldeff_misc.o(.rodata.fldeff_misc_data)',
                  'data/data_b2d_mid60.o(.rodata.mid60_tail_prefix)',
                  'src/rotating_gate.o(.rodata.rotating_gate_data)']
        for owner in owners:
            self.assertEqual(linker.count(owner), 1)
        self.assertEqual([linker.index(o) for o in owners], sorted(linker.index(o) for o in owners))

    @unittest.skipUnless(GFX.is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires the local JP baserom and built gbagfx')
    def test_all_ten_native_resources_rebuild_byte_exactly(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='fldeff-misc-', dir=temp_root) as temp:
            for i, (relative, start, size, flags) in enumerate(RESOURCES):
                suffix = '.4bpp' if relative.endswith('.png') else '.gbapal'
                output = Path(temp) / (str(i) + suffix)
                subprocess.run([str(GFX), str(ROOT / 'graphics/field_effects' / relative),
                                str(output), *flags.split()], check=True, capture_output=True)
                self.assertEqual(output.read_bytes(), rom[start:start + size], relative)


if __name__ == '__main__':
    unittest.main()
