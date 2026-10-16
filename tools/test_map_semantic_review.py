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
            owner = ('data/event_scripts.o' if span['role'] in ('scripts', 'shared_script')
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
        self.assertEqual(self.progress()['reviewed_maps'], 1)

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


if __name__ == '__main__':
    unittest.main()
