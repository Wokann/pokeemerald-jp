.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong30_Part0
sSong30_Part0: @ 0x088689A4
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 127
	.byte	BENDR , 12
	.byte	VOL , 127
	.byte	BEND , 64
	.byte	N72, Cn3, 127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_30
sSongHeader_30: @ 0x088689B8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong30_Part0  @ parts
