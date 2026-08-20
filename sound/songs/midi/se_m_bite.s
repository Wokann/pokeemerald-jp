.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong161_Part0
sSong161_Part0: @ 0x0886B834
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 26
	.byte	BENDR , 12
	.byte	PAN , 70
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N02, Gn3, 112
	.byte	W02
	.byte	Gs3
	.byte	W01
	.byte	PAN , 57
	.byte	W01
	.byte	N02, An3
	.byte	W02
	.byte	PAN , 71
	.byte	W02
	.byte	56
	.byte	W02
	.byte	VOICE , 21
	.byte	PAN , 64
	.byte	N01, Cn5, 116
	.byte	W02
	.byte	PAN , 74
	.byte	N01, Cn4, 108
	.byte	W01
	.byte	PAN , 56
	.byte	N01, Gn4, 104
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Gn3, 96
	.byte	W01
	.byte	PAN , 74
	.byte	N01, Cn4, 88
	.byte	W01
	.byte	PAN , 56
	.byte	N01, Cn3, 80
	.byte	W02
	.byte	PAN , 64
	.byte	N01, Gn3, 72
	.byte	W01
	.byte	PAN , 74
	.byte	N01, Gn2, 64
	.byte	W01
	.byte	PAN , 56
	.byte	N01, Cn3, 56
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Gn2, 48
	.byte	W03
	.byte	FINE
	.globl sSong161_Part1
sSong161_Part1: @ 0x0886B892
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W10
	.byte	N01, Gn2, 40
	.byte	W08
	.byte	N01
	.byte	W06
	.byte	FINE
	.globl sSongHeader_161
sSongHeader_161: @ 0x0886B8A4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B834, 0x0886B892  @ parts
