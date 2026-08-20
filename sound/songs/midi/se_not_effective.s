.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong12_Part0
sSong12_Part0: @ 0x08868594
	.byte	KEYSH , 0
	.byte	TEMPO , 45
	.byte	VOICE , 127
	.byte	VOL , 110
	.byte	N03, Gn2, 100
	.byte	W03
	.byte	N06, As2
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong12_Part1
sSong12_Part1: @ 0x088685A5
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 110
	.byte	N09, As1, 127
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8685B2, 0x2
	.globl sSongHeader_12
sSongHeader_12: @ 0x088685B4
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x08868594, 0x088685A5  @ parts
