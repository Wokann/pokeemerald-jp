"""JP Trainer Hill dispatch, generated trainers and implicit END boundaries."""
from pathlib import Path
import copy
import re
import struct
import subprocess
import unittest
from unittest.mock import patch

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['TrainerHill_' + part for part in ('Entrance', '1F', '2F', '3F', '4F', 'Roof')]
SHARED = 'data/scripts/trainer_hill.inc'
WARP = 'TrainerHill_1F_EventScript_DummyOnWarp'
BATTLE = 'TrainerHill_EventScript_TrainerBattle'
PLACEHOLDER = 'BattleFacility_TrainerBattle_PlaceholderText'
US_REF = '731ad5bfd6e6f265508d0efcca0ba42f9dcf5881'


class TrainerHillProfileTests(unittest.TestCase):
    def parse(self, body, owner='Owner', version=4, waits=None, address=0x0823B765):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=address)

    def native(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        owners = []
        for line in (ROOT / 'pokeemerald_jp.map').read_text().splitlines():
            match = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
            if match:
                owners.append((int(match[1], 16), int(match[2], 16), match[3]))
        return dict(symbols=symbols, owners=owners, rom=(ROOT / 'baserom_jp.gba').read_bytes())

    def test_only_seventeen_actual_jp_selectors_and_actual_wait_widths(self):
        forms = [op for op in profile.FACILITY_FORMS if op.startswith('trainerhill_')]
        self.assertEqual(len(forms), 17)
        self.assertEqual(profile.special_waits(ROOT)['CallTrainerHillFunction'], 0)
        for op in forms:
            for wait in (0, 1):
                result = self.parse(op + '\nreturn', waits={'CallTrainerHillFunction': wait})
                self.assertEqual(result.size, 9 + wait)
                self.assertEqual(result.specials, {'CallTrainerHillFunction': wait})
        for body in ('trainerhill_setmode VAR_RESULT', 'trainerhill_setmode 0',
                     'trainerhill_start 0', 'trainerhill_unknown'):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body + '\nreturn')

    def test_all_new_forms_remain_closed_in_legacy_reviews(self):
        for op in profile.FACILITY_FORMS:
            if op.startswith('trainerhill_'):
                with self.subTest(op=op), self.assertRaises(ValueError):
                    self.parse(op + '\nreturn', version=3)
        with self.assertRaises(ValueError):
            self.parse('trainerbattle TRAINER_BATTLE_HILL, TRAINER_PHILLIP, LOCALID_NONE, '
                       + PLACEHOLDER + ', ' + PLACEHOLDER + '\nend', BATTLE, version=3)

    def test_exact_four_floor_callbacks_add_the_c_produced_trainer_entry(self):
        for name in MAPS[1:5]:
            block = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())[name + '_MapScripts']
            result = profile.profile_block(ROOT, block, version=4, address=0x0823BF80)
            self.assertEqual(result.runtime_scripts, {'trainer_hill_trainers'})
            self.assertEqual(result.targets[BATTLE], 'script')
            self.assertEqual(result.size, 16 if name in MAPS[1:3] else 11)
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, block.replace('TrainerHill_OnResume', 'Other'), version=4, address=0x0823BF80)

    def test_missing_end_guard_is_only_the_real_prefix_and_configuration(self):
        block = review.label_blocks((ROOT / SHARED).read_text())[WARP]
        result = profile.profile_block(ROOT, block, version=4, address=0x08276E98)
        self.assertEqual((result.size, result.fallthrough), (5, 'TrainerHill_OnFrame'))
        self.assertEqual(result.targets, {'TrainerHill_OnFrame': 'condition_table'})
        with patch.object(profile.subprocess, 'check_output', return_value='setvar VAR_TEMP_3, 1\nend\n'):
            fixed = profile.profile_block(ROOT, block, version=4, address=0x08276E98)
        self.assertEqual((fixed.size, fixed.fallthrough), (6, None))
        for changed in (block.replace('VAR_TEMP_3', 'VAR_TEMP_2'),
                        block.replace('#ifdef BUGFIX', '#ifndef BUGFIX'),
                        block.replace('setvar VAR_TEMP_3, 1', 'setvar VAR_TEMP_3, 2'),
                        block.replace(WARP, 'UnreviewedOwner')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                profile.profile_block(ROOT, changed, version=4, address=0x08276E98)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_seventeen_selectors_and_guard_match_fresh_native_expansion(self):
        forms = sorted(op for op in profile.FACILITY_FORMS if op.startswith('trainerhill_'))
        native_forms.StoryProfileTests().check_native_forms(forms, version=4)
        block = review.label_blocks((ROOT / SHARED).read_text())[WARP]
        body = '\n'.join(review.statements(block))
        native_forms.StoryProfileTests().check_native_forms([body], version=4, source_owners={body: WARP})

    def test_hill_battle_requires_real_owner_and_placeholder_header(self):
        body = ('trainerbattle TRAINER_BATTLE_HILL, TRAINER_PHILLIP, LOCALID_NONE, '
                + PLACEHOLDER + ', ' + PLACEHOLDER + '\ntrainerhill_postbattletext\nend')
        result = self.parse(body, BATTLE)
        self.assertEqual(result.size, 23)
        self.assertEqual(result.trainer_battles[0]['mode'], 'TRAINER_BATTLE_HILL')
        self.assertEqual(result.trainer_battles[0]['resume'], '0x0823B773')
        for changed in (body.replace('TRAINER_PHILLIP', 'TRAINER_OTHER'),
                        body.replace('LOCALID_NONE', 'LOCALID_PLAYER'),
                        body.replace(PLACEHOLDER, 'OtherText'),
                        body.split('\n')[0]):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed, BATTLE)
        with self.assertRaises(ValueError):
            self.parse(body, 'UnreviewedOwner')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_native_implicit_end_rejects_wrong_byte_target_and_adjacency(self):
        native = self.native()
        at = next(iter(native['symbols'][WARP]))
        result = profile.profile_block(ROOT, review.label_blocks((ROOT / SHARED).read_text())[WARP],
                                       version=4, address=at)
        errors = []
        review._script_fallthrough_native(WARP, result, at, native, errors)
        self.assertEqual(errors, [])
        forged = copy.deepcopy(native)
        data = bytearray(forged['rom'])
        data[at + result.size - 0x08000000] = 1
        forged['rom'] = bytes(data)
        errors = []
        review._script_fallthrough_native(WARP, result, at, forged, errors)
        self.assertIn('native_trainer_hill_implicit_end_mismatch', errors)
        forged = copy.deepcopy(native)
        forged['symbols']['TrainerHill_OnFrame'] = {at + result.size + 1}
        errors = []
        review._script_fallthrough_native(WARP, result, at, forged, errors)
        self.assertIn('native_script_fallthrough_mismatch:' + WARP, errors)
        result.targets['TrainerHill_OnFrame'] = 'script'
        errors = []
        review._script_fallthrough_native(WARP, result, at, native, errors)
        self.assertIn('native_trainer_hill_implicit_end_mismatch', errors)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_generated_trainer_script_requires_native_producer_and_object_owner(self):
        native = self.native()
        result = profile.profile_block(ROOT, (ROOT / 'data/maps/TrainerHill_1F/scripts.inc').read_text(),
                                       version=4, address=0x0823BF80)
        errors = []
        review._trainer_hill_script_native(result, native, errors)
        self.assertEqual(errors, [])
        for kind in ('pointer', 'owner', 'symbol'):
            forged = copy.deepcopy(native)
            address = next(iter(native['symbols']['GetTrainerHillTrainerScript'])) & ~1
            if kind == 'pointer':
                data = bytearray(forged['rom'])
                struct.pack_into('<I', data, address - 0x08000000 + 4, 0)
                forged['rom'] = bytes(data)
            elif kind == 'owner':
                forged['owners'] = [(a, n, 'src/unrelated.o' if a <= address < a + n else p)
                                    for a, n, p in native['owners']]
            else:
                forged['symbols'].pop('GetTrainerHillTrainerScript')
            errors = []
            review._trainer_hill_script_native(result, forged, errors)
            self.assertTrue(errors, kind)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_nine_normal_continuations_and_implicit_table_match_actual_adjacency(self):
        native = self.native()
        count = 0
        for path in [f'data/maps/{name}/scripts.inc' for name in MAPS] + [SHARED]:
            for label, body in review.label_blocks((ROOT / path).read_text()).items():
                if not (label.startswith('TrainerHill_') and label in profile.FALLTHROUGHS) and label != WARP:
                    continue
                at = next(iter(native['symbols'][label]))
                result = profile.profile_block(ROOT, body, version=4, address=at)
                errors = []
                review._script_fallthrough_native(label, result, at, native, errors)
                self.assertEqual(errors, [], label)
                self.assertEqual(verifier.assemble_candidate(body, at),
                                 native['rom'][at - 0x08000000:at - 0x08000000 + result.size])
                count += 1
        self.assertEqual(count, 10)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_actual_seventeen_slot_table_excludes_us_mode_setter(self):
        native = self.native()
        expected = ['TrainerHillStartChallenge', 'sub_081D4F2C', 'sub_081D4F78', 'sub_081D5024',
                    'TrainerHillResumeTimer', 'TrainerHillSetPlayerLost', 'TrainerHillGetChallengeStatus',
                    'sub_081D5164', 'sub_081D51F4', 'sub_081D5238', 'sub_081D5334',
                    'sub_081D5C50', 'sub_081D5E4C', 'sub_081D5E7C', 'sub_081D5E9C',
                    'nullsub_2', 'sub_081D5F08']
        source = (ROOT / 'src/trainer_hill.c').read_text()
        table = source.split('sHillFunctions[]', 1)[1].split('{', 1)[1].split('}', 1)[0]
        self.assertEqual(re.findall(r'^\s*(\w+),', table, re.M), expected)
        at = next(iter(native['symbols']['sHillFunctions']))
        pointers = struct.unpack_from('<17I', native['rom'], at - 0x08000000)
        for pointer, target in zip(pointers, expected):
            self.assertIn(pointer, {v | 1 for v in native['symbols'][target]}, target)
            self.assertTrue(any(a <= (pointer & ~1) < a + n
                                and (p == 'src/trainer_hill.o' or p.endswith('/src/trainer_hill.o'))
                                for a, n, p in native['owners']), target)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_hill_shared_battle_and_native_parameter_schema(self):
        native = self.native()
        body = review.label_blocks((ROOT / SHARED).read_text())[BATTLE]
        at = next(iter(native['symbols'][BATTLE]))
        result = profile.profile_block(ROOT, body, version=4, address=at)
        self.assertEqual(result.size, 26)
        self.assertEqual(verifier.assemble_candidate(body, at),
                         native['rom'][at - 0x08000000:at - 0x08000000 + result.size])
        errors = []
        review._trainer_parameter_tables(ROOT, native,
            {'sOrdinaryBattleParams', 'sTrainerBOrdinaryBattleParams', 'sTrainerBContinueScriptBattleParams'}, errors)
        self.assertEqual(errors, [])
        source = (ROOT / 'src/battle_setup.c').read_text().split('case TRAINER_BATTLE_HILL:', 1)[1].split('default:', 1)[0]
        self.assertIn('LocalIdToHillTrainerId(gSpecialVar_LastTalked)', source)
        self.assertIn('return EventScript_TryDoNormalTrainerBattle;', source)

    def test_jp_entry_keeps_its_open_challenge_and_no_us_difficulty_menu(self):
        path = 'data/maps/TrainerHill_Entrance/scripts.inc'
        jp = review.label_blocks((ROOT / path).read_text())
        us = review.label_blocks(subprocess.check_output(['git', '--no-replace-objects', '-C',
            '/home/kenny/pokeemerald', 'show', US_REF + ':' + path], text=True))
        extra = {name for name in us if name not in jp}
        self.assertEqual(len(extra), 6)
        self.assertEqual(list(jp), [name for name in us if name not in extra])
        for suffix in ('EntryTrigger', 'Man', 'Girl'):
            label = 'TrainerHill_Entrance_EventScript_' + suffix
            left, right = review.statements(jp[label]), review.statements(us[label])
            self.assertEqual(left, [line for line in right if not line.startswith('goto_if_unset FLAG_SYS_GAME_CLEAR,')])
        label = 'TrainerHill_Entrance_EventScript_ChooseChallenge'
        right = review.statements(us[label])
        self.assertIn('trainerhill_setmode VAR_RESULT', right[:5])
        self.assertEqual(review.statements(jp[label]), right[5:])


if __name__ == '__main__':
    unittest.main()
