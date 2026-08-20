.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong77_Part0
sSong77_Part0: @ 0x0886950C
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 41
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, Fs4, 127
	.byte	W01
	.byte	BEND , 56
	.byte	W01
	.byte	41
	.byte	W01
	.byte	W01
	.byte	64
	.byte	N10, Cn4
	.byte	W02
	.byte	W03
	.byte	W01
	.byte	VOL , 96
	.byte	W02
	.byte	82
	.byte	W01
	.byte	45
	.byte	W01
	.byte	20
	.byte	W01
	.byte	W03
	.byte	W01
	.byte	110
	.byte	N10, Cn4, 40
	.byte	W02
	.byte	W03
	.byte	W01
	.byte	VOL , 96
	.byte	W01
	.byte	82
	.byte	W01
	.byte	45
	.byte	W01
	.byte	20
	.byte	W02
	.byte	FINE
	.globl sSongHeader_77
sSongHeader_77: @ 0x08869544
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong77_Part0  @ parts
