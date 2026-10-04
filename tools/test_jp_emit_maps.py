#!/usr/bin/env python3
"""Regression coverage for source-proven semantic recovery in jp_emit_maps."""
import difflib
import json
import re
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))

import jp_emit_maps as emitter  # noqa: E402


def render_map(name):
    """Render one map exactly as jp_emit_maps.main would, without writing it."""
    entries = emitter.map_entries(include_empty=True)
    global_text_ptrs = emitter.collect_all_text_ptrs(entries)
    text_label_map = {
        pointer: 'gJPText_%08X' % (pointer & 0xFFFFFF)
        for pointer in global_text_ptrs
    }
    all_labels = emitter.event_script_labels()
    map_starts = {entry[0] for entry in entries}
    nonmap = sorted(address for address in all_labels if address not in map_starts)
    last_map_end = next(
        (address for address in nonmap if address > entries[-1][0]),
        0x0828F000)
    for index, (start, map_name, group, number, map_entries, events_addr) in enumerate(entries):
        if map_name != name:
            continue
        next_index = index + 1
        while next_index < len(entries) and entries[next_index][0] == start:
            next_index += 1
        natural_end = (entries[next_index][0]
                       if next_index < len(entries) else last_map_end)
        region_end = emitter.MAP_SOURCE_REGION_ENDS.get(map_name, natural_end)
        region_labels = {
            address: label for address, label in all_labels.items()
            if start <= address < region_end
        }
        return emitter.emit_map(
            start, map_name, group, number, map_entries, region_end,
            global_text_ptrs, text_label_map, region_labels, set(), events_addr)[0]
    raise AssertionError('map not found: %s' % name)


class Route111SemanticRecoveryTest(unittest.TestCase):
    def collapse_movement(self, generated, reviewed):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            owner = root / 'data/maps/Map'
            owner.mkdir(parents=True)
            (owner / 'scripts.inc').write_text(reviewed, encoding='utf-8')
            with patch.object(emitter, 'ROOT', root):
                overrides = emitter.reviewed_operand_overrides('Map', generated)
                named = emitter.apply_reviewed_operand_overrides(generated, overrides)
                return emitter.collapse_reviewed_movement_wait_macros('Map', named)

    def test_movement_helper_retains_address_scoped_operands(self):
        generated = ('Map_First:: @ 0x08100000\n'
                     '\tapplymovement 0x1, 0x08100100\n\twaitmovement 0x0\n'
                     'Map_Second:: @ 0x08100010\n'
                     '\tapplymovement 0x1, 0x08100100\n\twaitmovement 0x0\n')
        reviewed = ('Map_First:: @ 0x08100000\n'
                    '\tapplywaitmovement LOCALID_MAP_NPC, Map_Movement\n'
                    'Map_Second:: @ 0x08100010\n'
                    '\tapplymovement 0x1, 0x08100100\n\twaitmovement 0x0\n')
        self.assertEqual(self.collapse_movement(generated, reviewed), reviewed)

    def test_movement_helper_does_not_collapse_nonzero_wait(self):
        generated = ('Map_First:: @ 0x08100000\n'
                     '\tapplymovement 1, Movement\n\twaitmovement 1\n')
        reviewed = ('Map_First:: @ 0x08100000\n'
                    '\tapplywaitmovement 1, Movement\n')
        self.assertEqual(self.collapse_movement(generated, reviewed), generated)

    def test_movement_helper_does_not_cross_a_label_or_comment(self):
        reviewed = ('Map_First:: @ 0x08100000\n'
                    '\tapplywaitmovement 1, Movement\n')
        for separator in ('Map_Second:: @ 0x08100007\n', '\t@ keep this boundary\n'):
            generated = ('Map_First:: @ 0x08100000\n\tapplymovement 1, Movement\n'
                         + separator + '\twaitmovement 0\n')
            with self.subTest(separator=separator):
                self.assertEqual(self.collapse_movement(generated, reviewed), generated)

    def test_movement_helper_preserves_parallel_and_optional_map_commands(self):
        for generated, reviewed in (
            ('\tapplymovement 1, Movement\n\tapplymovement 2, Other\n\twaitmovement 0\n',
             '\tapplymovement 1, Movement\n\tapplymovement 2, Other\n\twaitmovement 0\n'),
            ('\tapplymovement_at 1, Movement, MAP_OTHER\n\twaitmovement 0\n',
             '\tapplywaitmovement 1, Movement, MAP_OTHER\n'),
        ):
            prefix = 'Map_First:: @ 0x08100000\n'
            with self.subTest(generated=generated):
                self.assertEqual(self.collapse_movement(prefix + generated, prefix + reviewed),
                                 prefix + generated)

    def test_overrides_are_address_and_command_scoped(self):
        generated = (
            'Map_Script:: @ 0x08100000\n'
            '\tcall_if_unset 0xE4, Target\n'
            'Map_Other:: @ 0x08100010\n'
            '\tcall_if_unset 0xE4, Target\n')
        override = {
            (0x08100000, 'call_if_unset', 0, 0xE4): 'FLAG_REGI_DOORS_OPENED',
        }
        expected = generated.replace(
            'call_if_unset 0xE4, Target\nMap_Other',
            'call_if_unset FLAG_REGI_DOORS_OPENED, Target\nMap_Other')
        self.assertEqual(
            emitter.apply_reviewed_operand_overrides(generated, override), expected)

    def test_route111_matches_reviewed_semantic_source(self):
        generated = render_map('Route111')
        checked_in = (ROOT / 'data' / 'maps' / 'Route111' / 'scripts.inc').read_text(
            encoding='utf-8')
        if generated != checked_in:
            self.fail('\n'.join(difflib.unified_diff(
                checked_in.splitlines(), generated.splitlines(),
                fromfile='checked-in', tofile='generated', n=2)))

        # Exercise the semantic categories that formerly regressed to raw
        # operands. These are exact output assertions, not a map snapshot.
        required = (
            'FLAG_REGI_DOORS_OPENED',             # flag
            'VAR_MIRAGE_TOWER_STATE',             # variable
            'TRAINER_VICKY',                       # trainer
            'MAP_LITTLEROOT_TOWN',                 # map
            'LAYOUT_ROUTE111_NO_MIRAGE_TOWER',     # layout
            'LOCALID_ROUTE111_PLAYER_FALLING',     # object id
            'Route111_Text_ClawFossilDisappeared', # local text
            'GabbyAndTy_EventScript_UpdateLocation',  # external script
            'Route111_Movement_PlayerFall',        # movement
            'METATILE_Mauville_MirageTower_Tile0', # metatile
            'special SetMirageTowerVisibility',    # special
            'trainerbattle_single ',               # trainer battle macro
            'giveitem ITEM_RAZZ_BERRY',            # item macro
            'register_matchcall TRAINER_DUSTY_1',  # match-call macro
            'applywaitmovement LOCALID_PLAYER, Route111_Movement_PushUpFromRoute',
        )
        for spelling in required:
            with self.subTest(spelling=spelling):
                self.assertIn(spelling, generated)

    def test_route111_rendering_is_deterministic(self):
        self.assertEqual(render_map('Route111'), render_map('Route111'))


class ReviewedMapShorthandTest(unittest.TestCase):
    def test_hideplayer_accepts_only_exact_player_and_zero_map(self):
        for args in ('LOCALID_PLAYER, MAP_NONE', '0xFF, 0x0',
                     '255, 0', '0xff, MAP_NONE', 'LOCALID_PLAYER, 0'):
            with self.subTest(args=args):
                self.assertEqual(
                    emitter.collapse_player_visibility_macros([('hideobjectat', args)]),
                    [('hideplayer', '')])

    def test_hideplayer_retains_other_objects_maps_and_commands(self):
        for line in (('hideobjectat', '1, 0'),
                     ('hideobjectat', 'LOCALID_PLAYER, MAP_OTHER'),
                     ('hideobjectat', '0xFF, 1'),
                     ('hideobjectat', 'VAR_LAST_TALKED, MAP_NONE'),
                     ('hideobjectat', '0xFF, 0, 1'),
                     ('showobjectat', '0xFF, 0')):
            with self.subTest(line=line):
                self.assertEqual(emitter.collapse_player_visibility_macros([line]), [line])

    def test_tower_opponent_uses_current_and_legacy_special_names(self):
        for special in ('CallBattleTowerFunc', 'sub_08161E88'):
            lines = [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT'),
                     ('special', special)]
            with self.subTest(special=special):
                self.assertEqual(emitter.collapse_battle_tent_macros(lines, enabled=True),
                                 [('tower_setopponent', '')])
                self.assertEqual(emitter.collapse_battle_tent_macros(lines), lines)

    def test_tower_opponent_does_not_match_another_function_or_special(self):
        for lines in (
            [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_INIT'),
             ('special', 'CallBattleTowerFunc')],
            [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT'),
             ('special', 'CallOtherFunction')],
            [('setvar', 'VAR_0x8005, BATTLE_TOWER_FUNC_SET_OPPONENT'),
             ('special', 'CallBattleTowerFunc')],
            [('setvar', 'VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT'),
             ('waitstate', ''), ('special', 'CallBattleTowerFunc')],
        ):
            with self.subTest(lines=lines):
                self.assertEqual(emitter.collapse_battle_tent_macros(lines, enabled=True),
                                 lines)

    def test_reviewed_shorthand_survives_actual_map_regeneration(self):
        expected = {
            'SlateportCity_OceanicMuseum_1F': ('giveitem ITEM_TM_THIEF', 'giveitem ITEM_TM46'),
            'MauvilleCity_House1': ('giveitem ITEM_HM_ROCK_SMASH', 'giveitem ITEM_HM06'),
            'SlateportCity_Harbor': ('\thideplayer\n', 'hideobjectat 0xFF, 0x0'),
            'VerdanturfTown_BattleTentBattleRoom': ('\ttower_setopponent\n',
                                                 'special CallBattleTowerFunc'),
        }
        for name, (required, forbidden) in expected.items():
            with self.subTest(map=name):
                generated = render_map(name)
                self.assertIn(required, generated)
                self.assertNotIn(forbidden, generated)

    def test_devon_text_placeholders_match_their_calling_context_and_us_labels(self):
        cases = {
            'RustboroCity_DevonCorp_2F': {
                'HandedFossilToResearcher': ['{PLAYER}', '{STR_VAR_1}'],
                'FossilizedMonBroughtBackToLife': ['{STR_VAR_2}'],
                'ReceivedMonFromResearcher': ['{PLAYER}', '{STR_VAR_2}'],
            },
            'RustboroCity_DevonCorp_3F': {
                'ReceivedPokenav': ['{PLAYER}'],
                'MrStoneGoWithCautionAndCare': ['{PLAYER}', '{KUN}'],
            },
        }
        for name, labels in cases.items():
            generated = render_map(name)
            reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
            for suffix, expected in labels.items():
                label = name + '_Text_' + suffix
                pattern = (r'^' + re.escape(label)
                           + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)')
                for tag, source in (('JP generated', generated), ('US reference', reference)):
                    with self.subTest(map=name, label=label, source=tag):
                        block = re.search(pattern, source, re.M | re.S)
                        self.assertIsNotNone(block)
                        strings = '\n'.join(line for line in block.group(1).splitlines()
                                            if line.lstrip().startswith('.string'))
                        self.assertEqual(re.findall(r'\{[^}]+\}', strings), expected)

    def test_reviewed_trade_regeneration_uses_current_special_wait_policy(self):
        for name in ('RustboroCity_House1', 'FortreeCity_House1'):
            with self.subTest(map=name):
                generated = render_map(name)
                self.assertNotIn('ChoosePartyMon requires explicit waitstate', generated)
                self.assertIn('\tspecial ChoosePartyMon\n'
                              '\tcopyvar VAR_0x800A, VAR_0x8004\n', generated)
        for root in (ROOT, emitter.US_MAPS.parents[1]):
            with self.subTest(root=root):
                specials = (root / 'data' / 'specials.inc').read_text(encoding='utf-8')
                self.assertRegex(specials,
                                 r'(?m)^\s*def_special ChoosePartyMon, waitstate=1\s*$')

    def test_motel_tv_push_retains_parallel_movements_during_regeneration(self):
        name = 'LilycoveCity_CoveLilyMotel_1F'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        parallel = (
            '\tapplymovement LOCALID_PLAYER, '
            + name + '_Movement_PlayerPushFromTV\n'
            '\tapplymovement LOCALID_MOTEL_OWNER, '
            + name + '_Movement_OwnerPushPlayer\n'
            '\twaitmovement 0\n')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertEqual(source.count(parallel), 1)
                self.assertEqual(source.count('\tapplywaitmovement '), 10)

    def test_motel_scott_retains_jp_placeholder_repetition(self):
        name = 'LilycoveCity_CoveLilyMotel_2F'
        label = name + '_Text_SnoozingPreferBattles'
        pattern = (r'^' + re.escape(label)
                   + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)')
        jp_expected = ['{PLAYER}', '{KUN}', '{PLAYER}', '{KUN}']
        cases = (
            ('JP source', (ROOT / 'data' / 'maps' / name / 'scripts.inc').read_text(
                encoding='utf-8'), jp_expected),
            ('JP generated', render_map(name), jp_expected),
            ('US reference', (emitter.US_MAPS / name / 'scripts.inc').read_text(
                encoding='utf-8'), ['{PLAYER}', '{KUN}']),
        )
        for tag, source, expected in cases:
            with self.subTest(source=tag):
                block = re.search(pattern, source, re.M | re.S)
                self.assertIsNotNone(block)
                strings = '\n'.join(line for line in block.group(1).splitlines()
                                    if line.lstrip().startswith('.string'))
                self.assertEqual(re.findall(r'\{[^}]+\}', strings), expected)

    def test_museum_regeneration_retains_parallel_and_scheduled_movements(self):
        first = 'LilycoveCity_LilycoveMuseum_1F'
        second = 'LilycoveCity_LilycoveMuseum_2F'
        generated_first = render_map(first)
        generated_second = render_map(second)
        self.assertEqual(generated_first.count('\tapplywaitmovement '), 5)
        self.assertEqual(generated_second.count('\tapplywaitmovement '), 5)
        self.assertIn(
            '\tapplymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer\n'
            '\tmessage ' + first + '_Text_ImCuratorHaveYouViewedOurPaintings\n',
            generated_first)
        self.assertIn(
            '\tapplymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer\n'
            '\tapplymovement LOCALID_PLAYER, '
            + second + '_Movement_PlayerWalkInPlaceLeft\n\twaitmovement 0\n',
            generated_second)
        for movement, text in (
            (second + '_Movement_FaceExhibitHall', '_Text_PaintingsAttractedMoreGuests'),
            ('Common_Movement_FacePlayer', '_Text_TokenOfGratitude'),
        ):
            with self.subTest(movement=movement, text=text):
                self.assertIn(
                    '\tapplymovement LOCALID_MUSEUM_2F_CURATOR, ' + movement
                    + '\n\tmsgbox ' + second + text + ', MSGBOX_DEFAULT\n',
                    generated_second)

    def test_museum_regeneration_retains_rom_state_copy_without_importing_bugfix(self):
        name = 'LilycoveCity_LilycoveMuseum_2F'
        checked_in = (ROOT / 'data' / 'maps' / name / 'scripts.inc').read_text(
            encoding='utf-8')
        for tag, source in (('JP source', checked_in), ('JP generated', render_map(name))):
            with self.subTest(source=tag):
                self.assertIn('\tcopyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE\n',
                              source)
                self.assertNotIn('\tsetvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1\n', source)

    def test_contest_lobby_regeneration_retains_parallel_and_object_specific_waits(self):
        name = 'LilycoveCity_ContestLobby'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertEqual(source.count('\tapplywaitmovement '), 21)
                for prefix in ('', 'LINK_'):
                    artist = 'LOCALID_CONTEST_LOBBY_' + prefix + 'ARTIST'
                    movement = 'LinkArtist' if prefix else 'Artist'
                    self.assertIn(
                        '\tapplymovement ' + artist + ', ' + name
                        + '_Movement_' + movement + 'ApproachPlayer\n'
                        '\twaitmovement ' + artist + '\n', source)
                    receptionist = 'LOCALID_CONTEST_LOBBY_' + prefix + 'RECEPTIONIST'
                    movement = 'LinkReceptionist' if prefix else 'Receptionist'
                    player_movement = 'PlayerWalkToLinkContestHall' if prefix else (
                        'PlayerWalkToContestHall')
                    self.assertIn(
                        '\tapplymovement ' + receptionist + ', ' + name
                        + '_Movement_' + movement + 'WalkToContestHall\n'
                        '\tapplymovement LOCALID_PLAYER, ' + name + '_Movement_'
                        + player_movement + '\n\twaitmovement 0\n', source)

    def test_contest_lobby_regeneration_retains_debug_copy_and_link_wait_contracts(self):
        name = 'LilycoveCity_ContestLobby'
        generated = render_map(name)
        self.assertIn('\tcopyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE\n',
                      generated)
        self.assertNotIn('\tsetvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1\n', generated)
        specials = (ROOT / 'data' / 'specials.inc').read_text(encoding='utf-8')
        for special in ('TryContestEModeLinkup', 'TryContestGModeLinkup',
                        'TryBecomeLinkLeader', 'TryJoinLinkGroup'):
            with self.subTest(special=special):
                self.assertRegex(specials,
                                 r'(?m)^\s*def_special ' + special + r', waitstate=1\s*$')
                self.assertIn('\tspecial ' + special + '\n\treturn\n', generated)
        for command in ('choosecontestmon', 'contestlinktransfer'):
            with self.subTest(command=command):
                self.assertIn('\t' + command + '\n', generated)
                self.assertNotIn('\t' + command + '\n\twaitstate\n', generated)

    def test_contest_hall_regeneration_retains_cute_audience_dialogue_order(self):
        name = 'LilycoveCity_ContestHall'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        sequence = (
            '\tapplywaitmovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer\n'
            '\tmsgbox ' + name + '_Text_MyChildIsInContest, MSGBOX_DEFAULT\n'
            '\tclosemessage\n'
            '\tapplywaitmovement LOCALID_CUTE_AUDIENCE_1, '
            'Common_Movement_FaceOriginalDirection\n'
            '\tdelay 25\n'
            '\tmsgbox ' + name + '_Text_ComeOnDear, MSGBOX_DEFAULT\n')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertEqual(source.count('\tapplywaitmovement '), 28)
                self.assertIn(sequence, source)

    def test_contest_lobby_placeholders_match_artist_and_link_entry_buffers(self):
        name = 'LilycoveCity_ContestLobby'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        link_number = (
            '\tspecial GetContestPlayerId\n\taddvar VAR_0x8004, 1\n'
            '\tbuffernumberstring STR_VAR_2, VAR_0x8004\n'
            '\tmessageautoscroll ' + name + '_Text_YourMonIsEntryNumX\n')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertIn(link_number, source)
                label = name + '_Text_PutTheRibbonOnMon'
                block = re.search(r'^' + re.escape(label)
                                  + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)',
                                  source, re.M | re.S)
                self.assertIsNotNone(block)
                strings = '\n'.join(line for line in block.group(1).splitlines()
                                    if line.lstrip().startswith('.string'))
                self.assertEqual(re.findall(r'\{[^}]+\}', strings),
                                 ['{PLAYER}', '{STR_VAR_1}'])
        for root in (ROOT, emitter.US_MAPS.parents[1]):
            with self.subTest(root=root):
                shared = (root / 'data' / 'scripts' / 'contest_hall.inc').read_text(
                    encoding='utf-8')
                label = name + '_Text_YourMonIsEntryNumX'
                block = re.search(r'^' + re.escape(label)
                                  + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)',
                                  shared, re.M | re.S)
                self.assertIsNotNone(block)
                strings = '\n'.join(line for line in block.group(1).splitlines()
                                    if line.lstrip().startswith('.string'))
                self.assertEqual(re.findall(r'\{[^}]+\}', strings), ['{STR_VAR_2}'])
    def test_fan_club_regeneration_retains_first_fans_parallel_movement(self):
        name = 'LilycoveCity_PokemonTrainerFanClub'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        parallel = (
            '\tapplymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, ' + name
            + '_Movement_LittleGirlWatchPlayer\n'
            '\tapplymovement LOCALID_TRAINER_FAN_CLUB_MAN, ' + name
            + '_Movement_FanApproachPlayer\n\twaitmovement 0\n')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertEqual(source.count('\tapplywaitmovement '), 5)
                self.assertEqual(source.count(parallel), 1)
                self.assertIn(
                    '\tapplywaitmovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, '
                    + name + '_Movement_LittleGirlHideFromPlayer\n'
                    '\tsetvar VAR_LILYCOVE_FAN_CLUB_STATE, 2\n', source)

    def test_fan_club_regeneration_retains_fan_count_and_interview_wait_contract(self):
        name = 'LilycoveCity_PokemonTrainerFanClub'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        label = name + '_EventScript_CheckSetUpTVShow'
        pattern = (r'^' + re.escape(label)
                   + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                block = re.search(pattern, source, re.M | re.S)
                self.assertIsNotNone(block)
                self.assertIn('\tsetvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS\n',
                              block.group(1))
                self.assertEqual(
                    re.findall(r'\tsetvar VAR_0x8004, FANCLUB_MEMBER([1-8])\n',
                               block.group(1)), list('12345678'))
                self.assertEqual(block.group(1).count(
                    '\tcall_if_eq VAR_RESULT, FALSE, ' + name
                    + '_EventScript_CountNotPlayersFan\n'), 8)
                self.assertIn('\tgoto_if_ge VAR_0x8005, 5, ' + name
                              + '_EventScript_TrySetUpTVShow\n', block.group(1))
                self.assertIn(
                    '\tspecial ShowScrollableMultichoice\n'
                    '\tsetvar VAR_0x8004, FANCLUB_MEMBER1\n\tswitch VAR_RESULT\n',
                    source)
                self.assertNotIn(
                    '\tspecial ShowScrollableMultichoice\n\twaitstate\n', source)
        specials = (ROOT / 'data' / 'specials.inc').read_text(encoding='utf-8')
        self.assertRegex(specials,
                         r'(?m)^\s*def_special ShowScrollableMultichoice, waitstate=1\s*$')

    def test_fan_club_placeholders_follow_player_and_trainer_buffers(self):
        name = 'LilycoveCity_PokemonTrainerFanClub'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        expected = {
            'OhWowItsPlayer': ['{PLAYER}'],
            'TrainersPowerIsOutOfTheOrdinary': ['{STR_VAR_1}'],
            'NeverGoingToStopBeingTrainersFan': ['{STR_VAR_1}', '{STR_VAR_1}'],
        }
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertIn(
                    '\tsetvar VAR_0x8004, FANCLUB_MEMBER1\n'
                    '\tspecial BufferFanClubTrainerName\n\tmsgbox ' + name
                    + '_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT\n', source)
                for suffix, placeholders in expected.items():
                    with self.subTest(text=suffix):
                        label = name + '_Text_' + suffix
                        block = re.search(
                            r'^' + re.escape(label)
                            + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)',
                            source, re.M | re.S)
                        self.assertIsNotNone(block)
                        strings = '\n'.join(line for line in block.group(1).splitlines()
                                            if line.lstrip().startswith('.string'))
                        self.assertEqual(re.findall(r'\{[^}]+\}', strings), placeholders)
    def test_harbor_regeneration_retains_both_parallel_boarding_sequences(self):
        name = 'LilycoveCity_Harbor'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertEqual(source.count('\tapplywaitmovement '), 17)
                for direction in ('North', 'East'):
                    with self.subTest(direction=direction):
                        parallel = (
                            '\tapplymovement LOCALID_LILYCOVE_HARBOR_BRINEY, '
                            + name + '_Movement_BrineyBoardFerry\n'
                            '\tapplymovement LOCALID_PLAYER, ' + name
                            + '_Movement_PlayerBoardWithBriney' + direction + '\n'
                            '\tapplymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, '
                            + name + '_Movement_SailorBoardWithBriney' + direction
                            + '\n\twaitmovement 0\n\treturn\n')
                        self.assertEqual(source.count(parallel), 1)

    def test_harbor_regeneration_retains_ticket_priority_bits_and_menu_wait(self):
        name = 'LilycoveCity_Harbor'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        priority = (
            '\tgoto_if_eq VAR_TEMP_C, 2, ' + name + '_EventScript_OldSeaMapFirstTime\n'
            '\tgoto_if_eq VAR_TEMP_B, 1, ' + name + '_EventScript_EonTicketFirstTime\n'
            '\tgoto_if_eq VAR_TEMP_B, 2, ' + name + '_EventScript_AuroraTicketFirstTime\n'
            '\tgoto_if_eq VAR_TEMP_B, 4, ' + name + '_EventScript_OldSeaMapFirstTime\n'
            '\tgoto_if_eq VAR_TEMP_B, 8, ' + name + '_EventScript_MysticTicketFirstTime\n')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertIn(priority, source)
                for temporary, ticket, bit in (('E', 'EonTicket', 1),
                                               ('D', 'AuroraTicket', 2),
                                               ('C', 'OldSeaMap', 4),
                                               ('9', 'MysticTicket', 8)):
                    with self.subTest(ticket=ticket):
                        self.assertIn('\tcall_if_eq VAR_TEMP_' + temporary + ', 2, '
                                      + name + '_EventScript_SetFirstTimeShowing'
                                      + ticket + '\n', source)
                        self.assertIn('\tcall_if_eq VAR_TEMP_' + temporary + ', 1, '
                                      + name + '_EventScript_SetHas' + ticket + '\n',
                                      source)
                        self.assertEqual(source.count('\taddvar VAR_TEMP_B, '
                                                      + str(bit) + '\n'), 1)
                        self.assertEqual(source.count('\taddvar VAR_TEMP_A, '
                                                      + str(bit) + '\n'), 1)
                for menu_mode in (0, 1):
                    self.assertIn(
                        '\tsetvar VAR_0x8004, ' + str(menu_mode) + '\n'
                        '\tspecial ScriptMenu_CreateLilycoveSSTidalMultichoice\n'
                        '\tspecial GetLilycoveSSTidalSelection\n\tswitch VAR_RESULT\n',
                        source)
                self.assertNotIn(
                    '\tspecial ScriptMenu_CreateLilycoveSSTidalMultichoice\n'
                    '\twaitstate\n', source)
        specials = (ROOT / 'data' / 'specials.inc').read_text(encoding='utf-8')
        self.assertRegex(specials,
                         r'(?m)^\s*def_special ScriptMenu_CreateLilycoveSSTidalMultichoice, '
                         r'waitstate=1\s*$')
        self.assertRegex(specials,
                         r'(?m)^\s*def_special GetLilycoveSSTidalSelection\s*$')

    def test_harbor_ticket_placeholders_retain_original_jp_text_controls(self):
        name = 'LilycoveCity_Harbor'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                for suffix in ('NoTicket', 'FlashTicketWhereTo'):
                    label = name + '_Text_' + suffix
                    block = re.search(
                        r'^' + re.escape(label)
                        + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)',
                        source, re.M | re.S)
                    self.assertIsNotNone(block)
                    self.assertEqual(re.findall(r'\{[^}]+\}', block.group(1)),
                                     ['{PLAYER}'])
                    if tag == 'JP generated':
                        self.assertIn('\t.string "{PLAYER}は\\n"\n', block.group(1))
                        self.assertEqual(block.group(1).count('\\p'), 2)
    def test_lilycove_interior_regeneration_retains_npc_facing_helpers(self):
        for name, count in (('LilycoveCity_MoveDeletersHouse', 1),
                            ('LilycoveCity_House3', 3)):
            generated = render_map(name)
            reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(
                encoding='utf-8')
            for tag, source in (('JP generated', generated), ('US reference', reference)):
                with self.subTest(map=name, source=tag):
                    self.assertEqual(source.count('\tapplywaitmovement '), count)
                    if name.endswith('House3'):
                        self.assertEqual(source.count(
                            '\tclosemessage\n'
                            '\tapplywaitmovement VAR_LAST_TALKED, '
                            'Common_Movement_FaceOriginalDirection\n'
                            '\trelease\n\tend\n'), 3)
                    else:
                        self.assertIn(
                            '\tlockall\n\tapplywaitmovement LOCALID_MOVE_DELETER, '
                            'Common_Movement_FacePlayer\n\tmsgbox ', source)

    def test_move_deleter_regeneration_retains_selection_guards_and_wait_contract(self):
        name = 'LilycoveCity_MoveDeletersHouse'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        guards = (
            '\tspecial ChoosePartyMon\n'
            '\tgoto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, '
            + name + '_EventScript_ComeAgain\n'
            '\tspecial IsSelectedMonEgg\n\tgoto_if_eq VAR_RESULT, TRUE, '
            + name + '_EventScript_EggCantForgetMoves\n'
            '\tspecial GetNumMovesSelectedMonHas\n\tgoto_if_eq VAR_RESULT, 1, '
            + name + '_EventScript_MonOnlyKnowsOneMove\n')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertIn(guards, source)
                self.assertIn(
                    '\tfadescreen FADE_TO_BLACK\n'
                    '\tspecial MoveDeleterChooseMoveToForget\n'
                    '\tfadescreen FADE_FROM_BLACK\n'
                    '\tgoto_if_eq VAR_0x8005, MAX_MON_MOVES, '
                    + name + '_EventScript_ChooseMonAndMoveToForget\n', source)
                self.assertIn(
                    '\tspecial IsLastMonThatKnowsSurf\n'
                    '\tgoto_if_eq VAR_RESULT, TRUE, '
                    + name + '_EventScript_LastMonWithSurf\n'
                    '\tspecial MoveDeleterForgetMove\n', source)
                self.assertNotIn('\tspecial ChoosePartyMon\n\twaitstate\n', source)
                for suffix in ('MonsMoveShouldBeForgotten', 'MonHasForgottenMove'):
                    label = name + '_Text_' + suffix
                    block = re.search(
                        r'^' + re.escape(label)
                        + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)',
                        source, re.M | re.S)
                    self.assertIsNotNone(block)
                    self.assertEqual(re.findall(r'\{[^}]+\}', block.group(1)),
                                     ['{STR_VAR_1}', '{STR_VAR_2}'])
        specials = (ROOT / 'data' / 'specials.inc').read_text(encoding='utf-8')
        self.assertRegex(specials,
                         r'(?m)^\s*def_special ChoosePartyMon, waitstate=1\s*$')
        self.assertRegex(specials,
                         r'(?m)^\s*def_special MoveDeleterChooseMoveToForget\s*$')

    def test_residential_regeneration_retains_shared_activity_and_rest_gift(self):
        activity = 'LilycoveCity_House3'
        rest = 'LilycoveCity_House2'
        for name in (activity, rest):
            generated = render_map(name)
            reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(
                encoding='utf-8')
            for tag, source in (('JP generated', generated), ('US reference', reference)):
                with self.subTest(map=name, source=tag):
                    if name == activity:
                        self.assertEqual(source.count(
                            '\trandom 4\n\tcopyvar VAR_TEMP_1, VAR_RESULT\n'), 1)
                        self.assertEqual(source.count('\tswitch VAR_TEMP_1\n'), 4)
                        for value, suffix in enumerate(('WereDoingMultiBattle',
                                                        'WereMixingRecords',
                                                        'WereBlendingBerries',
                                                        'WereDoingContest')):
                            self.assertEqual(source.count('\tcase ' + str(value) + ', '
                                                          + activity + '_EventScript_'
                                                          + suffix + '\n'), 4)
                    else:
                        self.assertIn(
                            '\tgiveitem ITEM_TM_REST\n'
                            '\tgoto_if_eq VAR_RESULT, FALSE, '
                            'Common_EventScript_ShowBagIsFull\n'
                            '\tsetflag FLAG_RECEIVED_TM_REST\n', source)


    def test_department_store_regeneration_retains_sequential_movement_helpers(self):
        for name, count in (('LilycoveCity_DepartmentStore_1F', 2),
                            ('LilycoveCity_DepartmentStore_5F', 2),
                            ('LilycoveCity_DepartmentStoreElevator', 1)):
            generated = render_map(name)
            reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(
                encoding='utf-8')
            for tag, source in (('JP generated', generated), ('US reference', reference)):
                with self.subTest(map=name, source=tag):
                    self.assertEqual(source.count('\tapplywaitmovement '), count)
                    self.assertNotIn('\tapplymovement ', source)
                    self.assertNotIn('\twaitmovement ', source)

    def test_lottery_regeneration_retains_pending_prize_and_daily_ticket_guards(self):
        name = 'LilycoveCity_DepartmentStore_1F'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertIn(
                    '\tdotimebasedevents\n'
                    '\tgoto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, '
                    + name + '_EventScript_GivePrizeFromEarlier\n'
                    '\tgoto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, '
                    + name + '_EventScript_ComeBackTomorrow\n', source)
                self.assertIn(
                    '\tgiveitem VAR_0x8005\n'
                    '\tgoto_if_eq VAR_RESULT, FALSE, '
                    + name + '_EventScript_RecordPrizeNoRoom\n'
                    '\tspecial TryPutLotteryWinnerReportOnAir\n', source)
                self.assertIn(
                    '\tcopyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004\n'
                    '\tcopyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005\n'
                    '\tgoto ' + name + '_EventScript_NoRoomForPrize\n', source)
                self.assertIn(
                    '\tgiveitem VAR_POKELOT_PRIZE_ITEM\n'
                    '\tgoto_if_eq VAR_RESULT, FALSE, '
                    + name + '_EventScript_NoRoomForPrize\n'
                    '\tcopyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE\n'
                    '\tcopyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM\n'
                    '\tspecial TryPutLotteryWinnerReportOnAir\n'
                    '\tsetvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE\n'
                    '\tsetvar VAR_POKELOT_PRIZE_PLACE, 0\n', source)
                for value, suffix in enumerate(('TwoDigitMatch', 'ThreeDigitMatch',
                                                'FourDigitMatch', 'FullMatch'), 1):
                    self.assertIn('\tcall_if_eq VAR_0x8004, ' + str(value) + ', '
                                  + name + '_EventScript_' + suffix + '\n', source)
                self.assertNotRegex(source,
                                    r'(?m)^' + name + r'_Text_LotteryCornerDrawTicket:')

    def test_department_store_fifth_floor_retains_legendary_weather_gate(self):
        name = 'LilycoveCity_DepartmentStore_5F'
        for tag, source in (
                ('JP generated', render_map(name)),
                ('US reference', (emitter.US_MAPS / name / 'scripts.inc').read_text(
                    encoding='utf-8'))):
            with self.subTest(source=tag):
                for value in (1, 2, 3):
                    self.assertIn('\tmap_script_2 VAR_SOOTOPOLIS_CITY_STATE, '
                                  + str(value) + ', ' + name
                                  + '_EventScript_BlockRoofStairs\n', source)
                self.assertIn(
                    '\tsetobjectxy LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, 16, 2\n'
                    '\tturnobject LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, DIR_NORTH\n',
                    source)
                self.assertIn(
                    '\tgoto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, '
                    + name + '_EventScript_WomanNormal\n'
                    '\tgoto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, '
                    + name + '_EventScript_WomanNormal\n', source)


    def test_rooftop_regeneration_retains_drink_dispatch_payment_and_bonus(self):
        name = 'LilycoveCity_DepartmentStoreRooftop'
        for tag, source in (
                ('JP generated', render_map(name)),
                ('US reference', (emitter.US_MAPS / name / 'scripts.inc').read_text(
                    encoding='utf-8'))):
            with self.subTest(source=tag):
                self.assertIn('\tcopyvar VAR_TEMP_1, VAR_RESULT\n'
                              '\tswitch VAR_TEMP_1\n', source)
                for value, drink in enumerate(('FreshWater', 'SodaPop', 'Lemonade')):
                    self.assertIn('\tcase ' + str(value) + ', ' + name
                                  + '_EventScript_' + drink + '\n', source)
                    price = (200, 300, 350)[value]
                    for command in ('checkmoney', 'removemoney'):
                        self.assertEqual(source.count('\t' + command + ' '
                                                      + str(price) + '\n'), 1)
                self.assertLess(source.index('\tcheckitemspace VAR_TEMP_0\n'),
                                source.index('\tcall_if_eq VAR_TEMP_1, 0, '
                                             + name + '_EventScript_RemoveMoneyFreshWater\n'))
                self.assertEqual(len(re.findall(r'^\s*random 64\b', source, re.M)), 2)
                self.assertEqual(source.count('\tadditem VAR_TEMP_0\n'), 3)
                self.assertEqual(source.count('\tbufferitemname STR_VAR_2, VAR_TEMP_0\n'), 3)
                self.assertIn('\thidemoneybox\n\treleaseall\n\tend\n', source)
                for suffix in ('CanOfDrinkDroppedDown', 'ExtraCanOfDrinkDroppedDown'):
                    block = re.search(
                        r'^' + name + '_Text_' + suffix
                        + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)',
                        source, re.M | re.S)
                    self.assertIsNotNone(block)
                    self.assertEqual(re.findall(r'\{[^}]+\}', block.group(1)),
                                     ['{STR_VAR_1}'])
                    if tag == 'JP generated':
                        self.assertEqual(block.group(1).count('\\p'), 1)
                        self.assertEqual(block.group(1).count('\\n'),
                                         int(suffix.startswith('Extra')))

    def test_elevator_regeneration_retains_default_cursor_cancel_and_floor_warps(self):
        name = 'LilycoveCity_DepartmentStoreElevator'
        for tag, source in (
                ('JP generated', render_map(name)),
                ('US reference', (emitter.US_MAPS / name / 'scripts.inc').read_text(
                    encoding='utf-8'))):
            with self.subTest(source=tag):
                self.assertEqual(source.count('\tswitch VAR_RESULT\n'), 2)
                for value, floor in enumerate(('5th', '4th', '3rd', '2nd', '1st')):
                    self.assertIn('\tcase ' + str(value) + ', ' + name
                                  + '_EventScript_ChooseFloorFrom' + floor + '\n', source)
                    block = re.search(
                        r'^' + name + '_EventScript_ChooseFloorFrom' + floor
                        + r':{1,2}[^\n]*\n(.*?)(?=^\w+:{1,2}|\Z)',
                        source, re.M | re.S)
                    self.assertIsNotNone(block)
                    # JP keeps equivalent hexadecimal literals in this menu.
                    match = re.search(r'^\s*multichoicedefault (.*)$', block.group(1), re.M)
                    self.assertIsNotNone(match)
                    arguments = [part.strip() for part in match.group(1).split(',')]
                    self.assertEqual([int(arguments[index], 0) for index in (0, 1, 3)],
                                     [0, 0, value])
                    self.assertEqual(arguments[2], 'MULTI_FLOORS')
                    self.assertEqual(arguments[4], 'FALSE')
                for value in ('5', 'MULTI_B_PRESSED'):
                    self.assertIn('\tcase ' + value + ', ' + name
                                  + '_EventScript_ExitFloorSelect\n', source)
                for floor in range(1, 6):
                    self.assertRegex(source, r'\tsetdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_'
                                     + str(floor) + r'F, (?:0x)?2, (?:0x)?1\n')
                    self.assertIn('\tgoto_if_eq VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_'
                                  + str(floor) + 'F, ' + name
                                  + '_EventScript_ExitFloorSelect\n', source)
                self.assertIn('\tcall_if_unset FLAG_TEMP_2, ' + name
                              + '_EventScript_SetFloor\n', source)
                self.assertIn('\tspecial MoveElevator\n\tsetflag FLAG_TEMP_2\n', source)
                self.assertNotIn('\tspecial MoveElevator\n\twaitstate\n', source)
        specials = (ROOT / 'data' / 'specials.inc').read_text(encoding='utf-8')
        self.assertRegex(specials, r'(?m)^\s*def_special MoveElevator, waitstate=1\s*$')

    def test_department_store_json_retains_rom_proven_jp_npc_movement(self):
        names = tuple('LilycoveCity_DepartmentStore_' + str(floor) + 'F'
                      for floor in range(1, 6)) + (
                          'LilycoveCity_DepartmentStoreRooftop',
                          'LilycoveCity_DepartmentStoreElevator')
        for name in names:
            actual = json.loads((ROOT / 'data/maps' / name / 'map.json').read_text(
                encoding='utf-8'))
            reference = json.loads((emitter.US_MAPS / name / 'map.json').read_text(
                encoding='utf-8'))
            with self.subTest(map=name):
                if name.endswith('_1F'):
                    npc = actual['object_events'][4]
                    self.assertEqual(npc['script'], name + '_EventScript_PokefanM')
                    self.assertEqual(npc['movement_type'], 'MOVEMENT_TYPE_WANDER_AROUND')
                    self.assertEqual(reference['object_events'][4]['movement_type'],
                                     'MOVEMENT_TYPE_LOOK_AROUND')
                    # JP Object 5: 24-byte object record, movement byte at +9.
                    self.assertEqual(emitter.ROM[0x50A821], 2)
                    npc['movement_type'] = 'MOVEMENT_TYPE_LOOK_AROUND'
                self.assertEqual(actual, reference)


    def test_mossdeep_gym_regeneration_retains_unused_switch_movement_helpers(self):
        name = 'MossdeepCity_Gym'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        for tag, source in (('JP generated', generated), ('US reference', reference)):
            with self.subTest(source=tag):
                self.assertEqual(source.count(
                    '\tapplywaitmovement LOCALID_PLAYER, '
                    + name + '_Movement_WaitAfterSwitchUse\n'), 8)
                self.assertNotIn('\tapplymovement ', source)
                self.assertRegex(source, name + '_Movement_WaitAfterSwitchUse:'
                                 r'[^\n]*\n\tdelay_16\n\tdelay_16\n\tstep_end\n')
                for number in range(1, 5):
                    flag = 'FLAG_MOSSDEEP_GYM_SWITCH_' + str(number)
                    self.assertEqual(source.count('\tsetflag ' + flag + '\n'), 1)
                    self.assertEqual(source.count('\tclearflag ' + flag + '\n'), 1)
        self.assertEqual(emitter.ROM[0x20B799:0x20B79C], bytes((0x14, 0x14, 0xFE)))

    def test_mossdeep_gym_regeneration_retains_explicit_rotating_tile_waits(self):
        name = 'MossdeepCity_Gym'
        generated = render_map(name)
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        for number, color in enumerate(('Yellow', 'Blue', 'Green', 'Purple', 'Red')):
            label = name + '_EventScript_' + color + 'FloorSwitch'
            for tag, source in (('JP generated', generated), ('US reference', reference)):
                with self.subTest(color=color, source=tag):
                    match = re.search(r'^' + label + r':{1,2}[^\n]*\n(.*?)'
                                      r'(?=^\w+:{1,2}|\Z)', source, re.M | re.S)
                    self.assertIsNotNone(match)
                    block = match.group(1)
                    block = re.sub(r'\b0x([0-9A-Fa-f]+)\b',
                                   lambda m: str(int(m.group(1), 16)), block)
                    wait = '\twaitmovement 0\n' if tag == 'JP generated' else ''
                    self.assertEqual(block.strip(), (
                        '\tplayse SE_SWITCH\n\twaitse\n\tplayse SE_REPEL\n'
                        '\tinitrotatingtilepuzzle FALSE\n'
                        '\tmoverotatingtileobjects ' + str(number) + '\n'
                        + wait + '\tturnrotatingtileobjects\n' + wait
                        + '\tfreerotatingtilepuzzle\n\tend').strip())
        self.assertEqual(generated.count('\twaitmovement 0\n'), 10)
        # Unlike upstream, current JP primitive macros do not emit waits.
        # Keep the source waits until the entire macro/caller contract migrates.
        for tag, path in (
                ('JP', ROOT / 'asm/macros/event.inc'),
                ('US', emitter.US_MAPS.parents[1] / 'asm/macros/event.inc')):
            macros = path.read_text(encoding='utf-8')
            for command in ('moverotatingtileobjects', 'turnrotatingtileobjects'):
                with self.subTest(source=tag, macro=command):
                    body = re.search(r'^\s*\.macro ' + command + r'[^\n]*\n'
                                     r'(.*?)^\s*\.endm', macros, re.M | re.S)
                    self.assertIsNotNone(body)
                    self.assertEqual(len(re.findall(r'^\s*waitmovement\b',
                                                    body.group(1), re.M)),
                                     int(tag == 'US'))

    def test_mossdeep_gym_regeneration_retains_jp_text_and_label_boundaries(self):
        name = 'MossdeepCity_Gym'
        generated = render_map(name)
        checked = (ROOT / 'data/maps' / name / 'scripts.inc').read_text(encoding='utf-8')
        reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(encoding='utf-8')
        label_pattern = r'^(\w+):{1,2}'
        self.assertEqual(re.findall(label_pattern, generated, re.M),
                         re.findall(label_pattern, reference, re.M))
        text_pattern = r'^(' + name + r'_Text_\w+):{1,2}[^\n]*\n(.*?)'
        text_pattern += r'(?=^\w+:{1,2}|\Z)'
        emitted_texts = re.findall(text_pattern, generated, re.M | re.S)
        checked_texts = re.findall(text_pattern, checked, re.M | re.S)
        self.assertEqual(len(emitted_texts), 52)
        self.assertEqual([(label, body.strip()) for label, body in emitted_texts],
                         [(label, body.strip()) for label, body in checked_texts])
        self.assertEqual(re.findall(r'\{[^}]+\}', ''.join(
            body for _, body in emitted_texts)), ['{PLAYER}'] * 3)
        self.assertIn('フウ“へへへ', generated)
        self.assertNotIn('{STRING ', generated)
        self.assertNotIn('{ESCAPE ', generated)
        self.assertNotIn('.incbin', generated)
        self.assertNotIn('.set ', generated)


    def test_mossdeep_houses_regeneration_retains_sequential_movement_helpers(self):
        for name, count in (('MossdeepCity_House2', 2),
                            ('MossdeepCity_StevensHouse', 5)):
            for tag, source in (
                    ('JP generated', render_map(name)),
                    ('US reference', (emitter.US_MAPS / name / 'scripts.inc').read_text(
                        encoding='utf-8'))):
                with self.subTest(map=name, source=tag):
                    self.assertEqual(source.count('\tapplywaitmovement '), count)
                    self.assertNotIn('\tapplymovement ', source)
                    self.assertNotIn('\twaitmovement ', source)

    def test_mossdeep_wingull_regeneration_retains_mail_and_facing_routes(self):
        name = 'MossdeepCity_House2'
        for tag, source in (
                ('JP generated', render_map(name)),
                ('US reference', (emitter.US_MAPS / name / 'scripts.inc').read_text(
                    encoding='utf-8'))):
            with self.subTest(source=tag):
                self.assertIn('\tplaymoncry SPECIES_WINGULL, CRY_MODE_NORMAL\n'
                              '\tmsgbox ' + name + '_Text_Wingull, MSGBOX_DEFAULT\n'
                              '\twaitmoncry\n\tclosemessage\n'
                              '\tsetflag FLAG_WINGULL_DELIVERED_MAIL\n'
                              '\tclearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL\n',
                              source)
                for direction, suffix in (('NORTH', 'North'), ('WEST', 'West')):
                    self.assertIn('\tcall_if_eq VAR_FACING, DIR_' + direction
                                  + ', ' + name + '_EventScript_WingullExit' + suffix
                                  + '\n', source)
                self.assertIn('\tremoveobject LOCALID_MOSSDEEP_HOUSE_WINGULL\n'
                              '\trelease\n\tend\n', source)
                self.assertRegex(source, name + '_Movement_WingullExitNorth:'
                                 r'[^\n]*\n\twalk_fast_right\n\twalk_fast_down\n'
                                 r'\twalk_fast_down\n\twalk_fast_left\n'
                                 r'\twalk_fast_down\n\tdelay_8\n\tstep_end\n')
                self.assertRegex(source, name + '_Movement_WingullExitEast:'
                                 r'[^\n]*\n(?:\twalk_fast_down\n){3}'
                                 r'\tdelay_8\n\tstep_end\n')


    def test_stevens_house_regeneration_retains_dive_and_beldum_gift_paths(self):
        name = 'MossdeepCity_StevensHouse'
        for tag, source in (
                ('JP generated', render_map(name)),
                ('US reference', (emitter.US_MAPS / name / 'scripts.inc').read_text(
                    encoding='utf-8'))):
            source = re.sub(r'\b0x([0-9A-Fa-f]+)\b',
                            lambda m: str(int(m.group(1), 16)), source)
            with self.subTest(source=tag):
                self.assertIn('\tcall_if_unset FLAG_SYS_GAME_CLEAR, ' + name
                              + '_EventScript_HideStevensNote\n', source)
                self.assertIn('\tmap_script_2 VAR_STEVENS_HOUSE_STATE, 1, '
                              + name + '_EventScript_StevenGivesDive\n', source)
                self.assertIn('\tgiveitem ITEM_HM_DIVE\n'
                              '\tsetflag FLAG_RECEIVED_HM_DIVE\n'
                              '\tsetflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER\n', source)
                self.assertIn('\tsetflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT\n'
                              '\tsetflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT\n'
                              '\tsetvar VAR_STEVENS_HOUSE_STATE, 2\n', source)
                self.assertIn('\tsetvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM\n'
                              '\tgivemon SPECIES_BELDUM, 5\n'
                              '\tgoto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, ' + name
                              + '_EventScript_SendBeldumParty\n'
                              '\tgoto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, ' + name
                              + '_EventScript_SendBeldumPC\n'
                              '\tgoto Common_EventScript_NoMoreRoomForPokemon\n', source)
                self.assertIn('\tcall Common_EventScript_GetGiftMonPartySlot\n'
                              '\tcall Common_EventScript_NameReceivedPartyMon\n', source)
                self.assertIn('\tcall Common_EventScript_NameReceivedBoxMon\n', source)
                self.assertIn('\tsetflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL\n'
                              '\tsetflag FLAG_RECEIVED_BELDUM\n\treleaseall\n\tend\n',
                              source)
                # Retained RS gift and unused no-space text are real JP bytes.
                self.assertRegex(source, name + '_EventScript_DiveItemBall:'
                                 r':?[^\n]*\n\tfinditem ITEM_HM_DIVE\n'
                                 r'\tsetflag FLAG_RECEIVED_HM_DIVE\n\tend\n')
                self.assertRegex(source, r'(?m)^' + name + '_Text_NoSpaceForAnotherMon:')


    def test_mossdeep_interiors_regeneration_retains_labels_jp_text_and_json(self):
        family = (('House1', 4), ('House2', 3), ('PokemonCenter_1F', 2),
                  ('PokemonCenter_2F', 1), ('Mart', 3), ('House3', 5),
                  ('StevensHouse', 9), ('House4', 5))
        total_labels = total_texts = 0
        for suffix, count in family:
            name = 'MossdeepCity_' + suffix
            generated = render_map(name)
            checked = (ROOT / 'data/maps' / name / 'scripts.inc').read_text(
                encoding='utf-8')
            reference = (emitter.US_MAPS / name / 'scripts.inc').read_text(
                encoding='utf-8')
            with self.subTest(map=name):
                labels = re.findall(r'^(\w+):{1,2}', generated, re.M)
                self.assertEqual(labels, re.findall(r'^(\w+):{1,2}', reference, re.M))
                pattern = r'^(' + name + r'_Text_\w+):{1,2}[^\n]*\n(.*?)'
                pattern += r'(?=^\w+:{1,2}|\Z)'
                texts = re.findall(pattern, generated, re.M | re.S)
                self.assertEqual(len(texts), count)
                self.assertEqual([(label, body.strip()) for label, body in texts],
                                 [(label, body.strip()) for label, body in
                                  re.findall(pattern, checked, re.M | re.S)])
                self.assertNotIn('{STRING ', generated)
                self.assertNotIn('{ESCAPE ', generated)
                self.assertNotIn('.incbin', generated)
                self.assertNotIn('.set ', generated)
                actual_json = json.loads((ROOT / 'data/maps' / name / 'map.json').read_text(
                    encoding='utf-8'))
                reference_json = json.loads((emitter.US_MAPS / name / 'map.json').read_text(
                    encoding='utf-8'))
                self.assertEqual(actual_json, reference_json)
                total_labels += len(labels)
                total_texts += len(texts)
        self.assertEqual(total_labels, 91)
        self.assertEqual(total_texts, 32)


if __name__ == '__main__':
    unittest.main()
