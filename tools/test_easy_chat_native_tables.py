"""Native Easy Chat tables, JP-only coordinates and unchanged ROM bindings."""

import hashlib
import re
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROM = ROOT / "baserom_jp.gba"
OBJECT = ROOT / "build/pokeemerald-jp/src/easy_chat.o"
ELF = ROOT / "pokeemerald_jp.elf"
BINUTILS = ROOT / "tools/binutils/bin"
DATA = (
    ("sFooterOptionXOffsets", ".rodata.easy_chat_footer_option_x_offsets_data",
     0x085743B4, bytes((3, 10, 17, 17, 3, 10, 15, 21))),
    ("sRestrictedWordSpecies", ".rodata.easy_chat_restricted_word_species_data",
     0x08579F34, struct.pack("<H", 410)),
)


def run(arguments):
    result = subprocess.run([str(argument) for argument in arguments],
                            cwd=ROOT, capture_output=True, text=True)
    if result.returncode:
        raise AssertionError(f"{result.args}:\n{result.stdout}\n{result.stderr}")
    return result.stdout


class EasyChatNativeTablesTests(unittest.TestCase):
    def test_both_tables_are_local_native_c_definitions_not_raw_or_aliases(self):
        source = (ROOT / "src/easy_chat.c").read_text()
        self.assertIn('#include "constants/species.h"', source)
        self.assertRegex(source, r"static const u8 sFooterOptionXOffsets\[2\]\[4\]"
                         r"\s+EASY_CHAT_FOOTER_OPTION_X_OFFSETS_DATA\s*=\s*\{"
                         r"\s*\{3, 10, 17, 17\},\s*\{3, 10, 15, 21\},\s*\};")
        self.assertRegex(source, r"static const u16 sRestrictedWordSpecies\[\]"
                         r"\s+EASY_CHAT_RESTRICTED_WORD_SPECIES_DATA\s*=\s*\{"
                         r"\s*SPECIES_DEOXYS,\s*\};")
        for symbol, *_ in DATA:
            self.assertIn(".4byte " + symbol, source)
            self.assertNotRegex(source, r"extern[^;\n]*\b" + symbol + r"\b")
        self.assertNotIn("gUnknown_8579F34", source)
        self.assertNotIn(".set sRestrictedWordSpecies", source)

    def test_retired_containers_are_absent_from_the_live_build_chain(self):
        linker = (ROOT / "ld_script_jp.txt").read_text()
        makefile = (ROOT / "Makefile").read_text()
        mid60 = (ROOT / "data/data_b2d_mid60.s").read_text()
        for path in ("data/data_b2d_mid61.s", "data/easy_chat/footer_option_x_offsets.inc"):
            self.assertFalse((ROOT / path).exists(), path)
        self.assertNotIn("data/data_b2d_mid61", linker + makefile)
        self.assertNotIn("footer_option_x_offsets.inc", mid60 + makefile)
        self.assertNotIn("sFooterOptionXOffsets", mid60)
        for _, section, *_ in DATA:
            self.assertEqual(linker.count("src/easy_chat.o(" + section + ")"), 1)
            self.assertNotIn("data/data_b2d_mid60.o(" + section + ")", linker)
        self.assertIn("src/easy_chat.o(.rodata.easy_chat_restricted_word_species_data);\n"
                      "        . = ALIGN(4);\n"
                      "        src/graphics.o(.rodata.mon_markings_menu_graphics);", linker)
        # An unused neighboring palette has no proven semantic owner yet.
        self.assertIn('gUnknown_85733B0:', mid60)
        self.assertIn('.incbin "baserom_jp.gba", 0x5733b0, 0x20', mid60)

    def test_restricted_species_name_covers_the_function_and_catalog_chain(self):
        source = (ROOT / "src/easy_chat.c").read_text()
        linker = (ROOT / "ld_script_jp.txt").read_text()
        self.assertIn("__attribute__((naked)) int IsRestrictedWordSpecies(u16 species)", source)
        self.assertIn("bl IsRestrictedWordSpecies", source)
        self.assertNotIn("GetFooterOptionXOffset", source + linker)
        self.assertIn("src/easy_chat.o(.text.IsRestrictedWordSpecies)", linker)
        self.assertIn("0811fd8c IsRestrictedWordSpecies IsRestrictedWordSpecies\n",
                      (ROOT / "funcmap_jp.txt").read_text())
        self.assertIn("thumb_func 0x811fd8c IsRestrictedWordSpecies\n",
                      (ROOT / "pokeemerald_jp.cfg").read_text())

    @unittest.skipUnless(ROM.exists(), "JP ROM required")
    def test_each_native_initializer_and_boundary_matches_original_jp_bytes(self):
        rom = ROM.read_bytes()
        self.assertEqual(hashlib.sha1(rom).hexdigest(),
                         "d7cf8f156ba9c455d164e1ea780a6bf1945465c2")
        for symbol, _, address, expected in DATA:
            offset = address - 0x08000000
            self.assertEqual(rom[offset:offset + len(expected)], expected, symbol)
        self.assertEqual(rom[0x579F36:0x579F38], bytes(2))
        self.assertEqual(rom[0x579F38:0x579F58],
                         (ROOT / "graphics/interface/mon_markings_menu.png.gbapal").read_bytes())
        self.assertRegex((ROOT / "include/constants/species.h").read_text(),
                         r"(?m)^#define SPECIES_DEOXYS\s+410\s*$")

    @unittest.skipUnless(ROM.exists() and OBJECT.exists() and ELF.exists(),
                         "fresh Easy Chat object and linked JP ELF required")
    def test_fresh_object_types_bindings_spans_and_padding_are_exact(self):
        self.assertGreaterEqual(OBJECT.stat().st_mtime_ns,
                                (ROOT / "src/easy_chat.c").stat().st_mtime_ns)
        rom = ROM.read_bytes()
        object_symbols = run((BINUTILS / "arm-none-eabi-nm", "-S", "--defined-only", OBJECT))
        linked_symbols = run((BINUTILS / "arm-none-eabi-nm", "-S", "--defined-only", ELF))
        linked_records = {fields[-1]: fields for line in linked_symbols.splitlines()
                          if len(fields := line.split()) == 4}
        with tempfile.TemporaryDirectory(prefix="easy-chat-native-tables-") as directory:
            for symbol, section, address, expected in DATA:
                output = Path(directory) / (symbol + ".bin")
                run((BINUTILS / "arm-none-eabi-objcopy", "-O", "binary",
                     "--only-section=" + section, OBJECT, output))
                self.assertEqual(output.read_bytes(), expected, symbol)
                self.assertRegex(object_symbols, r"(?m)^00000000 " + f"{len(expected):08x}"
                                 + r" r " + symbol + r"$")
                self.assertIn(symbol, linked_records)
                record = linked_records[symbol]
                self.assertEqual(record[:2], [f"{address:08x}", f"{len(expected):08x}"])
                # The JP output .rodata inherits WRITE from old assembly inputs;
                # its local const objects are therefore classified as "d" by nm.
                self.assertEqual(record[2:], ["d", symbol])
        self.assertEqual(linked_records.get("IsRestrictedWordSpecies"),
                         ["0811fd8c", "00000028", "T", "IsRestrictedWordSpecies"])
        self.assertNotIn("GetFooterOptionXOffset", linked_records)
        # The alignment gap is physical padding, not a second restricted species.
        self.assertEqual(rom[0x579F36:0x579F38], bytes(2))
        self.assertEqual((ROOT / "pokeemerald_jp.gba").read_bytes(), rom)


if __name__ == "__main__":
    unittest.main()
