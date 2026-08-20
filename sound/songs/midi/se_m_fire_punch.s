.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong147_Part0
sSong147_Part0: @ 0x0886B108
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 6
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N06, Cn3, 127
	.byte	W01
	.byte	BEND , 55
	.byte	W01
	.byte	43
	.byte	W01
	.byte	PAN , 58
	.byte	BEND , 24
	.byte	W01
	.byte	0
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N06, En3
	.byte	W01
	.byte	BEND , 55
	.byte	W01
	.byte	43
	.byte	W01
	.byte	PAN , 71
	.byte	BEND , 24
	.byte	W01
	.byte	0
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N09, An2
	.byte	W01
	.byte	BEND , 55
	.byte	W01
	.byte	45
	.byte	W01
	.byte	35
	.byte	W01
	.byte	VOL , 86
	.byte	BEND , 25
	.byte	W02
	.byte	VOL , 69
	.byte	BEND , 19
	.byte	W01
	.byte	VOL , 53
	.byte	BEND , 8
	.byte	W01
	.byte	VOL , 20
	.byte	BEND , 0
	.byte	W01
	.byte	VOICE , 29
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N48
	.byte	W03
	.byte	W02
	.byte	PAN , 56
	.byte	W04
	.byte	69
	.byte	W03
	.byte	58
	.byte	W04
	.byte	70
	.byte	W03
	.byte	61
	.byte	W08
	.byte	W03
	.byte	VOL , 78
	.byte	W04
	.byte	64
	.byte	W03
	.byte	51
	.byte	W04
	.byte	38
	.byte	W04
	.byte	25
	.byte	W03
	.byte	12
	.byte	W03
	.byte	FINE
	.globl sSong147_Part1
sSong147_Part1: @ 0x0886B17E
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 110
	.byte	PAN , 73
	.byte	N03, Gs2, 52
	.byte	W06
	.byte	PAN , 57
	.byte	N03
	.byte	W06
	.byte	PAN , 64
	.byte	N03
	.byte	W12
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B19A, 0x2
	.globl sSongHeader_147
sSongHeader_147: @ 0x0886B19C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B108, 0x0886B17E  @ parts
