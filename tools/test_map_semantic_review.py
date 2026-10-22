#!/usr/bin/env python3
"""Review records require current, complete evidence and fail closed on changes."""
import copy
import hashlib
import json
import os
import struct
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

try:
    import map_semantic_review as review
except ModuleNotFoundError:
    from tools import map_semantic_review as review


def elf_image(image, symbols):
    strings = b'\0'
    entries = bytes(16)
    for name, value in symbols:
        name_at = len(strings)
        strings += name.encode() + b'\0'
        entries += struct.pack('<IIIBBH', name_at, value, 4, 1, 0, 1)
    first = 52 + 4 * 40
    string_at = first + len(image)
    sym_at = string_at + len(strings)
    ident = b'\x7fELF\x01\x01\x01' + bytes(9)
    header = struct.pack('<16sHHIIIIIHHHHHH', ident, 2, 40, 1, 0, 0, 52, 0, 52, 0, 0, 40, 4, 0)
    sections = bytes(40)
    sections += struct.pack('<10I', 0, 1, 2, 0x08000000, first, len(image), 0, 0, 4, 0)
    sections += struct.pack('<10I', 0, 3, 0, 0, string_at, len(strings), 0, 0, 1, 0)
    sections += struct.pack('<10I', 0, 2, 0, 0, sym_at, len(entries), 2, 1, 4, 16)
    return header + sections + image + strings + entries


class MapSemanticReviewTests(unittest.TestCase):
    def setUp(self):
        temporary_root = Path(__file__).resolve().parents[1] / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        self.temporary = tempfile.TemporaryDirectory(prefix='map-review-', dir=temporary_root)
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.name = 'First'
        for path in sorted(review.REQUIRED_CONTEXT):
            self.put(path, 'fixture source\n')
        self.put('data/event_scripts.s', '.include "data/maps/First/scripts.inc"\n')
        self.put('data/map_events.s', '.include "data/maps/First/events.inc"\n')
        self.put('data/maps.s', '.include "data/maps/First/header.inc"\n.include "data/maps/First/connections.inc"\n')
        self.put('data/maps/First/map.json', json.dumps({'name': 'First', 'layout': 'LAYOUT_FIRST',
                 'connections': [{'direction': 'right', 'map': 'MAP_SECOND', 'offset': 0}]}))
        for part, label in [('scripts.inc', 'First_MapScripts'), ('events.inc', 'First_MapEvents'),
                            ('header.inc', 'First'), ('connections.inc', 'First_MapConnectionsList')]:
            self.put('data/maps/First/' + part, label + '::\n\t.byte 0\n')
        for filename in ('border.bin', 'map.bin'):
            self.put('data/layouts/First/' + filename, b'\0\0')
        self.put('data/layouts/layouts.json', json.dumps({'layouts': [{'id': 'LAYOUT_FIRST', 'name': 'First_Layout'}]}))
        self.labels = ['First_Layout_Border', 'First_Layout_Blockdata', 'First_Layout']
        self.put('data/layouts/layouts.inc', ''.join(n + '::\n\t.byte 0\n' for n in self.labels))
        make = 'TEST_CC := original\nCC := $(TEST_CC)\n'
        for prefix in review.MAKE_PREFIXES:
            make += prefix + (' := First\n' if ':' not in prefix else ' source\n\t$(CC) fixture\n')
        self.put('Makefile', make)
        sources = []
        paths = set(review.REQUIRED_CONTEXT) | {'data/maps/First/' + p for p in review.REQUIRED_COMPONENTS}
        paths |= {'data/layouts/First/border.bin', 'data/layouts/First/map.bin'}
        for path in sorted(paths):
            sources.append(self.claim(path))
        sources.append(self.claim('data/layouts/layouts.inc', selector='asm_labels', labels=self.labels))
        sources.append(self.claim('data/layouts/layouts.json', selector='json_layout', id='LAYOUT_FIRST'))
        sources.append(self.claim('Makefile', selector='make_prefixes', prefixes=list(review.MAKE_PREFIXES)))
        self.put('ld_script_jp.txt', ''.join(n + '(.rodata);\n' for n in review.LINKER_INPUTS))
        sources.append(self.claim('ld_script_jp.txt', selector='linker_inputs', inputs=list(review.LINKER_INPUTS)))
        self.image = bytes(range(100))
        self.components = [('scripts', 'First_MapScripts', 0, 1), ('events', 'First_MapEvents', 4, 20),
                           ('header', 'First', 24, 28), ('connections', 'First_MapConnectionsList', 52, 20),
                           ('layout', 'First_Layout', 72, 24), ('border', 'First_Layout_Border', 96, 2),
                           ('blockdata', 'First_Layout_Blockdata', 98, 2)]
        self.symbols = [(symbol, 0x08000000 + offset) for role, symbol, offset, size in self.components]
        spans = [dict(map='First', role=role, symbol=symbol, address=0x08000000 + offset, size=size,
                      sha256=review.sha256(self.image[offset:offset + size]))
                 for role, symbol, offset, size in self.components]
        checks = {key: 'Explicit fixture review assertion.' for key in
                  ('script_control_flow', 'event_fields', 'header_flags', 'connections',
                   'layout_resources', 'shared_call_closure', 'localization')}
        batch = dict(id='first_review', maps=['First'], review_type='direct_map_v1', decision='reviewed',
                     jp_commit='1' * 40, rom_sha1=hashlib.sha1(self.image).hexdigest(),
                     us_reference={'commit': '2' * 40, 'files': {'data/maps/First/map.json': '3' * 64}},
                     sources=sources, native_spans=spans, checks={'First': checks})
        self.manifest = {'schema_version': 1, 'batches': [batch]}
        self.save_manifest()
        self.put('baserom_jp.gba', self.image)
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.map', self.linker_map())

    def put(self, path, data):
        dest = self.root / path
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(data.encode() if isinstance(data, str) else data)

    def claim(self, path, **selector):
        record = dict(path=path, selector='file')
        record.update(selector)
        record['sha256'] = review.sha256(review.source_payload(self.root, record))
        return record

    def save_manifest(self):
        self.put(review.MANIFEST_PATH, json.dumps(self.manifest))

    def linker_map(self):
        rows = ['0x%08X %s' % (v, n) for n, v in self.symbols]
        for span in self.manifest['batches'][0]['native_spans']:
            owner = ('data/event_scripts.o' if span['role'] in ('scripts', 'shared_script', 'shared_text', 'standard_script_table')
                     else 'data/map_events.o' if span['role'] == 'events' else 'data/maps.o')
            rows.append(' .rodata 0x%08X 0x%X %s' % (span['address'], span['size'], owner))
        return '\n'.join(rows)

    def progress(self):
        return review.map_review_progress(self.root, {'First'})

    def assert_not_approved(self, report):
        self.assertEqual(report['reviewed_maps'], 0)
        self.assertEqual(report['reviewed_map_names'], [])

    def test_complete_explicit_evidence_accepts_local_elf_symbols(self):
        report = self.progress()
        self.assertEqual(report['status'], 'recorded')
        self.assertEqual(report['reviewed_map_names'], ['First'])
        self.assertEqual(report['batches'][0]['status'], 'current')

    def test_structural_files_without_a_manifest_are_not_review(self):
        (self.root / review.MANIFEST_PATH).unlink()
        report = self.progress()
        self.assertEqual(report['status'], 'not_recorded')
        self.assert_not_approved(report)

    def test_source_mutation_revokes_the_record(self):
        self.put('data/maps/First/scripts.inc', 'First_MapScripts::\n\t.byte 0\n@ changed source\n')
        report = self.progress()
        self.assertEqual(report['batches'][0]['status'], 'stale')
        self.assert_not_approved(report)

    def test_missing_generated_include_revokes_the_record(self):
        (self.root / 'data/maps/First/events.inc').unlink()
        self.assert_not_approved(self.progress())

    def test_missing_native_artifacts_never_count_as_reviewed(self):
        (self.root / 'pokeemerald_jp.elf').unlink()
        report = self.progress()
        self.assertEqual(report['batches'][0]['status'], 'native_artifacts_unavailable')
        self.assert_not_approved(report)

    def test_changed_native_build_revokes_the_record(self):
        self.put('pokeemerald_jp.gba', b'X' + self.image[1:])
        self.assert_not_approved(self.progress())

    def test_elf_bytes_must_also_match_the_native_image(self):
        self.put('pokeemerald_jp.elf', elf_image(b'X' + self.image[1:], self.symbols))
        self.assert_not_approved(self.progress())

    def test_ambiguous_elf_symbol_is_not_a_binding(self):
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols + [(self.symbols[0][0], 0x08000001)]))
        self.assert_not_approved(self.progress())

    def test_linker_map_disagreement_revokes_the_record(self):
        self.put('pokeemerald_jp.map', '0x08000001 ' + self.symbols[0][0] + '\n')
        self.assert_not_approved(self.progress())

    def test_missing_component_role_is_rejected(self):
        self.manifest['batches'][0]['native_spans'].pop()
        self.save_manifest()
        report = self.progress()
        self.assertEqual(report['status'], 'invalid_manifest')
        self.assert_not_approved(report)

    def test_incomplete_generator_context_is_rejected(self):
        batch = self.manifest['batches'][0]
        batch['sources'] = [c for c in batch['sources'] if c['path'] != 'tools/mapjson/mapjson.cpp']
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_duplicate_reviews_do_not_double_count_or_override(self):
        duplicate = copy.deepcopy(self.manifest['batches'][0])
        duplicate['id'] = 'duplicate_review'
        self.manifest['batches'].append(duplicate)
        self.save_manifest()
        report = self.progress()
        self.assertEqual(report['status'], 'invalid_manifest')
        self.assert_not_approved(report)

    def test_consumed_make_variable_change_is_detected(self):
        path = self.root / 'Makefile'
        path.write_text(path.read_text().replace('TEST_CC := original', 'TEST_CC := changed'))
        self.assert_not_approved(self.progress())

    def test_unrelated_make_assets_do_not_permanently_stale_a_review(self):
        path = self.root / 'Makefile'
        path.write_text(path.read_text() + '\nUNRELATED_ASSETS := other.png\n')
        # Existing native artifacts are now older than an input, so do not pass
        # until a successful equivalent rebuild refreshes the artifacts.
        changed = max((self.root / p).stat().st_mtime_ns for p in
                      ('pokeemerald_jp.gba', 'pokeemerald_jp.elf', 'pokeemerald_jp.map')) + 2_000_000_000
        os.utime(path, ns=(changed, changed))
        self.assert_not_approved(self.progress())
        refreshed = changed + 2_000_000_000
        for name in ('pokeemerald_jp.gba', 'pokeemerald_jp.elf', 'pokeemerald_jp.map'):
            os.utime(self.root / name, ns=(refreshed, refreshed))
        self.assertEqual(self.progress()['reviewed_map_names'], ['First'])

    def test_outside_source_path_is_rejected(self):
        self.manifest['batches'][0]['sources'][0]['path'] = '../outside'
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_review_decision_and_semantic_checklist_are_required(self):
        self.manifest['batches'][0]['checks']['First'].pop('localization')
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_bad_json_and_unsupported_elf_fail_closed(self):
        self.put(review.MANIFEST_PATH, '{')
        self.assert_not_approved(self.progress())
        self.save_manifest()
        self.put('pokeemerald_jp.elf', b'invalid elf')
        self.assert_not_approved(self.progress())

    def test_output_is_deterministic(self):
        left = json.dumps(self.progress(), sort_keys=True)
        right = json.dumps(self.progress(), sort_keys=True)
        self.assertEqual(left, right)

    def add_shared_fixture(self):
        self.put('data/maps/First/scripts.inc', 'First_MapScripts::\n'
                 '\tmap_script MAP_SCRIPT_ON_RESUME, First_OnResume\n\t.byte 0\n'
                 'First_OnResume:\n\tcall Shared\n\tend\n')
        self.put('data/shared.inc', 'Shared::\n\tswitch VAR_TEST\n'
                 '\tcase 1, SharedExit\n\treturn\n'
                 'SharedExit:\n\tsetescapewarp MAP_SECOND, 1, 2\n\treturn\n')
        self.put('data/event_scripts.s', '.include "data/maps/First/scripts.inc"\n'
                 '.include "data/shared.inc"\n')
        batch = self.manifest['batches'][0]
        labels = ['Shared', 'SharedExit']
        batch['shared_dependencies'] = [dict(entry='Shared', path='data/shared.inc', labels=labels)]
        batch['sources'].append(self.claim('data/shared.inc', selector='asm_labels', labels=labels))
        self.image = bytes(n % 256 for n in range(282))
        batch['rom_sha1'] = hashlib.sha1(self.image).hexdigest()
        self.symbols = []
        for span in batch['native_spans']:
            if span['role'] == 'scripts':
                span['size'] = 12
            else:
                span['address'] += 16
            offset = span['address'] - 0x08000000
            span['sha256'] = review.sha256(self.image[offset:offset + span['size']])
            self.symbols.append((span['symbol'], span['address']))
        batch['native_spans'].append(dict(map=None, role='shared_script', symbol='Shared',
                                         address=0x08000100, size=26,
                                         sha256=review.sha256(self.image[256:282])))
        self.symbols += [('First_OnResume', 0x08000006), ('Shared', 0x08000100), ('SharedExit', 0x08000111)]
        for claim in batch['sources']:
            claim['sha256'] = review.sha256(review.source_payload(self.root, claim))
        self.save_manifest()
        self.put('baserom_jp.gba', self.image)
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.map', self.linker_map())
        result = self.progress()
        self.assertEqual(result['reviewed_maps'], 1, result)

    def test_full_shared_dependency_closure_is_required(self):
        self.add_shared_fixture()
        batch = self.manifest['batches'][0]
        batch['sources'] = [c for c in batch['sources'] if c['path'] != 'data/shared.inc']
        batch['native_spans'] = [s for s in batch['native_spans'] if s['role'] != 'shared_script']
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_shared_native_extent_cannot_be_omitted(self):
        self.add_shared_fixture()
        self.manifest['batches'][0]['native_spans'].pop()
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_shared_source_binding_cannot_be_omitted(self):
        self.add_shared_fixture()
        batch = self.manifest['batches'][0]
        batch['sources'] = [c for c in batch['sources'] if c['path'] != 'data/shared.inc']
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_truncated_script_with_a_true_partial_hash_is_rejected(self):
        self.add_shared_fixture()
        span = self.manifest['batches'][0]['native_spans'][0]
        span['size'] = 1
        span['sha256'] = review.sha256(self.image[:1])
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_script_span_cannot_impersonate_header_role(self):
        spans = self.manifest['batches'][0]['native_spans']
        header = next(s for s in spans if s['role'] == 'header')
        header.update(copy.deepcopy(spans[0]))
        header['role'] = 'header'
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_new_external_call_requires_explicit_shared_evidence(self):
        self.add_shared_fixture()
        source = self.root / 'data/shared.inc'
        source.write_text(source.read_text().replace('\tswitch VAR_TEST', '\tcall Other\n\tswitch VAR_TEST'))
        for c in self.manifest['batches'][0]['sources']:
            if c['path'] == 'data/shared.inc':
                c['sha256'] = review.sha256(review.source_payload(self.root, c))
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_transitive_constant_dependency_is_not_optional(self):
        self.put('include/constants/map_scripts.h', '#include "review_nested.h"\n')
        self.put('include/constants/review_nested.h', '#define ON_RESUME 5\n')
        batch = self.manifest['batches'][0]
        for c in batch['sources']:
            c['sha256'] = review.sha256(review.source_payload(self.root, c))
        self.save_manifest()
        self.assert_not_approved(self.progress())
        batch['sources'].append(self.claim('include/constants/review_nested.h'))
        self.save_manifest()
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.map', self.linker_map())
        self.assertEqual(self.progress()['reviewed_maps'], 1)
        self.put('include/constants/review_nested.h', '#define ON_RESUME 4\n')
        self.assert_not_approved(self.progress())

    def test_linker_input_ownership_and_selection_are_required(self):
        self.put('pokeemerald_jp.map', self.linker_map().replace('data/map_events.o', 'data/unused.o'))
        self.assert_not_approved(self.progress())

    def test_linker_input_source_changes_revoke_review(self):
        self.put('ld_script_jp.txt', 'data/event_scripts.o(other_section);\n'
                 'data/map_events.o(.rodata);\ndata/maps.o(.rodata);\n')
        self.assert_not_approved(self.progress())

    def add_braille_fixture(self):
        project = Path(__file__).resolve().parents[1]
        binary = project / 'tools/preproc/preproc'
        if not binary.is_file():
            self.skipTest('requires the built real JP preprocessor')
        self.put('tools/preproc/preproc', binary.read_bytes())
        (self.root / 'tools/preproc/preproc').chmod(0o700)
        for path in review.TEXT_CONTEXT:
            self.put(path, (project / path).read_bytes() if path == 'charmap.txt' else 'fixture source\n')
        self.put('data/maps/First/scripts.inc', 'First_MapScripts::\n\t.byte 0\n'
                 'First_Inspect::\n\tlockall\n\tbraillemsgbox SharedBraille\n\treleaseall\n\tend\n')
        self.put('data/braille.inc', 'SharedBraille::\n\tbrailleformat 4, 6, 26, 13, 7, 9\n'
                 '\t@ Visual cells are comments, not encoding inputs.\n\t.braille "ココデ アガレ$"\n')
        self.put('data/event_scripts.s', '.include "data/maps/First/scripts.inc"\n.include "data/braille.inc"\n')
        batch = self.manifest['batches'][0]
        batch['review_type'] = 'direct_map_v2'
        batch['text_dependencies'] = [dict(entry='SharedBraille', path='data/braille.inc', kind='braille')]
        for path in sorted(review.TEXT_CONTEXT):
            batch['sources'].append(self.claim(path))
        batch['sources'].append(self.claim('data/braille.inc', selector='asm_labels', labels=['SharedBraille']))
        for claim in batch['sources']:
            claim['sha256'] = review.sha256(review.source_payload(self.root, claim))
        image = bytearray(i % 256 for i in range(512))
        payload = review.encoded_text(self.root, (self.root / 'data/braille.inc').read_text(), 'braille')
        self.assertEqual(len(payload), 16)
        image[256:272] = payload
        self.image = bytes(image)
        self.symbols = []
        for span in batch['native_spans']:
            if span['role'] == 'scripts':
                span['size'] = 11
            else:
                span['address'] += 16
            offset = span['address'] - 0x08000000
            span['sha256'] = review.sha256(self.image[offset:offset + span['size']])
            self.symbols.append((span['symbol'], span['address']))
        batch['native_spans'].append(dict(map=None, role='shared_text', symbol='SharedBraille',
                                         address=0x08000100, size=16, sha256=review.sha256(payload)))
        batch['rom_sha1'] = hashlib.sha1(self.image).hexdigest()
        self.symbols += [('First_Inspect', 0x08000001), ('SharedBraille', 0x08000100)]
        self.save_manifest()
        self.put('baserom_jp.gba', self.image)
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.map', self.linker_map())
        self.assertEqual(self.progress()['reviewed_maps'], 1)

    def test_v1_is_not_silently_broadened(self):
        with self.assertRaisesRegex(ValueError, 'unsupported_direct_review_statement'):
            review.script_analysis('First::\n\tsetdivewarp MAP_FIRST, 1, 2\n\tend\n')

    def test_v2_dive_flag_tile_and_conditional_sizes_are_explicit(self):
        text = ('First::\n\tsetdivewarp MAP_FIRST, 1, 2\n\tsetflag FLAG_FIRST\n'
                '\tgetplayerxy VAR_X, VAR_Y\n\tgoto_if_ne VAR_X, 12, Other\n'
                '\tgoto_if_set FLAG_FIRST, Other\n\tcall_if_set FLAG_FIRST, Other\n'
                '\tsetmetatile 1, 2, METATILE_FIRST, TRUE\n\tend\n')
        self.assertEqual(review.extended_analysis(self.root, text), (55, {'Other'}, {}))
        for unsupported in ('goto_if_ne Other', 'goto_if_ne VAR_X, VAR_Y, Other',
                            'setdivewarp MAP_FIRST, 1', 'msgbox Text, MSGBOX_DEFAULT',
                            'special Unknown', '.incbin "raw.bin"', '.set Alias, 0x08000000'):
            with self.subTest(unsupported=unsupported), self.assertRaises(ValueError):
                review.extended_analysis(self.root, 'First::\n\t' + unsupported + '\n')

    def test_complete_v2_braille_is_real_preproc_encoded_and_native_bound(self):
        self.add_braille_fixture()
        self.assertEqual(self.progress()['reviewed_maps'], 1)

    def test_v2_text_dependency_cannot_be_omitted_or_assigned_the_wrong_kind(self):
        self.add_braille_fixture()
        batch = self.manifest['batches'][0]
        original = copy.deepcopy(batch['text_dependencies'])
        batch['text_dependencies'] = []
        self.save_manifest()
        self.assert_not_approved(self.progress())
        batch['text_dependencies'] = original
        batch['text_dependencies'][0]['kind'] = 'string'
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_v2_text_native_span_cannot_be_truncated_to_a_true_prefix(self):
        self.add_braille_fixture()
        span = self.manifest['batches'][0]['native_spans'][-1]
        span['size'] = 15
        span['sha256'] = review.sha256(self.image[256:271])
        self.save_manifest()
        self.assert_not_approved(self.progress())

    def test_v2_text_reencoding_must_match_rom_even_with_refreshed_source_hashes(self):
        self.add_braille_fixture()
        path = self.root / 'data/braille.inc'
        path.write_text(path.read_text().replace('ココデ', 'ソコデ'))
        for claim in self.manifest['batches'][0]['sources']:
            claim['sha256'] = review.sha256(review.source_payload(self.root, claim))
        self.save_manifest()
        for name in ('pokeemerald_jp.gba', 'pokeemerald_jp.elf', 'pokeemerald_jp.map'):
            self.put(name, (self.root / name).read_bytes())
        report = self.progress()
        self.assert_not_approved(report)
        self.assertIn('native_text_encoding_mismatch:SharedBraille', report['batches'][0]['errors'])

    def test_v2_text_source_and_compiler_closure_are_required(self):
        self.add_braille_fixture()
        batch = self.manifest['batches'][0]
        for path in ('data/braille.inc', 'tools/preproc/utf8.cpp'):
            original = batch['sources']
            batch['sources'] = [claim for claim in original if claim['path'] != path]
            self.save_manifest()
            self.assert_not_approved(self.progress())
            batch['sources'] = original

    def test_v2_incompatible_local_message_kinds_and_script_targets_are_rejected(self):
        self.add_braille_fixture()
        source = 'First_MapScripts::\n\tmsgbox Text, MSGBOX_SIGN\nText::\n\tbrailleformat 1, 2, 3, 4, 5, 6\n\t.braille "ア$"\n'
        self.put('data/maps/First/scripts.inc', source)
        with self.assertRaisesRegex(ValueError, 'incompatible_message_target'):
            review.component_contracts(self.root, self.manifest['batches'][0], ['First'])
        self.put('data/maps/First/scripts.inc', source.replace('msgbox Text, MSGBOX_SIGN', 'goto Text'))
        with self.assertRaisesRegex(ValueError, 'script_target_is_text'):
            review.component_contracts(self.root, self.manifest['batches'][0], ['First'])

    def test_v2_japanese_strings_preserve_at_signs_and_control_sequences(self):
        self.add_braille_fixture()
        self.assertEqual(review.statements('Text::\n\t.string "あ@\\n" @ comment\n'), ['.string "あ@\\n"'])
        text = 'Text::\n\t.string "あ\\n"\n\t.string "い$"\n'
        encoded = review.encoded_text(self.root, text, 'string')
        self.assertEqual(encoded[-3:], bytes([0xFE, 0x02, 0xFF]))
        self.assertEqual(len(encoded), 4)

    def test_v2_preprocessor_rejection_unknown_output_and_unterminated_text_fail_closed(self):
        self.add_braille_fixture()
        for text in ('Text::\n\t.string "あ"\n', 'Text::\n\t.string "{UNKNOWN_REVIEW_CONTROL}$"\n',
                     'Text::\n\tbrailleformat 1, 2, 3, 4, 5\n\t.braille "ア$"\n'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                review.encoded_text(self.root, text, 'braille' if 'brailleformat' in text else 'string')
        with patch.object(review.subprocess, 'run') as process:
            process.return_value.returncode = 0
            process.return_value.stdout = '\t.byte 0xFF\n.incbin "unknown"\n'
            with self.assertRaisesRegex(ValueError, 'unexpected_text_preprocessor_output'):
                review.encoded_text(self.root, 'Text::\n\t.string "あ$"\n', 'string')

    def test_internal_parent_includes_are_canonical_but_escapes_are_not(self):
        self.put('tools/preproc/sample.cpp', '#include "../../include/constants/characters.h"\n')
        self.put('include/constants/characters.h', '#define TEXT_END 255\n')
        closure = review.compile_context(self.root, {'tools/preproc/sample.cpp'})
        self.assertEqual(closure, {'tools/preproc/sample.cpp', 'include/constants/characters.h'})

    def test_v2_null_connections_require_an_empty_generated_file_and_native_zero_pointer(self):
        self.add_braille_fixture()
        metadata = json.loads((self.root / 'data/maps/First/map.json').read_text())
        metadata['connections'] = None
        self.put('data/maps/First/map.json', json.dumps(metadata))
        self.put('data/maps/First/connections.inc', '\n')
        batch = self.manifest['batches'][0]
        batch['native_spans'] = [span for span in batch['native_spans'] if span['role'] != 'connections']
        image = bytearray(self.image)
        header = next(span for span in batch['native_spans'] if span['role'] == 'header')
        offset = header['address'] - 0x08000000
        image[offset + 12:offset + 16] = bytes(4)
        self.image = bytes(image)
        batch['rom_sha1'] = hashlib.sha1(self.image).hexdigest()
        header['sha256'] = review.sha256(self.image[offset:offset + 28])
        for claim in batch['sources']:
            claim['sha256'] = review.sha256(review.source_payload(self.root, claim))
        self.save_manifest()
        self.put('baserom_jp.gba', self.image)
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.map', self.linker_map())
        self.assertEqual(self.progress()['reviewed_maps'], 1)
        self.put('data/maps/First/connections.inc', 'First_MapConnectionsList::\n\t.byte 0\n')
        self.assert_not_approved(self.progress())
        self.put('data/maps/First/connections.inc', '\n')
        image[offset + 12] = 1
        self.image = bytes(image)
        batch['rom_sha1'] = hashlib.sha1(self.image).hexdigest()
        header['sha256'] = review.sha256(self.image[offset:offset + 28])
        self.save_manifest()
        self.put('baserom_jp.gba', self.image)
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.map', self.linker_map())
        report = self.progress()
        self.assert_not_approved(report)
        self.assertIn('native_null_connection_pointer_mismatch:First', report['batches'][0]['errors'])

    def test_object_event_contract_uses_the_actual_generator_label(self):
        metadata = json.loads((self.root / 'data/maps/First/map.json').read_text())
        metadata['object_events'] = [{}]
        self.put('data/maps/First/map.json', json.dumps(metadata))
        contracts, shared = review.component_contracts(self.root, self.manifest['batches'][0], ['First'])
        self.assertEqual(contracts[('First', 'events')], ('First_ObjectEvents', 44))

    def test_external_text_must_remain_reachable_from_the_actual_script_owner(self):
        self.add_braille_fixture()
        self.put('data/event_scripts.s', '.include "data/maps/First/scripts.inc"\n')
        for claim in self.manifest['batches'][0]['sources']:
            claim['sha256'] = review.sha256(review.source_payload(self.root, claim))
        self.save_manifest()
        for name in ('pokeemerald_jp.gba', 'pokeemerald_jp.elf', 'pokeemerald_jp.map'):
            self.put(name, (self.root / name).read_bytes())
        report = self.progress()
        self.assert_not_approved(report)
        self.assertIn('unreachable_shared_owner:data/braille.inc', report['batches'][0]['errors'])

    def add_sign_fixture(self):
        self.add_braille_fixture()
        self.put('data/maps/First/scripts.inc', 'First_MapScripts::\n\t.byte 0\n'
                 'First_Inspect::\n\tmsgbox First_Text, MSGBOX_SIGN\n\tend\n'
                 'First_Text::\n\t.string "あ$"\n')
        self.put('data/std.inc', 'Std_MsgboxSign::\n\tlockall\n\tmessage NULL\n'
                 '\twaitmessage\n\twaitbuttonpress\n\treleaseall\n\treturn\n')
        self.put('data/event_scripts.s', 'gStdScripts::\n\t.4byte NULL\n\t.4byte NULL\n'
                 '\t.4byte NULL\n\t.4byte Std_MsgboxSign\ngStdScripts_End::\n'
                 '.include "data/maps/First/scripts.inc"\n.include "data/std.inc"\n')
        batch = self.manifest['batches'][0]
        batch['text_dependencies'] = []
        batch['shared_dependencies'] = [dict(entry='Std_MsgboxSign', path='data/std.inc', labels=['Std_MsgboxSign'])]
        batch['standard_scripts'] = [dict(index=3, entry='Std_MsgboxSign')]
        batch['sources'] = [c for c in batch['sources'] if c['path'] != 'data/braille.inc']
        batch['sources'] += [self.claim('data/std.inc', selector='asm_labels', labels=['Std_MsgboxSign']),
                             self.claim('data/event_scripts.s', selector='asm_labels', labels=['gStdScripts'])]
        for claim in batch['sources']:
            claim['sha256'] = review.sha256(review.source_payload(self.root, claim))
        image = bytearray(self.image)
        image[10:12] = bytes([1, 255])
        image[288:298] = bytes.fromhex('696700000000666d6b03')
        image[384:400] = bytes(12) + struct.pack('<I', 0x08000120)
        self.image = bytes(image)
        batch['rom_sha1'] = hashlib.sha1(self.image).hexdigest()
        batch['native_spans'] = [s for s in batch['native_spans'] if s['role'] != 'shared_text']
        batch['native_spans'][0]['size'] = 12
        batch['native_spans'][0]['sha256'] = review.sha256(self.image[:12])
        for role, symbol, offset, size in [('shared_script', 'Std_MsgboxSign', 288, 10),
                                           ('standard_script_table', 'gStdScripts', 384, 16)]:
            batch['native_spans'].append(dict(map=None, role=role, symbol=symbol, address=0x08000000 + offset,
                                             size=size, sha256=review.sha256(self.image[offset:offset + size])))
        self.symbols = [(name, value) for name, value in self.symbols if name != 'SharedBraille']
        self.symbols += [('First_Text', 0x0800000A), ('Std_MsgboxSign', 0x08000120), ('gStdScripts', 0x08000180)]
        self.save_manifest()
        self.put('baserom_jp.gba', self.image)
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.map', self.linker_map())
        report = self.progress()
        self.assertEqual(report['reviewed_maps'], 1, report)

    def test_sign_message_requires_the_standard_table_and_the_actual_standard_script(self):
        self.add_sign_fixture()
        batch = self.manifest['batches'][0]
        for field in ('standard_scripts', 'shared_dependencies'):
            original = batch[field]
            batch[field] = []
            self.save_manifest()
            self.assert_not_approved(self.progress())
            batch[field] = original

    def test_sign_table_pointer_must_bind_the_real_native_entry(self):
        self.add_sign_fixture()
        image = bytearray(self.image)
        image[396:400] = struct.pack('<I', 0x08000121)
        self.image = bytes(image)
        batch = self.manifest['batches'][0]
        batch['rom_sha1'] = hashlib.sha1(self.image).hexdigest()
        batch['native_spans'][-1]['sha256'] = review.sha256(self.image[384:400])
        self.save_manifest()
        self.put('baserom_jp.gba', self.image)
        self.put('pokeemerald_jp.gba', self.image)
        self.put('pokeemerald_jp.elf', elf_image(self.image, self.symbols))
        self.put('pokeemerald_jp.map', self.linker_map())
        report = self.progress()
        self.assert_not_approved(report)
        self.assertIn('native_standard_script_target_mismatch:Std_MsgboxSign', report['batches'][0]['errors'])

    def test_standard_table_source_and_native_role_cannot_be_substituted(self):
        self.add_sign_fixture()
        batch = self.manifest['batches'][0]
        batch['native_spans'][-1]['role'] = 'shared_script'
        self.save_manifest()
        self.assert_not_approved(self.progress())
        batch['native_spans'][-1]['role'] = 'standard_script_table'
        batch['sources'] = [c for c in batch['sources'] if not (c['path'] == 'data/event_scripts.s' and c['selector'] == 'asm_labels')]
        self.save_manifest()
        self.assert_not_approved(self.progress())


if __name__ == '__main__':
    unittest.main()
