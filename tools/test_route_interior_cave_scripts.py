import json
from pathlib import Path
import re
import unittest

import verify_generated_map_scripts as verifier


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / "pokeemerald"
MAPS = (
    "Route104_MrBrineysHouse",
    "Route104_PrettyPetalFlowerShop",
    "Route111_WinstrateFamilysHouse",
    "Route111_OldLadysRestStop",
    "Route112_CableCarStation",
    "MtChimney_CableCarStation",
    "Route114_FossilManiacsHouse",
    "Route114_FossilManiacsTunnel",
    "Route114_LanettesHouse",
    "Route116_TunnelersRestHouse",
    "Route117_PokemonDayCare",
    "Route121_SafariZoneEntrance",
    "MeteorFalls_1F_1R",
    "MeteorFalls_1F_2R",
    "MeteorFalls_B1F_1R",
    "MeteorFalls_B1F_2R",
    "RusturfTunnel",
    "Underwater_SootopolisCity",
    "DesertRuins",
    "GraniteCave_1F",
    "GraniteCave_B1F",
    "GraniteCave_B2F",
    "GraniteCave_StevensRoom",
)
SERIAL_COUNTS = {
    "Route111_WinstrateFamilysHouse": 1,
    "Route121_SafariZoneEntrance": 4,
    "MeteorFalls_1F_1R": 8,
    "RusturfTunnel": 13,
    "GraniteCave_StevensRoom": 1,
}
PARALLEL_SIZES = {
    "Route112_CableCarStation": [2, 2],
    "MtChimney_CableCarStation": [2, 2],
    "Route114_FossilManiacsTunnel": [2],
    "MeteorFalls_1F_1R": [2, 3, 3, 2, 3, 2, 3],
    "RusturfTunnel": [2, 2, 2, 2, 3, 2, 2, 2, 3],
    "GraniteCave_StevensRoom": [2, 2],
}


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
class RouteInteriorCaveScriptsTests(unittest.TestCase):
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
        end = 0x082115F0
        total_texts = 0
        for name in MAPS:
            with self.subTest(map=name):
                start, end_next, generated, texts, raw_segments = verifier.map_context(name)
                self.assertEqual(start, end)
                end = end_next
                total_texts += texts
                self.assertEqual(raw_segments, 0)
                self.assertEqual(source_lines(self.jp[name]), source_lines(generated))
        self.assertEqual(end, 0x08214278)
        self.assertEqual(end - 0x082115F0, 11400)
        self.assertEqual(total_texts, 102)

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
        self.assertEqual(sum(SERIAL_COUNTS.values()), 27)
        self.assertEqual(sum(len(sizes) for sizes in PARALLEL_SIZES.values()), 23)

    def script_block(self, name, suffix):
        lines = source_lines(self.jp[name], include_text=False)
        start = lines.index(name + suffix + ":") + 1
        end = next((index for index in range(start, len(lines)) if lines[index].endswith(":")), len(lines))
        return lines[start:end]

    def test_gift_failure_branches_precede_success_flags(self):
        for name, suffix, gift, failure, flag in (
            ("Route111_WinstrateFamilysHouse", "_EventScript_Victoria", "giveitem ITEM_MACHO_BRACE",
             "goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull", "FLAG_RECEIVED_MACHO_BRACE"),
            ("Route114_FossilManiacsHouse", "_EventScript_FossilManiacsBrother", "giveitem ITEM_TM_DIG",
             "goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull", "FLAG_RECEIVED_TM_DIG"),
            ("Route114_LanettesHouse", "_EventScript_Lanette", "givedecoration DECOR_LOTAD_DOLL",
             "goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor", "FLAG_RECEIVED_DOLL_LANETTE"),
        ):
            with self.subTest(map=name):
                lines = self.script_block(name, suffix)
                self.assertLess(lines.index(gift), lines.index(failure))
                self.assertLess(lines.index(failure), lines.index("setflag " + flag))
        steven = self.script_block("GraniteCave_StevensRoom", "_EventScript_Steven")
        self.assertIn("call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull", steven)
        self.assertIn("setflag FLAG_REGISTERED_STEVEN_POKENAV", steven)

    def test_cable_car_and_safari_wait_contracts(self):
        specials = (ROOT / "data/specials.inc").read_text(encoding="utf-8")
        for symbol, waiting in (
            ("CableCar", True), ("CableCarWarp", False), ("EnterSafariMode", False),
            ("ScriptCheckFreePokemonStorageSpace", False), ("StartRegiBattle", True),
        ):
            with self.subTest(special=symbol):
                match = re.search(r"(?m)^\s*def_special " + symbol + r"(?:,([^\n]+))?$", specials)
                self.assertIsNotNone(match)
                self.assertEqual("waitstate=1" in (match[1] or ""), waiting)
        for name, direction, state in (
            ("Route112_CableCarStation", "FALSE", 1),
            ("MtChimney_CableCarStation", "TRUE", 2),
        ):
            with self.subTest(map=name):
                ride = self.script_block(name, "_EventScript_RideCableCar")
                self.assertIn("setvar VAR_0x8004, " + direction, ride)
                self.assertIn("setvar VAR_CABLE_CAR_STATION_STATE, " + str(state), ride)
                self.assertEqual(ride[-3:], ["special CableCar", "release", "end"])
                self.assertIn("setvar VAR_CABLE_CAR_STATION_STATE, 0",
                              self.script_block(name, "_EventScript_ExitCableCar"))
        safari = self.script_block("Route121_SafariZoneEntrance", "_EventScript_TryEnterSafariZone")
        for before, after in (
            ("checkitem ITEM_POKEBLOCK_CASE", "call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon"),
            ("call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon", "checkmoney 500"),
            ("checkmoney 500", "removemoney 500"),
            ("removemoney 500", "special EnterSafariMode"),
        ):
            self.assertLess(safari.index(before), safari.index(after))
        self.assertEqual(safari[-3:], ["warp MAP_SAFARI_ZONE_SOUTH, 32, 33", "waitstate", "end"])

    def test_shared_owners_are_referenced_not_duplicated(self):
        for name in ("Route104_PrettyPetalFlowerShop", "Route117_PokemonDayCare",
                     "Route121_SafariZoneEntrance"):
            with self.subTest(map=name):
                self.assertNotIn(".string", self.jp[name])
        self.assertNotIn("Route117_PokemonDayCare_EventScript_DaycareWoman:",
                         self.jp["Route117_PokemonDayCare"])
        granite = source_lines(self.jp["GraniteCave_B1F"], include_text=False)
        self.assertIn("map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole", granite)
        self.assertIn("map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround", granite)
        desert = source_lines(self.jp["DesertRuins"], include_text=False)
        self.assertEqual(desert.count("braillemsgbox DesertRuins_Braille_UseRockSmash"), 2)

    def test_whole_batch_is_contiguous_in_top_level_include_order(self):
        top = (ROOT / "data/event_scripts.s").read_text(encoding="utf-8")
        names = re.findall(r'(?m)^\s*\.include "data/maps/([^/]+)/scripts\.inc"', top)
        start = names.index(MAPS[0])
        self.assertEqual(tuple(names[start:start + len(MAPS)]), MAPS)
        self.assertEqual(names[start + len(MAPS)], "PetalburgWoods")


if __name__ == "__main__":
    unittest.main()
