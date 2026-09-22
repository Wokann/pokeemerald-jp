@ Secret Power and Sand Pillar descriptors retained in the original mid60
@ tail-prefix section. Keep these byte-exact owners here until fldeff_misc.c
@ can place the corresponding C structures at their JP ROM addresses.

	.globl gSpritePalette_SecretPower_Cave
gSpritePalette_SecretPower_Cave: @ 0x0856A22C
	.incbin "baserom_jp.gba", 0x56a22c, 0x8

	.globl gSpritePalette_SecretPower_Plant
gSpritePalette_SecretPower_Plant: @ 0x0856A234
	.incbin "baserom_jp.gba", 0x56a234, 0x8

sOam_SandPillar: @ 0x0856A23C
	.incbin "baserom_jp.gba", 0x56a23c, 0x8

sAnim_SandPillar: @ 0x0856A244
	.incbin "baserom_jp.gba", 0x56a244, 0x10

sAnimTable_SandPillar: @ 0x0856A254
	.incbin "baserom_jp.gba", 0x56a254, 0x4

sPicTable_SandPillar: @ 0x0856A258
	.incbin "baserom_jp.gba", 0x56a258, 0x18

	.globl sSpriteTemplate_SandPillar
sSpriteTemplate_SandPillar: @ 0x0856A270
	.incbin "baserom_jp.gba", 0x56a270, 0x18

	.globl gSpritePalette_SandPillar
gSpritePalette_SandPillar: @ 0x0856A288
	.incbin "baserom_jp.gba", 0x56a288, 0x8
