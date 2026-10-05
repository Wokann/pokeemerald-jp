#!/usr/bin/env python3
"""Regression checks for ``audit_eventscript_sync.py``."""

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import audit_eventscript_sync as audit


class EventScriptSyncTests(unittest.TestCase):
    def test_macro_report_identifies_only_jp_definitions(self):
        with tempfile.TemporaryDirectory() as temporary:
            jp = Path(temporary) / "jp"
            us = Path(temporary) / "us"
            for root, extra in ((jp, "jp_only"), (us, "us_only")):
                path = root / "asm/macros/event.inc"
                path.parent.mkdir(parents=True)
                path.write_text(
                    ".macro shared arg:req\n.byte \\arg\n.endm\n"
                    f".macro {extra}\n.endm\n",
                    encoding="utf-8",
                )
            report = audit.macro_report(jp, us)
        self.assertEqual(report["shared_body_or_signature_differences"], [])
        self.assertEqual(report["jp_only_macros"], ["jp_only"])
        self.assertEqual(report["us_only_macros"], ["us_only"])

    def test_special_alignment_accounts_for_us_insertions_without_shifting_jp(self):
        jp = [audit.Special("A", False), audit.Special("B", False)]
        us = [audit.Special("A", False), audit.Special("Only", False), audit.Special("B", True)]
        self.assertEqual(audit.special_alignment(jp, us, ((1, "Only"),)), [(0, 0), (1, 2)])

    def test_special_call_sites_detect_immediate_explicit_waitstate(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            path = root / "data/maps/Test/scripts.inc"
            path.parent.mkdir(parents=True)
            path.write_text(
                "special NeedsWait\n@ a comment\nwaitstate\n"
                "specialvar VAR_RESULT, NeedsWait\nwaitstate\n"
                "special NoWait\nreturn\n",
                encoding="utf-8",
            )
            sites = audit.special_call_sites(root, {"NeedsWait", "NoWait"})
        self.assertEqual(len(sites["NeedsWait"]), 2)
        self.assertTrue(all(site["explicit_waitstate"] for site in sites["NeedsWait"]))
        self.assertFalse(sites["NoWait"][0]["explicit_waitstate"])

    def test_opcode_report_detects_header_table_divergence(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            header = root / "include/constants/script_commands.h"
            table = root / "data/script_cmd_table.inc"
            header.parent.mkdir(parents=True)
            table.parent.mkdir(parents=True)
            header.write_text("SCR_OP_A = 0x00,\nSCR_OP_B = 0x02,\n", encoding="utf-8")
            table.write_text(
                "script_cmd_table_entry SCR_OP_A Handler @ 0x00\n"
                "script_cmd_table_entry SCR_OP_B Handler @ 0x01\n",
                encoding="utf-8",
            )
            report = audit.opcode_report(root)
        self.assertEqual(report["divergent_values"], [{"name": "SCR_OP_B", "header": 2, "table": 1}])
        self.assertEqual(report["header_values_outside_table"], [{"name": "SCR_OP_B", "value": 2}])
        self.assertEqual(report["status"], "divergent")

    def opcode_fixture(self, header_source, table_source):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            header = root / "include/constants/script_commands.h"
            table = root / "data/script_cmd_table.inc"
            header.parent.mkdir(parents=True)
            table.parent.mkdir(parents=True)
            header.write_text(header_source, encoding="utf-8")
            table.write_text(table_source, encoding="utf-8")
            return audit.opcode_report(root)

    def test_opcode_report_reads_entries_without_address_comments(self):
        report = self.opcode_fixture(
            "SCR_OP_A = 0x00,\nSCR_OP_B = 1,\n",
            "@ script_cmd_table_entry SCR_OP_FAKE Handler @ 0x00\n"
            "script_cmd_table_entry SCR_OP_A Handler\n"
            "script_cmd_table_entry SCR_OP_B OtherHandler @ not an address\n",
        )
        self.assertEqual(report["status"], "complete")
        self.assertEqual(report["table_value_source"], "entry_ordinal")
        self.assertEqual(report["table_range"], {"first": 0, "last": 1})
        self.assertEqual([entry["value"] for entry in report["entries"]], [0, 1])

    def test_opcode_report_reports_wrong_comments_without_using_their_values(self):
        report = self.opcode_fixture(
            "SCR_OP_A = 0x00,\nSCR_OP_B = 0x01,\n",
            "script_cmd_table_entry SCR_OP_A Handler @ 0x09\n"
            "script_cmd_table_entry SCR_OP_B Handler @ 0x00\n",
        )
        self.assertEqual(report["divergent_values"], [])
        self.assertEqual(report["table_comment_mismatches"], [
            {"name": "SCR_OP_A", "ordinal": 0, "comment": 9, "line": 1},
            {"name": "SCR_OP_B", "ordinal": 1, "comment": 0, "line": 2},
        ])
        self.assertEqual(report["status"], "divergent")

    def test_opcode_report_reports_missing_and_us_only_names(self):
        report = self.opcode_fixture(
            "SCR_OP_NOP = 0x00,\nSCR_OP_US_ONLY = 0x01,\nSCR_OP_US_TAIL = 0xE1,\n",
            "script_cmd_table_entry SCR_OP_NOP Handler\n"
            "script_cmd_table_entry SCR_OP_JP_ONLY Handler\n",
        )
        self.assertEqual(report["header_only_opcodes"], ["SCR_OP_US_ONLY", "SCR_OP_US_TAIL"])
        self.assertEqual(report["table_only_opcodes"], ["SCR_OP_JP_ONLY"])
        self.assertEqual(report["shared_opcodes"], 1)
        self.assertEqual(report["status"], "divergent")

    def test_opcode_report_does_not_hide_duplicate_names_or_values(self):
        report = self.opcode_fixture(
            "SCR_OP_A = 0x00,\nSCR_OP_A = 0x01,\nSCR_OP_B = 0x01,\n",
            "script_cmd_table_entry SCR_OP_A Handler\n"
            "script_cmd_table_entry SCR_OP_A Handler\n",
        )
        self.assertEqual(report["duplicate_header_names"], ["SCR_OP_A"])
        self.assertEqual(report["duplicate_table_names"], ["SCR_OP_A"])
        self.assertEqual(report["duplicate_header_values"], [1])
        self.assertEqual(report["header_entries"], 3)
        self.assertEqual(report["table_entries"], 2)
        self.assertEqual(report["status"], "divergent")

    def test_opcode_report_excludes_end_sentinel_and_commented_header_values(self):
        report = self.opcode_fixture(
            "// SCR_OP_BAD = 0xE1,\n/* SCR_OP_BAD2 = 0xE2, */\nSCR_OP_A = 0x00,\n",
            "enum_start\ngScriptCmdTable::\n"
            "script_cmd_table_entry SCR_OP_A Handler\n"
            "gScriptCmdTableEnd::\n.4byte ScrCmd_nop\n",
        )
        self.assertEqual(report["status"], "complete")
        self.assertEqual(report["table_entries"], 1)
        self.assertEqual(report["header_entries"], 1)

    def test_opcode_report_checks_order_and_rejects_empty_contract(self):
        report = self.opcode_fixture(
            "SCR_OP_B = 0x01,\nSCR_OP_A = 0x00,\n",
            "script_cmd_table_entry SCR_OP_A Handler\n"
            "script_cmd_table_entry SCR_OP_B Handler\n",
        )
        self.assertEqual(report["divergent_values"], [])
        self.assertFalse(report["header_order_matches_table"])
        self.assertEqual(report["status"], "divergent")
        empty = self.opcode_fixture("", "")
        self.assertIsNone(empty["table_range"])
        self.assertEqual(empty["status"], "divergent")

    def test_complete_jp_opcode_header_matches_all_225_dispatch_slots(self):
        report = audit.opcode_report(audit.ROOT)
        self.assertEqual(report["status"], "complete")
        self.assertEqual(report["header_entries"], 225)
        self.assertEqual(report["table_entries"], 225)
        self.assertEqual(report["table_range"], {"first": 0, "last": 0xE0})
        actual = {entry["name"]: entry["value"] for entry in report["entries"]}
        header = {entry["name"]: entry["value"] for entry in audit.parse_opcode_header(
            audit.ROOT / "include/constants/script_commands.h")}
        self.assertEqual(header, actual)
        self.assertEqual(actual["SCR_OP_DRAWBOX"], 0x72)
        self.assertEqual(actual["SCR_OP_ERASEBOX"], 0x73)
        self.assertEqual(actual["SCR_OP_DRAWBOXTEXT"], 0x74)
        self.assertEqual(actual["SCR_OP_CHECKPARTYMOVE"], 0x7C)
        self.assertEqual(actual["SCR_OP_DRAWBOX_JP"], 0xB2)
        self.assertEqual(actual["SCR_OP_CD"], 0xCD)
        self.assertEqual(actual["SCR_OP_CE"], 0xCE)
        for name in ("SCR_OP_SHOWELEVMENU", "SCR_OP_CHECKFIELDMOVE",
                     "SCR_OP_SETMODERNFATEFULENCOUNTER", "SCR_OP_CHECKMODERNFATEFULENCOUNTER",
                     "SCR_OP_BUFFERCONTESTNAME", "SCR_OP_BUFFERITEMNAMEPLURAL",
                     "SCR_OP_DYNMULTICHOICE", "SCR_OP_DYNMULTIPUSH",
                     "SCR_OP_HIDEFOLLOWER", "SCR_OP_GETBRAILLESTRINGWIDTH"):
            self.assertNotIn(name, header)

    def test_constants_report_hashes_equal_files(self):
        with tempfile.TemporaryDirectory() as temporary:
            jp = Path(temporary) / "jp"
            us = Path(temporary) / "us"
            for root in (jp, us):
                constants = root / "include/constants"
                constants.mkdir(parents=True)
                (constants / "vars.h").write_text("vars\n", encoding="utf-8")
                (constants / "flags.h").write_text("flags\n", encoding="utf-8")
            report = audit.constants_report(jp, us)
        self.assertTrue(report["vars.h"]["identical"])
        self.assertTrue(report["flags.h"]["identical"])


if __name__ == "__main__":
    unittest.main()
