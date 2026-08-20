.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong150_Part0
sSong150_Part0: @ 0x0886B290
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	VOL , 22
	.byte	PAN , 69
	.byte	BEND , 64
	.byte	N96, Gn3, 127
	.byte	W01
	.byte	VOL , 49
	.byte	W01
	.byte	71
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 95
	.byte	BEND , 72
	.byte	W01
	.byte	VOL , 110
	.byte	W02
	.byte	PAN , 59
	.byte	BEND , 80
	.byte	W03
	.byte	VOL , 97
	.byte	PAN , 64
	.byte	BEND , 71
	.byte	W03
	.byte	PAN , 69
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 84
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 55
	.byte	W03
	.byte	VOL , 76
	.byte	PAN , 59
	.byte	BEND , 40
	.byte	W03
	.byte	PAN , 62
	.byte	BEND , 18
	.byte	W03
	.byte	VOL , 84
	.byte	PAN , 69
	.byte	W03
	.byte	64
	.byte	W01
	.byte	VOL , 92
	.byte	W02
	.byte	PAN , 59
	.byte	W01
	.byte	BEND , 32
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 86
	.byte	W02
	.byte	PAN , 69
	.byte	W02
	.byte	BEND , 46
	.byte	W01
	.byte	VOL , 78
	.byte	PAN , 64
	.byte	W03
	.byte	59
	.byte	W02
	.byte	VOL , 71
	.byte	W01
	.byte	PAN , 62
	.byte	W03
	.byte	69
	.byte	W03
	.byte	64
	.byte	VOL , 78
	.byte	W03
	.byte	PAN , 59
	.byte	W02
	.byte	VOL , 86
	.byte	W01
	.byte	PAN , 64
	.byte	W03
	.byte	69
	.byte	W02
	.byte	VOL , 90
	.byte	W01
	.byte	PAN , 64
	.byte	W03
	.byte	59
	.byte	W03
	.byte	62
	.byte	W01
	.byte	VOL , 80
	.byte	W02
	.byte	PAN , 69
	.byte	W03
	.byte	64
	.byte	W01
	.byte	VOL , 86
	.byte	W02
	.byte	PAN , 59
	.byte	W03
	.byte	64
	.byte	VOL , 83
	.byte	W03
	.byte	PAN , 69
	.byte	VOL , 63
	.byte	W03
	.byte	37
	.byte	PAN , 64
	.byte	W03
	.byte	59
	.byte	VOL , 13
	.byte	W03
	.byte	PAN , 62
	.byte	W03
	.byte	FINE
	.globl sSong150_Part1
sSong150_Part1: @ 0x0886B33D
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	VOL , 22
	.byte	N96, Gn2, 32
	.byte	W01
	.byte	VOL , 49
	.byte	W01
	.byte	71
	.byte	W01
	.byte	95
	.byte	W01
	.byte	110
	.byte	W05
	.byte	97
	.byte	W15
	.byte	W24
	.byte	W24
	.byte	W09
	.byte	83
	.byte	W03
	.byte	63
	.byte	W03
	.byte	37
	.byte	W03
	.byte	13
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B35E, 0x2
	.globl sSongHeader_150
sSongHeader_150: @ 0x0886B360
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B290, 0x0886B33D  @ parts
