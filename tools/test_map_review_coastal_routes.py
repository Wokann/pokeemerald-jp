"""Continuous coastal owners keep sailing, rewards and weather byte-exact."""
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
OWNERS = [('Route104', 119, 4208, 32), ('Route105', 16, 556, 2),
          ('Route106', 9, 225, 1), ('Route107', 10, 245, 0),
          ('Route108', 9, 214, 0), ('Route109', 62, 2003, 16)]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


class CoastalRouteTests(unittest.TestCase):
    def test_new_forms_are_explicit_and_use_real_native_macro_expansion(self):
        for source, size, kind in [('walk_faster_down\nstep_end', 2, 'movement'),
                                   ('fadescreenswapbuffers FADE_TO_BLACK', 2, 'script')]:
            p = profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E7400)
            self.assertEqual((p.size, p.kind), (size, kind))
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {})
        for source in ('walk_faster_down 2\nstep_end', 'walk_faster_down\nend',
                       'fadescreenswapbuffers', 'fadescreenswapbuffers 1, 2'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E7400)
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms(
                ['walk_faster_down', 'fadescreenswapbuffers FADE_TO_BLACK',
                 'fadescreenswapbuffers FADE_FROM_BLACK'], version=4)

    def test_optional_dad_call_preserves_the_identical_total_sailing_path(self):
        source = blocks('Route104')
        before = review.statements(source['Route104_Movement_SailToDewfordBeforeDadCalls'])
        after = review.statements(source['Route104_Movement_SailToDewfordAfterDadCalls'])
        full = review.statements(source['Route104_Movement_SailToDewford'])
        self.assertEqual((len(before), len(after), len(full)), (98, 98, 195))
        self.assertEqual(before[:-1] + after, full)
        call = review.statements(source['Route104_EventScript_SailToDewfordDadCalls'])
        flag = call.index('setflag FLAG_ENABLE_NORMAN_MATCH_CALL')
        self.assertLess(call.index('pokenavcall Route104_Text_DadPokenavCall'), flag)
        self.assertLess(call.index('waitfanfare'), flag)
        self.assertIn('applymovement LOCALID_ROUTE104_BOAT, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104', call)
        self.assertIn('waitmovement LOCALID_ROUTE104_BOAT, MAP_ROUTE104', call)
        self.assertEqual(call[-2:], ['waitmovement 0', 'goto Route104_EventScript_ArriveInDewford'])

    def test_three_route104_gifts_and_soft_sand_do_not_set_flags_when_bag_is_full(self):
        source = blocks('Route104')
        for entry, flag in [('ExpertF', 'FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104'),
                             ('WhiteHerbFlorist', 'FLAG_RECEIVED_WHITE_HERB'),
                             ('Boy2', 'FLAG_RECEIVED_TM_BULLET_SEED')]:
            lines = review.statements(source['Route104_EventScript_' + entry])
            self.assertLess(lines.index('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull'),
                            lines.index('setflag ' + flag))
        lines = review.statements(blocks('Route109')['Route109_EventScript_SoftSandGirl'])
        self.assertLess(lines.index('goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull'),
                        lines.index('setflag FLAG_RECEIVED_SOFT_SAND'))

    def test_weather_cleanup_and_regi_gate_retain_the_actual_sequence(self):
        source = blocks('Route105')
        self.assertIn('call_if_unset FLAG_REGI_DOORS_OPENED, Route105_CloseRegiEntrance',
                      review.statements(source['Route105_OnLoad']))
        self.assertIn('map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1',
                      review.statements(source['Route105_OnFrame']))
        shared = review.label_blocks((ROOT / 'data/scripts/abnormal_weather.inc').read_text())
        lines = review.statements(shared['AbnormalWeather_EventScript_EndEventAndCleanup_2'])
        ordered = ['fadescreenswapbuffers FADE_TO_BLACK', 'setweather WEATHER_SUNNY', 'doweather',
                   'call AbnormalWeather_EventScript_CleanupMapTiles', 'special DrawWholeMapView',
                   'setvar VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_NONE',
                   'setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 0', 'clearflag FLAG_HIDE_MAP_NAME_POPUP',
                   'fadescreenswapbuffers FADE_FROM_BLACK', 'releaseall', 'end']
        indices = [lines.index(line) for line in ordered]
        self.assertEqual(indices, sorted(indices))
        for location in ('North', 'South'):
            placed = review.statements(shared['AbnormalWeather_EventScript_PlaceTilesRoute105' + location])
            removed = review.statements(shared['AbnormalWeather_EventScript_CleanupRoute105' + location])
            self.assertEqual((len(placed), len(removed)), (13, 13))
            self.assertTrue(all('METATILE_General_CalmWater' in line for line in removed[:-1]))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_six_owners_and_local_text_boundaries_are_native_exact(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, count, size, texts in OWNERS:
            source = blocks(name)
            start = next(iter(symbols[name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, ''.join(source.values()), version=4, address=start)
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertEqual(sum(p.kind == 'string' for p in parts.values()), texts)
            labels = list(parts)
            for i, label in enumerate(labels):
                begin = next(iter(symbols[label]))
                following = labels[i + 1] if i + 1 < len(labels) else f'Route{int(name[5:]) + 1}_MapScripts'
                end = next(iter(symbols[following]))
                self.assertEqual(parts[label].size, end - begin, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, source[label], 'string'),
                                     rom[begin - 0x08000000:end - 0x08000000], label)

    def test_text_prefixes_do_not_reassign_physical_ownership(self):
        self.assertIn('Route104_Text_DadPokenavCall', blocks('Route105'))
        self.assertIn('Route104_Text_RegisteredDadInPokenav', blocks('Route105'))
        self.assertNotIn('Route104_Text_DadPokenavCall', blocks('Route104'))
        for name in ('DewfordTown_Text_BrineyLandedInSlateportDeliverGoods',
                     'DewfordTown_Text_BrineyLandedInSlateport'):
            self.assertIn(name, blocks('Route109'))

    def test_zigzagoon_wait_is_bound_to_current_command_table_not_stale_comment(self):
        source = blocks('Route109')['Route109_EventScript_Zigzagoon']
        self.assertIn('waitmoncry', review.statements(source))
        self.assertNotIn('WAITDOORANIM', source)
        commands = (ROOT / 'data/script_cmd_table.inc').read_text()
        self.assertIn('SCR_OP_WAITMONCRY ScrCmd_waitmoncry @ 0xC5', commands)

    def family(self):
        manifest = json.loads((ROOT / review.MANIFEST_PATH).read_text())
        matches = [b for b in manifest['batches'] if set(b['maps']) & {r[0] for r in OWNERS}]
        self.assertEqual(len(matches), 1, 'one cohesive family, not partial map approvals')
        self.assertEqual(matches[0]['maps'], [r[0] for r in OWNERS])
        return matches[0]

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_recorded_family_and_all_61_battle_frames_are_current(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 61)
        result = review._review_batch(ROOT, batch, {r[0] for r in OWNERS}, {})
        self.assertEqual(result['status'], 'current', result)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_every_distinct_full_family_macro_form_matches_native_expansion(self):
        batch = self.family()
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name, *_ in OWNERS]
        for dep in batch['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 778)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
