"""Dewford's remaining interiors preserve JP battle, light and trend contracts."""
import json
from pathlib import Path
import struct
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
MAPS = ['DewfordTown_Gym', 'DewfordTown_Hall', 'DewfordTown_House2']
SIZES = [(83, 2561, 33), (63, 2176, 26), (9, 381, 4)]


def blocks(path):
    return review.label_blocks((ROOT / path).read_text())


def scene(name, suffix):
    return review.statements(blocks(f'data/maps/{name}/scripts.inc')[name + '_' + suffix])


class DewfordProfileTests(unittest.TestCase):
    def parse(self, source, version=4, owner='Entry'):
        return profile.profile_block(ROOT, owner + '::\n' + source, {}, version=version, address=0x081F2F0D)

    def test_flash_and_trainer_flag_forms_keep_their_measured_widths(self):
        forms = [('setflashlevel 0', 3), ('setflashlevel 8', 3),
                 ('animateflash 0', 2), ('animateflash 8', 2),
                 ('nop1', 1), ('settrainerflag TRAINER_TAKAO', 3)]
        for source, size in forms:
            with self.subTest(source=source):
                self.assertEqual(self.parse(source).size, size)
                with self.assertRaises(ValueError):
                    self.parse(source, version=3)
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms([source for source, _ in forms], version=4)

    def test_unreviewed_flash_ranges_variables_and_raw_trainer_ids_are_rejected(self):
        for source in ('setflashlevel', 'setflashlevel -1', 'setflashlevel 9',
                       'setflashlevel VAR_RESULT', 'setflashlevel 0, 1',
                       'animateflash -1', 'animateflash 9', 'animateflash 256',
                       'animateflash VAR_RESULT', 'nop1 1', 'settrainerflag 10',
                       'settrainerflag VAR_RESULT', 'settrainerflag TRAINER_TAKAO, 1'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)

    def test_no_music_is_a_mode_selector_not_a_fifth_pointer(self):
        source = 'trainerbattle_single TRAINER_BRAWLY_1, Intro, Defeat, After, NO_MUSIC\nend'
        p = self.parse(source)
        self.assertEqual(p.size, 19)
        self.assertEqual(p.texts, {'Intro': 'string', 'Defeat': 'string'})
        self.assertEqual(p.targets, {'EventScript_TryDoNormalTrainerBattle': 'script',
                                    'EventScript_StartTrainerApproach': 'script', 'After': 'script'})
        self.assertEqual(p.trainer_battles, [dict(owner='Entry', trainer='TRAINER_BRAWLY_1',
            mode='TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC', intro_text='Intro', defeat_text='Defeat',
            post_script='After', address='0x081F2F0D', resume='0x081F2F1F')])
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms([source.split('\n')[0]], version=4)

    def test_unreviewed_music_flags_and_missing_inline_continuations_fail_closed(self):
        prefix = 'trainerbattle_single TRAINER_BRAWLY_1, Intro, Defeat, After, '
        cases = [prefix + flag + '\nend' for flag in ('TRUE', 'FALSE', '0', '1', 'Music')]
        cases += [prefix + 'NO_MUSIC', prefix + 'NO_MUSIC, EXTRA\nend',
                  'trainerbattle_double TRAINER_BRAWLY_1, Intro, Defeat, TooFew, After, NO_MUSIC\nend']
        for source in cases:
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)
        with self.assertRaises(ValueError):
            self.parse(prefix + 'NO_MUSIC\nend', version=3)

    def test_the_seven_light_count_fallthroughs_are_explicit(self):
        selected = {name: target for name, target in profile.FALLTHROUGHS.items() if name.startswith(MAPS[0])}
        self.assertEqual(len(selected), 7)
        source = blocks('data/maps/DewfordTown_Gym/scripts.inc')
        for owner, following in selected.items():
            p = profile.profile_block(ROOT, source[owner], {}, version=4, address=0x081F2D87)
            self.assertTrue(p.may_fall_through)
            self.assertEqual(p.fallthrough, following)
            self.assertEqual(p.targets[following], 'script')


class DewfordStoryTests(unittest.TestCase):
    def test_darkness_tracks_six_trainers_but_brawly_forces_full_light(self):
        entry = scene(MAPS[0], 'EventScript_SetFlashLevel')
        self.assertEqual(entry[0], 'goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn')
        self.assertIn('copyvar VAR_0x8001, VAR_0x8000', entry)
        for defeated in range(6):
            self.assertIn(f'goto_if_eq VAR_0x8000, {defeated}, DewfordTown_Gym_EventScript_SetFlashLevel{7-defeated}', entry)
        self.assertEqual(entry[-1], 'goto DewfordTown_Gym_EventScript_SetFlashLevel1')
        self.assertEqual(scene(MAPS[0], 'EventScript_SetLightsOn'), ['setflashlevel 0', 'return'])
        brighten = scene(MAPS[0], 'EventScript_BrightenRoom')
        self.assertEqual(brighten[:3], ['call DewfordTown_Gym_EventScript_CountTrainersDefeated',
            'nop1', 'goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange'])

    def test_badge_story_and_tm_receipt_are_separate_success_gates(self):
        win = scene(MAPS[0], 'EventScript_BrawlyDefeated')
        for statement in ('setflag FLAG_DEFEATED_DEWFORD_GYM', 'setflag FLAG_BADGE02_GET',
                          'addvar VAR_PETALBURG_GYM_STATE, 1',
                          'call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle',
                          'setvar VAR_0x8008, 2', 'call Common_EventScript_SetGymTrainers',
                          'setflag FLAG_ENABLE_BRAWLY_MATCH_CALL'):
            self.assertIn(statement, win)
        for suffix, failure in [('EventScript_GiveBulkUp', 'Common_EventScript_BagIsFull'),
                                ('EventScript_GiveBulkUp2', 'Common_EventScript_ShowBagIsFull')]:
            give = scene(MAPS[0], suffix)
            self.assertEqual(give[:2], ['giveitem ITEM_TM_BULK_UP', f'goto_if_eq VAR_RESULT, 0, {failure}'])
            self.assertGreater(give.index('setflag FLAG_RECEIVED_TM_BULK_UP'), 1)

    def test_hall_buffers_the_current_trend_before_the_secondary_phrase(self):
        helper = review.statements(blocks('data/event_scripts.s')['Common_EventScript_BufferTrendyPhrase'])
        self.assertEqual(helper, ['dotimebasedevents', 'setvar VAR_0x8004, 0',
                                  'special BufferTrendyPhraseString', 'return'])
        man = scene(MAPS[1], 'EventScript_Man')
        self.assertLess(man.index('call Common_EventScript_BufferTrendyPhrase'), man.index('special BufferDeepLinkPhrase'))
        self.assertIn('msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO', man)
        girl = scene(MAPS[1], 'EventScript_Girl')
        self.assertIn('special IsTrendyPhraseBoring', girl)

    def test_painting_and_debate_use_the_exact_eight_way_jp_dispatch(self):
        painting = scene(MAPS[1], 'EventScript_Painting')
        suffixes = ['ScreamTitle', 'SmileTitle', 'LastTitle', 'BirthTitle',
                    'ScreamTitle', 'ScreamTitle', 'LastTitle', 'LastTitle']
        for value, suffix in enumerate(suffixes):
            self.assertIn(f'case {value}, DewfordTown_Hall_EventScript_{suffix}', painting)
        debate = scene(MAPS[1], 'EventScript_DoTrendDebate')
        for value, branch in enumerate((1, 1, 2, 2, 3, 3, 4, 5)):
            self.assertIn(f'case {value}, DewfordTown_Hall_EventScript_TrendDebate{branch}', debate)

    def test_gifts_set_flags_only_after_the_bag_success_branch(self):
        for name, suffix, item, flag in [(MAPS[1], 'EventScript_SludgeBombMan', 'TM_SLUDGE_BOMB', 'TM_SLUDGE_BOMB'),
                                          (MAPS[2], 'EventScript_Man', 'SILK_SCARF', 'SILK_SCARF')]:
            give = scene(name, suffix)
            at = give.index('giveitem ITEM_' + item)
            self.assertTrue(give[at + 1].startswith('goto_if_eq VAR_RESULT, FALSE, '))
            self.assertEqual(give[at + 2], 'setflag FLAG_RECEIVED_' + flag)


class DewfordNativeTests(unittest.TestCase):
    def family(self):
        rows = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        found = [row for row in rows if set(row['maps']) & set(MAPS)]
        self.assertEqual(len(found), 1)
        self.assertEqual(found[0]['maps'], MAPS)
        return found[0]

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_155_labels_and_63_texts_have_exact_native_boundaries(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for i, (name, expected) in enumerate(zip(MAPS, SIZES)):
            source = blocks(f'data/maps/{name}/scripts.inc')
            parts = profile.profile_owner(ROOT, ''.join(source.values()), version=4,
                address=next(iter(symbols[name + '_MapScripts'])))
            self.assertEqual((len(parts), sum(p.size for p in parts.values()),
                              sum(p.kind == 'string' for p in parts.values())), expected)
            labels = list(parts)
            for j, label in enumerate(labels):
                following = labels[j + 1] if j + 1 < len(labels) else (
                    MAPS[i + 1] if i + 1 < len(MAPS) else 'LavaridgeTown_HerbShop') + '_MapScripts'
                start, end = next(iter(symbols[label])), next(iter(symbols[following]))
                self.assertEqual(parts[label].size, end - start, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, source[label], 'string'),
                                     rom[start - 0x08000000:end - 0x08000000], label)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_no_music_header_has_two_text_pointers_and_one_post_script(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        trainer = review._literal_define(ROOT, 'include/constants/opponents.h', 'TRAINER_BRAWLY_1')
        expected = struct.pack('<BBHH', 0x5C, 1, trainer, 0)
        expected += b''.join(struct.pack('<I', next(iter(symbols['DewfordTown_Gym_' + label])))
            for label in ('Text_BrawlyIntro', 'Text_BrawlyDefeat', 'EventScript_BrawlyDefeated'))
        self.assertEqual(rom[0x1F2F0D:0x1F2F1F], expected)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_current_family_covers_eight_frames_without_claiming_new_c_conversion(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 8)
        self.assertEqual(batch['trainer_battles'][0]['mode'], 'TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC')
        self.assertEqual(batch['dynamic_layouts'], [])
        self.assertEqual(review._review_batch(ROOT, batch, set(MAPS), {})['status'], 'current')

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_complete_family_uses_real_native_macro_expansion(self):
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in self.family()['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertIn('nop1', forms)
        self.assertIn('setflashlevel 7', forms)
        self.assertTrue(any(line.endswith(', NO_MUSIC') for line in forms))
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
