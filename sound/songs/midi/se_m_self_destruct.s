.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong177_Part0
sSong177_Part0: @ 0x0886C0CC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 41
	.byte	VOL , 115
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N01, Gn3, 127
	.byte	W01
	.byte	Cn3
	.byte	W01
	.byte	N24, An3
	.byte	W06
	.byte	PAN , 70
	.byte	W04
	.byte	64
	.byte	W01
	.byte	VOL , 102
	.byte	W02
	.byte	PAN , 56
	.byte	VOL , 88
	.byte	W03
	.byte	78
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 67
	.byte	W01
	.byte	BEND , 62
	.byte	W01
	.byte	PAN , 71
	.byte	VOL , 45
	.byte	W02
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 13
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 49
	.byte	W22
	.byte	FINE
	.globl sSongHeader_177
sSongHeader_177: @ 0x0886C10C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong177_Part0  @ parts
