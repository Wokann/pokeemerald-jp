.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong197_Part0
sSong197_Part0: @ 0x0886CB40
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 38
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 27
	.byte	BEND , 64
	.byte	N10, An1, 127
	.byte	W01
	.byte	VOL , 75
	.byte	W01
	.byte	120
	.byte	W04
	.byte	W02
	.byte	75
	.byte	W01
	.byte	28
	.byte	W03
	.byte	VOICE , 36
	.byte	VOL , 83
	.byte	N18, En2, 112
	.byte	W02
	.byte	VOL , 87
	.byte	W02
	.byte	91
	.byte	W02
	.byte	W01
	.byte	97
	.byte	W02
	.byte	102
	.byte	W01
	.byte	109
	.byte	W02
	.byte	113
	.byte	W01
	.byte	120
	.byte	W05
	.byte	FINE
	.globl sSong197_Part1
sSong197_Part1: @ 0x0886CB75
	.byte	VOL , 120
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	N01, En2, 52
	.byte	W02
	.byte	Dn2
	.byte	W02
	.byte	En2
	.byte	W02
	.byte	W01
	.byte	Dn2
	.byte	W02
	.byte	En2
	.byte	W03
	.byte	W01
	.byte	En2, 64
	.byte	W02
	.byte	Gs2
	.byte	W03
	.byte	Dn3
	.byte	W02
	.byte	En2
	.byte	W02
	.byte	Gs2
	.byte	W02
	.byte	W01
	.byte	Dn3
	.byte	W05
	.byte	FINE
	.globl sSongHeader_197
sSongHeader_197: @ 0x0886CB98
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886CB40, 0x0886CB75  @ parts
