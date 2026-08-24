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
            header.write_text("SCR_OP_A = 0x01,\nSCR_OP_B = 0x02,\n", encoding="utf-8")
            table.write_text(
                "script_cmd_table_entry SCR_OP_A Handler @ 0x01\n"
                "script_cmd_table_entry SCR_OP_B Handler @ 0x03\n",
                encoding="utf-8",
            )
            report = audit.opcode_report(root)
        self.assertEqual(report["divergent_values"], [{"name": "SCR_OP_B", "header": 2, "table": 3}])

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
