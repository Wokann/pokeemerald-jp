.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong55_Part0
sSong55_Part0: @ 0x08869024
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 14
	.byte	VOL , 80
	.byte	BEND , 81
	.byte	N03, En3, 96
	.byte	W03
	.byte	Bn2
	.byte	W03
	.byte	En3
	.byte	W03
	.byte	Bn3
	.byte	W03
	.byte	N06, Cn5
	.byte	W06
	.byte	N24, Cn6
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSong55_Part1
sSong55_Part1: @ 0x08869042
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 80
	.byte	N03, En3, 100
	.byte	W03
	.byte	Bn2
	.byte	W03
	.byte	En3
	.byte	W03
	.byte	Bn3
	.byte	W03
	.byte	N06, Cn5
	.byte	W06
	.byte	N24, Cn6
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSongHeader_55
sSongHeader_55: @ 0x0886905C
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869024, 0x08869042  @ parts
