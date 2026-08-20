.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong227_Part0
sSong227_Part0: @ 0x0886E2A0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 61
	.byte	BENDR , 44
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	MOD , 30
	.byte	BEND , 66
	.byte	N54, Dn4, 80
	.byte	W12
	.byte	PAN , 60
	.byte	W12
	.byte	54
	.byte	W12
	.byte	60
	.byte	W12
	.byte	64
	.byte	W06
	.byte	N54, Cn4
	.byte	W06
	.byte	PAN , 70
	.byte	W12
	.byte	73
	.byte	W12
	.byte	69
	.byte	W12
	.byte	64
	.byte	W12
	.byte	60
	.byte	N54, Dn4
	.byte	W12
	.byte	PAN , 54
	.byte	W12
	.byte	60
	.byte	W12
	.byte	64
	.byte	W12
	.byte	70
	.byte	W06
	.byte	N54, Cn4
	.byte	W06
	.byte	PAN , 73
	.byte	W12
	.byte	69
	.byte	W12
	.byte	64
	.byte	W12
	.byte	60
	.byte	W12
	.byte	FINE
	.globl sSong227_Part1
sSong227_Part1: @ 0x0886E2E3
	.byte	KEYSH , 0
	.byte	VOICE , 62
	.byte	BENDR , 44
	.byte	VOL , 110
	.byte	MOD , 30
	.byte	PAN , 65
	.byte	BEND , 65
	.byte	N24, Dn4, 40
	.byte	W24
	.byte	W02
	.byte	PAN , 111
	.byte	N24, Dn4, 32
	.byte	W22
	.byte	W06
	.byte	PAN , 64
	.byte	N24, Cn4, 40
	.byte	W18
	.byte	W08
	.byte	PAN , 15
	.byte	N24, Cn4, 32
	.byte	W16
	.byte	W12
	.byte	PAN , 65
	.byte	N24, Dn4, 40
	.byte	W12
	.byte	W14
	.byte	PAN , 111
	.byte	N24, Dn4, 32
	.byte	W10
	.byte	W18
	.byte	PAN , 64
	.byte	N24, Cn4, 40
	.byte	W06
	.byte	W20
	.byte	PAN , 16
	.byte	N24, Cn4, 32
	.byte	W04
	.byte	W24
	.byte	FINE
	.globl sSongHeader_227
sSongHeader_227: @ 0x0886E328
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E2A0, 0x0886E2E3  @ parts
