.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong243_Part0
sSong243_Part0: @ 0x0886EEFC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 46
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 60
	.byte	N09, As5, 112
	.byte	W06
	.byte	W03
	.byte	PAN , 59
	.byte	N08, Cn5
	.byte	W03
	.byte	W06
	.byte	PAN , 55
	.byte	N10, Gn5
	.byte	W06
	.byte	W04
	.byte	PAN , 59
	.byte	N09, Fn6
	.byte	W02
	.byte	W06
	.byte	W02
	.byte	PAN , 64
	.byte	N09, An5
	.byte	W04
	.byte	W06
	.byte	PAN , 68
	.byte	N09, As5
	.byte	W06
	.byte	W03
	.byte	PAN , 73
	.byte	N08, Cn5, 108
	.byte	W03
	.byte	W06
	.byte	PAN , 68
	.byte	N10, Gn5, 104
	.byte	W06
	.byte	W04
	.byte	PAN , 64
	.byte	N09, Fn6, 96
	.byte	W02
	.byte	W06
	.byte	W02
	.byte	PAN , 59
	.byte	N09, An5, 92
	.byte	W04
	.byte	W04
	.byte	PAN , 55
	.byte	W02
	.byte	N09, As5, 84
	.byte	W06
	.byte	W03
	.byte	PAN , 59
	.byte	N08, Cn5, 80
	.byte	W03
	.byte	W06
	.byte	N10, Gn5, 72
	.byte	W01
	.byte	PAN , 64
	.byte	W05
	.byte	W04
	.byte	68
	.byte	N09, Fn6, 68
	.byte	W02
	.byte	W06
	.byte	W02
	.byte	PAN , 73
	.byte	N09, An5, 60
	.byte	W04
	.byte	W04
	.byte	PAN , 68
	.byte	W02
	.byte	N09, As5, 56
	.byte	W06
	.byte	W03
	.byte	PAN , 64
	.byte	N08, Cn5, 52
	.byte	W03
	.byte	W06
	.byte	N10, Gn5, 44
	.byte	W01
	.byte	PAN , 59
	.byte	W05
	.byte	W03
	.byte	55
	.byte	W01
	.byte	N09, Fn6, 40
	.byte	W02
	.byte	W06
	.byte	W02
	.byte	PAN , 59
	.byte	N09, An5, 32
	.byte	W04
	.byte	W06
	.byte	PAN , 64
	.byte	W06
	.byte	FINE
	.globl sSong243_Part1
sSong243_Part1: @ 0x0886EF9A
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	XCMD , 8 , 9
	.byte	9 , 8
	.byte	VOL , 43
	.byte	BEND , 62
	.byte	W04
	.byte	N08, Fn5, 112
	.byte	W02
	.byte	W06
	.byte	W01
	.byte	N10, Ds5
	.byte	W05
	.byte	W06
	.byte	N09, As6
	.byte	W06
	.byte	W03
	.byte	Cn6
	.byte	W03
	.byte	W06
	.byte	N10, Fn5
	.byte	W06
	.byte	W04
	.byte	N08
	.byte	W02
	.byte	W06
	.byte	W01
	.byte	N10, Ds5, 104
	.byte	W05
	.byte	W06
	.byte	N09, As6, 100
	.byte	W06
	.byte	W03
	.byte	Cn6, 92
	.byte	W03
	.byte	W06
	.byte	N10, Fn5, 88
	.byte	W06
	.byte	W04
	.byte	N08, Fn5, 80
	.byte	W02
	.byte	W06
	.byte	W01
	.byte	N10, Ds5, 76
	.byte	W05
	.byte	W06
	.byte	N09, As6, 72
	.byte	W06
	.byte	W03
	.byte	Cn6, 64
	.byte	W03
	.byte	W06
	.byte	N10, Fn5, 60
	.byte	W06
	.byte	W04
	.byte	N08, Fn5, 52
	.byte	W02
	.byte	W06
	.byte	W01
	.byte	N10, Ds5, 48
	.byte	W05
	.byte	W06
	.byte	N09, As6, 40
	.byte	W06
	.byte	W03
	.byte	Cn6, 36
	.byte	W03
	.byte	W06
	.byte	N12, Fn5, 32
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F007, 0x1
	.globl sSongHeader_243
sSongHeader_243: @ 0x0886F008
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886EEFC, 0x0886EF9A  @ parts
