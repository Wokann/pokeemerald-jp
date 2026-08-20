.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong203_Part0
sSong203_Part0: @ 0x0886CFC0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 45
	.byte	BENDR , 24
	.byte	PAN , 64
	.byte	VOL , 32
	.byte	MOD , 30
	.byte	BEND , 64
	.byte	N06, Cn3, 127
	.byte	W01
	.byte	BEND , 68
	.byte	W01
	.byte	VOL , 49
	.byte	PAN , 69
	.byte	BEND , 73
	.byte	W01
	.byte	80
	.byte	W01
	.byte	VOL , 61
	.byte	BEND , 88
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 66
	.byte	N06, Dn3, 116
	.byte	W01
	.byte	VOL , 71
	.byte	BEND , 71
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 76
	.byte	W01
	.byte	VOL , 81
	.byte	BEND , 82
	.byte	W01
	.byte	91
	.byte	W02
	.byte	VOL , 95
	.byte	PAN , 64
	.byte	BEND , 68
	.byte	N06, En3, 112
	.byte	W01
	.byte	BEND , 73
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 78
	.byte	W01
	.byte	84
	.byte	W01
	.byte	93
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 70
	.byte	N06, Fn3
	.byte	W01
	.byte	BEND , 75
	.byte	W01
	.byte	PAN , 58
	.byte	BEND , 79
	.byte	W01
	.byte	86
	.byte	W01
	.byte	95
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 73
	.byte	N06, Gn3, 108
	.byte	W01
	.byte	BEND , 78
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 82
	.byte	W01
	.byte	89
	.byte	W01
	.byte	98
	.byte	W02
	.byte	VOL , 82
	.byte	PAN , 64
	.byte	BEND , 78
	.byte	N06, An3, 100
	.byte	W01
	.byte	BEND , 82
	.byte	W01
	.byte	VOL , 71
	.byte	PAN , 56
	.byte	BEND , 87
	.byte	W01
	.byte	94
	.byte	W01
	.byte	VOL , 61
	.byte	BEND , 102
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 78
	.byte	N06, Bn3, 60
	.byte	W01
	.byte	BEND , 82
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 87
	.byte	W01
	.byte	94
	.byte	W01
	.byte	102
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 78
	.byte	N06, Cn4, 40
	.byte	W01
	.byte	BEND , 82
	.byte	W01
	.byte	PAN , 56
	.byte	BEND , 87
	.byte	W01
	.byte	94
	.byte	W01
	.byte	102
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 78
	.byte	N06, Dn4, 20
	.byte	W01
	.byte	BEND , 82
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 87
	.byte	W01
	.byte	94
	.byte	W01
	.byte	102
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D093, 0x1
	.globl sSongHeader_203
sSongHeader_203: @ 0x0886D094
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong203_Part0  @ parts
