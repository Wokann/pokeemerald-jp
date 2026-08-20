.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong57_Part0
sSong57_Part0: @ 0x08869098
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 16
	.byte	VOL , 100
	.byte	BEND , 65
	.byte	N12, Fn4, 100
	.byte	W12
	.byte	FINE
	.globl sSong57_Part1
sSong57_Part1: @ 0x088690A7
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N09, Fn4, 88
	.byte	W12
	.byte	FINE
	.globl sSongHeader_57
sSongHeader_57: @ 0x088690B4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869098, 0x088690A7  @ parts
