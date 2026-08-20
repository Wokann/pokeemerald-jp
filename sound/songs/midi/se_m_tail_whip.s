.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong167_Part0
sSong167_Part0: @ 0x0886BB04
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 15
	.byte	BENDR , 12
	.byte	PAN , 82
	.byte	VOL , 48
	.byte	BEND , 16
	.byte	N04, Gn2, 127
	.byte	W01
	.byte	VOL , 81
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 110
	.byte	BEND , 80
	.byte	W01
	.byte	64
	.byte	W04
	.byte	VOL , 48
	.byte	PAN , 48
	.byte	BEND , 16
	.byte	N04, An2
	.byte	W01
	.byte	VOL , 81
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 110
	.byte	BEND , 80
	.byte	W15
	.byte	VOL , 110
	.byte	FINE
	.globl sSongHeader_167
sSongHeader_167: @ 0x0886BB38
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong167_Part0  @ parts
