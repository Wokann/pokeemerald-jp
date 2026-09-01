.include "sound/MPlayDef.s"
.section .rodata.data_rest2b_before_battle_anim_a_base_graphics
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.globl gBlankGfxCompressed
gBlankGfxCompressed: @ 0x8C02384
	.incbin "baserom_jp.gba", 0xc02384, 0xfc

	.section .rodata.data_rest2b_between_battle_anim_a_base_and_claw
	.incbin "baserom_jp.gba", 0xc06e2c, 0xaf0

	.section .rodata.data_rest2b_between_battle_anim_a_claw_and_burst
	.incbin "baserom_jp.gba", 0xc08238, 0x94

	.section .rodata.data_rest2b_after_battle_anim_a_burst_graphics
	.incbin "baserom_jp.gba", 0xc08f14, 0x4e4

	.section .rodata.data_rest2b_before_impact_graphics
	.incbin "baserom_jp.gba", 0xc0a21c, 0x194
	.globl gBattleAnimSpriteGfx_YellowUnk
gBattleAnimSpriteGfx_YellowUnk: @ 0x08C0A3B0
	.incbin "baserom_jp.gba", 0xc0a3b0, 0x2c
	.globl gBattleAnimSpritePal_YellowUnk
gBattleAnimSpritePal_YellowUnk: @ 0x08C0A3DC
	.incbin "baserom_jp.gba", 0xc0a3dc, 0x18

	.section .rodata.data_rest2b_before_status_particle_graphics
	.incbin "baserom_jp.gba", 0xc0b630, 0x70
	.globl gBattleAnimSpritePal_Clapping
gBattleAnimSpritePal_Clapping: @ 0x08C0B6A0
	.incbin "baserom_jp.gba", 0xc0b6a0, 0x24

	.section .rodata.data_rest2b_after_blue_lines_graphics
	.globl gBattleAnimSpritePal_Impact3
gBattleAnimSpritePal_Impact3: @ 0x08C0CBD0
	.incbin "baserom_jp.gba", 0xc0cbd0, 0x28
	.globl gBattleAnimSpritePal_Impact2
gBattleAnimSpritePal_Impact2: @ 0x08C0CBF8
	.incbin "baserom_jp.gba", 0xc0cbf8, 0x28
	.globl gBattleAnimSpritePal_Reticle
gBattleAnimSpritePal_Reticle: @ 0x08C0CC20
	.incbin "baserom_jp.gba", 0xc0cc20, 0x18
	.globl gBattleAnimSpritePal_Breath
gBattleAnimSpritePal_Breath: @ 0x08C0CC38
	.incbin "baserom_jp.gba", 0xc0cc38, 0x28
	.globl gBattleAnimSpritePal_Snowball
gBattleAnimSpritePal_Snowball: @ 0x08C0CC60
	.incbin "baserom_jp.gba", 0xc0cc60, 0x1c
	.globl gBattleAnimSpritePal_Vine
gBattleAnimSpritePal_Vine: @ 0x08C0CC7C
	.incbin "baserom_jp.gba", 0xc0cc7c, 0x28
	.globl gBattleAnimSpritePal_Sword2
gBattleAnimSpritePal_Sword2: @ 0x08C0CCA4
	.incbin "baserom_jp.gba", 0xc0cca4, 0x24
	.globl gBattleAnimSpritePal_RedTube
gBattleAnimSpritePal_RedTube: @ 0x08C0CCC8
	.incbin "baserom_jp.gba", 0xc0ccc8, 0x1c
	.globl gBattleAnimSpritePal_Amnesia
gBattleAnimSpritePal_Amnesia: @ 0x08C0CCE4
	.incbin "baserom_jp.gba", 0xc0cce4, 0x28
	.globl gBattleAnimSpritePal_String2
gBattleAnimSpritePal_String2: @ 0x08C0CD0C
	.incbin "baserom_jp.gba", 0xc0cd0c, 0x40
	.globl gBattleAnimSpritePal_Pencil2
gBattleAnimSpritePal_Pencil2: @ 0x08C0CD4C
	.incbin "baserom_jp.gba", 0xc0cd4c, 0x28
	.globl gBattleAnimSpritePal_Petal
gBattleAnimSpritePal_Petal: @ 0x08C0CD74
	.incbin "baserom_jp.gba", 0xc0cd74, 0x1c
	.globl gBattleAnimSpritePal_BentSpoon
gBattleAnimSpritePal_BentSpoon: @ 0x08C0CD90
	.incbin "baserom_jp.gba", 0xc0cd90, 0x28
	.globl gBattleAnimSpritePal_Coin
gBattleAnimSpritePal_Coin: @ 0x08C0CDB8
	.incbin "baserom_jp.gba", 0xc0cdb8, 0x1c
	.globl gBattleAnimSpritePal_CrackedEgg
gBattleAnimSpritePal_CrackedEgg: @ 0x08C0CDD4
	.incbin "baserom_jp.gba", 0xc0cdd4, 0x28
	.globl gBattleAnimSpritePal_FreshEgg
gBattleAnimSpritePal_FreshEgg: @ 0x08C0CDFC
	.incbin "baserom_jp.gba", 0xc0cdfc, 0x24
	.globl gBattleAnimSpriteGfx_Impact3
gBattleAnimSpriteGfx_Impact3: @ 0x08C0CE20
	.incbin "baserom_jp.gba", 0xc0ce20, 0x4a4
	.globl gBattleAnimSpriteGfx_Impact2
gBattleAnimSpriteGfx_Impact2: @ 0x08C0D2C4
	.incbin "baserom_jp.gba", 0xc0d2c4, 0x3c4
	.globl gBattleAnimSpriteGfx_Reticle
gBattleAnimSpriteGfx_Reticle: @ 0x08C0D688
	.incbin "baserom_jp.gba", 0xc0d688, 0xb8
	.globl gBattleAnimSpriteGfx_Breath
gBattleAnimSpriteGfx_Breath: @ 0x08C0D740
	.incbin "baserom_jp.gba", 0xc0d740, 0x170
	.globl gBattleAnimSpriteGfx_Snowball
gBattleAnimSpriteGfx_Snowball: @ 0x08C0D8B0
	.incbin "baserom_jp.gba", 0xc0d8b0, 0x50
	.globl gBattleAnimSpriteGfx_Vine
gBattleAnimSpriteGfx_Vine: @ 0x08C0D900
	.incbin "baserom_jp.gba", 0xc0d900, 0x274
	.globl gBattleAnimSpriteGfx_Sword2
gBattleAnimSpriteGfx_Sword2: @ 0x08C0DB74
	.incbin "baserom_jp.gba", 0xc0db74, 0x90
	.globl gBattleAnimSpriteGfx_Clapping
gBattleAnimSpriteGfx_Clapping: @ 0x08C0DC04
	.incbin "baserom_jp.gba", 0xc0dc04, 0x134
	.globl gBattleAnimSpriteGfx_RedTube
gBattleAnimSpriteGfx_RedTube: @ 0x08C0DD38
	.incbin "baserom_jp.gba", 0xc0dd38, 0x7c
	.globl gBattleAnimSpriteGfx_Amnesia
gBattleAnimSpriteGfx_Amnesia: @ 0x08C0DDB4
	.incbin "baserom_jp.gba", 0xc0ddb4, 0x6d0
	.globl gBattleAnimSpriteGfx_String2
gBattleAnimSpriteGfx_String2: @ 0x08C0E484
	.incbin "baserom_jp.gba", 0xc0e484, 0x1a4
	.globl gBattleAnimSpriteGfx_Pencil2
gBattleAnimSpriteGfx_Pencil2: @ 0x08C0E628
	.incbin "baserom_jp.gba", 0xc0e628, 0xb0
	.globl gBattleAnimSpriteGfx_Petal
gBattleAnimSpriteGfx_Petal: @ 0x08C0E6D8
	.incbin "baserom_jp.gba", 0xc0e6d8, 0x170
	.globl gBattleAnimSpriteGfx_BentSpoon
gBattleAnimSpriteGfx_BentSpoon: @ 0x08C0E848
	.incbin "baserom_jp.gba", 0xc0e848, 0x1e0
	.globl gBattleAnimSpriteGfx_Web
gBattleAnimSpriteGfx_Web: @ 0x08C0EA28
	.incbin "baserom_jp.gba", 0xc0ea28, 0x138
	.globl gBattleAnimSpriteGfx_Coin
gBattleAnimSpriteGfx_Coin: @ 0x08C0EB60
	.incbin "baserom_jp.gba", 0xc0eb60, 0x100
	.globl gBattleAnimSpriteGfx_CrackedEgg
gBattleAnimSpriteGfx_CrackedEgg: @ 0x08C0EC60
	.incbin "baserom_jp.gba", 0xc0ec60, 0x130
	.globl gBattleAnimSpriteGfx_HatchedEgg
gBattleAnimSpriteGfx_HatchedEgg: @ 0x08C0ED90
	.incbin "baserom_jp.gba", 0xc0ed90, 0x198
	.globl gBattleAnimSpriteGfx_FreshEgg
gBattleAnimSpriteGfx_FreshEgg: @ 0x08C0EF28
	.incbin "baserom_jp.gba", 0xc0ef28, 0x6c
	.globl gBattleAnimSpriteGfx_Fangs
gBattleAnimSpriteGfx_Fangs: @ 0x08C0EF94
	.incbin "baserom_jp.gba", 0xc0ef94, 0x1c0
	.globl gBattleAnimSpritePal_Fangs
gBattleAnimSpritePal_Fangs: @ 0x08C0F154
	.incbin "baserom_jp.gba", 0xc0f154, 0x28
	.globl gBattleAnimSpriteGfx_Explosion2
gBattleAnimSpriteGfx_Explosion2: @ 0x08C0F17C
	.incbin "baserom_jp.gba", 0xc0f17c, 0x584
	.globl gBattleAnimSpritePal_Explosion2
gBattleAnimSpritePal_Explosion2: @ 0x08C0F700
	.incbin "baserom_jp.gba", 0xc0f700, 0x28
	.globl gBattleAnimSpriteGfx_Explosion3
gBattleAnimSpriteGfx_Explosion3: @ 0x08C0F728
	.incbin "baserom_jp.gba", 0xc0f728, 0xf0
	.globl gBattleAnimSpriteGfx_WaterDroplet
gBattleAnimSpriteGfx_WaterDroplet: @ 0x08C0F818
	.incbin "baserom_jp.gba", 0xc0f818, 0x3ac
	.globl gBattleAnimSpritePal_WaterDroplet
gBattleAnimSpritePal_WaterDroplet: @ 0x08C0FBC4
	.incbin "baserom_jp.gba", 0xc0fbc4, 0x28
	.globl gBattleAnimSpriteGfx_WaterDroplet2
gBattleAnimSpriteGfx_WaterDroplet2: @ 0x08C0FBEC
	.incbin "baserom_jp.gba", 0xc0fbec, 0x384
	.globl gBattleAnimSpriteGfx_Seed2
gBattleAnimSpriteGfx_Seed2: @ 0x08C0FF70
	.incbin "baserom_jp.gba", 0xc0ff70, 0x28
	.globl gBattleAnimSpritePal_Seed2
gBattleAnimSpritePal_Seed2: @ 0x08C0FF98
	.incbin "baserom_jp.gba", 0xc0ff98, 0x28
	.globl gBattleAnimSpriteGfx_Sprout
gBattleAnimSpriteGfx_Sprout: @ 0x08C0FFC0
	.incbin "baserom_jp.gba", 0xc0ffc0, 0x3e4
	.globl gBattleAnimSpriteGfx_RedWand
gBattleAnimSpriteGfx_RedWand: @ 0x08C103A4
	.incbin "baserom_jp.gba", 0xc103a4, 0x44
	.globl gBattleAnimSpritePal_RedWand
gBattleAnimSpritePal_RedWand: @ 0x08C103E8
	.incbin "baserom_jp.gba", 0xc103e8, 0x24
	.globl gBattleAnimSpriteGfx_PurpleGreenUnk
gBattleAnimSpriteGfx_PurpleGreenUnk: @ 0x08C1040C
	.incbin "baserom_jp.gba", 0xc1040c, 0x328
	.globl gBattleAnimSpritePal_PurpleGreenUnk
gBattleAnimSpritePal_PurpleGreenUnk: @ 0x08C10734
	.incbin "baserom_jp.gba", 0xc10734, 0x28
	.globl gBattleAnimSpriteGfx_WaterColumn
gBattleAnimSpriteGfx_WaterColumn: @ 0x08C1075C
	.incbin "baserom_jp.gba", 0xc1075c, 0x26c
	.globl gBattleAnimSpritePal_WaterColumn
gBattleAnimSpritePal_WaterColumn: @ 0x08C109C8
	.incbin "baserom_jp.gba", 0xc109c8, 0x28
	.globl gBattleAnimSpriteGfx_MudUnk
gBattleAnimSpriteGfx_MudUnk: @ 0x08C109F0
	.incbin "baserom_jp.gba", 0xc109f0, 0xf4
	.globl gBattleAnimSpritePal_MudUnk
gBattleAnimSpritePal_MudUnk: @ 0x08C10AE4
	.incbin "baserom_jp.gba", 0xc10ae4, 0xb08
	.globl gBattleAnimSpriteGfx_RainDrops
gBattleAnimSpriteGfx_RainDrops: @ 0x08C115EC
	.incbin "baserom_jp.gba", 0xc115ec, 0x5b8


	.section .rodata.data_rest2b_after_healthbox
	.incbin "baserom_jp.gba", 0xc12aa4, 0x3ec
	.globl gBattleAnimSpriteGfx_FurySwipes
gBattleAnimSpriteGfx_FurySwipes: @ 0x08C12E90
	.incbin "baserom_jp.gba", 0xc12e90, 0x2ac
	.globl gBattleAnimSpritePal_FurySwipes
gBattleAnimSpritePal_FurySwipes: @ 0x08C1313C
	.incbin "baserom_jp.gba", 0xc1313c, 0x28
	.globl gBattleAnimSpriteGfx_Vine2
gBattleAnimSpriteGfx_Vine2: @ 0x08C13164
	.incbin "baserom_jp.gba", 0xc13164, 0x23c
	.globl gBattleAnimSpritePal_Vine2
gBattleAnimSpritePal_Vine2: @ 0x08C133A0
	.incbin "baserom_jp.gba", 0xc133a0, 0x1c
	.globl gBattleAnimSpriteGfx_Teeth
gBattleAnimSpriteGfx_Teeth: @ 0x08C133BC
	.incbin "baserom_jp.gba", 0xc133bc, 0x198
	.globl gBattleAnimSpritePal_Teeth
gBattleAnimSpritePal_Teeth: @ 0x08C13554
	.incbin "baserom_jp.gba", 0xc13554, 0x1c
	.globl gBattleAnimSpriteGfx_Bone2
gBattleAnimSpriteGfx_Bone2: @ 0x08C13570
	.incbin "baserom_jp.gba", 0xc13570, 0x290
	.globl gBattleAnimSpritePal_Bone2
gBattleAnimSpritePal_Bone2: @ 0x08C13800
	.incbin "baserom_jp.gba", 0xc13800, 0x28
	.globl gBattleAnimSpriteGfx_WhiteBag
gBattleAnimSpriteGfx_WhiteBag: @ 0x08C13828
	.incbin "baserom_jp.gba", 0xc13828, 0xf4
	.globl gBattleAnimSpritePal_WhiteBag
gBattleAnimSpritePal_WhiteBag: @ 0x08C1391C
	.incbin "baserom_jp.gba", 0xc1391c, 0x28
	.globl gBattleAnimSpriteGfx_Unknown
gBattleAnimSpriteGfx_Unknown: @ 0x08C13944
	.incbin "baserom_jp.gba", 0xc13944, 0x2c
	.globl gBattleAnimSpritePal_Unknown
gBattleAnimSpritePal_Unknown: @ 0x08C13970
	.incbin "baserom_jp.gba", 0xc13970, 0x24
	.globl gBattleAnimSpriteGfx_PurpleCoral
gBattleAnimSpriteGfx_PurpleCoral: @ 0x08C13994
	.incbin "baserom_jp.gba", 0xc13994, 0xfc
	.globl gBattleAnimSpritePal_PurpleCoral
gBattleAnimSpritePal_PurpleCoral: @ 0x08C13A90
	.incbin "baserom_jp.gba", 0xc13a90, 0x1c
	.globl gBattleAnimSpriteGfx_PurpleDroplet
gBattleAnimSpriteGfx_PurpleDroplet: @ 0x08C13AAC
	.incbin "baserom_jp.gba", 0xc13aac, 0x13c
	.globl gBattleAnimSpriteGfx_Shock2
gBattleAnimSpriteGfx_Shock2: @ 0x08C13BE8
	.incbin "baserom_jp.gba", 0xc13be8, 0x298
	.globl gBattleAnimSpritePal_Shock2
gBattleAnimSpritePal_Shock2: @ 0x08C13E80
	.incbin "baserom_jp.gba", 0xc13e80, 0x28
	.globl gBattleAnimSpriteGfx_ClosingEye2
gBattleAnimSpriteGfx_ClosingEye2: @ 0x08C13EA8
	.incbin "baserom_jp.gba", 0xc13ea8, 0xec
	.globl gBattleAnimSpritePal_ClosingEye2
gBattleAnimSpritePal_ClosingEye2: @ 0x08C13F94
	.incbin "baserom_jp.gba", 0xc13f94, 0x28
	.globl gBattleAnimSpriteGfx_MetalBall
gBattleAnimSpriteGfx_MetalBall: @ 0x08C13FBC
	.incbin "baserom_jp.gba", 0xc13fbc, 0x68
	.globl gBattleAnimSpritePal_MetalBall
gBattleAnimSpritePal_MetalBall: @ 0x08C14024
	.incbin "baserom_jp.gba", 0xc14024, 0x20
	.globl gBattleAnimSpriteGfx_MonsterDoll
gBattleAnimSpriteGfx_MonsterDoll: @ 0x08C14044
	.incbin "baserom_jp.gba", 0xc14044, 0x1a0
	.globl gBattleAnimSpritePal_MonsterDoll
gBattleAnimSpritePal_MonsterDoll: @ 0x08C141E4
	.incbin "baserom_jp.gba", 0xc141e4, 0x24
	.globl gBattleAnimSpriteGfx_Whirlwind
gBattleAnimSpriteGfx_Whirlwind: @ 0x08C14208
	.incbin "baserom_jp.gba", 0xc14208, 0x26c
	.globl gBattleAnimSpritePal_Whirlwind
gBattleAnimSpritePal_Whirlwind: @ 0x08C14474
	.incbin "baserom_jp.gba", 0xc14474, 0x20
	.globl gBattleAnimSpriteGfx_Whirlwind2
gBattleAnimSpriteGfx_Whirlwind2: @ 0x08C14494
	.incbin "baserom_jp.gba", 0xc14494, 0x64
	.globl gBattleAnimSpriteGfx_Explosion4
gBattleAnimSpriteGfx_Explosion4: @ 0x08C144F8
	.incbin "baserom_jp.gba", 0xc144f8, 0x3d0
	.globl gBattleAnimSpritePal_Explosion4
gBattleAnimSpritePal_Explosion4: @ 0x08C148C8
	.incbin "baserom_jp.gba", 0xc148c8, 0x28
	.globl gBattleAnimSpriteGfx_Explosion5
gBattleAnimSpriteGfx_Explosion5: @ 0x08C148F0
	.incbin "baserom_jp.gba", 0xc148f0, 0x170
	.globl gBattleAnimSpriteGfx_Tongue
gBattleAnimSpriteGfx_Tongue: @ 0x08C14A60
	.incbin "baserom_jp.gba", 0xc14a60, 0x100
	.globl gBattleAnimSpritePal_Tongue
gBattleAnimSpritePal_Tongue: @ 0x08C14B60
	.incbin "baserom_jp.gba", 0xc14b60, 0x20
	.globl gBattleAnimSpriteGfx_Smoke
gBattleAnimSpriteGfx_Smoke: @ 0x08C14B80
	.incbin "baserom_jp.gba", 0xc14b80, 0x7c
	.globl gBattleAnimSpritePal_Smoke
gBattleAnimSpritePal_Smoke: @ 0x08C14BFC
	.incbin "baserom_jp.gba", 0xc14bfc, 0x28
	.globl gBattleAnimSpriteGfx_Smoke2
gBattleAnimSpriteGfx_Smoke2: @ 0x08C14C24
	.incbin "baserom_jp.gba", 0xc14c24, 0xd0
	.globl gBattleAnimSpriteGfx_BlueFlames
gBattleAnimSpriteGfx_BlueFlames: @ 0x08C14CF4
	.incbin "baserom_jp.gba", 0xc14cf4, 0x23c
	.globl gBattleAnimSpritePal_BlueFlames
gBattleAnimSpritePal_BlueFlames: @ 0x08C14F30
	.incbin "baserom_jp.gba", 0xc14f30, 0x28
	.globl gBattleAnimSpriteGfx_BlueFlames2
gBattleAnimSpriteGfx_BlueFlames2: @ 0x08C14F58
	.incbin "baserom_jp.gba", 0xc14f58, 0xd4
