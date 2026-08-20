.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong121_Part0
sSong121_Part0: @ 0x0886A600
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 3
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W06
	.byte	N03, Gn2, 92
	.byte	W06
	.byte	PAN , 48
	.byte	N03, Gn2, 88
	.byte	W09
	.byte	PAN , 63
	.byte	N03, Fs3, 104
	.byte	W03
	.byte	W03
	.byte	PAN , 80
	.byte	N03, Fs3, 88
	.byte	W06
	.byte	PAN , 64
	.byte	N03, Ds3
	.byte	W06
	.byte	PAN , 48
	.byte	N03
	.byte	W09
	.byte	PAN , 63
	.byte	N03, An2, 96
	.byte	W06
	.byte	PAN , 81
	.byte	N03, An2, 88
	.byte	W09
	.byte	PAN , 63
	.byte	N03, Gs3, 104
	.byte	W06
	.byte	PAN , 48
	.byte	N03, Gs3, 88
	.byte	W03
	.byte	W03
	.byte	PAN , 63
	.byte	N03, Fn3
	.byte	W06
	.byte	PAN , 80
	.byte	N03
	.byte	W15
	.byte	FINE
	.globl sSong121_Part1
sSong121_Part1: @ 0x0886A652
	.byte	KEYSH , 0
	.byte	VOICE , 20
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 110
	.byte	PAN , 57
	.byte	BEND , 119
	.byte	N03, Cn2, 100
	.byte	W06
	.byte	PAN , 70
	.byte	BEND , 100
	.byte	N03
	.byte	W06
	.byte	PAN , 57
	.byte	BEND , 81
	.byte	N03
	.byte	W06
	.byte	PAN , 70
	.byte	BEND , 66
	.byte	N03
	.byte	W06
	.byte	PAN , 57
	.byte	BEND , 56
	.byte	N03
	.byte	W06
	.byte	PAN , 70
	.byte	BEND , 76
	.byte	N03
	.byte	W06
	.byte	PAN , 57
	.byte	BEND , 70
	.byte	N03
	.byte	W06
	.byte	PAN , 70
	.byte	BEND , 64
	.byte	N03
	.byte	W06
	.byte	PAN , 57
	.byte	BEND , 58
	.byte	N03
	.byte	W06
	.byte	PAN , 70
	.byte	BEND , 45
	.byte	N03
	.byte	W06
	.byte	PAN , 57
	.byte	BEND , 33
	.byte	N03
	.byte	W06
	.byte	PAN , 70
	.byte	BEND , 20
	.byte	N03
	.byte	W06
	.byte	PAN , 57
	.byte	BEND , 9
	.byte	N03
	.byte	W06
	.byte	PAN , 70
	.byte	BEND , 0
	.byte	N03
	.byte	W18
	.byte	FINE
	.globl sSongHeader_121
sSongHeader_121: @ 0x0886A6B4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A600, 0x0886A652  @ parts
