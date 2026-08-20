.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong159_Part0
sSong159_Part0: @ 0x0886B78C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 26
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N02, Gn5, 92
	.byte	W02
	.byte	Cn5
	.byte	W04
	.byte	VOICE , 36
	.byte	VOL , 84
	.byte	PAN , 69
	.byte	N15, Gn5, 40
	.byte	W01
	.byte	PAN , 54
	.byte	W01
	.byte	69
	.byte	W01
	.byte	54
	.byte	W01
	.byte	VOL , 94
	.byte	PAN , 69
	.byte	W02
	.byte	54
	.byte	W01
	.byte	69
	.byte	W01
	.byte	54
	.byte	W01
	.byte	VOL , 110
	.byte	PAN , 69
	.byte	W01
	.byte	54
	.byte	W02
	.byte	VOL , 96
	.byte	PAN , 69
	.byte	W01
	.byte	VOL , 68
	.byte	PAN , 54
	.byte	W01
	.byte	VOL , 15
	.byte	PAN , 69
	.byte	W01
	.byte	54
	.byte	W03
	.byte	FINE
	.globl sSong159_Part1
sSong159_Part1: @ 0x0886B7D5
	.byte	KEYSH , 0
	.byte	VOICE , 25
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	N01, Cn3, 40
	.byte	W02
	.byte	N01
	.byte	W22
	.byte	FINE
	.globl sSongHeader_159
sSongHeader_159: @ 0x0886B7E4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B78C, 0x0886B7D5  @ parts
