.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong149_Part0
sSong149_Part0: @ 0x0886B218
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	PAN , 69
	.byte	BEND , 64
	.byte	N04, Cn3, 127
	.byte	W03
	.byte	PAN , 64
	.byte	W01
	.byte	N18, Gn4
	.byte	W02
	.byte	PAN , 59
	.byte	W01
	.byte	VOL , 98
	.byte	BEND , 66
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 83
	.byte	BEND , 70
	.byte	W02
	.byte	PAN , 69
	.byte	W01
	.byte	BEND , 73
	.byte	W01
	.byte	VOL , 63
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	BEND , 77
	.byte	W02
	.byte	VOL , 44
	.byte	PAN , 59
	.byte	W02
	.byte	VOL , 28
	.byte	BEND , 84
	.byte	W01
	.byte	PAN , 62
	.byte	W01
	.byte	VOL , 12
	.byte	W02
	.byte	FINE
	.globl sSong149_Part1
sSong149_Part1: @ 0x0886B260
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	N01, Gn2, 32
	.byte	W02
	.byte	N01
	.byte	W02
	.byte	N18
	.byte	W03
	.byte	VOL , 98
	.byte	W03
	.byte	83
	.byte	W04
	.byte	63
	.byte	W04
	.byte	44
	.byte	W02
	.byte	28
	.byte	W02
	.byte	12
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B27E, 0x2
	.globl sSongHeader_149
sSongHeader_149: @ 0x0886B280
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B218, 0x0886B260  @ parts
