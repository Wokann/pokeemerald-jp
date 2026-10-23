"""Littleroot interiors keep gender/story gates and gift outcomes distinct."""
import json
from pathlib import Path
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
    import test_map_review_story_v4 as story_fixtures
    import test_map_review_dynamic_layouts as layout_fixtures
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms
    from tools import test_map_review_story_v4 as story_fixtures
    from tools import test_map_review_dynamic_layouts as layout_fixtures

ROOT = Path(__file__).resolve().parents[1]
OWNERS = [('LittlerootTown_BrendansHouse_1F', 66, 2061, 29),
          ('LittlerootTown_BrendansHouse_2F', 39, 966, 5),
          ('LittlerootTown_MaysHouse_1F', 50, 1930, 8),
          ('LittlerootTown_MaysHouse_2F', 49, 1866, 9),
          ('LittlerootTown_ProfessorBirchsLab', 130, 5799, 50)]
MAPS = [row[0] for row in OWNERS]
LAB = MAPS[-1]
SPECIES = [('Cyndaquil', 155), ('Totodile', 158), ('Chikorita', 152)]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def lines(name, suffix):
    return review.statements(blocks(name)[name + '_' + suffix])


class LittlerootInteriorTests(unittest.TestCase):
    def family(self):
        rows = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        selected = [row for row in rows if set(row['maps']) & set(MAPS)]
        self.assertEqual(len(selected), 1, 'one explicitly reviewed adjacent family')
        self.assertEqual(selected[0]['maps'], MAPS)
        return selected[0]

    def parse(self, text, version=4):
        return profile.profile_block(ROOT, 'Entry::\n' + text, {}, version=version, address=0x08240000)

    def test_new_forms_are_v4_only_and_measure_each_parameter_width(self):
        forms = [('call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, Target', 11),
                 ('givemon SPECIES_CYNDAQUIL, 5', 15),
                 ('givemon SPECIES_TOTODILE, 255, ITEM_ORAN_BERRY', 15),
                 ('subvar VAR_RESULT, 1', 5), ('subvar VAR_RESULT, 0xFFFF', 5),
                 ('showmonpic SPECIES_CHIKORITA, 10, 3', 5),
                 ('showmonpic SPECIES_CHIKORITA, 0, 255', 5), ('hidemonpic', 1),
                 ('bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL', 4),
                 ('bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES', 4),
                 ('bufferboxname STR_VAR_3, VAR_RESULT', 4)]
        for source, size in forms:
            with self.subTest(source=source):
                self.assertEqual(self.parse(source).size, size)
                with self.assertRaises(ValueError):
                    self.parse(source, version=3)
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms([source for source, _ in forms], version=4)

    def test_bad_gift_species_level_item_and_extra_operands_fail_closed(self):
        for source in ('givemon', 'givemon SPECIES_CYNDAQUIL', 'givemon VAR_RESULT, 5',
                       'givemon SPECIES_CYNDAQUIL, -1', 'givemon SPECIES_CYNDAQUIL, 256',
                       'givemon SPECIES_CYNDAQUIL, VAR_RESULT',
                       'givemon SPECIES_CYNDAQUIL, 5, VAR_RESULT',
                       'givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE, 0'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)

    def test_bad_picture_coordinates_and_buffer_registers_fail_closed(self):
        for source in ('showmonpic VAR_RESULT, 10, 3', 'showmonpic SPECIES_CYNDAQUIL, 10',
                       'showmonpic SPECIES_CYNDAQUIL, -1, 3', 'showmonpic SPECIES_CYNDAQUIL, 10, 256',
                       'showmonpic SPECIES_CYNDAQUIL, 10, 3, 0', 'hidemonpic 0',
                       'bufferspeciesname STR_VAR_4, SPECIES_CYNDAQUIL',
                       'bufferspeciesname STR_VAR_1, 155', 'bufferspeciesname VAR_RESULT, SPECIES_CYNDAQUIL',
                       'bufferboxname STR_VAR_1, SPECIES_CYNDAQUIL', 'bufferboxname STR_VAR_1, 0'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)

    def test_bad_subtraction_width_or_untyped_conditional_call_is_rejected(self):
        for source in ('subvar 0x800D, 1', 'subvar VAR_RESULT, -1', 'subvar VAR_RESULT, 65536',
                       'subvar VAR_RESULT, 1, 0', 'call_if_lt 2, VAR_RESULT, Target',
                       'call_if_lt VAR_RESULT, 2, NULL', 'call_if_lt VAR_RESULT, 2, Target, Extra'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)

    def test_manual_boxes_and_mom_positions_are_not_blind_gender_substitution(self):
        for name, gender, x in [(MAPS[0], 'MALE', 3), (MAPS[2], 'FEMALE', 6)]:
            self.assertIn(f'goto_if_eq VAR_RESULT, {gender}, {name}_EventScript_ShowRunningShoesManual',
                          lines(name, 'EventScript_CheckShowShoesManual'))
            self.assertEqual(lines(name, 'EventScript_ShowRunningShoesManual'),
                             [f'setmetatile {x}, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE', 'return'])
            self.assertEqual(lines(name, 'EventScript_SetMovingBoxes'),
                ['setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE',
                 'setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE', 'return'])
            self.assertIn('map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV',
                          lines(name, 'OnFrame'))

    def test_upstairs_parallel_movement_finishes_before_warp_and_waitstate(self):
        for name, upstairs, x in [(MAPS[0], 'BRENDANS', 7), (MAPS[2], 'MAYS', 1)]:
            scene = lines(name, 'EventScript_GoUpstairsToSetClock')
            index = scene.index('waitmovement 0')
            self.assertTrue(all(line.startswith('applymovement ') for line in scene[index - 2:index]))
            self.assertEqual(scene[index + 1:],
                             [f'warp MAP_LITTLEROOT_TOWN_{upstairs}_HOUSE_2F, {x}, 1',
                              'waitstate', 'releaseall', 'end'])

    def test_readiness_decorations_and_pc_entry_use_opposite_gender_contracts(self):
        for name, rival, player, visitor in [(MAPS[1], 'Brendan', 'MALE', 'FEMALE'),
                                             (MAPS[3], 'May', 'FEMALE', 'MALE')]:
            self.assertEqual(lines(name, 'OnTransition')[-3:],
                ['call SecretBase_EventScript_SetDecorationFlags', 'setvar VAR_SECRET_BASE_INITIALIZED, 0', 'end'])
            self.assertIn(f'goto_if_eq VAR_RESULT, {visitor}, {name}_EventScript_SetReadyToMeet{rival}',
                          lines(name, 'EventScript_CheckSetReadyToMeet' + rival))
            self.assertEqual(lines(name, 'EventScript_CheckInitDecor'),
                ['checkplayergender', f'goto_if_eq VAR_RESULT, {player}, SecretBase_EventScript_InitDecorations', 'end'])
            pc = lines(name, 'EventScript_PC')
            self.assertIn(f'goto_if_eq VAR_RESULT, {player}, {name}_EventScript_CheckPlayersPC', pc)
            self.assertIn(f'goto_if_eq VAR_RESULT, {visitor}, {name}_EventScript_CheckRivalsPC', pc)

    def test_cross_house_return_is_a_real_local_callback_not_an_alias(self):
        entry = 'goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret'
        self.assertIn(entry, lines(MAPS[1], 'EventScript_TryUpdateBrendanPos'))
        self.assertEqual(lines(MAPS[3], 'EventScript_Ret'), ['return'])

    def test_shared_movers_keep_the_jp_machoke_cry_not_the_english_species(self):
        source = review.label_blocks((ROOT / 'data/scripts/players_house.inc').read_text())
        for entry in ('PlayersHouse_1F_EventScript_Vigoroth1', 'PlayersHouse_1F_EventScript_Vigoroth2'):
            scene = review.statements(source[entry])
            self.assertIn('playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL', scene)
            self.assertNotIn('playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL', scene)
            self.assertEqual(scene[-3:], ['waitmoncry', 'release', 'end'])

    def test_jp_birch_shared_registration_callback_keeps_its_actual_gate(self):
        source = review.label_blocks((ROOT / 'data/scripts/prof_birch.inc').read_text())
        self.assertEqual(review.statements(source['ProfBirch_EventScript_RatePokedexOrRegister']),
            ['lock', 'faceplayer', 'goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch'])
        self.assertIn('EventScript_RegisterProfBirch', blocks(LAB))
        callback = review.statements(blocks(LAB)['EventScript_RegisterProfBirch'])
        self.assertLess(callback.index('waitfanfare'), callback.index('setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL'))
        self.assertIn('setvar VAR_REGISTER_BIRCH_STATE, 2', callback)

    def test_neighbor_and_sibling_fill_the_actual_jp_placeholder_before_message(self):
        source = blocks(MAPS[2])
        neighbor = lines(MAPS[2], 'EventScript_YoureNewNeighbor')
        self.assertLess(neighbor.index('special GetRivalSonDaughterString'),
                        next(i for i, line in enumerate(neighbor) if line.startswith('msgbox RivalsHouse_1F_Text_OhYoure')))
        sibling = [review.statements(block) for block in source.values()
                   if 'special GetPlayerBigGuyGirlString' in block]
        self.assertEqual(len(sibling), 1)
        self.assertLess(sibling[0].index('special GetPlayerBigGuyGirlString'),
                        sibling[0].index('msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT'))
        self.assertIn('{STR_VAR_1}', source['RivalsHouse_1F_Text_DoYouHavePokemon'])

    def test_all_three_johto_gifts_keep_party_pc_failure_and_retry_separate(self):
        for species, _ in SPECIES:
            with self.subTest(species=species):
                upper = species.upper()
                give = lines(LAB, 'EventScript_Give' + species)
                self.assertEqual(give[:3], [f'bufferspeciesname STR_VAR_1, SPECIES_{upper}',
                    f'setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_{upper}', f'givemon SPECIES_{upper}, 5'])
                self.assertEqual(give[3:5], [
                    f'goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, {LAB}_EventScript_Send{species}ToParty',
                    f'goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, {LAB}_EventScript_Send{species}ToPC'])
                self.assertEqual(give[5:], ['hidemonpic', 'goto Common_EventScript_NoMoreRoomForPokemon', 'end'])
                for destination in ('Party', 'PC'):
                    success = lines(LAB, f'EventScript_Send{species}To{destination}')
                    self.assertEqual(success[:2], [f'call {LAB}_EventScript_ReceivedJohtoStarter',
                                                  f'removeobject LOCALID_BIRCHS_LAB_{upper}_BALL'])
                received = lines(LAB, 'EventScript_Received' + species)
                self.assertEqual(received[0], 'hidemonpic')
                self.assertEqual(received[-3:], ['setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6', 'releaseall', 'end'])

    def test_johto_picture_decline_and_full_storage_do_not_finish_the_choice(self):
        for species, _ in SPECIES:
            entry = lines(LAB, 'EventScript_' + species)
            self.assertIn(f'showmonpic SPECIES_{species.upper()}, 10, 3', entry)
            self.assertIn(f'goto_if_eq VAR_RESULT, NO, {LAB}_EventScript_TakeYourTime', entry)
        decline = lines(LAB, 'EventScript_TakeYourTime')
        self.assertEqual(decline[0], 'hidemonpic')
        self.assertFalse(any('setvar VAR_DEX' in line or line.startswith('removeobject') for line in decline))

    def test_party_nickname_slot_and_pc_box_buffers_keep_their_u16_variables(self):
        source = review.label_blocks((ROOT / 'data/scripts/pc_transfer.inc').read_text())
        self.assertEqual(review.statements(source['Common_EventScript_GetGiftMonPartySlot']),
            ['getpartysize', 'subvar VAR_RESULT, 1', 'copyvar VAR_0x8004, VAR_RESULT', 'return'])
        self.assertEqual(review.statements(source['Common_EventScript_TransferredToPC'])[:2],
            ['bufferboxname STR_VAR_1, VAR_PC_BOX_TO_SEND_MON',
             'bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES'])
        waits = profile.special_waits(ROOT)
        self.assertEqual((waits['ChangePokemonNickname'], waits['ChangeBoxPokemonNickname']), (1, 1))

    def test_lab_frame_roots_and_national_flags_preserve_scene_phases(self):
        frame = lines(LAB, 'OnFrame')
        self.assertEqual([line.split(', ')[1] for line in frame[:-1]], ['2', '4', '1', '4'])
        upgrade = lines(LAB, 'EventScript_UpgradeToNationalDex')
        self.assertEqual(upgrade.count('waitmovement 0'), 2)
        self.assertLess(upgrade.index('waitfanfare'), upgrade.index('setflag FLAG_SYS_NATIONAL_DEX'))
        self.assertEqual(upgrade[upgrade.index('setflag FLAG_SYS_NATIONAL_DEX') + 1], 'special EnableNationalPokedex')
        self.assertIn('setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2', upgrade)
        initial = lines(LAB, 'EventScript_GiveStarterEvent')
        self.assertFalse(any(line.startswith('givemon ') for line in initial))

    def test_pokedex_and_pokeball_bag_full_warning_do_not_invent_a_retry(self):
        receipt = lines(LAB, 'EventScript_ReceivePokedex')
        self.assertEqual(receipt[2:6], ['waitfanfare', 'setflag FLAG_SYS_POKEDEX_GET',
                                      'special SetUnlockedPokedexFlags', 'setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH'])
        for rival in ('May', 'Brendan'):
            ball = lines(LAB, 'EventScript_' + rival + 'GivePokeBalls')
            self.assertEqual(ball[1], 'giveitem ITEM_POKE_BALL, 5')
            self.assertEqual(ball[2], f'call_if_eq VAR_RESULT, FALSE, {LAB}_EventScript_{rival}NoRoomForPokeBalls')
            self.assertEqual(ball[-1], 'return')
        story = lines(LAB, 'EventScript_GivePokedex')
        self.assertEqual(story[-7:], ['setvar VAR_BIRCH_LAB_STATE, 5', 'setflag FLAG_ADVENTURE_STARTED',
            'setvar VAR_OLDALE_TOWN_STATE, 1', 'setvar VAR_LITTLEROOT_RIVAL_STATE, 4',
            'setvar VAR_LITTLEROOT_TOWN_STATE, 3', 'releaseall', 'end'])

    def test_all_five_headers_have_null_connections_and_real_json_events(self):
        for name, expected in zip(MAPS, [(7, 3, 4, 0), (16, 1, 0, 4), (7, 3, 4, 0), (16, 1, 0, 4), (6, 2, 0, 15)]):
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            self.assertEqual(tuple(len(metadata[field]) for field in
                ('object_events', 'warp_events', 'coord_events', 'bg_events')), expected)
            self.assertIsNone(metadata['connections'])
            self.assertEqual(review.statements((ROOT / f'data/maps/{name}/connections.inc').read_text()), [])
            self.assertEqual(metadata['map_type'], 'MAP_TYPE_INDOOR')
            self.assertFalse(any(metadata[key] for key in
                ('allow_cycling', 'allow_running', 'allow_escaping', 'requires_flash', 'show_map_name')))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_334_local_labels_and_101_text_objects_keep_every_native_boundary(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for i, (name, count, size, texts) in enumerate(OWNERS):
            source = blocks(name)
            start = next(iter(symbols[name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, ''.join(source.values()), version=4, address=start)
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertEqual(sum(p.kind == 'string' for p in parts.values()), texts)
            ordered = list(parts)
            for j, label in enumerate(ordered):
                following = ordered[j + 1] if j + 1 < len(ordered) else (
                    MAPS[i + 1] if i + 1 < len(MAPS) else 'OldaleTown_House1') + '_MapScripts'
                begin, end = next(iter(symbols[label])), next(iter(symbols[following]))
                self.assertEqual(parts[label].size, end - begin, label)
                if parts[label].kind == 'string':
                    data = review.encoded_text(ROOT, source[label], 'string')
                    self.assertEqual(data, rom[begin - 0x08000000:end - 0x08000000], label)
                    self.assertEqual((data.count(b'\xff'), data[-1:]), (1, b'\xff'), label)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_native_gift_framing_has_two_unused_words_and_one_unused_byte(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for species, number in SPECIES:
            begin = next(iter(symbols[LAB + '_EventScript_Give' + species])) - 0x08000000
            self.assertEqual(rom[begin:begin + 4], bytes([0x7D, 0, number, 0]))
            # Four-byte buffer, five-byte setvar, then the fifteen-byte gift.
            self.assertEqual(rom[begin + 9:begin + 24], bytes([0x79, number, 0, 5]) + bytes(11))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_current_family_binds_default_and_with_table_layout_without_changing_assets(self):
        batch = self.family()
        self.assertEqual(batch['dynamic_layouts'], ['LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE'])
        self.assertEqual(batch['trainer_battles'], [])
        self.assertEqual(review._review_batch(ROOT, batch, set(MAPS), {})['status'], 'current')
        data = (ROOT / 'data/layouts/LittlerootTown_ProfessorBirchsLabWithTable/map.bin').read_bytes()
        self.assertEqual((len(data), data[13 * 13 * 2:]), (340, b'\0\0'))
        span = next(s for s in batch['native_spans'] if s['role'] == 'dynamic_blockdata')
        self.assertEqual(span['size'], len(data), 'the optional alignment tail remains explicitly bound')

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_753_distinct_family_and_shared_forms_match_real_expansion(self):
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in self.family()['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 753)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


class LocalCallbackContractTests(unittest.TestCase):
    def fixture(self, target):
        setup = story_fixtures.AddressedStoryReviewTests()
        setup.setUp()
        self.addCleanup(setup.doCleanups)
        f = setup.f
        path = 'data/std.inc'
        old = (f.root / path).read_text()
        entry = 'Std_MsgboxYesNo::'
        head, body = old.split(entry)
        f.put(path, head + entry + body.replace('\treturn', '\tgoto ' + target))
        return f

    def test_shared_helper_can_reenter_an_already_typed_local_map_entry(self):
        f = self.fixture('First_Entry')
        contracts, shared = review.component_contracts(f.root, f.manifest['batches'][0], ['First'])
        self.assertIn(('First', 'scripts'), contracts)
        self.assertNotIn('First_Entry', shared, 'the callback does not create a second source/native owner')

    def test_shared_callback_to_text_is_not_accepted_as_a_script(self):
        f = self.fixture('First_Text')
        with self.assertRaisesRegex(ValueError, 'incompatible_reference_kinds:First_Text'):
            review.component_contracts(f.root, f.manifest['batches'][0], ['First'])

    def test_unbound_callback_still_requires_explicit_shared_evidence(self):
        f = self.fixture('First_Missing')
        with self.assertRaisesRegex(ValueError, 'missing_shared_call_evidence:First_Missing'):
            review.component_contracts(f.root, f.manifest['batches'][0], ['First'])


class AlignedDynamicAssetTests(unittest.TestCase):
    def fixture(self):
        f = layout_fixtures.DynamicLayoutTests()
        f.setUp()
        self.addCleanup(f.doCleanups)
        f.row.update(width=3, height=1)
        f.put('data/layouts/layouts.json', json.dumps(dict(layouts=[f.row])))
        path = f.root / 'data/layouts/layouts.inc'
        f.put('data/layouts/layouts.inc', path.read_text().replace('.4byte 2\n.4byte 2', '.4byte 3\n.4byte 1'))
        return f

    def test_dynamic_block_asset_may_retain_only_a_zero_word_alignment_tail(self):
        f = self.fixture()
        for data in (bytes(6), bytes(8)):
            f.put('data/layouts/Alt/map.bin', data)
            review.dynamic_layout_contracts(f.root, f.batch)
            self.assertEqual(review._dynamic_blockdata_size(f.root, f.row), len(data))

    def test_nonzero_arbitrary_trailing_or_missing_cell_data_is_rejected(self):
        f = self.fixture()
        for data in (bytes(5), bytes(7), bytes(10), bytes(6) + b'\0\x01'):
            f.put('data/layouts/Alt/map.bin', data)
            with self.subTest(size=len(data)), self.assertRaisesRegex(ValueError, 'dynamic_layout_asset'):
                review.dynamic_layout_contracts(f.root, f.batch)


if __name__ == '__main__':
    unittest.main()
