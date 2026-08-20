.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong228_Part0
sSong228_Part0: @ 0x0886E338
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 46
	.byte	VOL , 95
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	W03
	.byte	N06, Ds6, 112
	.byte	W03
	.byte	W03
	.byte	En5, 104
	.byte	W03
	.byte	W03
	.byte	Ds6, 96
	.byte	W03
	.byte	W03
	.byte	En5, 88
	.byte	W03
	.byte	W03
	.byte	PAN , 60
	.byte	N06, Ds6, 80
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, En5, 72
	.byte	W03
	.byte	W03
	.byte	PAN , 68
	.byte	N06, Ds6, 64
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, En5, 56
	.byte	W03
	.byte	W03
	.byte	PAN , 60
	.byte	N06, Ds6, 44
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, En5, 36
	.byte	W03
	.byte	W03
	.byte	PAN , 68
	.byte	N06, Ds6, 28
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, En5, 20
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong228_Part1
sSong228_Part1: @ 0x0886E391
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	BENDR , 2
	.byte	VOL , 43
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	N06, Gs6, 108
	.byte	W03
	.byte	W03
	.byte	Bn5
	.byte	W03
	.byte	W03
	.byte	Gs6, 100
	.byte	W03
	.byte	W03
	.byte	Bn5, 92
	.byte	W03
	.byte	W03
	.byte	Gs6, 84
	.byte	W03
	.byte	W03
	.byte	Bn5, 76
	.byte	W03
	.byte	W03
	.byte	Gs6, 68
	.byte	W03
	.byte	W03
	.byte	Bn5, 60
	.byte	W03
	.byte	W03
	.byte	Gs6, 52
	.byte	W03
	.byte	W03
	.byte	Bn5, 40
	.byte	W03
	.byte	W03
	.byte	Gs6, 32
	.byte	W03
	.byte	W03
	.byte	Bn5, 24
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86E3CF, 0x1
	.globl sSongHeader_228
sSongHeader_228: @ 0x0886E3D0
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E338, 0x0886E391  @ parts
