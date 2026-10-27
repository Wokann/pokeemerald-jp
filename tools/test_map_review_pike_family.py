"""Pike dispatch, two causal speech producers, shared controls and native bytes."""
from pathlib import Path
import copy
import re
import struct
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['BattleFrontier_BattlePike' + part for part in
        ('Lobby', 'Corridor', 'ThreePathRoom', 'RoomNormal', 'RoomFinal', 'RoomWildMons')]
ROOM = MAPS[3]
PREFIX = ROOM + '_EventScript_'
SHARED = 'data/scripts/battle_pike.inc'


class PikeFamilyProfileTests(unittest.TestCase):
    def parse(self, body, *, owner='Owner', waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=0x0823309D)

    def native(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        owners = []
        for line in (ROOT / 'pokeemerald_jp.map').read_text().splitlines():
            match = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
            if match:
                owners.append((int(match[1], 16), int(match[2], 16), match[3]))
        return dict(symbols=symbols, owners=owners, rom=(ROOT / 'baserom_jp.gba').read_bytes())

    def test_observed_pike_selectors_use_actual_special_wait_widths(self):
        zero = [op for op, (_, _, args) in profile.FACILITY_FORMS.items()
                if op.startswith('pike_') and not args]
        self.assertEqual(len(zero), 21)
        forms = [(op, 8) for op in zero]
        forms += [('pike_get PIKE_DATA_' + value, 13) for value in ('WIN_STREAK', 'TOTAL_STREAKS')]
        forms += [('pike_set PIKE_DATA_WIN_STREAK_ACTIVE, ' + value, 18) for value in ('TRUE', 'FALSE')]
        forms += [('pike_save ' + value, 13) for value in ('0', 'CHALLENGE_STATUS_SAVING', 'CHALLENGE_STATUS_PAUSED')]
        forms += [('pike_gettrainerintro ' + value, 13) for value in ('0', '1')]
        forms += [('pike_nohealing ' + value, 13) for value in ('TRUE', 'FALSE')]
        for text, size in forms:
            for wait in (0, 1):
                result = self.parse(text + '\nreturn', waits={'CallBattlePikeFunction': wait})
                self.assertEqual(result.size, size + wait + 1, text)
                self.assertEqual(result.specials, {'CallBattlePikeFunction': wait})
        for text in ('pike_init 0', 'pike_get PIKE_DATA_PRIZE', 'pike_gettrainerintro 2',
                     'pike_gettrainerintro VAR_RESULT', 'pike_nohealing 0', 'pike_set PIKE_DATA_WIN_STREAK',
                     'pike_save CHALLENGE_STATUS_OTHER', 'pike_inchallenge'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_results_keep_only_the_observed_pike_default_mode(self):
        self.assertEqual(self.parse('frontier_results FRONTIER_FACILITY_PIKE\nreturn').size, 14)
        for suffix in (', 0xFF', ', FRONTIER_MODE_SINGLES', ', FRONTIER_MODE_DOUBLES'):
            with self.subTest(suffix=suffix), self.assertRaises(ValueError):
                self.parse('frontier_results FRONTIER_FACILITY_PIKE' + suffix + '\nreturn')

    def test_npc_and_trainer_messages_require_their_own_real_producer_and_owner(self):
        cases = [('NormalNPC', 'pike_getnpcmsg', 'pike_getnpcmsg'),
                 ('EnterSingleBattleRoom', 'pike_gettrainerintro 0', 'pike_gettrainerintro'),
                 ('EnterHardBattleRoom', 'pike_gettrainerintro 0', 'pike_gettrainerintro'),
                 ('EnterDoubleBattleRoom', 'pike_gettrainerintro 0', 'pike_gettrainerintro'),
                 ('EnterDoubleBattleRoom', 'pike_gettrainerintro 1', 'pike_gettrainerintro')]
        for entry, op, producer in cases:
            body = op + '\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn'
            result = self.parse(body, owner=PREFIX + entry)
            self.assertEqual(result.runtime_texts, {'gStringVar4': producer})
            self.assertNotIn('gStringVar4', result.texts)
            for changed in (body.replace('\nmsgbox', '\ndelay 1\nmsgbox'),
                            body.replace('MSGBOX_DEFAULT', 'MSGBOX_SIGN')):
                with self.subTest(entry=entry, changed=changed), self.assertRaises(ValueError):
                    self.parse(changed, owner=PREFIX + entry)
            with self.assertRaises(ValueError):
                self.parse(body, owner='UnreviewedOwner')
        for entry, op in (('NormalNPC', 'pike_gettrainerintro 0'),
                          ('EnterSingleBattleRoom', 'pike_getnpcmsg'),
                          ('EnterSingleBattleRoom', 'pike_gettrainerintro 1')):
            with self.subTest(entry=entry, op=op), self.assertRaises(ValueError):
                self.parse(op + '\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn', owner=PREFIX + entry)

    def test_two_movement_prefixes_require_exact_direction_length_and_owner(self):
        prefixes = {owner: value for owner, value in profile.MOVEMENT_PREFIXES.items()
                    if owner.startswith('BattleFrontier_BattlePike')}
        self.assertEqual(len(prefixes), 2)
        for owner, (target, steps) in prefixes.items():
            result = self.parse('\n'.join(steps), owner=owner)
            self.assertEqual((result.size, result.fallthrough), (1, target))
            for changed in (steps + steps, ('walk_right',)):
                with self.subTest(owner=owner, changed=changed), self.assertRaises(ValueError):
                    self.parse('\n'.join(changed), owner=owner)
            with self.assertRaises(ValueError):
                self.parse('\n'.join(steps), owner='UnreviewedMovement')

    def test_extensions_leave_legacy_review_closed(self):
        for text in ('pike_init', 'pike_get PIKE_DATA_WIN_STREAK', 'pike_set PIKE_DATA_WIN_STREAK, 0',
                     'pike_gettrainerintro 0', 'frontier_results FRONTIER_FACILITY_PIKE'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn', version=3)

    def test_shared_retire_keeps_the_real_us_whitespace_operand_spelling(self):
        body = 'frontier_set FRONTIER_DATA_CHALLENGE_STATUS CHALLENGE_STATUS_LOST\nreturn'
        self.assertEqual(self.parse(body).size, 19)
        for changed in (body.replace('CHALLENGE_STATUS_LOST', 'CHALLENGE_STATUS_WON'),
                        body.replace(' CHALLENGE_STATUS_LOST', ' CHALLENGE_STATUS_LOST EXTRA')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_observed_pike_forms_match_actual_native_expansion(self):
        paths = [f'data/maps/{name}/scripts.inc' for name in MAPS] + [SHARED]
        samples = {line for path in paths
                   for body in review.label_blocks((ROOT / path).read_text()).values()
                   for line in review.statements(body)
                   if line.startswith(('pike_', 'frontier_results'))}
        self.assertEqual(len(samples), 36)
        samples.add('frontier_set FRONTIER_DATA_CHALLENGE_STATUS CHALLENGE_STATUS_LOST')
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_thirteen_script_and_two_movement_edges_match_native_adjacency(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        count = 0
        for path in [f'data/maps/{name}/scripts.inc' for name in MAPS] + [SHARED]:
            for label, body in review.label_blocks((ROOT / path).read_text()).items():
                if label not in profile.FALLTHROUGHS and label not in profile.MOVEMENT_PREFIXES:
                    continue
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, body, version=4, address=at)
                self.assertEqual(symbols[result.fallthrough], {at + result.size})
                self.assertEqual(verifier.assemble_candidate(body, at),
                                 rom[at - 0x08000000:at - 0x08000000 + result.size])
                count += 1
        self.assertEqual(count, 15)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_twenty_nine_dispatch_slots_match_source_rom_and_object(self):
        native = self.native()
        symbols, rom = native['symbols'], native['rom']
        at = next(iter(symbols['gUnknown_85DDE30'])) - 0x08000000
        payload = rom[at:at + 116]
        source = (ROOT / 'src/battle_pike.c').read_text().split('const u8 gUnknown_85DDE30[] = {', 1)[1].split('};', 1)[0]
        self.assertEqual(bytes(int(v, 16) for v in re.findall(r'0x([0-9a-fA-F]{2})', source)), payload)
        targets = ('SetRoomType', 'GetBattlePikeData', 'SetBattlePikeData', 'GetInFinalRoom',
                   'SetupRoomEventObjects', 'GetRoomType', 'sub_081A7180', 'sub_081A718C',
                   'sub_081A7198', 'sub_081A71E0', 'nullsub_124', 'GetRoomInflictedStatus',
                   'GetRoomInflictedStatusMon', 'HealOneOrTwoMons', 'BufferNPCMessage',
                   'StatusInflictionScreenFade', 'GetInBattlePike', 'SetHintedRoom',
                   'GetHintedRoomIndex', 'GetRoomTypeHint', 'ClearPikeTrainerIds',
                   'BufferRecordMixingTrainerMessage', 'GetCurrentRoomPikeQueenFightType',
                   'HealSomeMonsBeforePikeQueen', 'SetHealingRoomsDisabled', 'CanAnyPartyMonsBeHealed',
                   'BackupMonHeldItems', 'RestoreMonHeldItems', 'InitPikeChallenge')
        for ptr, target in zip(struct.unpack('<29I', payload), targets):
            self.assertTrue(ptr & 1)
            self.assertIn(ptr, {value | 1 for value in symbols[target]})
            self.assertTrue(any(start <= (ptr & ~1) < start + size
                                and (owner == 'src/battle_pike.o' or owner.endswith('/src/battle_pike.o'))
                                for start, size, owner in native['owners']))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_both_native_speech_chains_reject_wrong_dispatch_and_producer(self):
        native = self.native()
        for entry, op, slot, producer, size in (
                ('NormalNPC', 'pike_getnpcmsg', 14, 'BufferNPCMessage', 0x78),
                ('EnterDoubleBattleRoom', 'pike_gettrainerintro 1', 21, 'BufferRecordMixingTrainerMessage', 0x68)):
            result = self.parse(op + '\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn', owner=PREFIX + entry)
            errors = []
            review._runtime_text_native(ROOT, result, native, errors)
            self.assertEqual(errors, [], entry)
            for symbol, offset, length, expected in (
                    ('gUnknown_85DDE30', slot * 4, 4, 'native_runtime_text_pike_dispatch_mismatch'),
                    (producer, 0, size, 'native_runtime_text_greeting_call_mismatch')):
                wrong = copy.deepcopy(native)
                payload = bytearray(wrong['rom'])
                start = (next(iter(native['symbols'][symbol])) & ~1) - 0x08000000 + offset
                payload[start:start + length] = bytes(length)
                wrong['rom'] = bytes(payload)
                errors = []
                review._runtime_text_native(ROOT, result, wrong, errors)
                self.assertIn(expected, errors)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_native_npc_tables_trainer_selector_and_ram_buffer_reject_forgery(self):
        native = self.native()
        for entry, op, symbol, expected in (
                ('NormalNPC', 'pike_getnpcmsg', 'gUnknown_85DDC1C', 'native_runtime_text_pike_npc_tables_mismatch'),
                ('NormalNPC', 'pike_getnpcmsg', 'gUnknown_85DDB54', 'native_runtime_text_pike_npc_tables_mismatch'),
                ('EnterDoubleBattleRoom', 'pike_gettrainerintro 1', 'gTrainerBattleOpponent_B', 'native_runtime_text_pike_trainer_selector_mismatch'),
                ('EnterSingleBattleRoom', 'pike_gettrainerintro 0', 'gStringVar4', 'native_runtime_text_buffer_mismatch:gStringVar4')):
            result = self.parse(op + '\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn', owner=PREFIX + entry)
            errors = []
            review._runtime_text_native(ROOT, result, native, errors)
            self.assertEqual(errors, [])
            wrong = copy.deepcopy(native)
            if symbol.startswith('gUnknown_'):
                wrong['symbols'][symbol] = {next(iter(native['symbols'][symbol])) + 4}
            else:
                wrong['runtime_text_symbols'][symbol] = {0x0823309D}
            errors = []
            review._runtime_text_native(ROOT, result, wrong, errors)
            self.assertIn(expected, errors)

    def test_status_flash_keeps_explicit_wait_and_six_actual_cry_waits(self):
        self.assertEqual(profile.special_waits(ROOT)['CallBattlePikeFunction'], 0)
        blocks = review.label_blocks((ROOT / f'data/maps/{ROOM}/scripts.inc').read_text())
        cries = 0
        for entry in ('KirliaAttack', 'DusclopsAttack'):
            lines = review.statements(blocks[PREFIX + entry])
            index = lines.index('pike_flashscreen')
            self.assertEqual(lines[index + 1], 'waitstate')
            cries += lines.count('waitmoncry')
        self.assertEqual(cries, 6)
        self.assertEqual(self.parse('pike_flashscreen\nwaitstate\nreturn').size, 10)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_corridor_retire_and_resume_preserve_actual_native_source_bytes(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        cases = [(f'data/maps/{MAPS[1]}/scripts.inc', MAPS[1] + '_EventScript_EnterCorridor'),
                 (SHARED, 'BattleFrontier_BattlePike_EventScript_Retire'),
                 (SHARED, 'BattleFrontier_BattlePikeRoom_OnResume')]
        for path, label in cases:
            body = review.label_blocks((ROOT / path).read_text())[label]
            at = next(iter(symbols[label]))
            result = profile.profile_block(ROOT, body, version=4, address=at)
            self.assertEqual(verifier.assemble_candidate(body, at),
                             rom[at - 0x08000000:at - 0x08000000 + result.size])


if __name__ == '__main__':
    unittest.main()
