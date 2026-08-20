.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong219_Part0
sSong219_Part0: @ 0x0886DD6C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 75
	.byte	BEND , 64
	.byte	N96, En2, 127
	.byte	W03
	.byte	VOL , 92
	.byte	BEND , 86
	.byte	W02
	.byte	72
	.byte	W01
	.byte	VOL , 98
	.byte	PAN , 60
	.byte	W03
	.byte	VOL , 106
	.byte	BEND , 64
	.byte	W03
	.byte	VOL , 116
	.byte	PAN , 56
	.byte	W03
	.byte	VOL , 127
	.byte	W03
	.byte	PAN , 52
	.byte	W06
	.byte	47
	.byte	BEND , 64
	.byte	W03
	.byte	57
	.byte	W03
	.byte	PAN , 55
	.byte	BEND , 52
	.byte	W03
	.byte	44
	.byte	W03
	.byte	PAN , 61
	.byte	W03
	.byte	70
	.byte	BEND , 51
	.byte	W03
	.byte	PAN , 74
	.byte	W03
	.byte	BEND , 58
	.byte	W03
	.byte	PAN , 80
	.byte	W03
	.byte	BEND , 70
	.byte	W03
	.byte	PAN , 77
	.byte	BEND , 75
	.byte	W03
	.byte	84
	.byte	W03
	.byte	PAN , 72
	.byte	W03
	.byte	64
	.byte	BEND , 76
	.byte	W03
	.byte	PAN , 56
	.byte	BEND , 71
	.byte	W03
	.byte	PAN , 53
	.byte	W03
	.byte	47
	.byte	VOL , 114
	.byte	BEND , 64
	.byte	W03
	.byte	VOL , 104
	.byte	BEND , 57
	.byte	W03
	.byte	PAN , 55
	.byte	BEND , 52
	.byte	W01
	.byte	VOL , 93
	.byte	W02
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 82
	.byte	W02
	.byte	PAN , 61
	.byte	W02
	.byte	VOL , 67
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 51
	.byte	W03
	.byte	PAN , 74
	.byte	VOL , 52
	.byte	W02
	.byte	32
	.byte	W01
	.byte	BEND , 58
	.byte	W01
	.byte	VOL , 13
	.byte	W02
	.byte	FINE
	.globl sSong219_Part1
sSong219_Part1: @ 0x0886DE02
	.byte	KEYSH , 0
	.byte	VOICE , 57
	.byte	PAN , 64
	.byte	VOL , 127
	.byte	N03, Cn3, 100
	.byte	W03
	.byte	En3, 80
	.byte	W04
	.byte	Dn3
	.byte	W03
	.byte	Cn3, 100
	.byte	W04
	.byte	En3, 80
	.byte	W04
	.byte	Dn3
	.byte	W03
	.byte	Cn3, 100
	.byte	W03
	.byte	W01
	.byte	En3, 80
	.byte	W03
	.byte	Dn3
	.byte	W04
	.byte	Cn3, 100
	.byte	W04
	.byte	En3, 80
	.byte	W03
	.byte	Dn3
	.byte	W04
	.byte	Cn3, 100
	.byte	W03
	.byte	En3, 80
	.byte	W02
	.byte	W02
	.byte	Dn3
	.byte	W04
	.byte	Cn3, 100
	.byte	W03
	.byte	En3, 80
	.byte	W04
	.byte	Dn3
	.byte	W03
	.byte	Cn3, 100
	.byte	W04
	.byte	En3, 80
	.byte	W04
	.byte	Dn3
	.byte	W03
	.byte	Cn3, 92
	.byte	W04
	.byte	En3, 60
	.byte	W03
	.byte	Dn3, 52
	.byte	W04
	.byte	Cn3, 60
	.byte	W04
	.byte	En3, 32
	.byte	W03
	.byte	N02, Dn3, 20
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86DE59, 0x3
	.globl sSongHeader_219
sSongHeader_219: @ 0x0886DE5C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886DD6C, 0x0886DE02  @ parts
