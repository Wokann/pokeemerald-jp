"""Native Tower/Apprentice selectors, causal RAM text and exact physical edges."""
from pathlib import Path
import copy
import re
import tempfile
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
LOBBY = 'BattleFrontier_BattleTowerLobby'
ROOM = 'BattleFrontier_BattleTowerBattleRoom'
CONDITIONAL = LOBBY + '_EventScript_SaveBeforeLinkMultisChallenge'


class TowerFamilyProfileTests(unittest.TestCase):
    def parse(self, body, *, owner='Owner', waits=None, version=4, root=ROOT):
        return profile.profile_block(root, owner + '::\n' + body, waits,
                                     version=version, address=0x0821EBA1)

    def test_tower_set_defaults_preserve_omitted_value_and_literal_write_sizes(self):
        for suffix, size in (('', 13), (', 0xFFFF', 13), (', 65535', 13),
                             (', 0', 18), (', FALSE', 18), (', TRUE', 18)):
            for wait in (0, 1):
                result = self.parse('tower_set TOWER_DATA_WIN_STREAK' + suffix + '\nreturn',
                                    waits={'CallBattleTowerFunc': wait})
                self.assertEqual(result.size, size + wait + 1)
                self.assertEqual(result.specials, {'CallBattleTowerFunc': wait})
        for body in ('tower_set', 'tower_set TOWER_DATA_OTHER',
                     'tower_set TOWER_DATA_LVL_MODE, 0, 1', 'tower_set TOWER_DATA_LVL_MODE, (1+1)'):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body + '\nreturn')

    def test_result_window_default_mode_and_four_explicit_modes_match_widths(self):
        for text, size in (('frontier_results FACILITY_LINK_CONTEST', 13),
                           ('frontier_results FRONTIER_FACILITY_TOWER', 13),
                           ('frontier_results FRONTIER_FACILITY_TOWER, 0xFF', 13),
                           ('frontier_results FRONTIER_FACILITY_TOWER, 255', 13)):
            self.assertEqual(self.parse(text + '\nreturn').size, size + 1)
        for mode in ('SINGLES', 'DOUBLES', 'MULTIS', 'LINK_MULTIS'):
            self.assertEqual(self.parse('frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_' + mode + '\nreturn').size, 19)
        for text in ('frontier_results', 'frontier_results OTHER',
                     'frontier_results FACILITY_LINK_CONTEST, 0xFF',
                     'frontier_results FACILITY_LINK_CONTEST, FRONTIER_MODE_SINGLES',
                     'frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_OTHER',
                     'frontier_results FRONTIER_FACILITY_TOWER, 0, 1'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_apprentice_explicit_waits_are_distinct_from_special_table_waits(self):
        for text, size in (('apprentice_menu APPRENTICE_ASK_YES_NO', 14),
                           ('apprentice_msg TRUE, APPRENTICE_MSG_WHICH_MOVE', 19),
                           ('apprentice_openbag', 9)):
            result = self.parse(text + '\nreturn', waits={'CallApprenticeFunction': 0})
            self.assertEqual(result.size, size + 1)
            self.assertEqual(result.specials, {'CallApprenticeFunction': 0})
            with self.assertRaises(ValueError):
                self.parse(text + '\nreturn', waits={'CallApprenticeFunction': 1})
        self.assertEqual(profile.special_waits(ROOT)['CallApprenticeFunction'], 0)

    def test_apprentice_operands_and_legacy_version_stay_closed(self):
        for text in ('apprentice_setlvlmode 7', 'apprentice_buff STR_VAR_4, APPRENTICE_BUFF_NAME',
                     'apprentice_buff STR_VAR_1, VAR_RESULT', 'apprentice_msg 9, APPRENTICE_MSG_WHICH_MOVE',
                     'apprentice_openbag 0', 'tower_get TOWER_DATA_OTHER', 'tower_save 0, 1'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')
        for text in ('tower_init', 'tower_set TOWER_DATA_LVL_MODE', 'apprentice_setgfx',
                     'frontier_getsymbols', 'frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_SINGLES'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn', version=3)

    def test_battle_point_message_tracks_real_standard_slot_nine(self):
        result = self.parse('msgbox SomeText, MSGBOX_GETPOINTS\nreturn')
        self.assertEqual(result.size, 9)
        self.assertEqual(result.standard_scripts, {9: 'Std_MsgboxGetPoints'})
        self.assertEqual(result.targets, {'Std_MsgboxGetPoints': 'script'})
        self.assertEqual(result.texts, {'SomeText': 'string'})

    def test_tower_message_requires_its_immediately_preceding_producer(self):
        result = self.parse('tower_getopponentintro 0\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn')
        self.assertEqual(result.runtime_texts, {'gStringVar4': 'tower_getopponentintro'})
        self.assertNotIn('gStringVar4', result.texts)
        for body in ('msgbox gStringVar4, MSGBOX_DEFAULT',
                     'tower_getopponentintro 0\ndelay 1\nmsgbox gStringVar4, MSGBOX_DEFAULT',
                     'tower_getopponentintro 1\nmsgbox gStringVar4, MSGBOX_DEFAULT'):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body + '\nreturn')

    def test_exact_movement_prefixes_reject_changed_direction_length_and_strangers(self):
        names = [name for name in profile.MOVEMENT_PREFIXES if name.startswith(('BattleFrontier_BattleTower', 'Apprentice_'))]
        self.assertEqual(len(names), 4)
        for name in names:
            target, steps = profile.MOVEMENT_PREFIXES[name]
            body = '\n'.join(steps)
            result = self.parse(body, owner=name)
            self.assertEqual((result.size, result.kind, result.fallthrough), (len(steps), 'movement', target))
            for invalid in (body + '\nwalk_up', body.replace('right', 'left'), body + ' 0'):
                with self.subTest(name=name, invalid=invalid), self.assertRaises(ValueError):
                    self.parse(invalid, owner=name)
            with self.assertRaises(ValueError):
                self.parse(body, owner='UnreviewedMovement')

    def test_only_exact_link_save_guards_follow_the_current_configuration(self):
        body = '#ifndef BUGFIX\ntower_save 0\n#endif\n#ifndef BUGFIX\nincrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER\n#endif\nreturn'
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='tower-config-', dir=parent) as folder:
            root = Path(folder)
            (root / 'include').mkdir()
            for config, expected in (('', 16), ('#define BUGFIX\n', 1)):
                (root / 'include/config.h').write_text(config)
                self.assertEqual(self.parse(body, owner=CONDITIONAL, root=root,
                                           waits={'CallBattleTowerFunc': 0}).size, expected)
            for changed in (body.replace('tower_save 0', 'tower_save 1'),
                            body.replace('#ifndef BUGFIX', '#ifdef BUGFIX', 1),
                            body + '\n#if OTHER\nend\n#endif'):
                with self.subTest(changed=changed), self.assertRaises(ValueError):
                    self.parse(changed, owner=CONDITIONAL, root=root)
        with self.assertRaises(ValueError):
            self.parse(body, owner='UnreviewedOwner')

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_actual_tower_frontier_and_apprentice_forms_expand_to_predicted_bytes(self):
        paths = [ROOT / f'data/maps/{name}/scripts.inc' for name in (LOBBY, ROOM)]
        paths.append(ROOT / 'data/scripts/apprentice.inc')
        samples = {line for path in paths for body in review.label_blocks(path.read_text()).values()
                   for line in review.statements(body) if line.startswith(('tower_', 'frontier_', 'apprentice_'))}
        self.assertGreater(len(samples), 65)
        samples |= {'tower_set TOWER_DATA_LVL_MODE, 0xFFFF', 'frontier_results FRONTIER_FACILITY_TOWER',
                    'frontier_results FRONTIER_FACILITY_TOWER, 0xFF', 'msgbox SomeText, MSGBOX_GETPOINTS',
                    'face_away_player', 'slide_down'}
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires JP native artifacts')
    def test_all_new_physical_script_and_movement_edges_are_real_rom_adjacencies(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        paths = [ROOT / f'data/maps/{name}/scripts.inc' for name in (LOBBY, ROOM, 'BattleFrontier_BattleTowerCorridor')]
        paths.append(ROOT / 'data/scripts/apprentice.inc')
        count = 0
        for path in paths:
            for label, body in review.label_blocks(path.read_text()).items():
                if label not in profile.FALLTHROUGHS and label not in profile.MOVEMENT_PREFIXES:
                    continue
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, body, version=4, address=at)
                with self.subTest(label=label):
                    self.assertEqual(symbols[result.fallthrough], {at + result.size})
                    self.assertEqual(verifier.assemble_candidate(body, at), rom[at - 0x08000000:at - 0x08000000 + result.size])
                count += 1
        self.assertGreater(count, 45)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires JP native artifacts')
    def test_configured_link_save_owner_reassembles_to_its_actual_rom_bytes(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        body = review.label_blocks((ROOT / f'data/maps/{LOBBY}/scripts.inc').read_text())[CONDITIONAL]
        at = next(iter(symbols[CONDITIONAL]))
        result = profile.profile_block(ROOT, body, version=4, address=at)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(verifier.assemble_candidate(body, at), rom[at - 0x08000000:at - 0x08000000 + result.size])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires JP native artifacts')
    def test_real_producer_dispatch_and_ram_buffer_reject_wrong_slot_or_rom_text(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        owners = []
        for line in (ROOT / 'pokeemerald_jp.map').read_text().splitlines():
            match = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
            if match:
                owners.append((int(match[1], 16), int(match[2], 16), match[3]))
        cache = dict(symbols=symbols, owners=owners, rom=(ROOT / 'baserom_jp.gba').read_bytes())
        result = self.parse('tower_getopponentintro 0\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn')
        errors = []
        review._runtime_text_native(ROOT, result, cache, errors)
        self.assertEqual(errors, [])
        wrong = copy.deepcopy(cache)
        payload = bytearray(wrong['rom'])
        slot = next(iter(symbols['sBattleTowerFuncs'])) - 0x08000000 + 7 * 4
        payload[slot:slot + 4] = b'\0' * 4
        wrong['rom'] = bytes(payload)
        errors = []
        review._runtime_text_native(ROOT, result, wrong, errors)
        self.assertIn('native_runtime_text_tower_dispatch_mismatch', errors)
        wrong = copy.deepcopy(cache)
        wrong['runtime_text_symbols']['gStringVar4'] = {0x0821EBA1}
        errors = []
        review._runtime_text_native(ROOT, result, wrong, errors)
        self.assertIn('native_runtime_text_buffer_mismatch:gStringVar4', errors)


if __name__ == '__main__':
    unittest.main()
