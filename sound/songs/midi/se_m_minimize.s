.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong204_Part0
sSong204_Part0: @ 0x0886D0A0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 45
	.byte	BENDR , 24
	.byte	PAN , 64
	.byte	VOL , 32
	.byte	MOD , 30
	.byte	BEND , 103
	.byte	N06, Dn4, 127
	.byte	W01
	.byte	BEND , 95
	.byte	W01
	.byte	VOL , 49
	.byte	PAN , 69
	.byte	BEND , 87
	.byte	W01
	.byte	79
	.byte	W01
	.byte	VOL , 61
	.byte	BEND , 72
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 99
	.byte	N06, Cn4, 116
	.byte	W01
	.byte	VOL , 71
	.byte	BEND , 91
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 83
	.byte	W01
	.byte	VOL , 81
	.byte	BEND , 76
	.byte	W01
	.byte	69
	.byte	W02
	.byte	VOL , 95
	.byte	PAN , 64
	.byte	BEND , 96
	.byte	N06, Bn3, 112
	.byte	W01
	.byte	BEND , 88
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 80
	.byte	W01
	.byte	72
	.byte	W01
	.byte	65
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 92
	.byte	N06, An3
	.byte	W01
	.byte	BEND , 84
	.byte	W01
	.byte	PAN , 58
	.byte	BEND , 76
	.byte	W01
	.byte	69
	.byte	W01
	.byte	62
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 88
	.byte	N06, Gn3, 108
	.byte	W01
	.byte	BEND , 80
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 73
	.byte	W01
	.byte	65
	.byte	W01
	.byte	58
	.byte	W02
	.byte	VOL , 82
	.byte	PAN , 64
	.byte	BEND , 85
	.byte	N06, Fn3, 100
	.byte	W01
	.byte	BEND , 77
	.byte	W01
	.byte	VOL , 71
	.byte	PAN , 56
	.byte	BEND , 69
	.byte	W01
	.byte	62
	.byte	W01
	.byte	VOL , 61
	.byte	BEND , 54
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 81
	.byte	N06, En3, 60
	.byte	W01
	.byte	BEND , 73
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 66
	.byte	W01
	.byte	58
	.byte	W01
	.byte	51
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 78
	.byte	N06, Dn3, 40
	.byte	W01
	.byte	BEND , 70
	.byte	W01
	.byte	PAN , 56
	.byte	BEND , 62
	.byte	W01
	.byte	54
	.byte	W01
	.byte	47
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 76
	.byte	N06, Cn3, 20
	.byte	W01
	.byte	BEND , 68
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 60
	.byte	W01
	.byte	53
	.byte	W01
	.byte	46
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D173, 0x1
	.globl sSongHeader_204
sSongHeader_204: @ 0x0886D174
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong204_Part0  @ parts
