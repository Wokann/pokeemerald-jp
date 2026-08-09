
	.section script_data, "aw", %progbits
	.include "asm/macros.inc"
	.set ALLOCATE_SCRIPT_CMD_TABLE, 1
	.align 2
	.globl gUnknown_81DABAC
gUnknown_81DABAC:
	.include "data/script_cmd_table.inc"

	.globl gUnknown_81DAF34
gUnknown_81DAF34: @ 0x81DAF34
	.incbin "build/data/event_scripts.bin", 0x388, 0x58

	.set ALLOCATE_SPECIAL_TABLE, 1
	.align 2
	.globl gUnknown_81DAF8C
gUnknown_81DAF8C:
	.include "data/specials.inc"

	.globl gUnknown_81DB7BC
gUnknown_81DB7BC: @ 0x81DB7BC
	.incbin "build/data/event_scripts.bin", 0xc10, 0x2c

	.globl gUnknown_81DB7E8
gUnknown_81DB7E8: @ 0x81DB7E8
	.incbin "build/data/event_scripts.bin", 0xc3c, 0x260b

	.globl gUnknown_81DDDF3
gUnknown_81DDDF3: @ 0x81DDDF3
	.incbin "build/data/event_scripts.bin", 0x3247, 0x4a04

	.globl gUnknown_81E27F7
gUnknown_81E27F7: @ 0x81E27F7
	.incbin "build/data/event_scripts.bin", 0x7c4b, 0xaab6

	.globl gUnknown_81ED2AD
gUnknown_81ED2AD: @ 0x81ED2AD
	.incbin "build/data/event_scripts.bin", 0x12701, 0x2f0f

	.globl gUnknown_81F01BC
gUnknown_81F01BC: @ 0x81F01BC
	.incbin "build/data/event_scripts.bin", 0x15610, 0x32

	.globl gUnknown_81F01EE
gUnknown_81F01EE: @ 0x81F01EE
	.incbin "build/data/event_scripts.bin", 0x15642, 0xbb1

	.globl gUnknown_81F0D9F
gUnknown_81F0D9F: @ 0x81F0D9F
	.incbin "build/data/event_scripts.bin", 0x161f3, 0x3c

	.globl gUnknown_81F0DDB
gUnknown_81F0DDB: @ 0x81F0DDB
	.incbin "build/data/event_scripts.bin", 0x1622f, 0xc96

	.globl gUnknown_81F1A71
gUnknown_81F1A71: @ 0x81F1A71
	.incbin "build/data/event_scripts.bin", 0x16ec5, 0x1099f

	.globl gUnknown_8202410
gUnknown_8202410: @ 0x8202410
	.incbin "build/data/event_scripts.bin", 0x27864, 0xb672

	.globl gUnknown_820DA82
gUnknown_820DA82: @ 0x820DA82
	.incbin "build/data/event_scripts.bin", 0x32ed6, 0xf

	.globl gUnknown_820DA91
gUnknown_820DA91: @ 0x820DA91
	.incbin "build/data/event_scripts.bin", 0x32ee5, 0xe

	.globl gUnknown_820DA9F
gUnknown_820DA9F: @ 0x820DA9F
	.incbin "build/data/event_scripts.bin", 0x32ef3, 0xdd55

	.globl gUnknown_821B7F4
gUnknown_821B7F4: @ 0x821B7F4
	.incbin "build/data/event_scripts.bin", 0x40c48, 0x54a

	.globl gUnknown_821BD3E
gUnknown_821BD3E: @ 0x821BD3E
	.incbin "build/data/event_scripts.bin", 0x41192, 0x166c

	.globl gUnknown_821D3AA
gUnknown_821D3AA: @ 0x821D3AA
	.incbin "build/data/event_scripts.bin", 0x427fe, 0x2d

	.globl gUnknown_821D3D7
gUnknown_821D3D7: @ 0x821D3D7
	.incbin "build/data/event_scripts.bin", 0x4282b, 0xa1

	.globl gUnknown_821D478
gUnknown_821D478: @ 0x821D478
	.incbin "build/data/event_scripts.bin", 0x428cc, 0x60

	.globl gUnknown_821D4D8
gUnknown_821D4D8: @ 0x821D4D8
	.incbin "build/data/event_scripts.bin", 0x4292c, 0x9b

	.globl gUnknown_821D573
gUnknown_821D573: @ 0x821D573
	.incbin "build/data/event_scripts.bin", 0x429c7, 0x8

	.globl gUnknown_821D57B
gUnknown_821D57B: @ 0x821D57B
	.incbin "build/data/event_scripts.bin", 0x429cf, 0x94c

	.globl gUnknown_821DEC7
gUnknown_821DEC7: @ 0x821DEC7
	.incbin "build/data/event_scripts.bin", 0x4331b, 0x45b7

	.globl gUnknown_822247E
gUnknown_822247E: @ 0x822247E
	.incbin "build/data/event_scripts.bin", 0x478d2, 0x61b

	.globl gUnknown_8222A99
gUnknown_8222A99: @ 0x8222A99
	.incbin "build/data/event_scripts.bin", 0x47eed, 0x42ba

	.globl gUnknown_8226D53
gUnknown_8226D53: @ 0x8226D53
	.incbin "build/data/event_scripts.bin", 0x4c1a7, 0xe

	.globl gUnknown_8226D61
gUnknown_8226D61: @ 0x8226D61
	.incbin "build/data/event_scripts.bin", 0x4c1b5, 0x6950

	.globl gUnknown_822D6B1
gUnknown_822D6B1: @ 0x822D6B1
	.incbin "build/data/event_scripts.bin", 0x52b05, 0x67

	.globl gUnknown_822D718
gUnknown_822D718: @ 0x822D718
	.incbin "build/data/event_scripts.bin", 0x52b6c, 0x1b

	.globl gUnknown_822D733
gUnknown_822D733: @ 0x822D733
	.incbin "build/data/event_scripts.bin", 0x52b87, 0x1e

	.globl gUnknown_822D751
gUnknown_822D751: @ 0x822D751
	.incbin "build/data/event_scripts.bin", 0x52ba5, 0x11

	.globl gUnknown_822D762
gUnknown_822D762: @ 0x822D762
	.incbin "build/data/event_scripts.bin", 0x52bb6, 0x2d

	.globl gUnknown_822D78F
gUnknown_822D78F: @ 0x822D78F
	.incbin "build/data/event_scripts.bin", 0x52be3, 0xde1a

	.globl gUnknown_823B5A9
gUnknown_823B5A9: @ 0x823B5A9
	.incbin "build/data/event_scripts.bin", 0x609fd, 0x1a52

	.globl gUnknown_823CFFB
gUnknown_823CFFB: @ 0x823CFFB
	.incbin "build/data/event_scripts.bin", 0x6244f, 0x53f3

	.globl gUnknown_82423EE
gUnknown_82423EE: @ 0x82423EE
	.incbin "build/data/event_scripts.bin", 0x67842, 0xe

	.globl gUnknown_82423FC
gUnknown_82423FC: @ 0x82423FC
	.incbin "build/data/event_scripts.bin", 0x67850, 0x28

	.globl gUnknown_8242424
gUnknown_8242424: @ 0x8242424
	.incbin "build/data/event_scripts.bin", 0x67878, 0x38

	.globl gUnknown_824245C
gUnknown_824245C: @ 0x824245C
	.incbin "build/data/event_scripts.bin", 0x678b0, 0xf

	.globl gUnknown_824246B
gUnknown_824246B: @ 0x824246B
	.incbin "build/data/event_scripts.bin", 0x678bf, 0x27

	.globl gUnknown_8242492
gUnknown_8242492: @ 0x8242492
	.incbin "build/data/event_scripts.bin", 0x678e6, 0x1e6

	.globl gUnknown_8242678
gUnknown_8242678: @ 0x8242678
	.incbin "build/data/event_scripts.bin", 0x67acc, 0x279

	.globl gUnknown_82428F1
gUnknown_82428F1: @ 0x82428F1
	.incbin "build/data/event_scripts.bin", 0x67d45, 0xb

	.globl gUnknown_82428FC
gUnknown_82428FC: @ 0x82428FC
	.incbin "build/data/event_scripts.bin", 0x67d50, 0x44d

	.globl gUnknown_8242D49
gUnknown_8242D49: @ 0x8242D49
	.incbin "build/data/event_scripts.bin", 0x6819d, 0xd5

	.globl gUnknown_8242E1E
gUnknown_8242E1E: @ 0x8242E1E
	.incbin "build/data/event_scripts.bin", 0x68272, 0x10e

	.globl gUnknown_8242F2C
gUnknown_8242F2C: @ 0x8242F2C
	.incbin "build/data/event_scripts.bin", 0x68380, 0x1ef

	.globl gUnknown_824311B
gUnknown_824311B: @ 0x824311B
	.incbin "build/data/event_scripts.bin", 0x6856f, 0x536

	.globl gUnknown_8243651
gUnknown_8243651: @ 0x8243651
	.incbin "build/data/event_scripts.bin", 0x68aa5, 0x9

	.globl gUnknown_824365A
gUnknown_824365A: @ 0x824365A
	.incbin "build/data/event_scripts.bin", 0x68aae, 0x9

	.globl gUnknown_8243663
gUnknown_8243663: @ 0x8243663
	.incbin "build/data/event_scripts.bin", 0x68ab7, 0x9

	.globl gUnknown_824366C
gUnknown_824366C: @ 0x824366C
	.incbin "build/data/event_scripts.bin", 0x68ac0, 0x9

	.globl gUnknown_8243675
gUnknown_8243675: @ 0x8243675
	.incbin "build/data/event_scripts.bin", 0x68ac9, 0x9

	.globl gUnknown_824367E
gUnknown_824367E: @ 0x824367E
	.incbin "build/data/event_scripts.bin", 0x68ad2, 0x9

	.globl gUnknown_8243687
gUnknown_8243687: @ 0x8243687
	.incbin "build/data/event_scripts.bin", 0x68adb, 0x46

	.globl gUnknown_82436CD
gUnknown_82436CD: @ 0x82436CD
	.incbin "build/data/event_scripts.bin", 0x68b21, 0xa10

	.globl gUnknown_82440DD
gUnknown_82440DD: @ 0x82440DD
	.incbin "build/data/event_scripts.bin", 0x69531, 0x9

	.globl gUnknown_82440E6
gUnknown_82440E6: @ 0x82440E6
	.incbin "build/data/event_scripts.bin", 0x6953a, 0x15f

	.globl gUnknown_8244245
gUnknown_8244245: @ 0x8244245
	.incbin "build/data/event_scripts.bin", 0x69699, 0x504

	.globl gUnknown_8244749
gUnknown_8244749: @ 0x8244749
	.incbin "build/data/event_scripts.bin", 0x69b9d, 0x5c7

	.globl gUnknown_8244D10
gUnknown_8244D10: @ 0x8244D10
	.incbin "build/data/event_scripts.bin", 0x6a164, 0x13

	.globl gUnknown_8244D23
gUnknown_8244D23: @ 0x8244D23
	.incbin "build/data/event_scripts.bin", 0x6a177, 0x17a

	.globl gUnknown_8244E9D
gUnknown_8244E9D: @ 0x8244E9D
	.incbin "build/data/event_scripts.bin", 0x6a2f1, 0x3b

	.globl gUnknown_8244ED8
gUnknown_8244ED8: @ 0x8244ED8
	.incbin "build/data/event_scripts.bin", 0x6a32c, 0x297

	.globl gUnknown_824516F
gUnknown_824516F: @ 0x824516F
	.incbin "build/data/event_scripts.bin", 0x6a5c3, 0xfe

	.globl gUnknown_824526D
gUnknown_824526D: @ 0x824526D
	.incbin "build/data/event_scripts.bin", 0x6a6c1, 0x107

	.globl gUnknown_8245374
gUnknown_8245374: @ 0x8245374
	.incbin "build/data/event_scripts.bin", 0x6a7c8, 0xe1

	.globl gUnknown_8245455
gUnknown_8245455: @ 0x8245455
	.incbin "build/data/event_scripts.bin", 0x6a8a9, 0xfb

	.globl gUnknown_8245550
gUnknown_8245550: @ 0x8245550
	.incbin "build/data/event_scripts.bin", 0x6a9a4, 0x10c

	.globl gUnknown_824565C
gUnknown_824565C: @ 0x824565C
	.incbin "build/data/event_scripts.bin", 0x6aab0, 0xe2

	.globl gUnknown_824573E
gUnknown_824573E: @ 0x824573E
	.incbin "build/data/event_scripts.bin", 0x6ab92, 0xdb

	.globl gUnknown_8245819
gUnknown_8245819: @ 0x8245819
	.incbin "build/data/event_scripts.bin", 0x6ac6d, 0xdb

	.globl gUnknown_82458F4
gUnknown_82458F4: @ 0x82458F4
	.incbin "build/data/event_scripts.bin", 0x6ad48, 0x112

	.globl gUnknown_8245A06
gUnknown_8245A06: @ 0x8245A06
	.incbin "build/data/event_scripts.bin", 0x6ae5a, 0x9a

	.globl gUnknown_8245AA0
gUnknown_8245AA0: @ 0x8245AA0
	.incbin "build/data/event_scripts.bin", 0x6aef4, 0x95

	.globl gUnknown_8245B35
gUnknown_8245B35: @ 0x8245B35
	.incbin "build/data/event_scripts.bin", 0x6af89, 0x59

	.globl gUnknown_8245B8E
gUnknown_8245B8E: @ 0x8245B8E
	.incbin "build/data/event_scripts.bin", 0x6afe2, 0x59

	.globl gUnknown_8245BE7
gUnknown_8245BE7: @ 0x8245BE7
	.incbin "build/data/event_scripts.bin", 0x6b03b, 0x7f

	.globl gUnknown_8245C66
gUnknown_8245C66: @ 0x8245C66
	.incbin "build/data/event_scripts.bin", 0x6b0ba, 0x155

	.globl gUnknown_8245DBB
gUnknown_8245DBB: @ 0x8245DBB
	.incbin "build/data/event_scripts.bin", 0x6b20f, 0x13

	.globl gUnknown_8245DCE
gUnknown_8245DCE: @ 0x8245DCE
	.incbin "build/data/event_scripts.bin", 0x6b222, 0xf

	.globl gUnknown_8245DDD
gUnknown_8245DDD: @ 0x8245DDD
	.incbin "build/data/event_scripts.bin", 0x6b231, 0x7d8

	.globl gUnknown_82465B5
gUnknown_82465B5: @ 0x82465B5
	.incbin "build/data/event_scripts.bin", 0x6ba09, 0x4

	.globl gUnknown_82465B9
gUnknown_82465B9: @ 0x82465B9
	.incbin "build/data/event_scripts.bin", 0x6ba0d, 0xa8b

	.globl gUnknown_8247044
gUnknown_8247044: @ 0x8247044
	.incbin "build/data/event_scripts.bin", 0x6c498, 0xf

	.globl gUnknown_8247053
gUnknown_8247053: @ 0x8247053
	.incbin "build/data/event_scripts.bin", 0x6c4a7, 0xa

	.globl gUnknown_824705D
gUnknown_824705D: @ 0x824705D
	.incbin "build/data/event_scripts.bin", 0x6c4b1, 0xa

	.globl gUnknown_8247067
gUnknown_8247067: @ 0x8247067
	.incbin "build/data/event_scripts.bin", 0x6c4bb, 0x1b

	.globl gUnknown_8247082
gUnknown_8247082: @ 0x8247082
	.incbin "build/data/event_scripts.bin", 0x6c4d6, 0x1b

	.globl gUnknown_824709D
gUnknown_824709D: @ 0x824709D
	.incbin "build/data/event_scripts.bin", 0x6c4f1, 0x1b

	.globl gUnknown_82470B8
gUnknown_82470B8: @ 0x82470B8
	.incbin "build/data/event_scripts.bin", 0x6c50c, 0x1c

	.globl gUnknown_82470D4
gUnknown_82470D4: @ 0x82470D4
	.incbin "build/data/event_scripts.bin", 0x6c528, 0xa

	.globl gUnknown_82470DE
gUnknown_82470DE: @ 0x82470DE
	.incbin "build/data/event_scripts.bin", 0x6c532, 0x1e

	.globl gUnknown_82470FC
gUnknown_82470FC: @ 0x82470FC
	.incbin "build/data/event_scripts.bin", 0x6c550, 0x15

	.globl gUnknown_8247111
gUnknown_8247111: @ 0x8247111
	.incbin "build/data/event_scripts.bin", 0x6c565, 0x15

	.globl gUnknown_8247126
gUnknown_8247126: @ 0x8247126
	.incbin "build/data/event_scripts.bin", 0x6c57a, 0x15

	.globl gUnknown_824713B
gUnknown_824713B: @ 0x824713B
	.incbin "build/data/event_scripts.bin", 0x6c58f, 0x22

	.globl gUnknown_824715D
gUnknown_824715D: @ 0x824715D
	.incbin "build/data/event_scripts.bin", 0x6c5b1, 0xf

	.globl gUnknown_824716C
gUnknown_824716C: @ 0x824716C
	.incbin "build/data/event_scripts.bin", 0x6c5c0, 0xf

	.globl gUnknown_824717B
gUnknown_824717B: @ 0x824717B
	.incbin "build/data/event_scripts.bin", 0x6c5cf, 0x53

	.globl gUnknown_82471CE
gUnknown_82471CE: @ 0x82471CE
	.incbin "build/data/event_scripts.bin", 0x6c622, 0x1a

	.globl gUnknown_82471E8
gUnknown_82471E8: @ 0x82471E8
	.incbin "build/data/event_scripts.bin", 0x6c63c, 0xa

	.globl gUnknown_82471F2
gUnknown_82471F2: @ 0x82471F2
	.incbin "build/data/event_scripts.bin", 0x6c646, 0x677

	.globl gUnknown_8247869
gUnknown_8247869: @ 0x8247869
	.incbin "build/data/event_scripts.bin", 0x6ccbd, 0x410

	.globl gUnknown_8247C79
gUnknown_8247C79: @ 0x8247C79
	.incbin "build/data/event_scripts.bin", 0x6d0cd, 0x1e

	.globl gUnknown_8247C97
gUnknown_8247C97: @ 0x8247C97
	.incbin "build/data/event_scripts.bin", 0x6d0eb, 0x1e

	.globl gUnknown_8247CB5
gUnknown_8247CB5: @ 0x8247CB5
	.incbin "build/data/event_scripts.bin", 0x6d109, 0x25

	.globl gUnknown_8247CDA
gUnknown_8247CDA: @ 0x8247CDA
	.incbin "build/data/event_scripts.bin", 0x6d12e, 0x363d

	.globl gUnknown_824B317
gUnknown_824B317: @ 0x824B317
	.incbin "build/data/event_scripts.bin", 0x7076b, 0x16

	.globl gUnknown_824B32D
gUnknown_824B32D: @ 0x824B32D
	.incbin "build/data/event_scripts.bin", 0x70781, 0x19

	.globl gUnknown_824B346
gUnknown_824B346: @ 0x824B346
	.incbin "build/data/event_scripts.bin", 0x7079a, 0xe

	.globl gUnknown_824B354
gUnknown_824B354: @ 0x824B354
	.incbin "build/data/event_scripts.bin", 0x707a8, 0x1b

	.globl gUnknown_824B36F
gUnknown_824B36F: @ 0x824B36F
	.incbin "build/data/event_scripts.bin", 0x707c3, 0x960

	.globl gUnknown_824BCCF
gUnknown_824BCCF: @ 0x824BCCF
	.incbin "build/data/event_scripts.bin", 0x71123, 0x23

	.globl gUnknown_824BCF2
gUnknown_824BCF2: @ 0x824BCF2
	.incbin "build/data/event_scripts.bin", 0x71146, 0x26

	.globl gUnknown_824BD18
gUnknown_824BD18: @ 0x824BD18
	.incbin "build/data/event_scripts.bin", 0x7116c, 0x26

	.globl gUnknown_824BD3E
gUnknown_824BD3E: @ 0x824BD3E
	.incbin "build/data/event_scripts.bin", 0x71192, 0x183

	.globl gUnknown_824BEC1
gUnknown_824BEC1: @ 0x824BEC1
	.incbin "build/data/event_scripts.bin", 0x71315, 0xfd

	.globl gUnknown_824BFBE
gUnknown_824BFBE: @ 0x824BFBE
	.incbin "build/data/event_scripts.bin", 0x71412, 0x28

	.globl gUnknown_824BFE6
gUnknown_824BFE6: @ 0x824BFE6
	.incbin "build/data/event_scripts.bin", 0x7143a, 0x22

	.globl gUnknown_824C008
gUnknown_824C008: @ 0x824C008
	.incbin "build/data/event_scripts.bin", 0x7145c, 0x21

	.globl gUnknown_824C029
gUnknown_824C029: @ 0x824C029
	.incbin "build/data/event_scripts.bin", 0x7147d, 0x21

	.globl gUnknown_824C04A
gUnknown_824C04A: @ 0x824C04A
	.incbin "build/data/event_scripts.bin", 0x7149e, 0x47

	.globl gUnknown_824C091
gUnknown_824C091: @ 0x824C091
	.incbin "build/data/event_scripts.bin", 0x714e5, 0x20

	.globl gUnknown_824C0B1
gUnknown_824C0B1: @ 0x824C0B1
	.incbin "build/data/event_scripts.bin", 0x71505, 0x21

	.globl gUnknown_824C0D2
gUnknown_824C0D2: @ 0x824C0D2
	.incbin "build/data/event_scripts.bin", 0x71526, 0x5

	.globl gUnknown_824C0D7
gUnknown_824C0D7: @ 0x824C0D7
	.incbin "build/data/event_scripts.bin", 0x7152b, 0x5

	.globl gUnknown_824C0DC
gUnknown_824C0DC: @ 0x824C0DC
	.incbin "build/data/event_scripts.bin", 0x71530, 0x5

	.globl gUnknown_824C0E1
gUnknown_824C0E1: @ 0x824C0E1
	.incbin "build/data/event_scripts.bin", 0x71535, 0x5

	.globl gUnknown_824C0E6
gUnknown_824C0E6: @ 0x824C0E6
	.incbin "build/data/event_scripts.bin", 0x7153a, 0x5a

	.globl gUnknown_824C140
gUnknown_824C140: @ 0x824C140
	.incbin "build/data/event_scripts.bin", 0x71594, 0xb5

	.globl gUnknown_824C1F5
gUnknown_824C1F5: @ 0x824C1F5
	.incbin "build/data/event_scripts.bin", 0x71649, 0xb

	.globl gUnknown_824C200
gUnknown_824C200: @ 0x824C200
	.incbin "build/data/event_scripts.bin", 0x71654, 0x27b

	.globl gUnknown_824C47B
gUnknown_824C47B: @ 0x824C47B
	.incbin "build/data/event_scripts.bin", 0x718cf, 0xa197

	.globl gUnknown_8256612
gUnknown_8256612: @ 0x8256612
	.incbin "build/data/event_scripts.bin", 0x7ba66, 0xb4

	.globl gUnknown_82566C6
gUnknown_82566C6: @ 0x82566C6
	.incbin "build/data/event_scripts.bin", 0x7bb1a, 0xd1

	.globl gUnknown_8256797
gUnknown_8256797: @ 0x8256797
	.incbin "build/data/event_scripts.bin", 0x7bbeb, 0xc6

	.globl gUnknown_825685D
gUnknown_825685D: @ 0x825685D
	.incbin "build/data/event_scripts.bin", 0x7bcb1, 0x3a

	.globl gUnknown_8256897
gUnknown_8256897: @ 0x8256897
	.incbin "build/data/event_scripts.bin", 0x7bceb, 0x53

	.globl gUnknown_82568EA
gUnknown_82568EA: @ 0x82568EA
	.incbin "build/data/event_scripts.bin", 0x7bd3e, 0x4b

	.globl gUnknown_8256935
gUnknown_8256935: @ 0x8256935
	.incbin "build/data/event_scripts.bin", 0x7bd89, 0xdf

	.globl gUnknown_8256A14
gUnknown_8256A14: @ 0x8256A14
	.incbin "build/data/event_scripts.bin", 0x7be68, 0x1075

	.globl gUnknown_8257A89
gUnknown_8257A89: @ 0x8257A89
	.incbin "build/data/event_scripts.bin", 0x7cedd, 0x459

	.globl gUnknown_8257EE2
gUnknown_8257EE2: @ 0x8257EE2
	.incbin "build/data/event_scripts.bin", 0x7d336, 0x6ed

	.globl gUnknown_82585CF
gUnknown_82585CF: @ 0x82585CF
	.incbin "build/data/event_scripts.bin", 0x7da23, 0xe4d

	.globl gUnknown_825941C
gUnknown_825941C: @ 0x825941C
	.incbin "build/data/event_scripts.bin", 0x7e870, 0x3

	.globl gUnknown_825941F
gUnknown_825941F: @ 0x825941F
	.incbin "build/data/event_scripts.bin", 0x7e873, 0x8f74

	.globl gUnknown_8262393
gUnknown_8262393: @ 0x8262393
	.incbin "build/data/event_scripts.bin", 0x877e7, 0x17

	.globl gUnknown_82623AA
gUnknown_82623AA: @ 0x82623AA
	.incbin "build/data/event_scripts.bin", 0x877fe, 0x23

	.globl gUnknown_82623CD
gUnknown_82623CD: @ 0x82623CD
	.incbin "build/data/event_scripts.bin", 0x87821, 0x1b

	.globl gUnknown_82623E8
gUnknown_82623E8: @ 0x82623E8
	.incbin "build/data/event_scripts.bin", 0x8783c, 0x11

	.globl gUnknown_82623F9
gUnknown_82623F9: @ 0x82623F9
	.incbin "build/data/event_scripts.bin", 0x8784d, 0x11

	.globl gUnknown_826240A
gUnknown_826240A: @ 0x826240A
	.incbin "build/data/event_scripts.bin", 0x8785e, 0x8e9

	.globl gUnknown_8262CF3
gUnknown_8262CF3: @ 0x8262CF3
	.incbin "build/data/event_scripts.bin", 0x88147, 0x25

	.globl gUnknown_8262D18
gUnknown_8262D18: @ 0x8262D18
	.incbin "build/data/event_scripts.bin", 0x8816c, 0xb

	.globl gUnknown_8262D23
gUnknown_8262D23: @ 0x8262D23
	.incbin "build/data/event_scripts.bin", 0x88177, 0x1c

	.globl gUnknown_8262D3F
gUnknown_8262D3F: @ 0x8262D3F
	.incbin "build/data/event_scripts.bin", 0x88193, 0x27

	.globl gUnknown_8262D66
gUnknown_8262D66: @ 0x8262D66
	.incbin "build/data/event_scripts.bin", 0x881ba, 0x6

	.globl gUnknown_8262D6C
gUnknown_8262D6C: @ 0x8262D6C
	.incbin "build/data/event_scripts.bin", 0x881c0, 0x8

	.globl gUnknown_8262D74
gUnknown_8262D74: @ 0x8262D74
	.incbin "build/data/event_scripts.bin", 0x881c8, 0x5

	.globl gUnknown_8262D79
gUnknown_8262D79: @ 0x8262D79
	.incbin "build/data/event_scripts.bin", 0x881cd, 0x1d

	.globl gUnknown_8262D96
gUnknown_8262D96: @ 0x8262D96
	.incbin "build/data/event_scripts.bin", 0x881ea, 0xd

	.globl gUnknown_8262DA3
gUnknown_8262DA3: @ 0x8262DA3
	.incbin "build/data/event_scripts.bin", 0x881f7, 0xd

	.globl gUnknown_8262DB0
gUnknown_8262DB0: @ 0x8262DB0
	.incbin "build/data/event_scripts.bin", 0x88204, 0x25

	.globl gUnknown_8262DD5
gUnknown_8262DD5: @ 0x8262DD5
	.incbin "build/data/event_scripts.bin", 0x88229, 0x20

	.globl gUnknown_8262DF5
gUnknown_8262DF5: @ 0x8262DF5
	.incbin "build/data/event_scripts.bin", 0x88249, 0x44

	.globl gUnknown_8262E39
gUnknown_8262E39: @ 0x8262E39
	.incbin "build/data/event_scripts.bin", 0x8828d, 0x26

	.globl gUnknown_8262E5F
gUnknown_8262E5F: @ 0x8262E5F
	.incbin "build/data/event_scripts.bin", 0x882b3, 0x22

	.globl gUnknown_8262E81
gUnknown_8262E81: @ 0x8262E81
	.incbin "build/data/event_scripts.bin", 0x882d5, 0x25

	.globl gUnknown_8262EA6
gUnknown_8262EA6: @ 0x8262EA6
	.incbin "build/data/event_scripts.bin", 0x882fa, 0x29

	.globl gUnknown_8262ECF
gUnknown_8262ECF: @ 0x8262ECF
	.incbin "build/data/event_scripts.bin", 0x88323, 0x26

	.globl gUnknown_8262EF5
gUnknown_8262EF5: @ 0x8262EF5
	.incbin "build/data/event_scripts.bin", 0x88349, 0x23

	.globl gUnknown_8262F18
gUnknown_8262F18: @ 0x8262F18
	.incbin "build/data/event_scripts.bin", 0x8836c, 0x27

	.globl gUnknown_8262F3F
gUnknown_8262F3F: @ 0x8262F3F
	.incbin "build/data/event_scripts.bin", 0x88393, 0x22

	.globl gUnknown_8262F61
gUnknown_8262F61: @ 0x8262F61
	.incbin "build/data/event_scripts.bin", 0x883b5, 0x29

	.globl gUnknown_8262F8A
gUnknown_8262F8A: @ 0x8262F8A
	.incbin "build/data/event_scripts.bin", 0x883de, 0x23

	.globl gUnknown_8262FAD
gUnknown_8262FAD: @ 0x8262FAD
	.incbin "build/data/event_scripts.bin", 0x88401, 0x34

	.globl gUnknown_8262FE1
gUnknown_8262FE1: @ 0x8262FE1
	.incbin "build/data/event_scripts.bin", 0x88435, 0x2b

	.globl gUnknown_826300C
gUnknown_826300C: @ 0x826300C
	.incbin "build/data/event_scripts.bin", 0x88460, 0x26

	.globl gUnknown_8263032
gUnknown_8263032: @ 0x8263032
	.incbin "build/data/event_scripts.bin", 0x88486, 0x1e

	.globl gUnknown_8263050
gUnknown_8263050: @ 0x8263050
	.incbin "build/data/event_scripts.bin", 0x884a4, 0x22

	.globl gUnknown_8263072
gUnknown_8263072: @ 0x8263072
	.incbin "build/data/event_scripts.bin", 0x884c6, 0x23

	.globl gUnknown_8263095
gUnknown_8263095: @ 0x8263095
	.incbin "build/data/event_scripts.bin", 0x884e9, 0x32

	.globl gUnknown_82630C7
gUnknown_82630C7: @ 0x82630C7
	.incbin "build/data/event_scripts.bin", 0x8851b, 0x29

	.globl gUnknown_82630F0
gUnknown_82630F0: @ 0x82630F0
	.incbin "build/data/event_scripts.bin", 0x88544, 0x1c

	.globl gUnknown_826310C
gUnknown_826310C: @ 0x826310C
	.incbin "build/data/event_scripts.bin", 0x88560, 0x21

	.globl gUnknown_826312D
gUnknown_826312D: @ 0x826312D
	.incbin "build/data/event_scripts.bin", 0x88581, 0x22

	.globl gUnknown_826314F
gUnknown_826314F: @ 0x826314F
	.incbin "build/data/event_scripts.bin", 0x885a3, 0x1b

	.globl gUnknown_826316A
gUnknown_826316A: @ 0x826316A
	.incbin "build/data/event_scripts.bin", 0x885be, 0x11d5

	.globl gUnknown_826433F
gUnknown_826433F: @ 0x826433F
	.incbin "build/data/event_scripts.bin", 0x89793, 0x19

	.globl gUnknown_8264358
gUnknown_8264358: @ 0x8264358
	.incbin "build/data/event_scripts.bin", 0x897ac, 0x12957

	.globl gUnknown_8276CAF
gUnknown_8276CAF: @ 0x8276CAF
	.incbin "build/data/event_scripts.bin", 0x9c103, 0x5d

	.globl gUnknown_8276D0C
gUnknown_8276D0C: @ 0x8276D0C
	.incbin "build/data/event_scripts.bin", 0x9c160, 0x31

	.globl gUnknown_8276D3D
gUnknown_8276D3D: @ 0x8276D3D
	.incbin "build/data/event_scripts.bin", 0x9c191, 0x21b

	.globl gUnknown_8276F58
gUnknown_8276F58: @ 0x8276F58
	.incbin "build/data/event_scripts.bin", 0x9c3ac, 0x1f

	.globl gUnknown_8276F77
gUnknown_8276F77: @ 0x8276F77
	.incbin "build/data/event_scripts.bin", 0x9c3cb, 0x20

	.globl gUnknown_8276F97
gUnknown_8276F97: @ 0x8276F97
	.incbin "build/data/event_scripts.bin", 0x9c3eb, 0x24

	.globl gUnknown_8276FBB
gUnknown_8276FBB: @ 0x8276FBB
	.incbin "build/data/event_scripts.bin", 0x9c40f, 0x18

	.globl gUnknown_8276FD3
gUnknown_8276FD3: @ 0x8276FD3
	.incbin "build/data/event_scripts.bin", 0x9c427, 0x75

	.globl gUnknown_8277048
gUnknown_8277048: @ 0x8277048
	.incbin "build/data/event_scripts.bin", 0x9c49c, 0x29

	.globl gUnknown_8277071
gUnknown_8277071: @ 0x8277071
	.incbin "build/data/event_scripts.bin", 0x9c4c5, 0x24

	.globl gUnknown_8277095
gUnknown_8277095: @ 0x8277095
	.incbin "build/data/event_scripts.bin", 0x9c4e9, 0x6d

	.globl gUnknown_8277102
gUnknown_8277102: @ 0x8277102
	.incbin "build/data/event_scripts.bin", 0x9c556, 0xf2

	.globl gUnknown_82771F4
gUnknown_82771F4: @ 0x82771F4
	.incbin "build/data/event_scripts.bin", 0x9c648, 0xc

	.globl gUnknown_8277200
gUnknown_8277200: @ 0x8277200
	.incbin "build/data/event_scripts.bin", 0x9c654, 0x13

	.globl gUnknown_8277213
gUnknown_8277213: @ 0x8277213
	.incbin "build/data/event_scripts.bin", 0x9c667, 0x11

	.globl gUnknown_8277224
gUnknown_8277224: @ 0x8277224
	.incbin "build/data/event_scripts.bin", 0x9c678, 0x9

	.globl gUnknown_827722D
gUnknown_827722D: @ 0x827722D
	.incbin "build/data/event_scripts.bin", 0x9c681, 0x38

	.globl gUnknown_8277265
gUnknown_8277265: @ 0x8277265
	.incbin "build/data/event_scripts.bin", 0x9c6b9, 0x8b

	.globl gUnknown_82772F0
gUnknown_82772F0: @ 0x82772F0
	.incbin "build/data/event_scripts.bin", 0x9c744, 0x8

	.globl gUnknown_82772F8
gUnknown_82772F8: @ 0x82772F8
	.incbin "build/data/event_scripts.bin", 0x9c74c, 0x590

	.globl gUnknown_8277888
gUnknown_8277888: @ 0x8277888
	.incbin "build/data/event_scripts.bin", 0x9ccdc, 0x24

	.globl gUnknown_82778AC
gUnknown_82778AC: @ 0x82778AC
	.incbin "build/data/event_scripts.bin", 0x9cd00, 0x5c

	.globl gUnknown_8277908
gUnknown_8277908: @ 0x8277908
	.incbin "build/data/event_scripts.bin", 0x9cd5c, 0xf328

	.globl gUnknown_8286C30
gUnknown_8286C30: @ 0x8286C30
	.incbin "build/data/event_scripts.bin", 0xac084, 0x388

	.globl gUnknown_8286FB8
gUnknown_8286FB8: @ 0x8286FB8
	.incbin "build/data/event_scripts.bin", 0xac40c, 0x1e

	.globl gUnknown_8286FD6
gUnknown_8286FD6: @ 0x8286FD6
	.incbin "build/data/event_scripts.bin", 0xac42a, 0x12

	.globl gUnknown_8286FE8
gUnknown_8286FE8: @ 0x8286FE8
	.incbin "build/data/event_scripts.bin", 0xac43c, 0x274

	.globl gUnknown_828725C
gUnknown_828725C: @ 0x828725C
	.incbin "build/data/event_scripts.bin", 0xac6b0, 0x91

	.globl gUnknown_82872ED
gUnknown_82872ED: @ 0x82872ED
	.incbin "build/data/event_scripts.bin", 0xac741, 0x6fd

	.globl gUnknown_82879EA
gUnknown_82879EA: @ 0x82879EA
	.incbin "build/data/event_scripts.bin", 0xace3e, 0xa7f

	.globl gUnknown_8288469
gUnknown_8288469: @ 0x8288469
	.incbin "build/data/event_scripts.bin", 0xad8bd, 0x1a

	.globl gUnknown_8288483
gUnknown_8288483: @ 0x8288483
	.incbin "build/data/event_scripts.bin", 0xad8d7, 0x21

	.globl gUnknown_82884A4
gUnknown_82884A4: @ 0x82884A4
	.incbin "build/data/event_scripts.bin", 0xad8f8, 0x88e

	.globl gUnknown_8288D32
gUnknown_8288D32: @ 0x8288D32
	.incbin "build/data/event_scripts.bin", 0xae186, 0xd

	.globl gUnknown_8288D3F
gUnknown_8288D3F: @ 0x8288D3F
	.incbin "build/data/event_scripts.bin", 0xae193, 0xd

	.globl gUnknown_8288D4C
gUnknown_8288D4C: @ 0x8288D4C
	.incbin "build/data/event_scripts.bin", 0xae1a0, 0x9

	.globl gUnknown_8288D55
gUnknown_8288D55: @ 0x8288D55
	.incbin "build/data/event_scripts.bin", 0xae1a9, 0x160

	.globl gUnknown_8288EB5
gUnknown_8288EB5: @ 0x8288EB5
	.incbin "build/data/event_scripts.bin", 0xae309, 0x3d

	.globl gUnknown_8288EF2
gUnknown_8288EF2: @ 0x8288EF2
	.incbin "build/data/event_scripts.bin", 0xae346, 0x3

	.globl gUnknown_8288EF5
gUnknown_8288EF5: @ 0x8288EF5
	.incbin "build/data/event_scripts.bin", 0xae349, 0x9e

	.globl gUnknown_8288F93
gUnknown_8288F93: @ 0x8288F93
	.incbin "build/data/event_scripts.bin", 0xae3e7, 0x2a

	.globl gUnknown_8288FBD
gUnknown_8288FBD: @ 0x8288FBD
	.incbin "build/data/event_scripts.bin", 0xae411, 0x52

	.globl gUnknown_828900F
gUnknown_828900F: @ 0x828900F
	.incbin "build/data/event_scripts.bin", 0xae463, 0x54

	.globl gUnknown_8289063
gUnknown_8289063: @ 0x8289063
	.incbin "build/data/event_scripts.bin", 0xae4b7, 0xe

	.globl gUnknown_8289071
gUnknown_8289071: @ 0x8289071
	.incbin "build/data/event_scripts.bin", 0xae4c5, 0x7

	.globl gUnknown_8289078
gUnknown_8289078: @ 0x8289078
	.incbin "build/data/event_scripts.bin", 0xae4cc, 0x7

	.globl gUnknown_828907F
gUnknown_828907F: @ 0x828907F
	.incbin "build/data/event_scripts.bin", 0xae4d3, 0x7

	.globl gUnknown_8289086
gUnknown_8289086: @ 0x8289086
	.incbin "build/data/event_scripts.bin", 0xae4da, 0x4

	.globl gUnknown_828908A
gUnknown_828908A: @ 0x828908A
	.incbin "build/data/event_scripts.bin", 0xae4de, 0x9

	.globl gUnknown_8289093
gUnknown_8289093: @ 0x8289093
	.incbin "build/data/event_scripts.bin", 0xae4e7, 0x6

	.globl gUnknown_8289099
gUnknown_8289099: @ 0x8289099
	.incbin "build/data/event_scripts.bin", 0xae4ed, 0x4

	.globl gUnknown_828909D
gUnknown_828909D: @ 0x828909D
	.incbin "build/data/event_scripts.bin", 0xae4f1, 0xa4

	.globl gUnknown_8289141
gUnknown_8289141: @ 0x8289141
	.incbin "build/data/event_scripts.bin", 0xae595, 0x4

	.globl gUnknown_8289145
gUnknown_8289145: @ 0x8289145
	.incbin "build/data/event_scripts.bin", 0xae599, 0x6f

	.globl gUnknown_82891B4
gUnknown_82891B4: @ 0x82891B4
	.incbin "build/data/event_scripts.bin", 0xae608, 0x1b

	.globl gUnknown_82891CF
gUnknown_82891CF: @ 0x82891CF
	.incbin "build/data/event_scripts.bin", 0xae623, 0x82

	.globl gUnknown_8289251
gUnknown_8289251: @ 0x8289251
	.incbin "build/data/event_scripts.bin", 0xae6a5, 0x9

	.globl gUnknown_828925A
gUnknown_828925A: @ 0x828925A
	.incbin "build/data/event_scripts.bin", 0xae6ae, 0xe

	.globl gUnknown_8289268
gUnknown_8289268: @ 0x8289268
	.incbin "build/data/event_scripts.bin", 0xae6bc, 0x7

	.globl gUnknown_828926F
gUnknown_828926F: @ 0x828926F
	.incbin "build/data/event_scripts.bin", 0xae6c3, 0x13

	.globl gUnknown_8289282
gUnknown_8289282: @ 0x8289282
	.incbin "build/data/event_scripts.bin", 0xae6d6, 0x11

	.globl gUnknown_8289293
gUnknown_8289293: @ 0x8289293
	.incbin "build/data/event_scripts.bin", 0xae6e7, 0xa

	.globl gUnknown_828929D
gUnknown_828929D: @ 0x828929D
	.incbin "build/data/event_scripts.bin", 0xae6f1, 0x5c

	.globl gUnknown_82892F9
gUnknown_82892F9: @ 0x82892F9
	.incbin "build/data/event_scripts.bin", 0xae74d, 0xb

	.globl gUnknown_8289304
gUnknown_8289304: @ 0x8289304
	.incbin "build/data/event_scripts.bin", 0xae758, 0x48

	.globl gUnknown_828934C
gUnknown_828934C: @ 0x828934C
	.incbin "build/data/event_scripts.bin", 0xae7a0, 0x14

	.globl gUnknown_8289360
gUnknown_8289360: @ 0x8289360
	.incbin "build/data/event_scripts.bin", 0xae7b4, 0x2b

	.globl gUnknown_828938B
gUnknown_828938B: @ 0x828938B
	.incbin "build/data/event_scripts.bin", 0xae7df, 0xa

	.globl gUnknown_8289395
gUnknown_8289395: @ 0x8289395
	.incbin "build/data/event_scripts.bin", 0xae7e9, 0x7

	.globl gUnknown_828939C
gUnknown_828939C: @ 0x828939C
	.incbin "build/data/event_scripts.bin", 0xae7f0, 0xb

	.globl gUnknown_82893A7
gUnknown_82893A7: @ 0x82893A7
	.incbin "build/data/event_scripts.bin", 0xae7fb, 0x4

	.globl gUnknown_82893AB
gUnknown_82893AB: @ 0x82893AB
	.incbin "build/data/event_scripts.bin", 0xae7ff, 0x7

	.globl gUnknown_82893B2
gUnknown_82893B2: @ 0x82893B2
	.incbin "build/data/event_scripts.bin", 0xae806, 0xd

	.globl gUnknown_82893BF
gUnknown_82893BF: @ 0x82893BF
	.incbin "build/data/event_scripts.bin", 0xae813, 0x7

	.globl gUnknown_82893C6
gUnknown_82893C6: @ 0x82893C6
	.incbin "build/data/event_scripts.bin", 0xae81a, 0x1b

	.globl gUnknown_82893E1
gUnknown_82893E1: @ 0x82893E1
	.incbin "build/data/event_scripts.bin", 0xae835, 0x37

	.globl gUnknown_8289418
gUnknown_8289418: @ 0x8289418
	.incbin "build/data/event_scripts.bin", 0xae86c, 0x37

	.globl gUnknown_828944F
gUnknown_828944F: @ 0x828944F
	.incbin "build/data/event_scripts.bin", 0xae8a3, 0x3e

	.globl gUnknown_828948D
gUnknown_828948D: @ 0x828948D
	.incbin "build/data/event_scripts.bin", 0xae8e1, 0x1b

	.globl gUnknown_82894A8
gUnknown_82894A8: @ 0x82894A8
	.incbin "build/data/event_scripts.bin", 0xae8fc, 0x7

	.globl gUnknown_82894AF
gUnknown_82894AF: @ 0x82894AF
	.incbin "build/data/event_scripts.bin", 0xae903, 0x9c

	.globl gUnknown_828954B
gUnknown_828954B: @ 0x828954B
	.incbin "build/data/event_scripts.bin", 0xae99f, 0x2

	.globl gUnknown_828954D
gUnknown_828954D: @ 0x828954D
	.incbin "build/data/event_scripts.bin", 0xae9a1, 0x11

	.globl gUnknown_828955E
gUnknown_828955E: @ 0x828955E
	.incbin "build/data/event_scripts.bin", 0xae9b2, 0x7

	.globl gUnknown_8289565
gUnknown_8289565: @ 0x8289565
	.incbin "build/data/event_scripts.bin", 0xae9b9, 0x7

	.globl gUnknown_828956C
gUnknown_828956C: @ 0x828956C
	.incbin "build/data/event_scripts.bin", 0xae9c0, 0x8e

	.globl gUnknown_82895FA
gUnknown_82895FA: @ 0x82895FA
	.incbin "build/data/event_scripts.bin", 0xaea4e, 0x4

	.globl gUnknown_82895FE
gUnknown_82895FE: @ 0x82895FE
	.incbin "build/data/event_scripts.bin", 0xaea52, 0x4

	.globl gUnknown_8289602
gUnknown_8289602: @ 0x8289602
	.incbin "build/data/event_scripts.bin", 0xaea56, 0xf

	.globl gUnknown_8289611
gUnknown_8289611: @ 0x8289611
	.incbin "build/data/event_scripts.bin", 0xaea65, 0xf

	.globl gUnknown_8289620
gUnknown_8289620: @ 0x8289620
	.incbin "build/data/event_scripts.bin", 0xaea74, 0x8

	.globl gUnknown_8289628
gUnknown_8289628: @ 0x8289628
	.incbin "build/data/event_scripts.bin", 0xaea7c, 0x4

	.globl gUnknown_828962C
gUnknown_828962C: @ 0x828962C
	.incbin "build/data/event_scripts.bin", 0xaea80, 0xb

	.globl gUnknown_8289637
gUnknown_8289637: @ 0x8289637
	.incbin "build/data/event_scripts.bin", 0xaea8b, 0x8

	.globl gUnknown_828963F
gUnknown_828963F: @ 0x828963F
	.incbin "build/data/event_scripts.bin", 0xaea93, 0x37

	.globl gUnknown_8289676
gUnknown_8289676: @ 0x8289676
	.incbin "build/data/event_scripts.bin", 0xaeaca, 0x29

	.globl gUnknown_828969F
gUnknown_828969F: @ 0x828969F
	.incbin "build/data/event_scripts.bin", 0xaeaf3, 0x51

	.globl gUnknown_82896F0
gUnknown_82896F0: @ 0x82896F0
	.incbin "build/data/event_scripts.bin", 0xaeb44, 0xe

	.globl gUnknown_82896FE
gUnknown_82896FE: @ 0x82896FE
	.incbin "build/data/event_scripts.bin", 0xaeb52, 0xb

	.globl gUnknown_8289709
gUnknown_8289709: @ 0x8289709
	.incbin "build/data/event_scripts.bin", 0xaeb5d, 0x4

	.globl gUnknown_828970D
gUnknown_828970D: @ 0x828970D
	.incbin "build/data/event_scripts.bin", 0xaeb61, 0x8

	.globl gUnknown_8289715
gUnknown_8289715: @ 0x8289715
	.incbin "build/data/event_scripts.bin", 0xaeb69, 0x7

	.globl gUnknown_828971C
gUnknown_828971C: @ 0x828971C
	.incbin "build/data/event_scripts.bin", 0xaeb70, 0x18

	.globl gUnknown_8289734
gUnknown_8289734: @ 0x8289734
	.incbin "build/data/event_scripts.bin", 0xaeb88, 0x1b

	.globl gUnknown_828974F
gUnknown_828974F: @ 0x828974F
	.incbin "build/data/event_scripts.bin", 0xaeba3, 0x7

	.globl gUnknown_8289756
gUnknown_8289756: @ 0x8289756
	.incbin "build/data/event_scripts.bin", 0xaebaa, 0x7

	.globl gUnknown_828975D
gUnknown_828975D: @ 0x828975D
	.incbin "build/data/event_scripts.bin", 0xaebb1, 0x2a

	.globl gUnknown_8289787
gUnknown_8289787: @ 0x8289787
	.incbin "build/data/event_scripts.bin", 0xaebdb, 0x14

	.globl gUnknown_828979B
gUnknown_828979B: @ 0x828979B
	.incbin "build/data/event_scripts.bin", 0xaebef, 0xd

	.globl gUnknown_82897A8
gUnknown_82897A8: @ 0x82897A8
	.incbin "build/data/event_scripts.bin", 0xaebfc, 0x14

	.globl gUnknown_82897BC
gUnknown_82897BC: @ 0x82897BC
	.incbin "build/data/event_scripts.bin", 0xaec10, 0x9

	.globl gUnknown_82897C5
gUnknown_82897C5: @ 0x82897C5
	.incbin "build/data/event_scripts.bin", 0xaec19, 0x22

	.globl gUnknown_82897E7
gUnknown_82897E7: @ 0x82897E7
	.incbin "build/data/event_scripts.bin", 0xaec3b, 0xb

	.globl gUnknown_82897F2
gUnknown_82897F2: @ 0x82897F2
	.incbin "build/data/event_scripts.bin", 0xaec46, 0xd

	.globl gUnknown_82897FF
gUnknown_82897FF: @ 0x82897FF
	.incbin "build/data/event_scripts.bin", 0xaec53, 0xb

	.globl gUnknown_828980A
gUnknown_828980A: @ 0x828980A
	.incbin "build/data/event_scripts.bin", 0xaec5e, 0x9

	.globl gUnknown_8289813
gUnknown_8289813: @ 0x8289813
	.incbin "build/data/event_scripts.bin", 0xaec67, 0x10

	.globl gUnknown_8289823
gUnknown_8289823: @ 0x8289823
	.incbin "build/data/event_scripts.bin", 0xaec77, 0xb

	.globl gUnknown_828982E
gUnknown_828982E: @ 0x828982E
	.incbin "build/data/event_scripts.bin", 0xaec82, 0x9

	.globl gUnknown_8289837
gUnknown_8289837: @ 0x8289837
	.incbin "build/data/event_scripts.bin", 0xaec8b, 0xe

	.globl gUnknown_8289845
gUnknown_8289845: @ 0x8289845
	.incbin "build/data/event_scripts.bin", 0xaec99, 0x43

	.globl gUnknown_8289888
gUnknown_8289888: @ 0x8289888
	.incbin "build/data/event_scripts.bin", 0xaecdc, 0x7

	.globl gUnknown_828988F
gUnknown_828988F: @ 0x828988F
	.incbin "build/data/event_scripts.bin", 0xaece3, 0x7

	.globl gUnknown_8289896
gUnknown_8289896: @ 0x8289896
	.incbin "build/data/event_scripts.bin", 0xaecea, 0x12

	.globl gUnknown_82898A8
gUnknown_82898A8: @ 0x82898A8
	.incbin "build/data/event_scripts.bin", 0xaecfc, 0x7

	.globl gUnknown_82898AF
gUnknown_82898AF: @ 0x82898AF
	.incbin "build/data/event_scripts.bin", 0xaed03, 0xd

	.globl gUnknown_82898BC
gUnknown_82898BC: @ 0x82898BC
	.incbin "build/data/event_scripts.bin", 0xaed10, 0xb

	.globl gUnknown_82898C7
gUnknown_82898C7: @ 0x82898C7
	.incbin "build/data/event_scripts.bin", 0xaed1b, 0x11

	.globl gUnknown_82898D8
gUnknown_82898D8: @ 0x82898D8
	.incbin "build/data/event_scripts.bin", 0xaed2c, 0x11

	.globl gUnknown_82898E9
gUnknown_82898E9: @ 0x82898E9
	.incbin "build/data/event_scripts.bin", 0xaed3d, 0x17

	.globl gUnknown_8289900
gUnknown_8289900: @ 0x8289900
	.incbin "build/data/event_scripts.bin", 0xaed54, 0xaa

	.globl gUnknown_82899AA
gUnknown_82899AA: @ 0x82899AA
	.incbin "build/data/event_scripts.bin", 0xaedfe, 0xe

	.globl gUnknown_82899B8
gUnknown_82899B8: @ 0x82899B8
	.incbin "build/data/event_scripts.bin", 0xaee0c, 0x14

	.globl gUnknown_82899CC
gUnknown_82899CC: @ 0x82899CC
	.incbin "build/data/event_scripts.bin", 0xaee20, 0xe

	.globl gUnknown_82899DA
gUnknown_82899DA: @ 0x82899DA
	.incbin "build/data/event_scripts.bin", 0xaee2e, 0xa

	.globl gUnknown_82899E4
gUnknown_82899E4: @ 0x82899E4
	.incbin "build/data/event_scripts.bin", 0xaee38, 0x14

	.globl gUnknown_82899F8
gUnknown_82899F8: @ 0x82899F8
	.incbin "build/data/event_scripts.bin", 0xaee4c, 0x14

	.globl gUnknown_8289A0C
gUnknown_8289A0C: @ 0x8289A0C
	.incbin "build/data/event_scripts.bin", 0xaee60, 0x25

	.globl gUnknown_8289A31
gUnknown_8289A31: @ 0x8289A31
	.incbin "build/data/event_scripts.bin", 0xaee85, 0xf

	.globl gUnknown_8289A40
gUnknown_8289A40: @ 0x8289A40
	.incbin "build/data/event_scripts.bin", 0xaee94, 0x9

	.globl gUnknown_8289A49
gUnknown_8289A49: @ 0x8289A49
	.incbin "build/data/event_scripts.bin", 0xaee9d, 0x69

	.globl gUnknown_8289AB2
gUnknown_8289AB2: @ 0x8289AB2
	.incbin "build/data/event_scripts.bin", 0xaef06, 0x14

	.globl gUnknown_8289AC6
gUnknown_8289AC6: @ 0x8289AC6
	.incbin "build/data/event_scripts.bin", 0xaef1a, 0x14

	.globl gUnknown_8289ADA
gUnknown_8289ADA: @ 0x8289ADA
	.incbin "build/data/event_scripts.bin", 0xaef2e, 0xe

	.globl gUnknown_8289AE8
gUnknown_8289AE8: @ 0x8289AE8
	.incbin "build/data/event_scripts.bin", 0xaef3c, 0xe

	.globl gUnknown_8289AF6
gUnknown_8289AF6: @ 0x8289AF6
	.incbin "build/data/event_scripts.bin", 0xaef4a, 0x1

	.globl gUnknown_8289AF7
gUnknown_8289AF7: @ 0x8289AF7
	.incbin "build/data/event_scripts.bin", 0xaef4b, 0x22

	.globl gUnknown_8289B19
gUnknown_8289B19: @ 0x8289B19
	.incbin "build/data/event_scripts.bin", 0xaef6d, 0x1

	.globl gUnknown_8289B1A
gUnknown_8289B1A: @ 0x8289B1A
	.incbin "build/data/event_scripts.bin", 0xaef6e, 0x15

	.globl gUnknown_8289B2F
gUnknown_8289B2F: @ 0x8289B2F
	.incbin "build/data/event_scripts.bin", 0xaef83, 0x1

	.globl gUnknown_8289B30
gUnknown_8289B30: @ 0x8289B30
	.incbin "build/data/event_scripts.bin", 0xaef84, 0x1f

	.globl gUnknown_8289B4F
gUnknown_8289B4F: @ 0x8289B4F
	.incbin "build/data/event_scripts.bin", 0xaefa3, 0xa

	.globl gUnknown_8289B59
gUnknown_8289B59: @ 0x8289B59
	.incbin "build/data/event_scripts.bin", 0xaefad, 0xc

	.globl gUnknown_8289B65
gUnknown_8289B65: @ 0x8289B65
	.incbin "build/data/event_scripts.bin", 0xaefb9, 0xc

	.globl gUnknown_8289B71
gUnknown_8289B71: @ 0x8289B71
	.incbin "build/data/event_scripts.bin", 0xaefc5, 0xc

	.globl gUnknown_8289B7D
gUnknown_8289B7D: @ 0x8289B7D
	.incbin "build/data/event_scripts.bin", 0xaefd1, 0xe

	.globl gUnknown_8289B8B
gUnknown_8289B8B: @ 0x8289B8B
	.incbin "build/data/event_scripts.bin", 0xaefdf, 0x1c

	.globl gUnknown_8289BA7
gUnknown_8289BA7: @ 0x8289BA7
	.incbin "build/data/event_scripts.bin", 0xaeffb, 0x10

	.globl gUnknown_8289BB7
gUnknown_8289BB7: @ 0x8289BB7
	.incbin "build/data/event_scripts.bin", 0xaf00b, 0x10

	.globl gUnknown_8289BC7
gUnknown_8289BC7: @ 0x8289BC7
	.incbin "build/data/event_scripts.bin", 0xaf01b, 0xe

	.globl gUnknown_8289BD5
gUnknown_8289BD5: @ 0x8289BD5
	.incbin "build/data/event_scripts.bin", 0xaf029, 0x7

	.globl gUnknown_8289BDC
gUnknown_8289BDC: @ 0x8289BDC
	.incbin "build/data/event_scripts.bin", 0xaf030, 0x1b

	.globl gUnknown_8289BF7
gUnknown_8289BF7: @ 0x8289BF7
	.incbin "build/data/event_scripts.bin", 0xaf04b, 0xd

	.globl gUnknown_8289C04
gUnknown_8289C04: @ 0x8289C04
	.incbin "build/data/event_scripts.bin", 0xaf058, 0x3

	.globl gUnknown_8289C07
gUnknown_8289C07: @ 0x8289C07
	.incbin "build/data/event_scripts.bin", 0xaf05b, 0x3

	.globl gUnknown_8289C0A
gUnknown_8289C0A: @ 0x8289C0A
	.incbin "build/data/event_scripts.bin", 0xaf05e, 0xa

	.globl gUnknown_8289C14
gUnknown_8289C14: @ 0x8289C14
	.incbin "build/data/event_scripts.bin", 0xaf068, 0x9

	.globl gUnknown_8289C1D
gUnknown_8289C1D: @ 0x8289C1D
	.incbin "build/data/event_scripts.bin", 0xaf071, 0x10

	.globl gUnknown_8289C2D
gUnknown_8289C2D: @ 0x8289C2D
	.incbin "build/data/event_scripts.bin", 0xaf081, 0x8

	.globl gUnknown_8289C35
gUnknown_8289C35: @ 0x8289C35
	.incbin "build/data/event_scripts.bin", 0xaf089, 0x2c

	.globl gUnknown_8289C61
gUnknown_8289C61: @ 0x8289C61
	.incbin "build/data/event_scripts.bin", 0xaf0b5, 0x17

	.globl gUnknown_8289C78
gUnknown_8289C78: @ 0x8289C78
	.incbin "build/data/event_scripts.bin", 0xaf0cc, 0xb

	.globl gUnknown_8289C83
gUnknown_8289C83: @ 0x8289C83
	.incbin "build/data/event_scripts.bin", 0xaf0d7, 0xb

	.globl gUnknown_8289C8E
gUnknown_8289C8E: @ 0x8289C8E
	.incbin "build/data/event_scripts.bin", 0xaf0e2, 0x6

	.globl gUnknown_8289C94
gUnknown_8289C94: @ 0x8289C94
	.incbin "build/data/event_scripts.bin", 0xaf0e8, 0x12

	.globl gUnknown_8289CA6
gUnknown_8289CA6: @ 0x8289CA6
	.incbin "build/data/event_scripts.bin", 0xaf0fa, 0x6

	.globl gUnknown_8289CAC
gUnknown_8289CAC: @ 0x8289CAC
	.incbin "build/data/event_scripts.bin", 0xaf100, 0x12

	.globl gUnknown_8289CBE
gUnknown_8289CBE: @ 0x8289CBE
	.incbin "build/data/event_scripts.bin", 0xaf112, 0x6

	.globl gUnknown_8289CC4
gUnknown_8289CC4: @ 0x8289CC4
	.incbin "build/data/event_scripts.bin", 0xaf118, 0x12

	.globl gUnknown_8289CD6
gUnknown_8289CD6: @ 0x8289CD6
	.incbin "build/data/event_scripts.bin", 0xaf12a, 0x6

	.globl gUnknown_8289CDC
gUnknown_8289CDC: @ 0x8289CDC
	.incbin "build/data/event_scripts.bin", 0xaf130, 0x12

	.globl gUnknown_8289CEE
gUnknown_8289CEE: @ 0x8289CEE
	.incbin "build/data/event_scripts.bin", 0xaf142, 0x6

	.globl gUnknown_8289CF4
gUnknown_8289CF4: @ 0x8289CF4
	.incbin "build/data/event_scripts.bin", 0xaf148, 0x12

	.globl gUnknown_8289D06
gUnknown_8289D06: @ 0x8289D06
	.incbin "build/data/event_scripts.bin", 0xaf15a, 0x6

	.globl gUnknown_8289D0C
gUnknown_8289D0C: @ 0x8289D0C
	.incbin "build/data/event_scripts.bin", 0xaf160, 0x10

	.globl gUnknown_8289D1C
gUnknown_8289D1C: @ 0x8289D1C
	.incbin "build/data/event_scripts.bin", 0xaf170, 0x6

	.globl gUnknown_8289D22
gUnknown_8289D22: @ 0x8289D22
	.incbin "build/data/event_scripts.bin", 0xaf176, 0x14

	.globl gUnknown_8289D36
gUnknown_8289D36: @ 0x8289D36
	.incbin "build/data/event_scripts.bin", 0xaf18a, 0x6

	.globl gUnknown_8289D3C
gUnknown_8289D3C: @ 0x8289D3C
	.incbin "build/data/event_scripts.bin", 0xaf190, 0x10

	.globl gUnknown_8289D4C
gUnknown_8289D4C: @ 0x8289D4C
	.incbin "build/data/event_scripts.bin", 0xaf1a0, 0x1d

	.globl gUnknown_8289D69
gUnknown_8289D69: @ 0x8289D69
	.incbin "build/data/event_scripts.bin", 0xaf1bd, 0x10

	.globl gUnknown_8289D79
gUnknown_8289D79: @ 0x8289D79
	.incbin "build/data/event_scripts.bin", 0xaf1cd, 0x6

	.globl gUnknown_8289D7F
gUnknown_8289D7F: @ 0x8289D7F
	.incbin "build/data/event_scripts.bin", 0xaf1d3, 0x1b

	.globl gUnknown_8289D9A
gUnknown_8289D9A: @ 0x8289D9A
	.incbin "build/data/event_scripts.bin", 0xaf1ee, 0x4

	.globl gUnknown_8289D9E
gUnknown_8289D9E: @ 0x8289D9E
	.incbin "build/data/event_scripts.bin", 0xaf1f2, 0xe

	.globl gUnknown_8289DAC
gUnknown_8289DAC: @ 0x8289DAC
	.incbin "build/data/event_scripts.bin", 0xaf200, 0x2a

	.globl gUnknown_8289DD6
gUnknown_8289DD6: @ 0x8289DD6
	.incbin "build/data/event_scripts.bin", 0xaf22a, 0x1b

	.globl gUnknown_8289DF1
gUnknown_8289DF1: @ 0x8289DF1
	.incbin "build/data/event_scripts.bin", 0xaf245, 0x10

	.globl gUnknown_8289E01
gUnknown_8289E01: @ 0x8289E01
	.incbin "build/data/event_scripts.bin", 0xaf255, 0x4

	.globl gUnknown_8289E05
gUnknown_8289E05: @ 0x8289E05
	.incbin "build/data/event_scripts.bin", 0xaf259, 0x4

	.globl gUnknown_8289E09
gUnknown_8289E09: @ 0x8289E09
	.incbin "build/data/event_scripts.bin", 0xaf25d, 0x3d

	.globl gUnknown_8289E46
gUnknown_8289E46: @ 0x8289E46
	.incbin "build/data/event_scripts.bin", 0xaf29a, 0x35

	.globl gUnknown_8289E7B
gUnknown_8289E7B: @ 0x8289E7B
	.incbin "build/data/event_scripts.bin", 0xaf2cf, 0xc7

	.globl gUnknown_8289F42
gUnknown_8289F42: @ 0x8289F42
	.incbin "build/data/event_scripts.bin", 0xaf396, 0x7

	.globl gUnknown_8289F49
gUnknown_8289F49: @ 0x8289F49
	.incbin "build/data/event_scripts.bin", 0xaf39d, 0x7

	.globl gUnknown_8289F50
gUnknown_8289F50: @ 0x8289F50
	.incbin "build/data/event_scripts.bin", 0xaf3a4, 0xc

	.globl gUnknown_8289F5C
gUnknown_8289F5C: @ 0x8289F5C
	.incbin "build/data/event_scripts.bin", 0xaf3b0, 0x334

	.globl gUnknown_828A290
gUnknown_828A290: @ 0x828A290
	.incbin "build/data/event_scripts.bin", 0xaf6e4, 0x34

	.globl gUnknown_828A2C4
gUnknown_828A2C4: @ 0x828A2C4
	.incbin "build/data/event_scripts.bin", 0xaf718, 0x18

	.globl gUnknown_828A2DC
gUnknown_828A2DC: @ 0x828A2DC
	.incbin "build/data/event_scripts.bin", 0xaf730, 0x4

	.globl gUnknown_828A2E0
gUnknown_828A2E0: @ 0x828A2E0
	.incbin "build/data/event_scripts.bin", 0xaf734, 0x2c

	.globl gUnknown_828A30C
gUnknown_828A30C: @ 0x828A30C
	.incbin "build/data/event_scripts.bin", 0xaf760, 0x46

	.globl gUnknown_828A352
gUnknown_828A352: @ 0x828A352
	.incbin "build/data/event_scripts.bin", 0xaf7a6, 0xa

	.globl gUnknown_828A35C
gUnknown_828A35C: @ 0x828A35C
	.incbin "build/data/event_scripts.bin", 0xaf7b0, 0x2e

	.globl gUnknown_828A38A
gUnknown_828A38A: @ 0x828A38A
	.incbin "build/data/event_scripts.bin", 0xaf7de, 0xf6

	.globl gUnknown_828A480
gUnknown_828A480: @ 0x828A480
	.incbin "build/data/event_scripts.bin", 0xaf8d4, 0x2458

	.globl gUnknown_828C8D8
gUnknown_828C8D8: @ 0x828C8D8
	.incbin "build/data/event_scripts.bin", 0xb1d2c, 0x9dc

	.align 2
	.globl gUnknown_828D2B4
gUnknown_828D2B4:
	.include "data/mystery_event_script_cmd_table.inc"

	.globl gUnknown_828D2F8
gUnknown_828D2F8: @ 0x828D2F8
