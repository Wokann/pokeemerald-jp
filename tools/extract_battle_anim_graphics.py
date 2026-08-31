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
    Resource("gBattleInterfaceGfx_UnusedWindow2", Path("graphics/battle_interface/unused_window2.png.4bpp.lz"), 0xC09A30, 0x29C, 0x299),
    Resource("gBattleInterfaceGfx_UnusedWindow2Bar", Path("graphics/battle_interface/unused_window2bar.png.4bpp.lz"), 0xC09CCC, 0x2C, 0x2C),
    Resource("gBattleAnimSpriteGfx_Sparkle1", Path("graphics/battle_anims/sprites/sparkle_1.png.4bpp.lz"), 0xC09CF8, 0x298, 0x295),
    Resource("gBattleAnimSpritePal_Sparkle1", Path("graphics/battle_anims/sprites/sparkle_1.png.gbapal.lz"), 0xC09F90, 0x28, 0x25),
    Resource("gBattleAnimSpritePal_Sparkle2", Path("graphics/battle_anims/sprites/sparkle_2.pal.gbapal.lz"), 0xC09FB8, 0x28, 0x25),
    Resource("gBattleAnimSpritePal_HumanoidFoot", Path("graphics/battle_anims/sprites/humanoid_foot.png.gbapal.lz"), 0xC09FE0, 0x24, 0x24),
    Resource("gBattleAnimSpriteGfx_HumanoidFoot", Path("graphics/battle_anims/sprites/humanoid_foot.png.4bpp.lz"), 0xC0A004, 0xA0, 0x9D),
    Resource("gBattleAnimSpriteGfx_MonsterFoot", Path("graphics/battle_anims/sprites/monster_foot.png.4bpp.lz"), 0xC0A0A4, 0xAC, 0xAB),
    Resource("gBattleAnimSpriteGfx_HumanoidHand", Path("graphics/battle_anims/sprites/humanoid_hand.png.4bpp.lz"), 0xC0A150, 0xCC, 0xCB),
    Resource("gBattleAnimSpriteGfx_SlamHit", Path("graphics/battle_anims/sprites/slam_hit.png.4bpp.lz"), 0xC0A3F4, 0x4A8, 0x4A8),
    Resource("gBattleAnimSpritePal_SlamHit", Path("graphics/battle_anims/sprites/slam_hit.png.gbapal.lz"), 0xC0A89C, 0x28, 0x25),
    Resource("gBattleAnimSpriteGfx_RedFist", Path("graphics/battle_anims/sprites/red_fist.png.4bpp.lz"), 0xC0A8C4, 0xC4, 0xC3),
    Resource("gBattleAnimSpriteGfx_Ring", Path("graphics/battle_anims/sprites/ring.png.4bpp.lz"), 0xC0A988, 0x88, 0x87),
    Resource("gBattleAnimSpritePal_Ring", Path("graphics/battle_anims/sprites/ring.png.gbapal.lz"), 0xC0AA10, 0x24, 0x24),
    Resource("gBattleAnimSpriteGfx_Rocks", Path("graphics/battle_anims/sprites/rocks.png.4bpp.lz"), 0xC0AA34, 0x468, 0x468),
    Resource("gBattleAnimSpritePal_Rocks", Path("graphics/battle_anims/sprites/rocks.png.gbapal.lz"), 0xC0AE9C, 0x28, 0x25),
    Resource("gBattleAnimSpriteGfx_Z", Path("graphics/battle_anims/sprites/z.png.4bpp.lz"), 0xC0AEC4, 0x60, 0x5F),
    Resource("gBattleAnimSpritePal_Z", Path("graphics/battle_anims/sprites/z.png.gbapal.lz"), 0xC0AF24, 0x1C, 0x19),
    Resource("gBattleAnimSpriteGfx_YellowUnk2", Path("graphics/battle_anims/sprites/yellow_unk_2.png.4bpp.lz"), 0xC0AF40, 0x28, 0x27),
    Resource("gBattleAnimSpritePal_YellowUnk2", Path("graphics/battle_anims/sprites/yellow_unk_2.png.gbapal.lz"), 0xC0AF68, 0x1C, 0x19),
    Resource("gBattleAnimSpriteGfx_AirSlash", Path("graphics/battle_anims/sprites/air_slash.png.4bpp.lz"), 0xC0AF84, 0xB0, 0xAE),
    Resource("gBattleAnimSpritePal_AirSlash", Path("graphics/battle_anims/sprites/air_slash.png.gbapal.lz"), 0xC0B034, 0x20, 0x1D),
    Resource("gBattleAnimSpriteGfx_SpinningGreenOrbs", Path("graphics/battle_anims/sprites/spinning_green_orbs.png.4bpp.lz"), 0xC0B054, 0x3D0, 0x3D0),
    Resource("gBattleAnimSpritePal_SpinningGreenOrbs", Path("graphics/battle_anims/sprites/spinning_green_orbs.png.gbapal.lz"), 0xC0B424, 0x28, 0x27),
    Resource("gBattleAnimSpriteGfx_Leaf", Path("graphics/battle_anims/sprites/leaf.png.4bpp.lz"), 0xC0B44C, 0x1BC, 0x1BB),
    Resource("gBattleAnimSpritePal_Leaf", Path("graphics/battle_anims/sprites/leaf.png.gbapal.lz"), 0xC0B608, 0x28, 0x25),
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
