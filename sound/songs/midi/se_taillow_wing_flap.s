.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong94_Part0
sSong94_Part0: @ 0x0886996C
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 40
	.byte	BEND , 32
	.byte	N07, An1, 127
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 74
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 68
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 82
	.byte	PAN , 55
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 64
	.byte	BEND , 101
	.byte	W02
	.byte	PAN , 74
	.byte	BEND , 127
	.byte	W03
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 40
	.byte	PAN , 74
	.byte	BEND , 65
	.byte	N06
	.byte	W02
	.byte	VOL , 52
	.byte	PAN , 64
	.byte	BEND , 102
	.byte	W01
	.byte	VOL , 79
	.byte	PAN , 55
	.byte	BEND , 112
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	W10
	.byte	W12
	.byte	W12
	.byte	GOTO , 110, 153
	.byte	W06
	.byte	8
	.byte	FINE
	.globl sSong94_Part1
sSong94_Part1: @ 0x088699C7
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	VOL , 52
	.byte	N07, Gn2, 40
	.byte	W01
	.byte	VOL , 69
	.byte	W01
	.byte	83
	.byte	W01
	.byte	105
	.byte	W01
	.byte	67
	.byte	W02
	.byte	23
	.byte	W04
	.byte	VOICE , 25
	.byte	VOL , 52
	.byte	N06, Gs4
	.byte	W02
	.byte	VOL , 81
	.byte	W01
	.byte	105
	.byte	W02
	.byte	52
	.byte	W09
	.byte	W12
	.byte	W12
	.byte	GOTO , 201, 153
	.byte	W06
	.byte	8
	.byte	FINE
	.globl sSongHeader_94
sSongHeader_94: @ 0x088699F4
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886996C, 0x088699C7  @ parts
