"""Gift ribbon constants retain their actual seven-byte JP table and native behavior."""
import hashlib
from pathlib import Path
import re
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
CODE_START = 0x080FA3A0
TABLE_START, TABLE_END = 0x08569552, 0x0856955C


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result


class GiftRibbonDataTests(unittest.TestCase):
    def test_seven_semantic_fields_belong_to_the_real_consumer_not_the_transition_file(self):
        source = (ROOT / 'src/give_gift_ribbon_to_party.c').read_text()
        self.assertIn('static const u8 sGiftRibbonsMonDataIds[GIFT_RIBBONS_COUNT - 4]', source)
        self.assertIn('section(".rodata.gift_ribbon_data"), aligned(1)', source)
        block = source.split('=\n{', 1)[1].split('};', 1)[0]
        self.assertEqual(re.findall(r'MON_DATA_\w+', block), ['MON_DATA_' + name + '_RIBBON'
                         for name in ('MARINE', 'LAND', 'SKY', 'COUNTRY', 'NATIONAL', 'EARTH', 'WORLD')])
        self.assertNotIn('extern const u8 sGiftRibbonsMonDataIds', source)
        self.assertNotIn('sGiftRibbonsMonDataIds', (ROOT / 'data/data_b2d_mid60.s').read_text())
        self.assertIn('memcpy(array, sGiftRibbonsMonDataIds, sizeof(sGiftRibbonsMonDataIds));', source)
        self.assertIn('if (index < GIFT_RIBBONS_COUNT && ribbonId <= MAX_GIFT_RIBBON)', source)

    def test_linker_padding_dependencies_and_unknown_mid60_raw_are_preserved(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('src/give_gift_ribbon_to_party.o(.rodata.gift_ribbon_data);\n        . = ALIGN(4);\n        src/fldeff_misc.o(.rodata.fldeff_misc_data);', linker)
        self.assertNotIn('data/data_b2d_mid60.o(.rodata);', linker)
        self.assertIn('$(C_BUILDDIR)/give_gift_ribbon_to_party.d: src/give_gift_ribbon_to_party.c Makefile | tools', make)
        self.assertIn('-include $(C_BUILDDIR)/give_gift_ribbon_to_party.d', make)
        self.assertIn('$(C_BUILDDIR)/give_gift_ribbon_to_party.o: src/give_gift_ribbon_to_party.c Makefile', make)
        remainder = (ROOT / 'data/data_b2d_mid60.s').read_text()
        self.assertIn('.incbin "baserom_jp.gba", 0x5733b0, 0x20', remainder)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires JP native artifacts')
    def test_real_local_table_is_seven_bytes_and_native_padding_is_separate(self):
        symbols = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', ROOT / 'pokeemerald_jp.elf'], text=True).stdout
        matches = re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) sGiftRibbonsMonDataIds$', symbols)
        self.assertEqual([(a, s) for a, s, kind in matches], [('08569552', '00000007')])
        # The legacy aggregate ROM output section may inherit WRITE from other
        # inputs; lowercase still proves that this real object is file-local.
        self.assertIn(matches[0][2], ('r', 'd'))
        sections = run(['tools/binutils/bin/arm-none-eabi-objdump', '-h',
                        ROOT / 'build/pokeemerald-jp/src/give_gift_ribbon_to_party.o'], text=True).stdout
        own = sections.split('.rodata.gift_ribbon_data', 1)[1].splitlines()[1]
        self.assertIn('READONLY', own)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(rom[TABLE_START - BASE:TABLE_END - BASE], bytes.fromhex('48 49 4A 4B 4C 4D 4E 00 00 00'))
        self.assertEqual(hashlib.sha256(rom[CODE_START - BASE:CODE_START - BASE + 156]).hexdigest(),
                         '15449128815c4df8e704d580b3f4a902d2fc91fe34d12b58b25c33e0a3599e79')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires JP native artifacts and compiler')
    def test_fresh_full_module_reproduces_code_table_and_three_alignment_bytes(self):
        temporary_root = ROOT / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='gift-ribbon-', dir=temporary_root) as directory:
            temporary = Path(directory)
            source = (ROOT / 'src/give_gift_ribbon_to_party.c').read_text()
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
                       '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
                       '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'], input=cpp, text=True).stdout
            assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
            module = temporary / 'module.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', module, '-'], input=assembly, text=True)
            script = temporary / 'module.ld'
            script.write_text('SECTIONS {\n.text 0x080FA3A0 : { *module.o(.text) }\n'
                              '.data 0x08569552 : { *module.o(.rodata.gift_ribbon_data) . = ALIGN(4); }\n'
                              '/DISCARD/ : { *(*) }\n}\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), module])
            rom = (ROOT / 'baserom_jp.gba').read_bytes()
            for name, start, end in (('.text', CODE_START, CODE_START + 156), ('.data', TABLE_START, TABLE_END)):
                target = temporary / (name[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + name, elf, target])
                self.assertEqual(target.read_bytes(), rom[start - BASE:end - BASE], name)


if __name__ == '__main__':
    unittest.main()
