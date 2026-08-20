.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong156_Part0
sSong156_Part0: @ 0x0886B520
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	PAN , 68
	.byte	VOL , 42
	.byte	BEND , 103
	.byte	N06, Cn5, 84
	.byte	W01
	.byte	VOL , 55
	.byte	BEND , 82
	.byte	W01
	.byte	VOL , 71
	.byte	BEND , 64
	.byte	W01
	.byte	PAN , 60
	.byte	VOL , 86
	.byte	BEND , 46
	.byte	W01
	.byte	VOL , 110
	.byte	BEND , 14
	.byte	W02
	.byte	PAN , 64
	.byte	W04
	.byte	VOICE , 8
	.byte	PAN , 53
	.byte	BEND , 64
	.byte	N06, Gn4, 120
	.byte	W02
	.byte	PAN , 75
	.byte	BEND , 51
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 38
	.byte	W01
	.byte	PAN , 52
	.byte	BEND , 18
	.byte	W01
	.byte	PAN , 75
	.byte	BEND , 10
	.byte	W09
	.byte	FINE
	.globl sSong156_Part1
sSong156_Part1: @ 0x0886B56A
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	N06, Cn2, 40
	.byte	W10
	.byte	N02, Gn2
	.byte	W14
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B57A, 0x2
	.globl sSongHeader_156
sSongHeader_156: @ 0x0886B57C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B520, 0x0886B56A  @ parts
