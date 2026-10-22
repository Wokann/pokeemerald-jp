"""All 75 JP tileset headers have a typed, read-only and byte-exact C owner."""
import hashlib
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest

try:
    from map_semantic_review import native_elf
except ModuleNotFoundError:
    from tools.map_semantic_review import native_elf

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
START, END = 0x083B7B24, 0x083B8234
HEADER = 'src/data/tilesets/headers.h'
FIELDS = ('isCompressed', 'isSecondary', 'tiles', 'palettes', 'metatiles', 'metatileAttributes', 'callback')
# These twelve formerly opaque headers had no real entry labels for any of
# their four backing resources. Resource byte order is independent of field order.
RAW_RESOURCES = (
    ('BattlePalace', 0x0835D1E8, 0x778, 0x0835D960, 0x200, 0x083A5E2A, 0xAE0, 0x083A690A, 0x15C),
    ('BattleDome', 0x0835DB60, 0x1250, 0x0835EDB0, 0x200, 0x083A6A66, 0x1AB0, 0x083A8516, 0x356),
    ('BattleFactory', 0x0835EFB0, 0x11EC, 0x0836019C, 0x200, 0x083A886C, 0x1620, 0x083A9E8C, 0x2C4),
    ('BattlePike', 0x0836039C, 0x12D4, 0x08361670, 0x200, 0x083AA150, 0x15B0, 0x083AB700, 0x2B6),
    ('BattleArena', 0x08361870, 0xB3C, 0x083623AC, 0x200, 0x083AB9B6, 0xB10, 0x083AC4C6, 0x162),
    ('BattlePyramid', 0x083625AC, 0x1210, 0x083637BC, 0x200, 0x083AC628, 0xDD0, 0x083AD3F8, 0x1BA),
    ('MirageTower', 0x083639BC, 0x1A48, 0x08365404, 0x200, 0x083AD5B2, 0x19E0, 0x083AEF92, 0x33C),
    ('IslandHarbor', 0x08365C24, 0x19D0, 0x083675F4, 0x200, 0x083AF688, 0x1D60, 0x083B13E8, 0x3AC),
    ('TrainerHill', 0x083677F4, 0x10F0, 0x083688E4, 0x200, 0x083B1794, 0x1E60, 0x083B35F4, 0x3CC),
    ('NavelRock', 0x08368AE4, 0x1B94, 0x0836A678, 0x200, 0x083B39C0, 0x1C30, 0x083B55F0, 0x386),
    ('BattleFrontierRankingHall', 0x0836A878, 0x854, 0x0836B0CC, 0x200, 0x083B5976, 0x5E0, 0x083B5F56, 0xBC),
    ('UnionRoom', 0x0836DC98, 0x878, 0x0836DA98, 0x200, 0x083B77B2, 0x310, 0x083B7AC2, 0x62),
)


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result.stdout


def headers():
    return [(name, dict(re.findall(r'\.(\w+) = (\w+),', body))) for name, body in re.findall(
        r'const struct Tileset (gTileset_\w+) TILESET_HEADER_DATA =\n\{\n(.*?)\n\};',
        (ROOT / HEADER).read_text(), re.S)]


class TilesetHeaderTests(unittest.TestCase):
    def test_whole_family_is_real_c_with_all_seven_fields_and_constant_pointers(self):
        source = (ROOT / HEADER).read_text()
        blocks = headers()
        self.assertEqual(len(blocks), 75)
        self.assertEqual(len({name for name, fields in blocks}), 75)
        self.assertEqual(blocks[0][0], 'gTileset_General')
        self.assertEqual(blocks[-1][0], 'gTileset_UnionRoom')
        for name, fields in blocks:
            self.assertEqual(tuple(fields), FIELDS, name)
            self.assertIn(fields['isCompressed'], ('TRUE', 'FALSE'))
            self.assertIn(fields['isSecondary'], ('TRUE', 'FALSE'))
        callbacks = [f['callback'] for name, f in blocks if f['callback'] != 'NULL']
        self.assertEqual(len(callbacks), 25)
        self.assertEqual(len(set(callbacks)), 25)
        self.assertEqual(re.findall(r'const struct Tileset \*const (\w+) TILESET_HEADER_DATA = &(\w+);', source),
                         [('gTilesetPointer_SecretBase', 'gTileset_SecretBase'),
                          ('gTilesetPointer_SecretBaseRedCave', 'gTileset_SecretBaseRedCave')])
        self.assertNotRegex(source, r'\.incbin|\.set\b|asm\s*\(|0x08[0-9A-Fa-f]{6}')
        self.assertFalse((ROOT / 'data/tilesets/headers.inc').exists())

    def test_real_resource_definitions_are_exported_without_aliases_or_duplicate_c_storage(self):
        source = (ROOT / 'src/tilesets.c').read_text()
        assets = '\n'.join((ROOT / path).read_text() for path in
                           ('data/tilesets.s', 'data/tilesets/graphics.inc', 'data/tilesets/metatiles.inc'))
        resources = {fields[field] for name, fields in headers() for field in FIELDS[2:6]}
        self.assertEqual(len(resources), 290)
        # General graphics already have a real C owner; do not duplicate them
        # in the assembly object merely to make the other resources uniform.
        general = {'gTilesetTiles_General', 'gTilesetPalettes_General'}
        graphics = (ROOT / 'src/graphics.c').read_text()
        for name in general:
            self.assertRegex(graphics, r'TILESET_GENERAL_DATA const u(?:16|32) ' + name + r'\[')
        for name in resources - general:
            pattern = r'(?m)^(?:\s*\.globl ' + name + r'\s*\n' + name + r':|' + name + r'::)'
            self.assertIsNotNone(re.search(pattern, assets), name)
        declarations = source + (ROOT / 'include/tilesets.h').read_text()
        for name, fields in headers():
            self.assertRegex(declarations, r'extern const u32 ' + fields['tiles'] + r'\[\];')
            self.assertRegex(declarations, r'extern const u16 ' + fields['palettes'] + r'\[\]\[16\];')
            for field in ('metatiles', 'metatileAttributes'):
                self.assertRegex(declarations, r'extern const u16 ' + fields[field] + r'\[\];')
        self.assertNotIn('INCBIN', source)
        self.assertNotIn('INCGFX', source)
        self.assertNotRegex(source, r'\.set|asm\s*\(')

    def test_all_forty_eight_new_resource_labels_retain_exact_bounded_raw_spans(self):
        source = '\n'.join((ROOT / path).read_text() for path in
                           ('data/tilesets/graphics.inc', 'data/tilesets/metatiles.inc'))
        total = 0
        for row in RAW_RESOURCES:
            owner, *ranges = row
            for prefix, address, size in zip(('gTilesetTiles_', 'gTilesetPalettes_', 'gMetatiles_', 'gMetatileAttributes_'),
                                             ranges[::2], ranges[1::2]):
                name = prefix + owner
                match = re.search(r'(?m)^' + name + r':[^\n]*\n\s*\.incbin "baserom_jp.gba", (0x\w+), (0x\w+)', source)
                self.assertIsNotNone(match, name)
                self.assertEqual(tuple(int(v, 16) for v in match.groups()), (address - BASE, size), name)
                total += size
        self.assertEqual(total, 124636)
        self.assertNotIn('.align', source[source.index('gMetatiles_BattlePalace:'):source.index('gMetatiles_BattleDome:')])

    def test_make_include_closure_and_native_linker_order_retire_the_old_header_owner(self):
        source = (ROOT / 'src/tilesets.c').read_text()
        self.assertIn('#include "data/tilesets/headers.h"', source)
        self.assertIn('section(".rodata.tileset_headers"), aligned(4)', source)
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('$(C_BUILDDIR)/tilesets.d: src/tilesets.c Makefile | tools', make)
        self.assertIn('-include $(C_BUILDDIR)/tilesets.d', make)
        self.assertIn('$(C_BUILDDIR)/tilesets.o: src/tilesets.c src/data/tilesets/headers.h Makefile', make)
        self.assertNotIn('data/tilesets/headers.inc', make)
        self.assertNotIn('headers.inc', (ROOT / 'data/tilesets.s').read_text())
        self.assertIn('data/tilesets.o(.rodata.tilesets);\n        src/tilesets.o(.rodata.tileset_headers);\n'
                      '        data/maps.o(.rodata.after_tilesets);', (ROOT / 'ld_script_jp.txt').read_text())

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires native JP artifacts')
    def test_all_native_header_fields_and_both_auxiliary_pointers_match_the_real_symbols(self):
        symbols, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        block = rom[START - BASE:END - BASE]
        self.assertEqual(hashlib.sha256(block).hexdigest(), 'a433cf4f18a1f7171eee896419fc9f720a985c0dfb0b82cf12a0fd23661a65aa')
        native = [data[START - base:END - base] for base, data in memory if base <= START and END <= base + len(data)]
        self.assertEqual(native, [block])
        for i, (name, fields) in enumerate(headers()):
            address = START + 24 * i + (8 if i >= 58 else 0)
            self.assertEqual(symbols[name], {address})
            flags = bytes((fields['isCompressed'] == 'TRUE', fields['isSecondary'] == 'TRUE', 0, 0))
            pointers = [0 if fields[field] == 'NULL' else next(iter(symbols[fields[field]])) for field in FIELDS[2:]]
            self.assertEqual(rom[address - BASE:address - BASE + 24], flags + struct.pack('<5I', *pointers), name)
        for name, address, target in (('gTilesetPointer_SecretBase', 0x083B8094, 'gTileset_SecretBase'),
                                      ('gTilesetPointer_SecretBaseRedCave', 0x083B8098, 'gTileset_SecretBaseRedCave')):
            self.assertEqual(symbols[name], {address})
            self.assertEqual(rom[address - BASE:address - BASE + 4], struct.pack('<I', next(iter(symbols[target]))))
        self.assertEqual(symbols['PetalburgCity_Layout_Border'], {END})

    @unittest.skipUnless((ROOT / 'build/pokeemerald-jp/src/tilesets.o').is_file(), 'requires native JP objects')
    def test_native_input_is_read_only_with_seventy_seven_typed_objects_and_no_resource_duplication(self):
        module = ROOT / 'build/pokeemerald-jp/src/tilesets.o'
        symbols = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', module], text=True)
        records = re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (gTileset(?:_|Pointer_)\w+)$', symbols)
        self.assertEqual(len(records), 77)
        self.assertEqual(sum(int(size, 16) for value, size, kind, name in records), END - START)
        for value, size, kind, name in records:
            self.assertEqual(int(size, 16), 4 if name.startswith('gTilesetPointer_') else 24)
            self.assertEqual(kind, 'R')
        sections = run(['tools/binutils/bin/arm-none-eabi-objdump', '-h', module], text=True)
        self.assertRegex(sections, r'\.rodata\.tileset_headers\s+00000710\b[^\n]*2\*\*2\n\s*CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA')
        for section in ('.text', '.data', '.bss'):
            self.assertRegex(sections, re.escape(section) + r'\s+00000000\b')
        relocs = run(['tools/binutils/bin/arm-none-eabi-objdump', '-r', module], text=True)
        self.assertEqual(len(re.findall(r'(?m)^[0-9a-f]+ R_ARM_ABS32\s+', relocs)), 327)
        link_map = (ROOT / 'pokeemerald_jp.map').read_text()
        self.assertRegex(link_map, r'\.rodata\.tileset_headers\s+0x0*83b7b24\s+0x710\s+src/tilesets\.o')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires native JP compiler and artifacts')
    def test_fresh_whole_c_constructor_reproduces_all_1808_bytes(self):
        temporary_root = ROOT / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='tileset-headers-', dir=temporary_root) as directory:
            temporary = Path(directory)
            source = (ROOT / 'src/tilesets.c').read_text()
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
                       '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc', '-undef',
                       '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True)
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'], input=cpp, text=True)
            module = temporary / 'module.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', module, '-'], input=assembly, text=True)
            script = temporary / 'module.ld'
            script.write_text('SECTIONS { .headers 0x083B7B24 : { *module.o(.rodata.tileset_headers) } /DISCARD/ : { *(*) } }\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), module])
            binary = temporary / 'headers.bin'
            run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=.headers', elf, binary])
            rom = (ROOT / 'baserom_jp.gba').read_bytes()
            self.assertEqual(binary.read_bytes(), rom[START - BASE:END - BASE])


if __name__ == '__main__':
    unittest.main()
