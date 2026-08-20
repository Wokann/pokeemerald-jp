.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong131_Part0
sSong131_Part0: @ 0x0886AA38
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 26
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 105
	.byte	BEND , 64
	.byte	N06, En3, 127
	.byte	W03
	.byte	PAN , 56
	.byte	BEND , 30
	.byte	W03
	.byte	PAN , 71
	.byte	N03, Gn3, 100
	.byte	W03
	.byte	PAN , 49
	.byte	BEND , 68
	.byte	N06, En3, 127
	.byte	W03
	.byte	PAN , 80
	.byte	BEND , 51
	.byte	W03
	.byte	PAN , 63
	.byte	BEND , 64
	.byte	N06, Cn3, 84
	.byte	W06
	.byte	BEND , 44
	.byte	N06, En3, 68
	.byte	W03
	.byte	BEND , 23
	.byte	W24
	.byte	FINE
	.globl sSongHeader_131
sSongHeader_131: @ 0x0886AA74
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong131_Part0  @ parts
