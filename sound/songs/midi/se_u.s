.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong27_Part0
sSong27_Part0: @ 0x08868944
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 124
	.byte	BENDR , 12
	.byte	VOL , 127
	.byte	BEND , 64
	.byte	N72, Cn3, 127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_27
sSongHeader_27: @ 0x08868958
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong27_Part0  @ parts
