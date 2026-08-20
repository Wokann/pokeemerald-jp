.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong136_Part0
sSong136_Part0: @ 0x0886ABC8
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	PAN , 78
	.byte	BEND , 64
	.byte	N09, Cn5, 92
	.byte	W03
	.byte	PAN , 49
	.byte	BEND , 32
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 92
	.byte	W03
	.byte	VOICE , 2
	.byte	BEND , 0
	.byte	N21, Bn2, 108
	.byte	W03
	.byte	BEND , 9
	.byte	W03
	.byte	PAN , 68
	.byte	BEND , 19
	.byte	W03
	.byte	PAN , 59
	.byte	BEND , 94
	.byte	W03
	.byte	PAN , 79
	.byte	BEND , 103
	.byte	W03
	.byte	PAN , 49
	.byte	BEND , 118
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	W21
	.byte	FINE
	.globl sSong136_Part1
sSong136_Part1: @ 0x0886AC0B
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	N06, Fn3, 40
	.byte	W09
	.byte	N24, Gn3
	.byte	W15
	.byte	W24
	.byte	FINE
	.globl sSongHeader_136
sSongHeader_136: @ 0x0886AC1C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886ABC8, 0x0886AC0B  @ parts
