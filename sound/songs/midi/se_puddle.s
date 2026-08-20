.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong70_Part0
sSong70_Part0: @ 0x08869370
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 23
	.byte	VOL , 20
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 39
	.byte	N03, Gs4, 112
	.byte	W01
	.byte	BEND , 55
	.byte	W01
	.byte	73
	.byte	W04
	.byte	W02
	.byte	VOL , 17
	.byte	BEND , 82
	.byte	N02, Gs4, 127
	.byte	W01
	.byte	BEND , 98
	.byte	W03
	.byte	FINE
	.globl sSongHeader_70
sSongHeader_70: @ 0x08869394
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong70_Part0  @ parts
