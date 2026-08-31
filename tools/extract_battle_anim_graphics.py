#!/usr/bin/env python3
"""Extract and verify named JP battle-animation graphics resources.

The entries in this manifest have been audited against the JP ROM, their LZ77
stream lengths, and the corresponding pokeemerald graphics symbols. Files
include any original zero padding needed to preserve the JP linker layout.
"""

from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"


@dataclass(frozen=True)
class Resource:
    symbol: str
    path: Path
    offset: int
    size: int
    stream_size: int


RESOURCES = (
    Resource("gBattleInterfaceGfx_BattleBar", Path("graphics/battle_interface/battle_bar.4bpp.lz"), 0xC093F8, 0x214, 0x211),
    Resource("gBattleAnimSpriteGfx_SapDrip", Path("graphics/battle_anims/sprites/sap_drip.png.4bpp.lz"), 0xC0960C, 0x3E0, 0x3DD),
    Resource("gBattleAnimSpritePal_SapDrip", Path("graphics/battle_anims/sprites/sap_drip.png.gbapal.lz"), 0xC099EC, 0x20, 0x20),
    Resource("gBattleAnimSpritePal_SapDrip2", Path("graphics/battle_anims/sprites/sap_drip_2.pal.gbapal.lz"), 0xC09A0C, 0x24, 0x22),
)


def lz_stream_len(data: bytes, output_size: int) -> int | None:
    pos = 4
    output = 0
    while output < output_size:
        if pos >= len(data):
            return None
        flags = data[pos]
        pos += 1
        for bit in range(8):
            if output >= output_size:
                break
            if flags & (0x80 >> bit):
                if pos + 1 >= len(data):
                    return None
                length = (data[pos] >> 4) + 3
                pos += 2
            else:
                if pos >= len(data):
                    return None
                length = 1
                pos += 1
            output += length
    return pos


def validate(resource: Resource, rom: bytes) -> bytes:
    data = rom[resource.offset:resource.offset + resource.size]
    if len(data) != resource.size:
        raise ValueError(f"{resource.symbol}: ROM range is truncated")
    if data[0] != 0x10:
        raise ValueError(f"{resource.symbol}: expected LZ77 type 0x10, got {data[0]:#x}")
    output_size = int.from_bytes(data[1:4], "little")
    stream_size = lz_stream_len(data, output_size)
    if stream_size != resource.stream_size:
        raise ValueError(
            f"{resource.symbol}: stream size {stream_size!r}, expected {resource.stream_size:#x}"
        )
    if any(data[stream_size:]):
        raise ValueError(f"{resource.symbol}: non-zero bytes after the LZ77 stream")
    return data


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true", help="verify tracked resources without writing them")
    args = parser.parse_args()

    rom = ROM_PATH.read_bytes()
    for resource in RESOURCES:
        data = validate(resource, rom)
        output = ROOT / resource.path
        if args.check:
            if not output.is_file():
                raise SystemExit(f"missing {resource.path}")
            if output.read_bytes() != data:
                raise SystemExit(f"{resource.path}: differs from {resource.symbol} ROM range")
            print(f"OK {resource.symbol}: {resource.path} ({resource.size:#x} bytes)")
        else:
            output.parent.mkdir(parents=True, exist_ok=True)
            output.write_bytes(data)
            print(f"extracted {resource.symbol}: {resource.path} ({resource.size:#x} bytes)")


if __name__ == "__main__":
    main()
