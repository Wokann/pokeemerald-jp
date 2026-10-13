#!/usr/bin/env python3
"""Check complete JP marking graphics ownership, encoding and ROM boundaries."""
import hashlib
import re
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / "tools/gbagfx/gbagfx"
BINUTILS = ROOT / "tools/binutils/bin"
ROM = ROOT / "baserom_jp.gba"
OBJECTS = ROOT / "build/pokeemerald-jp"
ASSETS = (
    ("mon_markings_menu", 200, 8, 0x579F38, 0x579F58, 0x320),
    ("mon_markings", 32, 128, 0x57A278, 0x57A298, 0x800),
)


def run(arguments):
    result = subprocess.run([str(value) for value in arguments], cwd=ROOT,
                            capture_output=True, text=True)
    if result.returncode:
        raise AssertionError(f"{result.args}:\n{result.stdout}\n{result.stderr}")
    return result.stdout


class MonMarkingsDataTests(unittest.TestCase):
    def test_complete_resources_have_native_us_owners_and_no_temporary_aliases(self):
        graphics = (ROOT / "src/graphics.c").read_text()
        markings = (ROOT / "src/mon_markings.c").read_text()
        self.assertFalse((ROOT / "data/data_b2d_mid61.s").exists())
        mid = (ROOT / "Makefile").read_text()
        linker = (ROOT / "ld_script_jp.txt").read_text()
        for symbol, kind in (("gMonMarkingsMenu_Pal", "U16"),
                             ("gMonMarkingsMenu_Gfx", "U8")):
            self.assertIn(symbol + '[] = INCGFX_' + kind
                          + '("graphics/interface/mon_markings_menu.png",', graphics)
            self.assertNotIn(symbol, mid)
        for symbol, kind in (("sMonMarkings_Pal", "U16"), ("sMonMarkings_Gfx", "U8")):
            self.assertIn(symbol + '[] = INCGFX_' + kind
                          + '("graphics/interface/mon_markings.png",', markings)
            self.assertNotIn(symbol, mid)
            self.assertNotIn("extern const u16 " + symbol, markings)
        self.assertIn('static const ALIGNED(4) u8 sMonMarkings_Gfx[]', markings)
        self.assertIn('static const u8 sText_Confirm[] = _("けってい");', markings)
        self.assertNotIn("graphics/mon_markings/", graphics + markings + mid)
        self.assertNotIn("__attribute__((naked))", markings)
        owners = (
            "src/easy_chat.o(.rodata.easy_chat_restricted_word_species_data)",
            "src/graphics.o(.rodata.mon_markings_menu_graphics)",
            "src/mon_markings.o(.rodata.mon_markings_graphics_data)",
            "src/mon_markings.o(.rodata.mon_markings_data)",
        )
        for owner in owners:
            self.assertEqual(linker.count(owner), 1)
        self.assertEqual([linker.index(owner) for owner in owners],
                         sorted(linker.index(owner) for owner in owners))
        self.assertNotIn("data/data_b2d_mid61", mid + linker)

    def test_clean_build_has_both_png_encoders_and_explicit_native_dependencies(self):
        makefile = (ROOT / "Makefile").read_text()
        self.assertIn("rm -f $(JP_MON_MARKINGS_ASSETS)", makefile)
        for suffix in ("4bpp", "gbapal"):
            self.assertIn("graphics/interface/%.png." + suffix
                          + ": graphics/interface/%.png | tools", makefile)
        self.assertIn("$(C_BUILDDIR)/graphics.o: $(JP_MON_MARKINGS_MENU_ASSETS)", makefile)
        self.assertIn("$(C_BUILDDIR)/mon_markings.o: src/mon_markings.c charmap.txt $(JP_MON_MARKINGS_COMBO_ASSETS)",
                      makefile)
        rule = makefile[makefile.index("$(C_BUILDDIR)/mon_markings.o: src/mon_markings.c"):].split("\n\n", 1)[0]
        self.assertIn("$(PREPROC) -i $< charmap.txt", rule)
        self.assertIn("-include $(C_BUILDDIR)/mon_markings.d", makefile)
        for name, *_ in ASSETS:
            for suffix in ("4bpp", "gbapal"):
                self.assertIn("graphics/interface/" + name + ".png." + suffix, makefile)

    @unittest.skipUnless(ROM.exists() and GFX.exists(), "JP ROM and built gbagfx required")
    def test_all_four_resources_round_trip_without_the_unused_text_becoming_tiles(self):
        rom = ROM.read_bytes()
        self.assertEqual(hashlib.sha1(rom).hexdigest(), "d7cf8f156ba9c455d164e1ea780a6bf1945465c2")
        with tempfile.TemporaryDirectory(prefix="mon-markings-assets-") as directory:
            temporary = Path(directory)
            for name, width, height, palette, tiles, size in ASSETS:
                source = ROOT / "graphics/interface" / (name + ".png")
                data = source.read_bytes()
                self.assertEqual(data[:8], b"\x89PNG\r\n\x1a\n")
                self.assertEqual(struct.unpack_from(">II", data, 16), (width, height))
                self.assertEqual(data[24:26], bytes((4, 3)))  # 4-bit indexed palette.
                for suffix, start, length in (("gbapal", palette, 0x20), ("4bpp", tiles, size)):
                    output = temporary / (name + "." + suffix)
                    run((GFX, source, output))
                    self.assertEqual(output.read_bytes(), rom[start:start + length],
                                     name + "." + suffix)
            self.assertEqual(rom[0x57AA98:0x57AAA0], bytes.fromhex("09 50 13 02 FF 00 00 00"))
            self.assertEqual(rom[0x579F34:0x579F38], bytes.fromhex("9A 01 00 00"))

    @unittest.skipUnless(ROM.exists() and (OBJECTS / "src/mon_markings.o").exists()
                         and (OBJECTS / "src/graphics.o").exists(),
                         "fresh native marking/graphics objects and JP ROM required")
    def test_complete_native_sections_preserve_the_exact_jp_asset_and_text_spans(self):
        rom = ROM.read_bytes()
        with tempfile.TemporaryDirectory(prefix="mon-markings-objects-") as directory:
            temporary = Path(directory)
            for owner, section, start, end in (
                ("graphics", ".rodata.mon_markings_menu_graphics", 0x579F38, 0x57A278),
                ("mon_markings", ".rodata.mon_markings_graphics_data", 0x57A278, 0x57AA9D),
            ):
                obj = OBJECTS / "src" / (owner + ".o")
                self.assertGreaterEqual(obj.stat().st_mtime_ns, (ROOT / "src" / (owner + ".c")).stat().st_mtime_ns,
                                        "stale object: " + owner)
                output = temporary / (owner + ".bin")
                run((BINUTILS / "arm-none-eabi-objcopy", "-O", "binary",
                     "--only-section=" + section, obj, output))
                self.assertEqual(output.read_bytes(), rom[start:end], section)
            definitions = run((BINUTILS / "arm-none-eabi-nm", "-S", "--defined-only",
                               OBJECTS / "src/mon_markings.o"))
            self.assertEqual(len(re.findall(r"(?m)^\w+ \w+ [Tt] ", definitions)), 15)
            self.assertRegex(definitions, r"(?m)^00000000 00000020 r sMonMarkings_Pal$")
            self.assertRegex(definitions, r"(?m)^00000020 00000800 r sMonMarkings_Gfx$")
            self.assertRegex(definitions, r"(?m)^00000820 00000005 r sText_Confirm$")


if __name__ == "__main__":
    unittest.main()
