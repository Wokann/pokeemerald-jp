"""Read audit reference inputs from exact Git blobs, never from unrelated WIP."""
from contextlib import contextmanager
import hashlib
from pathlib import Path, PurePosixPath
import re
import subprocess
import tempfile


def git(repository: Path, *arguments: str) -> bytes:
    result = subprocess.run(['git', '--no-replace-objects', '-C', str(repository), *arguments], capture_output=True)
    if result.returncode:
        raise ValueError('US Git reference unavailable: ' + result.stderr.decode('utf-8', errors='replace').strip())
    return result.stdout


def git_entries(repository: Path, commit: str) -> list[tuple[str, str, str]]:
    """Reject links and unsafe names before materializing any reference files."""
    entries = []
    for record in git(repository, 'ls-tree', '-r', '-z', '--full-tree', commit).split(b'\0'):
        if not record:
            continue
        metadata, raw_name = record.split(b'\t', 1)
        mode, kind, oid = metadata.decode('ascii').split()
        name = raw_name.decode('utf-8')
        path = PurePosixPath(name)
        if (path.is_absolute() or not path.parts or str(path) != name or '\\' in name or ':' in name
                or any(part in ('.', '..', '.git') for part in path.parts)):
            raise ValueError('unsafe_US_Git_path:' + name)
        if kind == 'commit' and mode == '160000':
            # A gitlink is not the checked-out submodule's source tree. Never
            # import live submodule files under a committed-parent claim.
            if path.parts[0] in ('src', 'include', 'asm', 'data', 'graphics', 'sound'):
                raise ValueError('unresolved_US_reference_submodule:' + name)
            continue
        if kind != 'blob' or mode not in ('100644', '100755'):
            raise ValueError('unsupported_US_Git_entry:' + name)
        entries.append((name, mode, oid))
    if not any(name.startswith('src/') for name, mode, oid in entries):
        raise ValueError('US Git reference has no tracked src/ files')
    return entries


def materialize(repository: Path, destination: Path, entries: list[tuple[str, str, str]]) -> str:
    """Use cat-file, not git archive (export-ignore/subst can alter archives)."""
    digest = hashlib.sha256()
    process = subprocess.Popen(['git', '--no-replace-objects', '-C', str(repository), 'cat-file', '--batch'],
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    try:
        for name, mode, oid in entries:
            process.stdin.write((oid + '\n').encode('ascii'))
            process.stdin.flush()
            header = process.stdout.readline().decode('ascii').rstrip('\n').split()
            if len(header) != 3 or header[:2] != [oid, 'blob'] or not header[2].isdigit():
                raise ValueError('invalid_US_Git_blob_response:' + name)
            size = int(header[2])
            data = process.stdout.read(size)
            if len(data) != size or process.stdout.read(1) != b'\n':
                raise ValueError('truncated_US_Git_blob:' + name)
            target = destination / name
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(data)
            digest.update((mode + ' ' + oid + '\t' + name + '\0').encode('utf-8'))
        process.stdin.close()
        if process.wait(timeout=30):
            raise ValueError('US Git blob reader failed')
    finally:
        if process.poll() is None:
            process.kill()
            process.wait()
        for pipe in (process.stdin, process.stdout, process.stderr):
            if not pipe.closed:
                pipe.close()
    return digest.hexdigest()


def temporary_anchor(jp_root: Path) -> Path:
    """Worktrees share their primary checkout's private agent-work directory."""
    root = jp_root.resolve()
    try:
        top = Path(git(root, 'rev-parse', '--show-toplevel').decode('utf-8').strip()).resolve()
        if top != root:
            return root
        common = Path(git(root, 'rev-parse', '--path-format=absolute', '--git-common-dir').decode('utf-8').strip()).resolve()
        if common.name == '.git' and common.is_dir() and (common.parent / 'src').is_dir():
            return common.parent
    except ValueError:
        pass  # Non-Git directory fixtures still use their explicitly supplied root.
    return root


@contextmanager
def us_reference(jp_root: Path, repository: Path, revision: str | None = 'HEAD'):
    """Yield an isolated committed tree, or an explicitly unverified live tree.

    The generated source copy is confined to the JP private temp directory and
    removed on every exit. No worktree, branch, checkout or external cache is
    created. The report records the original repository and resolved commit,
    not the random temporary materialization path.
    """
    repository = repository.resolve()
    if not (repository / 'src').is_dir():
        raise ValueError('US source root is missing src/: ' + str(repository))
    if revision is None:
        yield repository, {
            'mode': 'unverified_worktree', 'repository': str(repository),
            'warning': 'Explicit live worktree input; not a committed pret reference. Generated US artifacts are unverified.',
        }
        return
    top = Path(git(repository, 'rev-parse', '--show-toplevel').decode('utf-8').strip()).resolve()
    if top != repository:
        raise ValueError('US root must be the Git repository root')
    commit = git(repository, 'rev-parse', '--verify', '--end-of-options', revision + '^{commit}').decode('ascii').strip()
    if not re.fullmatch(r'[0-9a-f]{40}|[0-9a-f]{64}', commit):
        raise ValueError('invalid_US_Git_commit')
    tree = git(repository, 'rev-parse', commit + '^{tree}').decode('ascii').strip()
    entries = git_entries(repository, commit)
    anchor = temporary_anchor(jp_root)
    private = (anchor / '.tmp/agent-work/us-reference').resolve()
    if not private.is_relative_to(anchor):
        raise ValueError('external_US_reference_temporary_directory')
    private.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix=commit[:12] + '-', dir=private) as directory:
        snapshot = Path(directory)
        manifest_digest = materialize(repository, snapshot, entries)
        names = {name for name, mode, oid in entries}
        yield snapshot, {
            'mode': 'git_snapshot', 'repository': str(repository), 'requested_revision': revision,
            'commit': commit, 'tree': tree, 'tracked_blob_count': len(entries),
            'tree_entry_manifest_sha256': manifest_digest,
            'source_scope': 'exact_committed_Git_blobs_only; no_worktree_files_or_export_substitution',
            'us_generated_artifacts': {name: ('tracked_Git_blob' if name in names else 'not_in_Git_snapshot')
                                       for name in ('pokeemerald.sym', 'pokeemerald.map')},
        }
