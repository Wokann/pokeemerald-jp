#!/usr/bin/env python3
"""Native evolution graphics, odd-address palette tables and JP text slots."""
import re
import subprocess
import tempfile
import unittest
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
PREPROC = ROOT / 'tools/preproc/preproc'
ASSETS = [('unused_1.pal', '.gbapal', 0x593c80, 32), ('bg.png', '.4bpp.lz', 0x593ca0, 0x6f8),
          ('bg_inner.bin', '.lz', 0x594398, 0x4e4), ('bg_outer.bin', '.lz', 0x59487c, 0x4d4),
          ('bg_anim_intro.pal', '.gbapal', 0x594d50, 512), ('unused_2.pal', '.gbapal', 0x594f50, 352),
          ('unused_3.pal', '.gbapal', 0x5950b0, 416), ('unused_4.pal', '.gbapal', 0x595250, 416),
          ('bg_anim.pal', '.gbapal', 0x5953f0, 64)]


class EvolutionSceneAssetTests(unittest.TestCase):
    def test_actual_c_owners_and_link_order(self):
        for path in ('data/data_b2d_mid32.s', 'data/graphics/evolution_scene.s', 'data/text/trade.inc'):
            self.assertFalse((ROOT / path).exists())
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        owners = ['data/graphics/pokedex_area_screen.o(.rodata.pokedex_area_screen_graphics_suffix)',
                  'src/evolution_scene.o(.rodata.evolution_scene_graphics)',
                  'src/strings.o(.rodata.strings_evolution_communication)',
                  'src/evolution_scene.o(.rodata.evolution_scene_palette_tables)']
        self.assertEqual([linker.index(p) for p in owners], sorted(linker.index(p) for p in owners))
        self.assertNotIn('data/data_b2d_mid32.o(', linker)
        self.assertNotIn('data/graphics/evolution_scene.o(', linker)
        self.assertIn('.incbin "baserom_jp.gba", 0x593abc, 0x1c4', (ROOT / 'data/graphics/pokedex_area_screen.s').read_text())

    @unittest.skipUnless(PREPROC.is_file() and (ROOT / 'baserom_jp.gba').is_file(), 'requires preproc and JP ROM')
    def test_jp_controls_eos_leading_spaces_and_slot_padding(self):
        source = (ROOT / 'src/strings.c').read_text()
        begin = source.index('#define STRINGS_EVOLUTION_COMMUNICATION ')
        end = source.index('#undef STRINGS_EVOLUTION_COMMUNICATION', begin)
        block = source[begin:end]
        self.assertNotIn('{RIGHT_ARROW}', block)
        root = ROOT / '.tmp/agent-work/tests'
        root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='evo-text-', dir=root) as temp:
            path = Path(temp) / 'text.c'
            path.write_text(block)
            encoded = subprocess.check_output([str(PREPROC), str(path), str(ROOT / 'charmap.txt')], text=True)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, start, size in [('gText_CommunicationStandby5', 0x595430, 13),
                                  ('gJPText_UnusedColoredYesNo', 0x59543d, 16),
                                  ('gJPText_UnusedTextColors', 0x59544d, 10)]:
            body = re.search(name + r'\[\]\s*=\s*\{([^}]+)\}', encoded).group(1)
            data = bytes(int(v, 16) for v in re.findall(r'0x([0-9A-Fa-f]+)', body))
            self.assertEqual(data, rom[start:start + size], name)
        body = re.search(r'gJPText_UnusedArrowPatterns\[3\]\[10\]\s*=\s*\{(.*?)\};', encoded, re.S).group(1)
        rows = [bytes(int(v, 16) for v in re.findall(r'0x([0-9A-Fa-f]+)', row)) for row in re.findall(r'\{([^}]+)\}', body)]
        self.assertEqual(rows, [b'\xef\xfe\x00\xff', b'\x00\xfe\xef\xff', b'\x00\xfe\x00\xff'])
        self.assertEqual(b''.join(row + bytes(6) for row in rows), rom[0x595457:0x595475])

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').is_file(), 'requires JP ROM')
    def test_palette_tables_keep_all_50_rows_without_alignment(self):
        source = (ROOT / 'src/evolution_scene.c').read_text()
        self.assertIn('section(".rodata.evolution_scene_palette_tables"), aligned(1)', source)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, width, start, size in [('sBgAnim_PaletteControl', 4, 0x595475, 16), ('sBgAnim_PalIndexes', 16, 0x595485, 800)]:
            body = re.search(name + r'\[\]\[' + str(width) + r'\]\s*=\s*\{(.*?)\};', source, re.S).group(1)
            values = bytes(int(v) for v in re.findall(r'\b\d+\b', body))
            self.assertEqual(len(values), size)
            self.assertEqual(values, rom[start:start + size])

    def test_clean_dependencies_and_explicit_preprocessing(self):
        make = (ROOT / 'Makefile').read_text()
        rule = re.search(r'(?m)^\$\(C_BUILDDIR\)/evolution_scene\.o: src/evolution_scene\.c charmap\.txt[^\n]*\n((?:\t[^\n]*\n)+)', make)
        self.assertIn('$(PREPROC) -i $< charmap.txt', rule.group(1))
        self.assertIn('$(JP_EVOLUTION_SCENE_ASSETS)', rule.group(0))
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('$(JP_EVOLUTION_SCENE_ASSETS) $(JP_EVOLUTION_SCENE_INTERMEDIATES)', clean)
        self.assertNotIn('data/graphics/evolution_scene.o', make)
        self.assertNotIn('data/data_b2d_mid32.o', make)

    @unittest.skipUnless(GFX.is_file() and (ROOT / 'baserom_jp.gba').is_file(), 'requires gbagfx and JP ROM')
    def test_all_nine_editable_sources_rebuild_native_bytes(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        root = ROOT / '.tmp/agent-work/tests'
        root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='evo-assets-', dir=root) as temp:
            for i, (name, extension, start, size) in enumerate(ASSETS):
                source = ROOT / 'graphics/evolution_scene' / name
                output = Path(temp) / (str(i) + extension)
                raw_extension = extension[:-3] if extension.endswith('.lz') else extension
                raw = output.with_suffix('') if extension.endswith('.lz') else output
                if raw_extension:
                    subprocess.run([str(GFX), str(source), str(raw)], check=True, capture_output=True)
                else:
                    raw = source
                if extension.endswith('.lz'):
                    subprocess.run([str(GFX), str(raw), str(output)], check=True, capture_output=True)
                self.assertEqual(output.read_bytes(), rom[start:start + size], name)


if __name__ == '__main__':
    unittest.main()
