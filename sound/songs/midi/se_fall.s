.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong43_Part0
sSong43_Part0: @ 0x08868C80
	.byte	KEYSH , 0
	.byte	TEMPO , 85
	.byte	VOICE , 22
	.byte	VOL , 110
	.byte	BEND , 124
	.byte	N44, Gn3, 80
	.byte	W03
	.byte	BEND , 121
	.byte	W03
	.byte	116
	.byte	W03
	.byte	107
	.byte	W03
	.byte	100
	.byte	W03
	.byte	94
	.byte	W03
	.byte	86
	.byte	W03
	.byte	80
	.byte	W03
	.byte	VOL , 104
	.byte	BEND , 75
	.byte	W03
	.byte	VOL , 90
	.byte	BEND , 67
	.byte	W03
	.byte	VOL , 82
	.byte	BEND , 56
	.byte	W03
	.byte	VOL , 71
	.byte	BEND , 48
	.byte	W03
	.byte	VOL , 58
	.byte	BEND , 40
	.byte	W03
	.byte	VOL , 45
	.byte	BEND , 28
	.byte	W03
	.byte	VOL , 36
	.byte	BEND , 14
	.byte	W03
	.byte	VOL , 11
	.byte	BEND , 1
	.byte	W03
	.byte	VOL , 3
	.byte	FINE
	.globl sSongHeader_43
sSongHeader_43: @ 0x08868CC8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong43_Part0  @ parts
