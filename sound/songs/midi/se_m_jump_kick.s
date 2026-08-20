.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong143_Part0
sSong143_Part0: @ 0x0886AEF4
	.byte	KEYSH , 0
	.byte	TEMPO , 90
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 52
	.byte	N19, Gn3, 108
	.byte	W02
	.byte	BEND , 59
	.byte	W01
	.byte	VOL , 101
	.byte	W01
	.byte	PAN , 55
	.byte	BEND , 72
	.byte	W02
	.byte	VOL , 84
	.byte	BEND , 68
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 64
	.byte	BEND , 51
	.byte	W01
	.byte	PAN , 72
	.byte	W02
	.byte	VOL , 45
	.byte	BEND , 33
	.byte	W02
	.byte	VOL , 32
	.byte	PAN , 64
	.byte	W01
	.byte	VOICE , 2
	.byte	W01
	.byte	VOL , 13
	.byte	BEND , 12
	.byte	W08
	.byte	FINE
	.globl sSongHeader_143
sSongHeader_143: @ 0x0886AF34
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong143_Part0  @ parts
