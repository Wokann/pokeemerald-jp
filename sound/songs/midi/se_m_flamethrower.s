.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong146_Part0
sSong146_Part0: @ 0x0886B034
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	PAN , 68
	.byte	BEND , 114
	.byte	TIE , 60, 127
	.byte	W01
	.byte	BEND , 96
	.byte	W02
	.byte	PAN , 59
	.byte	BEND , 80
	.byte	W02
	.byte	56
	.byte	W02
	.byte	PAN , 72
	.byte	BEND , 49
	.byte	W02
	.byte	54
	.byte	W01
	.byte	PAN , 55
	.byte	W02
	.byte	BEND , 64
	.byte	W02
	.byte	PAN , 68
	.byte	BEND , 66
	.byte	W04
	.byte	PAN , 59
	.byte	BEND , 74
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 80
	.byte	W03
	.byte	PAN , 68
	.byte	W01
	.byte	BEND , 85
	.byte	W02
	.byte	PAN , 59
	.byte	W04
	.byte	72
	.byte	W03
	.byte	55
	.byte	W04
	.byte	68
	.byte	W04
	.byte	59
	.byte	W03
	.byte	64
	.byte	W03
	.byte	PAN , 68
	.byte	W03
	.byte	59
	.byte	W04
	.byte	72
	.byte	W03
	.byte	55
	.byte	W04
	.byte	68
	.byte	W04
	.byte	59
	.byte	W03
	.byte	64
	.byte	W03
	.byte	PEND
	.byte	PATT , 127, 176
	.byte	W06
	.byte	8
	.byte	PATT , 127, 176
	.byte	W06
	.byte	8
	.byte	PATT , 127, 176
	.byte	W06
	.byte	8
	.byte	PAN , 68
	.byte	W03
	.byte	59
	.byte	W03
	.byte	VOL , 103
	.byte	W01
	.byte	PAN , 72
	.byte	W03
	.byte	VOL , 96
	.byte	PAN , 55
	.byte	W04
	.byte	68
	.byte	W02
	.byte	VOL , 88
	.byte	W02
	.byte	PAN , 59
	.byte	W03
	.byte	64
	.byte	W01
	.byte	VOL , 73
	.byte	W02
	.byte	PAN , 68
	.byte	W03
	.byte	VOL , 62
	.byte	PAN , 59
	.byte	W04
	.byte	72
	.byte	W01
	.byte	VOL , 47
	.byte	W02
	.byte	PAN , 55
	.byte	W03
	.byte	VOL , 27
	.byte	W01
	.byte	PAN , 68
	.byte	W04
	.byte	VOL , 10
	.byte	PAN , 59
	.byte	W03
	.byte	64
	.byte	W03
	.byte	EOT , 60
	.byte	FINE
	.globl sSong146_Part1
sSong146_Part1: @ 0x0886B0DB
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	N24, Fn2, 60
	.byte	W10
	.byte	VOL , 99
	.byte	W05
	.byte	82
	.byte	W04
	.byte	54
	.byte	W02
	.byte	25
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_146
sSongHeader_146: @ 0x0886B0F8
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B034, 0x0886B0DB  @ parts
