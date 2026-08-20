.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong107_Part0
sSong107_Part0: @ 0x08869F14
	.byte	KEYSH , 0
	.byte	TEMPO , 55
	.byte	VOICE , 15
	.byte	BENDR , 12
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	BEND , 94
	.byte	TIE , 72, 100
	.byte	W01
	.byte	BEND , 88
	.byte	W01
	.byte	83
	.byte	W01
	.byte	78
	.byte	W01
	.byte	72
	.byte	W02
	.byte	68
	.byte	W01
	.byte	66
	.byte	W01
	.byte	64
	.byte	W04
	.byte	W04
	.byte	65
	.byte	W02
	.byte	W06
	.byte	65
	.byte	W06
	.byte	65
	.byte	W06
	.byte	66
	.byte	W06
	.byte	67
	.byte	W06
	.byte	67
	.byte	W06
	.byte	68
	.byte	W06
	.byte	68
	.byte	W06
	.byte	69
	.byte	W06
	.byte	70
	.byte	W06
	.byte	72
	.byte	W06
	.byte	74
	.byte	W06
	.byte	76
	.byte	W06
	.byte	78
	.byte	W06
	.byte	80
	.byte	W06
	.byte	82
	.byte	W06
	.byte	84
	.byte	W06
	.byte	VOL , 98
	.byte	BEND , 86
	.byte	W03
	.byte	VOL , 97
	.byte	W03
	.byte	BEND , 88
	.byte	W01
	.byte	VOL , 94
	.byte	W03
	.byte	91
	.byte	W02
	.byte	BEND , 90
	.byte	W02
	.byte	VOL , 88
	.byte	W02
	.byte	85
	.byte	W02
	.byte	BEND , 92
	.byte	W02
	.byte	VOL , 80
	.byte	W02
	.byte	73
	.byte	W02
	.byte	BEND , 94
	.byte	W01
	.byte	VOL , 68
	.byte	W02
	.byte	62
	.byte	W03
	.byte	55
	.byte	BEND , 96
	.byte	W02
	.byte	VOL , 47
	.byte	W02
	.byte	37
	.byte	W02
	.byte	BEND , 100
	.byte	W01
	.byte	VOL , 30
	.byte	W01
	.byte	20
	.byte	W01
	.byte	13
	.byte	W01
	.byte	4
	.byte	W02
	.byte	EOT
	.byte	FINE
	.globl sSong107_Part1
sSong107_Part1: @ 0x08869F98
	.byte	KEYSH , 0
	.byte	VOICE , 25
	.byte	VOL , 15
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	TIE , 56, 60
	.byte	W01
	.byte	VOL , 21
	.byte	W01
	.byte	33
	.byte	W01
	.byte	41
	.byte	W01
	.byte	49
	.byte	W02
	.byte	55
	.byte	W01
	.byte	61
	.byte	W01
	.byte	69
	.byte	W01
	.byte	76
	.byte	W01
	.byte	80
	.byte	W02
	.byte	86
	.byte	W01
	.byte	90
	.byte	W01
	.byte	100
	.byte	W04
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W01
	.byte	BEND , 65
	.byte	W05
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W02
	.byte	66
	.byte	W04
	.byte	W01
	.byte	68
	.byte	W05
	.byte	69
	.byte	W03
	.byte	VOL , 97
	.byte	BEND , 70
	.byte	W03
	.byte	VOL , 94
	.byte	W01
	.byte	BEND , 70
	.byte	W01
	.byte	VOL , 87
	.byte	W02
	.byte	83
	.byte	BEND , 72
	.byte	W02
	.byte	W01
	.byte	VOL , 77
	.byte	BEND , 74
	.byte	W02
	.byte	VOL , 66
	.byte	BEND , 78
	.byte	W03
	.byte	VOL , 55
	.byte	BEND , 81
	.byte	W02
	.byte	VOL , 45
	.byte	BEND , 88
	.byte	W02
	.byte	VOL , 33
	.byte	BEND , 94
	.byte	W02
	.byte	105
	.byte	W01
	.byte	VOL , 21
	.byte	BEND , 110
	.byte	W01
	.byte	119
	.byte	W01
	.byte	VOL , 11
	.byte	BEND , 124
	.byte	W01
	.byte	VOL , 5
	.byte	BEND , 127
	.byte	W02
	.byte	EOT
	.byte	FINE
	.globl sSongHeader_107
sSongHeader_107: @ 0x0886A01C
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869F14, 0x08869F98  @ parts
