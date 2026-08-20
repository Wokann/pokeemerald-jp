.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong216_Part0
sSong216_Part0: @ 0x0886D9A0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 115
	.byte	BEND , 46
	.byte	N60, Gn2, 127
	.byte	W03
	.byte	PAN , 67
	.byte	BEND , 48
	.byte	W04
	.byte	PAN , 70
	.byte	BEND , 50
	.byte	W03
	.byte	PAN , 67
	.byte	BEND , 53
	.byte	W02
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 56
	.byte	W04
	.byte	PAN , 61
	.byte	BEND , 59
	.byte	W03
	.byte	PAN , 58
	.byte	BEND , 62
	.byte	W03
	.byte	W01
	.byte	PAN , 61
	.byte	BEND , 65
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 68
	.byte	W04
	.byte	PAN , 67
	.byte	BEND , 71
	.byte	W02
	.byte	VOL , 109
	.byte	W02
	.byte	PAN , 70
	.byte	BEND , 74
	.byte	W02
	.byte	VOL , 103
	.byte	W01
	.byte	PAN , 67
	.byte	BEND , 77
	.byte	W03
	.byte	VOL , 92
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 80
	.byte	W03
	.byte	VOL , 79
	.byte	PAN , 61
	.byte	BEND , 82
	.byte	W02
	.byte	W02
	.byte	VOL , 62
	.byte	PAN , 58
	.byte	BEND , 85
	.byte	W04
	.byte	VOL , 40
	.byte	PAN , 61
	.byte	BEND , 90
	.byte	W02
	.byte	VOL , 22
	.byte	BEND , 97
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 8
	.byte	BEND , 107
	.byte	W02
	.byte	FINE
	.globl sSong216_Part1
sSong216_Part1: @ 0x0886DA1D
	.byte	KEYSH , 0
	.byte	VOICE , 25
	.byte	VOL , 115
	.byte	N06, Cn3, 40
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	N06, Cn3, 40
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	PEND
	.byte	PATT , 41, 218
	.byte	W06
	.byte	GsM2
	.byte	N06, Cn3, 32
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	Cn3, 12
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86DA41, 0x3
	.globl sSongHeader_216
sSongHeader_216: @ 0x0886DA44
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886D9A0, 0x0886DA1D  @ parts
