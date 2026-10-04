import hashlib
import json
from pathlib import Path
import re
import unittest

import verify_generated_map_scripts as verifier


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / "pokeemerald"
MAPS = (
    "PetalburgWoods",
    "MtChimney",
    "JaggedPass",
    "FieryPath",
    "MtPyre_1F",
    "MtPyre_2F",
    "MtPyre_3F",
    "MtPyre_4F",
    "MtPyre_5F",
    "MtPyre_6F",
    "MtPyre_Exterior",
    "MtPyre_Summit",
)
SERIAL_COUNTS = {"PetalburgWoods":19,"MtChimney":9,"JaggedPass":6,"MtPyre_Summit":15}
PARALLEL_SIZES = {"PetalburgWoods":[2,2],"MtPyre_Summit":[2,3,3,3,3,3,3,2,2,2]}


def source_lines(source, include_text=True):
    lines = []
    for raw in source.splitlines():
        if raw.lstrip().startswith(".string"):
            if include_text:
                lines.append(raw.strip())
            continue
        line = raw.partition("@")[0].strip()
        if line:
            lines.append(line[:-1] if line.endswith("::") else line)
    return lines


def instruction_lines(source):
    lines = []
    for line in source_lines(source, include_text=False):
        line = re.sub(r"\bTRUE\b", "1", line)
        line = re.sub(r"\bFALSE\b", "0", line)
        line = re.sub(r"\b0x([0-9A-Fa-f]+)\b", lambda match: str(int(match[1], 16)), line)
        if line.startswith("applywaitmovement "):
            lines.extend(("applymovement " + line.split(None, 1)[1], "waitmovement 0"))
        elif line.startswith("switch "):
            lines.append("copyvar VAR_0x8000, " + line.split(None, 1)[1])
        elif line.startswith("case "):
            lines.append("goto_if_eq VAR_0x8000, " + line.split(None, 1)[1])
        else:
            lines.append(line)
    return lines


def parallel_movements(source):
    groups = []
    pending = []
    for line in source_lines(source, include_text=False):
        if line.startswith("applymovement "):
            pending.append(line)
        else:
            if line == "waitmovement 0" and len(pending) > 1:
                groups.append(tuple(pending))
            pending = []
    return groups


@unittest.skipUnless((US / "data/event_scripts.s").exists(), "US reference checkout required")
class WildernessMtPyreScriptsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.jp = {
            name: (ROOT / "data/maps" / name / "scripts.inc").read_text(encoding="utf-8")
            for name in MAPS
        }
        cls.us = {
            name: (US / "data/maps" / name / "scripts.inc").read_text(encoding="utf-8")
            for name in MAPS
        }

    def test_all_maps_match_reviewed_us_instruction_semantics(self):
        for name in MAPS:
            with self.subTest(map=name):
                self.assertEqual(instruction_lines(self.jp[name]), instruction_lines(self.us[name]))
                self.assertNotRegex(self.jp[name], r"(?m)^\s*\.(?:incbin|globl|set)\b")
                self.assertNotRegex(self.jp[name], r"\{(?:STRING|ESCAPE)\s")
                self.assertEqual(
                    json.loads((ROOT / "data/maps" / name / "map.json").read_text(encoding="utf-8")),
                    json.loads((US / "data/maps" / name / "map.json").read_text(encoding="utf-8")),
                )

    def test_all_maps_regenerate_without_hidden_raw_or_style_drift(self):
        end = 0x08214278
        total_texts = 0
        for name in MAPS:
            with self.subTest(map=name):
                start, end_next, generated, texts, raw_segments = verifier.map_context(name)
                self.assertEqual(start, end)
                end = end_next
                total_texts += texts
                self.assertEqual(raw_segments, 0)
                self.assertEqual(source_lines(self.jp[name]), source_lines(generated))
        self.assertEqual(end, 0x08217935)
        self.assertEqual(end - 0x08214278, 14013)
        self.assertEqual(total_texts, 192)

    def test_serial_helpers_do_not_serialize_parallel_groups(self):
        for name in MAPS:
            with self.subTest(map=name):
                helpers = re.findall(r"(?m)^\s*(applywaitmovement .+)$", self.jp[name])
                self.assertEqual(len(helpers), SERIAL_COUNTS.get(name, 0))
                self.assertEqual(
                    helpers, re.findall(r"(?m)^\s*(applywaitmovement .+)$", self.us[name])
                )
                groups = parallel_movements(self.jp[name])
                self.assertEqual([len(group) for group in groups], PARALLEL_SIZES.get(name, []))
                self.assertEqual(groups, parallel_movements(self.us[name]))
        self.assertEqual(sum(SERIAL_COUNTS.values()), 49)
        self.assertEqual(sum(len(sizes) for sizes in PARALLEL_SIZES.values()), 12)

    def script_block(self, name, suffix):
        lines = instruction_lines(self.jp[name])
        label = name + "_EventScript_" + suffix + ":"
        start = lines.index(label) + 1
        end = next((i for i in range(start, len(lines)) if lines[i].endswith(":")), len(lines))
        return lines[start:end]

    def assert_ordered(self, lines, expected):
        last = -1
        for line in expected:
            last = lines.index(line, last + 1)

    def test_complete_family_is_byte_exact_to_jp_rom(self):
        source = "\n".join(self.jp[name] for name in MAPS)
        candidate = verifier.assemble_candidate(source, 0x08214278)
        expected = (ROOT / "baserom_jp.gba").read_bytes()[0x214278:0x217935]
        self.assertEqual(len(candidate), 14013)
        self.assertEqual(candidate, expected)
        self.assertEqual(hashlib.sha256(candidate).hexdigest(),
                         "075219fc8fec0d0b876f9f180a93ebf1de924a987dc8a317fde3a1e1e304ae0c")

    def test_forest_reward_failures_and_match_call_gates(self):
        self.assert_ordered(self.script_block("PetalburgWoods", "DevonResearcherPostBattle"), [
            "giveitem ITEM_GREAT_BALL",
            "goto_if_eq VAR_RESULT, 0, PetalburgWoods_EventScript_BagFull",
            "goto PetalburgWoods_EventScript_DevonResearcherFinish",
        ])
        self.assertIn("goto PetalburgWoods_EventScript_DevonResearcherFinish",
                      self.script_block("PetalburgWoods", "BagFull"))
        self.assert_ordered(self.script_block("PetalburgWoods", "Girl"), [
            "giveitem ITEM_MIRACLE_SEED",
            "goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull",
            "setflag FLAG_RECEIVED_MIRACLE_SEED",
        ])
        for suffix in ("TryRegisterJames", "TryRegisterJames2"):
            self.assertRegex("\n".join(self.script_block("PetalburgWoods", suffix)),
                             r"goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2?")

    def test_volcano_purchase_and_meteorite_guards(self):
        self.assert_ordered(self.script_block("MtChimney", "LavaCookieLady"), [
            "checkmoney 200",
            "goto_if_eq VAR_RESULT, 0, MtChimney_EventScript_NotEnoughMoney",
            "checkitemspace ITEM_LAVA_COOKIE",
            "call_if_eq VAR_RESULT, 1, MtChimney_EventScript_RemoveMoney",
            "giveitem ITEM_LAVA_COOKIE",
            "goto_if_eq VAR_RESULT, 0, MtChimney_EventScript_BagIsFull",
        ])
        self.assertEqual(self.script_block("MtChimney", "RemoveMoney"),
                         ["removemoney 200", "updatemoneybox", "return"])
        self.assertNotIn("removemoney 200", self.script_block("MtChimney", "BagIsFull"))
        self.assert_ordered(self.script_block("MtChimney", "MeteoriteMachine"), [
            "goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn",
            "goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff",
            "giveitem ITEM_METEORITE",
            "setflag FLAG_RECEIVED_METEORITE",
        ])
        unused = re.findall(r"(?m)^(MtChimney_Movement_.*Unused\w*)\s*:", self.jp["MtChimney"])
        self.assertEqual(unused, re.findall(r"(?m)^(MtChimney_Movement_.*Unused\w*)\s*:",
                                           self.us["MtChimney"]))
        self.assertEqual(len(unused), 15)

    def test_magma_entrance_and_pyre_floor_ownership(self):
        entrance = self.script_block("JaggedPass", "OpenMagmaHideout")
        self.assertEqual(entrance.count("special ShakeCamera"), 2)
        self.assertEqual(entrance.count("waitstate"), 2)
        self.assert_ordered(entrance, [
            "setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, 1",
            "setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, 0",
            "special DrawWholeMapView",
            "setvar VAR_JAGGED_PASS_STATE, 2",
        ])
        self.assert_ordered(self.script_block("MtPyre_1F", "CleanseTagWoman"), [
            "giveitem ITEM_CLEANSE_TAG",
            "goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull",
            "setflag FLAG_RECEIVED_CLEANSE_TAG",
        ])
        self.assertIn("MtPyre_5F_EventScript_Atsushi:", instruction_lines(self.jp["MtPyre_4F"]))
        self.assertIn("MtPyre_4F_EventScript_Tasha:", instruction_lines(self.jp["MtPyre_5F"]))
        pyre2 = instruction_lines(self.jp["MtPyre_2F"])
        self.assertTrue(any("CaveHole_CheckFallDownHole" in line for line in pyre2))
        self.assertTrue(any("CaveHole_FixCrackedGround" in line for line in pyre2))

    def test_summit_trainers_and_orb_cutscene_states(self):
        header = (ROOT / "include/constants/opponents.h").read_text(encoding="utf-8")
        us_header = (US / "include/constants/opponents.h").read_text(encoding="utf-8")
        for grunt, value in enumerate((23, 24, 25, 569), 1):
            name = "TRAINER_GRUNT_MT_PYRE_" + str(grunt)
            for source in (header, us_header):
                self.assertRegex(source, r"(?m)^#define " + name + r"\s+" + str(value) + r"\s*$")
            self.assertTrue(self.script_block("MtPyre_Summit", "Grunt" + str(grunt))[0]
                            .startswith("trainerbattle_single " + name + ","))
        self.assert_ordered(self.script_block("MtPyre_Summit", "TeamAquaExits"), [
            "setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE",
            "setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA",
            "setvar VAR_MT_PYRE_STATE, 1",
            "giveitem ITEM_MAGMA_EMBLEM",
            "setflag FLAG_RECEIVED_RED_OR_BLUE_ORB",
            "setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD",
        ])
        self.assert_ordered(self.script_block("MtPyre_Summit", "ArchieMaxieReturnOrbs"), [
            "removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE",
            "removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE",
            "setvar VAR_MT_PYRE_STATE, 3",
            "releaseall",
        ])
        summit = self.jp["MtPyre_Summit"]
        self.assertIn('.string "マツブサ“{PLAYER}⋯⋯\\p"', summit)
        for lane in range(3):
            self.assertIn("setvar VAR_0x8008, " + str(lane),
                          self.script_block("MtPyre_Summit", "TeamAquaTrigger" + str(lane)))
            self.assertIn("setvar VAR_0x8008, " + str(lane),
                          self.script_block("MtPyre_Summit", "ArchieMaxieTrigger" + str(lane)))


if __name__ == "__main__":
    unittest.main()
