#!/usr/bin/env python3
"""Native JP unused Pokemon text and explicit Day Care alignment contracts."""
import re
import subprocess
import tempfile
import unittest
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
PREPROC = ROOT / 'tools/preproc/preproc'


class PokemonDataBoundaryTests(unittest.TestCase):
    def test_mid47_has_been_fully_retired(self):
        self.assertFalse((ROOT / 'data/data_b2d_mid47.s').exists())
        for path in ('Makefile', 'ld_script_jp.txt'):
            self.assertNotIn('data/data_b2d_mid47.o', (ROOT / path).read_text())
        source = (ROOT / 'src/pokemon.c').read_text()
        self.assertNotIn('gUnknown_82FA6D0', source)
        self.assertIn('sUnusedGameFreakName[6]', source)
        self.assertIn('section(".rodata.pokemon_unused_game_freak_name"), aligned(1)', source)

    @unittest.skipUnless(PREPROC.is_file() and (ROOT / 'baserom_jp.gba').is_file(), 'requires preproc and JP ROM')
    def test_unused_text_keeps_native_eos_and_fixed_width_zero(self):
        source = (ROOT / 'src/pokemon.c').read_text()
        declaration = re.search(r'static const u8 sUnusedGameFreakName\[6\][^;]+;', source).group(0)
        root = ROOT / '.tmp/agent-work/tests'
        root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='pokemon-boundary-', dir=root) as temp:
            path = Path(temp) / 'text.c'
            path.write_text(declaration + '\n')
            result = subprocess.check_output([str(PREPROC), str(path), str(ROOT / 'charmap.txt')], text=True)
        body = result.split('=', 1)[1]
        encoded = bytes(int(v, 16) for v in re.findall(r'0x([0-9A-Fa-f]+)', body))
        self.assertEqual(encoded, bytes.fromhex('8a ae 6c 78 ff'))
        self.assertEqual(encoded.ljust(6, b'\0'), (ROOT / 'baserom_jp.gba').read_bytes()[0x2fa6d0:0x2fa6d6])

    def test_native_linker_boundaries_are_explicit(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        text = 'src/pokemon.o(.rodata.pokemon_unused_game_freak_name)'
        left = 'src/pokemon.o(.rodata.pokemon_pp_up_and_stat_stage_data)'
        right = 'src/pokemon.o(.rodata.pokemon_battler_support_data)'
        self.assertEqual(linker.count(text), 1)
        self.assertLess(linker.index(left), linker.index(text))
        self.assertLess(linker.index(text), linker.index(right))
        self.assertRegex(linker, r'pokemon_battler_misc_data\);\s*\. = ALIGN\(2\);\s*src/pokemon.o\(\.rodata.pokemon_hm_and_altering_cave_data\)')
        self.assertRegex(linker, r'gUnknown_82FB764 = gEggMoves;\s*\. = ALIGN\(4\);\s*src/daycare.o\(\.rodata.daycare_level_menu_data\)')
        self.assertRegex(linker, r'strings_daycare\);\s*\. = ALIGN\(4\);\s*src/daycare.o\(\.rodata.daycare_compatibility_messages_data\)')

    def test_pokemon_build_uses_the_actual_text_preprocessor(self):
        make = (ROOT / 'Makefile').read_text()
        rule = re.search(r'(?m)^\$\(C_BUILDDIR\)/pokemon\.o: src/pokemon\.c charmap\.txt\n((?:\t[^\n]*\n)+)', make)
        self.assertIsNotNone(rule)
        self.assertIn('$(PREPROC) -i $< charmap.txt', rule.group(1))
        self.assertIn('$(CFLAGS)', rule.group(1))


if __name__ == '__main__':
    unittest.main()
