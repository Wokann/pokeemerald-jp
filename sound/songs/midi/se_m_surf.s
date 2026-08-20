.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong163_Part0
sSong163_Part0: @ 0x0886B91C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	VOL , 27
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N96, Cn3, 112
	.byte	W04
	.byte	VOL , 45
	.byte	W02
	.byte	PAN , 60
	.byte	W02
	.byte	BEND , 68
	.byte	W01
	.byte	VOL , 60
	.byte	W03
	.byte	PAN , 54
	.byte	W02
	.byte	BEND , 73
	.byte	W01
	.byte	VOL , 88
	.byte	W03
	.byte	PAN , 59
	.byte	W02
	.byte	BEND , 78
	.byte	W04
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 110
	.byte	W02
	.byte	BEND , 83
	.byte	W03
	.byte	PAN , 68
	.byte	W02
	.byte	BEND , 88
	.byte	W04
	.byte	PAN , 75
	.byte	W06
	.byte	68
	.byte	W06
	.byte	64
	.byte	W06
	.byte	60
	.byte	W02
	.byte	BEND , 83
	.byte	W04
	.byte	PAN , 54
	.byte	W01
	.byte	VOL , 98
	.byte	W05
	.byte	81
	.byte	PAN , 59
	.byte	BEND , 76
	.byte	W06
	.byte	VOL , 68
	.byte	PAN , 64
	.byte	W03
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 50
	.byte	W02
	.byte	PAN , 68
	.byte	W03
	.byte	VOL , 31
	.byte	W03
	.byte	PAN , 75
	.byte	BEND , 86
	.byte	W02
	.byte	VOL , 11
	.byte	W04
	.byte	6
	.byte	PAN , 68
	.byte	BEND , 94
	.byte	W06
	.byte	FINE
	.globl sSongHeader_163
sSongHeader_163: @ 0x0886B990
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong163_Part0  @ parts
