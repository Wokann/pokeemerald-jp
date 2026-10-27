"""Slateport rental, museum, fan-club and harbor static contracts."""
import json
from pathlib import Path
import re
import struct
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_tests
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_tests

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['SlateportCity_SternsShipyard_1F', 'SlateportCity_SternsShipyard_2F',
        'SlateportCity_BattleTentLobby', 'SlateportCity_BattleTentCorridor', 'SlateportCity_BattleTentBattleRoom',
        'SlateportCity_NameRatersHouse', 'SlateportCity_PokemonFanClub', 'SlateportCity_OceanicMuseum_1F',
        'SlateportCity_OceanicMuseum_2F', 'SlateportCity_Harbor', 'SlateportCity_House',
        'SlateportCity_PokemonCenter_1F', 'SlateportCity_PokemonCenter_2F', 'SlateportCity_Mart']
SIZES = [(18,1146,9),(5,145,2),(45,1377,5),(36,1733,15),(14,324,0),(18,650,9),(58,2583,22),
         (64,2251,26),(58,2405,26),(76,2820,26),(5,151,2),(7,201,2),(4,39,0),(7,187,2)]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def scene(name, suffix):
    return review.statements(blocks(name)[name + '_' + suffix])


class SlateportProfileTests(unittest.TestCase):
    def test_optional_itemspace_preserves_the_legacy_two_operand_form(self):
        for line in ('checkitemspace ITEM_RED_SCARF', 'checkitemspace ITEMID, AMOUNT'):
            p = profile.profile_block(ROOT, 'Entry::\n' + line + '\nend', version=4, address=0x08000000)
            self.assertEqual(p.size, 6)
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT, 'Entry::\ncheckitemspace ITEM_RED_SCARF\nend', version=3)

    def test_money_arguments_are_immediate_and_bounded(self):
        for line in ('checkmoney VAR_RESULT', 'removemoney 4294967296', 'checkmoney 50, 2',
                     'showmoneybox 256, 0', 'showmoneybox 0, 0, 2', 'hidemoneybox 0', 'updatemoneybox 2'):
            with self.subTest(line=line), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Entry::\n' + line + '\nend', version=4, address=0x08000000)

    def test_buffer_producer_allows_only_the_audited_lockall_interposition(self):
        source = 'Entry::\nbattletent_getopponentintro\nlockall\nmsgbox gStringVar4, MSGBOX_DEFAULT\nend'
        p = profile.profile_block(ROOT, source, version=4, address=0x08000000)
        self.assertEqual(p.runtime_texts, {'gStringVar4': 'battletent_getopponentintro'})
        self.assertNotIn('gStringVar4', p.texts)
        for replacement in ('waitstate', 'special HealPlayerParty', 'lockall\nlockall'):
            with self.subTest(replacement=replacement), self.assertRaises(ValueError):
                profile.profile_block(ROOT, source.replace('\nlockall\n', '\n' + replacement + '\n'),
                                      version=4, address=0x08000000)

    def test_context_replacement_cannot_approve_an_arbitrary_warp_tail(self):
        label = MAPS[4] + '_EventScript_WarpToLobbyWon'
        tail = 'warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 6, 6\nwaitstate'
        p = profile.profile_block(ROOT, label + '::\n' + tail, version=4, address=0x08000000)
        self.assertFalse(p.may_fall_through)
        self.assertEqual(p.context_warp, 'MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY')
        other = profile.profile_block(ROOT, 'Unreviewed::\n' + tail, version=4, address=0x08000000)
        self.assertTrue(other.may_fall_through)
        with self.assertRaisesRegex(ValueError, 'changed_context_replacing_warp'):
            profile.profile_block(ROOT, label + '::\n' + tail.replace(', 6, 6', ', 6, 7'),
                                  version=4, address=0x08000000)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_new_forms_match_real_native_macros_and_handler_waits(self):
        samples = ['checkitemspace ITEM_RED_SCARF', 'checkitemspace ITEMID, AMOUNT',
            'checkmoney 50', 'checkmoney 50, 1', 'removemoney 50', 'showmoneybox 0, 0',
            'showmoneybox 1, 2, 1', 'hidemoneybox', 'updatemoneybox', 'updatemoneybox 1',
            'jump_up', 'walk_slow_right', 'slateporttent_save CHALLENGE_STATUS_PAUSED', 'factory_setparties 0']
        samples += [name for name in profile.FACILITY_FORMS
                    if (name.startswith('slateporttent_') or name.startswith('factory_'))
                    and not profile.FACILITY_FORMS[name][2]]
        native_tests.StoryProfileTests().check_native_forms(samples, version=4)
        native_tests.StoryProfileTests().check_native_forms(['slateporttent_rentmons', 'factory_setopponentgfx'],
            {'CallSlateportTentFunction': 1, 'CallBattleFactoryFunction': 1}, version=4)


class SlateportStoryTests(unittest.TestCase):
    def test_reporter_text_uses_overworld_buffers_without_rewriting_broadcasts(self):
        source = review.label_blocks((ROOT / 'data/text/tv/pokemon_fan_club.inc').read_text())
        for suffix in ('InterviewRequestHasName', 'DescribeFeelingsFirstMetMon', 'LikenMonToSomethingYouLike',
                       'WhatAttractedYouAboutMon', 'InterviewRequest', 'TellMeAnythingAboutYourMon', 'ThatsAllForInterview2'):
            block = source['SlateportCity_PokemonFanClub_Text_' + suffix]
            self.assertIn('{STR_VAR_1}', block)
            self.assertNotIn('B_COPY_VAR_', block)
        self.assertIn('{STR_VAR_2}', source['SlateportCity_PokemonFanClub_Text_InterviewRequestHasName'])
        for index in (1, 2):
            before = 'Alias:\n.string "{B_COPY_VAR_%d}$"' % index
            after = 'Buffer:\n.string "{STR_VAR_%d}$"' % index
            self.assertEqual(review.encoded_text(ROOT, before, 'string'), review.encoded_text(ROOT, after, 'string'))

    def test_scarf_checks_are_ordered_overwrites_not_a_highest_stat_search(self):
        lines = scene(MAPS[6], 'EventScript_ChairmanAssessLeadMon')
        checks = [line for line in lines if line.startswith('call_if_unset FLAG_RECEIVED_')]
        self.assertEqual([line.split('_SCARF,')[0].split('FLAG_RECEIVED_')[1] for line in checks],
                         ['YELLOW', 'GREEN', 'PINK', 'BLUE', 'RED'])
        for color in ('Red', 'Blue', 'Pink', 'Green', 'Yellow'):
            lines = scene(MAPS[6], 'EventScript_Give' + color + 'Scarf')
            self.assertEqual(lines[0], 'checkitemspace ITEM_' + color.upper() + '_SCARF')
            self.assertIn('VAR_RESULT, FALSE,', lines[1])
            self.assertLess(lines.index('setflag FLAG_RECEIVED_' + color.upper() + '_SCARF'),
                            lines.index('giveitem ITEM_' + color.upper() + '_SCARF'))

    def test_rental_and_swap_waits_are_explicit_not_dispatcher_wide(self):
        for suffix, command in (('EnterCorridor', 'slateporttent_rentmons'), ('SwapMons', 'slateporttent_swapmons')):
            lines = scene(MAPS[3], 'EventScript_' + suffix)
            self.assertEqual(lines[lines.index(command) + 1], 'waitstate')
        waits = profile.special_waits(ROOT)
        self.assertEqual((waits['CallSlateportTentFunction'], waits['CallBattleFactoryFunction']), (0, 0))
        lines = scene(MAPS[3], 'EventScript_SwapMons')
        self.assertIn('goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom', lines)

    def test_name_rater_checks_the_slot_and_restores_the_nickname_buffer(self):
        choose = scene(MAPS[5], 'EventScript_ChooseMonToRate')
        self.assertIn('VAR_0x8004, PARTY_NOTHING_CHOSEN,', '\n'.join(choose))
        lines = scene(MAPS[5], 'EventScript_RateMonNickname')
        self.assertEqual(lines[:2], ['specialvar VAR_RESULT, ScriptGetPartyMonSpecies',
            'goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg'])
        self.assertIn('special IsMonOTIDNotPlayers', lines)
        at = lines.index('specialvar VAR_RESULT, MonOTNameNotPlayer')
        self.assertEqual(lines[at + 1], 'special BufferMonNickname')

    def test_museum_fee_is_a_script_gate_with_the_devon_exception(self):
        lines = scene(MAPS[7], 'EventScript_CheckMoneyForFee')
        self.assertEqual(lines[0], 'checkmoney 50')
        self.assertIn('VAR_RESULT, FALSE,', lines[1])
        self.assertLess(lines.index('removemoney 50'), lines.index('setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1'))
        reject = scene(MAPS[7], 'EventScript_NotEnoughMoney')
        self.assertEqual(reject[0], 'goto_if_unset FLAG_DELIVERED_DEVON_GOODS, '
                         'SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway')
        allowed = scene(MAPS[7], 'EventScript_AllowEntranceAnyway')
        self.assertFalse(any(line.startswith('removemoney') for line in allowed))

    def test_scanner_is_removed_only_after_the_reward_is_added(self):
        for suffix, item in (('DeepSeaTooth', 'TOOTH'), ('DeepSeaScale', 'SCALE')):
            lines = scene(MAPS[9], 'EventScript_' + suffix)
            at = lines.index('giveitem ITEM_DEEP_SEA_' + item)
            self.assertEqual(lines[at + 1], 'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull')
            self.assertGreater(lines.index('removeitem ITEM_SCANNER'), at + 1)
            self.assertGreater(lines.index('setflag FLAG_EXCHANGED_SCANNER'), at + 1)

    def test_ferry_does_not_invent_an_item_check_from_the_ticket_dialogue(self):
        lines = scene(MAPS[9], 'EventScript_FerryAttendant')
        self.assertIn('goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket', lines)
        ask = scene(MAPS[9], 'EventScript_AskForTicket')
        self.assertFalse(any(line.startswith('checkitem ') for line in ask))
        self.assertIn('goto SlateportCity_Harbor_EventScript_ChooseDestination', ask)


@unittest.skipUnless(all((ROOT / name).is_file() for name in
    ('pokeemerald_jp.elf', 'pokeemerald_jp.map', 'baserom_jp.gba')), 'requires native artifacts')
class SlateportNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        symbols, memory = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        owners = []
        for line in (ROOT / 'pokeemerald_jp.map').read_text().splitlines():
            match = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
            if match:
                owners.append((int(match[1], 16), int(match[2], 16), match[3].replace('\\', '/')))
        cls.native = dict(symbols=symbols, memory=memory, owners=owners, rom=(ROOT / 'baserom_jp.gba').read_bytes())

    def test_all_owners_and_explicit_edge_kinds_match_native_addresses(self):
        symbols = self.native['symbols']
        falls, exits, battles = [], [], []
        for name, (labels, size, texts) in zip(MAPS, SIZES):
            self.assertEqual(len(symbols[name + '_MapScripts']), 1)
            at = next(iter(symbols[name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, (ROOT / f'data/maps/{name}/scripts.inc').read_text(), version=4, address=at)
            self.assertEqual((len(parts), sum(p.size for p in parts.values()),
                              sum(p.kind == 'string' for p in parts.values())), (labels, size, texts))
            for label, p in parts.items():
                if p.fallthrough:
                    self.assertEqual(symbols[p.fallthrough], {at + p.size})
                    falls.append(label)
                self.assertFalse(p.may_fall_through and not p.fallthrough, label)
                if p.context_warp:
                    exits.append(label)
                battles.extend(p.trainer_battles)
                at += p.size
        self.assertEqual((len(falls), len(exits), len(battles)), (15, 3, 2))
        self.assertEqual(set(exits), {label for label in profile.CONTEXT_WARP_EXITS
                                      if label.startswith('SlateportCity_')})

    def test_real_context_exit_chain_and_negative_native_fixtures(self):
        batch = dict(context_exits=[dict(entry=label, destination=target[0])
                                   for label, target in profile.CONTEXT_WARP_EXITS.items()])
        errors = []
        review._context_warp_native(batch, self.native, errors)
        self.assertEqual(errors, [])
        renamed = dict(self.native, symbols=dict(self.native['symbols']))
        renamed['symbols'].pop('ScriptContext1_Init', None)
        errors = []
        review._context_warp_native(batch, renamed, errors)
        self.assertEqual(errors, [])
        bad = dict(self.native, symbols=dict(self.native['symbols']))
        bad['symbols']['ScriptContext1_Init'] = {0x08000000}
        errors = []
        review._context_warp_native(batch, bad, errors)
        self.assertIn('native_context_warp_init_alias_mismatch', errors)
        base = next(iter(self.native['symbols']['CB2_LoadMap'])) & ~1
        rom = bytearray(self.native['rom'])
        rom[base - 0x08000000:base - 0x08000000 + 16] = bytes(16)
        errors = []
        review._context_warp_native(batch, dict(self.native, rom=bytes(rom)), errors)
        self.assertIn('native_context_warp_missing_init_call', errors)
        errors = []
        review._context_warp_native(batch, dict(self.native, owners=[]), errors)
        self.assertIn('native_context_warp_owner_mismatch:CB2_LoadMap', errors)

    def test_four_used_factory_dispatch_slots_are_real_thumb_function_pointers(self):
        symbols, rom = self.native['symbols'], self.native['rom']
        table = next(iter(symbols['gUnknown_85DD958']))
        for selector, name in (('SET_OPPONENT_MONS', 'SetRentalsToOpponentParty'),
                               ('SET_PARTIES', 'SetPlayerAndOpponentParties'),
                               ('SET_OPPONENT_GFX', 'SetOpponentGfxVar'),
                               ('RESET_HELD_ITEMS', 'RestorePlayerPartyHeldItems')):
            slot = review._literal_define(ROOT, 'include/constants/battle_factory.h', 'BATTLE_FACTORY_FUNC_' + selector)
            self.assertEqual(len(symbols[name]), 1)
            expected = (next(iter(symbols[name])) & ~1) | 1
            self.assertEqual(struct.unpack_from('<I', rom, table - 0x08000000 + 4 * slot)[0], expected)
            self.assertTrue(any(base <= table + 4 * slot and table + 4 * slot + 4 <= base + len(data)
                and struct.unpack_from('<I', data, table + 4 * slot - base)[0] == expected
                for base, data in self.native['memory']))


if __name__ == '__main__':
    unittest.main()
