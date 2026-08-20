.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong191_Part0
sSong191_Part0: @ 0x0886C830
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 28
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N01, Fn5, 100
	.byte	W01
	.byte	PAN , 58
	.byte	N01, Fs5, 88
	.byte	W01
	.byte	PAN , 69
	.byte	N01, Gn5
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Fs5
	.byte	W01
	.byte	N14, Gn5, 100
	.byte	W02
	.byte	PAN , 60
	.byte	W01
	.byte	64
	.byte	W01
	.byte	69
	.byte	W01
	.byte	64
	.byte	W01
	.byte	60
	.byte	W02
	.byte	VOL , 95
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 92
	.byte	PAN , 69
	.byte	W01
	.byte	VOL , 87
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 79
	.byte	PAN , 60
	.byte	W01
	.byte	VOL , 66
	.byte	PAN , 64
	.byte	W02
	.byte	VOL , 58
	.byte	W01
	.byte	VOICE , 22
	.byte	VOL , 100
	.byte	N10, Cn4, 92
	.byte	W01
	.byte	BEND , 67
	.byte	W01
	.byte	69
	.byte	W01
	.byte	PAN , 63
	.byte	BEND , 71
	.byte	W02
	.byte	VOL , 96
	.byte	BEND , 76
	.byte	W01
	.byte	VOL , 90
	.byte	PAN , 61
	.byte	BEND , 80
	.byte	W01
	.byte	VOL , 84
	.byte	BEND , 84
	.byte	W01
	.byte	VOL , 70
	.byte	PAN , 58
	.byte	BEND , 90
	.byte	W01
	.byte	VOL , 61
	.byte	BEND , 96
	.byte	W03
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N10
	.byte	W01
	.byte	BEND , 67
	.byte	W01
	.byte	69
	.byte	W01
	.byte	PAN , 66
	.byte	BEND , 71
	.byte	W02
	.byte	VOL , 96
	.byte	BEND , 76
	.byte	W01
	.byte	VOL , 90
	.byte	PAN , 69
	.byte	BEND , 80
	.byte	W01
	.byte	VOL , 84
	.byte	BEND , 84
	.byte	W01
	.byte	VOL , 70
	.byte	PAN , 71
	.byte	BEND , 90
	.byte	W01
	.byte	VOL , 61
	.byte	BEND , 96
	.byte	W03
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N16
	.byte	W01
	.byte	BEND , 67
	.byte	W01
	.byte	69
	.byte	W01
	.byte	PAN , 67
	.byte	BEND , 71
	.byte	W02
	.byte	VOL , 96
	.byte	BEND , 76
	.byte	W01
	.byte	VOL , 90
	.byte	PAN , 62
	.byte	BEND , 80
	.byte	W01
	.byte	VOL , 84
	.byte	BEND , 84
	.byte	W01
	.byte	VOL , 70
	.byte	PAN , 70
	.byte	BEND , 90
	.byte	W01
	.byte	VOL , 61
	.byte	BEND , 96
	.byte	W02
	.byte	VOL , 56
	.byte	PAN , 60
	.byte	BEND , 100
	.byte	W01
	.byte	VOL , 48
	.byte	BEND , 106
	.byte	W01
	.byte	VOL , 37
	.byte	PAN , 75
	.byte	BEND , 112
	.byte	W01
	.byte	VOL , 25
	.byte	BEND , 120
	.byte	W01
	.byte	VOL , 11
	.byte	PAN , 53
	.byte	BEND , 127
	.byte	W02
	.byte	FINE
	.globl sSong191_Part1
sSong191_Part1: @ 0x0886C92A
	.byte	KEYSH , 0
	.byte	VOICE , 25
	.byte	VOL , 100
	.byte	N04, Cn3, 40
	.byte	W04
	.byte	N14, Gs4
	.byte	W08
	.byte	VOL , 89
	.byte	W01
	.byte	72
	.byte	W01
	.byte	46
	.byte	W01
	.byte	25
	.byte	W01
	.byte	11
	.byte	W08
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C946, 0x2
	.globl sSongHeader_191
sSongHeader_191: @ 0x0886C948
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886C830, 0x0886C92A  @ parts
