.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong56_Part0
sSong56_Part0: @ 0x0886906C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 16
	.byte	VOL , 100
	.byte	BEND , 65
	.byte	N12, Fn4, 112
	.byte	W12
	.byte	FINE
	.globl sSong56_Part1
sSong56_Part1: @ 0x0886907B
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N09, Fn4, 100
	.byte	W12
	.byte	FINE
	.globl sSongHeader_56
sSongHeader_56: @ 0x08869088
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886906C, 0x0886907B  @ parts
