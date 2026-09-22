@ Secret Power and Sand Pillar graphics retained in the original mid60 section.
@ This JP owner includes a required 0x20-byte filler and an unused sixth tree
@ frame. Keep the physical order and exact bytes until fldeff_misc.c owns a
@ precisely placed rodata section and regenerated graphics assets.

	.globl sSecretPowerCave_Gfx
sSecretPowerCave_Gfx: @ 0x0856955C
	.incbin "baserom_jp.gba", 0x56955c, 0x280

	.globl sSecretPowerCave_Filler
sSecretPowerCave_Filler: @ 0x085697DC
	.incbin "baserom_jp.gba", 0x5697dc, 0x20

	.globl sSecretPowerCave_Pal
sSecretPowerCave_Pal: @ 0x085697FC
	.incbin "baserom_jp.gba", 0x5697fc, 0x20

	.globl sSecretPowerShrub_Gfx
sSecretPowerShrub_Gfx: @ 0x0856981C
	.incbin "baserom_jp.gba", 0x56981c, 0x280

	.globl sSecretPowerTree_Gfx
sSecretPowerTree_Gfx: @ 0x08569A9C
	.incbin "baserom_jp.gba", 0x569a9c, 0x300

	.globl sSecretPowerPlant_Pal
sSecretPowerPlant_Pal: @ 0x08569D9C
	.incbin "baserom_jp.gba", 0x569d9c, 0x20

	.globl sSandPillar0_Gfx
sSandPillar0_Gfx: @ 0x08569DBC
	.incbin "baserom_jp.gba", 0x569dbc, 0x100

	.globl sSandPillar1_Gfx
sSandPillar1_Gfx: @ 0x08569EBC
	.incbin "baserom_jp.gba", 0x569ebc, 0x100

	.globl sSandPillar2_Gfx
sSandPillar2_Gfx: @ 0x08569FBC
	.incbin "baserom_jp.gba", 0x569fbc, 0x100
