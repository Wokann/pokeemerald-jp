#!/usr/bin/env python3
"""Assemble all Contest AI encodings, including commands unused by the ROM.

These are serializer/argument/relocation contracts, not runtime approval of
vanilla C handlers. In particular, original conditional-pointer bugs remain.
"""

import re
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MACROS = ROOT / "asm/macros/contest_ai_script.inc"
BINUTILS = ROOT / "tools/binutils/bin"
AS = BINUTILS / "arm-none-eabi-as"
LD = BINUTILS / "arm-none-eabi-ld"
OBJCOPY = BINUTILS / "arm-none-eabi-objcopy"
TEMP_ROOT = ROOT / ".tmp/agent-work/tests/contest-ai-macros"
DESTINATION = 0x08345678


def opcode_layouts():
    """Fixed byte widths; do not derive expected sizes from the tested macros."""
    layouts = {}

    def add(widths, *ranges):
        for first, last in ranges:
            for opcode in range(first, last + 1):
                if opcode in layouts:
                    raise AssertionError(f"duplicate fixture opcode {opcode:#x}")
                layouts[opcode] = widths

    add((), (0x01, 0x01), (0x06, 0x06), (0x0B, 0x0B),
        (0x10, 0x10), (0x15, 0x15), (0x1A, 0x1A), (0x1F, 0x1F),
        (0x22, 0x22), (0x27, 0x27), (0x2A, 0x2A), (0x2D, 0x2D),
        (0x2F, 0x2F), (0x31, 0x31), (0x36, 0x36), (0x3B, 0x3B),
        (0x40, 0x40), (0x43, 0x43), (0x46, 0x46), (0x81, 0x82))
    add((1,), (0x00, 0x00), (0x49, 0x49), (0x4E, 0x4E),
        (0x53, 0x53), (0x56, 0x56), (0x59, 0x59),
        (0x5E, 0x5E), (0x70, 0x70))
    add((1, 4), (0x02, 0x05), (0x07, 0x0A), (0x0C, 0x0F),
        (0x11, 0x14), (0x20, 0x21), (0x23, 0x26), (0x28, 0x29),
        (0x2B, 0x2C), (0x32, 0x35), (0x37, 0x3A), (0x3C, 0x3F),
        (0x54, 0x55), (0x57, 0x58), (0x5A, 0x5D), (0x5F, 0x62),
        (0x7D, 0x7E))
    add((2, 4), (0x16, 0x19), (0x1B, 0x1E), (0x86, 0x87))
    add((4,), (0x2E, 0x2E), (0x30, 0x30), (0x41, 0x42),
        (0x44, 0x45), (0x47, 0x48), (0x7F, 0x80), (0x83, 0x84))
    add((1, 1, 4), (0x4A, 0x4D), (0x4F, 0x52), (0x79, 0x7C))
    add((1, 1), (0x63, 0x63), (0x68, 0x68), (0x6D, 0x6D), (0x73, 0x74))
    add((1, 1, 1, 4), (0x64, 0x67), (0x69, 0x6C), (0x6E, 0x6F))
    add((1, 2), (0x71, 0x72))
    add((1, 2, 4), (0x75, 0x78))
    add((2,), (0x85, 0x85))
    if set(layouts) != set(range(0x88)):
        raise AssertionError("fixture does not cover all 136 command encodings")
    return layouts


def macro_definitions(source):
    definitions = {}
    pattern = r"^\s*\.macro\s+(\w+)([^\n]*)\n(.*?)^\s*\.endm\s*$"
    for match in re.finditer(pattern, source, re.M | re.S):
        name, arguments, body = match.groups()
        if name in definitions:
            raise AssertionError(f"duplicate macro {name}")
        parameters = [item.split(":")[0] for item in arguments.replace(",", " ").split()]
        opcode = re.search(r"^\s*\.byte\s+(0x[0-9A-Fa-f]+)\s*$", body, re.M)
        definitions[name] = {
            "parameters": parameters,
            "body": body,
            "opcode": int(opcode[1], 16) if opcode else None,
        }
    return definitions


@unittest.skipUnless(all(path.is_file() for path in (AS, LD, OBJCOPY)),
                     "bundled ARM assembler/linker/objcopy are required")
class ContestAIMacroTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.definitions = macro_definitions(MACROS.read_text())
        cls.layouts = opcode_layouts()
        TEMP_ROOT.mkdir(parents=True, exist_ok=True)

    def assemble(self, commands, *, link_address=None, source=None):
        with tempfile.TemporaryDirectory(prefix="fixture-", dir=TEMP_ROOT) as directory:
            directory = Path(directory)
            macro_path = MACROS
            if source is not None:
                macro_path = directory / "macros.inc"
                macro_path.write_text(source)
            fixture = (
                ".equ TRUE, 1\n.equ FALSE, 0\n.equ CONTEST_LAST_APPEAL, 4\n"
                f'.include "{macro_path}"\n.section script_data,"aw",%progbits\n'
                + commands + "\n"
            )
            obj = directory / "fixture.o"
            result = subprocess.run(
                [str(AS), "-mcpu=arm7tdmi", "--fatal-warnings", "-o", str(obj), "-"],
                input=fixture, text=True, capture_output=True, cwd=ROOT,
            )
            if result.returncode:
                return result, None
            if link_address is not None:
                linked = directory / "fixture.elf"
                subprocess.run(
                    [str(LD), f"--section-start=script_data={link_address:#x}",
                     "-e", "0", "-o", str(linked), str(obj)],
                    check=True, capture_output=True, text=True,
                )
                obj = linked
            binary = directory / "fixture.bin"
            subprocess.run([str(OBJCOPY), "-O", "binary", "-j", "script_data",
                            str(obj), str(binary)], check=True, capture_output=True)
            return result, binary.read_bytes()

    def test_complete_primitive_and_helper_inventory(self):
        primitive = [spec["opcode"] for spec in self.definitions.values()
                     if spec["opcode"] is not None]
        self.assertEqual(len(primitive), 136)
        self.assertCountEqual(primitive, range(0x88))
        self.assertEqual(
            {name for name, spec in self.definitions.items() if spec["opcode"] is None},
            {"if_last_appeal", "if_not_last_appeal",
             "if_used_combo_starter", "if_not_used_combo_starter"},
        )

    def test_every_macro_uses_only_its_declared_parameters(self):
        for name, spec in self.definitions.items():
            with self.subTest(macro=name):
                referenced = set(re.findall(r"\\([A-Za-z_]\w*)", spec["body"]))
                self.assertLessEqual(referenced, set(spec["parameters"]))

    def test_all_136_primitive_encodings(self):
        for name, spec in self.definitions.items():
            opcode = spec["opcode"]
            if opcode is None:
                continue
            with self.subTest(macro=name, opcode=f"{opcode:#04x}"):
                widths = self.layouts[opcode]
                self.assertEqual(len(spec["parameters"]), len(widths))
                values = [DESTINATION if width == 4 else
                          (0x1234 + index * 0x1111 if width == 2 else 0x2D + index * 0x11)
                          for index, width in enumerate(widths)]
                command = name + (" " + ", ".join(map(str, values)) if values else "")
                result, raw = self.assemble(command)
                self.assertEqual(result.returncode, 0, result.stderr)
                expected = bytes((opcode,)) + b"".join(
                    value.to_bytes(width, "little") for value, width in zip(values, widths)
                )
                self.assertEqual(raw, expected)

    def test_all_four_compound_macros(self):
        cases = (
            (f"if_last_appeal {DESTINATION}", b"\x04\x04"),
            (f"if_not_last_appeal {DESTINATION}", b"\x05\x04"),
            (f"if_used_combo_starter 2, {DESTINATION}", b"\x51\x02\x01"),
            (f"if_not_used_combo_starter 2, {DESTINATION}", b"\x51\x02\x00"),
        )
        for command, prefix in cases:
            with self.subTest(command=command):
                result, raw = self.assemble(command)
                self.assertEqual(result.returncode, 0, result.stderr)
                self.assertEqual(raw, prefix + DESTINATION.to_bytes(4, "little"))

    def test_symbolic_jump_and_following_getter_relocate_exactly(self):
        origin = 0x0828C8D8
        commands = "\n".join((
            "if_most_jamming_move Fixture_Target",
            "get_completed_combo 2",
            "Fixture_Target:",
            "end",
        ))
        result, raw = self.assemble(commands, link_address=origin)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(raw, b"\x30" + (origin + 7).to_bytes(4, "little") + b"\x56\x02\x81")

    def test_completed_combo_getter_does_not_consume_the_next_command(self):
        result, raw = self.assemble("get_completed_combo 3\nend")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(raw, b"\x56\x03\x81")

    def test_signed_score_and_wide_immediates_keep_native_byte_order(self):
        cases = (
            ("score -5", b"\x00\xFB"),
            ("setvar 2, 0xABCD", b"\x71\x02\xCD\xAB"),
            ("if_eq 2, 0xABCD, 0x08345678", b"\x77\x02\xCD\xAB\x78\x56\x34\x08"),
            ("if_used_moves_effect_eq 2, 3, 127, 0x08345678", b"\x66\x02\x03\x7F\x78\x56\x34\x08"),
        )
        for command, expected in cases:
            with self.subTest(command=command):
                result, raw = self.assemble(command)
                self.assertEqual(result.returncode, 0, result.stderr)
                self.assertEqual(raw, expected)

    def test_keyword_arguments_keep_the_declared_interface(self):
        result, raw = self.assemble("if_condition_less_than destination=0x08345678, num=7, mon=2")
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(raw, b"\x4A\x02\x07\x78\x56\x34\x08")

    def test_required_parameters_cannot_be_omitted(self):
        for name, spec in self.definitions.items():
            if not spec["parameters"]:
                continue
            with self.subTest(macro=name):
                supplied = ["2"] * (len(spec["parameters"]) - 1)
                result, raw = self.assemble(name + (" " + ", ".join(supplied) if supplied else ""))
                self.assertNotEqual(result.returncode, 0)
                self.assertIsNone(raw)

    def test_historical_unused_macro_defects_are_real_assembler_failures(self):
        source = MACROS.read_text()
        fixtures = (
            ("\t.macro if_most_jamming_move destination:req\n\t.byte 0x30\n\t.4byte \\destination\n",
             "\t.macro if_most_jamming_move destination:req\n\t.byte 0x30\n\t.4bye \\destination\n",
             "if_most_jamming_move 0x08345678"),
            ("\t.macro get_completed_combo mon:req\n\t.byte 0x56\n\t.byte \\mon\n\t.endm",
             "\t.macro get_completed_combo mon:req\n\t.byte 0x56\n\t.byte \\mon\n\t.4byte \\destination\n\t.endm",
             "get_completed_combo 2"),
        )
        for good, bad, command in fixtures:
            with self.subTest(command=command):
                self.assertEqual(source.count(good), 1)
                result, raw = self.assemble(command, source=source.replace(good, bad, 1))
                self.assertNotEqual(result.returncode, 0)
                self.assertIsNone(raw)


if __name__ == "__main__":
    unittest.main()
