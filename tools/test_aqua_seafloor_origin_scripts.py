import hashlib
import json
from pathlib import Path
import re
import unittest

import jp_emit_maps as emitter
import jp_script_parser as parser
import verify_generated_map_scripts as verifier
import map_review_script_profile as review_profile
import map_semantic_review as semantic_review
import test_map_review_script_profile as native_forms


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / "pokeemerald"
MAPS = (
    "AquaHideout_1F",
    "AquaHideout_B1F",
    "AquaHideout_B2F",
    "Underwater_SeafloorCavern",
    "SeafloorCavern_Entrance",
    "SeafloorCavern_Room1",
    "SeafloorCavern_Room2",
    "SeafloorCavern_Room3",
    "SeafloorCavern_Room4",
    "SeafloorCavern_Room5",
    "SeafloorCavern_Room6",
    "SeafloorCavern_Room7",
    "SeafloorCavern_Room8",
    "SeafloorCavern_Room9",
    "CaveOfOrigin_Entrance",
    "CaveOfOrigin_1F",
    "CaveOfOrigin_UnusedRubySapphireMap1",
    "CaveOfOrigin_UnusedRubySapphireMap2",
    "CaveOfOrigin_UnusedRubySapphireMap3",
    "CaveOfOrigin_B1F",
)
SERIAL_COUNTS = {
    "AquaHideout_B2F": 5,
    "SeafloorCavern_Entrance": 7,
    "SeafloorCavern_Room9": 14,
    "CaveOfOrigin_B1F": 4,
}
PARALLEL_SIZES = {"AquaHideout_B2F": [2], "SeafloorCavern_Room9": [2, 3, 2]}


class AquaMeasuredProfileTests(unittest.TestCase):
    def parse(self, text, version=4):
        return review_profile.profile_block(ROOT, 'Entry::\n' + text, {},
                                            version=version, address=0x082189FE)

    def test_sparkle_expands_to_three_arguments_and_one_field_effect(self):
        for text in ('dofieldeffectsparkle 16, 42, 0',
                     'dofieldeffectsparkle 0x10, 0x2A, 0x0'):
            result = self.parse(text)
            self.assertEqual(result.size, 15)
            self.assertFalse(result.targets or result.texts or result.specials)

    def test_sparkle_rejects_wrong_arity_unmodeled_variables_and_bad_priority(self):
        for text in ('dofieldeffectsparkle', 'dofieldeffectsparkle 16, 42',
                     'dofieldeffectsparkle 16, 42, 0, 0',
                     'dofieldeffectsparkle VAR_0x8004, 42, 0',
                     'dofieldeffectsparkle 65536, 42, 0',
                     'dofieldeffectsparkle 16, -1, 0',
                     'dofieldeffectsparkle 16, 42, 4'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text)

    def test_upward_slide_is_a_terminated_movement_not_a_script(self):
        result = self.parse('slide_up\nslide_up\nstep_end')
        self.assertEqual((result.kind, result.size), ('movement', 3))
        for text in ('slide_up', 'slide_up\nend', 'slide_up 1\nstep_end'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text)

    def test_new_forms_leave_legacy_profile_rules_closed(self):
        for text in ('dofieldeffectsparkle 16, 42, 0', 'slide_up\nstep_end'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text, version=3)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_new_forms_match_the_real_macro_assembler_pipeline(self):
        native_forms.StoryProfileTests().check_native_forms([
            'dofieldeffectsparkle 16, 42, 0', 'slide_up'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_full_kyogre_owner_closes_the_actual_1714_byte_span(self):
        name = 'SeafloorCavern_Room9'
        symbols, _ = semantic_review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        start = next(iter(symbols[name + '_MapScripts']))
        end = next(iter(symbols['CaveOfOrigin_Entrance_MapScripts']))
        self.assertEqual(end - start, 1714)
        at = start
        for label, part in review_profile.profile_owner(ROOT,
                (ROOT / f'data/maps/{name}/scripts.inc').read_text(),
                version=4, address=start).items():
            self.assertEqual(symbols[label], {at}, label)
            at += part.size
        self.assertEqual(at, end)


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
            if line in ("waitmovement 0", "waitmovement 0x0") and len(pending) > 1:
                groups.append(tuple(pending))
            pending = []
    return groups


@unittest.skipUnless((US / "data/event_scripts.s").exists(), "US reference checkout required")
class AquaSeafloorOriginScriptsTests(unittest.TestCase):
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
        end = 0x08217935
        total_texts = 0
        for name in MAPS:
            with self.subTest(map=name):
                start, end_next, generated, texts, raw_segments = verifier.map_context(name)
                self.assertEqual(start, end)
                end = end_next
                total_texts += texts
                self.assertEqual(raw_segments, 0)
                self.assertEqual(source_lines(self.jp[name]), source_lines(generated))
        self.assertEqual(end, 0x0821949C)
        self.assertEqual(end - 0x08217935, 7015)
        self.assertEqual(total_texts, 76)

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
        self.assertEqual(sum(SERIAL_COUNTS.values()), 30)
        self.assertEqual(sum(len(sizes) for sizes in PARALLEL_SIZES.values()), 4)

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
        candidate = verifier.assemble_candidate(source, 0x08217935)
        expected = (ROOT / "baserom_jp.gba").read_bytes()[0x217935:0x21949C]
        self.assertEqual(len(candidate), 7015)
        self.assertEqual(candidate, expected)
        self.assertEqual(hashlib.sha256(candidate).hexdigest(),
                         "38a1b93cb6ea1d5c04dc052f142133ef7290838329a373425b926ff7a9fda971")

    def test_hideout_hints_capture_cleanup_and_submarine_escape(self):
        for grunt in (1, 2):
            self.assert_ordered(
                self.script_block("AquaHideout_1F", "HideoutEntranceGrunt" + str(grunt)), [
                    "goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, "
                    "AquaHideout_1F_EventScript_SlateportHint" + str(grunt),
                    "goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, "
                    "AquaHideout_1F_EventScript_MagmaHideoutHint" + str(grunt),
                ])
        self.assertEqual(self.script_block("AquaHideout_B1F", "TryRemoveElectrode"), [
            "specialvar VAR_RESULT, GetBattleOutcome",
            "goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn",
            "removeobject VAR_LAST_TALKED",
            "return",
        ])
        rom = (ROOT / "baserom_jp.gba").read_bytes()
        for electrode, cry_wait in ((1, 0x217D05), (2, 0x217D52)):
            lines = self.script_block("AquaHideout_B1F", "Electrode" + str(electrode))
            self.assertEqual(rom[cry_wait], 0xC5)
            self.assert_ordered(lines, [
                "setwildbattle SPECIES_ELECTRODE, 30",
                "playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER",
                "delay 40",
                "waitmoncry",
                "setflag FLAG_SYS_CTRL_OBJ_DELETE",
                "dowildbattle",
                "clearflag FLAG_SYS_CTRL_OBJ_DELETE",
                "specialvar VAR_RESULT, GetBattleOutcome",
            ])
            for outcome in ("WON", "RAN", "PLAYER_TELEPORTED"):
                self.assertIn("goto_if_eq VAR_RESULT, B_OUTCOME_" + outcome +
                              ", AquaHideout_B1F_EventScript_DefeatedElectrode" + str(electrode), lines)
            self.assertIn("goto Common_EventScript_RemoveStaticPokemon",
                          self.script_block("AquaHideout_B1F", "DefeatedElectrode" + str(electrode)))
        self.assert_ordered(self.script_block("AquaHideout_B2F", "SubmarineEscape"), [
            "setvar VAR_0x8008, LOCALID_AQUA_HIDEOUT_MATT",
            "setvar VAR_0x8009, LOCALID_AQUA_HIDEOUT_SUBMARINE",
            "applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft",
            "applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft",
            "waitmovement 0",
            "removeobject VAR_0x8009",
            "setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE",
            "setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS",
        ])
        self.assertIn("AquaHideout_B2F_Movement_SumbarineDepartRight:",
                      instruction_lines(self.jp["AquaHideout_B2F"]))

    def test_instruction_scoped_object_names_do_not_rename_camera_parameters(self):
        name = "SeafloorCavern_Room9"
        entry = 0x082189FE
        assignments = {
            entry + off: args
            for off, operation, args, _refs in parser.parse_script(entry)
            if operation == "setvar"
        }
        object_ids = (
            (0x082189FF, 0x8004, 2, "ARCHIE"),
            (0x08218A04, 0x8005, 3, "MAXIE"),
            (0x08218A09, 0x8006, 4, "GRUNT_1"),
            (0x08218A0E, 0x8007, 5, "GRUNT_2"),
            (0x08218B35, 0x8004, 2, "ARCHIE"),
            (0x08218B3A, 0x8005, 3, "MAXIE"),
            (0x08218B3F, 0x8006, 4, "GRUNT_1"),
            (0x08218B44, 0x8007, 5, "GRUNT_2"),
        )
        for address, var, value, suffix in object_ids:
            with self.subTest(address=hex(address)):
                self.assertEqual(tuple(assignments[address]), (var, value))
                formatter = emitter.semantic_symbol_formatter(name, entry, address)
                self.assertEqual(formatter("setvar", 1, value, (var, value)),
                                 "LOCALID_SEAFLOOR_CAVERN_" + suffix)
                self.assertNotEqual(formatter("setvar", 1, value + 1, (var, value + 1)),
                                    "LOCALID_SEAFLOOR_CAVERN_" + suffix)
                self.assertNotEqual(formatter("setvar", 1, value, (0x800D, value)),
                                    "LOCALID_SEAFLOOR_CAVERN_" + suffix)
        for address, var, value in (
            (0x08218AF2, 0x8004, 1), (0x08218AF7, 0x8005, 1),
            (0x08218AFC, 0x8006, 8), (0x08218B01, 0x8007, 5),
            (0x08218B1A, 0x8004, 2), (0x08218B1F, 0x8005, 2),
            (0x08218B24, 0x8006, 8), (0x08218B29, 0x8007, 5),
        ):
            with self.subTest(camera_address=hex(address)):
                self.assertEqual(tuple(assignments[address]), (var, value))
                formatter = emitter.semantic_symbol_formatter(name, entry, address)
                self.assertEqual(formatter("setvar", 1, value, (var, value)), str(value))
        for address in (None, entry, 0x08218AF2):
            formatter = emitter.semantic_symbol_formatter(name, entry, address)
            self.assertNotEqual(formatter("setvar", 1, 2, (0x8004, 2)),
                                "LOCALID_SEAFLOOR_CAVERN_ARCHIE")

    def test_kyogre_orb_and_camera_waits_preserve_jp_execution_order(self):
        lines = self.script_block("SeafloorCavern_Room9", "ArchieAwakenKyogre")
        self.assertIn("dofieldeffectsparkle 16, 42, 0", lines)
        for special in ("Script_FadeOutMapMusic", "WaitWeather", "FadeOutOrbEffect"):
            index = lines.index("special " + special)
            self.assertNotEqual(lines[index + 1], "waitstate")
        self.assert_ordered(lines, [
            "special DoOrbEffect",
            "applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp",
            "applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp",
            "waitmovement 0",
            "delay 150",
            "removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING",
            "addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE",
            "waitstate",
        ])
        self.assertNotEqual(lines[lines.index("special DoOrbEffect") + 1], "waitstate")
        shake_indices = [i for i, line in enumerate(lines) if line == "special ShakeCamera"]
        self.assertEqual(len(shake_indices), 2)
        for index in shake_indices:
            self.assertEqual(lines[index + 1], "waitstate")
        self.assert_ordered(lines, [
            "setvar VAR_ROUTE128_STATE, 1",
            "setvar VAR_SOOTOPOLIS_CITY_STATE, 1",
            "setflag FLAG_SYS_WEATHER_CTRL",
            "setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN",
            "setvar VAR_STEVENS_HOUSE_STATE, 2",
            "setvar VAR_SEAFLOOR_CAVERN_STATE, 1",
            "setflag FLAG_HIDE_MAP_NAME_POPUP",
            "warp MAP_ROUTE128, 38, 22",
            "waitstate",
            "releaseall",
            "end",
        ])
        for suffix in ("Unused1", "Unused2"):
            self.assertIn("SeafloorCavern_Room9_Movement_" + suffix + ":",
                          instruction_lines(self.jp["SeafloorCavern_Room9"]))

    def test_shared_cave_triggers_and_active_empty_rooms_keep_their_owners(self):
        for name in ("CaveOfOrigin_1F",) + tuple(
                "CaveOfOrigin_UnusedRubySapphireMap" + str(i) for i in (1, 2, 3)):
            self.assertEqual(instruction_lines(self.jp[name]), [
                name + "_MapScripts:",
                "map_script MAP_SCRIPT_ON_TRANSITION, " + name + "_OnTransition",
                ".byte 0",
                name + "_OnTransition:",
                "call_if_set FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE, "
                "CaveOfOrigin_EventScript_DisableTriggers",
                "end",
            ])
            self.assertNotIn("CaveOfOrigin_EventScript_DisableTriggers:", self.jp[name])
        for room in (2, 5, 6, 7, 8):
            name = "SeafloorCavern_Room" + str(room)
            self.assertEqual(instruction_lines(self.jp[name]), [name + "_MapScripts:", ".byte 0"])
            data = json.loads((ROOT / "data/maps" / name / "map.json").read_text(encoding="utf-8"))
            self.assertTrue(data["warp_events"])
        self.assertIn("setescapewarp MAP_SOOTOPOLIS_CITY, 31, 17",
                      instruction_lines(self.jp["CaveOfOrigin_Entrance"]))

    def test_wallace_question_loops_and_jp_honorifics_are_preserved(self):
        name = "CaveOfOrigin_B1F"
        choices = self.script_block(name, "WheresRayquaza")
        for index, suffix in enumerate(("AtCaveOfOrigin", "AtMtPyre", "AtSkyPillar", "DontRemember")):
            self.assertIn("goto_if_eq VAR_0x8000, " + str(index) + ", " +
                          name + "_EventScript_" + suffix, choices)
        for suffix in ("AtCaveOfOrigin", "AtMtPyre", "DontRemember"):
            self.assertIn("goto CaveOfOrigin_B1F_EventScript_WheresRayquaza",
                          self.script_block(name, suffix))
        self.assert_ordered(self.script_block(name, "AtSkyPillar"), [
            "setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR",
            "setvar VAR_SOOTOPOLIS_CITY_STATE, 3",
            "removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE",
            "clearflag FLAG_HIDE_SKY_PILLAR_WALLACE",
            "release",
            "end",
        ])
        self.assertEqual(self.jp[name].count("{PLAYER}{KUN}"), 4)
        self.assertEqual(self.us[name].count("{PLAYER}{KUN}"), 4)
        self.assertIn('.string "ミクリ“{PLAYER}{KUN}　ひょっとして\\n"', self.jp[name])


if __name__ == "__main__":
    unittest.main()
