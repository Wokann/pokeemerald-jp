.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong226_Part0
sSong226_Part0: @ 0x0886E208
	.byte	KEYSH , 0
	.byte	TEMPO , 105
	.byte	VOICE , 46
	.byte	VOL , 95
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	W03
	.byte	N06, Cn6, 116
	.byte	W03
	.byte	W03
	.byte	En6, 108
	.byte	W03
	.byte	W03
	.byte	Cs5, 100
	.byte	W03
	.byte	W03
	.byte	Gs5, 88
	.byte	W03
	.byte	W03
	.byte	PAN , 60
	.byte	N06, Cs6, 80
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, Dn6, 72
	.byte	W03
	.byte	W03
	.byte	PAN , 68
	.byte	N06, Fs6, 60
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, Ds5, 52
	.byte	W03
	.byte	W03
	.byte	PAN , 60
	.byte	N06, As5, 40
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	W03
	.byte	W03
	.byte	68
	.byte	W03
	.byte	W03
	.byte	64
	.byte	FINE
	.globl sSong226_Part1
sSong226_Part1: @ 0x0886E254
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	BENDR , 2
	.byte	VOL , 43
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	N06, Cn5, 120
	.byte	W03
	.byte	W03
	.byte	Gn5, 112
	.byte	W03
	.byte	W03
	.byte	Cn6, 104
	.byte	W03
	.byte	W03
	.byte	Cs6, 92
	.byte	W03
	.byte	W03
	.byte	Fn6, 84
	.byte	W03
	.byte	W03
	.byte	Dn5, 76
	.byte	W03
	.byte	W03
	.byte	An5, 64
	.byte	W03
	.byte	W03
	.byte	Dn6, 56
	.byte	W03
	.byte	W03
	.byte	Ds6, 48
	.byte	W03
	.byte	W03
	.byte	Gn6, 36
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86E28D, 0x3
	.globl sSongHeader_226
sSongHeader_226: @ 0x0886E290
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E208, 0x0886E254  @ parts
