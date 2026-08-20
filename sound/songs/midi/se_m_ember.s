.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong151_Part0
sSong151_Part0: @ 0x0886B370
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 61
	.byte	BEND , 72
	.byte	N10, Gn3, 127
	.byte	W01
	.byte	VOL , 84
	.byte	W01
	.byte	97
	.byte	BEND , 80
	.byte	W01
	.byte	VOL , 110
	.byte	W01
	.byte	BEND , 71
	.byte	W02
	.byte	52
	.byte	W01
	.byte	VOL , 89
	.byte	W01
	.byte	64
	.byte	BEND , 22
	.byte	W01
	.byte	VOL , 34
	.byte	W15
	.byte	FINE
	.globl sSongHeader_151
sSongHeader_151: @ 0x0886B39C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong151_Part0  @ parts
