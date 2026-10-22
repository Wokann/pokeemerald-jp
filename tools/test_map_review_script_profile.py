"""Story-map forms are measured, typed and rejected when not explicitly known."""
from pathlib import Path
import json
import re
import subprocess
import tempfile
import unittest
from unittest.mock import patch
try:
    import map_review_script_profile as profile
    from map_semantic_review import label_blocks, native_elf, statements, text_kind
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools.map_semantic_review import label_blocks, native_elf, statements, text_kind

ROOT = Path(__file__).resolve().parents[1]


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result.stdout


class StoryProfileTests(unittest.TestCase):
    def parse(self, source, waits=None):
        return profile.profile_block(ROOT, 'Entry::\n' + source, {} if waits is None else waits)

    def test_object_movement_variants_and_applywait_default_are_distinct(self):
        for source, size in [('applymovement LOCALID_PLAYER, Path', 7),
                             ('applymovement LOCALID_PLAYER, Path, MAP_FIRST', 9),
                             ('applywaitmovement LOCALID_PLAYER, Path', 10),
                             ('applywaitmovement LOCALID_PLAYER, Path, MAP_FIRST', 12),
                             ('waitmovement', 3), ('waitmovement 0', 3), ('waitmovement 1, MAP_FIRST', 5)]:
            with self.subTest(source=source):
                self.assertEqual(self.parse(source).size, size)
        self.assertEqual(self.parse('applymovement 1, Path').targets, {'Path': 'movement'})

    def test_special_waits_are_selected_by_actual_handler_not_us_table_index(self):
        self.assertEqual(self.parse('special SaveParty', {'SaveParty': 0}).size, 3)
        self.assertEqual(self.parse('special StartBattle', {'StartBattle': 1}).size, 4)
        for waits in ({}, {'StartBattle': 2}):
            with self.assertRaises(ValueError):
                self.parse('special StartBattle', waits)

    def test_repeated_special_handler_requires_one_consistent_wait_contract(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='special-profile-', dir=parent) as directory:
            root = Path(directory)
            (root / 'data').mkdir()
            path = root / 'data/specials.inc'
            path.write_text('def_special\tSame\ndef_special Same\n')
            self.assertEqual(profile.special_waits(root), {'Same': 0})
            path.write_text('def_special Same\ndef_special Same, waitstate=1\n')
            with self.assertRaisesRegex(ValueError, 'conflicting_special_wait'):
                profile.special_waits(root)

    def test_three_explicit_message_forms_bind_actual_standard_entries_and_text(self):
        for name, (index, entry) in profile.STANDARD.items():
            block = self.parse('msgbox Text, ' + name)
            self.assertEqual(block.size, 8)
            self.assertEqual(block.targets, {entry: 'script'})
            self.assertEqual(block.texts, {'Text': 'string'})
            self.assertEqual(block.standard_scripts, {index: entry})
        with self.assertRaises(ValueError):
            self.parse('msgbox Text, MSGBOX_YESNO')

    def test_map_tables_require_correct_zero_terminator_and_typed_targets(self):
        table = self.parse('map_script MAP_SCRIPT_ON_FRAME_TABLE, Frame\n.byte 0')
        self.assertEqual((table.kind, table.size, table.targets), ('map_table', 6, {'Frame': 'condition_table'}))
        for source in ('map_script_2 VAR_STATE, 2, Script\n.byte 0',
                       'map_script MAP_SCRIPT_ON_LOAD, Script\n.2byte 0',
                       'map_script MAP_SCRIPT_ON_LOAD, Script'):
            with self.assertRaises(ValueError):
                self.parse(source)

    def test_unknown_raw_numeric_control_and_implicit_forms_fail_closed(self):
        for source in ('unknown_op', '.incbin "baserom_jp.gba", 0, 12', 'goto 0x08123456',
                       'msgbox Text', 'message 0x08123456', 'setvar VAR_STATE', 'warp 0, 4, 6',
                       'call_if_eq 0x4000, 2, Target', 'applymovement 1, Path, 0, 0'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                self.parse(source)

    def test_movements_require_termination_and_cannot_mix_script_commands(self):
        good = self.parse('walk_up\ndelay_8\nstep_end')
        self.assertEqual((good.kind, good.size), ('movement', 3))
        for source in ('walk_up', 'walk_up\nend', 'walk_up 3\nstep_end'):
            with self.assertRaises(ValueError):
                self.parse(source)

    def test_cross_block_and_external_reference_kind_conflicts_are_rejected(self):
        for source in ('Start::\ngoto Path\nPath:\nwalk_up\nstep_end',
                       'Start::\ngoto External\nOther:\napplymovement 1, External',
                       'Start::\nmsgbox External, MSGBOX_DEFAULT\nOther:\ngoto External'):
            with self.assertRaises(ValueError):
                profile.profile_owner(ROOT, source, {})

    def test_unmodeled_prefixes_separators_expressions_and_wrong_table_formats_are_rejected(self):
        for source in ('Entry::\nsetvar VAR_STATE, 1; end', 'Entry::\nsetvar VAR_STATE, 1+1',
                       '.incbin "baserom_jp.gba", 0, 12\nEntry::\nend',
                       'Entry::\nmap_script 2, Nested\n.byte 0\nNested:\nend',
                       'Entry::\nmap_script MAP_SCRIPT_ON_FRAME_TABLE, Nested\n.byte 0\n'
                       'Nested:\nmap_script MAP_SCRIPT_ON_LOAD, Done\n.byte 0\nDone:\nend',
                       'Entry::\nmap_script MAP_SCRIPT_ON_LOAD, Done\n.byte 0\n.byte 0\nDone:\nend',
                       'Entry::\nstep_end\nwalk_up\nstep_end'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                profile.profile_owner(ROOT, source, {})

    def test_item_and_hidden_item_shared_forms_keep_explicit_dependencies(self):
        found = self.parse('finditem ITEM_ETHER\nend')
        self.assertEqual((found.size, found.targets, found.standard_scripts),
                         (13, {'Std_FindItem': 'script'}, {1: 'Std_FindItem'}))
        self.assertEqual(self.parse('message Text').texts, {'Text': 'string'})
        self.assertEqual(self.parse('specialvar VAR_RESULT, BufferName', {'BufferName': 0}).size, 5)
        pyramid = self.parse('pyramid_getlocation', {'CallBattlePyramidFunction': 0})
        self.assertEqual((pyramid.size, pyramid.specials), (8, {'CallBattlePyramidFunction': 0}))

    def test_strings_are_encoded_by_real_text_contract_not_treated_as_opcodes(self):
        with patch.object(profile, 'encoded_text', return_value=b'\x01\xff') as encode:
            result = self.parse('.string "text$"')
            self.assertEqual((result.kind, result.size), ('string', 2))
            encode.assert_called_once()

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_79_first_map_blocks_close_the_exact_2027_byte_native_owner(self):
        source = (ROOT / 'data/maps/PetalburgCity/scripts.inc').read_text()
        profiles = profile.profile_owner(ROOT, source)
        names, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        ordered = list(profiles)
        self.assertEqual(len(ordered), 79)
        for i, name in enumerate(ordered):
            next_name = ordered[i + 1] if i + 1 < len(ordered) else 'SlateportCity_MapScripts'
            self.assertEqual(len(names[name]), 1)
            self.assertEqual(len(names[next_name]), 1)
            self.assertEqual(profiles[name].size, next(iter(names[next_name])) - next(iter(names[name])), name)
        self.assertEqual(sum(p.size for p in profiles.values()), 2027)
        self.assertEqual(sum(p.kind == 'movement' for p in profiles.values()), 30)
        self.assertEqual(sum(p.kind == 'string' for p in profiles.values()), 12)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_every_distinct_first_map_macro_form_matches_the_actual_native_pipeline(self):
        text = (ROOT / 'data/maps/PetalburgCity/scripts.inc').read_text()
        samples = sorted({line for block in label_blocks(text).values() if text_kind(block) is None for line in statements(block)})
        self.assertEqual(len(samples), 144)
        self.check_native_forms(samples)

    def check_native_forms(self, samples, forced_waits=None):
        source = (ROOT / 'data/event_scripts.s').read_text()
        prefix = source[:source.index('\t.include "data/maps/PetalburgCity/scripts.inc"')]
        item_owner = (ROOT / 'data/scripts/obtain_item.inc').read_text()
        prefix += item_owner[:item_owner.index('Std_ObtainItem::')]
        for name, wait in (forced_waits or {}).items():
            prefix += '\n.set SPECIAL_WAITSTATE_%s, %d\n' % (name, wait)
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='native-story-profile-', dir=parent) as directory:
            fixture, obj = Path(directory) / 'profile.s', Path(directory) / 'profile.o'
            fixture.write_text(prefix + '\n' + ''.join('ProfileStart_%d:\n%s\nProfileEnd_%d:\n' % (i, line, i) for i, line in enumerate(samples)))
            expanded = run(['tools/preproc/preproc', fixture, 'charmap.txt'], text=True)
            cpp = run(['cpp', '-iquote', 'include', '-Wno-trigraphs', '-I', 'tools/agbcc/include', '-I', 'tools/agbcc',
                       '-nostdinc', '-undef', '-std=gnu89', '-'], input=expanded, text=True)
            assembly = run(['tools/preproc/preproc', '-ie', fixture, 'charmap.txt'], input=cpp, text=True)
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', obj, '-'], input=assembly, text=True)
            output = run(['tools/binutils/bin/arm-none-eabi-nm', '--defined-only', obj], text=True)
            symbols = {name: int(address, 16) for address, kind, name in re.findall(r'(?m)^([0-9a-f]+) (\w) (\S+)$', output)}
            waits = profile.special_waits(ROOT)
            waits.update(forced_waits or {})
            for i, line in enumerate(samples):
                op = line.split(None, 1)[0]
                if op in ('.byte', '.2byte'):
                    predicted = 1 if op == '.byte' else 2
                elif op in ('map_script', 'map_script_2'):
                    tail, size = ('\n.byte 0', 1) if op == 'map_script' else ('\n.2byte 0', 2)
                    predicted = self.parse(line + tail).size - size
                else:
                    tail = '\nstep_end' if op in profile.MOVEMENTS and op != 'step_end' else ''
                    predicted = profile.profile_block(ROOT, 'Entry::\n' + line + tail, waits).size - bool(tail)
                self.assertEqual(symbols['ProfileEnd_%d' % i] - symbols['ProfileStart_%d' % i], predicted, line)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_complete_first_map_shared_forms_and_wait_variants_match_real_macro_expansion(self):
        manifest = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())
        batches = [b for b in manifest['batches'] if b['review_type'] == 'direct_map_v3' and 'PetalburgCity' in b['maps']]
        self.assertEqual(len(batches), 1, 'the full story-map closure must be explicitly recorded')
        samples = set()
        for dep in batches[0]['shared_dependencies']:
            blocks = label_blocks((ROOT / dep['path']).read_text())
            for name in dep['labels']:
                samples.update(statements(blocks[name]))
        samples.update(('finditem ITEM_ETHER, 2', 'specialvar VAR_RESULT, StartWallyTutorialBattle',
                        'special SavePlayerParty', 'special StartWallyTutorialBattle'))
        self.assertTrue({'pyramid_getlocation', 'finditem ITEM_ETHER', 'switch VAR_RESULT'} <= samples)
        self.check_native_forms(sorted(samples))
        # Hypothetical metadata fixture: the macro's conditional wait branch
        # must also be measured, without changing the real Special table.
        self.check_native_forms(['pyramid_getlocation'], {'CallBattlePyramidFunction': 1})


if __name__ == '__main__':
    unittest.main()
