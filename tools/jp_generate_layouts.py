#!/usr/bin/env python3
"""Generate the JP layout sources from local layout metadata.

The normal mapjson output is shared with pokeemerald.  Route110 Trick House
Puzzle 4 is the one reviewed JP-only asset exception: its blockdata differs
from the US source asset, so it deliberately remains a visible byte-exact ROM
span under the canonical layout label.
"""

from __future__ import annotations

import argparse
import subprocess
import tempfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
LAYOUTS_JSON = ROOT / "data/layouts/layouts.json"
MAPJSON = ROOT / "tools/mapjson/mapjson"
LAYOUTS_DIR = ROOT / "data/layouts"
CONSTANTS_DIR = ROOT / "include/constants"

RAW_LABEL = "Route110_TrickHousePuzzle4_Layout_Blockdata::"
RAW_US_ASSET = '\t.incbin "data/layouts/Route110_TrickHousePuzzle4/map.bin"'
RAW_JP_OWNER = (
    "@ JP-specific blockdata differs from the US asset at 16 bytes. Keep this\n"
    "@ byte-exact span visible under its final owner until it has a reconstructed\n"
    "@ JP source asset.\n"
    f"{RAW_LABEL}\n"
    '\t.incbin "baserom_jp.gba", 0x420280, 0x294'
)


def patch_jp_layout_exception(text: str) -> str:
    expected = f"{RAW_LABEL}\n{RAW_US_ASSET}"
    if text.count(expected) != 1:
        raise ValueError("expected exactly one Route110 Trick House Puzzle 4 blockdata owner")
    return text.replace(expected, RAW_JP_OWNER)


def normalize_generated_text(text: str) -> str:
    return text.rstrip() + "\n"


def generated_outputs() -> dict[Path, str]:
    if not LAYOUTS_JSON.is_file():
        raise FileNotFoundError(f"missing local layout metadata: {LAYOUTS_JSON}")
    if not MAPJSON.is_file():
        raise FileNotFoundError(f"missing mapjson tool: {MAPJSON}")

    with tempfile.TemporaryDirectory(prefix="pokeemerald-jp-layouts-") as directory:
        temp_root = Path(directory)
        temp_layouts = temp_root / "layouts"
        temp_constants = temp_root / "constants"
        temp_layouts.mkdir()
        temp_constants.mkdir()
        subprocess.run(
            [str(MAPJSON), "layouts", "emerald", str(LAYOUTS_JSON), str(temp_layouts), str(temp_constants)],
            check=True,
        )
        return {
            LAYOUTS_DIR / "layouts.inc": normalize_generated_text(
                patch_jp_layout_exception((temp_layouts / "layouts.inc").read_text(encoding="utf-8"))
            ),
            LAYOUTS_DIR / "layouts_table.inc": normalize_generated_text(
                (temp_layouts / "layouts_table.inc").read_text(encoding="utf-8")
            ),
            CONSTANTS_DIR / "layouts.h": normalize_generated_text(
                (temp_constants / "layouts.h").read_text(encoding="utf-8")
            ),
        }


def write_if_changed(path: Path, text: str) -> bool:
    if path.is_file() and path.read_text(encoding="utf-8") == text:
        return False
    path.write_text(text, encoding="utf-8")
    return True


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="fail if generated sources are stale")
    args = parser.parse_args()

    outputs = generated_outputs()
    stale = [path for path, text in outputs.items() if not path.is_file() or path.read_text(encoding="utf-8") != text]
    if args.check:
        if stale:
            raise SystemExit("stale layout sources: " + ", ".join(str(path) for path in stale))
        return

    changed = [path for path, text in outputs.items() if write_if_changed(path, text)]
    if changed:
        print("updated " + ", ".join(str(path) for path in changed))


if __name__ == "__main__":
    main()
