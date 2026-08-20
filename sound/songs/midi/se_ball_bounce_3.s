.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong58_Part0
sSong58_Part0: @ 0x088690C4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 16
	.byte	VOL , 100
	.byte	BEND , 65
	.byte	N12, Fn4, 88
	.byte	W12
	.byte	FINE
	.globl sSong58_Part1
sSong58_Part1: @ 0x088690D3
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N09, Fn4, 72
	.byte	W12
	.byte	FINE
	.globl sSongHeader_58
sSongHeader_58: @ 0x088690E0
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x088690C4, 0x088690D3  @ parts
