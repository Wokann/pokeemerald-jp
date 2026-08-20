.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong246_Part0
sSong246_Part0: @ 0x0886F22C
	.byte	KEYSH , 0
	.byte	TEMPO , 95
	.byte	VOICE , 45
	.byte	BENDR , 8
	.byte	PAN , 17
	.byte	VOL , 10
	.byte	MOD , 30
	.byte	BEND , 65
	.byte	TIE , 58, 100
	.byte	W03
	.byte	VOL , 14
	.byte	W03
	.byte	22
	.byte	PAN , 19
	.byte	W02
	.byte	VOL , 31
	.byte	W02
	.byte	39
	.byte	W02
	.byte	PAN , 21
	.byte	W02
	.byte	VOL , 45
	.byte	W02
	.byte	50
	.byte	W02
	.byte	PAN , 23
	.byte	W01
	.byte	VOL , 61
	.byte	W02
	.byte	66
	.byte	W03
	.byte	PAN , 25
	.byte	VOL , 73
	.byte	W02
	.byte	78
	.byte	W04
	.byte	84
	.byte	PAN , 27
	.byte	W03
	.byte	VOL , 91
	.byte	W03
	.byte	98
	.byte	PAN , 29
	.byte	W02
	.byte	VOL , 104
	.byte	W04
	.byte	110
	.byte	PAN , 32
	.byte	W06
	.byte	36
	.byte	W06
	.byte	39
	.byte	VOL , 106
	.byte	W04
	.byte	104
	.byte	W02
	.byte	PAN , 41
	.byte	W03
	.byte	VOL , 101
	.byte	W03
	.byte	PAN , 44
	.byte	W03
	.byte	VOL , 97
	.byte	W03
	.byte	PAN , 47
	.byte	W02
	.byte	VOL , 91
	.byte	W04
	.byte	PAN , 51
	.byte	W03
	.byte	VOL , 88
	.byte	W03
	.byte	PAN , 54
	.byte	W03
	.byte	VOL , 81
	.byte	W03
	.byte	PAN , 57
	.byte	W04
	.byte	VOL , 75
	.byte	W02
	.byte	PAN , 61
	.byte	W02
	.byte	VOL , 74
	.byte	W02
	.byte	76
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 79
	.byte	W02
	.byte	83
	.byte	W03
	.byte	W01
	.byte	86
	.byte	W02
	.byte	PAN , 66
	.byte	VOL , 90
	.byte	W03
	.byte	95
	.byte	W03
	.byte	98
	.byte	W03
	.byte	PAN , 71
	.byte	VOL , 102
	.byte	W02
	.byte	104
	.byte	W04
	.byte	PAN , 74
	.byte	VOL , 110
	.byte	W06
	.byte	PAN , 78
	.byte	W06
	.byte	80
	.byte	W02
	.byte	VOL , 106
	.byte	W04
	.byte	PAN , 83
	.byte	W01
	.byte	VOL , 100
	.byte	W05
	.byte	PAN , 86
	.byte	VOL , 94
	.byte	W06
	.byte	PAN , 89
	.byte	VOL , 88
	.byte	W04
	.byte	83
	.byte	W02
	.byte	PAN , 91
	.byte	W06
	.byte	93
	.byte	VOL , 75
	.byte	W06
	.byte	PAN , 96
	.byte	VOL , 64
	.byte	W06
	.byte	PAN , 98
	.byte	W01
	.byte	VOL , 55
	.byte	W05
	.byte	PAN , 102
	.byte	W01
	.byte	VOL , 47
	.byte	W05
	.byte	PAN , 105
	.byte	W01
	.byte	VOL , 41
	.byte	W05
	.byte	PAN , 108
	.byte	VOL , 32
	.byte	W03
	.byte	25
	.byte	W03
	.byte	PAN , 111
	.byte	W01
	.byte	VOL , 12
	.byte	W03
	.byte	6
	.byte	W02
	.byte	EOT
	.byte	FINE
	.globl sSong246_Part1
sSong246_Part1: @ 0x0886F312
	.byte	KEYSH , 0
	.byte	VOICE , 70
	.byte	BENDR , 8
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N24, Fn4, 20
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	Fn4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	N18, Ds4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F34E, 0x2
	.globl sSongHeader_246
sSongHeader_246: @ 0x0886F350
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886F22C, 0x0886F312  @ parts
