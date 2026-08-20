.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong125_Part0
sSong125_Part0: @ 0x0886A7CC
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 24
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W03
	.byte	N09, Gn4, 127
	.byte	W02
	.byte	BEND , 95
	.byte	W02
	.byte	30
	.byte	W17
	.byte	FINE
	.globl sSong125_Part1
sSong125_Part1: @ 0x0886A7E5
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	N01, Cn4, 44
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A7F2, 0x2
	.globl sSongHeader_125
sSongHeader_125: @ 0x0886A7F4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A7CC, 0x0886A7E5  @ parts
