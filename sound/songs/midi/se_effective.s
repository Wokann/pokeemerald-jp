.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong13_Part0
sSong13_Part0: @ 0x088685C4
	.byte	KEYSH , 0
	.byte	TEMPO , 45
	.byte	VOICE , 125
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, As2, 100
	.byte	W03
	.byte	BEND , 31
	.byte	N36, Ds3
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong13_Part1
sSong13_Part1: @ 0x088685E6
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 110
	.byte	N03, Cn3, 127
	.byte	W03
	.byte	N18
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8685FF, 0x1
	.globl sSongHeader_13
sSongHeader_13: @ 0x08868600
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x088685C4, 0x088685E6  @ parts
