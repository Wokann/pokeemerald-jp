#!/usr/bin/env python3
"""Lossless Japanese script-text codec.

This module is deliberately narrower than a generic charmap decoder.  It
decodes only text that the Japanese text engine can consume and emits source
accepted by ``tools/preproc/preproc``.  Every accepted conversion is then
re-encoded by that same preprocessor and compared byte-for-byte with the ROM
input.  An unknown control sequence is an error, not a guess: callers must
keep that source range as ``.incbin`` until it is understood.

The generated representation is intended for ``.string`` directives.  It
does not choose between the C ``_`` and ``__`` helpers; that choice depends on
the owning object's exact storage layout and must be made separately.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import tempfile
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
CHARMAP_PATH = ROOT / "charmap.txt"
PREPROC_PATH = ROOT / "tools" / "preproc" / "preproc"
BASEROM_PATH = ROOT / "baserom_jp.gba"

# preproc begins every assembly result with a line marker naming its input
# file.  Temporary file names may themselves contain ``0xNN``; only actual
# .byte directives carry encoded text bytes.
PREPROC_BYTE_LINE_RE = re.compile(r"^\s*\.byte\s+(.+?)\s*$")
PREPROC_HEX_BYTE_RE = re.compile(r"0x([0-9A-Fa-f]{2})(?![0-9A-Fa-f])")


class TextDecodeError(ValueError):
    """The byte stream is not safe to render as a source string."""


class TextRoundTripError(ValueError):
    """The source representation did not reproduce the original bytes."""


def _extract_preproc_bytes(output: str) -> bytes:
    """Extract encoded bytes from preproc output, excluding line markers."""
    encoded = bytearray()
    for line in output.splitlines():
        line_match = PREPROC_BYTE_LINE_RE.match(line)
        if line_match is None:
            continue
        payload = line_match.group(1)
        byte_matches = list(PREPROC_HEX_BYTE_RE.finditer(payload))
        remainder = PREPROC_HEX_BYTE_RE.sub("", payload)
        if not byte_matches or remainder.replace(",", "").strip():
            raise TextRoundTripError(
                f"unexpected preproc .byte output: {line!r}"
            )
        encoded.extend(int(match.group(1), 16) for match in byte_matches)
    return bytes(encoded)


# These lengths are taken from the Japanese text engine's RenderText switch in
# src/text.c.  Keeping the argument bytes inside the same brace group avoids
# the historic error of decoding a control argument as a kana glyph.
EXT_CTRL_SPECS = {
    0x00: ("NAME_END", 0),
    0x01: ("COLOR", 1),
    0x02: ("HIGHLIGHT", 1),
    0x03: ("SHADOW", 1),
    0x04: ("COLOR_HIGHLIGHT_SHADOW", 3),
    0x05: ("PALETTE", 1),
    0x06: ("FONT", 1),
    0x07: ("RESET_FONT", 0),
    0x08: ("PAUSE", 1),
    0x09: ("PAUSE_UNTIL_PRESS", 0),
    0x0A: ("WAIT_SE", 0),
    0x0B: ("PLAY_BGM", 2),
    0x0C: ("ESCAPE", 1),
    0x0D: ("SHIFT_RIGHT", 1),
    0x0E: ("SHIFT_DOWN", 1),
    0x0F: ("FILL_WINDOW", 0),
    0x10: ("PLAY_SE", 2),
    0x11: ("CLEAR", 0),
    0x12: ("SKIP", 0),
    0x13: ("CLEAR_TO", 1),
    0x14: ("MIN_LETTER_SPACING", 1),
    0x15: ("JPN", 0),
    0x16: ("ENG", 0),
    0x17: ("PAUSE_MUSIC", 0),
    0x18: ("RESUME_MUSIC", 0),
}

KEYPAD_CONSTANTS = (
    "A_BUTTON",
    "B_BUTTON",
    "L_BUTTON",
    "R_BUTTON",
    "START_BUTTON",
    "SELECT_BUTTON",
    "DPAD_UP",
    "DPAD_DOWN",
    "DPAD_LEFT",
    "DPAD_RIGHT",
    "DPAD_UPDOWN",
    "DPAD_LEFTRIGHT",
    "DPAD_NONE",
)


@dataclass(frozen=True)
class DecodedText:
    source: str
    consumed: int
    ended: bool


def _parse_hex_sequence(value: str) -> bytes:
    value = value.split("@", 1)[0].strip()
    pieces = value.split()
    if not pieces or any(not re.fullmatch(r"[0-9A-Fa-f]{2}", piece) for piece in pieces):
        raise TextDecodeError(f"invalid charmap byte sequence: {value!r}")
    return bytes(int(piece, 16) for piece in pieces)


def _unescape_charmap_literal(raw: str) -> tuple[str, bool]:
    """Return the source spelling and whether the entry is an escape mapping."""
    if raw.startswith("\\") and len(raw) == 2:
        if raw[1] in ("'", "\\"):
            return raw[1], False
        return raw, True
    return raw, False


def _literal_priority(char: str) -> tuple[int, str]:
    """Prefer JP punctuation aliases without changing the underlying byte."""
    preferred = {"！", "？", "。", "ー", "⋯"}
    if char in preferred:
        return (0, char)
    if not char.isascii():
        return (1, char)
    return (2, char)


class JapaneseScriptTextCodec:
    """Decode and preprocessor-verify Japanese game text byte streams."""

    def __init__(self, charmap_path: Path = CHARMAP_PATH):
        self.charmap_path = charmap_path
        self.constants: dict[str, bytes] = {}
        literal_candidates: dict[int, list[str]] = {}

        char_re = re.compile(r"^'((?:[^'\\]|\\.)*)'\s*=\s*(.+)$")
        const_re = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(.+)$")
        for original_line in charmap_path.read_text(encoding="utf-8").splitlines():
            line = original_line.strip()
            if not line or line.startswith("@"):
                continue
            char_match = char_re.match(line)
            if char_match:
                raw, value = char_match.groups()
                sequence = _parse_hex_sequence(value)
                literal, is_escape = _unescape_charmap_literal(raw)
                if is_escape or len(sequence) != 1 or len(literal) != 1:
                    continue
                literal_candidates.setdefault(sequence[0], []).append(literal)
                continue
            const_match = const_re.match(line)
            if const_match:
                name, value = const_match.groups()
                self.constants[name] = _parse_hex_sequence(value)

        self.literals = {
            byte: min(candidates, key=_literal_priority)
            for byte, candidates in literal_candidates.items()
        }
        self.keypad = self._named_sequences(KEYPAD_CONSTANTS, expected_prefix=0xF8)
        self.emoji = self._named_sequences(
            tuple(name for name in self.constants if name.startswith("EMOJI_")),
            expected_prefix=0xF9,
        )
        self._validate_charmap_contract()

    def _named_sequences(self, names: tuple[str, ...], expected_prefix: int) -> dict[bytes, str]:
        sequences: dict[bytes, str] = {}
        for name in names:
            sequence = self.constants.get(name)
            if sequence is None:
                raise TextDecodeError(f"charmap is missing required constant {name}")
            if len(sequence) != 2 or sequence[0] != expected_prefix:
                raise TextDecodeError(f"unexpected mapping for {name}: {sequence.hex()}")
            sequences[sequence] = name
        return sequences

    def _validate_charmap_contract(self) -> None:
        required = {"STRING": b"\xFD", "DYNAMIC": b"\xF7"}
        for code, (name, _) in EXT_CTRL_SPECS.items():
            required[name] = bytes((0xFC, code))
        for name, expected in required.items():
            actual = self.constants.get(name)
            if actual != expected:
                found = "missing" if actual is None else actual.hex()
                raise TextDecodeError(
                    f"charmap constant {name} must be {expected.hex()}, found {found}"
                )

    @staticmethod
    def _format_control(name: str, args: bytes = b"") -> str:
        if not args:
            return "{" + name + "}"
        numbers = " ".join(f"0x{byte:02X}" for byte in args)
        return "{" + name + " " + numbers + "}"

    @staticmethod
    def _escape_literal(char: str) -> str:
        if char == "\\":
            return "\\\\"
        if char == '"':
            return '\\"'
        return char

    def _decode_token(self, data: bytes, pos: int) -> tuple[str, int, bool]:
        byte = data[pos]
        if byte == 0xFF:
            return "$", pos + 1, True
        if byte == 0xFE:
            return "\\n", pos + 1, False
        if byte == 0xFA:
            return "\\l", pos + 1, False
        if byte == 0xFB:
            return "\\p", pos + 1, False
        if byte == 0xF7:
            if pos + 1 >= len(data):
                raise TextDecodeError("truncated dynamic-placeholder control (F7)")
            # DynamicPlaceholderTextUtil_ExpandPlaceholders consumes F7 and
            # the following placeholder index together.  Treating the index
            # as a glyph (often Japanese full-width space for 00) preserves
            # bytes by accident while changing the string's meaning.
            return self._format_control("DYNAMIC", data[pos + 1 : pos + 2]), pos + 2, False
        if byte == 0xF8:
            if pos + 1 >= len(data):
                raise TextDecodeError("truncated keypad-icon control (F8)")
            sequence = data[pos : pos + 2]
            name = self.keypad.get(sequence)
            if name is None:
                raise TextDecodeError(f"unknown keypad-icon control {sequence.hex().upper()}")
            return "{" + name + "}", pos + 2, False
        if byte == 0xF9:
            if pos + 1 >= len(data):
                raise TextDecodeError("truncated extra-symbol control (F9)")
            sequence = data[pos : pos + 2]
            name = self.emoji.get(sequence)
            if name is None:
                raise TextDecodeError(f"unknown extra-symbol control {sequence.hex().upper()}")
            return "{" + name + "}", pos + 2, False
        if byte == 0xFD:
            if pos + 1 >= len(data):
                raise TextDecodeError("truncated string-placeholder control (FD)")
            # Field and battle placeholder names share byte values.  Preserve
            # the exact generic control rather than guessing a false meaning.
            return self._format_control("STRING", data[pos + 1 : pos + 2]), pos + 2, False
        if byte == 0xFC:
            if pos + 1 >= len(data):
                raise TextDecodeError("truncated extended control prefix (FC)")
            control = data[pos + 1]
            spec = EXT_CTRL_SPECS.get(control)
            if spec is None:
                raise TextDecodeError(f"unknown extended control FC {control:02X}")
            name, arg_count = spec
            end = pos + 2 + arg_count
            if end > len(data):
                raise TextDecodeError(
                    f"truncated {name} control: expected {arg_count} argument byte(s)"
                )
            return self._format_control(name, data[pos + 2 : end]), end, False

        literal = self.literals.get(byte)
        if literal is None:
            raise TextDecodeError(f"unmapped text byte {byte:02X}")
        return self._escape_literal(literal), pos + 1, False

    def decode(self, data: bytes) -> str:
        """Decode all bytes, allowing multiple EOS characters in one span."""
        out: list[str] = []
        pos = 0
        while pos < len(data):
            token, pos, _ = self._decode_token(data, pos)
            out.append(token)
        return "".join(out)

    def decode_one(self, data: bytes) -> DecodedText:
        """Decode exactly one EOS-terminated text object from the start."""
        out: list[str] = []
        pos = 0
        while pos < len(data):
            token, pos, ended = self._decode_token(data, pos)
            out.append(token)
            if ended:
                return DecodedText("".join(out), pos, True)
        raise TextDecodeError("unterminated text object")

    def preproc_bytes(self, source: str) -> bytes:
        """Use the project's real preprocessor to encode one .string value."""
        if not PREPROC_PATH.is_file():
            raise TextRoundTripError(f"missing preprocessor: {PREPROC_PATH}")
        with tempfile.NamedTemporaryFile(
            "w", suffix=".s", encoding="utf-8", delete=False
        ) as tmp:
            tmp_path = Path(tmp.name)
            tmp.write(f'\t.string "{source}"\n')
        try:
            result = subprocess.run(
                [str(PREPROC_PATH), str(tmp_path), str(self.charmap_path)],
                capture_output=True,
                text=True,
                check=False,
            )
        finally:
            tmp_path.unlink(missing_ok=True)
        if result.returncode != 0:
            raise TextRoundTripError(
                "preproc rejected decoded text: " + result.stderr.strip()
            )
        return _extract_preproc_bytes(result.stdout)

    def verify(self, data: bytes) -> str:
        """Decode then verify an exact re-encoding through preproc."""
        source = self.decode(data)
        encoded = self.preproc_bytes(source)
        if encoded != data:
            raise TextRoundTripError(
                "preproc round-trip mismatch: "
                f"expected {data.hex().upper()}, got {encoded.hex().upper()}"
            )
        return source

    def verify_one(self, data: bytes) -> DecodedText:
        """Decode and verify one EOS-terminated object, leaving trailing bytes alone."""
        decoded = self.decode_one(data)
        encoded = self.preproc_bytes(decoded.source)
        expected = data[: decoded.consumed]
        if encoded != expected:
            raise TextRoundTripError(
                "preproc round-trip mismatch: "
                f"expected {expected.hex().upper()}, got {encoded.hex().upper()}"
            )
        return decoded


def _parse_hex_bytes(text: str) -> bytes:
    compact = re.sub(r"[^0-9A-Fa-f]", "", text)
    if len(compact) % 2:
        raise argparse.ArgumentTypeError("hex input must contain full bytes")
    try:
        return bytes.fromhex(compact)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(str(exc)) from exc


def _run_selftest(codec: JapaneseScriptTextCodec) -> None:
    marker_bytes = _extract_preproc_bytes(
        '# 1 "/tmp/preproc0x29.s"\n\t.byte 0x1E, 0x06\n'
    )
    if marker_bytes != bytes.fromhex("1E06"):
        raise TextRoundTripError(
            f"line-marker extraction failed: got {marker_bytes.hex().upper()}"
        )
    print("PASS preproc-line-marker: 1E06")

    cases = (
        ("kana", bytes.fromhex("58 77 9A FF"), "クラボ$"),
        ("dynamic", bytes.fromhex("F7 01 FF"), "{DYNAMIC 0x01}$"),
        (
            "dynamic-search-rank",
            bytes.fromhex("F7 00 46 2E 22 FF"),
            "{DYNAMIC 0x00}ばんめ$",
        ),
        (
            "controls",
            bytes.fromhex("FC 08 7F FC 0B 34 12 FC 0C FB FD 01 F8 00 F9 E7 FE FA FB FF"),
            "{PAUSE 0x7F}{PLAY_BGM 0x34 0x12}{ESCAPE 0xFB}{STRING 0x01}"
            "{A_BUTTON}{EMOJI_HEART}\\n\\l\\p$",
        ),
        ("name-end", bytes.fromhex("FC 00 FF"), "{NAME_END}$"),
    )
    for name, raw, expected in cases:
        source = codec.verify(raw)
        if source != expected:
            raise TextRoundTripError(
                f"{name}: expected source {expected!r}, got {source!r}"
            )
        print(f"PASS {name}: {raw.hex().upper()} -> {source}")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="command", required=True)
    subparsers.add_parser("selftest", help="exercise kana and every special-control family")

    decode_parser = subparsers.add_parser("decode", help="decode and round-trip an exact hex span")
    decode_parser.add_argument("hex_bytes", type=_parse_hex_bytes)

    rom_parser = subparsers.add_parser("rom", help="decode one EOS-terminated string from baserom_jp.gba")
    rom_parser.add_argument("offset", type=lambda value: int(value, 0), help="ROM-file offset, not a GBA address")
    rom_parser.add_argument("--max-size", type=lambda value: int(value, 0), default=0x4000)

    args = parser.parse_args()
    codec = JapaneseScriptTextCodec()
    if args.command == "selftest":
        _run_selftest(codec)
        return
    if args.command == "decode":
        source = codec.verify(args.hex_bytes)
        print(source)
        return

    if not BASEROM_PATH.is_file():
        raise SystemExit(f"missing matching Japanese baserom: {BASEROM_PATH}")
    if args.offset < 0:
        raise SystemExit("offset must be non-negative")
    data = BASEROM_PATH.read_bytes()[args.offset : args.offset + args.max_size]
    decoded = codec.verify_one(data)
    print(f"offset=0x{args.offset:X} size=0x{decoded.consumed:X}")
    print(decoded.source)


if __name__ == "__main__":
    main()
