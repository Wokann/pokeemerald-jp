.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong2_Part0
sSong2_Part0: @ 0x0886840C
	.byte	KEYSH , 0
	.byte	TEMPO , 72
	.byte	VOICE , 4
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 100
	.byte	BEND , 58
	.byte	N08, Cn4, 112
	.byte	W08
	.byte	N04, Cn4, 28
	.byte	W04
	.byte	N08, Cn4, 112
	.byte	W08
	.byte	N04, Cn4, 24
	.byte	W04
	.byte	FINE
	.globl sSongHeader_2
sSongHeader_2: @ 0x0886842C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong2_Part0  @ parts
