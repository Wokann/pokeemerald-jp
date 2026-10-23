"""Early-town services use actual shared layouts and bounded script interfaces."""
import copy
import json
from pathlib import Path
import struct
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
    import test_map_review_dynamic_layouts as layout_fixtures
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms
    from tools import test_map_review_dynamic_layouts as layout_fixtures

ROOT = Path(__file__).resolve().parents[1]
OWNERS = [('OldaleTown_House1', 3, 118, 1), ('OldaleTown_House2', 5, 89, 2),
          ('OldaleTown_PokemonCenter_1F', 11, 322, 4), ('OldaleTown_PokemonCenter_2F', 4, 39, 0),
          ('OldaleTown_Mart', 11, 261, 3), ('DewfordTown_House1', 7, 191, 3),
          ('DewfordTown_PokemonCenter_1F', 7, 145, 2), ('DewfordTown_PokemonCenter_2F', 4, 39, 0)]
MAPS = [row[0] for row in OWNERS]


def blocks(path):
    return review.label_blocks((ROOT / path).read_text())


def local(name, suffix):
    return review.statements(blocks(f'data/maps/{name}/scripts.inc')[name + '_' + suffix])


class ServiceInterfaceTests(unittest.TestCase):
    def parse(self, text, version=4, owner='Entry'):
        return profile.profile_block(ROOT, owner + '::\n' + text, {}, version=version, address=0x08240000)

    def test_new_forms_are_typed_and_their_real_macro_widths_match(self):
        cases = [('setrespawn HEAL_LOCATION_OLDALE_TOWN', 3),
                 ('setwarp MAP_TRADE_CENTER, 5, 8', 8), ('setwarp MAP_TRADE_CENTER, 0, 65535', 8),
                 ('warpspinenter MAP_UNION_ROOM, 7, 11', 8),
                 ('erasebox 0, 0, 29, 19', 5), ('messageautoscroll Text', 5),
                 ('trywondercardscript', 1), ('nurse_joy_bow\nstep_end', 2)]
        for source, size in cases:
            with self.subTest(source=source):
                self.assertEqual(self.parse(source).size, size)
                with self.assertRaises(ValueError):
                    self.parse(source, version=3)
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms([source.split('\n')[0] for source, _ in cases], version=4)

    def test_unsupported_forms_do_not_hide_numeric_pointers_or_width_overflow(self):
        for source in ('setrespawn 14', 'setrespawn VAR_RESULT', 'setrespawn HEAL_LOCATION_OLDALE_TOWN, 0',
                       'setwarp 0, 5, 8', 'setwarp MAP_TRADE_CENTER, 5',
                       'setwarp MAP_TRADE_CENTER, -1, 8', 'setwarp MAP_TRADE_CENTER, 5, 65536',
                       'warpspinenter MAP_UNION_ROOM, 7, 11, 0', 'erasebox 0, 0, 29',
                       'erasebox 0, 0, 256, 19', 'messageautoscroll 0x08240000',
                       'messageautoscroll NULL', 'trywondercardscript 0',
                       'nurse_joy_bow 1\nstep_end', 'nurse_joy_bow\nend', 'nurse_joy_bow'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)

    def test_saved_script_is_an_explicit_runtime_interface_with_a_real_fallback(self):
        p = self.parse('trywondercardscript', owner='CableClub_EventScript_TryWonderCardScript')
        self.assertEqual(p.runtime_scripts, {'saved_wonder_card'})
        self.assertEqual(p.fallthrough, 'CableClub_EventScript_MysteryGiftThankYou')
        self.assertEqual(p.targets, {p.fallthrough: 'script'})
        self.assertTrue(p.may_fall_through)
        self.assertEqual(self.parse('end').runtime_scripts, set())

    def test_nurse_heals_only_after_yes_and_keeps_last_message_for_the_caller(self):
        source = blocks('data/scripts/pkmn_center_nurse.inc')
        entry = review.statements(source['Common_EventScript_PkmnCenterNurse'])
        self.assertIn('goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard', entry)
        self.assertIn('goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn', entry)
        self.assertEqual(review.statements(source['EventScript_PkmnCenterNurse_Goodbye']),
                         ['message gText_WeHopeToSeeYouAgain', 'return'])
        heal = review.statements(source['EventScript_PkmnCenterNurse_TakeAndHealPkmn'])
        self.assertEqual(heal, ['applywaitmovement VAR_0x800B, Common_Movement_WalkInPlaceFasterLeft',
            'dofieldeffect FLDEFF_POKECENTER_HEAL', 'waitfieldeffect FLDEFF_POKECENTER_HEAL',
            'applywaitmovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown', 'special HealPlayerParty', 'return'])
        self.assertEqual(review.statements(source['Movement_PkmnCenterNurse_Bow']), ['nurse_joy_bow', 'delay_4', 'step_end'])
        for name in (MAPS[2], MAPS[6]):
            scene = local(name, 'EventScript_Nurse')
            self.assertEqual(scene[-5:], ['call Common_EventScript_PkmnCenterNurse', 'waitmessage',
                                         'waitbuttonpress', 'release', 'end'])

    def test_oldale_wireless_dialogue_is_gated_by_the_pokedex_not_map_presence(self):
        scene = local(MAPS[2], 'EventScript_Girl')
        self.assertEqual(scene[:3], ['lock', 'faceplayer',
            'goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable'])
        self.assertIn('msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT', scene)

    def test_two_floors_keep_four_shared_hooks_and_three_returning_service_wrappers(self):
        for name in (MAPS[3], MAPS[7]):
            self.assertEqual(local(name, 'MapScripts'), [
                'map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame',
                'map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp',
                'map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad',
                'map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition', '.byte 0'])
            for service in ('Colosseum', 'TradeCenter', 'RecordCorner'):
                self.assertEqual(local(name, 'EventScript_' + service), ['call CableClub_EventScript_' + service, 'end'])

    def test_mart_stock_and_dialogue_share_the_adventure_flag_with_distinct_tables(self):
        clerk = local(MAPS[4], 'EventScript_Clerk')
        self.assertIn('goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems', clerk)
        basic, expanded = local(MAPS[4], 'Pokemart_Basic'), local(MAPS[4], 'Pokemart_Expanded')
        self.assertEqual(basic, ['.2byte ITEM_POTION', '.2byte ITEM_ANTIDOTE',
                                '.2byte ITEM_PARALYZE_HEAL', '.2byte ITEM_AWAKENING', 'pokemartlistend'])
        self.assertEqual(expanded, ['.2byte ITEM_POKE_BALL'] + basic)
        self.assertIn('goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock',
                      local(MAPS[4], 'EventScript_Woman'))

    def test_cable_trade_and_union_room_have_distinct_party_requirements(self):
        source = blocks('data/scripts/cable_club.inc')
        trade = review.statements(source['CableClub_EventScript_CheckPartyTradeRequirements'])
        union = review.statements(source['CableClub_EventScript_CheckPartyUnionRoomRequirements'])
        self.assertEqual(trade[0], 'specialvar VAR_RESULT, CalculatePlayerPartyCount')
        self.assertEqual(union[0], 'specialvar VAR_RESULT, CountPartyNonEggMons')
        for scene in (trade, union):
            self.assertTrue(scene[1].startswith('goto_if_lt VAR_RESULT, 2, '))
            self.assertEqual(scene[2], 'specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry')
            self.assertEqual(scene[-2:], ['setvar VAR_RESULT, TRUE', 'return'])

    def test_native_union_entry_keeps_two_explicit_waits_not_table_inferred_waits(self):
        scene = review.statements(blocks('data/scripts/cable_club.inc')['CableClub_EventScript_EnterUnionRoom'])
        self.assertEqual(scene[-5:], ['warpspinenter MAP_UNION_ROOM, 7, 11', 'waitstate',
                                     'special RunUnionRoom', 'waitstate', 'end'])

    def test_jp_record_mixing_does_not_invent_the_us_foreign_language_branch(self):
        scene = review.statements(blocks('data/scripts/cable_club.inc')['CableClub_EventScript_RecordCorner'])
        self.assertIn('special TryRecordMixLinkup', scene)
        self.assertNotIn('special ValidateMixingGameLanguage', scene)
        self.assertFalse(any('LINKUP_FOREIGN_GAME' in line for line in scene))

    def test_jp_trainer_card_confirmation_advances_without_the_us_delay(self):
        scene = review.statements(blocks('data/scripts/cable_club.inc')['CableClub_EventScript_TrainerCardDataOverwritten'])
        start = scene.index('playse SE_PIN')
        self.assertEqual(scene[start + 1], 'message CableClub_Text_HopeToSeeYouAgain')
        self.assertNotIn('delay 60', scene)


class SharedDefaultLayoutTests(unittest.TestCase):
    def fixture(self):
        f = layout_fixtures.DynamicLayoutTests()
        f.setUp()
        self.addCleanup(f.doCleanups)
        f.put('data/maps/First/map.json', json.dumps(dict(name='First', layout='LAYOUT_ALT')))
        image = bytearray(f.native['rom'])
        struct.pack_into('<I', image, 128, 0x08000010)
        struct.pack_into('<H', image, 146, 1)
        f.native['rom'] = bytes(image)
        f.native['symbols']['First'] = {0x08000080}
        return f

    def test_shared_owner_comes_from_metadata_not_a_same_named_map_directory(self):
        f = self.fixture()
        self.assertEqual(review.default_layout_owner(f.root, 'First', allow_shared=True), f.row)
        with self.assertRaisesRegex(ValueError, 'shared_default_layout_version'):
            review.default_layout_owner(f.root, 'First')
        errors = []
        review._shared_default_layout_native(f.root, ['First'], f.native, errors)
        self.assertEqual(errors, [])

    def test_missing_ambiguous_or_nonsemantic_layout_ids_and_owners_are_rejected(self):
        f = self.fixture()
        for rows in ([], [f.row, f.row], [dict(f.row, name='0x08400000')],
                     [dict(f.row, width=0)], [dict(f.row, width=True)], [dict(f.row, height=-1)]):
            f.put('data/layouts/layouts.json', json.dumps(dict(layouts=rows)))
            with self.subTest(rows=rows), self.assertRaises(ValueError):
                review.default_layout_owner(f.root, 'First', allow_shared=True)
        f.put('data/layouts/layouts.json', json.dumps(dict(layouts=[f.row])))
        f.put('data/maps/First/map.json', json.dumps(dict(layout=None)))
        with self.assertRaises(ValueError):
            review.default_layout_owner(f.root, 'First', allow_shared=True)

    def test_shared_assets_cannot_be_guessed_or_redirected_outside_layouts(self):
        f = self.fixture()
        bad = [dict(f.row, border_filepath='../outside/border.bin'),
               dict(f.row, blockdata_filepath='data/layouts/../../src/map.bin'),
               dict(f.row, border_filepath='data/layouts/Alt/not-border.bin')]
        missing = dict(f.row)
        del missing['blockdata_filepath']
        bad.append(missing)
        for row in bad:
            f.put('data/layouts/layouts.json', json.dumps(dict(layouts=[row])))
            with self.subTest(row=row), self.assertRaises(ValueError):
                review.default_layout_owner(f.root, 'First', allow_shared=True)

    def test_true_asset_bytes_do_not_replace_header_layout_id_fields_or_table_checks(self):
        f = self.fixture()
        for offset, value, kind, error in [(128, 0x08000030, '<I', 'header'), (146, 2, '<H', 'header'),
                                           (16, 3, '<I', 'structure'), (0, 0x08000030, '<I', 'table')]:
            original = f.native['rom']
            image = bytearray(original)
            struct.pack_into(kind, image, offset, value)
            f.native['rom'] = bytes(image)
            errors = []
            review._shared_default_layout_native(f.root, ['First'], f.native, errors)
            self.assertIn(f'native_shared_default_layout_{error}_mismatch:First', errors)
            f.native['rom'] = original


class ServiceFamilyNativeTests(unittest.TestCase):
    def family(self):
        rows = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        found = [row for row in rows if set(row['maps']) & set(MAPS)]
        self.assertEqual(len(found), 1, 'one explicitly reviewed adjacent service family')
        self.assertEqual(found[0]['maps'], MAPS)
        return found[0]

    def test_eight_map_references_have_only_six_layout_owners_and_twelve_assets(self):
        owners = [review.default_layout_owner(ROOT, name, allow_shared=True) for name in MAPS]
        self.assertEqual([row['name'] for row in owners], [
            'House1_Layout', 'House2_Layout', 'PokemonCenter_1F_Layout', 'PokemonCenter_2F_Layout',
            'Mart_Layout', 'House3_Layout', 'PokemonCenter_1F_Layout', 'PokemonCenter_2F_Layout'])
        self.assertEqual(len({row[field] for row in owners for field in ('border_filepath', 'blockdata_filepath')}), 12)
        for name in MAPS:
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            self.assertIsNone(metadata['connections'])
            self.assertEqual((len(metadata['coord_events']), len(metadata['bg_events'])), (0, 0))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_52_labels_and_15_jp_text_objects_close_the_exact_1204_bytes(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for i, (name, count, size, texts) in enumerate(OWNERS):
            source = blocks(f'data/maps/{name}/scripts.inc')
            first = next(iter(symbols[name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, ''.join(source.values()), version=4, address=first)
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertEqual(sum(p.kind == 'string' for p in parts.values()), texts)
            ordered = list(parts)
            for j, label in enumerate(ordered):
                following = ordered[j + 1] if j + 1 < len(ordered) else (
                    MAPS[i + 1] if i + 1 < len(MAPS) else 'DewfordTown_Gym') + '_MapScripts'
                start, end = next(iter(symbols[label])), next(iter(symbols[following]))
                self.assertEqual(parts[label].size, end - start, label)
                if parts[label].kind == 'string':
                    data = review.encoded_text(ROOT, source[label], 'string')
                    self.assertEqual(data, rom[start - 0x08000000:end - 0x08000000], label)
                    self.assertEqual((data.count(b'\xff'), data[-1:]), (1, b'\xff'))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_respawn_keeps_real_oldale_and_dewford_ids_not_map_or_layout_ids(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, heal_id in ((MAPS[2], 14), (MAPS[6], 15)):
            address = next(iter(symbols[name + '_OnTransition'])) - 0x08000000
            self.assertEqual(rom[address:address + 3], bytes([0x9F, heal_id, 0]))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_native_link_tails_keep_destination_opcode_and_implicit_special_wait(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        tails = [(0x246D16, '25 01 00 39 19 18 FF 06 00 08 00 25 02 00 27 02'),
                 (0x246D31, '25 01 00 39 19 1B FF 05 00 08 00 25 02 00 27 02'),
                 (0x246E84, '25 01 00 3E 19 19 FF 05 00 08 00 25 02 00 27 02'),
                 (0x246F87, '25 01 00 3E 19 1A FF 08 00 09 00 25 02 00 27 02')]
        for address, expected in tails:
            self.assertEqual(rom[address:address + 16], bytes.fromhex(expected))
        waits = profile.special_waits(ROOT)
        self.assertEqual((waits['SetCableClubWarp'], waits['DoCableClubWarp'], waits['RunUnionRoom']), (0, 1, 0))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_union_native_pauses_and_destination_resume_are_separate_interfaces(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(rom[0x2472F4:0x247305], bytes.fromhex('25 01 00 D1 19 3C FF 07 00 0B 00 27 25 9F 01 27 02'))
        target = review.statements(blocks('data/maps/UnionRoom/scripts.inc')['UnionRoom_OnResume'])
        self.assertEqual(target[-2:], ['special RunUnionRoom', 'end'])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_record_current_and_no_runtime_save_payload_is_claimed_as_rom_code(self):
        batch = self.family()
        self.assertEqual(batch['trainer_battles'], [])
        self.assertEqual(batch['dynamic_layouts'], [])
        self.assertEqual(review._review_batch(ROOT, batch, set(MAPS), {})['status'], 'current')
        self.assertEqual(sum(s['role'] == 'default_layout_table' for s in batch['native_spans']), 8)
        bad = copy.deepcopy(batch)
        bad['sources'] = [s for s in bad['sources'] if s['path'] != 'src/util.c']
        with self.assertRaisesRegex(ValueError, 'missing_runtime_script_interface_context'):
            review.component_contracts(ROOT, bad, MAPS)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_complete_family_forms_use_real_native_macro_expansion(self):
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in self.family()['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 452)
        self.assertIn('trywondercardscript', forms)
        self.assertIn('nurse_joy_bow', forms)
        self.assertTrue(any(line.startswith('setrespawn ') for line in forms))
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
