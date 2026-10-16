#!/usr/bin/env python3
"""The whole Contest graphics family and Results UI retain JP native data."""
import re
import shlex
import shutil
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
NM = shutil.which('arm-none-eabi-nm')
COMPOSITES = {
    'graphics/contest/japanese/composite_1.4bpp': [
        'graphics/contest/japanese/' + n + '.png'
        for n in ('frame_1', 'floor', 'frame_2', 'symbols', 'meter', 'letters', 'numbers')
    ],
    'graphics/contest/japanese/composite_2.4bpp': [
        'graphics/contest/japanese/interface.png', 'graphics/contest/japanese/audience.png'
    ],
}


def resources():
    text = (ROOT / 'src/graphics.c').read_text()
    rows = re.findall(r'const (u\d+) (\w+)\[\] = INCGFX_U\d+\("(graphics/contest/[^"]+)", "([^"]+)"(?:, "([^"]+)")?\);', text)
    text = (ROOT / 'src/contest_util.c').read_text().split('#undef CONTEST_RESULTS_SUFFIX', 1)[0]
    rows += re.findall(r'const (u\d+) (\w+)\[\] = INCGFX_U\d+\("([^"]+)", "([^"]+)"(?:, "([^"]+)")?\);', text)
    return rows


class ContestAssetTests(unittest.TestCase):
    def test_complete_graphics_family_is_source_backed(self):
        rows = resources()
        self.assertEqual(len(rows), 35)
        inputs = {p for t, n, p, e, f in rows if p not in COMPOSITES}
        inputs.update(p for parts in COMPOSITES.values() for p in parts)
        self.assertEqual(len(inputs), 36)
        for path in inputs:
            self.assertTrue((ROOT / path).is_file(), path)
        source = (ROOT / 'src/graphics.c').read_text()
        self.assertNotRegex(source, r'INCBIN_U\d+\("graphics/contest/')
        # Confetti remains a genuine shared Hall of Fame / Contest global.
        self.assertIn('gConfetti_Gfx[]', source)
        self.assertIn('gConfetti_Pal[]', source)

    def test_native_localization_and_crop_parameters_are_preserved(self):
        data = (ROOT / 'graphics/contest/nextturn.png').read_bytes()
        self.assertEqual(struct.unpack('>II', data[16:24]), (40, 8))
        self.assertEqual([(n, f) for t, n, p, e, f in resources() if f],
                         [('gJPContestVoltageGfx', '-num_tiles 36 -Wnum_tiles')])
        source = (ROOT / 'src/contest_util.c').read_text()
        self.assertIn('sContestLinkTextColors[4] = {3, 4, 5, 14}', source)
        windows = source.split('struct WindowTemplate sWindowTemplates[]', 1)[1].split('};', 1)[0]
        self.assertEqual(windows.count('.baseBlock ='), 8)
        self.assertEqual(windows.count('DUMMY_WIN_TEMPLATE'), 1)
        self.assertIn('(SpriteCallback)sub_080F7FF8', source)

    def test_all_eleven_jp_title_tilemaps_are_structured(self):
        source = (ROOT / 'src/graphics.c').read_text()
        rows = re.findall(r'CONTEST_RESULTS_TITLE_TILEMAPS const u16 (gContestResultsTitle_\w+)\[\] =\n\{\n(.*?)\n\};', source, re.S)
        self.assertEqual(len(rows), 11)
        self.assertEqual([len(re.findall(r'0x[0-9A-F]{4}', body)) for n, body in rows], [16] * 5 + [10] * 6)
        rom = ROOT / 'baserom_jp.gba'
        if rom.is_file():
            encoded = b''.join(struct.pack('<H', int(v, 16)) for name, body in rows
                               for v in re.findall(r'0x[0-9A-F]{4}', body))
            self.assertEqual(encoded, rom.read_bytes()[0x569334:0x56944c])

    def test_build_clean_link_owners_and_aliases_are_closed(self):
        make = (ROOT / 'Makefile').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertFalse((ROOT / 'data/contest_results.s').exists())
        self.assertFalse((ROOT / 'data/contest/contest_results.inc').exists())
        self.assertNotIn('data/contest_results.o', make + linker)
        for section in ('src/contest_util.o(.rodata.contest_results_prefix)',
                        'src/graphics.o(.rodata.contest_results_title_tilemaps)',
                        'src/contest_util.o(.rodata.contest_results_suffix)'):
            self.assertEqual(linker.count(section), 1)
        self.assertLess(linker.index('.rodata.contest_results_prefix'), linker.index('.rodata.contest_results_title_tilemaps'))
        self.assertLess(linker.index('.rodata.contest_results_title_tilemaps'), linker.index('.rodata.contest_results_suffix'))
        self.assertIn('$(JP_CONTEST_ASSETS) $(JP_CONTEST_INTERMEDIATES)', make)
        self.assertIn('rm -f $(JP_CONTEST_RESULTS_ASSETS)', make)
        rule = make.split('$(C_BUILDDIR)/contest_util.o:', 1)[1].split('\n\n', 1)[0]
        self.assertIn('$(JP_CONTEST_RESULTS_ASSETS)', rule)
        self.assertIn('include/util.h', rule)
        self.assertIn('$(PREPROC) -i $< charmap.txt', rule)
        self.assertIn('$(GFX) $< $@ -num_tiles 36 -Wnum_tiles', make)
        for target, parts in COMPOSITES.items():
            self.assertIn(target + ': ' + ' '.join(p + '.4bpp' for p in parts) + ' Makefile\n\tcat $(filter %.4bpp,$^) >$@', make)
        source = (ROOT / 'src/contest.c').read_text() + (ROOT / 'src/contest_util.c').read_text() + linker
        for address in ('16E98', '16FB0', '17178', '17988', '17AB8', '18650',
                        '196CC', '19F34', '1A048', '1A174', '1A2FC', '1C700'):
            self.assertNotIn('gUnknown_8C' + address, source)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires native JP artifacts and gbagfx')
    def test_all_thirty_five_graphics_regenerate_native_bytes(self):
        output = subprocess.check_output([NM, '-S', '--defined-only', str(ROOT / 'pokeemerald_jp.elf')], text=True)
        symbols = {}
        for address, size, kind, name in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output):
            symbols.setdefault(name, []).append((int(address, 16), int(size, 16)))
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        total = 0
        with tempfile.TemporaryDirectory(prefix='contest-assets-', dir=temp_root) as temp:
            for i, (ctype, name, path, extension, flags) in enumerate(resources()):
                candidates = symbols[name]
                if name.startswith('s'):
                    candidates = [(a, s) for a, s in candidates if 0x856915c <= a < 0x85694d0]
                self.assertEqual(len(candidates), 1, name)
                address, size = candidates[0]
                target = Path(temp) / (str(i) + extension)
                if path in COMPOSITES:
                    parts = []
                    for j, component in enumerate(COMPOSITES[path]):
                        part = Path(temp) / (str(i) + '-' + str(j) + '.4bpp')
                        subprocess.run([str(GFX), str(ROOT / component), str(part)], check=True, capture_output=True)
                        parts.append(part.read_bytes())
                    raw = target.with_name(str(i) + '.4bpp')
                    raw.write_bytes(b''.join(parts))
                elif path.endswith('.bin'):
                    raw = ROOT / path
                else:
                    raw = target.with_name(target.name.removesuffix('.lz'))
                    subprocess.run([str(GFX), str(ROOT / path), str(raw), *shlex.split(flags)], check=True, capture_output=True)
                if extension.endswith('.lz'):
                    subprocess.run([str(GFX), str(raw), str(target)], check=True, capture_output=True)
                else:
                    target = raw
                self.assertEqual(target.stat().st_size, size, name)
                self.assertEqual(target.read_bytes(), rom[address - 0x8000000:address - 0x8000000 + size], name)
                total += size
        self.assertEqual(total, 23232)


if __name__ == '__main__':
    unittest.main()
