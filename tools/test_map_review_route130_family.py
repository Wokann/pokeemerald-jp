"""Route130-134 bind alternate layouts and a fixed-dive interface explicitly."""
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
OWNERS = [('Route130', 7, 165), ('Route131', 12, 229), ('Route132', 9, 185),
          ('Route133', 8, 162), ('Route134', 11, 222)]
MAPS = [row[0] for row in OWNERS]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def lines(name, entry):
    return review.statements(blocks(name)[name + '_' + entry])


class Route130FamilyTests(unittest.TestCase):
    def family(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        found = [batch for batch in batches if set(batch['maps']) & set(MAPS)]
        self.assertEqual(len(found), 1, 'one explicitly reviewed adjacent family')
        self.assertEqual(found[0]['maps'], MAPS)
        return found[0]

    def test_mirage_present_branch_precedes_all_absent_object_flags(self):
        sequence = lines('Route130', 'OnTransition')
        self.assertEqual(sequence[:3], [
            'call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route130_EventScript_CheckSetAbnormalWeather',
            'specialvar VAR_RESULT, IsMirageIslandPresent',
            'goto_if_eq VAR_RESULT, TRUE, Route130_EventScript_SetMirageIslandLayout'])
        flags = ['FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE'] + [f'FLAG_TEMP_{i:02X}' for i in range(0x12, 0x20)]
        self.assertEqual(sequence[3:-2], ['setflag ' + flag for flag in flags])
        self.assertEqual(sequence[-2:], ['setmaplayoutindex LAYOUT_ROUTE130', 'end'])
        self.assertEqual(lines('Route130', 'EventScript_SetMirageIslandLayout'),
                         ['setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND', 'end'])

    def test_both_weather_helpers_return_and_keep_the_same_story_gate(self):
        for name in ('Route130', 'Route131'):
            self.assertEqual(lines(name, 'OnTransition')[0],
                f'call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, {name}_EventScript_CheckSetAbnormalWeather')
            self.assertEqual(lines(name, 'EventScript_CheckSetAbnormalWeather'),
                ['call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather', 'return'])

    def test_sky_pillar_layout_is_selected_unconditionally_after_weather_check(self):
        sequence = lines('Route131', 'OnTransition')
        self.assertEqual(sequence[1:], ['call Route131_EventScript_SetLayout', 'end'])
        self.assertEqual(lines('Route131', 'EventScript_SetLayout'),
                         ['setmaplayoutindex LAYOUT_ROUTE131_SKY_PILLAR', 'return'])
        metadata = json.loads((ROOT / 'data/maps/Route131/map.json').read_text())
        self.assertEqual(metadata['warp_events'], [dict(x=36, y=6, elevation=3,
                         dest_map='MAP_SKY_PILLAR_ENTRANCE', dest_warp_id='0')])

    def test_empty_current_route_hooks_do_not_hide_the_real_trainer_scripts(self):
        for name, trainer_count in (('Route132', 8), ('Route133', 7)):
            self.assertEqual(lines(name, 'MapScripts'), ['.byte 0'])
            self.assertEqual(sum('trainerbattle_single ' in block for block in blocks(name).values()), trainer_count)
            self.assertFalse(any(label.endswith(('_OnLoad', '_OnTransition', '_OnResume')) for label in blocks(name)))

    def test_route134_on_resume_sets_a_destination_without_an_immediate_warp(self):
        self.assertEqual(lines('Route134', 'MapScripts'),
                         ['map_script MAP_SCRIPT_ON_RESUME, Route134_OnResume', '.byte 0'])
        self.assertEqual(lines('Route134', 'OnResume'),
                         ['setdivewarp MAP_UNDERWATER_ROUTE134, 8, 6', 'end'])
        metadata = json.loads((ROOT / 'data/maps/Route134/map.json').read_text())
        self.assertEqual([item['direction'] for item in metadata['connections']], ['left', 'right'])
        self.assertEqual(metadata['warp_events'], [])

    def test_object_flags_items_and_header_defaults_are_not_replaced_by_variants(self):
        expected = [(4, 0), (8, 1), (10, 0), (10, 0), (11, 0)]
        for name, (objects, warps) in zip(MAPS, expected):
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            self.assertEqual([len(metadata[field]) for field in
                ('object_events', 'warp_events', 'coord_events', 'bg_events')], [objects, warps, 0, 0])
            self.assertEqual(metadata['layout'], 'LAYOUT_' + name.upper())
            self.assertEqual(metadata['map_type'], 'MAP_TYPE_OCEAN_ROUTE')
            self.assertEqual(metadata['music'], 'MUS_ROUTE119')
        metadata = json.loads((ROOT / 'data/maps/Route130/map.json').read_text())
        berry = next(obj for obj in metadata['object_events'] if obj['script'] == 'BerryTreeScript')
        self.assertEqual(berry['flag'], 'FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE')
        self.assertEqual(berry['trainer_sight_or_berry_tree_id'], 'BERRY_TREE_ROUTE_130_LIECHI')

    def test_selected_layouts_keep_their_actual_tilesets_and_dimensions(self):
        rows = {row['id']: row for row in json.loads((ROOT / 'data/layouts/layouts.json').read_text())['layouts']}
        for key in ('LAYOUT_ROUTE130', 'LAYOUT_ROUTE130_MIRAGE_ISLAND'):
            self.assertEqual((rows[key]['width'], rows[key]['height'], rows[key]['secondary_tileset']),
                             (80, 40, 'gTileset_Cave'))
        row = rows['LAYOUT_ROUTE131_SKY_PILLAR']
        self.assertEqual((row['width'], row['height'], row['secondary_tileset']), (60, 40, 'gTileset_Pacifidlog'))
        for row in (rows[key] for key in ('LAYOUT_ROUTE130', 'LAYOUT_ROUTE130_MIRAGE_ISLAND', 'LAYOUT_ROUTE131_SKY_PILLAR')):
            self.assertEqual((ROOT / row['border_filepath']).stat().st_size, 8)
            self.assertEqual((ROOT / row['blockdata_filepath']).stat().st_size, row['width'] * row['height'] * 2)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_47_labels_preserve_complete_native_spans_without_local_text(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        for name, count, size in OWNERS:
            source = blocks(name)
            start = next(iter(symbols[name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, ''.join(source.values()), version=4, address=start)
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertFalse(any(p.kind == 'string' for p in parts.values()))
            labels = list(parts)
            for i, label in enumerate(labels):
                begin = next(iter(symbols[label]))
                following = labels[i + 1] if i + 1 < len(labels) else (
                    'Underwater_Route124_MapScripts' if name == 'Route134' else f'Route{int(name[5:]) + 1}_MapScripts')
                self.assertEqual(parts[label].size, next(iter(symbols[following])) - begin, label)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_35_trainer_frames_layout_choices_and_immediate_mirage_special_are_current(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 35)
        self.assertEqual(set(batch['dynamic_layouts']),
            {'LAYOUT_ROUTE130', 'LAYOUT_ROUTE130_MIRAGE_ISLAND', 'LAYOUT_ROUTE131_SKY_PILLAR'})
        contract = next(item for item in batch['special_contracts'] if item['entry'] == 'IsMirageIslandPresent')
        self.assertEqual(contract, dict(entry='IsMirageIslandPresent', waitstate=0,
                         source_path='src/time_events.c', source_symbol='IsMirageIslandPresent'))
        self.assertEqual(review._review_batch(ROOT, batch, set(MAPS), {})['status'], 'current')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_real_layout_table_ids_distinguish_default_130_from_mirage(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        base = next(iter(symbols['gMapLayouts'])) - 0x08000000
        for name, number in [('Route130', 263), ('Route130_MirageIsland', 46),
                             ('Route131', 47), ('Route132', 48), ('Route133', 49),
                             ('Route134', 50), ('Route131_SkyPillar', 319)]:
            offset = base + (number - 1) * 4
            self.assertEqual(int.from_bytes(rom[offset:offset + 4], 'little'),
                             next(iter(symbols[name + '_Layout'])), name)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_fixed_dive_native_bytes_encode_coordinates_and_no_warp_id(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        begin = next(iter(symbols['Route134_OnResume'])) - 0x08000000
        self.assertEqual(rom[begin:begin + 9], bytes.fromhex('40 18 45 ff 08 00 06 00 02'))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_missing_mirage_layout_selection_evidence_cannot_be_current(self):
        batch = copy.deepcopy(self.family())
        batch['dynamic_layouts'].remove('LAYOUT_ROUTE130_MIRAGE_ISLAND')
        with self.assertRaisesRegex(ValueError, '^missing_or_unreachable_dynamic_layout_contract$'):
            review._review_batch(ROOT, batch, set(MAPS), {})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_missing_mirage_blockdata_native_span_cannot_be_current(self):
        batch = copy.deepcopy(self.family())
        removed = [item for item in batch['native_spans'] if item['role'] == 'dynamic_blockdata'
                   and item['symbol'] == 'Route130_MirageIsland_Layout_Blockdata']
        self.assertEqual(len(removed), 1)
        batch['native_spans'].remove(removed[0])
        with self.assertRaisesRegex(ValueError, '^incomplete_shared_native_coverage$'):
            review._review_batch(ROOT, batch, set(MAPS), {})

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_250_distinct_forms_match_native_macro_expansion(self):
        batch = self.family()
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in batch['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 250)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
