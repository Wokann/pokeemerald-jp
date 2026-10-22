"""The complete JP initializer family has US semantic identities, not address guesses."""
import hashlib
from pathlib import Path
import re
import unittest

try:
    from map_semantic_review import native_elf
except ModuleNotFoundError:
    from tools.map_semantic_review import native_elf

ROOT = Path(__file__).resolve().parents[1]
PREFIX = 'InitTilesetAnim_'
# Native entries are verified against actual callback stores and each tileset
# consumer. The five NULL callbacks require their consumers to disambiguate.
ENTRIES = [
    ('General', 0x080A03E8), ('Building', 0x080A0410), ('Petalburg', 0x080A0534),
    ('Rustboro', 0x080A055C), ('Dewford', 0x080A0588), ('Slateport', 0x080A05B4),
    ('Mauville', 0x080A05E0), ('Lavaridge', 0x080A0610), ('Fallarbor', 0x080A063C),
    ('Fortree', 0x080A0664), ('Lilycove', 0x080A068C), ('Mossdeep', 0x080A06B4),
    ('EverGrande', 0x080A06DC), ('Pacifidlog', 0x080A0708), ('Sootopolis', 0x080A0738),
    ('BattleFrontierOutsideWest', 0x080A0764), ('BattleFrontierOutsideEast', 0x080A0790),
    ('Underwater', 0x080A07BC), ('SootopolisGym', 0x080A07E0), ('Cave', 0x080A0804),
    ('EliteFour', 0x080A0830), ('MauvilleGym', 0x080A0854), ('BikeShop', 0x080A0880),
    ('BattlePyramid', 0x080A08AC), ('BattleDome', 0x080A08D8),
]
NULL_CALLBACKS = {'Petalburg', 'Fallarbor', 'Fortree', 'Lilycove', 'Mossdeep'}


def headers():
    source = (ROOT / 'src/data/tilesets/headers.h').read_text()
    labels = list(re.finditer(r'(?m)^const struct Tileset (gTileset_\w+) TILESET_HEADER_DATA =', source))
    return {label[1]: source[label.start():labels[i + 1].start() if i + 1 < len(labels) else len(source)]
            for i, label in enumerate(labels)}


class TilesetInitializerNameTests(unittest.TestCase):
    def test_all_twenty_five_semantic_bodies_and_original_physical_order(self):
        source = (ROOT / 'src/tileset_anims.c').read_text()
        functions = re.findall(r'(?ms)^void (InitTilesetAnim_\w+)\(void\)\n\{\n(.*?)\n\}', source)
        self.assertEqual([name for name, body in functions], [PREFIX + name for name, address in ENTRIES])
        for (name, body), (suffix, address) in zip(functions, ENTRIES):
            primary = suffix in ('General', 'Building')
            group = 'sPrimaryTilesetAnim' if primary else 'sSecondaryTilesetAnim'
            counter = 'sPrimaryTilesetAnimCounter' if suffix in ('Mauville', 'Pacifidlog') else '0'
            maximum = ('256' if primary else '128' if suffix in ('Underwater', 'EliteFour')
                       else '240' if suffix == 'SootopolisGym' else 'sPrimaryTilesetAnimCounterMax')
            callback = '0' if suffix in NULL_CALLBACKS else 'TilesetAnim_' + suffix
            expected = group + 'Counter=' + counter + ';' + group + 'CounterMax=' + maximum + ';' + group + 'Callback=' + callback + ';'
            self.assertEqual(re.sub(r'\s+', '', body), expected, name)

    def test_public_declarations_jp_funcmap_and_regeneration_config_agree_by_address(self):
        expected = {PREFIX + name: address for name, address in ENTRIES}
        declarations = re.findall(r'void (InitTilesetAnim_\w+)\(void\);', (ROOT / 'include/tileset_anims.h').read_text())
        self.assertEqual(len(declarations), 25)
        self.assertEqual(set(declarations), expected.keys())
        funcmap = re.findall(r'(?m)^([0-9A-Fa-f]+) \S+ (InitTilesetAnim_\w+)$', (ROOT / 'funcmap_jp.txt').read_text())
        config = re.findall(r'(?m)^thumb_func (0x[0-9A-Fa-f]+) (InitTilesetAnim_\w+)$', (ROOT / 'pokeemerald_jp.cfg').read_text())
        self.assertEqual(len(funcmap), 25)
        self.assertEqual(len(config), 25)
        self.assertEqual({name: int(address, 16) for address, name in funcmap}, expected)
        self.assertEqual({name: int(address, 16) for address, name in config}, expected)

    def test_all_twenty_five_consumers_use_the_real_c_header_fields(self):
        blocks = headers()
        self.assertEqual(len(blocks), 75)
        for name, address in ENTRIES:
            block = blocks['gTileset_' + name]
            callback = re.findall(r'(?m)^\s*\.callback = (\w+),', block)
            self.assertEqual(callback, [PREFIX + name])
            self.assertNotIn('.incbin', block)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires native JP artifacts')
    def test_native_names_and_all_seventy_five_headers_retain_their_real_rom_bindings(self):
        symbols, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, address in ENTRIES:
            self.assertEqual(symbols.get(PREFIX + name), {address | 1}, name)
            values = symbols['gTileset_' + name]
            self.assertEqual(len(values), 1)
            header_address = next(iter(values)) - 0x08000000
            self.assertEqual(int.from_bytes(rom[header_address + 20:header_address + 24], 'little'), address | 1)
        for name in headers():
            values = symbols[name]
            self.assertEqual(len(values), 1, name)
            address = next(iter(values))
            native = [data[address - base:address - base + 24] for base, data in memory
                      if base <= address and address + 24 <= base + len(data)]
            self.assertEqual(native, [rom[address - 0x08000000:address - 0x08000000 + 24]], name)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires native JP artifacts')
    def test_all_initializer_instructions_and_literal_pools_stay_byte_exact(self):
        symbols, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for address, size, digest in [(0x080A03E8, 80, '98f9f0567fb6e0810362953e8652230b4924e229a0f7af6eed920811637f7f5c'),
                                      (0x080A0534, 976, '458d21c1d1bbee93b3a6e1336c611dac9b4a1761420760b9a3ca0255384ad4b0')]:
            payload = rom[address - 0x08000000:address - 0x08000000 + size]
            self.assertEqual(hashlib.sha256(payload).hexdigest(), digest)
            native = [data[address - base:address - base + size] for base, data in memory
                      if base <= address and address + size <= base + len(data)]
            self.assertEqual(native, [payload])


if __name__ == '__main__':
    unittest.main()
