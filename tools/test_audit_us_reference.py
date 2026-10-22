"""US provenance must survive dirty worktrees, replacement refs and cleanup."""
from contextlib import contextmanager
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

try:
    import audit_structure as audit
    import audit_us_reference as reference
except ModuleNotFoundError:
    from tools import audit_structure as audit, audit_us_reference as reference

ROOT = Path(__file__).resolve().parents[1]


def git(root, *args):
    return subprocess.check_output(['git', '-C', str(root), *args], stderr=subprocess.STDOUT)


def commit(root):
    git(root, 'add', '--all')
    git(root, '-c', 'user.name=Reference Test', '-c', 'user.email=reference@example.invalid',
        '-c', 'commit.gpgsign=false', 'commit', '-qm', 'fixture')
    return git(root, 'rev-parse', 'HEAD').decode().strip()


@contextmanager
def fixture():
    parent = ROOT / '.tmp/agent-work/tests'
    parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='us-reference-', dir=parent) as directory:
        root = Path(directory)
        jp, us = root / 'jp', root / 'us'
        jp.mkdir()
        (us / 'src').mkdir(parents=True)
        (us / 'src/main.c').write_text('void Original(void) {}\n')
        git(us, 'init', '-q')
        revision = commit(us)
        yield jp, us, revision


class UsReferenceTests(unittest.TestCase):
    def test_default_uses_committed_blobs_not_dirty_tracked_untracked_or_generated_inputs(self):
        with fixture() as (jp, us, revision):
            (us / 'src/main.c').write_text('void Dirty(void) {}\n')
            (us / 'src/port.c').write_text('void Untracked(void) {}\n')
            (us / 'pokeemerald.sym').write_text('08000100 T 4 Untracked\n')
            (us / 'pokeemerald.map').write_text('script_data 0x08000100 0x20\n')
            state = git(us, 'status', '--porcelain=v1', '-uall')
            with reference.us_reference(jp, us) as (snapshot, proof):
                self.assertEqual((snapshot / 'src/main.c').read_text(), 'void Original(void) {}\n')
                self.assertFalse((snapshot / 'src/port.c').exists())
                self.assertFalse((snapshot / 'pokeemerald.sym').exists())
                self.assertEqual(proof['commit'], revision)
                self.assertEqual(proof['tracked_blob_count'], 1)
                self.assertEqual(proof['mode'], 'git_snapshot')
                self.assertEqual(set(proof['us_generated_artifacts'].values()), {'not_in_Git_snapshot'})
                self.assertTrue(snapshot.is_relative_to(jp / '.tmp/agent-work/us-reference'))
            self.assertFalse(snapshot.exists())
            self.assertEqual(git(us, 'status', '--porcelain=v1', '-uall'), state)

    def test_explicit_historical_commit_does_not_float_to_head(self):
        with fixture() as (jp, us, revision):
            (us / 'src/main.c').write_text('void NewHead(void) {}\n')
            newer = commit(us)
            self.assertNotEqual(revision, newer)
            with reference.us_reference(jp, us, revision) as (snapshot, proof):
                self.assertEqual((snapshot / 'src/main.c').read_text(), 'void Original(void) {}\n')
                self.assertEqual(proof['commit'], revision)
            with reference.us_reference(jp, us) as (snapshot, proof):
                self.assertEqual((snapshot / 'src/main.c').read_text(), 'void NewHead(void) {}\n')
                self.assertEqual(proof['commit'], newer)

    def test_export_ignore_and_export_substitution_cannot_change_the_reference(self):
        with fixture() as (jp, us, revision):
            (us / '.gitattributes').write_text('src/main.c export-ignore\nsrc/format.c export-subst\n')
            literal = 'const char *s = "$Format:%H$";\n'
            (us / 'src/format.c').write_text(literal)
            commit(us)
            with reference.us_reference(jp, us) as (snapshot, proof):
                self.assertTrue((snapshot / 'src/main.c').is_file())
                self.assertEqual((snapshot / 'src/format.c').read_text(), literal)

    def test_local_replacement_refs_cannot_substitute_other_commit_contents(self):
        with fixture() as (jp, us, revision):
            (us / 'src/main.c').write_text('void Replacement(void) {}\n')
            newer = commit(us)
            git(us, 'replace', revision, newer)
            with reference.us_reference(jp, us, revision) as (snapshot, proof):
                self.assertEqual((snapshot / 'src/main.c').read_text(), 'void Original(void) {}\n')
                self.assertEqual(proof['commit'], revision)

    def test_real_git_blob_binary_and_spaces_survive_without_encoding_or_mode_substitution(self):
        with fixture() as (jp, us, revision):
            binary = bytes(range(256)) + b'\0\r\n\xff'
            (us / 'src/a name.h').write_bytes(binary)
            commit(us)
            with reference.us_reference(jp, us) as (snapshot, proof):
                self.assertEqual((snapshot / 'src/a name.h').read_bytes(), binary)
                self.assertEqual(proof['tracked_blob_count'], 2)

    def test_links_and_path_traversal_are_rejected_without_materializing_outside_the_snapshot(self):
        with fixture() as (jp, us, revision):
            os.symlink('/etc/passwd', us / 'src/link.h')
            commit(us)
            with self.assertRaisesRegex(ValueError, 'unsupported_US_Git_entry:src/link.h'):
                with reference.us_reference(jp, us):
                    self.fail('unsafe reference was accepted')
            for name in ('../escape.c', '/escape.c', 'src/../escape.c', 'src\\escape.c', '.git/config'):
                response = ('100644 blob ' + '1' * 40 + '\t' + name + '\0').encode()
                with mock.patch.object(reference, 'git', return_value=response), self.assertRaisesRegex(ValueError, 'unsafe_US_Git_path'):
                    reference.git_entries(us, revision)

    def test_unknown_or_option_shaped_refs_fail_closed_and_never_fall_back_to_live_files(self):
        with fixture() as (jp, us, revision):
            for name in ('missing-ref', '--help'):
                with self.subTest(name=name), self.assertRaisesRegex(ValueError, 'US Git reference unavailable'):
                    with reference.us_reference(jp, us, name):
                        self.fail('unknown revision accepted')
            plain = jp / 'plain/src'
            plain.mkdir(parents=True)
            with self.assertRaises(ValueError):
                with reference.us_reference(jp, plain.parent):
                    self.fail('non-Git tree silently accepted')

    def test_explicit_worktree_is_labelled_unverified_and_does_not_create_a_snapshot(self):
        with fixture() as (jp, us, revision):
            (us / 'src/main.c').write_text('void Worktree(void) {}\n')
            with reference.us_reference(jp, us, None) as (snapshot, proof):
                self.assertEqual(snapshot, us)
                self.assertEqual(proof['mode'], 'unverified_worktree')
                self.assertNotIn('commit', proof)
                self.assertIn('not a committed pret reference', proof['warning'])
            self.assertFalse((jp / '.tmp').exists())

    def test_snapshot_is_removed_even_when_the_report_consumer_raises(self):
        with fixture() as (jp, us, revision):
            with self.assertRaisesRegex(RuntimeError, 'consumer failure'):
                with reference.us_reference(jp, us) as (snapshot, proof):
                    raise RuntimeError('consumer failure')
            self.assertFalse(snapshot.exists())

    def test_report_wrapper_uses_snapshot_and_keeps_json_stable_without_temporary_paths(self):
        with fixture() as (jp, us, revision):
            def inventory(root, reference_root):
                self.assertEqual((reference_root / 'src/main.c').read_text(), 'void Original(void) {}\n')
                return {'roots': {'jp': str(root), 'us': str(reference_root)}}
            with mock.patch.object(audit, '_build_report', side_effect=inventory):
                first = audit.build_report(jp, us)
                second = audit.build_report(jp, us)
            self.assertEqual(first, second)
            self.assertEqual(first['roots']['us'], str(us))
            self.assertEqual(first['us_reference']['commit'], revision)
            self.assertNotIn('/us-reference/' + revision[:12] + '-', json.dumps(first))

    def test_private_snapshot_directory_cannot_escape_the_jp_project_through_a_symlink(self):
        with fixture() as (jp, us, revision):
            outside = us.parent / 'outside'
            outside.mkdir()
            private = jp / '.tmp/agent-work'
            private.mkdir(parents=True)
            os.symlink(outside, private / 'us-reference')
            with self.assertRaisesRegex(ValueError, 'external_US_reference_temporary_directory'):
                with reference.us_reference(jp, us):
                    self.fail('external temporary directory accepted')
            self.assertEqual(list(outside.iterdir()), [])

    def test_a_nested_directory_cannot_implicitly_use_another_repository_root(self):
        with fixture() as (jp, us, revision):
            (us / 'nested/src').mkdir(parents=True)
            with self.assertRaisesRegex(ValueError, 'US root must be the Git repository root'):
                with reference.us_reference(jp, us / 'nested'):
                    self.fail('wrong repository root accepted')

    def test_cli_can_pin_a_ref_or_explicitly_opt_into_the_unverified_worktree(self):
        with fixture() as (jp, us, revision):
            for arguments, expected in (([], 'HEAD'), (['--us-ref', revision], revision), (['--us-worktree'], None)):
                with mock.patch.object(sys, 'argv', ['audit_structure.py', '--json', '--us-root', str(us), *arguments]), \
                     mock.patch.object(audit, 'build_report', return_value={'ok': True}) as build, \
                     mock.patch.object(sys, 'stdout', io.StringIO()):
                    audit.main()
                build.assert_called_once_with(audit.ROOT, us.resolve(), us_ref=expected)
            with mock.patch.object(sys, 'argv', ['audit_structure.py', '--us-ref', revision, '--us-worktree']), \
                 mock.patch.object(sys, 'stderr', io.StringIO()), self.assertRaises(SystemExit):
                audit.main()

    def test_missing_us_binary_artifacts_are_unknown_not_zero_or_negative_matches(self):
        with fixture() as (jp, us, revision):
            report = {'roots': {}, 'functions': {'us_binary_only_addresses': 0,
                      'ownership': [{'us_binary_symbol': False}]},
                      'script_data': {'linked_sections': {'us': {'section': None, 'objects': []}}}}
            with mock.patch.object(audit, '_build_report', return_value=report):
                result = audit.build_report(jp, us)
            self.assertIsNone(result['functions']['us_binary_only_addresses'])
            self.assertIsNone(result['functions']['ownership'][0]['us_binary_symbol'])
            self.assertEqual(result['functions']['us_binary_symbol_evidence']['status'], 'unavailable')
            self.assertEqual(result['script_data']['linked_sections']['us']['evidence_status'], 'unavailable')

    def test_worktree_materialization_uses_the_primary_checkout_private_directory(self):
        with fixture() as (jp, us, revision):
            (jp / 'src').mkdir()
            (jp / 'src/main.c').write_text('void Jp(void) {}\n')
            git(jp, 'init', '-q')
            commit(jp)
            worker = jp.parent / 'jp-worker'
            git(jp, 'worktree', 'add', '--detach', str(worker), 'HEAD')
            with reference.us_reference(worker, us) as (snapshot, proof):
                self.assertTrue(snapshot.is_relative_to(jp / '.tmp/agent-work/us-reference'))
                self.assertFalse((worker / '.tmp').exists())
            self.assertFalse(snapshot.exists())


if __name__ == '__main__':
    unittest.main()
