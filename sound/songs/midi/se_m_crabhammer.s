.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong142_Part0
sSong142_Part0: @ 0x0886AEBC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 23
	.byte	VOL , 100
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 66
	.byte	N02, Dn3, 127
	.byte	W01
	.byte	PAN , 54
	.byte	BEND , 68
	.byte	W02
	.byte	PAN , 72
	.byte	BEND , 70
	.byte	N02, Dn3, 84
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 73
	.byte	W02
	.byte	63
	.byte	W02
	.byte	96
	.byte	N02, Dn3, 56
	.byte	W16
	.byte	FINE
	.globl sSongHeader_142
sSongHeader_142: @ 0x0886AEE8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong142_Part0  @ parts
