"""The complete Roulette data/graphics family retains native JP behavior."""
import hashlib
from pathlib import Path
import re
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
COMPOSITES = {
    'graphics/roulette/roulette_tilt.4bpp': ['graphics/roulette/shroomish.png', 'graphics/roulette/tailow.png'],
    'graphics/roulette/wheel_icons.4bpp': ['graphics/roulette/' + n + '.png' for n in ('wynaut', 'azurill', 'skitty', 'makuhita')],
}


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result


def resources():
    rows = []
    for file, owner, macro in [('src/roulette.c', 'roulette', 'ROULETTE_DATA static'),
                               ('src/graphics.c', 'graphics', 'ROULETTE_GRAPHICS')]:
        text = (ROOT / file).read_text()
        rows += [(owner, *match) for match in re.findall(
            r'^' + macro + r' const (u\d+) (\w+)\[\] = INCGFX_U\d+\("([^"]+)", "([^"]+)"\);', text, re.M)]
    return rows


def compile_c(source, output, label):
    cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
               '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
               '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
    pre = run(['tools/preproc/preproc', '-i', label, 'charmap.txt'], input=cpp, text=True).stdout
    assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'],
                   input=pre, text=True).stdout
    assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
    run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', output, '-'], input=assembly, text=True)


class RouletteDataTests(unittest.TestCase):
    def test_whole_native_owner_is_typed_and_all_aliases_are_real_references(self):
        text = (ROOT / 'src/roulette.c').read_text()
        self.assertFalse((ROOT / 'src/data/roulette_data.s').exists())
        self.assertEqual(text.count('ROULETTE_DATA static const '), 153)
        self.assertEqual(text.count('__attribute__((naked))'), 104)
        self.assertNotRegex(text, r'gUnknown_859[0-9A-Fa-f]+')
        self.assertIn('.4byte sGridSelections + 12', text)
        self.assertIn('.4byte sRouletteSlots + 4', text)
        self.assertNotIn('.set ', text)
        self.assertNotIn('baserom_jp.gba', text)

    def test_localization_unused_records_shared_animation_and_native_alignment_survive(self):
        text = (ROOT / 'src/roulette.c').read_text()
        windows = text.split('struct WindowTemplate sWindowTemplates[] =', 1)[1].split('};', 1)[0]
        self.assertIn('.baseBlock = 0xD6', windows)
        self.assertNotIn('DUMMY_WIN_TEMPLATE', windows)
        self.assertIn('sUnusedText_NumberOfCoins[8] = _("{STR_VAR_1}まい")', text)
        self.assertIn('sFiller[3] = {}', text)
        self.assertIn('sBoardColumnFlags[NUM_BOARD_POKES] __attribute__((aligned(4)))', text)
        self.assertIn('sShroomishShadowCoords[2][2] __attribute__((aligned(2)))', text)
        for n in range(1, 5):
            self.assertIn('sUnused' + str(n) + '_Pal[]', text)
        digits = text.split('union AnimCmd sAnim_CreditDigit[] =', 1)[1].split('};', 1)[0]
        self.assertEqual(digits.count('ANIMCMD_FRAME'), 10)
        self.assertIn('#ifdef BUGFIX', digits)
        balls = text.split('sAnims_Ball[] =', 1)[1].split('};', 1)[0]
        self.assertEqual(balls.count('sAnim_Ball_StopOnFrame4'), 2)

    def test_complete_source_asset_family_and_composites_are_present(self):
        rows = resources()
        self.assertEqual(len(rows), 33)
        self.assertEqual(sum(owner == 'roulette' for owner, *rest in rows), 26)
        paths = {p for owner, c, n, p, e in rows if p not in COMPOSITES}
        paths.update(p for sources in COMPOSITES.values() for p in sources)
        self.assertEqual(len(paths), 24)
        for path in paths:
            self.assertTrue((ROOT / path).is_file(), path)
        self.assertIn(('graphics', 'u32', 'gRouletteWheel_Gfx', 'graphics/roulette/wheel.png', '.8bpp.lz'), rows)
        self.assertFalse((ROOT / 'graphics/roulette/gRouletteMenu_Gfx.bin').exists())
        self.assertFalse((ROOT / 'graphics/misc/gRouletteWheel_Gfx.4bpp.lz').exists())

    def test_build_generation_clean_and_link_owners_match_native_boundaries(self):
        make = (ROOT / 'Makefile').read_text()
        ld = (ROOT / 'ld_script_jp.txt').read_text()
        rest = (ROOT / 'data/data_rest2c.s').read_text()
        self.assertNotIn('src/data/roulette_data.o', make + ld)
        self.assertIn('src/roulette.o(.rodata.roulette_data);', ld)
        self.assertIn('src/graphics.o(.rodata.roulette_graphics);', ld)
        self.assertIn('data/data_rest2c.o(.rodata.data_rest2c_after_roulette_graphics);', ld)
        self.assertIn('0xDBEAC0, 0x241540', rest)
        self.assertNotIn('0xDBDD61', rest)
        self.assertNotIn('gRouletteMenu_Gfx:', rest)
        self.assertNotIn('gRouletteWheel_Gfx:', rest)
        self.assertIn('rm -f $(JP_ROULETTE_ASSETS) $(JP_ROULETTE_INTERMEDIATES)', make)
        self.assertIn('$(C_BUILDDIR)/roulette.d: src/roulette.c Makefile | tools', make)
        self.assertIn('-include $(C_BUILDDIR)/roulette.d', make)
        block = make.split('$(C_BUILDDIR)/roulette.o: src/roulette.c', 1)[1]
        self.assertIn('$(JP_ROULETTE_ASSETS)', block)
        self.assertIn('$(PREPROC) -i $< charmap.txt', block)
        for path, sources in COMPOSITES.items():
            self.assertIn(path + ': ' + ' '.join(p + '.4bpp' for p in sources) + ' Makefile\n\tcat $(filter %.4bpp,$^) >$@', make)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file()
                         and (ROOT / 'tools/gbagfx/gbagfx').is_file(), 'requires JP native artifacts and gbagfx')
    def test_fresh_sources_reproduce_the_entire_code_data_and_global_graphics(self):
        temporary_root = ROOT / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='roulette-family-', dir=temporary_root) as directory:
            temporary = Path(directory)
            source = (ROOT / 'src/roulette.c').read_text()
            graphics = '#include "global.h"\n#define ROULETTE_GRAPHICS __attribute__((section(".rodata.roulette_graphics"), aligned(4)))\n'
            graphics += '\n'.join(re.findall(r'^ROULETTE_GRAPHICS const u32 gRoulette[^\n]+', (ROOT / 'src/graphics.c').read_text(), re.M)) + '\n'
            for i, (owner, ctype, name, path, extension) in enumerate(resources()):
                output = temporary / (str(i) + extension)
                if path in COMPOSITES:
                    pieces = []
                    for j, part_path in enumerate(COMPOSITES[path]):
                        target = temporary / (str(i) + '-part-' + str(j) + '.4bpp')
                        run(['tools/gbagfx/gbagfx', ROOT / part_path, target])
                        pieces.append(target.read_bytes())
                    raw = temporary / (str(i) + '-composite.4bpp')
                    raw.write_bytes(b''.join(pieces))
                elif path.endswith('.bin'):
                    raw = ROOT / path
                else:
                    raw = output.with_name(output.name.removesuffix('.lz'))
                    run(['tools/gbagfx/gbagfx', ROOT / path, raw])
                if extension.endswith('.lz'):
                    run(['tools/gbagfx/gbagfx', raw, output])
                else:
                    output = raw
                before = 'INCGFX_U' + ctype[1:] + '("' + path + '", "' + extension + '")'
                after = 'INCBIN_U' + ctype[1:] + '("' + str(output) + '")'
                if owner == 'roulette':
                    self.assertEqual(source.count(before), 1)
                    source = source.replace(before, after)
                else:
                    self.assertEqual(graphics.count(before), 1)
                    graphics = graphics.replace(before, after)
            module, gfx = temporary / 'roulette.o', temporary / 'graphics.o'
            compile_c(source, module, 'src/roulette.c')
            compile_c(graphics, gfx, 'src/graphics.c')
            script = temporary / 'module.ld'
            script.write_text('SECTIONS {\n'
                '.text 0x08140300 : { *roulette.o(.text) }\n'
                '.data 0x085957A8 : { *roulette.o(.rodata.roulette_data) }\n'
                '.graphics 0x08DBC590 : { *graphics.o(.rodata.roulette_graphics) }\n'
                '/DISCARD/ : { *(*) }\n}\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), module, gfx])
            for name, start, end, digest in (
                ('.text', 0x08140300, 0x08145420, 'b1d07efd501876a9faeb7ba9dcd1506e3af608482c27e8620866069cc6b15c4d'),
                ('.data', 0x085957A8, 0x0859770C, '2ddd555b056820f11f2d6957992484244745f469c14bc0be3d5a432564b568e4'),
                ('.graphics', 0x08DBC590, 0x08DBEAC0, '1e3f92f7632e168ad64d22e262e3ab6118b97d1393ca4e78154a0412c67bf1c6'),
            ):
                output = temporary / (name[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + name, elf, output])
                actual = output.read_bytes()
                self.assertEqual(actual, rom[start - BASE:end - BASE], name)
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest, name)


if __name__ == '__main__':
    unittest.main()
