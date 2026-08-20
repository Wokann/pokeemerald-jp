.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong14_Part0
sSong14_Part0: @ 0x08868610
	.byte	KEYSH , 0
	.byte	TEMPO , 45
	.byte	VOICE , 125
	.byte	VOL , 110
	.byte	N03, Cn3, 100
	.byte	W03
	.byte	An2
	.byte	W03
	.byte	Cn3
	.byte	W03
	.byte	N06, Gn3, 72
	.byte	W03
	.byte	W03
	.byte	N03, Cn3, 52
	.byte	W03
	.byte	N06, Gn3, 48
	.byte	W03
	.byte	W03
	.byte	N03, Cn3, 28
	.byte	W03
	.byte	N06, Gn3
	.byte	W03
	.byte	W03
	.byte	N03, Cn3
	.byte	W03
	.byte	N06, Gn3
	.byte	W03
	.byte	W03
	.byte	N03, Cn3, 12
	.byte	W03
	.byte	N06, Gn3
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong14_Part1
sSong14_Part1: @ 0x08868646
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 110
	.byte	N03, Cn4, 127
	.byte	W03
	.byte	Cn3
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	N06, Gn3, 88
	.byte	W03
	.byte	W03
	.byte	N03, Cn3, 64
	.byte	W03
	.byte	N06, Gn3
	.byte	W03
	.byte	W03
	.byte	N03, Cn3, 44
	.byte	W03
	.byte	N06, Gn3
	.byte	W03
	.byte	W03
	.byte	N03, Cn3, 28
	.byte	W03
	.byte	N06, Gn3
	.byte	W03
	.byte	W03
	.byte	N03, Cn3, 12
	.byte	W03
	.byte	N06, Gn3
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86867A, 0x2
	.globl sSongHeader_14
sSongHeader_14: @ 0x0886867C
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x08868610, 0x08868646  @ parts
