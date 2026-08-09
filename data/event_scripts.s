
	.section script_data, "aw", %progbits
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
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
	.4byte gUnknown_8242B6D                  @ 000
	.4byte gUnknown_8242C95                  @ 001
	.4byte gUnknown_82423AF                  @ 002
	.4byte gUnknown_82423BA                  @ 003
	.4byte gUnknown_82423C4                  @ 004
	.4byte gUnknown_82423CC                  @ 005
	.4byte gUnknown_824252E                  @ 006
	.4byte gUnknown_8242C4F                  @ 007
	.4byte gUnknown_8244CF3                  @ 008
	.4byte gUnknown_82423D6                  @ 009
	.4byte gUnknown_82423E1                  @ 010

	.globl gUnknown_81DB7E8
gUnknown_81DB7E8: @ 0x81DB7E8
	.include "data/scripts/gUnknown_81DB7E8.inc"

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
	.incbin "build/data/event_scripts.bin", 0x6244f, 0x53b4
gUnknown_82423AF: @ 0x82423AF
	.incbin "build/data/event_scripts.bin", 0x67803, 0xb
gUnknown_82423BA: @ 0x82423BA
	.incbin "build/data/event_scripts.bin", 0x6780e, 0xa
gUnknown_82423C4: @ 0x82423C4
	.incbin "build/data/event_scripts.bin", 0x67818, 0x8
gUnknown_82423CC: @ 0x82423CC
	.incbin "build/data/event_scripts.bin", 0x67820, 0xa
gUnknown_82423D6: @ 0x82423D6
	.incbin "build/data/event_scripts.bin", 0x6782a, 0xb
gUnknown_82423E1: @ 0x82423E1
	.incbin "build/data/event_scripts.bin", 0x67835, 0xd

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
	.incbin "build/data/event_scripts.bin", 0x678e6, 0x9c
gUnknown_824252E: @ 0x824252E
	.incbin "build/data/event_scripts.bin", 0x67982, 0x14a

	.globl gUnknown_8242678
gUnknown_8242678: @ 0x8242678
	.incbin "build/data/event_scripts.bin", 0x67acc, 0x279

	.globl gUnknown_82428F1
gUnknown_82428F1: @ 0x82428F1
	.incbin "build/data/event_scripts.bin", 0x67d45, 0xb

	.globl gUnknown_82428FC
gUnknown_82428FC: @ 0x82428FC
	.incbin "build/data/event_scripts.bin", 0x67d50, 0x271
gUnknown_8242B6D: @ 0x8242B6D
	.incbin "build/data/event_scripts.bin", 0x67fc1, 0xe2
gUnknown_8242C4F: @ 0x8242C4F
	.incbin "build/data/event_scripts.bin", 0x680a3, 0x46
gUnknown_8242C95: @ 0x8242C95
	.incbin "build/data/event_scripts.bin", 0x680e9, 0xb4

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
	.incbin "build/data/event_scripts.bin", 0x69b9d, 0x5aa
gUnknown_8244CF3: @ 0x8244CF3
	.incbin "build/data/event_scripts.bin", 0x6a147, 0x1d

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
	.4byte gUnknown_8277924                  @ 000
	.4byte gUnknown_8277924                  @ 001
	.4byte gUnknown_828063A                  @ 002
	.4byte gUnknown_8277955                  @ 003
	.4byte gUnknown_827884F                  @ 004
	.4byte gUnknown_82786D9                  @ 005
	.4byte gUnknown_8279E41                  @ 006
	.4byte gUnknown_8281204                  @ 007
	.4byte gUnknown_827DC85                  @ 008
	.4byte gUnknown_827E01B                  @ 009
	.4byte gUnknown_827E2CB                  @ 010
	.4byte gUnknown_8279D6D                  @ 011
	.4byte gUnknown_8279DB5                  @ 012
	.4byte gUnknown_8281F08                  @ 013
	.4byte gUnknown_8279030                  @ 014
	.4byte gUnknown_8278D16                  @ 015
	.4byte gUnknown_827FF98                  @ 016
	.4byte gUnknown_827FFE9                  @ 017
	.4byte gUnknown_827A375                  @ 018
	.4byte gUnknown_828056D                  @ 019
	.4byte gUnknown_828164F                  @ 020
	.4byte gUnknown_8279495                  @ 021
	.4byte gUnknown_827951D                  @ 022
	.4byte gUnknown_8278CB6                  @ 023
	.4byte gUnknown_82807E8                  @ 024
	.4byte gUnknown_82787B3                  @ 025
	.4byte gUnknown_82806F5                  @ 026
	.4byte gUnknown_827ABC6                  @ 027
	.4byte gUnknown_827E873                  @ 028
	.4byte gUnknown_827AC49                  @ 029
	.4byte gUnknown_827ACA6                  @ 030
	.4byte gUnknown_827AD13                  @ 031
	.4byte gUnknown_827AD90                  @ 032
	.4byte gUnknown_8277E82                  @ 033
	.4byte gUnknown_8277EC0                  @ 034
	.4byte gUnknown_8281689                  @ 035
	.4byte gUnknown_8278276                  @ 036
	.4byte gUnknown_827AF0D                  @ 037
	.4byte gUnknown_8278306                  @ 038
	.4byte gUnknown_8278CFD                  @ 039
	.4byte gUnknown_8278419                  @ 040
	.4byte gUnknown_827846E                  @ 041
	.4byte gUnknown_82780EC                  @ 042
	.4byte gUnknown_8281317                  @ 043
	.4byte gUnknown_827EAE1                  @ 044
	.4byte gUnknown_827E4A8                  @ 045
	.4byte gUnknown_827E411                  @ 046
	.4byte gUnknown_827AF8C                  @ 047
	.4byte gUnknown_8277F4D                  @ 048
	.4byte gUnknown_82788C7                  @ 049
	.4byte gUnknown_8281FEE                  @ 050
	.4byte gUnknown_827FC59                  @ 051
	.4byte gUnknown_8278665                  @ 052
	.4byte gUnknown_8280365                  @ 053
	.4byte gUnknown_8281170                  @ 054
	.4byte gUnknown_82801CA                  @ 055
	.4byte gUnknown_827F33F                  @ 056
	.4byte gUnknown_8280351                  @ 057
	.4byte gUnknown_827EC4C                  @ 058
	.4byte gUnknown_827F0B9                  @ 059
	.4byte gUnknown_828169F                  @ 060
	.4byte gUnknown_827A6FF                  @ 061
	.4byte gUnknown_827ED90                  @ 062
	.4byte gUnknown_82832F7                  @ 063
	.4byte gUnknown_8280086                  @ 064
	.4byte gUnknown_8279554                  @ 065
	.4byte gUnknown_8280BEB                  @ 066
	.4byte gUnknown_827B060                  @ 067
	.4byte gUnknown_82809A9                  @ 068
	.4byte gUnknown_8285087                  @ 069
	.4byte gUnknown_8277DEE                  @ 070
	.4byte gUnknown_827F526                  @ 071
	.4byte gUnknown_827F63E                  @ 072
	.4byte gUnknown_827860F                  @ 073
	.4byte gUnknown_827A33F                  @ 074
	.4byte gUnknown_8280EDB                  @ 075
	.4byte gUnknown_827EE64                  @ 076
	.4byte gUnknown_82779A8                  @ 077
	.4byte gUnknown_8277AD9                  @ 078
	.4byte gUnknown_8277C07                  @ 079
	.4byte gUnknown_8280DA3                  @ 080
	.4byte gUnknown_8281D95                  @ 081
	.4byte gUnknown_827E9B9                  @ 082
	.4byte gUnknown_8279222                  @ 083
	.4byte gUnknown_8278928                  @ 084
	.4byte gUnknown_8278996                  @ 085
	.4byte gUnknown_8278B4C                  @ 086
	.4byte gUnknown_827DEC1                  @ 087
	.4byte gUnknown_827A4EB                  @ 088
	.4byte gUnknown_827B0BD                  @ 089
	.4byte gUnknown_827B10A                  @ 090
	.4byte gUnknown_827B22D                  @ 091
	.4byte gUnknown_827FA82                  @ 092
	.4byte gUnknown_827DDB0                  @ 093
	.4byte gUnknown_827DE11                  @ 094
	.4byte gUnknown_8281739                  @ 095
	.4byte gUnknown_827B349                  @ 096
	.4byte gUnknown_827B366                  @ 097
	.4byte gUnknown_827B3B0                  @ 098
	.4byte gUnknown_827B408                  @ 099
	.4byte gUnknown_827B47E                  @ 100
	.4byte gUnknown_8281B0A                  @ 101
	.4byte gUnknown_82820C6                  @ 102
	.4byte gUnknown_8277FA5                  @ 103
	.4byte gUnknown_827B497                  @ 104
	.4byte gUnknown_828201C                  @ 105
	.4byte gUnknown_827DA50                  @ 106
	.4byte gUnknown_827B4DE                  @ 107
	.4byte gUnknown_827A89C                  @ 108
	.4byte gUnknown_827A41D                  @ 109
	.4byte gUnknown_827ED83                  @ 110
	.4byte gUnknown_8279908                  @ 111
	.4byte gUnknown_827E67E                  @ 112
	.4byte gUnknown_827E579                  @ 113
	.4byte gUnknown_82811D1                  @ 114
	.4byte gUnknown_827E62B                  @ 115
	.4byte gUnknown_8281C56                  @ 116
	.4byte gUnknown_8281C96                  @ 117
	.4byte gUnknown_827B4F1                  @ 118
	.4byte gUnknown_8277924                  @ 119
	.4byte gUnknown_82793A5                  @ 120
	.4byte gUnknown_8281B52                  @ 121
	.4byte gUnknown_8281C2F                  @ 122
	.4byte gUnknown_827E771                  @ 123
	.4byte gUnknown_827FAF1                  @ 124
	.4byte gUnknown_827FDA7                  @ 125
	.4byte gUnknown_82784E1                  @ 126
	.4byte gUnknown_82795AD                  @ 127
	.4byte gUnknown_827EBEF                  @ 128
	.4byte gUnknown_8277D35                  @ 129
	.4byte gUnknown_827B51B                  @ 130
	.4byte gUnknown_8278F7D                  @ 131
	.4byte gUnknown_8282111                  @ 132
	.4byte gUnknown_827B5E1                  @ 133
	.4byte gUnknown_827B605                  @ 134
	.4byte gUnknown_8282239                  @ 135
	.4byte gUnknown_8280752                  @ 136
	.4byte gUnknown_827B656                  @ 137
	.4byte gUnknown_828136E                  @ 138
	.4byte gUnknown_8281571                  @ 139
	.4byte gUnknown_827B6BF                  @ 140
	.4byte gUnknown_827F9D6                  @ 141
	.4byte gUnknown_82825BC                  @ 142
	.4byte gUnknown_827B707                  @ 143
	.4byte gUnknown_8283161                  @ 144
	.4byte gUnknown_827E69B                  @ 145
	.4byte gUnknown_82790E8                  @ 146
	.4byte gUnknown_8280D3E                  @ 147
	.4byte gUnknown_827B89F                  @ 148
	.4byte gUnknown_8281799                  @ 149
	.4byte gUnknown_827B8AC                  @ 150
	.4byte gUnknown_827B8C1                  @ 151
	.4byte gUnknown_8280257                  @ 152
	.4byte gUnknown_8279801                  @ 153
	.4byte gUnknown_8282603                  @ 154
	.4byte gUnknown_827FD53                  @ 155
	.4byte gUnknown_827DD70                  @ 156
	.4byte gUnknown_827A577                  @ 157
	.4byte gUnknown_8282AB5                  @ 158
	.4byte gUnknown_827B8DA                  @ 159
	.4byte gUnknown_827A995                  @ 160
	.4byte gUnknown_8282B1C                  @ 161
	.4byte gUnknown_827B8E6                  @ 162
	.4byte gUnknown_827B967                  @ 163
	.4byte gUnknown_8283D8E                  @ 164
	.4byte gUnknown_827B9A1                  @ 165
	.4byte gUnknown_827BA07                  @ 166
	.4byte gUnknown_828081A                  @ 167
	.4byte gUnknown_827A6B8                  @ 168
	.4byte gUnknown_8281E67                  @ 169
	.4byte gUnknown_827DB4D                  @ 170
	.4byte gUnknown_827BA2F                  @ 171
	.4byte gUnknown_8277FF2                  @ 172
	.4byte gUnknown_827E4E9                  @ 173
	.4byte gUnknown_8282179                  @ 174
	.4byte gUnknown_827BA85                  @ 175
	.4byte gUnknown_827AAAA                  @ 176
	.4byte gUnknown_82800AD                  @ 177
	.4byte gUnknown_8280CE4                  @ 178
	.4byte gUnknown_8278E31                  @ 179
	.4byte gUnknown_827BAC2                  @ 180
	.4byte gUnknown_827F245                  @ 181
	.4byte gUnknown_8279941                  @ 182
	.4byte gUnknown_827BAF1                  @ 183
	.4byte gUnknown_82824F0                  @ 184
	.4byte gUnknown_827E7EC                  @ 185
	.4byte gUnknown_8282553                  @ 186
	.4byte gUnknown_827DA65                  @ 187
	.4byte gUnknown_827FB33                  @ 188
	.4byte gUnknown_827E91B                  @ 189
	.4byte gUnknown_828110A                  @ 190
	.4byte gUnknown_827FE54                  @ 191
	.4byte gUnknown_828181F                  @ 192
	.4byte gUnknown_827BB79                  @ 193
	.4byte gUnknown_827BBB8                  @ 194
	.4byte gUnknown_8282891                  @ 195
	.4byte gUnknown_827A7DC                  @ 196
	.4byte gUnknown_827995E                  @ 197
	.4byte gUnknown_827FE09                  @ 198
	.4byte gUnknown_827A470                  @ 199
	.4byte gUnknown_8279E94                  @ 200
	.4byte gUnknown_8280402                  @ 201
	.4byte gUnknown_827F7CE                  @ 202
	.4byte gUnknown_827BC13                  @ 203
	.4byte gUnknown_827BCA7                  @ 204
	.4byte gUnknown_827BCEA                  @ 205
	.4byte gUnknown_827BD2B                  @ 206
	.4byte gUnknown_827BDB2                  @ 207
	.4byte gUnknown_827BDFA                  @ 208
	.4byte gUnknown_827A02F                  @ 209
	.4byte gUnknown_82792D6                  @ 210
	.4byte gUnknown_8281904                  @ 211
	.4byte gUnknown_827A4A6                  @ 212
	.4byte gUnknown_827A246                  @ 213
	.4byte gUnknown_82829FA                  @ 214
	.4byte gUnknown_82822BB                  @ 215
	.4byte gUnknown_8284055                  @ 216
	.4byte gUnknown_8282718                  @ 217
	.4byte gUnknown_82799BC                  @ 218
	.4byte gUnknown_8279C83                  @ 219
	.4byte gUnknown_8279CC5                  @ 220
	.4byte gUnknown_827E0E4                  @ 221
	.4byte gUnknown_827BE3C                  @ 222
	.4byte gUnknown_82808E1                  @ 223
	.4byte gUnknown_827FEAB                  @ 224
	.4byte gUnknown_827E2FD                  @ 225
	.4byte gUnknown_828286F                  @ 226
	.4byte gUnknown_8282D4E                  @ 227
	.4byte gUnknown_8278F0C                  @ 228
	.4byte gUnknown_827BECD                  @ 229
	.4byte gUnknown_828320D                  @ 230
	.4byte gUnknown_82819B3                  @ 231
	.4byte gUnknown_8281A77                  @ 232
	.4byte gUnknown_8280A78                  @ 233
	.4byte gUnknown_8283179                  @ 234
	.4byte gUnknown_827FA58                  @ 235
	.4byte gUnknown_827BF3A                  @ 236
	.4byte gUnknown_8278D48                  @ 237
	.4byte gUnknown_828068C                  @ 238
	.4byte gUnknown_82855AB                  @ 239
	.4byte gUnknown_827EA96                  @ 240
	.4byte gUnknown_8280C8E                  @ 241
	.4byte gUnknown_827EB3F                  @ 242
	.4byte gUnknown_827E605                  @ 243
	.4byte gUnknown_8279076                  @ 244
	.4byte gUnknown_827BFCA                  @ 245
	.4byte gUnknown_8280FE2                  @ 246
	.4byte gUnknown_8281BEC                  @ 247
	.4byte gUnknown_827DE74                  @ 248
	.4byte gUnknown_8280AF3                  @ 249
	.4byte gUnknown_828048A                  @ 250
	.4byte gUnknown_8278BBB                  @ 251
	.4byte gUnknown_82824B5                  @ 252
	.4byte gUnknown_827C088                  @ 253
	.4byte gUnknown_8282EBB                  @ 254
	.4byte gUnknown_8282F72                  @ 255
	.4byte gUnknown_82830B5                  @ 256
	.4byte gUnknown_827C152                  @ 257
	.4byte gUnknown_827C202                  @ 258
	.4byte gUnknown_827C23A                  @ 259
	.4byte gUnknown_8283439                  @ 260
	.4byte gUnknown_8282C90                  @ 261
	.4byte gUnknown_827C27E                  @ 262
	.4byte gUnknown_827C2C2                  @ 263
	.4byte gUnknown_8283F8E                  @ 264
	.4byte gUnknown_827C2E2                  @ 265
	.4byte gUnknown_827C33D                  @ 266
	.4byte gUnknown_8280FE2                  @ 267
	.4byte gUnknown_827C35C                  @ 268
	.4byte gUnknown_827C3F7                  @ 269
	.4byte gUnknown_827C44B                  @ 270
	.4byte gUnknown_8282DF5                  @ 271
	.4byte gUnknown_8283535                  @ 272
	.4byte gUnknown_8282E73                  @ 273
	.4byte gUnknown_827C4BE                  @ 274
	.4byte gUnknown_8282667                  @ 275
	.4byte gUnknown_827C52F                  @ 276
	.4byte gUnknown_82851E4                  @ 277
	.4byte gUnknown_827C5EA                  @ 278
	.4byte gUnknown_8283CB8                  @ 279
	.4byte gUnknown_827C61E                  @ 280
	.4byte gUnknown_827C7DF                  @ 281
	.4byte gUnknown_828536A                  @ 282
	.4byte gUnknown_827C822                  @ 283
	.4byte gUnknown_827C897                  @ 284
	.4byte gUnknown_827C964                  @ 285
	.4byte gUnknown_827C9AF                  @ 286
	.4byte gUnknown_8283592                  @ 287
	.4byte gUnknown_827C9F2                  @ 288
	.4byte gUnknown_8284AAA                  @ 289
	.4byte gUnknown_8285557                  @ 290
	.4byte gUnknown_8284AC4                  @ 291
	.4byte gUnknown_82837EE                  @ 292
	.4byte gUnknown_827CA1A                  @ 293
	.4byte gUnknown_827CA60                  @ 294
	.4byte gUnknown_827CAA3                  @ 295
	.4byte gUnknown_827CBBA                  @ 296
	.4byte gUnknown_827CC49                  @ 297
	.4byte gUnknown_827CD19                  @ 298
	.4byte gUnknown_82835D5                  @ 299
	.4byte gUnknown_827CD84                  @ 300
	.4byte gUnknown_828582B                  @ 301
	.4byte gUnknown_827CEBB                  @ 302
	.4byte gUnknown_827D06B                  @ 303
	.4byte gUnknown_828365D                  @ 304
	.4byte gUnknown_8283D4F                  @ 305
	.4byte gUnknown_827D083                  @ 306
	.4byte gUnknown_8284569                  @ 307
	.4byte gUnknown_8284F0D                  @ 308
	.4byte gUnknown_8283C31                  @ 309
	.4byte gUnknown_828503F                  @ 310
	.4byte gUnknown_82859FA                  @ 311
	.4byte gUnknown_827D0F2                  @ 312
	.4byte gUnknown_827D254                  @ 313
	.4byte gUnknown_827D2E4                  @ 314
	.4byte gUnknown_8284C1B                  @ 315
	.4byte gUnknown_827D346                  @ 316
	.4byte gUnknown_82847AB                  @ 317
	.4byte gUnknown_8284892                  @ 318
	.4byte gUnknown_8283F3E                  @ 319
	.4byte gUnknown_827D390                  @ 320
	.4byte gUnknown_827D483                  @ 321
	.4byte gUnknown_82844E4                  @ 322
	.4byte gUnknown_827D4EF                  @ 323
	.4byte gUnknown_827F43E                  @ 324
	.4byte gUnknown_827D51D                  @ 325
	.4byte gUnknown_827D578                  @ 326
	.4byte gUnknown_828545E                  @ 327
	.4byte gUnknown_82836F1                  @ 328
	.4byte gUnknown_82837C9                  @ 329
	.4byte gUnknown_8283883                  @ 330
	.4byte gUnknown_8283895                  @ 331
	.4byte gUnknown_827D5E0                  @ 332
	.4byte gUnknown_82781B1                  @ 333
	.4byte gUnknown_827D64A                  @ 334
	.4byte gUnknown_827D674                  @ 335
	.4byte gUnknown_827D683                  @ 336
	.4byte gUnknown_828392B                  @ 337
	.4byte gUnknown_8283D9A                  @ 338
	.4byte gUnknown_827D6A5                  @ 339
	.4byte gUnknown_82805D7                  @ 340
	.4byte gUnknown_8283B94                  @ 341
	.4byte gUnknown_8281A11                  @ 342
	.4byte gUnknown_827D6C3                  @ 343
	.4byte gUnknown_827D720                  @ 344
	.4byte gUnknown_828570A                  @ 345
	.4byte gUnknown_827D818                  @ 346
	.4byte gUnknown_827D83E                  @ 347
	.4byte gUnknown_827D8BC                  @ 348
	.4byte gUnknown_827D93F                  @ 349
	.4byte gUnknown_8284B7E                  @ 350
	.4byte gUnknown_827D9AE                  @ 351
	.4byte gUnknown_8285201                  @ 352
	.4byte gUnknown_82853FA                  @ 353
	.4byte gUnknown_82852F6                  @ 354
	.4byte gUnknown_8285C76                  @ 355

	.globl gUnknown_8277888
gUnknown_8277888: @ 0x8277888
	.4byte gUnknown_82862E1                  @ 000
	.4byte gUnknown_828630C                  @ 001
	.4byte gUnknown_8286315                  @ 002
	.4byte gUnknown_8286345                  @ 003
	.4byte gUnknown_828637A                  @ 004
	.4byte gUnknown_82863A6                  @ 005
	.4byte gUnknown_82863C0                  @ 006
	.4byte gUnknown_82863DB                  @ 007
	.4byte gUnknown_8286400                  @ 008

	.globl gUnknown_82778AC
gUnknown_82778AC: @ 0x82778AC
	.4byte gUnknown_8286425                  @ 000
	.4byte gUnknown_828645B                  @ 001
	.4byte gUnknown_8286464                  @ 002
	.4byte gUnknown_82864A1                  @ 003
	.4byte gUnknown_82864A9                  @ 004
	.4byte gUnknown_82864F1                  @ 005
	.4byte gUnknown_82864FC                  @ 006
	.4byte gUnknown_828668F                  @ 007
	.4byte gUnknown_8286703                  @ 008
	.4byte gUnknown_82867DF                  @ 009
	.4byte gUnknown_828682C                  @ 010
	.4byte gUnknown_8286875                  @ 011
	.4byte gUnknown_828687A                  @ 012
	.4byte gUnknown_828687F                  @ 013
	.4byte gUnknown_8286884                  @ 014
	.4byte gUnknown_8286892                  @ 015
	.4byte gUnknown_82868C3                  @ 016
	.4byte gUnknown_82868E8                  @ 017
	.4byte gUnknown_8286946                  @ 018
	.4byte gUnknown_82869A5                  @ 019
	.4byte gUnknown_8286A6A                  @ 020
	.4byte gUnknown_8286AAA                  @ 021
	.4byte gUnknown_8286AED                  @ 022

	.globl gUnknown_8277908
gUnknown_8277908: @ 0x8277908
	.incbin "build/data/event_scripts.bin", 0x9cd5c, 0x1c
gUnknown_8277924: @ 0x8277924
	.incbin "build/data/event_scripts.bin", 0x9cd78, 0x31
gUnknown_8277955: @ 0x8277955
	.incbin "build/data/event_scripts.bin", 0x9cda9, 0x53
gUnknown_82779A8: @ 0x82779A8
	.incbin "build/data/event_scripts.bin", 0x9cdfc, 0x131
gUnknown_8277AD9: @ 0x8277AD9
	.incbin "build/data/event_scripts.bin", 0x9cf2d, 0x12e
gUnknown_8277C07: @ 0x8277C07
	.incbin "build/data/event_scripts.bin", 0x9d05b, 0x12e
gUnknown_8277D35: @ 0x8277D35
	.incbin "build/data/event_scripts.bin", 0x9d189, 0xb9
gUnknown_8277DEE: @ 0x8277DEE
	.incbin "build/data/event_scripts.bin", 0x9d242, 0x94
gUnknown_8277E82: @ 0x8277E82
	.incbin "build/data/event_scripts.bin", 0x9d2d6, 0x3e
gUnknown_8277EC0: @ 0x8277EC0
	.incbin "build/data/event_scripts.bin", 0x9d314, 0x8d
gUnknown_8277F4D: @ 0x8277F4D
	.incbin "build/data/event_scripts.bin", 0x9d3a1, 0x58
gUnknown_8277FA5: @ 0x8277FA5
	.incbin "build/data/event_scripts.bin", 0x9d3f9, 0x4d
gUnknown_8277FF2: @ 0x8277FF2
	.incbin "build/data/event_scripts.bin", 0x9d446, 0xfa
gUnknown_82780EC: @ 0x82780EC
	.incbin "build/data/event_scripts.bin", 0x9d540, 0xc5
gUnknown_82781B1: @ 0x82781B1
	.incbin "build/data/event_scripts.bin", 0x9d605, 0xc5
gUnknown_8278276: @ 0x8278276
	.incbin "build/data/event_scripts.bin", 0x9d6ca, 0x90
gUnknown_8278306: @ 0x8278306
	.incbin "build/data/event_scripts.bin", 0x9d75a, 0x113
gUnknown_8278419: @ 0x8278419
	.incbin "build/data/event_scripts.bin", 0x9d86d, 0x55
gUnknown_827846E: @ 0x827846E
	.incbin "build/data/event_scripts.bin", 0x9d8c2, 0x73
gUnknown_82784E1: @ 0x82784E1
	.incbin "build/data/event_scripts.bin", 0x9d935, 0x12e
gUnknown_827860F: @ 0x827860F
	.incbin "build/data/event_scripts.bin", 0x9da63, 0x56
gUnknown_8278665: @ 0x8278665
	.incbin "build/data/event_scripts.bin", 0x9dab9, 0x74
gUnknown_82786D9: @ 0x82786D9
	.incbin "build/data/event_scripts.bin", 0x9db2d, 0xda
gUnknown_82787B3: @ 0x82787B3
	.incbin "build/data/event_scripts.bin", 0x9dc07, 0x9c
gUnknown_827884F: @ 0x827884F
	.incbin "build/data/event_scripts.bin", 0x9dca3, 0x78
gUnknown_82788C7: @ 0x82788C7
	.incbin "build/data/event_scripts.bin", 0x9dd1b, 0x61
gUnknown_8278928: @ 0x8278928
	.incbin "build/data/event_scripts.bin", 0x9dd7c, 0x6e
gUnknown_8278996: @ 0x8278996
	.incbin "build/data/event_scripts.bin", 0x9ddea, 0x1b6
gUnknown_8278B4C: @ 0x8278B4C
	.incbin "build/data/event_scripts.bin", 0x9dfa0, 0x6f
gUnknown_8278BBB: @ 0x8278BBB
	.incbin "build/data/event_scripts.bin", 0x9e00f, 0xfb
gUnknown_8278CB6: @ 0x8278CB6
	.incbin "build/data/event_scripts.bin", 0x9e10a, 0x47
gUnknown_8278CFD: @ 0x8278CFD
	.incbin "build/data/event_scripts.bin", 0x9e151, 0x19
gUnknown_8278D16: @ 0x8278D16
	.incbin "build/data/event_scripts.bin", 0x9e16a, 0x32
gUnknown_8278D48: @ 0x8278D48
	.incbin "build/data/event_scripts.bin", 0x9e19c, 0xe9
gUnknown_8278E31: @ 0x8278E31
	.incbin "build/data/event_scripts.bin", 0x9e285, 0xdb
gUnknown_8278F0C: @ 0x8278F0C
	.incbin "build/data/event_scripts.bin", 0x9e360, 0x71
gUnknown_8278F7D: @ 0x8278F7D
	.incbin "build/data/event_scripts.bin", 0x9e3d1, 0xb3
gUnknown_8279030: @ 0x8279030
	.incbin "build/data/event_scripts.bin", 0x9e484, 0x46
gUnknown_8279076: @ 0x8279076
	.incbin "build/data/event_scripts.bin", 0x9e4ca, 0x72
gUnknown_82790E8: @ 0x82790E8
	.incbin "build/data/event_scripts.bin", 0x9e53c, 0x13a
gUnknown_8279222: @ 0x8279222
	.incbin "build/data/event_scripts.bin", 0x9e676, 0xb4
gUnknown_82792D6: @ 0x82792D6
	.incbin "build/data/event_scripts.bin", 0x9e72a, 0xcf
gUnknown_82793A5: @ 0x82793A5
	.incbin "build/data/event_scripts.bin", 0x9e7f9, 0xf0
gUnknown_8279495: @ 0x8279495
	.incbin "build/data/event_scripts.bin", 0x9e8e9, 0x88
gUnknown_827951D: @ 0x827951D
	.incbin "build/data/event_scripts.bin", 0x9e971, 0x37
gUnknown_8279554: @ 0x8279554
	.incbin "build/data/event_scripts.bin", 0x9e9a8, 0x59
gUnknown_82795AD: @ 0x82795AD
	.incbin "build/data/event_scripts.bin", 0x9ea01, 0x254
gUnknown_8279801: @ 0x8279801
	.incbin "build/data/event_scripts.bin", 0x9ec55, 0x107
gUnknown_8279908: @ 0x8279908
	.incbin "build/data/event_scripts.bin", 0x9ed5c, 0x39
gUnknown_8279941: @ 0x8279941
	.incbin "build/data/event_scripts.bin", 0x9ed95, 0x1d
gUnknown_827995E: @ 0x827995E
	.incbin "build/data/event_scripts.bin", 0x9edb2, 0x5e
gUnknown_82799BC: @ 0x82799BC
	.incbin "build/data/event_scripts.bin", 0x9ee10, 0x2c7
gUnknown_8279C83: @ 0x8279C83
	.incbin "build/data/event_scripts.bin", 0x9f0d7, 0x42
gUnknown_8279CC5: @ 0x8279CC5
	.incbin "build/data/event_scripts.bin", 0x9f119, 0xa8
gUnknown_8279D6D: @ 0x8279D6D
	.incbin "build/data/event_scripts.bin", 0x9f1c1, 0x48
gUnknown_8279DB5: @ 0x8279DB5
	.incbin "build/data/event_scripts.bin", 0x9f209, 0x8c
gUnknown_8279E41: @ 0x8279E41
	.incbin "build/data/event_scripts.bin", 0x9f295, 0x53
gUnknown_8279E94: @ 0x8279E94
	.incbin "build/data/event_scripts.bin", 0x9f2e8, 0x19b
gUnknown_827A02F: @ 0x827A02F
	.incbin "build/data/event_scripts.bin", 0x9f483, 0x217
gUnknown_827A246: @ 0x827A246
	.incbin "build/data/event_scripts.bin", 0x9f69a, 0xf9
gUnknown_827A33F: @ 0x827A33F
	.incbin "build/data/event_scripts.bin", 0x9f793, 0x36
gUnknown_827A375: @ 0x827A375
	.incbin "build/data/event_scripts.bin", 0x9f7c9, 0xa8
gUnknown_827A41D: @ 0x827A41D
	.incbin "build/data/event_scripts.bin", 0x9f871, 0x53
gUnknown_827A470: @ 0x827A470
	.incbin "build/data/event_scripts.bin", 0x9f8c4, 0x36
gUnknown_827A4A6: @ 0x827A4A6
	.incbin "build/data/event_scripts.bin", 0x9f8fa, 0x45
gUnknown_827A4EB: @ 0x827A4EB
	.incbin "build/data/event_scripts.bin", 0x9f93f, 0x8c
gUnknown_827A577: @ 0x827A577
	.incbin "build/data/event_scripts.bin", 0x9f9cb, 0x141
gUnknown_827A6B8: @ 0x827A6B8
	.incbin "build/data/event_scripts.bin", 0x9fb0c, 0x47
gUnknown_827A6FF: @ 0x827A6FF
	.incbin "build/data/event_scripts.bin", 0x9fb53, 0xdd
gUnknown_827A7DC: @ 0x827A7DC
	.incbin "build/data/event_scripts.bin", 0x9fc30, 0xc0
gUnknown_827A89C: @ 0x827A89C
	.incbin "build/data/event_scripts.bin", 0x9fcf0, 0xf9
gUnknown_827A995: @ 0x827A995
	.incbin "build/data/event_scripts.bin", 0x9fde9, 0x115
gUnknown_827AAAA: @ 0x827AAAA
	.incbin "build/data/event_scripts.bin", 0x9fefe, 0x11c
gUnknown_827ABC6: @ 0x827ABC6
	.incbin "build/data/event_scripts.bin", 0xa001a, 0x83
gUnknown_827AC49: @ 0x827AC49
	.incbin "build/data/event_scripts.bin", 0xa009d, 0x5d
gUnknown_827ACA6: @ 0x827ACA6
	.incbin "build/data/event_scripts.bin", 0xa00fa, 0x6d
gUnknown_827AD13: @ 0x827AD13
	.incbin "build/data/event_scripts.bin", 0xa0167, 0x7d
gUnknown_827AD90: @ 0x827AD90
	.incbin "build/data/event_scripts.bin", 0xa01e4, 0x17d
gUnknown_827AF0D: @ 0x827AF0D
	.incbin "build/data/event_scripts.bin", 0xa0361, 0x7f
gUnknown_827AF8C: @ 0x827AF8C
	.incbin "build/data/event_scripts.bin", 0xa03e0, 0xd4
gUnknown_827B060: @ 0x827B060
	.incbin "build/data/event_scripts.bin", 0xa04b4, 0x5d
gUnknown_827B0BD: @ 0x827B0BD
	.incbin "build/data/event_scripts.bin", 0xa0511, 0x4d
gUnknown_827B10A: @ 0x827B10A
	.incbin "build/data/event_scripts.bin", 0xa055e, 0x123
gUnknown_827B22D: @ 0x827B22D
	.incbin "build/data/event_scripts.bin", 0xa0681, 0x11c
gUnknown_827B349: @ 0x827B349
	.incbin "build/data/event_scripts.bin", 0xa079d, 0x1d
gUnknown_827B366: @ 0x827B366
	.incbin "build/data/event_scripts.bin", 0xa07ba, 0x4a
gUnknown_827B3B0: @ 0x827B3B0
	.incbin "build/data/event_scripts.bin", 0xa0804, 0x58
gUnknown_827B408: @ 0x827B408
	.incbin "build/data/event_scripts.bin", 0xa085c, 0x76
gUnknown_827B47E: @ 0x827B47E
	.incbin "build/data/event_scripts.bin", 0xa08d2, 0x19
gUnknown_827B497: @ 0x827B497
	.incbin "build/data/event_scripts.bin", 0xa08eb, 0x47
gUnknown_827B4DE: @ 0x827B4DE
	.incbin "build/data/event_scripts.bin", 0xa0932, 0x13
gUnknown_827B4F1: @ 0x827B4F1
	.incbin "build/data/event_scripts.bin", 0xa0945, 0x2a
gUnknown_827B51B: @ 0x827B51B
	.incbin "build/data/event_scripts.bin", 0xa096f, 0xc6
gUnknown_827B5E1: @ 0x827B5E1
	.incbin "build/data/event_scripts.bin", 0xa0a35, 0x24
gUnknown_827B605: @ 0x827B605
	.incbin "build/data/event_scripts.bin", 0xa0a59, 0x51
gUnknown_827B656: @ 0x827B656
	.incbin "build/data/event_scripts.bin", 0xa0aaa, 0x69
gUnknown_827B6BF: @ 0x827B6BF
	.incbin "build/data/event_scripts.bin", 0xa0b13, 0x48
gUnknown_827B707: @ 0x827B707
	.incbin "build/data/event_scripts.bin", 0xa0b5b, 0x198
gUnknown_827B89F: @ 0x827B89F
	.incbin "build/data/event_scripts.bin", 0xa0cf3, 0xd
gUnknown_827B8AC: @ 0x827B8AC
	.incbin "build/data/event_scripts.bin", 0xa0d00, 0x15
gUnknown_827B8C1: @ 0x827B8C1
	.incbin "build/data/event_scripts.bin", 0xa0d15, 0x19
gUnknown_827B8DA: @ 0x827B8DA
	.incbin "build/data/event_scripts.bin", 0xa0d2e, 0xc
gUnknown_827B8E6: @ 0x827B8E6
	.incbin "build/data/event_scripts.bin", 0xa0d3a, 0x81
gUnknown_827B967: @ 0x827B967
	.incbin "build/data/event_scripts.bin", 0xa0dbb, 0x3a
gUnknown_827B9A1: @ 0x827B9A1
	.incbin "build/data/event_scripts.bin", 0xa0df5, 0x66
gUnknown_827BA07: @ 0x827BA07
	.incbin "build/data/event_scripts.bin", 0xa0e5b, 0x28
gUnknown_827BA2F: @ 0x827BA2F
	.incbin "build/data/event_scripts.bin", 0xa0e83, 0x56
gUnknown_827BA85: @ 0x827BA85
	.incbin "build/data/event_scripts.bin", 0xa0ed9, 0x3d
gUnknown_827BAC2: @ 0x827BAC2
	.incbin "build/data/event_scripts.bin", 0xa0f16, 0x2f
gUnknown_827BAF1: @ 0x827BAF1
	.incbin "build/data/event_scripts.bin", 0xa0f45, 0x88
gUnknown_827BB79: @ 0x827BB79
	.incbin "build/data/event_scripts.bin", 0xa0fcd, 0x3f
gUnknown_827BBB8: @ 0x827BBB8
	.incbin "build/data/event_scripts.bin", 0xa100c, 0x5b
gUnknown_827BC13: @ 0x827BC13
	.incbin "build/data/event_scripts.bin", 0xa1067, 0x94
gUnknown_827BCA7: @ 0x827BCA7
	.incbin "build/data/event_scripts.bin", 0xa10fb, 0x43
gUnknown_827BCEA: @ 0x827BCEA
	.incbin "build/data/event_scripts.bin", 0xa113e, 0x41
gUnknown_827BD2B: @ 0x827BD2B
	.incbin "build/data/event_scripts.bin", 0xa117f, 0x87
gUnknown_827BDB2: @ 0x827BDB2
	.incbin "build/data/event_scripts.bin", 0xa1206, 0x48
gUnknown_827BDFA: @ 0x827BDFA
	.incbin "build/data/event_scripts.bin", 0xa124e, 0x42
gUnknown_827BE3C: @ 0x827BE3C
	.incbin "build/data/event_scripts.bin", 0xa1290, 0x91
gUnknown_827BECD: @ 0x827BECD
	.incbin "build/data/event_scripts.bin", 0xa1321, 0x6d
gUnknown_827BF3A: @ 0x827BF3A
	.incbin "build/data/event_scripts.bin", 0xa138e, 0x90
gUnknown_827BFCA: @ 0x827BFCA
	.incbin "build/data/event_scripts.bin", 0xa141e, 0xbe
gUnknown_827C088: @ 0x827C088
	.incbin "build/data/event_scripts.bin", 0xa14dc, 0xca
gUnknown_827C152: @ 0x827C152
	.incbin "build/data/event_scripts.bin", 0xa15a6, 0xb0
gUnknown_827C202: @ 0x827C202
	.incbin "build/data/event_scripts.bin", 0xa1656, 0x38
gUnknown_827C23A: @ 0x827C23A
	.incbin "build/data/event_scripts.bin", 0xa168e, 0x44
gUnknown_827C27E: @ 0x827C27E
	.incbin "build/data/event_scripts.bin", 0xa16d2, 0x44
gUnknown_827C2C2: @ 0x827C2C2
	.incbin "build/data/event_scripts.bin", 0xa1716, 0x20
gUnknown_827C2E2: @ 0x827C2E2
	.incbin "build/data/event_scripts.bin", 0xa1736, 0x5b
gUnknown_827C33D: @ 0x827C33D
	.incbin "build/data/event_scripts.bin", 0xa1791, 0x1f
gUnknown_827C35C: @ 0x827C35C
	.incbin "build/data/event_scripts.bin", 0xa17b0, 0x9b
gUnknown_827C3F7: @ 0x827C3F7
	.incbin "build/data/event_scripts.bin", 0xa184b, 0x54
gUnknown_827C44B: @ 0x827C44B
	.incbin "build/data/event_scripts.bin", 0xa189f, 0x73
gUnknown_827C4BE: @ 0x827C4BE
	.incbin "build/data/event_scripts.bin", 0xa1912, 0x71
gUnknown_827C52F: @ 0x827C52F
	.incbin "build/data/event_scripts.bin", 0xa1983, 0xbb
gUnknown_827C5EA: @ 0x827C5EA
	.incbin "build/data/event_scripts.bin", 0xa1a3e, 0x34
gUnknown_827C61E: @ 0x827C61E
	.incbin "build/data/event_scripts.bin", 0xa1a72, 0x1c1
gUnknown_827C7DF: @ 0x827C7DF
	.incbin "build/data/event_scripts.bin", 0xa1c33, 0x43
gUnknown_827C822: @ 0x827C822
	.incbin "build/data/event_scripts.bin", 0xa1c76, 0x75
gUnknown_827C897: @ 0x827C897
	.incbin "build/data/event_scripts.bin", 0xa1ceb, 0xcd
gUnknown_827C964: @ 0x827C964
	.incbin "build/data/event_scripts.bin", 0xa1db8, 0x4b
gUnknown_827C9AF: @ 0x827C9AF
	.incbin "build/data/event_scripts.bin", 0xa1e03, 0x43
gUnknown_827C9F2: @ 0x827C9F2
	.incbin "build/data/event_scripts.bin", 0xa1e46, 0x28
gUnknown_827CA1A: @ 0x827CA1A
	.incbin "build/data/event_scripts.bin", 0xa1e6e, 0x46
gUnknown_827CA60: @ 0x827CA60
	.incbin "build/data/event_scripts.bin", 0xa1eb4, 0x43
gUnknown_827CAA3: @ 0x827CAA3
	.incbin "build/data/event_scripts.bin", 0xa1ef7, 0x117
gUnknown_827CBBA: @ 0x827CBBA
	.incbin "build/data/event_scripts.bin", 0xa200e, 0x8f
gUnknown_827CC49: @ 0x827CC49
	.incbin "build/data/event_scripts.bin", 0xa209d, 0xd0
gUnknown_827CD19: @ 0x827CD19
	.incbin "build/data/event_scripts.bin", 0xa216d, 0x6b
gUnknown_827CD84: @ 0x827CD84
	.incbin "build/data/event_scripts.bin", 0xa21d8, 0x137
gUnknown_827CEBB: @ 0x827CEBB
	.incbin "build/data/event_scripts.bin", 0xa230f, 0x1b0
gUnknown_827D06B: @ 0x827D06B
	.incbin "build/data/event_scripts.bin", 0xa24bf, 0x18
gUnknown_827D083: @ 0x827D083
	.incbin "build/data/event_scripts.bin", 0xa24d7, 0x6f
gUnknown_827D0F2: @ 0x827D0F2
	.incbin "build/data/event_scripts.bin", 0xa2546, 0x162
gUnknown_827D254: @ 0x827D254
	.incbin "build/data/event_scripts.bin", 0xa26a8, 0x90
gUnknown_827D2E4: @ 0x827D2E4
	.incbin "build/data/event_scripts.bin", 0xa2738, 0x62
gUnknown_827D346: @ 0x827D346
	.incbin "build/data/event_scripts.bin", 0xa279a, 0x4a
gUnknown_827D390: @ 0x827D390
	.incbin "build/data/event_scripts.bin", 0xa27e4, 0xf3
gUnknown_827D483: @ 0x827D483
	.incbin "build/data/event_scripts.bin", 0xa28d7, 0x6c
gUnknown_827D4EF: @ 0x827D4EF
	.incbin "build/data/event_scripts.bin", 0xa2943, 0x2e
gUnknown_827D51D: @ 0x827D51D
	.incbin "build/data/event_scripts.bin", 0xa2971, 0x5b
gUnknown_827D578: @ 0x827D578
	.incbin "build/data/event_scripts.bin", 0xa29cc, 0x68
gUnknown_827D5E0: @ 0x827D5E0
	.incbin "build/data/event_scripts.bin", 0xa2a34, 0x6a
gUnknown_827D64A: @ 0x827D64A
	.incbin "build/data/event_scripts.bin", 0xa2a9e, 0x2a
gUnknown_827D674: @ 0x827D674
	.incbin "build/data/event_scripts.bin", 0xa2ac8, 0xf
gUnknown_827D683: @ 0x827D683
	.incbin "build/data/event_scripts.bin", 0xa2ad7, 0x22
gUnknown_827D6A5: @ 0x827D6A5
	.incbin "build/data/event_scripts.bin", 0xa2af9, 0x1e
gUnknown_827D6C3: @ 0x827D6C3
	.incbin "build/data/event_scripts.bin", 0xa2b17, 0x5d
gUnknown_827D720: @ 0x827D720
	.incbin "build/data/event_scripts.bin", 0xa2b74, 0xf8
gUnknown_827D818: @ 0x827D818
	.incbin "build/data/event_scripts.bin", 0xa2c6c, 0x26
gUnknown_827D83E: @ 0x827D83E
	.incbin "build/data/event_scripts.bin", 0xa2c92, 0x7e
gUnknown_827D8BC: @ 0x827D8BC
	.incbin "build/data/event_scripts.bin", 0xa2d10, 0x83
gUnknown_827D93F: @ 0x827D93F
	.incbin "build/data/event_scripts.bin", 0xa2d93, 0x6f
gUnknown_827D9AE: @ 0x827D9AE
	.incbin "build/data/event_scripts.bin", 0xa2e02, 0xa2
gUnknown_827DA50: @ 0x827DA50
	.incbin "build/data/event_scripts.bin", 0xa2ea4, 0x15
gUnknown_827DA65: @ 0x827DA65
	.incbin "build/data/event_scripts.bin", 0xa2eb9, 0xe8
gUnknown_827DB4D: @ 0x827DB4D
	.incbin "build/data/event_scripts.bin", 0xa2fa1, 0x138
gUnknown_827DC85: @ 0x827DC85
	.incbin "build/data/event_scripts.bin", 0xa30d9, 0xeb
gUnknown_827DD70: @ 0x827DD70
	.incbin "build/data/event_scripts.bin", 0xa31c4, 0x40
gUnknown_827DDB0: @ 0x827DDB0
	.incbin "build/data/event_scripts.bin", 0xa3204, 0x61
gUnknown_827DE11: @ 0x827DE11
	.incbin "build/data/event_scripts.bin", 0xa3265, 0x63
gUnknown_827DE74: @ 0x827DE74
	.incbin "build/data/event_scripts.bin", 0xa32c8, 0x4d
gUnknown_827DEC1: @ 0x827DEC1
	.incbin "build/data/event_scripts.bin", 0xa3315, 0x15a
gUnknown_827E01B: @ 0x827E01B
	.incbin "build/data/event_scripts.bin", 0xa346f, 0xc9
gUnknown_827E0E4: @ 0x827E0E4
	.incbin "build/data/event_scripts.bin", 0xa3538, 0x1e7
gUnknown_827E2CB: @ 0x827E2CB
	.incbin "build/data/event_scripts.bin", 0xa371f, 0x32
gUnknown_827E2FD: @ 0x827E2FD
	.incbin "build/data/event_scripts.bin", 0xa3751, 0x114
gUnknown_827E411: @ 0x827E411
	.incbin "build/data/event_scripts.bin", 0xa3865, 0x97
gUnknown_827E4A8: @ 0x827E4A8
	.incbin "build/data/event_scripts.bin", 0xa38fc, 0x41
gUnknown_827E4E9: @ 0x827E4E9
	.incbin "build/data/event_scripts.bin", 0xa393d, 0x90
gUnknown_827E579: @ 0x827E579
	.incbin "build/data/event_scripts.bin", 0xa39cd, 0x8c
gUnknown_827E605: @ 0x827E605
	.incbin "build/data/event_scripts.bin", 0xa3a59, 0x26
gUnknown_827E62B: @ 0x827E62B
	.incbin "build/data/event_scripts.bin", 0xa3a7f, 0x53
gUnknown_827E67E: @ 0x827E67E
	.incbin "build/data/event_scripts.bin", 0xa3ad2, 0x1d
gUnknown_827E69B: @ 0x827E69B
	.incbin "build/data/event_scripts.bin", 0xa3aef, 0xd6
gUnknown_827E771: @ 0x827E771
	.incbin "build/data/event_scripts.bin", 0xa3bc5, 0x7b
gUnknown_827E7EC: @ 0x827E7EC
	.incbin "build/data/event_scripts.bin", 0xa3c40, 0x87
gUnknown_827E873: @ 0x827E873
	.incbin "build/data/event_scripts.bin", 0xa3cc7, 0xa8
gUnknown_827E91B: @ 0x827E91B
	.incbin "build/data/event_scripts.bin", 0xa3d6f, 0x9e
gUnknown_827E9B9: @ 0x827E9B9
	.incbin "build/data/event_scripts.bin", 0xa3e0d, 0xdd
gUnknown_827EA96: @ 0x827EA96
	.incbin "build/data/event_scripts.bin", 0xa3eea, 0x4b
gUnknown_827EAE1: @ 0x827EAE1
	.incbin "build/data/event_scripts.bin", 0xa3f35, 0x5e
gUnknown_827EB3F: @ 0x827EB3F
	.incbin "build/data/event_scripts.bin", 0xa3f93, 0xb0
gUnknown_827EBEF: @ 0x827EBEF
	.incbin "build/data/event_scripts.bin", 0xa4043, 0x5d
gUnknown_827EC4C: @ 0x827EC4C
	.incbin "build/data/event_scripts.bin", 0xa40a0, 0x137
gUnknown_827ED83: @ 0x827ED83
	.incbin "build/data/event_scripts.bin", 0xa41d7, 0xd
gUnknown_827ED90: @ 0x827ED90
	.incbin "build/data/event_scripts.bin", 0xa41e4, 0xd4
gUnknown_827EE64: @ 0x827EE64
	.incbin "build/data/event_scripts.bin", 0xa42b8, 0x255
gUnknown_827F0B9: @ 0x827F0B9
	.incbin "build/data/event_scripts.bin", 0xa450d, 0x18c
gUnknown_827F245: @ 0x827F245
	.incbin "build/data/event_scripts.bin", 0xa4699, 0xfa
gUnknown_827F33F: @ 0x827F33F
	.incbin "build/data/event_scripts.bin", 0xa4793, 0xff
gUnknown_827F43E: @ 0x827F43E
	.incbin "build/data/event_scripts.bin", 0xa4892, 0xe8
gUnknown_827F526: @ 0x827F526
	.incbin "build/data/event_scripts.bin", 0xa497a, 0x118
gUnknown_827F63E: @ 0x827F63E
	.incbin "build/data/event_scripts.bin", 0xa4a92, 0x190
gUnknown_827F7CE: @ 0x827F7CE
	.incbin "build/data/event_scripts.bin", 0xa4c22, 0x208
gUnknown_827F9D6: @ 0x827F9D6
	.incbin "build/data/event_scripts.bin", 0xa4e2a, 0x82
gUnknown_827FA58: @ 0x827FA58
	.incbin "build/data/event_scripts.bin", 0xa4eac, 0x2a
gUnknown_827FA82: @ 0x827FA82
	.incbin "build/data/event_scripts.bin", 0xa4ed6, 0x6f
gUnknown_827FAF1: @ 0x827FAF1
	.incbin "build/data/event_scripts.bin", 0xa4f45, 0x42
gUnknown_827FB33: @ 0x827FB33
	.incbin "build/data/event_scripts.bin", 0xa4f87, 0x126
gUnknown_827FC59: @ 0x827FC59
	.incbin "build/data/event_scripts.bin", 0xa50ad, 0xfa
gUnknown_827FD53: @ 0x827FD53
	.incbin "build/data/event_scripts.bin", 0xa51a7, 0x54
gUnknown_827FDA7: @ 0x827FDA7
	.incbin "build/data/event_scripts.bin", 0xa51fb, 0x62
gUnknown_827FE09: @ 0x827FE09
	.incbin "build/data/event_scripts.bin", 0xa525d, 0x4b
gUnknown_827FE54: @ 0x827FE54
	.incbin "build/data/event_scripts.bin", 0xa52a8, 0x57
gUnknown_827FEAB: @ 0x827FEAB
	.incbin "build/data/event_scripts.bin", 0xa52ff, 0xed
gUnknown_827FF98: @ 0x827FF98
	.incbin "build/data/event_scripts.bin", 0xa53ec, 0x51
gUnknown_827FFE9: @ 0x827FFE9
	.incbin "build/data/event_scripts.bin", 0xa543d, 0x9d
gUnknown_8280086: @ 0x8280086
	.incbin "build/data/event_scripts.bin", 0xa54da, 0x27
gUnknown_82800AD: @ 0x82800AD
	.incbin "build/data/event_scripts.bin", 0xa5501, 0x11d
gUnknown_82801CA: @ 0x82801CA
	.incbin "build/data/event_scripts.bin", 0xa561e, 0x8d
gUnknown_8280257: @ 0x8280257
	.incbin "build/data/event_scripts.bin", 0xa56ab, 0xfa
gUnknown_8280351: @ 0x8280351
	.incbin "build/data/event_scripts.bin", 0xa57a5, 0x14
gUnknown_8280365: @ 0x8280365
	.incbin "build/data/event_scripts.bin", 0xa57b9, 0x9d
gUnknown_8280402: @ 0x8280402
	.incbin "build/data/event_scripts.bin", 0xa5856, 0x88
gUnknown_828048A: @ 0x828048A
	.incbin "build/data/event_scripts.bin", 0xa58de, 0xe3
gUnknown_828056D: @ 0x828056D
	.incbin "build/data/event_scripts.bin", 0xa59c1, 0x6a
gUnknown_82805D7: @ 0x82805D7
	.incbin "build/data/event_scripts.bin", 0xa5a2b, 0x63
gUnknown_828063A: @ 0x828063A
	.incbin "build/data/event_scripts.bin", 0xa5a8e, 0x52
gUnknown_828068C: @ 0x828068C
	.incbin "build/data/event_scripts.bin", 0xa5ae0, 0x69
gUnknown_82806F5: @ 0x82806F5
	.incbin "build/data/event_scripts.bin", 0xa5b49, 0x5d
gUnknown_8280752: @ 0x8280752
	.incbin "build/data/event_scripts.bin", 0xa5ba6, 0x96
gUnknown_82807E8: @ 0x82807E8
	.incbin "build/data/event_scripts.bin", 0xa5c3c, 0x32
gUnknown_828081A: @ 0x828081A
	.incbin "build/data/event_scripts.bin", 0xa5c6e, 0xc7
gUnknown_82808E1: @ 0x82808E1
	.incbin "build/data/event_scripts.bin", 0xa5d35, 0xc8
gUnknown_82809A9: @ 0x82809A9
	.incbin "build/data/event_scripts.bin", 0xa5dfd, 0xcf
gUnknown_8280A78: @ 0x8280A78
	.incbin "build/data/event_scripts.bin", 0xa5ecc, 0x7b
gUnknown_8280AF3: @ 0x8280AF3
	.incbin "build/data/event_scripts.bin", 0xa5f47, 0xf8
gUnknown_8280BEB: @ 0x8280BEB
	.incbin "build/data/event_scripts.bin", 0xa603f, 0xa3
gUnknown_8280C8E: @ 0x8280C8E
	.incbin "build/data/event_scripts.bin", 0xa60e2, 0x56
gUnknown_8280CE4: @ 0x8280CE4
	.incbin "build/data/event_scripts.bin", 0xa6138, 0x5a
gUnknown_8280D3E: @ 0x8280D3E
	.incbin "build/data/event_scripts.bin", 0xa6192, 0x65
gUnknown_8280DA3: @ 0x8280DA3
	.incbin "build/data/event_scripts.bin", 0xa61f7, 0x138
gUnknown_8280EDB: @ 0x8280EDB
	.incbin "build/data/event_scripts.bin", 0xa632f, 0x107
gUnknown_8280FE2: @ 0x8280FE2
	.incbin "build/data/event_scripts.bin", 0xa6436, 0x128
gUnknown_828110A: @ 0x828110A
	.incbin "build/data/event_scripts.bin", 0xa655e, 0x66
gUnknown_8281170: @ 0x8281170
	.incbin "build/data/event_scripts.bin", 0xa65c4, 0x61
gUnknown_82811D1: @ 0x82811D1
	.incbin "build/data/event_scripts.bin", 0xa6625, 0x33
gUnknown_8281204: @ 0x8281204
	.incbin "build/data/event_scripts.bin", 0xa6658, 0x113
gUnknown_8281317: @ 0x8281317
	.incbin "build/data/event_scripts.bin", 0xa676b, 0x57
gUnknown_828136E: @ 0x828136E
	.incbin "build/data/event_scripts.bin", 0xa67c2, 0x203
gUnknown_8281571: @ 0x8281571
	.incbin "build/data/event_scripts.bin", 0xa69c5, 0xde
gUnknown_828164F: @ 0x828164F
	.incbin "build/data/event_scripts.bin", 0xa6aa3, 0x3a
gUnknown_8281689: @ 0x8281689
	.incbin "build/data/event_scripts.bin", 0xa6add, 0x16
gUnknown_828169F: @ 0x828169F
	.incbin "build/data/event_scripts.bin", 0xa6af3, 0x9a
gUnknown_8281739: @ 0x8281739
	.incbin "build/data/event_scripts.bin", 0xa6b8d, 0x60
gUnknown_8281799: @ 0x8281799
	.incbin "build/data/event_scripts.bin", 0xa6bed, 0x86
gUnknown_828181F: @ 0x828181F
	.incbin "build/data/event_scripts.bin", 0xa6c73, 0xe5
gUnknown_8281904: @ 0x8281904
	.incbin "build/data/event_scripts.bin", 0xa6d58, 0xaf
gUnknown_82819B3: @ 0x82819B3
	.incbin "build/data/event_scripts.bin", 0xa6e07, 0x5e
gUnknown_8281A11: @ 0x8281A11
	.incbin "build/data/event_scripts.bin", 0xa6e65, 0x66
gUnknown_8281A77: @ 0x8281A77
	.incbin "build/data/event_scripts.bin", 0xa6ecb, 0x93
gUnknown_8281B0A: @ 0x8281B0A
	.incbin "build/data/event_scripts.bin", 0xa6f5e, 0x48
gUnknown_8281B52: @ 0x8281B52
	.incbin "build/data/event_scripts.bin", 0xa6fa6, 0x9a
gUnknown_8281BEC: @ 0x8281BEC
	.incbin "build/data/event_scripts.bin", 0xa7040, 0x43
gUnknown_8281C2F: @ 0x8281C2F
	.incbin "build/data/event_scripts.bin", 0xa7083, 0x27
gUnknown_8281C56: @ 0x8281C56
	.incbin "build/data/event_scripts.bin", 0xa70aa, 0x40
gUnknown_8281C96: @ 0x8281C96
	.incbin "build/data/event_scripts.bin", 0xa70ea, 0xff
gUnknown_8281D95: @ 0x8281D95
	.incbin "build/data/event_scripts.bin", 0xa71e9, 0xd2
gUnknown_8281E67: @ 0x8281E67
	.incbin "build/data/event_scripts.bin", 0xa72bb, 0xa1
gUnknown_8281F08: @ 0x8281F08
	.incbin "build/data/event_scripts.bin", 0xa735c, 0xe6
gUnknown_8281FEE: @ 0x8281FEE
	.incbin "build/data/event_scripts.bin", 0xa7442, 0x2e
gUnknown_828201C: @ 0x828201C
	.incbin "build/data/event_scripts.bin", 0xa7470, 0xaa
gUnknown_82820C6: @ 0x82820C6
	.incbin "build/data/event_scripts.bin", 0xa751a, 0x4b
gUnknown_8282111: @ 0x8282111
	.incbin "build/data/event_scripts.bin", 0xa7565, 0x68
gUnknown_8282179: @ 0x8282179
	.incbin "build/data/event_scripts.bin", 0xa75cd, 0xc0
gUnknown_8282239: @ 0x8282239
	.incbin "build/data/event_scripts.bin", 0xa768d, 0x82
gUnknown_82822BB: @ 0x82822BB
	.incbin "build/data/event_scripts.bin", 0xa770f, 0x1fa
gUnknown_82824B5: @ 0x82824B5
	.incbin "build/data/event_scripts.bin", 0xa7909, 0x3b
gUnknown_82824F0: @ 0x82824F0
	.incbin "build/data/event_scripts.bin", 0xa7944, 0x63
gUnknown_8282553: @ 0x8282553
	.incbin "build/data/event_scripts.bin", 0xa79a7, 0x69
gUnknown_82825BC: @ 0x82825BC
	.incbin "build/data/event_scripts.bin", 0xa7a10, 0x47
gUnknown_8282603: @ 0x8282603
	.incbin "build/data/event_scripts.bin", 0xa7a57, 0x64
gUnknown_8282667: @ 0x8282667
	.incbin "build/data/event_scripts.bin", 0xa7abb, 0xb1
gUnknown_8282718: @ 0x8282718
	.incbin "build/data/event_scripts.bin", 0xa7b6c, 0x157
gUnknown_828286F: @ 0x828286F
	.incbin "build/data/event_scripts.bin", 0xa7cc3, 0x22
gUnknown_8282891: @ 0x8282891
	.incbin "build/data/event_scripts.bin", 0xa7ce5, 0x169
gUnknown_82829FA: @ 0x82829FA
	.incbin "build/data/event_scripts.bin", 0xa7e4e, 0xbb
gUnknown_8282AB5: @ 0x8282AB5
	.incbin "build/data/event_scripts.bin", 0xa7f09, 0x67
gUnknown_8282B1C: @ 0x8282B1C
	.incbin "build/data/event_scripts.bin", 0xa7f70, 0x174
gUnknown_8282C90: @ 0x8282C90
	.incbin "build/data/event_scripts.bin", 0xa80e4, 0xbe
gUnknown_8282D4E: @ 0x8282D4E
	.incbin "build/data/event_scripts.bin", 0xa81a2, 0xa7
gUnknown_8282DF5: @ 0x8282DF5
	.incbin "build/data/event_scripts.bin", 0xa8249, 0x7e
gUnknown_8282E73: @ 0x8282E73
	.incbin "build/data/event_scripts.bin", 0xa82c7, 0x48
gUnknown_8282EBB: @ 0x8282EBB
	.incbin "build/data/event_scripts.bin", 0xa830f, 0xb7
gUnknown_8282F72: @ 0x8282F72
	.incbin "build/data/event_scripts.bin", 0xa83c6, 0x143
gUnknown_82830B5: @ 0x82830B5
	.incbin "build/data/event_scripts.bin", 0xa8509, 0xac
gUnknown_8283161: @ 0x8283161
	.incbin "build/data/event_scripts.bin", 0xa85b5, 0x18
gUnknown_8283179: @ 0x8283179
	.incbin "build/data/event_scripts.bin", 0xa85cd, 0x94
gUnknown_828320D: @ 0x828320D
	.incbin "build/data/event_scripts.bin", 0xa8661, 0xea
gUnknown_82832F7: @ 0x82832F7
	.incbin "build/data/event_scripts.bin", 0xa874b, 0x142
gUnknown_8283439: @ 0x8283439
	.incbin "build/data/event_scripts.bin", 0xa888d, 0xfc
gUnknown_8283535: @ 0x8283535
	.incbin "build/data/event_scripts.bin", 0xa8989, 0x5d
gUnknown_8283592: @ 0x8283592
	.incbin "build/data/event_scripts.bin", 0xa89e6, 0x43
gUnknown_82835D5: @ 0x82835D5
	.incbin "build/data/event_scripts.bin", 0xa8a29, 0x88
gUnknown_828365D: @ 0x828365D
	.incbin "build/data/event_scripts.bin", 0xa8ab1, 0x94
gUnknown_82836F1: @ 0x82836F1
	.incbin "build/data/event_scripts.bin", 0xa8b45, 0xd8
gUnknown_82837C9: @ 0x82837C9
	.incbin "build/data/event_scripts.bin", 0xa8c1d, 0x25
gUnknown_82837EE: @ 0x82837EE
	.incbin "build/data/event_scripts.bin", 0xa8c42, 0x95
gUnknown_8283883: @ 0x8283883
	.incbin "build/data/event_scripts.bin", 0xa8cd7, 0x12
gUnknown_8283895: @ 0x8283895
	.incbin "build/data/event_scripts.bin", 0xa8ce9, 0x96
gUnknown_828392B: @ 0x828392B
	.incbin "build/data/event_scripts.bin", 0xa8d7f, 0x269
gUnknown_8283B94: @ 0x8283B94
	.incbin "build/data/event_scripts.bin", 0xa8fe8, 0x9d
gUnknown_8283C31: @ 0x8283C31
	.incbin "build/data/event_scripts.bin", 0xa9085, 0x87
gUnknown_8283CB8: @ 0x8283CB8
	.incbin "build/data/event_scripts.bin", 0xa910c, 0x97
gUnknown_8283D4F: @ 0x8283D4F
	.incbin "build/data/event_scripts.bin", 0xa91a3, 0x3f
gUnknown_8283D8E: @ 0x8283D8E
	.incbin "build/data/event_scripts.bin", 0xa91e2, 0xc
gUnknown_8283D9A: @ 0x8283D9A
	.incbin "build/data/event_scripts.bin", 0xa91ee, 0x1a4
gUnknown_8283F3E: @ 0x8283F3E
	.incbin "build/data/event_scripts.bin", 0xa9392, 0x50
gUnknown_8283F8E: @ 0x8283F8E
	.incbin "build/data/event_scripts.bin", 0xa93e2, 0xc7
gUnknown_8284055: @ 0x8284055
	.incbin "build/data/event_scripts.bin", 0xa94a9, 0x48f
gUnknown_82844E4: @ 0x82844E4
	.incbin "build/data/event_scripts.bin", 0xa9938, 0x85
gUnknown_8284569: @ 0x8284569
	.incbin "build/data/event_scripts.bin", 0xa99bd, 0x242
gUnknown_82847AB: @ 0x82847AB
	.incbin "build/data/event_scripts.bin", 0xa9bff, 0xe7
gUnknown_8284892: @ 0x8284892
	.incbin "build/data/event_scripts.bin", 0xa9ce6, 0x218
gUnknown_8284AAA: @ 0x8284AAA
	.incbin "build/data/event_scripts.bin", 0xa9efe, 0x1a
gUnknown_8284AC4: @ 0x8284AC4
	.incbin "build/data/event_scripts.bin", 0xa9f18, 0xba
gUnknown_8284B7E: @ 0x8284B7E
	.incbin "build/data/event_scripts.bin", 0xa9fd2, 0x9d
gUnknown_8284C1B: @ 0x8284C1B
	.incbin "build/data/event_scripts.bin", 0xaa06f, 0x2f2
gUnknown_8284F0D: @ 0x8284F0D
	.incbin "build/data/event_scripts.bin", 0xaa361, 0x132
gUnknown_828503F: @ 0x828503F
	.incbin "build/data/event_scripts.bin", 0xaa493, 0x48
gUnknown_8285087: @ 0x8285087
	.incbin "build/data/event_scripts.bin", 0xaa4db, 0x15d
gUnknown_82851E4: @ 0x82851E4
	.incbin "build/data/event_scripts.bin", 0xaa638, 0x1d
gUnknown_8285201: @ 0x8285201
	.incbin "build/data/event_scripts.bin", 0xaa655, 0xf5
gUnknown_82852F6: @ 0x82852F6
	.incbin "build/data/event_scripts.bin", 0xaa74a, 0x74
gUnknown_828536A: @ 0x828536A
	.incbin "build/data/event_scripts.bin", 0xaa7be, 0x90
gUnknown_82853FA: @ 0x82853FA
	.incbin "build/data/event_scripts.bin", 0xaa84e, 0x64
gUnknown_828545E: @ 0x828545E
	.incbin "build/data/event_scripts.bin", 0xaa8b2, 0xf9
gUnknown_8285557: @ 0x8285557
	.incbin "build/data/event_scripts.bin", 0xaa9ab, 0x54
gUnknown_82855AB: @ 0x82855AB
	.incbin "build/data/event_scripts.bin", 0xaa9ff, 0x15f
gUnknown_828570A: @ 0x828570A
	.incbin "build/data/event_scripts.bin", 0xaab5e, 0x121
gUnknown_828582B: @ 0x828582B
	.incbin "build/data/event_scripts.bin", 0xaac7f, 0x1cf
gUnknown_82859FA: @ 0x82859FA
	.incbin "build/data/event_scripts.bin", 0xaae4e, 0x27c
gUnknown_8285C76: @ 0x8285C76
	.incbin "build/data/event_scripts.bin", 0xab0ca, 0x66b
gUnknown_82862E1: @ 0x82862E1
	.incbin "build/data/event_scripts.bin", 0xab735, 0x2b
gUnknown_828630C: @ 0x828630C
	.incbin "build/data/event_scripts.bin", 0xab760, 0x9
gUnknown_8286315: @ 0x8286315
	.incbin "build/data/event_scripts.bin", 0xab769, 0x30
gUnknown_8286345: @ 0x8286345
	.incbin "build/data/event_scripts.bin", 0xab799, 0x35
gUnknown_828637A: @ 0x828637A
	.incbin "build/data/event_scripts.bin", 0xab7ce, 0x2c
gUnknown_82863A6: @ 0x82863A6
	.incbin "build/data/event_scripts.bin", 0xab7fa, 0x1a
gUnknown_82863C0: @ 0x82863C0
	.incbin "build/data/event_scripts.bin", 0xab814, 0x1b
gUnknown_82863DB: @ 0x82863DB
	.incbin "build/data/event_scripts.bin", 0xab82f, 0x25
gUnknown_8286400: @ 0x8286400
	.incbin "build/data/event_scripts.bin", 0xab854, 0x25
gUnknown_8286425: @ 0x8286425
	.incbin "build/data/event_scripts.bin", 0xab879, 0x36
gUnknown_828645B: @ 0x828645B
	.incbin "build/data/event_scripts.bin", 0xab8af, 0x9
gUnknown_8286464: @ 0x8286464
	.incbin "build/data/event_scripts.bin", 0xab8b8, 0x3d
gUnknown_82864A1: @ 0x82864A1
	.incbin "build/data/event_scripts.bin", 0xab8f5, 0x8
gUnknown_82864A9: @ 0x82864A9
	.incbin "build/data/event_scripts.bin", 0xab8fd, 0x48
gUnknown_82864F1: @ 0x82864F1
	.incbin "build/data/event_scripts.bin", 0xab945, 0xb
gUnknown_82864FC: @ 0x82864FC
	.incbin "build/data/event_scripts.bin", 0xab950, 0x193
gUnknown_828668F: @ 0x828668F
	.incbin "build/data/event_scripts.bin", 0xabae3, 0x74
gUnknown_8286703: @ 0x8286703
	.incbin "build/data/event_scripts.bin", 0xabb57, 0xdc
gUnknown_82867DF: @ 0x82867DF
	.incbin "build/data/event_scripts.bin", 0xabc33, 0x4d
gUnknown_828682C: @ 0x828682C
	.incbin "build/data/event_scripts.bin", 0xabc80, 0x49
gUnknown_8286875: @ 0x8286875
	.incbin "build/data/event_scripts.bin", 0xabcc9, 0x5
gUnknown_828687A: @ 0x828687A
	.incbin "build/data/event_scripts.bin", 0xabcce, 0x5
gUnknown_828687F: @ 0x828687F
	.incbin "build/data/event_scripts.bin", 0xabcd3, 0x5
gUnknown_8286884: @ 0x8286884
	.incbin "build/data/event_scripts.bin", 0xabcd8, 0xe
gUnknown_8286892: @ 0x8286892
	.incbin "build/data/event_scripts.bin", 0xabce6, 0x31
gUnknown_82868C3: @ 0x82868C3
	.incbin "build/data/event_scripts.bin", 0xabd17, 0x25
gUnknown_82868E8: @ 0x82868E8
	.incbin "build/data/event_scripts.bin", 0xabd3c, 0x5e
gUnknown_8286946: @ 0x8286946
	.incbin "build/data/event_scripts.bin", 0xabd9a, 0x5f
gUnknown_82869A5: @ 0x82869A5
	.incbin "build/data/event_scripts.bin", 0xabdf9, 0xc5
gUnknown_8286A6A: @ 0x8286A6A
	.incbin "build/data/event_scripts.bin", 0xabebe, 0x40
gUnknown_8286AAA: @ 0x8286AAA
	.incbin "build/data/event_scripts.bin", 0xabefe, 0x43
gUnknown_8286AED: @ 0x8286AED
	.incbin "build/data/event_scripts.bin", 0xabf41, 0x143

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
	.4byte gUnknown_828A2F0                  @ 000
	.4byte gUnknown_828A2F0                  @ 001
	.4byte gUnknown_828A2F0                  @ 002
	.4byte gUnknown_828A2F0                  @ 003
	.4byte gUnknown_828A2F0                  @ 004
	.4byte gUnknown_828A306                  @ 005
	.4byte gUnknown_828A2F0                  @ 006
	.4byte gUnknown_828A2F0                  @ 007
	.4byte gUnknown_828A2F0                  @ 008
	.4byte gUnknown_828A2F0                  @ 009
	.4byte gUnknown_828A2F0                  @ 010
	.4byte gUnknown_828A2F0                  @ 011
	.4byte gUnknown_828A2F0                  @ 012

	.globl gUnknown_828A2C4
gUnknown_828A2C4: @ 0x828A2C4
	.4byte gUnknown_828A39A                  @ 000
	.4byte gUnknown_828A3A4                  @ 001
	.4byte gUnknown_828A3A4                  @ 002
	.4byte gUnknown_828A3D3                  @ 003
	.4byte gUnknown_828A3F7                  @ 004
	.4byte gUnknown_828A419                  @ 005

	.globl gUnknown_828A2DC
gUnknown_828A2DC: @ 0x828A2DC
	.4byte gUnknown_828A43B                  @ 000

	.globl gUnknown_828A2E0
gUnknown_828A2E0: @ 0x828A2E0
	.incbin "build/data/event_scripts.bin", 0xaf734, 0x10
gUnknown_828A2F0: @ 0x828A2F0
	.incbin "build/data/event_scripts.bin", 0xaf744, 0x16
gUnknown_828A306: @ 0x828A306
	.incbin "build/data/event_scripts.bin", 0xaf75a, 0x6

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
	.incbin "build/data/event_scripts.bin", 0xaf7de, 0x10
gUnknown_828A39A: @ 0x828A39A
	.incbin "build/data/event_scripts.bin", 0xaf7ee, 0xa
gUnknown_828A3A4: @ 0x828A3A4
	.incbin "build/data/event_scripts.bin", 0xaf7f8, 0x2f
gUnknown_828A3D3: @ 0x828A3D3
	.incbin "build/data/event_scripts.bin", 0xaf827, 0x24
gUnknown_828A3F7: @ 0x828A3F7
	.incbin "build/data/event_scripts.bin", 0xaf84b, 0x22
gUnknown_828A419: @ 0x828A419
	.incbin "build/data/event_scripts.bin", 0xaf86d, 0x22
gUnknown_828A43B: @ 0x828A43B
	.incbin "build/data/event_scripts.bin", 0xaf88f, 0x45

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
