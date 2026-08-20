.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong224_Part0
sSong224_Part0: @ 0x0886E080
	.byte	KEYSH , 0
	.byte	VOICE , 19
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 12
	.byte	BEND , 113
	.byte	N06, Gn4, 80
	.byte	W01
	.byte	VOL , 44
	.byte	BEND , 86
	.byte	W01
	.byte	VOL , 62
	.byte	PAN , 72
	.byte	VOL , 75
	.byte	BEND , 84
	.byte	W01
	.byte	VOL , 87
	.byte	BEND , 97
	.byte	W01
	.byte	VOL , 96
	.byte	PAN , 57
	.byte	VOL , 100
	.byte	BEND , 118
	.byte	W01
	.byte	127
	.byte	W01
	.byte	W02
	.byte	PAN , 64
	.byte	N04, Gn4, 40
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	VOICE , 45
	.byte	MOD , 30
	.byte	BENDR , 24
	.byte	VOL , 54
	.byte	BEND , 64
	.byte	N06, Gn3, 108
	.byte	W01
	.byte	VOL , 70
	.byte	BEND , 68
	.byte	W01
	.byte	PAN , 69
	.byte	VOL , 80
	.byte	BEND , 73
	.byte	W01
	.byte	VOL , 100
	.byte	BEND , 80
	.byte	W01
	.byte	88
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 66
	.byte	N06, An3, 100
	.byte	W01
	.byte	BEND , 71
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 76
	.byte	W01
	.byte	82
	.byte	W01
	.byte	91
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 68
	.byte	N06, Bn3, 60
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
	.byte	N06, Cn4, 40
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
	.byte	N06, Dn4, 20
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
	.byte	FINE
	.globl sSong224_Part1
sSong224_Part1: @ 0x0886E129
	.byte	KEYSH , 0
	.byte	VOICE , 57
	.byte	VOL , 59
	.byte	N06, Gs4, 52
	.byte	W01
	.byte	VOL , 72
	.byte	W01
	.byte	90
	.byte	W01
	.byte	100
	.byte	W03
	.byte	W02
	.byte	N04, Gs4, 24
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSongHeader_224
sSongHeader_224: @ 0x0886E14C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E080, 0x0886E129  @ parts
