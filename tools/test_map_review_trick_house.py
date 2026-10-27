"""Measured Trick House forms retain their own owners and native encodings."""
from pathlib import Path
import json
import struct
import subprocess
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier
import jp_emit_maps as emitter

ROOT = Path(__file__).resolve().parents[1]
SPARKLE = 'Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle'
PAD = 'Route110_TrickHousePuzzle7_EventScript_TeleportPad'
BUTTONS = ['Route110_TrickHousePuzzle7_EventScript_' + color + 'Button'
           for color in ('Yellow', 'Blue', 'Green', 'Purple', 'Red')]
VARIABLE_SPARKLE = 'dofieldeffectsparkle VAR_0x8004, VAR_0x8005, VAR_0x8006'
TELEPORT = 'warpteleport MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 3, 19'


class TrickHouseProfileTests(unittest.TestCase):
    def parse(self, body, owner='Owner', version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body, version=version, address=0x0823C9E0)

    def test_variable_sparkle_requires_exact_owner_and_register_order(self):
        result = self.parse(VARIABLE_SPARKLE + '\nreturn', SPARKLE)
        self.assertEqual(result.size, 16)
        for changed in (VARIABLE_SPARKLE.replace('8006', '8007'),
                        VARIABLE_SPARKLE.replace('8004', '8005'),
                        VARIABLE_SPARKLE.replace('VAR_0x8006', '0'), VARIABLE_SPARKLE + ', 0'):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed + '\nreturn', SPARKLE)
        with self.assertRaises(ValueError):
            self.parse(VARIABLE_SPARKLE + '\nreturn')
        self.assertEqual(self.parse('dofieldeffectsparkle 1, 2, 0\nreturn').size, 16)

    def test_true_rotation_mode_is_only_the_five_actual_trick_buttons(self):
        for owner in BUTTONS:
            self.assertEqual(self.parse('initrotatingtilepuzzle TRUE\nreturn', owner).size, 4)
            for value in ('1', 'VAR_RESULT', 'FALSE, TRUE'):
                with self.subTest(owner=owner, value=value), self.assertRaises(ValueError):
                    self.parse('initrotatingtilepuzzle ' + value + '\nreturn', owner)
        with self.assertRaises(ValueError):
            self.parse('initrotatingtilepuzzle TRUE\nreturn')
        self.assertEqual(self.parse('initrotatingtilepuzzle FALSE\nreturn').size, 4)

    def test_teleport_only_accepts_real_pad_destination_coordinates_and_owner(self):
        self.assertEqual(self.parse(TELEPORT + '\nend', PAD).size, 9)
        for changed in (TELEPORT.replace('PUZZLE7', 'PUZZLE6'), TELEPORT.replace(', 3,', ', 4,'),
                        TELEPORT.replace(', 19', ', 18'), TELEPORT + ', 0'):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed + '\nend', PAD)
        with self.assertRaises(ValueError):
            self.parse(TELEPORT + '\nend')

    def test_disable_animation_is_a_one_byte_movement_without_arguments(self):
        result = self.parse('disable_anim\nstep_end')
        self.assertEqual((result.kind, result.size), ('movement', 2))
        for body in ('disable_anim 1\nstep_end', 'disable_anim\nreturn', 'disable_anim'):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body)

    def test_all_new_forms_stay_closed_to_legacy_reviews(self):
        for body, owner in ((VARIABLE_SPARKLE + '\nreturn', SPARKLE),
                            ('initrotatingtilepuzzle TRUE\nreturn', BUTTONS[0]),
                            (TELEPORT + '\nend', PAD), ('disable_anim\nstep_end', 'Movement')):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body, owner, version=3)

    def test_generator_consumes_only_exact_adjacent_native_zero_waits(self):
        body = ('Entry:: @ 0x0823F000\n\tmoverotatingtileobjects 0\n\twaitmovement 0\n'
                '\tturnrotatingtileobjects\n\twaitmovement 0\n\tend\n')
        expected = body.replace('\twaitmovement 0\n', '')
        for name in ('MossdeepCity_Gym', 'Route110_TrickHousePuzzle7'):
            self.assertEqual(emitter.collapse_rotating_tile_wait_macros(name, body), expected)
            for changed in (body.replace('\twaitmovement 0\n', '', 1),
                            body.replace('waitmovement 0', 'waitmovement 1', 1),
                            body.replace('waitmovement 0', 'waitmovement VAR_RESULT', 1),
                            body.replace('\twaitmovement 0', 'InteriorEntry::\n\twaitmovement 0', 1),
                            body.replace('moverotatingtileobjects 0', 'moverotatingtileobjects 5')):
                with self.subTest(name=name, changed=changed), self.assertRaises(RuntimeError):
                    emitter.collapse_rotating_tile_wait_macros(name, changed)
        self.assertEqual(emitter.collapse_rotating_tile_wait_macros('UnreviewedMap', body), body)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_each_new_form_matches_fresh_real_cpp_preproc_and_assembler(self):
        forms = [VARIABLE_SPARKLE, TELEPORT, 'initrotatingtilepuzzle TRUE', 'disable_anim']
        owners = {VARIABLE_SPARKLE: SPARKLE, TELEPORT: PAD,
                  'initrotatingtilepuzzle TRUE': BUTTONS[0]}
        native_forms.StoryProfileTests().check_native_forms(forms, version=4, source_owners=owners)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_complete_sparkle_jump_pad_and_five_button_blocks_match_native_rom(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        paths = ['data/maps/Route110_TrickHouseEntrance/scripts.inc',
                 'data/maps/Route110_TrickHousePuzzle7/scripts.inc']
        wanted = {SPARKLE, PAD, 'Route110_TrickHouse_Movement_TrickMasterJumpAway', *BUTTONS}
        count = 0
        for path in paths:
            for label, block in review.label_blocks((ROOT / path).read_text()).items():
                if label not in wanted:
                    continue
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, block, version=4, address=at)
                self.assertEqual(verifier.assemble_candidate(block, at),
                                 rom[at - 0x08000000:at - 0x08000000 + result.size], label)
                count += 1
        self.assertEqual(count, 8)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_fourth_room_keeps_native_jp_extra_boulder_and_its_distinct_position(self):
        path = 'data/maps/Route110_TrickHousePuzzle4/map.json'
        jp = json.loads((ROOT / path).read_text())['object_events']
        us = json.loads(subprocess.check_output(['git', '--no-replace-objects', '-C',
            '/home/kenny/pokeemerald', 'show',
            '731ad5bfd6e6f265508d0efcca0ba42f9dcf5881:' + path]))['object_events']
        self.assertEqual((len(jp), len(us)), (15, 14))
        self.assertEqual((jp[5]['x'], jp[5]['y']), (1, 10))
        self.assertEqual((jp[14]['x'], jp[14]['y'], jp[14]['flag']), (12, 5, 'FLAG_TEMP_1B'))
        projected = [dict(event) for event in jp[:-1]]
        projected[5].update(x=12, y=5)
        self.assertEqual(projected, us)
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        header = next(iter(symbols['Route110_TrickHousePuzzle4_MapEvents'])) - 0x08000000
        start = next(iter(symbols['Route110_TrickHousePuzzle4_ObjectEvents']))
        self.assertEqual(rom[header], 15)
        self.assertEqual(struct.unpack_from('<I', rom, header + 4)[0], start)
        gfx = review._literal_define(ROOT, 'include/constants/event_objects.h', 'OBJ_EVENT_GFX_PUSHABLE_BOULDER')
        flag = struct.unpack('<H', verifier.assemble_candidate('Entry::\n.2byte FLAG_TEMP_1B', 0x08000000))[0]
        expected = struct.pack('<BBBBhhBBBBHHIH2x', 15, gfx, 0, 0, 12, 5, 3, 1, 0, 0, 0, 0,
                               next(iter(symbols['EventScript_StrengthBoulder'])), flag)
        offset = start - 0x08000000 + 14 * 24
        self.assertEqual(rom[offset:offset + 24], expected)


if __name__ == '__main__':
    unittest.main()
