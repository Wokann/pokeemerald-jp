.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong59_Part0
sSong59_Part0: @ 0x088690F0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 16
	.byte	VOL , 100
	.byte	BEND , 65
	.byte	N12, Fn4, 76
	.byte	W12
	.byte	FINE
	.globl sSong59_Part1
sSong59_Part1: @ 0x088690FF
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N09, Fn4, 56
	.byte	W12
	.byte	FINE
	.globl sSongHeader_59
sSongHeader_59: @ 0x0886910C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x088690F0, 0x088690FF  @ parts
