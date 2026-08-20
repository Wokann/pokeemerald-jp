.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong128_Part0
sSong128_Part0: @ 0x0886A8B8
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 120
	.byte	BEND , 64
	.byte	N15, Cn3, 108
	.byte	W03
	.byte	VOL , 102
	.byte	BEND , 86
	.byte	W02
	.byte	72
	.byte	W01
	.byte	VOL , 88
	.byte	W03
	.byte	75
	.byte	BEND , 51
	.byte	W03
	.byte	VOL , 55
	.byte	W03
	.byte	VOICE , 18
	.byte	VOL , 120
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
	.byte	N21, Cn3, 108
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
	.byte	W06
	.byte	FINE
	.globl sSong128_Part1
sSong128_Part1: @ 0x0886A916
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	PAN , 64
	.byte	VOL , 120
	.byte	N15, Cn2, 40
	.byte	W15
	.byte	N06, Fs3
	.byte	W09
	.byte	N24, Gs3
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A929, 0x3
	.globl sSongHeader_128
sSongHeader_128: @ 0x0886A92C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A8B8, 0x0886A916  @ parts
