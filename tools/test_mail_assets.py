"""Rebuild the complete Mail source family without reusing generated assets."""
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
FUNCTIONS = (
    'ReadMail', 'MailReadBuildGraphics', 'CB2_InitMailRead', 'BufferMailText',
    'PrintMailText', 'VBlankCB_MailRead', 'CB2_MailRead',
    'CB2_WaitForPaletteExitOnKeyPress', 'CB2_ExitOnKeyPress', 'CB2_ExitMailReadFreeVars',
)
STYLES = ('Orange', 'Harbor', 'Glitter', 'Mech', 'Wood', 'Wave',
          'Bead', 'Shadow', 'Tropic', 'Dream', 'Fab', 'Retro')


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result


def resources():
    return re.findall(r'^MAIL_GRAPHICS const (u\d+) (gMail\w+)\[\] = '
                      r'INCGFX_U\d+\("([^"]+)", "([^"]+)"\);',
                      (ROOT / 'src/data/graphics/mail.h').read_text(), re.M)


def symbols():
    text = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only',
                ROOT / 'pokeemerald_jp.elf'], text=True).stdout
    result = {}
    for address, size, kind, name in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', text):
        result.setdefault(name, []).append((int(address, 16), int(size, 16)))
    return result


def compile_c(source, output, label, function_sections=False):
    cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
               '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
               '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
    pre = run(['tools/preproc/preproc', '-i', label, 'charmap.txt'], input=cpp, text=True).stdout
    flags = ['-ffunction-sections'] if function_sections else []
    assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm',
                    *flags, '-o', '-', '-'], input=pre, text=True).stdout
    assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
    run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', output, '-'],
        input=assembly, text=True)


class MailAssetsTests(unittest.TestCase):
    def test_all_twelve_triplets_use_final_paths_and_existing_public_symbols(self):
        rows = resources()
        self.assertEqual(len(rows), 36)
        self.assertEqual([name for c, name, p, e in rows],
                         ['gMail' + kind + '_' + style
                          for kind in ('Palette', 'Tiles', 'Tilemap') for style in STYLES])
        self.assertEqual(len({p for c, n, p, e in rows}), 36)
        header = (ROOT / 'include/graphics.h').read_text()
        mail = (ROOT / 'src/mail.c').read_text()
        for ctype, name, path, extension in rows:
            self.assertTrue((ROOT / path).is_file(), path)
            self.assertEqual(header.count('extern const ' + ctype + ' ' + name + '[];'), 1, name)
            self.assertEqual(len(re.findall(r'\b' + name + r'\b', mail)), 1, name)
        self.assertNotRegex(mail, r'MAIL_(?:PALETTE|TILES|TILEMAP)_|0x08D[B-C][0-9A-Fa-f]{4}')
        self.assertNotIn('baserom_jp.gba', mail)

    def test_japanese_reader_layout_and_exact_eos_expression_are_retained(self):
        mail = (ROOT / 'src/mail.c').read_text()
        for text in ('u8 message[8][24];', 'u8 playerName[12];',
                     '/*0x0DD*/ u8 international;', '/*0x0DE*/ u8 language;',
                     '/*0x0EC*/ u8 bg1TilemapBuffer[0x1000];',
                     '/*0x10EC*/ u8 bg2TilemapBuffer[0x1000];',
                     'u8 signatureYPos:4;', 'u8 signatureWidth:4;', 'u8 unused[2];',
                     'const u8 sMailFromText[] MAIL_DATA = _("　より");'):
            self.assertIn(text, mail)
        self.assertNotIn('_("　より$")', mail)
        for name in ('Wide', 'Tall'):
            block = mail.split('sMailLayouts_' + name + '[] MAIL_DATA =', 1)[1].split('};', 1)[0]
            self.assertEqual(block.count('.numLines = '), 12)
        # These original unused fields are not the compressed-stream lengths.
        wood = mail.split('.palette = gMailPalette_Wood,', 1)[1].split('},', 1)[0]
        retro = mail.split('.palette = gMailPalette_Retro,', 1)[1].split('},', 1)[0]
        self.assertIn('.unused = 0x2E0', wood)
        self.assertIn('.unused = 0x520', retro)

    def test_build_clean_and_link_owners_cover_sources_without_absorbing_neighbors(self):
        make = (ROOT / 'Makefile').read_text()
        ld = (ROOT / 'ld_script_jp.txt').read_text()
        rest = (ROOT / 'data/data_rest2c.s').read_text()
        self.assertIn('#include "data/graphics/mail.h"', (ROOT / 'src/graphics.c').read_text())
        self.assertIn('$(C_BUILDDIR)/graphics.o: src/data/graphics/mail.h $(JP_MAIL_ASSETS)', make)
        self.assertIn('rm -f $(JP_MAIL_ASSETS) $(JP_MAIL_INTERMEDIATES)', make)
        self.assertIn('$(C_BUILDDIR)/mail.d: src/mail.c Makefile | tools', make)
        self.assertIn('-include $(C_BUILDDIR)/mail.d', make)
        self.assertIn('$(C_BUILDDIR)/mail.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections', make)
        recipe = make.split('$(C_BUILDDIR)/mail.o: src/mail.c', 1)[1]
        self.assertIn('$(PREPROC) -i $< charmap.txt', recipe)
        for c, n, path, extension in resources():
            self.assertIn(path + extension, make)
        selectors = ['src/graphics.o(.rodata.roulette_graphics);',
                     'src/graphics.o(.rodata.mail_graphics);',
                     'data/data_rest2c.o(.rodata.data_rest2c_after_mail_graphics);']
        self.assertEqual([ld.count(s) for s in selectors], [1, 1, 1])
        self.assertEqual(sorted(ld.index(s) for s in selectors), [ld.index(s) for s in selectors])
        self.assertIn('src/mail.o(.rodata.mail_data);', ld)
        self.assertIn('0xDC09BC, 0x23F644', rest)
        self.assertNotIn('0xDBEAC0', rest)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires JP native artifacts')
    def test_native_table_has_36_real_asset_pointers_and_no_extra_suffix_byte(self):
        named = symbols()
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(named['sMailGraphics'], [(0x0857AEE4, 240)])
        self.assertEqual(named['sMailLayouts_Wide'], [(0x0857AFE0, 96)])
        self.assertEqual(named['sMailLayouts_Tall'], [(0x0857B054, 96)])
        self.assertEqual(named['sMailFromText'], [(0x0857B0B4, 4)])
        self.assertEqual(rom[0x57B0B4:0x57B0B8], bytes.fromhex('00 26 28 FF'))
        self.assertEqual([n for c, n, p, e in resources()][:12],
                         ['gMailPalette_' + style for style in STYLES])
        cursor = 0x08DBEAC0
        for c, name, path, extension in resources():
            self.assertEqual(len(named[name]), 1, name)
            address, size = named[name][0]
            self.assertEqual(address, cursor, name)
            self.assertGreater(size, 0, name)
            cursor += size
        self.assertEqual(cursor, 0x08DC09BC)
        for i, style in enumerate(STYLES):
            expected = tuple(named['gMail' + kind + '_' + style][0][0]
                             for kind in ('Palette', 'Tiles', 'Tilemap'))
            self.assertEqual(struct.unpack_from('<III', rom, 0x57AEE4 + i * 20), expected)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file()
                         and (ROOT / 'tools/gbagfx/gbagfx').is_file(), 'requires JP native artifacts and gbagfx')
    def test_fresh_sources_reproduce_all_code_reader_data_and_36_graphics_objects(self):
        temporary_root = ROOT / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='mail-family-', dir=temporary_root) as directory:
            temporary = Path(directory)
            graphics = '#include "global.h"\n#define MAIL_GRAPHICS __attribute__((section(".rodata.mail_graphics"), aligned(4)))\n'
            graphics += (ROOT / 'src/data/graphics/mail.h').read_text()
            for i, (ctype, name, path, extension) in enumerate(resources()):
                output = temporary / (str(i) + extension)
                if path.endswith('.bin'):
                    raw = ROOT / path
                else:
                    raw = output.with_name(output.name.removesuffix('.lz'))
                    run(['tools/gbagfx/gbagfx', ROOT / path, raw])
                if extension.endswith('.lz'):
                    run(['tools/gbagfx/gbagfx', raw, output])
                else:
                    output = raw
                before = 'INCGFX_U' + ctype[1:] + '("' + path + '", "' + extension + '")'
                self.assertEqual(graphics.count(before), 1)
                graphics = graphics.replace(before, 'INCBIN_U' + ctype[1:] + '("' + str(output) + '")')
            module, gfx = temporary / 'mail.o', temporary / 'graphics.o'
            compile_c((ROOT / 'src/mail.c').read_text(), module, 'src/mail.c', function_sections=True)
            compile_c(graphics, gfx, 'src/graphics.c')
            script = temporary / 'module.ld'
            script.write_text('SECTIONS {\n.text 0x08121568 : {\n'
                + ''.join('*mail.o(.text.' + name + ')\n' for name in FUNCTIONS)
                + '}\n.data 0x0857AEB4 : { *mail.o(.rodata.mail_data) }\n'
                '.graphics 0x08DBEAC0 : { *graphics.o(.rodata.mail_graphics) }\n'
                '/DISCARD/ : { *(*) }\n}\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), module, gfx])
            for name, start, end in (('.text', 0x08121568, 0x08121D90),
                                     ('.data', 0x0857AEB4, 0x0857B0B8),
                                     ('.graphics', 0x08DBEAC0, 0x08DC09BC)):
                output = temporary / (name[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + name, elf, output])
                self.assertEqual(output.read_bytes(), rom[start - BASE:end - BASE], name)


if __name__ == '__main__':
    unittest.main()
