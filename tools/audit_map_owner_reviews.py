#!/usr/bin/env python3
"""Validate project-owned map/shared-owner review evidence, without granting parity.

Schema v1 is deliberately conservative: it NEVER emits reviewed_current. Literal
include discovery cannot prove the complete C, macro, linker, or cross-script
dependency graph. Even fresh evidence remains partial with
manual_dependency_scope_unverified. Human declarations are reported separately
from executed checks; no file presence, label count, or supplied "passed" flag
constitutes a semantic review. Historical commit bodies are not imported.

Manifest shape (all listed keys required, no extra keys accepted):
  schema_version: 1
  rom: {size: integer, sha256: lowercase SHA256}
  owners: [{id: "map:Name" or "shared:Name",
    jp_sources: {project-relative path: SHA256}, us_sources: {path: SHA256},
    dependency_roots: {jp: [source paths], us: [source paths]},
    spans: [{kind: script/events/header/text/movement/data,
             start: ROM address, end: exclusive ROM address, sha256: SHA256}],
    shared_dependencies: ["shared:Name"],
    events: null or {map_json: path, events_inc: path},
    labels: null or {jp: path, us: path, jp_only: [labels], us_only: [labels]},
    manual_review: {script_semantics: declaration, jp_differences: declaration,
                    text_semantics: declaration, unreviewed_text: [descriptions]}
  }]
Each declaration is {state: reviewed/not_reviewed, reviewer: string,
  summary: string, evidence: [{tree: jp/us, path: source path,
                             start_line: integer, end_line: inclusive integer}]}.

Source hashes and literal include sets are checked on every invocation. ROM span
hashes and optional built-ROM byte comparisons are deterministic checks, NOT
proof of source-to-ROM binding or build provenance. Label comparison establishes
only names/order. --run-generation-check invokes ONLY the fixed project mapjson
binary in a temporary output directory; no manifest command is ever executed.
Paths must stay inside the selected JP/US roots, including symlink resolution.
There is no writer, hash refresh, ROM extraction, or agent-log storage facility.

Usage: python3 tools/audit_map_owner_reviews.py --manifest audits/reviews.json
       --us-root /path/to/pokeemerald --json
Optional: --rom baserom_jp.gba --built-rom pokeemerald_jp.gba
          --run-generation-check --require-current
No manifest preserves not_recorded without reading ROM/build inputs.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
import tempfile
from collections import Counter
from pathlib import Path, PurePosixPath


ROOT = Path(__file__).resolve().parents[1]
US_ROOT_CANDIDATES = (ROOT.parent / "pokeemerald", ROOT.parent.parent / "pokeemerald")
DEFAULT_US_ROOT = next((x for x in US_ROOT_CANDIDATES if (x / "src").is_dir()), US_ROOT_CANDIDATES[0])
ROM_BASE = 0x08000000
MAX_ROM = 32 * 1024 * 1024
MAX_SOURCE = 8 * 1024 * 1024
MAX_MANIFEST = 4 * 1024 * 1024
OWNER_RE = re.compile(r"^(map|shared):[A-Za-z][A-Za-z0-9_]*$")
SYMBOL_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
HASH_RE = re.compile(r"^[0-9a-f]{64}$")
LABEL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*):{1,2}\s*(?:@.*)?$", re.M)
INCLUDE_RE = re.compile(r'^\s*\.include\s+"([^"]+)"\s*(?:@.*)?$', re.M)
C_INCLUDE_RE = re.compile(r'^\s*#\s*include\s*["<]([^">]+)[">]', re.M)
GATES = ("script_semantics", "jp_differences", "text_semantics")
TRUST_BOUNDARY = (
    "Human semantic declarations are attestations, not machine-proven parity. "
    "Schema v1 cannot prove full dependency scope or source-to-ROM binding; "
    "no record is promoted to reviewed_current."
)


class ManifestError(ValueError):
    """Invalid or unsafe review input."""


def fields(value, expected, where):
    if not isinstance(value, dict) or set(value) != set(expected):
        raise ManifestError(f"{where}: expected exactly {', '.join(sorted(expected))}")


def integer(value, low, high, where):
    if type(value) is not int or not low <= value <= high:
        raise ManifestError(f"{where}: integer outside [{low}, {high}]")


def string(value, where, *, nonempty=False):
    if (not isinstance(value, str) or len(value) > 4096 or "\x00" in value
            or (nonempty and not value.strip())):
        raise ManifestError(f"{where}: invalid string")


def path_name(value):
    string(value, "path", nonempty=True)
    path = PurePosixPath(value)
    if (not path.parts or path.is_absolute() or "\\" in value or ":" in value
            or path.as_posix() != value or any(x in (".", "..") or x.startswith(".")
                                             for x in path.parts)):
        raise ManifestError("path must be a normalized, non-hidden project-relative path")
    return value


def project_path(root, value):
    relative = path_name(value)
    resolved = (root / relative).resolve()
    if not resolved.is_relative_to(root.resolve()):
        raise ManifestError(f"path escapes project root: {relative}")
    return resolved


def digest(value):
    if not isinstance(value, str) or HASH_RE.fullmatch(value) is None:
        raise ManifestError("expected a lowercase 64-digit SHA256")


def unique_list(value, where, *, nonempty=False):
    if (not isinstance(value, list) or len(value) > 8192
            or any(not isinstance(x, str) for x in value)
            or len(set(value)) != len(value) or (nonempty and not value)):
        raise ManifestError(f"{where}: expected a bounded list of unique strings")
    for item in value:
        string(item, where, nonempty=True)


def source_hashes(value, where):
    if not isinstance(value, dict) or not value or len(value) > 8192:
        raise ManifestError(f"{where}: missing or invalid dependency source hashes")
    for path, sha in value.items():
        path_name(path)
        digest(sha)


def validate_manifest(data):
    fields(data, ("schema_version", "rom", "owners"), "manifest")
    if type(data["schema_version"]) is not int or data["schema_version"] != 1:
        raise ManifestError("unsupported schema_version")
    fields(data["rom"], ("size", "sha256"), "rom")
    integer(data["rom"]["size"], 1, MAX_ROM, "ROM size")
    digest(data["rom"]["sha256"])
    owners = data["owners"]
    if not isinstance(owners, list) or len(owners) > 1024:
        raise ManifestError("owners must be a bounded list")
    ids, ranges = set(), []
    for owner in owners:
        fields(owner, ("id", "jp_sources", "us_sources", "dependency_roots", "spans",
                       "shared_dependencies", "events", "labels", "manual_review"), "owner")
        name = owner["id"]
        if not isinstance(name, str) or OWNER_RE.fullmatch(name) is None or name in ids:
            raise ManifestError("invalid or duplicate owner id")
        ids.add(name)
        for tree in ("jp", "us"):
            source_hashes(owner[tree + "_sources"], tree + "_sources")
        fields(owner["dependency_roots"], ("jp", "us"), "dependency_roots")
        for tree, roots in owner["dependency_roots"].items():
            unique_list(roots, "dependency_roots", nonempty=True)
            if any(path not in owner[tree + "_sources"] for path in roots):
                raise ManifestError("dependency root is not in the hashed source set")
        unique_list(owner["shared_dependencies"], "shared_dependencies")
        if any(not x.startswith("shared:") or OWNER_RE.fullmatch(x) is None or x == name
               for x in owner["shared_dependencies"]):
            raise ManifestError("invalid shared dependency")
        spans = owner["spans"]
        if not isinstance(spans, list) or not spans or len(spans) > 8192:
            raise ManifestError("spans must be a nonempty bounded list")
        for span in spans:
            fields(span, ("kind", "start", "end", "sha256"), "span")
            if span["kind"] not in ("script", "events", "header", "text", "movement", "data"):
                raise ManifestError("invalid span kind")
            integer(span["start"], ROM_BASE, ROM_BASE + data["rom"]["size"] - 1, "span start")
            integer(span["end"], span["start"] + 1, ROM_BASE + data["rom"]["size"], "span end")
            digest(span["sha256"])
            ranges.append((span["start"], span["end"], name))
        events = owner["events"]
        if events is not None:
            fields(events, ("map_json", "events_inc"), "events")
            if not name.startswith("map:"):
                raise ManifestError("shared owners cannot declare map generation")
            prefix = "data/maps/" + name.split(":", 1)[1] + "/"
            if events != {"map_json": prefix + "map.json", "events_inc": prefix + "events.inc"}:
                raise ManifestError("event generation must use this map's canonical source pair")
            if any(x not in owner["jp_sources"] for x in events.values()):
                raise ManifestError("event generation sources must be hashed")
        labels = owner["labels"]
        if labels is not None:
            fields(labels, ("jp", "us", "jp_only", "us_only"), "labels")
            for tree in ("jp", "us"):
                path_name(labels[tree])
                if labels[tree] not in owner[tree + "_sources"]:
                    raise ManifestError("label comparison source must be hashed")
                unique_list(labels[tree + "_only"], "label exceptions")
                if any(SYMBOL_RE.fullmatch(x) is None for x in labels[tree + "_only"]):
                    raise ManifestError("invalid label exception")
        manual = owner["manual_review"]
        fields(manual, (*GATES, "unreviewed_text"), "manual_review")
        unique_list(manual["unreviewed_text"], "unreviewed_text")
        for gate in GATES:
            declaration = manual[gate]
            fields(declaration, ("state", "reviewer", "summary", "evidence"), gate)
            if declaration["state"] not in ("reviewed", "not_reviewed"):
                raise ManifestError("manual state must be reviewed or not_reviewed, never passed")
            string(declaration["reviewer"], "reviewer")
            string(declaration["summary"], "review summary")
            if not isinstance(declaration["evidence"], list) or len(declaration["evidence"]) > 8192:
                raise ManifestError("invalid evidence list")
            for anchor in declaration["evidence"]:
                fields(anchor, ("tree", "path", "start_line", "end_line"), "evidence anchor")
                if anchor["tree"] not in ("jp", "us"):
                    raise ManifestError("invalid evidence tree")
                path_name(anchor["path"])
                if anchor["path"] not in owner[anchor["tree"] + "_sources"]:
                    raise ManifestError("evidence source is not hashed")
                integer(anchor["start_line"], 1, 1000000, "evidence start_line")
                integer(anchor["end_line"], anchor["start_line"], 1000000, "evidence end_line")
    ranges.sort()
    for previous, current in zip(ranges, ranges[1:]):
        if current[0] < previous[1]:
            raise ManifestError(f"overlapping or duplicate ROM spans: {previous[2]}, {current[2]}")
    by_id = {x["id"]: x for x in owners}
    visiting, visited = set(), set()

    def visit(name):
        if name in visiting:
            raise ManifestError("cyclic shared dependencies")
        if name in visited or name not in by_id:
            return
        visiting.add(name)
        for child in by_id[name]["shared_dependencies"]:
            visit(child)
        visiting.remove(name)
        visited.add(name)

    for name in sorted(by_id):
        visit(name)
    return data


def reject_duplicate_keys(pairs):
    result = {}
    for key, value in pairs:
        if key in result:
            raise ManifestError(f"duplicate JSON key: {key}")
        result[key] = value
    return result


def load_manifest(path):
    with path.open("rb") as stream:
        raw = stream.read(MAX_MANIFEST + 1)
    if len(raw) > MAX_MANIFEST:
        raise ManifestError("manifest exceeds size limit")
    return validate_manifest(json.loads(
        raw.decode("utf-8"), object_pairs_hook=reject_duplicate_keys,
        parse_constant=lambda x: (_ for _ in ()).throw(ManifestError("invalid JSON constant"))))


def sha256(raw):
    return hashlib.sha256(raw).hexdigest()


def read_project_file(root, relative, limit=MAX_SOURCE):
    path = project_path(root, relative)
    if not path.is_file():
        return None
    with path.open("rb") as stream:
        raw = stream.read(limit + 1)
    if len(raw) > limit:
        raise ManifestError(f"input exceeds size limit: {relative}")
    return raw


def discover_includes(root, roots):
    """Literal includes only; ALL preprocessor branches, never a full dependency proof."""
    pending, found, issues = list(roots), set(), set()
    while pending:
        name = pending.pop()
        if name in found:
            continue
        found.add(name)
        if len(found) > 8192:
            raise ManifestError("include graph exceeds size limit")
        raw = read_project_file(root, name)
        if raw is None:
            issues.add("missing_include_source:" + name)
            continue
        try:
            text = raw.decode("utf-8")
        except UnicodeDecodeError:
            issues.add("non_text_dependency:" + name)
            continue
        for match in INCLUDE_RE.finditer(text):
            pending.append(path_name(match.group(1)))
        c_matches = list(C_INCLUDE_RE.finditer(text))
        if len(c_matches) != len(re.findall(r"^\s*#\s*include\b", text, re.M)):
            issues.add("nonliteral_include:" + name)
        if len(list(INCLUDE_RE.finditer(text))) != len(re.findall(r"^\s*\.include\b", text, re.M)):
            issues.add("nonliteral_include:" + name)
        for match in c_matches:
            included = path_name(match.group(1))
            candidates = sorted({(PurePosixPath(name).parent / included).as_posix(),
                                 included, "include/" + included})
            present = [x for x in candidates if project_path(root, x).is_file()]
            if len(present) != 1:
                issues.add("unresolved_or_ambiguous_include:" + name + ":" + included)
            else:
                pending.append(present[0])
    return sorted(found), sorted(issues)


def compare_labels(owner, blobs):
    spec = owner["labels"]
    if spec is None:
        return {"status": "not_run"}
    lists = {}
    for tree in ("jp", "us"):
        raw = blobs[tree].get(spec[tree])
        if raw is None:
            return {"status": "unavailable"}
        lists[tree] = LABEL_RE.findall(raw.decode("utf-8"))
    if any(not values or len(values) != len(set(values)) for values in lists.values()):
        return {"status": "failed", "reason": "empty_or_duplicate_labels"}
    jp, us = lists["jp"], lists["us"]
    jp_only, us_only = set(jp) - set(us), set(us) - set(jp)
    common = [x for x in jp if x in set(us)] == [x for x in us if x in set(jp)]
    equal = (common and jp_only == set(spec["jp_only"]) and us_only == set(spec["us_only"]))
    return {"status": "passed" if equal else "failed", "jp_only": sorted(jp_only),
            "us_only": sorted(us_only), "common_order_matches": common,
            "scope": "names/order and declared exceptions only; not semantic equivalence"}


def compare_events(root, owner, run_generation):
    spec = owner["events"]
    if spec is None:
        return {"status": "not_applicable" if owner["id"].startswith("shared:") else "not_run"}
    if not run_generation:
        return {"status": "not_run"}
    generator = project_path(root, "tools/mapjson/mapjson")
    source = project_path(root, spec["map_json"])
    expected = read_project_file(root, spec["events_inc"])
    if not generator.is_file() or not source.is_file() or expected is None:
        return {"status": "unavailable"}
    with tempfile.TemporaryDirectory(prefix="jp-review-events-") as temporary:
        result = subprocess.run([str(generator), "events", "emerald", str(source), temporary],
                                cwd=root, capture_output=True, check=False, timeout=30)
        generated = Path(temporary) / "events.inc"
        if result.returncode or not generated.is_file():
            return {"status": "failed", "reason": "fixed_mapjson_generation_failed"}
        actual = generated.read_bytes()
    return {"status": "passed" if actual == expected else "failed",
            "expected_sha256": sha256(expected), "generated_sha256": sha256(actual),
            "generator_sha256": sha256(generator.read_bytes()),
            "scope": "generated source equality only; not ROM or semantic equivalence"}


def manual_checks(owner, blobs, stale):
    result = {}
    for gate in GATES:
        declaration = owner["manual_review"][gate]
        status = "not_reviewed"
        if declaration["state"] == "reviewed":
            evidence = declaration["evidence"]
            valid = bool(declaration["reviewer"].strip() and declaration["summary"].strip()
                         and {x["tree"] for x in evidence} == {"jp", "us"})
            for anchor in evidence:
                raw = blobs[anchor["tree"]].get(anchor["path"])
                valid = valid and raw is not None and anchor["end_line"] <= len(raw.splitlines())
            status = "stale" if stale else ("declared_current" if valid else "incomplete_evidence")
        result[gate] = {"status": status, "reviewer": declaration["reviewer"],
                        "scope": "human attestation; not executable semantic proof"}
    return result


def empty_report():
    return {"schema_version": 1, "semantic_review": "not_recorded", "trust_boundary": TRUST_BOUNDARY,
            "summary": {"manifest_records": 0, "status_counts": {}, "reviewed_map_names": [],
                        "reviewed_shared_owners": []}, "records": []}


def audit_reviews(root, us_root, manifest=None, *, rom_path="baserom_jp.gba",
                  built_rom_path=None, run_generation=False):
    report = empty_report()
    if manifest is None:
        return report
    root, us_root = Path(root).resolve(), Path(us_root).resolve()
    data = load_manifest(project_path(root, manifest))
    if not data["owners"]:
        return report
    rom = read_project_file(root, rom_path, MAX_ROM)
    built = read_project_file(root, built_rom_path, MAX_ROM) if built_rom_path else None
    rom_ok = rom is not None and len(rom) == data["rom"]["size"] and sha256(rom) == data["rom"]["sha256"]
    rom_state = "unavailable" if rom is None else ("passed" if rom_ok else "failed")
    for owner in sorted(data["owners"], key=lambda x: x["id"]):
        issues = {"manual_dependency_scope_unverified", "source_to_rom_binding_unverified"}
        blobs, freshness, dependencies = {}, {}, {}
        stale = False
        for tree, base in (("jp", root), ("us", us_root)):
            blobs[tree], freshness[tree] = {}, []
            expected = owner[tree + "_sources"]
            for path, expected_hash in sorted(expected.items()):
                raw = read_project_file(base, path)
                blobs[tree][path] = raw
                current = sha256(raw) if raw is not None else None
                fresh = current == expected_hash
                stale |= not fresh
                freshness[tree].append({"path": path, "sha256": current,
                                        "status": "current" if fresh else "stale"})
            found, missing = discover_includes(base, owner["dependency_roots"][tree])
            dependencies[tree] = found
            issues.update(tree + ":" + x for x in missing)
            issues.update(tree + ":unhashed_include:" + x for x in set(found) - set(expected))
        if stale:
            issues.add("source_hash_stale_or_missing")
        spans = []
        for span in sorted(owner["spans"], key=lambda x: x["start"]):
            start, end = span["start"] - ROM_BASE, span["end"] - ROM_BASE
            expected = rom[start:end] if rom_ok else None
            span_state = ("unavailable" if expected is None else
                          ("passed" if sha256(expected) == span["sha256"] else "failed"))
            built_state = ("not_run" if built is None else
                           ("unavailable" if expected is None else
                            ("passed" if end <= len(built) and built[start:end] == expected else "failed")))
            spans.append({**span, "rom_hash_check": span_state, "built_rom_equality": built_state})
        labels = compare_labels(owner, blobs)
        events = compare_events(root, owner, run_generation)
        # Generation reads live inputs. Refuse evidence from a changing source
        # snapshot rather than silently trusting the earlier cached contents.
        for tree, base in (("jp", root), ("us", us_root)):
            for source in freshness[tree]:
                latest = read_project_file(base, source["path"])
                current = sha256(latest) if latest is not None else None
                if current != source["sha256"]:
                    stale = True
                    issues.add("source_snapshot_changed")
                    source.update(sha256=current, status="stale")
        if stale:
            issues.add("source_hash_stale_or_missing")
        manual = manual_checks(owner, blobs, stale)
        if owner["manual_review"]["unreviewed_text"]:
            issues.add("unreviewed_text")
        for gate, check in manual.items():
            if check["status"] != "declared_current":
                issues.add(gate + ":" + check["status"])
        machine_states = [rom_state, labels["status"], events["status"]]
        machine_states.extend(x[key] for x in spans for key in ("rom_hash_check", "built_rom_equality"))
        if any(x in ("not_run", "unavailable") for x in machine_states):
            issues.add("deterministic_checks_incomplete")
        status = "failed" if "failed" in machine_states else ("stale" if stale else "partial")
        report["records"].append({"id": owner["id"], "status": status, "issues": sorted(issues),
                                  "source_freshness": freshness, "literal_include_inputs": dependencies,
                                  "machine_checks": {"rom_identity": rom_state, "spans": spans,
                                                     "label_order": labels, "json_events_equal": events},
                                  "manual_checks": manual,
                                  "unreviewed_text": owner["manual_review"]["unreviewed_text"],
                                  "shared_dependencies": sorted(owner["shared_dependencies"])})
    by_id = {x["id"]: x for x in report["records"]}
    for record in report["records"]:
        issues = set(record["issues"])
        for dependency in record["shared_dependencies"]:
            issues.add(("missing_shared_review:" if dependency not in by_id else
                        "shared_dependency_not_reviewed:") + dependency)
        record["issues"] = sorted(issues)
    counts = Counter(x["status"] for x in report["records"])
    report["semantic_review"] = "failed" if counts["failed"] else ("stale" if counts["stale"] else "partial")
    report["summary"].update(manifest_records=len(report["records"]), status_counts=dict(sorted(counts.items())))
    return report


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--us-root", type=Path, default=DEFAULT_US_ROOT)
    parser.add_argument("--manifest", help="project-relative review JSON; absent means not_recorded")
    parser.add_argument("--rom", default="baserom_jp.gba", help="project-relative authoritative ROM")
    parser.add_argument("--built-rom", help="project-relative built ROM; no source provenance is inferred")
    parser.add_argument("--run-generation-check", action="store_true", help="run ONLY fixed project mapjson")
    parser.add_argument("--require-current", action="store_true", help="fail unrecorded/partial reviews (all schema v1 records)")
    parser.add_argument("--json", action="store_true", help="deterministic complete JSON")
    args = parser.parse_args(argv)
    try:
        report = audit_reviews(args.root, args.us_root, args.manifest, rom_path=args.rom,
                               built_rom_path=args.built_rom, run_generation=args.run_generation_check)
    except (ValueError, OSError, RecursionError, subprocess.SubprocessError) as exc:
        report = {**empty_report(), "semantic_review": "invalid_manifest", "errors": [str(exc)]}
    if args.json:
        print(json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True))
    else:
        print("semantic_review: " + report["semantic_review"])
        print("manifest_records: " + str(report["summary"]["manifest_records"]))
        for record in report["records"]:
            print(record["id"] + ": " + record["status"] + " (" + ", ".join(record["issues"]) + ")")
        for error in report.get("errors", []):
            print("ERROR: " + error)
        print(TRUST_BOUNDARY)
    if report["semantic_review"] == "invalid_manifest":
        return 2
    return int(args.require_current or any(x["status"] in ("failed", "stale") for x in report["records"]))


if __name__ == "__main__":
    raise SystemExit(main())
