.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong235_Part0
sSong235_Part0: @ 0x0886E8C4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 67
	.byte	BEND , 64
	.byte	TIE , 50, 127
	.byte	W03
	.byte	VOL , 83
	.byte	BEND , 86
	.byte	W03
	.byte	VOL , 88
	.byte	PAN , 60
	.byte	W03
	.byte	VOL , 95
	.byte	W02
	.byte	BEND , 72
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 56
	.byte	W03
	.byte	VOL , 115
	.byte	W02
	.byte	BEND , 64
	.byte	W01
	.byte	PAN , 52
	.byte	W06
	.byte	47
	.byte	BEND , 64
	.byte	W03
	.byte	57
	.byte	W03
	.byte	PAN , 55
	.byte	W06
	.byte	61
	.byte	W01
	.byte	BEND , 52
	.byte	W02
	.byte	PAN , 70
	.byte	W03
	.byte	74
	.byte	W06
	.byte	80
	.byte	W01
	.byte	BEND , 44
	.byte	W05
	.byte	PAN , 77
	.byte	W06
	.byte	72
	.byte	W03
	.byte	64
	.byte	W01
	.byte	BEND , 51
	.byte	W02
	.byte	PAN , 56
	.byte	W03
	.byte	53
	.byte	W03
	.byte	47
	.byte	W01
	.byte	BEND , 58
	.byte	W05
	.byte	PAN , 55
	.byte	W06
	.byte	61
	.byte	W03
	.byte	70
	.byte	W03
	.byte	74
	.byte	W01
	.byte	BEND , 70
	.byte	W05
	.byte	PAN , 80
	.byte	W06
	.byte	77
	.byte	W06
	.byte	72
	.byte	W03
	.byte	64
	.byte	BEND , 75
	.byte	W03
	.byte	PAN , 56
	.byte	W03
	.byte	53
	.byte	VOL , 103
	.byte	W03
	.byte	PAN , 47
	.byte	W01
	.byte	BEND , 84
	.byte	W05
	.byte	PAN , 55
	.byte	W01
	.byte	VOL , 97
	.byte	W05
	.byte	PAN , 61
	.byte	W01
	.byte	BEND , 76
	.byte	W02
	.byte	PAN , 70
	.byte	VOL , 88
	.byte	W03
	.byte	PAN , 74
	.byte	W02
	.byte	BEND , 71
	.byte	W02
	.byte	VOL , 79
	.byte	W02
	.byte	PAN , 80
	.byte	W04
	.byte	VOL , 62
	.byte	BEND , 64
	.byte	W02
	.byte	PAN , 77
	.byte	W04
	.byte	VOL , 45
	.byte	W02
	.byte	PAN , 72
	.byte	W01
	.byte	BEND , 57
	.byte	W01
	.byte	VOL , 33
	.byte	W01
	.byte	PAN , 64
	.byte	W03
	.byte	56
	.byte	W01
	.byte	VOL , 18
	.byte	W02
	.byte	PAN , 53
	.byte	W03
	.byte	EOT
	.byte	FINE
	.globl sSong235_Part1
sSong235_Part1: @ 0x0886E982
	.byte	KEYSH , 0
	.byte	VOICE , 25
	.byte	VOL , 67
	.byte	TIE , 80, 12
	.byte	W03
	.byte	VOL , 83
	.byte	W03
	.byte	88
	.byte	W03
	.byte	95
	.byte	W03
	.byte	105
	.byte	W03
	.byte	115
	.byte	W09
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W21
	.byte	103
	.byte	W03
	.byte	W07
	.byte	97
	.byte	W08
	.byte	88
	.byte	W07
	.byte	79
	.byte	W02
	.byte	W04
	.byte	62
	.byte	W06
	.byte	45
	.byte	W04
	.byte	33
	.byte	W05
	.byte	18
	.byte	W05
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86E9AF, 0x1
	.globl sSongHeader_235
sSongHeader_235: @ 0x0886E9B0
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E8C4, 0x0886E982  @ parts
