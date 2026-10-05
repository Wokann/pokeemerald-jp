"""Regression coverage for the contiguous JP dungeon map-script batch."""

import json
from pathlib import Path
import re
import unittest
from unittest import mock

import jp_emit_maps as emitter
import verify_generated_map_scripts as verifier


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / "pokeemerald"
MAPS = (
    "VictoryRoad_1F",
    "VictoryRoad_B1F",
    "VictoryRoad_B2F",
    "ShoalCave_LowTideEntranceRoom",
    "ShoalCave_LowTideInnerRoom",
    "ShoalCave_LowTideStairsRoom",
    "ShoalCave_LowTideLowerRoom",
    "ShoalCave_HighTideEntranceRoom",
    "ShoalCave_HighTideInnerRoom",
    "NewMauville_Entrance",
    "NewMauville_Inside",
    "AbandonedShip_Deck",
    "AbandonedShip_Corridors_1F",
    "AbandonedShip_Rooms_1F",
    "AbandonedShip_Corridors_B1F",
    "AbandonedShip_Rooms_B1F",
    "AbandonedShip_Rooms2_B1F",
    "AbandonedShip_Underwater1",
    "AbandonedShip_Room_B1F",
    "AbandonedShip_Rooms2_1F",
    "AbandonedShip_CaptainsOffice",
    "AbandonedShip_Underwater2",
    "AbandonedShip_HiddenFloorCorridors",
    "AbandonedShip_HiddenFloorRooms",
    "IslandCave",
    "AncientTomb",
    "Underwater_Route134",
    "Underwater_SealedChamber",
    "SealedChamber_OuterRoom",
    "SealedChamber_InnerRoom",
    "ScorchedSlab",
    "AquaHideout_UnusedRubyMap1",
    "AquaHideout_UnusedRubyMap2",
    "AquaHideout_UnusedRubyMap3",
    "SkyPillar_Entrance",
    "SkyPillar_Outside",
    "SkyPillar_1F",
    "SkyPillar_2F",
    "SkyPillar_3F",
    "SkyPillar_4F",
    "ShoalCave_LowTideIceRoom",
    "SkyPillar_5F",
    "SkyPillar_Top",
    "MagmaHideout_1F",
    "MagmaHideout_2F_1R",
    "MagmaHideout_2F_2R",
    "MagmaHideout_3F_1R",
    "MagmaHideout_3F_2R",
    "MagmaHideout_4F",
    "MagmaHideout_3F_3R",
    "MagmaHideout_2F_3R",
    "MirageTower_1F",
    "MirageTower_2F",
    "MirageTower_3F",
    "MirageTower_4F",
    "DesertUnderpass",
    "ArtisanCave_B1F",
    "ArtisanCave_1F",
    "Underwater_MarineCave",
    "MarineCave_Entrance",
    "MarineCave_End",
    "TerraCave_Entrance",
    "TerraCave_End",
    "AlteringCave",
    "MeteorFalls_StevensCave",
)
SERIAL_COUNTS = {
    "VictoryRoad_1F": 3,
    "NewMauville_Entrance": 1,
    "SkyPillar_Outside": 5,
    "SkyPillar_Top": 5,
    "MagmaHideout_4F": 6,
    "MarineCave_End": 2,
    "TerraCave_End": 2,
    "MeteorFalls_StevensCave": 4,
}
PARALLEL_SIZES = {"SkyPillar_Outside": [2]}


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
        elif line.startswith("setwildbattle "):
            lines.append(re.sub(r", 0$", "", line))
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
class DungeonMapScriptsTests(unittest.TestCase):
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
        end = 0x0821949C
        total_texts = 0
        for name in MAPS:
            with self.subTest(map=name):
                start, end_next, generated, texts, raw_segments = verifier.map_context(name)
                self.assertEqual(start, end)
                end = end_next
                total_texts += texts
                self.assertEqual(raw_segments, 0)
                self.assertEqual(source_lines(self.jp[name]), source_lines(generated))
        self.assertEqual(end, 0x0821D372)
        self.assertEqual(end - 0x0821949C, 16086)
        self.assertEqual(total_texts, 189)

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
        self.assertEqual(sum(SERIAL_COUNTS.values()), 28)
        self.assertEqual(sum(len(sizes) for sizes in PARALLEL_SIZES.values()), 1)

    def test_whole_contiguous_owner_matches_rom_without_shared_base_bytes(self):
        actual = verifier.assemble_candidate(
            "\n".join(self.jp[name] for name in MAPS), 0x0821949C
        )
        expected = emitter.ROM[0x21949C:0x21D372]
        self.assertEqual(len(actual), 16086)
        self.assertEqual(actual, expected)
        top = (ROOT / "data/event_scripts.s").read_text(encoding="utf-8")
        includes = re.findall(r'^\s*\.include "([^"]+)"', top, re.MULTILINE)
        first = includes.index("data/maps/VictoryRoad_1F/scripts.inc")
        self.assertEqual(
            includes[first:first + len(MAPS)],
            [f"data/maps/{name}/scripts.inc" for name in MAPS],
        )
        self.assertEqual(
            includes[first + len(MAPS)], "data/scripts/shared_secret_base.inc"
        )

    def test_verifier_uses_emitter_source_boundaries_and_rejects_invalid_ends(self):
        entries = ((0x0821D1A6, "MeteorFalls_StevensCave"),
                   (0x0821D626, "BattleColosseum_2P"))
        self.assertEqual(verifier.region_end(entries, 0, 0x0828F000), 0x0821D372)
        for invalid in (0x0821D1A6, 0x0821D627):
            with self.subTest(end=invalid), mock.patch.dict(
                emitter.MAP_SOURCE_REGION_ENDS, {"MeteorFalls_StevensCave": invalid}
            ):
                with self.assertRaises(verifier.VerificationError):
                    verifier.region_end(entries, 0, 0x0828F000)

    def test_cracked_ground_preserves_either_verified_build_branch(self):
        branch = (
            '#ifdef UBFIX\n\tsetvar VAR_ICE_STEP_COUNT, 1\n#else\n'
            '\tcopyvar VAR_ICE_STEP_COUNT, 1, warn=FALSE\n#endif')
        for name in ('SkyPillar_2F', 'SkyPillar_4F'):
            for command in ('\tsetvar VAR_ICE_STEP_COUNT, 1',
                            '\tcopyvar VAR_ICE_STEP_COUNT, 1, warn=FALSE'):
                with self.subTest(map=name, command=command):
                    self.assertEqual(
                        emitter.preserve_reviewed_cracked_ground_fix(name, command + '\n'),
                        branch + '\n',
                    )
            with self.assertRaises(RuntimeError):
                emitter.preserve_reviewed_cracked_ground_fix(name, '\tsetvar VAR_ICE_STEP_COUNT, 0\n')

    def test_regi_and_postgame_legendaries_keep_capture_escape_cleanup(self):
        for name, species in (
            ("IslandCave", "REGICE"), ("AncientTomb", "REGISTEEL"),
            ("SkyPillar_Top", "RAYQUAZA"), ("MarineCave_End", "KYOGRE"),
            ("TerraCave_End", "GROUDON"),
        ):
            with self.subTest(map=name):
                source = self.jp[name]
                self.assertIn("specialvar VAR_RESULT, GetBattleOutcome", source)
                for outcome in ("CAUGHT", "WON", "RAN", "PLAYER_TELEPORTED"):
                    self.assertIn(f"B_OUTCOME_{outcome}", source)
                self.assertIn(f"setflag FLAG_DEFEATED_{species}", source)
                self.assertIn("setflag FLAG_SYS_CTRL_OBJ_DELETE", source)
                self.assertIn("clearflag FLAG_SYS_CTRL_OBJ_DELETE", source)
                self.assertRegex(source, r"playmoncry SPECIES_" + species)
                self.assertIn("delay 40\n\twaitmoncry", source)
        for name in ("MarineCave_End", "TerraCave_End"):
            self.assertEqual(
                self.jp[name].count("setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1"), 2
            )
            self.assertIn("goto Common_EventScript_LegendaryFlewAway", self.jp[name])

    def test_cracked_floors_and_braille_keep_shared_semantic_owners(self):
        for name, below in (
            ("SkyPillar_2F", "SKY_PILLAR_1F"),
            ("SkyPillar_4F", "SKY_PILLAR_3F"),
            ("MirageTower_2F", "MIRAGE_TOWER_1F"),
            ("MirageTower_3F", "MIRAGE_TOWER_2F"),
        ):
            with self.subTest(map=name):
                self.assertIn("CaveHole_CheckFallDownHole", self.jp[name])
                self.assertIn("setstepcallback STEP_CB_CRACKED_FLOOR", self.jp[name])
                self.assertIn(f"setholewarp MAP_{below}", self.jp[name])
        for name in ("SkyPillar_2F", "SkyPillar_4F"):
            self.assertIn(
                "#ifdef UBFIX\n\tsetvar VAR_ICE_STEP_COUNT, 1\n#else\n"
                "\tcopyvar VAR_ICE_STEP_COUNT, 1, warn=FALSE\n#endif",
                self.jp[name],
            )
        for name in ("SealedChamber_OuterRoom", "SealedChamber_InnerRoom",
                     "Underwater_SealedChamber", "IslandCave", "AncientTomb"):
            self.assertIn("braille", self.jp[name])
            self.assertNotIn(".braille", self.jp[name])
        self.assertIn("specialvar VAR_RESULT, CheckRelicanthWailord", self.jp["SealedChamber_InnerRoom"])

    def test_abandoned_ship_keeps_scanner_and_permanent_key_door_state(self):
        office = self.jp["AbandonedShip_CaptainsOffice"]
        self.assertIn("ITEM_SCANNER", office)
        self.assertNotIn("removeitem", office)
        corridor = self.jp["AbandonedShip_HiddenFloorCorridors"]
        for room in (1, 2, 4, 6):
            self.assertIn(f"removeitem ITEM_ROOM_{room}_KEY", corridor)
            self.assertIn(f"FLAG_USED_ROOM_{room}_KEY", corridor)
        self.assertNotIn(
            "AbandonedShip_Text_TheDoorIsOpen:",
            "\n".join(source_lines(corridor)),
        )
        self.assertIn(
            "AbandonedShip_Text_TheDoorIsOpen:",
            "\n".join(source_lines(self.jp["AbandonedShip_Corridors_B1F"])),
        )
        rooms = self.jp["AbandonedShip_HiddenFloorRooms"]
        self.assertEqual(rooms.count("dofieldeffectsparkle "), 10)
        self.assertIn("switch VAR_TEMP_4", rooms)

    def test_sky_pillar_and_magma_scene_states_keep_story_dependencies(self):
        outside = self.jp["SkyPillar_Outside"]
        self.assertIn("setvar VAR_SOOTOPOLIS_CITY_STATE, 4", outside)
        self.assertIn("clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE", outside)
        top = self.jp["SkyPillar_Top"]
        self.assertIn("setvar VAR_SOOTOPOLIS_CITY_STATE, 5", top)
        self.assertIn("setvar VAR_SKY_PILLAR_STATE, 1", top)
        self.assertIn("setvar VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE, 1", top)
        self.assertEqual(top.count("special SpawnCameraObject"), 2)
        self.assertEqual(top.count("special RemoveCameraObject"), 2)
        magma = self.jp["MagmaHideout_4F"]
        self.assertIn("special DoOrbEffect", magma)
        self.assertIn("special FadeOutOrbEffect", magma)
        self.assertIn("setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT", magma)
        self.assertIn("setvar VAR_SLATEPORT_CITY_STATE, 1", magma)
        self.assertIn("setvar VAR_SLATEPORT_HARBOR_STATE, 1", magma)
        self.assertIn("trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT", magma)
        steven = self.jp["MeteorFalls_StevensCave"]
        self.assertIn("trainerbattle_no_intro TRAINER_STEVEN", steven)
        self.assertIn("setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN", steven)

    def test_fossils_unused_tables_and_jp_placeholders_are_preserved(self):
        for name in ("AquaHideout_UnusedRubyMap1", "AquaHideout_UnusedRubyMap2",
                     "AquaHideout_UnusedRubyMap3", "ShoalCave_LowTideIceRoom",
                     "MagmaHideout_3F_3R", "MagmaHideout_2F_3R", "ArtisanCave_1F"):
            self.assertEqual(
                source_lines(self.jp[name]), [f"{name}_MapScripts:", ".byte 0"]
            )
        tower = self.jp["MirageTower_4F"]
        for fossil in ("ROOT", "CLAW"):
            self.assertIn(f"giveitem ITEM_{fossil}_FOSSIL", tower)
            self.assertIn(f"setflag FLAG_CHOSE_{fossil}_FOSSIL", tower)
        underpass = self.jp["DesertUnderpass"]
        self.assertIn("FLAG_CHOSE_ROOT_FOSSIL", underpass)
        self.assertIn("FLAG_CHOSE_CLAW_FOSSIL", underpass)
        self.assertIn("special DoMirageTowerCeilingCrumble", tower)
        self.assertIn("{PLAYER}{KUN}", self.jp["SkyPillar_Outside"])
        self.assertIn("{PLAYER}{KUN}", self.jp["MeteorFalls_StevensCave"])


if __name__ == "__main__":
    unittest.main()
