.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong28_Part0
sSong28_Part0: @ 0x08868964
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 125
	.byte	BENDR , 12
	.byte	VOL , 120
	.byte	BEND , 64
	.byte	N72, Cn3, 127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_28
sSongHeader_28: @ 0x08868978
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong28_Part0  @ parts
