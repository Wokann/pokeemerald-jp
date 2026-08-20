.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong119_Part0
sSong119_Part0: @ 0x0886A54C
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	VOL , 100
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, Cn4, 88
	.byte	W06
	.byte	PAN , 55
	.byte	N03, Cn4, 80
	.byte	W06
	.byte	PAN , 73
	.byte	N03, Cn4, 72
	.byte	W06
	.byte	PAN , 48
	.byte	N03, Cn4, 64
	.byte	W06
	.byte	PAN , 80
	.byte	N03, Cn4, 60
	.byte	W06
	.byte	PAN , 48
	.byte	N03, Cn4, 52
	.byte	W18
	.byte	FINE
	.globl sSong119_Part1
sSong119_Part1: @ 0x0886A57D
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 100
	.byte	PAN , 73
	.byte	N02, Gn3, 72
	.byte	W06
	.byte	PAN , 57
	.byte	N02, Gn3, 68
	.byte	W06
	.byte	PAN , 73
	.byte	N02, Gn3, 64
	.byte	W06
	.byte	PAN , 57
	.byte	N02, Gn3, 60
	.byte	W06
	.byte	PAN , 73
	.byte	N02, Gn3, 56
	.byte	W06
	.byte	PAN , 57
	.byte	N02, Gn3, 48
	.byte	W18
	.byte	FINE
	.globl sSongHeader_119
sSongHeader_119: @ 0x0886A5A8
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A54C, 0x0886A57D  @ parts
