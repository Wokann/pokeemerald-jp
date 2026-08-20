.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong86_Part0
sSong86_Part0: @ 0x08869744
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 80
	.byte	BEND , 64
	.byte	N24, Bn3, 52
	.byte	W03
	.byte	VOL , 76
	.byte	W03
	.byte	74
	.byte	W03
	.byte	72
	.byte	W03
	.byte	68
	.byte	W03
	.byte	64
	.byte	W03
	.byte	58
	.byte	W03
	.byte	50
	.byte	W03
	.byte	44
	.byte	N24
	.byte	W03
	.byte	VOL , 38
	.byte	W03
	.byte	34
	.byte	W03
	.byte	27
	.byte	W03
	.byte	20
	.byte	W03
	.byte	15
	.byte	W03
	.byte	10
	.byte	W03
	.byte	6
	.byte	W03
	.byte	FINE
	.globl sSongHeader_86
sSongHeader_86: @ 0x08869778
	.byte 0x01, 0x00, 0x02, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong86_Part0  @ parts
