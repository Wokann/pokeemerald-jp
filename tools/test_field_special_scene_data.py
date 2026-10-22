"""The whole truck/S.S. Tidal data family retains its JP bytes and C owner."""
import hashlib
from pathlib import Path
import re
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
START, END = 0x0856A47C, 0x0856A494
SECTION = '.rodata.field_special_scene_data'
TABLES = [('sTruckCamera_HorizontalTable', START, 19),
          ('sSSTidalSailEastMovementScript', START + 19, 2),
          ('sSSTidalSailWestMovementScript', START + 21, 2)]


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result


class FieldSpecialSceneDataTests(unittest.TestCase):
    def test_complete_family_uses_typed_private_constants_and_semantic_movement_ids(self):
        source = (ROOT / 'src/field_special_scene.c').read_text()
        self.assertIn('static const s8 sTruckCamera_HorizontalTable[]', source)
        data = source.split('static const s8 sTruckCamera_HorizontalTable[]', 1)[1].split('static void Task_Truck3', 1)[0]
        self.assertEqual(data.count('section("' + SECTION + '"), aligned(1)'), 3)
        values = data.split('{', 1)[1].split('}', 1)[0]
        self.assertEqual([int(n) for n in values.split(',')], [0] * 8 + [1] + [2] * 6 + [-1] * 3 + [0])
        for name, start, size in TABLES:
            self.assertNotIn('extern const ' + ('s8 ' if size == 19 else 'u8 ') + name, source)
        self.assertIn('MOVEMENT_ACTION_WALK_FAST_RIGHT,\n    MOVEMENT_ACTION_STEP_END', data)
        self.assertIn('MOVEMENT_ACTION_WALK_FAST_LEFT,\n    MOVEMENT_ACTION_STEP_END', data)

    def test_retired_assembly_owner_is_replaced_with_native_linker_padding_and_dependencies(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('src/fldeff_misc.o(.rodata.fldeff_misc_data);\n        src/field_special_scene.o(' + SECTION + ');\n        . = ALIGN(4);\n        src/rotating_gate.o(.rodata.rotating_gate_data);', linker)
        self.assertNotIn('.rodata.mid60_tail_prefix', linker)
        self.assertFalse((ROOT / 'data/field_special_scene/truck_and_ss_tidal.inc').exists())
        remainder = (ROOT / 'data/data_b2d_mid60.s').read_text()
        self.assertNotIn('truck_and_ss_tidal.inc', remainder)
        self.assertIn('.incbin "baserom_jp.gba", 0x5733b0, 0x20', remainder)
        self.assertIn('$(C_BUILDDIR)/field_special_scene.d: src/field_special_scene.c Makefile | tools', make)
        self.assertIn('-include $(C_BUILDDIR)/field_special_scene.d', make)
        self.assertIn('$(C_BUILDDIR)/field_special_scene.o: CFLAGS := -mthumb-interwork -O2 -fhex-asm -ffunction-sections', make)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires native JP artifacts')
    def test_three_real_local_objects_preserve_exact_sizes_and_alignment_is_not_an_element(self):
        symbols = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', 'pokeemerald_jp.elf'], text=True).stdout
        for name, address, size in TABLES:
            matches = re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) ' + name + '$', symbols)
            self.assertEqual([(int(a, 16), int(s, 16)) for a, s, kind in matches], [(address, size)])
            self.assertIn(matches[0][2], ('r', 'd'))
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        block = rom[START - BASE:END - BASE]
        self.assertEqual(block, bytes([0] * 8 + [1] + [2] * 6 + [255] * 3 + [0, 0x18, 0xFE, 0x17, 0xFE, 0]))
        self.assertEqual(hashlib.sha256(block).hexdigest(), '970b198f512465db5e0016283b04572acc0358d1bc1bb4753ef8bd69a46ad169')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires native JP artifacts and compiler')
    def test_fresh_whole_module_rebuilds_all_thirteen_functions_three_tables_and_padding(self):
        temporary_root = ROOT / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='field-special-scene-', dir=temporary_root) as directory:
            temporary = Path(directory)
            source = (ROOT / 'src/field_special_scene.c').read_text()
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
                       '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
                       '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm',
                            '-ffunction-sections', '-o', '-', '-'], input=cpp, text=True).stdout
            assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
            module = temporary / 'module.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', module, '-'], input=assembly, text=True)
            fresh_symbols = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', module], text=True).stdout
            names = re.findall(r'(?m)^[0-9a-f]+ [0-9a-f]+ [tT] (\w+)$', fresh_symbols)
            self.assertEqual(len(names), 13)
            native_symbols = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', 'pokeemerald_jp.elf'], text=True).stdout
            script_lines = ['SECTIONS {']
            spans = []
            for name in names:
                records = re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) [tT] ' + name + '$', native_symbols)
                self.assertEqual(len(records), 1, name)
                address, size = (int(v, 16) for v in records[0])
                address &= ~1
                section = '.text.' + name
                script_lines.append('%s 0x%X : { *module.o(%s) }' % (section, address, section))
                spans.append((section, address, address + size))
            script_lines += ['.data 0x0856A47C : { *module.o(' + SECTION + ') . = ALIGN(4); }', '/DISCARD/ : { *(*) }', '}']
            script = temporary / 'module.ld'
            script.write_text('\n'.join(script_lines) + '\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), module])
            rom = (ROOT / 'baserom_jp.gba').read_bytes()
            for index, (section, address, end) in enumerate(spans + [('.data', START, END)]):
                target = temporary / ('section-%d.bin' % index)
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + section, elf, target])
                self.assertEqual(target.read_bytes(), rom[address - BASE:end - BASE], section)


if __name__ == '__main__':
    unittest.main()
