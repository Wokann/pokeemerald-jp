.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong124_Part0
sSong124_Part0: @ 0x0886A798
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 23
	.byte	VOL , 95
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N09, Cn3, 127
	.byte	W03
	.byte	PAN , 48
	.byte	BEND , 70
	.byte	W01
	.byte	80
	.byte	W02
	.byte	PAN , 80
	.byte	BEND , 101
	.byte	W01
	.byte	112
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 63
	.byte	N03, En3
	.byte	W15
	.byte	FINE
	.globl sSongHeader_124
sSongHeader_124: @ 0x0886A7C0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong124_Part0  @ parts
