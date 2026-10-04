#!/usr/bin/env python3
"""Keep weather opcode names aligned with their verified JP implementation."""

import re
import sys
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import jp_script_parser as parser  # noqa: E402


class ScriptWeatherCommandTests(unittest.TestCase):
    def test_parser_and_c_constants_agree_on_weather_opcodes(self):
        constants = (ROOT / "include/constants/script_commands.h").read_text()
        for name, opcode, macro in (
            ("SCR_OP_RESETWEATHER", 0xA3, "resetweather"),
            ("SCR_OP_SETWEATHER", 0xA4, "setweather"),
            ("SCR_OP_DOWEATHER", 0xA5, "doweather"),
        ):
            with self.subTest(name=name):
                self.assertEqual(parser.OPCODE_BY_NAME[name], opcode)
                self.assertEqual(parser.FORMATS[opcode][0], macro)
                match = re.search(r"\b" + name + r"\s*=\s*(0x[0-9A-Fa-f]+)", constants)
                self.assertIsNotNone(match)
                self.assertEqual(int(match.group(1), 16), opcode)

    def test_weather_table_uses_the_matching_handlers(self):
        entries = re.findall(
            r"^\s*script_cmd_table_entry\s+(\w+)\s+(\w+)\s*@",
            (ROOT / "data/script_cmd_table.inc").read_text(),
            re.MULTILINE,
        )
        self.assertEqual(entries[0xA3], ("SCR_OP_RESETWEATHER", "ScrCmd_resetweather"))
        self.assertEqual(entries[0xA5], ("SCR_OP_DOWEATHER", "ScrCmd_doweather"))

    def test_handlers_and_reset_alias_follow_the_actual_weather_behavior(self):
        source = (ROOT / "src/scrcmd.c").read_text()
        for handler, callee in (
            ("ScrCmd_resetweather", "SetSavedWeatherFromCurrMapHeader"),
            ("ScrCmd_doweather", "DoCurrentWeather"),
        ):
            with self.subTest(handler=handler):
                match = re.search(
                    r"bool8 " + handler + r"\(struct ScriptContext \*ctx\)\s*\{([^}]+)\}",
                    source,
                )
                self.assertIsNotNone(match)
                self.assertEqual(match.group(1).split(), [callee + "();", "return", "FALSE;"])
        self.assertIn(
            "SetSavedWeatherFromCurrMapHeader = SetSav1WeatherFromCurrMapHeader;",
            (ROOT / "ld_script_jp.txt").read_text(),
        )


if __name__ == "__main__":
    unittest.main()
