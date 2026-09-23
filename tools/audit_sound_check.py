#!/usr/bin/env python3
"""Validate the JP-only Sound Check module without extracting ROM data.

The Sound Check UI occupies one fixed code slice.  A future source migration
can use this read-only audit to prove that the linked candidate preserves the
slice, exports the intended neutral symbols at their original addresses, keeps
the fixed RAM allocations, and has removed the misleading legacy aliases.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROM_BASE = 0x08000000
CODE_START = 0x080E82DC
CODE_END = 0x080E977C
CODE_SHA256 = "030fdc725465e2ea9b852bd9404b327b547ff654b4768e9190c97b12581b7414"

CODE_SYMBOLS = {
    "CB2_SoundCheck": 0x080E82DC,
    "VBlankCB_SoundCheck": 0x080E82F4,
    "CB2_InitSoundCheck": 0x080E8320,
    "Task_SoundCheck": 0x080E84A4,
    "SoundCheck_PutWindowTilemapAndCopy": 0x080E9734,
    "SoundCheck_ClearAndRemoveWindow": 0x080E9750,
}
EWRAM_SYMBOLS = (
    ("sSoundCheckAudioUpdateEnabled", 0x02039CBC, 1),
    ("sSoundCheckCryPlaying", 0x02039CBD, 1),
    ("sSoundCheckCryState", 0x02039CBE, 2),
    ("sSoundCheckState", 0x02039CC0, 0x24),
    ("sSoundCheckReverseCry", 0x02039CE4, 1),
    ("sSoundCheckStereoState", 0x02039CE5, 3),
)
IWRAM_SYMBOLS = (("sSoundCheckCryPlayer", 0x03005E1C, 4),)
LEGACY_FUNCMAP_ALIASES = (
    "SanitizeRubyBattleTowerRecord",
    "SanitizeDayCareMailForRuby",
    "DrawTrainerCardWindow",
    "sub_080E82F4",
    "sub_080E8320",
    "sub_080E9734",
    "sub_080E9750",
)
LEGACY_SOURCE_ALIASES = (
    "SPECIAL_InitSecretBaseVars",
    "SPECIAL_CheckLeadMonTough",
    "SPECIAL_FoundAbandonedShipRoom1Key",
)
MAP_SYMBOL_RE = re.compile(r"^\s*0x([0-9A-Fa-f]+)\s+([A-Za-z_]\w*)\s*$", re.MULTILINE)


class AuditError(ValueError):
    """The Sound Check source or linked candidate violates its contract."""


def fail(message: str) -> None:
    raise AuditError(f"audit_sound_check: {message}")


def rom_slice(data: bytes, start: int, end: int) -> bytes:
    if start < ROM_BASE or end < start or end - ROM_BASE > len(data):
        fail(f"ROM does not contain 0x{start:08X}..0x{end:08X}")
    return data[start - ROM_BASE:end - ROM_BASE]


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def audit_baseline(data: bytes) -> dict[str, object]:
    code = rom_slice(data, CODE_START, CODE_END)
    digest = sha256(code)
    if digest != CODE_SHA256:
        fail(f"Sound Check SHA-256 is {digest}, expected {CODE_SHA256}")
    return {
        "format": 1,
        "code": {
            "start": f"0x{CODE_START:08X}",
            "end": f"0x{CODE_END:08X}",
            "size": CODE_END - CODE_START,
            "sha256": digest,
        },
        "symbols": {name: f"0x{address:08X}" for name, address in CODE_SYMBOLS.items()},
        "ewram": [symbol_dict(symbol) for symbol in EWRAM_SYMBOLS],
        "iwram": [symbol_dict(symbol) for symbol in IWRAM_SYMBOLS],
    }


def symbol_dict(symbol: tuple[str, int, int]) -> dict[str, object]:
    name, address, size = symbol
    return {"name": name, "address": f"0x{address:08X}", "size": size}


def parse_map_symbols(path: Path) -> dict[str, list[int]]:
    result: dict[str, list[int]] = {}
    for address, name in MAP_SYMBOL_RE.findall(path.read_text(encoding="utf-8", errors="replace")):
        result.setdefault(name, []).append(int(address, 16))
    return result


def check_map(path: Path) -> dict[str, object]:
    symbols = parse_map_symbols(path)
    expected = list(CODE_SYMBOLS.items())
    expected.extend((name, address) for name, address, _ in EWRAM_SYMBOLS)
    expected.extend((name, address) for name, address, _ in IWRAM_SYMBOLS)
    for name, address in expected:
        if symbols.get(name) != [address]:
            fail(f"{path} must define {name} exactly once at 0x{address:08X}; found {symbols.get(name, [])}")
    legacy = [name for name in LEGACY_FUNCMAP_ALIASES if name in symbols]
    if legacy:
        fail(f"{path} still exports legacy Sound Check aliases: {', '.join(legacy)}")
    return {"path": str(path), "checked_symbols": len(expected)}


def check_ram_symbols(path: Path, expected: tuple[tuple[str, int, int], ...]) -> dict[str, object]:
    """Verify linker allocation order and size in a ``sym_*_jp.txt`` file."""
    text = path.read_text(encoding="utf-8", errors="replace")
    for name, address, size in expected:
        label = re.compile(
            rf"^{re.escape(name)}\s*=\s*\.\s*;\s*\n\s*\.\s*\+=\s*(0x[0-9A-Fa-f]+|\d+)\s*;",
            re.MULTILINE,
        )
        match = label.search(text)
        if match is None:
            fail(f"{path} has no size allocation for {name}")
        actual_size = int(match.group(1), 0)
        if actual_size != size:
            fail(f"{path} allocates {name} as {actual_size:#x}, expected {size:#x} at 0x{address:08X}")
    return {"path": str(path), "checked_symbols": len(expected)}


def check_funcmap(path: Path) -> dict[str, object]:
    text = path.read_text(encoding="utf-8", errors="replace")
    for legacy in LEGACY_FUNCMAP_ALIASES:
        if legacy in text:
            fail(f"{path} still contains legacy funcmap alias {legacy}")
    for name, address in CODE_SYMBOLS.items():
        row = re.compile(rf"^{address:08x}\s+.*\b{re.escape(name)}\b.*$", re.IGNORECASE | re.MULTILINE)
        if row.search(text) is None:
            fail(f"{path} has no Sound Check funcmap row for {name} at 0x{address:08X}")
    return {"path": str(path), "checked_symbols": len(CODE_SYMBOLS)}


def check_source(path: Path) -> dict[str, object]:
    text = path.read_text(encoding="utf-8", errors="replace")
    for legacy in LEGACY_SOURCE_ALIASES:
        if legacy in text:
            fail(f"{path} still uses misleading Special alias {legacy}")
    for name in CODE_SYMBOLS:
        if name not in text:
            fail(f"{path} does not define expected Sound Check symbol {name}")
    return {"path": str(path), "checked_symbols": len(CODE_SYMBOLS)}


def compare_candidate(baseline: bytes, candidate: bytes) -> dict[str, object]:
    expected = rom_slice(baseline, CODE_START, CODE_END)
    actual = rom_slice(candidate, CODE_START, CODE_END)
    if actual != expected:
        fail(f"candidate differs in Sound Check code 0x{CODE_START:08X}..0x{CODE_END:08X}")
    return {"start": f"0x{CODE_START:08X}", "end": f"0x{CODE_END:08X}", "sha256": sha256(actual)}


def render_human(manifest: dict[str, object]) -> str:
    code = manifest["code"]
    return "\n".join((
        f"Sound Check code: {code['start']}..{code['end']} ({code['size']:#x})",
        f"SHA-256: {code['sha256']}",
        f"Code symbols: {len(manifest['symbols'])}; EWRAM: {len(manifest['ewram'])}; IWRAM: {len(manifest['iwram'])}",
    ))


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rom", type=Path, default=ROOT / "baserom_jp.gba", help="baseline JP ROM (read only)")
    parser.add_argument("--candidate-rom", type=Path, help="linked candidate ROM to compare with the baseline")
    parser.add_argument("--map", dest="link_map", type=Path, help="candidate link map with neutral Sound Check symbols")
    parser.add_argument("--ewram-symbols", type=Path, help="candidate sym_ewram_jp.txt")
    parser.add_argument("--iwram-symbols", type=Path, help="candidate sym_iwram_jp.txt")
    parser.add_argument("--funcmap", type=Path, help="candidate funcmap_jp.txt")
    parser.add_argument("--source", type=Path, help="candidate src/sound_check.c")
    parser.add_argument("--json", action="store_true", help="emit stable machine-readable output")
    args = parser.parse_args(argv)

    baseline = args.rom.read_bytes()
    manifest = audit_baseline(baseline)
    if args.candidate_rom is not None:
        manifest["candidate_code"] = compare_candidate(baseline, args.candidate_rom.read_bytes())
    if args.link_map is not None:
        manifest["link_map"] = check_map(args.link_map)
    if args.ewram_symbols is not None:
        manifest["ewram_symbols"] = check_ram_symbols(args.ewram_symbols, EWRAM_SYMBOLS)
    if args.iwram_symbols is not None:
        manifest["iwram_symbols"] = check_ram_symbols(args.iwram_symbols, IWRAM_SYMBOLS)
    if args.funcmap is not None:
        manifest["funcmap"] = check_funcmap(args.funcmap)
    if args.source is not None:
        manifest["source"] = check_source(args.source)
    if args.json:
        print(json.dumps(manifest, ensure_ascii=False, indent=2, sort_keys=True))
    else:
        print(render_human(manifest))
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except AuditError as error:
        print(error, file=sys.stderr)
        raise SystemExit(1)
