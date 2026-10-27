"""Early cave story gates, typed braille/hole warps and real JP ownership."""
from pathlib import Path
import json
import re
import struct
import tempfile
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms

ROOT=Path(__file__).resolve().parents[1]

def blocks(name):
    return review.label_blocks((ROOT/f'data/maps/{name}/scripts.inc').read_text())

def lines(name,label):
    return review.statements(blocks(name)[name+'_'+label])

def family_names():
    source=(ROOT/'data/event_scripts.s').read_text()
    first=source.index('\t.include "data/maps/MeteorFalls_1F_1R/scripts.inc"')
    last=source.index('\t.include "data/maps/PetalburgWoods/scripts.inc"',first)
    names=re.findall(r'\.include "data/maps/(\w+)/scripts.inc"',source[first:last])
    if len(names)!=11:
        raise AssertionError('changed early cave physical family')
    return names

class CaveCommandTests(unittest.TestCase):
    def parse(self,body,version=4):
        return profile.profile_block(ROOT,'Entry::\n'+body,{},version=version,address=0x08200000)

    def test_fast_up_movement_requires_a_real_movement_terminator(self):
        part=self.parse('walk_in_place_fast_up\nwalk_in_place_fast_up\nwalk_fast_up\nwalk_fast_right\nstep_end')
        self.assertEqual((part.kind,part.size),('movement',5))
        with self.assertRaises(ValueError):
            self.parse('walk_in_place_fast_up\nend')

    def test_fixed_hole_target_is_eight_bytes_and_distinct_from_warphole(self):
        self.assertEqual(self.parse('setholewarp MAP_GRANITE_CAVE_B2F').size,8)
        self.assertEqual(self.parse('warphole MAP_UNDEFINED').size,3)
        for source in ('setholewarp','setholewarp 0','setholewarp NULL',
                       'setholewarp MAP_GRANITE_CAVE_B2F, 0, 0'):
            with self.subTest(source=source),self.assertRaises(ValueError):
                self.parse(source)

    def test_braille_message_has_a_braille_dependency_and_no_standard_msgbox(self):
        part=self.parse('braillemsgbox DesertRuins_Braille_UseRockSmash')
        self.assertEqual((part.size,part.texts),(7,{'DesertRuins_Braille_UseRockSmash':'braille'}))
        self.assertFalse(part.targets)
        self.assertFalse(part.standard_scripts)

    def test_braille_message_rejects_raw_pointers_ram_and_extra_arguments(self):
        for source in ('braillemsgbox','braillemsgbox 0x08263753','braillemsgbox NULL',
                       'braillemsgbox gStringVar4','braillemsgbox Text, MSGBOX_DEFAULT'):
            with self.subTest(source=source),self.assertRaises(ValueError):
                self.parse(source)

    def test_new_forms_do_not_change_legacy_review_versions(self):
        for version in (2,3):
            for source in ('setholewarp MAP_GRANITE_CAVE_B2F',
                           'braillemsgbox DesertRuins_Braille_UseRockSmash',
                           'walk_in_place_fast_up\nstep_end'):
                with self.subTest(version=version,source=source),self.assertRaises(ValueError):
                    self.parse(source,version)

    def test_zero_background_scripts_select_the_real_c_fallback(self):
        for zero in ('NULL','0','0x0',0):
            event={'type':'sign','script':zero}
            self.assertEqual(review.story_event_target(event,'bg_events',version=4),
                             'EventScript_TestSignpostMsg')
            for version in (2,3):
                with self.assertRaises(ValueError):
                    review.story_event_target(event,'bg_events',version=version)
        for bad in (None,False,'','0x08212345'):
            with self.subTest(bad=bad),self.assertRaises(ValueError):
                review.story_event_target({'type':'sign','script':bad},'bg_events',version=4)

    def test_shared_script_boundary_allows_only_one_final_section_padding_byte(self):
        parent=ROOT/'.tmp/agent-work/tests'
        parent.mkdir(parents=True,exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='cave-tail-',dir=parent) as folder:
            root=Path(folder)
            (root/'data/scripts').mkdir(parents=True)
            (root/'data/scripts/next.inc').write_text('Next::\nend\n')
            source='Entry::\nend\n.include "data/scripts/next.inc"\n'
            dep=dict(path='data/event_scripts.s',entry='Entry',labels=['Entry'],
                     end_before_includes=['data/scripts/next.inc'])
            path=root/'data/event_scripts.s'
            path.write_text(source+'.byte 0\n')
            self.assertEqual(review.statements(review.shared_script_blocks(root,dep)['Entry']),['end'])
            claim=dict(path=dep['path'],selector='asm_labels',labels=['Entry'])
            self.assertIn(b'.byte 0',review.source_payload(root,claim))
            for tail in ('.byte 1\n','.byte 0\n.byte 0\n','.2byte 0\n','.incbin "unknown.bin"\n'):
                path.write_text(source+tail)
                with self.subTest(tail=tail),self.assertRaises(ValueError):
                    review.shared_script_blocks(root,dep)

    def test_cave_hole_conditional_models_only_the_exact_equal_size_branches(self):
        shared=review.label_blocks((ROOT/'data/scripts/cave_hole.inc').read_text())['CaveHole_FixCrackedGround']
        part=profile.profile_block(ROOT,shared,{},version=4,address=0x08264339)
        self.assertEqual(part.size,6)
        self.assertFalse(part.targets or part.texts or part.specials)
        for changed in (shared.replace('UBFIX','BUGFIX'),shared.replace('setvar VAR_ICE_STEP_COUNT, 1','setvar VAR_ICE_STEP_COUNT, 2')):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT,changed,{},version=4,address=0x08264339)

    @unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
    def test_new_forms_match_real_preprocessor_and_assembler_sizes(self):
        native_forms.StoryProfileTests().check_native_forms([
            'walk_in_place_fast_up','setholewarp MAP_GRANITE_CAVE_B2F',
            'braillemsgbox DesertRuins_Braille_UseRockSmash'],version=4)

class CaveStoryTests(unittest.TestCase):
    def test_stevens_cave_opening_is_postgame_and_does_not_add_a_scene_battle(self):
        name='MeteorFalls_1F_1R'
        self.assertEqual(lines(name,'OnLoad')[0],
            'call_if_set FLAG_SYS_GAME_CLEAR, '+name+'_EventScript_OpenStevensCave')
        entrance=lines(name,'EventScript_OpenStevensCave')
        self.assertEqual(sum(row.startswith('setmetatile ') for row in entrance),4)
        scene=lines(name,'EventScript_MagmaStealsMeteoriteScene')
        self.assertFalse(any(row.startswith('trainerbattle') for row in scene))
        self.assertEqual(scene[-3:],['setvar VAR_METEOR_FALLS_STATE, 1','releaseall','end'])

    def test_meteor_trainers_keep_single_and_shared_double_rematch_modes(self):
        name='MeteorFalls_1F_2R'
        self.assertTrue(lines(name,'EventScript_Nicolas')[0].startswith('trainerbattle_single TRAINER_NICOLAS_1,'))
        for member in ('John','Jay'):
            self.assertTrue(lines(name,'EventScript_'+member)[0].startswith('trainerbattle_double TRAINER_JOHN_AND_JAY_1,'))
            self.assertTrue(lines(name,'EventScript_Rematch'+member)[0].startswith('trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1,'))
            self.assertTrue(any('NotEnoughMons' in row for row in lines(name,'EventScript_'+member)))

    def test_rusturf_strength_scene_dispatches_all_three_trigger_positions(self):
        name='RusturfTunnel'
        scene=lines(name,'EventScript_ClearTunnelScene')
        for number in (1,2,3):
            self.assertEqual(lines(name,'EventScript_TunnelBlockagePos'+str(number))[0],
                             'setvar VAR_TEMP_1, '+str(number))
            self.assertIn(f'call_if_eq VAR_TEMP_1, {number}, {name}_EventScript_BoyfriendApproachWanda{number}',scene)
        grant=next(i for i,row in enumerate(scene) if row.startswith('giveitem ITEM_HM_STRENGTH'))
        self.assertLess(grant,scene.index('setflag FLAG_RECEIVED_HM_STRENGTH'))
        self.assertIn('call RusturfTunnel_EventScript_SetRusturfTunnelOpen',scene)

    def test_devon_goods_rescue_restores_both_briney_and_rustboro_state(self):
        name='RusturfTunnel'
        body=lines(name,'EventScript_Grunt')
        self.assertTrue(any(row.startswith('trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL,') for row in body))
        for row in ('clearflag FLAG_DEVON_GOODS_STOLEN','setflag FLAG_RECOVERED_DEVON_GOODS',
                    'setvar VAR_RUSTBORO_CITY_STATE, 4','setvar VAR_BRINEY_HOUSE_STATE, 1',
                    'setflag FLAG_HIDE_ROUTE_116_MR_BRINEY'):
            self.assertIn(row,body)
        self.assertEqual(body[-2:],['release','end'])

    def test_regirock_escape_is_not_the_won_or_caught_cleanup_branch(self):
        name='DesertRuins'
        body=lines(name,'EventScript_Regirock')
        for result in ('B_OUTCOME_RAN','B_OUTCOME_PLAYER_TELEPORTED'):
            self.assertIn('goto_if_eq VAR_RESULT, '+result+', '+name+'_EventScript_RanFromRegirock',body)
        self.assertIn('goto_if_eq VAR_RESULT, B_OUTCOME_WON, '+name+'_EventScript_DefeatedRegirock',body)
        self.assertIn('setvar VAR_0x8004, SPECIES_REGIROCK',lines(name,'EventScript_RanFromRegirock'))
        self.assertTrue(any('B_OUTCOME_CAUGHT' in row for row in lines(name,'EventScript_TryRemoveRegirock')))

    def test_desert_three_wall_positions_share_the_actual_braille_owner(self):
        name='DesertRuins'
        for suffix in ('Middle','Side'):
            self.assertIn('braillemsgbox DesertRuins_Braille_UseRockSmash',lines(name,'EventScript_CaveEntrance'+suffix))
        events=json.loads((ROOT/f'data/maps/{name}/map.json').read_text())['bg_events']
        self.assertEqual({(row['x'],row['y']) for row in events},{(7,20),(8,20),(9,20)})
        source=(ROOT/'src/braille_puzzles.c').read_text()
        start=source.index('bool8 ShouldDoBrailleRegirockEffect(')
        body=source[start:source.index('\n}',start)+2]
        self.assertIn('MAP_DESERT_RUINS',body)
        self.assertIn('FLAG_SYS_REGIROCK_PUZZLE_COMPLETED',body)

    def test_granite_flash_reward_and_cracked_floor_callback_remain_distinct(self):
        body=lines('GraniteCave_1F','EventScript_Hiker')
        grant=next(i for i,row in enumerate(body) if row.startswith('giveitem ITEM_HM_FLASH'))
        self.assertLess(grant,body.index('setflag FLAG_RECEIVED_HM_FLASH'))
        self.assertEqual(lines('GraniteCave_B1F','SetHoleWarp'),[
            'setstepcallback STEP_CB_CRACKED_FLOOR','setholewarp MAP_GRANITE_CAVE_B2F','end'])

    def test_steven_tm_bag_failure_returns_and_still_registers_then_exits(self):
        name='GraniteCave_StevensRoom'
        body=lines(name,'EventScript_Steven')
        grant=body.index('giveitem ITEM_TM_STEEL_WING')
        failure=body.index('call_if_eq VAR_RESULT, FALSE, '+name+'_EventScript_BagFull')
        self.assertLess(body.index('setflag FLAG_DELIVERED_STEVEN_LETTER'),grant)
        self.assertLess(grant,failure)
        self.assertLess(failure,body.index('setflag FLAG_REGISTERED_STEVEN_POKENAV'))
        self.assertEqual(lines(name,'EventScript_BagFull')[-1],'return')
        self.assertTrue(any(row.startswith('removeobject ') for row in body))

@unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
class CaveNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        cls.rom=(ROOT/'baserom_jp.gba').read_bytes()

    def address(self,name):
        self.assertEqual(len(self.symbols[name]),1,name)
        return next(iter(self.symbols[name]))

    def test_all_eleven_owners_and_167_labels_keep_physical_boundaries(self):
        names=family_names()
        self.assertEqual(self.address(names[0]+'_MapScripts'),0x08212B54)
        count=0
        for name,following in zip(names,names[1:]+['PetalburgWoods']):
            at=self.address(name+'_MapScripts')
            for label,part in profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),version=4,address=at).items():
                self.assertEqual(self.address(label),at,label)
                self.assertFalse(part.may_fall_through and not part.fallthrough,label)
                at+=part.size
                count+=1
            self.assertEqual(at,self.address(following+'_MapScripts'))
        self.assertEqual((count,at),(167,0x08214278))

    def test_all_58_local_texts_preserve_3573_jp_bytes(self):
        count=total=0
        for name in family_names():
            for label,block in blocks(name).items():
                if review.text_kind(block)!='string':
                    continue
                data=review.encoded_text(ROOT,block,'string')
                at=self.address(label)-0x08000000
                self.assertEqual(data,self.rom[at:at+len(data)],label)
                self.assertTrue(data.endswith(b'\xff'))
                count+=1
                total+=len(data)
        self.assertEqual((count,total),(58,3573))

    def test_central_layout_assets_and_default_indexes_match_rom(self):
        table=self.address('gMapLayouts')-0x08000000
        for name in family_names():
            row=review.default_layout_owner(ROOT,name,allow_shared=True)
            index=review._literal_define(ROOT,'include/constants/layouts.h',row['id'])
            self.assertEqual(struct.unpack_from('<I',self.rom,table+4*(index-1))[0],self.address(row['name']))
            for field,suffix in (('border_filepath','_Border'),('blockdata_filepath','_Blockdata')):
                data=(ROOT/row[field]).read_bytes()
                at=self.address(row['name']+suffix)-0x08000000
                self.assertEqual(data,self.rom[at:at+len(data)])

    def test_japanese_braille_plaintext_reencodes_exact_39_byte_object(self):
        name='DesertRuins_Braille_UseRockSmash'
        block=review.label_blocks((ROOT/'data/text/braille.inc').read_text())[name]
        self.assertIn('.braille "ヒダリ ヒダリ',block)
        self.assertIn('brailleformat 1, 0, 27, 19, 4, 3',block)
        data=review.encoded_text(ROOT,block,'braille')
        self.assertEqual(len(data),39)
        self.assertEqual(data,self.rom[0x263753:0x26377A])

    def test_hole_warp_payload_keeps_map_only_defaults(self):
        start=self.address('GraniteCave_B1F_SetHoleWarp')-0x08000000
        data=self.rom[start:start+11]
        self.assertEqual(data[:5],b'\xa6\x07\x41\x18\x09')
        self.assertEqual(data[5:],b'\xff\x00\x00\x00\x00\x02')
        self.assertEqual(self.rom[0x264339:0x26433F],b'\x19\x22\x40\x01\x00\x02')

    def test_existing_underwater_review_is_not_duplicated(self):
        name='Underwater_SootopolisCity'
        data=json.loads((ROOT/'tools/map_semantic_reviews.json').read_text())
        owners=[row for row in data['batches'] if name in row['maps']]
        self.assertEqual(len(owners),1)
        self.assertEqual(owners[0]['id'],'underwater_remaining_route_cave_ship_family')
        self.assertEqual(self.address('DesertRuins_MapScripts')-self.address(name+'_MapScripts'),15)
