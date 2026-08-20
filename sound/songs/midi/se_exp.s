.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong33_Part0
sSong33_Part0: @ 0x08868A14
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 13
	.byte	BENDR , 12
	.byte	24
	.byte	VOL , 80
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N12, Cn4, 112
	.byte	W02
	.byte	BEND , 72
	.byte	W02
	.byte	VOL , 74
	.byte	BEND , 80
	.byte	W03
	.byte	VOL , 61
	.byte	BEND , 86
	.byte	W02
	.byte	VOL , 45
	.byte	BEND , 97
	.byte	W03
	.byte	VOL , 80
	.byte	BEND , 64
	.byte	TIE
	.byte	W06
	.byte	BEND , 67
	.byte	W02
	.byte	64
	.byte	W04
	.byte	70
	.byte	W03
	.byte	68
	.byte	W03
	.byte	73
	.byte	W02
	.byte	72
	.byte	W04
	.byte	76
	.byte	W03
	.byte	73
	.byte	W03
	.byte	78
	.byte	W03
	.byte	76
	.byte	W03
	.byte	80
	.byte	W03
	.byte	78
	.byte	W03
	.byte	83
	.byte	W03
	.byte	80
	.byte	W03
	.byte	86
	.byte	W03
	.byte	83
	.byte	W03
	.byte	89
	.byte	W03
	.byte	86
	.byte	W03
	.byte	92
	.byte	W03
	.byte	89
	.byte	W03
	.byte	96
	.byte	W03
	.byte	92
	.byte	W03
	.byte	99
	.byte	W03
	.byte	96
	.byte	W03
	.byte	100
	.byte	W03
	.byte	99
	.byte	W03
	.byte	104
	.byte	W03
	.byte	100
	.byte	W03
	.byte	107
	.byte	W03
	.byte	104
	.byte	W03
	.byte	110
	.byte	W03
	.byte	107
	.byte	W03
	.byte	113
	.byte	W03
	.byte	110
	.byte	W03
	.byte	117
	.byte	W03
	.byte	113
	.byte	W03
	.byte	119
	.byte	W03
	.byte	117
	.byte	W03
	.byte	122
	.byte	W03
	.byte	119
	.byte	W03
	.byte	124
	.byte	W03
	.byte	122
	.byte	W03
	.byte	127
	.byte	W04
	.byte	124
	.byte	W03
	.byte	127
	.byte	W05
	.byte	EOT
	.byte	FINE
	.globl sSongHeader_33
sSongHeader_33: @ 0x08868A9C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong33_Part0  @ parts
