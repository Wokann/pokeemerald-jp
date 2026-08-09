#!/usr/bin/env python3
"""JP text decode/encode and chunk scanning for data/data.s.

The JP ROM stores text in the game's charmap encoding.  This tool:

  * decodes ROM bytes into readable text (kana/Latin via charmap.txt,
    unmapped byte sequences as {UNK_XXXX} placeholders),
  * encodes text back into ROM bytes (round-trip is byte-exact),
  * scans data.s chunks to find text-like chunks.

Usage:
    python3 tools/text_tool.py scan [top N]
    python3 tools/text_tool.py dump <label>
    python3 tools/text_tool.py check <label>
"""

import re
import sys
import subprocess
import tempfile
import os
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CHARMAP_FILE = ROOT / "charmap.txt"
DATA_S = ROOT / "data" / "data.s"
BIN = ROOT / "build" / "data" / "data.bin"

REGION_START = 0x29BDA4

LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
INCINBIN_RE = re.compile(
    r'^\s*\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)\s*$'
)


class Charmap:
    def __init__(self):
        self.bytes_to_text = {}  # bytes tuple -> text repr
        self.text_to_bytes = {}  # text repr -> bytes tuple

    def load(self, path):
        for line in path.read_text(encoding="utf-8").splitlines():
            line = line.strip()
            if not line or line.startswith("@"):
                continue
            m = re.match(r"^'((?:[^'\\]|\\.)*)'\s*=\s*(.+)$", line)
            if m:
                raw = m.group(1)
                seq = self._parse_hex(m.group(2))
                if seq:
                    if raw.startswith("\\") and len(raw) == 2:
                        # Escape entries like '\n' stay in source form
                        # (backslash + letter); preproc converts them via
                        # its Escape table.  \' and \\ are plain chars.
                        c = raw[1]
                        if c in ("'", "\\"):
                            repr = c
                        else:
                            repr = raw
                    elif len(raw) == 1:
                        repr = raw
                    else:
                        continue
                    self.bytes_to_text[seq] = repr
                    self.text_to_bytes[repr] = seq
                continue
            m = re.match(r"^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(.+)$", line)
            if m:
                name = m.group(1)
                seq = self._parse_hex(m.group(2))
                if seq:
                    self.bytes_to_text[seq] = "{" + name + "}"
                    self.text_to_bytes["{" + name + "}"] = seq

    @staticmethod
    def _parse_hex(s):
        s = s.split("@", 1)[0]  # comments start with @, like preproc
        vals = re.findall(r"\b[0-9A-Fa-f]{2}\b", s)
        return tuple(int(v, 16) for v in vals) if vals else None

    def decode(self, data):
        out = []
        i = 0
        while i < len(data):
            matched = None
            for size in (3, 2, 1):
                if i + size <= len(data):
                    seq = tuple(data[i : i + size])
                    if seq in self.bytes_to_text:
                        matched = (size, seq)
                        break
            if matched:
                size, seq = matched
                out.append(self.bytes_to_text[seq])
                i += size
            elif i + 1 < len(data):
                out.append(f"{{UNK_{data[i]:02X}{data[i+1]:02X}}}")
                i += 2
            else:
                out.append(f"{{BYTE_{data[i]:02X}}}")
                i += 1
        return "".join(out)

    def encode(self, text):
        out = bytearray()
        i = 0
        while i < len(text):
            if text[i] == "{":
                j = text.find("}", i)
                if j == -1:
                    raise ValueError(f"unterminated constant at {i}")
                token = text[i : j + 1]
                m = re.match(r"^\{UNK_([0-9A-Fa-f]{4})\}$", token)
                if m:
                    out.append(int(m.group(1)[0:2], 16))
                    out.append(int(m.group(1)[2:4], 16))
                    i = j + 1
                    continue
                m = re.match(r"^\{BYTE_([0-9A-Fa-f]{2})\}$", token)
                if m:
                    out.append(int(m.group(1), 16))
                    i = j + 1
                    continue
                if token not in self.text_to_bytes:
                    raise ValueError(f"unknown constant {token}")
                out.extend(self.text_to_bytes[token])
                i = j + 1
            elif text[i] == "\\" and i + 1 < len(text):
                token = text[i : i + 2]
                if token in self.text_to_bytes:
                    out.extend(self.text_to_bytes[token])
                    i += 2
                    continue
                raise ValueError(f"unknown escape {token!r} at {i}")
            else:
                ch = text[i]
                if ch not in self.text_to_bytes:
                    raise ValueError(f"unknown character {ch!r} at {i}")
                out.extend(self.text_to_bytes[ch])
                i += 1
        return bytes(out)

    def roundtrip(self, data):
        try:
            return self.encode(self.decode(data)) == data
        except ValueError:
            return False

    def preproc_bytes(self, text):
        """Run preproc on the .string lines and return the encoded bytes,
        or None if preproc is unavailable."""
        preproc = ROOT / "tools" / "preproc" / "preproc"
        if not preproc.is_file():
            return None
        tmp = tempfile.NamedTemporaryFile(
            "w", suffix=".s", delete=False, encoding="utf-8"
        )
        try:
            for seg in split_strings(text):
                tmp.write(f'\t.string "{seg}"\n')
            tmp.close()
            result = subprocess.run(
                [str(preproc), tmp.name, str(CHARMAP_FILE)],
                capture_output=True,
                text=True,
                check=True,
            )
        except subprocess.CalledProcessError:
            return None
        finally:
            os.unlink(tmp.name)
        vals = []
        for line in result.stdout.splitlines():
            vals.extend(int(m.group(1), 16) for m in re.finditer(r"0x([0-9A-Fa-f]{2})", line))
        return bytes(vals)


def parse_chunks():
    chunks = []
    label = None
    for line in DATA_S.read_text(encoding="utf-8").splitlines():
        lm = LABEL_RE.match(line)
        if lm:
            label = lm.group(1)
            addr = int(lm.group(2), 16)
            continue
        m = INCINBIN_RE.match(line)
        if m:
            if label is None:
                sys.exit("incbin without label")
            rel = int(m.group(1), 16)
            size = int(m.group(2), 16)
            chunks.append((label, addr, rel, size))
            label = None
    return chunks


def main():
    if not BIN.is_file():
        sys.exit(f"missing {BIN}; run make first")
    data = BIN.read_bytes()
    cm = Charmap()
    cm.load(CHARMAP_FILE)

    if len(sys.argv) < 2:
        sys.exit(__doc__)
    cmd = sys.argv[1]

    if cmd == "scan":
        top = int(sys.argv[2]) if len(sys.argv) > 2 else 30
        rows = []
        for label, addr, rel, size in parse_chunks():
            raw = data[rel : rel + size]
            if size < 4:
                continue
            kana = sum(1 for b in raw if 0x01 <= b <= 0x50) / len(raw)
            latin = sum(1 for b in raw if 0xB9 <= b <= 0xE9) / len(raw)
            ff = raw.count(0xFF) / len(raw)
            nul = raw.count(0x00) / len(raw)
            text = cm.decode(raw)
            consts = len(re.findall(r"\{[A-Za-z0-9_]+\}", text)) / len(raw)
            score = kana + latin * 0.5 + min(ff * 4, 0.4)
            rows.append((score, label, addr, size, kana, latin, ff, nul, consts))
        rows.sort(reverse=True)
        print(f"{'score':>6} {'label':<26} {'addr':>9} {'size':>7} {'kana':>5} "
              f"{'latin':>5} {'ff':>5} {'nul':>5} {'const':>5}")
        for score, label, addr, size, kana, latin, ff, nul, consts in rows[:top]:
            print(f"{score:6.2f} {label:<26} 0x{addr:07X} 0x{size:05X} "
                  f"{kana:5.2f} {latin:5.2f} {ff:5.3f} {nul:5.3f} {consts:5.2f}")
    elif cmd == "dump":
        target = sys.argv[2]
        for label, addr, rel, size in parse_chunks():
            if label == target:
                print(cm.decode(data[rel : rel + size]))
                return
        sys.exit(f"no chunk named {target}")
    elif cmd == "check":
        target = sys.argv[2]
        for label, addr, rel, size in parse_chunks():
            if label == target:
                raw = data[rel : rel + size]
                ok = cm.roundtrip(raw)
                print(f"{label}: roundtrip {'OK' if ok else 'FAIL'} "
                      f"({size} bytes)")
                return
        sys.exit(f"no chunk named {target}")
    elif cmd == "convert":
        target = sys.argv[2]
        converted, _ = convert_chunks([target], data, cm)
        if not converted:
            sys.exit(f"{target}: not found or already converted")
        print(f"converted {target} to .string")
    elif cmd == "convert-all":
        targets = [label for label, _, _, _ in parse_chunks()]
        converted, skipped = convert_chunks(targets, data, cm)
        print(f"converted {len(converted)} chunks, "
              f"{sum(c[1] for c in converted)} bytes, skipped {len(skipped)}")
    elif cmd == "map":
        name = sys.argv[2]
        token = name if name.startswith("{") else "{" + name + "}"
        seq = cm.text_to_bytes.get(token)
        print(f"{token} -> {seq}")
    elif cmd == "decode-hex":
        raw = bytes.fromhex(sys.argv[2])
        print(cm.decode(raw))
        print(f"roundtrip: {cm.roundtrip(raw)}")
    elif cmd == "skip-reasons":
        reasons = {}
        samples = {}
        for label, addr, rel, size in parse_chunks():
            raw = data[rel : rel + size]
            text = cm.decode(raw)
            if not cm.roundtrip(raw):
                reason = "not-text"
            elif not text.endswith("$"):
                reason = "unterminated"
            elif '"' in text or "\\" in text:
                reason = "quotes"
            else:
                encoded = cm.preproc_bytes(text)
                if encoded is None:
                    reason = "preproc-error"
                elif encoded != raw:
                    reason = "preproc-divergence"
                else:
                    reason = "ok"
            reasons[reason] = reasons.get(reason, 0) + 1
            samples.setdefault(reason, []).append((label, addr, size))
        for reason, count in sorted(reasons.items(), key=lambda kv: -kv[1]):
            print(f"{reason:<20} {count}")
            for label, addr, size in samples[reason][:3]:
                print(f"    {label} 0x{addr:07X} 0x{size:05X}")
    elif cmd == "preproc-check":
        target = sys.argv[2]
        for label, addr, rel, size in parse_chunks():
            if label == target:
                raw = data[rel : rel + size]
                text = cm.decode(raw)
                tmp = tempfile.NamedTemporaryFile(
                    "w", suffix=".s", delete=False, encoding="utf-8"
                )
                try:
                    for seg in split_strings(text):
                        tmp.write(f'\t.string "{seg}"\n')
                    tmp.close()
                    result = subprocess.run(
                        [str(ROOT / "tools" / "preproc" / "preproc"),
                         tmp.name, str(CHARMAP_FILE)],
                        capture_output=True,
                        text=True,
                    )
                    print("stderr:", result.stderr[:800])
                    print("rc:", result.returncode)
                finally:
                    os.unlink(tmp.name)
                return
        sys.exit(f"no chunk named {target}")
    else:
        sys.exit(__doc__)


def convert_chunks(targets, data, cm):
    """Convert the given chunk labels from .incbin to .string lines.
    Only chunks that pass every gate are converted:
    - decode/encode round-trips byte-exactly,
    - the text ends with the 0xFF terminator,
    - no quote/backslash characters,
    - preproc re-encodes the .string lines to the exact original bytes.
    Returns (converted, skipped) lists of (label, size)."""
    targets = set(targets)
    lines = DATA_S.read_text(encoding="utf-8").splitlines(keepends=True)
    out = []
    label = None
    converted = []
    skipped = []
    for line in lines:
        lm = LABEL_RE.match(line.rstrip("\r\n"))
        if lm:
            label = lm.group(1)
            out.append(line)
            continue
        m = INCINBIN_RE.match(line)
        if m and label in targets:
            rel = int(m.group(1), 16)
            size = int(m.group(2), 16)
            raw = data[rel : rel + size]
            ok = cm.roundtrip(raw)
            if ok:
                text = cm.decode(raw)
                ok = text.endswith("$") and '"' not in text
            if ok:
                encoded = cm.preproc_bytes(text)
                ok = encoded is not None and encoded == raw
            if ok:
                for seg in split_strings(text):
                    out.append(f'\t.string "{seg}"\n')
                converted.append((label, size))
            else:
                skipped.append((label, size))
                out.append(line)
            label = None
            continue
        out.append(line)
    DATA_S.write_text("".join(out), encoding="utf-8")
    return converted, skipped


def split_strings(text):
    """Split decoded text into .string lines, never inside a {NAME}
    constant and preferring string ($) boundaries."""
    pieces = []
    cur = ""
    for ch in text:
        cur += ch
        if ch == "$" and len(cur) >= 40:
            pieces.append(cur)
            cur = ""
    if cur:
        pieces.append(cur)

    # Further split very long lines at constant boundaries.
    out = []
    for piece in pieces:
        while len(piece) > 100:
            cut = -1
            for i in range(100, 0, -1):
                if piece[i] == "}":
                    cut = i + 1
                    break
            if cut == -1:
                cut = 100
            out.append(piece[:cut])
            piece = piece[cut:]
        out.append(piece)
    return out


if __name__ == "__main__":
    main()
