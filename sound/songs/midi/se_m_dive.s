.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong233_Part0
sSong233_Part0: @ 0x0886E620
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 105
	.byte	BEND , 46
	.byte	N06, Fn2, 127
	.byte	W03
	.byte	PAN , 67
	.byte	BEND , 48
	.byte	W04
	.byte	PAN , 70
	.byte	BEND , 50
	.byte	N04
	.byte	W03
	.byte	PAN , 67
	.byte	BEND , 53
	.byte	W02
	.byte	N36, Gn3, 92
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 56
	.byte	W04
	.byte	PAN , 61
	.byte	BEND , 59
	.byte	W02
	.byte	VOL , 100
	.byte	W01
	.byte	PAN , 58
	.byte	BEND , 62
	.byte	W03
	.byte	VOL , 94
	.byte	W01
	.byte	PAN , 61
	.byte	BEND , 65
	.byte	W02
	.byte	VOL , 84
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 68
	.byte	W04
	.byte	PAN , 67
	.byte	VOL , 72
	.byte	BEND , 66
	.byte	W04
	.byte	PAN , 70
	.byte	VOL , 57
	.byte	BEND , 61
	.byte	W03
	.byte	PAN , 67
	.byte	VOL , 37
	.byte	BEND , 57
	.byte	W03
	.byte	VOL , 20
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 53
	.byte	W01
	.byte	VOL , 7
	.byte	W02
	.byte	PAN , 61
	.byte	BEND , 48
	.byte	W02
	.byte	FINE
	.globl sSong233_Part1
sSong233_Part1: @ 0x0886E68E
	.byte	KEYSH , 0
	.byte	VOICE , 25
	.byte	VOL , 105
	.byte	N06, An2, 40
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	Gs3, 44
	.byte	W07
	.byte	Gs3, 36
	.byte	W05
	.byte	W02
	.byte	Gs3, 28
	.byte	W07
	.byte	Gs3, 20
	.byte	W03
	.byte	W04
	.byte	Gs3, 12
	.byte	W08
	.byte	FINE
	.globl sSongHeader_233
sSongHeader_233: @ 0x0886E6AC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E620, 0x0886E68E  @ parts
