"""Complete native-asset/JSON region-map ownership, not partial table checks."""

import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest

from jp_script_text import JapaneseScriptTextCodec


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / 'pokeemerald'
JSON_PATH = 'src/data/region_map/region_map_sections.json'
TEMPLATES = ('src/data/region_map/region_map_sections.json.txt',
             'src/data/region_map/region_map_sections.constants.json.txt')
GENERATED = ('src/data/region_map/region_map_entries.h',
             'include/constants/region_map_sections.h')
CODE_START, CODE_END = 0x08122CE8, 0x08124F14
DATA_START, DATA_END = 0x0857B1BC, 0x0857D884
CODE_SHA256 = 'ad563ea46b01e53ed16f405ec3bf868b816055d62aa013c4a96492cff9647bdb'
DATA_SHA256 = 'ec1d8a92a7b039a869ecfb969ff4e1b28941ab5f7eb7fd7b3bcf8e518abf5083'
ASSETS = (
    (0x857B1BC, 0x857B1DC, 'cursor.pal', '.gbapal', False),
    (0x857B1DC, 0x857B220, 'cursor_small.png', '.4bpp', True),
    (0x857B220, 0x857B30C, 'cursor_large.png', '.4bpp', True),
    (0x857B30C, 0x857B34C, 'map.pal', '.gbapal', False),
    (0x857B34C, 0x857C0B0, 'map.png', '.8bpp', True),
    (0x857C0B0, 0x857C3FC, 'map.bin', '.bin', True),
    (0x857C3FC, 0x857C41C, 'brendan_icon.png', '.gbapal', False),
    (0x857C41C, 0x857C49C, 'brendan_icon.png', '.4bpp', False),
    (0x857C49C, 0x857C4BC, 'may_icon.png', '.gbapal', False),
    (0x857C4BC, 0x857C53C, 'may_icon.png', '.4bpp', False),
    (0x857D528, 0x857D548, 'frame.png', '.gbapal', False),
    (0x857D548, 0x857D580, 'frame.png', '.4bpp', True),
    (0x857D580, 0x857D638, 'frame.bin', '.bin', True),
    (0x857D638, 0x857D658, 'fly_target_icons.png', '.gbapal', False),
    (0x857D658, 0x857D72C, 'fly_target_icons.png', '.4bpp', True),
)


def run(args, **kwargs):
    return subprocess.run([str(value) for value in args], cwd=ROOT,
                          capture_output=True, check=True, **kwargs)


def generate_assets(directory):
    outputs = {}
    for start, end, name, extension, compressed in ASSETS:
        source = ROOT / 'graphics/pokenav/region_map' / name
        binary_name = name if extension == '.bin' else str(Path(name).with_suffix(extension))
        binary = directory / binary_name
        if extension == '.bin':
            # Native US-style metatile maps are editable source assets,
            # not unclassified extracted ROM blobs.
            binary.write_bytes(source.read_bytes())
        else:
            options = ['-num_tiles', '233', '-Wnum_tiles'] if name == 'map.png' else []
            run(['tools/gbagfx/gbagfx', source, binary, *options])
        if compressed:
            packed = Path(str(binary) + '.lz')
            run(['tools/gbagfx/gbagfx', binary, packed])
            binary = packed
        outputs['graphics/pokenav/region_map/' + binary.name] = (binary, start, end)
    return outputs


class RegionMapGenerationTests(unittest.TestCase):
    def test_complete_owner_replaces_all_old_mid_tables_and_the_helper_module(self):
        source = (ROOT / 'src/region_map.c').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        mid = (ROOT / 'data/data_b2d_mid61.s').read_text()
        self.assertFalse((ROOT / 'src/data/region_map_tables.c').exists())
        self.assertNotIn('src/data/region_map_tables.o', linker)
        self.assertNotRegex(source + mid, r'gUnknown_857(?:B|C)[0-9A-F]+')
        self.assertNotRegex(source + mid, r'gUnknown_857D[0-7][0-9A-F]+')
        self.assertEqual(linker.count('src/region_map.o(.rodata.region_map_data)'), 1)
        self.assertLess(linker.index('src/heal_location.o(.rodata)'),
                        linker.index('src/region_map.o(.rodata.region_map_data)'))
        self.assertLess(linker.index('src/region_map.o(.rodata.region_map_data)'),
                        linker.index('data/data_b2d_mid61.o(.rodata.data_b2d_mid61_after_region_map)'))
        self.assertIn('gUnknown_857D884:', mid)
        self.assertIn('.incbin "baserom_jp.gba", 0x57d884, 0x2580', mid)
        self.assertIn('.tilemapLeft = 19,', source)
        self.assertIn('.width = 10,', source)
        self.assertIn('.baseBlock = 0x3D', source)
        self.assertNotIn('SpriteCallback_CursorFull', source)

    def test_external_consumers_and_the_exit_callback_use_real_module_owners(self):
        region_map = (ROOT / 'src/region_map.c').read_text()
        image_processing = (ROOT / 'src/image_processing_effects.c').read_text()
        area_screen = (ROOT / 'src/pokedex_area_screen.c').read_text()
        self.assertNotIn('gUnknown_857CD6C', area_screen)
        self.assertNotIn('JPRegionMapEntry', area_screen)
        self.assertEqual(area_screen.count('gRegionMapEntries[gUnknown_3001202]'), 4)
        self.assertNotIn('gUnknown_857D72C', image_processing + region_map)
        self.assertNotIn('sub_08124DF4', image_processing + region_map)
        self.assertNotIn('CB_ExitFlyMap', image_processing)
        self.assertIn('__attribute__((naked)) static void CB_ExitFlyMap(void)', region_map)
        self.assertEqual(region_map.count('.4byte CB_ExitFlyMap + 1'), 2)
        self.assertIn('.4byte sMapHealLocations', region_map)
        self.assertNotIn('0x08124DF5', region_map)

    def test_headers_and_native_assets_rebuild_from_the_tracked_source_inputs(self):
        makefile = (ROOT / 'Makefile').read_text()
        self.assertIn('JP_GENERATED_REGION_MAP_HEADERS := ' + ' '.join(GENERATED), makefile)
        self.assertIn('\trm -f $(JP_GENERATED_REGION_MAP_HEADERS) $(JP_REGION_MAP_ASSETS) $(JP_REGION_MAP_INTERMEDIATES)', makefile)
        self.assertIn('JP_REGION_MAP_INTERMEDIATES := graphics/pokenav/region_map/map.8bpp', makefile)
        self.assertIn('$(JP_REGION_MAP_ASSETS) include/constants/heal_locations.h charmap.txt', makefile)
        self.assertIn('$(OBJFILE): | include/constants/region_map_sections.h', makefile)
        self.assertIn('$(PREPROC) -i $< charmap.txt', makefile[makefile.index('$(C_BUILDDIR)/region_map.o:'):])
        for path, template in zip(GENERATED, TEMPLATES):
            self.assertIn(path + ': ' + JSON_PATH + ' ' + template + ' | tools\n'
                          '\t$(JSONPROC) $^ $@', makefile)
            self.assertEqual(run(['git', 'check-ignore', '--no-index', path], text=True).stdout.strip(), path)
            self.assertEqual(run(['git', 'ls-files', '--', path], text=True).stdout.strip(), '')
        for _, _, name, _, _ in ASSETS:
            self.assertTrue((ROOT / 'graphics/pokenav/region_map' / name).is_file())

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').is_file(), 'JP ROM required')
    def test_all_213_records_197_names_and_shared_pointers_match_jp_not_us_text(self):
        rows = json.loads((ROOT / JSON_PATH).read_text())['map_sections']
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        codec = JapaneseScriptTextCodec()
        self.assertEqual(len(rows), 213)
        self.assertEqual(len({row['id'] for row in rows}), 213)
        owners = {}
        position = 0x0857C6E0
        for index, row in enumerate(rows):
            x, y, width, height, pointer = struct.unpack_from('<BBBBI', rom, 0x57CD6C + index * 8)
            self.assertEqual((x, y, width, height), tuple(row.get(key, default) for key, default in
                                                        [('x', 0), ('y', 0), ('width', 1), ('height', 1)]))
            self.assertRegex(row['name_symbol'], r'^sMapName_[A-Z_0-9]+(?:_Clone)?$')
            self.assertEqual(row['name_owner'], pointer not in owners)
            if pointer not in owners:
                self.assertEqual(pointer, position)
                decoded = codec.verify_one(rom[pointer - 0x08000000:])
                self.assertEqual(row['name'], decoded.source[:-1])
                owners[pointer] = (row['name_symbol'], row['name'])
                position += decoded.consumed
            self.assertEqual((row['name_symbol'], row['name']), owners[pointer])
        self.assertEqual(len(owners), 197)
        self.assertEqual(position, 0x0857CD6A)
        self.assertEqual(rom[0x57CD6A:0x57CD6C], b'\0\0')
        if (US / JSON_PATH).exists():
            reference = json.loads((US / JSON_PATH).read_text())['map_sections']
            self.assertEqual([row['id'] for row in rows], [row['id'] for row in reference])

    @unittest.skipUnless((ROOT / 'tools/gbagfx/gbagfx').exists() and (ROOT / 'baserom_jp.gba').exists(),
                         'built graphics tool and JP ROM required')
    def test_all_15_native_assets_reencode_to_the_original_compressed_bytes(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='region-map-assets-') as directory:
            outputs = generate_assets(Path(directory))
            self.assertEqual(len(outputs), 15)
            for binary, start, end in outputs.values():
                self.assertEqual(binary.read_bytes(), rom[start - 0x08000000:end - 0x08000000])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').exists(), 'linked JP ELF required')
    def test_fresh_json_and_native_assets_reproduce_the_complete_module_code_and_data(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='region-map-module-') as directory:
            temporary = Path(directory)
            source = (ROOT / 'src/region_map.c').read_text()
            for generated, template in zip(GENERATED, TEMPLATES):
                header = temporary / Path(generated).name
                run(['tools/jsonproc/jsonproc', JSON_PATH, template, header])
                first = header.read_bytes()
                run(['tools/jsonproc/jsonproc', JSON_PATH, template, header])
                self.assertEqual(header.read_bytes(), first)
                include = generated.removeprefix('src/').removeprefix('include/')
                source = source.replace('"' + include + '"', '"' + str(header) + '"')
            for path, (binary, _, _) in generate_assets(temporary).items():
                source = source.replace('"' + path + '"', '"' + str(binary) + '"')
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs', '-I', 'tools/agbcc/include',
                       '-I', 'tools/agbcc', '-nostdinc', '-undef', '-std=gnu89', '-P', '-x', 'c', '-'],
                      input=source, text=True).stdout
            preprocessed = run(['tools/preproc/preproc', '-i', 'src/region_map.c', 'charmap.txt'],
                               input=cpp, text=True).stdout
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm',
                            '-o', '-', '-'], input=preprocessed, text=True).stdout
            assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
            obj = temporary / 'module.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', obj, '-'],
                input=assembly, text=True)
            script = temporary / 'module.ld'
            script.write_text('SECTIONS { .text ' + hex(CODE_START) + ': { *(.text) } .rodata '
                              + hex(DATA_START) + ': { *(.rodata.region_map_data) } /DISCARD/ : '
                              '{ *(.data) *(.bss) *(.comment) *(.note*) *(.ARM.attributes) } }\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), obj])
            for name, start, end, digest in (('.text', CODE_START, CODE_END, CODE_SHA256),
                                            ('.rodata', DATA_START, DATA_END, DATA_SHA256)):
                binary = temporary / (name[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary',
                     '--only-section=' + name, elf, binary])
                actual = binary.read_bytes()
                self.assertEqual(actual, rom[start - 0x08000000:end - 0x08000000])
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest)


if __name__ == '__main__':
    unittest.main()
