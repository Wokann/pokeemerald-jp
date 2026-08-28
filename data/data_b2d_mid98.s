.include "sound/MPlayDef.s"
	.section .rodata.mid98_prefix
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_85CD19F
gUnknown_85CD19F: @ 0x85CD19F
	.string "エラーがはっせいしました\n"
	.string "しゅうりょうします$Aボタンを　おしてください$つながりました$データを　じゅしんしました$セーブできませんでした$セーブできました$ロードできませんでした$ロードできました$"
	.globl gUnknown_85CD204
gUnknown_85CD204: @ 0x85CD204
	.byte 0xF8, 0x01, 0x00, 0x00

	.globl gUnknown_85CD208
gUnknown_85CD208: @ 0x85CD208
	.byte 0x00, 0x04, 0x0F, 0x16, 0x04, 0x0E, 0x14, 0x00
	.byte 0x00, 0x07, 0x06, 0x10, 0x04, 0x0E, 0x6C, 0x00
	.byte 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.section .rodata.mid98_between

	.globl sRegicePathCoords
sRegicePathCoords: @ 0x85CD314
	.byte 0x04, 0x15, 0x05, 0x15, 0x06, 0x15, 0x07, 0x15, 0x08, 0x15, 0x09, 0x15
	.byte 0x0A, 0x15, 0x0B, 0x15, 0x0C, 0x15, 0x0C, 0x16, 0x0C, 0x17, 0x0D, 0x17
	.byte 0x0D, 0x18, 0x0D, 0x19, 0x0D, 0x1A, 0x0D, 0x1B, 0x0C, 0x1B, 0x0C, 0x1C
	.byte 0x04, 0x1D, 0x05, 0x1D, 0x06, 0x1D, 0x07, 0x1D, 0x08, 0x1D, 0x09, 0x1D
	.byte 0x0A, 0x1D, 0x0B, 0x1D, 0x0C, 0x1D, 0x04, 0x1C, 0x04, 0x1B, 0x03, 0x1B
	.byte 0x03, 0x1A, 0x03, 0x19, 0x03, 0x18, 0x03, 0x17, 0x04, 0x17, 0x04, 0x16

	.globl gUnknown_85CD35C
gUnknown_85CD35C: @ 0x85CD35C
	.incbin "baserom_jp.gba", 0x5cd35c, 0x32

	.globl gUnknown_85CD38E
gUnknown_85CD38E: @ 0x85CD38E
	.incbin "baserom_jp.gba", 0x5cd38e, 0x12

	.globl gUnknown_85CD3A0
gUnknown_85CD3A0: @ 0x85CD3A0
	.incbin "baserom_jp.gba", 0x5cd3a0, 0x5fc

	.globl gUnknown_85CD99C
gUnknown_85CD99C: @ 0x85CD99C
	.4byte 0x085CD7DC, 0x085CD7EC, 0x085CD834, 0x085CD87C
	.4byte 0x085CD8C4, 0x085CD90C, 0x085CD954, 0x085CD7DC
	.4byte 0x085CD7DC, 0x085CD7DC, 0x085CD7DC, 0x085CD80C
	.4byte 0x085CD854, 0x085CD89C, 0x085CD8E4, 0x085CD92C
	.4byte 0x085CD974, 0x085CD7DC, 0x085CD7DC, 0x085CD7DC
	.4byte 0x085CD7DC

	.globl gUnknown_85CD9F0
gUnknown_85CD9F0: @ 0x85CD9F0
	.byte 0xF0, 0x01, 0x00, 0x00, 0xE9, 0x31, 0x00, 0x00

	.globl gUnknown_85CD9F8
gUnknown_85CD9F8: @ 0x85CD9F8
	.byte 0x00, 0x01, 0x0F, 0x1C, 0x04, 0x0F, 0x0A, 0x00
	.byte 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.section .rodata.mid98_suffix

	.globl gUnknown_85CDBB0
gUnknown_85CDBB0: @ 0x85CDBB0
	.incbin "baserom_jp.gba", 0x5cdbb0, 0x20

	.globl gUnknown_85CDBD0
gUnknown_85CDBD0: @ 0x85CDBD0
	.incbin "baserom_jp.gba", 0x5cdbd0, 0x20

	.globl gUnknown_85CDBF0
gUnknown_85CDBF0: @ 0x85CDBF0
	.incbin "baserom_jp.gba", 0x5cdbf0, 0x20

	.globl gUnknown_85CDC10
gUnknown_85CDC10: @ 0x85CDC10
	.incbin "baserom_jp.gba", 0x5cdc10, 0x480

	.globl gUnknown_85CE090
gUnknown_85CE090: @ 0x85CE090
	.incbin "baserom_jp.gba", 0x5ce090, 0x13c

	.globl gUnknown_85CE1CC
gUnknown_85CE1CC: @ 0x85CE1CC
	.incbin "baserom_jp.gba", 0x5ce1cc, 0x60

	.globl gUnknown_85CE22C
gUnknown_85CE22C: @ 0x85CE22C
	.incbin "baserom_jp.gba", 0x5ce22c, 0x60

	.globl gUnknown_85CE28C
gUnknown_85CE28C: @ 0x85CE28C
	.incbin "baserom_jp.gba", 0x5ce28c, 0x5dc

	.globl gUnknown_85CE868
gUnknown_85CE868: @ 0x85CE868
	.incbin "baserom_jp.gba", 0x5ce868, 0x2d0

	.globl gUnknown_85CEB38
gUnknown_85CEB38: @ 0x85CEB38
	.incbin "baserom_jp.gba", 0x5ceb38, 0x20

	.globl gUnknown_85CEB58
gUnknown_85CEB58: @ 0x85CEB58
	.incbin "baserom_jp.gba", 0x5ceb58, 0x20

	.globl gUnknown_85CEB78
gUnknown_85CEB78: @ 0x85CEB78
	.incbin "baserom_jp.gba", 0x5ceb78, 0x13c

	.globl gUnknown_85CECB4
gUnknown_85CECB4: @ 0x85CECB4
	.incbin "baserom_jp.gba", 0x5cecb4, 0x20

	.globl gUnknown_85CECD4
gUnknown_85CECD4: @ 0x85CECD4
	.incbin "baserom_jp.gba", 0x5cecd4, 0x20

	.globl gUnknown_85CECF4
gUnknown_85CECF4: @ 0x85CECF4
	.incbin "baserom_jp.gba", 0x5cecf4, 0x688

	.globl gUnknown_85CF37C
gUnknown_85CF37C: @ 0x85CF37C
	.incbin "baserom_jp.gba", 0x5cf37c, 0x304

	.globl gUnknown_85CF680
gUnknown_85CF680: @ 0x85CF680
	.incbin "baserom_jp.gba", 0x5cf680, 0x16c

	.globl gUnknown_85CF7EC
gUnknown_85CF7EC: @ 0x85CF7EC
	.incbin "baserom_jp.gba", 0x5cf7ec, 0x40

	.globl gUnknown_85CF82C
gUnknown_85CF82C: @ 0x85CF82C
	.incbin "baserom_jp.gba", 0x5cf82c, 0x1ec

	.globl gUnknown_85CFA18
gUnknown_85CFA18: @ 0x85CFA18
	.incbin "baserom_jp.gba", 0x5cfa18, 0x20

	.globl gUnknown_85CFA38
gUnknown_85CFA38: @ 0x85CFA38
	.incbin "baserom_jp.gba", 0x5cfa38, 0x2ae4

	.globl gUnknown_85D251C
gUnknown_85D251C: @ 0x85D251C
	.incbin "baserom_jp.gba", 0x5d251c, 0x18

	.globl gUnknown_85D2534
gUnknown_85D2534: @ 0x85D2534
	.incbin "baserom_jp.gba", 0x5d2534, 0x30

	.globl gUnknown_85D2564
gUnknown_85D2564: @ 0x85D2564
	.incbin "baserom_jp.gba", 0x5d2564, 0x10

	.globl gUnknown_85D2574
gUnknown_85D2574: @ 0x85D2574
	.incbin "baserom_jp.gba", 0x5d2574, 0x48

	.globl gUnknown_85D25BC
gUnknown_85D25BC: @ 0x85D25BC
	.incbin "baserom_jp.gba", 0x5d25bc, 0x28

	.globl gUnknown_85D25E4
gUnknown_85D25E4: @ 0x85D25E4
	.incbin "baserom_jp.gba", 0x5d25e4, 0xc

	.globl gUnknown_85D25F0
gUnknown_85D25F0: @ 0x85D25F0
	.incbin "baserom_jp.gba", 0x5d25f0, 0x60

	.globl gUnknown_85D2650
gUnknown_85D2650: @ 0x85D2650
	.incbin "baserom_jp.gba", 0x5d2650, 0x18

	.globl gUnknown_85D2668
gUnknown_85D2668: @ 0x85D2668
	.incbin "baserom_jp.gba", 0x5d2668, 0x4

	.globl gUnknown_85D266C
gUnknown_85D266C: @ 0x85D266C
	.incbin "baserom_jp.gba", 0x5d266c, 0x50

	.globl gUnknown_85D26BC
gUnknown_85D26BC: @ 0x85D26BC
	.incbin "baserom_jp.gba", 0x5d26bc, 0x18

	.globl gUnknown_85D26D4
gUnknown_85D26D4: @ 0x85D26D4
	.incbin "baserom_jp.gba", 0x5d26d4, 0x38

	.globl gUnknown_85D270C
gUnknown_85D270C: @ 0x85D270C
	.incbin "baserom_jp.gba", 0x5d270c, 0x18

	.globl gUnknown_85D2724
gUnknown_85D2724: @ 0x85D2724
	.incbin "baserom_jp.gba", 0x5d2724, 0x38

	.globl gUnknown_85D275C
gUnknown_85D275C: @ 0x85D275C
	.incbin "baserom_jp.gba", 0x5d275c, 0x18

	.globl gUnknown_85D2774
gUnknown_85D2774: @ 0x85D2774
	.incbin "baserom_jp.gba", 0x5d2774, 0x18

	.globl gUnknown_85D278C
gUnknown_85D278C: @ 0x85D278C
	.incbin "baserom_jp.gba", 0x5d278c, 0x10

	.globl gUnknown_85D279C
gUnknown_85D279C: @ 0x85D279C
	.incbin "baserom_jp.gba", 0x5d279c, 0x10

	.globl gUnknown_85D27AC
gUnknown_85D27AC: @ 0x85D27AC
	.incbin "baserom_jp.gba", 0x5d27ac, 0x20

	.globl gUnknown_85D27CC
gUnknown_85D27CC: @ 0x85D27CC
	.incbin "baserom_jp.gba", 0x5d27cc, 0x10

	.globl gUnknown_85D27DC
gUnknown_85D27DC: @ 0x85D27DC
	.incbin "baserom_jp.gba", 0x5d27dc, 0x28

	.globl gUnknown_85D2804
gUnknown_85D2804: @ 0x85D2804
	.incbin "baserom_jp.gba", 0x5d2804, 0x10

	.globl gUnknown_85D2814
gUnknown_85D2814: @ 0x85D2814
	.incbin "baserom_jp.gba", 0x5d2814, 0x10

	.globl gUnknown_85D2824
gUnknown_85D2824: @ 0x85D2824
	.incbin "baserom_jp.gba", 0x5d2824, 0x30

	.globl gUnknown_85D2854
gUnknown_85D2854: @ 0x85D2854
	.incbin "baserom_jp.gba", 0x5d2854, 0x28

	.globl gUnknown_85D287C
gUnknown_85D287C: @ 0x85D287C
	.incbin "baserom_jp.gba", 0x5d287c, 0x10

	.globl gUnknown_85D288C
gUnknown_85D288C: @ 0x85D288C
	.incbin "baserom_jp.gba", 0x5d288c, 0x50

	.globl gUnknown_85D28DC
gUnknown_85D28DC: @ 0x85D28DC
	.incbin "baserom_jp.gba", 0x5d28dc, 0x10

	.globl gUnknown_85D28EC
gUnknown_85D28EC: @ 0x85D28EC
	.incbin "baserom_jp.gba", 0x5d28ec, 0x24

	.globl gUnknown_85D2910
gUnknown_85D2910: @ 0x85D2910
	.incbin "baserom_jp.gba", 0x5d2910, 0x18

	.globl gUnknown_85D2928
gUnknown_85D2928: @ 0x85D2928
	.incbin "baserom_jp.gba", 0x5d2928, 0x198

	.globl sWordSounds
sWordSounds: @ 0x85D2AC0
	.4byte 0x085D2960, 0x085D2964, 0x085D2968, 0x085D296C
	.4byte 0x085D2970, 0x085D2974, 0x085D297A, 0x085D2980
	.4byte 0x085D2986, 0x085D298C, 0x085D2992, 0x085D299A
	.4byte 0x085D29A2, 0x085D29AA, 0x085D29B2, 0x085D29BA
	.4byte 0x085D29C4, 0x085D29CE, 0x085D29D8, 0x085D29E2
	.4byte 0x085D29EC, 0x085D29F8, 0x085D2A04, 0x085D2A10
	.4byte 0x085D2A1C, 0x085D2A28, 0x085D2A36, 0x085D2A44
	.4byte 0x085D2A52, 0x085D2A60, 0x085D2A6E, 0x085D2A7E
	.4byte 0x085D2A8E, 0x085D2A9E, 0x085D2AAE

	.globl sWordPhonemes
sWordPhonemes: @ 0x85D2B4C
	.incbin "baserom_jp.gba", 0x5d2b4c, 0x3c0

	.globl sVariableDmgMoves
sVariableDmgMoves: @ 0x85D2F0C
	.hword 0x0044, 0x005A, 0x0075, 0x00F3, 0x0020, 0x00AF, 0x00B3, 0x00ED, 0x0149, 0x0108, 0x011C, 0x0143
	.hword 0x008A, 0x0137, 0x00AD, 0x00DC, 0x000C, 0x00DA, 0x00D8, 0x011B, 0x00D9, 0x0117, 0xFFFF, 0x00DE
	.hword 0x0095, 0xFFFF, 0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0001, 0x0000, 0x0005, 0x0001
	.hword 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001
	.hword 0x0001, 0x0001, 0x0001, 0x0005, 0x0005, 0x0004, 0x0005, 0x0001, 0x0003, 0x0001, 0x0003, 0x0005
	.hword 0x0001, 0x0007, 0x0001, 0x0007, 0x0007, 0x0001, 0x0005, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001
	.hword 0x0005, 0x0001, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000
	.hword 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0007, 0x0004, 0x0004, 0x0001, 0x0001
	.hword 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0001, 0x0004, 0x0005, 0x0002
	.hword 0x0004, 0x0001, 0x0004, 0x0001, 0x0007, 0x0002, 0x0001, 0x0005, 0x0007, 0x0003, 0x0003, 0x0004
	.hword 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0002, 0x0004, 0x0001, 0x0005, 0x0001, 0x0001, 0x0004
	.hword 0x0005, 0x0003, 0x0001, 0x0002, 0x0001, 0x0005, 0x0004, 0x0003, 0x0006, 0x0004, 0x0003, 0x0003
	.hword 0x0003, 0x0002, 0x0004, 0x0001, 0x0001, 0x0001, 0x0005, 0x0001, 0x0001, 0x0007, 0x0002, 0x0002
	.hword 0x0001, 0x0001, 0x0004, 0x0004, 0x0004, 0x0001, 0x0004, 0x0004, 0x0001, 0x0001, 0x0001, 0x0001
	.hword 0x0007, 0x0007, 0x0006, 0x0003, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001
	.hword 0x0002, 0x0003, 0x0001, 0x0001, 0x0004, 0x0004, 0x0003, 0x0003, 0x0003, 0x0001, 0x0004, 0x0007
	.hword 0x0007, 0x0005, 0x0007, 0x0001, 0x0007, 0x0001, 0x0005, 0x0000, 0x0004, 0x0004, 0x0004, 0x0004
	.hword 0x0004, 0x0002, 0x0002, 0x0006, 0x0003, 0x0006, 0x0004, 0x0004, 0x0002, 0x0005, 0x0002, 0x0001
	.hword 0x0001, 0x0006, 0x0006, 0x0006, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0006, 0x0001, 0x0004
	.hword 0x0001, 0x0001, 0x0003, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0004, 0x0001, 0x0001, 0x0003
	.hword 0x0004, 0xFFFD, 0xFFFA, 0x0004, 0x0004, 0x0006, 0x0006, 0x0007, 0x0006, 0x0002, 0x0091, 0x0003
	.hword 0x00FA, 0x0003, 0x00BE, 0x0003, 0x0080, 0x0003, 0x006E, 0x0003, 0x0098, 0x0003, 0x0143, 0x0003
	.hword 0x0123, 0x0003, 0x007F, 0x0003, 0x014A, 0x0003, 0x0039, 0x0003, 0x0134, 0x0003, 0x0038, 0x0003
	.hword 0x003D, 0x0003, 0x015A, 0x0000, 0x0037, 0x0003, 0x0160, 0x0003, 0x0137, 0x0003, 0x0057, 0x0003
	.hword 0x004C, 0xFFFC, 0x013B, 0xFFFC, 0x00AC, 0xFFFC, 0x0035, 0xFFFC, 0x00DD, 0xFFFC, 0x007E, 0xFFFC
	.hword 0x0101, 0xFFFC, 0x0034, 0xFFFC, 0x0133, 0xFFFC, 0x012B, 0xFFFC, 0x011C, 0xFFFC, 0x0053, 0xFFFC
	.hword 0x0007, 0xFFFC, 0x004C, 0xFFFC, 0xFFFF, 0x0000, 0x013B, 0x0003, 0x00AC, 0x0003, 0x0035, 0x0003
	.hword 0x00DD, 0x0003, 0x007E, 0x0003, 0x0101, 0x0003, 0x0034, 0x0003, 0x0133, 0x0003, 0x012B, 0x0003
	.hword 0x011C, 0x0003, 0x0053, 0x0003, 0x0007, 0x0003, 0x004C, 0x0005, 0x00EB, 0x0003, 0x00EA, 0x0003
	.hword 0x00EC, 0x0003, 0x0137, 0x0003, 0xFFFF, 0x0000, 0x0137, 0x0003, 0x004C, 0xFFFD, 0xFFFF, 0x0000
	.hword 0x0137, 0x0003, 0x004C, 0xFFFD, 0xFFFF, 0x0000, 0x0055, 0x0003, 0x0009, 0x0003, 0x00D1, 0x0003
	.hword 0x0054, 0x0003, 0x00C0, 0x0003, 0x015F, 0x0003, 0x0056, 0x0000, 0x0057, 0x0003, 0x0158, 0x0003
	.hword 0xFFFF, 0x0000, 0x0005, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0003, 0x0005, 0x0005, 0x0005
	.hword 0x0005, 0x0005, 0x0004, 0x0005, 0x0005, 0x0003, 0x0003, 0x0004, 0x0003, 0x0006, 0x0006, 0x0006
	.hword 0x0004, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0004, 0x0004, 0x0004, 0x0004
	.hword 0x0004, 0x0004, 0x0004, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0002, 0x0002
	.hword 0x0002, 0x0002, 0x0002, 0x0002, 0x0002, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004
	.hword 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0x0000

	.globl sPointsArray
sPointsArray: @ 0x85D3294
	.4byte 0x085D2F40, 0x085D30EC, 0x085D30F2, 0x085D3100
	.4byte 0x085D3188, 0x085D31D0, 0x085D31DC, 0x085D31E8
	.4byte 0x085D3210, 0x085D321E, 0x085D3228, 0x085D322A
	.4byte 0x085D322C, 0x085D322E, 0x085D3230, 0x085D3232
	.4byte 0x085D3234, 0x085D3236, 0x085D3238, 0x085D323A
	.4byte 0x085D323A, 0x085D323C, 0x085D323E, 0x085D324C
	.4byte 0x085D325A, 0x085D3268, 0x085D3276, 0x085D3284

	.globl sSpecialBattleStrings
sSpecialBattleStrings: @ 0x85D3304
	.string "ビ　”　B　ザ　'　♂　ヅ　ハ　ダ　セ　ぃ　れ　ド　ふ　へ　ト　タ　$$"
	.globl gUnknown_85D3328
gUnknown_85D3328: @ 0x85D3328
	.incbin "baserom_jp.gba", 0x5d3328, 0x19c

	.globl gUnknown_85D34C4
gUnknown_85D34C4: @ 0x85D34C4
	.string "　おああ　そあえ　いあい　いあい　いあい　いあい　い　$"
	.globl gUnknown_85D34E0
gUnknown_85D34E0: @ 0x85D34E0
	.incbin "baserom_jp.gba", 0x5d34e0, 0x8

	.globl sMonAnimFunctions
sMonAnimFunctions: @ 0x85D34E8
	.4byte Anim_VerticalSquishBounce + 1, Anim_CircularStretchTwice + 1, Anim_HorizontalVibrate + 1, Anim_HorizontalSlide + 1, Anim_VerticalSlide + 1, Anim_BounceRotateToSides + 1, Anim_VerticalJumpsHorizontalJumps + 1, Anim_RotateToSides + 1
	.4byte Anim_RotateToSides_Twice + 1, Anim_GrowVibrate + 1, Anim_ZigzagFast + 1, Anim_SwingConcave + 1, Anim_SwingConcave_Fast + 1, Anim_SwingConvex + 1, Anim_SwingConvex_Fast + 1, Anim_HorizontalShake + 1
	.4byte Anim_VerticalShake + 1, Anim_CircularVibrate + 1, Anim_Twist + 1, Anim_ShrinkGrow + 1, Anim_CircleCounterclockwise + 1, Anim_GlowBlack + 1, Anim_HorizontalStretch + 1, Anim_VerticalStretch + 1
	.4byte Anim_RisingWobble + 1, Anim_VerticalShakeTwice + 1, Anim_TipMoveForward + 1, Anim_HorizontalPivot + 1, Anim_VerticalSlideWobble + 1, Anim_HorizontalSlideWobble + 1, Anim_VerticalJumps_Big + 1, Anim_Spin_Long + 1
	.4byte Anim_GlowOrange + 1, Anim_GlowRed + 1, Anim_GlowBlue + 1, Anim_GlowYellow + 1, Anim_GlowPurple + 1, Anim_BackAndLunge + 1, Anim_BackFlip + 1, Anim_Flicker + 1
	.4byte Anim_BackFlipBig + 1, Anim_FrontFlip + 1, Anim_TumblingFrontFlip + 1, Anim_Figure8 + 1, Anim_FlashYellow + 1, Anim_SwingConcave_FastShort + 1, Anim_SwingConvex_FastShort + 1, Anim_RotateUpSlamDown + 1
	.4byte Anim_DeepVerticalSquishBounce + 1, Anim_HorizontalJumps + 1, Anim_HorizontalJumpsVerticalStretch + 1, Anim_RotateToSides_Fast + 1, Anim_RotateUpToSides + 1, Anim_FlickerIncreasing + 1, Anim_TipHopForward + 1, Anim_PivotShake + 1
	.4byte Anim_TipAndShake + 1, Anim_VibrateToCorners + 1, Anim_GrowInStages + 1, Anim_VerticalSpring + 1, Anim_VerticalRepeatedSpring + 1, Anim_SpringRising + 1, Anim_HorizontalSpring + 1, Anim_HorizontalRepeatedSpring_Slow + 1
	.4byte Anim_HorizontalSlideShrink + 1, Anim_LungeGrow + 1, Anim_CircleIntoBackground + 1, Anim_RapidHorizontalHops + 1, Anim_FourPetal + 1, Anim_VerticalSquishBounce_Slow + 1, Anim_HorizontalSlide_Slow + 1, Anim_VerticalSlide_Slow + 1
	.4byte Anim_BounceRotateToSides_Small + 1, Anim_BounceRotateToSides_Slow + 1, Anim_BounceRotateToSides_SmallSlow + 1, Anim_ZigzagSlow + 1, Anim_HorizontalShake_Slow + 1, Anim_VertialShake_Slow + 1, Anim_Twist_Twice + 1, Anim_CircleCounterclockwise_Slow + 1
	.4byte Anim_VerticalShakeTwice_Slow + 1, Anim_VerticalSlideWobble_Small + 1, Anim_VerticalJumps_Small + 1, Anim_Spin + 1, Anim_TumblingFrontFlip_Twice + 1, Anim_DeepVerticalSquishBounce_Twice + 1, Anim_HorizontalJumpsVerticalStretch_Twice + 1, Anim_VerticalShakeBack + 1
	.4byte Anim_VerticalShakeBack_Slow + 1, Anim_VerticalShakeHorizontalSlide_Slow + 1, Anim_VerticalStretchBothEnds_Slow + 1, Anim_HorizontalStretchFar_Slow + 1, Anim_VerticalShakeLowTwice + 1, Anim_HorizontalShake_Fast + 1, Anim_HorizontalSlide_Fast + 1, Anim_HorizontalVibrate_Fast + 1
	.4byte Anim_HorizontalVibrate_Fastest + 1, Anim_VerticalShakeBack_Fast + 1, Anim_VerticalShakeLowTwice_Slow + 1, Anim_VerticalShakeLowTwice_Fast + 1, Anim_CircleCounterclockwise_Long + 1, Anim_GrowStutter_Slow + 1, Anim_VerticalShakeHorizontalSlide + 1, Anim_VerticalShakeHorizontalSlide_Fast + 1
	.4byte Anim_TriangleDown_Slow + 1, Anim_TriangleDown + 1, Anim_TriangleDown_Fast + 1, Anim_Grow + 1, Anim_Grow_Twice + 1, Anim_HorizontalSpring_Fast + 1, Anim_HorizontalSpring_Slow + 1, Anim_HorizontalRepeatedSpring_Fast + 1
	.4byte Anim_HorizontalRepeatedSpring + 1, Anim_ShrinkGrow_Fast + 1, Anim_ShrinkGrow_Slow + 1, Anim_VerticalStretchBothEnds + 1, Anim_VerticalStretchBothEnds_Twice + 1, Anim_HorizontalStretchFar_Twice + 1, Anim_HorizontalStretchFar + 1, Anim_GrowStutter_Twice + 1
	.4byte Anim_GrowStutter + 1, Anim_ConcaveArcLarge_Slow + 1, Anim_ConcaveArcLarge + 1, Anim_ConcaveArcLarge_Twice + 1, Anim_ConvexDoubleArc_Slow + 1, Anim_ConvexDoubleArc + 1, Anim_ConvexDoubleArc_Twice + 1, Anim_ConcaveArcSmall_Slow + 1
	.4byte Anim_ConcaveArcSmall + 1, Anim_ConcaveArcSmall_Twice + 1, Anim_HorizontalDip + 1, Anim_HorizontalDip_Fast + 1, Anim_HorizontalDip_Twice + 1, Anim_ShrinkGrowVibrate_Fast + 1, Anim_ShrinkGrowVibrate + 1, Anim_ShrinkGrowVibrate_Slow + 1
	.4byte Anim_JoltRight_Fast + 1, Anim_JoltRight + 1, Anim_JoltRight_Slow + 1, Anim_ShakeFlashYellow_Fast + 1, Anim_ShakeFlashYellow + 1, Anim_ShakeFlashYellow_Slow + 1, Anim_ShakeGlowRed_Fast + 1, Anim_ShakeGlowRed + 1
	.4byte Anim_ShakeGlowRed_Slow + 1, Anim_ShakeGlowGreen_Fast + 1, Anim_ShakeGlowGreen + 1, Anim_ShakeGlowGreen_Slow + 1, Anim_ShakeGlowBlue_Fast + 1, Anim_ShakeGlowBlue + 1, Anim_ShakeGlowBlue_Slow + 1

	.globl gUnknown_85D3744
gUnknown_85D3744: @ 0x85D3744
	.incbin "baserom_jp.gba", 0x5d3744, 0x4b

	.globl gUnknown_85D378F
gUnknown_85D378F: @ 0x85D378F
	.incbin "baserom_jp.gba", 0x5d378f, 0x39

	.globl gUnknown_85D37C8
gUnknown_85D37C8: @ 0x85D37C8
	.incbin "baserom_jp.gba", 0x5d37c8, 0x8

	.globl gUnknown_85D37D0
gUnknown_85D37D0: @ 0x85D37D0
	.incbin "baserom_jp.gba", 0x5d37d0, 0x1e

	.globl gUnknown_85D37EE
gUnknown_85D37EE: @ 0x85D37EE
	.incbin "baserom_jp.gba", 0x5d37ee, 0x30

	.globl gUnknown_85D381E
gUnknown_85D381E: @ 0x85D381E
	.incbin "baserom_jp.gba", 0x5d381e, 0xbe

	.globl gUnknown_85D38DC
gUnknown_85D38DC: @ 0x85D38DC
	.incbin "baserom_jp.gba", 0x5d38dc, 0xc

	.globl gUnknown_85D38E8
gUnknown_85D38E8: @ 0x85D38E8
	.incbin "baserom_jp.gba", 0x5d38e8, 0x8

	.globl gUnknown_85D38F0
gUnknown_85D38F0: @ 0x85D38F0
	.incbin "baserom_jp.gba", 0x5d38f0, 0xe4

	.globl gUnknown_85D39D4
gUnknown_85D39D4: @ 0x85D39D4
	.incbin "baserom_jp.gba", 0x5d39d4, 0xe4

	.globl sDummyPicData
sDummyPicData: @ 0x85D3AB8
	.incbin "graphics/misc/sDummyPicData.bin"

	.globl sOamData_Normal
sOamData_Normal: @ 0x85D3AC4
	.byte 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00

	.globl sOamData_Affine
sOamData_Affine: @ 0x85D3ACC
	.byte 0x00, 0x01, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00

	.globl gUnknown_85D3AD4
gUnknown_85D3AD4: @ 0x85D3AD4
	.incbin "baserom_jp.gba", 0x5d3ad4, 0xa

	.globl gUnknown_85D3ADE
gUnknown_85D3ADE: @ 0x85D3ADE
	.incbin "baserom_jp.gba", 0x5d3ade, 0x126

	.globl gUnknown_85D3C04
gUnknown_85D3C04: @ 0x85D3C04
	.incbin "baserom_jp.gba", 0x5d3c04, 0x40

	.globl gUnknown_85D3C44
gUnknown_85D3C44: @ 0x85D3C44
	.incbin "baserom_jp.gba", 0x5d3c44, 0x20

	.globl gUnknown_85D3C64
gUnknown_85D3C64: @ 0x85D3C64
	.incbin "baserom_jp.gba", 0x5d3c64, 0x40

	.globl gUnknown_85D3CA4
gUnknown_85D3CA4: @ 0x85D3CA4
	.incbin "baserom_jp.gba", 0x5d3ca4, 0xc8

	.globl gUnknown_85D3D6C
gUnknown_85D3D6C: @ 0x85D3D6C
	.incbin "baserom_jp.gba", 0x5d3d6c, 0x18

	.globl gUnknown_85D3D84
gUnknown_85D3D84: @ 0x85D3D84
	.incbin "baserom_jp.gba", 0x5d3d84, 0xc

	.globl gUnknown_85D3D90
gUnknown_85D3D90: @ 0x85D3D90
	.string "おねえ$ハンサム$ジョバンニ$もあもあ$てつ$きんにくん$　　　"

	.globl gUnknown_85D3DB0
gUnknown_85D3DB0: @ 0x85D3DB0
	.incbin "baserom_jp.gba", 0x5d3db0, 0x2c

	.globl gUnknown_85D3DDC
gUnknown_85D3DDC: @ 0x85D3DDC
	.incbin "baserom_jp.gba", 0x5d3ddc, 0x14

	.globl gUnknown_85D3DF0
gUnknown_85D3DF0: @ 0x85D3DF0
	.incbin "baserom_jp.gba", 0x5d3df0, 0xc

	.globl gUnknown_85D3DFC
gUnknown_85D3DFC: @ 0x85D3DFC
	.incbin "baserom_jp.gba", 0x5d3dfc, 0x1630

	.globl gUnknown_85D542C
gUnknown_85D542C: @ 0x85D542C
	.incbin "baserom_jp.gba", 0x5d542c, 0x269

	.globl gUnknown_85D5695
gUnknown_85D5695: @ 0x85D5695
	.incbin "baserom_jp.gba", 0x5d5695, 0x283

	.globl gUnknown_85D5918
gUnknown_85D5918: @ 0x85D5918
	.incbin "baserom_jp.gba", 0x5d5918, 0x10

	.globl gUnknown_85D5928
gUnknown_85D5928: @ 0x85D5928
	.incbin "baserom_jp.gba", 0x5d5928, 0x10

	.globl gUnknown_85D5938
gUnknown_85D5938: @ 0x85D5938
	.incbin "baserom_jp.gba", 0x5d5938, 0x20

	.globl gUnknown_85D5958
gUnknown_85D5958: @ 0x85D5958
	.incbin "baserom_jp.gba", 0x5d5958, 0x98

	.globl gUnknown_85D59F0
gUnknown_85D59F0: @ 0x85D59F0
	.incbin "baserom_jp.gba", 0x5d59f0, 0xc

	.globl gUnknown_85D59FC
gUnknown_85D59FC: @ 0x85D59FC
	.incbin "baserom_jp.gba", 0x5d59fc, 0x58

	.globl gUnknown_85D5A54
gUnknown_85D5A54: @ 0x85D5A54
	.incbin "baserom_jp.gba", 0x5d5a54, 0x30

	.globl gUnknown_85D5A84
gUnknown_85D5A84: @ 0x85D5A84
	.incbin "baserom_jp.gba", 0x5d5a84, 0x48

	.globl gUnknown_85D5ACC
gUnknown_85D5ACC: @ 0x85D5ACC
	.incbin "baserom_jp.gba", 0x5d5acc, 0x18

	.globl gUnknown_85D5AE4
gUnknown_85D5AE4: @ 0x85D5AE4
	.incbin "baserom_jp.gba", 0x5d5ae4, 0x18

	.globl sTourneyTreeTrainerIds
sTourneyTreeTrainerIds: @ 0x85D5AFC
	.incbin "baserom_jp.gba", 0x5d5afc, 0x10

	.globl gUnknown_85D5B0C
gUnknown_85D5B0C: @ 0x85D5B0C
	.incbin "baserom_jp.gba", 0x5d5b0c, 0x5c

	.globl gUnknown_85D5B68
gUnknown_85D5B68: @ 0x85D5B68
	.incbin "baserom_jp.gba", 0x5d5b68, 0x10

	.globl gUnknown_85D5B78
gUnknown_85D5B78: @ 0x85D5B78
	.incbin "baserom_jp.gba", 0x5d5b78, 0x10
	.globl gUnknown_85D5B88
gUnknown_85D5B88: @ 0x85D5B88
	.incbin "baserom_jp.gba", 0x5d5b88, 0x40

	.globl sTourneyTreeTrainerOpponentIds
sTourneyTreeTrainerOpponentIds: @ 0x85D5BC8
	.incbin "baserom_jp.gba", 0x5d5bc8, 0x10

	.globl gUnknown_85D5BD8
gUnknown_85D5BD8: @ 0x85D5BD8
	.incbin "baserom_jp.gba", 0x5d5bd8, 0x40

	.globl gUnknown_85D5C18
gUnknown_85D5C18: @ 0x85D5C18
	.incbin "baserom_jp.gba", 0x5d5c18, 0x4

	.globl gUnknown_85D5C1C
gUnknown_85D5C1C: @ 0x85D5C1C
	.incbin "baserom_jp.gba", 0x5d5c1c, 0x20

	.globl sTournamentIdToPairedTrainerIds
sTournamentIdToPairedTrainerIds: @ 0x85D5C3C
	.incbin "baserom_jp.gba", 0x5d5c3c, 0x10

	.globl gUnknown_85D5C4C
gUnknown_85D5C4C: @ 0x85D5C4C
	.incbin "baserom_jp.gba", 0x5d5c4c, 0x44

	.globl gUnknown_85D5C90
gUnknown_85D5C90: @ 0x85D5C90
	.incbin "baserom_jp.gba", 0x5d5c90, 0x80

	.globl gUnknown_85D5D10
gUnknown_85D5D10: @ 0x85D5D10
	.incbin "baserom_jp.gba", 0x5d5d10, 0xac

	.globl gUnknown_85D5DBC
gUnknown_85D5DBC: @ 0x85D5DBC
	.incbin "baserom_jp.gba", 0x5d5dbc, 0x3

	.globl gUnknown_85D5DBF
gUnknown_85D5DBF: @ 0x85D5DBF
	.incbin "baserom_jp.gba", 0x5d5dbf, 0x3

	.globl gUnknown_85D5DC2
gUnknown_85D5DC2: @ 0x85D5DC2
	.incbin "baserom_jp.gba", 0x5d5dc2, 0x3

	.globl gUnknown_85D5DC5
gUnknown_85D5DC5: @ 0x85D5DC5
	.incbin "baserom_jp.gba", 0x5d5dc5, 0x7

	.globl gUnknown_85D5DCC
gUnknown_85D5DCC: @ 0x85D5DCC
	.incbin "baserom_jp.gba", 0x5d5dcc, 0x3c

	.globl gUnknown_85D5E08
gUnknown_85D5E08: @ 0x85D5E08
	.incbin "baserom_jp.gba", 0x5d5e08, 0x1c

	.globl gUnknown_85D5E24
gUnknown_85D5E24: @ 0x85D5E24
	.incbin "baserom_jp.gba", 0x5d5e24, 0x3

	.globl gUnknown_85D5E27
gUnknown_85D5E27: @ 0x85D5E27
	.incbin "baserom_jp.gba", 0x5d5e27, 0x3

	.globl gUnknown_85D5E2A
gUnknown_85D5E2A: @ 0x85D5E2A
	.incbin "baserom_jp.gba", 0x5d5e2a, 0x3

	.globl gUnknown_85D5E2D
gUnknown_85D5E2D: @ 0x85D5E2D
	.incbin "baserom_jp.gba", 0x5d5e2d, 0x3

	.globl sTourneyTreeTrainerIds2
sTourneyTreeTrainerIds2: @ 0x85D5E30
	.incbin "baserom_jp.gba", 0x5d5e30, 0x10

	.globl gUnknown_85D5E40
gUnknown_85D5E40: @ 0x85D5E40
	.incbin "baserom_jp.gba", 0x5d5e40, 0x2

	.globl gUnknown_85D5E42
gUnknown_85D5E42: @ 0x85D5E42
	.incbin "baserom_jp.gba", 0x5d5e42, 0x2b

	.globl gUnknown_85D5E6D
gUnknown_85D5E6D: @ 0x85D5E6D
	.incbin "baserom_jp.gba", 0x5d5e6d, 0x1

	.globl gUnknown_85D5E6E
gUnknown_85D5E6E: @ 0x85D5E6E
	.incbin "baserom_jp.gba", 0x5d5e6e, 0x1f

	.globl gUnknown_85D5E8D
gUnknown_85D5E8D: @ 0x85D5E8D
	.incbin "baserom_jp.gba", 0x5d5e8d, 0x8ff

	.globl gUnknown_85D678C
gUnknown_85D678C: @ 0x85D678C
	.incbin "baserom_jp.gba", 0x5d678c, 0x100

	.globl gUnknown_85D688C
gUnknown_85D688C: @ 0x85D688C
	.incbin "baserom_jp.gba", 0x5d688c, 0x40

	.globl sBattlePalaceFunctions
sBattlePalaceFunctions: @ 0x85D68CC
	.incbin "graphics/battle_palace/sBattlePalaceFunctions.bin"

	.globl sBattlePalaceEarlyPrizes
sBattlePalaceEarlyPrizes: @ 0x85D68F4
	.hword 0x003F, 0x0040, 0x0041, 0x0043, 0x0042, 0x0046

	.globl sBattlePalaceLatePrizes
sBattlePalaceLatePrizes: @ 0x85D6900
	.hword 0x00B3, 0x00B4, 0x00B7, 0x00C8, 0x00B9, 0x00BB, 0x00C4, 0x00C6, 0x00BA, 0x0000

	.globl sWinStreakFlags
sWinStreakFlags: @ 0x85D6914
	.4byte 0x00000010, 0x00000020, 0x00400000, 0x00800000

	.globl sWinStreakMasks
sWinStreakMasks: @ 0x85D6924
	.4byte 0xFFFFFFEF, 0xFFFFFFDF, 0xFFBFFFFF, 0xFF7FFFFF

	.globl gUnknown_85D6934
gUnknown_85D6934: @ 0x85D6934
	.incbin "baserom_jp.gba", 0x5d6934, 0xb68

	.globl sMatchCallBattleTopics
sMatchCallBattleTopics: @ 0x85D749C
	.4byte 0x085D6E34 @ sMatchCallWildBattleTexts
	.4byte 0x085D6EAC @ sMatchCallNegativeBattleTexts
	.4byte 0x085D6F1C @ sMatchCallPositiveBattleTexts

	.globl sMatchCallBattleRequestTopics
sMatchCallBattleRequestTopics: @ 0x85D74A8
	.4byte 0x085D6F8C @ sMatchCallSameRouteBattleRequestTexts
	.4byte 0x085D6FFC @ sMatchCallDifferentRouteBattleRequestTexts

	.globl sMatchCallGeneralTopics
sMatchCallGeneralTopics: @ 0x85D74B0
	.4byte 0x085D706C @ sMatchCallPersonalizedTexts
	.4byte 0x085D726C @ sMatchCallBattleFrontierStreakTexts
	.4byte 0x085D72DC @ sMatchCallBattleFrontierRecordStreakTexts
	.4byte 0x085D734C @ sMatchCallBattleDomeTexts
	.4byte 0x085D73BC @ sMatchCallBattlePikeTexts
	.4byte 0x085D742C @ sMatchCallBattlePyramidTexts

	.globl sMatchCallWindow_Pal
sMatchCallWindow_Pal: @ 0x85D74C8
	.hword 0x0000 @ color 0
	.hword 0x7FFF @ color 1
	.hword 0x0000 @ color 2
	.hword 0x6718 @ color 3
	.hword 0x4B64 @ color 4
	.hword 0x5BAD @ color 5
	.hword 0x6BF6 @ color 6
	.hword 0x7F1A @ color 7
	.hword 0x7F9D @ color 8
	.hword 0x5AFF @ color 9
	.hword 0x6B7F @ color 10
	.hword 0x0257 @ color 11
	.hword 0x73BD @ color 12
	.hword 0x0000 @ color 13
	.hword 0x0000 @ color 14
	.hword 0x0000 @ color 15

	.globl gUnknown_85D74E8
gUnknown_85D74E8: @ 0x85D74E8
	.incbin "baserom_jp.gba", 0x5d74e8, 0x100

	.globl sPokenavIcon_Pal
sPokenavIcon_Pal: @ 0x85D75E8
	.hword 0x7FFF @ color 0
	.hword 0x1595 @ color 1
	.hword 0x4A55 @ color 2
	.hword 0x56B6 @ color 3
	.hword 0x001F @ color 4
	.hword 0x31FE @ color 5
	.hword 0x6694 @ color 6
	.hword 0x798C @ color 7
	.hword 0x7FFF @ color 8
	.hword 0x7EC1 @ color 9
	.hword 0x0000 @ color 10
	.hword 0x0000 @ color 11
	.hword 0x0000 @ color 12
	.hword 0x3B1F @ color 13
	.hword 0x6B39 @ color 14
	.hword 0x5EB5 @ color 15

	.globl gUnknown_85D7608
gUnknown_85D7608: @ 0x85D7608
	.incbin "baserom_jp.gba", 0x5d7608, 0x3e4

	.globl gUnknown_85D79EC
gUnknown_85D79EC: @ 0x85D79EC
	.string "⋯⋯⋯⋯⋯⋯\p$"

	.globl sMatchCallTaskFuncs
sMatchCallTaskFuncs: @ 0x85D79F4
	.4byte MatchCall_LoadGfx @ 0x08195D2D
	.4byte MatchCall_DrawWindow @ 0x08195DF1
	.4byte MatchCall_ReadyIntro @ 0x08195E75
	.4byte MatchCall_SlideWindowIn @ 0x08195EB1
	.4byte MatchCall_PrintIntro @ 0x08195ED9
	.4byte MatchCall_PrintMessage @ 0x08195F31
	.4byte MatchCall_SlideWindowOut @ 0x08195F91
	.4byte MatchCall_EndCall @ 0x08195FF1

	.globl sMatchCallTextWindow
sMatchCallTextWindow: @ 0x85D7A14
	.byte 0 @ bg
	.byte 1 @ tilemapLeft
	.byte 15 @ tilemapTop
	.byte 28 @ width
	.byte 4 @ height
	.byte 15 @ paletteNum
	.hword 0x0200 @ baseBlock

	.globl sMatchCallTextStringVars
sMatchCallTextStringVars: @ 0x85D7A1C
	.4byte gStringVar1
	.4byte gStringVar2
	.4byte gStringVar3

	.globl gUnknown_85D7A28
gUnknown_85D7A28: @ 0x85D7A28
	.string "どニのくベニのくドヌのくヘネのくuネのくけノのくナツ$クミ$ゲン$コウ$マリ$ミホ$　　"

	.globl sMultiTrainerMatchCallTexts
sMultiTrainerMatchCallTexts: @ 0x85D7A54
	.hword 0x0282 @ trainerId (US TRAINER_KIRA_AND_DAN_1)
	.hword 0
	.4byte 0x085D7A40 @ text (gText_* not yet symbolized)
	.hword 0x01E1 @ trainerId (US TRAINER_AMY_AND_LIV_1)
	.hword 0
	.4byte 0x085D7A43 @ text (gText_* not yet symbolized)
	.hword 0x02A9 @ trainerId (US TRAINER_JOHN_AND_JAY_1)
	.hword 0
	.4byte 0x085D7A46 @ text (gText_* not yet symbolized)
	.hword 0x02AF @ trainerId (US TRAINER_LILA_AND_ROY_1)
	.hword 0
	.4byte 0x085D7A49 @ text (gText_* not yet symbolized)
	.hword 0x0033 @ trainerId (US TRAINER_GABBY_AND_TY_1)
	.hword 0
	.4byte 0x085D7A4C @ text (gText_* not yet symbolized)
	.hword 0x011F @ trainerId (US TRAINER_ANNA_AND_MEG_1)
	.hword 0
	.4byte 0x085D7A4F @ text (gText_* not yet symbolized)

	.globl sBattleFrontierFacilityNames
sBattleFrontierFacilityNames: @ 0x85D7A84
	.4byte 0x085CC423 @ FRONTIER_FACILITY_TOWER (US gText_*)
	.4byte 0x085CC42A @ FRONTIER_FACILITY_DOME (US gText_*)
	.4byte 0x085CC431 @ FRONTIER_FACILITY_PALACE (US gText_*)
	.4byte 0x085CC442 @ FRONTIER_FACILITY_ARENA (US gText_*)
	.4byte 0x085CC44A @ MATCH_CALL_PIKE (US gText_*)
	.4byte 0x085CC438 @ MATCH_CALL_FACTORY (US gText_*)
	.4byte 0x085CC452 @ FRONTIER_FACILITY_PYRAMID (US gText_*)

	.globl sBadgeFlags
sBadgeFlags: @ 0x85D7AA0
	.hword 0x867 @ FLAG_BADGE01_GET
	.hword 0x868 @ FLAG_BADGE02_GET
	.hword 0x869 @ FLAG_BADGE03_GET
	.hword 0x86A @ FLAG_BADGE04_GET
	.hword 0x86B @ FLAG_BADGE05_GET
	.hword 0x86C @ FLAG_BADGE06_GET
	.hword 0x86D @ FLAG_BADGE07_GET
	.hword 0x86E @ FLAG_BADGE08_GET

	.globl sBirchDexRatingTexts
sBirchDexRatingTexts: @ 0x85D7AB0
	.4byte gBirchDexRatingText_LessThan10
	.4byte gBirchDexRatingText_LessThan20
	.4byte gBirchDexRatingText_LessThan30
	.4byte gBirchDexRatingText_LessThan40
	.4byte gBirchDexRatingText_LessThan50
	.4byte gBirchDexRatingText_LessThan60
	.4byte gBirchDexRatingText_LessThan70
	.4byte gBirchDexRatingText_LessThan80
	.4byte gBirchDexRatingText_LessThan90
	.4byte gBirchDexRatingText_LessThan100
	.4byte gBirchDexRatingText_LessThan110
	.4byte gBirchDexRatingText_LessThan120
	.4byte gBirchDexRatingText_LessThan130
	.4byte gBirchDexRatingText_LessThan140
	.4byte gBirchDexRatingText_LessThan150
	.4byte gBirchDexRatingText_LessThan160
	.4byte gBirchDexRatingText_LessThan170
	.4byte gBirchDexRatingText_LessThan180
	.4byte gBirchDexRatingText_LessThan190
	.4byte gBirchDexRatingText_LessThan200
	.4byte gBirchDexRatingText_DexCompleted

	.globl gStandardMenuPalette
gStandardMenuPalette: @ 0x85D7B04
	.incbin "graphics/misc/gStandardMenuPalette.bin"

	.globl gUnknown_85D7B24
gUnknown_85D7B24: @ 0x85D7B24
	.incbin "baserom_jp.gba", 0x5d7b24, 0x4

	.globl gUnknown_85D7B28
gUnknown_85D7B28: @ 0x85D7B28
	.incbin "baserom_jp.gba", 0x5d7b28, 0x10

	.globl gUnknown_85D7B38
gUnknown_85D7B38: @ 0x85D7B38
	.incbin "baserom_jp.gba", 0x5d7b38, 0x8

	.globl gUnknown_85D7B40
gUnknown_85D7B40: @ 0x85D7B40
	.incbin "baserom_jp.gba", 0x5d7b40, 0x8

	.globl gUnknown_85D7B48
gUnknown_85D7B48: @ 0x85D7B48
	.incbin "baserom_jp.gba", 0x5d7b48, 0x20

	.globl gUnknown_85D7B68
gUnknown_85D7B68: @ 0x85D7B68
	.incbin "baserom_jp.gba", 0x5d7b68, 0x4

	.globl gUnknown_85D7B6C
gUnknown_85D7B6C: @ 0x85D7B6C
	.incbin "baserom_jp.gba", 0x5d7b6c, 0x4

	.globl gUnknown_85D7B70
gUnknown_85D7B70: @ 0x85D7B70
	.incbin "baserom_jp.gba", 0x5d7b70, 0x68

	.globl gUnknown_85D7BD8
gUnknown_85D7BD8: @ 0x85D7BD8
	.incbin "baserom_jp.gba", 0x5d7bd8, 0x20

	.globl gUnknown_85D7BF8
gUnknown_85D7BF8: @ 0x85D7BF8
	.incbin "baserom_jp.gba", 0x5d7bf8, 0x20

	.globl gUnknown_85D7C18
gUnknown_85D7C18: @ 0x85D7C18
	.incbin "baserom_jp.gba", 0x5d7c18, 0x20

	.globl gUnknown_85D7C38
gUnknown_85D7C38: @ 0x85D7C38
	.incbin "baserom_jp.gba", 0x5d7c38, 0x2000

	.globl gUnknown_85D9C38
gUnknown_85D9C38: @ 0x85D9C38
	.incbin "baserom_jp.gba", 0x5d9c38, 0x1100

	.globl gUnknown_85DAD38
gUnknown_85DAD38: @ 0x85DAD38
	.incbin "baserom_jp.gba", 0x5dad38, 0x440

	.globl gUnknown_85DB178
gUnknown_85DB178: @ 0x85DB178
	.incbin "baserom_jp.gba", 0x5db178, 0x800

	.globl gUnknown_85DB978
gUnknown_85DB978: @ 0x85DB978
	.incbin "baserom_jp.gba", 0x5db978, 0x100

	.globl gUnknown_85DBA78
gUnknown_85DBA78: @ 0x85DBA78
	.incbin "baserom_jp.gba", 0x5dba78, 0x60

	.globl gUnknown_85DBAD8
gUnknown_85DBAD8: @ 0x85DBAD8
	.incbin "baserom_jp.gba", 0x5dbad8, 0x40

	.globl gUnknown_85DBB18
gUnknown_85DBB18: @ 0x85DBB18
	.incbin "baserom_jp.gba", 0x5dbb18, 0x20

	.globl gUnknown_85DBB38
gUnknown_85DBB38: @ 0x85DBB38
	.incbin "baserom_jp.gba", 0x5dbb38, 0x28

	.globl gUnknown_85DBB60
gUnknown_85DBB60: @ 0x85DBB60
	.incbin "baserom_jp.gba", 0x5dbb60, 0x10

	.globl gUnknown_85DBB70
gUnknown_85DBB70: @ 0x85DBB70
	.incbin "baserom_jp.gba", 0x5dbb70, 0x28

	.globl gUnknown_85DBB98
