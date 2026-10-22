"""No-intro battles require the implicit shared root and exact JP return frame."""
import json
from pathlib import Path
import unittest
try:
    import map_review_script_profile as profile
    import test_map_semantic_review as fixtures
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import test_map_semantic_review as fixtures
    from tools import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]


class TrainerProfileTests(unittest.TestCase):
    def test_no_intro_keeps_text_implicit_root_and_inline_continuation(self):
        p = profile.profile_block(ROOT, 'Owner::\nmsgbox Intro, MSGBOX_DEFAULT\n'
            'trainerbattle_no_intro TRAINER_REVIEW, Defeat\nreturn', {}, version=4, address=0x081DDC73)
        self.assertEqual(p.size, 19)
        self.assertEqual(p.targets['EventScript_DoNoIntroTrainerBattle'], 'script')
        self.assertEqual(p.texts['Defeat'], 'string')
        self.assertEqual(p.trainer_battles, [dict(owner='Owner', trainer='TRAINER_REVIEW',
            defeat_text='Defeat', address='0x081DDC7B', resume='0x081DDC85')])
        for source in ('trainerbattle_no_intro TRAINER_REVIEW, Defeat',
                       'trainerbattle_no_intro TRAINER_REVIEW, 0x08123456\nreturn',
                       'trainerbattle_no_intro TRAINER_REVIEW, NULL\nreturn'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x08000000)

    def test_only_v4_accepts_the_new_primitive_forms(self):
        for statement, size in (('call_if_set FLAG_TEST, Done', 9), ('pokenavcall Text', 5),
                                ('dotrainerbattle', 1), ('gotopostbattlescript', 1)):
            p = profile.profile_block(ROOT, 'Owner::\n' + statement, {}, version=4, address=0x08000000)
            self.assertEqual(p.size, size)
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + statement, {})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_complete_real_map_boundaries_and_inline_battle_site(self):
        review = fixtures.review
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        text = (ROOT / 'data/maps/MauvilleCity/scripts.inc').read_text()
        profiles = profile.profile_owner(ROOT, text, version=4, address=next(iter(symbols['MauvilleCity_MapScripts'])))
        names = list(profiles)
        self.assertEqual(len(names), 84)
        self.assertEqual(sum(p.size for p in profiles.values()), 3384)
        for i, name in enumerate(names):
            stop = next(iter(symbols[names[i + 1] if i + 1 < len(names) else 'RustboroCity_MapScripts']))
            self.assertEqual(profiles[name].size, stop - next(iter(symbols[name])), name)
        self.assertEqual(profiles['MauvilleCity_EventScript_BattleWally'].trainer_battles,
            [dict(owner='MauvilleCity_EventScript_BattleWally', trainer='TRAINER_WALLY_MAUVILLE',
                  defeat_text='MauvilleCity_Text_WallyDefeat', address='0x081DDC7B', resume='0x081DDC85')])

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_all_map_and_shared_macro_forms_use_real_native_expansion(self):
        review = fixtures.review
        manifest = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())
        batches = [b for b in manifest['batches'] if 'MauvilleCity' in b['maps'] and b['review_type'] == 'direct_map_v4']
        self.assertEqual(len(batches), 1, 'complete trainer handoff must be explicitly recorded')
        sources = [(ROOT / 'data/maps/MauvilleCity/scripts.inc').read_text()]
        for dep in batches[0]['shared_dependencies']:
            blocks = review.label_blocks((ROOT / dep['path']).read_text())
            sources.extend(blocks[name] for name in dep['labels'])
        samples = {line for source in sources for block in review.label_blocks(source).values()
                   if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(samples), 209)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)


class TrainerHandoffReviewTests(unittest.TestCase):
    def setUp(self):
        f = self.f = fixtures.MapSemanticReviewTests()
        f.setUp()
        self.addCleanup(f.doCleanups)
        f.add_story_fixture()
        review = fixtures.review
        batch = f.manifest['batches'][0]
        batch['review_type'] = 'direct_map_v4'
        f.put('data/maps/First/scripts.inc', 'First_MapScripts::\n'
            'map_script MAP_SCRIPT_ON_LOAD, First_Entry\n.byte 0\n'
            'First_Entry::\ntrainerbattle_no_intro TRAINER_REVIEW, First_Defeat\n'
            'msgbox First_Text, MSGBOX_DEFAULT\nend\n'
            'First_Text:\n.string "あ$"\nFirst_Defeat:\n.string "い$"\n')
        f.put('data/trainer.inc', 'EventScript_DoNoIntroTrainerBattle::\n'
            'applywaitmovement VAR_LAST_TALKED, Movement_RevealTrainer\nspecial PlayTrainerEncounterMusic\n'
            'dotrainerbattle\ngotopostbattlescript\nMovement_RevealTrainer:\nreveal_trainer\nstep_end\n')
        f.put('data/std.inc', (f.root / 'data/std.inc').read_text() + 'Std_MsgboxDefault::\n'
              'message NULL\nwaitmessage\nwaitbuttonpress\nreturn\n')
        f.put('data/specials.inc', 'def_special PlayTrainerEncounterMusic\n')
        for path in review.TRAINER_ENGINE_CONTEXT:
            f.put(path, 'fixture source\n')
            batch['sources'].append(f.claim(path))
        for path, text in [('include/constants/battle_setup.h', '#define TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT 3\n'),
                           ('include/constants/event_objects.h', '#define LOCALID_NONE 0\n'),
                           ('include/constants/opponents.h', '#define TRAINER_REVIEW 656\n'),
                           ('data/script_cmd_table.inc', 'script_cmd_table_entry SCR_OP_NOP ScrCmd_nop\n'
                            'script_cmd_table_entry SCR_OP_TRAINERBATTLE ScrCmd_trainerbattle\n')]:
            f.put(path, text)
            if not any(c['path'] == path for c in batch['sources']):
                batch['sources'].append(f.claim(path))
        batch['special_contracts'] = [dict(entry='PlayTrainerEncounterMusic', waitstate=0,
            source_path='src/battle_setup.c', source_symbol='PlayTrainerEncounterMusic')]
        batch['trainer_battles'] = [dict(owner='First_Entry', trainer='TRAINER_REVIEW',
            defeat_text='First_Defeat', address='0x08000006', resume='0x08000010')]
        batch['shared_dependencies'] = [d for d in batch['shared_dependencies'] if d['entry'] != 'SharedMove']
        for path, name in [('data/trainer.inc', 'EventScript_DoNoIntroTrainerBattle'),
                           ('data/trainer.inc', 'Movement_RevealTrainer'), ('data/std.inc', 'Std_MsgboxDefault')]:
            batch['shared_dependencies'].append(dict(entry=name, path=path, labels=[name]))
            batch['sources'].append(f.claim(path, selector='asm_labels', labels=[name]))
        batch['sources'] = [c for c in batch['sources'] if c['path'] not in ('data/movement.inc', 'src/fixture_battle.c')]
        source = (f.root / 'data/event_scripts.s').read_text()
        f.put('data/event_scripts.s', source.replace('gStdScripts_End::',
            '.4byte Std_MsgboxDefault\ngStdScripts_End::') + '.include "data/trainer.inc"\n')
        batch['standard_scripts'].append(dict(index=4, entry='Std_MsgboxDefault'))
        batch['native_spans'] = [s for s in batch['native_spans'] if s['symbol'] != 'SharedMove']
        batch['native_spans'][0]['size'] = 29
        for span in batch['native_spans']:
            if span['symbol'] == 'gStdScripts':
                span['size'] = 20
        for name, offset, size in [('EventScript_DoNoIntroTrainerBattle', 624, 15),
                                   ('Movement_RevealTrainer', 640, 2), ('Std_MsgboxDefault', 656, 8)]:
            batch['native_spans'].append(dict(map=None, role='shared_script', symbol=name,
                                             address=0x08000000 + offset, size=size))
        image = bytearray(i % 256 for i in range(768))
        image[:len(f.image)] = f.image
        image[6:16] = bytes([1, 3, 0x90, 2, 0, 0]) + (0x0800001B).to_bytes(4, 'little')
        image[25:29] = bytes([1, 255, 2, 255])
        image[400:404] = (0x08000290).to_bytes(4, 'little')
        f.image = bytes(image)
        f.symbols = [(s['symbol'], s['address']) for s in batch['native_spans']]
        f.symbols += [('First_Entry', 0x08000006), ('First_Text', 0x08000019),
                      ('First_Defeat', 0x0800001B), ('PlayTrainerEncounterMusic', 0x0800021D)]
        self.engine_symbols = []
        for i, (name, path) in enumerate(review.TRAINER_ENGINE_SYMBOLS.items()):
            value = 0x08000200 + 4 * i
            f.symbols.append((name, value | 1))
            self.engine_symbols.append((value, path))
        self.refresh()
        self.assertEqual(f.progress()['reviewed_maps'], 1, f.progress())

    def refresh(self):
        f = self.f
        f.refresh_story_fixture()
        rows = ''.join('\n .text 0x%08X 0x4 %s' % (at, path[:-2] + '.o') for at, path in self.engine_symbols)
        f.put('pokeemerald_jp.map', f.linker_map() + rows)

    def test_complete_implicit_engine_entry_and_return_frame_are_accepted(self):
        self.assertEqual(self.f.progress()['reviewed_maps'], 1)

    def test_implicit_entry_and_explicit_frame_cannot_be_omitted(self):
        batch = self.f.manifest['batches'][0]
        original = batch['shared_dependencies']
        batch['shared_dependencies'] = [d for d in original if d['entry'] != 'EventScript_DoNoIntroTrainerBattle']
        self.f.save_manifest()
        self.f.assert_not_approved(self.f.progress())
        batch['shared_dependencies'] = original
        batch['trainer_battles'] = []
        self.f.save_manifest()
        self.f.assert_not_approved(self.f.progress())

    def test_shared_postbattle_jump_cannot_be_dropped_with_a_true_prefix_hash(self):
        f = self.f
        path = 'data/trainer.inc'
        f.put(path, (f.root / path).read_text().replace('gotopostbattlescript\n', ''))
        for span in f.manifest['batches'][0]['native_spans']:
            if span['symbol'] == 'EventScript_DoNoIntroTrainerBattle':
                span['size'] -= 1
        self.refresh()
        f.assert_not_approved(f.progress())

    def test_native_parameter_header_is_not_only_a_size_or_whole_rom_hash(self):
        f = self.f
        image = bytearray(f.image)
        image[7] = 4
        f.image = bytes(image)
        self.refresh()
        report = f.progress()
        f.assert_not_approved(report)
        self.assertIn('native_trainer_parameter_header_mismatch:First_Entry', report['batches'][0]['errors'])

    def test_engine_source_and_native_owner_evidence_are_mandatory(self):
        f = self.f
        original = f.manifest['batches'][0]['sources']
        f.manifest['batches'][0]['sources'] = [c for c in f.manifest['batches'][0]['sources']
                                               if c['path'] != 'src/field_screen_effect.c']
        f.save_manifest()
        f.assert_not_approved(f.progress())
        f.manifest['batches'][0]['sources'] = original
        address, path = self.engine_symbols[0]
        self.engine_symbols[0] = (address, 'src/other.c')
        self.refresh()
        result = f.progress()
        f.assert_not_approved(result)
        self.assertIn('native_trainer_engine_owner_mismatch:ScrCmd_trainerbattle', result['batches'][0]['errors'])


if __name__ == '__main__':
    unittest.main()
