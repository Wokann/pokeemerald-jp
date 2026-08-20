.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong29_Part0
sSong29_Part0: @ 0x08868984
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 126
	.byte	BENDR , 12
	.byte	VOL , 120
	.byte	BEND , 64
	.byte	N72, Cn3, 127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_29
sSongHeader_29: @ 0x08868998
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong29_Part0  @ parts
