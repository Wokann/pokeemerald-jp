.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong95_Part0
sSong95_Part0: @ 0x08869A04
	.byte	KEYSH , 0
	.byte	TEMPO , 64
	.byte	VOICE , 6
	.byte	BENDR , 12
	.byte	VOL , 90
	.byte	BEND , 63
	.byte	N01, Ds3, 127
	.byte	W02
	.byte	N03, Gs3, 100
	.byte	W05
	.byte	N16, Fn5, 72
	.byte	W05
	.byte	W12
	.byte	FINE
	.globl sSong95_Part1
sSong95_Part1: @ 0x08869A1E
	.byte	KEYSH , 0
	.byte	VOICE , 14
	.byte	VOL , 90
	.byte	BEND , 56
	.byte	W02
	.byte	N03, Gs3, 60
	.byte	W05
	.byte	N16, Fn5
	.byte	W05
	.byte	W12
	.byte	FINE
	.globl sSongHeader_95
sSongHeader_95: @ 0x08869A30
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x08869A04, 0x08869A1E  @ parts
