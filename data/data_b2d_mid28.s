.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_846FA13
gUnknown_846FA13: @ 0x846FA13
	.incbin "baserom_jp.gba", 0x46fa13, 0x5

	.globl gReflectionEffectPaletteMap
gReflectionEffectPaletteMap: @ 0x846FA18
	.incbin "baserom_jp.gba", 0x46fa18, 0x10

	.globl gUnknown_846FA28
gUnknown_846FA28: @ 0x846FA28
	.incbin "baserom_jp.gba", 0x46fa28, 0x18

	.globl gUnknown_846FA40
gUnknown_846FA40: @ 0x846FA40
	.incbin "baserom_jp.gba", 0x46fa40, 0x120c

	.globl gUnknown_8470C4C
gUnknown_8470C4C: @ 0x8470C4C
	.incbin "baserom_jp.gba", 0x470c4c, 0x1220

	.globl gUnknown_8471E6C
gUnknown_8471E6C: @ 0x8471E6C
	.incbin "baserom_jp.gba", 0x471e6c, 0xa860

	.globl gUnknown_847C6CC
gUnknown_847C6CC: @ 0x847C6CC
	.incbin "baserom_jp.gba", 0x47c6cc, 0x1240

	.globl gUnknown_847D90C
gUnknown_847D90C: @ 0x847D90C
	.incbin "baserom_jp.gba", 0x47d90c, 0x5ff80

	.globl gUnknown_84DD88C
gUnknown_84DD88C: @ 0x84DD88C
	.incbin "baserom_jp.gba", 0x4dd88c, 0x144

	.globl gUnknown_84DD9D0
gUnknown_84DD9D0: @ 0x84DD9D0
	.incbin "baserom_jp.gba", 0x4dd9d0, 0x51

	.globl gUnknown_84DDA21
gUnknown_84DDA21: @ 0x84DDA21
	.incbin "baserom_jp.gba", 0x4dda21, 0x53

	.globl gUnknown_84DDA74
gUnknown_84DDA74: @ 0x84DDA74
	.incbin "baserom_jp.gba", 0x4dda74, 0x3bc

	.globl gUnknown_84DDE30
gUnknown_84DDE30: @ 0x84DDE30
	.incbin "baserom_jp.gba", 0x4dde30, 0x1c

	.globl gFieldEffectObjectTemplatePointers
gFieldEffectObjectTemplatePointers: @ 0x84DDE4C
	.incbin "baserom_jp.gba", 0x4dde4c, 0x3ab4

	.globl gUnknown_84E1900
gUnknown_84E1900: @ 0x84E1900
	.incbin "baserom_jp.gba", 0x4e1900, 0x271c

	.globl gUnknown_84E401C
gUnknown_84E401C: @ 0x84E401C
	.incbin "baserom_jp.gba", 0x4e401c, 0x138

	.globl gUnknown_84E4154
gUnknown_84E4154: @ 0x84E4154
	.incbin "baserom_jp.gba", 0x4e4154, 0x78

	.globl gUnknown_84E41CC
gUnknown_84E41CC: @ 0x84E41CC
	.incbin "baserom_jp.gba", 0x4e41cc, 0xc0

	.globl gUnknown_84E428C
gUnknown_84E428C: @ 0x84E428C
	.incbin "baserom_jp.gba", 0x4e428c, 0x978

	.globl gUnknown_84E4C04
gUnknown_84E4C04: @ 0x84E4C04
	.incbin "baserom_jp.gba", 0x4e4c04, 0xac

	.globl gUnknown_84E4CB0
gUnknown_84E4CB0: @ 0x84E4CB0
	.incbin "baserom_jp.gba", 0x4e4cb0, 0xac

	.globl gUnknown_84E4D5C
gUnknown_84E4D5C: @ 0x84E4D5C
	.incbin "baserom_jp.gba", 0x4e4d5c, 0xc0

	.globl gSpritePalette_GeneralFieldEffect1
gSpritePalette_GeneralFieldEffect1: @ 0x84E4E1C
	.incbin "baserom_jp.gba", 0x4e4e1c, 0xd14

	.globl gUnknown_84E5B30
gUnknown_84E5B30: @ 0x84E5B30
	.incbin "baserom_jp.gba", 0x4e5b30, 0x10

	.globl gUnknown_84E5B40
gUnknown_84E5B40: @ 0x84E5B40
	.incbin "baserom_jp.gba", 0x4e5b40, 0x8

	.globl gUnknown_84E5B48
gUnknown_84E5B48: @ 0x84E5B48
	.incbin "baserom_jp.gba", 0x4e5b48, 0x1c

	.globl gUnknown_84E5B64
gUnknown_84E5B64: @ 0x84E5B64
	.incbin "baserom_jp.gba", 0x4e5b64, 0x4

	.globl gUnknown_84E5B68
gUnknown_84E5B68: @ 0x84E5B68
	.incbin "baserom_jp.gba", 0x4e5b68, 0x2c

	.globl gUnknown_84E5B94
gUnknown_84E5B94: @ 0x84E5B94
	.incbin "baserom_jp.gba", 0x4e5b94, 0x14

	.globl gUnknown_84E5BA8
gUnknown_84E5BA8: @ 0x84E5BA8
	.incbin "baserom_jp.gba", 0x4e5ba8, 0x1c

	.globl gUnknown_84E5BC4
gUnknown_84E5BC4: @ 0x84E5BC4
	.incbin "baserom_jp.gba", 0x4e5bc4, 0x4

	.globl gUnknown_84E5BC8
gUnknown_84E5BC8: @ 0x84E5BC8
	.incbin "baserom_jp.gba", 0x4e5bc8, 0x1c

	.globl gUnknown_84E5BE4
gUnknown_84E5BE4: @ 0x84E5BE4
	.incbin "baserom_jp.gba", 0x4e5be4, 0x4

	.globl gUnknown_84E5BE8
gUnknown_84E5BE8: @ 0x84E5BE8
	.incbin "baserom_jp.gba", 0x4e5be8, 0xc

	.globl gUnknown_84E5BF4
gUnknown_84E5BF4: @ 0x84E5BF4
	.incbin "baserom_jp.gba", 0x4e5bf4, 0x14

	.globl gUnknown_84E5C08
gUnknown_84E5C08: @ 0x84E5C08
	.incbin "baserom_jp.gba", 0x4e5c08, 0x14

	.globl gUnknown_84E5C1C
gUnknown_84E5C1C: @ 0x84E5C1C
	.incbin "baserom_jp.gba", 0x4e5c1c, 0x14

	.globl gUnknown_84E5C30
gUnknown_84E5C30: @ 0x84E5C30
	.incbin "baserom_jp.gba", 0x4e5c30, 0x14

	.globl gUnknown_84E5C44
gUnknown_84E5C44: @ 0x84E5C44
	.incbin "baserom_jp.gba", 0x4e5c44, 0x4

	.globl gUnknown_84E5C48
gUnknown_84E5C48: @ 0x84E5C48
	.incbin "baserom_jp.gba", 0x4e5c48, 0x14

	.globl gUnknown_84E5C5C
gUnknown_84E5C5C: @ 0x84E5C5C
	.incbin "baserom_jp.gba", 0x4e5c5c, 0x4

	.globl gUnknown_84E5C60
gUnknown_84E5C60: @ 0x84E5C60
	.incbin "baserom_jp.gba", 0x4e5c60, 0x14

	.globl gUnknown_84E5C74
gUnknown_84E5C74: @ 0x84E5C74
	.incbin "baserom_jp.gba", 0x4e5c74, 0x4

	.globl gUnknown_84E5C78
gUnknown_84E5C78: @ 0x84E5C78
	.incbin "baserom_jp.gba", 0x4e5c78, 0x14

	.globl gUnknown_84E5C8C
gUnknown_84E5C8C: @ 0x84E5C8C
	.incbin "baserom_jp.gba", 0x4e5c8c, 0x4

	.globl gUnknown_84E5C90
gUnknown_84E5C90: @ 0x84E5C90
	.incbin "baserom_jp.gba", 0x4e5c90, 0x14

	.globl gUnknown_84E5CA4
gUnknown_84E5CA4: @ 0x84E5CA4
	.incbin "baserom_jp.gba", 0x4e5ca4, 0x4

	.globl gUnknown_84E5CA8
gUnknown_84E5CA8: @ 0x84E5CA8
	.incbin "baserom_jp.gba", 0x4e5ca8, 0x14

	.globl gUnknown_84E5CBC
gUnknown_84E5CBC: @ 0x84E5CBC
	.incbin "baserom_jp.gba", 0x4e5cbc, 0x4

	.globl gUnknown_84E5CC0
gUnknown_84E5CC0: @ 0x84E5CC0
	.incbin "baserom_jp.gba", 0x4e5cc0, 0x14

	.globl gUnknown_84E5CD4
gUnknown_84E5CD4: @ 0x84E5CD4
	.incbin "baserom_jp.gba", 0x4e5cd4, 0x4

	.globl gUnknown_84E5CD8
gUnknown_84E5CD8: @ 0x84E5CD8
	.incbin "baserom_jp.gba", 0x4e5cd8, 0x14

	.globl gUnknown_84E5CEC
gUnknown_84E5CEC: @ 0x84E5CEC
	.incbin "baserom_jp.gba", 0x4e5cec, 0x4

	.globl gUnknown_84E5CF0
gUnknown_84E5CF0: @ 0x84E5CF0
	.incbin "baserom_jp.gba", 0x4e5cf0, 0x10

	.globl gUnknown_84E5D00
gUnknown_84E5D00: @ 0x84E5D00
	.incbin "baserom_jp.gba", 0x4e5d00, 0x8

	.globl gUnknown_84E5D08
gUnknown_84E5D08: @ 0x84E5D08
	.incbin "baserom_jp.gba", 0x4e5d08, 0x10

	.globl gUnknown_84E5D18
gUnknown_84E5D18: @ 0x84E5D18
	.incbin "baserom_jp.gba", 0x4e5d18, 0x8

	.globl gUnknown_84E5D20
gUnknown_84E5D20: @ 0x84E5D20
	.incbin "baserom_jp.gba", 0x4e5d20, 0x10

	.globl gUnknown_84E5D30
gUnknown_84E5D30: @ 0x84E5D30
	.incbin "baserom_jp.gba", 0x4e5d30, 0xc

	.globl gUnknown_84E5D3C
gUnknown_84E5D3C: @ 0x84E5D3C
	.incbin "baserom_jp.gba", 0x4e5d3c, 0x4

	.globl gUnknown_84E5D40
gUnknown_84E5D40: @ 0x84E5D40
	.incbin "baserom_jp.gba", 0x4e5d40, 0xc

	.globl gUnknown_84E5D4C
gUnknown_84E5D4C: @ 0x84E5D4C
	.incbin "baserom_jp.gba", 0x4e5d4c, 0x4

	.globl gUnknown_84E5D50
gUnknown_84E5D50: @ 0x84E5D50
	.incbin "baserom_jp.gba", 0x4e5d50, 0xc

	.globl gUnknown_84E5D5C
gUnknown_84E5D5C: @ 0x84E5D5C
	.incbin "baserom_jp.gba", 0x4e5d5c, 0x4

	.globl gUnknown_84E5D60
gUnknown_84E5D60: @ 0x84E5D60
	.incbin "baserom_jp.gba", 0x4e5d60, 0xc

	.globl gUnknown_84E5D6C
gUnknown_84E5D6C: @ 0x84E5D6C
	.incbin "baserom_jp.gba", 0x4e5d6c, 0x4

	.globl gUnknown_84E5D70
gUnknown_84E5D70: @ 0x84E5D70
	.incbin "baserom_jp.gba", 0x4e5d70, 0xc

	.globl gUnknown_84E5D7C
gUnknown_84E5D7C: @ 0x84E5D7C
	.incbin "baserom_jp.gba", 0x4e5d7c, 0x4

	.globl gUnknown_84E5D80
gUnknown_84E5D80: @ 0x84E5D80
	.incbin "baserom_jp.gba", 0x4e5d80, 0xc

	.globl gUnknown_84E5D8C
gUnknown_84E5D8C: @ 0x84E5D8C
	.incbin "baserom_jp.gba", 0x4e5d8c, 0x4

	.globl gUnknown_84E5D90
gUnknown_84E5D90: @ 0x84E5D90
	.incbin "baserom_jp.gba", 0x4e5d90, 0xc

	.globl gUnknown_84E5D9C
gUnknown_84E5D9C: @ 0x84E5D9C
	.incbin "baserom_jp.gba", 0x4e5d9c, 0xc

	.globl gUnknown_84E5DA8
gUnknown_84E5DA8: @ 0x84E5DA8
	.incbin "baserom_jp.gba", 0x4e5da8, 0x4

	.globl gUnknown_84E5DAC
gUnknown_84E5DAC: @ 0x84E5DAC
	.incbin "baserom_jp.gba", 0x4e5dac, 0xc

	.globl gUnknown_84E5DB8
gUnknown_84E5DB8: @ 0x84E5DB8
	.incbin "baserom_jp.gba", 0x4e5db8, 0x4

	.globl gUnknown_84E5DBC
gUnknown_84E5DBC: @ 0x84E5DBC
	.incbin "baserom_jp.gba", 0x4e5dbc, 0xc

	.globl gUnknown_84E5DC8
gUnknown_84E5DC8: @ 0x84E5DC8
	.incbin "baserom_jp.gba", 0x4e5dc8, 0x4

	.globl gUnknown_84E5DCC
gUnknown_84E5DCC: @ 0x84E5DCC
	.incbin "baserom_jp.gba", 0x4e5dcc, 0xc

	.globl gUnknown_84E5DD8
gUnknown_84E5DD8: @ 0x84E5DD8
	.incbin "baserom_jp.gba", 0x4e5dd8, 0x4

	.globl gUnknown_84E5DDC
gUnknown_84E5DDC: @ 0x84E5DDC
	.incbin "baserom_jp.gba", 0x4e5ddc, 0xc

	.globl gUnknown_84E5DE8
gUnknown_84E5DE8: @ 0x84E5DE8
	.incbin "baserom_jp.gba", 0x4e5de8, 0x4

	.globl gUnknown_84E5DEC
gUnknown_84E5DEC: @ 0x84E5DEC
	.incbin "baserom_jp.gba", 0x4e5dec, 0xc

	.globl gUnknown_84E5DF8
gUnknown_84E5DF8: @ 0x84E5DF8
	.incbin "baserom_jp.gba", 0x4e5df8, 0x4

	.globl gUnknown_84E5DFC
gUnknown_84E5DFC: @ 0x84E5DFC
	.incbin "baserom_jp.gba", 0x4e5dfc, 0xc

	.globl gUnknown_84E5E08
gUnknown_84E5E08: @ 0x84E5E08
	.incbin "baserom_jp.gba", 0x4e5e08, 0x4

	.globl gUnknown_84E5E0C
gUnknown_84E5E0C: @ 0x84E5E0C
	.incbin "baserom_jp.gba", 0x4e5e0c, 0xc

	.globl gUnknown_84E5E18
gUnknown_84E5E18: @ 0x84E5E18
	.incbin "baserom_jp.gba", 0x4e5e18, 0x4

	.globl gUnknown_84E5E1C
gUnknown_84E5E1C: @ 0x84E5E1C
	.incbin "baserom_jp.gba", 0x4e5e1c, 0xc

	.globl gUnknown_84E5E28
gUnknown_84E5E28: @ 0x84E5E28
	.incbin "baserom_jp.gba", 0x4e5e28, 0x4

	.globl gUnknown_84E5E2C
gUnknown_84E5E2C: @ 0x84E5E2C
	.incbin "baserom_jp.gba", 0x4e5e2c, 0xc

	.globl gUnknown_84E5E38
gUnknown_84E5E38: @ 0x84E5E38
	.incbin "baserom_jp.gba", 0x4e5e38, 0x4

	.globl gUnknown_84E5E3C
gUnknown_84E5E3C: @ 0x84E5E3C
	.incbin "baserom_jp.gba", 0x4e5e3c, 0xc

	.globl gUnknown_84E5E48
gUnknown_84E5E48: @ 0x84E5E48
	.incbin "baserom_jp.gba", 0x4e5e48, 0x4

	.globl gUnknown_84E5E4C
gUnknown_84E5E4C: @ 0x84E5E4C
	.incbin "baserom_jp.gba", 0x4e5e4c, 0xc

	.globl gUnknown_84E5E58
gUnknown_84E5E58: @ 0x84E5E58
	.incbin "baserom_jp.gba", 0x4e5e58, 0x4

	.globl gUnknown_84E5E5C
gUnknown_84E5E5C: @ 0x84E5E5C
	.incbin "baserom_jp.gba", 0x4e5e5c, 0xc

	.globl gUnknown_84E5E68
gUnknown_84E5E68: @ 0x84E5E68
	.incbin "baserom_jp.gba", 0x4e5e68, 0x4

	.globl gUnknown_84E5E6C
gUnknown_84E5E6C: @ 0x84E5E6C
	.incbin "baserom_jp.gba", 0x4e5e6c, 0xc

	.globl gUnknown_84E5E78
gUnknown_84E5E78: @ 0x84E5E78
	.incbin "baserom_jp.gba", 0x4e5e78, 0x4

	.globl gUnknown_84E5E7C
gUnknown_84E5E7C: @ 0x84E5E7C
	.incbin "baserom_jp.gba", 0x4e5e7c, 0xc

	.globl gUnknown_84E5E88
gUnknown_84E5E88: @ 0x84E5E88
	.incbin "baserom_jp.gba", 0x4e5e88, 0x4

	.globl gUnknown_84E5E8C
gUnknown_84E5E8C: @ 0x84E5E8C
	.incbin "baserom_jp.gba", 0x4e5e8c, 0xc

	.globl gUnknown_84E5E98
gUnknown_84E5E98: @ 0x84E5E98
	.incbin "baserom_jp.gba", 0x4e5e98, 0x4

	.globl gUnknown_84E5E9C
gUnknown_84E5E9C: @ 0x84E5E9C
	.incbin "baserom_jp.gba", 0x4e5e9c, 0xc

	.globl gUnknown_84E5EA8
gUnknown_84E5EA8: @ 0x84E5EA8
	.incbin "baserom_jp.gba", 0x4e5ea8, 0x4

	.globl gUnknown_84E5EAC
gUnknown_84E5EAC: @ 0x84E5EAC
	.incbin "baserom_jp.gba", 0x4e5eac, 0xc

	.globl gUnknown_84E5EB8
gUnknown_84E5EB8: @ 0x84E5EB8
	.incbin "baserom_jp.gba", 0x4e5eb8, 0x2c

	.globl gUnknown_84E5EE4
gUnknown_84E5EE4: @ 0x84E5EE4
	.incbin "baserom_jp.gba", 0x4e5ee4, 0xc

	.globl gUnknown_84E5EF0
gUnknown_84E5EF0: @ 0x84E5EF0
	.incbin "baserom_jp.gba", 0x4e5ef0, 0x4

	.globl gUnknown_84E5EF4
gUnknown_84E5EF4: @ 0x84E5EF4
	.incbin "baserom_jp.gba", 0x4e5ef4, 0x8

	.globl gUnknown_84E5EFC
gUnknown_84E5EFC: @ 0x84E5EFC
	.incbin "baserom_jp.gba", 0x4e5efc, 0x8

	.globl gUnknown_84E5F04
gUnknown_84E5F04: @ 0x84E5F04
	.incbin "baserom_jp.gba", 0x4e5f04, 0x8

	.globl gUnknown_84E5F0C
gUnknown_84E5F0C: @ 0x84E5F0C
	.incbin "baserom_jp.gba", 0x4e5f0c, 0x8

	.globl gUnknown_84E5F14
gUnknown_84E5F14: @ 0x84E5F14
	.incbin "baserom_jp.gba", 0x4e5f14, 0xc

	.globl gUnknown_84E5F20
gUnknown_84E5F20: @ 0x84E5F20
	.incbin "baserom_jp.gba", 0x4e5f20, 0x9

	.globl gUnknown_84E5F29
gUnknown_84E5F29: @ 0x84E5F29
	.incbin "baserom_jp.gba", 0x4e5f29, 0x9

	.globl gUnknown_84E5F32
gUnknown_84E5F32: @ 0x84E5F32
	.incbin "baserom_jp.gba", 0x4e5f32, 0x9

	.globl gUnknown_84E5F3B
gUnknown_84E5F3B: @ 0x84E5F3B
	.incbin "baserom_jp.gba", 0x4e5f3b, 0x9

	.globl gUnknown_84E5F44
gUnknown_84E5F44: @ 0x84E5F44
	.incbin "baserom_jp.gba", 0x4e5f44, 0x9

	.globl gUnknown_84E5F4D
gUnknown_84E5F4D: @ 0x84E5F4D
	.incbin "baserom_jp.gba", 0x4e5f4d, 0x9

	.globl gUnknown_84E5F56
gUnknown_84E5F56: @ 0x84E5F56
	.incbin "baserom_jp.gba", 0x4e5f56, 0x9

	.globl gUnknown_84E5F5F
gUnknown_84E5F5F: @ 0x84E5F5F
	.incbin "baserom_jp.gba", 0x4e5f5f, 0x9

	.globl gUnknown_84E5F68
gUnknown_84E5F68: @ 0x84E5F68
	.incbin "baserom_jp.gba", 0x4e5f68, 0x9

	.globl gUnknown_84E5F71
gUnknown_84E5F71: @ 0x84E5F71
	.incbin "baserom_jp.gba", 0x4e5f71, 0x9

	.globl gUnknown_84E5F7A
gUnknown_84E5F7A: @ 0x84E5F7A
	.incbin "baserom_jp.gba", 0x4e5f7a, 0x9

	.globl gUnknown_84E5F83
gUnknown_84E5F83: @ 0x84E5F83
	.incbin "baserom_jp.gba", 0x4e5f83, 0x9

	.globl gUnknown_84E5F8C
gUnknown_84E5F8C: @ 0x84E5F8C
	.incbin "baserom_jp.gba", 0x4e5f8c, 0x9

	.globl gUnknown_84E5F95
gUnknown_84E5F95: @ 0x84E5F95
	.incbin "baserom_jp.gba", 0x4e5f95, 0x9

	.globl gUnknown_84E5F9E
gUnknown_84E5F9E: @ 0x84E5F9E
	.incbin "baserom_jp.gba", 0x4e5f9e, 0x9

	.globl gUnknown_84E5FA7
gUnknown_84E5FA7: @ 0x84E5FA7
	.incbin "baserom_jp.gba", 0x4e5fa7, 0x9

	.globl gUnknown_84E5FB0
gUnknown_84E5FB0: @ 0x84E5FB0
	.incbin "baserom_jp.gba", 0x4e5fb0, 0x10

	.globl gUnknown_84E5FC0
gUnknown_84E5FC0: @ 0x84E5FC0
	.incbin "baserom_jp.gba", 0x4e5fc0, 0x10

	.globl gUnknown_84E5FD0
gUnknown_84E5FD0: @ 0x84E5FD0
	.incbin "baserom_jp.gba", 0x4E5FD0, 0x24
	.globl gUnknown_84E5FF4
gUnknown_84E5FF4: @ 0x84E5FF4
	.incbin "baserom_jp.gba", 0x4e5ff4, 0x5

	.globl gUnknown_84E5FF9
gUnknown_84E5FF9: @ 0x84E5FF9
	.incbin "baserom_jp.gba", 0x4e5ff9, 0x5

	.globl gUnknown_84E5FFE
gUnknown_84E5FFE: @ 0x84E5FFE
	.incbin "baserom_jp.gba", 0x4e5ffe, 0x5

	.globl gUnknown_84E6003
gUnknown_84E6003: @ 0x84E6003
	.incbin "baserom_jp.gba", 0x4e6003, 0x5

	.globl gUnknown_84E6008
gUnknown_84E6008: @ 0x84E6008
	.incbin "baserom_jp.gba", 0x4e6008, 0x5

	.globl gUnknown_84E600D
gUnknown_84E600D: @ 0x84E600D
	.incbin "baserom_jp.gba", 0x4e600d, 0x5

	.globl gUnknown_84E6012
gUnknown_84E6012: @ 0x84E6012
	.incbin "baserom_jp.gba", 0x4e6012, 0x5

	.globl gUnknown_84E6017
gUnknown_84E6017: @ 0x84E6017
	.incbin "baserom_jp.gba", 0x4e6017, 0x5

	.globl gUnknown_84E601C
gUnknown_84E601C: @ 0x84E601C
	.incbin "baserom_jp.gba", 0x4e601c, 0x5

	.globl gUnknown_84E6021
gUnknown_84E6021: @ 0x84E6021
	.incbin "baserom_jp.gba", 0x4e6021, 0x5

	.globl gUnknown_84E6026
gUnknown_84E6026: @ 0x84E6026
	.incbin "baserom_jp.gba", 0x4e6026, 0x5

	.globl gUnknown_84E602B
gUnknown_84E602B: @ 0x84E602B
	.incbin "baserom_jp.gba", 0x4e602b, 0x5

	.globl gUnknown_84E6030
gUnknown_84E6030: @ 0x84E6030
	.incbin "baserom_jp.gba", 0x4e6030, 0x5

	.globl gUnknown_84E6035
gUnknown_84E6035: @ 0x84E6035
	.incbin "baserom_jp.gba", 0x4e6035, 0x5

	.globl gUnknown_84E603A
gUnknown_84E603A: @ 0x84E603A
	.incbin "baserom_jp.gba", 0x4e603a, 0x5

	.globl gUnknown_84E603F
gUnknown_84E603F: @ 0x84E603F
	.incbin "baserom_jp.gba", 0x4e603f, 0x5

	.globl gUnknown_84E6044
gUnknown_84E6044: @ 0x84E6044
	.incbin "baserom_jp.gba", 0x4e6044, 0x5

	.globl gUnknown_84E6049
gUnknown_84E6049: @ 0x84E6049
	.incbin "baserom_jp.gba", 0x4e6049, 0x5

	.globl gUnknown_84E604E
gUnknown_84E604E: @ 0x84E604E
	.incbin "baserom_jp.gba", 0x4e604e, 0x5

	.globl gUnknown_84E6053
gUnknown_84E6053: @ 0x84E6053
	.incbin "baserom_jp.gba", 0x4e6053, 0x5

	.globl gUnknown_84E6058
gUnknown_84E6058: @ 0x84E6058
	.incbin "baserom_jp.gba", 0x4e6058, 0x5

	.globl gUnknown_84E605D
gUnknown_84E605D: @ 0x84E605D
	.incbin "baserom_jp.gba", 0x4e605d, 0x5

	.globl gUnknown_84E6062
gUnknown_84E6062: @ 0x84E6062
	.incbin "baserom_jp.gba", 0x4e6062, 0x5

	.globl gUnknown_84E6067
gUnknown_84E6067: @ 0x84E6067
	.incbin "baserom_jp.gba", 0x4e6067, 0x5

	.globl gUnknown_84E606C
gUnknown_84E606C: @ 0x84E606C
	.incbin "baserom_jp.gba", 0x4e606c, 0x5

	.globl gUnknown_84E6071
gUnknown_84E6071: @ 0x84E6071
	.incbin "baserom_jp.gba", 0x4e6071, 0x5

	.globl gUnknown_84E6076
gUnknown_84E6076: @ 0x84E6076
	.incbin "baserom_jp.gba", 0x4e6076, 0x5

	.globl gUnknown_84E607B
gUnknown_84E607B: @ 0x84E607B
	.incbin "baserom_jp.gba", 0x4e607b, 0x8

	.globl gUnknown_84E6083
gUnknown_84E6083: @ 0x84E6083
	.incbin "baserom_jp.gba", 0x4e6083, 0x10

	.globl gUnknown_84E6093
gUnknown_84E6093: @ 0x84E6093
	.incbin "baserom_jp.gba", 0x4e6093, 0x11

	.globl gUnknown_84E60A4
gUnknown_84E60A4: @ 0x84E60A4
	.incbin "baserom_jp.gba", 0x4e60a4, 0x298

	.globl gUnknown_84E633C
gUnknown_84E633C: @ 0x84E633C
	.incbin "baserom_jp.gba", 0x4e633c, 0xd4

	.globl gUnknown_84E6410
gUnknown_84E6410: @ 0x84E6410
	.incbin "baserom_jp.gba", 0x4e6410, 0x6

	.globl gUnknown_84E6416
gUnknown_84E6416: @ 0x84E6416
	.incbin "baserom_jp.gba", 0x4e6416, 0x61a

	.globl gUnknown_84E6A30
gUnknown_84E6A30: @ 0x84E6A30
	.incbin "baserom_jp.gba", 0x4e6a30, 0x8

	.globl gUnknown_84E6A38
gUnknown_84E6A38: @ 0x84E6A38
	.incbin "baserom_jp.gba", 0x4e6a38, 0x18

	.globl gUnknown_84E6A50
gUnknown_84E6A50: @ 0x84E6A50
	.incbin "baserom_jp.gba", 0x4e6a50, 0x18

	.globl gUnknown_84E6A68
gUnknown_84E6A68: @ 0x84E6A68
	.incbin "baserom_jp.gba", 0x4e6a68, 0x10

	.globl gUnknown_84E6A78
gUnknown_84E6A78: @ 0x84E6A78
	.incbin "baserom_jp.gba", 0x4e6a78, 0x10

	.globl gUnknown_84E6A88
gUnknown_84E6A88: @ 0x84E6A88
	.incbin "baserom_jp.gba", 0x4e6a88, 0x10

	.globl gUnknown_84E6A98
gUnknown_84E6A98: @ 0x84E6A98
	.incbin "baserom_jp.gba", 0x4e6a98, 0x10

	.globl gUnknown_84E6AA8
gUnknown_84E6AA8: @ 0x84E6AA8
	.incbin "baserom_jp.gba", 0x4e6aa8, 0xc

	.globl gUnknown_84E6AB4
gUnknown_84E6AB4: @ 0x84E6AB4
	.incbin "baserom_jp.gba", 0x4e6ab4, 0x4

	.globl gUnknown_84E6AB8
gUnknown_84E6AB8: @ 0x84E6AB8
	.incbin "baserom_jp.gba", 0x4e6ab8, 0x10

	.globl gUnknown_84E6AC8
gUnknown_84E6AC8: @ 0x84E6AC8
	.incbin "baserom_jp.gba", 0x4e6ac8, 0xe0

	.globl gUnknown_84E6BA8
gUnknown_84E6BA8: @ 0x84E6BA8
	.incbin "baserom_jp.gba", 0x4e6ba8, 0x14

	.globl gUnknown_84E6BBC
gUnknown_84E6BBC: @ 0x84E6BBC
	.incbin "baserom_jp.gba", 0x4e6bbc, 0xa

	.globl sFigure8XOffsets
sFigure8XOffsets: @ 0x84E6BC6
	.byte 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01
	.byte 0x02, 0x02, 0x01, 0x02, 0x02, 0x01, 0x02, 0x02, 0x01, 0x02, 0x01, 0x01
	.byte 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sFigure8YOffsets
sFigure8YOffsets: @ 0x84E6C0E
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01
	.byte 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0xFF
	.byte 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE
	.byte 0xFC, 0xFA, 0xF8, 0xF6, 0xF5, 0xF4, 0xF4, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8
	.byte 0xFA, 0xFC, 0x00, 0x00, 0x00, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xFA
	.byte 0xFB, 0xFB, 0xFC, 0xFD, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0xFC, 0xFA, 0xF8
	.byte 0xF7, 0xF6, 0xF6, 0xF6, 0xF7, 0xF8, 0xFA, 0xFB, 0xFD, 0xFE, 0x00, 0x00
	.byte 0x00, 0x00

	.globl gUnknown_84E6C88
gUnknown_84E6C88: @ 0x84E6C88
	.incbin "baserom_jp.gba", 0x4e6c88, 0xc

	.globl gUnknown_84E6C94
gUnknown_84E6C94: @ 0x84E6C94
	.incbin "baserom_jp.gba", 0x4e6c94, 0x6

	.globl gUnknown_84E6C9A
gUnknown_84E6C9A: @ 0x84E6C9A
	.incbin "baserom_jp.gba", 0x4e6c9a, 0x4

	.globl gUnknown_84E6C9E
gUnknown_84E6C9E: @ 0x84E6C9E
	.incbin "baserom_jp.gba", 0x4e6c9e, 0x6

	.globl gUnknown_84E6CA4
gUnknown_84E6CA4: @ 0x84E6CA4
	.incbin "baserom_jp.gba", 0x4e6ca4, 0x4

	.globl gUnknown_84E6CA8
gUnknown_84E6CA8: @ 0x84E6CA8
	.incbin "baserom_jp.gba", 0x4e6ca8, 0xc

	.globl gUnknown_84E6CB4
gUnknown_84E6CB4: @ 0x84E6CB4
	.incbin "baserom_jp.gba", 0x4e6cb4, 0x2c

	.globl gTextWindowFrame1_Gfx
gTextWindowFrame1_Gfx: @ 0x84E6CE0
	.incbin "baserom_jp.gba", 0x4e6ce0, 0x1680

	.globl gTextWindowFrame1_Pal
gTextWindowFrame1_Pal: @ 0x84E8360
	.incbin "baserom_jp.gba", 0x4e8360, 0x280

	.globl gMessageBox_Gfx
gMessageBox_Gfx: @ 0x84E85E0
	.incbin "baserom_jp.gba", 0x4e85e0, 0x1c0

	.globl sTextWindowPalettes
sTextWindowPalettes: @ 0x84E87A0
	.incbin "baserom_jp.gba", 0x4e87a0, 0xa0

	.globl gUnknown_84E8840
gUnknown_84E8840: @ 0x84E8840
	.incbin "baserom_jp.gba", 0x4e8840, 0x20

	.globl sWindowFrames
sWindowFrames: @ 0x84E8860
	.incbin "baserom_jp.gba", 0x4e8860, 0xa0

	.globl gNullScriptPtr
gNullScriptPtr: @ 0x84E8900
	.incbin "baserom_jp.gba", 0x4e8900, 0x4

	.globl sScriptConditionTable
sScriptConditionTable: @ 0x84E8904
	.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00
	.byte 0x00, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x00

	.globl sScriptStringVars
sScriptStringVars: @ 0x84E8918
	.incbin "baserom_jp.gba", 0x4e8918, 0xc

	.globl sCoordEventWeatherFuncs
sCoordEventWeatherFuncs: @ 0x84E8924
	.incbin "baserom_jp.gba", 0x4e8924, 0x68

	.globl sPerStepCallbacks
sPerStepCallbacks: @ 0x84E898C
	.incbin "baserom_jp.gba", 0x4e898c, 0x20

	.globl sHalfSubmergedBridgeMetatileOffsets
sHalfSubmergedBridgeMetatileOffsets: @ 0x84E89AC
	.incbin "baserom_jp.gba", 0x4e89ac, 0x20

	.globl sFullySubmergedBridgeMetatileOffsets
sFullySubmergedBridgeMetatileOffsets: @ 0x84E89CC
	.incbin "baserom_jp.gba", 0x4e89cc, 0x20

	.globl sFloatingBridgeMetatileOffsets
sFloatingBridgeMetatileOffsets: @ 0x84E89EC
	.incbin "baserom_jp.gba", 0x4e89ec, 0x20

	.globl sSootopolisGymIceRowVars
sSootopolisGymIceRowVars: @ 0x84E8A0C
	.hword 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4001, 0x4002, 0x4003, 0x4004, 0x0000, 0x0000
	.hword 0x4005, 0x4006, 0x4007, 0x0000, 0x0000, 0x4008, 0x4009, 0x400A, 0x0000, 0x0000, 0x0000, 0x0000
	.hword 0x0000, 0x0000

	.globl sMuddySlopeMetatiles
sMuddySlopeMetatiles: @ 0x84E8A40
	.hword 0x00E8, 0x00EB, 0x00EA, 0x00E9

	.globl gResetRtcBgTemplates
gResetRtcBgTemplates: @ 0x84E8A48
	.incbin "baserom_jp.gba", 0x4e8a48, 0x4

	.globl gResetRtcWindowTemplates
gResetRtcWindowTemplates: @ 0x84E8A4C
	.incbin "baserom_jp.gba", 0x4e8a4c, 0x18

	.globl gResetRtcInputTimeWindow
gResetRtcInputTimeWindow: @ 0x84E8A64
	.incbin "baserom_jp.gba", 0x4e8a64, 0x8
