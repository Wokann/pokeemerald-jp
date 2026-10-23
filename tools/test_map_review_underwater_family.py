"""Upgrade the existing sequential underwater owners without double counting."""
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
NUMBERS = (124,126,127,128,129,105,125)
MAPS = [f'Underwater_Route{n}' for n in NUMBERS]
RESUME = {127,129,105,125}
DESTINATIONS = [('105_NORTH','105North',105,11,29), ('105_SOUTH','105South',105,21,54),
                ('125_WEST','125West',125,9,17), ('125_EAST','125East',125,54,19),
                ('127_NORTH','127North',127,58,10), ('127_SOUTH','127South',127,62,31),
                ('129_WEST','129West',129,17,15), ('129_EAST','129East',129,43,20)]
PREFIX = 'AbnormalWeather_Underwater_SetupEscapeWarp'


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


class UnderwaterFamilyTests(unittest.TestCase):
    def family(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        found = [batch for batch in batches if set(batch['maps']) & set(MAPS)]
        self.assertEqual(len(found), 1)
        self.assertEqual(found[0]['maps'], MAPS)
        self.assertEqual(found[0]['review_type'], 'direct_map_v4')
        return found[0]

    def test_escape_coordinate_form_matches_eight_real_macro_expansions(self):
        forms = [f'setescapewarp MAP_ROUTE{route}, {x}, {y}' for _,_,route,x,y in DESTINATIONS]
        for statement in forms:
            p = profile.profile_block(ROOT, 'Entry:\n' + statement + '\nreturn', {},
                                      version=4, address=0x08240000)
            self.assertEqual((p.kind,p.size,p.targets), ('script',9,{}))
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Entry:\n' + statement + '\nreturn', {})
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms(forms, version=4)

    def test_unmeasured_escape_warp_overloads_fail_closed(self):
        for statement in ('setescapewarp MAP_ROUTE105, 0', 'setescapewarp MAP_ROUTE105, 0, 11, 29',
                          'setescapewarp Route105, 11, 29', 'setescapewarp MAP_ROUTE105, 11+1, 29'):
            with self.subTest(statement=statement), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Entry:\n' + statement + '\nreturn', {},
                                      version=4, address=0x08240000)

    def test_empty_and_resume_tables_keep_their_actual_complete_shapes(self):
        for number,name in zip(NUMBERS,MAPS):
            source = blocks(name)
            table = review.statements(source[name + '_MapScripts'])
            if number in RESUME:
                self.assertEqual(table, [f'map_script MAP_SCRIPT_ON_RESUME, {name}_OnResume','.byte 0'])
                self.assertEqual(review.statements(source[name + '_OnResume']), ['call ' + PREFIX,'end'])
                self.assertEqual(len(source), 2)
            else:
                self.assertEqual(table, ['.byte 0'])
                self.assertEqual(len(source), 1)

    def test_shared_switch_has_all_eight_cases_and_an_unchanged_default_return(self):
        source = review.label_blocks((ROOT / 'data/scripts/abnormal_weather.inc').read_text())
        self.assertEqual(review.statements(source[PREFIX]), ['switch VAR_ABNORMAL_WEATHER_LOCATION'] +
            [f'case ABNORMAL_WEATHER_ROUTE_{location}, {PREFIX}Route{suffix}'
             for location,suffix,_,_,_ in DESTINATIONS] + ['return'])
        for _,suffix,route,x,y in DESTINATIONS:
            self.assertEqual(review.statements(source[PREFIX + 'Route' + suffix]),
                             [f'setescapewarp MAP_ROUTE{route}, {x}, {y}','return'])

    def test_event_payloads_are_hidden_items_not_missing_script_pointers(self):
        expected = [(0,7),(1,8),(2,4),(1,2),(2,0),(2,0),(2,0)]
        for name,(warps,hidden) in zip(MAPS,expected):
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            self.assertEqual([len(metadata[field]) for field in
                ('object_events','warp_events','coord_events','bg_events')], [0,warps,0,hidden])
            for event in metadata['bg_events']:
                self.assertEqual(event['type'], 'hidden_item')
                self.assertNotIn('script',event)
                self.assertEqual(review.story_event_target(event,'bg_events',version=4), 'EventScript_HiddenItemScript')
                forged = dict(event,script='EventScript_HiddenItemScript')
                with self.assertRaises(ValueError):
                    review.story_event_target(forged,'bg_events',version=4)

    def test_underwater_header_flags_are_preserved_not_guessed_from_map_type(self):
        for name in MAPS:
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            self.assertEqual((metadata['music'],metadata['weather'],metadata['map_type']),
                             ('MUS_UNDERWATER','WEATHER_UNDERWATER_BUBBLES','MAP_TYPE_UNDERWATER'))
            self.assertTrue(metadata['allow_cycling'] and metadata['allow_running'] and metadata['show_map_name'])
            self.assertFalse(metadata['allow_escaping'] or metadata['requires_flash'])

    def test_emerge_connections_remain_separate_from_escape_warp_destinations(self):
        total = 0
        for number,name in zip(NUMBERS,MAPS):
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            emerge = [item for item in metadata['connections'] if item['direction']=='emerge']
            self.assertEqual(emerge,[dict(map=f'MAP_ROUTE{number}',offset=0,direction='emerge')])
            total += len(metadata['connections'])
        self.assertEqual(total,13)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(),'requires native JP artifacts')
    def test_all_51_bytes_and_11_local_labels_keep_native_boundaries(self):
        symbols,_ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        total = labels_count = 0
        for index,(number,name) in enumerate(zip(NUMBERS,MAPS)):
            source = blocks(name)
            start = next(iter(symbols[name + '_MapScripts']))
            parts = profile.profile_owner(ROOT,''.join(source.values()),version=4,address=start)
            size = 12 if number in RESUME else 1
            self.assertEqual(sum(item.size for item in parts.values()),size)
            self.assertFalse(any(item.kind=='string' for item in parts.values()))
            names = list(parts)
            for i,label in enumerate(names):
                following = names[i+1] if i+1<len(names) else (
                    MAPS[index+1] + '_MapScripts' if index+1<len(MAPS) else 'LittlerootTown_BrendansHouse_1F_MapScripts')
                self.assertEqual(parts[label].size,next(iter(symbols[following]))-next(iter(symbols[label])))
            total += size
            labels_count += len(parts)
        self.assertEqual((total,labels_count),(51,11))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(),'requires native JP artifacts')
    def test_eight_escape_warp_native_commands_encode_surface_coords_and_return(self):
        symbols,_ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        map_numbers = {105:20,125:40,127:42,129:44}
        for _,suffix,route,x,y in DESTINATIONS:
            address = next(iter(symbols[PREFIX + 'Route' + suffix]))-0x08000000
            self.assertEqual(rom[address:address+9], bytes((0xC4,0,map_numbers[route],0xFF)) +
                             x.to_bytes(2,'little')+y.to_bytes(2,'little')+b'\x03')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(),'requires native JP artifacts')
    def test_new_v4_family_has_complete_current_closure_without_trainers(self):
        batch = self.family()
        self.assertEqual(batch['trainer_battles'],[])
        self.assertEqual(batch['dynamic_layouts'],[])
        self.assertEqual(review._review_batch(ROOT,batch,set(MAPS),{})['status'],'current')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(),'requires native JP artifacts')
    def test_legacy_v2_residual_maps_keep_their_own_valid_evidence(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        residual = next(row for row in batches if row['id']=='underwater_remaining_route_cave_ship_family')
        self.assertEqual(residual['review_type'],'direct_map_v2')
        self.assertEqual(set(residual['maps']),{'Underwater_Route134','Underwater_MarineCave',
            'Underwater_SeafloorCavern','Underwater_SealedChamber','Underwater_SootopolisCity',
            'AbandonedShip_Underwater1','AbandonedShip_Underwater2'})
        self.assertEqual(review._review_batch(ROOT,residual,set(residual['maps']),{})['status'],'current')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(),'requires native JP artifacts')
    def test_version_upgrade_never_duplicates_or_adds_reviewed_maps(self):
        manifest = json.loads((ROOT / review.MANIFEST_PATH).read_text())
        names = [name for batch in manifest['batches'] for name in batch['maps']]
        self.assertEqual(len(names),len(set(names)))
        self.assertEqual([name for name in names if name in MAPS],MAPS)
        known = {path.parent.name for path in (ROOT / 'data/maps').glob('*/map.json')}
        result = review.map_review_progress(ROOT,known)
        self.assertEqual(result['reviewed_maps'],len(names))
        self.assertEqual(sum(result['current_maps_by_review_type'].values()),len(names))
        self.assertNotIn('direct_map_v1',result['current_maps_by_review_type'])
        self.assertEqual(result['current_maps_by_review_type']['direct_map_v2'],7)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(),'requires native tools')
    def test_all_71_distinct_forms_match_native_macro_expansion(self):
        batch = self.family()
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in batch['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT,dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms),71)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms),version=4)


if __name__=='__main__':
    unittest.main()
