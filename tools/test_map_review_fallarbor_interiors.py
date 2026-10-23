"""Fallarbor Tent selectors, runtime text and the adjacent town services."""
import copy
import json
from pathlib import Path
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['FallarborTown_Mart', 'FallarborTown_BattleTentLobby', 'FallarborTown_BattleTentCorridor',
        'FallarborTown_BattleTentBattleRoom', 'FallarborTown_PokemonCenter_1F',
        'FallarborTown_PokemonCenter_2F', 'FallarborTown_CozmosHouse', 'FallarborTown_MoveRelearnersHouse']
SIZES = [(9,237,3), (48,1619,5), (10,322,4), (32,820,0), (14,515,3), (4,39,0), (19,733,9), (16,528,8)]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def scene(name, suffix):
    return review.statements(blocks(name)[name + '_' + suffix])


def parse(text, version=4, owner='Entry'):
    return profile.profile_block(ROOT, owner + '::\n' + text, version=version, address=0x081F591A)


class TentFormTests(unittest.TestCase):
    def test_optional_frontier_set_preserves_the_absent_8006_write(self):
        self.assertEqual(parse('frontier_set FRONTIER_DATA_SELECTED_MON_ORDER').size, 13)
        self.assertEqual(parse('frontier_set FRONTIER_DATA_SELECTED_MON_ORDER, 0xFFFF').size, 13)
        self.assertEqual(parse('frontier_set FRONTIER_DATA_BATTLE_NUM, 0').size, 18)
        self.assertEqual(parse('frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT').size, 18)
        self.assertEqual(parse('battletent_getopponentintro').specials, {'CallVerdanturfTentFunction':0})
        self.assertEqual(parse('fallarbortent_getopponentname').specials, {'CallFallarborTentFunction':0})

    def test_unknown_arguments_and_legacy_versions_fail_closed(self):
        for text in ('frontier_set', 'frontier_set FRONTIER_DATA_BATTLE_NUM, 0, 0',
                     'frontier_setpartyorder 0', 'frontier_get 2', 'fallarbortent_init 1',
                     'fallarbortent_save VAR_RESULT', 'arena_get 0', 'tower_setopponent 2'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                parse(text)
        with self.assertRaises(ValueError):
            parse('frontier_getstatus', version=3)

    def test_runtime_intro_requires_the_immediate_actual_producer(self):
        text = 'battletent_getopponentintro\nmsgbox gStringVar4, MSGBOX_DEFAULT\nend'
        p = parse(text)
        self.assertEqual(p.runtime_texts, {'gStringVar4':'battletent_getopponentintro'})
        self.assertEqual(p.texts, {})
        self.assertEqual(p.size, 17)
        self.assertEqual(p.standard_scripts, {4:'Std_MsgboxDefault'})
        for before in ('', 'fallarbortent_getopponentname\n', 'battletent_getopponentintro\ncall Other\n'):
            with self.subTest(before=before), self.assertRaisesRegex(ValueError, 'unproven_runtime_message'):
                parse(before + 'msgbox gStringVar4, MSGBOX_DEFAULT\nend')

    def test_runtime_buffer_has_one_ewram_address_not_a_rom_text_owner(self):
        p = parse('battletent_getopponentintro\nmsgbox gStringVar4, MSGBOX_DEFAULT\nend')
        for addresses, valid in (({0x02021D18},True), (set(),False), ({0x08210000},False),
                                 ({0x02001000,0x02002000},False), ({0x03000000},False)):
            errors = []
            review._runtime_text_native(ROOT,p,dict(runtime_text_symbols={'gStringVar4':addresses}),errors)
            self.assertEqual(not errors, valid)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_actual_facility_forms_and_wait_variants_match_macro_bytes(self):
        forms = set()
        for name in MAPS[1:4]:
            for block in blocks(name).values():
                forms.update(line for line in review.statements(block)
                             if line.split()[0] in profile.FACILITY_FORMS or line.startswith('frontier_set '))
        shared = blocks('BattleFrontier_BattleArenaBattleRoom')['BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle']
        forms.update(line for line in review.statements(shared)
                     if line.split()[0] in profile.FACILITY_FORMS or line.startswith('frontier_set '))
        forms |= {'frontier_set FRONTIER_DATA_BATTLE_NUM, 0',
                  'frontier_set FRONTIER_DATA_SELECTED_MON_ORDER, 0xFFFF',
                  'frontier_set FRONTIER_DATA_SELECTED_MON_ORDER, 0xFfFf',
                  'frontier_set FRONTIER_DATA_SELECTED_MON_ORDER, 65535',
                  'msgbox gStringVar4, MSGBOX_DEFAULT', 'jump_in_place_down'}
        native_forms.StoryProfileTests().check_native_forms(sorted(forms),version=4)
        waits = {handler:1 for handler,_,_ in profile.FACILITY_FORMS.values()}
        native_forms.StoryProfileTests().check_native_forms(sorted(forms - {'msgbox gStringVar4, MSGBOX_DEFAULT'}),
                                                         forced_waits=waits,version=4)

    def test_only_the_known_corridor_movement_can_share_a_tail(self):
        owner = MAPS[2] + '_Movement_PlayerEnterDoor'
        p = parse('walk_up',owner=owner)
        self.assertEqual((p.size,p.kind,p.fallthrough), (1,'movement',MAPS[2]+'_Movement_AttendantEnterDoor'))
        for text, name in (('walk_up','Other'), ('walk_down',owner), ('walk_up\nwalk_up',owner)):
            with self.subTest(text=text,name=name), self.assertRaises(ValueError):
                parse(text,owner=name)


class FallarborStoryTests(unittest.TestCase):
    def test_prize_failure_keeps_the_pending_prize(self):
        lines = scene(MAPS[1], 'EventScript_GivePrize')
        prize = lines.index('fallarbortent_giveprize')
        self.assertEqual(lines[prize+1:prize+3], ['switch VAR_RESULT',
            'case FALSE, FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize'])
        self.assertIn('frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0',lines)
        failed = scene(MAPS[1], 'EventScript_NoRoomForPrize')
        self.assertFalse(any('FRONTIER_DATA_CHALLENGE_STATUS' in line or 'giveprize' in line for line in failed))
        self.assertIn('setvar VAR_TEMP_CHALLENGE_STATUS, 255', failed)

    def test_cozmo_does_not_take_the_meteorite_until_tm_delivery_succeeds(self):
        lines = scene(MAPS[6], 'EventScript_PlayerHasMeteorite')
        give = lines.index('giveitem ITEM_TM_RETURN')
        self.assertTrue(lines[give+1].startswith('goto_if_eq VAR_RESULT, FALSE,'))
        handed = lines.index('call Common_EventScript_PlayerHandedOverTheItem')
        self.assertGreater(handed,give+1)
        self.assertGreater(lines.index('setflag FLAG_RECEIVED_TM_RETURN'),handed)

    def test_relearner_charges_only_after_move_selection_succeeds(self):
        lines = scene(MAPS[7], 'EventScript_ChooseMove')
        teach = lines.index('special TeachMoveRelearnerMove')
        self.assertTrue(lines[teach+1].startswith('goto_if_eq VAR_0x8004, 0,'))
        self.assertGreater(lines.index('removeitem ITEM_HEART_SCALE'),teach+1)
        choose = scene(MAPS[7], 'EventScript_ChooseMon')
        self.assertIn('special IsSelectedMonEgg',choose)
        self.assertTrue(any('PARTY_NOTHING_CHOSEN' in line for line in choose))


class FallarborNativeTests(unittest.TestCase):
    def family(self):
        rows = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        selected = [row for row in rows if row['id']=='FallarborInteriors_story_review_20261023']
        self.assertEqual(len(selected),1)
        self.assertEqual(selected[0]['maps'],MAPS)
        return selected[0]

    def test_family_is_explicit_and_runtime_text_is_not_miscounted_as_rom(self):
        batch = self.family()
        self.assertNotIn('gStringVar4',{d['entry'] for d in batch['text_dependencies']})
        self.assertNotIn('gStringVar4',{s['symbol'] for s in batch['native_spans']})
        for path in ('src/battle_tent.c','src/battle_tower.c','include/battle_tower.h',
                     'src/frontier_util.c','src/string_util.c'):
            changed = copy.deepcopy(batch)
            changed['sources'] = [s for s in changed['sources'] if s['path']!=path]
            with self.assertRaisesRegex(ValueError,'missing_runtime_text_interface_context'):
                review.component_contracts(ROOT,changed,MAPS)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_exact_owner_extents_movement_prefix_and_retained_waitstate(self):
        symbols,_ = review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        def address(label):
            self.assertEqual(len(symbols[label]),1)
            return next(iter(symbols[label]))
        for name,(labels,size,texts) in zip(MAPS,SIZES):
            p = profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),
                                      version=4,address=address(name+'_MapScripts'))
            self.assertEqual((len(p),sum(b.size for b in p.values()),sum(b.kind=='string' for b in p.values())),
                             (labels,size,texts))
            for label,part in p.items():
                if part.fallthrough:
                    self.assertEqual(address(label)+part.size,address(part.fallthrough),label)
        retained = address(MAPS[3]+'_EventScript_UnreachableWaitstate')
        rom = (ROOT/'baserom_jp.gba').read_bytes()
        self.assertEqual(rom[retained-0x08000000],0x27)
        self.assertEqual(address(MAPS[3]+'_EventScript_WarpToLobbyWon'),retained+1)


if __name__ == '__main__':
    unittest.main()
